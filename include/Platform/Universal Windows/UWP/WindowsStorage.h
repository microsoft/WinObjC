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

// WindowsStorage.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSTORAGEEXPORT
#define OBJCUWPWINDOWSSTORAGEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsStorage.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSStorageLibrary, WSStorageFolder, WSStorageLibraryChangeTracker, WSKnownFolders, WSUserDataPaths, WSAppDataPaths, WSSystemDataPaths, WSStorageFile, WSDownloadsFolder, WSStorageLibraryChange, WSStorageLibraryChangeReader, WSStreamedFileDataRequest, WSStorageStreamTransaction, WSStorageProvider, WSFileIO, WSPathIO, WSCachedFileManager, WSSystemAudioProperties, WSSystemGPSProperties, WSSystemImageProperties, WSSystemMediaProperties, WSSystemMusicProperties, WSSystemPhotoProperties, WSSystemVideoProperties, WSSystemProperties, WSApplicationData, WSSetVersionRequest, WSApplicationDataContainer, WSSetVersionDeferral, WSApplicationDataContainerSettings, WSApplicationDataCompositeValue;
@protocol WSIStorageLibraryStatics, WSIStorageLibraryStatics2, WSIStorageLibrary, WSIStorageLibrary2, WSIStorageLibrary3, WSIKnownFoldersStatics, WSIKnownFoldersStatics2, WSIKnownFoldersStatics3, WSIKnownFoldersPlaylistsStatics, WSIKnownFoldersCameraRollStatics, WSIKnownFoldersSavedPicturesStatics, WSIUserDataPathsStatics, WSIUserDataPaths, WSIAppDataPathsStatics, WSIAppDataPaths, WSISystemDataPathsStatics, WSISystemDataPaths, WSIDownloadsFolderStatics, WSIDownloadsFolderStatics2, WSIStorageLibraryChange, WSIStorageItem, WSIStorageLibraryChangeReader, WSIStorageLibraryChangeTracker, WSIStreamedFileDataRequest, WSIStorageFileStatics, WSIStorageFolder, WSIStorageFile, WSIStorageFolderStatics, WSIStorageItem2, WSIStorageItemProperties, WSIStorageItemProperties2, WSIStorageItemPropertiesWithProvider, WSIStorageFilePropertiesWithAvailability, WSIStorageProvider, WSIStorageProvider2, WSIStorageFolder2, WSIStorageStreamTransaction, WSIStorageFile2, WSIFileIOStatics, WSIPathIOStatics, WSICachedFileManagerStatics, WSISystemAudioProperties, WSISystemGPSProperties, WSISystemImageProperties, WSISystemMediaProperties, WSISystemMusicProperties, WSISystemPhotoProperties, WSISystemVideoProperties, WSISystemProperties, WSIApplicationDataStatics, WSIApplicationDataStatics2, WSIApplicationData, WSIApplicationData2, WSIApplicationData3, WSISetVersionRequest, WSISetVersionDeferral, WSIApplicationDataContainer;

// Windows.Storage.KnownLibraryId
enum _WSKnownLibraryId {
    WSKnownLibraryIdMusic = 0,
    WSKnownLibraryIdPictures = 1,
    WSKnownLibraryIdVideos = 2,
    WSKnownLibraryIdDocuments = 3,
};
typedef unsigned WSKnownLibraryId;

// Windows.Storage.KnownFolderId
enum _WSKnownFolderId {
    WSKnownFolderIdAppCaptures = 0,
    WSKnownFolderIdCameraRoll = 1,
    WSKnownFolderIdDocumentsLibrary = 2,
    WSKnownFolderIdHomeGroup = 3,
    WSKnownFolderIdMediaServerDevices = 4,
    WSKnownFolderIdMusicLibrary = 5,
    WSKnownFolderIdObjects3D = 6,
    WSKnownFolderIdPicturesLibrary = 7,
    WSKnownFolderIdPlaylists = 8,
    WSKnownFolderIdRecordedCalls = 9,
    WSKnownFolderIdRemovableDevices = 10,
    WSKnownFolderIdSavedPictures = 11,
    WSKnownFolderIdScreenshots = 12,
    WSKnownFolderIdVideosLibrary = 13,
    WSKnownFolderIdAllAppMods = 14,
    WSKnownFolderIdCurrentAppMods = 15,
};
typedef unsigned WSKnownFolderId;

// Windows.Storage.CreationCollisionOption
enum _WSCreationCollisionOption {
    WSCreationCollisionOptionGenerateUniqueName = 0,
    WSCreationCollisionOptionReplaceExisting = 1,
    WSCreationCollisionOptionFailIfExists = 2,
    WSCreationCollisionOptionOpenIfExists = 3,
};
typedef unsigned WSCreationCollisionOption;

// Windows.Storage.NameCollisionOption
enum _WSNameCollisionOption {
    WSNameCollisionOptionGenerateUniqueName = 0,
    WSNameCollisionOptionReplaceExisting = 1,
    WSNameCollisionOptionFailIfExists = 2,
};
typedef unsigned WSNameCollisionOption;

// Windows.Storage.StorageDeleteOption
enum _WSStorageDeleteOption {
    WSStorageDeleteOptionDefault = 0,
    WSStorageDeleteOptionPermanentDelete = 1,
};
typedef unsigned WSStorageDeleteOption;

// Windows.Storage.StorageItemTypes
enum _WSStorageItemTypes {
    WSStorageItemTypesNone = 0,
    WSStorageItemTypesFile = 1,
    WSStorageItemTypesFolder = 2,
};
typedef unsigned WSStorageItemTypes;

// Windows.Storage.FileAttributes
enum _WSFileAttributes {
    WSFileAttributesNormal = 0,
    WSFileAttributesReadOnly = 1,
    WSFileAttributesDirectory = 16,
    WSFileAttributesArchive = 32,
    WSFileAttributesTemporary = 256,
    WSFileAttributesLocallyIncomplete = 512,
};
typedef unsigned WSFileAttributes;

// Windows.Storage.FileAccessMode
enum _WSFileAccessMode {
    WSFileAccessModeRead = 0,
    WSFileAccessModeReadWrite = 1,
};
typedef unsigned WSFileAccessMode;

// Windows.Storage.StorageLibraryChangeType
enum _WSStorageLibraryChangeType {
    WSStorageLibraryChangeTypeCreated = 0,
    WSStorageLibraryChangeTypeDeleted = 1,
    WSStorageLibraryChangeTypeMovedOrRenamed = 2,
    WSStorageLibraryChangeTypeContentsChanged = 3,
    WSStorageLibraryChangeTypeMovedOutOfLibrary = 4,
    WSStorageLibraryChangeTypeMovedIntoLibrary = 5,
    WSStorageLibraryChangeTypeContentsReplaced = 6,
    WSStorageLibraryChangeTypeIndexingStatusChanged = 7,
    WSStorageLibraryChangeTypeEncryptionChanged = 8,
    WSStorageLibraryChangeTypeChangeTrackingLost = 9,
};
typedef unsigned WSStorageLibraryChangeType;

