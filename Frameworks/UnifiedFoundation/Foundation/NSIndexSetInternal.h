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
#pragma once

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define NSNotFound 0x7fffffff

static inline unsigned positionOfRangeGreaterThanOrEqualToLocation(NSRange* ranges, unsigned length, unsigned location) {
    for (unsigned i = 0; i < length; i++) {
        if (location < NSMaxRange(ranges[i])) {
            return i;
        }
    }

    return NSNotFound;
}

static inline unsigned positionOfRangeLessThanOrEqualToLocation(NSRange* ranges, unsigned length, unsigned location) {
    int i = length;

    while (--i >= 0) {
        if (ranges[i].location <= location) {
            return i;
        }
    }

    return NSNotFound;
}

static inline void removeRangeAtPosition(NSRange* ranges, unsigned length, unsigned position) {
    for (unsigned i = position; i + 1 < length; i++) {
        ranges[i] = ranges[i + 1];
    }
}

static inline unsigned raCount(NSIndexSet* set) {
    return set->_length;
}

static inline NSRange raItemAtIndex(NSIndexSet* set, unsigned i) {
    return set->_ranges[i];
}

static inline void raAddItem(NSIndexSet* set, NSRange r) {
    if (set->_length + 1 >= set->_maxLength) {
        set->_maxLength += 64;
        set->_ranges = (NSRange*)IwRealloc(set->_ranges, set->_maxLength * sizeof(NSRange));
    }

    set->_ranges[set->_length++] = r;
}

static inline void raInsertItem(NSIndexSet* set, NSRange r, NSUInteger idx) {
    if (idx > set->_length) {
        assert(0);
    }

    if (idx + 1 >= set->_maxLength) {
        set->_maxLength += 64;
        set->_ranges = (NSRange*)IwRealloc(set->_ranges, set->_maxLength * sizeof(NSRange));
    }

    //  Shift ranges up
    memmove(&set->_ranges[idx + 1], &set->_ranges[idx], sizeof(NSRange) * (set->_length - idx));
    set->_ranges[idx] = r;
    set->_length++;
}

static inline void raSetItemAtIndex(NSIndexSet* set, NSRange r, NSUInteger idx) {
    if (idx >= set->_length) {
        assert(0);
    }

    set->_ranges[idx] = r;
}

static inline void raRemoveItemAtIndex(NSIndexSet* set, NSUInteger idx) {
    if (idx >= set->_length) {
        assert(0);
    }

    //  Shift ranges down
    memmove(&set->_ranges[idx], &set->_ranges[idx + 1], sizeof(NSRange) * (set->_length - (idx + 1)));
    set->_length--;
}