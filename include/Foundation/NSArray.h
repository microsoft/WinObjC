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
#import <Foundation/NSRange.h>
#import <Foundation/NSFastEnumeration.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSKeyValueObserving.h>

@class NSString;
@class NSURL;
@class NSIndexSet;
@class NSEnumerator;
@class NSPredicate;
@class NSData;

typedef NSUInteger NSBinarySearchingOptions;
enum {
    NSBinarySearchingFirstEqual = (1 << 8),
    NSBinarySearchingLastEqual = (1 << 9),
    NSBinarySearchingInsertionIndex = (1 << 10),
};

FOUNDATION_EXPORT_CLASS
@interface NSArray : NSObject <NSCopying, NSFastEnumeration, NSMutableCopying, NSSecureCoding> {
}

+ (instancetype)array;
+ (instancetype)arrayWithArray:(NSArray*)anArray;
+ (NSArray*)arrayWithContentsOfFile:(NSString*)aPath;
+ (NSArray*)arrayWithContentsOfURL:(NSURL*)aURL STUB_METHOD;
+ (instancetype)arrayWithObject:(id)anObject;
+ (instancetype)arrayWithObjects:(id)firstObj, ...;
+ (instancetype)arrayWithObjects:(id _Nonnull const[])objects count:(NSUInteger)count;
- (instancetype)initWithArray:(NSArray*)anArray;
- (instancetype)initWithArray:(NSArray*)array copyItems:(BOOL)flag;
- (NSArray*)initWithContentsOfFile:(NSString*)aPath;
- (NSArray*)initWithContentsOfURL:(NSURL*)aURL STUB_METHOD;
- (instancetype)initWithObjects:(id)firstObj, ...;
- (instancetype)initWithObjects:(id _Nonnull const[])objects count:(NSUInteger)count;
- (BOOL)containsObject:(id)anObject;
@property (readonly) NSUInteger count;
- (void)getObjects:(id __unsafe_unretained _Nonnull[])aBuffer;
- (void)getObjects:(id __unsafe_unretained _Nonnull[])aBuffer range:(NSRange)aRange;
@property (readonly, nonatomic) id firstObject;
@property (readonly, nonatomic) id lastObject;
- (id)objectAtIndex:(NSUInteger)index;
- (id)objectAtIndexedSubscript:(NSUInteger)idx;
- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes;
- (NSEnumerator*)objectEnumerator;
- (NSEnumerator*)reverseObjectEnumerator;
- (NSUInteger)indexOfObject:(id)anObject;
- (NSUInteger)indexOfObject:(id)anObject inRange:(NSRange)range;
- (NSUInteger)indexOfObjectIdenticalTo:(id)anObject;
- (NSUInteger)indexOfObjectIdenticalTo:(id)anObject inRange:(NSRange)range STUB_METHOD;
- (NSUInteger)indexOfObjectPassingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate;
- (NSUInteger)indexOfObjectWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSUInteger)indexOfObjectAtIndexes:(NSIndexSet*)indexSet
                             options:(NSEnumerationOptions)opts
                         passingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSIndexSet*)indexesOfObjectsPassingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate;
- (NSIndexSet*)indexesOfObjectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSIndexSet*)indexesOfObjectsAtIndexes:(NSIndexSet*)indexSet
                                 options:(NSEnumerationOptions)opts
                             passingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSUInteger)indexOfObject:(id)obj inSortedRange:(NSRange)r options:(NSBinarySearchingOptions)opts usingComparator:(NSComparator)cmp;
- (void)makeObjectsPerformSelector:(SEL)aSelector;
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)anObject;
- (void)enumerateObjectsUsingBlock:(void (^)(id, NSUInteger, BOOL*))block;
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(id, NSUInteger, BOOL*))block;
- (void)enumerateObjectsAtIndexes:(NSIndexSet*)indexSet
                          options:(NSEnumerationOptions)opts
                       usingBlock:(void (^)(id, NSUInteger, BOOL*))block STUB_METHOD;
- (id)firstObjectCommonWithArray:(NSArray*)otherArray;
- (BOOL)isEqualToArray:(NSArray*)otherArray;
- (NSArray*)arrayByAddingObject:(id)anObject;
- (NSArray*)arrayByAddingObjectsFromArray:(NSArray*)otherArray;
- (NSArray*)filteredArrayUsingPredicate:(NSPredicate*)predicate;
- (NSArray*)subarrayWithRange:(NSRange)range;
@property (readonly, copy) NSData* sortedArrayHint;
- (NSArray*)sortedArrayUsingFunction:(NSInteger (*)(id, id, void*))comparator context:(void*)context;
- (NSArray*)sortedArrayUsingFunction:(NSInteger (*)(id, id, void*))comparator context:(void*)context hint:(NSData*)hint;
- (NSArray*)sortedArrayUsingDescriptors:(NSArray*)sortDescriptors;
- (NSArray*)sortedArrayUsingSelector:(SEL)comparator;
- (NSArray*)sortedArrayUsingComparator:(NSComparator)cmptr;
- (NSArray*)sortedArrayWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;
- (NSString*)componentsJoinedByString:(NSString*)separator;
@property (readonly, copy) NSString* description;
- (NSString*)descriptionWithLocale:(id)locale STUB_METHOD;
- (NSString*)descriptionWithLocale:(id)locale indent:(NSUInteger)level STUB_METHOD;
- (BOOL)writeToFile:(NSString*)path atomically:(BOOL)flag;
- (BOOL)writeToURL:(NSURL*)aURL atomically:(BOOL)flag STUB_METHOD;
- (NSArray*)pathsMatchingExtensions:(NSArray*)filterTypes;
- (void)removeObserver:(NSObject*)observer
  fromObjectsAtIndexes:(NSIndexSet*)indexes
            forKeyPath:(NSString*)keyPath
               context:(void*)context STUB_METHOD;
- (void)addObserver:(NSObject*)anObserver
 toObjectsAtIndexes:(NSIndexSet*)indexes
         forKeyPath:(NSString*)keyPath
            options:(NSKeyValueObservingOptions)options
            context:(void*)context STUB_METHOD;
- (void)removeObserver:(NSObject*)anObserver fromObjectsAtIndexes:(NSIndexSet*)indexes forKeyPath:(NSString*)keyPath STUB_METHOD;
- (void)setValue:(id)value forKey:(NSString*)key;
- (id)valueForKey:(NSString*)key;
@end
