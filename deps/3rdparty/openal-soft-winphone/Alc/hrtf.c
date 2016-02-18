/**
 * OpenAL cross platform audio library
 * Copyright (C) 2011 by Chris Robinson
 * This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the
 *  Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 *  Boston, MA  02111-1307, USA.
 * Or go to http://www.gnu.org/copyleft/lgpl.html
 */

#include "config.h"

#include <stdlib.h>
#include <ctype.h>

#include "AL/al.h"
#include "AL/alc.h"
#include "alMain.h"
#include "alSource.h"

/* External HRTF file format (LE byte order):
 *
 * ALchar   magic[8] = "MinPHR00";
 * ALuint   sampleRate;
 *
 * ALushort hrirCount; // Required value: 828
 * ALushort hrirSize;  // Required value: 32
 * ALubyte  evCount;   // Required value: 19
 *
 * ALushort evOffset[evCount]; // Required values:
 *   { 0, 1, 13, 37, 73, 118, 174, 234, 306, 378, 450, 522, 594, 654, 710, 755, 791, 815, 827 }
 *
 * ALshort coefficients[hrirCount][hrirSize];
 * ALubyte delays[hrirCount]; // Element values must not exceed 127
 */

static const ALchar magicMarker[8] = "MinPHR00";

#define HRIR_COUNT 828
#define ELEV_COUNT 19

static const ALushort evOffset[ELEV_COUNT] = { 0, 1, 13, 37, 73, 118, 174, 234, 306, 378, 450, 522, 594, 654, 710, 755, 791, 815, 827 };
static const ALubyte azCount[ELEV_COUNT] = { 1, 12, 24, 36, 45, 56, 60, 72, 72, 72, 72, 72, 60, 56, 45, 36, 24, 12, 1 };


static const struct Hrtf {
    ALuint sampleRate;
    ALshort coeffs[HRIR_COUNT][HRIR_LENGTH];
    ALubyte delays[HRIR_COUNT];
} DefaultHrtf = {
    44100,
#include "hrtf_tables.inc"
};

static struct Hrtf *LoadedHrtfs = NULL;
static ALuint NumLoadedHrtfs = 0;


// Calculate the elevation indices given the polar elevation in radians.
// This will return two indices between 0 and (ELEV_COUNT-1) and an
// interpolation factor between 0.0 and 1.0.
static void CalcEvIndices(ALfloat ev, ALuint *evidx, ALfloat *evmu)
{
    ev = (F_PI_2 + ev) * (ELEV_COUNT-1) / F_PI;
    evidx[0] = fastf2u(ev);
    evidx[1] = minu(evidx[0] + 1, ELEV_COUNT-1);
    *evmu = ev - evidx[0];
}

// Calculate the azimuth indices given the polar azimuth in radians.  This
// will return two indices between 0 and (azCount [ei] - 1) and an
// interpolation factor between 0.0 and 1.0.
static void CalcAzIndices(ALuint evidx, ALfloat az, ALuint *azidx, ALfloat *azmu)
{
    az = (F_PI*2.0f + az) * azCount[evidx] / (F_PI*2.0f);
    azidx[0] = fastf2u(az) % azCount[evidx];
    azidx[1] = (azidx[0] + 1) % azCount[evidx];
    *azmu = az - aluFloor(az);
}

// Calculates the normalized HRTF transition factor (delta) from the changes
// in gain and listener to source angle between updates.  The result is a
// normalized delta factor than can be used to calculate moving HRIR stepping
// values.
ALfloat CalcHrtfDelta(ALfloat oldGain, ALfloat newGain, const ALfloat olddir[3], const ALfloat newdir[3])
{
    ALfloat gainChange, angleChange;

    // Calculate the normalized dB gain change.
    newGain = maxf(newGain, 0.0001f);
    oldGain = maxf(oldGain, 0.0001f);
    gainChange = aluFabs(aluLog10(newGain / oldGain) / aluLog10(0.0001f));

    // Calculate the normalized listener to source angle change when there is
    // enough gain to notice it.
    angleChange = 0.0f;
    if(gainChange > 0.0001f || newGain > 0.0001f)
    {
        // No angle change when the directions are equal or degenerate (when
        // both have zero length).
        if(newdir[0]-olddir[0] || newdir[1]-olddir[1] || newdir[2]-olddir[2])
            angleChange = aluAcos(olddir[0]*newdir[0] +
                                  olddir[1]*newdir[1] +
                                  olddir[2]*newdir[2]) / F_PI;

    }

    // Use the largest of the two changes for the delta factor, and apply a
    // significance shaping function to it.
    return clampf(angleChange*2.0f, gainChange*2.0f, 1.0f);
}

