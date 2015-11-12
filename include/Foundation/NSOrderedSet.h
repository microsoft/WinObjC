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

#ifndef _NSORDEREDSET_H_
#define _NSORDEREDSET_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSEnumerator.h>

@class NSSet;
@class NSIndexSet;

FOUNDATION_EXPORT_CLASS
@interface NSOrderedSet : NSObject <NSFastEnumeration>

+ (id)orderedSet;
+ (id)orderedSetWithSet:(NSSet*)set;
+ (id)orderedSetWithOrderedSet:(NSOrderedSet*)set;
+ (id)orderedSetWithObject:(id)object;
+ (id)orderedSetWithArray:(NSArray*)array;

- (NSIndexSet*)indexesOfObjectsPassingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL* stop))predicate;
- (NSUInteger)count;
- (void)enumerateObjectsUsingBlock:(void (^)(id obj, NSUInteger idx, BOOL* stop))block;
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(id obj, NSUInteger idx, BOOL* stop))block;
- (NSUInteger)indexOfObjectPassingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL* stop))predicate;
- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes;
- (id)objectAtIndex:(NSUInteger)index;
- (id)objectAtIndexedSubscript:(NSUInteger)index;
- (NSSet*)set;
- (NSArray*)array;
- (id)lastObject;
- (id)firstObject;
- (BOOL)containsObject:(id)object;

@end

FOUNDATION_EXPORT_CLASS
@interface NSMutableOrderedSet : NSOrderedSet

+ (id)orderedSetWithCapacity:(NSUInteger)numItems;

- (void)removeObjectsAtIndexes:(NSIndexSet*)indexes;
- (void)replaceObjectsAtIndexes:(NSIndexSet*)indexes withObjects:(NSArray*)objects;
- (void)addObject:(id)object;
- (void)addObjectsFromArray:(NSArray*)array;
- (void)setObject:(id)obj atIndex:(NSUInteger)idx;
- (void)removeAllObjects;

@end

#endif /* _NSORDEREDSET_H_ */