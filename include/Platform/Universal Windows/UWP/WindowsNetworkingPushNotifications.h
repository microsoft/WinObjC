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

// WindowsNetworkingPushNotifications.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSNETWORKINGPUSHNOTIFICATIONSEXPORT
#define OBJCUWPWINDOWSNETWORKINGPUSHNOTIFICATIONSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsNetworkingPushNotifications.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WNPPushNotificationChannel, WNPPushNotificationChannelManagerForUser, WNPPushNotificationReceivedEventArgs, WNPRawNotification, WNPPushNotificationChannelManager;
@protocol WNPIPushNotificationChannelManagerStatics, WNPIPushNotificationChannelManagerStatics2, WNPIPushNotificationChannelManagerStatics3, WNPIPushNotificationChannelManagerForUser, WNPIPushNotificationChannelManagerForUser2, WNPIPushNotificationChannel, WNPIPushNotificationReceivedEventArgs, WNPIRawNotification, WNPIRawNotification2;

// Windows.Networking.PushNotifications.PushNotificationType
enum _WNPPushNotificationType {
    WNPPushNotificationTypeToast = 0,
    WNPPushNotificationTypeTile = 1,
    WNPPushNotificationTypeBadge = 2,
    WNPPushNotificationTypeRaw = 3,
    WNPPushNotificationTypeTileFlyout = 4,
};
typedef unsigned WNPPushNotificationType;

#include "WindowsStorageStreams.h"
#include "WindowsSystem.h"
#include "WindowsFoundation.h"
#include "WindowsUINotifications.h"

#import <Foundation/Foundation.h>

// Windows.Networking.PushNotifications.PushNotificationChannel
#ifndef __WNPPushNotificationChannel_DEFINED__
#define __WNPPushNotificationChannel_DEFINED__

OBJCUWPWINDOWSNETWORKINGPUSHNOTIFICATIONSEXPORT
@interface WNPPushNotificationChannel : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFDateTime* expirationTime;
@property (readonly) NSString * uri;
- (EventRegistrationToken)addPushNotificationReceivedEvent:(void(^)(WNPPushNotificationChannel*, WNPPushNotificationReceivedEventArgs*))del;
- (void)removePushNotificationReceivedEvent:(EventRegistrationToken)tok;
- (void)close;
@end

#endif // __WNPPushNotificationChannel_DEFINED__

// Windows.Networking.PushNotifications.PushNotificationChannelManagerForUser
#ifndef __WNPPushNotificationChannelManagerForUser_DEFINED__
#define __WNPPushNotificationChannelManagerForUser_DEFINED__

OBJCUWPWINDOWSNETWORKINGPUSHNOTIFICATIONSEXPORT
@interface WNPPushNotificationChannelManagerForUser : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSUser* user;
- (void)createPushNotificationChannelForApplicationAsyncWithSuccess:(void (^)(WNPPushNotificationChannel*))success failure:(void (^)(NSError*))failure;
- (void)createPushNotificationChannelForApplicationAsyncWithId:(NSString *)applicationId success:(void (^)(WNPPushNotificationChannel*))success failure:(void (^)(NSError*))failure;
- (void)createPushNotificationChannelForSecondaryTileAsync:(NSString *)tileId success:(void (^)(WNPPushNotificationChannel*))success failure:(void (^)(NSError*))failure;
- (void)createRawPushNotificationChannelWithAlternateKeyForApplicationAsync:(RTObject<WSSIBuffer>*)appServerKey channelId:(NSString *)channelId success:(void (^)(WNPPushNotificationChannel*))success failure:(void (^)(NSError*))failure;
- (void)createRawPushNotificationChannelWithAlternateKeyForApplicationAsyncWithId:(RTObject<WSSIBuffer>*)appServerKey channelId:(NSString *)channelId appId:(NSString *)appId success:(void (^)(WNPPushNotificationChannel*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WNPPushNotificationChannelManagerForUser_DEFINED__

// Windows.Networking.PushNotifications.PushNotificationReceivedEventArgs
#ifndef __WNPPushNotificationReceivedEventArgs_DEFINED__
#define __WNPPushNotificationReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSNETWORKINGPUSHNOTIFICATIONSEXPORT
@interface WNPPushNotificationReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL cancel;
@property (readonly) WUNBadgeNotification* badgeNotification;
@property (readonly) WNPPushNotificationType notificationType;
@property (readonly) WNPRawNotification* rawNotification;
@property (readonly) WUNTileNotification* tileNotification;
@property (readonly) WUNToastNotification* toastNotification;
@end

#endif // __WNPPushNotificationReceivedEventArgs_DEFINED__

// Windows.Networking.PushNotifications.RawNotification
#ifndef __WNPRawNotification_DEFINED__
#define __WNPRawNotification_DEFINED__

OBJCUWPWINDOWSNETWORKINGPUSHNOTIFICATIONSEXPORT
@interface WNPRawNotification : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * content;
@property (readonly) NSString * channelId;
@property (readonly) NSDictionary* /* NSString *, NSString * */ headers;
@end

#endif // __WNPRawNotification_DEFINED__

// Windows.Networking.PushNotifications.PushNotificationChannelManager
#ifndef __WNPPushNotificationChannelManager_DEFINED__
#define __WNPPushNotificationChannelManager_DEFINED__

OBJCUWPWINDOWSNETWORKINGPUSHNOTIFICATIONSEXPORT
@interface WNPPushNotificationChannelManager : RTObject
+ (void)createPushNotificationChannelForApplicationAsyncWithSuccess:(void (^)(WNPPushNotificationChannel*))success failure:(void (^)(NSError*))failure;
+ (void)createPushNotificationChannelForApplicationAsyncWithId:(NSString *)applicationId success:(void (^)(WNPPushNotificationChannel*))success failure:(void (^)(NSError*))failure;
+ (void)createPushNotificationChannelForSecondaryTileAsync:(NSString *)tileId success:(void (^)(WNPPushNotificationChannel*))success failure:(void (^)(NSError*))failure;
+ (WNPPushNotificationChannelManagerForUser*)getForUser:(WSUser*)user;
+ (WNPPushNotificationChannelManagerForUser*)getDefault;
@end

#endif // __WNPPushNotificationChannelManager_DEFINED__

