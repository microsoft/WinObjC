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

// WindowsServicesStore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSERVICESSTOREEXPORT
#define OBJCUWPWINDOWSSERVICESSTOREEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsServicesStore.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSSStoreProduct, WSSStoreProductPagedQueryResult, WSSStorePurchaseProperties, WSSStoreLicense, WSSStoreImage, WSSStoreVideo, WSSStoreSku, WSSStorePrice, WSSStorePurchaseResult, WSSStoreAvailability, WSSStoreCollectionData, WSSStoreSubscriptionInfo, WSSStoreContext, WSSStoreSendRequestResult, WSSStoreAppLicense, WSSStoreProductResult, WSSStoreProductQueryResult, WSSStoreConsumableResult, WSSStoreAcquireLicenseResult, WSSStorePackageUpdate, WSSStorePackageUpdateResult, WSSStorePackageLicense, WSSStoreRequestHelper;
@class WSSStorePackageUpdateStatus;
@protocol WSSIStoreProductPagedQueryResult, WSSIStoreProductQueryResult, WSSIStoreProductResult, WSSIStorePurchaseProperties, WSSIStorePurchasePropertiesFactory, WSSIStoreCollectionData, WSSIStoreLicense, WSSIStoreAppLicense, WSSIStoreSendRequestResult, WSSIStoreSendRequestResult2, WSSIStoreProduct, WSSIStoreImage, WSSIStoreVideo, WSSIStoreSku, WSSIStoreAvailability, WSSIStorePrice, WSSIStoreSubscriptionInfo, WSSIStoreConsumableResult, WSSIStorePurchaseResult, WSSIStoreContextStatics, WSSIStoreRequestHelperStatics, WSSIStoreContext, WSSIStoreContext2, WSSIStorePackageUpdate, WSSIStorePackageUpdateResult, WSSIStoreAcquireLicenseResult, WSSIStorePackageLicense;

// Windows.Services.Store.StorePurchaseStatus
enum _WSSStorePurchaseStatus {
    WSSStorePurchaseStatusSucceeded = 0,
    WSSStorePurchaseStatusAlreadyPurchased = 1,
    WSSStorePurchaseStatusNotPurchased = 2,
    WSSStorePurchaseStatusNetworkError = 3,
    WSSStorePurchaseStatusServerError = 4,
};
typedef unsigned WSSStorePurchaseStatus;

// Windows.Services.Store.StoreConsumableStatus
enum _WSSStoreConsumableStatus {
    WSSStoreConsumableStatusSucceeded = 0,
    WSSStoreConsumableStatusInsufficentQuantity = 1,
    WSSStoreConsumableStatusNetworkError = 2,
    WSSStoreConsumableStatusServerError = 3,
};
typedef unsigned WSSStoreConsumableStatus;

// Windows.Services.Store.StoreDurationUnit
enum _WSSStoreDurationUnit {
    WSSStoreDurationUnitMinute = 0,
    WSSStoreDurationUnitHour = 1,
    WSSStoreDurationUnitDay = 2,
    WSSStoreDurationUnitWeek = 3,
    WSSStoreDurationUnitMonth = 4,
    WSSStoreDurationUnitYear = 5,
};
typedef unsigned WSSStoreDurationUnit;

// Windows.Services.Store.StorePackageUpdateState
enum _WSSStorePackageUpdateState {
    WSSStorePackageUpdateStatePending = 0,
    WSSStorePackageUpdateStateDownloading = 1,
    WSSStorePackageUpdateStateDeploying = 2,
    WSSStorePackageUpdateStateCompleted = 3,
    WSSStorePackageUpdateStateCanceled = 4,
    WSSStorePackageUpdateStateOtherError = 5,
    WSSStorePackageUpdateStateErrorLowBattery = 6,
    WSSStorePackageUpdateStateErrorWiFiRecommended = 7,
    WSSStorePackageUpdateStateErrorWiFiRequired = 8,
};
typedef unsigned WSSStorePackageUpdateState;

#include "WindowsFoundation.h"
#include "WindowsWebHttp.h"
#include "WindowsApplicationModel.h"
#include "WindowsSystem.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Services.Store.StorePackageUpdateStatus
OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStorePackageUpdateStatus : NSObject
+ (instancetype)new;
@property (retain) NSString * packageFamilyName;
@property uint64_t packageDownloadSizeInBytes;
@property uint64_t packageBytesDownloaded;
@property double packageDownloadProgress;
@property double totalDownloadProgress;
@property WSSStorePackageUpdateState packageUpdateState;
@end

