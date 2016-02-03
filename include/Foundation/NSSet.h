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
#import <Foundation/NSCopying.h>
#import <Foundation/NSFastEnumeration.h>
#import <Foundation/NSMutableCopying.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSecureCoding.h>
#import <Foundation/NSKeyValueObserving.h>
#import <Foundation/NSMutableDictionary.h>

@class NSArray;
@class NSPredicate;
@class NSEnumerator;
@class NSString;

struct NSSetTable {
    CFMutableDictionaryRef dict;
};

FOUNDATION_EXPORT_CLASS
@interface NSSet : NSObject <NSCopying, NSFastEnumeration, NSMutableCopying, NSSecureCoding> {
@public
    struct NSSetTable _table;
}

+ (instancetype)set;
+ (instancetype)setWithArray:(NSArray*)array;
+ (instancetype)setWithObject:(id)object;
+ (instancetype)setWithObjects:(id)firstObj, ...;
+ (instancetype)setWithObjects:(id _Nonnull const[])objects count:(NSUInteger)cnt;
+ (instancetype)setWithSet:(NSSet*)set;
- (NSSet*)setByAddingObject:(id)anObject;
- (NSSet*)setByAddingObjectsFromSet:(NSSet*)other;
- (NSSet*)setByAddingObjectsFromArray:(NSArray*)other STUB_METHOD;
- (instancetype)initWithArray:(NSArray*)array;
- (instancetype)initWithObjects:(id)firstObj, ...;
- (instancetype)initWithObjects:(id _Nonnull const[])objects count:(NSUInteger)cnt;
- (instancetype)initWithSet:(NSSet*)set;
- (instancetype)initWithSet:(NSSet*)set copyItems:(BOOL)flag STUB_METHOD;
- (instancetype)init;
@property (readonly) NSUInteger count;
@property (readonly, copy) NSArray* allObjects;
- (id)anyObject;
- (BOOL)containsObject:(id)anObject;
- (NSSet*)filteredSetUsingPredicate:(NSPredicate*)predicate STUB_METHOD;
- (void)makeObjectsPerformSelector:(SEL)aSelector;
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(id)argument STUB_METHOD;
- (id)member:(id)object;
- (NSEnumerator*)objectEnumerator;
- (void)enumerateObjectsUsingBlock:(void (^)(id, BOOL*))block;
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(id, BOOL*))block;
- (NSSet*)objectsPassingTest:(BOOL (^)(id, BOOL*))predicate STUB_METHOD;
- (NSSet*)objectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id, BOOL*))predicate STUB_METHOD;
- (BOOL)isSubsetOfSet:(NSSet*)otherSet;
- (BOOL)intersectsSet:(NSSet*)otherSet;
- (BOOL)isEqualToSet:(NSSet*)otherSet;
- (id)valueForKey:(NSString*)key STUB_METHOD;
- (void)setValue:(id)value forKey:(NSString*)key STUB_METHOD;
- (NSArray*)sortedArrayUsingDescriptors:(NSArray*)sortDescriptors;
@property (readonly, copy) NSString* description;
- (NSString*)descriptionWithLocale:(id)locale STUB_METHOD;
@end
