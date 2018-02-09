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

// WindowsApplicationModelAppService.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELAPPSERVICEEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELAPPSERVICEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelAppService.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAAAppServiceRequest, WAAAppServiceDeferral, WAAAppServiceResponse, WAAAppServiceConnection, WAAAppServiceRequestReceivedEventArgs, WAAAppServiceClosedEventArgs, WAAAppServiceTriggerDetails, WAAAppServiceCatalog;
@protocol WAAIAppServiceDeferral, WAAIAppServiceClosedEventArgs, WAAIAppServiceRequestReceivedEventArgs, WAAIAppServiceConnection, WAAIAppServiceConnection2, WAAIAppServiceTriggerDetails, WAAIAppServiceTriggerDetails2, WAAIAppServiceTriggerDetails3, WAAIAppServiceRequest, WAAIAppServiceResponse, WAAIAppServiceCatalogStatics;

// Windows.ApplicationModel.AppService.AppServiceClosedStatus
enum _WAAAppServiceClosedStatus {
    WAAAppServiceClosedStatusCompleted = 0,
    WAAAppServiceClosedStatusCanceled = 1,
    WAAAppServiceClosedStatusResourceLimitsExceeded = 2,
    WAAAppServiceClosedStatusUnknown = 3,
};
typedef unsigned WAAAppServiceClosedStatus;

// Windows.ApplicationModel.AppService.AppServiceConnectionStatus
enum _WAAAppServiceConnectionStatus {
    WAAAppServiceConnectionStatusSuccess = 0,
    WAAAppServiceConnectionStatusAppNotInstalled = 1,
    WAAAppServiceConnectionStatusAppUnavailable = 2,
    WAAAppServiceConnectionStatusAppServiceUnavailable = 3,
    WAAAppServiceConnectionStatusUnknown = 4,
    WAAAppServiceConnectionStatusRemoteSystemUnavailable = 5,
    WAAAppServiceConnectionStatusRemoteSystemNotSupportedByApp = 6,
    WAAAppServiceConnectionStatusNotAuthorized = 7,
};
typedef unsigned WAAAppServiceConnectionStatus;

// Windows.ApplicationModel.AppService.AppServiceResponseStatus
enum _WAAAppServiceResponseStatus {
    WAAAppServiceResponseStatusSuccess = 0,
    WAAAppServiceResponseStatusFailure = 1,
    WAAAppServiceResponseStatusResourceLimitsExceeded = 2,
    WAAAppServiceResponseStatusUnknown = 3,
    WAAAppServiceResponseStatusRemoteSystemUnavailable = 4,
    WAAAppServiceResponseStatusMessageSizeTooLarge = 5,
};
typedef unsigned WAAAppServiceResponseStatus;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsSystemRemoteSystems.h"
#include "WindowsApplicationModel.h"
#include "WindowsSystem.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.AppService.AppServiceRequest
#ifndef __WAAAppServiceRequest_DEFINED__
#define __WAAAppServiceRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPSERVICEEXPORT
@interface WAAAppServiceRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFCValueSet* message;
- (void)sendResponseAsync:(WFCValueSet*)message success:(void (^)(WAAAppServiceResponseStatus))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAAAppServiceRequest_DEFINED__

// Windows.ApplicationModel.AppService.AppServiceDeferral
#ifndef __WAAAppServiceDeferral_DEFINED__
#define __WAAAppServiceDeferral_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPSERVICEEXPORT
@interface WAAAppServiceDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WAAAppServiceDeferral_DEFINED__

// Windows.ApplicationModel.AppService.AppServiceResponse
#ifndef __WAAAppServiceResponse_DEFINED__
#define __WAAAppServiceResponse_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPSERVICEEXPORT
@interface WAAAppServiceResponse : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFCValueSet* message;
@property (readonly) WAAAppServiceResponseStatus status;
@end

#endif // __WAAAppServiceResponse_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSAPPLICATIONMODELAPPSERVICEEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.ApplicationModel.AppService.AppServiceConnection
#ifndef __WAAAppServiceConnection_DEFINED__
#define __WAAAppServiceConnection_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPSERVICEEXPORT
@interface WAAAppServiceConnection : RTObject <WFIClosable>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * packageFamilyName;
@property (retain) NSString * appServiceName;
@property (retain) WSUser* user;
- (EventRegistrationToken)addRequestReceivedEvent:(void(^)(WAAAppServiceConnection*, WAAAppServiceRequestReceivedEventArgs*))del;
- (void)removeRequestReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addServiceClosedEvent:(void(^)(WAAAppServiceConnection*, WAAAppServiceClosedEventArgs*))del;
- (void)removeServiceClosedEvent:(EventRegistrationToken)tok;
- (void)openAsyncWithSuccess:(void (^)(WAAAppServiceConnectionStatus))success failure:(void (^)(NSError*))failure;
- (void)sendMessageAsync:(WFCValueSet*)message success:(void (^)(WAAAppServiceResponse*))success failure:(void (^)(NSError*))failure;
- (void)close;
- (void)openRemoteAsync:(WSRRemoteSystemConnectionRequest*)remoteSystemConnectionRequest success:(void (^)(WAAAppServiceConnectionStatus))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAAAppServiceConnection_DEFINED__

// Windows.ApplicationModel.AppService.AppServiceRequestReceivedEventArgs
#ifndef __WAAAppServiceRequestReceivedEventArgs_DEFINED__
#define __WAAAppServiceRequestReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPSERVICEEXPORT
@interface WAAAppServiceRequestReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAAppServiceRequest* request;
- (WAAAppServiceDeferral*)getDeferral;
@end

#endif // __WAAAppServiceRequestReceivedEventArgs_DEFINED__

// Windows.ApplicationModel.AppService.AppServiceClosedEventArgs
#ifndef __WAAAppServiceClosedEventArgs_DEFINED__
#define __WAAAppServiceClosedEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPSERVICEEXPORT
@interface WAAAppServiceClosedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAAppServiceClosedStatus status;
@end

#endif // __WAAAppServiceClosedEventArgs_DEFINED__

// Windows.ApplicationModel.AppService.AppServiceTriggerDetails
#ifndef __WAAAppServiceTriggerDetails_DEFINED__
#define __WAAAppServiceTriggerDetails_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPSERVICEEXPORT
@interface WAAAppServiceTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAAppServiceConnection* appServiceConnection;
@property (readonly) NSString * callerPackageFamilyName;
@property (readonly) NSString * name;
@property (readonly) BOOL isRemoteSystemConnection;
- (void)checkCallerForCapabilityAsync:(NSString *)capabilityName success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAAAppServiceTriggerDetails_DEFINED__

// Windows.ApplicationModel.AppService.AppServiceCatalog
#ifndef __WAAAppServiceCatalog_DEFINED__
#define __WAAAppServiceCatalog_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELAPPSERVICEEXPORT
@interface WAAAppServiceCatalog : RTObject
+ (void)findAppServiceProvidersAsync:(NSString *)appServiceName success:(void (^)(NSArray* /* WAAppInfo* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAAAppServiceCatalog_DEFINED__

