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

@implementation NSMutableIndexSet {
    std::vector<NSRange> _ranges;
}

/**
 @Status Interoperable
*/
- (void)addIndexesInRange:(NSRange)candidateRange {
    // A range is added to the index by finding its appropriate sorted position such
    // that no overlaps exist. This may mean that multiple ranges are subsumed by the addition of this range.
    // Additionally, a candidate range may be a total subset of an existing range which should result in a no-op.
    // A range is ordered in the _ranges array according to its left edge (range.location). The length of each range is
    // at most the distance to the next left edge as any range would be coalesced with a longer distance.
    // In order to coalesce two or more ranges, the current list of ranges will be scanned for any overlaps. When an overlap is
    // detected the candidate range will be updated to include the new maximal bounds and the current entry marked for removal.
    // Once all overlaps are accounted for, old items will be removed, and the candidate range will be inserted into the least vacated
    // index (all removed indices should be contiguous and by definition everything non overlapping was not removed.)

    NSRange removalRange = { 0, 0 }; // The set of ranges to remove during cleanup. Start with removing at index 0 with a length of 0.
    for (unsigned int i = 0; i < [self _count]; i++) {
        NSRange cur = [self _itemAtIndex:i];

        // There are six ways two ranges can be arranged relative to each other.
        //                   |================|
        // 1. |=====|                                          (left of)
        // 2.             |====|                               (left overlap)
        // 3.                     |====|                       (subset)
        // 4.                             |========|           (right overlap)
        // 5.                                     |=========|  (right of)
        // 6.         |==============================|         (super set)

        if (cur.location > NSMaxRange(candidateRange)) {
            // current range's left side is beyond that of the candidate range's right side.
            // This is means that the candidate range is (left of) the current range. All overlaps
            // are done and its time to clean up.
            break;
        } else if (NSMaxRange(cur) < candidateRange.location) {
            // The candidate range's left edge is beyond the current range's right edge.
            // this means that the candidate range is (right of) the current range. No overlap.
            // move along.
            removalRange.location++;
        } else {
            // the 4 other cases all involve some overlap (or adjacency). This means that the candidate range needs
            // to expand to include the maximal range and the current range removed.
            removalRange.length++;
            candidateRange = NSUnionRange(candidateRange, cur);
        }
    }

    // Cleanup step is to first remove everything we need and then to insert at the min removed index.
    // Since all ranges to be removed are contiguous, simply shift the ranges beyond the removed chunk
    // down into vacated spots.
    if (removalRange.length > 0) {
        [self _removeRanges:removalRange];
    }

    // Now insert the candidate range
    [self _insertItem:candidateRange AtIndex:removalRange.location];
}

/**
 @Status Interoperable
*/
- (void)removeIndexesInRange:(NSRange)range {
    unsigned pos = [self _positionOfRangeLessThanOrEqualToLocation:range.location];

    if (pos == NSNotFound) {
        pos = 0;
    }

    while (range.length > 0 && pos < [self _count]) {
        NSRange& rangeAtPos = [self _itemReferenceAtIndex:pos];
        unsigned max = NSMaxRange(rangeAtPos);
        if (rangeAtPos.location >= NSMaxRange(range)) {
            break;
        }

        if (max == NSMaxRange(range)) {
            if (rangeAtPos.location == range.location) {
                [self _removeItemAtIndex:pos];
            } else {
                rangeAtPos.length = range.location - rangeAtPos.location;
            }
            break;
        }

        if (max > NSMaxRange(range)) {
            if (rangeAtPos.location == range.location) {
                rangeAtPos.location = NSMaxRange(range);
                rangeAtPos.length = max - rangeAtPos.location;
            } else {
                NSRange iceberg;

                iceberg.location = NSMaxRange(range);
                iceberg.length = max - iceberg.location;

                rangeAtPos.length = range.location - rangeAtPos.location;

                [self _insertItem:iceberg AtIndex:pos + 1];
            }
            break;
        }

        if (range.location >= max) {
            pos++;
        } else {
            unsigned max = NSMaxRange(range);
            NSRange temp = rangeAtPos;

            if (rangeAtPos.location >= range.location) {
                [self _removeItemAtIndex:pos];
            } else {
                rangeAtPos.length = range.location - rangeAtPos.location;
                pos++;
            }
            range.location = NSMaxRange(temp);
            range.length = max - range.location;
        }
    }
}

/**
 @Status Interoperable
*/
- (void)addIndex:(NSUInteger)index {
    NSRange r;

    r.location = index;
    r.length = 1;

    [self addIndexesInRange:r];
}

/**
 @Status Interoperable
*/
- (void)addIndexes:(NSIndexSet*)other {
    for (unsigned i = 0; i < [static_cast<NSMutableIndexSet*>(other) _count]; ++i) {
        [self addIndexesInRange:[static_cast<NSMutableIndexSet*>(other) _itemAtIndex:i]];
    }
}

/**
 @Status Interoperable
*/
- (void)removeIndex:(NSUInteger)index {
    NSRange r;

    r.location = index;
    r.length = 1;

    [self removeIndexesInRange:r];
}

