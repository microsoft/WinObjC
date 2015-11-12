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

// WindowsApplicationModelStore.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSLicenseInformation, WSListingInformation, WSPurchaseResults, WSProductPurchaseDisplayProperties, WSUnfulfilledConsumable,
    WSProductLicense, WSProductListing, WSCurrentApp, WSCurrentAppSimulator;
@protocol WSICurrentApp
, WSICurrentAppWithConsumables, WSICurrentAppSimulator, WSICurrentAppSimulatorWithConsumables, WSIPurchaseResults, WSILicenseInformation,
    WSIProductLicense, WSIListingInformation, WSIProductListing, WSIProductListingWithConsumables, WSIUnfulfilledConsumable,
    WSIProductPurchaseDisplayProperties, WSIProductPurchaseDisplayPropertiesFactory;

// Windows.ApplicationModel.Store.ProductPurchaseStatus
enum _WSProductPurchaseStatus {
    WSProductPurchaseStatusSucceeded = 0,
    WSProductPurchaseStatusAlreadyPurchased = 1,
    WSProductPurchaseStatusNotFulfilled = 2,
    WSProductPurchaseStatusNotPurchased = 3,
};
typedef unsigned WSProductPurchaseStatus;

// Windows.ApplicationModel.Store.ProductType
enum _WSProductType {
    WSProductTypeUnknown = 0,
    WSProductTypeDurable = 1,
    WSProductTypeConsumable = 2,
};
typedef unsigned WSProductType;

// Windows.ApplicationModel.Store.FulfillmentResult
enum _WSFulfillmentResult {
    WSFulfillmentResultSucceeded = 0,
    WSFulfillmentResultNothingToFulfill = 1,
    WSFulfillmentResultPurchasePending = 2,
    WSFulfillmentResultPurchaseReverted = 3,
    WSFulfillmentResultServerError = 4,
};
typedef unsigned WSFulfillmentResult;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorage.h"
// Windows.ApplicationModel.Store.LicenseChangedEventHandler
#ifndef __WSLicenseChangedEventHandler__DEFINED
#define __WSLicenseChangedEventHandler__DEFINED
typedef void (^WSLicenseChangedEventHandler)();
#endif // __WSLicenseChangedEventHandler__DEFINED

// Windows.ApplicationModel.Store.LicenseChangedEventHandler
#ifndef __WSLicenseChangedEventHandler__DEFINED
#define __WSLicenseChangedEventHandler__DEFINED
typedef void (^WSLicenseChangedEventHandler)();
#endif // __WSLicenseChangedEventHandler__DEFINED

// Windows.ApplicationModel.Store.LicenseInformation
#ifndef __WSLicenseInformation_DEFINED__
#define __WSLicenseInformation_DEFINED__

WINRT_EXPORT
@interface WSLicenseInformation : RTObject
@property (readonly) WFDateTime* expirationDate;
@property (readonly) BOOL isActive;
@property (readonly) BOOL isTrial;
@property (readonly) NSDictionary* /*String, WSProductLicense*/ productLicenses;
- (EventRegistrationToken)addLicenseChangedEvent:(WSLicenseChangedEventHandler)del;
- (void)removeLicenseChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WSLicenseInformation_DEFINED__

// Windows.ApplicationModel.Store.ListingInformation
#ifndef __WSListingInformation_DEFINED__
#define __WSListingInformation_DEFINED__

WINRT_EXPORT
@interface WSListingInformation : RTObject
@property (readonly) unsigned ageRating;
@property (readonly) NSString* currentMarket;
@property (readonly) NSString* description;
@property (readonly) NSString* formattedPrice;
@property (readonly) NSString* name;
@property (readonly) NSDictionary* /*String, WSProductListing*/ productListings;
@end

#endif // __WSListingInformation_DEFINED__

// Windows.ApplicationModel.Store.PurchaseResults
#ifndef __WSPurchaseResults_DEFINED__
#define __WSPurchaseResults_DEFINED__

WINRT_EXPORT
@interface WSPurchaseResults : RTObject
@property (readonly) NSString* offerId;
@property (readonly) NSString* receiptXml;
@property (readonly) WSProductPurchaseStatus status;
@property (readonly) WFGUID* transactionId;
@end

#endif // __WSPurchaseResults_DEFINED__

// Windows.ApplicationModel.Store.ProductPurchaseDisplayProperties
#ifndef __WSProductPurchaseDisplayProperties_DEFINED__
#define __WSProductPurchaseDisplayProperties_DEFINED__

WINRT_EXPORT
@interface WSProductPurchaseDisplayProperties : RTObject
+ (WSProductPurchaseDisplayProperties*)createProductPurchaseDisplayProperties:(NSString*)name ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* name;
@property (copy) WFUri* image;
@property (copy) NSString* description;
@end

#endif // __WSProductPurchaseDisplayProperties_DEFINED__

// Windows.ApplicationModel.Store.UnfulfilledConsumable
#ifndef __WSUnfulfilledConsumable_DEFINED__
#define __WSUnfulfilledConsumable_DEFINED__

