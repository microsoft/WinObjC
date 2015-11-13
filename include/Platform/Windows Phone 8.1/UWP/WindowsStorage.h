//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include "interopBase.h"
@class WSStorageLibrary, WSStorageFolder, WSKnownFolders, WSStorageFile, WSDownloadsFolder, WSStreamedFileDataRequest,
    WSStorageStreamTransaction, WSStorageProvider, WSFileIO, WSPathIO, WSCachedFileManager, WSSystemAudioProperties, WSSystemGPSProperties,
    WSSystemImageProperties, WSSystemMediaProperties, WSSystemMusicProperties, WSSystemPhotoProperties, WSSystemVideoProperties,
    WSSystemProperties, WSApplicationData, WSSetVersionRequest, WSApplicationDataContainer, WSSetVersionDeferral,
    WSApplicationDataContainerSettings, WSApplicationDataCompositeValue;
@protocol WSIStorageLibraryStatics
, WSIStorageLibrary, WSIKnownFoldersStatics, WSIKnownFoldersPlaylistsStatics, WSIKnownFoldersCameraRollStatics,
    WSIKnownFoldersSavedPicturesStatics, WSIDownloadsFolderStatics, WSIStreamedFileDataRequest, WSIStorageFileStatics, WSIStorageItem,
    WSIStorageFolder, WSIStorageFile, WSIStorageFolderStatics, WSIStorageItem2, WSIStorageItemProperties, WSIStorageItemProperties2,
    WSIStorageItemPropertiesWithProvider, WSIStorageFilePropertiesWithAvailability, WSIStorageProvider, WSIStorageFolder2, WSIFileIOStatics,
    WSIPathIOStatics, WSICachedFileManagerStatics, WSISystemAudioProperties, WSISystemGPSProperties, WSISystemImageProperties,
    WSISystemMediaProperties, WSISystemMusicProperties, WSISystemPhotoProperties, WSISystemVideoProperties, WSISystemProperties,
    WSIStorageStreamTransaction, WSIApplicationDataStatics, WSIApplicationData, WSISetVersionRequest, WSISetVersionDeferral,
    WSIApplicationDataContainer;

// Windows.Storage.KnownLibraryId
enum _WSKnownLibraryId {
    WSKnownLibraryIdMusic = 0,
    WSKnownLibraryIdPictures = 1,
    WSKnownLibraryIdVideos = 2,
    WSKnownLibraryIdDocuments = 3,
};
typedef unsigned WSKnownLibraryId;

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

// Windows.Storage.StreamedFileFailureMode
enum _WSStreamedFileFailureMode {
    WSStreamedFileFailureModeFailed = 0,
    WSStreamedFileFailureModeCurrentlyUnavailable = 1,
    WSStreamedFileFailureModeIncomplete = 2,
};
typedef unsigned WSStreamedFileFailureMode;

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
#include "WindowsFoundation.h"
#include "WindowsStorageFileProperties.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageProvider.h"
// Windows.Storage.ApplicationDataSetVersionHandler
#ifndef __WSApplicationDataSetVersionHandler__DEFINED
#define __WSApplicationDataSetVersionHandler__DEFINED
typedef void (^WSApplicationDataSetVersionHandler)(WSSetVersionRequest* setVersionRequest);
#endif // __WSApplicationDataSetVersionHandler__DEFINED

// Windows.Storage.StreamedFileDataRequestedHandler
#ifndef __WSStreamedFileDataRequestedHandler__DEFINED
#define __WSStreamedFileDataRequestedHandler__DEFINED
typedef void (^WSStreamedFileDataRequestedHandler)(WSStreamedFileDataRequest* stream);
#endif // __WSStreamedFileDataRequestedHandler__DEFINED

#import <Foundation/Foundation.h>

// Windows.Storage.StreamedFileDataRequestedHandler
#ifndef __WSStreamedFileDataRequestedHandler__DEFINED
#define __WSStreamedFileDataRequestedHandler__DEFINED
typedef void (^WSStreamedFileDataRequestedHandler)(WSStreamedFileDataRequest* stream);
#endif // __WSStreamedFileDataRequestedHandler__DEFINED

// Windows.Storage.ApplicationDataSetVersionHandler
#ifndef __WSApplicationDataSetVersionHandler__DEFINED
#define __WSApplicationDataSetVersionHandler__DEFINED
typedef void (^WSApplicationDataSetVersionHandler)(WSSetVersionRequest* setVersionRequest);
#endif // __WSApplicationDataSetVersionHandler__DEFINED

// Windows.Storage.IStreamedFileDataRequest
#ifndef __WSIStreamedFileDataRequest_DEFINED__
#define __WSIStreamedFileDataRequest_DEFINED__

@protocol WSIStreamedFileDataRequest
- (void)failAndClose:(WSStreamedFileFailureMode)failureMode;
@end

#endif // __WSIStreamedFileDataRequest_DEFINED__

// Windows.Storage.IStorageItem
#ifndef __WSIStorageItem_DEFINED__
#define __WSIStorageItem_DEFINED__

@protocol WSIStorageItem
@property (readonly) WSFileAttributes attributes;
@property (readonly) WFDateTime* dateCreated;
@property (readonly) NSString* name;
@property (readonly) NSString* path;
- (RTObject<WFIAsyncAction>*)renameAsyncOverloadDefaultOptions:(NSString*)desiredName;
- (RTObject<WFIAsyncAction>*)renameAsync:(NSString*)desiredName option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)deleteAsyncOverloadDefaultOptions;
- (RTObject<WFIAsyncAction>*)deleteAsync:(WSStorageDeleteOption)option;
- (void)getBasicPropertiesAsyncWithSuccess:(void (^)(WSFBasicProperties*))success failure:(void (^)(NSError*))failure;
- (BOOL)isOfType:(WSStorageItemTypes)type;
@end

#endif // __WSIStorageItem_DEFINED__

// Windows.Storage.IStorageFolder
#ifndef __WSIStorageFolder_DEFINED__
#define __WSIStorageFolder_DEFINED__

@protocol WSIStorageFolder <WSIStorageItem>
- (void)createFileAsyncOverloadDefaultOptions:(NSString*)desiredName
                                      success:(void (^)(WSStorageFile*))success
                                      failure:(void (^)(NSError*))failure;
