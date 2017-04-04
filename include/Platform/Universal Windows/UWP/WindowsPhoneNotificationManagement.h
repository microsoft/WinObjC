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

// WindowsPhoneNotificationManagement.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
#define OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsPhoneNotificationManagement.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPNMTextResponse, WPNMAppNotificationInfo, WPNMEmailAccountInfo, WPNMEmailFolderInfo, WPNMBinaryId, WPNMAlarmNotificationTriggerDetails, WPNMEmailReadNotificationTriggerDetails, WPNMEmailNotificationTriggerDetails, WPNMPhoneLineDetails, WPNMPhoneCallDetails, WPNMPhoneNotificationTriggerDetails, WPNMSpeedDialEntry, WPNMReminderNotificationTriggerDetails, WPNMCalendarChangedNotificationTriggerDetails, WPNMToastNotificationTriggerDetails, WPNMCortanaTileNotificationTriggerDetails, WPNMMediaMetadata, WPNMMediaControlsTriggerDetails, WPNMVolumeInfo, WPNMAccessoryManager;
@protocol WPNMITextResponse, WPNMIAppNotificationInfo, WPNMIEmailAccountInfo, WPNMIEmailFolderInfo, WPNMIBinaryId, WPNMIAccessoryNotificationTriggerDetails, WPNMIAlarmNotificationTriggerDetails, WPNMIAlarmNotificationTriggerDetails2, WPNMIEmailNotificationTriggerDetails, WPNMIEmailNotificationTriggerDetails2, WPNMIEmailReadNotificationTriggerDetails, WPNMIPhoneLineDetails, WPNMIPhoneLineDetails2, WPNMIPhoneCallDetails, WPNMIPhoneNotificationTriggerDetails, WPNMISpeedDialEntry, WPNMIReminderNotificationTriggerDetails, WPNMIReminderNotificationTriggerDetails2, WPNMICalendarChangedNotificationTriggerDetails, WPNMIToastNotificationTriggerDetails, WPNMIToastNotificationTriggerDetails2, WPNMICortanaTileNotificationTriggerDetails, WPNMIMediaMetadata, WPNMIMediaControlsTriggerDetails, WPNMIVolumeInfo, WPNMIAccessoryManager, WPNMIAccessoryManager2, WPNMIAccessoryManager3;

// Windows.Phone.Notification.Management.AccessoryNotificationType
enum _WPNMAccessoryNotificationType {
    WPNMAccessoryNotificationTypeNone = 0,
    WPNMAccessoryNotificationTypePhone = 1,
    WPNMAccessoryNotificationTypeEmail = 2,
    WPNMAccessoryNotificationTypeReminder = 4,
    WPNMAccessoryNotificationTypeAlarm = 8,
    WPNMAccessoryNotificationTypeToast = 16,
    WPNMAccessoryNotificationTypeAppUninstalled = 32,
    WPNMAccessoryNotificationTypeDnd = 64,
    WPNMAccessoryNotificationTypeDrivingMode = 128,
    WPNMAccessoryNotificationTypeBatterySaver = 256,
    WPNMAccessoryNotificationTypeMedia = 512,
    WPNMAccessoryNotificationTypeCortanaTile = 1024,
    WPNMAccessoryNotificationTypeToastCleared = 2048,
    WPNMAccessoryNotificationTypeCalendarChanged = 4096,
    WPNMAccessoryNotificationTypeVolumeChanged = 8192,
    WPNMAccessoryNotificationTypeEmailReadStatusChanged = 16384,
};
typedef unsigned WPNMAccessoryNotificationType;

// Windows.Phone.Notification.Management.ReminderState
enum _WPNMReminderState {
    WPNMReminderStateActive = 0,
    WPNMReminderStateSnoozed = 1,
    WPNMReminderStateDismissed = 2,
};
typedef unsigned WPNMReminderState;

// Windows.Phone.Notification.Management.PhoneNotificationType
enum _WPNMPhoneNotificationType {
    WPNMPhoneNotificationTypeNewCall = 0,
    WPNMPhoneNotificationTypeCallChanged = 1,
    WPNMPhoneNotificationTypeLineChanged = 2,
    WPNMPhoneNotificationTypePhoneCallAudioEndpointChanged = 3,
    WPNMPhoneNotificationTypePhoneMuteChanged = 4,
};
typedef unsigned WPNMPhoneNotificationType;

