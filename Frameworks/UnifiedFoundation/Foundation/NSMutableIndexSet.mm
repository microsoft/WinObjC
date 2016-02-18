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

@implementation NSMutableIndexSet : NSIndexSet

/**
 @Status Stub
*/
- (void)addIndexesInRange:(NSRange)aRange {
    UNIMPLEMENTED();
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