WINRT_EXPORT
@interface WSUnfulfilledConsumable : RTObject
@property (readonly) NSString* offerId;
@property (readonly) NSString* productId;
@property (readonly) WFGUID* transactionId;
@end

#endif // __WSUnfulfilledConsumable_DEFINED__

// Windows.ApplicationModel.Store.ProductLicense
#ifndef __WSProductLicense_DEFINED__
#define __WSProductLicense_DEFINED__

WINRT_EXPORT
@interface WSProductLicense : RTObject
@property (readonly) WFDateTime* expirationDate;
@property (readonly) BOOL isActive;
@property (readonly) NSString* productId;
@end

#endif // __WSProductLicense_DEFINED__

// Windows.ApplicationModel.Store.ProductListing
#ifndef __WSProductListing_DEFINED__
#define __WSProductListing_DEFINED__

WINRT_EXPORT
@interface WSProductListing : RTObject
@property (readonly) NSString* formattedPrice;
@property (readonly) NSString* name;
@property (readonly) NSString* productId;
@property (readonly) WSProductType productType;
@end

#endif // __WSProductListing_DEFINED__

// Windows.ApplicationModel.Store.CurrentApp
#ifndef __WSCurrentApp_DEFINED__
#define __WSCurrentApp_DEFINED__

WINRT_EXPORT
@interface WSCurrentApp : RTObject
+ (void)reportConsumableFulfillmentAsync:(NSString*)productId
                           transactionId:(WFGUID*)transactionId
                                 success:(void (^)(WSFulfillmentResult))success
                                 failure:(void (^)(NSError*))failure;
+ (void)requestProductPurchaseWithResultsAsync:(NSString*)productId
                                       success:(void (^)(WSPurchaseResults*))success
                                       failure:(void (^)(NSError*))failure;
+ (void)requestProductPurchaseWithDisplayPropertiesAsync:(NSString*)productId
                                                 offerId:(NSString*)offerId
                                       displayProperties:(WSProductPurchaseDisplayProperties*)displayProperties
                                                 success:(void (^)(WSPurchaseResults*))success
                                                 failure:(void (^)(NSError*))failure;
+ (void)getUnfulfilledConsumablesAsyncWithSuccess:(void (^)(id<NSFastEnumeration> /*WSUnfulfilledConsumable*/))success
                                          failure:(void (^)(NSError*))failure;
+ (void)requestAppPurchaseAsync:(BOOL)includeReceipt success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (void)requestProductPurchaseAsync:(NSString*)productId
                     includeReceipt:(BOOL)includeReceipt
                            success:(void (^)(NSString*))success
                            failure:(void (^)(NSError*))failure;
+ (void)loadListingInformationAsyncWithSuccess:(void (^)(WSListingInformation*))success failure:(void (^)(NSError*))failure;
+ (void)getAppReceiptAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (void)getProductReceiptAsync:(NSString*)productId success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (WFGUID*)appId;
+ (WSLicenseInformation*)licenseInformation;
+ (WFUri*)linkUri;
@end

#endif // __WSCurrentApp_DEFINED__

// Windows.ApplicationModel.Store.CurrentAppSimulator
#ifndef __WSCurrentAppSimulator_DEFINED__
#define __WSCurrentAppSimulator_DEFINED__

WINRT_EXPORT
@interface WSCurrentAppSimulator : RTObject
+ (void)reportConsumableFulfillmentAsync:(NSString*)productId
                           transactionId:(WFGUID*)transactionId
                                 success:(void (^)(WSFulfillmentResult))success
                                 failure:(void (^)(NSError*))failure;
+ (void)requestProductPurchaseWithResultsAsync:(NSString*)productId
                                       success:(void (^)(WSPurchaseResults*))success
                                       failure:(void (^)(NSError*))failure;
+ (void)requestProductPurchaseWithDisplayPropertiesAsync:(NSString*)productId
                                                 offerId:(NSString*)offerId
                                       displayProperties:(WSProductPurchaseDisplayProperties*)displayProperties
                                                 success:(void (^)(WSPurchaseResults*))success
                                                 failure:(void (^)(NSError*))failure;
+ (void)getUnfulfilledConsumablesAsyncWithSuccess:(void (^)(id<NSFastEnumeration> /*WSUnfulfilledConsumable*/))success
                                          failure:(void (^)(NSError*))failure;
+ (void)requestAppPurchaseAsync:(BOOL)includeReceipt success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (void)requestProductPurchaseAsync:(NSString*)productId
                     includeReceipt:(BOOL)includeReceipt
                            success:(void (^)(NSString*))success
                            failure:(void (^)(NSError*))failure;
+ (void)loadListingInformationAsyncWithSuccess:(void (^)(WSListingInformation*))success failure:(void (^)(NSError*))failure;
+ (void)getAppReceiptAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (void)getProductReceiptAsync:(NSString*)productId success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)reloadSimulatorAsync:(WSStorageFile*)simulatorSettingsFile;
+ (WFGUID*)appId;
+ (WSLicenseInformation*)licenseInformation;
+ (WFUri*)linkUri;
@end

#endif // __WSCurrentAppSimulator_DEFINED__
