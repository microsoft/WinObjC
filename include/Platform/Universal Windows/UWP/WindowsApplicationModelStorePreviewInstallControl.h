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

// WindowsApplicationModelStorePreviewInstallControl.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWINSTALLCONTROLEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWINSTALLCONTROLEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelStorePreviewInstallControl.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WASPIAppInstallStatus, WASPIAppInstallItem, WASPIGetEntitlementResult, WASPIAppInstallManagerItemEventArgs, WASPIAppInstallManager;
@protocol WASPIIAppInstallStatus, WASPIIAppInstallStatus2, WASPIIAppInstallItem, WASPIIAppInstallItem2, WASPIIAppInstallItem3, WASPIIGetEntitlementResult, WASPIIAppInstallManagerItemEventArgs, WASPIIAppInstallManager, WASPIIAppInstallManager2, WASPIIAppInstallManager3, WASPIIAppInstallManager4, WASPIIAppInstallManager5;

// Windows.ApplicationModel.Store.Preview.InstallControl.GetEntitlementStatus
enum _WASPIGetEntitlementStatus {
    WASPIGetEntitlementStatusSucceeded = 0,
    WASPIGetEntitlementStatusNoStoreAccount = 1,
    WASPIGetEntitlementStatusNetworkError = 2,
    WASPIGetEntitlementStatusServerError = 3,
};
typedef unsigned WASPIGetEntitlementStatus;

// Windows.ApplicationModel.Store.Preview.InstallControl.AppInstallState
enum _WASPIAppInstallState {
    WASPIAppInstallStatePending = 0,
    WASPIAppInstallStateStarting = 1,
    WASPIAppInstallStateAcquiringLicense = 2,
    WASPIAppInstallStateDownloading = 3,
    WASPIAppInstallStateRestoringData = 4,
    WASPIAppInstallStateInstalling = 5,
    WASPIAppInstallStateCompleted = 6,
    WASPIAppInstallStateCanceled = 7,
    WASPIAppInstallStatePaused = 8,
    WASPIAppInstallStateError = 9,
    WASPIAppInstallStatePausedLowBattery = 10,
    WASPIAppInstallStatePausedWiFiRecommended = 11,
    WASPIAppInstallStatePausedWiFiRequired = 12,
    WASPIAppInstallStateReadyToDownload = 13,
};
typedef unsigned WASPIAppInstallState;

// Windows.ApplicationModel.Store.Preview.InstallControl.AppInstallType
enum _WASPIAppInstallType {
    WASPIAppInstallTypeInstall = 0,
    WASPIAppInstallTypeUpdate = 1,
    WASPIAppInstallTypeRepair = 2,
};
typedef unsigned WASPIAppInstallType;

// Windows.ApplicationModel.Store.Preview.InstallControl.AutoUpdateSetting
enum _WASPIAutoUpdateSetting {
    WASPIAutoUpdateSettingDisabled = 0,
    WASPIAutoUpdateSettingEnabled = 1,
    WASPIAutoUpdateSettingDisabledByPolicy = 2,
    WASPIAutoUpdateSettingEnabledByPolicy = 3,
};
typedef unsigned WASPIAutoUpdateSetting;

#include "WindowsFoundation.h"
#include "WindowsSystem.h"
#include "WindowsManagementDeployment.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Store.Preview.InstallControl.AppInstallStatus
#ifndef __WASPIAppInstallStatus_DEFINED__
#define __WASPIAppInstallStatus_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWINSTALLCONTROLEXPORT
@interface WASPIAppInstallStatus : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint64_t bytesDownloaded;
@property (readonly) uint64_t downloadSizeInBytes;
@property (readonly) HRESULT errorCode;
@property (readonly) WASPIAppInstallState installState;
@property (readonly) double percentComplete;
@property (readonly) BOOL readyForLaunch;
@property (readonly) WSUser* user;
@end

#endif // __WASPIAppInstallStatus_DEFINED__