- (void)createFileAsync:(NSString*)desiredName
                options:(WSCreationCollisionOption)options
                success:(void (^)(WSStorageFile*))success
                failure:(void (^)(NSError*))failure;
- (void)createFolderAsyncOverloadDefaultOptions:(NSString*)desiredName
                                        success:(void (^)(WSStorageFolder*))success
                                        failure:(void (^)(NSError*))failure;
- (void)createFolderAsync:(NSString*)desiredName
                  options:(WSCreationCollisionOption)options
                  success:(void (^)(WSStorageFolder*))success
                  failure:(void (^)(NSError*))failure;
- (void)getFileAsync:(NSString*)name success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)getFolderAsync:(NSString*)name success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (void)getItemAsync:(NSString*)name success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure;
- (void)getFilesAsyncOverloadDefaultOptionsStartAndCountWithSuccess:(void (^)(id<NSFastEnumeration> /*WSStorageFile*/))success
                                                            failure:(void (^)(NSError*))failure;
- (void)getFoldersAsyncOverloadDefaultOptionsStartAndCountWithSuccess:(void (^)(id<NSFastEnumeration> /*WSStorageFolder*/))success
                                                              failure:(void (^)(NSError*))failure;
- (void)getItemsAsyncOverloadDefaultStartAndCountWithSuccess:(void (^)(id<NSFastEnumeration> /*WSIStorageItem*/))success
                                                     failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)renameAsyncOverloadDefaultOptions:(NSString*)desiredName;
- (RTObject<WFIAsyncAction>*)renameAsync:(NSString*)desiredName option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)deleteAsyncOverloadDefaultOptions;
- (RTObject<WFIAsyncAction>*)deleteAsync:(WSStorageDeleteOption)option;
- (void)getBasicPropertiesAsyncWithSuccess:(void (^)(WSFBasicProperties*))success failure:(void (^)(NSError*))failure;
- (BOOL)isOfType:(WSStorageItemTypes)type;
@end

#endif // __WSIStorageFolder_DEFINED__

// Windows.Storage.Streams.IRandomAccessStreamReference
#ifndef __WSSIRandomAccessStreamReference_DEFINED__
#define __WSSIRandomAccessStreamReference_DEFINED__

@protocol WSSIRandomAccessStreamReference
- (void)openReadAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSIRandomAccessStreamReference_DEFINED__

// Windows.Storage.Streams.IInputStreamReference
#ifndef __WSSIInputStreamReference_DEFINED__
#define __WSSIInputStreamReference_DEFINED__

@protocol WSSIInputStreamReference
- (void)openSequentialReadAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSIInputStreamReference_DEFINED__

// Windows.Storage.IStorageFile
#ifndef __WSIStorageFile_DEFINED__
#define __WSIStorageFile_DEFINED__

@protocol WSIStorageFile <WSIStorageItem, WSSIRandomAccessStreamReference, WSSIInputStreamReference>
@property (readonly) NSString* contentType;
@property (readonly) NSString* fileType;
- (void)openAsync:(WSFileAccessMode)accessMode
          success:(void (^)(RTObject<WSSIRandomAccessStream>*))success
          failure:(void (^)(NSError*))failure;
- (void)openTransactedWriteAsyncWithSuccess:(void (^)(WSStorageStreamTransaction*))success failure:(void (^)(NSError*))failure;
- (void)copyOverloadDefaultNameAndOptions:(RTObject<WSIStorageFolder>*)destinationFolder
                                  success:(void (^)(WSStorageFile*))success
                                  failure:(void (^)(NSError*))failure;
- (void)copyOverloadDefaultOptions:(RTObject<WSIStorageFolder>*)destinationFolder
                    desiredNewName:(NSString*)desiredNewName
                           success:(void (^)(WSStorageFile*))success
                           failure:(void (^)(NSError*))failure;
- (void)copyOverload:(RTObject<WSIStorageFolder>*)destinationFolder
      desiredNewName:(NSString*)desiredNewName
              option:(WSNameCollisionOption)option
             success:(void (^)(WSStorageFile*))success
             failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)copyAndReplaceAsync:(RTObject<WSIStorageFile>*)fileToReplace;
- (RTObject<WFIAsyncAction>*)moveOverloadDefaultNameAndOptions:(RTObject<WSIStorageFolder>*)destinationFolder;
- (RTObject<WFIAsyncAction>*)moveOverloadDefaultOptions:(RTObject<WSIStorageFolder>*)destinationFolder
                                         desiredNewName:(NSString*)desiredNewName;
- (RTObject<WFIAsyncAction>*)moveOverload:(RTObject<WSIStorageFolder>*)destinationFolder
                           desiredNewName:(NSString*)desiredNewName
                                   option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)moveAndReplaceAsync:(RTObject<WSIStorageFile>*)fileToReplace;
- (RTObject<WFIAsyncAction>*)renameAsyncOverloadDefaultOptions:(NSString*)desiredName;
- (RTObject<WFIAsyncAction>*)renameAsync:(NSString*)desiredName option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)deleteAsyncOverloadDefaultOptions;
- (RTObject<WFIAsyncAction>*)deleteAsync:(WSStorageDeleteOption)option;
- (void)getBasicPropertiesAsyncWithSuccess:(void (^)(WSFBasicProperties*))success failure:(void (^)(NSError*))failure;
- (BOOL)isOfType:(WSStorageItemTypes)type;
- (void)openReadAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
- (void)openSequentialReadAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSIStorageFile_DEFINED__

// Windows.Storage.IStorageItem2
#ifndef __WSIStorageItem2_DEFINED__
#define __WSIStorageItem2_DEFINED__

@protocol WSIStorageItem2 <WSIStorageItem>
- (void)getParentAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (BOOL)isEqual:(RTObject<WSIStorageItem>*)item;
- (RTObject<WFIAsyncAction>*)renameAsyncOverloadDefaultOptions:(NSString*)desiredName;
- (RTObject<WFIAsyncAction>*)renameAsync:(NSString*)desiredName option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)deleteAsyncOverloadDefaultOptions;
- (RTObject<WFIAsyncAction>*)deleteAsync:(WSStorageDeleteOption)option;
- (void)getBasicPropertiesAsyncWithSuccess:(void (^)(WSFBasicProperties*))success failure:(void (^)(NSError*))failure;
- (BOOL)isOfType:(WSStorageItemTypes)type;
@end

