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

// WindowsUINotifications.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUNTileUpdater, WUNTileNotification, WUNScheduledTileNotification, WUNTileFlyoutUpdater, WUNTileFlyoutNotification, WUNBadgeUpdater,
    WUNBadgeNotification, WUNToastNotifier, WUNToastNotification, WUNScheduledToastNotification, WUNToastDismissedEventArgs,
    WUNToastFailedEventArgs, WUNToastNotificationHistory, WUNTileUpdateManager, WUNBadgeUpdateManager, WUNTileFlyoutUpdateManager,
    WUNToastNotificationManager, WUNToastActivatedEventArgs, WUNToastNotificationHistoryChangedTriggerDetail,
    WUNToastNotificationActionTriggerDetail;
@protocol WUNIToastDismissedEventArgs
, WUNIToastFailedEventArgs, WUNIToastActivatedEventArgs, WUNITileUpdateManagerStatics, WUNITileUpdater, WUNITileUpdater2,
    WUNITileFlyoutUpdateManagerStatics, WUNITileFlyoutUpdater, WUNIBadgeUpdateManagerStatics, WUNIBadgeUpdater,
    WUNIToastNotificationManagerStatics, WUNIToastNotifier, WUNITileNotificationFactory, WUNITileNotification,
    WUNITileFlyoutNotificationFactory, WUNITileFlyoutNotification, WUNIBadgeNotificationFactory, WUNIBadgeNotification,
    WUNIToastNotificationFactory, WUNIToastNotification, WUNIToastNotification2, WUNIScheduledToastNotificationFactory,
    WUNIScheduledToastNotification, WUNIScheduledToastNotification2, WUNIScheduledTileNotificationFactory, WUNIScheduledTileNotification,
    WUNIToastNotificationManagerStatics2, WUNIToastNotificationHistory, WUNIToastNotificationHistory2,
    WUNIToastNotificationHistoryChangedTriggerDetail, WUNIToastNotificationActionTriggerDetail;

// Windows.UI.Notifications.NotificationSetting
enum _WUNNotificationSetting {
    WUNNotificationSettingEnabled = 0,
    WUNNotificationSettingDisabledForApplication = 1,
    WUNNotificationSettingDisabledForUser = 2,
    WUNNotificationSettingDisabledByGroupPolicy = 3,
    WUNNotificationSettingDisabledByManifest = 4,
};
typedef unsigned WUNNotificationSetting;

// Windows.UI.Notifications.ToastDismissalReason
enum _WUNToastDismissalReason {
    WUNToastDismissalReasonUserCanceled = 0,
    WUNToastDismissalReasonApplicationHidden = 1,
    WUNToastDismissalReasonTimedOut = 2,
};
typedef unsigned WUNToastDismissalReason;

// Windows.UI.Notifications.BadgeTemplateType
enum _WUNBadgeTemplateType {
    WUNBadgeTemplateTypeBadgeGlyph = 0,
    WUNBadgeTemplateTypeBadgeNumber = 1,
};
typedef unsigned WUNBadgeTemplateType;

// Windows.UI.Notifications.TileFlyoutTemplateType
enum _WUNTileFlyoutTemplateType {
    WUNTileFlyoutTemplateTypeTileFlyoutTemplate01 = 0,
};
typedef unsigned WUNTileFlyoutTemplateType;