// Windows.ApplicationModel.Store.Preview.InstallControl.AppInstallItem
#ifndef __WASPIAppInstallItem_DEFINED__
#define __WASPIAppInstallItem_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWINSTALLCONTROLEXPORT
@interface WASPIAppInstallItem : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WASPIAppInstallType installType;
@property (readonly) BOOL isUserInitiated;
@property (readonly) NSString * packageFamilyName;
@property (readonly) NSString * productId;
@property (readonly) NSArray* /* WASPIAppInstallItem* */ children;
@property (readonly) BOOL itemOperationsMightAffectOtherItems;
- (EventRegistrationToken)addCompletedEvent:(void(^)(WASPIAppInstallItem*, RTObject*))del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStatusChangedEvent:(void(^)(WASPIAppInstallItem*, RTObject*))del;
- (void)removeStatusChangedEvent:(EventRegistrationToken)tok;
- (WASPIAppInstallStatus*)getCurrentStatus;
- (void)cancel;
- (void)pause;
- (void)restart;
- (void)cancelWithTelemetry:(NSString *)correlationVector;
- (void)pauseWithTelemetry:(NSString *)correlationVector;
- (void)restartWithTelemetry:(NSString *)correlationVector;
@end

#endif // __WASPIAppInstallItem_DEFINED__

// Windows.ApplicationModel.Store.Preview.InstallControl.GetEntitlementResult
#ifndef __WASPIGetEntitlementResult_DEFINED__
#define __WASPIGetEntitlementResult_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWINSTALLCONTROLEXPORT
@interface WASPIGetEntitlementResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WASPIGetEntitlementStatus status;
@end

#endif // __WASPIGetEntitlementResult_DEFINED__

// Windows.ApplicationModel.Store.Preview.InstallControl.AppInstallManagerItemEventArgs
#ifndef __WASPIAppInstallManagerItemEventArgs_DEFINED__
#define __WASPIAppInstallManagerItemEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWINSTALLCONTROLEXPORT
@interface WASPIAppInstallManagerItemEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WASPIAppInstallItem* item;
@end

#endif // __WASPIAppInstallManagerItemEventArgs_DEFINED__

