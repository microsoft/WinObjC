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

#ifndef __NSARRAY_H
#define __NSARRAY_H
class CFArray;

#define NSBinarySearchingFirstEqual (1 << 8)
#define NSBinarySearchingLastEqual (1 << 9)
#define NSBinarySearchingInsertionIndex (1 << 10)

typedef enum {
    NSEnumerationConcurrent = 1,
    NSEnumerationReverse = 2,
} NSEnumerationOptions;

#define __CFARRAY_SIZE_BYTES (0x30)
class __CFArray;

@interface NSArray : NSObject {
@public
    __CFArray* arr;
    DWORD _arraySpace[((__CFARRAY_SIZE_BYTES + 3) & ~3) / 4];
}
- (NSArray*)initWithObject:(NSObject*)obj;
- (NSArray*)initWithObjects:(NSObject*)first, ...;
- (NSArray*)initWithObjects:(NSObject**)objs count:(NSUInteger)count;
- (NSArray*)initWithObjectsTakeOwnership:(NSObject**)objs count:(NSUInteger)count;
- (NSArray*)initWithContentsOfFile:(NSString*)filename;
- (NSUInteger)count;
- (NSObject*)init;
- (NSObject*)lastObject;
- (NSObject*)firstObject;
- (id)objectAtIndex:(NSUInteger)index;
- (id)objectAtIndexedSubscript:(NSUInteger)index;
- (NSUInteger)indexOfObject:(id)obj;
- (NSIndexSet*)indexesOfObjectsPassingTest:(id)pred;
- (NSUInteger)indexOfObjectPassingTest:(id)pred;
- (NSUInteger)indexOfObject:(id)obj inRange:(NSRange)range;
- (NSUInteger)indexOfObjectIdenticalTo:(id)obj;
- (NSArray*)initWithCoder:(NSCoder*)coder;
- (NSArray*)initWithArray:(NSArray*)arrayToCopy;
- (NSArray*)initWithArray:(id)arrayToCopy copyItems:(BOOL)copyFlag;
- (NSObject*)valueForKey:(NSString*)key;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(NSUInteger)maxCount;
- (void)makeObjectsPerformSelector:(SEL)selector;
- (void)setValue:(NSObject*)value forKey:(NSString*)key;
- (void)makeObjectsPerformSelector:(SEL)selector withObject:(NSObject*)obj;
- (BOOL)containsObject:(NSObject*)obj;
- (NSString*)componentsJoinedByString:(NSString*)str;
- (NSArray*)sortedArrayUsingFunction:(compFuncType)compFunc context:(void*)context;
- (NSArray*)sortedArrayUsingComparator:(id)comparator;
- (NSArray*)filteredArrayUsingPredicate:(NSPredicate*)predicate;
- (NSObject*)mutableCopy;
- (NSObject*)mutableCopyWithZone:(NSZone*)zone;
- (NSObject*)copyWithZone:(NSZone*)zone;
- (NSEnumerator*)objectEnumerator;
- (NSEnumerator*)reverseObjectEnumerator;
- (NSArray*)sortedArrayUsingSelector:(SEL)selector;
- (NSArray*)sortedArrayUsingDescriptors:(NSArray*)descriptors;
- (NSArray*)subarrayWithRange:(NSRange)range;
- (NSObject*)firstObjectCommonWithArray:(NSArray*)array;
- (NSArray*)arrayByAddingObject:(NSObject*)obj;
- (NSArray*)arrayByAddingObjectsFromArray:(NSArray*)arr;
- (NSArray*)pathsMatchingExtensions:(NSArray*)extensions;
- (NSUInteger)indexOfObject:(NSObject*)obj inSortedRange:(NSRange)range options:(int)options usingComparator:(id)comparator;
- (void)dealloc;
- (BOOL)writeToFile:(NSString*)file atomically:(BOOL)atomically;
- (NSObject*)encodeWithCoder:(NSCoder*)coder;
- (NSString*)description;
- (void)getObjects:(id*)objects;
- (void)enumerateObjectsUsingBlock:(id)block;
- (void)enumerateObjectsWithOptions:(NSUInteger)options usingBlock:(id)block;
- (void)getObjects:(id*)objects range:(NSRange)range;
- (BOOL)isEqual:(NSObject*)other;
- (NSArray*)allObjects;
- (BOOL)isEqualToArray:(NSArray*)otherArray;
- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(DWORD)maxCount;
+ (NSArray*)arrayWithObjects:(NSObject*)first, ...;
+ (NSArray*)arrayWithObject:(NSObject*)obj;
+ (NSArray*)array;
+ (NSArray*)arrayWithObjects:(NSObject**)objs count:(NSUInteger)count;
+ (NSArray*)arrayWithArray:(NSArray*)arrayToCopy;
+ (NSArray*)arrayWithContentsOfFile:(NSString*)filename;
+ (NSObject*)allocWithZone:(NSZone*)zone;
@end