// Windows.Storage.StreamedFileFailureMode
enum _WSStreamedFileFailureMode {
    WSStreamedFileFailureModeFailed = 0,
    WSStreamedFileFailureModeCurrentlyUnavailable = 1,
    WSStreamedFileFailureModeIncomplete = 2,
};
typedef unsigned WSStreamedFileFailureMode;

// Windows.Storage.StorageOpenOptions
enum _WSStorageOpenOptions {
    WSStorageOpenOptionsNone = 0,
    WSStorageOpenOptionsAllowOnlyReaders = 1,
    WSStorageOpenOptionsAllowReadersAndWriters = 2,
};
typedef unsigned WSStorageOpenOptions;

// Windows.Storage.ApplicationDataLocality
enum _WSApplicationDataLocality {
    WSApplicationDataLocalityLocal = 0,
    WSApplicationDataLocalityRoaming = 1,
    WSApplicationDataLocalityTemporary = 2,
    WSApplicationDataLocalityLocalCache = 3,
};
typedef unsigned WSApplicationDataLocality;

// Windows.Storage.ApplicationDataCreateDisposition
enum _WSApplicationDataCreateDisposition {
    WSApplicationDataCreateDispositionAlways = 0,
    WSApplicationDataCreateDispositionExisting = 1,
};
typedef unsigned WSApplicationDataCreateDisposition;

#include "WindowsStorageSearch.h"
#include "WindowsSystem.h"
#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsStorageFileProperties.h"
#include "WindowsStorageProvider.h"
// Windows.Storage.ApplicationDataSetVersionHandler
#ifndef __WSApplicationDataSetVersionHandler__DEFINED
#define __WSApplicationDataSetVersionHandler__DEFINED
typedef void(^WSApplicationDataSetVersionHandler)(WSSetVersionRequest* setVersionRequest);
#endif // __WSApplicationDataSetVersionHandler__DEFINED

// Windows.Storage.StreamedFileDataRequestedHandler
#ifndef __WSStreamedFileDataRequestedHandler__DEFINED
#define __WSStreamedFileDataRequestedHandler__DEFINED
typedef void(^WSStreamedFileDataRequestedHandler)(WSStreamedFileDataRequest* stream);
#endif // __WSStreamedFileDataRequestedHandler__DEFINED


#import <Foundation/Foundation.h>

// Windows.Storage.StreamedFileDataRequestedHandler
#ifndef __WSStreamedFileDataRequestedHandler__DEFINED
#define __WSStreamedFileDataRequestedHandler__DEFINED
typedef void(^WSStreamedFileDataRequestedHandler)(WSStreamedFileDataRequest* stream);
#endif // __WSStreamedFileDataRequestedHandler__DEFINED

// Windows.Storage.ApplicationDataSetVersionHandler
#ifndef __WSApplicationDataSetVersionHandler__DEFINED
#define __WSApplicationDataSetVersionHandler__DEFINED
typedef void(^WSApplicationDataSetVersionHandler)(WSSetVersionRequest* setVersionRequest);
#endif // __WSApplicationDataSetVersionHandler__DEFINED

// Windows.Storage.IStorageItem
#ifndef __WSIStorageItem_DEFINED__
#define __WSIStorageItem_DEFINED__

@protocol WSIStorageItem
@property (readonly) WSFileAttributes attributes;
@property (readonly) WFDateTime* dateCreated;
@property (readonly) NSString * name;
@property (readonly) NSString * path;
- (RTObject<WFIAsyncAction>*)renameAsyncOverloadDefaultOptions:(NSString *)desiredName;
- (RTObject<WFIAsyncAction>*)renameAsync:(NSString *)desiredName option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)deleteAsyncOverloadDefaultOptions;
- (RTObject<WFIAsyncAction>*)deleteAsync:(WSStorageDeleteOption)option;
- (void)getBasicPropertiesAsyncWithSuccess:(void (^)(WSFBasicProperties*))success failure:(void (^)(NSError*))failure;
- (BOOL)isOfType:(WSStorageItemTypes)type;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSIStorageItem : RTObject <WSIStorageItem>
@end

#endif // __WSIStorageItem_DEFINED__

// Windows.Storage.IStreamedFileDataRequest
#ifndef __WSIStreamedFileDataRequest_DEFINED__
#define __WSIStreamedFileDataRequest_DEFINED__

@protocol WSIStreamedFileDataRequest
- (void)failAndClose:(WSStreamedFileFailureMode)failureMode;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSIStreamedFileDataRequest : RTObject <WSIStreamedFileDataRequest>
@end

#endif // __WSIStreamedFileDataRequest_DEFINED__

// Windows.Storage.IStorageFolder
#ifndef __WSIStorageFolder_DEFINED__
#define __WSIStorageFolder_DEFINED__

@protocol WSIStorageFolder <WSIStorageItem>
- (void)createFileAsyncOverloadDefaultOptions:(NSString *)desiredName success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)createFileAsync:(NSString *)desiredName options:(WSCreationCollisionOption)options success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)createFolderAsyncOverloadDefaultOptions:(NSString *)desiredName success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (void)createFolderAsync:(NSString *)desiredName options:(WSCreationCollisionOption)options success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (void)getFileAsync:(NSString *)name success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)getFolderAsync:(NSString *)name success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (void)getItemAsync:(NSString *)name success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure;
- (void)getFilesAsyncOverloadDefaultOptionsStartAndCountWithSuccess:(void (^)(NSArray* /* WSStorageFile* */))success failure:(void (^)(NSError*))failure;
- (void)getFoldersAsyncOverloadDefaultOptionsStartAndCountWithSuccess:(void (^)(NSArray* /* WSStorageFolder* */))success failure:(void (^)(NSError*))failure;
- (void)getItemsAsyncOverloadDefaultStartAndCountWithSuccess:(void (^)(NSArray* /* RTObject<WSIStorageItem>* */))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)renameAsyncOverloadDefaultOptions:(NSString *)desiredName;
- (RTObject<WFIAsyncAction>*)renameAsync:(NSString *)desiredName option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)deleteAsyncOverloadDefaultOptions;
- (RTObject<WFIAsyncAction>*)deleteAsync:(WSStorageDeleteOption)option;
- (void)getBasicPropertiesAsyncWithSuccess:(void (^)(WSFBasicProperties*))success failure:(void (^)(NSError*))failure;
- (BOOL)isOfType:(WSStorageItemTypes)type;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSIStorageFolder : RTObject <WSIStorageFolder>
@end

#endif // __WSIStorageFolder_DEFINED__

// Windows.Storage.Streams.IRandomAccessStreamReference
#ifndef __WSSIRandomAccessStreamReference_DEFINED__
#define __WSSIRandomAccessStreamReference_DEFINED__

@protocol WSSIRandomAccessStreamReference
- (void)openReadAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSIRandomAccessStreamReference : RTObject <WSSIRandomAccessStreamReference>
@end

#endif // __WSSIRandomAccessStreamReference_DEFINED__

// Windows.Storage.Streams.IInputStreamReference
#ifndef __WSSIInputStreamReference_DEFINED__
#define __WSSIInputStreamReference_DEFINED__

@protocol WSSIInputStreamReference
- (void)openSequentialReadAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSIInputStreamReference : RTObject <WSSIInputStreamReference>
@end

#endif // __WSSIInputStreamReference_DEFINED__

