// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::Notification::Management {

struct IAccessoryManager;
struct IAccessoryManager2;
struct IAccessoryManager3;
struct IAccessoryNotificationTriggerDetails;
struct IAlarmNotificationTriggerDetails;
struct IAlarmNotificationTriggerDetails2;
struct IAppNotificationInfo;
struct IBinaryId;
struct ICalendarChangedNotificationTriggerDetails;
struct ICortanaTileNotificationTriggerDetails;
struct IEmailAccountInfo;
struct IEmailFolderInfo;
struct IEmailNotificationTriggerDetails;
struct IEmailNotificationTriggerDetails2;
struct IEmailReadNotificationTriggerDetails;
struct IMediaControlsTriggerDetails;
struct IMediaMetadata;
struct IPhoneCallDetails;
struct IPhoneLineDetails;
struct IPhoneLineDetails2;
struct IPhoneNotificationTriggerDetails;
struct IReminderNotificationTriggerDetails;
struct IReminderNotificationTriggerDetails2;
struct ISpeedDialEntry;
struct ITextResponse;
struct IToastNotificationTriggerDetails;
struct IToastNotificationTriggerDetails2;
struct IVolumeInfo;
struct AlarmNotificationTriggerDetails;
struct AppNotificationInfo;
struct BinaryId;
struct CalendarChangedNotificationTriggerDetails;
struct CortanaTileNotificationTriggerDetails;
struct EmailAccountInfo;
struct EmailFolderInfo;
struct EmailNotificationTriggerDetails;
struct EmailReadNotificationTriggerDetails;
struct MediaControlsTriggerDetails;
struct MediaMetadata;
struct PhoneCallDetails;
struct PhoneLineDetails;
struct PhoneNotificationTriggerDetails;
struct ReminderNotificationTriggerDetails;
struct SpeedDialEntry;
struct TextResponse;
struct ToastNotificationTriggerDetails;
struct VolumeInfo;

}

namespace Windows::Phone::Notification::Management {

struct IAccessoryManager;
struct IAccessoryManager2;
struct IAccessoryManager3;
struct IAccessoryNotificationTriggerDetails;
struct IAlarmNotificationTriggerDetails;
struct IAlarmNotificationTriggerDetails2;
struct IAppNotificationInfo;
struct IBinaryId;
struct ICalendarChangedNotificationTriggerDetails;
struct ICortanaTileNotificationTriggerDetails;
struct IEmailAccountInfo;
struct IEmailFolderInfo;
struct IEmailNotificationTriggerDetails;
struct IEmailNotificationTriggerDetails2;
struct IEmailReadNotificationTriggerDetails;
struct IMediaControlsTriggerDetails;
struct IMediaMetadata;
struct IPhoneCallDetails;
struct IPhoneLineDetails;
struct IPhoneLineDetails2;
struct IPhoneNotificationTriggerDetails;
struct IReminderNotificationTriggerDetails;
struct IReminderNotificationTriggerDetails2;
struct ISpeedDialEntry;
struct ITextResponse;
struct IToastNotificationTriggerDetails;
struct IToastNotificationTriggerDetails2;
struct IVolumeInfo;
struct AccessoryManager;
struct AlarmNotificationTriggerDetails;
struct AppNotificationInfo;
struct BinaryId;
struct CalendarChangedNotificationTriggerDetails;
struct CortanaTileNotificationTriggerDetails;
struct EmailAccountInfo;
struct EmailFolderInfo;
struct EmailNotificationTriggerDetails;
struct EmailReadNotificationTriggerDetails;
struct MediaControlsTriggerDetails;
struct MediaMetadata;
struct PhoneCallDetails;
struct PhoneLineDetails;
struct PhoneNotificationTriggerDetails;
struct ReminderNotificationTriggerDetails;
struct SpeedDialEntry;
struct TextResponse;
struct ToastNotificationTriggerDetails;
struct VolumeInfo;

}

