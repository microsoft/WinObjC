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
@class NSArray;
@class NSSet;
@class NSIndexSet;
@class NSEnumerator;
@class NSString;
@class NSPredicate;

FOUNDATION_EXPORT_CLASS
@interface NSOrderedSet : NSObject <NSCopying, NSFastEnumeration, NSMutableCopying, NSSecureCoding>
+ (instancetype)orderedSet STUB_METHOD;
+ (instancetype)orderedSetWithArray:(NSArray*)array STUB_METHOD;
+ (instancetype)orderedSetWithArray:(NSArray*)array range:(NSRange)range copyItems:(BOOL)flag STUB_METHOD;
+ (instancetype)orderedSetWithObject:(id)object STUB_METHOD;
+ (instancetype)orderedSetWithObjects:(id)firstObj STUB_METHOD;
+ (instancetype)orderedSetWithObjects:(id _Nonnull const[])objects count:(NSUInteger)cnt STUB_METHOD;
+ (instancetype)orderedSetWithOrderedSet:(NSOrderedSet*)set STUB_METHOD;
+ (instancetype)orderedSetWithOrderedSet:(NSOrderedSet*)set range:(NSRange)range copyItems:(BOOL)flag STUB_METHOD;
+ (instancetype)orderedSetWithSet:(NSSet*)set STUB_METHOD;
+ (instancetype)orderedSetWithSet:(NSSet*)set copyItems:(BOOL)flag STUB_METHOD;
- (instancetype)initWithArray:(NSArray*)array STUB_METHOD;
- (instancetype)initWithArray:(NSArray*)array copyItems:(BOOL)flag STUB_METHOD;
- (instancetype)initWithArray:(NSArray*)array range:(NSRange)range copyItems:(BOOL)flag STUB_METHOD;
- (instancetype)initWithObject:(id)object STUB_METHOD;
- (instancetype)initWithObjects:(id)firstObj STUB_METHOD;
- (instancetype)initWithObjects:(id _Nonnull const[])objects count:(NSUInteger)cnt STUB_METHOD;
- (instancetype)initWithOrderedSet:(NSOrderedSet*)set STUB_METHOD;
- (instancetype)initWithOrderedSet:(NSOrderedSet*)set copyItems:(BOOL)flag STUB_METHOD;
- (instancetype)initWithOrderedSet:(NSOrderedSet*)orderedSet range:(NSRange)range copyItems:(BOOL)flag STUB_METHOD;
- (instancetype)initWithSet:(NSSet*)set STUB_METHOD;
- (instancetype)initWithSet:(NSSet*)set copyItems:(BOOL)flag STUB_METHOD;
- (instancetype)init STUB_METHOD;
@property (readonly) NSUInteger count STUB_PROPERTY;
- (BOOL)containsObject:(id)object STUB_METHOD;
- (void)enumerateObjectsAtIndexes:(NSIndexSet*)indexSet
                          options:(NSEnumerationOptions)opts
                       usingBlock:(void (^)(id, NSUInteger, BOOL*))block STUB_METHOD;
- (void)enumerateObjectsUsingBlock:(void (^)(id, NSUInteger, BOOL*))block STUB_METHOD;
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(id, NSUInteger, BOOL*))block STUB_METHOD;
@property (readonly, nonatomic) id firstObject STUB_PROPERTY;
@property (readonly, nonatomic) id lastObject STUB_PROPERTY;
- (id)objectAtIndex:(NSUInteger)index STUB_METHOD;
- (id)objectAtIndexedSubscript:(NSUInteger)index STUB_METHOD;
- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes STUB_METHOD;
- (NSUInteger)indexOfObject:(id)object STUB_METHOD;
- (NSUInteger)indexOfObject:(id)object
              inSortedRange:(NSRange)range
                    options:(NSBinarySearchingOptions)opts
            usingComparator:(NSComparator)cmp STUB_METHOD;
- (NSUInteger)indexOfObjectAtIndexes:(NSIndexSet*)indexSet
                             options:(NSEnumerationOptions)opts
                         passingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSUInteger)indexOfObjectPassingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSUInteger)indexOfObjectWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSIndexSet*)indexesOfObjectsAtIndexes:(NSIndexSet*)indexSet
                                 options:(NSEnumerationOptions)opts
                             passingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSIndexSet*)indexesOfObjectsPassingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSIndexSet*)indexesOfObjectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id, NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSEnumerator*)objectEnumerator STUB_METHOD;
- (NSEnumerator*)reverseObjectEnumerator STUB_METHOD;
@property (readonly, copy) NSOrderedSet* reversedOrderedSet STUB_PROPERTY;
- (void)getObjects:(id __unsafe_unretained _Nonnull[])objects range:(NSRange)range STUB_METHOD;
- (void)setValue:(id)value forKey:(NSString*)key STUB_METHOD;
- (id)valueForKey:(NSString*)key STUB_METHOD;
- (void)addObserver:(NSObject*)observer
         forKeyPath:(NSString*)keyPath
            options:(NSKeyValueObservingOptions)options
            context:(void*)context STUB_METHOD;
- (void)removeObserver:(NSObject*)observer forKeyPath:(NSString*)keyPath STUB_METHOD;
- (void)removeObserver:(NSObject*)observer forKeyPath:(NSString*)keyPath context:(void*)context STUB_METHOD;
- (BOOL)isEqualToOrderedSet:(NSOrderedSet*)other STUB_METHOD;
- (BOOL)intersectsOrderedSet:(NSOrderedSet*)other STUB_METHOD;
- (BOOL)intersectsSet:(NSSet*)set STUB_METHOD;
- (BOOL)isSubsetOfOrderedSet:(NSOrderedSet*)other STUB_METHOD;
- (BOOL)isSubsetOfSet:(NSSet*)set STUB_METHOD;
- (NSArray*)sortedArrayUsingDescriptors:(NSArray*)sortDescriptors STUB_METHOD;
- (NSArray*)sortedArrayUsingComparator:(NSComparator)cmptr STUB_METHOD;
- (NSArray*)sortedArrayWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr STUB_METHOD;
- (NSOrderedSet*)filteredOrderedSetUsingPredicate:(NSPredicate*)predicate STUB_METHOD;
@property (readonly, copy) NSString* description STUB_PROPERTY;
- (NSString*)descriptionWithLocale:(id)locale STUB_METHOD;
- (NSString*)descriptionWithLocale:(id)locale indent:(NSUInteger)level STUB_METHOD;
@property (readonly, strong) NSArray* array STUB_PROPERTY;
@property (readonly, strong) NSSet* set STUB_PROPERTY;
@end
