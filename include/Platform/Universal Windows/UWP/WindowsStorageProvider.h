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

// WindowsStorageProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSTORAGEEXPORT
#define OBJCUWPWINDOWSSTORAGEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsStorage.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSPCachedFileUpdaterUI, WSPFileUpdateRequestedEventArgs, WSPFileUpdateRequest, WSPFileUpdateRequestDeferral, WSPCachedFileUpdater, WSPStorageProviderItemProperty, WSPStorageProviderItemProperties, WSPStorageProviderItemPropertyDefinition, WSPStorageProviderSyncRootInfo, WSPStorageProviderSyncRootManager;
@protocol WSPICachedFileUpdaterUI, WSPIFileUpdateRequestedEventArgs, WSPIFileUpdateRequest, WSPIFileUpdateRequestDeferral, WSPICachedFileUpdaterUI2, WSPIFileUpdateRequest2, WSPICachedFileUpdaterStatics, WSPIStorageProviderPropertyCapabilities, WSPIStorageProviderItemProperty, WSPIStorageProviderItemPropertiesStatics, WSPIStorageProviderItemPropertySource, WSPIStorageProviderItemPropertyDefinition, WSPIStorageProviderSyncRootInfo, WSPIStorageProviderSyncRootManagerStatics;

// Windows.Storage.Provider.CachedFileTarget
enum _WSPCachedFileTarget {
    WSPCachedFileTargetLocal = 0,
    WSPCachedFileTargetRemote = 1,
};
typedef unsigned WSPCachedFileTarget;

// Windows.Storage.Provider.UIStatus
enum _WSPUIStatus {
    WSPUIStatusUnavailable = 0,
    WSPUIStatusHidden = 1,
    WSPUIStatusVisible = 2,
    WSPUIStatusComplete = 3,
};
typedef unsigned WSPUIStatus;

// Windows.Storage.Provider.FileUpdateStatus
enum _WSPFileUpdateStatus {
    WSPFileUpdateStatusIncomplete = 0,
    WSPFileUpdateStatusComplete = 1,
    WSPFileUpdateStatusUserInputNeeded = 2,
    WSPFileUpdateStatusCurrentlyUnavailable = 3,
    WSPFileUpdateStatusFailed = 4,
    WSPFileUpdateStatusCompleteAndRenamed = 5,
};
typedef unsigned WSPFileUpdateStatus;

// Windows.Storage.Provider.CachedFileOptions
enum _WSPCachedFileOptions {
    WSPCachedFileOptionsNone = 0,
    WSPCachedFileOptionsRequireUpdateOnAccess = 1,
    WSPCachedFileOptionsUseCachedFileWhenOffline = 2,
    WSPCachedFileOptionsDenyAccessWhenOffline = 4,
};
typedef unsigned WSPCachedFileOptions;

// Windows.Storage.Provider.ReadActivationMode
enum _WSPReadActivationMode {
    WSPReadActivationModeNotNeeded = 0,
    WSPReadActivationModeBeforeAccess = 1,
};
typedef unsigned WSPReadActivationMode;

// Windows.Storage.Provider.WriteActivationMode
enum _WSPWriteActivationMode {
    WSPWriteActivationModeReadOnly = 0,
    WSPWriteActivationModeNotNeeded = 1,
    WSPWriteActivationModeAfterWrite = 2,
};
typedef unsigned WSPWriteActivationMode;

// Windows.Storage.Provider.StorageProviderHydrationPolicy
enum _WSPStorageProviderHydrationPolicy {
    WSPStorageProviderHydrationPolicyPartial = 0,
    WSPStorageProviderHydrationPolicyProgressive = 1,
    WSPStorageProviderHydrationPolicyFull = 2,
    WSPStorageProviderHydrationPolicyAlwaysFull = 3,
};
typedef unsigned WSPStorageProviderHydrationPolicy;

// Windows.Storage.Provider.StorageProviderPopulationPolicy
enum _WSPStorageProviderPopulationPolicy {
    WSPStorageProviderPopulationPolicyFull = 1,
    WSPStorageProviderPopulationPolicyAlwaysFull = 2,
};
typedef unsigned WSPStorageProviderPopulationPolicy;

// Windows.Storage.Provider.StorageProviderHydrationPolicyModifier
enum _WSPStorageProviderHydrationPolicyModifier {
    WSPStorageProviderHydrationPolicyModifierNone = 0,
    WSPStorageProviderHydrationPolicyModifierValidationRequired = 1,
    WSPStorageProviderHydrationPolicyModifierStreamingAllowed = 2,
};
typedef unsigned WSPStorageProviderHydrationPolicyModifier;

