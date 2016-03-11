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
+ (instancetype)orderedSet STUB_METHOD;
+ (instancetype)orderedSetWithArray:(NSArray<ObjectType>*)array STUB_METHOD;
+ (instancetype)orderedSetWithArray:(NSArray<ObjectType>*)array range:(NSRange)range copyItems:(BOOL)flag STUB_METHOD;
+ (instancetype)orderedSetWithObject:(ObjectType)object STUB_METHOD;
+ (instancetype)orderedSetWithObjects:(ObjectType)firstObj STUB_METHOD;
+ (instancetype)orderedSetWithObjects:(const ObjectType _Nonnull[])objects count:(NSUInteger)cnt STUB_METHOD;
+ (instancetype)orderedSetWithOrderedSet:(NSOrderedSet<ObjectType>*)set STUB_METHOD;
+ (instancetype)orderedSetWithOrderedSet:(NSOrderedSet<ObjectType>*)set range:(NSRange)range copyItems:(BOOL)flag STUB_METHOD;
+ (instancetype)orderedSetWithSet:(NSSet<ObjectType>*)set STUB_METHOD;
+ (instancetype)orderedSetWithSet:(NSSet<ObjectType>*)set copyItems:(BOOL)flag STUB_METHOD;
- (instancetype)initWithArray:(NSArray<ObjectType>*)array STUB_METHOD;
- (instancetype)initWithArray:(NSArray<ObjectType>*)array copyItems:(BOOL)flag STUB_METHOD;
- (instancetype)initWithArray:(NSArray<ObjectType>*)array range:(NSRange)range copyItems:(BOOL)flag STUB_METHOD;
- (instancetype)initWithObject:(ObjectType)object STUB_METHOD;
- (instancetype)initWithObjects:(ObjectType)firstObj STUB_METHOD;
- (instancetype)initWithObjects:(const ObjectType _Nonnull[])objects count:(NSUInteger)cnt STUB_METHOD;
- (instancetype)initWithOrderedSet:(NSOrderedSet<ObjectType>*)set STUB_METHOD;
- (instancetype)initWithOrderedSet:(NSOrderedSet<ObjectType>*)set copyItems:(BOOL)flag STUB_METHOD;
- (instancetype)initWithOrderedSet:(NSOrderedSet<ObjectType>*)orderedSet range:(NSRange)range copyItems:(BOOL)flag STUB_METHOD;
- (instancetype)initWithSet:(NSSet<ObjectType>*)set STUB_METHOD;
- (instancetype)initWithSet:(NSSet<ObjectType>*)set copyItems:(BOOL)flag STUB_METHOD;
- (instancetype)init STUB_METHOD;
@property (readonly) NSUInteger count STUB_PROPERTY;
- (BOOL)containsObject:(ObjectType)object STUB_METHOD;
- (void)enumerateObjectsAtIndexes:(NSIndexSet*)indexSet
                          options:(NSEnumerationOptions)opts
                       usingBlock:(void (^)(ObjectType, NSUInteger, BOOL*))block STUB_METHOD;
- (void)enumerateObjectsUsingBlock:(void (^)(ObjectType, NSUInteger, BOOL*))block STUB_METHOD;
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(ObjectType, NSUInteger, BOOL*))block STUB_METHOD;
@property (readonly, nonatomic) ObjectType firstObject STUB_PROPERTY;
@property (readonly, nonatomic) ObjectType lastObject STUB_PROPERTY;
- (ObjectType)objectAtIndex:(NSUInteger)index STUB_METHOD;
- (ObjectType)objectAtIndexedSubscript:(NSUInteger)index STUB_METHOD;
- (NSArray<ObjectType>*)objectsAtIndexes:(NSIndexSet*)indexes STUB_METHOD;
- (NSUInteger)indexOfObject:(ObjectType)object STUB_METHOD;
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
- (NSEnumerator<ObjectType>*)objectEnumerator STUB_METHOD;
- (NSEnumerator<ObjectType>*)reverseObjectEnumerator STUB_METHOD;
@property (readonly, copy) NSOrderedSet<ObjectType>* reversedOrderedSet STUB_PROPERTY;
- (void)getObjects:(ObjectType __unsafe_unretained _Nonnull[])objects range:(NSRange)range STUB_METHOD;
- (void)setValue:(id)value forKey:(NSString*)key STUB_METHOD;
- (id)valueForKey:(NSString*)key STUB_METHOD;
- (void)addObserver:(NSObject*)observer
         forKeyPath:(NSString*)keyPath
            options:(NSKeyValueObservingOptions)options
            context:(void*)context STUB_METHOD;
- (void)removeObserver:(NSObject*)observer forKeyPath:(NSString*)keyPath STUB_METHOD;
- (void)removeObserver:(NSObject*)observer forKeyPath:(NSString*)keyPath context:(void*)context STUB_METHOD;
- (BOOL)isEqualToOrderedSet:(NSOrderedSet<ObjectType>*)other STUB_METHOD;
- (BOOL)intersectsOrderedSet:(NSOrderedSet<ObjectType>*)other STUB_METHOD;
- (BOOL)intersectsSet:(NSSet<ObjectType>*)set STUB_METHOD;
- (BOOL)isSubsetOfOrderedSet:(NSOrderedSet<ObjectType>*)other STUB_METHOD;
- (BOOL)isSubsetOfSet:(NSSet<ObjectType>*)set STUB_METHOD;
- (NSArray<ObjectType>*)sortedArrayUsingDescriptors:(NSArray<NSSortDescriptor*>*)sortDescriptors STUB_METHOD;
- (NSArray<ObjectType>*)sortedArrayUsingComparator:(NSComparator)cmptr STUB_METHOD;
- (NSArray<ObjectType>*)sortedArrayWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr STUB_METHOD;
- (NSOrderedSet<ObjectType>*)filteredOrderedSetUsingPredicate:(NSPredicate*)predicate STUB_METHOD;
@property (readonly, copy) NSString* description STUB_PROPERTY;
- (NSString*)descriptionWithLocale:(id)locale STUB_METHOD;
- (NSString*)descriptionWithLocale:(id)locale indent:(NSUInteger)level STUB_METHOD;
@property (readonly, strong) NSArray<ObjectType>* array STUB_PROPERTY;
@property (readonly, strong) NSSet<ObjectType>* set STUB_PROPERTY;
@end
