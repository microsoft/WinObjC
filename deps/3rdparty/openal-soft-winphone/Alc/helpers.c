/**
 * OpenAL cross platform audio library
 * Copyright (C) 2011 by authors.
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
#ifdef HAVE_DLFCN_H
#include <dlfcn.h>
#endif

#if defined(HAVE_GUIDDEF_H) || defined(HAVE_INITGUID_H)
#define INITGUID
#include <windows.h>
#ifdef HAVE_GUIDDEF_H
#include <guiddef.h>
#else
#include <initguid.h>
#endif

DEFINE_GUID(KSDATAFORMAT_SUBTYPE_PCM,        0x00000001, 0x0000, 0x0010, 0x80,0x00, 0x00,0xaa,0x00,0x38,0x9b,0x71);
DEFINE_GUID(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT, 0x00000003, 0x0000, 0x0010, 0x80,0x00, 0x00,0xaa,0x00,0x38,0x9b,0x71);

DEFINE_GUID(IID_IDirectSoundNotify,   0xb0210783, 0x89cd, 0x11d0, 0xaf,0x08, 0x00,0xa0,0xc9,0x25,0xcd,0x16);

DEFINE_GUID(CLSID_MMDeviceEnumerator, 0xbcde0395, 0xe52f, 0x467c, 0x8e,0x3d, 0xc4,0x57,0x92,0x91,0x69,0x2e);
DEFINE_GUID(IID_IMMDeviceEnumerator,  0xa95664d2, 0x9614, 0x4f35, 0xa7,0x46, 0xde,0x8d,0xb6,0x36,0x17,0xe6);
DEFINE_GUID(IID_IAudioClient,         0x1cb9ad4c, 0xdbfa, 0x4c32, 0xb1,0x78, 0xc2,0xf5,0x68,0xa7,0x03,0xb2);
DEFINE_GUID(IID_IAudioRenderClient,   0xf294acfc, 0x3146, 0x4483, 0xa7,0xbf, 0xad,0xdc,0xa7,0xc2,0x60,0xe2);

#endif

#include "alMain.h"

#ifdef ANDROID
#include <android/log.h>
#endif

#ifdef _WIN32


//Windows STore/Phone cannot use Tls API functions
#if defined _WIN_RT

#	include <time.h>

#	define TlsAlloc cpp11_TlsAlloc
#	define TlsFree cpp11_TlsFree
#	define TlsGetValue cpp11_TlsGetValue
#	define TlsSetValue cpp11_TlsSetValue
#	define LoadLibraryA(str) NULL

DWORD cpp11_TlsAlloc();
BOOL cpp11_TlsFree(DWORD id);
void* cpp11_TlsGetValue(DWORD id);
BOOL cpp11_TlsSetValue(DWORD id, void* value);

//timeGetTime implementation
ALuint timeGetTime(void)
{
	static time_t startTime = 0;
	time_t currentTime;
	if (startTime == 0)
		startTime = time(NULL);

	currentTime = time(NULL);

	return (ALuint)(currentTime - startTime) * 1000;
}

#endif//#if defined _WIN_RT

void pthread_once(pthread_once_t *once, void (*callback)(void))
{
    LONG ret;
    while((ret=InterlockedExchange(once, 1)) == 1)
        sched_yield();
    if(ret == 0)
        callback();
    InterlockedExchange(once, 2);
}


int pthread_key_create(pthread_key_t *key, void (*callback)(void*))
{
    *key = TlsAlloc();
    if(callback)
        InsertUIntMapEntry(&TlsDestructor, *key, callback);
    return 0;
}

int pthread_key_delete(pthread_key_t key)
{
    InsertUIntMapEntry(&TlsDestructor, key, NULL);
    TlsFree(key);
    return 0;
}

void *pthread_getspecific(pthread_key_t key)
{ return TlsGetValue(key); }

int pthread_setspecific(pthread_key_t key, void *val)
{
    TlsSetValue(key, val);
    return 0;
}


void *LoadLib(const char *name)
{ return LoadLibraryA(name); }
void CloseLib(void *handle)
{ FreeLibrary((HANDLE)handle); }
void *GetSymbol(void *handle, const char *name)
{
    void *ret;

    ret = (void*)GetProcAddress((HANDLE)handle, name);
    if(ret == NULL)
        ERR("Failed to load %s\n", name);
    return ret;
}

#else

void InitializeCriticalSection(CRITICAL_SECTION *cs)
{
    pthread_mutexattr_t attrib;
    int ret;

    ret = pthread_mutexattr_init(&attrib);
    assert(ret == 0);

    ret = pthread_mutexattr_settype(&attrib, PTHREAD_MUTEX_RECURSIVE);
#ifdef HAVE_PTHREAD_NP_H
    if(ret != 0)
        ret = pthread_mutexattr_setkind_np(&attrib, PTHREAD_MUTEX_RECURSIVE);
#endif
    assert(ret == 0);
    ret = pthread_mutex_init(cs, &attrib);
    assert(ret == 0);

    pthread_mutexattr_destroy(&attrib);
}
void DeleteCriticalSection(CRITICAL_SECTION *cs)
{
    int ret;
    ret = pthread_mutex_destroy(cs);
    assert(ret == 0);
}
void EnterCriticalSection(CRITICAL_SECTION *cs)
{
    int ret;
    ret = pthread_mutex_lock(cs);
    assert(ret == 0);
}
void LeaveCriticalSection(CRITICAL_SECTION *cs)
{
    int ret;
    ret = pthread_mutex_unlock(cs);
    assert(ret == 0);
}

/* NOTE: This wrapper isn't quite accurate as it returns an ALuint, as opposed
 * to the expected DWORD. Both are defined as unsigned 32-bit types, however.
 * Additionally, Win32 is supposed to measure the time since Windows started,
 * as opposed to the actual time. */
