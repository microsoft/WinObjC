//******************************************************************************
//
// Copyright (c) 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015
//   Jonathan Schleifer <js@webkeks.org>. All rights reserved.
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

#include <string.h>
#include <assert.h>

#include "runtime.h"
#include "runtime-private.h"

#include <windows.h>

#define NUM_LOCKS 8 /* needs to be a power of 2 */
#define LOCK_HASH(p) ((unsigned)((uintptr_t)p >> 4) & (NUM_LOCKS - 1))
static CRITICAL_SECTION locks[NUM_LOCKS];

#pragma section(".CRT$XCU", read)
static void __cdecl prop_constructor(void);
__declspec(allocate(".CRT$XCU")) void(__cdecl* prop_fconstructor_)(void) = prop_constructor;
static void __cdecl prop_constructor(void) {
    size_t i;

    for (i = 0; i < NUM_LOCKS; i++)
        if (!InitializeCriticalSectionEx(&locks[i], 0, 0))
            OBJC_ERROR("Failed to initialize spinlocks!");
}

OBJCRT_EXPORT id objc_getProperty(id self, SEL _cmd, ptrdiff_t offset, BOOL atomic) {
    if (atomic) {
        id* ptr = (id*)(void*)((char*)self + offset);
        unsigned hash = LOCK_HASH(ptr);

        EnterCriticalSection(&locks[hash]);

        id ret = [[*ptr retain] autorelease];

        LeaveCriticalSection(&locks[hash]);

        return ret;
    }

    return *(id*)(void*)((char*)self + offset);
}

OBJCRT_EXPORT void objc_setProperty(id self, SEL _cmd, ptrdiff_t offset, id value, BOOL atomic, signed char copy) {
    if (atomic) {
        id* ptr = (id*)(void*)((char*)self + offset);
        unsigned hash = LOCK_HASH(ptr);

        EnterCriticalSection(&locks[hash]);

        id old = *ptr;
        switch (copy) {
            case 0:
                *ptr = [value retain];
                break;
            case 2:
                *ptr = [value mutableCopy];
                break;
            default:
                *ptr = [value copy];
        }

        [old release];

        LeaveCriticalSection(&locks[hash]);

        return;
    }

    id* ptr = (id*)(void*)((char*)self + offset);
    id old = *ptr;

    switch (copy) {
        case 0:
            *ptr = [value retain];
            break;
        case 2:
            *ptr = [value mutableCopy];
            break;
        default:
            *ptr = [value copy];
    }

    [old release];
}

OBJCRT_EXPORT void objc_getPropertyStruct(void* dest, const void* src, ptrdiff_t size, BOOL atomic, BOOL strong) {
    if (atomic) {
        unsigned hash = LOCK_HASH(src);

        EnterCriticalSection(&locks[hash]);

        memcpy(dest, src, size);

        LeaveCriticalSection(&locks[hash]);

        return;
    }

    memcpy(dest, src, size);
}

OBJCRT_EXPORT void objc_setPropertyStruct(void* dest, const void* src, ptrdiff_t size, BOOL atomic, BOOL strong) {
    if (atomic) {
        unsigned hash = LOCK_HASH(src);

        EnterCriticalSection(&locks[hash]);

        memcpy(dest, src, size);

        LeaveCriticalSection(&locks[hash]);

        return;
    }

    memcpy(dest, src, size);
}

const char* property_getAttributes(Property property) {
    OBJC_NOT_IMPLEMENTED_ERROR("property_getAttributes is not yet implemented");
    return NULL;
}

const char* property_getName(Property property) {
    return property->name;
}