// Calculates static HRIR coefficients and delays for the given polar
// elevation and azimuth in radians.  Linear interpolation is used to
// increase the apparent resolution of the HRIR dataset.  The coefficients
// are also normalized and attenuated by the specified gain.
void GetLerpedHrtfCoeffs(const struct Hrtf *Hrtf, ALfloat elevation, ALfloat azimuth, ALfloat gain, ALfloat (*coeffs)[2], ALuint *delays)
{
    ALuint evidx[2], azidx[2];
    ALfloat mu[3];
    ALuint lidx[4], ridx[4];
    ALuint i;

    // Claculate elevation indices and interpolation factor.
    CalcEvIndices(elevation, evidx, &mu[2]);

    // Calculate azimuth indices and interpolation factor for the first
    // elevation.
    CalcAzIndices(evidx[0], azimuth, azidx, &mu[0]);

    // Calculate the first set of linear HRIR indices for left and right
    // channels.
    lidx[0] = evOffset[evidx[0]] + azidx[0];
    lidx[1] = evOffset[evidx[0]] + azidx[1];
    ridx[0] = evOffset[evidx[0]] + ((azCount[evidx[0]]-azidx[0]) % azCount[evidx[0]]);
    ridx[1] = evOffset[evidx[0]] + ((azCount[evidx[0]]-azidx[1]) % azCount[evidx[0]]);

    // Calculate azimuth indices and interpolation factor for the second
    // elevation.
    CalcAzIndices(evidx[1], azimuth, azidx, &mu[1]);

    // Calculate the second set of linear HRIR indices for left and right
    // channels.
    lidx[2] = evOffset[evidx[1]] + azidx[0];
    lidx[3] = evOffset[evidx[1]] + azidx[1];
    ridx[2] = evOffset[evidx[1]] + ((azCount[evidx[1]]-azidx[0]) % azCount[evidx[1]]);
    ridx[3] = evOffset[evidx[1]] + ((azCount[evidx[1]]-azidx[1]) % azCount[evidx[1]]);

    // Calculate the normalized and attenuated HRIR coefficients using linear
    // interpolation when there is enough gain to warrant it.  Zero the
    // coefficients if gain is too low.
    if(gain > 0.0001f)
    {
        gain *= 1.0f/32767.0f;
        for(i = 0;i < HRIR_LENGTH;i++)
        {
            coeffs[i][0] = lerp(lerp(Hrtf->coeffs[lidx[0]][i], Hrtf->coeffs[lidx[1]][i], mu[0]),
                                lerp(Hrtf->coeffs[lidx[2]][i], Hrtf->coeffs[lidx[3]][i], mu[1]),
                                mu[2]) * gain;
            coeffs[i][1] = lerp(lerp(Hrtf->coeffs[ridx[0]][i], Hrtf->coeffs[ridx[1]][i], mu[0]),
                                lerp(Hrtf->coeffs[ridx[2]][i], Hrtf->coeffs[ridx[3]][i], mu[1]),
                                mu[2]) * gain;
        }
    }
    else
    {
        for(i = 0;i < HRIR_LENGTH;i++)
        {
            coeffs[i][0] = 0.0f;
            coeffs[i][1] = 0.0f;
        }
    }

    // Calculate the HRIR delays using linear interpolation.
    delays[0] = fastf2u(lerp(lerp(Hrtf->delays[lidx[0]], Hrtf->delays[lidx[1]], mu[0]),
                             lerp(Hrtf->delays[lidx[2]], Hrtf->delays[lidx[3]], mu[1]),
                             mu[2]) * 65536.0f);
    delays[1] = fastf2u(lerp(lerp(Hrtf->delays[ridx[0]], Hrtf->delays[ridx[1]], mu[0]),
                             lerp(Hrtf->delays[ridx[2]], Hrtf->delays[ridx[3]], mu[1]),
                             mu[2]) * 65536.0f);
}

