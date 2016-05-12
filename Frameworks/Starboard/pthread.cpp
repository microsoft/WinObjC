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
#include <cmath>
#include <map>
#include <mutex>
#include <concrt.h>
#include "StubReturn.h"

#include "pthread.h"

const static size_t PTHREAD_MIN_STACK_SIZE = 1024 * 1024;
static const wchar_t* TAG = L"pthread";

#if NEEDTIMESPEC
struct timespec {
    long tv_sec;
    long tv_nsec;
};
#endif

DWORD WINAPI ThreadRoutine(LPVOID param);

struct pthread_attr {
public:
    pthread_attr()
        : _schedpolicy(0),
          _schedparam{ (sched_get_priority_max(_schedpolicy) + sched_get_priority_min(_schedpolicy) / 2) },
          _stacksize(PTHREAD_MIN_STACK_SIZE) {
    }

    void _setStackSize(size_t size) {
        _stacksize = size;
    }

    size_t _getStackSize() const {
        return _stacksize;
    }

    void _setSchedParam(const struct sched_param& param) {
        _schedparam = param;
    }

    struct sched_param _getParams() const {
        return _schedparam;
    }

    void _setSchedPolicy(int policy) {
        _schedpolicy = policy;
    }

    int _getSchedPolicy() const {
        return _schedpolicy;
    }

    int _getPriorityAttr() const {
        return _schedparam._schedPriority;
    }

private:
    int _schedpolicy;
    struct sched_param _schedparam;
    size_t _stacksize;
};

namespace {
class _pthread_handle {
public:
    void* (*startRoutine)(void*);
    void* param;

    _pthread_handle(void* (*start)(void*), void* params, size_t stackSize, int priority, int policy) : startRoutine(start), param(params) {
        DWORD threadid;
        _nativeHandle = CreateThread(nullptr, stackSize, ThreadRoutine, this, CREATE_SUSPENDED, &threadid);
        THROW_LAST_ERROR_IF_NULL(_nativeHandle);

        THROW_IF_WIN32_ERROR(_setPriority(priority, policy));
    }

    ~_pthread_handle() {
        if (_nativeHandle) {
            CloseHandle(_nativeHandle);
        }
    }

    void _start() {
        if (_nativeHandle) {
            ResumeThread(_nativeHandle);
        }
    }

    /* Notes about thread priority conversion
     * Thread Priority will change to the actual windows thread Priority.
     * For example, NSThread priority of .8 maps to pthread priority 80 for most policies
     * which is then mapped to windows priority THREAD_PRIORITY_ABOVE_NORMAL.
     * Returning from this value gives a priority of 87 which is a value between 75 and 100 which are the cutoffs for
     * THREAD_PRIORITY_HIGHEST and THREAD_PRIORITY_TIME_CRITICAL. Setting priority to half way between these makes it clear
     * what the priority is when conveyed back to the user.
     */

    int _convertPriorityToWindows(int priority, int policy) {
        // priority min is equal to THREAD_PRIORITY_IDLE, the lowest thread priority
        // priority max is equal to THREAD_PRIORITY_TIME_CRITICAL, the highest thread priority
        // priority (min + max)/2 is equal to THREAD_PRIORITY_NORMAL

        int windowsPriority = THREAD_PRIORITY_NORMAL;
        int maxPriority = sched_get_priority_max(policy);
        int minPriority = sched_get_priority_min(policy);

        if (priority == maxPriority) {
            windowsPriority = THREAD_PRIORITY_TIME_CRITICAL;
        } else if (priority == minPriority) {
            windowsPriority = THREAD_PRIORITY_IDLE;
        } else if (priority == ((maxPriority + minPriority) / 2)) {
            // Halfway between max and min priority
            windowsPriority = THREAD_PRIORITY_NORMAL;
        } else if (priority <= (double)(maxPriority - minPriority) / 4.0 + minPriority) {
            // Priority is between 0% and 25% of min to max priority
            windowsPriority = THREAD_PRIORITY_LOWEST;
        } else if (priority < (double)(maxPriority - minPriority) / 2.0 + minPriority) {
            // Priority is between 25% and 50% of min to max priority
            windowsPriority = THREAD_PRIORITY_BELOW_NORMAL;
        } else if (priority < 3.0 * (double)(maxPriority - minPriority) / 4.0 + minPriority) {
            // Priority is between 50% and 75% of min to max priority
            windowsPriority = THREAD_PRIORITY_ABOVE_NORMAL;
        } else {
            // Priority is between 75% and 100% of min to max priority
            windowsPriority = THREAD_PRIORITY_HIGHEST;
        }

        return windowsPriority;
    }

