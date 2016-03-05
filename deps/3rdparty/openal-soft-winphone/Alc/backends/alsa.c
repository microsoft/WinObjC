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

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#include "alMain.h"

#include <alsa/asoundlib.h>


static const ALCchar alsaDevice[] = "ALSA Default";


static void *alsa_handle;
#ifdef HAVE_DYNLOAD
#define MAKE_FUNC(f) static typeof(f) * p##f
MAKE_FUNC(snd_strerror);
MAKE_FUNC(snd_pcm_open);
MAKE_FUNC(snd_pcm_close);
MAKE_FUNC(snd_pcm_nonblock);
MAKE_FUNC(snd_pcm_frames_to_bytes);
MAKE_FUNC(snd_pcm_bytes_to_frames);
MAKE_FUNC(snd_pcm_hw_params_malloc);
MAKE_FUNC(snd_pcm_hw_params_free);
MAKE_FUNC(snd_pcm_hw_params_any);
MAKE_FUNC(snd_pcm_hw_params_set_access);
MAKE_FUNC(snd_pcm_hw_params_set_format);
MAKE_FUNC(snd_pcm_hw_params_set_channels);
MAKE_FUNC(snd_pcm_hw_params_set_periods_near);
MAKE_FUNC(snd_pcm_hw_params_set_rate_near);
MAKE_FUNC(snd_pcm_hw_params_set_rate);
MAKE_FUNC(snd_pcm_hw_params_set_rate_resample);
MAKE_FUNC(snd_pcm_hw_params_set_buffer_time_near);
MAKE_FUNC(snd_pcm_hw_params_set_period_time_near);
MAKE_FUNC(snd_pcm_hw_params_set_buffer_size_near);
MAKE_FUNC(snd_pcm_hw_params_set_period_size_near);
MAKE_FUNC(snd_pcm_hw_params_set_buffer_size_min);
MAKE_FUNC(snd_pcm_hw_params_get_buffer_size);
MAKE_FUNC(snd_pcm_hw_params_get_period_size);
MAKE_FUNC(snd_pcm_hw_params_get_access);
MAKE_FUNC(snd_pcm_hw_params_get_periods);
MAKE_FUNC(snd_pcm_hw_params);
MAKE_FUNC(snd_pcm_sw_params_malloc);
MAKE_FUNC(snd_pcm_sw_params_current);
MAKE_FUNC(snd_pcm_sw_params_set_avail_min);
MAKE_FUNC(snd_pcm_sw_params_set_stop_threshold);
MAKE_FUNC(snd_pcm_sw_params);
MAKE_FUNC(snd_pcm_sw_params_free);
MAKE_FUNC(snd_pcm_prepare);
MAKE_FUNC(snd_pcm_start);
MAKE_FUNC(snd_pcm_resume);
MAKE_FUNC(snd_pcm_reset);
MAKE_FUNC(snd_pcm_wait);
MAKE_FUNC(snd_pcm_state);
MAKE_FUNC(snd_pcm_avail_update);
MAKE_FUNC(snd_pcm_areas_silence);
MAKE_FUNC(snd_pcm_mmap_begin);
MAKE_FUNC(snd_pcm_mmap_commit);
MAKE_FUNC(snd_pcm_readi);
MAKE_FUNC(snd_pcm_writei);
MAKE_FUNC(snd_pcm_drain);
MAKE_FUNC(snd_pcm_recover);
MAKE_FUNC(snd_pcm_info_malloc);
MAKE_FUNC(snd_pcm_info_free);
MAKE_FUNC(snd_pcm_info_set_device);
MAKE_FUNC(snd_pcm_info_set_subdevice);
MAKE_FUNC(snd_pcm_info_set_stream);
MAKE_FUNC(snd_pcm_info_get_name);
MAKE_FUNC(snd_ctl_pcm_next_device);
MAKE_FUNC(snd_ctl_pcm_info);
MAKE_FUNC(snd_ctl_open);
MAKE_FUNC(snd_ctl_close);
MAKE_FUNC(snd_ctl_card_info_malloc);
MAKE_FUNC(snd_ctl_card_info_free);
MAKE_FUNC(snd_ctl_card_info);
MAKE_FUNC(snd_ctl_card_info_get_name);
MAKE_FUNC(snd_ctl_card_info_get_id);
MAKE_FUNC(snd_card_next);
#undef MAKE_FUNC

