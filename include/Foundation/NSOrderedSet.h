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
#import <Foundation/NSKeyValueObserving.h>

@class NSArray<ObjectType>;
@class NSSet<ObjectType>;
@class NSIndexSet;
@class NSEnumerator<ObjectType>;
@class NSString;
@class NSPredicate;
@class NSSortDescriptor;

FOUNDATION_EXPORT_CLASS
@interface NSOrderedSet <__covariant ObjectType> : NSObject <NSCopying, NSFastEnumeration, NSMutableCopying, NSSecureCoding>
+ (instancetype)orderedSet;
+ (instancetype)orderedSetWithArray:(NSArray<ObjectType>*)array;
+ (instancetype)orderedSetWithArray:(NSArray<ObjectType>*)array range:(NSRange)range copyItems:(BOOL)flag;
+ (instancetype)orderedSetWithObject:(ObjectType)object;
+ (instancetype)orderedSetWithObjects:(ObjectType)firstObj, ...;
+ (instancetype)orderedSetWithObjects:(const ObjectType _Nonnull[])objects count:(NSUInteger)cnt;
+ (instancetype)orderedSetWithOrderedSet:(NSOrderedSet<ObjectType>*)set;
+ (instancetype)orderedSetWithOrderedSet:(NSOrderedSet<ObjectType>*)set range:(NSRange)range copyItems:(BOOL)flag;
+ (instancetype)orderedSetWithSet:(NSSet<ObjectType>*)set;
+ (instancetype)orderedSetWithSet:(NSSet<ObjectType>*)set copyItems:(BOOL)flag;
- (instancetype)initWithArray:(NSArray<ObjectType>*)array;
- (instancetype)initWithArray:(NSArray<ObjectType>*)array copyItems:(BOOL)flag;
- (instancetype)initWithArray:(NSArray<ObjectType>*)array range:(NSRange)range copyItems:(BOOL)flag;
- (instancetype)initWithObject:(ObjectType)object;
- (instancetype)initWithObjects:(ObjectType)firstObj, ...;
- (instancetype)initWithObjects:(const ObjectType _Nonnull[])objects count:(NSUInteger)cnt;
- (instancetype)initWithOrderedSet:(NSOrderedSet<ObjectType>*)set;
- (instancetype)initWithOrderedSet:(NSOrderedSet<ObjectType>*)set copyItems:(BOOL)flag;
- (instancetype)initWithOrderedSet:(NSOrderedSet<ObjectType>*)orderedSet range:(NSRange)range copyItems:(BOOL)flag;
- (instancetype)initWithSet:(NSSet<ObjectType>*)set;
- (instancetype)initWithSet:(NSSet<ObjectType>*)set copyItems:(BOOL)flag;
- (instancetype)init;
@property (readonly) NSUInteger count;
- (BOOL)containsObject:(ObjectType)object;
- (void)enumerateObjectsAtIndexes:(NSIndexSet*)indexSet
                          options:(NSEnumerationOptions)opts
                       usingBlock:(void (^)(ObjectType, NSUInteger, BOOL*))block;
- (void)enumerateObjectsUsingBlock:(void (^)(ObjectType, NSUInteger, BOOL*))block;
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(ObjectType, NSUInteger, BOOL*))block;
@property (readonly, nonatomic) ObjectType firstObject;
@property (readonly, nonatomic) ObjectType lastObject;
- (ObjectType)objectAtIndex:(NSUInteger)index;
- (ObjectType)objectAtIndexedSubscript:(NSUInteger)index;
- (NSArray<ObjectType>*)objectsAtIndexes:(NSIndexSet*)indexes;
- (NSUInteger)indexOfObject:(ObjectType)object;
- (NSUInteger)indexOfObject:(ObjectType)object
              inSortedRange:(NSRange)range
                    options:(NSBinarySearchingOptions)opts
            usingComparator:(NSComparator)cmp STUB_METHOD;
- (NSUInteger)indexOfObjectAtIndexes:(NSIndexSet*)indexSet
                             options:(NSEnumerationOptions)opts
                         passingTest:(BOOL (^)(ObjectType, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSUInteger)indexOfObjectPassingTest:(BOOL (^)(ObjectType, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSUInteger)indexOfObjectWithOptions:(NSEnumerationOptions)opts
                           passingTest:(BOOL (^)(ObjectType, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSIndexSet*)indexesOfObjectsAtIndexes:(NSIndexSet*)indexSet
                                 options:(NSEnumerationOptions)opts
                             passingTest:(BOOL (^)(ObjectType, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSIndexSet*)indexesOfObjectsPassingTest:(BOOL (^)(ObjectType, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSIndexSet*)indexesOfObjectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSEnumerator<ObjectType>*)objectEnumerator;
- (NSEnumerator<ObjectType>*)reverseObjectEnumerator;
@property (readonly, copy) NSOrderedSet<ObjectType>* reversedOrderedSet STUB_PROPERTY;
- (void)getObjects:(ObjectType __unsafe_unretained _Nonnull[])objects range:(NSRange)range;
- (void)setValue:(id)value forKey:(NSString*)key STUB_METHOD;
- (id)valueForKey:(NSString*)key STUB_METHOD;
- (void)addObserver:(NSObject*)observer
         forKeyPath:(NSString*)keyPath
            options:(NSKeyValueObservingOptions)options
            context:(void*)context STUB_METHOD;
- (void)removeObserver:(NSObject*)observer forKeyPath:(NSString*)keyPath STUB_METHOD;
- (void)removeObserver:(NSObject*)observer forKeyPath:(NSString*)keyPath context:(void*)context STUB_METHOD;
- (BOOL)isEqualToOrderedSet:(NSOrderedSet<ObjectType>*)other;
- (BOOL)intersectsOrderedSet:(NSOrderedSet<ObjectType>*)other;
- (BOOL)intersectsSet:(NSSet<ObjectType>*)set;
- (BOOL)isSubsetOfOrderedSet:(NSOrderedSet<ObjectType>*)other;
- (BOOL)isSubsetOfSet:(NSSet<ObjectType>*)set;
- (NSArray<ObjectType>*)sortedArrayUsingDescriptors:(NSArray<NSSortDescriptor*>*)sortDescriptors;
- (NSArray<ObjectType>*)sortedArrayUsingComparator:(NSComparator)cmptr STUB_METHOD;
- (NSArray<ObjectType>*)sortedArrayWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr STUB_METHOD;
- (NSOrderedSet<ObjectType>*)filteredOrderedSetUsingPredicate:(NSPredicate*)predicate STUB_METHOD;
@property (readonly, copy) NSString* description STUB_PROPERTY;
- (NSString*)descriptionWithLocale:(id)locale STUB_METHOD;
- (NSString*)descriptionWithLocale:(id)locale indent:(NSUInteger)level STUB_METHOD;
@property (readonly, strong) NSArray<ObjectType>* array;
@property (readonly, strong) NSSet<ObjectType>* set;
@end