#endif // __WSIStorageItem2_DEFINED__

// Windows.Storage.IStorageItemProperties
#ifndef __WSIStorageItemProperties_DEFINED__
#define __WSIStorageItemProperties_DEFINED__

@protocol WSIStorageItemProperties
@property (readonly) NSString* displayName;
@property (readonly) NSString* displayType;
@property (readonly) NSString* folderRelativeId;
@property (readonly) WSFStorageItemContentProperties* properties;
- (void)getThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode
                                                   success:(void (^)(WSFStorageItemThumbnail*))success
                                                   failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode
                                  requestedSize:(unsigned)requestedSize
                                        success:(void (^)(WSFStorageItemThumbnail*))success
                                        failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsync:(WSFThumbnailMode)mode
            requestedSize:(unsigned)requestedSize
                  options:(WSFThumbnailOptions)options
                  success:(void (^)(WSFStorageItemThumbnail*))success
                  failure:(void (^)(NSError*))failure;
@end

#endif // __WSIStorageItemProperties_DEFINED__

// Windows.Storage.IStorageItemProperties2
#ifndef __WSIStorageItemProperties2_DEFINED__
#define __WSIStorageItemProperties2_DEFINED__

@protocol WSIStorageItemProperties2 <WSIStorageItemProperties>
- (void)getScaledImageAsThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode
                                                                success:(void (^)(WSFStorageItemThumbnail*))success
                                                                failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode
                                               requestedSize:(unsigned)requestedSize
                                                     success:(void (^)(WSFStorageItemThumbnail*))success
                                                     failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsync:(WSFThumbnailMode)mode
                         requestedSize:(unsigned)requestedSize
                               options:(WSFThumbnailOptions)options
                               success:(void (^)(WSFStorageItemThumbnail*))success
                               failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode
                                                   success:(void (^)(WSFStorageItemThumbnail*))success
                                                   failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode
                                  requestedSize:(unsigned)requestedSize
                                        success:(void (^)(WSFStorageItemThumbnail*))success
                                        failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsync:(WSFThumbnailMode)mode
            requestedSize:(unsigned)requestedSize
                  options:(WSFThumbnailOptions)options
                  success:(void (^)(WSFStorageItemThumbnail*))success
                  failure:(void (^)(NSError*))failure;
@end

#endif // __WSIStorageItemProperties2_DEFINED__

// Windows.Storage.IStorageItemPropertiesWithProvider
#ifndef __WSIStorageItemPropertiesWithProvider_DEFINED__
#define __WSIStorageItemPropertiesWithProvider_DEFINED__

@protocol WSIStorageItemPropertiesWithProvider <WSIStorageItemProperties>
@property (readonly) WSStorageProvider* provider;
- (void)getThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode
                                                   success:(void (^)(WSFStorageItemThumbnail*))success
                                                   failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode
                                  requestedSize:(unsigned)requestedSize
                                        success:(void (^)(WSFStorageItemThumbnail*))success
                                        failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsync:(WSFThumbnailMode)mode
            requestedSize:(unsigned)requestedSize
                  options:(WSFThumbnailOptions)options
                  success:(void (^)(WSFStorageItemThumbnail*))success
                  failure:(void (^)(NSError*))failure;
@end

#endif // __WSIStorageItemPropertiesWithProvider_DEFINED__

// Windows.Storage.IStorageFilePropertiesWithAvailability
#ifndef __WSIStorageFilePropertiesWithAvailability_DEFINED__
#define __WSIStorageFilePropertiesWithAvailability_DEFINED__

@protocol WSIStorageFilePropertiesWithAvailability
@property (readonly) BOOL isAvailable;
@end

#endif // __WSIStorageFilePropertiesWithAvailability_DEFINED__

// Windows.Storage.IStorageFolder2
#ifndef __WSIStorageFolder2_DEFINED__
#define __WSIStorageFolder2_DEFINED__

@protocol WSIStorageFolder2
- (void)tryGetItemAsync:(NSString*)name success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSIStorageFolder2_DEFINED__

// Windows.Storage.StorageLibrary
#ifndef __WSStorageLibrary_DEFINED__
#define __WSStorageLibrary_DEFINED__

WINRT_EXPORT
@interface WSStorageLibrary : RTObject
+ (void)getLibraryAsync:(WSKnownLibraryId)libraryId success:(void (^)(WSStorageLibrary*))success failure:(void (^)(NSError*))failure;
// Failed to generate property Folders (Can't marshal Windows.Foundation.Collections.IObservableVector`1<Windows.Storage.StorageFolder>)
@property (readonly) WSStorageFolder* saveFolder;
- (EventRegistrationToken)addDefinitionChangedEvent:(void (^)(WSStorageLibrary*, RTObject*))del;
- (void)removeDefinitionChangedEvent:(EventRegistrationToken)tok;
- (void)requestAddFolderAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (void)requestRemoveFolderAsync:(WSStorageFolder*)folder success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
// Failed to generate member get_Folders (Can't marshal Windows.Foundation.Collections.IObservableVector`1<Windows.Storage.StorageFolder>)
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
- (void)getFilesAsync:(WSSCommonFileQuery)query
           startIndex:(unsigned)startIndex
   maxItemsToRetrieve:(unsigned)maxItemsToRetrieve
              success:(void (^)(id<NSFastEnumeration> /*WSStorageFile*/))success
              failure:(void (^)(NSError*))failure;
- (void)getFilesAsyncOverloadDefaultStartAndCount:(WSSCommonFileQuery)query
                                          success:(void (^)(id<NSFastEnumeration> /*WSStorageFile*/))success
                                          failure:(void (^)(NSError*))failure;
- (void)getFoldersAsync:(WSSCommonFolderQuery)query
             startIndex:(unsigned)startIndex
     maxItemsToRetrieve:(unsigned)maxItemsToRetrieve
                success:(void (^)(id<NSFastEnumeration> /*WSStorageFolder*/))success
                failure:(void (^)(NSError*))failure;
