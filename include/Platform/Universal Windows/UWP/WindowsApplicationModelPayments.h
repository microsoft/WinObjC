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

// WindowsApplicationModelPayments.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelPayments.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAPPaymentMerchantInfo, WAPPaymentDetails, WAPPaymentMethodData, WAPPaymentOptions, WAPPaymentRequest, WAPPaymentToken, WAPPaymentShippingOption, WAPPaymentAddress, WAPPaymentItem, WAPPaymentDetailsModifier, WAPPaymentCurrencyAmount, WAPPaymentRequestChangedResult, WAPPaymentRequestChangedArgs, WAPPaymentRequestSubmitResult, WAPPaymentCanMakePaymentResult, WAPPaymentResponse, WAPPaymentMediator;
@protocol WAPIPaymentRequest, WAPIPaymentRequest2, WAPIPaymentRequestFactory, WAPIPaymentRequestFactory2, WAPIPaymentResponse, WAPIPaymentDetails, WAPIPaymentDetailsFactory, WAPIPaymentDetailsModifier, WAPIPaymentDetailsModifierFactory, WAPIPaymentToken, WAPIPaymentTokenFactory, WAPIPaymentMethodData, WAPIPaymentMethodDataFactory, WAPIPaymentCurrencyAmount, WAPIPaymentCurrencyAmountFactory, WAPIPaymentItem, WAPIPaymentItemFactory, WAPIPaymentShippingOption, WAPIPaymentShippingOptionFactory, WAPIPaymentAddress, WAPIPaymentMerchantInfo, WAPIPaymentMerchantInfoFactory, WAPIPaymentOptions, WAPIPaymentRequestChangedArgs, WAPIPaymentRequestChangedResult, WAPIPaymentRequestChangedResultFactory, WAPIPaymentMediator, WAPIPaymentMediator2, WAPIPaymentRequestSubmitResult, WAPIPaymentCanMakePaymentResult, WAPIPaymentCanMakePaymentResultFactory;

// Windows.ApplicationModel.Payments.PaymentRequestStatus
enum _WAPPaymentRequestStatus {
    WAPPaymentRequestStatusSucceeded = 0,
    WAPPaymentRequestStatusFailed = 1,
    WAPPaymentRequestStatusCanceled = 2,
};
typedef unsigned WAPPaymentRequestStatus;

// Windows.ApplicationModel.Payments.PaymentRequestCompletionStatus
enum _WAPPaymentRequestCompletionStatus {
    WAPPaymentRequestCompletionStatusSucceeded = 0,
    WAPPaymentRequestCompletionStatusFailed = 1,
    WAPPaymentRequestCompletionStatusUnknown = 2,
};
typedef unsigned WAPPaymentRequestCompletionStatus;

// Windows.ApplicationModel.Payments.PaymentRequestChangeKind
enum _WAPPaymentRequestChangeKind {
    WAPPaymentRequestChangeKindShippingOption = 0,
    WAPPaymentRequestChangeKindShippingAddress = 1,
};
typedef unsigned WAPPaymentRequestChangeKind;

// Windows.ApplicationModel.Payments.PaymentOptionPresence
enum _WAPPaymentOptionPresence {
    WAPPaymentOptionPresenceNone = 0,
    WAPPaymentOptionPresenceOptional = 1,
    WAPPaymentOptionPresenceRequired = 2,
};
typedef unsigned WAPPaymentOptionPresence;

// Windows.ApplicationModel.Payments.PaymentShippingType
enum _WAPPaymentShippingType {
    WAPPaymentShippingTypeShipping = 0,
    WAPPaymentShippingTypeDelivery = 1,
    WAPPaymentShippingTypePickup = 2,
};
typedef unsigned WAPPaymentShippingType;

// Windows.ApplicationModel.Payments.PaymentCanMakePaymentResultStatus
enum _WAPPaymentCanMakePaymentResultStatus {
    WAPPaymentCanMakePaymentResultStatusUnknown = 0,
    WAPPaymentCanMakePaymentResultStatusYes = 1,
    WAPPaymentCanMakePaymentResultStatusNo = 2,
    WAPPaymentCanMakePaymentResultStatusNotAllowed = 3,
    WAPPaymentCanMakePaymentResultStatusUserNotSignedIn = 4,
    WAPPaymentCanMakePaymentResultStatusSpecifiedPaymentMethodIdsNotSupported = 5,
    WAPPaymentCanMakePaymentResultStatusNoQualifyingCardOnFile = 6,
};
typedef unsigned WAPPaymentCanMakePaymentResultStatus;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
// Windows.ApplicationModel.Payments.PaymentRequestChangedHandler
#ifndef __WAPPaymentRequestChangedHandler__DEFINED
#define __WAPPaymentRequestChangedHandler__DEFINED
typedef void(^WAPPaymentRequestChangedHandler)(WAPPaymentRequest* paymentRequest, WAPPaymentRequestChangedArgs* args);
#endif // __WAPPaymentRequestChangedHandler__DEFINED


