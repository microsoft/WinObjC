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
#include "Foundation/NSMutableSet.h"
#include "Foundation/NSMutableArray.h"
#include "NSRaise.h"
#include "NSCFSet.h"
#include "BridgeHelpers.h"

@implementation NSMutableSet

+ ALLOC_PROTOTYPE_SUBCLASS_WITH_ZONE(NSMutableSet, NSMutableSetPrototype);

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    return [[NSSet allocWithZone:zone] initWithSet:self];
}

/**
 @Status Interoperable
*/
+ (instancetype)setWithCapacity:(unsigned)capacity {
    return [[[self alloc] initWithCapacity:capacity] autorelease];
}

/**
 @Status Interoperable
*/
- (void)addObjectsFromArray:(NSArray*)array {
    for (id curObj in array) {
        [self addObject:curObj];
    }
}

/**
 @Status Interoperable
*/
- (void)setSet:(NSSet*)other {
    if (self == other) {
        return;
    }

    [self removeAllObjects];

    for (id curObj in other) {
        [self addObject:curObj];
    }
}

/**
 @Status Interoperable
*/
- (void)unionSet:(NSSet*)other {
    for (id curObj in other) {
        [self addObject:curObj];
    }
}

/**
 @Status Interoperable
*/
- (void)removeAllObjects {
    for (id object in self) {
        [self removeObject:object];
    }
}

/**
 @Status Interoperable
*/
- (void)minusSet:(NSSet*)other {
    for (id curObj in other) {
        [self removeObject:curObj];
    }
}

/**
 @Status Interoperable
*/
- (void)intersectSet:(NSSet*)other {
    id* removeObjects = NULL;
    int removeObjectsCount = 0, removeObjectsCapacity = 0;

    for (id curObj in self) {
        if ([other member:curObj] == nil) {
            if (removeObjectsCount >= removeObjectsCapacity) {
                removeObjectsCapacity += 128;
                removeObjects = (id*)IwRealloc(removeObjects, sizeof(id*) * removeObjectsCapacity);
            }
            removeObjects[removeObjectsCount++] = curObj;
        }
    }

    for (int i = 0; i < removeObjectsCount; i++) {
        [self removeObject:removeObjects[i]];
    }
    IwFree(removeObjects);
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCapacity:(unsigned)capacity {
    // Derived classes are required to implement this initializer.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (void)addObject:(id)object {
    // NSSet is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)removeObject:(id)object {
    // NSSet is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)filterUsingPredicate:(NSPredicate*)predicate {
    if (predicate == nil) {
        return;
    }

    NSArray* objects = [self allObjects];
    for (id obj in objects) {
        if (![predicate evaluateWithObject:obj]) {
            [self removeObject:obj];
        }
    }
}

@end