- (void)getFoldersAsyncOverloadDefaultStartAndCount:(WSSCommonFolderQuery)query
                                            success:(void (^)(id<NSFastEnumeration> /*WSStorageFolder*/))success
                                            failure:(void (^)(NSError*))failure;
- (void)getItemsAsync:(unsigned)startIndex
   maxItemsToRetrieve:(unsigned)maxItemsToRetrieve
              success:(void (^)(id<NSFastEnumeration> /*WSIStorageItem*/))success
              failure:(void (^)(NSError*))failure;
- (BOOL)areQueryOptionsSupported:(WSSQueryOptions*)queryOptions;
- (BOOL)isCommonFolderQuerySupported:(WSSCommonFolderQuery)query;
- (BOOL)isCommonFileQuerySupported:(WSSCommonFileQuery)query;
@end

#endif // __WSSIStorageFolderQueryOperations_DEFINED__

// Windows.Storage.StorageFolder
#ifndef __WSStorageFolder_DEFINED__
#define __WSStorageFolder_DEFINED__

WINRT_EXPORT
@interface WSStorageFolder : RTObject <WSIStorageFolder,
                                       WSIStorageItem,
                                       WSSIStorageFolderQueryOperations,
                                       WSIStorageItemProperties,
                                       WSIStorageItemProperties2,
                                       WSIStorageItem2,
                                       WSIStorageFolder2,
                                       WSIStorageItemPropertiesWithProvider>
+ (void)getFolderFromPathAsync:(NSString*)path success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
@property (readonly) WSFileAttributes attributes;
@property (readonly) WFDateTime* dateCreated;
@property (readonly) NSString* name;
@property (readonly) NSString* path;
@property (readonly) NSString* displayName;
@property (readonly) NSString* displayType;
@property (readonly) NSString* folderRelativeId;
@property (readonly) WSFStorageItemContentProperties* properties;
@property (readonly) WSStorageProvider* provider;
- (void)createFileAsyncOverloadDefaultOptions:(NSString*)desiredName
                                      success:(void (^)(WSStorageFile*))success
                                      failure:(void (^)(NSError*))failure;
- (void)createFileAsync:(NSString*)desiredName
                options:(WSCreationCollisionOption)options
                success:(void (^)(WSStorageFile*))success
                failure:(void (^)(NSError*))failure;
- (void)createFolderAsyncOverloadDefaultOptions:(NSString*)desiredName
                                        success:(void (^)(WSStorageFolder*))success
                                        failure:(void (^)(NSError*))failure;
- (void)createFolderAsync:(NSString*)desiredName
                  options:(WSCreationCollisionOption)options
                  success:(void (^)(WSStorageFolder*))success
                  failure:(void (^)(NSError*))failure;
- (void)getFileAsync:(NSString*)name success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)getFolderAsync:(NSString*)name success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (void)getItemAsync:(NSString*)name success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure;
- (void)getFilesAsyncOverloadDefaultOptionsStartAndCountWithSuccess:(void (^)(id<NSFastEnumeration> /*WSStorageFile*/))success
                                                            failure:(void (^)(NSError*))failure;
- (void)getFoldersAsyncOverloadDefaultOptionsStartAndCountWithSuccess:(void (^)(id<NSFastEnumeration> /*WSStorageFolder*/))success
                                                              failure:(void (^)(NSError*))failure;
- (void)getItemsAsyncOverloadDefaultStartAndCountWithSuccess:(void (^)(id<NSFastEnumeration> /*WSIStorageItem*/))success
                                                     failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)renameAsyncOverloadDefaultOptions:(NSString*)desiredName;
- (RTObject<WFIAsyncAction>*)renameAsync:(NSString*)desiredName option:(WSNameCollisionOption)option;
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
- (void)getFilesAsync:(WSSCommonFileQuery)query
           startIndex:(unsigned)startIndex
   maxItemsToRetrieve:(unsigned)maxItemsToRetrieve
              success:(void (^)(id<NSFastEnumeration> /*WSStorageFile*/))success
              failure:(void (^)(NSError*))failure;
- (void)getFilesAsyncOverloadDefaultStartAndCount:(WSSCommonFileQuery)query
                                          success:(void (^)(id<NSFastEnumeration> /*WSStorageFile*/))success
                                          failure:(void (^)(NSError*))failure;
- (void)getFoldersAsync:(WSSCommonFolderQuery)query
             startIndex:(unsigned)startIndex
     maxItemsToRetrieve:(unsigned)maxItemsToRetrieve
                success:(void (^)(id<NSFastEnumeration> /*WSStorageFolder*/))success
                failure:(void (^)(NSError*))failure;
- (void)getFoldersAsyncOverloadDefaultStartAndCount:(WSSCommonFolderQuery)query
                                            success:(void (^)(id<NSFastEnumeration> /*WSStorageFolder*/))success
                                            failure:(void (^)(NSError*))failure;
- (void)getItemsAsync:(unsigned)startIndex
   maxItemsToRetrieve:(unsigned)maxItemsToRetrieve
              success:(void (^)(id<NSFastEnumeration> /*WSIStorageItem*/))success
              failure:(void (^)(NSError*))failure;
- (BOOL)areQueryOptionsSupported:(WSSQueryOptions*)queryOptions;
- (BOOL)isCommonFolderQuerySupported:(WSSCommonFolderQuery)query;
- (BOOL)isCommonFileQuerySupported:(WSSCommonFileQuery)query;
- (void)getThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode
                                                   success:(void (^)(WSFStorageItemThumbnail*))success
                                                   failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode
                                  requestedSize:(unsigned)requestedSize
                                        success:(void (^)(WSFStorageItemThumbnail*))success
                                        failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsync:(WSFThumbnailMode)mode
            requestedSize:(unsigned)requestedSize
                  options:(WSFThumbnailOptions)options
                  success:(void (^)(WSFStorageItemThumbnail*))success
                  failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode
                                                                success:(void (^)(WSFStorageItemThumbnail*))success
                                                                failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode
                                               requestedSize:(unsigned)requestedSize
                                                     success:(void (^)(WSFStorageItemThumbnail*))success
                                                     failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsync:(WSFThumbnailMode)mode
                         requestedSize:(unsigned)requestedSize
                               options:(WSFThumbnailOptions)options
                               success:(void (^)(WSFStorageItemThumbnail*))success
                               failure:(void (^)(NSError*))failure;