    int _convertPriorityFromWindows(int priority, int policy) {
        int pthreadPriority = 0;
        int maxPriority = sched_get_priority_max(policy);
        int minPriority = sched_get_priority_min(policy);

        int increments = (double)(maxPriority - minPriority) / 4.0;
        int halfIncrements = (double)(maxPriority - minPriority) / 8.0;

        if (priority == THREAD_PRIORITY_TIME_CRITICAL) {
            // 100% of min to max priority
            pthreadPriority = maxPriority;
        } else if (priority == THREAD_PRIORITY_IDLE) {
            // 0% of min to max priority
            pthreadPriority = minPriority;
        } else if (priority == THREAD_PRIORITY_NORMAL) {
            // 50% of min to max priority
            pthreadPriority = ((maxPriority + minPriority) / 2);
        } else if (priority == THREAD_PRIORITY_LOWEST) {
            // 12% of min to max priority
            pthreadPriority = halfIncrements + minPriority;
        } else if (priority == THREAD_PRIORITY_BELOW_NORMAL) {
            // 37% of min to max priority
            pthreadPriority = increments + halfIncrements + minPriority;
        } else if (priority == THREAD_PRIORITY_ABOVE_NORMAL) {
            // 62% of min to max priority
            pthreadPriority = 2 * increments + halfIncrements + minPriority;
        } else {
            // 87% of min to max priority
            pthreadPriority = 3 * increments + halfIncrements + minPriority;
        }

        return pthreadPriority;
    }

    int _setPriority(int priority, int policy) {
        if (priority > sched_get_priority_max(policy) || priority < sched_get_priority_min(policy)) {
            return ERROR_INVALID_PARAMETER;
        }

        int windowsPriority = _convertPriorityToWindows(priority, policy);

        RETURN_LAST_ERROR_IF(SetThreadPriority(_nativeHandle, windowsPriority) == 0);

        int resultingPriority = _convertPriorityFromWindows(GetThreadPriority(_nativeHandle), policy);

        const struct sched_param params { resultingPriority };
        _nativeAttrs._setSchedParam(params);

        return ERROR_SUCCESS;
    }

    pthread_attr _getAttrs() {
        return _nativeAttrs;
    }

    HANDLE _getNativeHandle() const {
        return _nativeHandle;
    }

private:
    HANDLE _nativeHandle;
    pthread_attr _nativeAttrs;
};
}

std::map<HANDLE, std::unique_ptr<_pthread_handle>> g_threads;
std::mutex g_threadMutex;

static DWORD g_selfTLSKey = ::FlsAlloc(nullptr);

DWORD WINAPI ThreadRoutine(LPVOID param) {
    _pthread_handle* p = (_pthread_handle*)param;

    ::FlsSetValue(g_selfTLSKey, p->_getNativeHandle());

    p->startRoutine(p->param);

    {
        // Remove finished thread.
        std::lock_guard<std::mutex> lock(g_threadMutex);
        g_threads.erase(p->_getNativeHandle());
    }

    return 0;
}

/**
@Status Interoperable
*/
extern "C" pthread_t pthread_self() {
    return (pthread_t)::FlsGetValue(g_selfTLSKey);
}

/**
@Status Interoperable
*/
extern "C" void* pthread_getspecific(pthread_key_t key) {
    void* ret = ::FlsGetValue((DWORD)key);
    return ret;
}

