/**
 * OpenAL cross platform audio library
 * Copyright (C) 1999-2007 by authors.
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alMain.h"
#include "AL/al.h"
#include "AL/alc.h"

#include <portaudio.h>


static const ALCchar pa_device[] = "PortAudio Default";


static void *pa_handle;
#ifdef HAVE_DYNLOAD
#define MAKE_FUNC(x) static typeof(x) * p##x
MAKE_FUNC(Pa_Initialize);
MAKE_FUNC(Pa_Terminate);
MAKE_FUNC(Pa_GetErrorText);
MAKE_FUNC(Pa_StartStream);
MAKE_FUNC(Pa_StopStream);
MAKE_FUNC(Pa_OpenStream);
MAKE_FUNC(Pa_CloseStream);
MAKE_FUNC(Pa_GetDefaultOutputDevice);
MAKE_FUNC(Pa_GetStreamInfo);
#undef MAKE_FUNC

#define Pa_Initialize                  pPa_Initialize
#define Pa_Terminate                   pPa_Terminate
#define Pa_GetErrorText                pPa_GetErrorText
#define Pa_StartStream                 pPa_StartStream
#define Pa_StopStream                  pPa_StopStream
#define Pa_OpenStream                  pPa_OpenStream
#define Pa_CloseStream                 pPa_CloseStream
#define Pa_GetDefaultOutputDevice      pPa_GetDefaultOutputDevice
#define Pa_GetStreamInfo               pPa_GetStreamInfo
#endif

static ALCboolean pa_load(void)
{
    if(!pa_handle)
    {
        PaError err;

#ifdef HAVE_DYNLOAD
#ifdef _WIN32
# define PALIB "portaudio.dll"
#elif defined(__APPLE__) && defined(__MACH__)
# define PALIB "libportaudio.2.dylib"
#elif defined(__OpenBSD__)
# define PALIB "libportaudio.so"
#else
# define PALIB "libportaudio.so.2"
#endif

        pa_handle = LoadLib(PALIB);
        if(!pa_handle)
            return ALC_FALSE;

#define LOAD_FUNC(f) do {                                                     \
    p##f = GetSymbol(pa_handle, #f);                                          \
    if(p##f == NULL)                                                          \
    {                                                                         \
        CloseLib(pa_handle);                                                  \
        pa_handle = NULL;                                                     \
        return ALC_FALSE;                                                     \
    }                                                                         \
} while(0)
        LOAD_FUNC(Pa_Initialize);
        LOAD_FUNC(Pa_Terminate);
        LOAD_FUNC(Pa_GetErrorText);
        LOAD_FUNC(Pa_StartStream);
        LOAD_FUNC(Pa_StopStream);
        LOAD_FUNC(Pa_OpenStream);
        LOAD_FUNC(Pa_CloseStream);
        LOAD_FUNC(Pa_GetDefaultOutputDevice);
        LOAD_FUNC(Pa_GetStreamInfo);
#undef LOAD_FUNC
#else
        pa_handle = (void*)0xDEADBEEF;
#endif

        if((err=Pa_Initialize()) != paNoError)
        {
            ERR("Pa_Initialize() returned an error: %s\n", Pa_GetErrorText(err));
            CloseLib(pa_handle);
            pa_handle = NULL;
            return ALC_FALSE;
        }
    }
    return ALC_TRUE;
}


typedef struct {
    PaStream *stream;
    ALuint update_size;

    RingBuffer *ring;
} pa_data;


static int pa_callback(const void *inputBuffer, void *outputBuffer,
                       unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo,
                       const PaStreamCallbackFlags statusFlags, void *userData)
{
    ALCdevice *device = (ALCdevice*)userData;

    (void)inputBuffer;
    (void)timeInfo;
    (void)statusFlags;

    aluMixData(device, outputBuffer, framesPerBuffer);
    return 0;
}

static int pa_capture_cb(const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo *timeInfo,
                         const PaStreamCallbackFlags statusFlags, void *userData)
{
    ALCdevice *device = (ALCdevice*)userData;
    pa_data *data = (pa_data*)device->ExtraData;

    (void)outputBuffer;
    (void)timeInfo;
    (void)statusFlags;

    WriteRingBuffer(data->ring, inputBuffer, framesPerBuffer);
    return 0;
}


static ALCenum pa_open_playback(ALCdevice *device, const ALCchar *deviceName)
{
    PaStreamParameters outParams;
    pa_data *data;
    PaError err;

    if(!deviceName)
        deviceName = pa_device;
    else if(strcmp(deviceName, pa_device) != 0)
        return ALC_INVALID_VALUE;

    data = (pa_data*)calloc(1, sizeof(pa_data));
    data->update_size = device->UpdateSize;

    device->ExtraData = data;

    outParams.device = -1;
    if(!ConfigValueInt("port", "device", &outParams.device) || outParams.device < 0)
        outParams.device = Pa_GetDefaultOutputDevice();
    outParams.suggestedLatency = (device->UpdateSize*device->NumUpdates) /
                                 (float)device->Frequency;
    outParams.hostApiSpecificStreamInfo = NULL;

    outParams.channelCount = ((device->FmtChans == DevFmtMono) ? 1 : 2);

retry_open:
    switch(device->FmtType)
    {
        case DevFmtByte:
            outParams.sampleFormat = paInt8;
            break;
        case DevFmtUByte:
            outParams.sampleFormat = paUInt8;
            break;
        case DevFmtUShort:
            device->FmtType = DevFmtShort;
            /* fall-through */
        case DevFmtShort:
            outParams.sampleFormat = paInt16;
            break;
        case DevFmtFloat:
            outParams.sampleFormat = paFloat32;
            break;
    }

    err = Pa_OpenStream(&data->stream, NULL, &outParams, device->Frequency,
                        device->UpdateSize, paNoFlag, pa_callback, device);
    if(err != paNoError)
    {
        if(device->FmtType == DevFmtFloat)
        {
            device->FmtType = DevFmtShort;
            goto retry_open;
        }
        ERR("Pa_OpenStream() returned an error: %s\n", Pa_GetErrorText(err));
        device->ExtraData = NULL;
        free(data);
        return ALC_INVALID_VALUE;
    }

    device->szDeviceName = strdup(deviceName);

    if((ALuint)outParams.channelCount != ChannelsFromDevFmt(device->FmtChans))
    {
        if(outParams.channelCount != 1 && outParams.channelCount != 2)
        {
            ERR("Unhandled channel count: %u\n", outParams.channelCount);
            Pa_CloseStream(data->stream);
            device->ExtraData = NULL;
            free(data);
            return ALC_INVALID_VALUE;
        }
        if((device->Flags&DEVICE_CHANNELS_REQUEST))
            ERR("Failed to set %s, got %u channels instead\n", DevFmtChannelsString(device->FmtChans), outParams.channelCount);
        device->Flags &= ~DEVICE_CHANNELS_REQUEST;
        device->FmtChans = ((outParams.channelCount==1) ? DevFmtMono : DevFmtStereo);
    }
    SetDefaultChannelOrder(device);

    return ALC_NO_ERROR;
}