// Windows.UI.Notifications.TileTemplateType
enum _WUNTileTemplateType {
    WUNTileTemplateTypeTileSquareImage = 0,
    WUNTileTemplateTypeTileSquareBlock = 1,
    WUNTileTemplateTypeTileSquareText01 = 2,
    WUNTileTemplateTypeTileSquareText02 = 3,
    WUNTileTemplateTypeTileSquareText03 = 4,
    WUNTileTemplateTypeTileSquareText04 = 5,
    WUNTileTemplateTypeTileSquarePeekImageAndText01 = 6,
    WUNTileTemplateTypeTileSquarePeekImageAndText02 = 7,
    WUNTileTemplateTypeTileSquarePeekImageAndText03 = 8,
    WUNTileTemplateTypeTileSquarePeekImageAndText04 = 9,
    WUNTileTemplateTypeTileWideImage = 10,
    WUNTileTemplateTypeTileWideImageCollection = 11,
    WUNTileTemplateTypeTileWideImageAndText01 = 12,
    WUNTileTemplateTypeTileWideImageAndText02 = 13,
    WUNTileTemplateTypeTileWideBlockAndText01 = 14,
    WUNTileTemplateTypeTileWideBlockAndText02 = 15,
    WUNTileTemplateTypeTileWidePeekImageCollection01 = 16,
    WUNTileTemplateTypeTileWidePeekImageCollection02 = 17,
    WUNTileTemplateTypeTileWidePeekImageCollection03 = 18,
    WUNTileTemplateTypeTileWidePeekImageCollection04 = 19,
    WUNTileTemplateTypeTileWidePeekImageCollection05 = 20,
    WUNTileTemplateTypeTileWidePeekImageCollection06 = 21,
    WUNTileTemplateTypeTileWidePeekImageAndText01 = 22,
    WUNTileTemplateTypeTileWidePeekImageAndText02 = 23,
    WUNTileTemplateTypeTileWidePeekImage01 = 24,
    WUNTileTemplateTypeTileWidePeekImage02 = 25,
    WUNTileTemplateTypeTileWidePeekImage03 = 26,
    WUNTileTemplateTypeTileWidePeekImage04 = 27,
    WUNTileTemplateTypeTileWidePeekImage05 = 28,
    WUNTileTemplateTypeTileWidePeekImage06 = 29,
    WUNTileTemplateTypeTileWideSmallImageAndText01 = 30,
    WUNTileTemplateTypeTileWideSmallImageAndText02 = 31,
    WUNTileTemplateTypeTileWideSmallImageAndText03 = 32,
    WUNTileTemplateTypeTileWideSmallImageAndText04 = 33,
    WUNTileTemplateTypeTileWideSmallImageAndText05 = 34,
    WUNTileTemplateTypeTileWideText01 = 35,
    WUNTileTemplateTypeTileWideText02 = 36,
    WUNTileTemplateTypeTileWideText03 = 37,
    WUNTileTemplateTypeTileWideText04 = 38,
    WUNTileTemplateTypeTileWideText05 = 39,
    WUNTileTemplateTypeTileWideText06 = 40,
    WUNTileTemplateTypeTileWideText07 = 41,
    WUNTileTemplateTypeTileWideText08 = 42,
    WUNTileTemplateTypeTileWideText09 = 43,
    WUNTileTemplateTypeTileWideText10 = 44,
    WUNTileTemplateTypeTileWideText11 = 45,
    WUNTileTemplateTypeTileSquare150x150Image = 0,
    WUNTileTemplateTypeTileSquare150x150Block = 1,
    WUNTileTemplateTypeTileSquare150x150Text01 = 2,
    WUNTileTemplateTypeTileSquare150x150Text02 = 3,
    WUNTileTemplateTypeTileSquare150x150Text03 = 4,
    WUNTileTemplateTypeTileSquare150x150Text04 = 5,
    WUNTileTemplateTypeTileSquare150x150PeekImageAndText01 = 6,
    WUNTileTemplateTypeTileSquare150x150PeekImageAndText02 = 7,
    WUNTileTemplateTypeTileSquare150x150PeekImageAndText03 = 8,
    WUNTileTemplateTypeTileSquare150x150PeekImageAndText04 = 9,
    WUNTileTemplateTypeTileWide310x150Image = 10,
    WUNTileTemplateTypeTileWide310x150ImageCollection = 11,
    WUNTileTemplateTypeTileWide310x150ImageAndText01 = 12,
    WUNTileTemplateTypeTileWide310x150ImageAndText02 = 13,
    WUNTileTemplateTypeTileWide310x150BlockAndText01 = 14,
    WUNTileTemplateTypeTileWide310x150BlockAndText02 = 15,
    WUNTileTemplateTypeTileWide310x150PeekImageCollection01 = 16,
    WUNTileTemplateTypeTileWide310x150PeekImageCollection02 = 17,
    WUNTileTemplateTypeTileWide310x150PeekImageCollection03 = 18,
    WUNTileTemplateTypeTileWide310x150PeekImageCollection04 = 19,
    WUNTileTemplateTypeTileWide310x150PeekImageCollection05 = 20,
    WUNTileTemplateTypeTileWide310x150PeekImageCollection06 = 21,
    WUNTileTemplateTypeTileWide310x150PeekImageAndText01 = 22,
    WUNTileTemplateTypeTileWide310x150PeekImageAndText02 = 23,
    WUNTileTemplateTypeTileWide310x150PeekImage01 = 24,
    WUNTileTemplateTypeTileWide310x150PeekImage02 = 25,
    WUNTileTemplateTypeTileWide310x150PeekImage03 = 26,
    WUNTileTemplateTypeTileWide310x150PeekImage04 = 27,
    WUNTileTemplateTypeTileWide310x150PeekImage05 = 28,
    WUNTileTemplateTypeTileWide310x150PeekImage06 = 29,
    WUNTileTemplateTypeTileWide310x150SmallImageAndText01 = 30,
    WUNTileTemplateTypeTileWide310x150SmallImageAndText02 = 31,
    WUNTileTemplateTypeTileWide310x150SmallImageAndText03 = 32,
    WUNTileTemplateTypeTileWide310x150SmallImageAndText04 = 33,
    WUNTileTemplateTypeTileWide310x150SmallImageAndText05 = 34,
    WUNTileTemplateTypeTileWide310x150Text01 = 35,
    WUNTileTemplateTypeTileWide310x150Text02 = 36,
    WUNTileTemplateTypeTileWide310x150Text03 = 37,
    WUNTileTemplateTypeTileWide310x150Text04 = 38,
    WUNTileTemplateTypeTileWide310x150Text05 = 39,
    WUNTileTemplateTypeTileWide310x150Text06 = 40,
    WUNTileTemplateTypeTileWide310x150Text07 = 41,
    WUNTileTemplateTypeTileWide310x150Text08 = 42,
    WUNTileTemplateTypeTileWide310x150Text09 = 43,
    WUNTileTemplateTypeTileWide310x150Text10 = 44,
    WUNTileTemplateTypeTileWide310x150Text11 = 45,
    WUNTileTemplateTypeTileSquare310x310BlockAndText01 = 46,
    WUNTileTemplateTypeTileSquare310x310BlockAndText02 = 47,
    WUNTileTemplateTypeTileSquare310x310Image = 48,
    WUNTileTemplateTypeTileSquare310x310ImageAndText01 = 49,
    WUNTileTemplateTypeTileSquare310x310ImageAndText02 = 50,
    WUNTileTemplateTypeTileSquare310x310ImageAndTextOverlay01 = 51,
    WUNTileTemplateTypeTileSquare310x310ImageAndTextOverlay02 = 52,
    WUNTileTemplateTypeTileSquare310x310ImageAndTextOverlay03 = 53,
    WUNTileTemplateTypeTileSquare310x310ImageCollectionAndText01 = 54,
    WUNTileTemplateTypeTileSquare310x310ImageCollectionAndText02 = 55,
    WUNTileTemplateTypeTileSquare310x310ImageCollection = 56,
    WUNTileTemplateTypeTileSquare310x310SmallImagesAndTextList01 = 57,
    WUNTileTemplateTypeTileSquare310x310SmallImagesAndTextList02 = 58,
    WUNTileTemplateTypeTileSquare310x310SmallImagesAndTextList03 = 59,
    WUNTileTemplateTypeTileSquare310x310SmallImagesAndTextList04 = 60,
    WUNTileTemplateTypeTileSquare310x310Text01 = 61,
    WUNTileTemplateTypeTileSquare310x310Text02 = 62,
    WUNTileTemplateTypeTileSquare310x310Text03 = 63,
    WUNTileTemplateTypeTileSquare310x310Text04 = 64,
    WUNTileTemplateTypeTileSquare310x310Text05 = 65,
    WUNTileTemplateTypeTileSquare310x310Text06 = 66,
    WUNTileTemplateTypeTileSquare310x310Text07 = 67,
    WUNTileTemplateTypeTileSquare310x310Text08 = 68,
    WUNTileTemplateTypeTileSquare310x310TextList01 = 69,
    WUNTileTemplateTypeTileSquare310x310TextList02 = 70,
    WUNTileTemplateTypeTileSquare310x310TextList03 = 71,
    WUNTileTemplateTypeTileSquare310x310SmallImageAndText01 = 72,
    WUNTileTemplateTypeTileSquare310x310SmallImagesAndTextList05 = 73,
    WUNTileTemplateTypeTileSquare310x310Text09 = 74,
    WUNTileTemplateTypeTileSquare71x71IconWithBadge = 75,
    WUNTileTemplateTypeTileSquare150x150IconWithBadge = 76,
    WUNTileTemplateTypeTileWide310x150IconWithBadgeAndText = 77,
    WUNTileTemplateTypeTileSquare71x71Image = 78,
    WUNTileTemplateTypeTileTall150x310Image = 79,
};
typedef unsigned WUNTileTemplateType;

