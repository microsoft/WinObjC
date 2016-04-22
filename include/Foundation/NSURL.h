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
#import <Foundation/NSObject.h>

@class NSString;
@class NSArray;
@class NSError;
@class NSData;
@class NSNumber;
@class NSDictionary;

typedef NSUInteger NSURLBookmarkFileCreationOptions;
typedef NSUInteger NSURLBookmarkCreationOptions;
typedef NSUInteger NSURLBookmarkResolutionOptions;
enum {
    NSURLBookmarkCreationPreferFileIDResolution = (1UL << 8),
    NSURLBookmarkCreationMinimalBookmark = (1UL << 9),
    NSURLBookmarkCreationSuitableForBookmarkFile = (1UL << 10),
};

enum {
    NSURLBookmarkResolutionWithoutUI = (1UL << 8),
    NSURLBookmarkResolutionWithoutMounting = (1UL << 9),
};

FOUNDATION_EXPORT NSString* const NSURLFileScheme;
FOUNDATION_EXPORT NSString* const NSURLAddedToDirectoryDateKey;

FOUNDATION_EXPORT NSString* const NSURLAttributeModificationDateKey;
FOUNDATION_EXPORT NSString* const NSURLContentAccessDateKey;
FOUNDATION_EXPORT NSString* const NSURLContentModificationDateKey;
FOUNDATION_EXPORT NSString* const NSURLCreationDateKey;
FOUNDATION_EXPORT NSString* const NSURLCustomIconKey;
FOUNDATION_EXPORT NSString* const NSURLDocumentIdentifierKey;

FOUNDATION_EXPORT NSString* const NSURLEffectiveIconKey;
FOUNDATION_EXPORT NSString* const NSURLFileResourceIdentifierKey;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeKey;
FOUNDATION_EXPORT NSString* const NSURLFileSecurityKey;
FOUNDATION_EXPORT NSString* const NSURLGenerationIdentifierKey;

FOUNDATION_EXPORT NSString* const NSURLHasHiddenExtensionKey;
FOUNDATION_EXPORT NSString* const NSURLIsDirectoryKey;
FOUNDATION_EXPORT NSString* const NSURLIsExcludedFromBackupKey;
FOUNDATION_EXPORT NSString* const NSURLIsExecutableKey;
FOUNDATION_EXPORT NSString* const NSURLIsHiddenKey;
FOUNDATION_EXPORT NSString* const NSURLIsMountTriggerKey;
FOUNDATION_EXPORT NSString* const NSURLIsPackageKey;
FOUNDATION_EXPORT NSString* const NSURLIsReadableKey;
FOUNDATION_EXPORT NSString* const NSURLIsRegularFileKey;
FOUNDATION_EXPORT NSString* const NSURLIsSymbolicLinkKey;
FOUNDATION_EXPORT NSString* const NSURLIsSystemImmutableKey;
FOUNDATION_EXPORT NSString* const NSURLIsUserImmutableKey;
FOUNDATION_EXPORT NSString* const NSURLIsVolumeKey;
FOUNDATION_EXPORT NSString* const NSURLIsWritableKey;
FOUNDATION_EXPORT NSString* const NSURLLabelColorKey;
FOUNDATION_EXPORT NSString* const NSURLLabelNumberKey;
FOUNDATION_EXPORT NSString* const NSURLLinkCountKey;
FOUNDATION_EXPORT NSString* const NSURLLocalizedLabelKey;
FOUNDATION_EXPORT NSString* const NSURLLocalizedNameKey;
FOUNDATION_EXPORT NSString* const NSURLLocalizedTypeDescriptionKey;
FOUNDATION_EXPORT NSString* const NSURLNameKey;
FOUNDATION_EXPORT NSString* const NSURLParentDirectoryURLKey;
FOUNDATION_EXPORT NSString* const NSURLPathKey;

FOUNDATION_EXPORT NSString* const NSURLPreferredIOBlockSizeKey;
FOUNDATION_EXPORT NSString* const NSURLThumbnailDictionaryKey;

