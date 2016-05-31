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
#include <Foundation/NSCountedSet.h>
#include <Foundation/NSMutableDictionary.h>

@implementation NSCountedSet {
@private
    StrongId<NSMutableSet> _internalSet;
    StrongId<NSMutableDictionary> _counts; // id -> nsnumber
}

/**
 @Status Interoperable
*/
- (instancetype)initWithObjects:(id _Nonnull const* _Nullable)objects count:(unsigned)count {
    if (self = [self initWithCapacity:count]) {
        for (unsigned int i = 0; i < count; i++) {
            [self addObject:objects[i]];
        }
    }
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCapacity:(unsigned)capacity {
    if (self = [self init]) {
        _internalSet = [NSMutableSet setWithCapacity:capacity];
        _counts = [NSMutableDictionary dictionary];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (NSUInteger)countForObject:(id)object {
    NSNumber* count = [_counts objectForKey:object];
    return count ? [count unsignedIntegerValue] : 0;
}

/**
 @Status Interoperable
*/
- (unsigned)count {
    return [_internalSet count];
}

/**
 @Status Interoperable
*/
- (NSEnumerator*)objectEnumerator {
    return [_internalSet objectEnumerator];
}

/**
 @Status Interoperable
*/
- (id)member:(id)object {
    return [_internalSet member:object];
}

/**
 @Status Interoperable
*/
- (void)addObject:(id)object {
    NSNumber* count = [_counts objectForKey:object];
    if (count) {
        [_counts setObject:[NSNumber numberWithInt:[count intValue] + 1] forKey:object];
    } else {
        [_internalSet addObject:object];
        [_counts setObject:@1 forKey:object];
    }
}

/**
 @Status Interoperable
*/
- (void)removeObject:(id)object {
    NSNumber* count = [_counts objectForKey:object];
    if (count) {
        if ([count isEqual:@1]) {
            [_internalSet removeObject:object];
            [_counts removeObjectForKey:object];
        } else {
            [_counts setObject:[NSNumber numberWithInt:[count intValue] - 1] forKey:object];
        }
    }
}

/**
 @Status Interoperable
*/
- (void)removeAllObjects {
    [_counts removeAllObjects];
    [_internalSet removeAllObjects];
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    return [[[self class] alloc] initWithSet:self];
}

/**
 @Status Interoperable
*/
- (instancetype)mutableCopyWithZone:(NSZone*)zone {
    // NSCountedSet is derived from NSMutableSet
    return [self copy];
}

@end
