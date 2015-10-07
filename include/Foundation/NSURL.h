/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSURL_H_
#define _NSURL_H_

#import <Foundation/NSObject.h>

@class NSURLHandle;
@class NSNumber;
@class NSData;
@class NSArray;
@class NSDictionary;
@class NSError;

SB_EXPORT NSString * const NSURLFileScheme;

SB_EXPORT NSString * const NSURLAttributeModificationDateKey;
SB_EXPORT NSString * const NSURLContentAccessDateKey;
SB_EXPORT NSString * const NSURLContentModificationDateKey;
SB_EXPORT NSString * const NSURLCreationDateKey;
SB_EXPORT NSString * const NSURLCustomIconKey;
SB_EXPORT NSString * const NSURLEffectiveIconKey;
SB_EXPORT NSString * const NSURLFileResourceIdentifierKey;
SB_EXPORT NSString * const NSURLFileResourceTypeKey;
SB_EXPORT NSString * const NSURLFileSecurityKey;
SB_EXPORT NSString * const NSURLHasHiddenExtensionKey;
SB_EXPORT NSString * const NSURLIsDirectoryKey;
SB_EXPORT NSString * const NSURLIsExcludedFromBackupKey;
SB_EXPORT NSString * const NSURLIsExecutableKey;
SB_EXPORT NSString * const NSURLIsHiddenKey;
SB_EXPORT NSString * const NSURLIsMountTriggerKey;
SB_EXPORT NSString * const NSURLIsPackageKey;
SB_EXPORT NSString * const NSURLIsReadableKey;
SB_EXPORT NSString * const NSURLIsRegularFileKey;
SB_EXPORT NSString * const NSURLIsSymbolicLinkKey;
SB_EXPORT NSString * const NSURLIsSystemImmutableKey;
SB_EXPORT NSString * const NSURLIsUserImmutableKey;
SB_EXPORT NSString * const NSURLIsVolumeKey;
SB_EXPORT NSString * const NSURLIsWritableKey;
SB_EXPORT NSString * const NSURLLabelColorKey;
SB_EXPORT NSString * const NSURLLabelNumberKey;
SB_EXPORT NSString * const NSURLLinkCountKey;
SB_EXPORT NSString * const NSURLLocalizedLabelKey;
SB_EXPORT NSString * const NSURLLocalizedNameKey;
SB_EXPORT NSString * const NSURLLocalizedTypeDescriptionKey;
SB_EXPORT NSString * const NSURLNameKey;
SB_EXPORT NSString * const NSURLParentDirectoryURLKey;
SB_EXPORT NSString * const NSURLPathKey;
SB_EXPORT NSString * const NSURLPreferredIOBlockSizeKey;
SB_EXPORT NSString * const NSURLTypeIdentifierKey;
SB_EXPORT NSString * const NSURLVolumeIdentifierKey;
SB_EXPORT NSString * const NSURLVolumeURLKey;
SB_EXPORT NSString * const NSURLTotalFileAllocatedSizeKey;
SB_EXPORT NSString * const NSURLFileSizeKey;

struct EbrURL;

FOUNDATION_EXPORT_CLASS
@interface NSURL : NSObject <NSCopying, NSCoding>

- initWithScheme:(NSString *)scheme host:(NSString *)host path:(NSString *)path;
- initFileURLWithPath:(NSString *)path;
- initWithString:(NSString *)string;
- initWithString:(NSString *)string relativeToURL:(NSURL *)parent;

+ fileURLWithPath:(NSString *)path;
+ URLWithString:(NSString *)string;
+ URLWithString:(NSString *)string relativeToURL:(NSURL *)parent;
+ (id)fileURLWithPath:(NSString *)path isDirectory:(BOOL)isDir; 

- (NSString *)absoluteString;
- (NSString *)parameterString;
- propertyForKey:(NSString *)key;

- (NSString *)scheme;
- (NSString *)host;
- (NSString *)user;
- (NSString *)password;
- (NSString *)fragment;
- (NSString *)path;
- (NSNumber *)port;
- (NSString *)query;
- (NSString *)relativePath;
- (NSString *)relativeString;
- (NSString *)resourceSpecifier;

- (BOOL)isFileURL;

- (NSURL *)standardizedURL;
- (NSURL *)absoluteURL;
- (NSURL *)baseURL;

- (BOOL)setProperty:property forKey:(NSString *)key;

- (BOOL)setResourceData:(NSData *)data;

- (NSData *)resourceDataUsingCache:(BOOL)useCache;
- (NSURLHandle *)URLHandleUsingCache:(BOOL)useCache;
- (void)loadResourceDataNotifyingClient:client usingCache:(BOOL)useCache;

- (NSURL *)URLByAppendingPathComponent:(NSString *)pathComponent isDirectory:(BOOL)isDirectory;
- (NSURL *)URLByAppendingPathComponent:(NSString *)pathComponent;
- (NSURL *)URLByDeletingLastPathComponent;

- (BOOL)checkResourceIsReachableAndReturnError:(NSError **)error;
- (NSString *)lastPathComponent;
- (NSString *)pathExtension;
- (BOOL)setResourceValue:(id)value forKey:(NSString *)key error:(NSError **)error;
- (BOOL)getResourceValue:(id *)value forKey:(NSString *)key error:(NSError **)error;
- (NSArray *)pathComponents;

- (NSDictionary *)resourceValuesForKeys:(NSArray *)keys error:(NSError **)error;

- (id)initFileURLWithPath:(NSString *)path isDirectory:(BOOL)isDir;

@end

#endif /* _NSURL_H_ */