FOUNDATION_EXPORT NSString* const NSURLTypeIdentifierKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeIdentifierKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeURLKey;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeNamedPipe;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeCharacterSpecial;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeDirectory;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeBlockSpecial;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeRegular;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeSymbolicLink;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeSocket;
FOUNDATION_EXPORT NSString* const NSURLFileResourceTypeUnknown;
FOUNDATION_EXPORT NSString* const NSThumbnail1024x1024SizeKey;
FOUNDATION_EXPORT NSString* const NSURLFileSizeKey;
FOUNDATION_EXPORT NSString* const NSURLFileAllocatedSizeKey;
FOUNDATION_EXPORT NSString* const NSURLIsAliasFileKey;
FOUNDATION_EXPORT NSString* const NSURLTotalFileAllocatedSizeKey;
FOUNDATION_EXPORT NSString* const NSURLTotalFileSizeKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeLocalizedFormatDescriptionKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeTotalCapacityKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeAvailableCapacityKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeResourceCountKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeSupportsPersistentIDsKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeSupportsSymbolicLinksKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeSupportsHardLinksKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeSupportsJournalingKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeIsJournalingKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeSupportsSparseFilesKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeSupportsZeroRunsKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeSupportsCaseSensitiveNamesKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeSupportsCasePreservedNamesKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeSupportsRootDirectoryDatesKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeSupportsVolumeSizesKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeSupportsRenamingKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeSupportsAdvisoryFileLockingKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeSupportsExtendedSecurityKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeIsBrowsableKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeMaximumFileSizeKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeIsEjectableKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeIsRemovableKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeIsInternalKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeIsAutomountedKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeIsLocalKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeIsReadOnlyKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeCreationDateKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeURLForRemountingKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeUUIDStringKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeNameKey;
FOUNDATION_EXPORT NSString* const NSURLVolumeLocalizedNameKey;
FOUNDATION_EXPORT NSString* const NSURLKeysOfUnsetValuesKey;
FOUNDATION_EXPORT NSString* const NSURLIsUbiquitousItemKey;
FOUNDATION_EXPORT NSString* const NSURLUbiquitousItemDownloadingErrorKey;
FOUNDATION_EXPORT NSString* const NSURLUbiquitousItemDownloadingStatusKey;
FOUNDATION_EXPORT NSString* const NSURLUbiquitousItemHasUnresolvedConflictsKey;
FOUNDATION_EXPORT NSString* const NSURLUbiquitousItemIsDownloadedKey;
FOUNDATION_EXPORT NSString* const NSURLUbiquitousItemIsDownloadingKey;
FOUNDATION_EXPORT NSString* const NSURLUbiquitousItemIsUploadedKey;
FOUNDATION_EXPORT NSString* const NSURLUbiquitousItemIsUploadingKey;
FOUNDATION_EXPORT NSString* const NSURLUbiquitousItemUploadingErrorKey;
FOUNDATION_EXPORT NSString* const NSURLUbiquitousItemDownloadRequestedKey;
FOUNDATION_EXPORT NSString* const NSURLUbiquitousItemContainerDisplayNameKey;
FOUNDATION_EXPORT NSString* const NSURLUbiquitousItemPercentUploadedKey;
FOUNDATION_EXPORT NSString* const NSURLUbiquitousItemDownloadingStatusCurrent;
FOUNDATION_EXPORT NSString* const NSURLUbiquitousItemDownloadingStatusDownloaded;
FOUNDATION_EXPORT NSString* const NSURLUbiquitousItemDownloadingStatusNotDownloaded;

FOUNDATION_EXPORT_CLASS
@interface NSURL : NSObject <NSCopying, NSSecureCoding>
- (instancetype)initWithScheme:(NSString*)scheme host:(NSString*)host path:(NSString*)path;
+ (instancetype)URLWithString:(NSString*)URLString;
- (instancetype)initWithString:(NSString*)URLString;
+ (instancetype)URLWithString:(NSString*)URLString relativeToURL:(NSURL*)baseURL;
- (instancetype)initWithString:(NSString*)URLString relativeToURL:(NSURL*)baseURL;
+ (NSURL*)fileURLWithPath:(NSString*)path isDirectory:(BOOL)isDir;
- (instancetype)initFileURLWithPath:(NSString*)path isDirectory:(BOOL)isDir;
+ (NSURL*)fileURLWithPath:(NSString*)path;
- (instancetype)initFileURLWithPath:(NSString*)path;
+ (NSURL*)fileURLWithPathComponents:(NSArray*)components;
+ (instancetype)URLByResolvingAliasFileAtURL:(NSURL*)url
                                     options:(NSURLBookmarkResolutionOptions)options
                                       error:(NSError* _Nullable*)error STUB_METHOD;
+ (instancetype)URLByResolvingBookmarkData:(NSData*)bookmarkData
                                   options:(NSURLBookmarkResolutionOptions)options
                             relativeToURL:(NSURL*)relativeURL
                       bookmarkDataIsStale:(BOOL*)isStale
                                     error:(NSError* _Nullable*)error STUB_METHOD;
