//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************


#include <windows.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <assert.h>
#include "Platform/EbrPlatform.h"

#include "pthread.h"

#if NEEDTIMESPEC
struct timespec {
    long tv_sec;
    long tv_nsec;
};
#endif

IWPLATFORM_EXPORT
pthread_t pthread_self() {
    return (pthread_t)GetCurrentThreadId();
}

IWPLATFORM_EXPORT
void* pthread_getspecific(pthread_key_t key) {
    void* ret = (void*)/*ThreadEmulation::*/ TlsGetValue((DWORD)key);
    return ret;
}

IWPLATFORM_EXPORT
int pthread_setspecific(pthread_key_t key, const void* ptr) {
    /*ThreadEmulation::*/ TlsSetValue((DWORD)key, (LPVOID)ptr);
    return 0;
}

IWPLATFORM_EXPORT
int pthread_key_delete(pthread_key_t key) {
    return 0;
}

IWPLATFORM_EXPORT
int pthread_key_create(pthread_key_t* keyPtr, void (*destructor)(void*)) {
    *((DWORD*)keyPtr) = /*ThreadEmulation::*/ TlsAlloc();
    return 0;
}

IWPLATFORM_EXPORT
int pthread_mutexattr_init(pthread_mutexattr_t* attr) {
    return 0;
}

IWPLATFORM_EXPORT
int pthread_mutexattr_settype(pthread_mutexattr_t* attr, int type) {
    return 0;
}

IWPLATFORM_EXPORT
int pthread_mutexattr_setpshared(pthread_mutexattr_t* attr, int type) {
    return 0;
}

IWPLATFORM_EXPORT
int pthread_mutexattr_destroy(pthread_mutexattr_t* attr) {
    return 0;
}

IWPLATFORM_EXPORT
int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr) {
    CRITICAL_SECTION* crit = new CRITICAL_SECTION();
    memset(crit, 0, sizeof(CRITICAL_SECTION));

    InitializeCriticalSectionEx(crit, 0, 0);
    *mutex = (pthread_mutex*)crit;
    return 0;
}

IWPLATFORM_EXPORT
int pthread_mutex_lock(pthread_mutex_t* mutex) {
    if (*((uint32_t*)mutex) == 0x32AAABA7) {
        pthread_mutex_init(mutex, NULL);
    }
    if (*mutex == PTHREAD_MUTEX_INITIALIZER) {
        CRITICAL_SECTION* crit = new CRITICAL_SECTION();
        memset(crit, 0, sizeof(CRITICAL_SECTION));

        InitializeCriticalSectionEx(crit, 0, 0);
        *mutex = (pthread_mutex*)crit;
    }
    EnterCriticalSection((CRITICAL_SECTION*)*mutex);
    return 0;
}

IWPLATFORM_EXPORT
int pthread_mutex_trylock(pthread_mutex_t* mutex) {
    if (*((uint32_t*)mutex) == 0x32AAABA7) {
        pthread_mutex_init(mutex, 0);
    }
    BOOL success = TryEnterCriticalSection((CRITICAL_SECTION*)*mutex);
    if (success) {
        return 0;
    }

    return EBUSY;
}

IWPLATFORM_EXPORT
int pthread_mutex_unlock(pthread_mutex_t* mutex) {
    LeaveCriticalSection((CRITICAL_SECTION*)*mutex);
    return 0;
}

IWPLATFORM_EXPORT
int pthread_mutex_destroy(pthread_mutex_t* mutex) {
    DeleteCriticalSection((CRITICAL_SECTION*)*mutex);
    delete ((CRITICAL_SECTION*)*mutex);
    return 0;
}

IWPLATFORM_EXPORT
int pthread_cond_init(pthread_cond_t* condvar, const pthread_condattr_t* attr) {
    CONDITION_VARIABLE* cond = new CONDITION_VARIABLE();
    memset(cond, 0, sizeof(CONDITION_VARIABLE));
    InitializeConditionVariable(cond);
    *condvar = (pthread_cond*)cond;
    return 0;
}

IWPLATFORM_EXPORT
int pthread_cond_destroy(pthread_cond_t* cond) {
    delete ((CONDITION_VARIABLE*)*cond);
    return 0;
}

IWPLATFORM_EXPORT
int pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex) {
    if (*((uint32_t*)cond) == (uint32_t)PTHREAD_COND_INITIALIZER) {
        pthread_cond_init(cond, 0);
    }
    if (*((uint32_t*)mutex) == 0x32AAABA7) {
        pthread_mutex_init(mutex, 0);
    }
    SleepConditionVariableCS((CONDITION_VARIABLE*)*cond, (CRITICAL_SECTION*)*mutex, INFINITE);
    return 0;
}

