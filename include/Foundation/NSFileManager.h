//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
#import <Foundation/NSPathUtilities.h>
#import <Foundation/NSDictionary.h>

@protocol NSCoding;
@protocol NSCopying;
@class NSFileManager;
@class NSString;
@class NSURL;
@class NSError;
@class NSArray<ObjectType>;
@class NSDirectoryEnumerator<ObjectType>;
@class NSData;
@class NSDate;
@protocol NSFileManagerDelegate;

typedef enum : NSUInteger {
    NSVolumeEnumerationSkipHiddenVolumes = 1L << 1,
    NSVolumeEnumerationProduceFileReferenceURLs = 1L << 2
} NSVolumeEnumerationOptions;

typedef enum : NSUInteger {
    NSDirectoryEnumerationSkipsSubdirectoryDescendants = 1L << 0,
    NSDirectoryEnumerationSkipsPackageDescendants = 1L << 1,
    NSDirectoryEnumerationSkipsHiddenFiles = 1L << 2
} NSDirectoryEnumerationOptions;

typedef enum : NSUInteger {
    NSFileManagerItemReplacementUsingNewMetadataOnly = 1UL << 0,
    NSFileManagerItemReplacementWithoutDeletingBackupItem = 1UL << 1
} NSFileManagerItemReplacementOptions;

typedef enum NSURLRelationship : NSInteger { NSURLRelationshipContains, NSURLRelationshipSame, NSURLRelationshipOther } NSURLRelationship;

typedef NSString* NSFileAttributeKey;
typedef NSString* NSFileAttributeType;

FOUNDATION_EXPORT NSFileAttributeKey const NSFileType;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileSize;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileModificationDate;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileReferenceCount;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileDeviceIdentifier;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileOwnerAccountName;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileGroupOwnerAccountName;
FOUNDATION_EXPORT NSFileAttributeKey const NSFilePosixPermissions;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileSystemNumber;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileSystemFileNumber;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileExtensionHidden;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileHFSCreatorCode;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileHFSTypeCode;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileImmutable;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileAppendOnly;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileCreationDate;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileOwnerAccountID;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileGroupOwnerAccountID;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileBusy;
FOUNDATION_EXPORT NSFileAttributeKey const NSFileProtectionKey;
FOUNDATION_EXPORT NSFileAttributeType const NSFileTypeDirectory;
FOUNDATION_EXPORT NSFileAttributeType const NSFileTypeRegular;
FOUNDATION_EXPORT NSFileAttributeType const NSFileTypeSymbolicLink;
FOUNDATION_EXPORT NSFileAttributeType const NSFileTypeSocket;
FOUNDATION_EXPORT NSFileAttributeType const NSFileTypeCharacterSpecial;
FOUNDATION_EXPORT NSFileAttributeType const NSFileTypeBlockSpecial;
FOUNDATION_EXPORT NSFileAttributeType const NSFileTypeUnknown;
FOUNDATION_EXPORT NSString* const NSFileSystemSize;
FOUNDATION_EXPORT NSString* const NSFileSystemFreeSize;
FOUNDATION_EXPORT NSString* const NSFileSystemNodes;
FOUNDATION_EXPORT NSString* const NSFileSystemFreeNodes;
FOUNDATION_EXPORT NSString* const NSFileProtectionNone;
FOUNDATION_EXPORT NSString* const NSFileProtectionComplete;
FOUNDATION_EXPORT NSString* const NSFileProtectionCompleteUnlessOpen;
FOUNDATION_EXPORT NSString* const NSFileProtectionCompleteUntilFirstUserAuthentication;

#define NSFoundationVersionWithFileManagerResourceForkSupport 412

FOUNDATION_EXPORT NSString* const NSUbiquityIdentityDidChangeNotification;

FOUNDATION_EXPORT NSString* NSOpenStepRootDirectory() NOTINPLAN_METHOD;