// Windows.UI.Notifications.ToastTemplateType
enum _WUNToastTemplateType {
    WUNToastTemplateTypeToastImageAndText01 = 0,
    WUNToastTemplateTypeToastImageAndText02 = 1,
    WUNToastTemplateTypeToastImageAndText03 = 2,
    WUNToastTemplateTypeToastImageAndText04 = 3,
    WUNToastTemplateTypeToastText01 = 4,
    WUNToastTemplateTypeToastText02 = 5,
    WUNToastTemplateTypeToastText03 = 6,
    WUNToastTemplateTypeToastText04 = 7,
};
typedef unsigned WUNToastTemplateType;

// Windows.UI.Notifications.PeriodicUpdateRecurrence
enum _WUNPeriodicUpdateRecurrence {
    WUNPeriodicUpdateRecurrenceHalfHour = 0,
    WUNPeriodicUpdateRecurrenceHour = 1,
    WUNPeriodicUpdateRecurrenceSixHours = 2,
    WUNPeriodicUpdateRecurrenceTwelveHours = 3,
    WUNPeriodicUpdateRecurrenceDaily = 4,
};
typedef unsigned WUNPeriodicUpdateRecurrence;

// Windows.UI.Notifications.ToastHistoryChangedType
enum _WUNToastHistoryChangedType {
    WUNToastHistoryChangedTypeCleared = 0,
    WUNToastHistoryChangedTypeRemoved = 1,
    WUNToastHistoryChangedTypeExpired = 2,
    WUNToastHistoryChangedTypeAdded = 3,
};
typedef unsigned WUNToastHistoryChangedType;