/**
 @Status Interoperable
*/
- (void)removeIndexes:(NSIndexSet*)other {
    for (unsigned i = 0; i < [static_cast<NSMutableIndexSet*>(other) _count]; i++) {
        [self removeIndexesInRange:[static_cast<NSMutableIndexSet*>(other) _itemAtIndex:i]];
    }
}

/**
 @Status Interoperable
*/
- (void)shiftIndexesStartingAtIndex:(NSUInteger)index by:(NSInteger)delta {
    if (delta < 0) {
        delta = -delta;
        NSUInteger pos = [self _positionOfRangeLessThanOrEqualToLocation:index - delta];

        if (pos == NSNotFound) {
            return;
        }

        NSUInteger count = [self _count];

        while (count > 0 && count > pos) {
            count--;
            NSRange& rangeAtCount = [self _itemReferenceAtIndex:count];

            if (rangeAtCount.location >= index) { // if above index just move it down
                rangeAtCount.location -= (unsigned)delta;
            } else if (NSMaxRange(rangeAtCount) <= index - (unsigned)delta) { // below area, ignore
                ;
            } else if (rangeAtCount.location <= index - (unsigned)delta) { // if below, shorten
                if (NSMaxRange(rangeAtCount) >= (unsigned)delta + index) { // if deletion entirely inside
                    rangeAtCount.length -= delta;
                } else {
                    rangeAtCount.length = NSMaxRange(rangeAtCount) - (index - delta);
                }
            } else { // if below and shorter than the delta, remove
                [self _removeItemAtIndex:count];
            }
        }

        // Remove overlap if necessary
        pos++;
        if (pos < [self _count]) {
            NSRange& rangeAtPos = [self _itemReferenceAtIndex:pos];
            NSRange rangeBelowPos = [self _itemAtIndex:(pos - 1)];
            if (NSMaxRange(rangeBelowPos) >= rangeAtPos.location) {
                NSRange unionRange = NSUnionRange(rangeAtPos, rangeBelowPos);
                rangeAtPos.location = unionRange.location;
                rangeAtPos.length = unionRange.length;
                [self _removeItemAtIndex:(pos - 1)];
            }
        }

    } else {
        NSInteger pos = [self _positionOfRangeLessThanOrEqualToLocation:index];

        if (pos == NSNotFound) {
            return; // raise?
        }

        NSRange& rangeAtPos = [self _itemReferenceAtIndex:pos];
        // if index is inside a range, split it
        if (rangeAtPos.location < index && index < NSMaxRange(rangeAtPos)) {
            NSRange below = rangeAtPos;

            below.length = index - below.location;
            rangeAtPos.length = NSMaxRange(rangeAtPos) - index;
            rangeAtPos.location = index;

            [self _insertItem:below AtIndex:pos];
        }

        // move all ranges at or above index by delta
        NSInteger count = [self _count];

        while (--count >= pos) {
            NSRange& rangeAtCount = [self _itemReferenceAtIndex:count];
            if (rangeAtCount.location >= index) {
                rangeAtCount.location += delta;
            }
        }
    }
}

/**
 @Status Interoperable
*/
- (void)removeAllIndexes {
    [self _removeRanges:{ 0, [self _count] }];
}

/**
 @Status Interoperable
*/
+ (instancetype)indexSet {
    return [[self new] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    return [[NSMutableIndexSet allocWithZone:zone] initWithIndexSet:self];
}

- (unsigned)_positionOfRangeGreaterThanOrEqualToLocation:(NSUInteger)location {
    unsigned length = self->_ranges.size();
    for (unsigned i = 0; i < length; i++) {
        if (location < NSMaxRange(self->_ranges[i])) {
            return i;
        }
    }

    return NSNotFound;
}

- (unsigned)_positionOfRangeLessThanOrEqualToLocation:(NSUInteger)location {
    unsigned i = self->_ranges.size();
    while (i-- >= 1) {
        if (self->_ranges[i].location <= location) {
            return i;
        }
    }

    return NSNotFound;
}

- (unsigned)_count {
    return self->_ranges.size();
}

- (NSRange)_itemAtIndex:(unsigned)index {
    return self->_ranges[index];
}

- (NSRange&)_itemReferenceAtIndex:(unsigned)index {
    return self->_ranges[index];
}

- (void)_insertItem:(NSRange)range AtIndex:(unsigned)position {
    // range exceeds NSNotFound
    if (NSNotFound - range.location < range.length) {
        THROW_NS_HR(E_BOUNDS);
    }

    // insert index exceeds range vector size
    if (position > self->_ranges.size()) {
        THROW_NS_HR(E_BOUNDS);
    }

    self->_ranges.insert(self->_ranges.begin() + position, range);
}

- (void)_addItem:(NSRange)range {
    [self _insertItem:range AtIndex:self->_ranges.size()];
}

- (void)_removeItemAtIndex:(unsigned)position {
    // remove index exceeds range vector size
    if (position >= self->_ranges.size()) {
        THROW_NS_HR(E_BOUNDS);
    }

    self->_ranges.erase(self->_ranges.begin() + position);
}

- (void)_removeRanges:(NSRange)ranges {
    // begin removing from _ranges at ranges.location, remove through ranges.length
    self->_ranges.erase(self->_ranges.begin() + ranges.location, self->_ranges.begin() + ranges.location + ranges.length);
}

- (NSRangePointer)_allRanges {
    return _ranges.data();
}

@end