// Windows.Storage.IStorageFile
#ifndef __WSIStorageFile_DEFINED__
#define __WSIStorageFile_DEFINED__

@protocol WSIStorageFile <WSIStorageItem, WSSIRandomAccessStreamReference, WSSIInputStreamReference>
@property (readonly) NSString * contentType;
@property (readonly) NSString * fileType;
- (void)openAsync:(WSFileAccessMode)accessMode success:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
- (void)openTransactedWriteAsyncWithSuccess:(void (^)(WSStorageStreamTransaction*))success failure:(void (^)(NSError*))failure;
- (void)copyOverloadDefaultNameAndOptions:(RTObject<WSIStorageFolder>*)destinationFolder success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)copyOverloadDefaultOptions:(RTObject<WSIStorageFolder>*)destinationFolder desiredNewName:(NSString *)desiredNewName success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)copyOverload:(RTObject<WSIStorageFolder>*)destinationFolder desiredNewName:(NSString *)desiredNewName option:(WSNameCollisionOption)option success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)copyAndReplaceAsync:(RTObject<WSIStorageFile>*)fileToReplace __attribute__ ((ns_returns_not_retained));
- (RTObject<WFIAsyncAction>*)moveOverloadDefaultNameAndOptions:(RTObject<WSIStorageFolder>*)destinationFolder;
- (RTObject<WFIAsyncAction>*)moveOverloadDefaultOptions:(RTObject<WSIStorageFolder>*)destinationFolder desiredNewName:(NSString *)desiredNewName;
- (RTObject<WFIAsyncAction>*)moveOverload:(RTObject<WSIStorageFolder>*)destinationFolder desiredNewName:(NSString *)desiredNewName option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)moveAndReplaceAsync:(RTObject<WSIStorageFile>*)fileToReplace;
- (RTObject<WFIAsyncAction>*)renameAsyncOverloadDefaultOptions:(NSString *)desiredName;
- (RTObject<WFIAsyncAction>*)renameAsync:(NSString *)desiredName option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)deleteAsyncOverloadDefaultOptions;
- (RTObject<WFIAsyncAction>*)deleteAsync:(WSStorageDeleteOption)option;
- (void)getBasicPropertiesAsyncWithSuccess:(void (^)(WSFBasicProperties*))success failure:(void (^)(NSError*))failure;
- (BOOL)isOfType:(WSStorageItemTypes)type;
- (void)openReadAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
- (void)openSequentialReadAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSIStorageFile : RTObject <WSIStorageFile>
@end

#endif // __WSIStorageFile_DEFINED__

// Windows.Storage.IStorageItem2
#ifndef __WSIStorageItem2_DEFINED__
#define __WSIStorageItem2_DEFINED__

@protocol WSIStorageItem2 <WSIStorageItem>
- (void)getParentAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (BOOL)IsEqual:(RTObject<WSIStorageItem>*)item;
- (RTObject<WFIAsyncAction>*)renameAsyncOverloadDefaultOptions:(NSString *)desiredName;
- (RTObject<WFIAsyncAction>*)renameAsync:(NSString *)desiredName option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)deleteAsyncOverloadDefaultOptions;
- (RTObject<WFIAsyncAction>*)deleteAsync:(WSStorageDeleteOption)option;
- (void)getBasicPropertiesAsyncWithSuccess:(void (^)(WSFBasicProperties*))success failure:(void (^)(NSError*))failure;
- (BOOL)isOfType:(WSStorageItemTypes)type;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSIStorageItem2 : RTObject <WSIStorageItem2>
@end

#endif // __WSIStorageItem2_DEFINED__

// Windows.Storage.IStorageItemProperties
#ifndef __WSIStorageItemProperties_DEFINED__
#define __WSIStorageItemProperties_DEFINED__

@protocol WSIStorageItemProperties
@property (readonly) NSString * displayName;
@property (readonly) NSString * displayType;
@property (readonly) NSString * folderRelativeId;
@property (readonly) WSFStorageItemContentProperties* properties;
- (void)getThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsync:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize options:(WSFThumbnailOptions)options success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSIStorageItemProperties : RTObject <WSIStorageItemProperties>
@end

#endif // __WSIStorageItemProperties_DEFINED__

// Windows.Storage.IStorageItemProperties2
#ifndef __WSIStorageItemProperties2_DEFINED__
#define __WSIStorageItemProperties2_DEFINED__

@protocol WSIStorageItemProperties2 <WSIStorageItemProperties>
- (void)getScaledImageAsThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsync:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize options:(WSFThumbnailOptions)options success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsync:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize options:(WSFThumbnailOptions)options success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSIStorageItemProperties2 : RTObject <WSIStorageItemProperties2>
@end

#endif // __WSIStorageItemProperties2_DEFINED__

// Windows.Storage.IStorageItemPropertiesWithProvider
#ifndef __WSIStorageItemPropertiesWithProvider_DEFINED__
#define __WSIStorageItemPropertiesWithProvider_DEFINED__

@protocol WSIStorageItemPropertiesWithProvider <WSIStorageItemProperties>
@property (readonly) WSStorageProvider* provider;
- (void)getThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsync:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize options:(WSFThumbnailOptions)options success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSIStorageItemPropertiesWithProvider : RTObject <WSIStorageItemPropertiesWithProvider>
@end

#endif // __WSIStorageItemPropertiesWithProvider_DEFINED__

// Windows.Storage.IStorageFilePropertiesWithAvailability
#ifndef __WSIStorageFilePropertiesWithAvailability_DEFINED__
#define __WSIStorageFilePropertiesWithAvailability_DEFINED__

@protocol WSIStorageFilePropertiesWithAvailability
@property (readonly) BOOL isAvailable;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSIStorageFilePropertiesWithAvailability : RTObject <WSIStorageFilePropertiesWithAvailability>
@end

#endif // __WSIStorageFilePropertiesWithAvailability_DEFINED__

// Windows.Storage.IStorageFolder2
#ifndef __WSIStorageFolder2_DEFINED__
#define __WSIStorageFolder2_DEFINED__

@protocol WSIStorageFolder2
- (void)tryGetItemAsync:(NSString *)name success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSIStorageFolder2 : RTObject <WSIStorageFolder2>
@end

#endif // __WSIStorageFolder2_DEFINED__

// Windows.Storage.IStorageFile2
#ifndef __WSIStorageFile2_DEFINED__
#define __WSIStorageFile2_DEFINED__

@protocol WSIStorageFile2
- (void)openWithOptionsAsync:(WSFileAccessMode)accessMode options:(WSStorageOpenOptions)options success:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
- (void)openTransactedWriteWithOptionsAsync:(WSStorageOpenOptions)options success:(void (^)(WSStorageStreamTransaction*))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSIStorageFile2 : RTObject <WSIStorageFile2>
@end

#endif // __WSIStorageFile2_DEFINED__