#define snd_strerror psnd_strerror
#define snd_pcm_open psnd_pcm_open
#define snd_pcm_close psnd_pcm_close
#define snd_pcm_nonblock psnd_pcm_nonblock
#define snd_pcm_frames_to_bytes psnd_pcm_frames_to_bytes
#define snd_pcm_bytes_to_frames psnd_pcm_bytes_to_frames
#define snd_pcm_hw_params_malloc psnd_pcm_hw_params_malloc
#define snd_pcm_hw_params_free psnd_pcm_hw_params_free
#define snd_pcm_hw_params_any psnd_pcm_hw_params_any
#define snd_pcm_hw_params_set_access psnd_pcm_hw_params_set_access
#define snd_pcm_hw_params_set_format psnd_pcm_hw_params_set_format
#define snd_pcm_hw_params_set_channels psnd_pcm_hw_params_set_channels
#define snd_pcm_hw_params_set_periods_near psnd_pcm_hw_params_set_periods_near
#define snd_pcm_hw_params_set_rate_near psnd_pcm_hw_params_set_rate_near
#define snd_pcm_hw_params_set_rate psnd_pcm_hw_params_set_rate
#define snd_pcm_hw_params_set_rate_resample psnd_pcm_hw_params_set_rate_resample
#define snd_pcm_hw_params_set_buffer_time_near psnd_pcm_hw_params_set_buffer_time_near
#define snd_pcm_hw_params_set_period_time_near psnd_pcm_hw_params_set_period_time_near
#define snd_pcm_hw_params_set_buffer_size_near psnd_pcm_hw_params_set_buffer_size_near
#define snd_pcm_hw_params_set_period_size_near psnd_pcm_hw_params_set_period_size_near
#define snd_pcm_hw_params_set_buffer_size_min psnd_pcm_hw_params_set_buffer_size_min
#define snd_pcm_hw_params_get_buffer_size psnd_pcm_hw_params_get_buffer_size
#define snd_pcm_hw_params_get_period_size psnd_pcm_hw_params_get_period_size
#define snd_pcm_hw_params_get_access psnd_pcm_hw_params_get_access
#define snd_pcm_hw_params_get_periods psnd_pcm_hw_params_get_periods
#define snd_pcm_hw_params psnd_pcm_hw_params
#define snd_pcm_sw_params_malloc psnd_pcm_sw_params_malloc
#define snd_pcm_sw_params_current psnd_pcm_sw_params_current
#define snd_pcm_sw_params_set_avail_min psnd_pcm_sw_params_set_avail_min
#define snd_pcm_sw_params_set_stop_threshold psnd_pcm_sw_params_set_stop_threshold
#define snd_pcm_sw_params psnd_pcm_sw_params
#define snd_pcm_sw_params_free psnd_pcm_sw_params_free
#define snd_pcm_prepare psnd_pcm_prepare
#define snd_pcm_start psnd_pcm_start
#define snd_pcm_resume psnd_pcm_resume
#define snd_pcm_reset psnd_pcm_reset
#define snd_pcm_wait psnd_pcm_wait
#define snd_pcm_state psnd_pcm_state
#define snd_pcm_avail_update psnd_pcm_avail_update
#define snd_pcm_areas_silence psnd_pcm_areas_silence
#define snd_pcm_mmap_begin psnd_pcm_mmap_begin
#define snd_pcm_mmap_commit psnd_pcm_mmap_commit
#define snd_pcm_readi psnd_pcm_readi
#define snd_pcm_writei psnd_pcm_writei
#define snd_pcm_drain psnd_pcm_drain
#define snd_pcm_recover psnd_pcm_recover
#define snd_pcm_info_malloc psnd_pcm_info_malloc
#define snd_pcm_info_free psnd_pcm_info_free
#define snd_pcm_info_set_device psnd_pcm_info_set_device
#define snd_pcm_info_set_subdevice psnd_pcm_info_set_subdevice
#define snd_pcm_info_set_stream psnd_pcm_info_set_stream
#define snd_pcm_info_get_name psnd_pcm_info_get_name
#define snd_ctl_pcm_next_device psnd_ctl_pcm_next_device
#define snd_ctl_pcm_info psnd_ctl_pcm_info
#define snd_ctl_open psnd_ctl_open
#define snd_ctl_close psnd_ctl_close
#define snd_ctl_card_info_malloc psnd_ctl_card_info_malloc
#define snd_ctl_card_info_free psnd_ctl_card_info_free
#define snd_ctl_card_info psnd_ctl_card_info
#define snd_ctl_card_info_get_name psnd_ctl_card_info_get_name
#define snd_ctl_card_info_get_id psnd_ctl_card_info_get_id
#define snd_card_next psnd_card_next
#endif