// Windows.Storage.Provider.StorageProviderInSyncPolicy
enum _WSPStorageProviderInSyncPolicy {
    WSPStorageProviderInSyncPolicyDefault = 0,
    WSPStorageProviderInSyncPolicyFileCreationTime = 1,
    WSPStorageProviderInSyncPolicyFileReadOnlyAttribute = 2,
    WSPStorageProviderInSyncPolicyFileHiddenAttribute = 4,
    WSPStorageProviderInSyncPolicyFileSystemAttribute = 8,
    WSPStorageProviderInSyncPolicyDirectoryCreationTime = 16,
    WSPStorageProviderInSyncPolicyDirectoryReadOnlyAttribute = 32,
    WSPStorageProviderInSyncPolicyDirectoryHiddenAttribute = 64,
    WSPStorageProviderInSyncPolicyDirectorySystemAttribute = 128,
    WSPStorageProviderInSyncPolicyFileLastWriteTime = 256,
    WSPStorageProviderInSyncPolicyDirectoryLastWriteTime = 512,
    WSPStorageProviderInSyncPolicyPreserveInsyncForSyncEngine = -2147483648,
};
typedef unsigned WSPStorageProviderInSyncPolicy;

// Windows.Storage.Provider.StorageProviderHardlinkPolicy
enum _WSPStorageProviderHardlinkPolicy {
    WSPStorageProviderHardlinkPolicyNone = 0,
    WSPStorageProviderHardlinkPolicyAllowed = 1,
};
typedef unsigned WSPStorageProviderHardlinkPolicy;

// Windows.Storage.Provider.StorageProviderProtectionMode
enum _WSPStorageProviderProtectionMode {
    WSPStorageProviderProtectionModeUnknown = 0,
    WSPStorageProviderProtectionModePersonal = 1,
};
typedef unsigned WSPStorageProviderProtectionMode;

#include "WindowsFoundation.h"
#include "WindowsStorage.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.Storage.Provider.IStorageProviderPropertyCapabilities
#ifndef __WSPIStorageProviderPropertyCapabilities_DEFINED__
#define __WSPIStorageProviderPropertyCapabilities_DEFINED__

@protocol WSPIStorageProviderPropertyCapabilities
- (BOOL)isPropertySupported:(NSString *)propertyCanonicalName;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSPIStorageProviderPropertyCapabilities : RTObject <WSPIStorageProviderPropertyCapabilities>
@end

#endif // __WSPIStorageProviderPropertyCapabilities_DEFINED__

// Windows.Storage.Provider.IStorageProviderItemPropertySource
#ifndef __WSPIStorageProviderItemPropertySource_DEFINED__
#define __WSPIStorageProviderItemPropertySource_DEFINED__

@protocol WSPIStorageProviderItemPropertySource
- (id<NSFastEnumeration> /* WSPStorageProviderItemProperty* */)getItemProperties:(NSString *)itemPath;
@end

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSPIStorageProviderItemPropertySource : RTObject <WSPIStorageProviderItemPropertySource>
@end

#endif // __WSPIStorageProviderItemPropertySource_DEFINED__

// Windows.Storage.Provider.CachedFileUpdaterUI
#ifndef __WSPCachedFileUpdaterUI_DEFINED__
#define __WSPCachedFileUpdaterUI_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSPCachedFileUpdaterUI : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * title;
@property (readonly) WSPUIStatus uIStatus;
@property (readonly) WSPCachedFileTarget updateTarget;
@property (readonly) WSPFileUpdateRequest* updateRequest;
- (EventRegistrationToken)addFileUpdateRequestedEvent:(void(^)(WSPCachedFileUpdaterUI*, WSPFileUpdateRequestedEventArgs*))del;
- (void)removeFileUpdateRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUIRequestedEvent:(void(^)(WSPCachedFileUpdaterUI*, RTObject*))del;
- (void)removeUIRequestedEvent:(EventRegistrationToken)tok;
- (WSPFileUpdateRequestDeferral*)getDeferral;
@end

#endif // __WSPCachedFileUpdaterUI_DEFINED__

// Windows.Storage.Provider.FileUpdateRequestedEventArgs
#ifndef __WSPFileUpdateRequestedEventArgs_DEFINED__
#define __WSPFileUpdateRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSPFileUpdateRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSPFileUpdateRequest* request;
@end

#endif // __WSPFileUpdateRequestedEventArgs_DEFINED__

// Windows.Storage.Provider.FileUpdateRequest
#ifndef __WSPFileUpdateRequest_DEFINED__
#define __WSPFileUpdateRequest_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSPFileUpdateRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WSPFileUpdateStatus status;
@property (readonly) NSString * contentId;
@property (readonly) WSStorageFile* file;
@property (retain) NSString * userInputNeededMessage;
- (WSPFileUpdateRequestDeferral*)getDeferral;
- (void)updateLocalFile:(RTObject<WSIStorageFile>*)value;
@end