#include "WindowsFoundation.h"
#include "WindowsDataXmlDom.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.UI.Notifications.TileUpdater
#ifndef __WUNTileUpdater_DEFINED__
#define __WUNTileUpdater_DEFINED__

WINRT_EXPORT
@interface WUNTileUpdater : RTObject
@property (readonly) WUNNotificationSetting setting;
- (void)update:(WUNTileNotification*)notification;
- (void)clear;
- (void)enableNotificationQueue:(BOOL)enable;
- (void)addToSchedule:(WUNScheduledTileNotification*)scheduledTile;
- (void)removeFromSchedule:(WUNScheduledTileNotification*)scheduledTile;
- (NSArray*)getScheduledTileNotifications;
- (void)startPeriodicUpdate:(WFUri*)tileContent requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval;
- (void)startPeriodicUpdateAtTime:(WFUri*)tileContent
                        startTime:(WFDateTime*)startTime
                requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval;
- (void)stopPeriodicUpdate;
- (void)startPeriodicUpdateBatch:(id<NSFastEnumeration> /* WFUri* */)tileContents
               requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval;
- (void)startPeriodicUpdateBatchAtTime:(id<NSFastEnumeration> /* WFUri* */)tileContents
                             startTime:(WFDateTime*)startTime
                     requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval;
- (void)enableNotificationQueueForSquare150x150:(BOOL)enable;
- (void)enableNotificationQueueForWide310x150:(BOOL)enable;
- (void)enableNotificationQueueForSquare310x310:(BOOL)enable;
@end

#endif // __WUNTileUpdater_DEFINED__

// Windows.UI.Notifications.TileNotification
#ifndef __WUNTileNotification_DEFINED__
#define __WUNTileNotification_DEFINED__

