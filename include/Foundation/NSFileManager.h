/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Copyright (c) 2015 Microsoft Corporation. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSFILEMANAGER_H_
#define _NSFILEMANAGER_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSDirectoryEnumerator.h>
#import <Foundation/NSPathUtilities.h>

@class NSData, NSDate, NSError, NSFileManager;

@protocol NSFileManagerDelegate
@optional

// Moving an Item
- (BOOL)fileManager:(NSFileManager*)fileManager shouldMoveItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldMoveItemAtPath:(NSString*)path toPath:(NSString*)toPath;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSError*)error movingItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL;
- (BOOL)fileManager:(NSFileManager*)fileManager
    shouldProceedAfterError:(NSError*)error
           movingItemAtPath:(NSString*)path
                     toPath:(NSString*)toPath;

// Copying an Item
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

// Removing an Item
- (BOOL)fileManager:(NSFileManager*)fileManager shouldRemoveItemAtURL:(NSURL*)URL;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldRemoveItemAtPath:(NSString*)path;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSError*)error removingItemAtURL:(NSURL*)URL;
- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSError*)error removingItemAtPath:(NSString*)path;

// Linking an Item
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

typedef NS_ENUM(NSUInteger, NSVolumeEnumerationOptions) {
    NSVolumeEnumerationSkipHiddenVolumes = 1L << 1,
    NSVolumeEnumerationProduceFileReferenceURLs = 1L << 2
};

typedef NS_ENUM(NSUInteger, NSDirectoryEnumerationOptions) {
    NSDirectoryEnumerationSkipsSubdirectoryDescendants = 1L << 0,
    NSDirectoryEnumerationSkipsPackageDescendants = 1L << 1,
    NSDirectoryEnumerationSkipsHiddenFiles = 1L << 2
};

typedef NS_ENUM(NSUInteger, NSFileManagerItemReplacementOptions) {
    NSFileManagerItemReplacementUsingNewMetadataOnly = 1UL << 0,
    NSFileManagerItemReplacementWithoutDeletingBackupItem = 1UL << 1
};

typedef NS_ENUM(NSInteger, NSURLRelationship) { NSURLRelationshipContains, NSURLRelationshipSame, NSURLRelationshipOther };

// file attribute keys
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

// NSFileType Attribute Values
FOUNDATION_EXPORT NSString* const NSFileTypeDirectory;
FOUNDATION_EXPORT NSString* const NSFileTypeRegular;
FOUNDATION_EXPORT NSString* const NSFileTypeSymbolicLink;
FOUNDATION_EXPORT NSString* const NSFileTypeSocket;
FOUNDATION_EXPORT NSString* const NSFileTypeCharacterSpecial;
FOUNDATION_EXPORT NSString* const NSFileTypeBlockSpecial;
FOUNDATION_EXPORT NSString* const NSFileTypeUnknown;

// File-System attribute Keys
FOUNDATION_EXPORT NSString* const NSFileSystemSize;
FOUNDATION_EXPORT NSString* const NSFileSystemFreeSize;
FOUNDATION_EXPORT NSString* const NSFileSystemNodes;
FOUNDATION_EXPORT NSString* const NSFileSystemFreeNodes;

// File Protection Values
FOUNDATION_EXPORT NSString* const NSFileProtectionNone;
FOUNDATION_EXPORT NSString* const NSFileProtectionComplete;
FOUNDATION_EXPORT NSString* const NSFileProtectionCompleteUnlessOpen;
FOUNDATION_EXPORT NSString* const NSFileProtectionCompleteUntilFirstUserAuthentication;

FOUNDATION_EXPORT_CLASS
@interface NSFileManager : NSObject

// Creating a File Manager
+ (NSFileManager*)defaultManager;
- (instancetype)init;

// Locating System Directories
- (NSURL*)URLForDirectory:(NSSearchPathDirectory)directory
                 inDomain:(NSSearchPathDomainMask)domain
        appropriateForURL:(NSURL*)url
                   create:(BOOL)shouldCreate
                    error:(NSError**)error;
- (NSArray*)URLsForDirectory:(NSSearchPathDirectory)directory inDomains:(NSSearchPathDomainMask)domainMask;