// Windows.Phone.Notification.Management.PhoneCallTransport
enum _WPNMPhoneCallTransport {
    WPNMPhoneCallTransportCellular = 0,
    WPNMPhoneCallTransportVoip = 1,
};
typedef unsigned WPNMPhoneCallTransport;

// Windows.Phone.Notification.Management.PhoneMediaType
enum _WPNMPhoneMediaType {
    WPNMPhoneMediaTypeAudioOnly = 0,
    WPNMPhoneMediaTypeAudioVideo = 1,
};
typedef unsigned WPNMPhoneMediaType;

// Windows.Phone.Notification.Management.PhoneCallDirection
enum _WPNMPhoneCallDirection {
    WPNMPhoneCallDirectionIncoming = 0,
    WPNMPhoneCallDirectionOutgoing = 1,
};
typedef unsigned WPNMPhoneCallDirection;

// Windows.Phone.Notification.Management.PhoneCallState
enum _WPNMPhoneCallState {
    WPNMPhoneCallStateUnknown = 0,
    WPNMPhoneCallStateRinging = 1,
    WPNMPhoneCallStateTalking = 2,
    WPNMPhoneCallStateHeld = 3,
    WPNMPhoneCallStateEnded = 4,
};
typedef unsigned WPNMPhoneCallState;

// Windows.Phone.Notification.Management.PhoneCallAudioEndpoint
enum _WPNMPhoneCallAudioEndpoint {
    WPNMPhoneCallAudioEndpointDefault = 0,
    WPNMPhoneCallAudioEndpointSpeaker = 1,
    WPNMPhoneCallAudioEndpointHandsfree = 2,
};
typedef unsigned WPNMPhoneCallAudioEndpoint;

// Windows.Phone.Notification.Management.PhoneLineRegistrationState
enum _WPNMPhoneLineRegistrationState {
    WPNMPhoneLineRegistrationStateDisconnected = 0,
    WPNMPhoneLineRegistrationStateHome = 1,
    WPNMPhoneLineRegistrationStateRoaming = 2,
};
typedef unsigned WPNMPhoneLineRegistrationState;

// Windows.Phone.Notification.Management.CalendarChangedEvent
enum _WPNMCalendarChangedEvent {
    WPNMCalendarChangedEventLostEvents = 0,
    WPNMCalendarChangedEventAppointmentAdded = 1,
    WPNMCalendarChangedEventAppointmentChanged = 2,
    WPNMCalendarChangedEventAppointmentDeleted = 3,
    WPNMCalendarChangedEventCalendarAdded = 4,
    WPNMCalendarChangedEventCalendarChanged = 5,
    WPNMCalendarChangedEventCalendarDeleted = 6,
};
typedef unsigned WPNMCalendarChangedEvent;

// Windows.Phone.Notification.Management.PlaybackStatus
enum _WPNMPlaybackStatus {
    WPNMPlaybackStatusNone = 0,
    WPNMPlaybackStatusTrackChanged = 1,
    WPNMPlaybackStatusStopped = 2,
    WPNMPlaybackStatusPlaying = 3,
    WPNMPlaybackStatusPaused = 4,
};
typedef unsigned WPNMPlaybackStatus;

// Windows.Phone.Notification.Management.PlaybackCapability
enum _WPNMPlaybackCapability {
    WPNMPlaybackCapabilityNone = 0,
    WPNMPlaybackCapabilityPlay = 1,
    WPNMPlaybackCapabilityPause = 2,
    WPNMPlaybackCapabilityStop = 4,
    WPNMPlaybackCapabilityRecord = 8,
    WPNMPlaybackCapabilityFastForward = 16,
    WPNMPlaybackCapabilityRewind = 32,
    WPNMPlaybackCapabilityNext = 64,
    WPNMPlaybackCapabilityPrevious = 128,
    WPNMPlaybackCapabilityChannelUp = 256,
    WPNMPlaybackCapabilityChannelDown = 512,
};
typedef unsigned WPNMPlaybackCapability;