// Windows.Storage.StorageLibrary
#ifndef __WSStorageLibrary_DEFINED__
#define __WSStorageLibrary_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSStorageLibrary : RTObject
+ (void)getLibraryAsync:(WSKnownLibraryId)libraryId success:(void (^)(WSStorageLibrary*))success failure:(void (^)(NSError*))failure;
+ (void)getLibraryForUserAsync:(WSUser*)user libraryId:(WSKnownLibraryId)libraryId success:(void (^)(WSStorageLibrary*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray<RTObservableCollection>* /* WSStorageFolder* */ folders;
@property (readonly) WSStorageFolder* saveFolder;
@property (readonly) WSStorageLibraryChangeTracker* changeTracker;
- (EventRegistrationToken)addDefinitionChangedEvent:(void(^)(WSStorageLibrary*, RTObject*))del;
- (void)removeDefinitionChangedEvent:(EventRegistrationToken)tok;
- (void)requestAddFolderAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (void)requestRemoveFolderAsync:(WSStorageFolder*)folder success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)areFolderSuggestionsAvailableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSStorageLibrary_DEFINED__

// Windows.Storage.Search.IStorageFolderQueryOperations
#ifndef __WSSIStorageFolderQueryOperations_DEFINED__
#define __WSSIStorageFolderQueryOperations_DEFINED__

@protocol WSSIStorageFolderQueryOperations
- (void)getIndexedStateAsyncWithSuccess:(void (^)(WSSIndexedState))success failure:(void (^)(NSError*))failure;
- (WSSStorageFileQueryResult*)createFileQueryOverloadDefault;
- (WSSStorageFileQueryResult*)createFileQuery:(WSSCommonFileQuery)query;
- (WSSStorageFileQueryResult*)createFileQueryWithOptions:(WSSQueryOptions*)queryOptions;
- (WSSStorageFolderQueryResult*)createFolderQueryOverloadDefault;
- (WSSStorageFolderQueryResult*)createFolderQuery:(WSSCommonFolderQuery)query;
- (WSSStorageFolderQueryResult*)createFolderQueryWithOptions:(WSSQueryOptions*)queryOptions;
- (WSSStorageItemQueryResult*)createItemQuery;
- (WSSStorageItemQueryResult*)createItemQueryWithOptions:(WSSQueryOptions*)queryOptions;
- (void)getFilesAsync:(WSSCommonFileQuery)query startIndex:(unsigned int)startIndex maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve success:(void (^)(NSArray* /* WSStorageFile* */))success failure:(void (^)(NSError*))failure;
- (void)getFilesAsyncOverloadDefaultStartAndCount:(WSSCommonFileQuery)query success:(void (^)(NSArray* /* WSStorageFile* */))success failure:(void (^)(NSError*))failure;
- (void)getFoldersAsync:(WSSCommonFolderQuery)query startIndex:(unsigned int)startIndex maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve success:(void (^)(NSArray* /* WSStorageFolder* */))success failure:(void (^)(NSError*))failure;
- (void)getFoldersAsyncOverloadDefaultStartAndCount:(WSSCommonFolderQuery)query success:(void (^)(NSArray* /* WSStorageFolder* */))success failure:(void (^)(NSError*))failure;
- (void)getItemsAsync:(unsigned int)startIndex maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve success:(void (^)(NSArray* /* RTObject<WSIStorageItem>* */))success failure:(void (^)(NSError*))failure;
- (BOOL)areQueryOptionsSupported:(WSSQueryOptions*)queryOptions;
- (BOOL)isCommonFolderQuerySupported:(WSSCommonFolderQuery)query;
- (BOOL)isCommonFileQuerySupported:(WSSCommonFileQuery)query;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSIStorageFolderQueryOperations : RTObject <WSSIStorageFolderQueryOperations>
@end

#endif // __WSSIStorageFolderQueryOperations_DEFINED__

// Windows.Storage.StorageFolder
#ifndef __WSStorageFolder_DEFINED__
#define __WSStorageFolder_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSStorageFolder : RTObject <WSIStorageFolder, WSIStorageItem, WSSIStorageFolderQueryOperations, WSIStorageItemProperties, WSIStorageItemProperties2, WSIStorageItem2, WSIStorageFolder2, WSIStorageItemPropertiesWithProvider>
+ (void)getFolderFromPathAsync:(NSString *)path success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSFileAttributes attributes;
@property (readonly) WFDateTime* dateCreated;
@property (readonly) NSString * name;
@property (readonly) NSString * path;
@property (readonly) NSString * displayName;
@property (readonly) NSString * displayType;
@property (readonly) NSString * folderRelativeId;
@property (readonly) WSFStorageItemContentProperties* properties;
@property (readonly) WSStorageProvider* provider;
- (void)createFileAsyncOverloadDefaultOptions:(NSString *)desiredName success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)createFileAsync:(NSString *)desiredName options:(WSCreationCollisionOption)options success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)createFolderAsyncOverloadDefaultOptions:(NSString *)desiredName success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (void)createFolderAsync:(NSString *)desiredName options:(WSCreationCollisionOption)options success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (void)getFileAsync:(NSString *)name success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)getFolderAsync:(NSString *)name success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (void)getItemAsync:(NSString *)name success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure;
- (void)getFilesAsyncOverloadDefaultOptionsStartAndCountWithSuccess:(void (^)(NSArray* /* WSStorageFile* */))success failure:(void (^)(NSError*))failure;
- (void)getFoldersAsyncOverloadDefaultOptionsStartAndCountWithSuccess:(void (^)(NSArray* /* WSStorageFolder* */))success failure:(void (^)(NSError*))failure;
- (void)getItemsAsyncOverloadDefaultStartAndCountWithSuccess:(void (^)(NSArray* /* RTObject<WSIStorageItem>* */))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)renameAsyncOverloadDefaultOptions:(NSString *)desiredName;
- (RTObject<WFIAsyncAction>*)renameAsync:(NSString *)desiredName option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)deleteAsyncOverloadDefaultOptions;
- (RTObject<WFIAsyncAction>*)deleteAsync:(WSStorageDeleteOption)option;
- (void)getBasicPropertiesAsyncWithSuccess:(void (^)(WSFBasicProperties*))success failure:(void (^)(NSError*))failure;
- (BOOL)isOfType:(WSStorageItemTypes)type;
- (void)getIndexedStateAsyncWithSuccess:(void (^)(WSSIndexedState))success failure:(void (^)(NSError*))failure;
- (WSSStorageFileQueryResult*)createFileQueryOverloadDefault;
- (WSSStorageFileQueryResult*)createFileQuery:(WSSCommonFileQuery)query;
- (WSSStorageFileQueryResult*)createFileQueryWithOptions:(WSSQueryOptions*)queryOptions;
- (WSSStorageFolderQueryResult*)createFolderQueryOverloadDefault;
- (WSSStorageFolderQueryResult*)createFolderQuery:(WSSCommonFolderQuery)query;
- (WSSStorageFolderQueryResult*)createFolderQueryWithOptions:(WSSQueryOptions*)queryOptions;
- (WSSStorageItemQueryResult*)createItemQuery;
- (WSSStorageItemQueryResult*)createItemQueryWithOptions:(WSSQueryOptions*)queryOptions;
- (void)getFilesAsync:(WSSCommonFileQuery)query startIndex:(unsigned int)startIndex maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve success:(void (^)(NSArray* /* WSStorageFile* */))success failure:(void (^)(NSError*))failure;
- (void)getFilesAsyncOverloadDefaultStartAndCount:(WSSCommonFileQuery)query success:(void (^)(NSArray* /* WSStorageFile* */))success failure:(void (^)(NSError*))failure;
- (void)getFoldersAsync:(WSSCommonFolderQuery)query startIndex:(unsigned int)startIndex maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve success:(void (^)(NSArray* /* WSStorageFolder* */))success failure:(void (^)(NSError*))failure;
- (void)getFoldersAsyncOverloadDefaultStartAndCount:(WSSCommonFolderQuery)query success:(void (^)(NSArray* /* WSStorageFolder* */))success failure:(void (^)(NSError*))failure;
- (void)getItemsAsync:(unsigned int)startIndex maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve success:(void (^)(NSArray* /* RTObject<WSIStorageItem>* */))success failure:(void (^)(NSError*))failure;
- (BOOL)areQueryOptionsSupported:(WSSQueryOptions*)queryOptions;
- (BOOL)isCommonFolderQuerySupported:(WSSCommonFolderQuery)query;
- (BOOL)isCommonFileQuerySupported:(WSSCommonFileQuery)query;
- (void)getThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsync:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize options:(WSFThumbnailOptions)options success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsync:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize options:(WSFThumbnailOptions)options success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getParentAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (BOOL)IsEqual:(RTObject<WSIStorageItem>*)item;
- (void)tryGetItemAsync:(NSString *)name success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSStorageFolder_DEFINED__

