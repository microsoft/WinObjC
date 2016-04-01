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

BRIDGED_CLASS_REQUIRED_IMPLS(CFSetRef, CFSetGetTypeID, NSSet, NSSetConcrete)

/**
@Status Interoperable
*/
- (instancetype)initWithObjects:(id _Nonnull const*)objs count:(NSUInteger)count {
    NSSetConcrete* newSelf = nullptr;
    // need to figure out if this is a mutable init or not.
    if ([self isMemberOfClass:[NSMutableSet class]]) {
        newSelf = reinterpret_cast<NSSetConcrete*>(static_cast<NSMutableSet*>(CFSetCreateMutable(NULL, 0, &kCFTypeSetCallBacks)));
        for (unsigned int i = 0; i < count; i++) {
            CFSetAddValue(static_cast<CFMutableSetRef>(newSelf), objs[i]);
        }
    } else {
        newSelf =
            reinterpret_cast<NSSetConcrete*>(static_cast<NSSet*>(CFSetCreate(NULL, (const void**)(objs), count, &kCFTypeSetCallBacks)));
    }

    [self release];
    self = newSelf;
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    return [self initWithObjects:nullptr count:0];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCapacity:(NSUInteger)numElements {
    NSSetConcrete* newSelf =
        reinterpret_cast<NSSetConcrete*>(static_cast<NSMutableSet*>(CFSetCreateMutable(NULL, numElements, &kCFTypeSetCallBacks)));
    [self release];
    self = newSelf;
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

/**
 @Status Interoperable
*/
- (void)removeAllObjects {
    CFSetRemoveAllValues(static_cast<CFMutableSetRef>(self));
}

@end
