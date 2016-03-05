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

#include <sndio.h>


static const ALCchar sndio_device[] = "SndIO Default";


static void *sndio_handle;
#ifdef HAVE_DYNLOAD
#define MAKE_FUNC(x) static typeof(x) * p##x
MAKE_FUNC(sio_initpar);
MAKE_FUNC(sio_open);
MAKE_FUNC(sio_close);
MAKE_FUNC(sio_setpar);
MAKE_FUNC(sio_getpar);
MAKE_FUNC(sio_getcap);
MAKE_FUNC(sio_onmove);
MAKE_FUNC(sio_write);
MAKE_FUNC(sio_read);
MAKE_FUNC(sio_start);
MAKE_FUNC(sio_stop);
MAKE_FUNC(sio_nfds);
MAKE_FUNC(sio_pollfd);
MAKE_FUNC(sio_revents);
MAKE_FUNC(sio_eof);
MAKE_FUNC(sio_setvol);
MAKE_FUNC(sio_onvol);

#define sio_initpar psio_initpar
#define sio_open psio_open
#define sio_close psio_close
#define sio_setpar psio_setpar
#define sio_getpar psio_getpar
#define sio_getcap psio_getcap
#define sio_onmove psio_onmove
#define sio_write psio_write
#define sio_read psio_read
#define sio_start psio_start
#define sio_stop psio_stop
#define sio_nfds psio_nfds
#define sio_pollfd psio_pollfd
#define sio_revents psio_revents
#define sio_eof psio_eof
#define sio_setvol psio_setvol
#define sio_onvol psio_onvol
#endif


static ALCboolean sndio_load(void)
{
    if(!sndio_handle)
    {
#ifdef HAVE_DYNLOAD
        sndio_handle = LoadLib("libsndio.so");
        if(!sndio_handle)
            return ALC_FALSE;

#define LOAD_FUNC(f) do {                                                     \
    p##f = GetSymbol(sndio_handle, #f);                                       \
    if(p##f == NULL) {                                                        \
        CloseLib(sndio_handle);                                               \
        sndio_handle = NULL;                                                  \
        return ALC_FALSE;                                                     \
    }                                                                         \
} while(0)
        LOAD_FUNC(sio_initpar);
        LOAD_FUNC(sio_open);
        LOAD_FUNC(sio_close);
        LOAD_FUNC(sio_setpar);
        LOAD_FUNC(sio_getpar);
        LOAD_FUNC(sio_getcap);
        LOAD_FUNC(sio_onmove);
        LOAD_FUNC(sio_write);
        LOAD_FUNC(sio_read);
        LOAD_FUNC(sio_start);
        LOAD_FUNC(sio_stop);
        LOAD_FUNC(sio_nfds);
        LOAD_FUNC(sio_pollfd);
        LOAD_FUNC(sio_revents);
        LOAD_FUNC(sio_eof);
        LOAD_FUNC(sio_setvol);
        LOAD_FUNC(sio_onvol);
#undef LOAD_FUNC
#else
        sndio_handle = (void*)0xDEADBEEF;
#endif
    }
    return ALC_TRUE;
}


typedef struct {
    struct sio_hdl *sndHandle;

    ALvoid *mix_data;
    ALsizei data_size;

    volatile int killNow;
    ALvoid *thread;
} sndio_data;


static ALuint sndio_proc(ALvoid *ptr)
{
    ALCdevice *device = ptr;
    sndio_data *data = device->ExtraData;
    ALsizei frameSize;
    size_t wrote;

    SetRTPriority();

    frameSize = FrameSizeFromDevFmt(device->FmtChans, device->FmtType);

    while(!data->killNow && device->Connected)
    {
        ALsizei len = data->data_size;
        ALubyte *WritePtr = data->mix_data;

        aluMixData(device, WritePtr, len/frameSize);
        while(len > 0 && !data->killNow)
        {
            wrote = sio_write(data->sndHandle, WritePtr, len);
            if(wrote == 0)
            {
                ERR("sio_write failed\n");
                aluHandleDisconnect(device);
                break;
            }

            len -= wrote;
            WritePtr += wrote;
        }
    }

    return 0;
}



static ALCenum sndio_open_playback(ALCdevice *device, const ALCchar *deviceName)
{
    sndio_data *data;

    if(!deviceName)
        deviceName = sndio_device;
    else if(strcmp(deviceName, sndio_device) != 0)
        return ALC_INVALID_VALUE;

    data = calloc(1, sizeof(*data));
    data->killNow = 0;

    data->sndHandle = sio_open(NULL, SIO_PLAY, 0);
    if(data->sndHandle == NULL)
    {
        free(data);
        ERR("Could not open device\n");
        return ALC_INVALID_VALUE;
    }

    device->szDeviceName = strdup(deviceName);
    device->ExtraData = data;

    return ALC_NO_ERROR;
}