// Windows.Storage.StorageLibraryChangeTracker
#ifndef __WSStorageLibraryChangeTracker_DEFINED__
#define __WSStorageLibraryChangeTracker_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSStorageLibraryChangeTracker : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WSStorageLibraryChangeReader*)getChangeReader;
- (void)enable;
- (void)reset;
@end

#endif // __WSStorageLibraryChangeTracker_DEFINED__

// Windows.Storage.KnownFolders
#ifndef __WSKnownFolders_DEFINED__
#define __WSKnownFolders_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSKnownFolders : RTObject
+ (void)getFolderForUserAsync:(WSUser*)user folderId:(WSKnownFolderId)folderId success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
+ (WSStorageFolder*)cameraRoll;
+ (WSStorageFolder*)playlists;
+ (WSStorageFolder*)savedPictures;
+ (WSStorageFolder*)documentsLibrary;
+ (WSStorageFolder*)homeGroup;
+ (WSStorageFolder*)mediaServerDevices;
+ (WSStorageFolder*)musicLibrary;
+ (WSStorageFolder*)picturesLibrary;
+ (WSStorageFolder*)removableDevices;
+ (WSStorageFolder*)videosLibrary;
+ (WSStorageFolder*)objects3D;
+ (WSStorageFolder*)recordedCalls;
+ (WSStorageFolder*)appCaptures;
@end

#endif // __WSKnownFolders_DEFINED__

