// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.Notification.Management.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Phone::Notification::Management {

struct AccessoryManager
{
    AccessoryManager() = delete;
    static hstring RegisterAccessoryApp();
    static Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails GetNextTriggerDetails();
    static void ProcessTriggerDetails(const Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails & pDetails);
    static Windows::Foundation::Collections::IVectorView<Windows::Phone::Notification::Management::PhoneLineDetails> PhoneLineDetails();
    static Windows::Phone::Notification::Management::PhoneLineDetails GetPhoneLineDetails(GUID phoneLine);
    static void AcceptPhoneCall(uint32_t phoneCallId);
    static void AcceptPhoneCall(uint32_t phoneCallId, Windows::Phone::Notification::Management::PhoneCallAudioEndpoint endPoint);
    static void AcceptPhoneCallWithVideo(uint32_t phoneCallId);
    static void AcceptPhoneCallWithVideo(uint32_t phoneCallId, Windows::Phone::Notification::Management::PhoneCallAudioEndpoint endPoint);
    static void RejectPhoneCall(uint32_t phoneCallId);
    static void RejectPhoneCall(uint32_t phoneCallId, uint32_t textResponseID);
    static void MakePhoneCall(GUID phoneLine, hstring_view phoneNumber);
    static void MakePhoneCall(GUID phoneLine, hstring_view phoneNumber, Windows::Phone::Notification::Management::PhoneCallAudioEndpoint endPoint);
    static void MakePhoneCallWithVideo(GUID phoneLine, hstring_view phoneNumber);
    static void MakePhoneCallWithVideo(GUID phoneLine, hstring_view phoneNumber, Windows::Phone::Notification::Management::PhoneCallAudioEndpoint endPoint);
    static void SwapPhoneCalls(uint32_t phoneCallIdToHold, uint32_t phoneCallIdOnHold);
    static void HoldPhoneCall(uint32_t phoneCallId, bool holdCall);
    static void EndPhoneCall(uint32_t phoneCallId);
    static void PhoneMute(bool value);
    static bool PhoneMute();
    static void PhoneCallAudioEndpoint(Windows::Phone::Notification::Management::PhoneCallAudioEndpoint value);
    static Windows::Phone::Notification::Management::PhoneCallAudioEndpoint PhoneCallAudioEndpoint();
    static void SnoozeAlarm(GUID alarmId);
    static void SnoozeAlarm(GUID alarmId, const Windows::Foundation::TimeSpan & timeSpan);
    static void DismissAlarm(GUID alarmId);
    static void SnoozeReminder(GUID reminderId);
    static void SnoozeReminder(GUID reminderId, const Windows::Foundation::TimeSpan & timeSpan);
    static void DismissReminder(GUID reminderId);
    static Windows::Phone::Notification::Management::MediaMetadata GetMediaMetadata();
    static Windows::Phone::Notification::Management::PlaybackCapability MediaPlaybackCapabilities();
    static Windows::Phone::Notification::Management::PlaybackStatus MediaPlaybackStatus();
    static void PerformMediaPlaybackCommand(Windows::Phone::Notification::Management::PlaybackCommand command);
    static bool DoNotDisturbEnabled();
    static bool DrivingModeEnabled();
    static bool BatterySaverState();
    static Windows::Foundation::Collections::IMapView<hstring, Windows::Phone::Notification::Management::AppNotificationInfo> GetApps();
    static void EnableNotificationsForApplication(hstring_view appId);
    static void DisableNotificationsForApplication(hstring_view appId);
    static bool IsNotificationEnabledForApplication(hstring_view appId);
    static int32_t GetEnabledAccessoryNotificationTypes();
    static void EnableAccessoryNotificationTypes(int32_t accessoryNotificationTypes);
    static void DisableAllAccessoryNotificationTypes();
    static bool GetUserConsent();
    static Windows::Storage::Streams::IRandomAccessStreamReference GetAppIcon(hstring_view appId);
    static void RingDevice();
    static Windows::Foundation::Collections::IVectorView<Windows::Phone::Notification::Management::SpeedDialEntry> SpeedDialList();
    static void ClearToast(hstring_view instanceId);
    static bool IsPhonePinLocked();
    static void IncreaseVolume(int32_t step);
    static void DecreaseVolume(int32_t step);
    static void SetMute(bool mute);
    static void SetRingerVibrate(bool ringer, bool vibrate);
    static Windows::Phone::Notification::Management::VolumeInfo VolumeInfo();
    static Windows::Foundation::Collections::IVectorView<Windows::Phone::Notification::Management::EmailAccountInfo> GetAllEmailAccounts();
    static Windows::Foundation::Collections::IVectorView<Windows::Phone::Notification::Management::EmailFolderInfo> GetFolders(hstring_view emailAccount);
    static void EnableEmailNotificationEmailAccount(hstring_view emailAccount);
    static void DisableEmailNotificationEmailAccount(hstring_view emailAccount);
    static void EnableEmailNotificationFolderFilter(hstring_view emailAccount, vector_view<hstring> folders);
    static void UpdateEmailReadStatus(const Windows::Phone::Notification::Management::BinaryId & messageEntryId, bool isRead);
    static void SnoozeAlarmByInstanceId(hstring_view instanceId);
    static void DismissAlarmByInstanceId(hstring_view instanceId);
    static void SnoozeReminderByInstanceId(hstring_view instanceId);
    static void DismissReminderByInstanceId(hstring_view instanceId);
};