namespace Windows::Phone::Notification::Management {

template <typename T> struct impl_IAccessoryManager;
template <typename T> struct impl_IAccessoryManager2;
template <typename T> struct impl_IAccessoryManager3;
template <typename T> struct impl_IAccessoryNotificationTriggerDetails;
template <typename T> struct impl_IAlarmNotificationTriggerDetails;
template <typename T> struct impl_IAlarmNotificationTriggerDetails2;
template <typename T> struct impl_IAppNotificationInfo;
template <typename T> struct impl_IBinaryId;
template <typename T> struct impl_ICalendarChangedNotificationTriggerDetails;
template <typename T> struct impl_ICortanaTileNotificationTriggerDetails;
template <typename T> struct impl_IEmailAccountInfo;
template <typename T> struct impl_IEmailFolderInfo;
template <typename T> struct impl_IEmailNotificationTriggerDetails;
template <typename T> struct impl_IEmailNotificationTriggerDetails2;
template <typename T> struct impl_IEmailReadNotificationTriggerDetails;
template <typename T> struct impl_IMediaControlsTriggerDetails;
template <typename T> struct impl_IMediaMetadata;
template <typename T> struct impl_IPhoneCallDetails;
template <typename T> struct impl_IPhoneLineDetails;
template <typename T> struct impl_IPhoneLineDetails2;
template <typename T> struct impl_IPhoneNotificationTriggerDetails;
template <typename T> struct impl_IReminderNotificationTriggerDetails;
template <typename T> struct impl_IReminderNotificationTriggerDetails2;
template <typename T> struct impl_ISpeedDialEntry;
template <typename T> struct impl_ITextResponse;
template <typename T> struct impl_IToastNotificationTriggerDetails;
template <typename T> struct impl_IToastNotificationTriggerDetails2;
template <typename T> struct impl_IVolumeInfo;

}

namespace Windows::Phone::Notification::Management {

enum class AccessoryNotificationType : unsigned
{
    None = 0x0,
    Phone = 0x1,
    Email = 0x2,
    Reminder = 0x4,
    Alarm = 0x8,
    Toast = 0x10,
    AppUninstalled = 0x20,
    Dnd = 0x40,
    DrivingMode = 0x80,
    BatterySaver = 0x100,
    Media = 0x200,
    CortanaTile = 0x400,
    ToastCleared = 0x800,
    CalendarChanged = 0x1000,
    VolumeChanged = 0x2000,
    EmailReadStatusChanged = 0x4000,
};

DEFINE_ENUM_FLAG_OPERATORS(AccessoryNotificationType)

enum class CalendarChangedEvent
{
    LostEvents = 0,
    AppointmentAdded = 1,
    AppointmentChanged = 2,
    AppointmentDeleted = 3,
    CalendarAdded = 4,
    CalendarChanged = 5,
    CalendarDeleted = 6,
};

enum class PhoneCallAudioEndpoint
{
    Default = 0,
    Speaker = 1,
    Handsfree = 2,
};

enum class PhoneCallDirection
{
    Incoming = 0,
    Outgoing = 1,
};

enum class PhoneCallState
{
    Unknown = 0,
    Ringing = 1,
    Talking = 2,
    Held = 3,
    Ended = 4,
};

enum class PhoneCallTransport
{
    Cellular = 0,
    Voip = 1,
};

enum class PhoneLineRegistrationState
{
    Disconnected = 0,
    Home = 1,
    Roaming = 2,
};

enum class PhoneMediaType
{
    AudioOnly = 0,
    AudioVideo = 1,
};

enum class PhoneNotificationType
{
    NewCall = 0,
    CallChanged = 1,
    LineChanged = 2,
    PhoneCallAudioEndpointChanged = 3,
    PhoneMuteChanged = 4,
};

enum class PlaybackCapability : unsigned
{
    None = 0x0,
    Play = 0x1,
    Pause = 0x2,
    Stop = 0x4,
    Record = 0x8,
    FastForward = 0x10,
    Rewind = 0x20,
    Next = 0x40,
    Previous = 0x80,
    ChannelUp = 0x100,
    ChannelDown = 0x200,
};

DEFINE_ENUM_FLAG_OPERATORS(PlaybackCapability)

enum class PlaybackCommand
{
    Play = 0,
    Pause = 1,
    Stop = 2,
    Record = 3,
    FastForward = 4,
    Rewind = 5,
    Next = 6,
    Previous = 7,
    ChannelUp = 8,
    ChannelDown = 9,
};

enum class PlaybackStatus
{
    None = 0,
    TrackChanged = 1,
    Stopped = 2,
    Playing = 3,
    Paused = 4,
};

enum class ReminderState
{
    Active = 0,
    Snoozed = 1,
    Dismissed = 2,
};

enum class VibrateState
{
    RingerOffVibrateOff = 0,
    RingerOffVibrateOn = 1,
    RingerOnVibrateOff = 2,
    RingerOnVibrateOn = 3,
};

}

}
