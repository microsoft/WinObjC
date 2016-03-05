/**
 * OpenAL cross platform audio library
 * Copyright (C) 2010 by Chris Robinson
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
#include <jni.h>
#include <pthread.h>
#include "alMain.h"
#include "AL/al.h"
#include "AL/alc.h"

static const ALCchar android_device[] = "Android Default";

static JavaVM* javaVM = NULL;
static pthread_key_t javaDetach = 0;

static jclass cAudioTrack = NULL;

static jmethodID mAudioTrack;
static jmethodID mGetMinBufferSize;
static jmethodID mPlay;
static jmethodID mStop;
static jmethodID mRelease;
static jmethodID mWrite;

static void onJavaDetach(void* arg)
{
    (*javaVM)->DetachCurrentThread(javaVM);
    pthread_setspecific(javaDetach, NULL);
}

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    javaVM = vm;
    pthread_key_create(&javaDetach, onJavaDetach);
    return JNI_VERSION_1_2;
}

static JNIEnv* GetEnv()
{
    JNIEnv* env = NULL;
    int err = (*javaVM)->GetEnv(javaVM, (void**)&env, JNI_VERSION_1_2);
    if (err ==  JNI_EDETACHED)
    {
        int err = (*javaVM)->AttachCurrentThread(javaVM, &env, NULL);
        if (err != 0)
        {
            AL_PRINT("Error attaching to current thread!");
            exit(1);
        }

        pthread_setspecific(javaDetach, env);
    }
    else if (err != JNI_OK)
    {
        AL_PRINT("Error getting JNIEnv!");
        exit(1);
    }
    return env;
}

typedef struct
{
    pthread_t thread;
    volatile int running;
} AndroidData;

#define STREAM_MUSIC 3
#define CHANNEL_CONFIGURATION_MONO 2
#define CHANNEL_CONFIGURATION_STEREO 3
#define ENCODING_PCM_8BIT 3
#define ENCODING_PCM_16BIT 2
#define MODE_STREAM 1

static void* thread_function(void* arg)
{
    ALCdevice* device = (ALCdevice*)arg;
    AndroidData* data = (AndroidData*)device->ExtraData;

    JNIEnv* env;
    (*javaVM)->AttachCurrentThread(javaVM, &env, NULL);

    (*env)->PushLocalFrame(env, 2);

    int sampleRateInHz = device->Frequency;
    int channelConfig = ChannelsFromDevFmt(device->FmtChans) == 1 ? CHANNEL_CONFIGURATION_MONO : CHANNEL_CONFIGURATION_STEREO;
    int audioFormat = BytesFromDevFmt(device->FmtType) == 1 ? ENCODING_PCM_8BIT : ENCODING_PCM_16BIT;

    int bufferSizeInBytes = (*env)->CallStaticIntMethod(env, cAudioTrack, 
        mGetMinBufferSize, sampleRateInHz, channelConfig, audioFormat);

    int bufferSizeInSamples = bufferSizeInBytes / FrameSizeFromDevFmt(device->FmtChans, device->FmtType);

    jobject track = (*env)->NewObject(env, cAudioTrack, mAudioTrack,
        STREAM_MUSIC, sampleRateInHz, channelConfig, audioFormat, device->NumUpdates * bufferSizeInBytes, MODE_STREAM);

    (*env)->CallNonvirtualVoidMethod(env, track, cAudioTrack, mPlay);

    jarray buffer = (*env)->NewByteArray(env, bufferSizeInBytes);

    while (data->running)
    {
        void* pBuffer = (*env)->GetPrimitiveArrayCritical(env, buffer, NULL);

        if (pBuffer)
        {
            aluMixData(device, pBuffer, bufferSizeInSamples);
            (*env)->ReleasePrimitiveArrayCritical(env, buffer, pBuffer, 0);

            (*env)->CallNonvirtualIntMethod(env, track, cAudioTrack, mWrite, buffer, 0, bufferSizeInBytes);
        }
        else
        {
            AL_PRINT("Failed to get pointer to array bytes");
        }
    }
    
    (*env)->CallNonvirtualVoidMethod(env, track, cAudioTrack, mStop);
    (*env)->CallNonvirtualVoidMethod(env, track, cAudioTrack, mRelease);

    (*env)->PopLocalFrame(env, NULL);

    (*javaVM)->DetachCurrentThread(javaVM);
    return NULL;
}

static ALCenum android_open_playback(ALCdevice *device, const ALCchar *deviceName)
{
    JNIEnv* env = GetEnv();
    AndroidData* data;
    int channels;
    int bytes;

    if (!cAudioTrack)
    {
        /* Cache AudioTrack class and it's method id's
         * And do this only once!
         */

        cAudioTrack = (*env)->FindClass(env, "android/media/AudioTrack");
        if (!cAudioTrack)
        {
            AL_PRINT("android.media.AudioTrack class is not found. Are you running at least 1.5 version?");
            return ALC_FALSE;
        }

        cAudioTrack = (*env)->NewGlobalRef(env, cAudioTrack);

        mAudioTrack = (*env)->GetMethodID(env, cAudioTrack, "<init>", "(IIIIII)V");
        mGetMinBufferSize = (*env)->GetStaticMethodID(env, cAudioTrack, "getMinBufferSize", "(III)I");
        mPlay = (*env)->GetMethodID(env, cAudioTrack, "play", "()V");
        mStop = (*env)->GetMethodID(env, cAudioTrack, "stop", "()V");
        mRelease = (*env)->GetMethodID(env, cAudioTrack, "release", "()V");
        mWrite = (*env)->GetMethodID(env, cAudioTrack, "write", "([BII)I");
    }

    if (!deviceName)
    {
        deviceName = android_device;
    }
    else if (strcmp(deviceName, android_device) != 0)
    {
        return ALC_INVALID_VALUE;
    }

    data = (AndroidData*)calloc(1, sizeof(*data));
    device->szDeviceName = strdup(deviceName);
    device->ExtraData = data;
    
    return ALC_NO_ERROR;
}

