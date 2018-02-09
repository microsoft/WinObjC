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

// WindowsApplicationModelPaymentsProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSPROVIDEREXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSPROVIDEREXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelPaymentsProvider.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAPPPaymentAppManager, WAPPPaymentTransactionAcceptResult, WAPPPaymentTransaction, WAPPPaymentAppCanMakePaymentTriggerDetails;
@protocol WAPPIPaymentAppManager, WAPPIPaymentAppManagerStatics, WAPPIPaymentTransaction, WAPPIPaymentTransactionAcceptResult, WAPPIPaymentTransactionStatics, WAPPIPaymentAppCanMakePaymentTriggerDetails;

#include "WindowsFoundation.h"
#include "WindowsApplicationModelPayments.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Payments.Provider.PaymentAppManager
#ifndef __WAPPPaymentAppManager_DEFINED__
#define __WAPPPaymentAppManager_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSPROVIDEREXPORT
@interface WAPPPaymentAppManager : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (WAPPPaymentAppManager*)current;
- (RTObject<WFIAsyncAction>*)registerAsync:(id<NSFastEnumeration> /* NSString * */)supportedPaymentMethodIds;
- (RTObject<WFIAsyncAction>*)unregisterAsync;
@end

#endif // __WAPPPaymentAppManager_DEFINED__

// Windows.ApplicationModel.Payments.Provider.PaymentTransactionAcceptResult
#ifndef __WAPPPaymentTransactionAcceptResult_DEFINED__
#define __WAPPPaymentTransactionAcceptResult_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSPROVIDEREXPORT
@interface WAPPPaymentTransactionAcceptResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAPPaymentRequestCompletionStatus status;
@end

#endif // __WAPPPaymentTransactionAcceptResult_DEFINED__

// Windows.ApplicationModel.Payments.Provider.PaymentTransaction
#ifndef __WAPPPaymentTransaction_DEFINED__
#define __WAPPPaymentTransaction_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSPROVIDEREXPORT
@interface WAPPPaymentTransaction : RTObject
+ (void)fromIdAsync:(NSString *)id success:(void (^)(WAPPPaymentTransaction*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * payerPhoneNumber;
@property (retain) NSString * payerName;
@property (retain) NSString * payerEmail;
@property (readonly) WAPPaymentRequest* paymentRequest;
- (void)updateShippingAddressAsync:(WAPPaymentAddress*)shippingAddress success:(void (^)(WAPPaymentRequestChangedResult*))success failure:(void (^)(NSError*))failure;
- (void)updateSelectedShippingOptionAsync:(WAPPaymentShippingOption*)selectedShippingOption success:(void (^)(WAPPaymentRequestChangedResult*))success failure:(void (^)(NSError*))failure;
- (void)acceptAsync:(WAPPaymentToken*)paymentToken success:(void (^)(WAPPPaymentTransactionAcceptResult*))success failure:(void (^)(NSError*))failure;
- (void)reject;
@end

#endif // __WAPPPaymentTransaction_DEFINED__

// Windows.ApplicationModel.Payments.Provider.PaymentAppCanMakePaymentTriggerDetails
#ifndef __WAPPPaymentAppCanMakePaymentTriggerDetails_DEFINED__
#define __WAPPPaymentAppCanMakePaymentTriggerDetails_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELPAYMENTSPROVIDEREXPORT
@interface WAPPPaymentAppCanMakePaymentTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAPPaymentRequest* request;
- (void)reportCanMakePaymentResult:(WAPPaymentCanMakePaymentResult*)value;
@end

#endif // __WAPPPaymentAppCanMakePaymentTriggerDetails_DEFINED__

