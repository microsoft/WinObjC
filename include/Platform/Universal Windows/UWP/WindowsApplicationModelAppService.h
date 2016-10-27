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

// WindowsApplicationModelAppService.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_APPLICATIONMODEL_APPSERVICE_EXPORT
#define OBJCUWP_WINDOWS_APPLICATIONMODEL_APPSERVICE_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_ApplicationModel_AppService.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAAAppServiceRequest, WAAAppServiceDeferral, WAAAppServiceResponse, WAAAppServiceConnection, WAAAppServiceRequestReceivedEventArgs,
    WAAAppServiceClosedEventArgs, WAAAppServiceTriggerDetails, WAAAppServiceCatalog;
@protocol WAAIAppServiceDeferral
, WAAIAppServiceClosedEventArgs, WAAIAppServiceRequestReceivedEventArgs, WAAIAppServiceTriggerDetails, WAAIAppServiceRequest,
    WAAIAppServiceResponse, WAAIAppServiceCatalogStatics, WAAIAppServiceConnection;

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
};
typedef unsigned WAAAppServiceConnectionStatus;

// Windows.ApplicationModel.AppService.AppServiceResponseStatus
enum _WAAAppServiceResponseStatus {
    WAAAppServiceResponseStatusSuccess = 0,
    WAAAppServiceResponseStatusFailure = 1,
    WAAAppServiceResponseStatusResourceLimitsExceeded = 2,
    WAAAppServiceResponseStatusUnknown = 3,
};
typedef unsigned WAAAppServiceResponseStatus;

#include "WindowsFoundationCollections.h"
#include "WindowsApplicationModel.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.AppService.AppServiceRequest
#ifndef __WAAAppServiceRequest_DEFINED__
#define __WAAAppServiceRequest_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_APPSERVICE_EXPORT
@interface WAAAppServiceRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WFCValueSet* message;
- (void)sendResponseAsync:(WFCValueSet*)message success:(void (^)(WAAAppServiceResponseStatus))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAAAppServiceRequest_DEFINED__

// Windows.ApplicationModel.AppService.AppServiceDeferral
#ifndef __WAAAppServiceDeferral_DEFINED__
#define __WAAAppServiceDeferral_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_APPSERVICE_EXPORT
@interface WAAAppServiceDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)complete;
@end

#endif // __WAAAppServiceDeferral_DEFINED__

// Windows.ApplicationModel.AppService.AppServiceResponse
#ifndef __WAAAppServiceResponse_DEFINED__
#define __WAAAppServiceResponse_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_APPSERVICE_EXPORT
@interface WAAAppServiceResponse : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
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

OBJCUWP_WINDOWS_APPLICATIONMODEL_APPSERVICE_EXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.ApplicationModel.AppService.AppServiceConnection
#ifndef __WAAAppServiceConnection_DEFINED__
#define __WAAAppServiceConnection_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_APPSERVICE_EXPORT
@interface WAAAppServiceConnection : RTObject <WFIClosable>
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (retain) NSString* packageFamilyName;
@property (retain) NSString* appServiceName;
- (EventRegistrationToken)addRequestReceivedEvent:(void (^)(WAAAppServiceConnection*, WAAAppServiceRequestReceivedEventArgs*))del;
- (void)removeRequestReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addServiceClosedEvent:(void (^)(WAAAppServiceConnection*, WAAAppServiceClosedEventArgs*))del;
- (void)removeServiceClosedEvent:(EventRegistrationToken)tok;
- (void)openAsyncWithSuccess:(void (^)(WAAAppServiceConnectionStatus))success failure:(void (^)(NSError*))failure;
- (void)sendMessageAsync:(WFCValueSet*)message success:(void (^)(WAAAppServiceResponse*))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WAAAppServiceConnection_DEFINED__

// Windows.ApplicationModel.AppService.AppServiceRequestReceivedEventArgs
#ifndef __WAAAppServiceRequestReceivedEventArgs_DEFINED__
#define __WAAAppServiceRequestReceivedEventArgs_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_APPSERVICE_EXPORT
@interface WAAAppServiceRequestReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WAAAppServiceRequest* request;
- (WAAAppServiceDeferral*)getDeferral;
@end

#endif // __WAAAppServiceRequestReceivedEventArgs_DEFINED__

// Windows.ApplicationModel.AppService.AppServiceClosedEventArgs
#ifndef __WAAAppServiceClosedEventArgs_DEFINED__
#define __WAAAppServiceClosedEventArgs_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_APPSERVICE_EXPORT
@interface WAAAppServiceClosedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WAAAppServiceClosedStatus status;
@end

#endif // __WAAAppServiceClosedEventArgs_DEFINED__

// Windows.ApplicationModel.AppService.AppServiceTriggerDetails
#ifndef __WAAAppServiceTriggerDetails_DEFINED__
#define __WAAAppServiceTriggerDetails_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_APPSERVICE_EXPORT
@interface WAAAppServiceTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WAAAppServiceConnection* appServiceConnection;
@property (readonly) NSString* callerPackageFamilyName;
@property (readonly) NSString* name;
@end

#endif // __WAAAppServiceTriggerDetails_DEFINED__

// Windows.ApplicationModel.AppService.AppServiceCatalog
#ifndef __WAAAppServiceCatalog_DEFINED__
#define __WAAAppServiceCatalog_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_APPSERVICE_EXPORT
@interface WAAAppServiceCatalog : RTObject
+ (void)findAppServiceProvidersAsync:(NSString*)appServiceName
                             success:(void (^)(NSArray* /* WAAppInfo* */))success
                             failure:(void (^)(NSError*))failure;
@end

#endif // __WAAAppServiceCatalog_DEFINED__