- (void)getParentAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (BOOL)isEqual:(RTObject<WSIStorageItem>*)item;
- (void)tryGetItemAsync:(NSString*)name success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSStorageFolder_DEFINED__

// Windows.Storage.KnownFolders
#ifndef __WSKnownFolders_DEFINED__
#define __WSKnownFolders_DEFINED__

WINRT_EXPORT
@interface WSKnownFolders : RTObject
+ (WSStorageFolder*)savedPictures;
+ (WSStorageFolder*)playlists;
+ (WSStorageFolder*)cameraRoll;
+ (WSStorageFolder*)documentsLibrary;
+ (WSStorageFolder*)homeGroup;
+ (WSStorageFolder*)mediaServerDevices;
+ (WSStorageFolder*)musicLibrary;
+ (WSStorageFolder*)picturesLibrary;
+ (WSStorageFolder*)removableDevices;
+ (WSStorageFolder*)videosLibrary;
@end

#endif // __WSKnownFolders_DEFINED__

// Windows.Storage.StorageFile
#ifndef __WSStorageFile_DEFINED__
#define __WSStorageFile_DEFINED__

WINRT_EXPORT
@interface WSStorageFile : RTObject <WSIStorageFile,
                                     WSSIInputStreamReference,
                                     WSSIRandomAccessStreamReference,
                                     WSIStorageItem,
                                     WSIStorageItemProperties,
                                     WSIStorageItemProperties2,
                                     WSIStorageItem2,
                                     WSIStorageItemPropertiesWithProvider,
                                     WSIStorageFilePropertiesWithAvailability>
+ (void)getFileFromPathAsync:(NSString*)path success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
+ (void)getFileFromApplicationUriAsync:(WFUri*)uri success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
+ (void)createStreamedFileAsync:(NSString*)displayNameWithExtension
                  dataRequested:(WSStreamedFileDataRequestedHandler)dataRequested
                      thumbnail:(RTObject<WSSIRandomAccessStreamReference>*)thumbnail
                        success:(void (^)(WSStorageFile*))success
                        failure:(void (^)(NSError*))failure;
+ (void)replaceWithStreamedFileAsync:(RTObject<WSIStorageFile>*)fileToReplace
                       dataRequested:(WSStreamedFileDataRequestedHandler)dataRequested
                           thumbnail:(RTObject<WSSIRandomAccessStreamReference>*)thumbnail
                             success:(void (^)(WSStorageFile*))success
                             failure:(void (^)(NSError*))failure;
+ (void)createStreamedFileFromUriAsync:(NSString*)displayNameWithExtension
                                   uri:(WFUri*)uri
                             thumbnail:(RTObject<WSSIRandomAccessStreamReference>*)thumbnail
                               success:(void (^)(WSStorageFile*))success
                               failure:(void (^)(NSError*))failure;
+ (void)replaceWithStreamedFileFromUriAsync:(RTObject<WSIStorageFile>*)fileToReplace
                                        uri:(WFUri*)uri
                                  thumbnail:(RTObject<WSSIRandomAccessStreamReference>*)thumbnail
                                    success:(void (^)(WSStorageFile*))success
                                    failure:(void (^)(NSError*))failure;
@property (readonly) NSString* displayName;
@property (readonly) NSString* displayType;
@property (readonly) NSString* folderRelativeId;
@property (readonly) WSFStorageItemContentProperties* properties;
@property (readonly) NSString* contentType;
@property (readonly) NSString* fileType;
@property (readonly) WSFileAttributes attributes;
@property (readonly) WFDateTime* dateCreated;
@property (readonly) NSString* name;
@property (readonly) NSString* path;
@property (readonly) WSStorageProvider* provider;
@property (readonly) BOOL isAvailable;
- (void)openAsync:(WSFileAccessMode)accessMode
          success:(void (^)(RTObject<WSSIRandomAccessStream>*))success
          failure:(void (^)(NSError*))failure;
- (void)openTransactedWriteAsyncWithSuccess:(void (^)(WSStorageStreamTransaction*))success failure:(void (^)(NSError*))failure;
- (void)copyOverloadDefaultNameAndOptions:(RTObject<WSIStorageFolder>*)destinationFolder
                                  success:(void (^)(WSStorageFile*))success
                                  failure:(void (^)(NSError*))failure;
- (void)copyOverloadDefaultOptions:(RTObject<WSIStorageFolder>*)destinationFolder
                    desiredNewName:(NSString*)desiredNewName
                           success:(void (^)(WSStorageFile*))success
                           failure:(void (^)(NSError*))failure;
- (void)copyOverload:(RTObject<WSIStorageFolder>*)destinationFolder
      desiredNewName:(NSString*)desiredNewName
              option:(WSNameCollisionOption)option
             success:(void (^)(WSStorageFile*))success
             failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)copyAndReplaceAsync:(RTObject<WSIStorageFile>*)fileToReplace;
- (RTObject<WFIAsyncAction>*)moveOverloadDefaultNameAndOptions:(RTObject<WSIStorageFolder>*)destinationFolder;
- (RTObject<WFIAsyncAction>*)moveOverloadDefaultOptions:(RTObject<WSIStorageFolder>*)destinationFolder
                                         desiredNewName:(NSString*)desiredNewName;
- (RTObject<WFIAsyncAction>*)moveOverload:(RTObject<WSIStorageFolder>*)destinationFolder
                           desiredNewName:(NSString*)desiredNewName
                                   option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)moveAndReplaceAsync:(RTObject<WSIStorageFile>*)fileToReplace;
