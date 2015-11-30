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

#include "Starboard.h"

#include "CoreFoundation/CFArray.h"
#include "CFArrayInternal.h"
#include "Foundation/NSMutableArray.h"

#include <sys/stat.h>

#include <vector>
#include <new>

class __CFArray;

static IWLazyClassLookup _LazyNSArray("NSArray"), _LazyNSMutableArray("NSMutableArray");
static IWLazyIvarLookup<uint8_t[]> _LazyArraySpaceOffset(_LazyNSArray, "_arraySpace");
static IWLazyIvarLookup<__CFArray*> _LazyArrOffset(_LazyNSArray, "arr");

const void* CFNSRetain(CFAllocatorRef allocator, const void* obj);
void CFNSRelease(CFAllocatorRef allocator, const void* obj);
Boolean CFNSEqual(const void* obj1, const void* obj2);

const CFArrayCallBacks kCFTypeArrayCallBacks = {
    0, CFNSRetain, CFNSRelease, 0, CFNSEqual,
};
const CFArrayCallBacks kNSTypeArrayCallBacks = {
    0, CFNSRetain, CFNSRelease, 0, CFNSEqual,
};

class __CFArray {
public:
    CFArrayCallBacks callbacks;
    CFAllocatorRef allocator;
    uint32_t objCount;
    bool heapAlloced;

#define INPLACE_CAPACITY 4
    union {
        id objs[INPLACE_CAPACITY];
        struct {
            id* objsArray;
            uint32_t objsCapacity;
        } heap;
    } contents;

public:
    __CFArray(const CFArrayCallBacks* c) {
        if (c) {
            callbacks = *c;
        } else {
            memset(&callbacks, 0, sizeof(callbacks));
        }

        objCount = 0;
        heapAlloced = false;
    }

    __CFArray(const CFArrayCallBacks* c, id* objs, int count, bool retain) {
        objCount = 0;
        heapAlloced = false;

        if (c) {
            callbacks = *c;
        } else {
            memset(&callbacks, 0, sizeof(callbacks));
        }

        setCapacity(count);
        memcpy(objsPtr(), objs, count * sizeof(id));
        objCount = count;

        if (retain && callbacks.retain != 0 && count > 0) {
            id* objStart = objsPtr();
            for (unsigned i = 0; i < objCount; i++) {
                objStart[i] = retainObj(objStart[i]);
            }
        }
    }

    ~__CFArray() {
        if (heapAlloced) {
            free(contents.heap.objsArray);
        }
        heapAlloced = false;
        objCount = 0;
    }

    void setCapacity(uint32_t capacity) {
        if (capacity <= INPLACE_CAPACITY) {
            return;
        }
        if (heapAlloced && capacity <= contents.heap.objsCapacity) {
            if (contents.heap.objsCapacity <= 256) {
                return;
            }

            //  Shrink the size of our object capacity?
            uint32_t newCapacity = contents.heap.objsCapacity;
            while ((newCapacity >> 1) >= capacity + 16) {
                newCapacity >>= 1;
            }

            if (newCapacity != contents.heap.objsCapacity) {
                contents.heap.objsCapacity = newCapacity;
                contents.heap.objsArray = (id*)realloc(contents.heap.objsArray, sizeof(id) * contents.heap.objsCapacity);
            }
            return;
        }

        if (!heapAlloced) {
            if (capacity < 8) {
                capacity = 8;
            }
            id* heapArr = (id*)malloc(sizeof(id) * capacity);
            for (unsigned i = 0; i < objCount; i++) {
                heapArr[i] = contents.objs[i];
            }
            heapAlloced = true;
            contents.heap.objsArray = heapArr;
            contents.heap.objsCapacity = capacity;
            return;
        } else {
            while (contents.heap.objsCapacity < capacity) {
                contents.heap.objsCapacity *= 2;
            }
            contents.heap.objsArray = (id*)realloc(contents.heap.objsArray, sizeof(id) * contents.heap.objsCapacity);
        }
    }

    id* objsPtr() {
        if (heapAlloced) {
            return contents.heap.objsArray;
        } else {
            return contents.objs;
        }
    }

    uint32_t getCount() {
        return objCount;
    }

    void removeAllObjects() {
        if (objCount == 0)
            return;

        int count = objCount;
        id localValues[INPLACE_CAPACITY];
        bool freeValues;
        id* values;

        if (!heapAlloced) {
            memcpy(localValues, contents.objs, count * sizeof(id));
            values = localValues;
            freeValues = false;
        } else {
            values = contents.heap.objsArray;
            freeValues = true;
        }

        heapAlloced = false;
        objCount = 0;

        if (callbacks.release != 0) {
            for (int i = 0; i < count; i++) {
                releaseObj(values[i]);
            }
        }

        if (freeValues)
            free(values);
    }

    id retainObj(id object) {
        if (callbacks.retain == kNSTypeArrayCallBacks.retain) {
            return static_cast<id>(CFNSRetain(allocator, (void*)object));
        } else {
            return static_cast<id>(callbacks.retain(allocator, object));
        }
    }

