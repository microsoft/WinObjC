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
#include "NSSetConcrete.h"
#include <CoreFoundation/CFSet.h>
#include <vector>

@implementation NSSetConcrete

// Provide our own implementations of retain and release so that the bridging works out.
- (id)retain {
    CFRetain(static_cast<CFSetRef>(self));
    return self;
}

// Provide our own implementations of retain and release so that the bridging works out.
- (oneway void)release {
    CFRelease(static_cast<CFSetRef>(self));
}

// Provide our own implementations of retain and release so that the bridging works out.
- (id)autorelease {
    return (id)(CFAutorelease(static_cast<CFSetRef>(self)));
}

/**
 @Status Interoperable
*/
- (NSUInteger)retainCount {
    return CFGetRetainCount(static_cast<CFSetRef>(self));
}

+ (NSObject*)allocWithZone:(NSZone*)zone {
    return static_cast<NSObject*>(CFSetCreateMutable(NULL, 0, &kCFTypeSetCallBacks));
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
    _CFRuntimeBridgeTypeToClass(CFSetGetTypeID(), self);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithObjects:(id*)objects count:(unsigned)count {
    for (unsigned int i = 0; i < count; i++) {
        CFSetAddValue(static_cast<CFMutableSetRef>(self), objects[i]);
    }

    return self;
}

/**
 @Status Interoperable
*/
- (unsigned)count {
    return CFSetGetCount(static_cast<CFSetRef>(self));
}

/**
 @Status Interoperable
*/
- (NSEnumerator*)objectEnumerator {
    std::vector<id> values([self count]);
    CFSetGetValues(static_cast<CFSetRef>(self), (const void**)values.data());

    return [[NSArray arrayWithObjects:values.data() count:values.size()] objectEnumerator];
}

/**
 @Status Interoperable
*/
- (id)member:(id)object {
    id objectToReturn = nil;

    if (CFSetGetValueIfPresent(static_cast<CFSetRef>(self), (void*)object, (const void**)&objectToReturn)) {
        return objectToReturn;
    }

    return nil;
}

/**
 @Status Interoperable
*/
- (void)addObject:(id)object {
    CFSetAddValue(static_cast<CFMutableSetRef>(self), object);
}

/**
 @Status Interoperable
*/
- (void)removeObject:(id)object {
    CFSetRemoveValue(static_cast<CFMutableSetRef>(self), object);
}

- (void)removeAllObjects {
    CFSetRemoveAllValues(static_cast<CFMutableSetRef>(self));
}

@end
