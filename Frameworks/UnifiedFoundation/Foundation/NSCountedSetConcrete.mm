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

#import "Starboard.h"
#import "BridgeHelpers.h"
#import "CFHelpers.h"
#import "CFFoundationInternal.h"
#import "NSCountedSetConcrete.h"
#import <CoreFoundation/CFBag.h>
#import <vector>

#pragma region Immutable Concrete Subclass
@implementation NSCountedSetConcrete {
@private
    StrongId<NSCFCountedSet> _nscf;
}

- (instancetype)init {
    return [self initWithObjects:nil count:0];
}

- (instancetype)initWithObjects:(id _Nonnull const* _Nullable)objects count:(unsigned)count {
    if (self = [super init]) {
        _nscf.attach(static_cast<NSCFCountedSet*>(CFBagCreateMutable(NULL, 0, &kCFTypeBagCallBacks)));

        for (unsigned int i = 0; i < count; i++) {
            [_nscf addObject:objects[i]];
        }
    }
    return self;
}

- (instancetype)initWithCapacity:(unsigned)capacity {
    if (self = [super init]) {
        _nscf.attach(static_cast<NSCFCountedSet*>(CFBagCreateMutable(NULL, capacity, &kCFTypeBagCallBacks)));
    }
    return self;
}

- INNER_BRIDGE_CALL(_nscf, NSUInteger, countForObject:(id)object);
- INNER_BRIDGE_CALL(_nscf, unsigned, count);
- INNER_BRIDGE_CALL(_nscf, NSEnumerator*, objectEnumerator);
- INNER_BRIDGE_CALL(_nscf, id, member:(id)object);
- INNER_BRIDGE_CALL(_nscf, void, addObject:(id)object);
- INNER_BRIDGE_CALL(_nscf, void, removeObject:(id)object);
- INNER_BRIDGE_CALL(_nscf, void, removeAllObjects);

@end
#pragma endregion

#pragma region NSCF Bridged Class
@implementation NSCFCountedSet

BRIDGED_CLASS_REQUIRED_IMPLS(CFMutableBagRef, CFBagGetTypeID, NSCountedSet, NSCFCountedSet)

- (instancetype)initWithObjects:(id _Nonnull const* _Nullable)objects count:(unsigned)count {
    FAIL_FAST();
    return nil;
}

- (instancetype)initWithCapacity:(unsigned)capacity {
    FAIL_FAST();
    return nil;
}

- (NSUInteger)countForObject:(id)object {
    return CFBagGetCountOfValue(static_cast<CFBagRef>(self), object);
}

- (unsigned)count {
    return CFBagGetCount(static_cast<CFBagRef>(self));
}

- (NSEnumerator*)objectEnumerator {
    std::vector<id> values([self count]);
    CFBagGetValues(static_cast<CFBagRef>(self), (const void**)values.data());

    return [[NSArray arrayWithObjects:values.data() count:values.size()] objectEnumerator];
}

- (id)member:(id)object {
    id objectToReturn = nil;

    if (CFBagGetValueIfPresent(static_cast<CFBagRef>(self), (void*)object, (const void**)&objectToReturn)) {
        return objectToReturn;
    }

    return nil;
}

- (void)addObject:(id)object {
    CFBagAddValue(static_cast<CFMutableBagRef>(self), object);
}

- (void)removeObject:(id)object {
    CFBagRemoveValue(static_cast<CFMutableBagRef>(self), object);
}

- (void)removeAllObjects {
    CFBagRemoveAllValues(static_cast<CFMutableBagRef>(self));
}

@end
#pragma endregion