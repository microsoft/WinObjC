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

// WindowsSystemDiagnosticsDevicePortal.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSYSTEMDIAGNOSTICSDEVICEPORTALEXPORT
#define OBJCUWPWINDOWSSYSTEMDIAGNOSTICSDEVICEPORTALEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsSystemDiagnosticsDevicePortal.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSDDDevicePortalConnectionClosedEventArgs, WSDDDevicePortalConnectionRequestReceivedEventArgs, WSDDDevicePortalConnection;
@protocol WSDDIDevicePortalConnectionClosedEventArgs, WSDDIDevicePortalConnectionRequestReceivedEventArgs, WSDDIDevicePortalConnectionStatics, WSDDIDevicePortalConnection;

// Windows.System.Diagnostics.DevicePortal.DevicePortalConnectionClosedReason
enum _WSDDDevicePortalConnectionClosedReason {
    WSDDDevicePortalConnectionClosedReasonUnknown = 0,
    WSDDDevicePortalConnectionClosedReasonResourceLimitsExceeded = 1,
    WSDDDevicePortalConnectionClosedReasonProtocolError = 2,
    WSDDDevicePortalConnectionClosedReasonNotAuthorized = 3,
    WSDDDevicePortalConnectionClosedReasonUserNotPresent = 4,
    WSDDDevicePortalConnectionClosedReasonServiceTerminated = 5,
};
typedef unsigned WSDDDevicePortalConnectionClosedReason;

#include "WindowsWebHttp.h"
#include "WindowsApplicationModelAppService.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.System.Diagnostics.DevicePortal.DevicePortalConnectionClosedEventArgs
#ifndef __WSDDDevicePortalConnectionClosedEventArgs_DEFINED__
#define __WSDDDevicePortalConnectionClosedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMDIAGNOSTICSDEVICEPORTALEXPORT
@interface WSDDDevicePortalConnectionClosedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSDDDevicePortalConnectionClosedReason reason;
@end

#endif // __WSDDDevicePortalConnectionClosedEventArgs_DEFINED__

// Windows.System.Diagnostics.DevicePortal.DevicePortalConnectionRequestReceivedEventArgs
#ifndef __WSDDDevicePortalConnectionRequestReceivedEventArgs_DEFINED__
#define __WSDDDevicePortalConnectionRequestReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMDIAGNOSTICSDEVICEPORTALEXPORT
@interface WSDDDevicePortalConnectionRequestReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WWHHttpRequestMessage* requestMessage;
@property (readonly) WWHHttpResponseMessage* responseMessage;
@end

#endif // __WSDDDevicePortalConnectionRequestReceivedEventArgs_DEFINED__

// Windows.System.Diagnostics.DevicePortal.DevicePortalConnection
#ifndef __WSDDDevicePortalConnection_DEFINED__
#define __WSDDDevicePortalConnection_DEFINED__

OBJCUWPWINDOWSSYSTEMDIAGNOSTICSDEVICEPORTALEXPORT
@interface WSDDDevicePortalConnection : RTObject
+ (WSDDDevicePortalConnection*)getForAppServiceConnection:(WAAAppServiceConnection*)appServiceConnection;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addClosedEvent:(void(^)(WSDDDevicePortalConnection*, WSDDDevicePortalConnectionClosedEventArgs*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRequestReceivedEvent:(void(^)(WSDDDevicePortalConnection*, WSDDDevicePortalConnectionRequestReceivedEventArgs*))del;
- (void)removeRequestReceivedEvent:(EventRegistrationToken)tok;
@end

#endif // __WSDDDevicePortalConnection_DEFINED__

