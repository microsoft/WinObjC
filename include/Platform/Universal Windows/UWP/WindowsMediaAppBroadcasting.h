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

// WindowsMediaAppBroadcasting.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMEDIAAPPBROADCASTINGEXPORT
#define OBJCUWPWINDOWSMEDIAAPPBROADCASTINGEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsMediaAppBroadcasting.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMAAppBroadcastingStatus, WMAAppBroadcastingUI, WMAAppBroadcastingMonitor, WMAAppBroadcastingStatusDetails;
@protocol WMAIAppBroadcastingUI, WMAIAppBroadcastingUIStatics, WMAIAppBroadcastingMonitor, WMAIAppBroadcastingStatus, WMAIAppBroadcastingStatusDetails;

#include "WindowsSystem.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Media.AppBroadcasting.AppBroadcastingStatus
#ifndef __WMAAppBroadcastingStatus_DEFINED__
#define __WMAAppBroadcastingStatus_DEFINED__

OBJCUWPWINDOWSMEDIAAPPBROADCASTINGEXPORT
@interface WMAAppBroadcastingStatus : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL canStartBroadcast;
@property (readonly) WMAAppBroadcastingStatusDetails* details;
@end

#endif // __WMAAppBroadcastingStatus_DEFINED__

// Windows.Media.AppBroadcasting.AppBroadcastingUI
#ifndef __WMAAppBroadcastingUI_DEFINED__
#define __WMAAppBroadcastingUI_DEFINED__

OBJCUWPWINDOWSMEDIAAPPBROADCASTINGEXPORT
@interface WMAAppBroadcastingUI : RTObject
+ (WMAAppBroadcastingUI*)getDefault;
+ (WMAAppBroadcastingUI*)getForUser:(WSUser*)user;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WMAAppBroadcastingStatus*)getStatus;
- (void)showBroadcastUI;
@end

#endif // __WMAAppBroadcastingUI_DEFINED__

// Windows.Media.AppBroadcasting.AppBroadcastingMonitor
#ifndef __WMAAppBroadcastingMonitor_DEFINED__
#define __WMAAppBroadcastingMonitor_DEFINED__

OBJCUWPWINDOWSMEDIAAPPBROADCASTINGEXPORT
@interface WMAAppBroadcastingMonitor : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isCurrentAppBroadcasting;
- (EventRegistrationToken)addIsCurrentAppBroadcastingChangedEvent:(void(^)(WMAAppBroadcastingMonitor*, RTObject*))del;
- (void)removeIsCurrentAppBroadcastingChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMAAppBroadcastingMonitor_DEFINED__

// Windows.Media.AppBroadcasting.AppBroadcastingStatusDetails
#ifndef __WMAAppBroadcastingStatusDetails_DEFINED__
#define __WMAAppBroadcastingStatusDetails_DEFINED__

OBJCUWPWINDOWSMEDIAAPPBROADCASTINGEXPORT
@interface WMAAppBroadcastingStatusDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isAnyAppBroadcasting;
@property (readonly) BOOL isAppInactive;
@property (readonly) BOOL isBlockedForApp;
@property (readonly) BOOL isCaptureResourceUnavailable;
@property (readonly) BOOL isDisabledBySystem;
@property (readonly) BOOL isDisabledByUser;
@property (readonly) BOOL isGameStreamInProgress;
@property (readonly) BOOL isGpuConstrained;
@end

#endif // __WMAAppBroadcastingStatusDetails_DEFINED__