static ALCboolean alsa_load(void)
{
    if(!alsa_handle)
    {
#ifdef HAVE_DYNLOAD
        alsa_handle = LoadLib("libasound.so.2");
        if(!alsa_handle)
            return ALC_FALSE;

#define LOAD_FUNC(f) do {                                                     \
    p##f = GetSymbol(alsa_handle, #f);                                        \
    if(p##f == NULL) {                                                        \
        CloseLib(alsa_handle);                                                \
        alsa_handle = NULL;                                                   \
        return ALC_FALSE;                                                     \
    }                                                                         \
} while(0)
        LOAD_FUNC(snd_strerror);
        LOAD_FUNC(snd_pcm_open);
        LOAD_FUNC(snd_pcm_close);
        LOAD_FUNC(snd_pcm_nonblock);
        LOAD_FUNC(snd_pcm_frames_to_bytes);
        LOAD_FUNC(snd_pcm_bytes_to_frames);
        LOAD_FUNC(snd_pcm_hw_params_malloc);
        LOAD_FUNC(snd_pcm_hw_params_free);
        LOAD_FUNC(snd_pcm_hw_params_any);
        LOAD_FUNC(snd_pcm_hw_params_set_access);
        LOAD_FUNC(snd_pcm_hw_params_set_format);
        LOAD_FUNC(snd_pcm_hw_params_set_channels);
        LOAD_FUNC(snd_pcm_hw_params_set_periods_near);
        LOAD_FUNC(snd_pcm_hw_params_set_rate_near);
        LOAD_FUNC(snd_pcm_hw_params_set_rate);
        LOAD_FUNC(snd_pcm_hw_params_set_rate_resample);
        LOAD_FUNC(snd_pcm_hw_params_set_buffer_time_near);
        LOAD_FUNC(snd_pcm_hw_params_set_period_time_near);
        LOAD_FUNC(snd_pcm_hw_params_set_buffer_size_near);
        LOAD_FUNC(snd_pcm_hw_params_set_buffer_size_min);
        LOAD_FUNC(snd_pcm_hw_params_set_period_size_near);
        LOAD_FUNC(snd_pcm_hw_params_get_buffer_size);
        LOAD_FUNC(snd_pcm_hw_params_get_period_size);
        LOAD_FUNC(snd_pcm_hw_params_get_access);
        LOAD_FUNC(snd_pcm_hw_params_get_periods);
        LOAD_FUNC(snd_pcm_hw_params);
        LOAD_FUNC(snd_pcm_sw_params_malloc);
        LOAD_FUNC(snd_pcm_sw_params_current);
        LOAD_FUNC(snd_pcm_sw_params_set_avail_min);
        LOAD_FUNC(snd_pcm_sw_params_set_stop_threshold);
        LOAD_FUNC(snd_pcm_sw_params);
        LOAD_FUNC(snd_pcm_sw_params_free);
        LOAD_FUNC(snd_pcm_prepare);
        LOAD_FUNC(snd_pcm_start);
        LOAD_FUNC(snd_pcm_resume);
        LOAD_FUNC(snd_pcm_reset);
        LOAD_FUNC(snd_pcm_wait);
        LOAD_FUNC(snd_pcm_state);
        LOAD_FUNC(snd_pcm_avail_update);
        LOAD_FUNC(snd_pcm_areas_silence);
        LOAD_FUNC(snd_pcm_mmap_begin);
        LOAD_FUNC(snd_pcm_mmap_commit);
        LOAD_FUNC(snd_pcm_readi);
        LOAD_FUNC(snd_pcm_writei);
        LOAD_FUNC(snd_pcm_drain);
        LOAD_FUNC(snd_pcm_recover);
        LOAD_FUNC(snd_pcm_info_malloc);
        LOAD_FUNC(snd_pcm_info_free);
        LOAD_FUNC(snd_pcm_info_set_device);
        LOAD_FUNC(snd_pcm_info_set_subdevice);
        LOAD_FUNC(snd_pcm_info_set_stream);
        LOAD_FUNC(snd_pcm_info_get_name);
        LOAD_FUNC(snd_ctl_pcm_next_device);
        LOAD_FUNC(snd_ctl_pcm_info);
        LOAD_FUNC(snd_ctl_open);
        LOAD_FUNC(snd_ctl_close);
        LOAD_FUNC(snd_ctl_card_info_malloc);
        LOAD_FUNC(snd_ctl_card_info_free);
        LOAD_FUNC(snd_ctl_card_info);
        LOAD_FUNC(snd_ctl_card_info_get_name);
        LOAD_FUNC(snd_ctl_card_info_get_id);
        LOAD_FUNC(snd_card_next);
#undef LOAD_FUNC
#else
        alsa_handle = (void*)0xDEADBEEF;
#endif
    }
    return ALC_TRUE;
}


typedef struct {
    snd_pcm_t *pcmHandle;

    ALvoid *buffer;
    ALsizei size;

    ALboolean doCapture;
    RingBuffer *ring;

    volatile int killNow;
    ALvoid *thread;
} alsa_data;

typedef struct {
    ALCchar *name;
    char *card;
    int dev;
} DevMap;

static DevMap *allDevNameMap;
static ALuint numDevNames;
static DevMap *allCaptureDevNameMap;
static ALuint numCaptureDevNames;

static const char *device_prefix;
static const char *capture_prefix;


static DevMap *probe_devices(snd_pcm_stream_t stream, ALuint *count)
{
    snd_ctl_t *handle;
    int card, err, dev, idx;
    snd_ctl_card_info_t *info;
    snd_pcm_info_t *pcminfo;
    DevMap *DevList;
    char name[1024];

    snd_ctl_card_info_malloc(&info);
    snd_pcm_info_malloc(&pcminfo);

    card = -1;
    if((err=snd_card_next(&card)) < 0)
        ERR("Failed to find a card: %s\n", snd_strerror(err));

    DevList = malloc(sizeof(DevMap) * 1);
    DevList[0].name = strdup("ALSA Default");
    DevList[0].card = NULL;
    DevList[0].dev = 0;
    idx = 1;
    while(card >= 0)
    {
        sprintf(name, "hw:%d", card);
        if((err = snd_ctl_open(&handle, name, 0)) < 0)
        {
            ERR("control open (%i): %s\n", card, snd_strerror(err));
            goto next_card;
        }
        if((err = snd_ctl_card_info(handle, info)) < 0)
        {
            ERR("control hardware info (%i): %s\n", card, snd_strerror(err));
            snd_ctl_close(handle);
            goto next_card;
        }

        dev = -1;
        while(1)
        {
            const char *cname, *dname, *cid;
            void *temp;

            if(snd_ctl_pcm_next_device(handle, &dev) < 0)
                ERR("snd_ctl_pcm_next_device failed\n");
            if(dev < 0)
                break;

            snd_pcm_info_set_device(pcminfo, dev);
            snd_pcm_info_set_subdevice(pcminfo, 0);
            snd_pcm_info_set_stream(pcminfo, stream);
            if((err = snd_ctl_pcm_info(handle, pcminfo)) < 0) {
                if(err != -ENOENT)
                    ERR("control digital audio info (%i): %s\n", card, snd_strerror(err));
                continue;
            }

            temp = realloc(DevList, sizeof(DevMap) * (idx+1));
            if(temp)
            {
                DevList = temp;
                cname = snd_ctl_card_info_get_name(info);
                dname = snd_pcm_info_get_name(pcminfo);
                cid = snd_ctl_card_info_get_id(info);
                snprintf(name, sizeof(name), "%s, %s (CARD=%s,DEV=%d)",
                         cname, dname, cid, dev);
                DevList[idx].name = strdup(name);
                DevList[idx].card = strdup(cid);
                DevList[idx].dev = dev;
                idx++;
            }
        }
        snd_ctl_close(handle);
    next_card:
        if(snd_card_next(&card) < 0) {
            ERR("snd_card_next failed\n");
            break;
        }
    }

    snd_pcm_info_free(pcminfo);
    snd_ctl_card_info_free(info);

    *count = idx;
    return DevList;
}


