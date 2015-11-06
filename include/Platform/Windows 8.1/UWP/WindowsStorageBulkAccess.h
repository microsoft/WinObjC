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

// WindowsStorageBulkAccess.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSBFileInformationFactory, WSBFileInformation, WSBFolderInformation;
@protocol WSBIStorageItemInformation
, WSBIFileInformationFactoryFactory, WSBIFileInformationFactory;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsStorageFileProperties.h"
#include "WindowsStorage.h"
#include "WindowsStorageSearch.h"

// Windows.Storage.BulkAccess.IStorageItemInformation
#ifndef __WSBIStorageItemInformation_DEFINED__
#define __WSBIStorageItemInformation_DEFINED__

@protocol WSBIStorageItemInformation
@property (readonly) WSFBasicProperties* basicProperties;
@property (readonly) WSFDocumentProperties* documentProperties;
@property (readonly) WSFImageProperties* imageProperties;
@property (readonly) WSFMusicProperties* musicProperties;
@property (readonly) WSFStorageItemThumbnail* thumbnail;
@property (readonly) WSFVideoProperties* videoProperties;
- (EventRegistrationToken)addPropertiesUpdatedEvent:(void (^)(RTObject<WSBIStorageItemInformation>*, RTObject*))del;
- (void)removePropertiesUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addThumbnailUpdatedEvent:(void (^)(RTObject<WSBIStorageItemInformation>*, RTObject*))del;
- (void)removeThumbnailUpdatedEvent:(EventRegistrationToken)tok;
@end

#endif // __WSBIStorageItemInformation_DEFINED__

// Windows.Storage.BulkAccess.FileInformationFactory
#ifndef __WSBFileInformationFactory_DEFINED__
#define __WSBFileInformationFactory_DEFINED__

WINRT_EXPORT
@interface WSBFileInformationFactory : RTObject
+ (WSBFileInformationFactory*)createWithMode:(RTObject<WSSIStorageQueryResultBase>*)queryResult mode:(WSFThumbnailMode)mode ACTIVATOR;
+ (WSBFileInformationFactory*)createWithModeAndSize:(RTObject<WSSIStorageQueryResultBase>*)queryResult
                                               mode:(WSFThumbnailMode)mode
                             requestedThumbnailSize:(unsigned)requestedThumbnailSize ACTIVATOR;
+ (WSBFileInformationFactory*)createWithModeAndSizeAndOptions:(RTObject<WSSIStorageQueryResultBase>*)queryResult
                                                         mode:(WSFThumbnailMode)mode
                                       requestedThumbnailSize:(unsigned)requestedThumbnailSize
                                             thumbnailOptions:(WSFThumbnailOptions)thumbnailOptions ACTIVATOR;
+ (WSBFileInformationFactory*)createWithModeAndSizeAndOptionsAndFlags:(RTObject<WSSIStorageQueryResultBase>*)queryResult
                                                                 mode:(WSFThumbnailMode)mode
                                               requestedThumbnailSize:(unsigned)requestedThumbnailSize
                                                     thumbnailOptions:(WSFThumbnailOptions)thumbnailOptions
                                                            delayLoad:(BOOL)delayLoad ACTIVATOR;
- (void)getItemsAsync:(unsigned)startIndex
   maxItemsToRetrieve:(unsigned)maxItemsToRetrieve
              success:(void (^)(id<NSFastEnumeration> /*WSBIStorageItemInformation*/))success
              failure:(void (^)(NSError*))failure;
- (void)getItemsAsyncDefaultStartAndCountWithSuccess:(void (^)(id<NSFastEnumeration> /*WSBIStorageItemInformation*/))success
                                             failure:(void (^)(NSError*))failure;
- (void)getFilesAsync:(unsigned)startIndex
   maxItemsToRetrieve:(unsigned)maxItemsToRetrieve
              success:(void (^)(id<NSFastEnumeration> /*WSBFileInformation*/))success
              failure:(void (^)(NSError*))failure;
- (void)getFilesAsyncDefaultStartAndCountWithSuccess:(void (^)(id<NSFastEnumeration> /*WSBFileInformation*/))success
                                             failure:(void (^)(NSError*))failure;
- (void)getFoldersAsync:(unsigned)startIndex
     maxItemsToRetrieve:(unsigned)maxItemsToRetrieve
                success:(void (^)(id<NSFastEnumeration> /*WSBFolderInformation*/))success
                failure:(void (^)(NSError*))failure;
- (void)getFoldersAsyncDefaultStartAndCountWithSuccess:(void (^)(id<NSFastEnumeration> /*WSBFolderInformation*/))success
                                               failure:(void (^)(NSError*))failure;
