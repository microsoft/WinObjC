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

// WindowsMediaImport.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMIPhotoImportSource, WMIPhotoImportOperation, WMIPhotoImportManager, WMIPhotoImportSession, WMIPhotoImportFindItemsResult,
    WMIPhotoImportImportItemsResult, WMIPhotoImportDeleteImportedItemsFromSourceResult, WMIPhotoImportStorageMedium, WMIPhotoImportSidecar,
    WMIPhotoImportVideoSegment, WMIPhotoImportItem, WMIPhotoImportSelectionChangedEventArgs, WMIPhotoImportItemImportedEventArgs;
@class WMIPhotoImportProgress;
@protocol WMIIPhotoImportManagerStatics
, WMIIPhotoImportOperation, WMIIPhotoImportStorageMedium, WMIIPhotoImportSourceStatics, WMIIPhotoImportSource, WMIIPhotoImportSession,
    WMIIPhotoImportItem, WMIIPhotoImportFindItemsResult, WMIIPhotoImportImportItemsResult,
    WMIIPhotoImportDeleteImportedItemsFromSourceResult, WMIIPhotoImportSidecar, WMIIPhotoImportVideoSegment,
    WMIIPhotoImportItemImportedEventArgs, WMIIPhotoImportSelectionChangedEventArgs;

// Windows.Media.Import.PhotoImportStage
enum _WMIPhotoImportStage {
    WMIPhotoImportStageNotStarted = 0,
    WMIPhotoImportStageFindingItems = 1,
    WMIPhotoImportStageImportingItems = 2,
    WMIPhotoImportStageDeletingImportedItemsFromSource = 3,
};
typedef unsigned WMIPhotoImportStage;

// Windows.Media.Import.PhotoImportAccessMode
enum _WMIPhotoImportAccessMode {
    WMIPhotoImportAccessModeReadWrite = 0,
    WMIPhotoImportAccessModeReadOnly = 1,
    WMIPhotoImportAccessModeReadAndDelete = 2,
};
typedef unsigned WMIPhotoImportAccessMode;

// Windows.Media.Import.PhotoImportImportMode
enum _WMIPhotoImportImportMode {
    WMIPhotoImportImportModeImportEverything = 0,
    WMIPhotoImportImportModeIgnoreSidecars = 1,
    WMIPhotoImportImportModeIgnoreSiblings = 2,
    WMIPhotoImportImportModeIgnoreSidecarsAndSiblings = 3,
};
typedef unsigned WMIPhotoImportImportMode;

// Windows.Media.Import.PhotoImportSourceType
enum _WMIPhotoImportSourceType {
    WMIPhotoImportSourceTypeGeneric = 0,
    WMIPhotoImportSourceTypeCamera = 1,
    WMIPhotoImportSourceTypeMediaPlayer = 2,
    WMIPhotoImportSourceTypePhone = 3,
    WMIPhotoImportSourceTypeVideo = 4,
    WMIPhotoImportSourceTypePersonalInfoManager = 5,
    WMIPhotoImportSourceTypeAudioRecorder = 6,
};
typedef unsigned WMIPhotoImportSourceType;

// Windows.Media.Import.PhotoImportContentType
enum _WMIPhotoImportContentType {
    WMIPhotoImportContentTypeUnknown = 0,
    WMIPhotoImportContentTypeImage = 1,
    WMIPhotoImportContentTypeVideo = 2,
};
typedef unsigned WMIPhotoImportContentType;

// Windows.Media.Import.PhotoImportPowerSource
enum _WMIPhotoImportPowerSource {
    WMIPhotoImportPowerSourceUnknown = 0,
    WMIPhotoImportPowerSourceBattery = 1,
    WMIPhotoImportPowerSourceExternal = 2,
};
typedef unsigned WMIPhotoImportPowerSource;

// Windows.Media.Import.PhotoImportStorageMediumType
enum _WMIPhotoImportStorageMediumType {
    WMIPhotoImportStorageMediumTypeUndefined = 0,
    WMIPhotoImportStorageMediumTypeFixed = 1,
    WMIPhotoImportStorageMediumTypeRemovable = 2,
};
typedef unsigned WMIPhotoImportStorageMediumType;

// Windows.Media.Import.PhotoImportContentTypeFilter
enum _WMIPhotoImportContentTypeFilter {
    WMIPhotoImportContentTypeFilterOnlyImages = 0,
    WMIPhotoImportContentTypeFilterOnlyVideos = 1,
    WMIPhotoImportContentTypeFilterImagesAndVideos = 2,
};
typedef unsigned WMIPhotoImportContentTypeFilter;

