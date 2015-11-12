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

// WindowsNetworkingPushNotifications.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WNPPushNotificationChannel, WNPPushNotificationReceivedEventArgs, WNPRawNotification, WNPPushNotificationChannelManager;
@protocol WNPIPushNotificationChannelManagerStatics
, WNPIPushNotificationChannel, WNPIPushNotificationReceivedEventArgs, WNPIRawNotification;

// Windows.Networking.PushNotifications.PushNotificationType
enum _WNPPushNotificationType {
    WNPPushNotificationTypeToast = 0,
    WNPPushNotificationTypeTile = 1,
    WNPPushNotificationTypeBadge = 2,
    WNPPushNotificationTypeRaw = 3,
};
typedef unsigned WNPPushNotificationType;

#include "WindowsFoundation.h"
#include "WindowsUINotifications.h"

// Windows.Networking.PushNotifications.PushNotificationChannel
#ifndef __WNPPushNotificationChannel_DEFINED__
#define __WNPPushNotificationChannel_DEFINED__

WINRT_EXPORT
@interface WNPPushNotificationChannel : RTObject
@property (readonly) WFDateTime* expirationTime;
@property (readonly) NSString* uri;
- (EventRegistrationToken)addPushNotificationReceivedEvent:(void (^)(WNPPushNotificationChannel*,
                                                                     WNPPushNotificationReceivedEventArgs*))del;
- (void)removePushNotificationReceivedEvent:(EventRegistrationToken)tok;
- (void)close;
@end

#endif // __WNPPushNotificationChannel_DEFINED__

// Windows.Networking.PushNotifications.PushNotificationReceivedEventArgs
#ifndef __WNPPushNotificationReceivedEventArgs_DEFINED__
#define __WNPPushNotificationReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WNPPushNotificationReceivedEventArgs : RTObject
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

WINRT_EXPORT
@interface WNPRawNotification : RTObject
@property (readonly) NSString* content;
@end

#endif // __WNPRawNotification_DEFINED__

// Windows.Networking.PushNotifications.PushNotificationChannelManager
#ifndef __WNPPushNotificationChannelManager_DEFINED__
#define __WNPPushNotificationChannelManager_DEFINED__

WINRT_EXPORT
@interface WNPPushNotificationChannelManager : RTObject
+ (void)createPushNotificationChannelForApplicationAsyncWithSuccess:(void (^)(WNPPushNotificationChannel*))success
                                                            failure:(void (^)(NSError*))failure;
+ (void)createPushNotificationChannelForApplicationAsyncWithId:(NSString*)applicationId
                                                       success:(void (^)(WNPPushNotificationChannel*))success
                                                       failure:(void (^)(NSError*))failure;
+ (void)createPushNotificationChannelForSecondaryTileAsync:(NSString*)tileId
                                                   success:(void (^)(WNPPushNotificationChannel*))success
                                                   failure:(void (^)(NSError*))failure;
@end

#endif // __WNPPushNotificationChannelManager_DEFINED__
