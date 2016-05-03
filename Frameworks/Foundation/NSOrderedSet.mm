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
#import <StubReturn.h>
#include <vector>

#import <Foundation/NSOrderedSet.h>
#import <Foundation/NSException.h>

@implementation NSOrderedSet {
    std::vector<StrongId<id>> setContainer;
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSet {
    return [[[NSOrderedSet alloc] init] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithArray:(NSArray*)array {
    return [NSOrderedSet orderedSetWithArray:array range:NSMakeRange(0, [array count]) copyItems:NO];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithArray:(NSArray*)array range:(NSRange)range copyItems:(BOOL)flag {
    return [[[NSOrderedSet alloc] initWithArray:array range:range copyItems:flag] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithObject:(id)object {
    return [[[NSOrderedSet alloc] initWithObject:object] autorelease];
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)orderedSetWithObjects:(id)firstObj {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithObjects:(id _Nonnull const[])objects count:(NSUInteger)count {
    return [[[NSOrderedSet alloc] initWithObjects:objects count:count] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithOrderedSet:(NSOrderedSet*)set {
    return [NSOrderedSet orderedSetWithOrderedSet:set range:NSMakeRange(0, [set count]) copyItems:NO];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithOrderedSet:(NSOrderedSet*)set range:(NSRange)range copyItems:(BOOL)flag {
    return [[[NSOrderedSet alloc] initWithOrderedSet:set range:range copyItems:flag] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithSet:(NSSet*)set {
    return [[[NSOrderedSet alloc] initWithSet:set] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithSet:(NSSet*)set copyItems:(BOOL)flag {
    return [[[NSOrderedSet alloc] initWithSet:set copyItems:flag] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithArray:(NSArray*)array {
    return [self initWithArray:array range:NSMakeRange(0, [array count]) copyItems:NO];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithArray:(NSArray*)array copyItems:(BOOL)flag {
    return [self initWithArray:array range:NSMakeRange(0, [array count]) copyItems:flag];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithArray:(NSArray*)array range:(NSRange)range copyItems:(BOOL)flag {
    if (range.length > [array count]) {
        [NSException raise:NSInvalidArgumentException format:@"The given range length is higher than the array length: %d.", [array count]];
    }

    if (self = [self init]) {
        NSUInteger start = range.location;
        NSUInteger end = range.length + range.location;

        if (flag) {
            for (NSUInteger i = start; i < end; i++) {
                id obj = [[array objectAtIndex:i] copy];
                [self _insertObject:obj];
                [obj release];
            }
        } else {
            for (NSUInteger i = start; i < end; i++) {
                [self _insertObject:[array objectAtIndex:i]];
            }
        }
    }
    return self;
}

- (void)_insertObject:(id)object {
    if ([self containsObject:object]) {
        return;
    }

    setContainer.push_back(object);
}

- (NSUInteger)count {
    return setContainer.size();
}

// - (NSArray*) array {
//     NSMutableArray* array = [[NSMutableArray alloc] autorelease];
//     auto object = setContainer.data();
//     NSUInteger length = setContainer.size();

//     for(NSUInteger i = 0; i < length; i++){
//         [array addObject:object];
//         object++;
//     }

//     return [[array copy] autorelease];
// }

/**
 @Status Interoperable
*/
- (instancetype)initWithObject:(id)object {
    id ret[] = { object };
    return [self initWithObjects:ret count:1];
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithObjects:(id)firstObj {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithObjects:(id _Nonnull const[])objects count:(NSUInteger)count {
    if (self = [super init]) {
        for (NSUInteger i = 0; i < count; ++i) {
            [self _insertObject:objects[i]];
        }
    }
    return self;
}
/**
 @Status Interoperable
*/
- (instancetype)initWithOrderedSet:(NSOrderedSet*)set {
    return [self initWithOrderedSet:set range:NSMakeRange(0, [set count]) copyItems:NO];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithOrderedSet:(NSOrderedSet*)set copyItems:(BOOL)flag {
    return [self initWithOrderedSet:set range:NSMakeRange(0, [set count]) copyItems:flag];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithOrderedSet:(NSOrderedSet*)orderedSet range:(NSRange)range copyItems:(BOOL)flag {
    auto values = orderedSet->setContainer;

    NSMutableArray* arrayObjs = [NSMutableArray array];

    for (id item : values) {
        [arrayObjs addObject:item];
    }

    return [self initWithArray:arrayObjs range:range copyItems:flag];
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithSet:(NSSet*)set {
    return [self initWithSet:set copyItems:NO];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithSet:(NSSet*)set copyItems:(BOOL)flag {
    NSMutableArray* arrayObjs = [NSMutableArray array];

    for (id item : set) {
        [arrayObjs addObject:item];
    }
    return [self initWithArray:arrayObjs range:NSMakeRange(0, [arrayObjs count]) copyItems:flag];
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    return [super init];
}

/**
 @Status Interoperable
*/
- (BOOL)containsObject:(id)object {
    return std::find(setContainer.begin(), setContainer.end(), object) != setContainer.end();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateObjectsAtIndexes:(NSIndexSet*)indexSet
                          options:(NSEnumerationOptions)opts
                       usingBlock:(void (^)(id, NSUInteger, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateObjectsUsingBlock:(void (^)(id, NSUInteger, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(id, NSUInteger, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (id)objectAtIndex:(NSUInteger)index {
    if (index >= [self count]) {
        [NSException raise:NSRangeException format:@"index is greater than the OrsdereSet size %d", [self count]];
    }
    return *std::next(setContainer.begin(), index);
}

/**
 @Status Interoperable
*/
- (id)firstObject {
    return [self objectAtIndex:0];
}

/**
 @Status Interoperable
*/
- (id)lastObject {
    return [self objectAtIndex:([self count] - 1)];
}

/**
 @Status Interoperable
*/
- (id)objectAtIndexedSubscript:(NSUInteger)index {
    return [self objectAtIndex:index];
}

/**
 @Status Interoperable
*/
- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes {
    if (indexes == nil) {
        [NSException raise:NSInvalidArgumentException format:@"indexs should not be nil."];
    }

    NSMutableArray* ret = [NSMutableArray array];
    [indexes enumerateIndexesUsingBlock:^(NSUInteger idx, BOOL* stop) {
        [ret addObject:[self objectAtIndex:idx]];
    }];

    return [ret copy];
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)indexOfObject:(id)object {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)indexOfObject:(id)object
              inSortedRange:(NSRange)range
                    options:(NSBinarySearchingOptions)opts
            usingComparator:(NSComparator)cmp {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)indexOfObjectAtIndexes:(NSIndexSet*)indexSet
                             options:(NSEnumerationOptions)opts
                         passingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)indexOfObjectPassingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)indexOfObjectWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSIndexSet*)indexesOfObjectsAtIndexes:(NSIndexSet*)indexSet
                                 options:(NSEnumerationOptions)opts
                             passingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSIndexSet*)indexesOfObjectsPassingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSIndexSet*)indexesOfObjectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSEnumerator*)objectEnumerator {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSEnumerator*)reverseObjectEnumerator {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)getObjects:(id _Nonnull[])objects range:(NSRange)range {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setValue:(id)value forKey:(NSString*)key {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id)valueForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addObserver:(NSObject*)observer forKeyPath:(NSString*)keyPath options:(NSKeyValueObservingOptions)options context:(void*)context {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeObserver:(NSObject*)observer forKeyPath:(NSString*)keyPath {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeObserver:(NSObject*)observer forKeyPath:(NSString*)keyPath context:(void*)context {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isEqualToOrderedSet:(NSOrderedSet*)other {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)intersectsOrderedSet:(NSOrderedSet*)other {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)intersectsSet:(NSSet*)set {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isSubsetOfOrderedSet:(NSOrderedSet*)other {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isSubsetOfSet:(NSSet*)set {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)sortedArrayUsingDescriptors:(NSArray*)sortDescriptors {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)sortedArrayUsingComparator:(NSComparator)cmptr {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)sortedArrayWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSOrderedSet*)filteredOrderedSetUsingPredicate:(NSPredicate*)predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)descriptionWithLocale:(id)locale {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)descriptionWithLocale:(id)locale indent:(NSUInteger)level {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id _Nonnull[])stackbuf count:(NSUInteger)len {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)mutableCopyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    UNIMPLEMENTED();
}

@end