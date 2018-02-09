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

// WindowsUINotificationsManagement.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUINOTIFICATIONSMANAGEMENTEXPORT
#define OBJCUWPWINDOWSUINOTIFICATIONSMANAGEMENTEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUINotificationsManagement.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUNMUserNotificationListener;
@protocol WUNMIUserNotificationListenerStatics, WUNMIUserNotificationListener;

// Windows.UI.Notifications.Management.UserNotificationListenerAccessStatus
enum _WUNMUserNotificationListenerAccessStatus {
    WUNMUserNotificationListenerAccessStatusUnspecified = 0,
    WUNMUserNotificationListenerAccessStatusAllowed = 1,
    WUNMUserNotificationListenerAccessStatusDenied = 2,
};
typedef unsigned WUNMUserNotificationListenerAccessStatus;

#include "WindowsUINotifications.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.UI.Notifications.Management.UserNotificationListener
#ifndef __WUNMUserNotificationListener_DEFINED__
#define __WUNMUserNotificationListener_DEFINED__

OBJCUWPWINDOWSUINOTIFICATIONSMANAGEMENTEXPORT
@interface WUNMUserNotificationListener : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (WUNMUserNotificationListener*)current;
- (EventRegistrationToken)addNotificationChangedEvent:(void(^)(WUNMUserNotificationListener*, WUNUserNotificationChangedEventArgs*))del;
- (void)removeNotificationChangedEvent:(EventRegistrationToken)tok;
- (void)requestAccessAsyncWithSuccess:(void (^)(WUNMUserNotificationListenerAccessStatus))success failure:(void (^)(NSError*))failure;
- (WUNMUserNotificationListenerAccessStatus)getAccessStatus;
- (void)getNotificationsAsync:(WUNNotificationKinds)kinds success:(void (^)(NSArray* /* WUNUserNotification* */))success failure:(void (^)(NSError*))failure;
- (WUNUserNotification*)getNotification:(unsigned int)notificationId;
- (void)clearNotifications;
- (void)removeNotification:(unsigned int)notificationId;
@end

#endif // __WUNMUserNotificationListener_DEFINED__

