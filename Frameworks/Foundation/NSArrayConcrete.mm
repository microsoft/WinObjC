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
#include "CFHelpers.h"
#include "CFFoundationInternal.h"
#include "NSArrayConcrete.h"
#include <CoreFoundation/CFArray.h>

static const wchar_t* TAG = L"NSArray";

#pragma region Immutable Concrete Subclass
@implementation NSArrayConcrete {
@private
    StrongId<NSCFArray> _nscf;
}

- (instancetype)init {
    return [self initWithObjects:nil count:0];
}

- (instancetype)initWithObjects:(id _Nonnull const*)objs count:(NSUInteger)count {
    if (self = [super init]) {
        _nscf.attach(reinterpret_cast<NSCFArray*>(
            static_cast<NSArray*>((CFArrayCreate(NULL, (const void**)(objs), count, &kCFTypeArrayCallBacks)))));
    }
    return self;
}

- INNER_BRIDGE_CALL(_nscf, NSUInteger, count);
- INNER_BRIDGE_CALL(_nscf, id, objectAtIndex:(NSUInteger)index);

@end
#pragma endregion

#pragma region Mutable Concrete Subclass
@implementation NSMutableArrayConcrete {
@private
    StrongId<NSCFArray> _nscf;
}

- (instancetype)init {
    return [self initWithObjects:nil count:0];
}

- (instancetype)initWithObjects:(id _Nonnull const*)objs count:(NSUInteger)count {
    if (self = [super init]) {
        _nscf.attach(reinterpret_cast<NSCFArray*>(static_cast<NSArray*>((CFArrayCreateMutable(NULL, 0, &kCFTypeArrayCallBacks)))));
        for (unsigned int i = 0; i < count; i++) {
            [_nscf addObject:objs[i]];
        }
    }
    return self;
}

- (instancetype)initWithCapacity:(NSUInteger)numElements {
    if (self = [super init]) {
        _nscf.attach(
            reinterpret_cast<NSCFArray*>(static_cast<NSArray*>((CFArrayCreateMutable(NULL, numElements, &kCFTypeArrayCallBacks)))));
    }
    return self;
}

- INNER_BRIDGE_CALL(_nscf, NSUInteger, count);
- INNER_BRIDGE_CALL(_nscf, id, objectAtIndex:(NSUInteger)index);
- INNER_BRIDGE_CALL(_nscf, void, removeObjectAtIndex:(NSUInteger)index);
- INNER_BRIDGE_CALL(_nscf, void, removeLastObject);
- INNER_BRIDGE_CALL(_nscf, void, replaceObjectAtIndex:(NSUInteger)index withObject:(NSObject*)obj);
- INNER_BRIDGE_CALL(_nscf, void, insertObject:(NSObject*)objAddr atIndex:(NSUInteger)index);
- INNER_BRIDGE_CALL(_nscf, void, removeAllObjects);
- INNER_BRIDGE_CALL(_nscf, void, addObject:(NSObject*)objAddr);

@end
#pragma endregion

#pragma region NSCF Bridged Class
@implementation NSCFArray

BRIDGED_CLASS_REQUIRED_IMPLS(CFArrayRef, CFArrayGetTypeID, NSArray, NSCFArray)

- (instancetype)initWithObjects:(id _Nonnull const*)objs count:(NSUInteger)count {
    FAIL_FAST();
    return nil;
}

- (instancetype)initWithCapacity:(NSUInteger)numElements {
    FAIL_FAST();
    return nil;
}

- (NSUInteger)count {
    return CFArrayGetCount((CFArrayRef)self);
}

- (id)objectAtIndex:(NSUInteger)index {
    if (index >= CFArrayGetCount((CFArrayRef)self)) {
        TraceWarning(TAG, L"objectAtIndex: index > count (%d > %d), throwing exception\n", index, CFArrayGetCount((CFArrayRef)self));
        [NSException raise:@"Array out of bounds" format:@""];
        return nil;
    }
    return (id)CFArrayGetValueAtIndex((CFArrayRef)self, index);
}

- (void)removeObjectAtIndex:(NSUInteger)index {
    CFArrayRemoveValueAtIndex(static_cast<CFMutableArrayRef>(self), index);
}

- (void)removeLastObject {
    NSUInteger count = [self count];
    CFArrayRemoveValueAtIndex(static_cast<CFMutableArrayRef>(self), count - 1);
}

- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(NSObject*)obj {
    //  Fastpath
    CFRange range;
    range.location = index;
    range.length = 1;
    CFArrayReplaceValues(static_cast<CFMutableArrayRef>(self), range, (const void**)(&obj), 1);
}

- (void)insertObject:(NSObject*)objAddr atIndex:(NSUInteger)index {
    CFArrayInsertValueAtIndex(static_cast<CFMutableArrayRef>(self), index, reinterpret_cast<const void*>(objAddr));
}

- (void)removeAllObjects {
    CFArrayRemoveAllValues((CFMutableArrayRef)self);
}

- (void)addObject:(NSObject*)objAddr {
    CFArrayAppendValue((CFMutableArrayRef)self, (const void*)objAddr);
}

@end
#pragma endregion