/**
@Status Caveat
@Notes Ignores return value errors
*/
extern "C" int pthread_setspecific(pthread_key_t key, const void* ptr) {
    ::FlsSetValue((DWORD)key, (LPVOID)ptr);
    return 0;
}

/**
@Status Stub
*/
extern "C" int pthread_key_delete(pthread_key_t key) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Caveat
@Notes Ignores return value errors
*/
extern "C" int pthread_key_create(pthread_key_t* keyPtr, void (*destructor)(void*)) {
    *((DWORD*)keyPtr) = ::FlsAlloc(nullptr);
    return 0;
}

/**
@Status Stub
*/
extern "C" int pthread_mutexattr_init(pthread_mutexattr_t* attr) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
extern "C" int pthread_mutexattr_settype(pthread_mutexattr_t* attr, int type) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
extern "C" int pthread_mutexattr_setpshared(pthread_mutexattr_t* attr, int type) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
extern "C" int pthread_mutexattr_destroy(pthread_mutexattr_t* attr) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Caveat
@Notes Ignores return value errors
*/
extern "C" int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr) {
    CRITICAL_SECTION* crit = new CRITICAL_SECTION();
    memset(crit, 0, sizeof(CRITICAL_SECTION));

    InitializeCriticalSectionEx(crit, 0, 0);
    *mutex = (pthread_mutex*)crit;
    return 0;
}

// Initialize mutex in a thread safe manner without locking
static inline void _pthread_ensure_initialized(pthread_mutex_t* mutex) {
    if (*mutex == PTHREAD_MUTEX_INITIALIZER) {
        pthread_mutex_t tmp;
        pthread_mutex_init(&tmp, nullptr);
        if (PTHREAD_MUTEX_INITIALIZER != InterlockedCompareExchangePointer((void**)mutex, tmp, (void*)PTHREAD_MUTEX_INITIALIZER)) {
            pthread_mutex_destroy(&tmp);
        }
    }

    // Ensure that the reader thread observes the write to *mutex after it observes the writes to **mutex.
    MemoryBarrier();
}

/**
@Status Caveat
@Notes Ignores return value errors
*/
extern "C" int pthread_mutex_lock(pthread_mutex_t* mutex) {
    _pthread_ensure_initialized(mutex);

    EnterCriticalSection((CRITICAL_SECTION*)*mutex);
    return 0;
}

/**
@Status Interoperable
*/
extern "C" int pthread_setschedparam(pthread_t thread, int policy, const struct sched_param* param) {
    {
        std::lock_guard<std::mutex> lock(g_threadMutex);

        const auto it = g_threads.find(thread);
        if (it != g_threads.end()) {
            if (it->second->_setPriority(param->_schedPriority, policy) != ERROR_SUCCESS) {
                return ESRCH;
            } else {
                return 0;
            }
        }
    }
    return ESRCH;
}

/**
@Status Interoperable
*/
extern "C" int pthread_getschedparam(pthread_t thread, int* policy, struct sched_param* param) {
    if (!param || !policy) {
        return EINVAL;
    }
    {
        std::lock_guard<std::mutex> lock(g_threadMutex);
        const auto it = g_threads.find(thread);

        if (it != g_threads.end()) {
            *param = it->second->_getAttrs()._getParams();
            *policy = it->second->_getAttrs()._getSchedPolicy();
            return 0;
        }
    }
    return ESRCH;
}

/**
@Status Stub
@Notes Policies are ignored.
*/
extern "C" int pthread_attr_getschedpolicy(const pthread_attr_t* attrs, int* policy) {
    if (attrs && *attrs && policy) {
        *policy = (*attrs)->_getSchedPolicy();
        return 0;
    }
    return EINVAL;
}

/**
@Status Interoperable
*/
extern "C" int pthread_attr_getstacksize(const pthread_attr_t* attrs, size_t* size) {
    if (attrs && *attrs && size) {
        *size = (*attrs)->_getStackSize();
        return 0;
    }
    return EINVAL;
}

