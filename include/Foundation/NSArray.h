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
@class NSEnumerator<ObjectType>;
@class NSPredicate;
@class NSData;
@class NSSortDescriptor;

typedef NSUInteger NSBinarySearchingOptions;
enum {
    NSBinarySearchingFirstEqual = (1 << 8),
    NSBinarySearchingLastEqual = (1 << 9),
    NSBinarySearchingInsertionIndex = (1 << 10),
};

FOUNDATION_EXPORT_CLASS
@interface NSArray <__covariant ObjectType> : NSObject <NSCopying, NSFastEnumeration, NSMutableCopying, NSSecureCoding>{
}
+ (instancetype)array;
+ (instancetype)arrayWithArray:(NSArray<ObjectType>*)anArray;
+ (instancetype)arrayWithContentsOfFile:(NSString*)aPath;
+ (instancetype)arrayWithContentsOfURL:(NSURL*)aURL STUB_METHOD;
+ (instancetype)arrayWithObject:(ObjectType)anObject;
+ (instancetype)arrayWithObjects:(ObjectType)firstObj, ...;
+ (instancetype)arrayWithObjects:(const ObjectType _Nonnull[])objects count:(NSUInteger)count;
- (instancetype)initWithArray:(NSArray<ObjectType>*)anArray;
- (instancetype)initWithArray:(NSArray<ObjectType>*)array copyItems:(BOOL)flag;
- (instancetype)initWithContentsOfFile:(NSString*)aPath;
- (instancetype)initWithContentsOfURL:(NSURL*)aURL STUB_METHOD;
- (instancetype)initWithObjects:(ObjectType)firstObj, ...;
- (instancetype)initWithObjects:(const ObjectType _Nonnull[])objects count:(NSUInteger)count;
- (BOOL)containsObject:(ObjectType)anObject;
@property (readonly) NSUInteger count;
- (void)getObjects:(ObjectType __unsafe_unretained _Nonnull[])aBuffer;
- (void)getObjects:(ObjectType __unsafe_unretained _Nonnull[])aBuffer range:(NSRange)aRange;
@property (readonly, nonatomic) ObjectType firstObject;
@property (readonly, nonatomic) ObjectType lastObject;
- (ObjectType)objectAtIndex:(NSUInteger)index;
- (ObjectType)objectAtIndexedSubscript:(NSUInteger)idx;
- (NSArray<ObjectType>*)objectsAtIndexes:(NSIndexSet*)indexes;
- (NSEnumerator<ObjectType>*)objectEnumerator;
- (NSEnumerator<ObjectType>*)reverseObjectEnumerator;
- (NSUInteger)indexOfObject:(ObjectType)anObject;
- (NSUInteger)indexOfObject:(ObjectType)anObject inRange:(NSRange)range;
- (NSUInteger)indexOfObjectIdenticalTo:(ObjectType)anObject;
- (NSUInteger)indexOfObjectIdenticalTo:(ObjectType)anObject inRange:(NSRange)range STUB_METHOD;
- (NSUInteger)indexOfObjectPassingTest:(BOOL (^)(ObjectType, NSUInteger, BOOL*))predicate;
- (NSUInteger)indexOfObjectWithOptions:(NSEnumerationOptions)opts
                           passingTest:(BOOL (^)(ObjectType, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSUInteger)indexOfObjectAtIndexes:(NSIndexSet*)indexSet
                             options:(NSEnumerationOptions)opts
                         passingTest:(BOOL (^)(ObjectType, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSIndexSet*)indexesOfObjectsPassingTest:(BOOL (^)(ObjectType, NSUInteger, BOOL*))predicate;
- (NSIndexSet*)indexesOfObjectsWithOptions:(NSEnumerationOptions)opts
                               passingTest:(BOOL (^)(ObjectType, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSIndexSet*)indexesOfObjectsAtIndexes:(NSIndexSet*)indexSet
                                 options:(NSEnumerationOptions)opts
                             passingTest:(BOOL (^)(ObjectType, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSUInteger)indexOfObject:(ObjectType)obj
              inSortedRange:(NSRange)r
                    options:(NSBinarySearchingOptions)opts
            usingComparator:(NSComparator)cmp;
- (void)makeObjectsPerformSelector:(SEL)aSelector;
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)anObject;
- (void)enumerateObjectsUsingBlock:(void (^)(ObjectType, NSUInteger, BOOL*))block;
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(ObjectType, NSUInteger, BOOL*))block;
- (void)enumerateObjectsAtIndexes:(NSIndexSet*)indexSet
                          options:(NSEnumerationOptions)opts
                       usingBlock:(void (^)(ObjectType, NSUInteger, BOOL*))block STUB_METHOD;
- (ObjectType)firstObjectCommonWithArray:(NSArray<ObjectType>*)otherArray;
- (BOOL)isEqualToArray:(NSArray<ObjectType>*)otherArray;
- (NSArray<ObjectType>*)arrayByAddingObject:(ObjectType)anObject;
- (NSArray<ObjectType>*)arrayByAddingObjectsFromArray:(NSArray<ObjectType>*)otherArray;
- (NSArray<ObjectType>*)filteredArrayUsingPredicate:(NSPredicate*)predicate;
- (NSArray<ObjectType>*)subarrayWithRange:(NSRange)range;
@property (readonly, copy) NSData* sortedArrayHint;
- (NSArray<ObjectType>*)sortedArrayUsingFunction:(NSInteger (*)(ObjectType, ObjectType, void*))comparator context:(void*)context;
- (NSArray<ObjectType>*)sortedArrayUsingFunction:(NSInteger (*)(ObjectType, ObjectType, void*))comparator
                                         context:(void*)context
                                            hint:(NSData*)hint;
- (NSArray<ObjectType>*)sortedArrayUsingDescriptors:(NSArray<NSSortDescriptor*>*)sortDescriptors;
- (NSArray<ObjectType>*)sortedArrayUsingSelector:(SEL)comparator;
- (NSArray<ObjectType>*)sortedArrayUsingComparator:(NSComparator)cmptr;
- (NSArray<ObjectType>*)sortedArrayWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;
- (NSString*)componentsJoinedByString:(NSString*)separator;
@property (readonly, copy) NSString* description;
- (NSString*)descriptionWithLocale:(id)locale STUB_METHOD;
- (NSString*)descriptionWithLocale:(id)locale indent:(NSUInteger)level STUB_METHOD;
- (BOOL)writeToFile:(NSString*)path atomically:(BOOL)flag;
- (BOOL)writeToURL:(NSURL*)aURL atomically:(BOOL)flag STUB_METHOD;
- (NSArray<NSString*>*)pathsMatchingExtensions:(NSArray<NSString*>*)filterTypes;
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