#endif // __WSPFileUpdateRequest_DEFINED__

// Windows.Storage.Provider.FileUpdateRequestDeferral
#ifndef __WSPFileUpdateRequestDeferral_DEFINED__
#define __WSPFileUpdateRequestDeferral_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSPFileUpdateRequestDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WSPFileUpdateRequestDeferral_DEFINED__

// Windows.Storage.Provider.CachedFileUpdater
#ifndef __WSPCachedFileUpdater_DEFINED__
#define __WSPCachedFileUpdater_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSPCachedFileUpdater : RTObject
+ (void)setUpdateInformation:(RTObject<WSIStorageFile>*)file contentId:(NSString *)contentId readMode:(WSPReadActivationMode)readMode writeMode:(WSPWriteActivationMode)writeMode options:(WSPCachedFileOptions)options;
@end

#endif // __WSPCachedFileUpdater_DEFINED__

// Windows.Storage.Provider.StorageProviderItemProperty
#ifndef __WSPStorageProviderItemProperty_DEFINED__
#define __WSPStorageProviderItemProperty_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSPStorageProviderItemProperty : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * value;
@property int id;
@property (retain) NSString * iconResource;
@end

#endif // __WSPStorageProviderItemProperty_DEFINED__

// Windows.Storage.Provider.StorageProviderItemProperties
#ifndef __WSPStorageProviderItemProperties_DEFINED__
#define __WSPStorageProviderItemProperties_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSPStorageProviderItemProperties : RTObject
+ (RTObject<WFIAsyncAction>*)setAsync:(RTObject<WSIStorageItem>*)item itemProperties:(id<NSFastEnumeration> /* WSPStorageProviderItemProperty* */)itemProperties;
@end

#endif // __WSPStorageProviderItemProperties_DEFINED__

// Windows.Storage.Provider.StorageProviderItemPropertyDefinition
#ifndef __WSPStorageProviderItemPropertyDefinition_DEFINED__
#define __WSPStorageProviderItemPropertyDefinition_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSPStorageProviderItemPropertyDefinition : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property int id;
@property (retain) NSString * displayNameResource;
@end

#endif // __WSPStorageProviderItemPropertyDefinition_DEFINED__

// Windows.Storage.Provider.StorageProviderSyncRootInfo
#ifndef __WSPStorageProviderSyncRootInfo_DEFINED__
#define __WSPStorageProviderSyncRootInfo_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSPStorageProviderSyncRootInfo : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * Version;
@property BOOL showSiblingsAsGroup;
@property (retain) WFUri* recycleBinUri;
@property WSPStorageProviderProtectionMode protectionMode;
@property WSPStorageProviderPopulationPolicy populationPolicy;
@property (retain) RTObject<WSIStorageFolder>* path;
@property WSPStorageProviderInSyncPolicy inSyncPolicy;
@property (retain) NSString * id;
@property (retain) NSString * iconResource;
@property WSPStorageProviderHydrationPolicyModifier hydrationPolicyModifier;
@property WSPStorageProviderHydrationPolicy hydrationPolicy;
@property WSPStorageProviderHardlinkPolicy hardlinkPolicy;
@property (retain) NSString * displayNameResource;
@property (retain) RTObject<WSSIBuffer>* context;
@property BOOL allowPinning;
@property (readonly) NSMutableArray* /* WSPStorageProviderItemPropertyDefinition* */ storageProviderItemPropertyDefinitions;
@end

#endif // __WSPStorageProviderSyncRootInfo_DEFINED__

// Windows.Storage.Provider.StorageProviderSyncRootManager
#ifndef __WSPStorageProviderSyncRootManager_DEFINED__
#define __WSPStorageProviderSyncRootManager_DEFINED__

OBJCUWPWINDOWSSTORAGEEXPORT
@interface WSPStorageProviderSyncRootManager : RTObject
+ (void)Register:(WSPStorageProviderSyncRootInfo*)syncRootInformation;
+ (void)unregister:(NSString *)id;
+ (WSPStorageProviderSyncRootInfo*)getSyncRootInformationForFolder:(RTObject<WSIStorageFolder>*)folder;
+ (WSPStorageProviderSyncRootInfo*)getSyncRootInformationForId:(NSString *)id;
+ (NSArray* /* WSPStorageProviderSyncRootInfo* */)getCurrentSyncRoots;
@end

#endif // __WSPStorageProviderSyncRootManager_DEFINED__