static void sndio_close_playback(ALCdevice *device)
{
    sndio_data *data = device->ExtraData;

    sio_close(data->sndHandle);
    free(data);
    device->ExtraData = NULL;
}

static ALCboolean sndio_reset_playback(ALCdevice *device)
{
    sndio_data *data = device->ExtraData;
    struct sio_par par;

    sio_initpar(&par);

    par.rate = device->Frequency;
    par.pchan = ((device->FmtChans != DevFmtMono) ? 2 : 1);

    switch(device->FmtType)
    {
        case DevFmtByte:
            par.bits = 8;
            par.sig = 1;
            break;
        case DevFmtUByte:
            par.bits = 8;
            par.sig = 0;
            break;
        case DevFmtFloat:
        case DevFmtShort:
            par.bits = 16;
            par.sig = 1;
            break;
        case DevFmtUShort:
            par.bits = 16;
            par.sig = 0;
            break;
    }
    par.le = SIO_LE_NATIVE;

    par.round = device->UpdateSize;
    par.appbufsz = device->UpdateSize * (device->NumUpdates-1);
    if(!par.appbufsz) par.appbufsz = device->UpdateSize;

    if(!sio_setpar(data->sndHandle, &par) || !sio_getpar(data->sndHandle, &par))
    {
        ERR("Failed to set device parameters\n");
        return ALC_FALSE;
    }

    if(par.bits != par.bps*8)
    {
        ERR("Padded samples not supported (%u of %u bits)\n", par.bits, par.bps*8);
        return ALC_FALSE;
    }

    device->Frequency = par.rate;
    device->FmtChans = ((par.pchan==1) ? DevFmtMono : DevFmtStereo);

    if(par.bits == 8 && par.sig == 1)
        device->FmtType = DevFmtByte;
    else if(par.bits == 8 && par.sig == 0)
        device->FmtType = DevFmtUByte;
    else if(par.bits == 16 && par.sig == 1)
        device->FmtType = DevFmtShort;
    else if(par.bits == 16 && par.sig == 0)
        device->FmtType = DevFmtUShort;
    else
    {
        ERR("Unhandled sample format: %s %u-bit\n", (par.sig?"signed":"unsigned"), par.bits);
        return ALC_FALSE;
    }

    device->UpdateSize = par.round;
    device->NumUpdates = (par.bufsz/par.round) + 1;

    SetDefaultChannelOrder(device);

    if(!sio_start(data->sndHandle))
    {
        ERR("Error starting playback\n");
        return ALC_FALSE;
    }

    data->data_size = device->UpdateSize * par.bps * par.pchan;
    data->mix_data = calloc(1, data->data_size);

    data->thread = StartThread(sndio_proc, device);
    if(data->thread == NULL)
    {
        sio_stop(data->sndHandle);
        free(data->mix_data);
        data->mix_data = NULL;
        return ALC_FALSE;
    }

    return ALC_TRUE;
}

static void sndio_stop_playback(ALCdevice *device)
{
    sndio_data *data = device->ExtraData;

    if(!data->thread)
        return;

    data->killNow = 1;
    StopThread(data->thread);
    data->thread = NULL;

    data->killNow = 0;
    if(!sio_stop(data->sndHandle))
        ERR("Error stopping device\n");

    free(data->mix_data);
    data->mix_data = NULL;
}


static const BackendFuncs sndio_funcs = {
    sndio_open_playback,
    sndio_close_playback,
    sndio_reset_playback,
    sndio_stop_playback,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

ALCboolean alc_sndio_init(BackendFuncs *func_list)
{
    if(!sndio_load())
        return ALC_FALSE;
    *func_list = sndio_funcs;
    return ALC_TRUE;
}

void alc_sndio_deinit(void)
{
#ifdef HAVE_DYNLOAD
    if(sndio_handle)
        CloseLib(sndio_handle);
    sndio_handle = NULL;
#endif
}

void alc_sndio_probe(enum DevProbe type)
{
    switch(type)
    {
        case DEVICE_PROBE:
            AppendDeviceList(sndio_device);
            break;
        case ALL_DEVICE_PROBE:
            AppendAllDeviceList(sndio_device);
            break;
        case CAPTURE_DEVICE_PROBE:
            break;
    }
}
