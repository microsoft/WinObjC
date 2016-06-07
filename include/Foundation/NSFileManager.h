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

#import <Foundation/NSPathUtilities.h>

@protocol NSCoding;
@protocol NSCopying;
@class NSFileManager;
@class NSDictionary<KeyType, ObjectType>;
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
@interface NSObject (NSFileManager)
- (BOOL)fileManager:(NSFileManager*)manager shouldProceedAfterError:(NSDictionary*)errorInfo;
- (void)fileManager:(NSFileManager*)manager willProcessPath:(NSString*)path;
@end
FOUNDATION_EXPORT NSString* const NSFileType;
FOUNDATION_EXPORT NSString* const NSFileSize;
FOUNDATION_EXPORT NSString* const NSFileModificationDate;
FOUNDATION_EXPORT NSString* const NSFileReferenceCount;
FOUNDATION_EXPORT NSString* const NSFileDeviceIdentifier;
FOUNDATION_EXPORT NSString* const NSFileOwnerAccountName;
FOUNDATION_EXPORT NSString* const NSFileGroupOwnerAccountName;
FOUNDATION_EXPORT NSString* const NSFilePosixPermissions;
FOUNDATION_EXPORT NSString* const NSFileSystemNumber;
FOUNDATION_EXPORT NSString* const NSFileSystemFileNumber;
FOUNDATION_EXPORT NSString* const NSFileExtensionHidden;
FOUNDATION_EXPORT NSString* const NSFileHFSCreatorCode;
FOUNDATION_EXPORT NSString* const NSFileHFSTypeCode;
FOUNDATION_EXPORT NSString* const NSFileImmutable;
FOUNDATION_EXPORT NSString* const NSFileAppendOnly;
FOUNDATION_EXPORT NSString* const NSFileCreationDate;
FOUNDATION_EXPORT NSString* const NSFileOwnerAccountID;
FOUNDATION_EXPORT NSString* const NSFileGroupOwnerAccountID;
FOUNDATION_EXPORT NSString* const NSFileBusy;
FOUNDATION_EXPORT NSString* const NSFileProtectionKey;
FOUNDATION_EXPORT NSString* const NSFileTypeDirectory;
FOUNDATION_EXPORT NSString* const NSFileTypeRegular;
FOUNDATION_EXPORT NSString* const NSFileTypeSymbolicLink;
FOUNDATION_EXPORT NSString* const NSFileTypeSocket;
FOUNDATION_EXPORT NSString* const NSFileTypeCharacterSpecial;
FOUNDATION_EXPORT NSString* const NSFileTypeBlockSpecial;
FOUNDATION_EXPORT NSString* const NSFileTypeUnknown;
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

FOUNDATION_EXPORT NSString* NSOpenStepRootDirectory() STUB_METHOD;

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
                   error:(NSError* _Nullable*)error;
- (BOOL)copyItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL error:(NSError* _Nullable*)error;
- (BOOL)copyItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath error:(NSError* _Nullable*)error;
- (BOOL)moveItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL error:(NSError* _Nullable*)error;
- (BOOL)moveItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath error:(NSError* _Nullable*)error;
@property (readonly, copy) id<NSCopying, NSCoding> ubiquityIdentityToken;
- (NSURL*)URLForUbiquityContainerIdentifier:(NSString*)containerID;
- (BOOL)isUbiquitousItemAtURL:(NSURL*)url;
- (BOOL)setUbiquitous:(BOOL)flag itemAtURL:(NSURL*)url destinationURL:(NSURL*)destinationURL error:(NSError* _Nullable*)errorOut;
- (BOOL)startDownloadingUbiquitousItemAtURL:(NSURL*)url error:(NSError* _Nullable*)errorOut;
- (BOOL)evictUbiquitousItemAtURL:(NSURL*)url error:(NSError* _Nullable*)errorOut;
- (NSURL*)URLForPublishingUbiquitousItemAtURL:(NSURL*)url expirationDate:(NSDate* _Nullable*)outDate error:(NSError* _Nullable*)error;
- (BOOL)createSymbolicLinkAtURL:(NSURL*)url withDestinationURL:(NSURL*)destURL error:(NSError* _Nullable*)error;
- (BOOL)createSymbolicLinkAtPath:(NSString*)path withDestinationPath:(NSString*)destPath error:(NSError* _Nullable*)error;
- (BOOL)linkItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL error:(NSError* _Nullable*)error;
- (BOOL)linkItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath error:(NSError* _Nullable*)error;
- (NSString*)destinationOfSymbolicLinkAtPath:(NSString*)path error:(NSError* _Nullable*)error;
- (BOOL)fileExistsAtPath:(NSString*)path;
- (BOOL)fileExistsAtPath:(NSString*)path isDirectory:(BOOL*)isDirectory;
- (BOOL)isReadableFileAtPath:(NSString*)path;
- (BOOL)isWritableFileAtPath:(NSString*)path;
- (BOOL)isExecutableFileAtPath:(NSString*)path;
- (BOOL)isDeletableFileAtPath:(NSString*)path;
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
                  error:(NSError* _Nullable*)error;
- (BOOL)getRelationship:(NSURLRelationship*)outRelationship
            ofDirectory:(NSSearchPathDirectory)directory
               inDomain:(NSSearchPathDomainMask)domainMask
            toItemAtURL:(NSURL*)url
                  error:(NSError* _Nullable*)error;
- (const char*)fileSystemRepresentationWithPath:(NSString*)path;
- (NSString*)stringWithFileSystemRepresentation:(const char*)string length:(NSUInteger)len;
@property (assign) id<NSFileManagerDelegate> delegate;
- (BOOL)changeCurrentDirectoryPath:(NSString*)path;
@property (readonly, copy) NSString* currentDirectoryPath;
- (BOOL)changeFileAttributes:(NSDictionary<NSString*, id>*)attributes atPath:(NSString*)path;
- (NSDictionary<NSString*, id>*)fileAttributesAtPath:(NSString*)path traverseLink:(BOOL)flag;
- (NSDictionary<NSString*, id>*)fileSystemAttributesAtPath:(NSString*)path;
- (NSArray<NSURL*>*)directoryContentsAtPath:(NSString*)path;
- (BOOL)createDirectoryAtPath:(NSString*)path attributes:(NSDictionary<NSString*, id>*)attributes;
- (BOOL)createSymbolicLinkAtPath:(NSString*)path pathContent:(NSString*)otherPath;
- (NSString*)pathContentOfSymbolicLinkAtPath:(NSString*)path;
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
