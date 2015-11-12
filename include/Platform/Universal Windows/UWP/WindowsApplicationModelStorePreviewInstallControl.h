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

// WindowsApplicationModelStorePreviewInstallControl.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WASPIAppInstallStatus, WASPIAppInstallItem, WASPIAppInstallManagerItemEventArgs, WASPIAppInstallManager;
@protocol WASPIIAppInstallStatus
, WASPIIAppInstallItem, WASPIIAppInstallManagerItemEventArgs, WASPIIAppInstallManager;

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

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Store.Preview.InstallControl.AppInstallStatus
#ifndef __WASPIAppInstallStatus_DEFINED__
#define __WASPIAppInstallStatus_DEFINED__

WINRT_EXPORT
@interface WASPIAppInstallStatus : RTObject
@property (readonly) uint64_t bytesDownloaded;
@property (readonly) uint64_t downloadSizeInBytes;
@property (readonly) HRESULT errorCode;
@property (readonly) WASPIAppInstallState installState;
@property (readonly) double percentComplete;
@end

#endif // __WASPIAppInstallStatus_DEFINED__

// Windows.ApplicationModel.Store.Preview.InstallControl.AppInstallItem
#ifndef __WASPIAppInstallItem_DEFINED__
#define __WASPIAppInstallItem_DEFINED__

WINRT_EXPORT
@interface WASPIAppInstallItem : RTObject
@property (readonly) WASPIAppInstallType installType;
@property (readonly) BOOL isUserInitiated;
@property (readonly) NSString* packageFamilyName;
@property (readonly) NSString* productId;
- (EventRegistrationToken)addCompletedEvent:(void (^)(WASPIAppInstallItem*, RTObject*))del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStatusChangedEvent:(void (^)(WASPIAppInstallItem*, RTObject*))del;
- (void)removeStatusChangedEvent:(EventRegistrationToken)tok;
- (WASPIAppInstallStatus*)getCurrentStatus;
- (void)cancel;
- (void)pause;
- (void)restart;
@end

#endif // __WASPIAppInstallItem_DEFINED__

// Windows.ApplicationModel.Store.Preview.InstallControl.AppInstallManagerItemEventArgs
#ifndef __WASPIAppInstallManagerItemEventArgs_DEFINED__
#define __WASPIAppInstallManagerItemEventArgs_DEFINED__

WINRT_EXPORT
@interface WASPIAppInstallManagerItemEventArgs : RTObject
@property (readonly) WASPIAppInstallItem* item;
@end

#endif // __WASPIAppInstallManagerItemEventArgs_DEFINED__

// Windows.ApplicationModel.Store.Preview.InstallControl.AppInstallManager
#ifndef __WASPIAppInstallManager_DEFINED__
#define __WASPIAppInstallManager_DEFINED__

WINRT_EXPORT
@interface WASPIAppInstallManager : RTObject
+ (instancetype)create ACTIVATOR;
@property WASPIAutoUpdateSetting autoUpdateSetting;
@property (copy) NSString* acquisitionIdentity;
@property (readonly) NSArray* appInstallItems;
- (EventRegistrationToken)addItemCompletedEvent:(void (^)(WASPIAppInstallManager*, WASPIAppInstallManagerItemEventArgs*))del;
- (void)removeItemCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addItemStatusChangedEvent:(void (^)(WASPIAppInstallManager*, WASPIAppInstallManagerItemEventArgs*))del;
- (void)removeItemStatusChangedEvent:(EventRegistrationToken)tok;
- (void)cancel:(NSString*)productId;
- (void)pause:(NSString*)productId;
- (void)restart:(NSString*)productId;
- (void)getIsApplicableAsync:(NSString*)productId
                       skuId:(NSString*)skuId
                     success:(void (^)(BOOL))success
                     failure:(void (^)(NSError*))failure;
- (void)startAppInstallAsync:(NSString*)productId
                            skuId:(NSString*)skuId
                           repair:(BOOL)repair
    forceUseOfNonRemovableStorage:(BOOL)forceUseOfNonRemovableStorage
                          success:(void (^)(WASPIAppInstallItem*))success
                          failure:(void (^)(NSError*))failure;
- (void)updateAppByPackageFamilyNameAsync:(NSString*)packageFamilyName
                                  success:(void (^)(WASPIAppInstallItem*))success
                                  failure:(void (^)(NSError*))failure;
- (void)searchForUpdatesAsync:(NSString*)productId
                        skuId:(NSString*)skuId
                      success:(void (^)(WASPIAppInstallItem*))success
                      failure:(void (^)(NSError*))failure;
- (void)searchForAllUpdatesAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)isStoreBlockedByPolicyAsync:(NSString*)storeClientName
               storeClientPublisher:(NSString*)storeClientPublisher
                            success:(void (^)(BOOL))success
                            failure:(void (^)(NSError*))failure;
- (void)getIsAppAllowedToInstallAsync:(NSString*)productId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WASPIAppInstallManager_DEFINED__