// Windows.Media.Import.PhotoImportItemSelectionMode
enum _WMIPhotoImportItemSelectionMode {
    WMIPhotoImportItemSelectionModeSelectAll = 0,
    WMIPhotoImportItemSelectionModeSelectNone = 1,
    WMIPhotoImportItemSelectionModeSelectNew = 2,
};
typedef unsigned WMIPhotoImportItemSelectionMode;

// Windows.Media.Import.PhotoImportConnectionTransport
enum _WMIPhotoImportConnectionTransport {
    WMIPhotoImportConnectionTransportUnknown = 0,
    WMIPhotoImportConnectionTransportUsb = 1,
    WMIPhotoImportConnectionTransportIP = 2,
    WMIPhotoImportConnectionTransportBluetooth = 3,
};
typedef unsigned WMIPhotoImportConnectionTransport;

// Windows.Media.Import.PhotoImportSubfolderCreationMode
enum _WMIPhotoImportSubfolderCreationMode {
    WMIPhotoImportSubfolderCreationModeDoNotCreateSubfolders = 0,
    WMIPhotoImportSubfolderCreationModeCreateSubfoldersFromFileDate = 1,
    WMIPhotoImportSubfolderCreationModeCreateSubfoldersFromExifDate = 2,
    WMIPhotoImportSubfolderCreationModeKeepOriginalFolderStructure = 3,
};
typedef unsigned WMIPhotoImportSubfolderCreationMode;

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Media.Import.PhotoImportProgress
WINRT_EXPORT
@interface WMIPhotoImportProgress : NSObject
+ (instancetype) new;
@property unsigned int itemsImported;
@property unsigned int totalItemsToImport;
@property uint64_t bytesImported;
@property uint64_t totalBytesToImport;
@property double importProgress;
@end

// Windows.Media.Import.PhotoImportSource
#ifndef __WMIPhotoImportSource_DEFINED__
#define __WMIPhotoImportSource_DEFINED__

WINRT_EXPORT
@interface WMIPhotoImportSource : RTObject
+ (void)fromIdAsync:(NSString*)sourceId success:(void (^)(WMIPhotoImportSource*))success failure:(void (^)(NSError*))failure;
+ (void)fromFolderAsync:(RTObject<WSIStorageFolder>*)sourceRootFolder
                success:(void (^)(WMIPhotoImportSource*))success
                failure:(void (^)(NSError*))failure;
@property (readonly) id batteryLevelPercent;
@property (readonly) NSString* connectionProtocol;
@property (readonly) WMIPhotoImportConnectionTransport connectionTransport;
@property (readonly) id dateTime;
@property (readonly) NSString* description;
@property (readonly) NSString* displayName;
@property (readonly) NSString* id;
@property (readonly) id isLocked;
@property (readonly) BOOL isMassStorage;
@property (readonly) NSString* manufacturer;
@property (readonly) NSString* model;
@property (readonly) WMIPhotoImportPowerSource powerSource;
@property (readonly) NSString* serialNumber;
@property (readonly) NSArray* storageMedia;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* thumbnail;
@property (readonly) WMIPhotoImportSourceType type;
- (WMIPhotoImportSession*)createImportSession;
@end

#endif // __WMIPhotoImportSource_DEFINED__

// Windows.Media.Import.PhotoImportOperation
#ifndef __WMIPhotoImportOperation_DEFINED__
#define __WMIPhotoImportOperation_DEFINED__

WINRT_EXPORT
@interface WMIPhotoImportOperation : RTObject
;
;
;
@property (readonly) WMIPhotoImportSession* session;
@property (readonly) WMIPhotoImportStage stage;
@end

#endif // __WMIPhotoImportOperation_DEFINED__

// Windows.Media.Import.PhotoImportManager
#ifndef __WMIPhotoImportManager_DEFINED__
#define __WMIPhotoImportManager_DEFINED__

WINRT_EXPORT
@interface WMIPhotoImportManager : RTObject
+ (void)isSupportedAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)findAllSourcesAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (NSArray*)getPendingOperations;
@end

#endif // __WMIPhotoImportManager_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Media.Import.PhotoImportSession
#ifndef __WMIPhotoImportSession_DEFINED__
#define __WMIPhotoImportSession_DEFINED__

