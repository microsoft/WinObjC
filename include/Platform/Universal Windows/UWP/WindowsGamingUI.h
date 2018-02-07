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

// WindowsGamingUI.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGAMINGUIEXPORT
#define OBJCUWPWINDOWSGAMINGUIEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGamingUI.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGUGameBar, WGUGameChatOverlay, WGUGameMonitor, WGUGameChatOverlayMessageSource, WGUGameChatMessageReceivedEventArgs, WGUGameUIProviderActivatedEventArgs;
@protocol WGUIGameBarStatics, WGUIGameChatOverlayStatics, WGUIGameChatOverlay, WGUIGameMonitor, WGUIGameMonitorStatics, WGUIGameChatOverlayMessageSource, WGUIGameChatMessageReceivedEventArgs, WGUIGameUIProviderActivatedEventArgs;

// Windows.Gaming.UI.GameChatOverlayPosition
enum _WGUGameChatOverlayPosition {
    WGUGameChatOverlayPositionBottomCenter = 0,
    WGUGameChatOverlayPositionBottomLeft = 1,
    WGUGameChatOverlayPositionBottomRight = 2,
    WGUGameChatOverlayPositionMiddleRight = 3,
    WGUGameChatOverlayPositionMiddleLeft = 4,
    WGUGameChatOverlayPositionTopCenter = 5,
    WGUGameChatOverlayPositionTopLeft = 6,
    WGUGameChatOverlayPositionTopRight = 7,
};
typedef unsigned WGUGameChatOverlayPosition;

// Windows.Gaming.UI.GameChatMessageOrigin
enum _WGUGameChatMessageOrigin {
    WGUGameChatMessageOriginVoice = 0,
    WGUGameChatMessageOriginText = 1,
};
typedef unsigned WGUGameChatMessageOrigin;

// Windows.Gaming.UI.GameMonitoringPermission
enum _WGUGameMonitoringPermission {
    WGUGameMonitoringPermissionAllowed = 0,
    WGUGameMonitoringPermissionDeniedByUser = 1,
    WGUGameMonitoringPermissionDeniedBySystem = 2,
};
typedef unsigned WGUGameMonitoringPermission;

#include "WindowsFoundation.h"
#include "WindowsApplicationModelActivation.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.Gaming.UI.GameBar
#ifndef __WGUGameBar_DEFINED__
#define __WGUGameBar_DEFINED__

OBJCUWPWINDOWSGAMINGUIEXPORT
@interface WGUGameBar : RTObject
+ (BOOL)isInputRedirected;
+ (BOOL)visible;
+ (EventRegistrationToken)addIsInputRedirectedChangedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeIsInputRedirectedChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addVisibilityChangedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeVisibilityChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WGUGameBar_DEFINED__

// Windows.Gaming.UI.GameChatOverlay
#ifndef __WGUGameChatOverlay_DEFINED__
#define __WGUGameChatOverlay_DEFINED__

OBJCUWPWINDOWSGAMINGUIEXPORT
@interface WGUGameChatOverlay : RTObject
+ (WGUGameChatOverlay*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WGUGameChatOverlayPosition desiredPosition;
- (void)addMessage:(NSString *)sender message:(NSString *)message origin:(WGUGameChatMessageOrigin)origin;
@end

#endif // __WGUGameChatOverlay_DEFINED__

// Windows.Gaming.UI.GameMonitor
#ifndef __WGUGameMonitor_DEFINED__
#define __WGUGameMonitor_DEFINED__

OBJCUWPWINDOWSGAMINGUIEXPORT
@interface WGUGameMonitor : RTObject
+ (WGUGameMonitor*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)requestPermissionAsyncWithSuccess:(void (^)(WGUGameMonitoringPermission))success failure:(void (^)(NSError*))failure;
@end

#endif // __WGUGameMonitor_DEFINED__

// Windows.Gaming.UI.GameChatOverlayMessageSource
#ifndef __WGUGameChatOverlayMessageSource_DEFINED__
#define __WGUGameChatOverlayMessageSource_DEFINED__

OBJCUWPWINDOWSGAMINGUIEXPORT
@interface WGUGameChatOverlayMessageSource : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addMessageReceivedEvent:(void(^)(WGUGameChatOverlayMessageSource*, WGUGameChatMessageReceivedEventArgs*))del;
- (void)removeMessageReceivedEvent:(EventRegistrationToken)tok;
- (void)setDelayBeforeClosingAfterMessageReceived:(WFTimeSpan*)value;
@end

#endif // __WGUGameChatOverlayMessageSource_DEFINED__

// Windows.Gaming.UI.GameChatMessageReceivedEventArgs
#ifndef __WGUGameChatMessageReceivedEventArgs_DEFINED__
#define __WGUGameChatMessageReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSGAMINGUIEXPORT
@interface WGUGameChatMessageReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * appDisplayName;
@property (readonly) NSString * appId;
@property (readonly) NSString * message;
@property (readonly) WGUGameChatMessageOrigin origin;
@property (readonly) NSString * senderName;
@end

#endif // __WGUGameChatMessageReceivedEventArgs_DEFINED__

// Windows.ApplicationModel.Activation.IActivatedEventArgs
#ifndef __WAAIActivatedEventArgs_DEFINED__
#define __WAAIActivatedEventArgs_DEFINED__

@protocol WAAIActivatedEventArgs
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@end

OBJCUWPWINDOWSGAMINGUIEXPORT
@interface WAAIActivatedEventArgs : RTObject <WAAIActivatedEventArgs>
@end

#endif // __WAAIActivatedEventArgs_DEFINED__

// Windows.Gaming.UI.GameUIProviderActivatedEventArgs
#ifndef __WGUGameUIProviderActivatedEventArgs_DEFINED__
#define __WGUGameUIProviderActivatedEventArgs_DEFINED__

OBJCUWPWINDOWSGAMINGUIEXPORT
@interface WGUGameUIProviderActivatedEventArgs : RTObject <WAAIActivatedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAActivationKind kind;
@property (readonly) WAAApplicationExecutionState previousExecutionState;
@property (readonly) WAASplashScreen* splashScreen;
@property (readonly) WFCValueSet* gameUIArgs;
- (void)reportCompleted:(WFCValueSet*)results;
@end

#endif // __WGUGameUIProviderActivatedEventArgs_DEFINED__

