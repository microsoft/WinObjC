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
#include <Foundation/NSCountedSet.h>
#include <CoreFoundation/CFBag.h>
#include <vector>

// HACKHACK: this is basically just a copy of NSSetConcrete with the addition of
// countForObject and using CFBag. To more properly share code here, a different strategy should be used
// but the class diagram with clustering makes that "difficult". For now be lazy.
@implementation NSCountedSet

/**
 @Status Interoperable
*/
- (NSUInteger)countForObject:(id)object {
    return CFBagGetCountOfValue(static_cast<CFBagRef>(self), object);
}

// Provide our own implementations of retain and release so that the bridging works out.
- (id)retain {
    CFRetain(static_cast<CFBagRef>(self));
    return self;
}

// Provide our own implementations of retain and release so that the bridging works out.
- (oneway void)release {
    CFRelease(static_cast<CFBagRef>(self));
}

// Provide our own implementations of retain and release so that the bridging works out.
- (id)autorelease {
    return (id)(CFAutorelease(static_cast<CFBagRef>(self)));
}

/**
 @Status Interoperable
*/
- (NSUInteger)retainCount {
    return CFGetRetainCount(static_cast<CFBagRef>(self));
}

+ (NSObject*)allocWithZone:(NSZone*)zone {
    return static_cast<NSObject*>(CFBagCreateMutable(NULL, 0, &kCFTypeBagCallBacks));
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    // No-op for bridged classes. This is because the CF system is responsible for the allocation and dealloc of the backing memory.
    // This is all handled via the CFRelease calls. When its CF ref count drops to 0 the CF version of dealloc is invoked so by the time
    // the NSObject dealloc is called, there is nothing left to do.
}

/**
 @Status Interoperable
*/
+ (void)load {
    // self here is referring to the Class object since its a + method.
    _CFRuntimeBridgeTypeToClass(CFBagGetTypeID(), self);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithObjects:(id*)objects count:(unsigned)count {
    for (unsigned int i = 0; i < count; i++) {
        CFBagAddValue(static_cast<CFMutableBagRef>(self), objects[i]);
    }

    return self;
}

/**
 @Status Interoperable
*/
- (unsigned)count {
    return CFBagGetCount(static_cast<CFBagRef>(self));
}

/**
 @Status Interoperable
*/
- (NSEnumerator*)objectEnumerator {
    std::vector<id> values([self count]);
    CFBagGetValues(static_cast<CFBagRef>(self), (const void**)values.data());

    return [[NSArray arrayWithObjects:values.data() count:values.size()] objectEnumerator];
}

/**
 @Status Interoperable
*/
- (id)member:(id)object {
    id objectToReturn = nil;

    if (CFBagGetValueIfPresent(static_cast<CFBagRef>(self), (void*)object, (const void**)&objectToReturn)) {
        return objectToReturn;
    }

    return nil;
}

/**
 @Status Interoperable
*/
- (void)addObject:(id)object {
    CFBagAddValue(static_cast<CFMutableBagRef>(self), object);
}

/**
 @Status Interoperable
*/
- (void)removeObject:(id)object {
    CFBagRemoveValue(static_cast<CFMutableBagRef>(self), object);
}

- (void)removeAllObjects {
    CFBagRemoveAllValues(static_cast<CFMutableBagRef>(self));
}

@end
