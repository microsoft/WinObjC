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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSFastEnumeration.h>
#import <Foundation/NSObject.h>

#import <Foundation/NSOrderedSet.h>

@class NSArray;
@class NSIndexSet;
@class NSPredicate;
@class NSSet;

FOUNDATION_EXPORT_CLASS
@interface NSMutableOrderedSet : NSOrderedSet <NSCopying, NSFastEnumeration, NSMutableCopying, NSSecureCoding>
+ (instancetype)orderedSetWithCapacity:(NSUInteger)numItems;
- (instancetype)initWithCapacity:(NSUInteger)numItems;
- (instancetype)init;
- (void)addObject:(id)object;
- (void)addObjects:(id _Nonnull const[])objects count:(NSUInteger)count;
- (void)addObjectsFromArray:(NSArray*)array;
- (void)insertObject:(id)object atIndex:(NSUInteger)idx;
- (void)setObject:(id)object atIndexedSubscript:(NSUInteger)idx;
- (void)insertObjects:(NSArray*)objects atIndexes:(NSIndexSet*)indexes;
- (void)removeObject:(id)object;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)removeObjectsAtIndexes:(NSIndexSet*)indexes;
- (void)removeObjectsInArray:(NSArray*)array;
- (void)removeObjectsInRange:(NSRange)range;
- (void)removeAllObjects;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)object;
- (void)replaceObjectsAtIndexes:(NSIndexSet*)indexes withObjects:(NSArray*)objects;
- (void)replaceObjectsInRange:(NSRange)range withObjects:(id _Nonnull const[])objects count:(NSUInteger)count;
- (void)setObject:(id)obj atIndex:(NSUInteger)idx;
- (void)moveObjectsAtIndexes:(NSIndexSet*)indexes toIndex:(NSUInteger)idx;
- (void)exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;
- (void)filterUsingPredicate:(NSPredicate*)predicate;
- (void)sortUsingDescriptors:(NSArray*)sortDescriptors;
- (void)sortUsingComparator:(NSComparator)cmptr;
- (void)sortWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;
- (void)sortRange:(NSRange)range options:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;
- (void)intersectOrderedSet:(NSOrderedSet*)other;
- (void)intersectSet:(NSSet*)other;
- (void)minusOrderedSet:(NSOrderedSet*)other;
- (void)minusSet:(NSSet*)other;
- (void)unionOrderedSet:(NSOrderedSet*)other;
- (void)unionSet:(NSSet*)other;
@end