// Windows.Phone.Notification.Management.PlaybackCommand
enum _WPNMPlaybackCommand {
    WPNMPlaybackCommandPlay = 0,
    WPNMPlaybackCommandPause = 1,
    WPNMPlaybackCommandStop = 2,
    WPNMPlaybackCommandRecord = 3,
    WPNMPlaybackCommandFastForward = 4,
    WPNMPlaybackCommandRewind = 5,
    WPNMPlaybackCommandNext = 6,
    WPNMPlaybackCommandPrevious = 7,
    WPNMPlaybackCommandChannelUp = 8,
    WPNMPlaybackCommandChannelDown = 9,
};
typedef unsigned WPNMPlaybackCommand;

// Windows.Phone.Notification.Management.VibrateState
enum _WPNMVibrateState {
    WPNMVibrateStateRingerOffVibrateOff = 0,
    WPNMVibrateStateRingerOffVibrateOn = 1,
    WPNMVibrateStateRingerOnVibrateOff = 2,
    WPNMVibrateStateRingerOnVibrateOn = 3,
};
typedef unsigned WPNMVibrateState;

#include "WindowsFoundation.h"
#include "WindowsApplicationModelAppointments.h"
#include "WindowsApplicationModelEmail.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.Phone.Notification.Management.IAccessoryNotificationTriggerDetails
#ifndef __WPNMIAccessoryNotificationTriggerDetails_DEFINED__
#define __WPNMIAccessoryNotificationTriggerDetails_DEFINED__

@protocol WPNMIAccessoryNotificationTriggerDetails
@property (readonly) WPNMAccessoryNotificationType accessoryNotificationType;
@property (readonly) NSString * appDisplayName;
@property (readonly) NSString * appId;
@property BOOL startedProcessing;
@property (readonly) WFDateTime* timeCreated;
@end

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMIAccessoryNotificationTriggerDetails : RTObject <WPNMIAccessoryNotificationTriggerDetails>
@end

#endif // __WPNMIAccessoryNotificationTriggerDetails_DEFINED__

// Windows.Phone.Notification.Management.TextResponse
#ifndef __WPNMTextResponse_DEFINED__
#define __WPNMTextResponse_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMTextResponse : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * content;
@property (readonly) unsigned int id;
@end

#endif // __WPNMTextResponse_DEFINED__

// Windows.Phone.Notification.Management.AppNotificationInfo
#ifndef __WPNMAppNotificationInfo_DEFINED__
#define __WPNMAppNotificationInfo_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMAppNotificationInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * id;
@property (readonly) NSString * name;
@end

#endif // __WPNMAppNotificationInfo_DEFINED__

// Windows.Phone.Notification.Management.EmailAccountInfo
#ifndef __WPNMEmailAccountInfo_DEFINED__
#define __WPNMEmailAccountInfo_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMEmailAccountInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayName;
@property (readonly) BOOL isNotificationEnabled;
@end

#endif // __WPNMEmailAccountInfo_DEFINED__

// Windows.Phone.Notification.Management.EmailFolderInfo
#ifndef __WPNMEmailFolderInfo_DEFINED__
#define __WPNMEmailFolderInfo_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMEmailFolderInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayName;
@property (readonly) BOOL isNotificationEnabled;
@end

#endif // __WPNMEmailFolderInfo_DEFINED__

// Windows.Phone.Notification.Management.BinaryId
#ifndef __WPNMBinaryId_DEFINED__
#define __WPNMBinaryId_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMBinaryId : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint8_t id;
@property (readonly) unsigned int length;
@end

#endif // __WPNMBinaryId_DEFINED__

// Windows.Phone.Notification.Management.AlarmNotificationTriggerDetails
#ifndef __WPNMAlarmNotificationTriggerDetails_DEFINED__
#define __WPNMAlarmNotificationTriggerDetails_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMAlarmNotificationTriggerDetails : RTObject <WPNMIAccessoryNotificationTriggerDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL startedProcessing;
@property (readonly) WPNMAccessoryNotificationType accessoryNotificationType;
@property (readonly) NSString * appDisplayName;
@property (readonly) NSString * appId;
@property (readonly) WFDateTime* timeCreated;
@property (readonly) WFGUID* alarmId;
@property (readonly) WPNMReminderState reminderState;
@property (readonly) WFDateTime* timestamp;
@property (readonly) NSString * title;
@property (readonly) NSString * instanceId;
@end