static int xrun_recovery(snd_pcm_t *handle, int err)
{
    err = snd_pcm_recover(handle, err, 1);
    if(err < 0)
        ERR("recover failed: %s\n", snd_strerror(err));
    return err;
}

static int verify_state(snd_pcm_t *handle)
{
    snd_pcm_state_t state = snd_pcm_state(handle);
    if(state == SND_PCM_STATE_DISCONNECTED)
        return -ENODEV;
    if(state == SND_PCM_STATE_XRUN)
    {
        int err = xrun_recovery(handle, -EPIPE);
        if(err < 0) return err;
    }
    else if(state == SND_PCM_STATE_SUSPENDED)
    {
        int err = xrun_recovery(handle, -ESTRPIPE);
        if(err < 0) return err;
    }

    return state;
}


static ALuint ALSAProc(ALvoid *ptr)
{
    ALCdevice *pDevice = (ALCdevice*)ptr;
    alsa_data *data = (alsa_data*)pDevice->ExtraData;
    const snd_pcm_channel_area_t *areas = NULL;
    snd_pcm_uframes_t update_size, num_updates;
    snd_pcm_sframes_t avail, commitres;
    snd_pcm_uframes_t offset, frames;
    char *WritePtr;
    int err;

    SetRTPriority();

    update_size = pDevice->UpdateSize;
    num_updates = pDevice->NumUpdates;
    while(!data->killNow)
    {
        int state = verify_state(data->pcmHandle);
        if(state < 0)
        {
            ERR("Invalid state detected: %s\n", snd_strerror(state));
            aluHandleDisconnect(pDevice);
            break;
        }

        avail = snd_pcm_avail_update(data->pcmHandle);
        if(avail < 0)
        {
            ERR("available update failed: %s\n", snd_strerror(avail));
            continue;
        }

        if((snd_pcm_uframes_t)avail > update_size*(num_updates+1))
        {
            WARN("available samples exceeds the buffer size\n");
            snd_pcm_reset(data->pcmHandle);
            continue;
        }

        // make sure there's frames to process
        if((snd_pcm_uframes_t)avail < update_size)
        {
            if(state != SND_PCM_STATE_RUNNING)
            {
                err = snd_pcm_start(data->pcmHandle);
                if(err < 0)
                {
                    ERR("start failed: %s\n", snd_strerror(err));
                    continue;
                }
            }
            if(snd_pcm_wait(data->pcmHandle, 1000) == 0)
                ERR("Wait timeout... buffer size too low?\n");
            continue;
        }
        avail -= avail%update_size;

        // it is possible that contiguous areas are smaller, thus we use a loop
        while(avail > 0)
        {
            frames = avail;

            err = snd_pcm_mmap_begin(data->pcmHandle, &areas, &offset, &frames);
            if(err < 0)
            {
                ERR("mmap begin error: %s\n", snd_strerror(err));
                break;
            }

            WritePtr = (char*)areas->addr + (offset * areas->step / 8);
            aluMixData(pDevice, WritePtr, frames);

            commitres = snd_pcm_mmap_commit(data->pcmHandle, offset, frames);
            if(commitres < 0 || (commitres-frames) != 0)
            {
                ERR("mmap commit error: %s\n",
                    snd_strerror(commitres >= 0 ? -EPIPE : commitres));
                break;
            }

            avail -= frames;
        }
    }

    return 0;
}

static ALuint ALSANoMMapProc(ALvoid *ptr)
{
    ALCdevice *pDevice = (ALCdevice*)ptr;
    alsa_data *data = (alsa_data*)pDevice->ExtraData;
    snd_pcm_sframes_t avail;
    char *WritePtr;

    SetRTPriority();

    while(!data->killNow)
    {
        int state = verify_state(data->pcmHandle);
        if(state < 0)
        {
            ERR("Invalid state detected: %s\n", snd_strerror(state));
            aluHandleDisconnect(pDevice);
            break;
        }

        WritePtr = data->buffer;
        avail = data->size / snd_pcm_frames_to_bytes(data->pcmHandle, 1);
        aluMixData(pDevice, WritePtr, avail);

        while(avail > 0)
        {
            int ret = snd_pcm_writei(data->pcmHandle, WritePtr, avail);
            switch (ret)
            {
            case -EAGAIN:
                continue;
            case -ESTRPIPE:
            case -EPIPE:
            case -EINTR:
                ret = snd_pcm_recover(data->pcmHandle, ret, 1);
                if(ret < 0)
                    avail = 0;
                break;
            default:
                if (ret >= 0)
                {
                    WritePtr += snd_pcm_frames_to_bytes(data->pcmHandle, ret);
                    avail -= ret;
                }
                break;
            }
            if (ret < 0)
            {
                ret = snd_pcm_prepare(data->pcmHandle);
                if(ret < 0)
                    break;
            }
        }
    }

    return 0;
}

