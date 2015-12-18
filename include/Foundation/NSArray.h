/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Copyright (c) 2015 Microsoft Corporation. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSARRAY_H_
#define _NSARRAY_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>
#import <Foundation/NSEnumerator.h>
#import <Foundation/NSObjCRuntime.h>
#import <CoreFoundation/CFArray.h>

enum {
    NSBinarySearchingFirstEqual = 1 << 8,
    NSBinarySearchingLastEqual = 1 << 9,
    NSBinarySearchingInsertionIndex = 1 << 10,
};
typedef uint32_t NSBinarySearchingOptions;

@class NSString, NSDictionary, NSPredicate, NSIndexSet, NSURL;
#define __CFARRAY_SIZE_BYTES (0x30)

FOUNDATION_EXPORT_CLASS
@interface NSArray : NSObject <NSCopying, NSMutableCopying, NSSecureCoding, NSFastEnumeration> {
@public
    CFArrayRef arr;
    uint32_t _arraySpace[((__CFARRAY_SIZE_BYTES + 3) & ~3) / 4];
}

- initWithArray:(NSArray*)array;
- initWithArray:(NSArray*)array copyItems:(BOOL)copyItems;
- initWithContentsOfFile:(NSString*)path;
- initWithContentsOfURL:(NSURL*)url;
- initWithObjects:(id*)objects count:(NSUInteger)count;
- initWithObjects:object, ...;

+ array;
+ arrayWithContentsOfFile:(NSString*)path;
+ arrayWithContentsOfURL:(NSURL*)url;
+ arrayWithObject:object;
+ arrayWithObjects:object, ...;

+ arrayWithArray:(NSArray*)array;
+ arrayWithObjects:(id*)objects count:(NSUInteger)count;

- (NSUInteger)count;
- objectAtIndex:(NSUInteger)index;

- (void)getObjects:(id __unsafe_unretained[])objects;
- (void)getObjects:(id*)aBuffer range:(NSRange)aRange;

- (id)objectAtIndex:(NSUInteger)index;
- (id)objectAtIndexedSubscript:(NSUInteger)idx;
- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes;

- (NSArray*)subarrayWithRange:(NSRange)range;

- (BOOL)isEqualToArray:(NSArray*)array;

- (NSUInteger)indexOfObject:object;
- (NSUInteger)indexOfObject:object inRange:(NSRange)range;

- (NSUInteger)indexOfObjectIdenticalTo:object;
- (NSUInteger)indexOfObjectIdenticalTo:object inRange:(NSRange)range;

- (NSEnumerator*)objectEnumerator;
- (NSEnumerator*)reverseObjectEnumerator;

- (NSArray*)arrayByAddingObject:object;
- (NSArray*)arrayByAddingObjectsFromArray:(NSArray*)array;
- (NSString*)componentsJoinedByString:(NSString*)string;

- (BOOL)containsObject:object;

- firstObjectCommonWithArray:(NSArray*)array;

- (id)firstObject;
- (id)lastObject;

- (NSArray*)sortedArrayUsingSelector:(SEL)selector;
- (NSArray*)sortedArrayUsingFunction:(int (*)(id, id, void*))function context:(void*)context;

- (BOOL)writeToFile:(NSString*)path atomically:(BOOL)atomically;
- (BOOL)writeToURL:(NSURL*)aURL atomically:(BOOL)atomically;

- (void)makeObjectsPerformSelector:(SEL)selector;
- (void)makeObjectsPerformSelector:(SEL)selector withObject:object;

- (NSString*)descriptionWithLocale:(NSDictionary*)locale;
- (NSString*)descriptionWithLocale:(NSDictionary*)locale indent:(NSUInteger)indent;

- (NSArray*)sortedArrayUsingDescriptors:(NSArray*)descriptors;
- (NSArray*)filteredArrayUsingPredicate:(NSPredicate*)predicate;

- (void)enumerateObjectsUsingBlock:(void (^)(id obj, NSUInteger idx, BOOL* stop))block;
- (NSArray*)sortedArrayUsingComparator:(NSComparator)cmptr;
- (void)enumerateObjectsAtIndexes:(NSIndexSet*)range
                          options:(NSEnumerationOptions)opts
                       usingBlock:(void (^)(id object, NSUInteger index, BOOL* stop))block;

- (NSUInteger)indexOfObject:(id)obj inSortedRange:(NSRange)r options:(NSBinarySearchingOptions)opts usingComparator:(NSComparator)cmp;

// TODO: File bug
- (void)sortWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;

- (NSArray*)sortedArrayWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;

- (NSUInteger)indexOfObjectPassingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL* stop))predicate;
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(id obj, NSUInteger idx, BOOL* stop))block;
- (NSIndexSet*)indexesOfObjectsPassingTest:(BOOL (^)(id obj, NSUInteger idx, BOOL* stop))predicate;

@end

@interface NSArrayConcrete : NSArray
@end

#import <Foundation/NSMutableArray.h>

#endif /* _NSARRAY_H_ */
