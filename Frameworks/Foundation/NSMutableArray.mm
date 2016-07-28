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

#import "Starboard.h"
#import "StubReturn.h"
#import "CoreFoundation/CFArray.h"
#import "Foundation/NSMutableArray.h"
#import "LoggingNative.h"
#import "CFHelpers.h"
#import "NSRaise.h"
#import "NSCFArray.h"
#import "BridgeHelpers.h"

#include <algorithm>

static const wchar_t* TAG = L"NSMutableArray";

using NSCompareFunc = NSInteger (*)(id, id, void*);

@implementation NSMutableArray

+ ALLOC_PROTOTYPE_SUBCLASS_WITH_ZONE(NSMutableArray, NSMutableArrayPrototype);

/**
 @Status Interoperable
*/
+ (instancetype)arrayWithCapacity:(NSUInteger)numElements {
    return [[[self alloc] initWithCapacity:numElements] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCapacity:(NSUInteger)numElements {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (void)removeAllObjects {
    while ([self count] > 0) {
        [self removeLastObject];
    }
}

/**
 @Status Interoperable
*/
- (void)addObject:(NSObject*)objAddr {
    // NSMutableArray is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)addObjectsFromArray:(NSArray*)fromArray {
    NSEnumerator* enumerator = [fromArray objectEnumerator];

    for (NSObject* curVal in enumerator) {
        [self addObject:curVal];
    }
}

/**
 @Status Interoperable
*/
- (void)setArray:(NSArray*)fromArray {
    [self removeAllObjects];
    [self addObjectsFromArray:fromArray];
}

/**
 @Status Interoperable
*/
- (void)removeObjectsInArray:(NSArray*)fromArray {
    NSEnumerator* enumerator = [fromArray objectEnumerator];
    NSObject* curVal = [enumerator nextObject];

    while (curVal != nil) {
        [self removeObject:curVal];
        curVal = [enumerator nextObject];
    }
}

/**
 @Status Interoperable
*/
- (void)insertObject:(NSObject*)objAddr atIndex:(NSUInteger)index {
    // NSMutableArray is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)insertObjects:(NSArray*)objects atIndexes:(NSIndexSet*)indexes {
    NSInteger i;
    NSInteger index = [indexes firstIndex];
    int count = [objects count];
    for (i = 0; i < count; i++) {
        [self insertObject:[objects objectAtIndex:i] atIndex:index];
        index = [indexes indexGreaterThanIndex:index];
    }
}

/**
 @Status Interoperable
*/
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)obj {
    // NSMutableArray is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)setObject:(NSObject*)obj atIndexedSubscript:(NSUInteger)index {
    if (index == [self count]) {
        [self addObject:obj];
    } else {
        [self replaceObjectAtIndex:index withObject:obj];
    }
}

/**
 @Status Interoperable
*/
- (void)exchangeObjectAtIndex:(NSUInteger)atIndex withObjectAtIndex:(NSUInteger)withIndex {
    NSObject* obj1 = [self objectAtIndex:atIndex];
    NSObject* obj2 = [self objectAtIndex:withIndex];

    [obj1 retain];
    [obj2 retain];

    [self replaceObjectAtIndex:atIndex withObject:obj2];
    [self replaceObjectAtIndex:withIndex withObject:obj1];

    [obj1 release];
    [obj2 release];
}

/**
 @Status Interoperable
*/
- (void)removeObject:(NSObject*)objAddr {
    if (objAddr == nil) {
        TraceVerbose(TAG, L"objAddr = nil!");
    }

    int idx = [self indexOfObject:objAddr];
    if (idx != NSNotFound) {
        [self removeObjectAtIndex:idx];
    }
}

/**
 @Status Interoperable
*/
- (void)removeObject:(NSObject*)objAddr inRange:(NSRange)range {
    for (int i = range.location + range.length - 1; i >= (int)range.location; i--) {
        id curObj = [self objectAtIndex:i];

        if ([curObj isEqual:objAddr]) {
            [self removeObject:curObj];
        }
    }
}

/**
 @Status Interoperable
*/
- (void)removeObjectsInRange:(NSRange)range {
    for (int i = range.location + range.length - 1; i >= (int)range.location; i--) {
        [self removeObjectAtIndex:i];
    }
}

/**
 @Status Interoperable
*/
- (void)removeObjectIdenticalTo:(NSObject*)objAddr {
    int idx = [self indexOfObjectIdenticalTo:objAddr];
    if (idx != NSNotFound) {
        [self removeObjectAtIndex:idx];
    }
}

/**
 @Status Interoperable
*/
- (void)removeObjectAtIndex:(NSUInteger)index {
    // NSMutableArray is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)removeObjectsAtIndexes:(NSIndexSet*)indexSet {
    [indexSet enumerateIndexesWithOptions:NSEnumerationReverse
                               usingBlock:^(NSUInteger index, BOOL* stop) {
                                   [self removeObjectAtIndex:index];
                               }];
}

/**
 @Status Interoperable
*/
- (void)removeLastObject {
    // NSMutableArray is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocation();
}

static void swap(NSMutableArray* self, uint32_t a, uint32_t b) {
    if (a == b)
        return;

    id obj1 = [self objectAtIndex:a];
    id obj2 = [self objectAtIndex:b];

    [obj1 retain];
    [obj2 retain];
    [self replaceObjectAtIndex:b withObject:obj1];
    [self replaceObjectAtIndex:a withObject:obj2];
    [obj1 release];
    [obj2 release];
}

static void shortsort(NSMutableArray* self, uint32_t lo, uint32_t hi, NSCompareFunc compFunc, void* context) {
    int p, max;

    while (hi > lo) {
        max = lo;
        for (p = lo + 1; p <= (int)hi; p += 1) {
            if ((compFunc([self objectAtIndex:p], [self objectAtIndex:max], context)) > 0)
                max = p;
        }

        swap(self, max, hi);
        hi -= 1;
    }
}

static signed int selComp(NSMutableArray* self, int i1, int i2, SEL selector) {
    typedef int (*ftype)(id, SEL, id);
    return ((ftype)objc_msgSend)([self objectAtIndex:i1], selector, [self objectAtIndex:i2]);
}

static void shortsort(NSMutableArray* self, uint32_t lo, uint32_t hi, SEL selector) {
    DWORD p, max;

    while (hi > lo) {
        max = lo;
        for (p = lo + 1; p <= hi; p += 1) {
            if (selComp(self, p, max, selector) > 0)
                max = p;
        }

        swap(self, max, hi);
        hi -= 1;
    }
}

/**
 @Status Interoperable
*/
- (void)sortUsingComparator:(NSComparator)comparator {
    [self sortUsingFunction:CFNSBlockCompare context:comparator];
}

#define CUTOFF 8

/**
 @Status Interoperable
*/
- (void)sortUsingFunction:(NSCompareFunc)compFunc context:(void*)context {
    NSUInteger count = [self count];

    [self sortUsingFunction:compFunc context:context range:NSMakeRange(0, count)];
}

/**
 @Status Interoperable
*/
- (void)sortUsingFunction:(NSCompareFunc)compFunc context:(void*)context range:(NSRange)range {
    uint32_t base = range.location;
    uint32_t num = range.length;

    uint32_t lo, hi;
    uint32_t mid;
    uint32_t loguy, higuy;
    uint32_t size;
    uint32_t lostk[30], histk[30];
    int stkptr;

    if (num < 2)
        return;
    stkptr = 0;

    lo = base;
    hi = base + (num - 1);

recurse:
    size = (hi - lo) + 1;

    if (size <= CUTOFF) {
        shortsort(self, lo, hi, compFunc, context);
    } else {
        mid = lo + (size / 2);
        swap(self, mid, lo);

        loguy = lo;
        higuy = hi + 1;

        for (;;) {
            do {
                loguy += 1;
            } while (loguy <= hi && (compFunc([self objectAtIndex:loguy], [self objectAtIndex:lo], context)) <= 0);

            do {
                higuy -= 1;
            } while (higuy > lo && (compFunc([self objectAtIndex:higuy], [self objectAtIndex:lo], context)) >= 0);

            if (higuy < loguy)
                break;
            swap(self, loguy, higuy);
        }

        swap(self, lo, higuy);

        if (higuy - 1 - lo >= hi - loguy) {
            if (lo + 1 < higuy) {
                lostk[stkptr] = lo;
                histk[stkptr] = higuy - 1;
                ++stkptr;
            }

            if (loguy < hi) {
                lo = loguy;
                goto recurse;
            }
        } else {
            if (loguy < hi) {
                lostk[stkptr] = loguy;
                histk[stkptr] = hi;
                ++stkptr;
            }

            if (lo + 1 < higuy) {
                hi = higuy - 1;
                goto recurse;
            }
        }
    }

    --stkptr;
    if (stkptr >= 0) {
        lo = lostk[stkptr];
        hi = histk[stkptr];
        goto recurse;
    }
}

/**
 @Status Interoperable
*/
- (void)sortUsingSelector:(SEL)selector {
    uint32_t base = 0;
    uint32_t num = [self count];

    uint32_t lo, hi;
    uint32_t mid;
    uint32_t loguy, higuy;
    unsigned size;
    uint32_t lostk[30], histk[30];
    int stkptr;

    if (num < 2)
        return;
    stkptr = 0;

    lo = base;
    hi = base + (num - 1);

recurse:
    size = (hi - lo) + 1;

    if (size <= CUTOFF) {
        shortsort(self, lo, hi, selector);
    } else {
        mid = lo + (size / 2);
        swap(self, mid, lo);

        loguy = lo;
        higuy = hi + 1;

        for (;;) {
            do {
                loguy += 1;
            } while (loguy <= hi && selComp(self, loguy, lo, selector) <= 0);

            do {
                higuy -= 1;
            } while (higuy > lo && selComp(self, higuy, lo, selector) >= 0);

            if (higuy < loguy)
                break;
            swap(self, loguy, higuy);
        }

        swap(self, lo, higuy);

        if (higuy - 1 - lo >= hi - loguy) {
            if (lo + 1 < higuy) {
                lostk[stkptr] = lo;
                histk[stkptr] = higuy - 1;
                ++stkptr;
            }

            if (loguy < hi) {
                lo = loguy;
                goto recurse;
            }
        } else {
            if (loguy < hi) {
                lostk[stkptr] = loguy;
                histk[stkptr] = hi;
                ++stkptr;
            }

            if (lo + 1 < higuy) {
                hi = higuy - 1;
                goto recurse;
            }
        }
    }

    --stkptr;
    if (stkptr >= 0) {
        lo = lostk[stkptr];
        hi = histk[stkptr];
        goto recurse;
    }
}

/**
 @Status Interoperable
*/
- (void)sortUsingDescriptors:(NSArray*)descriptors {
    [self sortUsingFunction:CFNSDescriptorCompare context:descriptors];
}

/**
 @Status Interoperable
*/
- (NSObject*)copyWithZone:(NSZone*)zone {
    NSArray* ret = [[NSArray alloc] initWithArray:self];

    return ret;
}

/**
 @Status Interoperable
*/
- (void)filterUsingPredicate:(NSPredicate*)predicate {
    if (predicate == nil) {
        return;
    }

    NSInteger count = [self count];

    while (--count >= 0) {
        id check = [self objectAtIndex:count];

        if (![predicate evaluateWithObject:check])
            [self removeObjectAtIndex:count];
    }
}

/**
 @Status Stub
 @Notes
*/
- (void)removeObjectIdenticalTo:(id)anObject inRange:(NSRange)aRange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeObjectsFromIndices:(NSUInteger*)indices numIndices:(NSUInteger)count {
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
 @Status Interoperable
 @Notes
*/
- (void)replaceObjectsInRange:(NSRange)aRange withObjectsFromArray:(NSArray*)otherArray range:(NSRange)otherRange {
    // An inefficient naive implementation would be to remove all objects from aRange,
    // then insert all objects from otherArray in otherRange.
    // However, this forces a unnecessary number of array shifts, which are expensive.
    // As an optimization, do as many direct replacements as possible.
    NSUInteger replaceEnd = std::min(aRange.length, otherRange.length);

    for (NSUInteger i = 0; i < replaceEnd; i++) {
        [self replaceObjectAtIndex:(i + aRange.location) withObject:[otherArray objectAtIndex:(i + otherRange.location)]];
    }

    if (aRange.length < otherRange.length) {
        // If aRange is smaller than otherRange, insert the remaining elements
        for (NSUInteger i = aRange.length; i < otherRange.length; i++) {
            [self insertObject:[otherArray objectAtIndex:(i + otherRange.location)] atIndex:(i + aRange.location)];
        }

    } else if (aRange.length > otherRange.length) {
        // If aRange is larger than otherRange, remove excess elements remaining in aRange
        NSUInteger removeIndex = aRange.location + otherRange.length;
        for (NSUInteger i = otherRange.length; i < aRange.length; i++) {
            [self removeObjectAtIndex:removeIndex];
        }
    }

    // If ranges are equal, nothing else needs to be done
}

/**
 @Status Interoperable
 @Notes
*/
- (void)replaceObjectsInRange:(NSRange)aRange withObjectsFromArray:(NSArray*)otherArray {
    [self replaceObjectsInRange:aRange withObjectsFromArray:otherArray range:{ 0, [otherArray count] }];
}

/**
 @Status Interoperable
 @Notes NSSortConcurrent is ignored, but this is compatible with reference documentation
*/
- (void)sortWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr {
    if (opts & NSSortStable) {
        CFMutableDictionaryRef originalIndices = CFDictionaryCreateMutable(kCFAllocatorDefault, [self count], nullptr, nullptr);

        // Construct a dictionary mapping of objects in the array to their original indices
        for (int i = 0; i < [self count]; i++) {
            CFDictionaryAddValue(originalIndices, (const void*)[self objectAtIndex:i], (const void*)i);
        }

        [self sortUsingFunction:CFNSBlockCompare context:^NSComparisonResult(id obj1, id obj2) {
            NSComparisonResult result = cmptr(obj1, obj2);
            if (result != NSOrderedSame) {
                return result;
            }

            // If the caller-provided comparator result is NSOrderedSame, ensure stability is enforced by comparing the original object indices.
            return ((NSUInteger)CFDictionaryGetValue(originalIndices, obj1) > (NSUInteger)CFDictionaryGetValue(originalIndices, obj2)) ?
                NSOrderedDescending : NSOrderedAscending;
        }];
        CFRelease(originalIndices);
    } else {
        [self sortUsingFunction:CFNSBlockCompare context:cmptr];
    }
}

@end