// Windows.Storage.UserDataPaths
#ifndef __WSUserDataPaths_DEFINED__
#define __WSUserDataPaths_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSUserDataPaths : RTObject
+ (WSUserDataPaths*)getForUser:(WSUser*)user;
+ (WSUserDataPaths*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * cameraRoll;
@property (readonly) NSString * cookies;
@property (readonly) NSString * desktop;
@property (readonly) NSString * documents;
@property (readonly) NSString * downloads;
@property (readonly) NSString * favorites;
@property (readonly) NSString * history;
@property (readonly) NSString * internetCache;
@property (readonly) NSString * localAppData;
@property (readonly) NSString * localAppDataLow;
@property (readonly) NSString * music;
@property (readonly) NSString * pictures;
@property (readonly) NSString * profile;
@property (readonly) NSString * recent;
@property (readonly) NSString * roamingAppData;
@property (readonly) NSString * savedPictures;
@property (readonly) NSString * screenshots;
@property (readonly) NSString * templates;
@property (readonly) NSString * videos;
@end

#endif // __WSUserDataPaths_DEFINED__

// Windows.Storage.AppDataPaths
#ifndef __WSAppDataPaths_DEFINED__
#define __WSAppDataPaths_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSAppDataPaths : RTObject
+ (WSAppDataPaths*)getForUser:(WSUser*)user;
+ (WSAppDataPaths*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * cookies;
@property (readonly) NSString * desktop;
@property (readonly) NSString * documents;
@property (readonly) NSString * favorites;
@property (readonly) NSString * history;
@property (readonly) NSString * internetCache;
@property (readonly) NSString * localAppData;
@property (readonly) NSString * programData;
@property (readonly) NSString * roamingAppData;
@end

#endif // __WSAppDataPaths_DEFINED__

// Windows.Storage.SystemDataPaths
#ifndef __WSSystemDataPaths_DEFINED__
#define __WSSystemDataPaths_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSystemDataPaths : RTObject
+ (WSSystemDataPaths*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * fonts;
@property (readonly) NSString * programData;
@property (readonly) NSString * Public;
@property (readonly) NSString * publicDesktop;
@property (readonly) NSString * publicDocuments;
@property (readonly) NSString * publicDownloads;
@property (readonly) NSString * publicMusic;
@property (readonly) NSString * publicPictures;
@property (readonly) NSString * publicVideos;
@property (readonly) NSString * system;
@property (readonly) NSString * systemArm;
@property (readonly) NSString * systemHost;
@property (readonly) NSString * systemX64;
@property (readonly) NSString * systemX86;
@property (readonly) NSString * userProfiles;
@property (readonly) NSString * windows;
@end

#endif // __WSSystemDataPaths_DEFINED__

// Windows.Storage.StorageFile
#ifndef __WSStorageFile_DEFINED__
#define __WSStorageFile_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSStorageFile : RTObject <WSIStorageFile, WSSIInputStreamReference, WSSIRandomAccessStreamReference, WSIStorageItem, WSIStorageItemProperties, WSIStorageItemProperties2, WSIStorageItem2, WSIStorageItemPropertiesWithProvider, WSIStorageFilePropertiesWithAvailability, WSIStorageFile2>
+ (void)getFileFromPathAsync:(NSString *)path success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
+ (void)getFileFromApplicationUriAsync:(WFUri*)uri success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
+ (void)createStreamedFileAsync:(NSString *)displayNameWithExtension dataRequested:(WSStreamedFileDataRequestedHandler)dataRequested thumbnail:(RTObject<WSSIRandomAccessStreamReference>*)thumbnail success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
+ (void)replaceWithStreamedFileAsync:(RTObject<WSIStorageFile>*)fileToReplace dataRequested:(WSStreamedFileDataRequestedHandler)dataRequested thumbnail:(RTObject<WSSIRandomAccessStreamReference>*)thumbnail success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
+ (void)createStreamedFileFromUriAsync:(NSString *)displayNameWithExtension uri:(WFUri*)uri thumbnail:(RTObject<WSSIRandomAccessStreamReference>*)thumbnail success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
+ (void)replaceWithStreamedFileFromUriAsync:(RTObject<WSIStorageFile>*)fileToReplace uri:(WFUri*)uri thumbnail:(RTObject<WSSIRandomAccessStreamReference>*)thumbnail success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * contentType;
@property (readonly) NSString * fileType;
@property (readonly) BOOL isAvailable;
@property (readonly) WSFileAttributes attributes;
@property (readonly) WFDateTime* dateCreated;
@property (readonly) NSString * name;
@property (readonly) NSString * path;
@property (readonly) NSString * displayType;
@property (readonly) NSString * folderRelativeId;
@property (readonly) WSFStorageItemContentProperties* properties;
@property (readonly) NSString * displayName;
@property (readonly) WSStorageProvider* provider;
- (void)openAsync:(WSFileAccessMode)accessMode success:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
- (void)openTransactedWriteAsyncWithSuccess:(void (^)(WSStorageStreamTransaction*))success failure:(void (^)(NSError*))failure;
- (void)copyOverloadDefaultNameAndOptions:(RTObject<WSIStorageFolder>*)destinationFolder success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)copyOverloadDefaultOptions:(RTObject<WSIStorageFolder>*)destinationFolder desiredNewName:(NSString *)desiredNewName success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)copyOverload:(RTObject<WSIStorageFolder>*)destinationFolder desiredNewName:(NSString *)desiredNewName option:(WSNameCollisionOption)option success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)copyAndReplaceAsync:(RTObject<WSIStorageFile>*)fileToReplace __attribute__ ((ns_returns_not_retained));
- (RTObject<WFIAsyncAction>*)moveOverloadDefaultNameAndOptions:(RTObject<WSIStorageFolder>*)destinationFolder;
- (RTObject<WFIAsyncAction>*)moveOverloadDefaultOptions:(RTObject<WSIStorageFolder>*)destinationFolder desiredNewName:(NSString *)desiredNewName;
- (RTObject<WFIAsyncAction>*)moveOverload:(RTObject<WSIStorageFolder>*)destinationFolder desiredNewName:(NSString *)desiredNewName option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)moveAndReplaceAsync:(RTObject<WSIStorageFile>*)fileToReplace;
- (RTObject<WFIAsyncAction>*)renameAsyncOverloadDefaultOptions:(NSString *)desiredName;
- (RTObject<WFIAsyncAction>*)renameAsync:(NSString *)desiredName option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)deleteAsyncOverloadDefaultOptions;
- (RTObject<WFIAsyncAction>*)deleteAsync:(WSStorageDeleteOption)option;
- (void)getBasicPropertiesAsyncWithSuccess:(void (^)(WSFBasicProperties*))success failure:(void (^)(NSError*))failure;
- (BOOL)isOfType:(WSStorageItemTypes)type;
- (void)openReadAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
- (void)openSequentialReadAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsync:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize options:(WSFThumbnailOptions)options success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsync:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize options:(WSFThumbnailOptions)options success:(void (^)(WSFStorageItemThumbnail*))success failure:(void (^)(NSError*))failure;
- (void)getParentAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (BOOL)IsEqual:(RTObject<WSIStorageItem>*)item;
- (void)openWithOptionsAsync:(WSFileAccessMode)accessMode options:(WSStorageOpenOptions)options success:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
- (void)openTransactedWriteWithOptionsAsync:(WSStorageOpenOptions)options success:(void (^)(WSStorageStreamTransaction*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSStorageFile_DEFINED__

// Windows.Storage.DownloadsFolder
#ifndef __WSDownloadsFolder_DEFINED__
#define __WSDownloadsFolder_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSDownloadsFolder : RTObject
+ (void)createFileForUserAsync:(WSUser*)user desiredName:(NSString *)desiredName success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
+ (void)createFolderForUserAsync:(WSUser*)user desiredName:(NSString *)desiredName success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
+ (void)createFileForUserWithCollisionOptionAsync:(WSUser*)user desiredName:(NSString *)desiredName option:(WSCreationCollisionOption)option success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
+ (void)createFolderForUserWithCollisionOptionAsync:(WSUser*)user desiredName:(NSString *)desiredName option:(WSCreationCollisionOption)option success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
+ (void)createFileAsync:(NSString *)desiredName success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
+ (void)createFolderAsync:(NSString *)desiredName success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
+ (void)createFileWithCollisionOptionAsync:(NSString *)desiredName option:(WSCreationCollisionOption)option success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
+ (void)createFolderWithCollisionOptionAsync:(NSString *)desiredName option:(WSCreationCollisionOption)option success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSDownloadsFolder_DEFINED__

// Windows.Storage.StorageLibraryChange
#ifndef __WSStorageLibraryChange_DEFINED__
#define __WSStorageLibraryChange_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSStorageLibraryChange : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSStorageLibraryChangeType changeType;
@property (readonly) NSString * path;
@property (readonly) NSString * previousPath;
- (BOOL)isOfType:(WSStorageItemTypes)type;
- (void)getStorageItemAsyncWithSuccess:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSStorageLibraryChange_DEFINED__

// Windows.Storage.StorageLibraryChangeReader
#ifndef __WSStorageLibraryChangeReader_DEFINED__
#define __WSStorageLibraryChangeReader_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSStorageLibraryChangeReader : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)readBatchAsyncWithSuccess:(void (^)(NSArray* /* WSStorageLibraryChange* */))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)acceptChangesAsync;
@end

#endif // __WSStorageLibraryChangeReader_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Storage.Streams.IOutputStream
#ifndef __WSSIOutputStream_DEFINED__
#define __WSSIOutputStream_DEFINED__

@protocol WSSIOutputStream <WFIClosable>
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer success:(void (^)(unsigned int))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSIOutputStream : RTObject <WSSIOutputStream>
@end

#endif // __WSSIOutputStream_DEFINED__

// Windows.Storage.StreamedFileDataRequest
#ifndef __WSStreamedFileDataRequest_DEFINED__
#define __WSStreamedFileDataRequest_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSStreamedFileDataRequest : RTObject <WSSIOutputStream, WFIClosable, WSIStreamedFileDataRequest>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer success:(void (^)(unsigned int))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
- (void)failAndClose:(WSStreamedFileFailureMode)failureMode;
@end

#endif // __WSStreamedFileDataRequest_DEFINED__

// Windows.Storage.StorageStreamTransaction
#ifndef __WSStorageStreamTransaction_DEFINED__
#define __WSStorageStreamTransaction_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSStorageStreamTransaction : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIRandomAccessStream>* stream;
- (RTObject<WFIAsyncAction>*)commitAsync;
- (void)close;
@end

#endif // __WSStorageStreamTransaction_DEFINED__

// Windows.Storage.StorageProvider
#ifndef __WSStorageProvider_DEFINED__
#define __WSStorageProvider_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSStorageProvider : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayName;
@property (readonly) NSString * id;
- (void)isPropertySupportedForPartialFileAsync:(NSString *)propertyCanonicalName success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSStorageProvider_DEFINED__

// Windows.Storage.FileIO
#ifndef __WSFileIO_DEFINED__
#define __WSFileIO_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSFileIO : RTObject
+ (void)readTextAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
+ (void)readTextWithEncodingAsync:(RTObject<WSIStorageFile>*)file encoding:(WSSUnicodeEncoding)encoding success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)writeTextAsync:(RTObject<WSIStorageFile>*)file contents:(NSString *)contents;
+ (RTObject<WFIAsyncAction>*)writeTextWithEncodingAsync:(RTObject<WSIStorageFile>*)file contents:(NSString *)contents encoding:(WSSUnicodeEncoding)encoding;
+ (RTObject<WFIAsyncAction>*)appendTextAsync:(RTObject<WSIStorageFile>*)file contents:(NSString *)contents;
+ (RTObject<WFIAsyncAction>*)appendTextWithEncodingAsync:(RTObject<WSIStorageFile>*)file contents:(NSString *)contents encoding:(WSSUnicodeEncoding)encoding;
+ (void)readLinesAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(NSMutableArray* /* NSString * */))success failure:(void (^)(NSError*))failure;
+ (void)readLinesWithEncodingAsync:(RTObject<WSIStorageFile>*)file encoding:(WSSUnicodeEncoding)encoding success:(void (^)(NSMutableArray* /* NSString * */))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)writeLinesAsync:(RTObject<WSIStorageFile>*)file lines:(id<NSFastEnumeration> /* NSString * */)lines;
+ (RTObject<WFIAsyncAction>*)writeLinesWithEncodingAsync:(RTObject<WSIStorageFile>*)file lines:(id<NSFastEnumeration> /* NSString * */)lines encoding:(WSSUnicodeEncoding)encoding;
+ (RTObject<WFIAsyncAction>*)appendLinesAsync:(RTObject<WSIStorageFile>*)file lines:(id<NSFastEnumeration> /* NSString * */)lines;
+ (RTObject<WFIAsyncAction>*)appendLinesWithEncodingAsync:(RTObject<WSIStorageFile>*)file lines:(id<NSFastEnumeration> /* NSString * */)lines encoding:(WSSUnicodeEncoding)encoding;
+ (void)readBufferAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)writeBufferAsync:(RTObject<WSIStorageFile>*)file buffer:(RTObject<WSSIBuffer>*)buffer;
+ (RTObject<WFIAsyncAction>*)writeBytesAsync:(RTObject<WSIStorageFile>*)file buffer:(NSArray* /* uint8_t */)buffer;
@end