struct WINRT_EBO AlarmNotificationTriggerDetails :
    Windows::Phone::Notification::Management::IAlarmNotificationTriggerDetails,
    impl::require<AlarmNotificationTriggerDetails, Windows::Phone::Notification::Management::IAlarmNotificationTriggerDetails2>
{
    AlarmNotificationTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppNotificationInfo :
    Windows::Phone::Notification::Management::IAppNotificationInfo
{
    AppNotificationInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BinaryId :
    Windows::Phone::Notification::Management::IBinaryId
{
    BinaryId(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CalendarChangedNotificationTriggerDetails :
    Windows::Phone::Notification::Management::ICalendarChangedNotificationTriggerDetails
{
    CalendarChangedNotificationTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CortanaTileNotificationTriggerDetails :
    Windows::Phone::Notification::Management::ICortanaTileNotificationTriggerDetails
{
    CortanaTileNotificationTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailAccountInfo :
    Windows::Phone::Notification::Management::IEmailAccountInfo
{
    EmailAccountInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailFolderInfo :
    Windows::Phone::Notification::Management::IEmailFolderInfo
{
    EmailFolderInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailNotificationTriggerDetails :
    Windows::Phone::Notification::Management::IEmailNotificationTriggerDetails,
    impl::require<EmailNotificationTriggerDetails, Windows::Phone::Notification::Management::IEmailNotificationTriggerDetails2>
{
    EmailNotificationTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailReadNotificationTriggerDetails :
    Windows::Phone::Notification::Management::IEmailReadNotificationTriggerDetails
{
    EmailReadNotificationTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaControlsTriggerDetails :
    Windows::Phone::Notification::Management::IMediaControlsTriggerDetails
{
    MediaControlsTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaMetadata :
    Windows::Phone::Notification::Management::IMediaMetadata
{
    MediaMetadata(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhoneCallDetails :
    Windows::Phone::Notification::Management::IPhoneCallDetails
{
    PhoneCallDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhoneLineDetails :
    Windows::Phone::Notification::Management::IPhoneLineDetails,
    impl::require<PhoneLineDetails, Windows::Phone::Notification::Management::IPhoneLineDetails2>
{
    PhoneLineDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhoneNotificationTriggerDetails :
    Windows::Phone::Notification::Management::IPhoneNotificationTriggerDetails
{
    PhoneNotificationTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ReminderNotificationTriggerDetails :
    Windows::Phone::Notification::Management::IReminderNotificationTriggerDetails,
    impl::require<ReminderNotificationTriggerDetails, Windows::Phone::Notification::Management::IReminderNotificationTriggerDetails2>
{
    ReminderNotificationTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpeedDialEntry :
    Windows::Phone::Notification::Management::ISpeedDialEntry
{
    SpeedDialEntry(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TextResponse :
    Windows::Phone::Notification::Management::ITextResponse
{
    TextResponse(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ToastNotificationTriggerDetails :
    Windows::Phone::Notification::Management::IToastNotificationTriggerDetails,
    impl::require<ToastNotificationTriggerDetails, Windows::Phone::Notification::Management::IToastNotificationTriggerDetails2>
{
    ToastNotificationTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VolumeInfo :
    Windows::Phone::Notification::Management::IVolumeInfo
{
    VolumeInfo(std::nullptr_t) noexcept {}
};

}

}