WINRT_EXPORT
@interface WMIPhotoImportSession : RTObject <WFIClosable>
@property WMIPhotoImportSubfolderCreationMode subfolderCreationMode;
@property (copy) RTObject<WSIStorageFolder>* destinationFolder;
@property (copy) NSString* destinationFileNamePrefix;
@property BOOL appendSessionDateToDestinationFolder;
@property (readonly) WFGUID* sessionId;
@property (readonly) WMIPhotoImportSource* source;
- (void)findItemsAsync:(WMIPhotoImportContentTypeFilter)contentTypeFilter
     itemSelectionMode:(WMIPhotoImportItemSelectionMode)itemSelectionMode
               success:(void (^)(WMIPhotoImportFindItemsResult*))success
              progress:(void (^)(unsigned int))progress
               failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WMIPhotoImportSession_DEFINED__

// Windows.Media.Import.PhotoImportFindItemsResult
#ifndef __WMIPhotoImportFindItemsResult_DEFINED__
#define __WMIPhotoImportFindItemsResult_DEFINED__

WINRT_EXPORT
@interface WMIPhotoImportFindItemsResult : RTObject
@property (readonly) NSArray* foundItems;
@property (readonly) BOOL hasSucceeded;
@property (readonly) WMIPhotoImportImportMode importMode;
@property (readonly) unsigned int photosCount;
@property (readonly) uint64_t photosSizeInBytes;
@property (readonly) unsigned int selectedPhotosCount;
@property (readonly) uint64_t selectedPhotosSizeInBytes;
@property (readonly) unsigned int selectedSiblingsCount;
@property (readonly) uint64_t selectedSiblingsSizeInBytes;
@property (readonly) unsigned int selectedSidecarsCount;
@property (readonly) uint64_t selectedSidecarsSizeInBytes;
@property (readonly) unsigned int selectedTotalCount;
@property (readonly) uint64_t selectedTotalSizeInBytes;
@property (readonly) unsigned int selectedVideosCount;
@property (readonly) uint64_t selectedVideosSizeInBytes;
@property (readonly) WMIPhotoImportSession* session;
@property (readonly) unsigned int siblingsCount;
@property (readonly) uint64_t siblingsSizeInBytes;
@property (readonly) unsigned int sidecarsCount;
@property (readonly) uint64_t sidecarsSizeInBytes;
@property (readonly) unsigned int totalCount;
@property (readonly) uint64_t totalSizeInBytes;
@property (readonly) unsigned int videosCount;
@property (readonly) uint64_t videosSizeInBytes;
- (EventRegistrationToken)addItemImportedEvent:(void (^)(WMIPhotoImportFindItemsResult*, WMIPhotoImportItemImportedEventArgs*))del;
- (void)removeItemImportedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSelectionChangedEvent:(void (^)(WMIPhotoImportFindItemsResult*, WMIPhotoImportSelectionChangedEventArgs*))del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
- (void)selectAll;
- (void)selectNone;
- (RTObject<WFIAsyncAction>*)selectNewAsync;
- (void)setImportMode:(WMIPhotoImportImportMode)value;
- (void)importItemsAsyncWithSuccess:(void (^)(WMIPhotoImportImportItemsResult*))success
                           progress:(void (^)(WMIPhotoImportProgress*))progress
                            failure:(void (^)(NSError*))failure;
@end

#endif // __WMIPhotoImportFindItemsResult_DEFINED__

// Windows.Media.Import.PhotoImportImportItemsResult
#ifndef __WMIPhotoImportImportItemsResult_DEFINED__
#define __WMIPhotoImportImportItemsResult_DEFINED__

WINRT_EXPORT
@interface WMIPhotoImportImportItemsResult : RTObject
@property (readonly) BOOL hasSucceeded;
@property (readonly) NSArray* importedItems;
@property (readonly) unsigned int photosCount;
@property (readonly) uint64_t photosSizeInBytes;
@property (readonly) WMIPhotoImportSession* session;
@property (readonly) unsigned int siblingsCount;
@property (readonly) uint64_t siblingsSizeInBytes;
@property (readonly) unsigned int sidecarsCount;
@property (readonly) uint64_t sidecarsSizeInBytes;
@property (readonly) unsigned int totalCount;
@property (readonly) uint64_t totalSizeInBytes;
@property (readonly) unsigned int videosCount;
@property (readonly) uint64_t videosSizeInBytes;
- (void)deleteImportedItemsFromSourceAsyncWithSuccess:(void (^)(WMIPhotoImportDeleteImportedItemsFromSourceResult*))success
                                             progress:(void (^)(double))progress
                                              failure:(void (^)(NSError*))failure;
@end

#endif // __WMIPhotoImportImportItemsResult_DEFINED__

// Windows.Media.Import.PhotoImportDeleteImportedItemsFromSourceResult
#ifndef __WMIPhotoImportDeleteImportedItemsFromSourceResult_DEFINED__
#define __WMIPhotoImportDeleteImportedItemsFromSourceResult_DEFINED__