// Calculates the moving HRIR target coefficients, target delays, and
// stepping values for the given polar elevation and azimuth in radians.
// Linear interpolation is used to increase the apparent resolution of the
// HRIR dataset.  The coefficients are also normalized and attenuated by the
// specified gain.  Stepping resolution and count is determined using the
// given delta factor between 0.0 and 1.0.
ALuint GetMovingHrtfCoeffs(const struct Hrtf *Hrtf, ALfloat elevation, ALfloat azimuth, ALfloat gain, ALfloat delta, ALint counter, ALfloat (*coeffs)[2], ALuint *delays, ALfloat (*coeffStep)[2], ALint *delayStep)
{
    ALuint evidx[2], azidx[2];
    ALuint lidx[4], ridx[4];
    ALfloat left, right;
    ALfloat mu[3];
    ALfloat step;
    ALuint i;

    // Claculate elevation indices and interpolation factor.
    CalcEvIndices(elevation, evidx, &mu[2]);

    // Calculate azimuth indices and interpolation factor for the first
    // elevation.
    CalcAzIndices(evidx[0], azimuth, azidx, &mu[0]);

    // Calculate the first set of linear HRIR indices for left and right
    // channels.
    lidx[0] = evOffset[evidx[0]] + azidx[0];
    lidx[1] = evOffset[evidx[0]] + azidx[1];
    ridx[0] = evOffset[evidx[0]] + ((azCount[evidx[0]]-azidx[0]) % azCount[evidx[0]]);
    ridx[1] = evOffset[evidx[0]] + ((azCount[evidx[0]]-azidx[1]) % azCount[evidx[0]]);

    // Calculate azimuth indices and interpolation factor for the second
    // elevation.
    CalcAzIndices(evidx[1], azimuth, azidx, &mu[1]);

    // Calculate the second set of linear HRIR indices for left and right
    // channels.
    lidx[2] = evOffset[evidx[1]] + azidx[0];
    lidx[3] = evOffset[evidx[1]] + azidx[1];
    ridx[2] = evOffset[evidx[1]] + ((azCount[evidx[1]]-azidx[0]) % azCount[evidx[1]]);
    ridx[3] = evOffset[evidx[1]] + ((azCount[evidx[1]]-azidx[1]) % azCount[evidx[1]]);

    // Calculate the stepping parameters.
    delta = maxf(aluFloor(delta*(Hrtf->sampleRate*0.015f) + 0.5f), 1.0f);
    step = 1.0f / delta;

    // Calculate the normalized and attenuated target HRIR coefficients using
    // linear interpolation when there is enough gain to warrant it.  Zero
    // the target coefficients if gain is too low.  Then calculate the
    // coefficient stepping values using the target and previous running
    // coefficients.
    if(gain > 0.0001f)
    {
        gain *= 1.0f/32767.0f;
        for(i = 0;i < HRIR_LENGTH;i++)
        {
            left = coeffs[i][0] - (coeffStep[i][0] * counter);
            right = coeffs[i][1] - (coeffStep[i][1] * counter);

            coeffs[i][0] = lerp(lerp(Hrtf->coeffs[lidx[0]][i], Hrtf->coeffs[lidx[1]][i], mu[0]),
                                lerp(Hrtf->coeffs[lidx[2]][i], Hrtf->coeffs[lidx[3]][i], mu[1]),
                                mu[2]) * gain;
            coeffs[i][1] = lerp(lerp(Hrtf->coeffs[ridx[0]][i], Hrtf->coeffs[ridx[1]][i], mu[0]),
                                lerp(Hrtf->coeffs[ridx[2]][i], Hrtf->coeffs[ridx[3]][i], mu[1]),
                                mu[2]) * gain;

            coeffStep[i][0] = step * (coeffs[i][0] - left);
            coeffStep[i][1] = step * (coeffs[i][1] - right);
        }
    }
    else
    {
        for(i = 0;i < HRIR_LENGTH;i++)
        {
            left = coeffs[i][0] - (coeffStep[i][0] * counter);
            right = coeffs[i][1] - (coeffStep[i][1] * counter);

            coeffs[i][0] = 0.0f;
            coeffs[i][1] = 0.0f;

            coeffStep[i][0] = step * -left;
            coeffStep[i][1] = step * -right;
        }
    }

    // Calculate the HRIR delays using linear interpolation.  Then calculate
    // the delay stepping values using the target and previous running
    // delays.
    left = (ALfloat)(delays[0] - (delayStep[0] * counter));
    right = (ALfloat)(delays[1] - (delayStep[1] * counter));

    delays[0] = fastf2u(lerp(lerp(Hrtf->delays[lidx[0]], Hrtf->delays[lidx[1]], mu[0]),
                             lerp(Hrtf->delays[lidx[2]], Hrtf->delays[lidx[3]], mu[1]),
                             mu[2]) * 65536.0f);
    delays[1] = fastf2u(lerp(lerp(Hrtf->delays[ridx[0]], Hrtf->delays[ridx[1]], mu[0]),
                             lerp(Hrtf->delays[ridx[2]], Hrtf->delays[ridx[3]], mu[1]),
                             mu[2]) * 65536.0f);

    delayStep[0] = fastf2i(step * (delays[0] - left));
    delayStep[1] = fastf2i(step * (delays[1] - right));

    // The stepping count is the number of samples necessary for the HRIR to
    // complete its transition.  The mixer will only apply stepping for this
    // many samples.
    return fastf2u(delta);
}