static void pa_close_playback(ALCdevice *device)
{
    pa_data *data = (pa_data*)device->ExtraData;
    PaError err;

    err = Pa_CloseStream(data->stream);
    if(err != paNoError)
        ERR("Error closing stream: %s\n", Pa_GetErrorText(err));

    free(data);
    device->ExtraData = NULL;
}

static ALCboolean pa_reset_playback(ALCdevice *device)
{
    pa_data *data = (pa_data*)device->ExtraData;
    const PaStreamInfo *streamInfo;
    PaError err;

    streamInfo = Pa_GetStreamInfo(data->stream);
    device->Frequency = streamInfo->sampleRate;
    device->UpdateSize = data->update_size;

    err = Pa_StartStream(data->stream);
    if(err != paNoError)
    {
        ERR("Pa_StartStream() returned an error: %s\n", Pa_GetErrorText(err));
        return ALC_FALSE;
    }

    return ALC_TRUE;
}

static void pa_stop_playback(ALCdevice *device)
{
    pa_data *data = (pa_data*)device->ExtraData;
    PaError err;

    err = Pa_StopStream(data->stream);
    if(err != paNoError)
        ERR("Error stopping stream: %s\n", Pa_GetErrorText(err));
}


static ALCenum pa_open_capture(ALCdevice *device, const ALCchar *deviceName)
{
    PaStreamParameters inParams;
    ALuint frame_size;
    pa_data *data;
    PaError err;

    if(!deviceName)
        deviceName = pa_device;
    else if(strcmp(deviceName, pa_device) != 0)
        return ALC_INVALID_VALUE;

    data = (pa_data*)calloc(1, sizeof(pa_data));
    if(data == NULL)
        return ALC_OUT_OF_MEMORY;

    frame_size = FrameSizeFromDevFmt(device->FmtChans, device->FmtType);
    data->ring = CreateRingBuffer(frame_size, device->UpdateSize*device->NumUpdates);
    if(data->ring == NULL)
        goto error;

    inParams.device = -1;
    if(!ConfigValueInt("port", "capture", &inParams.device) || inParams.device < 0)
        inParams.device = Pa_GetDefaultOutputDevice();
    inParams.suggestedLatency = 0.0f;
    inParams.hostApiSpecificStreamInfo = NULL;

    switch(device->FmtType)
    {
        case DevFmtByte:
            inParams.sampleFormat = paInt8;
            break;
        case DevFmtUByte:
            inParams.sampleFormat = paUInt8;
            break;
        case DevFmtShort:
            inParams.sampleFormat = paInt16;
            break;
        case DevFmtFloat:
            inParams.sampleFormat = paFloat32;
            break;
        case DevFmtUShort:
            ERR("Unsigned short samples not supported\n");
            goto error;
    }
    inParams.channelCount = ChannelsFromDevFmt(device->FmtChans);

    err = Pa_OpenStream(&data->stream, &inParams, NULL, device->Frequency,
                        paFramesPerBufferUnspecified, paNoFlag, pa_capture_cb, device);
    if(err != paNoError)
    {
        ERR("Pa_OpenStream() returned an error: %s\n", Pa_GetErrorText(err));
        goto error;
    }

    device->szDeviceName = strdup(deviceName);

    device->ExtraData = data;
    return ALC_NO_ERROR;

error:
    DestroyRingBuffer(data->ring);
    free(data);
    return ALC_INVALID_VALUE;
}