#endif // __WPNMAlarmNotificationTriggerDetails_DEFINED__

// Windows.Phone.Notification.Management.EmailReadNotificationTriggerDetails
#ifndef __WPNMEmailReadNotificationTriggerDetails_DEFINED__
#define __WPNMEmailReadNotificationTriggerDetails_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMEmailReadNotificationTriggerDetails : RTObject <WPNMIAccessoryNotificationTriggerDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL startedProcessing;
@property (readonly) WPNMAccessoryNotificationType accessoryNotificationType;
@property (readonly) NSString * appDisplayName;
@property (readonly) NSString * appId;
@property (readonly) WFDateTime* timeCreated;
@property (readonly) NSString * accountName;
@property (readonly) BOOL isRead;
@property (readonly) WPNMBinaryId* messageEntryId;
@property (readonly) NSString * parentFolderName;
@end

#endif // __WPNMEmailReadNotificationTriggerDetails_DEFINED__

// Windows.Phone.Notification.Management.EmailNotificationTriggerDetails
#ifndef __WPNMEmailNotificationTriggerDetails_DEFINED__
#define __WPNMEmailNotificationTriggerDetails_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMEmailNotificationTriggerDetails : RTObject <WPNMIAccessoryNotificationTriggerDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL startedProcessing;
@property (readonly) WPNMAccessoryNotificationType accessoryNotificationType;
@property (readonly) NSString * appDisplayName;
@property (readonly) NSString * appId;
@property (readonly) WFDateTime* timeCreated;
@property (readonly) NSString * accountName;
@property (readonly) WAEEmailMessage* emailMessage;
@property (readonly) NSString * parentFolderName;
@property (readonly) NSString * senderAddress;
@property (readonly) NSString * senderName;
@property (readonly) WFDateTime* timestamp;
@property (readonly) WPNMBinaryId* messageEntryId;
@end

#endif // __WPNMEmailNotificationTriggerDetails_DEFINED__

// Windows.Phone.Notification.Management.PhoneLineDetails
#ifndef __WPNMPhoneLineDetails_DEFINED__
#define __WPNMPhoneLineDetails_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMPhoneLineDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL defaultOutgoingLine;
@property (readonly) NSString * displayName;
@property (readonly) WFGUID* lineId;
@property (readonly) NSString * lineNumber;
@property (readonly) WPNMPhoneLineRegistrationState registrationState;
@property (readonly) unsigned int voicemailCount;
@property (readonly) unsigned int missedCallCount;
@end

#endif // __WPNMPhoneLineDetails_DEFINED__

// Windows.Phone.Notification.Management.PhoneCallDetails
#ifndef __WPNMPhoneCallDetails_DEFINED__
#define __WPNMPhoneCallDetails_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMPhoneCallDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WPNMPhoneCallDirection callDirection;
@property (readonly) unsigned int callId;
@property (readonly) WPNMPhoneMediaType callMediaType;
@property (readonly) WPNMPhoneCallTransport callTransport;
@property (readonly) unsigned int conferenceCallId;
@property (readonly) NSString * contactName;
@property (readonly) WFDateTime* endTime;
@property (readonly) WFGUID* phoneLine;
@property (readonly) NSString * phoneNumber;
@property (readonly) NSArray* /* WPNMTextResponse* */ presetTextResponses;
@property (readonly) WFDateTime* startTime;
@property (readonly) WPNMPhoneCallState state;
@end

#endif // __WPNMPhoneCallDetails_DEFINED__

// Windows.Phone.Notification.Management.PhoneNotificationTriggerDetails
#ifndef __WPNMPhoneNotificationTriggerDetails_DEFINED__
#define __WPNMPhoneNotificationTriggerDetails_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMPhoneNotificationTriggerDetails : RTObject <WPNMIAccessoryNotificationTriggerDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL startedProcessing;
@property (readonly) WPNMAccessoryNotificationType accessoryNotificationType;
@property (readonly) NSString * appDisplayName;
@property (readonly) NSString * appId;
@property (readonly) WFDateTime* timeCreated;
@property (readonly) WPNMPhoneCallDetails* callDetails;
@property (readonly) WFGUID* phoneLineChangedId;
@property (readonly) WPNMPhoneNotificationType phoneNotificationType;
@end