static void android_close_playback(ALCdevice *device)
{
    AndroidData* data = (AndroidData*)device->ExtraData;
    if (data != NULL)
    {
        free(data);
        device->ExtraData = NULL;
    }
}

static ALCboolean android_reset_playback(ALCdevice *device)
{
    AndroidData* data = (AndroidData*)device->ExtraData;

    device->Frequency = 22050;
    device->NumUpdates = 2;
    device->FmtChans = ChannelsFromDevFmt(device->FmtChans) > 1 ? ALC_STEREO_SOFT : ALC_MONO_SOFT;
    device->FmtType = BytesFromDevFmt(device->FmtType) > 1 ? ALC_SHORT_SOFT : ALC_UNSIGNED_BYTE_SOFT;

    SetDefaultChannelOrder(device);

    data->running = 1;
    pthread_create(&data->thread, NULL, thread_function, device);

    return ALC_TRUE;
}

static void android_stop_playback(ALCdevice *device)
{
    AndroidData* data = (AndroidData*)device->ExtraData;

    if (data->running)
    {
        data->running = 0;
        pthread_join(data->thread, NULL);
    }
}

static ALCenum android_open_capture(ALCdevice *pDevice, const ALCchar *deviceName)
{
    (void)pDevice;
    (void)deviceName;
    
    return ALC_INVALID_DEVICE;
}

static void android_close_capture(ALCdevice *pDevice)
{
    (void)pDevice;
}

static void android_start_capture(ALCdevice *pDevice)
{
    (void)pDevice;
}

static void android_stop_capture(ALCdevice *pDevice)
{
    (void)pDevice;
}

static ALCenum android_capture_samples(ALCdevice *pDevice, ALCvoid *pBuffer, ALCuint lSamples)
{
    (void)pDevice;
    (void)pBuffer;
    (void)lSamples;
    
    return ALC_INVALID_DEVICE;
}

static ALCuint android_available_samples(ALCdevice *pDevice)
{
    (void)pDevice;
    return 0;
}

static const BackendFuncs android_funcs = {
    android_open_playback,
    android_close_playback,
    android_reset_playback,
    android_stop_playback,
    android_open_capture,
    android_close_capture,
    android_start_capture,
    android_stop_capture,
    android_capture_samples,
    android_available_samples
};

void alc_android_init(BackendFuncs *func_list)
{
    *func_list = android_funcs;
}

void alc_android_deinit(void)
{
    JNIEnv* env = GetEnv();

    /* release cached AudioTrack class */
    (*env)->DeleteGlobalRef(env, cAudioTrack);
}

void alc_android_probe(int type)
{
    if (type == DEVICE_PROBE)
    {
        AppendDeviceList(android_device);
    }
    else if (type == ALL_DEVICE_PROBE)
    {
        AppendAllDeviceList(android_device);
    }
}