WINRT_EXPORT
@interface WMIPhotoImportDeleteImportedItemsFromSourceResult : RTObject
@property (readonly) NSArray* deletedItems;
@property (readonly) BOOL hasSucceeded;
@property (readonly) unsigned int photosCount;
@property (readonly) uint64_t photosSizeInBytes;
@property (readonly) WMIPhotoImportSession* session;
@property (readonly) unsigned int siblingsCount;
@property (readonly) uint64_t siblingsSizeInBytes;
@property (readonly) unsigned int sidecarsCount;
@property (readonly) uint64_t sidecarsSizeInBytes;
@property (readonly) unsigned int totalCount;
@property (readonly) uint64_t totalSizeInBytes;
@property (readonly) unsigned int videosCount;
@property (readonly) uint64_t videosSizeInBytes;
@end

#endif // __WMIPhotoImportDeleteImportedItemsFromSourceResult_DEFINED__

// Windows.Media.Import.PhotoImportStorageMedium
#ifndef __WMIPhotoImportStorageMedium_DEFINED__
#define __WMIPhotoImportStorageMedium_DEFINED__

WINRT_EXPORT
@interface WMIPhotoImportStorageMedium : RTObject
@property (readonly) uint64_t availableSpaceInBytes;
@property (readonly) uint64_t capacityInBytes;
@property (readonly) NSString* description;
@property (readonly) NSString* name;
@property (readonly) NSString* serialNumber;
@property (readonly) WMIPhotoImportStorageMediumType storageMediumType;
@property (readonly) WMIPhotoImportAccessMode supportedAccessMode;
- (void)refresh;
@end

#endif // __WMIPhotoImportStorageMedium_DEFINED__

// Windows.Media.Import.PhotoImportSidecar
#ifndef __WMIPhotoImportSidecar_DEFINED__
#define __WMIPhotoImportSidecar_DEFINED__

WINRT_EXPORT
@interface WMIPhotoImportSidecar : RTObject
@property (readonly) WFDateTime* date;
@property (readonly) NSString* name;
@property (readonly) uint64_t sizeInBytes;
@end

#endif // __WMIPhotoImportSidecar_DEFINED__

// Windows.Media.Import.PhotoImportVideoSegment
#ifndef __WMIPhotoImportVideoSegment_DEFINED__
#define __WMIPhotoImportVideoSegment_DEFINED__

WINRT_EXPORT
@interface WMIPhotoImportVideoSegment : RTObject
@property (readonly) WFDateTime* date;
@property (readonly) NSString* name;
@property (readonly) WMIPhotoImportSidecar* sibling;
@property (readonly) NSArray* sidecars;
@property (readonly) uint64_t sizeInBytes;
@end

#endif // __WMIPhotoImportVideoSegment_DEFINED__

// Windows.Media.Import.PhotoImportItem
#ifndef __WMIPhotoImportItem_DEFINED__
#define __WMIPhotoImportItem_DEFINED__

WINRT_EXPORT
@interface WMIPhotoImportItem : RTObject
@property BOOL isSelected;
@property (readonly) WMIPhotoImportContentType contentType;
@property (readonly) WFDateTime* date;
@property (readonly) NSArray* deletedFileNames;
@property (readonly) NSArray* importedFileNames;
@property (readonly) uint64_t itemKey;
@property (readonly) NSString* name;
@property (readonly) WMIPhotoImportSidecar* sibling;
@property (readonly) NSArray* sidecars;
@property (readonly) uint64_t sizeInBytes;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* thumbnail;
@property (readonly) NSArray* videoSegments;
@end

#endif // __WMIPhotoImportItem_DEFINED__

// Windows.Media.Import.PhotoImportSelectionChangedEventArgs
#ifndef __WMIPhotoImportSelectionChangedEventArgs_DEFINED__
#define __WMIPhotoImportSelectionChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMIPhotoImportSelectionChangedEventArgs : RTObject
@property (readonly) BOOL isSelectionEmpty;
@end

#endif // __WMIPhotoImportSelectionChangedEventArgs_DEFINED__

// Windows.Media.Import.PhotoImportItemImportedEventArgs
#ifndef __WMIPhotoImportItemImportedEventArgs_DEFINED__
#define __WMIPhotoImportItemImportedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMIPhotoImportItemImportedEventArgs : RTObject
@property (readonly) WMIPhotoImportItem* importedItem;
@end

#endif // __WMIPhotoImportItemImportedEventArgs_DEFINED__
