//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <Foundation/NSMutableOrderedSet.h>
#import <NSOrderedSetInternal.h>
#import <StubReturn.h>

@implementation NSMutableOrderedSet
/**
 @Status Stub
 @Notes
*/
+ (instancetype)orderedSetWithCapacity:(NSUInteger)numItems {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCapacity:(NSUInteger)numItems {
    UNIMPLEMENTED();
    return StubReturn();
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
- (void)addObject:(id)object {
    [self insertObject:object atIndex:[self count]];
}

/**
 @Status Stub
 @Notes
*/
- (void)addObjects:(id _Nonnull const[])objects count:(NSUInteger)count {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addObjectsFromArray:(NSArray*)array {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)insertObject:(id)object atIndex:(NSUInteger)idx {
    THROW_NS_IF_FALSE(E_INVALIDARG, object != nil);

    if ([self containsObject:object]) {
        return;
    }

    [_arrayContainer insertObject:object atIndex:idx];
    [_setContainer addObject:object];
}

/**
 @Status Stub
 @Notes
*/
- (void)setObject:(id)object atIndexedSubscript:(NSUInteger)idx {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)insertObjects:(NSArray*)objects atIndexes:(NSIndexSet*)indexes {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeObject:(id)object {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeObjectAtIndex:(NSUInteger)idx {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeObjectsAtIndexes:(NSIndexSet*)indexes {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeObjectsInArray:(NSArray*)array {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeObjectsInRange:(NSRange)range {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeAllObjects {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)object {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)replaceObjectsAtIndexes:(NSIndexSet*)indexes withObjects:(NSArray*)objects {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)replaceObjectsInRange:(NSRange)range withObjects:(id _Nonnull const[])objects count:(NSUInteger)count {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setObject:(id)obj atIndex:(NSUInteger)idx {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)moveObjectsAtIndexes:(NSIndexSet*)indexes toIndex:(NSUInteger)idx {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2 {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)filterUsingPredicate:(NSPredicate*)predicate {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)sortUsingDescriptors:(NSArray*)sortDescriptors {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)sortUsingComparator:(NSComparator)cmptr {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)sortWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)sortRange:(NSRange)range options:(NSSortOptions)opts usingComparator:(NSComparator)cmptr {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)intersectOrderedSet:(NSOrderedSet*)other {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)intersectSet:(NSSet*)other {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)minusOrderedSet:(NSOrderedSet*)other {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)minusSet:(NSSet*)other {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)unionOrderedSet:(NSOrderedSet*)other {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)unionSet:(NSSet*)other {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    return [[NSOrderedSet alloc] initWithOrderedSet:self];
}

@end
