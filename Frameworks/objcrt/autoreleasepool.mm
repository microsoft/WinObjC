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

#include <stdio.h>
#include <deque>

#include "runtime.h"

class ObjCrtMutex
{
public:
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

@interface NSObject {
@public
    WinRT_isa isa;
}
@end

@interface NSAutoreleasePool : NSObject {
@public
    NSAutoreleasePool*_parent;
    NSAutoreleasePool *_childPool;
    id                 _lastItem;
    std::deque<id*> pages;
    unsigned nextSlot;
}
@end

#include "runtime-private.h"
#include "Hash.h"

static bool _AutoReleasePoolInitialized = false;
typedef HashSet<id> WeakObjectsSet;
extern WeakObjectsSet _weak_objects;
extern ObjCrtMutex &_objLifetimeLock;

@class NSAutoreleasePool;
__declspec(thread) id tlsAutorelease;

#define PAGESIZE 1024

NSAutoreleasePool* NSThreadCurrentPool()
{
    return tlsAutorelease;
}

void NSThreadSetCurrentPool(id pool)
{
    tlsAutorelease = pool;
}

#define NSOBJECT_MAGIC  0x234BC09A
#define NSOBJECT_MANAGED_MAGIC  0x234BA55E

@implementation NSAutoreleasePool 
    -(void) insert:(id)object {
        if ( object != nil ) {
            if ( *((uint32_t *) ((char *) object - 4)) == NSOBJECT_MAGIC || *((uint32_t *) ((char *) object - 4)) == NSOBJECT_MANAGED_MAGIC ) {
                //  Objects being dellocated should not be autoreleased
                if ( (*((volatile int *) (uint32_t *) ((char *) object - 8)) & 0xF0000000) != 0x00000000 ) {
                    return;
                }
            }
        }

        if ( self->pages.empty() || nextSlot >= PAGESIZE ) {
            id* newPage = new id[PAGESIZE];
            self->pages.push_back(newPage);
            nextSlot = 0;
        }

        self->pages.back()[nextSlot++] = object;
    }

    +(void) load {
        _AutoReleasePoolInitialized = true;
    }

    -(instancetype) init {
        NSAutoreleasePool* current = NSThreadCurrentPool();

        _parent=current;

        if(current!=nil)
            current->_childPool = self;

        _childPool=nil;

        NSThreadSetCurrentPool(self);

        return self;
    }

    -(void) addObject:(id)object {
        if ( self->_lastItem != nil ) {
            id item = self->_lastItem;
            self->_lastItem = nil;
            [self insert: item];
        }

        self->_lastItem = object;
    }

    +(void) addObject:(id)object {
        //EbrDebugLog("Autoreleasing object %x \"%s\"\n", object, object_getClassName(object));
        NSAutoreleasePool *curPool = NSThreadCurrentPool();
        if (!curPool) {
            //dbg_printf("No autorelease pool for this thread!");
        }
        [curPool addObject:object];
    }

    -(void) drain {
        [self release];
    }