const struct Hrtf *GetHrtf(ALCdevice *device)
{
    if(device->FmtChans == DevFmtStereo)
    {
        ALuint i;
        for(i = 0;i < NumLoadedHrtfs;i++)
        {
            if(device->Frequency == LoadedHrtfs[i].sampleRate)
                return &LoadedHrtfs[i];
        }
        if(device->Frequency == DefaultHrtf.sampleRate)
            return &DefaultHrtf;
    }
    ERR("Incompatible format: %s %uhz\n",
        DevFmtChannelsString(device->FmtChans), device->Frequency);
    return NULL;
}

void InitHrtf(void)
{
    char *fnamelist=NULL, *next=NULL;
    const char *val;

    if(ConfigValueStr(NULL, "hrtf_tables", &val))
        next = fnamelist = alc_strdup(val);
    while(next && *next)
    {
        const ALubyte maxDelay = SRC_HISTORY_LENGTH-1;
        struct Hrtf newdata;
        ALboolean failed;
        ALchar magic[9];
        ALsizei i, j;
        char *fname;
        FILE *f;

        fname = next;
        next = strchr(fname, ',');
        if(next)
        {
            while(next != fname)
            {
                next--;
                if(!isspace(*next))
                {
                    *(next++) = '\0';
                    break;
                }
            }
            while(isspace(*next) || *next == ',')
                next++;
        }

        if(!fname[0])
            continue;
        TRACE("Loading %s\n", fname);
        f = fopen(fname, "rb");
        if(f == NULL)
        {
            ERR("Could not open %s\n", fname);
            continue;
        }

        failed = AL_FALSE;
        if(fread(magic, 1, sizeof(magicMarker), f) != sizeof(magicMarker))
        {
            ERR("Failed to read magic marker\n");
            failed = AL_TRUE;
        }
        else if(memcmp(magic, magicMarker, sizeof(magicMarker)) != 0)
        {
            magic[8] = 0;
            ERR("Invalid magic marker: \"%s\"\n", magic);
            failed = AL_TRUE;
        }

        if(!failed)
        {
            ALushort hrirCount, hrirSize;
            ALubyte  evCount;

            newdata.sampleRate  = fgetc(f);
            newdata.sampleRate |= fgetc(f)<<8;
            newdata.sampleRate |= fgetc(f)<<16;
            newdata.sampleRate |= fgetc(f)<<24;

            hrirCount  = fgetc(f);
            hrirCount |= fgetc(f)<<8;

            hrirSize  = fgetc(f);
            hrirSize |= fgetc(f)<<8;

            evCount = fgetc(f);

            if(hrirCount != HRIR_COUNT || hrirSize != HRIR_LENGTH || evCount != ELEV_COUNT)
            {
                ERR("Unsupported value: hrirCount=%d (%d), hrirSize=%d (%d), evCount=%d (%d)\n",
                    hrirCount, HRIR_COUNT, hrirSize, HRIR_LENGTH, evCount, ELEV_COUNT);
                failed = AL_TRUE;
            }
        }

        if(!failed)
        {
            for(i = 0;i < HRIR_COUNT;i++)
            {
                ALushort offset;
                offset  = fgetc(f);
                offset |= fgetc(f)<<8;
                if(offset != evOffset[i])
                {
                    ERR("Unsupported evOffset[%d] value: %d (%d)\n", i, offset, evOffset[i]);
                    failed = AL_TRUE;
                }
            }
        }

        if(!failed)
        {
            for(i = 0;i < HRIR_COUNT;i++)
            {
                for(j = 0;j < HRIR_LENGTH;j++)
                {
                    ALshort coeff;
                    coeff  = fgetc(f);
                    coeff |= fgetc(f)<<8;
                    newdata.coeffs[i][j] = coeff;
                }
            }
            for(i = 0;i < HRIR_COUNT;i++)
            {
                ALubyte delay;
                delay = fgetc(f);
                newdata.delays[i] = delay;
                if(delay > maxDelay)
                {
                    ERR("Invalid delay[%d]: %d (%d)\n", i, delay, maxDelay);
                    failed = AL_TRUE;
                }
            }

            if(feof(f))
            {
                ERR("Premature end of data\n");
                failed = AL_TRUE;
            }
        }

        fclose(f);
        f = NULL;

        if(!failed)
        {
            void *temp = realloc(LoadedHrtfs, (NumLoadedHrtfs+1)*sizeof(LoadedHrtfs[0]));
            if(temp != NULL)
            {
                LoadedHrtfs = temp;
                TRACE("Loaded HRTF support for format: %s %uhz\n",
                      DevFmtChannelsString(DevFmtStereo), newdata.sampleRate);
                LoadedHrtfs[NumLoadedHrtfs++] = newdata;
            }
        }
        else
            ERR("Failed to load %s\n", fname);
    }
    free(fnamelist);
    fnamelist = NULL;
}

void FreeHrtf(void)
{
    NumLoadedHrtfs = 0;
    free(LoadedHrtfs);
    LoadedHrtfs = NULL;
}