// Windows.Services.Store.StoreProduct
#ifndef __WSSStoreProduct_DEFINED__
#define __WSSStoreProduct_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreProduct : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * Description;
@property (readonly) NSString * extendedJsonData;
@property (readonly) BOOL hasDigitalDownload;
@property (readonly) NSArray* /* WSSStoreImage* */ images;
@property (readonly) NSString * inAppOfferToken;
@property (readonly) BOOL isInUserCollection;
@property (readonly) NSArray* /* NSString * */ keywords;
@property (readonly) NSString * language;
@property (readonly) WFUri* linkUri;
@property (readonly) WSSStorePrice* price;
@property (readonly) NSString * productKind;
@property (readonly) NSArray* /* WSSStoreSku* */ skus;
@property (readonly) NSString * storeId;
@property (readonly) NSString * title;
@property (readonly) NSArray* /* WSSStoreVideo* */ videos;
- (void)getIsAnySkuInstalledAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestPurchaseAsyncWithSuccess:(void (^)(WSSStorePurchaseResult*))success failure:(void (^)(NSError*))failure;
- (void)requestPurchaseWithPurchasePropertiesAsync:(WSSStorePurchaseProperties*)storePurchaseProperties success:(void (^)(WSSStorePurchaseResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSStoreProduct_DEFINED__

// Windows.Services.Store.StoreProductPagedQueryResult
#ifndef __WSSStoreProductPagedQueryResult_DEFINED__
#define __WSSStoreProductPagedQueryResult_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreProductPagedQueryResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) BOOL hasMoreResults;
@property (readonly) NSDictionary* /* NSString *, WSSStoreProduct* */ products;
- (void)getNextAsyncWithSuccess:(void (^)(WSSStoreProductPagedQueryResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSStoreProductPagedQueryResult_DEFINED__

// Windows.Services.Store.StorePurchaseProperties
#ifndef __WSSStorePurchaseProperties_DEFINED__
#define __WSSStorePurchaseProperties_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStorePurchaseProperties : RTObject
+ (WSSStorePurchaseProperties*)make:(NSString *)name ACTIVATOR;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * name;
@property (retain) NSString * extendedJsonData;
@end

#endif // __WSSStorePurchaseProperties_DEFINED__

// Windows.Services.Store.StoreLicense
#ifndef __WSSStoreLicense_DEFINED__
#define __WSSStoreLicense_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreLicense : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFDateTime* expirationDate;
@property (readonly) NSString * extendedJsonData;
@property (readonly) NSString * inAppOfferToken;
@property (readonly) BOOL isActive;
@property (readonly) NSString * skuStoreId;
@end

#endif // __WSSStoreLicense_DEFINED__

// Windows.Services.Store.StoreImage
#ifndef __WSSStoreImage_DEFINED__
#define __WSSStoreImage_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreImage : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * caption;
@property (readonly) unsigned int height;
@property (readonly) NSString * imagePurposeTag;
@property (readonly) WFUri* uri;
@property (readonly) unsigned int width;
@end

#endif // __WSSStoreImage_DEFINED__

// Windows.Services.Store.StoreVideo
#ifndef __WSSStoreVideo_DEFINED__
#define __WSSStoreVideo_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreVideo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * caption;
@property (readonly) unsigned int height;
@property (readonly) WSSStoreImage* previewImage;
@property (readonly) WFUri* uri;
@property (readonly) NSString * videoPurposeTag;
@property (readonly) unsigned int width;
@end

#endif // __WSSStoreVideo_DEFINED__

// Windows.Services.Store.StoreSku
#ifndef __WSSStoreSku_DEFINED__
#define __WSSStoreSku_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreSku : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSSStoreAvailability* */ availabilities;
@property (readonly) NSArray* /* NSString * */ bundledSkus;
@property (readonly) WSSStoreCollectionData* collectionData;
@property (readonly) NSString * customDeveloperData;
@property (readonly) NSString * Description;
@property (readonly) NSString * extendedJsonData;
@property (readonly) NSArray* /* WSSStoreImage* */ images;
@property (readonly) BOOL isInUserCollection;
@property (readonly) BOOL isSubscription;
@property (readonly) BOOL isTrial;
@property (readonly) NSString * language;
@property (readonly) WSSStorePrice* price;
@property (readonly) NSString * storeId;
@property (readonly) WSSStoreSubscriptionInfo* subscriptionInfo;
@property (readonly) NSString * title;
@property (readonly) NSArray* /* WSSStoreVideo* */ videos;
- (void)getIsInstalledAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestPurchaseAsyncWithSuccess:(void (^)(WSSStorePurchaseResult*))success failure:(void (^)(NSError*))failure;
- (void)requestPurchaseWithPurchasePropertiesAsync:(WSSStorePurchaseProperties*)storePurchaseProperties success:(void (^)(WSSStorePurchaseResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSStoreSku_DEFINED__

// Windows.Services.Store.StorePrice
#ifndef __WSSStorePrice_DEFINED__
#define __WSSStorePrice_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStorePrice : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * currencyCode;
@property (readonly) NSString * formattedBasePrice;
@property (readonly) NSString * formattedPrice;
@property (readonly) NSString * formattedRecurrencePrice;
@property (readonly) BOOL isOnSale;
@property (readonly) WFDateTime* saleEndDate;
@end

#endif // __WSSStorePrice_DEFINED__

// Windows.Services.Store.StorePurchaseResult
#ifndef __WSSStorePurchaseResult_DEFINED__
#define __WSSStorePurchaseResult_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStorePurchaseResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) WSSStorePurchaseStatus status;
@end

#endif // __WSSStorePurchaseResult_DEFINED__

// Windows.Services.Store.StoreAvailability
#ifndef __WSSStoreAvailability_DEFINED__
#define __WSSStoreAvailability_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreAvailability : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFDateTime* endDate;
@property (readonly) NSString * extendedJsonData;
@property (readonly) WSSStorePrice* price;
@property (readonly) NSString * storeId;
- (void)requestPurchaseAsyncWithSuccess:(void (^)(WSSStorePurchaseResult*))success failure:(void (^)(NSError*))failure;
- (void)requestPurchaseWithPurchasePropertiesAsync:(WSSStorePurchaseProperties*)storePurchaseProperties success:(void (^)(WSSStorePurchaseResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSStoreAvailability_DEFINED__

// Windows.Services.Store.StoreCollectionData
#ifndef __WSSStoreCollectionData_DEFINED__
#define __WSSStoreCollectionData_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreCollectionData : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFDateTime* acquiredDate;
@property (readonly) NSString * campaignId;
@property (readonly) NSString * developerOfferId;
@property (readonly) WFDateTime* endDate;
@property (readonly) NSString * extendedJsonData;
@property (readonly) BOOL isTrial;
@property (readonly) WFDateTime* startDate;
@property (readonly) WFTimeSpan* trialTimeRemaining;
@end

#endif // __WSSStoreCollectionData_DEFINED__

// Windows.Services.Store.StoreSubscriptionInfo
#ifndef __WSSStoreSubscriptionInfo_DEFINED__
#define __WSSStoreSubscriptionInfo_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreSubscriptionInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int billingPeriod;
@property (readonly) WSSStoreDurationUnit billingPeriodUnit;
@property (readonly) BOOL hasTrialPeriod;
@property (readonly) unsigned int trialPeriod;
@property (readonly) WSSStoreDurationUnit trialPeriodUnit;
@end

#endif // __WSSStoreSubscriptionInfo_DEFINED__

// Windows.Services.Store.StoreContext
#ifndef __WSSStoreContext_DEFINED__
#define __WSSStoreContext_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreContext : RTObject
+ (WSSStoreContext*)getDefault;
+ (WSSStoreContext*)getForUser:(WSUser*)user;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSUser* user;
- (EventRegistrationToken)addOfflineLicensesChangedEvent:(void(^)(WSSStoreContext*, RTObject*))del;
- (void)removeOfflineLicensesChangedEvent:(EventRegistrationToken)tok;
- (void)getCustomerPurchaseIdAsync:(NSString *)serviceTicket publisherUserId:(NSString *)publisherUserId success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)getCustomerCollectionsIdAsync:(NSString *)serviceTicket publisherUserId:(NSString *)publisherUserId success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)getAppLicenseAsyncWithSuccess:(void (^)(WSSStoreAppLicense*))success failure:(void (^)(NSError*))failure;
- (void)getStoreProductForCurrentAppAsyncWithSuccess:(void (^)(WSSStoreProductResult*))success failure:(void (^)(NSError*))failure;
- (void)getStoreProductsAsync:(id<NSFastEnumeration> /* NSString * */)productKinds storeIds:(id<NSFastEnumeration> /* NSString * */)storeIds success:(void (^)(WSSStoreProductQueryResult*))success failure:(void (^)(NSError*))failure;
- (void)getAssociatedStoreProductsAsync:(id<NSFastEnumeration> /* NSString * */)productKinds success:(void (^)(WSSStoreProductQueryResult*))success failure:(void (^)(NSError*))failure;
- (void)getAssociatedStoreProductsWithPagingAsync:(id<NSFastEnumeration> /* NSString * */)productKinds maxItemsToRetrievePerPage:(unsigned int)maxItemsToRetrievePerPage success:(void (^)(WSSStoreProductPagedQueryResult*))success failure:(void (^)(NSError*))failure;
- (void)getUserCollectionAsync:(id<NSFastEnumeration> /* NSString * */)productKinds success:(void (^)(WSSStoreProductQueryResult*))success failure:(void (^)(NSError*))failure;
- (void)getUserCollectionWithPagingAsync:(id<NSFastEnumeration> /* NSString * */)productKinds maxItemsToRetrievePerPage:(unsigned int)maxItemsToRetrievePerPage success:(void (^)(WSSStoreProductPagedQueryResult*))success failure:(void (^)(NSError*))failure;
- (void)reportConsumableFulfillmentAsync:(NSString *)productStoreId quantity:(unsigned int)quantity trackingId:(WFGUID*)trackingId success:(void (^)(WSSStoreConsumableResult*))success failure:(void (^)(NSError*))failure;
- (void)getConsumableBalanceRemainingAsync:(NSString *)productStoreId success:(void (^)(WSSStoreConsumableResult*))success failure:(void (^)(NSError*))failure;
- (void)acquireStoreLicenseForOptionalPackageAsync:(WAPackage*)optionalPackage success:(void (^)(WSSStoreAcquireLicenseResult*))success failure:(void (^)(NSError*))failure;
- (void)requestPurchaseAsync:(NSString *)storeId success:(void (^)(WSSStorePurchaseResult*))success failure:(void (^)(NSError*))failure;
- (void)requestPurchaseWithPurchasePropertiesAsync:(NSString *)storeId storePurchaseProperties:(WSSStorePurchaseProperties*)storePurchaseProperties success:(void (^)(WSSStorePurchaseResult*))success failure:(void (^)(NSError*))failure;
- (void)getAppAndOptionalStorePackageUpdatesAsyncWithSuccess:(void (^)(NSArray* /* WSSStorePackageUpdate* */))success failure:(void (^)(NSError*))failure;
- (void)requestDownloadStorePackageUpdatesAsync:(id<NSFastEnumeration> /* WSSStorePackageUpdate* */)storePackageUpdates success:(void (^)(WSSStorePackageUpdateResult*))success progress:(void (^)(WSSStorePackageUpdateStatus*))progress failure:(void (^)(NSError*))failure;
- (void)requestDownloadAndInstallStorePackageUpdatesAsync:(id<NSFastEnumeration> /* WSSStorePackageUpdate* */)storePackageUpdates success:(void (^)(WSSStorePackageUpdateResult*))success progress:(void (^)(WSSStorePackageUpdateStatus*))progress failure:(void (^)(NSError*))failure;
- (void)requestDownloadAndInstallStorePackagesAsync:(id<NSFastEnumeration> /* NSString * */)storeIds success:(void (^)(WSSStorePackageUpdateResult*))success progress:(void (^)(WSSStorePackageUpdateStatus*))progress failure:(void (^)(NSError*))failure;
- (void)findStoreProductForPackageAsync:(id<NSFastEnumeration> /* NSString * */)productKinds package:(WAPackage*)package success:(void (^)(WSSStoreProductResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSStoreContext_DEFINED__

// Windows.Services.Store.StoreSendRequestResult
#ifndef __WSSStoreSendRequestResult_DEFINED__
#define __WSSStoreSendRequestResult_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreSendRequestResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) NSString * response;
@property (readonly) WWHHttpStatusCode httpStatusCode;
@end

#endif // __WSSStoreSendRequestResult_DEFINED__

// Windows.Services.Store.StoreAppLicense
#ifndef __WSSStoreAppLicense_DEFINED__
#define __WSSStoreAppLicense_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreAppLicense : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSDictionary* /* NSString *, WSSStoreLicense* */ addOnLicenses;
@property (readonly) WFDateTime* expirationDate;
@property (readonly) NSString * extendedJsonData;
@property (readonly) BOOL isActive;
@property (readonly) BOOL isTrial;
@property (readonly) BOOL isTrialOwnedByThisUser;
@property (readonly) NSString * skuStoreId;
@property (readonly) WFTimeSpan* trialTimeRemaining;
@property (readonly) NSString * trialUniqueId;
@end

#endif // __WSSStoreAppLicense_DEFINED__

// Windows.Services.Store.StoreProductResult
#ifndef __WSSStoreProductResult_DEFINED__
#define __WSSStoreProductResult_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreProductResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) WSSStoreProduct* product;
@end

#endif // __WSSStoreProductResult_DEFINED__

// Windows.Services.Store.StoreProductQueryResult
#ifndef __WSSStoreProductQueryResult_DEFINED__
#define __WSSStoreProductQueryResult_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreProductQueryResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) NSDictionary* /* NSString *, WSSStoreProduct* */ products;
@end

#endif // __WSSStoreProductQueryResult_DEFINED__

// Windows.Services.Store.StoreConsumableResult
#ifndef __WSSStoreConsumableResult_DEFINED__
#define __WSSStoreConsumableResult_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreConsumableResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int balanceRemaining;
@property (readonly) HRESULT extendedError;
@property (readonly) WSSStoreConsumableStatus status;
@property (readonly) WFGUID* trackingId;
@end

#endif // __WSSStoreConsumableResult_DEFINED__

// Windows.Services.Store.StoreAcquireLicenseResult
#ifndef __WSSStoreAcquireLicenseResult_DEFINED__
#define __WSSStoreAcquireLicenseResult_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreAcquireLicenseResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) WSSStorePackageLicense* storePackageLicense;
@end

#endif // __WSSStoreAcquireLicenseResult_DEFINED__

// Windows.Services.Store.StorePackageUpdate
#ifndef __WSSStorePackageUpdate_DEFINED__
#define __WSSStorePackageUpdate_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStorePackageUpdate : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL mandatory;
@property (readonly) WAPackage* package;
@end

#endif // __WSSStorePackageUpdate_DEFINED__

// Windows.Services.Store.StorePackageUpdateResult
#ifndef __WSSStorePackageUpdateResult_DEFINED__
#define __WSSStorePackageUpdateResult_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStorePackageUpdateResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSSStorePackageUpdateState overallState;
@property (readonly) NSArray* /* WSSStorePackageUpdateStatus* */ storePackageUpdateStatuses;
@end

#endif // __WSSStorePackageUpdateResult_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Services.Store.StorePackageLicense
#ifndef __WSSStorePackageLicense_DEFINED__
#define __WSSStorePackageLicense_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStorePackageLicense : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isValid;
@property (readonly) WAPackage* package;
- (EventRegistrationToken)addLicenseLostEvent:(void(^)(WSSStorePackageLicense*, RTObject*))del;
- (void)removeLicenseLostEvent:(EventRegistrationToken)tok;
- (void)releaseLicense;
- (void)close;
@end

#endif // __WSSStorePackageLicense_DEFINED__

// Windows.Services.Store.StoreRequestHelper
#ifndef __WSSStoreRequestHelper_DEFINED__
#define __WSSStoreRequestHelper_DEFINED__

OBJCUWPWINDOWSSERVICESSTOREEXPORT
@interface WSSStoreRequestHelper : RTObject
+ (void)sendRequestAsync:(WSSStoreContext*)context requestKind:(unsigned int)requestKind parametersAsJson:(NSString *)parametersAsJson success:(void (^)(WSSStoreSendRequestResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSStoreRequestHelper_DEFINED__

