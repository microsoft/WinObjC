//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#include <algorithm>

@implementation NSIndexSet

static NSString* c_archiveKey = @"_NS.IS";

/**
 @Status Interoperable
*/
+ (instancetype)indexSet {
    return [[NSIndexSet new] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)indexSetWithIndex:(NSUInteger)index {
    return [[[self alloc] initWithIndex:index] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)indexSetWithIndexesInRange:(NSRange)range {
    return [[[self alloc] initWithIndexesInRange:range] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithIndex:(NSUInteger)index {
    return [self initWithIndexesInRange:{ index, 1 }];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithIndexesInRange:(NSRange)indexRange {
    if (self = [super init]) {
        [static_cast<NSMutableIndexSet*>(self) _addItem:indexRange];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithIndexSet:(NSIndexSet*)other {
    if (self = [super init]) {
        unsigned numRanges = [static_cast<NSMutableIndexSet*>(other) _count];
        for (unsigned i = 0; i < numRanges; i++) {
            [static_cast<NSMutableIndexSet*>(self) _addItem:[static_cast<NSMutableIndexSet*>(other) _itemAtIndex:i]];
        }
    }

    return self;
}

/**
 @Status Interoperable
*/
- (BOOL)containsIndex:(NSUInteger)anIndex {
    unsigned rangePos = [static_cast<NSMutableIndexSet*>(self) _positionOfRangeGreaterThanOrEqualToLocation:anIndex];

    if (rangePos == NSNotFound) {
        return NO;
    }

    return [static_cast<NSMutableIndexSet*>(self) _itemAtIndex:rangePos].location <= anIndex;
}

/**
 @Status Interoperable
*/
- (BOOL)containsIndexes:(NSIndexSet*)other {
    unsigned selfIndex = 0;
    unsigned selfSize = [static_cast<NSMutableIndexSet*>(self) _count];
    unsigned otherIndex = 0;
    unsigned otherSize = [static_cast<NSMutableIndexSet*>(other) _count];

    while (selfIndex < selfSize && otherIndex < otherSize) {
        NSRange currSelf = [static_cast<NSMutableIndexSet*>(self) _itemAtIndex:selfIndex];
        NSRange currOther = [static_cast<NSMutableIndexSet*>(other) _itemAtIndex:otherIndex];
        if (NSEqualRanges(currOther, NSIntersectionRange(currSelf, currOther))) {
            // current range from other a subset of current range from self
            otherIndex++;
        } else {
            selfIndex++;
        }
    }

    if (otherIndex == otherSize) {
        return YES;
    }

    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)containsIndexesInRange:(NSRange)indexRange {
    unsigned selfIndex = 0;
    unsigned selfSize = [static_cast<NSMutableIndexSet*>(self) _count];

    while (selfIndex < selfSize) {
        NSRange currSelf = [static_cast<NSMutableIndexSet*>(self) _itemAtIndex:selfIndex];
        if (NSEqualRanges(indexRange, NSIntersectionRange(currSelf, indexRange))) {
            // indexRange a subset of current range from self
            return YES;
        }

        selfIndex++;
    }

    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)intersectsIndexesInRange:(NSRange)range {
    unsigned first = [static_cast<NSMutableIndexSet*>(self) _positionOfRangeGreaterThanOrEqualToLocation:range.location];

    if (first == NSNotFound) {
        return NO;
    }

    return ([static_cast<NSMutableIndexSet*>(self) _itemAtIndex:first].location < NSMaxRange(range)) ? YES : NO;
}

/**
 @Status Interoperable
*/
- (NSUInteger)count {
    unsigned ret = 0;
    unsigned numRanges = [static_cast<NSMutableIndexSet*>(self) _count];

    for (unsigned i = 0; i < numRanges; i++) {
        ret += [static_cast<NSMutableIndexSet*>(self) _itemAtIndex:i].length;
    }
    return ret;
}

/**
 @Status Interoperable
*/
+ (NSObject*)allocWithZone:(NSZone*)zone {
    // Note: NSIndexSet is not intended to be subclassable
    return NSAllocateObject((Class)[NSMutableIndexSet class], 0, zone);
}

/**
 @Status Interoperable
*/
- (NSUInteger)countOfIndexesInRange:(NSRange)range {
    unsigned ret = 0;

    for (unsigned i = 0; i < [static_cast<NSMutableIndexSet*>(self) _count]; i++) {
        NSRange cur = [static_cast<NSMutableIndexSet*>(self) _itemAtIndex:i];

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
 @Status Caveat
 @Notes NSEnumerationReverse not implemented.
*/
- (void)enumerateIndexesWithOptions:(NSEnumerationOptions)options usingBlock:(void (^)(NSUInteger, BOOL*))block {
    dispatch_queue_t queue;
    dispatch_group_t group;

    // Initialize dispatch queue for concurrent enumeration
    if (options & NSEnumerationConcurrent) {
        queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
        group = dispatch_group_create();
    }

    __block BOOL stop = NO;
    BOOL reverse = options & NSEnumerationReverse;
    unsigned long count = [static_cast<NSMutableIndexSet*>(self) _count];
    unsigned long start = (reverse) ? count : 1;
    unsigned long end = (reverse) ? 0 : count + 1;
    long step = (reverse) ? -1 : 1;
    for (unsigned long i = start; i != end && !stop; i += step) {
        NSRange cur = [static_cast<NSMutableIndexSet*>(self) _itemAtIndex:(i - 1)];
        __block unsigned long j;
        unsigned long innerStart = (reverse) ? NSMaxRange(cur) - 1 : cur.location;
        for (j = innerStart; NSLocationInRange(j, cur) && !stop; j += step) {
            if (options & NSEnumerationConcurrent) {
                dispatch_group_async(group,
                                     queue,
                                     ^() {
                                         block(j, &stop);
                                     });
            } else {
                block(j, &stop);
            }
        }
    }

    // Wait for dispatch queue to execute
    if (options & NSEnumerationConcurrent) {
        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
        dispatch_release(group);
    }
}

/**
 @Status Interoperable
*/
- (void)enumerateIndexesUsingBlock:(void (^)(NSUInteger idx, BOOL* stop))block {
    [self enumerateIndexesWithOptions:0 usingBlock:block];
}

/**
 @Status Interoperable
*/
- (instancetype)mutableCopyWithZone:(NSZone*)zone {
    return [[NSMutableIndexSet allocWithZone:zone] initWithIndexSet:self];
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    // requires a deep copy because our implementation is mutable
    return [self mutableCopyWithZone:zone];
}

/**
 @Status Interoperable
*/
- (NSUInteger)firstIndex {
    if ([static_cast<NSMutableIndexSet*>(self) _count] == 0) {
        return NSNotFound;
    }
    unsigned ret = [static_cast<NSMutableIndexSet*>(self) _itemAtIndex:0].location;

    return ret;
}

/**
 @Status Interoperable
*/
- (NSUInteger)lastIndex {
    if ([static_cast<NSMutableIndexSet*>(self) _count] == 0) {
        return NSNotFound;
    }

    unsigned ret =
        NSMaxRange([static_cast<NSMutableIndexSet*>(self) _itemAtIndex:([static_cast<NSMutableIndexSet*>(self) _count] - 1)]) - 1;

    return ret;
}

/**
 @Status Caveat
 @Notes Has known issues - does not detect equality in cases where the sets are logically equal but the ranges differ (VSO 6979799)
*/
- (BOOL)isEqual:(id)other {
    if (self == other) {
        return YES;
    }

    if (![other isKindOfClass:[NSIndexSet class]]) {
        return NO;
    }

    return [self isEqualToIndexSet:static_cast<NSIndexSet*>(other)];
}

/**
 @Status Caveat
 @Notes Has known issues - does not detect equality in cases where the sets are logically equal but the ranges differ (VSO 6979799)
*/
- (BOOL)isEqualToIndexSet:(NSIndexSet*)otherSet {
    // NSIndexSet isEqualToIndexSet relies on invariants that aren't kept by the implementation

    if (self == otherSet) {
        return YES;
    }

    if (![otherSet isKindOfClass:[NSIndexSet class]]) {
        return NO;
    }

    NSUInteger count = otherSet ? [static_cast<NSMutableIndexSet*>(otherSet) _count] : 0;

    if (count != [static_cast<NSMutableIndexSet*>(self) _count]) {
        return NO;
    }
    if (count > 0) {
        NSUInteger i;

        for (i = 0; i < count; i++) {
            NSRange rself = [static_cast<NSMutableIndexSet*>(self) _itemAtIndex:i];
            NSRange rother = [static_cast<NSMutableIndexSet*>(otherSet) _itemAtIndex:i];

            if (rself.location != rother.location || rself.length != rother.length) {
                return NO;
            }
        }
    }
    return YES;
}

/**
 @Status Stub
*/
- (NSUInteger)indexPassingTest:(BOOL (^)(NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (NSIndexSet*)indexesPassingTest:(BOOL (^)(NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (NSUInteger)indexWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (NSIndexSet*)indexesWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (NSUInteger)indexInRange:(NSRange)range options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (NSIndexSet*)indexesInRange:(NSRange)range options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)enumerateRangesInRange:(NSRange)range options:(NSEnumerationOptions)opts usingBlock:(void (^)(NSRange, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)enumerateRangesUsingBlock:(void (^)(NSRange, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)enumerateRangesWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(NSRange, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (NSUInteger)indexLessThanIndex:(NSUInteger)index {
    unsigned rangePos = [static_cast<NSMutableIndexSet*>(self) _positionOfRangeLessThanOrEqualToLocation:index];
    if (rangePos != NSNotFound) {
        NSRange range = [static_cast<NSMutableIndexSet*>(self) _itemAtIndex:rangePos];
        if (range.location < index) {
            // Closest index is in this range
            return std::min(range.location + range.length - 1, index - 1);
        } else if (rangePos > 0) {
            // Closest index less than input is in one earlier range
            range = [static_cast<NSMutableIndexSet*>(self) _itemAtIndex:rangePos - 1];
            return range.location + range.length;
        }
    }

    return NSNotFound;
}

/**
 @Status Interoperable
*/
- (NSUInteger)indexLessThanOrEqualToIndex:(NSUInteger)index {
    unsigned rangePos = [static_cast<NSMutableIndexSet*>(self) _positionOfRangeLessThanOrEqualToLocation:index];
    if (rangePos != NSNotFound) {
        NSRange range = [static_cast<NSMutableIndexSet*>(self) _itemAtIndex:rangePos];
        return std::min(range.location + range.length - 1, index);
    }

    return NSNotFound;
}

/**
 @Status Interoperable
*/
- (NSUInteger)indexGreaterThanIndex:(NSUInteger)index {
    unsigned rangePos = [static_cast<NSMutableIndexSet*>(self) _positionOfRangeGreaterThanOrEqualToLocation:index];
    if (rangePos != NSNotFound) {
        NSRange range = [static_cast<NSMutableIndexSet*>(self) _itemAtIndex:rangePos];
        if (range.location + range.length - 1 > index) {
            return std::max(range.location, index + 1);
        } else if (rangePos < [static_cast<NSMutableIndexSet*>(self) _count] - 1) {
            range = [static_cast<NSMutableIndexSet*>(self) _itemAtIndex:rangePos + 1];
            return range.location;
        }
    }

    return NSNotFound;
}

/**
 @Status Interoperable
*/
- (NSUInteger)indexGreaterThanOrEqualToIndex:(NSUInteger)index {
    unsigned rangePos = [static_cast<NSMutableIndexSet*>(self) _positionOfRangeGreaterThanOrEqualToLocation:index];
    if (rangePos != NSNotFound) {
        NSRange range = [static_cast<NSMutableIndexSet*>(self) _itemAtIndex:rangePos];
        return std::max(range.location, index);
    }

    return NSNotFound;
}

/**
 @Status Stub
*/
- (NSUInteger)getIndexes:(NSUInteger*)indexBuffer maxCount:(NSUInteger)bufferSize inIndexRange:(NSRangePointer)indexRange {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)enumerateIndexesInRange:(NSRange)range options:(NSEnumerationOptions)opts usingBlock:(void (^)(NSUInteger, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Interoperable
*/
- (id)initWithCoder:(NSCoder*)decoder {
    if (self = [super init]) {
        NSUInteger length = 0;
        const NSRange* ranges = [decoder isKindOfClass:[NSKeyedUnarchiver class]] ?
                                    reinterpret_cast<const NSRange*>([decoder decodeBytesForKey:c_archiveKey returnedLength:&length]) :
                                    reinterpret_cast<const NSRange*>([decoder decodeBytesWithReturnedLength:&length]);

        if (ranges && length > 0) {
            for (size_t i = 0; i < length / sizeof(NSRange); ++i) {
                [static_cast<NSMutableIndexSet*>(self) _addItem:ranges[i]];
            }
        }
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    unsigned int count = [static_cast<NSMutableIndexSet*>(self) _count];
    if (count > 0) {
        NSRangePointer ranges = [static_cast<NSMutableIndexSet*>(self) _allRanges];
        if ([coder isKindOfClass:[NSKeyedArchiver class]]) {
            [coder encodeBytes:reinterpret_cast<uint8_t*>(ranges) length:count * sizeof(NSRange) forKey:c_archiveKey];
        } else {
            [coder encodeBytes:ranges length:count * sizeof(NSRange)];
        }
    }
}

@end

static bool rangesIntersect(const NSRange& lhs, const NSRange& rhs) {
    if (lhs.location < rhs.location) {
        return lhs.location + lhs.length >= rhs.location;
    }
    return rhs.location + rhs.length >= lhs.location;
}