#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Payments.PaymentRequestChangedHandler
#ifndef __WAPPaymentRequestChangedHandler__DEFINED
#define __WAPPaymentRequestChangedHandler__DEFINED
typedef void(^WAPPaymentRequestChangedHandler)(WAPPaymentRequest* paymentRequest, WAPPaymentRequestChangedArgs* args);
#endif // __WAPPaymentRequestChangedHandler__DEFINED

// Windows.ApplicationModel.Payments.PaymentMerchantInfo
#ifndef __WAPPaymentMerchantInfo_DEFINED__
#define __WAPPaymentMerchantInfo_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentMerchantInfo : RTObject
+ (WAPPaymentMerchantInfo*)make:(WFUri*)uri ACTIVATOR;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * packageFullName;
@property (readonly) WFUri* uri;
@end

#endif // __WAPPaymentMerchantInfo_DEFINED__

// Windows.ApplicationModel.Payments.PaymentDetails
#ifndef __WAPPaymentDetails_DEFINED__
#define __WAPPaymentDetails_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentDetails : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
+ (WAPPaymentDetails*)make:(WAPPaymentItem*)total ACTIVATOR;
+ (WAPPaymentDetails*)makeWithDisplayItems:(WAPPaymentItem*)total displayItems:(id<NSFastEnumeration> /* WAPPaymentItem* */)displayItems ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WAPPaymentItem* total;
@property (retain) NSArray* /* WAPPaymentShippingOption* */ shippingOptions;
@property (retain) NSArray* /* WAPPaymentDetailsModifier* */ modifiers;
@property (retain) NSArray* /* WAPPaymentItem* */ displayItems;
@end

#endif // __WAPPaymentDetails_DEFINED__

// Windows.ApplicationModel.Payments.PaymentMethodData
#ifndef __WAPPaymentMethodData_DEFINED__
#define __WAPPaymentMethodData_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentMethodData : RTObject
+ (WAPPaymentMethodData*)make:(id<NSFastEnumeration> /* NSString * */)supportedMethodIds ACTIVATOR;
+ (WAPPaymentMethodData*)makeWithJsonData:(id<NSFastEnumeration> /* NSString * */)supportedMethodIds jsonData:(NSString *)jsonData ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * jsonData;
@property (readonly) NSArray* /* NSString * */ supportedMethodIds;
@end

#endif // __WAPPaymentMethodData_DEFINED__

// Windows.ApplicationModel.Payments.PaymentOptions
#ifndef __WAPPaymentOptions_DEFINED__
#define __WAPPaymentOptions_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WAPPaymentShippingType shippingType;
@property BOOL requestShipping;
@property WAPPaymentOptionPresence requestPayerPhoneNumber;
@property WAPPaymentOptionPresence requestPayerName;
@property WAPPaymentOptionPresence requestPayerEmail;
@end

#endif // __WAPPaymentOptions_DEFINED__

// Windows.ApplicationModel.Payments.PaymentRequest
#ifndef __WAPPaymentRequest_DEFINED__
#define __WAPPaymentRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentRequest : RTObject
+ (WAPPaymentRequest*)make:(WAPPaymentDetails*)details methodData:(id<NSFastEnumeration> /* WAPPaymentMethodData* */)methodData ACTIVATOR;
+ (WAPPaymentRequest*)makeWithMerchantInfo:(WAPPaymentDetails*)details methodData:(id<NSFastEnumeration> /* WAPPaymentMethodData* */)methodData merchantInfo:(WAPPaymentMerchantInfo*)merchantInfo ACTIVATOR;
+ (WAPPaymentRequest*)makeWithMerchantInfoAndOptions:(WAPPaymentDetails*)details methodData:(id<NSFastEnumeration> /* WAPPaymentMethodData* */)methodData merchantInfo:(WAPPaymentMerchantInfo*)merchantInfo options:(WAPPaymentOptions*)options ACTIVATOR;
+ (WAPPaymentRequest*)makeWithMerchantInfoOptionsAndId:(WAPPaymentDetails*)details methodData:(id<NSFastEnumeration> /* WAPPaymentMethodData* */)methodData merchantInfo:(WAPPaymentMerchantInfo*)merchantInfo options:(WAPPaymentOptions*)options id:(NSString *)id ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAPPaymentDetails* details;
@property (readonly) WAPPaymentMerchantInfo* merchantInfo;
@property (readonly) NSArray* /* WAPPaymentMethodData* */ methodData;
@property (readonly) WAPPaymentOptions* options;
@property (readonly) NSString * id;
@end