    id releaseObj(id object) {
        if (callbacks.release == kNSTypeArrayCallBacks.release) {
            CFNSRelease(allocator, (void*)object);
        } else {
            callbacks.release(allocator, object);
        }

        return object;
    }

    void addObject(id object, bool retain = true) {
        if (object == 0) {
            assert(0);
        }

        //  Call retain function on object
        if ((retain) && (callbacks.retain != 0))
            object = retainObj(object);

        assert(object != 0);

        setCapacity(objCount + 1);
        objsPtr()[objCount] = object;
        objCount++;
    }

    void replaceObject(id object, uint32_t index) {
        if (object == 0) {
            assert(0);
        }

        assert(index <= objCount);

        //  Call retain function on new object
        if (callbacks.retain != 0)
            object = retainObj(object);

        assert(object != 0);

        //  Call release function on old object
        id oldObj = objsPtr()[index];
        if (callbacks.release != 0)
            releaseObj(oldObj);

        objsPtr()[index] = object;
    }

    void addObjectAtIndex(id object, uint32_t index) {
        if (object == 0) {
            assert(0);
        }
        assert(index <= objCount);

        //  Call retain function on object
        if (callbacks.retain != 0)
            object = retainObj(object);

        assert(object != 0);

        setCapacity(objCount + 1);
        memmove(&objsPtr()[index + 1], &objsPtr()[index], (objCount - index) * sizeof(id));
        objsPtr()[index] = object;
        objCount++;
    }

    id objectFromIndex(uint32_t idx) {
        if (idx >= objCount) {
            assert(0);
        }

        return objsPtr()[idx];
    }

    void removeObject(uint32_t idx) {
        assert(idx < objCount);

        id obj = objsPtr()[idx];

        memmove(&objsPtr()[idx], &objsPtr()[idx + 1], (objCount - idx - 1) * sizeof(id));
        objCount--;
        setCapacity(objCount);

        if (callbacks.release != 0)
            releaseObj(obj);
    }

    void moveObjectAtIndexToEnd(uint32_t idx) {
        assert(idx < objCount);

        id obj = objsPtr()[idx];
        memmove(&objsPtr()[idx], &objsPtr()[idx + 1], (objCount - idx - 1) * sizeof(id));
        objsPtr()[objCount - 1] = obj;
    }

    BOOL doesContainValue(uint32_t start, uint32_t length, id value) {
        assert(start + length <= objCount);
        uint32_t cur = 0;

        id* objs = objsPtr();
        while (cur < objCount && length > 0) {
            id curValue = objs[cur];

            if (callbacks.equal != 0) {
                if (callbacks.equal(value, curValue)) {
                    return TRUE;
                }
            } else {
                if (value == curValue) {
                    return TRUE;
                }
            }

            length--;
            cur++;
        }

        return FALSE;
    }
};

/**
 @Status Interoperable
*/
CFMutableArrayRef CFArrayCreateMutable(CFAllocatorRef allocator, CFIndex max, const CFArrayCallBacks* valueCallbacks) {
    static int numCreated;
    numCreated++;

    NSArray* ret = [_LazyNSMutableArray alloc];
    _LazyArrOffset.member(ret) = new (_LazyArraySpaceOffset.member(ret)) __CFArray(valueCallbacks);

    return (CFMutableArrayRef)ret;
}

/**
 @Status Interoperable
*/
CFMutableArrayRef CFArrayCreateMutableCopy(CFAllocatorRef allocator, CFIndex max, CFArrayRef array) {
    id ret = [(NSArray*)array mutableCopy];

    return (CFMutableArrayRef)ret;
}

/**
 @Status Interoperable
*/
CFArrayRef CFArrayCreateCopy(CFAllocatorRef allocator, CFArrayRef array) {
    id ret = [(NSArray*)array copy];

    return (CFArrayRef)ret;
}

/**
 @Status Interoperable
*/
CFArrayRef CFArrayCreate(CFAllocatorRef allocator, const void** values, CFIndex numValues, const CFArrayCallBacks* valueCallbacks) {
    NSArray* ret = [_LazyNSArray alloc];
    __CFArray* cfarr = new (_LazyArraySpaceOffset.member(ret)) __CFArray(valueCallbacks);
    _LazyArrOffset.member(ret) = cfarr;

    for (CFIndex i = 0; i < numValues; i++) {
        cfarr->addObject(((id*)values)[i]);
    }

    return (CFArrayRef)ret;
}

/**
 @Status Interoperable
*/
CFIndex CFArrayGetCount(CFArrayRef array) {
    return _LazyArrOffset.member(array)->getCount();
}

/**
 @Status Interoperable
*/
void CFArraySortValues(CFMutableArrayRef array, CFRange range, id comparator, id context) {
    [(NSArray*)array sortUsingFunction:comparator context:context range:range];
}

/**
 @Status Interoperable
*/
const void* CFArrayGetValueAtIndex(CFArrayRef array, CFIndex index) {
    return (const void*)_LazyArrOffset.member(array)->objectFromIndex(index);
}