#endif // __WSFileIO_DEFINED__

// Windows.Storage.PathIO
#ifndef __WSPathIO_DEFINED__
#define __WSPathIO_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSPathIO : RTObject
+ (void)readTextAsync:(NSString *)absolutePath success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
+ (void)readTextWithEncodingAsync:(NSString *)absolutePath encoding:(WSSUnicodeEncoding)encoding success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)writeTextAsync:(NSString *)absolutePath contents:(NSString *)contents;
+ (RTObject<WFIAsyncAction>*)writeTextWithEncodingAsync:(NSString *)absolutePath contents:(NSString *)contents encoding:(WSSUnicodeEncoding)encoding;
+ (RTObject<WFIAsyncAction>*)appendTextAsync:(NSString *)absolutePath contents:(NSString *)contents;
+ (RTObject<WFIAsyncAction>*)appendTextWithEncodingAsync:(NSString *)absolutePath contents:(NSString *)contents encoding:(WSSUnicodeEncoding)encoding;
+ (void)readLinesAsync:(NSString *)absolutePath success:(void (^)(NSMutableArray* /* NSString * */))success failure:(void (^)(NSError*))failure;
+ (void)readLinesWithEncodingAsync:(NSString *)absolutePath encoding:(WSSUnicodeEncoding)encoding success:(void (^)(NSMutableArray* /* NSString * */))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)writeLinesAsync:(NSString *)absolutePath lines:(id<NSFastEnumeration> /* NSString * */)lines;
+ (RTObject<WFIAsyncAction>*)writeLinesWithEncodingAsync:(NSString *)absolutePath lines:(id<NSFastEnumeration> /* NSString * */)lines encoding:(WSSUnicodeEncoding)encoding;
+ (RTObject<WFIAsyncAction>*)appendLinesAsync:(NSString *)absolutePath lines:(id<NSFastEnumeration> /* NSString * */)lines;
+ (RTObject<WFIAsyncAction>*)appendLinesWithEncodingAsync:(NSString *)absolutePath lines:(id<NSFastEnumeration> /* NSString * */)lines encoding:(WSSUnicodeEncoding)encoding;
+ (void)readBufferAsync:(NSString *)absolutePath success:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)writeBufferAsync:(NSString *)absolutePath buffer:(RTObject<WSSIBuffer>*)buffer;
+ (RTObject<WFIAsyncAction>*)writeBytesAsync:(NSString *)absolutePath buffer:(NSArray* /* uint8_t */)buffer;
@end

#endif // __WSPathIO_DEFINED__

// Windows.Storage.CachedFileManager
#ifndef __WSCachedFileManager_DEFINED__
#define __WSCachedFileManager_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSCachedFileManager : RTObject
+ (void)deferUpdates:(RTObject<WSIStorageFile>*)file;
+ (void)completeUpdatesAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(WSPFileUpdateStatus))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSCachedFileManager_DEFINED__

// Windows.Storage.SystemAudioProperties
#ifndef __WSSystemAudioProperties_DEFINED__
#define __WSSystemAudioProperties_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSystemAudioProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * encodingBitrate;
@end

#endif // __WSSystemAudioProperties_DEFINED__

// Windows.Storage.SystemGPSProperties
#ifndef __WSSystemGPSProperties_DEFINED__
#define __WSSystemGPSProperties_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSystemGPSProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * latitudeDecimal;
@property (readonly) NSString * longitudeDecimal;
@end

#endif // __WSSystemGPSProperties_DEFINED__

// Windows.Storage.SystemImageProperties
#ifndef __WSSystemImageProperties_DEFINED__
#define __WSSystemImageProperties_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSystemImageProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * horizontalSize;
@property (readonly) NSString * verticalSize;
@end

#endif // __WSSystemImageProperties_DEFINED__

// Windows.Storage.SystemMediaProperties
#ifndef __WSSystemMediaProperties_DEFINED__
#define __WSSystemMediaProperties_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSystemMediaProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * duration;
@property (readonly) NSString * producer;
@property (readonly) NSString * publisher;
@property (readonly) NSString * subTitle;
@property (readonly) NSString * writer;
@property (readonly) NSString * year;
@end

#endif // __WSSystemMediaProperties_DEFINED__

// Windows.Storage.SystemMusicProperties
#ifndef __WSSystemMusicProperties_DEFINED__
#define __WSSystemMusicProperties_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSystemMusicProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * albumArtist;
@property (readonly) NSString * albumTitle;
@property (readonly) NSString * artist;
@property (readonly) NSString * composer;
@property (readonly) NSString * conductor;
@property (readonly) NSString * displayArtist;
@property (readonly) NSString * genre;
@property (readonly) NSString * trackNumber;
@end

#endif // __WSSystemMusicProperties_DEFINED__

// Windows.Storage.SystemPhotoProperties
#ifndef __WSSystemPhotoProperties_DEFINED__
#define __WSSystemPhotoProperties_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSystemPhotoProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * cameraManufacturer;
@property (readonly) NSString * cameraModel;
@property (readonly) NSString * dateTaken;
@property (readonly) NSString * orientation;
@property (readonly) NSString * peopleNames;
@end

#endif // __WSSystemPhotoProperties_DEFINED__