/**
@Status Interoperable
*/
extern "C" int pthread_mutex_trylock(pthread_mutex_t* mutex) {
    _pthread_ensure_initialized(mutex);

    BOOL success = TryEnterCriticalSection((CRITICAL_SECTION*)*mutex);
    if (success) {
        return 0;
    }

    return EBUSY;
}

/**
@Status Caveat
@Notes Ignores Error codes
*/
extern "C" int pthread_mutex_unlock(pthread_mutex_t* mutex) {
    LeaveCriticalSection((CRITICAL_SECTION*)*mutex);
    return 0;
}

/**
@Status Caveat
@Notes Ignores Error codes, ignores error cases
*/
extern "C" int pthread_mutex_destroy(pthread_mutex_t* mutex) {
    DeleteCriticalSection((CRITICAL_SECTION*)*mutex);
    delete ((CRITICAL_SECTION*)*mutex);
    return 0;
}

/**
@Status Caveat
@Notes Ignores Error codes, ignores error cases
*/
extern "C" int pthread_cond_init(pthread_cond_t* condvar, const pthread_condattr_t* attr) {
    CONDITION_VARIABLE* cond = new CONDITION_VARIABLE();
    memset(cond, 0, sizeof(CONDITION_VARIABLE));
    InitializeConditionVariable(cond);
    *condvar = (pthread_cond*)cond;
    return 0;
}

/**
@Status Caveat
@Notes Ignores Error codes
*/
extern "C" int pthread_cond_destroy(pthread_cond_t* cond) {
    delete ((CONDITION_VARIABLE*)*cond);
    return 0;
}

/**
@Status Caveat
@Notes Ignores Error codes, ignores error cases
*/
extern "C" int pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex) {
    if (*((uint32_t*)cond) == (uint32_t)PTHREAD_COND_INITIALIZER) {
        pthread_cond_init(cond, 0);
    }
    if (*mutex == PTHREAD_MUTEX_INITIALIZER) {
        pthread_mutex_init(mutex, 0);
    }
    SleepConditionVariableCS((CONDITION_VARIABLE*)*cond, (CRITICAL_SECTION*)*mutex, INFINITE);
    return 0;
}

// Internal method
extern "C" int pthread_cond_wait_ms(pthread_cond_t* cond, pthread_mutex_t* mutex, unsigned int ms) {
    if (*((uint32_t*)cond) == (uint32_t)PTHREAD_COND_INITIALIZER) {
        pthread_cond_init(cond, 0);
    }
    if (*mutex == PTHREAD_MUTEX_INITIALIZER) {
        pthread_mutex_init(mutex, 0);
    }
    BOOL ret = SleepConditionVariableCS((CONDITION_VARIABLE*)*cond, (CRITICAL_SECTION*)*mutex, ms);
    if (ret) {
        return 0;
    } else {
        return -1;
    }
}

/**
@Status Caveat
@Notes Error return codes ignored.
*/
extern "C" int pthread_cond_signal(pthread_cond_t* cond) {
    if (*((uint32_t*)cond) == (uint32_t)PTHREAD_COND_INITIALIZER) {
        pthread_cond_init(cond, 0);
    }
    WakeConditionVariable((CONDITION_VARIABLE*)*cond);
    return 0;
}

/**
@Status Caveat
@Notes Error return codes ignored.
*/
extern "C" int pthread_cond_broadcast(pthread_cond_t* cond) {
    if (*((uint32_t*)cond) == (uint32_t)PTHREAD_COND_INITIALIZER) {
        pthread_cond_init(cond, 0);
    }
    WakeAllConditionVariable((CONDITION_VARIABLE*)*cond);
    return 0;
}

