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
#include "StubReturn.h"
#include "CFHelpers.h"
#include "CFFoundationInternal.h"
#include "NSCFArray.h"
#include <CoreFoundation/CFArray.h>

static const wchar_t* TAG = L"NSArray";

@implementation NSCFArray

BRIDGED_CLASS_REQUIRED_IMPLS(CFArrayRef, CFArrayGetTypeID, NSArray, NSCFArray)

/**
 @Status Interoperable
*/
- (instancetype)initWithObjects:(id _Nonnull const*)objs count:(NSUInteger)count {
    FAIL_FAST();
    return nil;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    FAIL_FAST();
    return nil;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCapacity:(NSUInteger)numElements {
    FAIL_FAST();
    return nil;
}

/**
 @Status Interoperable
*/
- (NSUInteger)count {
    return CFArrayGetCount((CFArrayRef)self);
}

/**
 @Status Interoperable
*/
- (id)objectAtIndex:(NSUInteger)index {
    if (index >= CFArrayGetCount((CFArrayRef)self)) {
        TraceWarning(TAG, L"objectAtIndex: index > count (%d > %d), throwing exception\n", index, CFArrayGetCount((CFArrayRef)self));
        [NSException raise:@"Array out of bounds" format:@""];
        return nil;
    }
    return (id)CFArrayGetValueAtIndex((CFArrayRef)self, index);
}

/**
 @Status Interoperable
*/
- (void)removeObjectAtIndex:(NSUInteger)index {
    CFArrayRemoveValueAtIndex(static_cast<CFMutableArrayRef>(self), index);
}

/**
 @Status Interoperable
*/
- (void)removeLastObject {
    NSUInteger count = [self count];
    CFArrayRemoveValueAtIndex(static_cast<CFMutableArrayRef>(self), count - 1);
}

/**
 @Status Interoperable
*/
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(NSObject*)obj {
    //  Fastpath
    CFRange range;
    range.location = index;
    range.length = 1;
    CFArrayReplaceValues(static_cast<CFMutableArrayRef>(self), range, (const void**)(&obj), 1);
}

/**
 @Status Interoperable
*/
- (void)insertObject:(NSObject*)objAddr atIndex:(NSUInteger)index {
    CFArrayInsertValueAtIndex(static_cast<CFMutableArrayRef>(self), index, reinterpret_cast<const void*>(objAddr));
}

/**
 @Status Interoperable
*/
- (void)removeAllObjects {
    CFArrayRemoveAllValues((CFMutableArrayRef)self);
}

/**
 @Status Interoperable
*/
- (void)addObject:(NSObject*)objAddr {
    CFArrayAppendValue((CFMutableArrayRef)self, (const void*)objAddr);
}

@end