ALuint timeGetTime(void)
{
#if _POSIX_TIMERS > 0
    struct timespec ts;
    int ret = -1;

#if defined(_POSIX_MONOTONIC_CLOCK) && (_POSIX_MONOTONIC_CLOCK >= 0)
#if _POSIX_MONOTONIC_CLOCK == 0
    static int hasmono = 0;
    if(hasmono > 0 || (hasmono == 0 &&
                       (hasmono=sysconf(_SC_MONOTONIC_CLOCK)) > 0))
#endif
        ret = clock_gettime(CLOCK_MONOTONIC, &ts);
#endif
    if(ret != 0)
        ret = clock_gettime(CLOCK_REALTIME, &ts);
    assert(ret == 0);

    return ts.tv_nsec/1000000 + ts.tv_sec*1000;
#else
    struct timeval tv;
    int ret;

    ret = gettimeofday(&tv, NULL);
    assert(ret == 0);

    return tv.tv_usec/1000 + tv.tv_sec*1000;
#endif
}

void Sleep(ALuint t)
{
    struct timespec tv, rem;
    tv.tv_nsec = (t*1000000)%1000000000;
    tv.tv_sec = t/1000;

    while(nanosleep(&tv, &rem) == -1 && errno == EINTR)
        tv = rem;
}

#ifdef HAVE_DLFCN_H

void *LoadLib(const char *name)
{
    const char *err;
    void *handle;

    dlerror();
    handle = dlopen(name, RTLD_NOW);
    if((err=dlerror()) != NULL)
        handle = NULL;
    return handle;
}
void CloseLib(void *handle)
{ dlclose(handle); }
void *GetSymbol(void *handle, const char *name)
{
    const char *err;
    void *sym;

    dlerror();
    sym = dlsym(handle, name);
    if((err=dlerror()) != NULL)
    {
        WARN("Failed to load %s: %s\n", name, err);
        sym = NULL;
    }
    return sym;
}

#endif
#endif


void al_print(const char *func, const char *fmt, ...)
{
    char str[256];
    int i;

    i = snprintf(str, sizeof(str), "AL lib: %s: ", func);
    if(i < (int)sizeof(str) && i > 0)
    {
        va_list ap;
        va_start(ap, fmt);
        vsnprintf(str+i, sizeof(str)-i, fmt, ap);
        va_end(ap);
    }
    str[sizeof(str)-1] = 0;

    fprintf(LogFile, "%s", str);
    fflush(LogFile);


#ifdef ANDROID
    __android_log_write(ANDROID_LOG_WARN, "OpenAL", str);
#elif defined _MSC_VER
#	if defined DEBUG || defined _DEBUG
	OutputDebugStringA(str);
#	endif
#endif
}


void SetRTPriority(void)
{
    ALboolean failed = AL_FALSE;

#if defined _WIN32 && !defined _WIN_RT
    if(RTPrioLevel > 0)
        failed = !SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
#elif defined(HAVE_PTHREAD_SETSCHEDPARAM) && !defined(__OpenBSD__)
    if(RTPrioLevel > 0)
    {
        struct sched_param param;
        /* Use the minimum real-time priority possible for now (on Linux this
         * should be 1 for SCHED_RR) */
        param.sched_priority = sched_get_priority_min(SCHED_RR);
        failed = !!pthread_setschedparam(pthread_self(), SCHED_RR, &param);
    }
#else
    /* Real-time priority not available */
    failed = (RTPrioLevel>0);
#endif
    if(failed)
        ERR("Failed to set priority level for thread\n");
}