/**
@Status Caveat
@Notes Error return codes ignored. Only ETIMEDOUT is supported, otherwise windows errors are used.
*/
extern "C" int pthread_cond_timedwait(pthread_cond_t* cond, pthread_mutex_t* mutex, const struct timespec* ts) {
    if (*((uint32_t*)cond) == PTHREAD_COND_INITIALIZER) {
        pthread_cond_init(cond, 0);
    }
    if (*mutex == PTHREAD_MUTEX_INITIALIZER) {
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

/**
@Status Interoperable
*/
extern "C" int pthread_attr_init(pthread_attr_t* attrs) {
    if (attrs) {
        *attrs = new pthread_attr();
        return 0;
    }
    return EINVAL;
}

/**
@Status Caveat
@Notes Must conform to windows stack sizes. We let windows take care of handling wrong sizes.
*/
extern "C" int pthread_attr_setstacksize(pthread_attr_t* attrs, size_t size) {
    if (attrs && *attrs) {
        (*attrs)->_setStackSize(size);
        return 0;
    }

    return EINVAL;
}

/**
@Status Interoperable
*/
extern "C" int pthread_attr_setschedparam(pthread_attr_t* attrs, const struct sched_param* param) {
    if (attrs && *attrs && param) {
        (*attrs)->_setSchedParam(*param);
        return 0;
    }
    return EINVAL;
}

/**
@Status Interoperable
*/
extern "C" int pthread_attr_destroy(pthread_attr_t* attrs) {
    if (attrs) {
        delete *attrs;
        *attrs = nullptr;
        return 0;
    }
    return EINVAL;
}

/**
@Status Interoperable
*/
extern "C" int pthread_create(pthread_t* tid, const pthread_attr_t* attr, void* (*start)(void*), void* param) {
    if (!tid) {
        return EINVAL;
    }
    size_t stackSize = PTHREAD_MIN_STACK_SIZE;
    int priority = 0;
    int policy = 0;
    if (attr && *attr) {
        stackSize = (*attr)->_getStackSize();
        priority = (*attr)->_getParams()._schedPriority;
        policy = (*attr)->_getSchedPolicy();
    }

    try {
        auto handle = std::make_unique<_pthread_handle>(start, param, stackSize, priority, policy);

        {
            std::lock_guard<std::mutex> lock(g_threadMutex);
            HANDLE threadHandle = handle->_getNativeHandle();

            // We have to start the thread after mapping has assumed ownership of unique pointer.
            _pthread_handle* rawHandle = handle.get();

            g_threads.emplace(threadHandle, std::move(handle));

            rawHandle->_start();

            *tid = (pthread_t)threadHandle;
        }
    } catch (const wil::ResultException& e) {
        DWORD error = HRESULT_CODE(e.GetFailureInfo().hr);
        if (error == ERROR_DS_THREAD_LIMIT_EXCEEDED || error == ERROR_TOO_MANY_TCBS || error == ERROR_MAX_THRDS_REACHED ||
            error == ERROR_TOO_MANY_THREADS) {
            return EAGAIN;
        }
        return EPERM;
    }

    return 0;
}

/**
@Status Stub
*/
extern "C" void pthread_exit(void* code) {
    UNIMPLEMENTED();
}

/**
@Status Stub
*/
extern "C" int pthread_join(pthread_t pthread, void** retaddr) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
extern "C" int pthread_cancel(pthread_t pthread) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
extern "C" int pthread_kill(pthread_t thread, int signal) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
extern "C" int pthread_equal(pthread_t t1, pthread_t t2) {
    return t1 == t2;
}

/**
@Status Stub
*/
extern "C" int pthread_rwlock_init(pthread_rwlock_t* mutex, const pthread_rwlockattr_t* attr) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
extern "C" int pthread_rwlock_wrlock(pthread_rwlock_t* mutex) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
extern "C" int pthread_rwlock_rdlock(pthread_rwlock_t* mutex) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
extern "C" int pthread_rwlock_unlock(pthread_rwlock_t* mutex) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
extern "C" int pthread_attr_setdetachstate(pthread_attr_t*, int) {
    UNIMPLEMENTED();
    return StubReturn();
}