- (RTObject<WFIAsyncAction>*)renameAsyncOverloadDefaultOptions:(NSString*)desiredName;
- (RTObject<WFIAsyncAction>*)renameAsync:(NSString*)desiredName option:(WSNameCollisionOption)option;
- (RTObject<WFIAsyncAction>*)deleteAsyncOverloadDefaultOptions;
- (RTObject<WFIAsyncAction>*)deleteAsync:(WSStorageDeleteOption)option;
- (void)getBasicPropertiesAsyncWithSuccess:(void (^)(WSFBasicProperties*))success failure:(void (^)(NSError*))failure;
- (BOOL)isOfType:(WSStorageItemTypes)type;
- (void)openReadAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
- (void)openSequentialReadAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode
                                                   success:(void (^)(WSFStorageItemThumbnail*))success
                                                   failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode
                                  requestedSize:(unsigned)requestedSize
                                        success:(void (^)(WSFStorageItemThumbnail*))success
                                        failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsync:(WSFThumbnailMode)mode
            requestedSize:(unsigned)requestedSize
                  options:(WSFThumbnailOptions)options
                  success:(void (^)(WSFStorageItemThumbnail*))success
                  failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode
                                                                success:(void (^)(WSFStorageItemThumbnail*))success
                                                                failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode
                                               requestedSize:(unsigned)requestedSize
                                                     success:(void (^)(WSFStorageItemThumbnail*))success
                                                     failure:(void (^)(NSError*))failure;
- (void)getScaledImageAsThumbnailAsync:(WSFThumbnailMode)mode
                         requestedSize:(unsigned)requestedSize
                               options:(WSFThumbnailOptions)options
                               success:(void (^)(WSFStorageItemThumbnail*))success
                               failure:(void (^)(NSError*))failure;
- (void)getParentAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (BOOL)isEqual:(RTObject<WSIStorageItem>*)item;
@end

#endif // __WSStorageFile_DEFINED__

// Windows.Storage.DownloadsFolder
#ifndef __WSDownloadsFolder_DEFINED__
#define __WSDownloadsFolder_DEFINED__

WINRT_EXPORT
@interface WSDownloadsFolder : RTObject
+ (void)createFileAsync:(NSString*)desiredName success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
+ (void)createFolderAsync:(NSString*)desiredName success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
+ (void)createFileWithCollisionOptionAsync:(NSString*)desiredName
                                    option:(WSCreationCollisionOption)option
                                   success:(void (^)(WSStorageFile*))success
                                   failure:(void (^)(NSError*))failure;
+ (void)createFolderWithCollisionOptionAsync:(NSString*)desiredName
                                      option:(WSCreationCollisionOption)option
                                     success:(void (^)(WSStorageFolder*))success
                                     failure:(void (^)(NSError*))failure;
@end

#endif // __WSDownloadsFolder_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Storage.Streams.IOutputStream
#ifndef __WSSIOutputStream_DEFINED__
#define __WSSIOutputStream_DEFINED__

@protocol WSSIOutputStream <WFIClosable>
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSSIOutputStream_DEFINED__

// Windows.Storage.StreamedFileDataRequest
#ifndef __WSStreamedFileDataRequest_DEFINED__
#define __WSStreamedFileDataRequest_DEFINED__

WINRT_EXPORT
@interface WSStreamedFileDataRequest : RTObject <WSSIOutputStream, WFIClosable, WSIStreamedFileDataRequest>
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
- (void)failAndClose:(WSStreamedFileFailureMode)failureMode;
@end

#endif // __WSStreamedFileDataRequest_DEFINED__

// Windows.Storage.StorageStreamTransaction
#ifndef __WSStorageStreamTransaction_DEFINED__
#define __WSStorageStreamTransaction_DEFINED__

WINRT_EXPORT
@interface WSStorageStreamTransaction : RTObject <WFIClosable>
@property (readonly) RTObject<WSSIRandomAccessStream>* stream;
- (RTObject<WFIAsyncAction>*)commitAsync;
- (void)close;
@end

#endif // __WSStorageStreamTransaction_DEFINED__

// Windows.Storage.StorageProvider
#ifndef __WSStorageProvider_DEFINED__
#define __WSStorageProvider_DEFINED__

WINRT_EXPORT
@interface WSStorageProvider : RTObject
@property (readonly) NSString* displayName;
@property (readonly) NSString* id;
@end

#endif // __WSStorageProvider_DEFINED__

// Windows.Storage.FileIO
#ifndef __WSFileIO_DEFINED__
#define __WSFileIO_DEFINED__

WINRT_EXPORT
@interface WSFileIO : RTObject
+ (void)readTextAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (void)readTextWithEncodingAsync:(RTObject<WSIStorageFile>*)file
                         encoding:(WSSUnicodeEncoding)encoding
                          success:(void (^)(NSString*))success
                          failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)writeTextAsync:(RTObject<WSIStorageFile>*)file contents:(NSString*)contents;
+ (RTObject<WFIAsyncAction>*)writeTextWithEncodingAsync:(RTObject<WSIStorageFile>*)file
                                               contents:(NSString*)contents
                                               encoding:(WSSUnicodeEncoding)encoding;
+ (RTObject<WFIAsyncAction>*)appendTextAsync:(RTObject<WSIStorageFile>*)file contents:(NSString*)contents;
+ (RTObject<WFIAsyncAction>*)appendTextWithEncodingAsync:(RTObject<WSIStorageFile>*)file
                                                contents:(NSString*)contents
                                                encoding:(WSSUnicodeEncoding)encoding;
+ (void)readLinesAsync:(RTObject<WSIStorageFile>*)file
               success:(void (^)(id<NSFastEnumeration> /*String*/))success
               failure:(void (^)(NSError*))failure;
+ (void)readLinesWithEncodingAsync:(RTObject<WSIStorageFile>*)file
                          encoding:(WSSUnicodeEncoding)encoding
                           success:(void (^)(id<NSFastEnumeration> /*String*/))success
                           failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)writeLinesAsync:(RTObject<WSIStorageFile>*)file lines:(id<NSFastEnumeration> /*String*/)lines;
+ (RTObject<WFIAsyncAction>*)writeLinesWithEncodingAsync:(RTObject<WSIStorageFile>*)file
                                                   lines:(id<NSFastEnumeration> /*String*/)lines
                                                encoding:(WSSUnicodeEncoding)encoding;
+ (RTObject<WFIAsyncAction>*)appendLinesAsync:(RTObject<WSIStorageFile>*)file lines:(id<NSFastEnumeration> /*String*/)lines;
+ (RTObject<WFIAsyncAction>*)appendLinesWithEncodingAsync:(RTObject<WSIStorageFile>*)file
                                                    lines:(id<NSFastEnumeration> /*String*/)lines
                                                 encoding:(WSSUnicodeEncoding)encoding;