#endif // __WPNMPhoneNotificationTriggerDetails_DEFINED__

// Windows.Phone.Notification.Management.SpeedDialEntry
#ifndef __WPNMSpeedDialEntry_DEFINED__
#define __WPNMSpeedDialEntry_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMSpeedDialEntry : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * contactName;
@property (readonly) NSString * numberType;
@property (readonly) NSString * phoneNumber;
@end

#endif // __WPNMSpeedDialEntry_DEFINED__

// Windows.Phone.Notification.Management.ReminderNotificationTriggerDetails
#ifndef __WPNMReminderNotificationTriggerDetails_DEFINED__
#define __WPNMReminderNotificationTriggerDetails_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMReminderNotificationTriggerDetails : RTObject <WPNMIAccessoryNotificationTriggerDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL startedProcessing;
@property (readonly) WPNMAccessoryNotificationType accessoryNotificationType;
@property (readonly) NSString * appDisplayName;
@property (readonly) NSString * appId;
@property (readonly) WFDateTime* timeCreated;
@property (readonly) WAAAppointment* appointment;
@property (readonly) NSString * Description;
@property (readonly) NSString * details;
@property (readonly) WFGUID* reminderId;
@property (readonly) WPNMReminderState reminderState;
@property (readonly) WFDateTime* timestamp;
@property (readonly) NSString * title;
@property (readonly) NSString * instanceId;
@end

#endif // __WPNMReminderNotificationTriggerDetails_DEFINED__

// Windows.Phone.Notification.Management.CalendarChangedNotificationTriggerDetails
#ifndef __WPNMCalendarChangedNotificationTriggerDetails_DEFINED__
#define __WPNMCalendarChangedNotificationTriggerDetails_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMCalendarChangedNotificationTriggerDetails : RTObject <WPNMIAccessoryNotificationTriggerDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL startedProcessing;
@property (readonly) WPNMAccessoryNotificationType accessoryNotificationType;
@property (readonly) NSString * appDisplayName;
@property (readonly) NSString * appId;
@property (readonly) WFDateTime* timeCreated;
@property (readonly) WPNMCalendarChangedEvent eventType;
@property (readonly) NSString * itemId;
@end

#endif // __WPNMCalendarChangedNotificationTriggerDetails_DEFINED__

// Windows.Phone.Notification.Management.ToastNotificationTriggerDetails
#ifndef __WPNMToastNotificationTriggerDetails_DEFINED__
#define __WPNMToastNotificationTriggerDetails_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMToastNotificationTriggerDetails : RTObject <WPNMIAccessoryNotificationTriggerDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL startedProcessing;
@property (readonly) WPNMAccessoryNotificationType accessoryNotificationType;
@property (readonly) NSString * appDisplayName;
@property (readonly) NSString * appId;
@property (readonly) WFDateTime* timeCreated;
@property (readonly) BOOL suppressPopup;
@property (readonly) NSString * text1;
@property (readonly) NSString * text2;
@property (readonly) NSString * text3;
@property (readonly) NSString * text4;
@property (readonly) NSString * instanceId;
@end

#endif // __WPNMToastNotificationTriggerDetails_DEFINED__

// Windows.Phone.Notification.Management.CortanaTileNotificationTriggerDetails
#ifndef __WPNMCortanaTileNotificationTriggerDetails_DEFINED__
#define __WPNMCortanaTileNotificationTriggerDetails_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMCortanaTileNotificationTriggerDetails : RTObject <WPNMIAccessoryNotificationTriggerDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL startedProcessing;
@property (readonly) WPNMAccessoryNotificationType accessoryNotificationType;
@property (readonly) NSString * appDisplayName;
@property (readonly) NSString * appId;
@property (readonly) WFDateTime* timeCreated;
@property (readonly) NSString * content;
@property (readonly) NSString * emphasizedText;
@property (readonly) NSString * largeContent1;
@property (readonly) NSString * largeContent2;
@property (readonly) NSString * nonWrappedSmallContent1;
@property (readonly) NSString * nonWrappedSmallContent2;
@property (readonly) NSString * nonWrappedSmallContent3;
@property (readonly) NSString * nonWrappedSmallContent4;
@property (readonly) NSString * source;
@property (readonly) NSString * tileId;
@end

