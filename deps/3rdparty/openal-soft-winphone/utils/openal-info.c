/*
 * OpenAL Info Utility
 *
 * Copyright (c) 2010 by Chris Robinson <chris.kcat@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>
#include <string.h>

#include "AL/alc.h"
#include "AL/al.h"
#include "AL/alext.h"

#ifndef ALC_ENUMERATE_ALL_EXT
#define ALC_DEFAULT_ALL_DEVICES_SPECIFIER        0x1012
#define ALC_ALL_DEVICES_SPECIFIER                0x1013
#endif

#ifndef ALC_EXT_EFX
#define ALC_EFX_MAJOR_VERSION                    0x20001
#define ALC_EFX_MINOR_VERSION                    0x20002
#define ALC_MAX_AUXILIARY_SENDS                  0x20003
#endif


#define MAX_WIDTH  80

static void printList(const char *list, char separator)
{
    size_t col = MAX_WIDTH, len;
    const char *indent = "    ";
    const char *next;

    if(!list || *list == '\0')
    {
        fprintf(stdout, "\n%s!!! none !!!\n", indent);
        return;
    }

    do {
        next = strchr(list, separator);
        if(next)
        {
            len = next-list;
            do {
                next++;
            } while(*next == separator);
        }
        else
            len = strlen(list);

        if(len + col + 2 >= MAX_WIDTH)
        {
            fprintf(stdout, "\n%s", indent);
            col = strlen(indent);
        }
        else
        {
            fputc(' ', stdout);
            col++;
        }

        len = fwrite(list, 1, len, stdout);
        col += len;

        if(!next || *next == '\0')
            break;
        fputc(',', stdout);
        col++;

        list = next;
    } while(1);
    fputc('\n', stdout);
}

static void printDeviceList(const char *list)
{
    if(!list || *list == '\0')
        printf("    !!! none !!!\n");
    else do {
        printf("    %s\n", list);
        list += strlen(list) + 1;
    } while(*list != '\0');
}


static ALenum checkALErrors(int linenum)
{
    ALenum err = alGetError();
    if(err != AL_NO_ERROR)
        printf("OpenAL Error: %s (0x%x), @ %d\n", alGetString(err), err, linenum);
    return err;
}
#define checkALErrors() checkALErrors(__LINE__)

static ALCenum checkALCErrors(ALCdevice *device, int linenum)
{
    ALCenum err = alcGetError(device);
    if(err != ALC_NO_ERROR)
        printf("ALC Error: %s (0x%x), @ %d\n", alcGetString(device, err), err, linenum);
    return err;
}
#define checkALCErrors(x) checkALCErrors((x),__LINE__)


static void printALCInfo(ALCdevice *device)
{
    ALCint major, minor;

    alcGetIntegerv(device, ALC_MAJOR_VERSION, 1, &major);
    alcGetIntegerv(device, ALC_MINOR_VERSION, 1, &minor);
    if(checkALCErrors(device) == ALC_NO_ERROR)
        printf("ALC version: %d.%d\n", major, minor);
    if(device)
    {
        printf("ALC extensions:");
        printList(alcGetString(device, ALC_EXTENSIONS), ' ');
        checkALCErrors(device);
    }
}

static void printALInfo(void)
{
    printf("OpenAL vendor string: %s\n", alGetString(AL_VENDOR));
    printf("OpenAL renderer string: %s\n", alGetString(AL_RENDERER));
    printf("OpenAL version string: %s\n", alGetString(AL_VERSION));
    printf("OpenAL extensions:");
    printList(alGetString(AL_EXTENSIONS), ' ');
    checkALErrors();
}

static void printEFXInfo(ALCdevice *device)
{
    ALCint major, minor, sends;
    static const ALchar filters[][32] = {
        "AL_FILTER_LOWPASS", "AL_FILTER_HIGHPASS", "AL_FILTER_BANDPASS", ""
    };
    char filterNames[] = "Low-pass,High-pass,Band-pass,";
    static const ALchar effects[][32] = {
        "AL_EFFECT_EAXREVERB", "AL_EFFECT_REVERB", "AL_EFFECT_CHORUS",
        "AL_EFFECT_DISTORTION", "AL_EFFECT_ECHO", "AL_EFFECT_FLANGER",
        "AL_EFFECT_FREQUENCY_SHIFTER", "AL_EFFECT_VOCAL_MORPHER",
        "AL_EFFECT_PITCH_SHIFTER", "AL_EFFECT_RING_MODULATOR",
        "AL_EFFECT_AUTOWAH", "AL_EFFECT_COMPRESSOR", "AL_EFFECT_EQUALIZER", ""
    };
    static const ALchar dedeffects[][64] = {
        "AL_EFFECT_DEDICATED_DIALOGUE",
        "AL_EFFECT_DEDICATED_LOW_FREQUENCY_EFFECT", ""
    };
    char effectNames[] = "EAX Reverb,Reverb,Chorus,Distortion,Echo,Flanger,"
                         "Frequency Shifter,Vocal Morpher,Pitch Shifter,"
                         "Ring Modulator,Autowah,Compressor,Equalizer,"
                         "Dedicated Dialog,Dedicated LFE,";
    char *current;
    int i;

    if(alcIsExtensionPresent(device, "ALC_EXT_EFX") == AL_FALSE)
    {
        printf("EFX not available\n");
        return;
    }

    alcGetIntegerv(device, ALC_EFX_MAJOR_VERSION, 1, &major);
    alcGetIntegerv(device, ALC_EFX_MINOR_VERSION, 1, &minor);
    if(checkALCErrors(device) == ALC_NO_ERROR)
        printf("EFX version: %d.%d\n", major, minor);
    alcGetIntegerv(device, ALC_MAX_AUXILIARY_SENDS, 1, &sends);
    if(checkALCErrors(device) == ALC_NO_ERROR)
        printf("Max auxiliary sends: %d\n", sends);

    current = filterNames;
    for(i = 0;filters[i][0];i++)
    {
        char *next = strchr(current, ',');
        ALenum val;

        val = alGetEnumValue(filters[i]);
        if(alGetError() != AL_NO_ERROR || val == 0 || val == -1)
            memmove(current, next+1, strlen(next));
        else
            current = next+1;
    }
    printf("Supported filters:");
    printList(filterNames, ',');

    current = effectNames;
    for(i = 0;effects[i][0];i++)
    {
        char *next = strchr(current, ',');
        ALenum val;

        val = alGetEnumValue(effects[i]);
        if(alGetError() != AL_NO_ERROR || val == 0 || val == -1)
            memmove(current, next+1, strlen(next));
        else
            current = next+1;
    }
    if(alcIsExtensionPresent(device, "ALC_EXT_DEDICATED"))
    {
        for(i = 0;dedeffects[i][0];i++)
        {
            char *next = strchr(current, ',');
            ALenum val;

            val = alGetEnumValue(dedeffects[i]);
            if(alGetError() != AL_NO_ERROR || val == 0 || val == -1)
                memmove(current, next+1, strlen(next));
            else
                current = next+1;
        }
    }
    else
    {
        for(i = 0;dedeffects[i][0];i++)
        {
            char *next = strchr(current, ',');
            memmove(current, next+1, strlen(next));
        }
    }
    printf("Supported effects:");
    printList(effectNames, ',');
}

int main(int argc, char *argv[])
{
    ALCdevice *device;
    ALCcontext *context;

    if(argc > 1 && (strcmp(argv[1], "--help") == 0 ||
                    strcmp(argv[1], "-h") == 0))
    {
        printf("Usage: %s [playback device]\n", argv[0]);
        return 0;
    }

    printf("Available playback devices:\n");
    if(alcIsExtensionPresent(NULL, "ALC_ENUMERATE_ALL_EXT") != AL_FALSE)
        printDeviceList(alcGetString(NULL, ALC_ALL_DEVICES_SPECIFIER));
    else
        printDeviceList(alcGetString(NULL, ALC_DEVICE_SPECIFIER));
    printf("Available capture devices:\n");
    printDeviceList(alcGetString(NULL, ALC_CAPTURE_DEVICE_SPECIFIER));

    if(alcIsExtensionPresent(NULL, "ALC_ENUMERATE_ALL_EXT") != AL_FALSE)
        printf("Default playback device: %s\n",
               alcGetString(NULL, ALC_DEFAULT_ALL_DEVICES_SPECIFIER));
    else
        printf("Default playback device: %s\n",
               alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER));
    printf("Default capture device: %s\n",
           alcGetString(NULL, ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER));

    printALCInfo(NULL);

    device = alcOpenDevice((argc>1) ? argv[1] : NULL);
    if(!device)
    {
        printf("\n!!! Failed to open %s !!!\n\n", ((argc>1) ? argv[1] : "default device"));
        return 1;
    }

    printf("\n** Info for device \"%s\" **\n", alcGetString(device, ALC_DEVICE_SPECIFIER));
    printALCInfo(device);

    context = alcCreateContext(device, NULL);
    if(!context || alcMakeContextCurrent(context) == ALC_FALSE)
    {
        if(context)
            alcDestroyContext(context);
        alcCloseDevice(device);
        printf("\n!!! Failed to set a context !!!\n\n");
        return 1;
    }

    printALInfo();
    printEFXInfo(device);

    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
    alcCloseDevice(device);

    return 0;
}