// Windows.Storage.SystemVideoProperties
#ifndef __WSSystemVideoProperties_DEFINED__
#define __WSSystemVideoProperties_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSystemVideoProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * director;
@property (readonly) NSString * frameHeight;
@property (readonly) NSString * frameWidth;
@property (readonly) NSString * orientation;
@property (readonly) NSString * totalBitrate;
@end

#endif // __WSSystemVideoProperties_DEFINED__

// Windows.Storage.SystemProperties
#ifndef __WSSystemProperties_DEFINED__
#define __WSSystemProperties_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSystemProperties : RTObject
+ (WSSystemAudioProperties*)audio;
+ (NSString *)author;
+ (NSString *)comment;
+ (WSSystemGPSProperties*)gPS;
+ (WSSystemImageProperties*)image;
+ (NSString *)itemNameDisplay;
+ (NSString *)keywords;
+ (WSSystemMediaProperties*)media;
+ (WSSystemMusicProperties*)music;
+ (WSSystemPhotoProperties*)photo;
+ (NSString *)rating;
+ (NSString *)title;
+ (WSSystemVideoProperties*)video;
@end

#endif // __WSSystemProperties_DEFINED__

// Windows.Storage.ApplicationData
#ifndef __WSApplicationData_DEFINED__
#define __WSApplicationData_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSApplicationData : RTObject
+ (void)getForUserAsync:(WSUser*)user success:(void (^)(WSApplicationData*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSStorageFolder* localFolder;
@property (readonly) WSApplicationDataContainer* localSettings;
@property (readonly) WSStorageFolder* roamingFolder;
@property (readonly) WSApplicationDataContainer* roamingSettings;
@property (readonly) uint64_t roamingStorageQuota;
@property (readonly) WSStorageFolder* temporaryFolder;
@property (readonly) unsigned int Version;
@property (readonly) WSStorageFolder* localCacheFolder;
@property (readonly) WSStorageFolder* sharedLocalFolder;
+ (WSApplicationData*)current;
- (EventRegistrationToken)addDataChangedEvent:(void(^)(WSApplicationData*, RTObject*))del;
- (void)removeDataChangedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)setVersionAsync:(unsigned int)desiredVersion handler:(WSApplicationDataSetVersionHandler)handler;
- (RTObject<WFIAsyncAction>*)clearAllAsync;
- (RTObject<WFIAsyncAction>*)clearAsync:(WSApplicationDataLocality)locality;
- (void)signalDataChanged;
- (WSStorageFolder*)getPublisherCacheFolder:(NSString *)folderName;
- (RTObject<WFIAsyncAction>*)clearPublisherCacheFolderAsync:(NSString *)folderName;
@end

#endif // __WSApplicationData_DEFINED__

// Windows.Storage.SetVersionRequest
#ifndef __WSSetVersionRequest_DEFINED__
#define __WSSetVersionRequest_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSetVersionRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int currentVersion;
@property (readonly) unsigned int desiredVersion;
- (WSSetVersionDeferral*)getDeferral;
@end

#endif // __WSSetVersionRequest_DEFINED__

// Windows.Storage.ApplicationDataContainer
#ifndef __WSApplicationDataContainer_DEFINED__
#define __WSApplicationDataContainer_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSApplicationDataContainer : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSDictionary* /* NSString *, WSApplicationDataContainer* */ containers;
@property (readonly) WSApplicationDataLocality locality;
@property (readonly) NSString * name;
@property (readonly) RTObject<WFCIPropertySet>* values;
- (WSApplicationDataContainer*)createContainer:(NSString *)name disposition:(WSApplicationDataCreateDisposition)disposition;
- (void)deleteContainer:(NSString *)name;
@end

#endif // __WSApplicationDataContainer_DEFINED__

// Windows.Storage.SetVersionDeferral
#ifndef __WSSetVersionDeferral_DEFINED__
#define __WSSetVersionDeferral_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSSetVersionDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WSSetVersionDeferral_DEFINED__

// Windows.Foundation.Collections.IPropertySet
#ifndef __WFCIPropertySet_DEFINED__
#define __WFCIPropertySet_DEFINED__

@protocol WFCIPropertySet
- (id)objectForKey: (id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject: (id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

-(void)setObject: (id)obj forKey: (id)key;
-(void)setObject:(id)object forKeyedSubscript:(id)key;
-(void)removeObjectForKey: (id)key;
-(void)removeAllObjects;
-(void)removeObjectsForKeys:(NSArray*)keys;
-(void)addEntriesFromDictionary:(NSDictionary*)otherDict;
-(void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;
-(void)setDictionary: (NSDictionary*)dict;
-(EventRegistrationToken)addObserver: (RTCollectionListener)receiver;
-(void)removeObserver: (EventRegistrationToken)receiverToken;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WFCIPropertySet : RTObject <WFCIPropertySet>
@end

#endif // __WFCIPropertySet_DEFINED__

// Windows.Storage.ApplicationDataContainerSettings
#ifndef __WSApplicationDataContainerSettings_DEFINED__
#define __WSApplicationDataContainerSettings_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSApplicationDataContainerSettings : RTObject <WFCIPropertySet>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
// Could not generate add_MapChanged (Can't marshal Windows.Foundation.Collections.MapChangedEventHandler`2<String,System.Object>)
- (void)removeMapChangedEvent:(EventRegistrationToken)tok;
- (id)objectForKey: (id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject: (id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

-(void)setObject: (id)obj forKey: (id)key;
-(void)setObject:(id)object forKeyedSubscript:(id)key;
-(void)removeObjectForKey: (id)key;
-(void)removeAllObjects;
-(void)removeObjectsForKeys:(NSArray*)keys;
-(void)addEntriesFromDictionary:(NSDictionary*)otherDict;
-(void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;
-(void)setDictionary: (NSDictionary*)dict;
-(EventRegistrationToken)addObserver: (RTCollectionListener)receiver;
-(void)removeObserver: (EventRegistrationToken)receiverToken;
@end

#endif // __WSApplicationDataContainerSettings_DEFINED__

// Windows.Storage.ApplicationDataCompositeValue
#ifndef __WSApplicationDataCompositeValue_DEFINED__
#define __WSApplicationDataCompositeValue_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSApplicationDataCompositeValue : RTObject <WFCIPropertySet>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
// Could not generate add_MapChanged (Can't marshal Windows.Foundation.Collections.MapChangedEventHandler`2<String,System.Object>)
- (void)removeMapChangedEvent:(EventRegistrationToken)tok;
- (id)objectForKey: (id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject: (id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

-(void)setObject: (id)obj forKey: (id)key;
-(void)setObject:(id)object forKeyedSubscript:(id)key;
-(void)removeObjectForKey: (id)key;
-(void)removeAllObjects;
-(void)removeObjectsForKeys:(NSArray*)keys;
-(void)addEntriesFromDictionary:(NSDictionary*)otherDict;
-(void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;
-(void)setDictionary: (NSDictionary*)dict;
-(EventRegistrationToken)addObserver: (RTCollectionListener)receiver;
-(void)removeObserver: (EventRegistrationToken)receiverToken;
@end

#endif // __WSApplicationDataCompositeValue_DEFINED__