WINRT_EXPORT
@interface WUNTileNotification : RTObject
+ (WUNTileNotification*)createTileNotification:(WDXDXmlDocument*)content ACTIVATOR;
@property (copy) NSString* tag;
@property (copy) id expirationTime;
@property (readonly) WDXDXmlDocument* content;
@end

#endif // __WUNTileNotification_DEFINED__

// Windows.UI.Notifications.ScheduledTileNotification
#ifndef __WUNScheduledTileNotification_DEFINED__
#define __WUNScheduledTileNotification_DEFINED__

WINRT_EXPORT
@interface WUNScheduledTileNotification : RTObject
+ (WUNScheduledTileNotification*)createScheduledTileNotification:(WDXDXmlDocument*)content deliveryTime:(WFDateTime*)deliveryTime ACTIVATOR;
@property (copy) NSString* tag;
@property (copy) NSString* id;
@property (copy) id expirationTime;
@property (readonly) WDXDXmlDocument* content;
@property (readonly) WFDateTime* deliveryTime;
@end

#endif // __WUNScheduledTileNotification_DEFINED__

// Windows.UI.Notifications.TileFlyoutUpdater
#ifndef __WUNTileFlyoutUpdater_DEFINED__
#define __WUNTileFlyoutUpdater_DEFINED__

WINRT_EXPORT
@interface WUNTileFlyoutUpdater : RTObject
@property (readonly) WUNNotificationSetting setting;
- (void)update:(WUNTileFlyoutNotification*)notification;
- (void)clear;
- (void)startPeriodicUpdate:(WFUri*)tileFlyoutContent requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval;
- (void)startPeriodicUpdateAtTime:(WFUri*)tileFlyoutContent
                        startTime:(WFDateTime*)startTime
                requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval;
- (void)stopPeriodicUpdate;
@end

#endif // __WUNTileFlyoutUpdater_DEFINED__

// Windows.UI.Notifications.TileFlyoutNotification
#ifndef __WUNTileFlyoutNotification_DEFINED__
#define __WUNTileFlyoutNotification_DEFINED__

WINRT_EXPORT
@interface WUNTileFlyoutNotification : RTObject
+ (WUNTileFlyoutNotification*)createTileFlyoutNotification:(WDXDXmlDocument*)content ACTIVATOR;
@property (copy) id expirationTime;
@property (readonly) WDXDXmlDocument* content;
@end

#endif // __WUNTileFlyoutNotification_DEFINED__

// Windows.UI.Notifications.BadgeUpdater
#ifndef __WUNBadgeUpdater_DEFINED__
#define __WUNBadgeUpdater_DEFINED__

WINRT_EXPORT
@interface WUNBadgeUpdater : RTObject
- (void)update:(WUNBadgeNotification*)notification;
- (void)clear;
- (void)startPeriodicUpdate:(WFUri*)badgeContent requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval;
- (void)startPeriodicUpdateAtTime:(WFUri*)badgeContent
                        startTime:(WFDateTime*)startTime
                requestedInterval:(WUNPeriodicUpdateRecurrence)requestedInterval;
- (void)stopPeriodicUpdate;
@end

#endif // __WUNBadgeUpdater_DEFINED__

// Windows.UI.Notifications.BadgeNotification
#ifndef __WUNBadgeNotification_DEFINED__
#define __WUNBadgeNotification_DEFINED__

WINRT_EXPORT
@interface WUNBadgeNotification : RTObject
+ (WUNBadgeNotification*)createBadgeNotification:(WDXDXmlDocument*)content ACTIVATOR;
@property (copy) id expirationTime;
@property (readonly) WDXDXmlDocument* content;
@end

#endif // __WUNBadgeNotification_DEFINED__

// Windows.UI.Notifications.ToastNotifier
#ifndef __WUNToastNotifier_DEFINED__
#define __WUNToastNotifier_DEFINED__

WINRT_EXPORT
@interface WUNToastNotifier : RTObject
@property (readonly) WUNNotificationSetting setting;
- (void)show:(WUNToastNotification*)notification;
- (void)hide:(WUNToastNotification*)notification;
- (void)addToSchedule:(WUNScheduledToastNotification*)scheduledToast;
- (void)removeFromSchedule:(WUNScheduledToastNotification*)scheduledToast;
- (NSArray*)getScheduledToastNotifications;
@end

