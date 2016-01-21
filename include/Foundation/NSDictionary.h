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
@class NSArray;
@class NSEnumerator;
@class NSSet;
@class NSDate;
@class NSNumber;

FOUNDATION_EXPORT_CLASS
@interface NSDictionary : NSObject <NSCopying, NSFastEnumeration, NSMutableCopying, NSSecureCoding> {
@public
}

+ (instancetype)dictionary;
+ (NSDictionary*)dictionaryWithContentsOfFile:(NSString*)path;
+ (NSDictionary*)dictionaryWithContentsOfURL:(NSURL*)aURL;
+ (instancetype)dictionaryWithDictionary:(NSDictionary*)otherDictionary;
+ (instancetype)dictionaryWithObject:(id)anObject forKey:(id<NSCopying>)aKey;
+ (instancetype)dictionaryWithObjects:(NSArray*)objects forKeys:(NSArray*)keys;
+ (instancetype)dictionaryWithObjects:(id _Nonnull const[])objects forKeys:(id<NSCopying> _Nonnull const[])keys count:(NSUInteger)count;
+ (instancetype)dictionaryWithObjectsAndKeys:(id)firstObject, ...;
- (instancetype)init;
- (NSDictionary*)initWithContentsOfFile:(NSString*)path;
- (NSDictionary*)initWithContentsOfURL:(NSURL*)aURL;
- (instancetype)initWithDictionary:(NSDictionary*)otherDictionary;
- (instancetype)initWithDictionary:(NSDictionary*)otherDictionary copyItems:(BOOL)flag;
- (instancetype)initWithObjects:(NSArray*)objects forKeys:(NSArray*)keys;
- (instancetype)initWithObjects:(id _Nonnull const[])objects forKeys:(id<NSCopying> _Nonnull const[])keys count:(NSUInteger)count;
- (instancetype)initWithObjectsAndKeys:(id)firstObject, ...;
+ (id)sharedKeySetForKeys:(NSArray*)keys STUB_METHOD;
@property (readonly) NSUInteger count;
- (BOOL)isEqualToDictionary:(NSDictionary*)otherDictionary;
@property (readonly, copy) NSArray* allKeys;
- (NSArray*)allKeysForObject:(id)anObject;
@property (readonly, copy) NSArray* allValues;
- (void)getObjects:(id __unsafe_unretained _Nonnull[])objects andKeys:(id __unsafe_unretained _Nonnull[])keys;
- (id)objectForKey:(id)aKey;
- (id)objectForKeyedSubscript:(id)key;
- (NSArray*)objectsForKeys:(NSArray*)keys notFoundMarker:(id)anObject;
- (id)valueForKey:(NSString*)key;
- (NSEnumerator*)keyEnumerator;
- (NSEnumerator*)objectEnumerator;
- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(id, id, BOOL*))block;
- (void)enumerateKeysAndObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(id, id, BOOL*))block;
- (NSArray*)keysSortedByValueUsingSelector:(SEL)comparator;
- (NSArray*)keysSortedByValueUsingComparator:(NSComparator)cmptr;
- (NSArray*)keysSortedByValueWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr STUB_METHOD;
- (NSSet*)keysOfEntriesPassingTest:(BOOL (^)(id, id, BOOL*))predicate STUB_METHOD;
- (NSSet*)keysOfEntriesWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id, id, BOOL*))predicate STUB_METHOD;
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