#endif // __WAPPaymentRequest_DEFINED__

// Windows.ApplicationModel.Payments.PaymentToken
#ifndef __WAPPaymentToken_DEFINED__
#define __WAPPaymentToken_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentToken : RTObject
+ (WAPPaymentToken*)make:(NSString *)paymentMethodId ACTIVATOR;
+ (WAPPaymentToken*)makeWithJsonDetails:(NSString *)paymentMethodId jsonDetails:(NSString *)jsonDetails ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * jsonDetails;
@property (readonly) NSString * paymentMethodId;
@end

#endif // __WAPPaymentToken_DEFINED__

// Windows.ApplicationModel.Payments.PaymentShippingOption
#ifndef __WAPPaymentShippingOption_DEFINED__
#define __WAPPaymentShippingOption_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentShippingOption : RTObject
+ (WAPPaymentShippingOption*)make:(NSString *)label amount:(WAPPaymentCurrencyAmount*)amount ACTIVATOR;
+ (WAPPaymentShippingOption*)makeWithSelected:(NSString *)label amount:(WAPPaymentCurrencyAmount*)amount selected:(BOOL)selected ACTIVATOR;
+ (WAPPaymentShippingOption*)makeWithSelectedAndTag:(NSString *)label amount:(WAPPaymentCurrencyAmount*)amount selected:(BOOL)selected tag:(NSString *)tag ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * tag;
@property (retain) NSString * label;
@property BOOL isSelected;
@property (retain) WAPPaymentCurrencyAmount* amount;
@end

#endif // __WAPPaymentShippingOption_DEFINED__

// Windows.ApplicationModel.Payments.PaymentAddress
#ifndef __WAPPaymentAddress_DEFINED__
#define __WAPPaymentAddress_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentAddress : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * sortingCode;
@property (retain) NSString * region;
@property (retain) NSString * recipient;
@property (retain) NSString * postalCode;
@property (retain) NSString * phoneNumber;
@property (retain) NSString * organization;
@property (retain) NSString * languageCode;
@property (retain) NSString * dependentLocality;
@property (retain) NSString * country;
@property (retain) NSString * city;
@property (retain) NSArray* /* NSString * */ addressLines;
@property (readonly) WFCValueSet* properties;
@end

#endif // __WAPPaymentAddress_DEFINED__

// Windows.ApplicationModel.Payments.PaymentItem
#ifndef __WAPPaymentItem_DEFINED__
#define __WAPPaymentItem_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentItem : RTObject
+ (WAPPaymentItem*)make:(NSString *)label amount:(WAPPaymentCurrencyAmount*)amount ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL pending;
@property (retain) NSString * label;
@property (retain) WAPPaymentCurrencyAmount* amount;
@end

#endif // __WAPPaymentItem_DEFINED__

// Windows.ApplicationModel.Payments.PaymentDetailsModifier
#ifndef __WAPPaymentDetailsModifier_DEFINED__
#define __WAPPaymentDetailsModifier_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentDetailsModifier : RTObject
+ (WAPPaymentDetailsModifier*)make:(id<NSFastEnumeration> /* NSString * */)supportedMethodIds total:(WAPPaymentItem*)total ACTIVATOR;
+ (WAPPaymentDetailsModifier*)makeWithAdditionalDisplayItems:(id<NSFastEnumeration> /* NSString * */)supportedMethodIds total:(WAPPaymentItem*)total additionalDisplayItems:(id<NSFastEnumeration> /* WAPPaymentItem* */)additionalDisplayItems ACTIVATOR;
+ (WAPPaymentDetailsModifier*)makeWithAdditionalDisplayItemsAndJsonData:(id<NSFastEnumeration> /* NSString * */)supportedMethodIds total:(WAPPaymentItem*)total additionalDisplayItems:(id<NSFastEnumeration> /* WAPPaymentItem* */)additionalDisplayItems jsonData:(NSString *)jsonData ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WAPPaymentItem* */ additionalDisplayItems;
@property (readonly) NSString * jsonData;
@property (readonly) NSArray* /* NSString * */ supportedMethodIds;
@property (readonly) WAPPaymentItem* total;
@end

#endif // __WAPPaymentDetailsModifier_DEFINED__