#endif // __WUNToastNotifier_DEFINED__

// Windows.UI.Notifications.ToastNotification
#ifndef __WUNToastNotification_DEFINED__
#define __WUNToastNotification_DEFINED__

WINRT_EXPORT
@interface WUNToastNotification : RTObject
+ (WUNToastNotification*)createToastNotification:(WDXDXmlDocument*)content ACTIVATOR;
@property (copy) id expirationTime;
@property (readonly) WDXDXmlDocument* content;
@property (copy) NSString* tag;
@property BOOL suppressPopup;
@property (copy) NSString* group;
- (EventRegistrationToken)addActivatedEvent:(void (^)(WUNToastNotification*, RTObject*))del;
- (void)removeActivatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDismissedEvent:(void (^)(WUNToastNotification*, WUNToastDismissedEventArgs*))del;
- (void)removeDismissedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFailedEvent:(void (^)(WUNToastNotification*, WUNToastFailedEventArgs*))del;
- (void)removeFailedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUNToastNotification_DEFINED__

// Windows.UI.Notifications.ScheduledToastNotification
#ifndef __WUNScheduledToastNotification_DEFINED__
#define __WUNScheduledToastNotification_DEFINED__

WINRT_EXPORT
@interface WUNScheduledToastNotification : RTObject
+ (WUNScheduledToastNotification*)createScheduledToastNotification:(WDXDXmlDocument*)content
                                                      deliveryTime:(WFDateTime*)deliveryTime ACTIVATOR;
+ (WUNScheduledToastNotification*)createScheduledToastNotificationRecurring:(WDXDXmlDocument*)content
                                                               deliveryTime:(WFDateTime*)deliveryTime
                                                             snoozeInterval:(WFTimeSpan*)snoozeInterval
                                                         maximumSnoozeCount:(unsigned int)maximumSnoozeCount ACTIVATOR;
@property (copy) NSString* id;
@property (readonly) WDXDXmlDocument* content;
@property (readonly) WFDateTime* deliveryTime;
@property (readonly) unsigned int maximumSnoozeCount;
@property (readonly) id snoozeInterval;
@property (copy) NSString* tag;
@property BOOL suppressPopup;
@property (copy) NSString* group;
@end

#endif // __WUNScheduledToastNotification_DEFINED__

// Windows.UI.Notifications.ToastDismissedEventArgs
#ifndef __WUNToastDismissedEventArgs_DEFINED__
#define __WUNToastDismissedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUNToastDismissedEventArgs : RTObject
@property (readonly) WUNToastDismissalReason reason;
@end

#endif // __WUNToastDismissedEventArgs_DEFINED__

// Windows.UI.Notifications.ToastFailedEventArgs
#ifndef __WUNToastFailedEventArgs_DEFINED__
#define __WUNToastFailedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUNToastFailedEventArgs : RTObject
@property (readonly) HRESULT errorCode;
@end

#endif // __WUNToastFailedEventArgs_DEFINED__

// Windows.UI.Notifications.ToastNotificationHistory
#ifndef __WUNToastNotificationHistory_DEFINED__
#define __WUNToastNotificationHistory_DEFINED__

WINRT_EXPORT
@interface WUNToastNotificationHistory : RTObject
- (void)removeGroup:(NSString*)group;
- (void)removeGroupWithId:(NSString*)group applicationId:(NSString*)applicationId;
- (void)removeGroupedTagWithId:(NSString*)tag group:(NSString*)group applicationId:(NSString*)applicationId;
- (void)removeGroupedTag:(NSString*)tag group:(NSString*)group;
- (void)remove:(NSString*)tag;
- (void)clear;
- (void)clearWithId:(NSString*)applicationId;
- (NSArray*)getHistory;
- (NSArray*)getHistoryWithId:(NSString*)applicationId;
@end

#endif // __WUNToastNotificationHistory_DEFINED__

// Windows.UI.Notifications.TileUpdateManager
#ifndef __WUNTileUpdateManager_DEFINED__
#define __WUNTileUpdateManager_DEFINED__