- (RTObject*)getVirtualizedItemsVector;
- (RTObject*)getVirtualizedFilesVector;
- (RTObject*)getVirtualizedFoldersVector;
@end

#endif // __WSBFileInformationFactory_DEFINED__

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

// Windows.Storage.BulkAccess.FileInformation
#ifndef __WSBFileInformation_DEFINED__
#define __WSBFileInformation_DEFINED__

WINRT_EXPORT
@interface WSBFileInformation : RTObject <WSBIStorageItemInformation,
                                          WSIStorageFile,
                                          WSSIInputStreamReference,
                                          WSSIRandomAccessStreamReference,
                                          WSIStorageItem,
                                          WSIStorageItemProperties,
                                          WSIStorageItem2,
                                          WSIStorageItemPropertiesWithProvider,
                                          WSIStorageFilePropertiesWithAvailability>
@property (readonly) WSFileAttributes attributes;
@property (readonly) WFDateTime* dateCreated;
@property (readonly) NSString* name;
@property (readonly) NSString* path;
@property (readonly) NSString* displayName;
@property (readonly) NSString* displayType;
@property (readonly) NSString* folderRelativeId;
@property (readonly) WSFStorageItemContentProperties* properties;
@property (readonly) WSFBasicProperties* basicProperties;
@property (readonly) WSFDocumentProperties* documentProperties;
@property (readonly) WSFImageProperties* imageProperties;
@property (readonly) WSFMusicProperties* musicProperties;
@property (readonly) WSFStorageItemThumbnail* thumbnail;
@property (readonly) WSFVideoProperties* videoProperties;
@property (readonly) NSString* contentType;
@property (readonly) NSString* fileType;
@property (readonly) WSStorageProvider* provider;
@property (readonly) BOOL isAvailable;
- (EventRegistrationToken)addPropertiesUpdatedEvent:(void (^)(RTObject<WSBIStorageItemInformation>*, RTObject*))del;
- (void)removePropertiesUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addThumbnailUpdatedEvent:(void (^)(RTObject<WSBIStorageItemInformation>*, RTObject*))del;
- (void)removeThumbnailUpdatedEvent:(EventRegistrationToken)tok;
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
- (void)getParentAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (BOOL)isEqual:(RTObject<WSIStorageItem>*)item;
@end

#endif // __WSBFileInformation_DEFINED__

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

// Windows.Storage.IStorageFolder2
#ifndef __WSIStorageFolder2_DEFINED__
#define __WSIStorageFolder2_DEFINED__

@protocol WSIStorageFolder2
- (void)tryGetItemAsync:(NSString*)name success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSIStorageFolder2_DEFINED__

// Windows.Storage.BulkAccess.FolderInformation
#ifndef __WSBFolderInformation_DEFINED__
#define __WSBFolderInformation_DEFINED__

WINRT_EXPORT
@interface WSBFolderInformation : RTObject <WSBIStorageItemInformation,
                                            WSIStorageFolder,
                                            WSIStorageItem,
                                            WSIStorageItemProperties,
                                            WSSIStorageFolderQueryOperations,
                                            WSIStorageItem2,
                                            WSIStorageFolder2,
                                            WSIStorageItemPropertiesWithProvider>
@property (readonly) WSFileAttributes attributes;
@property (readonly) WFDateTime* dateCreated;
@property (readonly) NSString* name;
@property (readonly) NSString* path;
@property (readonly) WSStorageProvider* provider;
@property (readonly) WSFBasicProperties* basicProperties;
@property (readonly) WSFDocumentProperties* documentProperties;
@property (readonly) WSFImageProperties* imageProperties;
@property (readonly) WSFMusicProperties* musicProperties;
@property (readonly) WSFStorageItemThumbnail* thumbnail;
@property (readonly) WSFVideoProperties* videoProperties;
@property (readonly) NSString* displayName;
@property (readonly) NSString* displayType;
@property (readonly) NSString* folderRelativeId;
@property (readonly) WSFStorageItemContentProperties* properties;
- (EventRegistrationToken)addPropertiesUpdatedEvent:(void (^)(RTObject<WSBIStorageItemInformation>*, RTObject*))del;
- (void)removePropertiesUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addThumbnailUpdatedEvent:(void (^)(RTObject<WSBIStorageItemInformation>*, RTObject*))del;
- (void)removeThumbnailUpdatedEvent:(EventRegistrationToken)tok;
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
- (void)getParentAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
- (BOOL)isEqual:(RTObject<WSIStorageItem>*)item;
- (void)tryGetItemAsync:(NSString*)name success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSBFolderInformation_DEFINED__