@interface NSObject (NSFileManager)
- (BOOL)fileManager:(NSFileManager*)manager shouldProceedAfterError:(NSDictionary*)errorInfo;
- (void)fileManager:(NSFileManager*)manager willProcessPath:(NSString*)path;
@end

FOUNDATION_EXPORT_CLASS
@interface NSFileManager : NSObject
+ (NSFileManager*)defaultManager;
- (NSURL*)URLForDirectory:(NSSearchPathDirectory)directory
                 inDomain:(NSSearchPathDomainMask)domain
        appropriateForURL:(NSURL*)url
                   create:(BOOL)shouldCreate
                    error:(NSError* _Nullable*)error;
- (NSArray<NSURL*>*)URLsForDirectory:(NSSearchPathDirectory)directory inDomains:(NSSearchPathDomainMask)domainMask;
- (NSURL*)containerURLForSecurityApplicationGroupIdentifier:(NSString*)groupIdentifier;
- (NSArray<NSURL*>*)contentsOfDirectoryAtURL:(NSURL*)url
                  includingPropertiesForKeys:(NSArray<NSString*>*)keys
                                     options:(NSDirectoryEnumerationOptions)mask
                                       error:(NSError* _Nullable*)error;
- (NSArray<NSURL*>*)contentsOfDirectoryAtPath:(NSString*)path error:(NSError* _Nullable*)error;
- (NSDirectoryEnumerator<NSURL*>*)enumeratorAtURL:(NSURL*)url
                       includingPropertiesForKeys:(NSArray<NSString*>*)keys
                                          options:(NSDirectoryEnumerationOptions)mask
                                     errorHandler:(BOOL (^)(NSURL*, NSError*))handler;
- (NSDirectoryEnumerator<NSString*>*)enumeratorAtPath:(NSString*)path;
- (NSArray<NSURL*>*)mountedVolumeURLsIncludingResourceValuesForKeys:(NSArray<NSString*>*)propertyKeys
                                                            options:(NSVolumeEnumerationOptions)options;
- (NSArray<NSURL*>*)subpathsOfDirectoryAtPath:(NSString*)path error:(NSError* _Nullable*)error;
- (NSArray<NSURL*>*)subpathsAtPath:(NSString*)path;
- (BOOL)createDirectoryAtURL:(NSURL*)url
    withIntermediateDirectories:(BOOL)createIntermediates
                     attributes:(NSDictionary<NSString*, id>*)attributes
                          error:(NSError* _Nullable*)error;
- (BOOL)createDirectoryAtPath:(NSString*)path
    withIntermediateDirectories:(BOOL)createIntermediates
                     attributes:(NSDictionary<NSString*, id>*)attributes
                          error:(NSError* _Nullable*)error;
- (BOOL)createFileAtPath:(NSString*)path contents:(NSData*)contents attributes:(NSDictionary<NSString*, id>*)attributes;
- (BOOL)removeItemAtURL:(NSURL*)URL error:(NSError* _Nullable*)error;
- (BOOL)removeItemAtPath:(NSString*)path error:(NSError* _Nullable*)error;
- (BOOL)replaceItemAtURL:(NSURL*)originalItemURL
           withItemAtURL:(NSURL*)newItemURL
          backupItemName:(NSString*)backupItemName
                 options:(NSFileManagerItemReplacementOptions)options
        resultingItemURL:(NSURL* _Nullable*)resultingURL
                   error:(NSError* _Nullable*)error NOTINPLAN_METHOD;
- (BOOL)trashItemAtURL:(NSURL*)url resultingItemURL:(NSURL**)outResultingURL error:(NSError**)error NOTINPLAN_METHOD;
- (BOOL)copyItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL error:(NSError* _Nullable*)error;
- (BOOL)copyItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath error:(NSError* _Nullable*)error;
- (BOOL)moveItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL error:(NSError* _Nullable*)error;
- (BOOL)moveItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath error:(NSError* _Nullable*)error;
- (NSURL*)URLForUbiquityContainerIdentifier:(NSString*)containerID NOTINPLAN_METHOD;
- (BOOL)isUbiquitousItemAtURL:(NSURL*)url NOTINPLAN_METHOD;
- (BOOL)setUbiquitous:(BOOL)flag
            itemAtURL:(NSURL*)url
       destinationURL:(NSURL*)destinationURL
                error:(NSError* _Nullable*)errorOut NOTINPLAN_METHOD;
