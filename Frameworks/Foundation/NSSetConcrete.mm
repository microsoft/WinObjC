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

#pragma region Immutable Concrete Subclass
@implementation NSSetConcrete {
@private
    StrongId<NSCFSet> _nscf;
}

- (instancetype)init {
    return [self initWithObjects:nil count:0];
}

- (instancetype)initWithObjects:(id _Nonnull const*)objs count:(NSUInteger)count {
    if (self = [super init]) {
        _nscf.attach(
            reinterpret_cast<NSCFSet*>(static_cast<NSSet*>((CFSetCreate(NULL, (const void**)(objs), count, &kCFTypeSetCallBacks)))));
    }
    return self;
}

- INNER_BRIDGE_CALL(_nscf, NSUInteger, count);
- INNER_BRIDGE_CALL(_nscf, id, member:(id)object);
- INNER_BRIDGE_CALL(_nscf, NSEnumerator*, objectEnumerator);

- INNER_BRIDGE_CALL(_nscf, NSUInteger, countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(NSUInteger)maxCount);

@end
#pragma endregion

#pragma region Mutable Concrete Subclass
@implementation NSMutableSetConcrete {
@private
    StrongId<NSCFSet> _nscf;
}

- (instancetype)init {
    return [self initWithObjects:nil count:0];
}

- (instancetype)initWithObjects:(id _Nonnull const*)objs count:(NSUInteger)count {
    if (self = [self initWithCapacity:count]) {
        for (unsigned i = 0; i < count; i++) {
            [_nscf addObject:objs[i]];
        }
    }
    return self;
}

- (instancetype)initWithCapacity:(NSUInteger)numItems {
    if (self = [super init]) {
        _nscf.attach(reinterpret_cast<NSCFSet*>(static_cast<NSSet*>((CFSetCreateMutable(NULL, numItems, &kCFTypeSetCallBacks)))));
    }
    return self;
}

- INNER_BRIDGE_CALL(_nscf, NSUInteger, count);
- INNER_BRIDGE_CALL(_nscf, id, member:(id)object);
- INNER_BRIDGE_CALL(_nscf, NSEnumerator*, objectEnumerator);
- INNER_BRIDGE_CALL(_nscf, void, addObject:(id)object);
- INNER_BRIDGE_CALL(_nscf, void, removeObject:(id)object);
- INNER_BRIDGE_CALL(_nscf, void, removeAllObjects);

@end
#pragma endregion

#pragma region NSCF Bridged Class
@implementation NSCFSet

BRIDGED_CLASS_REQUIRED_IMPLS(CFSetRef, CFSetGetTypeID, NSSet, NSCFSet)

- (instancetype)initWithObjects:(id _Nonnull const*)objs count:(NSUInteger)count {
    FAIL_FAST();
    return nil;
}

- (instancetype)initWithCapacity:(NSUInteger)numElements {
    FAIL_FAST();
    return nil;
}

- (unsigned)count {
    return CFSetGetCount(static_cast<CFSetRef>(self));
}

- (NSEnumerator*)objectEnumerator {
    std::vector<id> values([self count]);
    CFSetGetValues(static_cast<CFSetRef>(self), (const void**)values.data());

    return [[NSArray arrayWithObjects:values.data() count:values.size()] objectEnumerator];
}

- (id)member:(id)object {
    id objectToReturn = nil;

    if (CFSetGetValueIfPresent(static_cast<CFSetRef>(self), (void*)object, (const void**)&objectToReturn)) {
        return objectToReturn;
    }

    return nil;
}

- (void)addObject:(id)object {
    CFSetAddValue(static_cast<CFMutableSetRef>(self), object);
}

- (void)removeObject:(id)object {
    CFSetRemoveValue(static_cast<CFMutableSetRef>(self), object);
}

- (void)removeAllObjects {
    CFSetRemoveAllValues(static_cast<CFMutableSetRef>(self));
}

- BRIDGED_COLLECTION_FAST_ENUMERATION(CFSet);

@end
#pragma endregion