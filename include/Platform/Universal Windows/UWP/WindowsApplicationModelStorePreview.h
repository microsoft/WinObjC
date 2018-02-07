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

// WindowsApplicationModelStorePreview.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelStorePreview.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WASPStorePreviewSkuInfo, WASPStorePreviewPurchaseResults, WASPStorePreviewProductInfo, WASPStoreHardwareManufacturerInfo, WASPStorePreview, WASPStoreConfiguration, WASPWebAuthenticationCoreManagerHelper;
@protocol WASPIStorePreviewProductInfo, WASPIStorePreviewSkuInfo, WASPIStorePreviewPurchaseResults, WASPIStorePreview, WASPIStoreHardwareManufacturerInfo, WASPIStoreConfigurationStatics, WASPIStoreConfigurationStatics2, WASPIStoreConfigurationStatics3, WASPIStoreConfigurationStatics4, WASPIWebAuthenticationCoreManagerHelper;

// Windows.ApplicationModel.Store.Preview.StorePreviewProductPurchaseStatus
enum _WASPStorePreviewProductPurchaseStatus {
    WASPStorePreviewProductPurchaseStatusSucceeded = 0,
    WASPStorePreviewProductPurchaseStatusAlreadyPurchased = 1,
    WASPStorePreviewProductPurchaseStatusNotFulfilled = 2,
    WASPStorePreviewProductPurchaseStatusNotPurchased = 3,
};
typedef unsigned WASPStorePreviewProductPurchaseStatus;

// Windows.ApplicationModel.Store.Preview.StoreSystemFeature
enum _WASPStoreSystemFeature {
    WASPStoreSystemFeatureArchitectureX86 = 0,
    WASPStoreSystemFeatureArchitectureX64 = 1,
    WASPStoreSystemFeatureArchitectureArm = 2,
    WASPStoreSystemFeatureDirectX9 = 3,
    WASPStoreSystemFeatureDirectX10 = 4,
    WASPStoreSystemFeatureDirectX11 = 5,
    WASPStoreSystemFeatureD3D12HardwareFL11 = 6,
    WASPStoreSystemFeatureD3D12HardwareFL12 = 7,
    WASPStoreSystemFeatureMemory300MB = 8,
    WASPStoreSystemFeatureMemory750MB = 9,
    WASPStoreSystemFeatureMemory1GB = 10,
    WASPStoreSystemFeatureMemory2GB = 11,
    WASPStoreSystemFeatureCameraFront = 12,
    WASPStoreSystemFeatureCameraRear = 13,
    WASPStoreSystemFeatureGyroscope = 14,
    WASPStoreSystemFeatureHover = 15,
    WASPStoreSystemFeatureMagnetometer = 16,
    WASPStoreSystemFeatureNfc = 17,
    WASPStoreSystemFeatureResolution720P = 18,
    WASPStoreSystemFeatureResolutionWvga = 19,
    WASPStoreSystemFeatureResolutionWvgaOr720P = 20,
    WASPStoreSystemFeatureResolutionWxga = 21,
    WASPStoreSystemFeatureResolutionWvgaOrWxga = 22,
    WASPStoreSystemFeatureResolutionWxgaOr720P = 23,
    WASPStoreSystemFeatureMemory4GB = 24,
    WASPStoreSystemFeatureMemory6GB = 25,
    WASPStoreSystemFeatureMemory8GB = 26,
    WASPStoreSystemFeatureMemory12GB = 27,
    WASPStoreSystemFeatureMemory16GB = 28,
    WASPStoreSystemFeatureMemory20GB = 29,
    WASPStoreSystemFeatureVideoMemory2GB = 30,
    WASPStoreSystemFeatureVideoMemory4GB = 31,
    WASPStoreSystemFeatureVideoMemory6GB = 32,
    WASPStoreSystemFeatureVideoMemory1GB = 33,
};
typedef unsigned WASPStoreSystemFeature;

// Windows.ApplicationModel.Store.Preview.StoreLogOptions
enum _WASPStoreLogOptions {
    WASPStoreLogOptionsNone = 0,
    WASPStoreLogOptionsTryElevate = 1,
};
typedef unsigned WASPStoreLogOptions;

#include "WindowsSecurityCredentials.h"
#include "WindowsStorageStreams.h"
#include "WindowsSecurityAuthenticationWebCore.h"
#include "WindowsFoundation.h"
#include "WindowsSystem.h"
#include "WindowsUIXaml.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Store.Preview.StorePreviewSkuInfo
#ifndef __WASPStorePreviewSkuInfo_DEFINED__
#define __WASPStorePreviewSkuInfo_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWEXPORT
@interface WASPStorePreviewSkuInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * currencyCode;
@property (readonly) NSString * customDeveloperData;
@property (readonly) NSString * Description;
@property (readonly) NSString * extendedData;
@property (readonly) NSString * formattedListPrice;
@property (readonly) NSString * productId;
@property (readonly) NSString * skuId;
@property (readonly) NSString * skuType;
@property (readonly) NSString * title;
@end

#endif // __WASPStorePreviewSkuInfo_DEFINED__

// Windows.ApplicationModel.Store.Preview.StorePreviewPurchaseResults
#ifndef __WASPStorePreviewPurchaseResults_DEFINED__
#define __WASPStorePreviewPurchaseResults_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWEXPORT
@interface WASPStorePreviewPurchaseResults : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WASPStorePreviewProductPurchaseStatus productPurchaseStatus;
@end

#endif // __WASPStorePreviewPurchaseResults_DEFINED__