static ALCenum alsa_open_playback(ALCdevice *device, const ALCchar *deviceName)
{
    const char *driver = "default";
    alsa_data *data;
    char str[128];
    int i;

    ConfigValueStr("alsa", "device", &driver);

    if(!deviceName)
        deviceName = alsaDevice;
    else if(strcmp(deviceName, alsaDevice) != 0)
    {
        size_t idx;

        if(!allDevNameMap)
            allDevNameMap = probe_devices(SND_PCM_STREAM_PLAYBACK, &numDevNames);

        for(idx = 0;idx < numDevNames;idx++)
        {
            if(allDevNameMap[idx].name &&
               strcmp(deviceName, allDevNameMap[idx].name) == 0)
            {
                if(idx > 0)
                {
                    snprintf(str, sizeof(str), "%sCARD=%s,DEV=%d", device_prefix,
                             allDevNameMap[idx].card, allDevNameMap[idx].dev);
                    driver = str;
                }
                break;
            }
        }
        if(idx == numDevNames)
            return ALC_INVALID_VALUE;
    }

    data = (alsa_data*)calloc(1, sizeof(alsa_data));

    i = snd_pcm_open(&data->pcmHandle, driver, SND_PCM_STREAM_PLAYBACK, SND_PCM_NONBLOCK);
    if(i >= 0)
    {
        i = snd_pcm_nonblock(data->pcmHandle, 0);
        if(i < 0)
            snd_pcm_close(data->pcmHandle);
    }
    if(i < 0)
    {
        free(data);
        ERR("Could not open playback device '%s': %s\n", driver, snd_strerror(i));
        return ALC_OUT_OF_MEMORY;
    }

    device->szDeviceName = strdup(deviceName);
    device->ExtraData = data;
    return ALC_NO_ERROR;
}

static void alsa_close_playback(ALCdevice *device)
{
    alsa_data *data = (alsa_data*)device->ExtraData;

    snd_pcm_close(data->pcmHandle);
    free(data);
    device->ExtraData = NULL;
}