#endif // __WPNMCortanaTileNotificationTriggerDetails_DEFINED__

// Windows.Phone.Notification.Management.MediaMetadata
#ifndef __WPNMMediaMetadata_DEFINED__
#define __WPNMMediaMetadata_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMMediaMetadata : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * album;
@property (readonly) NSString * artist;
@property (readonly) WFTimeSpan* duration;
@property (readonly) NSString * subtitle;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* thumbnail;
@property (readonly) NSString * title;
@property (readonly) unsigned int track;
@end

#endif // __WPNMMediaMetadata_DEFINED__

// Windows.Phone.Notification.Management.MediaControlsTriggerDetails
#ifndef __WPNMMediaControlsTriggerDetails_DEFINED__
#define __WPNMMediaControlsTriggerDetails_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMMediaControlsTriggerDetails : RTObject <WPNMIAccessoryNotificationTriggerDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL startedProcessing;
@property (readonly) WPNMAccessoryNotificationType accessoryNotificationType;
@property (readonly) NSString * appDisplayName;
@property (readonly) NSString * appId;
@property (readonly) WFDateTime* timeCreated;
@property (readonly) WPNMMediaMetadata* mediaMetadata;
@property (readonly) WPNMPlaybackStatus playbackStatus;
@end

#endif // __WPNMMediaControlsTriggerDetails_DEFINED__

// Windows.Phone.Notification.Management.VolumeInfo
#ifndef __WPNMVolumeInfo_DEFINED__
#define __WPNMVolumeInfo_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMVolumeInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int callVolume;
@property (readonly) BOOL isMuted;
@property (readonly) WPNMVibrateState isVibrateEnabled;
@property (readonly) unsigned int mediaVolume;
@property (readonly) unsigned int systemVolume;
@end

#endif // __WPNMVolumeInfo_DEFINED__

// Windows.Phone.Notification.Management.AccessoryManager
#ifndef __WPNMAccessoryManager_DEFINED__
#define __WPNMAccessoryManager_DEFINED__

