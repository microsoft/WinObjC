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

@implementation NSMutableIndexSet

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
    for (unsigned int i = 0; i < (raCount(self)); i++) {
        NSRange cur = raItemAtIndex(self, i);

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
        memmove(&_ranges[removalRange.location], // dest
                &_ranges[removalRange.location + removalRange.length], // src
                sizeof(NSRange) * ((_length) - (removalRange.location + removalRange.length))); // numbytes
        _length -= removalRange.length;
    }

    // Now insert the candidate range
    raInsertItem(self, candidateRange, removalRange.location);
}

/**
 @Status Interoperable
*/
- (id)removeIndexesInRange:(NSRange)range {
    unsigned pos = positionOfRangeLessThanOrEqualToLocation(_ranges, _length, range.location);

    if (pos == NSNotFound) {
        pos = 0;
    }

    while (range.length > 0 && pos < _length) {
        if (_ranges[pos].location >= NSMaxRange(range)) {
            break;
        }

        if (NSMaxRange(_ranges[pos]) == NSMaxRange(range)) {
            if (_ranges[pos].location == range.location) {
                removeRangeAtPosition(_ranges, _length, pos);
                _length--;
            } else {
                _ranges[pos].length = range.location - _ranges[pos].location;
            }
            break;
        }

        if (NSMaxRange(_ranges[pos]) > NSMaxRange(range)) {
            if (_ranges[pos].location == range.location) {
                unsigned max = NSMaxRange(_ranges[pos]);

                _ranges[pos].location = NSMaxRange(range);
                _ranges[pos].length = max - _ranges[pos].location;
            } else {
                NSRange iceberg;

                iceberg.location = NSMaxRange(range);
                iceberg.length = NSMaxRange(_ranges[pos]) - iceberg.location;

                _ranges[pos].length = range.location - _ranges[pos].location;

                raInsertItem(self, iceberg, pos + 1);
            }
            break;
        }

        if (range.location >= NSMaxRange(_ranges[pos])) {
            pos++;
        } else {
            unsigned max = NSMaxRange(range);
            NSRange temp = _ranges[pos];

            if (_ranges[pos].location >= range.location) {
                removeRangeAtPosition(_ranges, _length, pos);
                _length--;
            } else {
                _ranges[pos].length = range.location - _ranges[pos].location;
                pos++;
            }
            range.location = NSMaxRange(temp);
            range.length = max - range.location;
        }
    }

    return self;
}

/**
 @Status Stub
*/
- (void)addIndex:(NSUInteger)index {
    UNIMPLEMENTED();
    NSRange r;

    r.location = index;
    r.length = 1;

    [self addIndexesInRange:r];
}

/**
 @Status Stub
*/
- (void)addIndexes:(NSIndexSet*)other {
    UNIMPLEMENTED();
    for (unsigned i = 0; i < other->_length; ++i) {
        [self addIndexesInRange:other->_ranges[i]];
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
    for (unsigned i = 0; i < other->_length; i++) {
        [self removeIndexesInRange:other->_ranges[i]];
    }
}

/**
 @Status Interoperable
*/
- (id)shiftIndexesStartingAtIndex:(NSUInteger)index by:(NSInteger)delta {
    if (delta < 0) {
        delta = -delta;
        NSUInteger pos = positionOfRangeLessThanOrEqualToLocation(_ranges, _length, index - delta);

        if (pos == NSNotFound) {
            return self; // raise?
        }

        NSUInteger count = _length;

        while (--count >= pos) {
            if (_ranges[count].location >= index) { // if above index just move it down
                _ranges[count].location -= (unsigned)delta;
            } else if (NSMaxRange(_ranges[count]) <= index - (unsigned)delta) { // below area, ignore
                ;
            } else if (_ranges[count].length > (unsigned)delta) { // if below, shorten
                if (NSMaxRange(_ranges[count]) - index >= (unsigned)delta) { // if deletion entirely inside
                    _ranges[count].length -= delta;
                } else {
                    _ranges[count].length = NSMaxRange(_ranges[count]) - (index - delta);
                }
            } else { // if below and shorter than the delta, remove
                _length--;
                for (unsigned i = count; i < _length; i++) {
                    _ranges[i] = _ranges[i + 1];
                }
            }
        }
    } else {
        NSInteger pos = positionOfRangeLessThanOrEqualToLocation(_ranges, _length, index);

        if (pos == NSNotFound) {
            return self; // raise?
        }

        // if index is inside a range, split it
        if (_ranges[pos].location < index && index < NSMaxRange(_ranges[pos])) {
            NSRange below = _ranges[pos];

            below.length = index - below.location;
            _ranges[pos].length = NSMaxRange(_ranges[pos]) - index;
            _ranges[pos].location = index;

            raInsertItem(self, below, pos);
        }

        // move all ranges at or above index by delta
        NSInteger count = _length;

        while (--count >= pos) {
            if (_ranges[count].location >= index) {
                _ranges[count].location += delta;
            }
        }
    }

    return self;
}

/**
 @Status Interoperable
*/
- (id)removeAllIndexes {
    _length = 0;
    return self;
}

+ (id)indexSet {
    return [[self new] autorelease];
}

- (id)_removeFromArray:(id)array {
    int i;

    for (i = raCount(self) - 1; i >= 0; i--) {
        NSRange rself = raItemAtIndex(self, i);

        for (int k = rself.location + rself.length - 1; k >= 0 && k >= int64_t(rself.location); k--) {
            [array removeObjectAtIndex:k];
        }
    }
    return self;
}

- (id)copyWithZone:(NSZone*)zone {
    return [[NSIndexSet allocWithZone:zone] initWithIndexSet:self];
}

@end
