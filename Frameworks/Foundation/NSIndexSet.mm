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

#include "CoreFoundation/CFArray.h"

#include "Foundation/NSMutableArray.h"
#include "Foundation/NSMutableData.h"
#include "Foundation/NSEnumerator.h"
#include "Foundation/NSKeyedArchiver.h"
#include "Foundation/NSMutableString.h"
#include "Foundation/NSIndexSet.h"
#include "Foundation/NSRange.h"
#include "Etc.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define NSNotFound 0x7fffffff

static unsigned positionOfRangeGreaterThanOrEqualToLocation(NSRange* ranges, unsigned length, unsigned location) {
    for (unsigned i = 0; i < length; i++)
        if (location < NSMaxRange(ranges[i]))
            return i;

    return NSNotFound;
}

static unsigned positionOfRangeLessThanOrEqualToLocation(NSRange* ranges, unsigned length, unsigned location) {
    int i = length;

    while (--i >= 0) {
        if (ranges[i].location <= location)
            return i;
    }

    return NSNotFound;
}

static void removeRangeAtPosition(NSRange* ranges, unsigned length, unsigned position) {
    for (unsigned i = position; i + 1 < length; i++)
        ranges[i] = ranges[i + 1];
}

static unsigned raCount(NSIndexSet* set) {
    return set->_length;
}

static NSRange raItemAtIndex(NSIndexSet* set, unsigned i) {
    return set->_ranges[i];
}

static void raAddItem(NSIndexSet* set, NSRange r) {
    if (set->_length + 1 >= set->_maxLength) {
        set->_maxLength += 64;
        set->_ranges = (NSRange*)EbrRealloc(set->_ranges, set->_maxLength * sizeof(NSRange));
    }

    set->_ranges[set->_length++] = r;
}

static void raInsertItem(NSIndexSet* set, NSRange r, NSUInteger idx) {
    if (idx > set->_length) {
        assert(0);
    }

    if (idx + 1 >= set->_maxLength) {
        set->_maxLength += 64;
        set->_ranges = (NSRange*)EbrRealloc(set->_ranges, set->_maxLength * sizeof(NSRange));
    }

    //  Shift ranges up
    memmove(&set->_ranges[idx + 1], &set->_ranges[idx], sizeof(NSRange) * (set->_length - idx));
    set->_ranges[idx] = r;
    set->_length++;
}

static void raSetItemAtIndex(NSIndexSet* set, NSRange r, NSUInteger idx) {
    if (idx >= set->_length) {
        assert(0);
    }

    set->_ranges[idx] = r;
}

static void raRemoveItemAtIndex(NSIndexSet* set, NSUInteger idx) {
    if (idx >= set->_length) {
        assert(0);
    }

    //  Shift ranges down
    memmove(&set->_ranges[idx], &set->_ranges[idx + 1], sizeof(NSRange) * (set->_length - (idx + 1)));
    set->_length--;
}

static BOOL NSLocationInRange(NSUInteger idx, NSRange r) {
    if (idx >= r.location && idx < r.location + r.length) {
        return TRUE;
    } else {
        return FALSE;
    }
}

@implementation NSIndexSet : NSObject
+ (id)indexSetWithIndexesInRange:(NSRange)range {
    id ret = [NSMutableIndexSet new];
    [ret addIndexesInRange:range];

    return [ret autorelease];
}

+ (id)indexSet {
    id ret = [NSIndexSet new];

    return [ret autorelease];
}

+ (id)indexSetWithIndex:(NSUInteger)index {
    NSRange range;
    range.location = index;
    range.length = 1;

    id ret = [NSMutableIndexSet new];
    [ret addIndexesInRange:range];

    return [ret autorelease];
}

- (id)init {
    return self;
}

- (id)initWithIndex:(unsigned)index {
    NSRange range;

    range.location = index;
    range.length = 0;

    raAddItem(self, range);
    return self;
}

- (id)initWithIndexSet:(NSIndexSet*)other {
    for (unsigned i = 0; i < other->_length; i++) {
        raAddItem(self, other->_ranges[i]);
    }

    return self;
}

- (unsigned)count {
    unsigned ret = 0;

    for (unsigned i = 0; i < _length; i++) {
        ret += _ranges[i].length;
    }
    return ret;
}

- (void)dealloc {
    if (_ranges)
        EbrFree(_ranges);
    [super dealloc];
}

- (unsigned)indexGreaterThanIndex:(unsigned)anIndex {
    assert(!"indexGreaterThanIndex not implemented!");
    return -1;
}

- (unsigned)countOfIndexesInRange:(NSRange)range {
    unsigned ret = 0;

    for (unsigned i = 0; i < raCount(self); i++) {
        NSRange cur = raItemAtIndex(self, i);

        if (cur.location > range.location + range.length)
            break;
        if (cur.location + cur.length < range.location)
            continue;

        int low = MAX(cur.location, range.location);
        int high = MIN(cur.location + cur.length, range.location + range.length);

        ret += high - low;
    }

    return ret;
}

