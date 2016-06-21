//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
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
#import <Foundation/NSKeyValueObserving.h>
#import <Foundation/NSMutableDictionary.h>

@class NSArray<ObjectType>;
@class NSPredicate;
@class NSEnumerator<ObjectType>;
@class NSString;
@class NSSortDescriptor;

FOUNDATION_EXPORT_CLASS
@interface NSSet <__covariant ObjectType> : NSObject <NSCopying, NSFastEnumeration, NSMutableCopying, NSSecureCoding> {
}
+ (instancetype)set;
+ (instancetype)setWithArray:(NSArray<ObjectType>*)array;
+ (instancetype)setWithObject:(ObjectType)object;
+ (instancetype)setWithObjects:(ObjectType)firstObj, ...;
+ (instancetype)setWithObjects:(const ObjectType _Nonnull[])objects count:(NSUInteger)cnt;
+ (instancetype)setWithSet:(NSSet<ObjectType>*)set;
- (NSSet*)setByAddingObject:(ObjectType)anObject;
- (NSSet*)setByAddingObjectsFromSet:(NSSet<ObjectType>*)other;
- (NSSet*)setByAddingObjectsFromArray:(NSArray<ObjectType>*)other STUB_METHOD;
- (instancetype)initWithArray:(NSArray<ObjectType>*)array;
- (instancetype)initWithObjects:(ObjectType)firstObj, ...;
- (instancetype)initWithObjects:(const ObjectType _Nonnull[])objects count:(NSUInteger)cnt;
- (instancetype)initWithSet:(NSSet<ObjectType>*)set;
- (instancetype)initWithSet:(NSSet<ObjectType>*)set copyItems:(BOOL)flag;
@property (readonly) NSUInteger count;
@property (readonly, copy) NSArray<ObjectType>* allObjects;
- (ObjectType)anyObject;
- (BOOL)containsObject:(ObjectType)anObject;
- (NSSet<ObjectType>*)filteredSetUsingPredicate:(NSPredicate*)predicate STUB_METHOD;
- (void)makeObjectsPerformSelector:(SEL)aSelector;
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument STUB_METHOD;
- (ObjectType)member:(ObjectType)object;
- (NSEnumerator<ObjectType>*)objectEnumerator;
- (void)enumerateObjectsUsingBlock:(void (^)(ObjectType, BOOL*))block;
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(ObjectType, BOOL*))block;
- (NSSet<ObjectType>*)objectsPassingTest:(BOOL (^)(ObjectType, BOOL*))predicate STUB_METHOD;
- (NSSet<ObjectType>*)objectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(ObjectType, BOOL*))predicate STUB_METHOD;
- (BOOL)isSubsetOfSet:(NSSet<ObjectType>*)otherSet;
- (BOOL)intersectsSet:(NSSet<ObjectType>*)otherSet;
- (BOOL)isEqualToSet:(NSSet<ObjectType>*)otherSet;
- (id)valueForKey:(NSString*)key STUB_METHOD;
- (void)setValue:(id)value forKey:(NSString*)key STUB_METHOD;
- (NSArray<ObjectType>*)sortedArrayUsingDescriptors:(NSArray<NSSortDescriptor*>*)sortDescriptors;
@property (readonly, copy) NSString* description;
- (NSString*)descriptionWithLocale:(id)locale STUB_METHOD;
@end
