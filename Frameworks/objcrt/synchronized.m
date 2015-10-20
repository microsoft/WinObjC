//******************************************************************************
//
// Copyright (c) 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015
//   Jonathan Schleifer <js@webkeks.org>. All rights reserved.
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

#include <stdio.h>
#include <stdlib.h>

#include "runtime.h"
#include "runtime-private.h"

#include <windows.h>

struct lock_s {
    id object;
    int count;
    CRITICAL_SECTION rmutex;
    struct lock_s* next;
}* locks = NULL;

static CRITICAL_SECTION mutex;

__attribute__((constructor)) void sync_init(void) {
    InitializeCriticalSectionEx(&mutex, 0, 0);
}

OBJCRT_EXPORT int objc_sync_enter(id object) {
    struct lock_s* lock;

    EnterCriticalSection(&mutex);

    /* Look if we already have a lock */
    for (lock = locks; lock != NULL; lock = lock->next) {
        if (lock->object != object)
            continue;

        lock->count++;

        LeaveCriticalSection(&mutex);
        EnterCriticalSection(&lock->rmutex);

        return 0;
    }

    /* Create a new lock */
    if ((lock = malloc(sizeof(*lock))) == NULL)
        OBJC_ERROR("Failed to allocate memory for mutex!");

    InitializeCriticalSectionEx(&lock->rmutex, 0, 0);

    lock->object = object;
    lock->count = 1;
    lock->next = locks;

    locks = lock;

    LeaveCriticalSection(&mutex);
    EnterCriticalSection(&lock->rmutex);

    return 0;
}

OBJCRT_EXPORT int objc_sync_exit(id object) {
    struct lock_s *lock, *last = NULL;

    EnterCriticalSection(&mutex);

    for (lock = locks; lock != NULL; lock = lock->next) {
        if (lock->object != object) {
            last = lock;
            continue;
        }

        LeaveCriticalSection(&lock->rmutex);

        if (--lock->count == 0) {
            DeleteCriticalSection(&lock->rmutex);

            if (last != NULL)
                last->next = lock->next;
            if (locks == lock)
                locks = lock->next;

            free(lock);
        }

        LeaveCriticalSection(&mutex);

        return 0;
    }

    OBJC_ERROR("objc_sync_exit() was called for an object not locked!");
}
