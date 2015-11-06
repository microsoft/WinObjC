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

// WindowsApplicationModelStorePreview.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WASPStorePreviewSkuInfo, WASPStorePreviewPurchaseResults, WASPStorePreviewProductInfo, WASPStoreHardwareManufacturerInfo,
    WASPStorePreview, WASPStoreConfiguration;
@protocol WASPIStorePreviewProductInfo
, WASPIStorePreviewSkuInfo, WASPIStorePreviewPurchaseResults, WASPIStorePreview, WASPIStoreHardwareManufacturerInfo,
    WASPIStoreConfigurationStatics;

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
};
typedef unsigned WASPStoreSystemFeature;

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Store.Preview.StorePreviewSkuInfo
#ifndef __WASPStorePreviewSkuInfo_DEFINED__
#define __WASPStorePreviewSkuInfo_DEFINED__

WINRT_EXPORT
@interface WASPStorePreviewSkuInfo : RTObject
@property (readonly) NSString* currencyCode;
@property (readonly) NSString* customDeveloperData;
@property (readonly) NSString* description;
@property (readonly) NSString* extendedData;
@property (readonly) NSString* formattedListPrice;
@property (readonly) NSString* productId;
@property (readonly) NSString* skuId;
@property (readonly) NSString* skuType;
@property (readonly) NSString* title;
@end

#endif // __WASPStorePreviewSkuInfo_DEFINED__

// Windows.ApplicationModel.Store.Preview.StorePreviewPurchaseResults
#ifndef __WASPStorePreviewPurchaseResults_DEFINED__
#define __WASPStorePreviewPurchaseResults_DEFINED__

WINRT_EXPORT
@interface WASPStorePreviewPurchaseResults : RTObject
@property (readonly) WASPStorePreviewProductPurchaseStatus productPurchaseStatus;
@end

#endif // __WASPStorePreviewPurchaseResults_DEFINED__

// Windows.ApplicationModel.Store.Preview.StorePreviewProductInfo
#ifndef __WASPStorePreviewProductInfo_DEFINED__
#define __WASPStorePreviewProductInfo_DEFINED__

WINRT_EXPORT
@interface WASPStorePreviewProductInfo : RTObject
@property (readonly) NSString* description;
@property (readonly) NSString* productId;
@property (readonly) NSString* productType;
@property (readonly) NSArray* skuInfoList;
@property (readonly) NSString* title;
@end

#endif // __WASPStorePreviewProductInfo_DEFINED__

// Windows.ApplicationModel.Store.Preview.StoreHardwareManufacturerInfo
#ifndef __WASPStoreHardwareManufacturerInfo_DEFINED__
#define __WASPStoreHardwareManufacturerInfo_DEFINED__

WINRT_EXPORT
@interface WASPStoreHardwareManufacturerInfo : RTObject
@property (readonly) NSString* hardwareManufacturerId;
@property (readonly) NSString* manufacturerName;
@property (readonly) NSString* modelName;
@property (readonly) NSString* storeContentModifierId;
@end

#endif // __WASPStoreHardwareManufacturerInfo_DEFINED__

// Windows.ApplicationModel.Store.Preview.StorePreview
#ifndef __WASPStorePreview_DEFINED__
#define __WASPStorePreview_DEFINED__

WINRT_EXPORT
@interface WASPStorePreview : RTObject
+ (void)requestProductPurchaseByProductIdAndSkuIdAsync:(NSString*)productId
                                                 skuId:(NSString*)skuId
                                               success:(void (^)(WASPStorePreviewPurchaseResults*))success
                                               failure:(void (^)(NSError*))failure;
+ (void)loadAddOnProductInfosAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WASPStorePreview_DEFINED__

// Windows.ApplicationModel.Store.Preview.StoreConfiguration
#ifndef __WASPStoreConfiguration_DEFINED__
#define __WASPStoreConfiguration_DEFINED__

WINRT_EXPORT
@interface WASPStoreConfiguration : RTObject
+ (void)setSystemConfiguration:(NSString*)catalogHardwareManufacturerId
 catalogStoreContentModifierId:(NSString*)catalogStoreContentModifierId
 systemConfigurationExpiration:(WFDateTime*)systemConfigurationExpiration
     catalogHardwareDescriptor:(NSString*)catalogHardwareDescriptor;
+ (void)setMobileOperatorConfiguration:(NSString*)mobileOperatorId
           appDownloadLimitInMegabytes:(unsigned int)appDownloadLimitInMegabytes
        updateDownloadLimitInMegabytes:(unsigned int)updateDownloadLimitInMegabytes;
+ (void)setStoreWebAccountId:(NSString*)webAccountId;
+ (BOOL)isStoreWebAccountId:(NSString*)webAccountId;
+ (void)filterUnsupportedSystemFeaturesAsync:(id<NSFastEnumeration> /* WASPStoreSystemFeature */)systemFeatures
                                     success:(void (^)(NSArray*))success
                                     failure:(void (^)(NSError*))failure;
+ (WASPStoreHardwareManufacturerInfo*)hardwareManufacturerInfo;
@end

#endif // __WASPStoreConfiguration_DEFINED__