// Windows.ApplicationModel.Store.Preview.InstallControl.AppInstallManager
#ifndef __WASPIAppInstallManager_DEFINED__
#define __WASPIAppInstallManager_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWINSTALLCONTROLEXPORT
@interface WASPIAppInstallManager : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WASPIAutoUpdateSetting autoUpdateSetting;
@property (retain) NSString * acquisitionIdentity;
@property (readonly) NSArray* /* WASPIAppInstallItem* */ appInstallItems;
@property (readonly) NSArray* /* WASPIAppInstallItem* */ appInstallItemsWithGroupSupport;
- (EventRegistrationToken)addItemCompletedEvent:(void(^)(WASPIAppInstallManager*, WASPIAppInstallManagerItemEventArgs*))del;
- (void)removeItemCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addItemStatusChangedEvent:(void(^)(WASPIAppInstallManager*, WASPIAppInstallManagerItemEventArgs*))del;
- (void)removeItemStatusChangedEvent:(EventRegistrationToken)tok;
- (void)cancel:(NSString *)productId;
- (void)pause:(NSString *)productId;
- (void)restart:(NSString *)productId;
- (void)getIsApplicableAsync:(NSString *)productId skuId:(NSString *)skuId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)startAppInstallAsync:(NSString *)productId skuId:(NSString *)skuId repair:(BOOL)repair forceUseOfNonRemovableStorage:(BOOL)forceUseOfNonRemovableStorage success:(void (^)(WASPIAppInstallItem*))success failure:(void (^)(NSError*))failure;
- (void)updateAppByPackageFamilyNameAsync:(NSString *)packageFamilyName success:(void (^)(WASPIAppInstallItem*))success failure:(void (^)(NSError*))failure;
- (void)searchForUpdatesAsync:(NSString *)productId skuId:(NSString *)skuId success:(void (^)(WASPIAppInstallItem*))success failure:(void (^)(NSError*))failure;
- (void)searchForAllUpdatesAsyncWithSuccess:(void (^)(NSArray* /* WASPIAppInstallItem* */))success failure:(void (^)(NSError*))failure;
- (void)isStoreBlockedByPolicyAsync:(NSString *)storeClientName storeClientPublisher:(NSString *)storeClientPublisher success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)getIsAppAllowedToInstallAsync:(NSString *)productId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)startAppInstallWithTelemetryAsync:(NSString *)productId skuId:(NSString *)skuId repair:(BOOL)repair forceUseOfNonRemovableStorage:(BOOL)forceUseOfNonRemovableStorage catalogId:(NSString *)catalogId bundleId:(NSString *)bundleId correlationVector:(NSString *)correlationVector success:(void (^)(WASPIAppInstallItem*))success failure:(void (^)(NSError*))failure;
- (void)updateAppByPackageFamilyNameWithTelemetryAsync:(NSString *)packageFamilyName correlationVector:(NSString *)correlationVector success:(void (^)(WASPIAppInstallItem*))success failure:(void (^)(NSError*))failure;
- (void)searchForUpdatesWithTelemetryAsync:(NSString *)productId skuId:(NSString *)skuId catalogId:(NSString *)catalogId correlationVector:(NSString *)correlationVector success:(void (^)(WASPIAppInstallItem*))success failure:(void (^)(NSError*))failure;
- (void)searchForAllUpdatesWithTelemetryAsync:(NSString *)correlationVector success:(void (^)(NSArray* /* WASPIAppInstallItem* */))success failure:(void (^)(NSError*))failure;
- (void)getIsAppAllowedToInstallWithTelemetryAsync:(NSString *)productId skuId:(NSString *)skuId catalogId:(NSString *)catalogId correlationVector:(NSString *)correlationVector success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)cancelWithTelemetry:(NSString *)productId correlationVector:(NSString *)correlationVector;
- (void)pauseWithTelemetry:(NSString *)productId correlationVector:(NSString *)correlationVector;
- (void)restartWithTelemetry:(NSString *)productId correlationVector:(NSString *)correlationVector;
- (void)startProductInstallAsync:(NSString *)productId catalogId:(NSString *)catalogId flightId:(NSString *)flightId clientId:(NSString *)clientId repair:(BOOL)repair forceUseOfNonRemovableStorage:(BOOL)forceUseOfNonRemovableStorage correlationVector:(NSString *)correlationVector targetVolume:(WMDPackageVolume*)targetVolume success:(void (^)(NSArray* /* WASPIAppInstallItem* */))success failure:(void (^)(NSError*))failure;
- (void)startProductInstallForUserAsync:(WSUser*)user productId:(NSString *)productId catalogId:(NSString *)catalogId flightId:(NSString *)flightId clientId:(NSString *)clientId repair:(BOOL)repair forceUseOfNonRemovableStorage:(BOOL)forceUseOfNonRemovableStorage correlationVector:(NSString *)correlationVector targetVolume:(WMDPackageVolume*)targetVolume success:(void (^)(NSArray* /* WASPIAppInstallItem* */))success failure:(void (^)(NSError*))failure;
- (void)updateAppByPackageFamilyNameForUserAsync:(WSUser*)user packageFamilyName:(NSString *)packageFamilyName correlationVector:(NSString *)correlationVector success:(void (^)(WASPIAppInstallItem*))success failure:(void (^)(NSError*))failure;
- (void)searchForUpdatesForUserAsync:(WSUser*)user productId:(NSString *)productId skuId:(NSString *)skuId catalogId:(NSString *)catalogId correlationVector:(NSString *)correlationVector success:(void (^)(WASPIAppInstallItem*))success failure:(void (^)(NSError*))failure;
- (void)searchForAllUpdatesForUserAsync:(WSUser*)user correlationVector:(NSString *)correlationVector success:(void (^)(NSArray* /* WASPIAppInstallItem* */))success failure:(void (^)(NSError*))failure;
- (void)getIsAppAllowedToInstallForUserAsync:(WSUser*)user productId:(NSString *)productId skuId:(NSString *)skuId catalogId:(NSString *)catalogId correlationVector:(NSString *)correlationVector success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)getIsApplicableForUserAsync:(WSUser*)user productId:(NSString *)productId skuId:(NSString *)skuId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)moveToFrontOfDownloadQueue:(NSString *)productId correlationVector:(NSString *)correlationVector;
- (void)getFreeUserEntitlementAsync:(NSString *)storeId campaignId:(NSString *)campaignId correlationVector:(NSString *)correlationVector success:(void (^)(WASPIGetEntitlementResult*))success failure:(void (^)(NSError*))failure;
- (void)getFreeUserEntitlementForUserAsync:(WSUser*)user storeId:(NSString *)storeId campaignId:(NSString *)campaignId correlationVector:(NSString *)correlationVector success:(void (^)(WASPIGetEntitlementResult*))success failure:(void (^)(NSError*))failure;
- (void)getFreeDeviceEntitlementAsync:(NSString *)storeId campaignId:(NSString *)campaignId correlationVector:(NSString *)correlationVector success:(void (^)(WASPIGetEntitlementResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WASPIAppInstallManager_DEFINED__

