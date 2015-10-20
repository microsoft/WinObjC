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

#ifndef __PTHREAD_H
#define __PTHREAD_H

#ifdef EBRIUS
struct timespec {
    long tv_sec;
    long tv_nsec;
};
#endif

struct pthread;
struct pthread_attr;
struct pthread_key;
struct pthread_cond;
struct pthread_condattr;
struct pthread_mutex;
struct pthread_mutexattr;
struct pthread_rwlock;
struct pthread_rwlockattr;

typedef void* pthread_t;
typedef struct pthread_attr* pthread_attr_t;
typedef struct pthread_key* pthread_key_t;
typedef struct pthread_cond* pthread_cond_t;
typedef struct pthread_cond* pthread_condattr_t;
typedef struct pthread_mutex* pthread_mutex_t;
typedef struct pthread_mutexattr* pthread_mutexattr_t;
typedef struct pthread_rwlock* pthread_rwlock_t;
typedef struct pthread_rwlockattr* pthread_rwlockattr_t;
typedef int pid_t;
typedef unsigned int u_int;
typedef unsigned short u_short;

#define PTHREAD_COND_INITIALIZER ((pthread_cond*)0x3CB0B1BB)
#define PTHREAD_MUTEX_INITIALIZER ((pthread_mutex*)0x12354CCA)
#define PTHREAD_MUTEX_RECURSIVE 1

pthread_t pthread_self();
int pthread_attr_init(pthread_attr_t* attrs);
int pthread_attr_setstacksize(pthread_attr_t*, size_t size);
int pthread_attr_destroy(pthread_attr_t* attrs);
int pthread_equal(pthread_t t1, pthread_t t2);
void* pthread_getspecific(pthread_key_t key);
int pthread_setspecific(pthread_key_t key, const void* ptr);
int pthread_key_delete(pthread_key_t key);
int pthread_key_create(pthread_key_t* keyPtr, void (*destructor)(void*));

int pthread_mutexattr_init(pthread_mutexattr_t* attr);
int pthread_mutexattr_settype(pthread_mutexattr_t* attr, int type);
int pthread_mutexattr_setpshared(pthread_mutexattr_t* attr, int type);
int pthread_mutexattr_destroy(pthread_mutexattr_t* attr);

int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr);
int pthread_mutex_lock(pthread_mutex_t* mutex);
int pthread_mutex_trylock(pthread_mutex_t* mutex);
int pthread_mutex_unlock(pthread_mutex_t* mutex);
int pthread_mutex_destroy(pthread_mutex_t* mutex);

int pthread_rwlock_init(pthread_rwlock_t* mutex, pthread_rwlockattr_t* attr);
int pthread_rwlock_wrlock(pthread_rwlock_t* mutex);
int pthread_rwlock_rdlock(pthread_rwlock_t* mutex);
int pthread_rwlock_unlock(pthread_rwlock_t* mutex);

int pthread_create(pthread_t*, const pthread_attr_t*, void* (*)(void*), void*);
void pthread_exit(void* code);
int pthread_join(pthread_t pthread, void** retaddr);
int pthread_cancel(pthread_t pthread);
int pthread_kill(pthread_t thread, int signal);

int pthread_cond_init(pthread_cond_t*, const pthread_condattr_t* attr);
int pthread_cond_destroy(pthread_cond_t*);
int pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex);
int pthread_cond_wait_ms(pthread_cond_t* cond, pthread_mutex_t* mutex, unsigned int ms);

int pthread_cond_signal(pthread_cond_t* cond);
int pthread_cond_broadcast(pthread_cond_t* cond);

struct timespec;
int pthread_cond_timedwait(pthread_cond_t* cond, pthread_mutex_t* mutex, const struct timespec* s);

#endif
