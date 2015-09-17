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

#include "runtime.h"
#include <assert.h>
#include <stdint.h>
#include "Etc.h"
#include "Hash.h"
#include "runtime-private.h"

@interface NSObject {
@public
    WinRT_isa isa;
}
@end

#include <windows.h>

typedef HashSet<id> WeakObjectsSet;

WeakObjectsSet _weak_objects;

class ObjCrtMutex
{
public:
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

class LifetimeMutex : public ObjCrtMutex
{
private:
    CRITICAL_SECTION _lock;

public:
    LifetimeMutex()
    {
        InitializeCriticalSectionEx(&_lock, 0, 0);
    }
    void lock()
    {
        EnterCriticalSection(&_lock);
    }
    void unlock()
    {
        LeaveCriticalSection(&_lock);
    }
};

static LifetimeMutex _objLifetimeMutex;
ObjCrtMutex &_objLifetimeLock = _objLifetimeMutex;

extern "C" int EbrIncrement(int volatile *var);
extern "C" int EbrDecrement(int volatile *var);

HashMap<id, uint32_t> _refCountTable;

#define NSOBJECT_MAGIC  0x234BC09A
#define NSOBJECT_MANAGED_MAGIC  0x234BA55E

typedef struct {
    uint32_t refCount;
    uint32_t magic;
} ObjectHeader;

class ObjCHeader
{
    ObjectHeader *_ptr;

public:
    ObjCHeader(id obj)
    {
        _ptr = (ObjectHeader *) ((char *) obj - 8);
    }

    bool isValid()
    {
        if ( _ptr->magic == NSOBJECT_MAGIC ||
             _ptr->magic == NSOBJECT_MANAGED_MAGIC ) {
            return true;
        } else {
            return false;
        }
    }

    uint32_t refCount()
    {
        return _ptr->refCount;
    }

    uint32_t Increment()
    {
        return InterlockedIncrement((volatile LONG *) &_ptr->refCount);
    }

    uint32_t Decrement()
    {
        return InterlockedDecrement((volatile LONG *) &_ptr->refCount);
    }

