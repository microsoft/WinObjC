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

#include "CoreFoundation/CFArray.h"

#include "Foundation/NSMutableArray.h"
#include "Foundation/NSMutableData.h"
#include "Foundation/NSEnumerator.h"
#include "Foundation/NSKeyedArchiver.h"
#include "Foundation/NSMutableString.h"
#include "Foundation/NSIndexSet.h"
#include "Foundation/NSRange.h"
#include "NSIndexSetInternal.h"
#include "Etc.h"

@implementation NSIndexSet

/**
 @Status Interoperable
*/
+ (id)indexSetWithIndexesInRange:(NSRange)range {
    id ret = [NSMutableIndexSet new];
    [ret addIndexesInRange:range];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (id)indexSet {
    id ret = [NSIndexSet new];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (id)indexSetWithIndex:(NSUInteger)index {
    NSRange range;
    range.location = index;
    range.length = 1;

    id ret = [NSMutableIndexSet new];
    [ret addIndexesInRange:range];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (id)init {
    return self;
}

/**
 @Status Interoperable
*/
- (id)initWithIndex:(unsigned)index {
    NSRange range;

    range.location = index;
    range.length = 0;

    raAddItem(self, range);
    return self;
}

/**
 @Status Interoperable
*/
- (id)initWithIndexSet:(NSIndexSet*)other {
    for (unsigned i = 0; i < other->_length; i++) {
        raAddItem(self, other->_ranges[i]);
    }

    return self;
}

/**
 @Status Interoperable
*/
- (unsigned)count {
    unsigned ret = 0;

    for (unsigned i = 0; i < _length; i++) {
        ret += _ranges[i].length;
    }
    return ret;
}

- (void)dealloc {
    if (_ranges) {
        IwFree(_ranges);
    }
    [super dealloc];
}

/**
 @Status Stub
*/
- (unsigned)indexGreaterThanIndex:(unsigned)anIndex {
    UNIMPLEMENTED();
    return -1;
}

/**
 @Status Interoperable
*/
- (unsigned)countOfIndexesInRange:(NSRange)range {
    unsigned ret = 0;

    for (unsigned i = 0; i < raCount(self); i++) {
        NSRange cur = raItemAtIndex(self, i);

        if (cur.location > range.location + range.length) {
            break;
        }
        if (cur.location + cur.length < range.location) {
            continue;
        }

        int low = MAX(cur.location, range.location);
        int high = MIN(cur.location + cur.length, range.location + range.length);

        ret += high - low;
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (void)enumerateIndexesUsingBlock:(void (^)(NSUInteger idx, BOOL* stop))block {
    BOOL stop = FALSE;
    for (unsigned int i = 0; i < raCount(self) && !stop; i++) {
        NSRange cur = raItemAtIndex(self, i);

        for (unsigned int j = cur.location; j < cur.location + cur.length && !stop; j++) {
            block(j, &stop);
        }
    }
}

/**
 @Status Interoperable
*/
- (BOOL)intersectsIndexesInRange:(NSRange)range {
    unsigned first = positionOfRangeGreaterThanOrEqualToLocation(_ranges, _length, range.location);

    if (first == NSNotFound) {
        return NO;
    }

    return (_ranges[first].location < NSMaxRange(range)) ? YES : NO;
}

- (id)mutableCopyWithZone:(NSZone*)zone {
    return [[NSMutableIndexSet allocWithZone:zone] initWithIndexSet:self];
}

- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Stub
*/
- (BOOL)containsIndex:(unsigned)anIndex {
    UNIMPLEMENTED();
    return YES;
}

/**
 @Status Interoperable
*/
- (unsigned)firstIndex {
    if (raCount(self) == 0) {
        return NSNotFound;
    }
    unsigned ret = raItemAtIndex(self, 0).location;

    return ret;
}

/**
 @Status Interoperable
*/
- (unsigned)lastIndex {
    if (raCount(self) == 0) {
        return NSNotFound;
    }
    unsigned ret = NSMaxRange(raItemAtIndex(self, raCount(self) - 1)) - 1;

    return ret;
}

/**
 @Status Interoperable
*/
- (BOOL)isEqualToIndexSet:(NSIndexSet*)otherSet {
    if (![otherSet isKindOfClass:[NSIndexSet class]]) {
        return FALSE;
    }

    NSUInteger count = otherSet ? raCount(otherSet) : 0;

    if (count != raCount(self)) {
        return NO;
    }
    if (count > 0) {
        NSUInteger i;

        for (i = 0; i < count; i++) {
            NSRange rself = raItemAtIndex(self, i);
            NSRange rother = raItemAtIndex(otherSet, i);

            if (rself.location != rother.location || rself.length != rother.length) {
                return NO;
            }
        }
    }
    return YES;
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithIndexesInRange:(NSRange)indexRange {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)containsIndexes:(NSIndexSet*)indexSet {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)containsIndexesInRange:(NSRange)indexRange {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)indexPassingTest:(BOOL (^)(NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSIndexSet*)indexesPassingTest:(BOOL (^)(NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)indexWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSIndexSet*)indexesWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)indexInRange:(NSRange)range options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSIndexSet*)indexesInRange:(NSRange)range options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateRangesInRange:(NSRange)range options:(NSEnumerationOptions)opts usingBlock:(void (^)(NSRange, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateRangesUsingBlock:(void (^)(NSRange, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateRangesWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(NSRange, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)indexLessThanIndex:(NSUInteger)index {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)indexLessThanOrEqualToIndex:(NSUInteger)index {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)indexGreaterThanOrEqualToIndex:(NSUInteger)index {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)getIndexes:(NSUInteger*)indexBuffer maxCount:(NSUInteger)bufferSize inIndexRange:(NSRangePointer)indexRange {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateIndexesWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(NSUInteger, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateIndexesInRange:(NSRange)range options:(NSEnumerationOptions)opts usingBlock:(void (^)(NSUInteger, BOOL*))block {
    UNIMPLEMENTED();
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

static bool rangesIntersect(const NSRange& lhs, const NSRange& rhs) {
    if (lhs.location < rhs.location) {
        return lhs.location + lhs.length >= rhs.location;
    }
    return rhs.location + rhs.length >= lhs.location;
}