- (void)enumerateIndexesUsingBlock:(void (^)(NSUInteger idx, BOOL* stop))block {
    BOOL stop = FALSE;
    for (unsigned int i = 0; i < raCount(self) && !stop; i++) {
        NSRange cur = raItemAtIndex(self, i);

        for (unsigned int j = cur.location; j < cur.location + cur.length && !stop; j++) {
            block(j, &stop);
        }
    }
}

- (BOOL)intersectsIndexesInRange:(NSRange)range {
    unsigned first = positionOfRangeGreaterThanOrEqualToLocation(_ranges, _length, range.location);

    if (first == NSNotFound)
        return NO;

    return (_ranges[first].location < NSMaxRange(range)) ? YES : NO;
}

- (id)mutableCopyWithZone:(NSZone*)zone {
    return [[NSMutableIndexSet allocWithZone:zone] initWithIndexSet:self];
}

- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (BOOL)containsIndex:(unsigned)anIndex {
    assert(!"containsIndex not implemented!");
    return YES;
}

- (unsigned)firstIndex {
    if (raCount(self) == 0) {
        return NSNotFound;
    }
    unsigned ret = raItemAtIndex(self, 0).location;

    return ret;
}

- (unsigned)lastIndex {
    if (raCount(self) == 0) {
        return NSNotFound;
    }
    unsigned ret = NSMaxRange(raItemAtIndex(self, raCount(self) - 1)) - 1;

    return ret;
}

- (BOOL)isEqualToIndexSet:(NSIndexSet*)otherSet {
    if (![otherSet isKindOfClass:[NSIndexSet class]])
        return FALSE;

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

@end

static bool rangesIntersect(const NSRange& lhs, const NSRange& rhs) {
    if (lhs.location < rhs.location) {
        return lhs.location + lhs.length >= rhs.location;
    }
    return rhs.location + rhs.length >= lhs.location;
}

@implementation NSMutableIndexSet : NSIndexSet
- (void)addIndexesInRange:(NSRange)aRange {
}

- (id)removeIndexesInRange:(NSRange)range {
    unsigned pos = positionOfRangeLessThanOrEqualToLocation(_ranges, _length, range.location);

    if (pos == NSNotFound)
        pos = 0;

    while (range.length > 0 && pos < _length) {
        if (_ranges[pos].location >= NSMaxRange(range))
            break;

        if (NSMaxRange(_ranges[pos]) == NSMaxRange(range)) {
            if (_ranges[pos].location == range.location) {
                removeRangeAtPosition(_ranges, _length, pos);
                _length--;
            } else
                _ranges[pos].length = range.location - _ranges[pos].location;
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

- (void)addIndex:(NSUInteger)index {
    NSRange r;

    r.location = index;
    r.length = 1;

    [self addIndexesInRange:r];
}

- (void)addIndexes:(NSIndexSet*)other {
    for (unsigned i = 0; i < other->_length; ++i) {
        [self addIndexesInRange:other->_ranges[i]];
    }
}

- (void)removeIndex:(NSUInteger)index {
    NSRange r;

    r.location = index;
    r.length = 1;

    [self removeIndexesInRange:r];
}

- (void)removeIndexes:(NSIndexSet*)other {
    for (unsigned i = 0; i < other->_length; i++) {
        [self removeIndexesInRange:other->_ranges[i]];
    }
}

- (id)shiftIndexesStartingAtIndex:(NSUInteger)index by:(NSInteger)delta {
    if (delta < 0) {
        delta = -delta;
        NSUInteger pos = positionOfRangeLessThanOrEqualToLocation(_ranges, _length, index - delta);

        if (pos == NSNotFound)
            return self; // raise?

        NSUInteger count = _length;

        while (--count >= pos) {
            if (_ranges[count].location >= index) // if above index just move it down
                _ranges[count].location -= (unsigned)delta;
            else if (NSMaxRange(_ranges[count]) <= index - (unsigned)delta) // below area, ignore
                ;
            else if (_ranges[count].length > (unsigned)delta) { // if below, shorten
                if (NSMaxRange(_ranges[count]) - index >= (unsigned)delta) // if deletion entirely inside
                    _ranges[count].length -= delta;
                else
                    _ranges[count].length = NSMaxRange(_ranges[count]) - (index - delta);
            } else { // if below and shorter than the delta, remove
                _length--;
                for (unsigned i = count; i < _length; i++)
                    _ranges[i] = _ranges[i + 1];
            }
        }
    } else {
        NSInteger pos = positionOfRangeLessThanOrEqualToLocation(_ranges, _length, index);

        if (pos == NSNotFound)
            return self; // raise?

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
            if (_ranges[count].location >= index)
                _ranges[count].location += delta;
        }
    }

    return self;
}

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