/**
 @Status Interoperable
*/
void CFArrayGetValues(CFArrayRef array, CFRange range, void** values) {
    for (unsigned i = range.location; i < range.location + range.length; i++) {
        values[i] = (void*)_LazyArrOffset.member(array)->objectFromIndex(i);
    }
}

/**
 @Status Interoperable
*/
void CFArrayAppendValue(CFMutableArrayRef array, const void* value) {
    _LazyArrOffset.member(array)->addObject((id)value, true);
}

void CFArrayAppendValueUnretained(CFMutableArrayRef array, const void* value) {
    _LazyArrOffset.member(array)->addObject((id)value, false);
}

void CFArrayAppendValueExport(CFMutableArrayRef array, const void* value) {
    CFArrayAppendValue(array, value);
}

/**
 @Status Interoperable
*/
void CFArrayAppendArray(CFMutableArrayRef array, CFArrayRef arrayToAppend, CFRange range) {
    for (unsigned i = range.location; i < range.location + range.length; i++) {
        const void* curVal = CFArrayGetValueAtIndex(arrayToAppend, i);
        CFArrayAppendValue(array, curVal);
    }
}

/**
 @Status Interoperable
*/
Boolean CFArrayContainsValue(CFArrayRef array, CFRange range, const void* value) {
    return _LazyArrOffset.member(array)->doesContainValue(range.location, range.length, (id)value) != FALSE;
}

Boolean CFArrayDoesContainValue(CFArrayRef array, const void* value) {
    return _LazyArrOffset.member(array)->doesContainValue(0, CFArrayGetCount(array), (id)value) != FALSE;
}

/**
 @Status Interoperable
*/
void CFArrayInsertValueAtIndex(CFMutableArrayRef array, CFIndex index, const void* value) {
    _LazyArrOffset.member(array)->addObjectAtIndex((id)value, index);
}

/**
 @Status Interoperable
*/
void CFArraySetValueAtIndex(CFMutableArrayRef self, CFIndex index, const void* value) {
    _LazyArrOffset.member(self)->replaceObject((id)value, index);
}

/**
 @Status Interoperable
*/
void CFArrayReplaceValues(CFMutableArrayRef array, CFRange range, const void** values, CFIndex newCount) {
    CFIndex curPos = range.location;
    const id* newValues = (const id*)values;

    //  Replace/remove items
    for (unsigned i = 0; i < range.length; i++) {
        if (newCount > 0) {
            _LazyArrOffset.member(array)->replaceObject(*newValues, curPos);

            curPos++;
            newValues++;
            newCount--;
        } else {
            _LazyArrOffset.member(array)->removeObject(curPos);
        }
    }

    //  Insert any leftover
    while (newCount > 0) {
        _LazyArrOffset.member(array)->addObjectAtIndex(*newValues, curPos);

        curPos++;
        newValues++;
        newCount--;
    }
}

/**
 @Status Interoperable
*/
void CFArrayRemoveAllValues(CFMutableArrayRef array) {
    if (_LazyArrOffset.member(array) == nil)
        return;

    _LazyArrOffset.member(array)->removeAllObjects();
}

/**
 @Status Interoperable
*/
void CFArrayRemoveValueAtIndex(CFMutableArrayRef array, CFIndex idx) {
    _LazyArrOffset.member(array)->removeObject(idx);
}

void CFArrayMoveValueAtIndexToEnd(CFMutableArrayRef array, CFIndex idx) {
    _LazyArrOffset.member(array)->moveObjectAtIndexToEnd(idx);
}

void CFArrayGetValueEnumerator(CFArrayRef arr, void* enumeratorHolder) {
    *((id*)enumeratorHolder) = 0;
}

int CFArrayGetNextValue(CFArrayRef arr, void* enumeratorHolder, id* ret, int count) {
    unsigned size = _LazyArrOffset.member(arr)->getCount();
    int i;

    for (i = 0; i < count; i++) {
        if (*((uint32_t*)enumeratorHolder) >= size)
            break;
        ret[i] = _LazyArrOffset.member(arr)->objectFromIndex(*((uint32_t*)enumeratorHolder));

        (*((uint32_t*)enumeratorHolder))++;
    }

    return i;
}

void _CFArrayInitInternal(CFArrayRef arr) {
    assert(sizeof(__CFArray) <= __CFARRAY_SIZE_BYTES);
    NSArray* pArr = (NSArray*)arr;
    _LazyArrOffset.member(arr) = new (_LazyArraySpaceOffset.member(pArr)) __CFArray(&kNSTypeArrayCallBacks);
}

void _CFArrayInitInternalWithObjects(CFArrayRef arr, const void** objects, int count, bool retain) {
    NSArray* pArr = (NSArray*)arr;
    _LazyArrOffset.member(arr) = new (_LazyArraySpaceOffset.member(pArr)) __CFArray(&kNSTypeArrayCallBacks, (id*)objects, count, retain);
}

void _CFArrayDestroyInternal(CFArrayRef arr) {
    _LazyArrOffset.member(arr)->~__CFArray();
    _LazyArrOffset.member(arr) = NULL;
}

void** _CFArrayGetPtr(CFArrayRef array) {
    return (void**)_LazyArrOffset.member(array)->objsPtr();
}