OBJCUWPWINDOWSPHONENOTIFICATIONMANAGEMENTEXPORT
@interface WPNMAccessoryManager : RTObject
+ (void)ringDevice;
+ (void)clearToast:(NSString *)instanceId;
+ (void)increaseVolume:(int)step;
+ (void)decreaseVolume:(int)step;
+ (void)setMute:(BOOL)mute;
+ (void)setRingerVibrate:(BOOL)ringer vibrate:(BOOL)vibrate;
+ (NSArray* /* WPNMEmailAccountInfo* */)getAllEmailAccounts;
+ (NSArray* /* WPNMEmailFolderInfo* */)getFolders:(NSString *)emailAccount;
+ (void)enableEmailNotificationEmailAccount:(NSString *)emailAccount;
+ (void)disableEmailNotificationEmailAccount:(NSString *)emailAccount;
+ (void)enableEmailNotificationFolderFilter:(NSString *)emailAccount folders:(NSArray* /* NSString * */)folders;
+ (void)updateEmailReadStatus:(WPNMBinaryId*)messageEntryId isRead:(BOOL)isRead;
+ (void)snoozeAlarmByInstanceId:(NSString *)instanceId;
+ (void)dismissAlarmByInstanceId:(NSString *)instanceId;
+ (void)snoozeReminderByInstanceId:(NSString *)instanceId;
+ (void)dismissReminderByInstanceId:(NSString *)instanceId;
+ (NSString *)registerAccessoryApp;
+ (RTObject<WPNMIAccessoryNotificationTriggerDetails>*)getNextTriggerDetails;
+ (void)processTriggerDetails:(RTObject<WPNMIAccessoryNotificationTriggerDetails>*)pDetails;
+ (WPNMPhoneLineDetails*)getPhoneLineDetails:(WFGUID*)phoneLine;
+ (void)acceptPhoneCall:(unsigned int)phoneCallId;
+ (void)acceptPhoneCallOnEndpoint:(unsigned int)phoneCallId endPoint:(WPNMPhoneCallAudioEndpoint)endPoint;
+ (void)acceptPhoneCallWithVideo:(unsigned int)phoneCallId;
+ (void)acceptPhoneCallWithVideoOnAudioEndpoint:(unsigned int)phoneCallId endPoint:(WPNMPhoneCallAudioEndpoint)endPoint;
+ (void)rejectPhoneCall:(unsigned int)phoneCallId;
+ (void)rejectPhoneCallWithText:(unsigned int)phoneCallId textResponseID:(unsigned int)textResponseID;
+ (void)makePhoneCall:(WFGUID*)phoneLine phoneNumber:(NSString *)phoneNumber;
+ (void)makePhoneCallOnAudioEndpoint:(WFGUID*)phoneLine phoneNumber:(NSString *)phoneNumber endPoint:(WPNMPhoneCallAudioEndpoint)endPoint;
+ (void)makePhoneCallWithVideo:(WFGUID*)phoneLine phoneNumber:(NSString *)phoneNumber;
+ (void)makePhoneCallWithVideoOnAudioEndpoint:(WFGUID*)phoneLine phoneNumber:(NSString *)phoneNumber endPoint:(WPNMPhoneCallAudioEndpoint)endPoint;
+ (void)swapPhoneCalls:(unsigned int)phoneCallIdToHold phoneCallIdOnHold:(unsigned int)phoneCallIdOnHold;
+ (void)holdPhoneCall:(unsigned int)phoneCallId holdCall:(BOOL)holdCall;
+ (void)endPhoneCall:(unsigned int)phoneCallId;
+ (void)snoozeAlarm:(WFGUID*)alarmId;
+ (void)snoozeAlarmForSpecifiedTime:(WFGUID*)alarmId timeSpan:(WFTimeSpan*)timeSpan;
+ (void)dismissAlarm:(WFGUID*)alarmId;
+ (void)snoozeReminder:(WFGUID*)reminderId;
+ (void)snoozeReminderForSpecifiedTime:(WFGUID*)reminderId timeSpan:(WFTimeSpan*)timeSpan;
+ (void)dismissReminder:(WFGUID*)reminderId;
+ (WPNMMediaMetadata*)getMediaMetadata;
+ (void)performMediaPlaybackCommand:(WPNMPlaybackCommand)command;
+ (NSDictionary* /* NSString *, WPNMAppNotificationInfo* */)getApps;
+ (void)enableNotificationsForApplication:(NSString *)appId;
+ (void)disableNotificationsForApplication:(NSString *)appId;
+ (BOOL)isNotificationEnabledForApplication:(NSString *)appId;
+ (int)getEnabledAccessoryNotificationTypes;
+ (void)enableAccessoryNotificationTypes:(int)accessoryNotificationTypes;
+ (void)disableAllAccessoryNotificationTypes;
+ (BOOL)getUserConsent;
+ (RTObject<WSSIRandomAccessStreamReference>*)getAppIcon:(NSString *)appId;
+ (BOOL)phoneMute;
+ (void)setPhoneMute:(BOOL)value;
+ (WPNMPhoneCallAudioEndpoint)phoneCallAudioEndpoint;
+ (void)setPhoneCallAudioEndpoint:(WPNMPhoneCallAudioEndpoint)value;
+ (BOOL)batterySaverState;
+ (BOOL)doNotDisturbEnabled;
+ (BOOL)drivingModeEnabled;
+ (WPNMPlaybackCapability)mediaPlaybackCapabilities;
+ (WPNMPlaybackStatus)mediaPlaybackStatus;
+ (NSArray* /* WPNMPhoneLineDetails* */)phoneLineDetails;
+ (BOOL)isPhonePinLocked;
+ (NSArray* /* WPNMSpeedDialEntry* */)speedDialList;
+ (WPNMVolumeInfo*)volumeInfo;
@end

#endif // __WPNMAccessoryManager_DEFINED__

