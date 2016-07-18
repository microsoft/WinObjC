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
#import <CoreFoundation/CFDictionary.h>

@class NSString;
@class NSURL;
@class NSArray<ObjectType>;
@class NSEnumerator<ObjectType>;
@class NSSet<ObjectType>;
@class NSDate;
@class NSNumber;

FOUNDATION_EXPORT_CLASS
@interface NSDictionary <__covariant KeyType, __covariant ObjectType> : NSObject <NSCopying, NSFastEnumeration, NSMutableCopying, NSSecureCoding> {
@public
}

+ (instancetype)dictionary;
+ (instancetype)dictionaryWithContentsOfFile:(NSString*)path;
+ (instancetype)dictionaryWithContentsOfURL:(NSURL*)aURL;
+ (instancetype)dictionaryWithDictionary:(NSDictionary<KeyType, ObjectType>*)otherDictionary;
+ (instancetype)dictionaryWithObject:(ObjectType)anObject forKey:(id<NSCopying>)aKey;
+ (instancetype)dictionaryWithObjects:(NSArray*)objects forKeys:(NSArray<id<NSCopying>>*)keys;
+ (instancetype)dictionaryWithObjects:(const ObjectType _Nonnull[])objects
                              forKeys:(const id<NSCopying> _Nonnull[])keys
                                count:(NSUInteger)count;
+ (instancetype)dictionaryWithObjectsAndKeys:(ObjectType)firstObject, ...;
- (instancetype)initWithContentsOfFile:(NSString*)path;
- (instancetype)initWithContentsOfURL:(NSURL*)aURL;
- (instancetype)initWithDictionary:(NSDictionary<KeyType, ObjectType>*)otherDictionary;
- (instancetype)initWithDictionary:(NSDictionary<KeyType, ObjectType>*)otherDictionary copyItems:(BOOL)flag;
- (instancetype)initWithObjects:(NSArray<ObjectType>*)objects forKeys:(NSArray<id<NSCopying>>*)keys;
- (instancetype)initWithObjects:(const ObjectType _Nonnull[])objects forKeys:(const id<NSCopying> _Nonnull[])keys count:(NSUInteger)count;
- (instancetype)initWithObjectsAndKeys:(ObjectType)firstObject, ...;
+ (id)sharedKeySetForKeys:(NSArray<id<NSCopying>>*)keys STUB_METHOD;
@property (readonly) NSUInteger count;
- (BOOL)isEqualToDictionary:(NSDictionary<KeyType, ObjectType>*)otherDictionary;
@property (readonly, copy) NSArray<KeyType>* allKeys;
- (NSArray<KeyType>*)allKeysForObject:(ObjectType)anObject;
@property (readonly, copy) NSArray<ObjectType>* allValues;
- (void)getObjects:(ObjectType __unsafe_unretained _Nonnull[])objects andKeys:(KeyType __unsafe_unretained _Nonnull[])keys;
- (ObjectType)objectForKey:(KeyType)aKey;
- (ObjectType)objectForKeyedSubscript:(KeyType)key;
- (NSArray<ObjectType>*)objectsForKeys:(NSArray<KeyType>*)keys notFoundMarker:(ObjectType)anObject;
- (ObjectType)valueForKey:(NSString*)key;
- (NSEnumerator<KeyType>*)keyEnumerator;
- (NSEnumerator<ObjectType>*)objectEnumerator;
- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(KeyType, ObjectType, BOOL*))block;
- (void)enumerateKeysAndObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(KeyType, ObjectType, BOOL*))block;
- (NSArray<KeyType>*)keysSortedByValueUsingSelector:(SEL)comparator;
- (NSArray<KeyType>*)keysSortedByValueUsingComparator:(NSComparator)cmptr;
- (NSArray<KeyType>*)keysSortedByValueWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;
- (NSSet<KeyType>*)keysOfEntriesPassingTest:(BOOL (^)(KeyType, ObjectType, BOOL*))predicate STUB_METHOD;
- (NSSet<KeyType>*)keysOfEntriesWithOptions:(NSEnumerationOptions)opts
                                passingTest:(BOOL (^)(KeyType, ObjectType, BOOL*))predicate STUB_METHOD;
- (BOOL)writeToFile:(NSString*)path atomically:(BOOL)flag;
- (BOOL)writeToURL:(NSURL*)aURL atomically:(BOOL)flag STUB_METHOD;
@property (readonly, copy) NSString* description;
@property (readonly, copy) NSString* descriptionInStringsFileFormat;
- (NSString*)descriptionWithLocale:(id)locale STUB_METHOD;
- (NSString*)descriptionWithLocale:(id)locale indent:(NSUInteger)level STUB_METHOD;

/* NSFileManager Extensions */
- (NSDate*)fileCreationDate;
- (BOOL)fileExtensionHidden STUB_METHOD;
- (NSNumber*)fileGroupOwnerAccountID STUB_METHOD;
- (NSString*)fileGroupOwnerAccountName STUB_METHOD;
- (OSType)fileHFSCreatorCode STUB_METHOD;
- (OSType)fileHFSTypeCode STUB_METHOD;
- (BOOL)fileIsAppendOnly STUB_METHOD;
- (BOOL)fileIsImmutable STUB_METHOD;
- (NSDate*)fileModificationDate;
- (NSNumber*)fileOwnerAccountID STUB_METHOD;
- (NSString*)fileOwnerAccountName STUB_METHOD;
- (NSUInteger)filePosixPermissions STUB_METHOD;
- (unsigned long long)fileSize;
- (NSUInteger)fileSystemFileNumber STUB_METHOD;
- (NSInteger)fileSystemNumber STUB_METHOD;
- (NSString*)fileType;
@end

#define NSDictionaryOfVariableBindings(...) _NSDictionaryOfVariableBindings(@"" #__VA_ARGS__, __VA_ARGS__, nil)
FOUNDATION_EXPORT NSDictionary* _NSDictionaryOfVariableBindings(NSString* keys, ...);