    ObjectHeader * operator->()
    {
        return _ptr;
    }
};

#ifndef NDEBUG
    #define ZOMBIE_DEBUG_CLASS_TYPE
#endif

static void _IncrementExtraRefCount(id object) {
    if ( ObjCHeader(object).isValid() ) {
        ObjCHeader(object).Increment();
        return;
    }

   _objLifetimeLock.lock();

   uint32_t *count;
   if ( !_refCountTable.get(object, count) ) {
       _refCountTable.insert(object, 2);
       _objLifetimeLock.unlock();
       return;
   }
   (*count) ++;
   _objLifetimeLock.unlock();
}

static bool _DecrementExtraRefCountWasZero(id object) {
    ObjCHeader hdr(object);
    if ( hdr.isValid() ) {
        if ( hdr.Decrement() == 0 ) {
            hdr->refCount = 0x7FFFFFFF;
            return true;
        }

        return false;
    }

    _objLifetimeLock.lock();

    uint32_t *count;
    if ( !_refCountTable.get(object, count) ) {
        _objLifetimeLock.unlock();
        return YES;
    }
    (*count) --;
    if ( *count == 1 ) {
        _refCountTable.remove(object);
    }
    _objLifetimeLock.unlock();

    return false;
}

static unsigned int _ExtraRefCount(id object) {
    ObjCHeader hdr(object);
    if ( hdr.isValid()) {
        return hdr.refCount();
    }

   unsigned int       result=1;

   _objLifetimeLock.lock();
   uint32_t *count;
   if ( _refCountTable.get(object, count) ) {
       result = *count;
   }
   _objLifetimeLock.unlock();

   return result;
}

static unsigned int _ExtraRefExists(id object) {
    ObjCHeader hdr(object);
    if ( hdr.isValid() ) {
        return hdr.refCount() > 1;
    }

   unsigned int       result=0;

   _objLifetimeLock.lock();
   uint32_t *count;
   if ( _refCountTable.get(object, count) ) {
       result = 1;
   }
   _objLifetimeLock.unlock();

   return result;
}
/****************************/

typedef HashSet<id> newObjectsList;

typedef struct
{
    const char *name;
    uint32_t count;
    uint32_t size;
} classMetrics;
typedef HashMap<id, classMetrics> classesCountList;

__declspec(thread) newObjectsList *g_newObjects;
classesCountList g_classesCount;
HashMap<id, id> g_objTrackList;

// Never deleted. Needs to be on heap, crashes when this guy gets dealloced before some other static OBJC class. 
static HashMap<id, id> * g_allocCount = new HashMap<id, id>();

// Call the constructors from the base class up to the most derived:
static void callConstructors(id obj, Class cls) {
    static SEL constructorSel = sel_registerName(".cxx_construct");

    Class parent = cls->superclass;
    if (parent) {
        callConstructors(obj, parent);
    }

    IMP constructor = class_getMethodImplementation(cls, constructorSel);
    if (constructor)
        constructor(obj, constructorSel);
}

id objc_allocateObject(Class classRef, unsigned int extraBytes)
{
    uint32_t refCountOffset = 0;
    uint32_t magic = NSOBJECT_MAGIC;
    size_t extraManagementBytes = 8;
    size_t size = class_getInstanceSize(classRef) + extraBytes + extraManagementBytes;
#ifdef ZOMBIE_DEBUG_CLASS_TYPE
    if ( size - extraManagementBytes < 8 ) {
        size += 4;  //  Make room for storing old class type in NSDeallocateObject
    }
#endif
    uint8_t *ret = (uint8_t *) calloc(1, size);
    ObjectHeader *hdr = (ObjectHeader *) (ret + refCountOffset);
    ret += extraManagementBytes;

    hdr->refCount = 1;
    hdr->magic = magic;
    
    _object_setClass((id) ret, classRef);

    callConstructors((id) ret, classRef);

    return (id) ret;
}

void objc_deallocateObject(id obj)
{
    ObjCHeader hdr(obj);
    void *freeAddr = (void *) obj;
    Class classRef = [obj class];

    if ( hdr->magic == NSOBJECT_MAGIC ) {
        freeAddr = (void *) ((char *) obj - 8);
    } else {
        OBJC_ERROR("Object @ 0x%x corrupt or was not allocated by objc_allocObject! (magic=0x%x)", obj, hdr->magic);
    }

    //  BUG: There's a small window for a loadWeak call to happen before the weak reference is removed below
    _objLifetimeLock.lock();
    _weak_objects.remove(obj);
    _objLifetimeLock.unlock();

    // Destruct from most derived to base class:
    Class curr = classRef;
    static SEL destructorSel = sel_registerName(".cxx_destruct");
    while (curr) {
        IMP destructor = class_getMethodImplementation(curr, destructorSel);
        if (destructor)
            destructor(obj, destructorSel);
        curr = curr->superclass;
    }

#if 0
    id oldIsa = ((ObjCObject *) obj)->isa;
    ((ObjCObject *) obj)->isa = [NSZombie class];

#ifdef ZOMBIE_DEBUG_CLASS_TYPE
    *((id *) obj))[1] = oldIsa; //  Store old class type as first member of object
#endif
#endif

    free(freeAddr);
}

typedef unsigned int __stdcall (*AddRefPtr)(void *thisptr);
typedef unsigned int __stdcall (*ReleasePtr)(void *thisptr);

void objc_release_ref(id obj)
{
    if ( obj == nil ) return;

    ((ReleasePtr) (((NSObject *) obj)->isa->IW_IInspectable[2]))(obj);
}

id objc_retain_ref(id obj)
{
    if ( obj == nil ) return nil;

    ((AddRefPtr) (((NSObject *) obj)->isa->IW_IInspectable[1]))(obj);

    return obj;
}

void objc_release_internal_ref(id obj)
{
    if ( _DecrementExtraRefCountWasZero((id) obj) ) {
        [(id) obj dealloc];
    }
}

id objc_retain_internal_ref(id obj)
{
    _IncrementExtraRefCount((id) obj);

    return obj;
}

size_t objc_getRetainCount(id obj)
{
    return _ExtraRefCount((id) obj);
}

BOOL objc_isRetained(id obj)
{
    return _ExtraRefExists((id) obj);
}