WINRT_EXPORT
@interface WUNTileUpdateManager : RTObject
+ (WUNTileUpdater*)createTileUpdaterForApplication;
+ (WUNTileUpdater*)createTileUpdaterForApplicationWithId:(NSString*)applicationId;
+ (WUNTileUpdater*)createTileUpdaterForSecondaryTile:(NSString*)tileId;
+ (WDXDXmlDocument*)getTemplateContent:(WUNTileTemplateType)type;
@end

#endif // __WUNTileUpdateManager_DEFINED__

// Windows.UI.Notifications.BadgeUpdateManager
#ifndef __WUNBadgeUpdateManager_DEFINED__
#define __WUNBadgeUpdateManager_DEFINED__

WINRT_EXPORT
@interface WUNBadgeUpdateManager : RTObject
+ (WUNBadgeUpdater*)createBadgeUpdaterForApplication;
+ (WUNBadgeUpdater*)createBadgeUpdaterForApplicationWithId:(NSString*)applicationId;
+ (WUNBadgeUpdater*)createBadgeUpdaterForSecondaryTile:(NSString*)tileId;
+ (WDXDXmlDocument*)getTemplateContent:(WUNBadgeTemplateType)type;
@end

#endif // __WUNBadgeUpdateManager_DEFINED__

// Windows.UI.Notifications.TileFlyoutUpdateManager
#ifndef __WUNTileFlyoutUpdateManager_DEFINED__
#define __WUNTileFlyoutUpdateManager_DEFINED__

WINRT_EXPORT
@interface WUNTileFlyoutUpdateManager : RTObject
+ (WUNTileFlyoutUpdater*)createTileFlyoutUpdaterForApplication;
+ (WUNTileFlyoutUpdater*)createTileFlyoutUpdaterForApplicationWithId:(NSString*)applicationId;
+ (WUNTileFlyoutUpdater*)createTileFlyoutUpdaterForSecondaryTile:(NSString*)tileId;
+ (WDXDXmlDocument*)getTemplateContent:(WUNTileFlyoutTemplateType)type;
@end

#endif // __WUNTileFlyoutUpdateManager_DEFINED__

// Windows.UI.Notifications.ToastNotificationManager
#ifndef __WUNToastNotificationManager_DEFINED__
#define __WUNToastNotificationManager_DEFINED__

WINRT_EXPORT
@interface WUNToastNotificationManager : RTObject
+ (WUNToastNotifier*)createToastNotifier;
+ (WUNToastNotifier*)createToastNotifierWithId:(NSString*)applicationId;
+ (WDXDXmlDocument*)getTemplateContent:(WUNToastTemplateType)type;
+ (WUNToastNotificationHistory*)history;
@end

#endif // __WUNToastNotificationManager_DEFINED__

// Windows.UI.Notifications.ToastActivatedEventArgs
#ifndef __WUNToastActivatedEventArgs_DEFINED__
#define __WUNToastActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUNToastActivatedEventArgs : RTObject
@property (readonly) NSString* arguments;
@end

#endif // __WUNToastActivatedEventArgs_DEFINED__

// Windows.UI.Notifications.ToastNotificationHistoryChangedTriggerDetail
#ifndef __WUNToastNotificationHistoryChangedTriggerDetail_DEFINED__
#define __WUNToastNotificationHistoryChangedTriggerDetail_DEFINED__

WINRT_EXPORT
@interface WUNToastNotificationHistoryChangedTriggerDetail : RTObject
@property (readonly) WUNToastHistoryChangedType changeType;
@end

#endif // __WUNToastNotificationHistoryChangedTriggerDetail_DEFINED__

// Windows.UI.Notifications.ToastNotificationActionTriggerDetail
#ifndef __WUNToastNotificationActionTriggerDetail_DEFINED__
#define __WUNToastNotificationActionTriggerDetail_DEFINED__

WINRT_EXPORT
@interface WUNToastNotificationActionTriggerDetail : RTObject
@property (readonly) NSString* argument;
@property (readonly) WFCValueSet* userInput;
@end

#endif // __WUNToastNotificationActionTriggerDetail_DEFINED__
