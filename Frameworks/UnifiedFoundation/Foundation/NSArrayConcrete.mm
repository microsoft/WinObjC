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
#include "NSArrayConcrete.h"
#include <CoreFoundation/CFArray.h>

static const wchar_t* TAG = L"NSArray";

@implementation NSArrayConcrete

// Provide our own implementations of retain and release so that the bridging works out.
- (id)retain {
    CFRetain(static_cast<CFArrayRef>(self));
    return self;
}

// Provide our own implementations of retain and release so that the bridging works out.
- (oneway void)release {
    CFRelease(static_cast<CFArrayRef>(self));
}

// Provide our own implementations of retain and release so that the bridging works out.
- (id)autorelease {
    return (id)(CFAutorelease(static_cast<CFArrayRef>(self)));
}

/**
 @Status Interoperable
*/
- (NSUInteger)retainCount {
    return CFGetRetainCount(static_cast<CFArrayRef>(self));
}

+ (NSArrayConcrete*)allocWithZone:(NSZone*)zone {
    return static_cast<NSArrayConcrete*>(CFArrayCreateMutable(NULL, 0, &kCFTypeArrayCallBacks));
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-missing-super-calls"
/**
 @Status Interoperable
*/
- (void)dealloc {
    // No-op for bridged classes. This is because the CF system is responsible for the allocation and dealloc of the backing memory.
    // This is all handled via the CFRelease calls. When its CF ref count drops to 0 the CF version of dealloc is invoked so by the time
    // the NSObject dealloc is called, there is nothing left to do.
}
#pragma clang diagnostic pop

/**
 @Status Interoperable
*/
+ (void)load {
    // self here is referring to the Class object since its a + method.
    _CFRuntimeBridgeTypeToClass(CFArrayGetTypeID(), self);
}

/**
 @Status Interoperable
*/
- (NSArray*)initWithObjects:(id*)objs count:(NSUInteger)count {
    for (unsigned int i = 0; i < count; i++) {
        CFArrayAppendValue(static_cast<CFMutableArrayRef>(self), objs[i]);
    }

    return self;
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