// Windows.ApplicationModel.Payments.PaymentCurrencyAmount
#ifndef __WAPPaymentCurrencyAmount_DEFINED__
#define __WAPPaymentCurrencyAmount_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentCurrencyAmount : RTObject
+ (WAPPaymentCurrencyAmount*)make:(NSString *)value currency:(NSString *)currency ACTIVATOR;
+ (WAPPaymentCurrencyAmount*)makeWithCurrencySystem:(NSString *)value currency:(NSString *)currency currencySystem:(NSString *)currencySystem ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * value;
@property (retain) NSString * currencySystem;
@property (retain) NSString * currency;
@end

#endif // __WAPPaymentCurrencyAmount_DEFINED__

// Windows.ApplicationModel.Payments.PaymentRequestChangedResult
#ifndef __WAPPaymentRequestChangedResult_DEFINED__
#define __WAPPaymentRequestChangedResult_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentRequestChangedResult : RTObject
+ (WAPPaymentRequestChangedResult*)make:(BOOL)changeAcceptedByMerchant ACTIVATOR;
+ (WAPPaymentRequestChangedResult*)makeWithPaymentDetails:(BOOL)changeAcceptedByMerchant updatedPaymentDetails:(WAPPaymentDetails*)updatedPaymentDetails ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WAPPaymentDetails* updatedPaymentDetails;
@property (retain) NSString * message;
@property BOOL changeAcceptedByMerchant;
@end

#endif // __WAPPaymentRequestChangedResult_DEFINED__

// Windows.ApplicationModel.Payments.PaymentRequestChangedArgs
#ifndef __WAPPaymentRequestChangedArgs_DEFINED__
#define __WAPPaymentRequestChangedArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentRequestChangedArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAPPaymentRequestChangeKind changeKind;
@property (readonly) WAPPaymentShippingOption* selectedShippingOption;
@property (readonly) WAPPaymentAddress* shippingAddress;
- (void)acknowledge:(WAPPaymentRequestChangedResult*)changeResult;
@end

#endif // __WAPPaymentRequestChangedArgs_DEFINED__

// Windows.ApplicationModel.Payments.PaymentRequestSubmitResult
#ifndef __WAPPaymentRequestSubmitResult_DEFINED__
#define __WAPPaymentRequestSubmitResult_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentRequestSubmitResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAPPaymentResponse* response;
@property (readonly) WAPPaymentRequestStatus status;
@end

#endif // __WAPPaymentRequestSubmitResult_DEFINED__

// Windows.ApplicationModel.Payments.PaymentCanMakePaymentResult
#ifndef __WAPPaymentCanMakePaymentResult_DEFINED__
#define __WAPPaymentCanMakePaymentResult_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentCanMakePaymentResult : RTObject
+ (WAPPaymentCanMakePaymentResult*)make:(WAPPaymentCanMakePaymentResultStatus)value ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAPPaymentCanMakePaymentResultStatus status;
@end

#endif // __WAPPaymentCanMakePaymentResult_DEFINED__

// Windows.ApplicationModel.Payments.PaymentResponse
#ifndef __WAPPaymentResponse_DEFINED__
#define __WAPPaymentResponse_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentResponse : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * payerEmail;
@property (readonly) NSString * payerName;
@property (readonly) NSString * payerPhoneNumber;
@property (readonly) WAPPaymentToken* paymentToken;
@property (readonly) WAPPaymentAddress* shippingAddress;
@property (readonly) WAPPaymentShippingOption* shippingOption;
- (RTObject<WFIAsyncAction>*)completeAsync:(WAPPaymentRequestCompletionStatus)status;
@end

#endif // __WAPPaymentResponse_DEFINED__

// Windows.ApplicationModel.Payments.PaymentMediator
#ifndef __WAPPaymentMediator_DEFINED__
#define __WAPPaymentMediator_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSEXPORT
@interface WAPPaymentMediator : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)getSupportedMethodIdsAsyncWithSuccess:(void (^)(NSArray* /* NSString * */))success failure:(void (^)(NSError*))failure;
- (void)submitPaymentRequestAsync:(WAPPaymentRequest*)paymentRequest success:(void (^)(WAPPaymentRequestSubmitResult*))success failure:(void (^)(NSError*))failure;
- (void)submitPaymentRequestWithChangeHandlerAsync:(WAPPaymentRequest*)paymentRequest changeHandler:(WAPPaymentRequestChangedHandler)changeHandler success:(void (^)(WAPPaymentRequestSubmitResult*))success failure:(void (^)(NSError*))failure;
- (void)canMakePaymentAsync:(WAPPaymentRequest*)paymentRequest success:(void (^)(WAPPaymentCanMakePaymentResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAPPaymentMediator_DEFINED__