static ALCboolean alsa_reset_playback(ALCdevice *device)
{
    alsa_data *data = (alsa_data*)device->ExtraData;
    snd_pcm_uframes_t periodSizeInFrames;
    unsigned int periodLen, bufferLen;
    snd_pcm_sw_params_t *sp = NULL;
    snd_pcm_hw_params_t *p = NULL;
    snd_pcm_access_t access;
    snd_pcm_format_t format;
    unsigned int periods;
    unsigned int rate;
    int allowmmap;
    char *err;
    int i;


    format = -1;
    switch(device->FmtType)
    {
        case DevFmtByte:
            format = SND_PCM_FORMAT_S8;
            break;
        case DevFmtUByte:
            format = SND_PCM_FORMAT_U8;
            break;
        case DevFmtShort:
            format = SND_PCM_FORMAT_S16;
            break;
        case DevFmtUShort:
            format = SND_PCM_FORMAT_U16;
            break;
        case DevFmtFloat:
            format = SND_PCM_FORMAT_FLOAT;
            break;
    }

    allowmmap = GetConfigValueBool("alsa", "mmap", 1);
    periods = device->NumUpdates;
    periodLen = (ALuint64)device->UpdateSize * 1000000 / device->Frequency;
    bufferLen = periodLen * periods;
    rate = device->Frequency;

    err = NULL;
    snd_pcm_hw_params_malloc(&p);

    if((i=snd_pcm_hw_params_any(data->pcmHandle, p)) < 0)
        err = "any";
    /* set interleaved access */
    if(i >= 0 && (!allowmmap || (i=snd_pcm_hw_params_set_access(data->pcmHandle, p, SND_PCM_ACCESS_MMAP_INTERLEAVED)) < 0))
    {
        if(periods > 2)
        {
            periods--;
            bufferLen = periodLen * periods;
        }
        if((i=snd_pcm_hw_params_set_access(data->pcmHandle, p, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0)
            err = "set access";
    }
    /* set format (implicitly sets sample bits) */
    if(i >= 0 && (i=snd_pcm_hw_params_set_format(data->pcmHandle, p, format)) < 0)
    {
        device->FmtType = DevFmtFloat;
        if(format == SND_PCM_FORMAT_FLOAT ||
           (i=snd_pcm_hw_params_set_format(data->pcmHandle, p, SND_PCM_FORMAT_FLOAT)) < 0)
        {
            device->FmtType = DevFmtShort;
            if(format == SND_PCM_FORMAT_S16 ||
               (i=snd_pcm_hw_params_set_format(data->pcmHandle, p, SND_PCM_FORMAT_S16)) < 0)
            {
                device->FmtType = DevFmtUByte;
                if(format == SND_PCM_FORMAT_U8 ||
                   (i=snd_pcm_hw_params_set_format(data->pcmHandle, p, SND_PCM_FORMAT_U8)) < 0)
                    err = "set format";
            }
        }
    }
    /* set channels (implicitly sets frame bits) */
    if(i >= 0 && (i=snd_pcm_hw_params_set_channels(data->pcmHandle, p, ChannelsFromDevFmt(device->FmtChans))) < 0)
    {
        if((i=snd_pcm_hw_params_set_channels(data->pcmHandle, p, 2)) < 0)
        {
            if((i=snd_pcm_hw_params_set_channels(data->pcmHandle, p, 1)) < 0)
                err = "set channels";
            else
                device->FmtChans = DevFmtMono;
        }
        else
            device->FmtChans = DevFmtStereo;
    }
    if(i >= 0 && (i=snd_pcm_hw_params_set_rate_resample(data->pcmHandle, p, 0)) < 0)
    {
        ERR("Failed to disable ALSA resampler\n");
        i = 0;
    }
    /* set rate (implicitly constrains period/buffer parameters) */
    if(i >= 0 && (i=snd_pcm_hw_params_set_rate_near(data->pcmHandle, p, &rate, NULL)) < 0)
        err = "set rate near";
    /* set buffer time (implicitly constrains period/buffer parameters) */
    if(i >= 0 && (i=snd_pcm_hw_params_set_buffer_time_near(data->pcmHandle, p, &bufferLen, NULL)) < 0)
        err = "set buffer time near";
    /* set period time in frame units (implicitly sets buffer size/bytes/time and period size/bytes) */
    if(i >= 0 && (i=snd_pcm_hw_params_set_period_time_near(data->pcmHandle, p, &periodLen, NULL)) < 0)
        err = "set period time near";
    /* install and prepare hardware configuration */
    if(i >= 0 && (i=snd_pcm_hw_params(data->pcmHandle, p)) < 0)
        err = "set params";
    if(i >= 0 && (i=snd_pcm_hw_params_get_access(p, &access)) < 0)
        err = "get access";
    if(i >= 0 && (i=snd_pcm_hw_params_get_period_size(p, &periodSizeInFrames, NULL)) < 0)
        err = "get period size";
    if(i >= 0 && (i=snd_pcm_hw_params_get_periods(p, &periods, NULL)) < 0)
        err = "get periods";
    if(i < 0)
    {
        ERR("%s failed: %s\n", err, snd_strerror(i));
        snd_pcm_hw_params_free(p);
        return ALC_FALSE;
    }

    snd_pcm_hw_params_free(p);

    err = NULL;
    snd_pcm_sw_params_malloc(&sp);

    if((i=snd_pcm_sw_params_current(data->pcmHandle, sp)) != 0)
        err = "sw current";
    if(i == 0 && (i=snd_pcm_sw_params_set_avail_min(data->pcmHandle, sp, periodSizeInFrames)) != 0)
        err = "sw set avail min";
    if(i == 0 && (i=snd_pcm_sw_params_set_stop_threshold(data->pcmHandle, sp, periodSizeInFrames*periods)) != 0)
        err = "sw set stop threshold";
    if(i == 0 && (i=snd_pcm_sw_params(data->pcmHandle, sp)) != 0)
        err = "sw set params";
    if(i != 0)
    {
        ERR("%s failed: %s\n", err, snd_strerror(i));
        snd_pcm_sw_params_free(sp);
        return ALC_FALSE;
    }

    snd_pcm_sw_params_free(sp);

    device->Frequency = rate;
    SetDefaultChannelOrder(device);

    data->size = snd_pcm_frames_to_bytes(data->pcmHandle, periodSizeInFrames);
    if(access == SND_PCM_ACCESS_RW_INTERLEAVED)
    {
        /* Increase periods by one, since the temp buffer counts as an extra
         * period */
        periods++;
        data->buffer = malloc(data->size);
        if(!data->buffer)
        {
            ERR("buffer malloc failed\n");
            return ALC_FALSE;
        }
        device->UpdateSize = periodSizeInFrames;
        device->NumUpdates = periods;
        data->thread = StartThread(ALSANoMMapProc, device);
    }
    else
    {
        i = snd_pcm_prepare(data->pcmHandle);
        if(i < 0)
        {
            ERR("prepare error: %s\n", snd_strerror(i));
            return ALC_FALSE;
        }
        device->UpdateSize = periodSizeInFrames;
        device->NumUpdates = periods;
        data->thread = StartThread(ALSAProc, device);
    }
    if(data->thread == NULL)
    {
        ERR("Could not create playback thread\n");
        free(data->buffer);
        data->buffer = NULL;
        return ALC_FALSE;
    }

    return ALC_TRUE;
}

static void alsa_stop_playback(ALCdevice *device)
{
    alsa_data *data = (alsa_data*)device->ExtraData;

    if(data->thread)
    {
        data->killNow = 1;
        StopThread(data->thread);
        data->thread = NULL;
    }
    data->killNow = 0;
    free(data->buffer);
    data->buffer = NULL;
}


static ALCenum alsa_open_capture(ALCdevice *pDevice, const ALCchar *deviceName)
{
    const char *driver = "default";
    snd_pcm_hw_params_t *p;
    snd_pcm_uframes_t bufferSizeInFrames;
    snd_pcm_uframes_t periodSizeInFrames;
    snd_pcm_format_t format;
    ALuint frameSize;
    alsa_data *data;
    char str[128];
    char *err;
    int i;

    ConfigValueStr("alsa", "capture", &driver);

    if(!allCaptureDevNameMap)
        allCaptureDevNameMap = probe_devices(SND_PCM_STREAM_CAPTURE, &numCaptureDevNames);

    if(!deviceName)
        deviceName = allCaptureDevNameMap[0].name;
    else
    {
        size_t idx;

        for(idx = 0;idx < numCaptureDevNames;idx++)
        {
            if(allCaptureDevNameMap[idx].name &&
               strcmp(deviceName, allCaptureDevNameMap[idx].name) == 0)
            {
                if(idx > 0)
                {
                    snprintf(str, sizeof(str), "%sCARD=%s,DEV=%d", capture_prefix,
                             allCaptureDevNameMap[idx].card, allCaptureDevNameMap[idx].dev);
                    driver = str;
                }
                break;
            }
        }
        if(idx == numCaptureDevNames)
            return ALC_INVALID_VALUE;
    }

    data = (alsa_data*)calloc(1, sizeof(alsa_data));

    i = snd_pcm_open(&data->pcmHandle, driver, SND_PCM_STREAM_CAPTURE, SND_PCM_NONBLOCK);
    if(i < 0)
    {
        ERR("Could not open capture device '%s': %s\n", driver, snd_strerror(i));
        free(data);
        return ALC_INVALID_VALUE;
    }

    format = -1;
    switch(pDevice->FmtType)
    {
        case DevFmtByte:
            format = SND_PCM_FORMAT_S8;
            break;
        case DevFmtUByte:
            format = SND_PCM_FORMAT_U8;
            break;
        case DevFmtShort:
            format = SND_PCM_FORMAT_S16;
            break;
        case DevFmtUShort:
            format = SND_PCM_FORMAT_U16;
            break;
        case DevFmtFloat:
            format = SND_PCM_FORMAT_FLOAT;
            break;
    }

    err = NULL;
    bufferSizeInFrames = maxu(pDevice->UpdateSize*pDevice->NumUpdates,
                              100*pDevice->Frequency/1000);
    periodSizeInFrames = minu(bufferSizeInFrames, 50*pDevice->Frequency/1000);
    snd_pcm_hw_params_malloc(&p);

    if((i=snd_pcm_hw_params_any(data->pcmHandle, p)) < 0)
        err = "any";
    /* set interleaved access */
    if(i >= 0 && (i=snd_pcm_hw_params_set_access(data->pcmHandle, p, SND_PCM_ACCESS_RW_INTERLEAVED)) < 0)
        err = "set access";
    /* set format (implicitly sets sample bits) */
    if(i >= 0 && (i=snd_pcm_hw_params_set_format(data->pcmHandle, p, format)) < 0)
        err = "set format";
    /* set channels (implicitly sets frame bits) */
    if(i >= 0 && (i=snd_pcm_hw_params_set_channels(data->pcmHandle, p, ChannelsFromDevFmt(pDevice->FmtChans))) < 0)
        err = "set channels";
    /* set rate (implicitly constrains period/buffer parameters) */
    if(i >= 0 && (i=snd_pcm_hw_params_set_rate(data->pcmHandle, p, pDevice->Frequency, 0)) < 0)
        err = "set rate near";
    /* set buffer size in frame units (implicitly sets period size/bytes/time and buffer time/bytes) */
    if(i >= 0 && (i=snd_pcm_hw_params_set_buffer_size_near(data->pcmHandle, p, &bufferSizeInFrames)) < 0)
        err = "set buffer size near";
    /* set buffer size in frame units (implicitly sets period size/bytes/time and buffer time/bytes) */
    if(i >= 0 && (i=snd_pcm_hw_params_set_period_size_near(data->pcmHandle, p, &periodSizeInFrames, NULL)) < 0)
        err = "set period size near";
    /* install and prepare hardware configuration */
    if(i >= 0 && (i=snd_pcm_hw_params(data->pcmHandle, p)) < 0)
        err = "set params";
    if(i < 0)
    {
        ERR("%s failed: %s\n", err, snd_strerror(i));
        snd_pcm_hw_params_free(p);
        goto error;
    }

    if((i=snd_pcm_hw_params_get_period_size(p, &bufferSizeInFrames, NULL)) < 0)
    {
        ERR("get size failed: %s\n", snd_strerror(i));
        snd_pcm_hw_params_free(p);
        goto error;
    }

    snd_pcm_hw_params_free(p);

    frameSize = FrameSizeFromDevFmt(pDevice->FmtChans, pDevice->FmtType);

    data->ring = CreateRingBuffer(frameSize, pDevice->UpdateSize*pDevice->NumUpdates);
    if(!data->ring)
    {
        ERR("ring buffer create failed\n");
        goto error;
    }

    data->size = snd_pcm_frames_to_bytes(data->pcmHandle, bufferSizeInFrames);
    data->buffer = malloc(data->size);
    if(!data->buffer)
    {
        ERR("buffer malloc failed\n");
        goto error;
    }

    pDevice->szDeviceName = strdup(deviceName);

    pDevice->ExtraData = data;
    return ALC_NO_ERROR;

error:
    free(data->buffer);
    DestroyRingBuffer(data->ring);
    snd_pcm_close(data->pcmHandle);
    free(data);

    pDevice->ExtraData = NULL;
    return ALC_INVALID_VALUE;
}

static void alsa_close_capture(ALCdevice *pDevice)
{
    alsa_data *data = (alsa_data*)pDevice->ExtraData;

    snd_pcm_close(data->pcmHandle);
    DestroyRingBuffer(data->ring);

    free(data->buffer);
    free(data);
    pDevice->ExtraData = NULL;
}

static void alsa_start_capture(ALCdevice *Device)
{
    alsa_data *data = (alsa_data*)Device->ExtraData;
    int err;

    err = snd_pcm_start(data->pcmHandle);
    if(err < 0)
    {
        ERR("start failed: %s\n", snd_strerror(err));
        aluHandleDisconnect(Device);
    }
    else
        data->doCapture = AL_TRUE;
}

static void alsa_stop_capture(ALCdevice *Device)
{
    alsa_data *data = (alsa_data*)Device->ExtraData;
    snd_pcm_drain(data->pcmHandle);
    data->doCapture = AL_FALSE;
}

static ALCenum alsa_capture_samples(ALCdevice *Device, ALCvoid *Buffer, ALCuint Samples)
{
    alsa_data *data = (alsa_data*)Device->ExtraData;
    ReadRingBuffer(data->ring, Buffer, Samples);
    return ALC_NO_ERROR;
}

static ALCuint alsa_available_samples(ALCdevice *Device)
{
    alsa_data *data = (alsa_data*)Device->ExtraData;
    snd_pcm_sframes_t avail;

    avail = (Device->Connected ? snd_pcm_avail_update(data->pcmHandle) : 0);
    if(avail < 0)
    {
        ERR("avail update failed: %s\n", snd_strerror(avail));

        if((avail=snd_pcm_recover(data->pcmHandle, avail, 1)) >= 0)
        {
            if(data->doCapture)
                avail = snd_pcm_start(data->pcmHandle);
            if(avail >= 0)
                avail = snd_pcm_avail_update(data->pcmHandle);
        }
        if(avail < 0)
        {
            ERR("restore error: %s\n", snd_strerror(avail));
            aluHandleDisconnect(Device);
        }
    }
    while(avail > 0)
    {
        snd_pcm_sframes_t amt;

        amt = snd_pcm_bytes_to_frames(data->pcmHandle, data->size);
        if(avail < amt) amt = avail;

        amt = snd_pcm_readi(data->pcmHandle, data->buffer, amt);
        if(amt < 0)
        {
            ERR("read error: %s\n", snd_strerror(amt));

            if(amt == -EAGAIN)
                continue;
            if((amt=snd_pcm_recover(data->pcmHandle, amt, 1)) >= 0)
            {
                if(data->doCapture)
                    amt = snd_pcm_start(data->pcmHandle);
                if(amt >= 0)
                    amt = snd_pcm_avail_update(data->pcmHandle);
            }
            if(amt < 0)
            {
                ERR("restore error: %s\n", snd_strerror(amt));
                aluHandleDisconnect(Device);
                break;
            }
            avail = amt;
            continue;
        }

        WriteRingBuffer(data->ring, data->buffer, amt);
        avail -= amt;
    }

    return RingBufferSize(data->ring);
}


static const BackendFuncs alsa_funcs = {
    alsa_open_playback,
    alsa_close_playback,
    alsa_reset_playback,
    alsa_stop_playback,
    alsa_open_capture,
    alsa_close_capture,
    alsa_start_capture,
    alsa_stop_capture,
    alsa_capture_samples,
    alsa_available_samples
};

ALCboolean alc_alsa_init(BackendFuncs *func_list)
{
    if(!alsa_load())
        return ALC_FALSE;
    device_prefix = GetConfigValue("alsa", "device-prefix", "plughw:");
    capture_prefix = GetConfigValue("alsa", "capture-prefix", "plughw:");
    *func_list = alsa_funcs;
    return ALC_TRUE;
}

void alc_alsa_deinit(void)
{
    ALuint i;

    for(i = 0;i < numDevNames;++i)
    {
        free(allDevNameMap[i].name);
        free(allDevNameMap[i].card);
    }
    free(allDevNameMap);
    allDevNameMap = NULL;
    numDevNames = 0;

    for(i = 0;i < numCaptureDevNames;++i)
    {
        free(allCaptureDevNameMap[i].name);
        free(allCaptureDevNameMap[i].card);
    }
    free(allCaptureDevNameMap);
    allCaptureDevNameMap = NULL;
    numCaptureDevNames = 0;

#ifdef HAVE_DYNLOAD
    if(alsa_handle)
        CloseLib(alsa_handle);
    alsa_handle = NULL;
#endif
}

void alc_alsa_probe(enum DevProbe type)
{
    ALuint i;

    switch(type)
    {
        case DEVICE_PROBE:
            AppendDeviceList(alsaDevice);
            break;

        case ALL_DEVICE_PROBE:
            for(i = 0;i < numDevNames;++i)
            {
                free(allDevNameMap[i].name);
                free(allDevNameMap[i].card);
            }

            free(allDevNameMap);
            allDevNameMap = probe_devices(SND_PCM_STREAM_PLAYBACK, &numDevNames);

            for(i = 0;i < numDevNames;++i)
                AppendAllDeviceList(allDevNameMap[i].name);
            break;

        case CAPTURE_DEVICE_PROBE:
            for(i = 0;i < numCaptureDevNames;++i)
            {
                free(allCaptureDevNameMap[i].name);
                free(allCaptureDevNameMap[i].card);
            }

            free(allCaptureDevNameMap);
            allCaptureDevNameMap = probe_devices(SND_PCM_STREAM_CAPTURE, &numCaptureDevNames);

            for(i = 0;i < numCaptureDevNames;++i)
                AppendCaptureDeviceList(allCaptureDevNameMap[i].name);
            break;
    }
}