// Locating Application Group Container Directories
- (NSURL*)containerURLForSecurityApplicationGroupIdentifier:(NSString*)groupIdentifier;

// Discovering Directory Contents
- (NSArray*)contentsOfDirectoryAtURL:(NSURL*)url
          includingPropertiesForKeys:(NSArray*)keys
                             options:(NSDirectoryEnumerationOptions)mask
                               error:(NSError**)error;
- (NSArray*)contentsOfDirectoryAtPath:(NSString*)path error:(NSError**)error;
- (NSDirectoryEnumerator*)enumeratorAtURL:(NSURL*)url
               includingPropertiesForKeys:(NSArray*)keys
                                  options:(NSDirectoryEnumerationOptions)mask
                             errorHandler:(BOOL (^)(NSURL* url, NSError* error))handler;
- (NSDirectoryEnumerator*)enumeratorAtPath:(NSString*)path;
- (NSArray**)mountedVolumeURLsIncludingResourceValuesForKeys:(NSArray**)propertyKeys options:(NSVolumeEnumerationOptions)options;
- (NSArray*)subpathsOfDirectoryAtPath:(NSString*)path error:(NSError**)error;
- (NSArray*)subpathsAtPath:(NSString*)path;

// Creating and Deleting Items
- (BOOL)createDirectoryAtURL:(NSURL*)url
 withIntermediateDirectories:(BOOL)createIntermediates
                  attributes:(NSDictionary*)attributes
                       error:(NSError**)error;
- (BOOL)createDirectoryAtPath:(NSString*)path
  withIntermediateDirectories:(BOOL)intermediates
                   attributes:(NSDictionary*)attributes
                        error:(NSError**)error;
- (BOOL)createFileAtPath:(NSString*)path contents:(NSData*)data attributes:(NSDictionary*)attributes;
- (BOOL)removeItemAtURL:(NSURL*)URL error:(NSError**)error;
- (BOOL)replaceItemAtURL:(NSURL*)originalItemURL
           withItemAtURL:(NSURL*)newItemURL
          backupItemName:(NSString*)backupItemName
                 options:(NSFileManagerItemReplacementOptions)options
        resultingItemURL:(NSURL**)resultingURL
                   error:(NSError**)error;
- (BOOL)trashItemAtURL:(NSURL*)url resultingItemURL:(NSURL**)outResultingURL error:(NSError**)error;

// Moving and Copying Items
- (BOOL)copyItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL error:(NSError**)error;
- (BOOL)copyItemAtPath:(NSString*)fromPath toPath:(NSString*)toPath error:(NSError**)error;
- (BOOL)moveItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL error:(NSError**)error;
- (BOOL)moveItemAtPath:(NSString*)fromPath toPath:(NSString*)toPath error:(NSError**)error;

// Managing iCloud-Based Items
@property (readonly, copy) id<NSObject, NSCopying, NSCoding> ubiquityIdentityToken;

- (NSURL*)URLForUbiquityContainerIdentifier:(NSString*)containerID;
- (BOOL)isUbiquitousItemAtURL:(NSURL*)url;
- (BOOL)setUbiquitous:(BOOL)flag itemAtURL:(NSURL*)url destinationURL:(NSURL*)destinationURL error:(NSError**)errorOut;
- (BOOL)setUbiquitous:(BOOL)flag itemAtURL:(NSURL*)url destinationURL:(NSURL*)destinationURL error:(NSError**)errorOut;
- (BOOL)startDownloadingUbiquitousItemAtURL:(NSURL*)url error:(NSError**)errorOut;
- (BOOL)evictUbiquitousItemAtURL:(NSURL*)url error:(NSError**)errorOut;
- (NSURL*)URLForPublishingUbiquitousItemAtURL:(NSURL*)url expirationDate:(NSDate**)outDate error:(NSError**)error;

// Creating Symbolic and Hard Links
- (BOOL)createSymbolicLinkAtURL:(NSURL*)url withDestinationURL:(NSURL*)destURL error:(NSError**)error;
- (BOOL)createSymbolicLinkAtPath:(NSString*)path withDestinationPath:(NSString*)toPath error:(NSError**)error;
- (BOOL)linkItemAtURL:(NSURL*)srcURL toURL:(NSURL*)dstURL error:(NSError**)error;
- (BOOL)linkItemAtPath:(NSString*)fromPath toPath:(NSString*)toPath error:(NSError**)error;
- (NSString*)destinationOfSymbolicLinkAtPath:(NSString*)path error:(NSError**)error;