+ (void)readBufferAsync:(RTObject<WSIStorageFile>*)file
                success:(void (^)(RTObject<WSSIBuffer>*))success
                failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)writeBufferAsync:(RTObject<WSIStorageFile>*)file buffer:(RTObject<WSSIBuffer>*)buffer;
+ (RTObject<WFIAsyncAction>*)writeBytesAsync:(RTObject<WSIStorageFile>*)file buffer:(id<NSFastEnumeration> /*UInt8*/)buffer;
@end

#endif // __WSFileIO_DEFINED__

// Windows.Storage.PathIO
#ifndef __WSPathIO_DEFINED__
#define __WSPathIO_DEFINED__

WINRT_EXPORT
@interface WSPathIO : RTObject
+ (void)readTextAsync:(NSString*)absolutePath success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (void)readTextWithEncodingAsync:(NSString*)absolutePath
                         encoding:(WSSUnicodeEncoding)encoding
                          success:(void (^)(NSString*))success
                          failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)writeTextAsync:(NSString*)absolutePath contents:(NSString*)contents;
+ (RTObject<WFIAsyncAction>*)writeTextWithEncodingAsync:(NSString*)absolutePath
                                               contents:(NSString*)contents
                                               encoding:(WSSUnicodeEncoding)encoding;
+ (RTObject<WFIAsyncAction>*)appendTextAsync:(NSString*)absolutePath contents:(NSString*)contents;
+ (RTObject<WFIAsyncAction>*)appendTextWithEncodingAsync:(NSString*)absolutePath
                                                contents:(NSString*)contents
                                                encoding:(WSSUnicodeEncoding)encoding;
+ (void)readLinesAsync:(NSString*)absolutePath
               success:(void (^)(id<NSFastEnumeration> /*String*/))success
               failure:(void (^)(NSError*))failure;
+ (void)readLinesWithEncodingAsync:(NSString*)absolutePath
                          encoding:(WSSUnicodeEncoding)encoding
                           success:(void (^)(id<NSFastEnumeration> /*String*/))success
                           failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)writeLinesAsync:(NSString*)absolutePath lines:(id<NSFastEnumeration> /*String*/)lines;
+ (RTObject<WFIAsyncAction>*)writeLinesWithEncodingAsync:(NSString*)absolutePath
                                                   lines:(id<NSFastEnumeration> /*String*/)lines
                                                encoding:(WSSUnicodeEncoding)encoding;
+ (RTObject<WFIAsyncAction>*)appendLinesAsync:(NSString*)absolutePath lines:(id<NSFastEnumeration> /*String*/)lines;
+ (RTObject<WFIAsyncAction>*)appendLinesWithEncodingAsync:(NSString*)absolutePath
                                                    lines:(id<NSFastEnumeration> /*String*/)lines
                                                 encoding:(WSSUnicodeEncoding)encoding;
+ (void)readBufferAsync:(NSString*)absolutePath success:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)writeBufferAsync:(NSString*)absolutePath buffer:(RTObject<WSSIBuffer>*)buffer;
+ (RTObject<WFIAsyncAction>*)writeBytesAsync:(NSString*)absolutePath buffer:(id<NSFastEnumeration> /*UInt8*/)buffer;
@end

#endif // __WSPathIO_DEFINED__

// Windows.Storage.CachedFileManager
#ifndef __WSCachedFileManager_DEFINED__
#define __WSCachedFileManager_DEFINED__

WINRT_EXPORT
@interface WSCachedFileManager : RTObject
+ (void)deferUpdates:(RTObject<WSIStorageFile>*)file;
+ (void)completeUpdatesAsync:(RTObject<WSIStorageFile>*)file
                     success:(void (^)(WSPFileUpdateStatus))success
                     failure:(void (^)(NSError*))failure;
@end

#endif // __WSCachedFileManager_DEFINED__

// Windows.Storage.SystemAudioProperties
#ifndef __WSSystemAudioProperties_DEFINED__
#define __WSSystemAudioProperties_DEFINED__

WINRT_EXPORT
@interface WSSystemAudioProperties : RTObject
@property (readonly) NSString* encodingBitrate;
@end

#endif // __WSSystemAudioProperties_DEFINED__

// Windows.Storage.SystemGPSProperties
#ifndef __WSSystemGPSProperties_DEFINED__
#define __WSSystemGPSProperties_DEFINED__

WINRT_EXPORT
@interface WSSystemGPSProperties : RTObject
@property (readonly) NSString* latitudeDecimal;
@property (readonly) NSString* longitudeDecimal;
@end

#endif // __WSSystemGPSProperties_DEFINED__

// Windows.Storage.SystemImageProperties
#ifndef __WSSystemImageProperties_DEFINED__
#define __WSSystemImageProperties_DEFINED__

WINRT_EXPORT
@interface WSSystemImageProperties : RTObject
@property (readonly) NSString* horizontalSize;
@property (readonly) NSString* verticalSize;
@end

#endif // __WSSystemImageProperties_DEFINED__

// Windows.Storage.SystemMediaProperties
#ifndef __WSSystemMediaProperties_DEFINED__
#define __WSSystemMediaProperties_DEFINED__

WINRT_EXPORT
@interface WSSystemMediaProperties : RTObject
@property (readonly) NSString* duration;
@property (readonly) NSString* producer;
@property (readonly) NSString* publisher;
@property (readonly) NSString* subTitle;
@property (readonly) NSString* writer;
@property (readonly) NSString* year;
@end

#endif // __WSSystemMediaProperties_DEFINED__

// Windows.Storage.SystemMusicProperties
#ifndef __WSSystemMusicProperties_DEFINED__
#define __WSSystemMusicProperties_DEFINED__

WINRT_EXPORT
@interface WSSystemMusicProperties : RTObject
@property (readonly) NSString* albumArtist;
@property (readonly) NSString* albumTitle;
@property (readonly) NSString* artist;
@property (readonly) NSString* composer;
@property (readonly) NSString* conductor;
@property (readonly) NSString* displayArtist;
@property (readonly) NSString* genre;
@property (readonly) NSString* trackNumber;
@end

#endif // __WSSystemMusicProperties_DEFINED__

// Windows.Storage.SystemPhotoProperties
#ifndef __WSSystemPhotoProperties_DEFINED__
#define __WSSystemPhotoProperties_DEFINED__

