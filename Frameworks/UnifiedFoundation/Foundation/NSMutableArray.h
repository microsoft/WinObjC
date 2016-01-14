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

#include "NSArray.h"

@interface NSMutableArray : NSArray {
@public
}
- (NSMutableArray*)initWithCapacity:(NSUInteger)numElements;
- (void)removeAllObjects;
- (void)addObject:(NSObject*)objAddr;
- (void)addObjectsFromArray:(NSArray*)fromArray;
- (void)setArray:(NSArray*)fromArray;
- (void)removeObjectsInArray:(NSArray*)fromArray;
- (void)insertObject:(NSObject*)objAddr atIndex:(NSUInteger)index;
- (void)insertObjects:(NSArray*)objects atIndexes:(NSIndexSet*)indexes;
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(NSObject*)obj;
- (void)setObject:(NSObject*)obj atIndexedSubscript:(NSUInteger)index;
- (void)exchangeObjectAtIndex:(NSUInteger)atIndex withObjectAtIndex:(NSUInteger)withIndex;
- (void)removeObject:(NSObject*)objAddr;
- (void)removeObject:(NSObject*)objAddr inRange:(NSRange)range;
- (void)removeObjectsInRange:(NSRange)range;
- (void)removeObjectIdenticalTo:(NSObject*)objAddr;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)removeObjectsAtIndexes:(NSIndexSet*)index;
- (void)_moveObjectAtIndexToEnd:(NSUInteger)index;
- (void)removeLastObject;
- (void)sortUsingComparator:(NSComparator*)comparator;
- (void)sortUsingFunction:(uint32_t)compFunc context:(uint32_t)context;
- (void)sortUsingFunction:(uint32_t)compFunc context:(uint32_t)context range:(NSRange)range;
- (void)sortUsingSelector:(SEL)selector;
- (void)sortUsingDescriptors:(NSArray*)descriptors;
- (NSObject*)copyWithZone:(NSZone*)zone;
- (void)filterUsingPredicate:(NSPredicate*)predicate;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(DWORD)maxCount;
+ (NSMutableArray*)arrayWithCapacity:(NSUInteger)numElements;
+ (NSObject*)allocWithZone:(NSZone*)zone;
@end

@interface NSMutableArrayConcrete : NSMutableArray {
@public
}
- (NSMutableArray*)initWithCapacity:(NSUInteger)numElements;
- (void)removeAllObjects;
- (void)addObject:(NSObject*)objAddr;
- (void)addObjectsFromArray:(NSArray*)fromArray;
- (void)setArray:(NSArray*)fromArray;
- (void)removeObjectsInArray:(NSArray*)fromArray;
- (void)insertObject:(NSObject*)objAddr atIndex:(NSUInteger)index;
- (void)insertObjects:(NSArray*)objects atIndexes:(NSIndexSet*)indexes;
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(NSObject*)obj;
- (void)setObject:(NSObject*)obj atIndexedSubscript:(NSUInteger)index;
- (void)exchangeObjectAtIndex:(NSUInteger)atIndex withObjectAtIndex:(NSUInteger)withIndex;
- (void)removeObject:(NSObject*)objAddr;
- (void)removeObject:(NSObject*)objAddr inRange:(NSRange)range;
- (void)removeObjectsInRange:(NSRange)range;
- (void)removeObjectIdenticalTo:(NSObject*)objAddr;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)removeObjectsAtIndexes:(NSIndexSet*)index;
- (void)_moveObjectAtIndexToEnd:(NSUInteger)index;
- (void)removeLastObject;
- (void)sortUsingComparator:(NSComparator*)comparator;
- (void)sortUsingFunction:(uint32_t)compFunc context:(uint32_t)context;
- (void)sortUsingFunction:(uint32_t)compFunc context:(uint32_t)context range:(NSRange)range;
- (void)sortUsingSelector:(SEL)selector;
- (void)sortUsingDescriptors:(NSArray*)descriptors;
- (NSObject*)copyWithZone:(NSZone*)zone;
- (void)filterUsingPredicate:(NSPredicate*)predicate;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(DWORD)maxCount;
+ (NSMutableArray*)arrayWithCapacity:(NSUInteger)numElements;
+ (NSObject*)allocWithZone:(NSZone*)zone;
@end