static void pa_close_capture(ALCdevice *device)
{
    pa_data *data = (pa_data*)device->ExtraData;
    PaError err;

    err = Pa_CloseStream(data->stream);
    if(err != paNoError)
        ERR("Error closing stream: %s\n", Pa_GetErrorText(err));

    free(data);
    device->ExtraData = NULL;
}

static void pa_start_capture(ALCdevice *device)
{
    pa_data *data = device->ExtraData;
    PaError err;

    err = Pa_StartStream(data->stream);
    if(err != paNoError)
        ERR("Error starting stream: %s\n", Pa_GetErrorText(err));
}

static void pa_stop_capture(ALCdevice *device)
{
    pa_data *data = (pa_data*)device->ExtraData;
    PaError err;

    err = Pa_StopStream(data->stream);
    if(err != paNoError)
        ERR("Error stopping stream: %s\n", Pa_GetErrorText(err));
}

static ALCenum pa_capture_samples(ALCdevice *device, ALCvoid *buffer, ALCuint samples)
{
    pa_data *data = device->ExtraData;
    ReadRingBuffer(data->ring, buffer, samples);
    return ALC_NO_ERROR;
}

static ALCuint pa_available_samples(ALCdevice *device)
{
    pa_data *data = device->ExtraData;
    return RingBufferSize(data->ring);
}


static const BackendFuncs pa_funcs = {
    pa_open_playback,
    pa_close_playback,
    pa_reset_playback,
    pa_stop_playback,
    pa_open_capture,
    pa_close_capture,
    pa_start_capture,
    pa_stop_capture,
    pa_capture_samples,
    pa_available_samples
};

ALCboolean alc_pa_init(BackendFuncs *func_list)
{
    if(!pa_load())
        return ALC_FALSE;
    *func_list = pa_funcs;
    return ALC_TRUE;
}

void alc_pa_deinit(void)
{
    if(pa_handle)
    {
        Pa_Terminate();
#ifdef HAVE_DYNLOAD
        CloseLib(pa_handle);
#endif
        pa_handle = NULL;
    }
}

void alc_pa_probe(enum DevProbe type)
{
    switch(type)
    {
        case DEVICE_PROBE:
            AppendDeviceList(pa_device);
            break;
        case ALL_DEVICE_PROBE:
            AppendAllDeviceList(pa_device);
            break;
        case CAPTURE_DEVICE_PROBE:
            AppendCaptureDeviceList(pa_device);
            break;
    }
}