WINRT_EXPORT
@interface WSSystemPhotoProperties : RTObject
@property (readonly) NSString* cameraManufacturer;
@property (readonly) NSString* cameraModel;
@property (readonly) NSString* dateTaken;
@property (readonly) NSString* orientation;
@property (readonly) NSString* peopleNames;
@end

#endif // __WSSystemPhotoProperties_DEFINED__

// Windows.Storage.SystemVideoProperties
#ifndef __WSSystemVideoProperties_DEFINED__
#define __WSSystemVideoProperties_DEFINED__

WINRT_EXPORT
@interface WSSystemVideoProperties : RTObject
@property (readonly) NSString* director;
@property (readonly) NSString* frameHeight;
@property (readonly) NSString* frameWidth;
@property (readonly) NSString* orientation;
@property (readonly) NSString* totalBitrate;
@end

#endif // __WSSystemVideoProperties_DEFINED__

// Windows.Storage.SystemProperties
#ifndef __WSSystemProperties_DEFINED__
#define __WSSystemProperties_DEFINED__

WINRT_EXPORT
@interface WSSystemProperties : RTObject
+ (WSSystemAudioProperties*)audio;
+ (NSString*)author;
+ (NSString*)comment;
+ (WSSystemGPSProperties*)gPS;
+ (WSSystemImageProperties*)image;
+ (NSString*)itemNameDisplay;
+ (NSString*)keywords;
+ (WSSystemMediaProperties*)media;
+ (WSSystemMusicProperties*)music;
+ (WSSystemPhotoProperties*)photo;
+ (NSString*)rating;
+ (NSString*)title;
+ (WSSystemVideoProperties*)video;
@end

#endif // __WSSystemProperties_DEFINED__

// Windows.Storage.ApplicationData
#ifndef __WSApplicationData_DEFINED__
#define __WSApplicationData_DEFINED__

WINRT_EXPORT
@interface WSApplicationData : RTObject
@property (readonly) WSStorageFolder* localFolder;
@property (readonly) WSApplicationDataContainer* localSettings;
@property (readonly) WSStorageFolder* roamingFolder;
@property (readonly) WSApplicationDataContainer* roamingSettings;
@property (readonly) uint64_t roamingStorageQuota;
@property (readonly) WSStorageFolder* temporaryFolder;
@property (readonly) unsigned version;
+ (WSApplicationData*)current;
- (EventRegistrationToken)addDataChangedEvent:(void (^)(WSApplicationData*, RTObject*))del;
- (void)removeDataChangedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)setVersionAsync:(unsigned)desiredVersion handler:(WSApplicationDataSetVersionHandler)handler;
- (RTObject<WFIAsyncAction>*)clearAllAsync;
- (RTObject<WFIAsyncAction>*)clearAsync:(WSApplicationDataLocality)locality;
- (void)signalDataChanged;
@end

#endif // __WSApplicationData_DEFINED__

// Windows.Storage.SetVersionRequest
#ifndef __WSSetVersionRequest_DEFINED__
#define __WSSetVersionRequest_DEFINED__

WINRT_EXPORT
@interface WSSetVersionRequest : RTObject
@property (readonly) unsigned currentVersion;
@property (readonly) unsigned desiredVersion;
- (WSSetVersionDeferral*)getDeferral;
@end

#endif // __WSSetVersionRequest_DEFINED__

// Windows.Storage.ApplicationDataContainer
#ifndef __WSApplicationDataContainer_DEFINED__
#define __WSApplicationDataContainer_DEFINED__

WINRT_EXPORT
@interface WSApplicationDataContainer : RTObject
@property (readonly) NSDictionary* /*String, WSApplicationDataContainer*/ containers;
@property (readonly) WSApplicationDataLocality locality;
@property (readonly) NSString* name;
@property (readonly) RTObject<WFCIPropertySet>* values;
- (WSApplicationDataContainer*)createContainer:(NSString*)name disposition:(WSApplicationDataCreateDisposition)disposition;
- (void)deleteContainer:(NSString*)name;
@end

#endif // __WSApplicationDataContainer_DEFINED__

// Windows.Storage.SetVersionDeferral
#ifndef __WSSetVersionDeferral_DEFINED__
#define __WSSetVersionDeferral_DEFINED__

WINRT_EXPORT
@interface WSSetVersionDeferral : RTObject
- (void)complete;
@end

#endif // __WSSetVersionDeferral_DEFINED__

// Windows.Foundation.Collections.IPropertySet
#ifndef __WFCIPropertySet_DEFINED__
#define __WFCIPropertySet_DEFINED__

@protocol WFCIPropertySet
// Could not find base class Windows.Foundation.Collections.IObservableMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,System.Object> type information
@end

#endif // __WFCIPropertySet_DEFINED__

// Windows.Storage.ApplicationDataContainerSettings
#ifndef __WSApplicationDataContainerSettings_DEFINED__
#define __WSApplicationDataContainerSettings_DEFINED__

WINRT_EXPORT
@interface WSApplicationDataContainerSettings : RTObject <WFCIPropertySet>
@property (readonly) unsigned size;
// Could not generate add_MapChanged (Can't marshal Windows.Foundation.Collections.MapChangedEventHandler`2<String,System.Object>)
- (void)removeMapChangedEvent:(EventRegistrationToken)tok;
// Could not find base class Windows.Foundation.Collections.IObservableMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IObservableMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,System.Object> type information
@end

#endif // __WSApplicationDataContainerSettings_DEFINED__

// Windows.Storage.ApplicationDataCompositeValue
#ifndef __WSApplicationDataCompositeValue_DEFINED__
#define __WSApplicationDataCompositeValue_DEFINED__

WINRT_EXPORT
@interface WSApplicationDataCompositeValue : RTObject <WFCIPropertySet>
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
// Could not generate add_MapChanged (Can't marshal Windows.Foundation.Collections.MapChangedEventHandler`2<String,System.Object>)
- (void)removeMapChangedEvent:(EventRegistrationToken)tok;
// Could not find base class Windows.Foundation.Collections.IObservableMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IObservableMap`2<String,System.Object> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,System.Object> type information
@end

#endif // __WSApplicationDataCompositeValue_DEFINED__