@interface NSArrayConcrete : NSArray {
@public
}
- (NSArray*)initWithObject:(NSObject*)obj;
- (NSArray*)initWithObjects:(NSObject*)first, ...;
- (NSArray*)initWithObjects:(NSObject**)objs count:(NSUInteger)count;
- (NSArray*)initWithObjectsTakeOwnership:(NSObject**)objs count:(NSUInteger)count;
- (NSArray*)initWithContentsOfFile:(NSString*)filename;
- (NSUInteger)count;
- (NSObject*)init;
- (NSObject*)lastObject;
- (NSObject*)firstObject;
- (id)objectAtIndex:(NSUInteger)index;
- (id)objectAtIndexedSubscript:(NSUInteger)index;
- (NSUInteger)indexOfObject:(id)obj;
- (NSIndexSet*)indexesOfObjectsPassingTest:(id)pred;
- (NSUInteger)indexOfObjectPassingTest:(id)pred;
- (NSUInteger)indexOfObject:(id)obj inRange:(NSRange)range;
- (NSUInteger)indexOfObjectIdenticalTo:(id)obj;
- (NSArray*)initWithCoder:(NSCoder*)coder;
- (NSArray*)initWithArray:(NSArray*)arrayToCopy;
- (NSArray*)initWithArray:(id)arrayToCopy copyItems:(BOOL)copyFlag;
- (NSObject*)valueForKey:(NSString*)key;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(NSUInteger)maxCount;
- (void)makeObjectsPerformSelector:(SEL)selector;
- (void)setValue:(NSObject*)value forKey:(NSString*)key;
- (void)makeObjectsPerformSelector:(SEL)selector withObject:(NSObject*)obj;
- (BOOL)containsObject:(NSObject*)obj;
- (NSString*)componentsJoinedByString:(NSString*)str;
- (NSArray*)sortedArrayUsingFunction:(compFuncType)compFunc context:(void*)context;
- (NSArray*)sortedArrayUsingComparator:(id)comparator;
- (NSArray*)filteredArrayUsingPredicate:(NSPredicate*)predicate;
- (NSObject*)mutableCopy;
- (NSObject*)mutableCopyWithZone:(NSZone*)zone;
- (NSObject*)copyWithZone:(NSZone*)zone;
- (NSEnumerator*)objectEnumerator;
- (NSEnumerator*)reverseObjectEnumerator;
- (NSArray*)sortedArrayUsingSelector:(SEL)selector;
- (NSArray*)sortedArrayUsingDescriptors:(NSArray*)descriptors;
- (NSArray*)subarrayWithRange:(NSRange)range;
- (NSObject*)firstObjectCommonWithArray:(NSArray*)array;
- (NSArray*)arrayByAddingObject:(NSObject*)obj;
- (NSArray*)arrayByAddingObjectsFromArray:(NSArray*)arr;
- (NSArray*)pathsMatchingExtensions:(NSArray*)extensions;
- (NSUInteger)indexOfObject:(NSObject*)obj inSortedRange:(NSRange)range options:(int)options usingComparator:(id)comparator;
- (void)dealloc;
- (BOOL)writeToFile:(NSString*)file atomically:(BOOL)atomically;
- (NSObject*)encodeWithCoder:(NSCoder*)coder;
- (NSString*)description;
- (void)getObjects:(id*)objects;
- (void)enumerateObjectsUsingBlock:(id)block;
- (void)enumerateObjectsWithOptions:(NSUInteger)options usingBlock:(id)block;
- (void)getObjects:(id*)objects range:(NSRange)range;
- (BOOL)isEqual:(NSObject*)other;
- (NSArray*)allObjects;
- (BOOL)isEqualToArray:(NSArray*)otherArray;
- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(DWORD)maxCount;
+ (NSArray*)arrayWithObjects:(NSObject*)first, ...;
+ (NSArray*)arrayWithObject:(NSObject*)obj;
+ (NSArray*)array;
+ (NSArray*)arrayWithObjects:(NSObject**)objs count:(NSUInteger)count;
+ (NSArray*)arrayWithArray:(NSArray*)arrayToCopy;
+ (NSArray*)arrayWithContentsOfFile:(NSString*)filename;
+ (NSObject*)allocWithZone:(NSZone*)zone;
@end
#endif