- (BOOL)startDownloadingUbiquitousItemAtURL:(NSURL*)url error:(NSError* _Nullable*)errorOut NOTINPLAN_METHOD;
- (BOOL)evictUbiquitousItemAtURL:(NSURL*)url error:(NSError* _Nullable*)errorOut NOTINPLAN_METHOD;
- (NSURL*)URLForPublishingUbiquitousItemAtURL:(NSURL*)url
                               expirationDate:(NSDate* _Nullable*)outDate
                                        error:(NSError* _Nullable*)error NOTINPLAN_METHOD;
- (BOOL)createSymbolicLinkAtURL:(NSURL*)url withDestinationURL:(NSURL*)destURL error:(NSError* _Nullable*)error NOTINPLAN_METHOD;
- (BOOL)createSymbolicLinkAtPath:(NSString*)path withDestinationPath:(NSString*)destPath error:(NSError* _Nullable*)error NOTINPLAN_METHOD;
- (BOOL)linkItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL error:(NSError* _Nullable*)error NOTINPLAN_METHOD;
- (BOOL)linkItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath error:(NSError* _Nullable*)error NOTINPLAN_METHOD;
- (NSString*)destinationOfSymbolicLinkAtPath:(NSString*)path error:(NSError* _Nullable*)error;
- (BOOL)fileExistsAtPath:(NSString*)path;
- (BOOL)fileExistsAtPath:(NSString*)path isDirectory:(BOOL*)isDirectory;
- (BOOL)isReadableFileAtPath:(NSString*)path;
- (BOOL)isWritableFileAtPath:(NSString*)path;
- (BOOL)isExecutableFileAtPath:(NSString*)path;
- (BOOL)isDeletableFileAtPath:(NSString*)path NOTINPLAN_METHOD;
- (NSArray<NSString*>*)componentsToDisplayForPath:(NSString*)path;
- (NSString*)displayNameAtPath:(NSString*)path;
- (NSDictionary<NSString*, id>*)attributesOfItemAtPath:(NSString*)path error:(NSError* _Nullable*)error;
- (NSDictionary<NSString*, id>*)attributesOfFileSystemForPath:(NSString*)path error:(NSError* _Nullable*)error;
- (BOOL)setAttributes:(NSDictionary<NSString*, id>*)attributes ofItemAtPath:(NSString*)path error:(NSError* _Nullable*)error;
- (NSData*)contentsAtPath:(NSString*)path;
- (BOOL)contentsEqualAtPath:(NSString*)path1 andPath:(NSString*)path2;
- (BOOL)getRelationship:(NSURLRelationship*)outRelationship
       ofDirectoryAtURL:(NSURL*)directoryURL
            toItemAtURL:(NSURL*)otherURL
                  error:(NSError* _Nullable*)error NOTINPLAN_METHOD;
- (BOOL)getRelationship:(NSURLRelationship*)outRelationship
            ofDirectory:(NSSearchPathDirectory)directory
               inDomain:(NSSearchPathDomainMask)domainMask
            toItemAtURL:(NSURL*)url
                  error:(NSError* _Nullable*)error NOTINPLAN_METHOD;