- (instancetype)initByResolvingBookmarkData:(NSData*)bookmarkData
                                    options:(NSURLBookmarkResolutionOptions)options
                              relativeToURL:(NSURL*)relativeURL
                        bookmarkDataIsStale:(BOOL*)isStale
                                      error:(NSError* _Nullable*)error STUB_METHOD;
+ (NSURL*)fileURLWithFileSystemRepresentation:(const char*)path isDirectory:(BOOL)isDir relativeToURL:(NSURL*)baseURL;
- (BOOL)getFileSystemRepresentation:(char*)buffer maxLength:(NSUInteger)maxBufferLength;
- (instancetype)initFileURLWithFileSystemRepresentation:(const char*)path isDirectory:(BOOL)isDir relativeToURL:(NSURL*)baseURL;
- (BOOL)isEqual:(id)anObject;
- (BOOL)checkResourceIsReachableAndReturnError:(NSError* _Nullable*)error;
- (BOOL)isFileReferenceURL;
@property (readonly, getter=isFileURL) BOOL fileURL;
@property (readonly, copy) NSString* absoluteString;
@property (readonly, copy) NSURL* absoluteURL;
@property (readonly, copy) NSURL* baseURL;
@property (readonly) const char* fileSystemRepresentation;
@property (readonly, copy) NSString* fragment;
@property (readonly, copy) NSString* host;
@property (readonly, copy) NSString* lastPathComponent;
@property (readonly, copy) NSString* parameterString;
@property (readonly, copy) NSString* password;
@property (readonly, copy) NSString* path;
@property (readonly, copy) NSArray* pathComponents;
@property (readonly, copy) NSString* pathExtension;
@property (readonly, copy) NSNumber* port;
@property (readonly, copy) NSString* query;
@property (readonly, copy) NSString* relativePath;
@property (readonly, copy) NSString* relativeString;
@property (readonly, copy) NSString* resourceSpecifier;
@property (readonly, copy) NSString* scheme;
@property (readonly, copy) NSURL* standardizedURL;
@property (readonly, copy) NSString* user;
@property (readonly, copy) NSURL* filePathURL;
- (NSURL*)fileReferenceURL;
- (NSURL*)URLByAppendingPathComponent:(NSString*)pathComponent;
- (NSURL*)URLByAppendingPathComponent:(NSString*)pathComponent isDirectory:(BOOL)isDirectory;
- (NSURL*)URLByAppendingPathExtension:(NSString*)pathExtension;
@property (readonly, copy) NSURL* URLByDeletingLastPathComponent;
@property (readonly, copy) NSURL* URLByDeletingPathExtension;
@property (readonly, copy) NSURL* URLByResolvingSymlinksInPath;
@property (readonly, copy) NSURL* URLByStandardizingPath;
+ (NSData*)bookmarkDataWithContentsOfURL:(NSURL*)bookmarkFileURL error:(NSError* _Nullable*)error;
- (NSData*)bookmarkDataWithOptions:(NSURLBookmarkCreationOptions)options
    includingResourceValuesForKeys:(NSArray*)keys
                     relativeToURL:(NSURL*)relativeURL
                             error:(NSError* _Nullable*)error;
+ (NSDictionary*)resourceValuesForKeys:(NSArray*)keys fromBookmarkData:(NSData*)bookmarkData;
+ (BOOL)writeBookmarkData:(NSData*)bookmarkData
                    toURL:(NSURL*)bookmarkFileURL
                  options:(NSURLBookmarkFileCreationOptions)options
                    error:(NSError* _Nullable*)error;
- (BOOL)startAccessingSecurityScopedResource;
- (void)stopAccessingSecurityScopedResource;
- (BOOL)getResourceValue:(id _Nullable*)value forKey:(NSString*)key error:(NSError* _Nullable*)error;
- (NSDictionary*)resourceValuesForKeys:(NSArray*)keys error:(NSError* _Nullable*)error;
- (BOOL)setResourceValue:(id)value forKey:(NSString*)key error:(NSError* _Nullable*)error;
- (BOOL)setResourceValues:(NSDictionary*)keyedValues error:(NSError* _Nullable*)error;
- (void)removeAllCachedResourceValues;
- (void)removeCachedResourceValueForKey:(NSString*)key;
- (void)setTemporaryResourceValue:(id)value forKey:(NSString*)key;
- (BOOL)checkPromisedItemIsReachableAndReturnError:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)getPromisedItemResourceValue:(id _Nullable*)value forKey:(NSString*)key error:(NSError* _Nullable*)error STUB_METHOD;
- (NSDictionary*)promisedItemResourceValuesForKeys:(NSArray*)keys error:(NSError* _Nullable*)error STUB_METHOD;
@end
