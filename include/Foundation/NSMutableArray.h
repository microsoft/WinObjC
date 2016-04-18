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

#import <Foundation/NSArray.h>

@class NSString;
@class NSURL;
@class NSIndexSet;
@class NSPredicate;

FOUNDATION_EXPORT_CLASS
@interface NSMutableArray : NSArray <NSCopying, NSFastEnumeration, NSMutableCopying, NSSecureCoding>
+ (instancetype)arrayWithCapacity:(NSUInteger)numItems;
- (instancetype)initWithCapacity:(NSUInteger)numItems;
- (void)addObject:(id)anObject;
- (void)addObjectsFromArray:(NSArray*)otherArray;
- (void)insertObject:(id)anObject atIndex:(NSUInteger)index;
- (void)insertObjects:(NSArray*)objects atIndexes:(NSIndexSet*)indexes;
- (void)removeAllObjects;
- (void)removeLastObject;
- (void)removeObject:(id)anObject;
- (void)removeObject:(id)anObject inRange:(NSRange)aRange;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)removeObjectsAtIndexes:(NSIndexSet*)indexes;
- (void)removeObjectIdenticalTo:(id)anObject;
- (void)removeObjectIdenticalTo:(id)anObject inRange:(NSRange)aRange STUB_METHOD;
- (void)removeObjectsFromIndices:(NSUInteger*)indices numIndices:(NSUInteger)count STUB_METHOD;
- (void)removeObjectsInArray:(NSArray*)otherArray;
- (void)removeObjectsInRange:(NSRange)aRange;
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject;
- (void)setObject:(id)anObject atIndexedSubscript:(NSUInteger)index;
- (void)replaceObjectsAtIndexes:(NSIndexSet*)indexes withObjects:(NSArray*)objects STUB_METHOD;
- (void)replaceObjectsInRange:(NSRange)aRange withObjectsFromArray:(NSArray*)otherArray range:(NSRange)otherRange;
- (void)replaceObjectsInRange:(NSRange)aRange withObjectsFromArray:(NSArray*)otherArray;
- (void)setArray:(NSArray*)otherArray;
- (void)filterUsingPredicate:(NSPredicate*)predicate;
- (void)exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;
- (void)sortUsingDescriptors:(NSArray*)sortDescriptors;
- (void)sortUsingComparator:(NSComparator)cmptr;
- (void)sortWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;
- (void)sortUsingFunction:(NSInteger (*)(id, id, void*))compare context:(void*)context;
- (void)sortUsingSelector:(SEL)comparator;
@end