// Determining Access to Files
- (BOOL)fileExistsAtPath:(NSString*)path;
- (BOOL)fileExistsAtPath:(NSString*)path isDirectory:(BOOL*)isDirectory;
- (BOOL)isReadableFileAtPath:(NSString*)path;
- (BOOL)isWritableFileAtPath:(NSString*)path;
- (BOOL)isExecutableFileAtPath:(NSString*)path;
- (BOOL)isDeletableFileAtPath:(NSString*)path;

// Getting and Setting Attributes
- (NSArray*)componentsToDisplayForPath:(NSString*)path;
- (NSString*)displayNameAtPath:(NSString*)path;
- (NSDictionary*)attributesOfItemAtPath:(NSString*)path error:(NSError**)error;
- (NSDictionary*)attributesOfFileSystemForPath:(NSString*)path error:(NSError**)errorp;
- (BOOL)setAttributes:(NSDictionary*)attributes ofItemAtPath:(NSString*)path error:(NSError**)error;

// Getting and Comparing File Contents
- (NSData*)contentsAtPath:(NSString*)path;
- (BOOL)contentsEqualAtPath:(NSString*)path1 andPath:(NSString*)path2;

// Getting the Relationship Between Items
- (BOOL)getRelationship:(NSURLRelationship*)outRelationship
       ofDirectoryAtURL:(NSURL*)directoryURL
            toItemAtURL:(NSURL*)otherURL
                  error:(NSError**)error;

- (BOOL)getRelationship:(NSURLRelationship*)outRelationship
            ofDirectory:(NSSearchPathDirectory)directory
               inDomain:(NSSearchPathDomainMask)domainMask
            toItemAtURL:(NSURL*)url
                  error:(NSError**)error;

// Converting File Paths to Strings
- (const char*)fileSystemRepresentationWithPath:(NSString*)path;
- (NSString*)stringWithFileSystemRepresentation:(const char*)string length:(NSUInteger)length;

// Managing the Delegate
@property (assign) id delegate;

// Managing the Current Directory
- (BOOL)changeCurrentDirectoryPath:(NSString*)path;
@property (readonly, copy) NSString* currentDirectoryPath;

// Deprecated Methods
- (BOOL)copyPath:(NSString*)src toPath:(NSString*)dest handler:handler;
- (BOOL)movePath:(NSString*)src toPath:(NSString*)dest handler:handler;
- (BOOL)removeFileAtPath:(NSString*)path handler:handler;
- (BOOL)changeFileAttributes:(NSDictionary*)attributes atPath:(NSString*)path;
- (NSDictionary*)fileAttributesAtPath:(NSString*)path traverseLink:(BOOL)traverse;
- (NSDictionary*)fileSystemAttributesAtPath:(NSString*)path;
- (NSArray*)directoryContentsAtPath:(NSString*)path;
- (BOOL)createDirectoryAtPath:(NSString*)path attributes:(NSDictionary*)attributes;
- (BOOL)createSymbolicLinkAtPath:(NSString*)path pathContent:(NSString*)otherPath;
- (NSString*)pathContentOfSymbolicLinkAtPath:(NSString*)path;
- (BOOL)linkPath:(NSString*)source toPath:(NSString*)destination handler:(id)handler;
- (BOOL)removeItemAtPath:(NSString*)path error:(NSError**)error;
@end

@interface NSObject (NSFileManager_handler)
- (BOOL)fileManager:(NSFileManager*)fileManager shouldProceedAfterError:(NSDictionary*)dictionary;
- (void)fileManager:(NSFileManager*)fileManager willProcessPath:(NSString*)path;
@end

@interface NSDictionary (NSFileManager_fileAttributes)
- (NSDate*)fileModificationDate;
- (NSUInteger)filePosixPermissions;
- (NSString*)fileOwnerAccountName;
- (NSString*)fileGroupOwnerAccountName;
- (NSString*)fileType;
- (uint64_t)fileSize;
- (NSDate*)fileCreationDate;
@end

#endif /* _NSFILEMANAGER_H_ */