// Windows.ApplicationModel.Store.Preview.StorePreviewProductInfo
#ifndef __WASPStorePreviewProductInfo_DEFINED__
#define __WASPStorePreviewProductInfo_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWEXPORT
@interface WASPStorePreviewProductInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * Description;
@property (readonly) NSString * productId;
@property (readonly) NSString * productType;
@property (readonly) NSArray* /* WASPStorePreviewSkuInfo* */ skuInfoList;
@property (readonly) NSString * title;
@end

#endif // __WASPStorePreviewProductInfo_DEFINED__

// Windows.ApplicationModel.Store.Preview.StoreHardwareManufacturerInfo
#ifndef __WASPStoreHardwareManufacturerInfo_DEFINED__
#define __WASPStoreHardwareManufacturerInfo_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWEXPORT
@interface WASPStoreHardwareManufacturerInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * hardwareManufacturerId;
@property (readonly) NSString * manufacturerName;
@property (readonly) NSString * modelName;
@property (readonly) NSString * storeContentModifierId;
@end

#endif // __WASPStoreHardwareManufacturerInfo_DEFINED__

// Windows.ApplicationModel.Store.Preview.StorePreview
#ifndef __WASPStorePreview_DEFINED__
#define __WASPStorePreview_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWEXPORT
@interface WASPStorePreview : RTObject
+ (void)requestProductPurchaseByProductIdAndSkuIdAsync:(NSString *)productId skuId:(NSString *)skuId success:(void (^)(WASPStorePreviewPurchaseResults*))success failure:(void (^)(NSError*))failure;
+ (void)loadAddOnProductInfosAsyncWithSuccess:(void (^)(NSArray* /* WASPStorePreviewProductInfo* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WASPStorePreview_DEFINED__

// Windows.ApplicationModel.Store.Preview.StoreConfiguration
#ifndef __WASPStoreConfiguration_DEFINED__
#define __WASPStoreConfiguration_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWEXPORT
@interface WASPStoreConfiguration : RTObject
+ (BOOL)hasStoreWebAccount;
+ (BOOL)hasStoreWebAccountForUser:(WSUser*)user;
+ (void)getStoreLogDataAsync:(WASPStoreLogOptions)options success:(void (^)(RTObject<WSSIRandomAccessStreamReference>*))success failure:(void (^)(NSError*))failure;
+ (void)setStoreWebAccountIdForUser:(WSUser*)user webAccountId:(NSString *)webAccountId;
+ (BOOL)isStoreWebAccountIdForUser:(WSUser*)user webAccountId:(NSString *)webAccountId;
+ (id /* unsigned int */)getPurchasePromptingPolicyForUser:(WSUser*)user;
+ (void)setPurchasePromptingPolicyForUser:(WSUser*)user value:(id /* unsigned int */)value;
+ (NSString *)getStoreWebAccountId;
+ (NSString *)getStoreWebAccountIdForUser:(WSUser*)user;
+ (void)setEnterpriseStoreWebAccountId:(NSString *)webAccountId;
+ (void)setEnterpriseStoreWebAccountIdForUser:(WSUser*)user webAccountId:(NSString *)webAccountId;
+ (NSString *)getEnterpriseStoreWebAccountId;
+ (NSString *)getEnterpriseStoreWebAccountIdForUser:(WSUser*)user;
+ (BOOL)shouldRestrictToEnterpriseStoreOnly;
+ (BOOL)shouldRestrictToEnterpriseStoreOnlyForUser:(WSUser*)user;
+ (void)setSystemConfiguration:(NSString *)catalogHardwareManufacturerId catalogStoreContentModifierId:(NSString *)catalogStoreContentModifierId systemConfigurationExpiration:(WFDateTime*)systemConfigurationExpiration catalogHardwareDescriptor:(NSString *)catalogHardwareDescriptor;
+ (void)setMobileOperatorConfiguration:(NSString *)mobileOperatorId appDownloadLimitInMegabytes:(unsigned int)appDownloadLimitInMegabytes updateDownloadLimitInMegabytes:(unsigned int)updateDownloadLimitInMegabytes;
+ (void)setStoreWebAccountId:(NSString *)webAccountId;
+ (BOOL)isStoreWebAccountId:(NSString *)webAccountId;
+ (void)filterUnsupportedSystemFeaturesAsync:(id<NSFastEnumeration> /* WASPStoreSystemFeature */)systemFeatures success:(void (^)(NSArray* /* WASPStoreSystemFeature */))success failure:(void (^)(NSError*))failure;
+ (WASPStoreHardwareManufacturerInfo*)hardwareManufacturerInfo;
+ (id /* unsigned int */)purchasePromptingPolicy;
+ (void)setPurchasePromptingPolicy:(id /* unsigned int */)value;
@end

#endif // __WASPStoreConfiguration_DEFINED__

// Windows.ApplicationModel.Store.Preview.WebAuthenticationCoreManagerHelper
#ifndef __WASPWebAuthenticationCoreManagerHelper_DEFINED__
#define __WASPWebAuthenticationCoreManagerHelper_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSTOREPREVIEWEXPORT
@interface WASPWebAuthenticationCoreManagerHelper : RTObject
+ (void)requestTokenWithUIElementHostingAsync:(WSAWCWebTokenRequest*)request uiElement:(WXUIElement*)uiElement success:(void (^)(WSAWCWebTokenRequestResult*))success failure:(void (^)(NSError*))failure;
+ (void)requestTokenWithUIElementHostingAndWebAccountAsync:(WSAWCWebTokenRequest*)request webAccount:(WSCWebAccount*)webAccount uiElement:(WXUIElement*)uiElement success:(void (^)(WSAWCWebTokenRequestResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WASPWebAuthenticationCoreManagerHelper_DEFINED__