static void Lock(volatile ALenum *l)
{
    while(ExchangeInt(l, AL_TRUE) == AL_TRUE)
        sched_yield();
}

static void Unlock(volatile ALenum *l)
{
    ExchangeInt(l, AL_FALSE);
}

void RWLockInit(RWLock *lock)
{
    lock->read_count = 0;
    lock->write_count = 0;
    lock->read_lock = AL_FALSE;
    lock->read_entry_lock = AL_FALSE;
    lock->write_lock = AL_FALSE;
}

void ReadLock(RWLock *lock)
{
    Lock(&lock->read_entry_lock);
    Lock(&lock->read_lock);
    if(IncrementRef(&lock->read_count) == 1)
        Lock(&lock->write_lock);
    Unlock(&lock->read_lock);
    Unlock(&lock->read_entry_lock);
}

void ReadUnlock(RWLock *lock)
{
    if(DecrementRef(&lock->read_count) == 0)
        Unlock(&lock->write_lock);
}

void WriteLock(RWLock *lock)
{
    if(IncrementRef(&lock->write_count) == 1)
        Lock(&lock->read_lock);
    Lock(&lock->write_lock);
}

void WriteUnlock(RWLock *lock)
{
    Unlock(&lock->write_lock);
    if(DecrementRef(&lock->write_count) == 0)
        Unlock(&lock->read_lock);
}


void InitUIntMap(UIntMap *map, ALsizei limit)
{
    map->array = NULL;
    map->size = 0;
    map->maxsize = 0;
    map->limit = limit;
    RWLockInit(&map->lock);
}

void ResetUIntMap(UIntMap *map)
{
    WriteLock(&map->lock);
    free(map->array);
    map->array = NULL;
    map->size = 0;
    map->maxsize = 0;
    WriteUnlock(&map->lock);
}

ALenum InsertUIntMapEntry(UIntMap *map, ALuint key, ALvoid *value)
{
    ALsizei pos = 0;

    WriteLock(&map->lock);
    if(map->size > 0)
    {
        ALsizei low = 0;
        ALsizei high = map->size - 1;
        while(low < high)
        {
            ALsizei mid = low + (high-low)/2;
            if(map->array[mid].key < key)
                low = mid + 1;
            else
                high = mid;
        }
        if(map->array[low].key < key)
            low++;
        pos = low;
    }

    if(pos == map->size || map->array[pos].key != key)
    {
        if(map->size == map->limit)
        {
            WriteUnlock(&map->lock);
            return AL_OUT_OF_MEMORY;
        }

        if(map->size == map->maxsize)
        {
            ALvoid *temp = NULL;
            ALsizei newsize;

            newsize = (map->maxsize ? (map->maxsize<<1) : 4);
            if(newsize >= map->maxsize)
                temp = realloc(map->array, newsize*sizeof(map->array[0]));
            if(!temp)
            {
                WriteUnlock(&map->lock);
                return AL_OUT_OF_MEMORY;
            }
            map->array = temp;
            map->maxsize = newsize;
        }

        if(pos < map->size)
            memmove(&map->array[pos+1], &map->array[pos],
                    (map->size-pos)*sizeof(map->array[0]));
        map->size++;
    }
    map->array[pos].key = key;
    map->array[pos].value = value;
    WriteUnlock(&map->lock);

    return AL_NO_ERROR;
}

ALvoid *RemoveUIntMapKey(UIntMap *map, ALuint key)
{
    ALvoid *ptr = NULL;
    WriteLock(&map->lock);
    if(map->size > 0)
    {
        ALsizei low = 0;
        ALsizei high = map->size - 1;
        while(low < high)
        {
            ALsizei mid = low + (high-low)/2;
            if(map->array[mid].key < key)
                low = mid + 1;
            else
                high = mid;
        }
        if(map->array[low].key == key)
        {
            ptr = map->array[low].value;
            if(low < map->size-1)
                memmove(&map->array[low], &map->array[low+1],
                        (map->size-1-low)*sizeof(map->array[0]));
            map->size--;
        }
    }
    WriteUnlock(&map->lock);
    return ptr;
}

ALvoid *LookupUIntMapKey(UIntMap *map, ALuint key)
{
    ALvoid *ptr = NULL;
    ReadLock(&map->lock);
    if(map->size > 0)
    {
        ALsizei low = 0;
        ALsizei high = map->size - 1;
        while(low < high)
        {
            ALsizei mid = low + (high-low)/2;
            if(map->array[mid].key < key)
                low = mid + 1;
            else
                high = mid;
        }
        if(map->array[low].key == key)
            ptr = map->array[low].value;
    }
    ReadUnlock(&map->lock);
    return ptr;
}
