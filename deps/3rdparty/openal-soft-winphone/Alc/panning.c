/**
 * OpenAL cross platform audio library
 * Copyright (C) 1999-2010 by authors.
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

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "alMain.h"
#include "AL/al.h"
#include "AL/alc.h"
#include "alu.h"

static void SetSpeakerArrangement(const char *name, ALfloat SpeakerAngle[MAXCHANNELS],
                                  enum Channel Speaker2Chan[MAXCHANNELS], ALint chans)
{
    char *confkey, *next;
    char *layout_str;
    char *sep, *end;
    enum Channel val;
    const char *str;
    int i;

    if(!ConfigValueStr(NULL, name, &str) && !ConfigValueStr(NULL, "layout", &str))
        return;

    layout_str = alc_strdup(str);
    next = confkey = layout_str;
    while(next && *next)
    {
        confkey = next;
        next = strchr(confkey, ',');
        if(next)
        {
            *next = 0;
            do {
                next++;
            } while(isspace(*next) || *next == ',');
        }

        sep = strchr(confkey, '=');
        if(!sep || confkey == sep)
        {
            ERR("Malformed speaker key: %s\n", confkey);
            continue;
        }

        end = sep - 1;
        while(isspace(*end) && end != confkey)
            end--;
        *(++end) = 0;

        if(strcmp(confkey, "fl") == 0 || strcmp(confkey, "front-left") == 0)
            val = FRONT_LEFT;
        else if(strcmp(confkey, "fr") == 0 || strcmp(confkey, "front-right") == 0)
            val = FRONT_RIGHT;
        else if(strcmp(confkey, "fc") == 0 || strcmp(confkey, "front-center") == 0)
            val = FRONT_CENTER;
        else if(strcmp(confkey, "bl") == 0 || strcmp(confkey, "back-left") == 0)
            val = BACK_LEFT;
        else if(strcmp(confkey, "br") == 0 || strcmp(confkey, "back-right") == 0)
            val = BACK_RIGHT;
        else if(strcmp(confkey, "bc") == 0 || strcmp(confkey, "back-center") == 0)
            val = BACK_CENTER;
        else if(strcmp(confkey, "sl") == 0 || strcmp(confkey, "side-left") == 0)
            val = SIDE_LEFT;
        else if(strcmp(confkey, "sr") == 0 || strcmp(confkey, "side-right") == 0)
            val = SIDE_RIGHT;
        else
        {
            ERR("Unknown speaker for %s: \"%s\"\n", name, confkey);
            continue;
        }

        *(sep++) = 0;
        while(isspace(*sep))
            sep++;

        for(i = 0;i < chans;i++)
        {
            if(Speaker2Chan[i] == val)
            {
                long angle = strtol(sep, NULL, 10);
                if(angle >= -180 && angle <= 180)
                    SpeakerAngle[i] = angle * F_PI/180.0f;
                else
                    ERR("Invalid angle for speaker \"%s\": %ld\n", confkey, angle);
                break;
            }
        }
    }
    free(layout_str);
    layout_str = NULL;

    for(i = 0;i < chans;i++)
    {
        int min = i;
        int i2;

        for(i2 = i+1;i2 < chans;i2++)
        {
            if(SpeakerAngle[i2] < SpeakerAngle[min])
                min = i2;
        }

        if(min != i)
        {
            ALfloat tmpf;
            enum Channel tmpc;

            tmpf = SpeakerAngle[i];
            SpeakerAngle[i] = SpeakerAngle[min];
            SpeakerAngle[min] = tmpf;

            tmpc = Speaker2Chan[i];
            Speaker2Chan[i] = Speaker2Chan[min];
            Speaker2Chan[min] = tmpc;
        }
    }
}

static ALfloat aluLUTpos2Angle(ALint pos)
{
    if(pos < QUADRANT_NUM)
        return aluAtan((ALfloat)pos / (ALfloat)(QUADRANT_NUM - pos));
    if(pos < 2 * QUADRANT_NUM)
        return F_PI_2 + aluAtan((ALfloat)(pos - QUADRANT_NUM) / (ALfloat)(2 * QUADRANT_NUM - pos));
    if(pos < 3 * QUADRANT_NUM)
        return aluAtan((ALfloat)(pos - 2 * QUADRANT_NUM) / (ALfloat)(3 * QUADRANT_NUM - pos)) - F_PI;
    return aluAtan((ALfloat)(pos - 3 * QUADRANT_NUM) / (ALfloat)(4 * QUADRANT_NUM - pos)) - F_PI_2;
}

ALint aluCart2LUTpos(ALfloat re, ALfloat im)
{
    ALint pos = 0;
    ALfloat denom = aluFabs(re) + aluFabs(im);
    if(denom > 0.0f)
        pos = (ALint)(QUADRANT_NUM*aluFabs(im) / denom + 0.5);

    if(re < 0.0f)
        pos = 2 * QUADRANT_NUM - pos;
    if(im < 0.0f)
        pos = LUT_NUM - pos;
    return pos%LUT_NUM;
}

ALvoid aluInitPanning(ALCdevice *Device)
{
    ALfloat SpeakerAngle[MAXCHANNELS];
    enum Channel *Speaker2Chan;
    ALfloat Alpha, Theta;
    ALint pos;
    ALuint s;

    Speaker2Chan = Device->Speaker2Chan;
    switch(Device->FmtChans)
    {
        case DevFmtMono:
            Device->NumChan = 1;
            Speaker2Chan[0] = FRONT_CENTER;
            SpeakerAngle[0] = F_PI/180.0f * 0.0f;
            break;

        case DevFmtStereo:
            Device->NumChan = 2;
            Speaker2Chan[0] = FRONT_LEFT;
            Speaker2Chan[1] = FRONT_RIGHT;
            SpeakerAngle[0] = F_PI/180.0f * -90.0f;
            SpeakerAngle[1] = F_PI/180.0f *  90.0f;
            SetSpeakerArrangement("layout_STEREO", SpeakerAngle, Speaker2Chan, Device->NumChan);
            break;

        case DevFmtQuad:
            Device->NumChan = 4;
            Speaker2Chan[0] = BACK_LEFT;
            Speaker2Chan[1] = FRONT_LEFT;
            Speaker2Chan[2] = FRONT_RIGHT;
            Speaker2Chan[3] = BACK_RIGHT;
            SpeakerAngle[0] = F_PI/180.0f * -135.0f;
            SpeakerAngle[1] = F_PI/180.0f *  -45.0f;
            SpeakerAngle[2] = F_PI/180.0f *   45.0f;
            SpeakerAngle[3] = F_PI/180.0f *  135.0f;
            SetSpeakerArrangement("layout_QUAD", SpeakerAngle, Speaker2Chan, Device->NumChan);
            break;

        case DevFmtX51:
            Device->NumChan = 5;
            Speaker2Chan[0] = BACK_LEFT;
            Speaker2Chan[1] = FRONT_LEFT;
            Speaker2Chan[2] = FRONT_CENTER;
            Speaker2Chan[3] = FRONT_RIGHT;
            Speaker2Chan[4] = BACK_RIGHT;
            SpeakerAngle[0] = F_PI/180.0f * -110.0f;
            SpeakerAngle[1] = F_PI/180.0f *  -30.0f;
            SpeakerAngle[2] = F_PI/180.0f *    0.0f;
            SpeakerAngle[3] = F_PI/180.0f *   30.0f;
            SpeakerAngle[4] = F_PI/180.0f *  110.0f;
            SetSpeakerArrangement("layout_51CHN", SpeakerAngle, Speaker2Chan, Device->NumChan);
            break;

        case DevFmtX51Side:
            Device->NumChan = 5;
            Speaker2Chan[0] = SIDE_LEFT;
            Speaker2Chan[1] = FRONT_LEFT;
            Speaker2Chan[2] = FRONT_CENTER;
            Speaker2Chan[3] = FRONT_RIGHT;
            Speaker2Chan[4] = SIDE_RIGHT;
            SpeakerAngle[0] = F_PI/180.0f * -90.0f;
            SpeakerAngle[1] = F_PI/180.0f * -30.0f;
            SpeakerAngle[2] = F_PI/180.0f *   0.0f;
            SpeakerAngle[3] = F_PI/180.0f *  30.0f;
            SpeakerAngle[4] = F_PI/180.0f *  90.0f;
            SetSpeakerArrangement("layout_51SIDECHN", SpeakerAngle, Speaker2Chan, Device->NumChan);
            break;

        case DevFmtX61:
            Device->NumChan = 6;
            Speaker2Chan[0] = SIDE_LEFT;
            Speaker2Chan[1] = FRONT_LEFT;
            Speaker2Chan[2] = FRONT_CENTER;
            Speaker2Chan[3] = FRONT_RIGHT;
            Speaker2Chan[4] = SIDE_RIGHT;
            Speaker2Chan[5] = BACK_CENTER;
            SpeakerAngle[0] = F_PI/180.0f * -90.0f;
            SpeakerAngle[1] = F_PI/180.0f * -30.0f;
            SpeakerAngle[2] = F_PI/180.0f *   0.0f;
            SpeakerAngle[3] = F_PI/180.0f *  30.0f;
            SpeakerAngle[4] = F_PI/180.0f *  90.0f;
            SpeakerAngle[5] = F_PI/180.0f * 180.0f;
            SetSpeakerArrangement("layout_61CHN", SpeakerAngle, Speaker2Chan, Device->NumChan);
            break;

        case DevFmtX71:
            Device->NumChan = 7;
            Speaker2Chan[0] = BACK_LEFT;
            Speaker2Chan[1] = SIDE_LEFT;
            Speaker2Chan[2] = FRONT_LEFT;
            Speaker2Chan[3] = FRONT_CENTER;
            Speaker2Chan[4] = FRONT_RIGHT;
            Speaker2Chan[5] = SIDE_RIGHT;
            Speaker2Chan[6] = BACK_RIGHT;
            SpeakerAngle[0] = F_PI/180.0f * -150.0f;
            SpeakerAngle[1] = F_PI/180.0f *  -90.0f;
            SpeakerAngle[2] = F_PI/180.0f *  -30.0f;
            SpeakerAngle[3] = F_PI/180.0f *    0.0f;
            SpeakerAngle[4] = F_PI/180.0f *   30.0f;
            SpeakerAngle[5] = F_PI/180.0f *   90.0f;
            SpeakerAngle[6] = F_PI/180.0f *  150.0f;
            SetSpeakerArrangement("layout_71CHN", SpeakerAngle, Speaker2Chan, Device->NumChan);
            break;
    }

    for(pos = 0; pos < LUT_NUM; pos++)
    {
        ALfloat *PanningLUT = Device->PanningLUT[pos];

        /* clear all values */
        for(s = 0; s < MAXCHANNELS; s++)
            PanningLUT[s] = 0.0f;

        if(Device->NumChan == 1)
        {
            PanningLUT[Speaker2Chan[0]] = 1.0f;
            continue;
        }

        /* source angle */
        Theta = aluLUTpos2Angle(pos);

        /* set panning values */
        for(s = 0; s < Device->NumChan - 1; s++)
        {
            if(Theta >= SpeakerAngle[s] && Theta < SpeakerAngle[s+1])
            {
                /* source between speaker s and speaker s+1 */
                Alpha = (Theta-SpeakerAngle[s]) /
                        (SpeakerAngle[s+1]-SpeakerAngle[s]);
                PanningLUT[Speaker2Chan[s]]   = aluSqrt(1.0f-Alpha);
                PanningLUT[Speaker2Chan[s+1]] = aluSqrt(     Alpha);
                break;
            }
        }
        if(s == Device->NumChan - 1)
        {
            /* source between last and first speaker */
            if(Theta < SpeakerAngle[0])
                Theta += F_PI*2.0f;
            Alpha = (Theta-SpeakerAngle[s]) /
                    (F_PI*2.0f + SpeakerAngle[0]-SpeakerAngle[s]);
            PanningLUT[Speaker2Chan[s]] = aluSqrt(1.0f-Alpha);
            PanningLUT[Speaker2Chan[0]] = aluSqrt(     Alpha);
        }
    }
}