    -(void) dealloc {
        [_childPool release];

        while (_lastItem || pages.size()) {
            if (_lastItem) {
                id item = _lastItem;
                _lastItem = nil;
                [item release];
            } else {
                id* page = pages.front();

                // If we aren't the last page in the list, we have to assume it's full because the
                // subsequent page wouldn't have been created.

                size_t count;
                if ( pages.size() == 1 )
                {
                    count = nextSlot;
                    nextSlot = 0;
                }
                else
                {
                    count = PAGESIZE;
                }

                pages.pop_front();

                for (size_t i = 0; i < count; ++i) {
                    [page[i] release];
                }
                delete page;
            }
        }

        NSThreadSetCurrentPool(_parent);

        if(_parent!=nil)
            _parent->_childPool=nil;

        [super dealloc];
    }

    
@end

OBJCRT_EXPORT
extern "C" id objc_autorelease(id value) {
    if (value != nil) [value autorelease];
    return value;
}

OBJCRT_EXPORT
extern "C" void objc_autoreleasePoolPop(void *pool) {
    [pool release];
}


OBJCRT_EXPORT
extern "C" void * objc_autoreleasePoolPush() {
    if ( !_AutoReleasePoolInitialized ) return NULL;

    return (void *) [[NSAutoreleasePool alloc] init];
}

OBJCRT_EXPORT
extern "C" void objc_release(id value) {
    [value release];
}

OBJCRT_EXPORT
extern "C" id objc_retain(id value) {
    return [value retain];
}

OBJCRT_EXPORT
extern "C" id objc_retainAutorelease(id value) {
    return objc_autorelease(objc_retain(value));
}

OBJCRT_EXPORT
extern "C" id objc_autoreleaseReturnValue(id obj)
{
    return objc_autorelease(obj);
}

OBJCRT_EXPORT
extern "C" id objc_retainAutoreleaseReturnValue(id value) {
    return objc_autoreleaseReturnValue(objc_retain(value));
}

OBJCRT_EXPORT
extern "C" id objc_retainAutoreleasedReturnValue(id value) {
    NSAutoreleasePool* pool = NSThreadCurrentPool();
    if ( pool && pool->_lastItem == value ) {
        pool->_lastItem = nil;
        return value;
    } else {
        return objc_retain(value);
    }
}

OBJCRT_EXPORT
extern "C" id objc_storeStrong(id *object, id value) {
    id oldValue = *object;
    if (oldValue == value)  return 0;

    /*
        Atomic update: it is imperative that *object never holds a non-owning
        reference. Ensuring that we have owning references to both the new and
        the old value when the change is made ensures this on strongly-ordered
        architextures like x86.
        FIXME: do we need barriers for, say,s PPC?
    */
    value = objc_retain(value);
    *object = value;
    objc_release(oldValue);

    return 0;
}

OBJCRT_EXPORT
extern "C" id objc_storeWeak(id *addr, id obj) {
    id old = *addr;
    if (nil == obj)
    {
        *addr = obj;
        return nil;
    }
    obj = objc_retainAutorelease(obj);
    *addr = obj;

    if ( obj != nil ) {
        _objLifetimeLock.lock();
        _weak_objects.insert(obj);
        _objLifetimeLock.unlock();
    }
    
    return obj;
}

OBJCRT_EXPORT
extern "C" id objc_getWeak(id *addr) {
    id ret = nil;

    _objLifetimeLock.lock();
    id obj = *addr;
    
    if ( _weak_objects.exists(obj) ) {
        ret = obj;
    }
    _objLifetimeLock.unlock();

    return ret;
}

OBJCRT_EXPORT
extern "C" id objc_loadWeakRetained(id *addr) {
    id ret = nil;

    _objLifetimeLock.lock();
    id obj = *addr;
    
    if ( _weak_objects.exists(obj) ) {
        obj = objc_retain(obj);
        ret = obj;
    }
    _objLifetimeLock.unlock();

    return ret;
}

OBJCRT_EXPORT
extern "C" id objc_loadWeak(id *object) {
    return objc_autorelease(objc_loadWeakRetained(object));
}

OBJCRT_EXPORT
extern "C" void objc_destroyWeak(id *obj) {
    objc_storeWeak(obj, nil);
}

OBJCRT_EXPORT
extern "C" id objc_initWeak(id *object, id value)
{
    *object = nil;
    return objc_storeWeak(object, value);
}

OBJCRT_EXPORT
extern "C" void objc_copyWeak(id *dest, id *src)
{
    objc_release(objc_initWeak(dest, objc_loadWeakRetained(src)));
}

OBJCRT_EXPORT
extern "C" void objc_moveWeak(id *dest, id *src)
{
    objc_release(objc_initWeak(dest, objc_loadWeakRetained(src)));
    objc_storeWeak(src, nil);
}
