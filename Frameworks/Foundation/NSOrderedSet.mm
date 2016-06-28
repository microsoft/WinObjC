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

#import <Foundation/NSException.h>
#import <NSOrderedSetInternal.h>
#import <Starboard.h>
#import <StubReturn.h>
#import <VAListHelper.h>

// Needed to make sure that the returned array behaves like a one way proxy to an array
@implementation _NSProxyOrderedSetArray
- (instancetype)initWithOrderedSet:(NSOrderedSet*)orderedSet {
    if (self = [super init]) {
        _array = orderedSet->_arrayContainer;
    }

    return self;
}

- (NSUInteger)count {
    return [_array count];
}

- (id)objectAtIndex:(NSUInteger)index {
    return [_array objectAtIndex:index];
}
@end

@implementation NSOrderedSet

/**
 @Status Interoperable
*/
+ (instancetype)orderedSet {
    return [[self new] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithArray:(NSArray*)array {
    return [self orderedSetWithArray:array range:NSMakeRange(0, [array count]) copyItems:NO];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithArray:(NSArray*)array range:(NSRange)range copyItems:(BOOL)flag {
    return [[[self alloc] initWithArray:array range:range copyItems:flag] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithObject:(id)object {
    return [[[self alloc] initWithObject:object] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithObjects:(id)firstObj, ... {
    va_list argList;
    va_start(argList, firstObj);
    std::vector<id> flatArgs = ConvertVAListToVector((id)firstObj, argList);
    va_end(argList);

    if (flatArgs.size() == 0) {
        // return empty set if args are nil.
        return [[self new] autorelease];
    }

    return [[[self alloc] initWithObjects:flatArgs.data() count:flatArgs.size()] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithObjects:(id _Nonnull const[])objects count:(NSUInteger)count {
    return [[[self alloc] initWithObjects:objects count:count] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithOrderedSet:(NSOrderedSet*)set {
    return [self orderedSetWithOrderedSet:set range:NSMakeRange(0, [set count]) copyItems:NO];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithOrderedSet:(NSOrderedSet*)set range:(NSRange)range copyItems:(BOOL)flag {
    return [[[self alloc] initWithOrderedSet:set range:range copyItems:flag] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithSet:(NSSet*)set {
    return [[[self alloc] initWithSet:set] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)orderedSetWithSet:(NSSet*)set copyItems:(BOOL)flag {
    return [[[self alloc] initWithSet:set copyItems:flag] autorelease];
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
    if (array == nil) {
        return [self init];
    }

    THROW_NS_IF_FALSE(E_BOUNDS, NSMaxRange(range) <= [array count]);

    if (self = [self init]) {
        NSUInteger start = range.location;
        NSUInteger end = NSMaxRange(range);

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

    [_arrayContainer addObject:object];
    [_setContainer addObject:object];
}

/**
 @Status Interoperable
*/
- (NSUInteger)count {
    return [_arrayContainer count];
}

/**
 @Status Interoperable
*/
- (NSArray*)array {
    return [[[_NSProxyOrderedSetArray alloc] initWithOrderedSet:self] autorelease];
}

/**
 @Status Caveat
 @Notes returned set does not reflect future changes.
*/
- (NSSet*)set {
    return [[_setContainer copy] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithObject:(id)object {
    THROW_NS_IF_FALSE(E_INVALIDARG, object != nil);
    id ret[] = { object };
    return [self initWithObjects:ret count:1];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithObjects:(id)firstObj, ... {
    va_list argList;
    va_start(argList, firstObj);
    std::vector<id> flatArgs = ConvertVAListToVector((id)firstObj, argList);
    va_end(argList);
    return [self initWithObjects:flatArgs.data() count:flatArgs.size()];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithObjects:(id _Nonnull const[])objects count:(NSUInteger)count {
    if ((objects == NULL) && (count == 0)) {
        return [self init];
    }

    THROW_NS_IF_FALSE(E_INVALIDARG, objects != NULL);

    if (self = [self init]) {
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
    if (orderedSet == nil) {
        return [self init];
    }

    return [self initWithArray:orderedSet->_arrayContainer range:range copyItems:flag];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithSet:(NSSet*)set {
    return [self initWithSet:set copyItems:NO];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithSet:(NSSet*)set copyItems:(BOOL)flag {
    if (set == nil) {
        return [self init];
    }

    if (self = [super init]) {
        _setContainer.attach([[NSMutableSet alloc] initWithSet:set copyItems:flag]);
        _arrayContainer.attach([[NSMutableArray alloc] initWithArray:[set allObjects] copyItems:flag]);
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        _setContainer = [NSMutableSet new];
        _arrayContainer = [NSMutableArray new];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (BOOL)containsObject:(id)object {
    if (object == nil) {
        return NO;
    }
    return [_setContainer containsObject:object];
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
 @Status Interoperable
*/
- (void)enumerateObjectsUsingBlock:(void (^)(id, NSUInteger, BOOL*))block {
    return [_arrayContainer enumerateObjectsUsingBlock:block];
}

/**
 @Status Interoperable
*/
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(id, NSUInteger, BOOL*))block {
    return [_arrayContainer enumerateObjectsWithOptions:opts usingBlock:block];
}

/**
 @Status Interoperable
*/
- (id)objectAtIndex:(NSUInteger)index {
    return [_arrayContainer objectAtIndex:index];
}

/**
 @Status Interoperable
*/
- (id)firstObject {
    return [_arrayContainer firstObject];
}

/**
 @Status Interoperable
*/
- (id)lastObject {
    return [_arrayContainer lastObject];
}

/**
 @Status Interoperable
*/
- (id)objectAtIndexedSubscript:(NSUInteger)index {
    return [_arrayContainer objectAtIndexedSubscript:index];
}

/**
 @Status Interoperable
*/
- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes {
    return [_arrayContainer objectsAtIndexes:indexes];
}

/**
 @Status Interoperable
*/
- (NSUInteger)indexOfObject:(id)object {
    return [_arrayContainer indexOfObject:object];
}

/**
 @Status Interoperable
*/
- (NSUInteger)indexOfObject:(id)object
              inSortedRange:(NSRange)range
                    options:(NSBinarySearchingOptions)opts
            usingComparator:(NSComparator)cmp {
    return [_arrayContainer indexOfObject:object inSortedRange:range options:opts usingComparator:cmp];
}

/**
 @Status Interoperable
*/
- (NSUInteger)indexOfObjectAtIndexes:(NSIndexSet*)indexSet
                             options:(NSEnumerationOptions)opts
                         passingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate {
    return [_arrayContainer indexOfObjectAtIndexes:indexSet options:opts passingTest:predicate];
}

/**
 @Status Interoperable
*/
- (NSUInteger)indexOfObjectPassingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate {
    return [_arrayContainer indexOfObjectPassingTest:predicate];
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
 @Status Interoperable
*/
- (NSIndexSet*)indexesOfObjectsPassingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate {
    return [_arrayContainer indexesOfObjectsPassingTest:predicate];
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
 @Status Interoperable
*/
- (NSEnumerator*)objectEnumerator {
    return [_arrayContainer objectEnumerator];
}

/**
 @Status Interoperable
*/
- (NSEnumerator*)reverseObjectEnumerator {
    return [_arrayContainer reverseObjectEnumerator];
}

/**
 @Status Interoperable
*/
- (void)getObjects:(id _Nonnull[])objects range:(NSRange)range {
    [_arrayContainer getObjects:objects range:range];
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
 @Status Interoperable
*/
- (BOOL)isEqualToOrderedSet:(NSOrderedSet*)other {
    return [[other array] isEqualToArray:_arrayContainer];
}

/**
 @Status Interoperable
*/
- (BOOL)intersectsOrderedSet:(NSOrderedSet*)other {
    return [self intersectsSet:[other set]];
}

/**
 @Status Interoperable
*/
- (BOOL)intersectsSet:(NSSet*)set {
    return [_setContainer intersectsSet:set];
}

/**
 @Status Interoperable
*/
- (BOOL)isSubsetOfOrderedSet:(NSOrderedSet*)other {
    return [self isSubsetOfSet:[other set]];
}

/**
 @Status Interoperable
*/
- (BOOL)isSubsetOfSet:(NSSet*)set {
    return [_setContainer isSubsetOfSet:set];
}

/**
 @Status Interoperable
*/
- (NSArray*)sortedArrayUsingDescriptors:(NSArray*)sortDescriptors {
    return [_arrayContainer sortedArrayUsingDescriptors:sortDescriptors];
}

/**
 @Status Interoperable
*/
- (NSArray*)sortedArrayUsingComparator:(NSComparator)cmptr {
    return [_arrayContainer sortedArrayUsingComparator:cmptr];
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
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id _Nonnull[])stackbuf count:(NSUInteger)len {
    return [_arrayContainer countByEnumeratingWithState:state objects:stackbuf count:len];
}

/**
 @Status Interoperable
*/
- (id)mutableCopyWithZone:(NSZone*)zone {
    return [[NSMutableOrderedSet alloc] initWithOrderedSet:self];
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