- (const char*)fileSystemRepresentationWithPath:(NSString*)path;
- (NSString*)stringWithFileSystemRepresentation:(const char*)string length:(NSUInteger)len;
- (BOOL)changeCurrentDirectoryPath:(NSString*)path;
- (BOOL)changeFileAttributes:(NSDictionary<NSString*, id>*)attributes atPath:(NSString*)path;
- (NSDictionary<NSString*, id>*)fileAttributesAtPath:(NSString*)path traverseLink:(BOOL)flag;
- (NSDictionary<NSString*, id>*)fileSystemAttributesAtPath:(NSString*)path;
- (NSArray<NSURL*>*)directoryContentsAtPath:(NSString*)path;
- (BOOL)createDirectoryAtPath:(NSString*)path attributes:(NSDictionary<NSString*, id>*)attributes;
- (BOOL)createSymbolicLinkAtPath:(NSString*)path pathContent:(NSString*)otherPath NOTINPLAN_METHOD;
- (NSString*)pathContentOfSymbolicLinkAtPath:(NSString*)path NOTINPLAN_METHOD;
- (BOOL)linkPath:(NSString*)source toPath:(NSString*)destination handler:handler NOTINPLAN_METHOD;
- (BOOL)copyPath:(NSString*)src toPath:(NSString*)dest handler:handler NOTINPLAN_METHOD;
- (BOOL)movePath:(NSString*)src toPath:(NSString*)dest handler:handler NOTINPLAN_METHOD;
- (BOOL)removeFileAtPath:(NSString*)path handler:handler NOTINPLAN_METHOD;
@property (assign) id<NSFileManagerDelegate> delegate;
@property (readonly, copy) id<NSCopying, NSCoding> ubiquityIdentityToken;
@property (readonly, copy) NSString* currentDirectoryPath;
@end

@protocol NSFileManagerDelegate <NSObject>
@optional
- (BOOL)fileManager:(NSFileManager*)fileManager shouldMoveItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldMoveItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSError*)error movingItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL;
- (BOOL)fileManager:(NSFileManager*)fileManager
    shouldProceedAfterError:(NSError*)error
           movingItemAtPath:(NSString*)srcPath
                     toPath:(NSString*)dstPath;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldCopyItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldCopyItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath;
- (BOOL)fileManager:(NSFileManager*)fileManager
    shouldProceedAfterError:(NSError*)error
           copyingItemAtURL:(NSURL*)srcURL
                      toURL:(NSURL*)dstURL;
- (BOOL)fileManager:(NSFileManager*)fileManager
    shouldProceedAfterError:(NSError*)error
          copyingItemAtPath:(NSString*)srcPath
                     toPath:(NSString*)dstPath;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldRemoveItemAtURL:(NSURL*)URL;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldRemoveItemAtPath:(NSString*)path;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSError*)error removingItemAtURL:(NSURL*)URL;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSError*)error removingItemAtPath:(NSString*)path;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldLinkItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldLinkItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath;
- (BOOL)fileManager:(NSFileManager*)fileManager
    shouldProceedAfterError:(NSError*)error
           linkingItemAtURL:(NSURL*)srcURL
                      toURL:(NSURL*)dstURL;
- (BOOL)fileManager:(NSFileManager*)fileManager
    shouldProceedAfterError:(NSError*)error
          linkingItemAtPath:(NSString*)srcPath
                     toPath:(NSString*)dstPath;
@end

@interface NSDictionary (NSFileManagerExtensions)
- (NSDate*)fileCreationDate;
- (BOOL)fileExtensionHidden;
- (NSNumber*)fileGroupOwnerAccountID;
- (NSString*)fileGroupOwnerAccountName;
- (OSType)fileHFSCreatorCode;
- (OSType)fileHFSTypeCode;
- (BOOL)fileIsAppendOnly;
- (BOOL)fileIsImmutable;
- (NSDate*)fileModificationDate;
- (NSNumber*)fileOwnerAccountID;
- (NSString*)fileOwnerAccountName;
- (NSUInteger)filePosixPermissions;
- (unsigned long long int)fileSize;
- (NSUInteger)fileSystemFileNumber;
- (NSInteger)fileSystemNumber;
- (NSString*)fileType;
@end