IWPLATFORM_EXPORT
int pthread_cond_wait_ms(pthread_cond_t* cond, pthread_mutex_t* mutex, unsigned int ms) {
    if (*((uint32_t*)cond) == (uint32_t)PTHREAD_COND_INITIALIZER) {
        pthread_cond_init(cond, 0);
    }
    if (*((uint32_t*)mutex) == 0x32AAABA7) {
        pthread_mutex_init(mutex, 0);
    }
    BOOL ret = SleepConditionVariableCS((CONDITION_VARIABLE*)*cond, (CRITICAL_SECTION*)*mutex, ms);
    if (ret) {
        return 0;
    } else {
        return -1;
    }
}

IWPLATFORM_EXPORT
int pthread_cond_signal(pthread_cond_t* cond) {
    if (*((uint32_t*)cond) == (uint32_t)PTHREAD_COND_INITIALIZER) {
        pthread_cond_init(cond, 0);
    }
    WakeConditionVariable((CONDITION_VARIABLE*)*cond);
    return 0;
}

IWPLATFORM_EXPORT
int pthread_cond_broadcast(pthread_cond_t* cond) {
    if (*((uint32_t*)cond) == (uint32_t)PTHREAD_COND_INITIALIZER) {
        pthread_cond_init(cond, 0);
    }
    WakeAllConditionVariable((CONDITION_VARIABLE*)*cond);
    return 0;
}

IWPLATFORM_EXPORT
int pthread_cond_timedwait(pthread_cond_t* cond, pthread_mutex_t* mutex, const struct timespec* ts) {
    if (*((uint32_t*)cond) == (uint32_t)PTHREAD_COND_INITIALIZER) {
        pthread_cond_init(cond, 0);
    }
    if (*((uint32_t*)mutex) == 0x32AAABA7) {
        pthread_mutex_init(mutex, 0);
    }
    EbrTimeval tv;
    EbrGetTimeOfDay(&tv);

    uint64_t curNanoseconds = ((uint64_t)tv.tv_sec) * 1000 * 1000 * 1000 + ((uint64_t)tv.tv_usec) * 1000;
    uint64_t timeoutNS = ((uint64_t)ts->tv_sec) * 1000 * 1000 * 1000 + (uint64_t)ts->tv_nsec;
    int64_t waitNS = timeoutNS - curNanoseconds;
    if (waitNS < 0)
        waitNS = 0;

    int retVal = 0;
    DWORD ms = waitNS / 1000000;

    DWORD ret = SleepConditionVariableCS((CONDITION_VARIABLE*)*cond, (CRITICAL_SECTION*)*mutex, ms);
    if (ret) {
        retVal = 0;
    } else {
        retVal = ETIMEDOUT;
    }

    return retVal;
}

IWPLATFORM_EXPORT
int pthread_attr_init(pthread_attr_t* attrs) {
    return 0;
}

IWPLATFORM_EXPORT
int pthread_attr_setstacksize(pthread_attr_t* attrs, size_t size) {
    return 0;
}

IWPLATFORM_EXPORT
int pthread_attr_destroy(pthread_attr_t* attrs) {
    return 0;
}

typedef struct {
    void* (*startRoutine)(void*);
    void* param;
} EbrStartParam;

DWORD WINAPI ThreadRoutine(LPVOID param) {
    EbrStartParam* p = (EbrStartParam*)param;

    p->startRoutine(p->param);

    return 0;
}

IWPLATFORM_EXPORT
int pthread_create(pthread_t* tid, const pthread_attr_t* attr, void* (*start)(void*), void* param) {
    DWORD threadid;
    EbrStartParam* startP = new EbrStartParam();
    startP->startRoutine = start;
    startP->param = param;
    HANDLE h = CreateThread(NULL, 16384, ThreadRoutine, startP, 0, &threadid);

    if (tid)
        *tid = (pthread*)(void*)threadid;
    return 0;
}

IWPLATFORM_EXPORT
void pthread_exit(void* code) {
    assert(0);
}

IWPLATFORM_EXPORT
int pthread_join(pthread_t pthread, void** retaddr) {
    assert(0);
    return 0;
}

IWPLATFORM_EXPORT
int pthread_cancel(pthread_t pthread) {
    assert(0);
    return 0;
}

IWPLATFORM_EXPORT
int pthread_kill(pthread_t thread, int signal) {
    assert(0);
    return 0;
}

IWPLATFORM_EXPORT
int pthread_equal(pthread_t t1, pthread_t t2) {
    return t1 == t2;
}

IWPLATFORM_EXPORT
int pthread_rwlock_init(pthread_rwlock_t* mutex, pthread_rwlockattr_t* attr) {
    assert(0);
    return 0;
}

IWPLATFORM_EXPORT
int pthread_rwlock_wrlock(pthread_rwlock_t* mutex) {
    assert(0);
    return 0;
}

IWPLATFORM_EXPORT
int pthread_rwlock_rdlock(pthread_rwlock_t* mutex) {
    assert(0);
    return 0;
}

IWPLATFORM_EXPORT
int pthread_rwlock_unlock(pthread_rwlock_t* mutex) {
    assert(0);
    return 0;
}
