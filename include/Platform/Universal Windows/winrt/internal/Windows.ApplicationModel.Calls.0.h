// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Calls {

struct ICallAnswerEventArgs;
struct ICallRejectEventArgs;
struct ICallStateChangeEventArgs;
struct ILockScreenCallEndCallDeferral;
struct ILockScreenCallEndRequestedEventArgs;
struct ILockScreenCallUI;
struct IMuteChangeEventArgs;
struct IPhoneCallBlockingStatics;
struct IPhoneCallHistoryEntry;
struct IPhoneCallHistoryEntryAddress;
struct IPhoneCallHistoryEntryAddressFactory;
struct IPhoneCallHistoryEntryQueryOptions;
struct IPhoneCallHistoryEntryReader;
struct IPhoneCallHistoryManagerForUser;
struct IPhoneCallHistoryManagerStatics;
struct IPhoneCallHistoryManagerStatics2;
struct IPhoneCallHistoryStore;
struct IPhoneCallManagerStatics;
struct IPhoneCallManagerStatics2;
struct IPhoneCallStore;
struct IPhoneCallVideoCapabilities;
struct IPhoneCallVideoCapabilitiesManagerStatics;
struct IPhoneDialOptions;
struct IPhoneLine;
struct IPhoneLineCellularDetails;
struct IPhoneLineConfiguration;
struct IPhoneLineStatics;
struct IPhoneLineWatcher;
struct IPhoneLineWatcherEventArgs;
struct IPhoneVoicemail;
struct IVoipCallCoordinator;
struct IVoipCallCoordinatorStatics;
struct IVoipPhoneCall;
struct CallAnswerEventArgs;
struct CallRejectEventArgs;
struct CallStateChangeEventArgs;
struct LockScreenCallEndCallDeferral;
struct LockScreenCallEndRequestedEventArgs;
struct LockScreenCallUI;
struct MuteChangeEventArgs;
struct PhoneCallHistoryEntry;
struct PhoneCallHistoryEntryAddress;
struct PhoneCallHistoryEntryQueryOptions;
struct PhoneCallHistoryEntryReader;
struct PhoneCallHistoryManagerForUser;
struct PhoneCallHistoryStore;
struct PhoneCallStore;
struct PhoneCallVideoCapabilities;
struct PhoneDialOptions;
struct PhoneLine;
struct PhoneLineCellularDetails;
struct PhoneLineConfiguration;
struct PhoneLineWatcher;
struct PhoneLineWatcherEventArgs;
struct PhoneVoicemail;
struct VoipCallCoordinator;
struct VoipPhoneCall;

}

namespace Windows::ApplicationModel::Calls {

struct ICallAnswerEventArgs;
struct ICallRejectEventArgs;
struct ICallStateChangeEventArgs;
struct ILockScreenCallEndCallDeferral;
struct ILockScreenCallEndRequestedEventArgs;
struct ILockScreenCallUI;
struct IMuteChangeEventArgs;
struct IPhoneCallBlockingStatics;
struct IPhoneCallHistoryEntry;
struct IPhoneCallHistoryEntryAddress;
struct IPhoneCallHistoryEntryAddressFactory;
struct IPhoneCallHistoryEntryQueryOptions;
struct IPhoneCallHistoryEntryReader;
struct IPhoneCallHistoryManagerForUser;
struct IPhoneCallHistoryManagerStatics;
struct IPhoneCallHistoryManagerStatics2;
struct IPhoneCallHistoryStore;
struct IPhoneCallManagerStatics;
struct IPhoneCallManagerStatics2;
struct IPhoneCallStore;
struct IPhoneCallVideoCapabilities;
struct IPhoneCallVideoCapabilitiesManagerStatics;
struct IPhoneDialOptions;
struct IPhoneLine;
struct IPhoneLineCellularDetails;
struct IPhoneLineConfiguration;
struct IPhoneLineStatics;
struct IPhoneLineWatcher;
struct IPhoneLineWatcherEventArgs;
struct IPhoneVoicemail;
struct IVoipCallCoordinator;
struct IVoipCallCoordinatorStatics;
struct IVoipPhoneCall;
struct CallAnswerEventArgs;
struct CallRejectEventArgs;
struct CallStateChangeEventArgs;
struct LockScreenCallEndCallDeferral;
struct LockScreenCallEndRequestedEventArgs;
struct LockScreenCallUI;
struct MuteChangeEventArgs;
struct PhoneCallBlocking;
struct PhoneCallHistoryEntry;
struct PhoneCallHistoryEntryAddress;
struct PhoneCallHistoryEntryQueryOptions;
struct PhoneCallHistoryEntryReader;
struct PhoneCallHistoryManager;
struct PhoneCallHistoryManagerForUser;
struct PhoneCallHistoryStore;
struct PhoneCallManager;
struct PhoneCallStore;
struct PhoneCallVideoCapabilities;
struct PhoneCallVideoCapabilitiesManager;
struct PhoneDialOptions;
struct PhoneLine;
struct PhoneLineCellularDetails;
struct PhoneLineConfiguration;
struct PhoneLineWatcher;
struct PhoneLineWatcherEventArgs;
struct PhoneVoicemail;
struct VoipCallCoordinator;
struct VoipPhoneCall;

}

namespace Windows::ApplicationModel::Calls {

template <typename T> struct impl_ICallAnswerEventArgs;
template <typename T> struct impl_ICallRejectEventArgs;
template <typename T> struct impl_ICallStateChangeEventArgs;
template <typename T> struct impl_ILockScreenCallEndCallDeferral;
template <typename T> struct impl_ILockScreenCallEndRequestedEventArgs;
template <typename T> struct impl_ILockScreenCallUI;
template <typename T> struct impl_IMuteChangeEventArgs;
template <typename T> struct impl_IPhoneCallBlockingStatics;
template <typename T> struct impl_IPhoneCallHistoryEntry;
template <typename T> struct impl_IPhoneCallHistoryEntryAddress;
template <typename T> struct impl_IPhoneCallHistoryEntryAddressFactory;
template <typename T> struct impl_IPhoneCallHistoryEntryQueryOptions;
template <typename T> struct impl_IPhoneCallHistoryEntryReader;
template <typename T> struct impl_IPhoneCallHistoryManagerForUser;
template <typename T> struct impl_IPhoneCallHistoryManagerStatics;
template <typename T> struct impl_IPhoneCallHistoryManagerStatics2;
template <typename T> struct impl_IPhoneCallHistoryStore;
template <typename T> struct impl_IPhoneCallManagerStatics;
template <typename T> struct impl_IPhoneCallManagerStatics2;
template <typename T> struct impl_IPhoneCallStore;
template <typename T> struct impl_IPhoneCallVideoCapabilities;
template <typename T> struct impl_IPhoneCallVideoCapabilitiesManagerStatics;
template <typename T> struct impl_IPhoneDialOptions;
template <typename T> struct impl_IPhoneLine;
template <typename T> struct impl_IPhoneLineCellularDetails;
template <typename T> struct impl_IPhoneLineConfiguration;
template <typename T> struct impl_IPhoneLineStatics;
template <typename T> struct impl_IPhoneLineWatcher;
template <typename T> struct impl_IPhoneLineWatcherEventArgs;
template <typename T> struct impl_IPhoneVoicemail;
template <typename T> struct impl_IVoipCallCoordinator;
template <typename T> struct impl_IVoipCallCoordinatorStatics;
template <typename T> struct impl_IVoipPhoneCall;

}

namespace Windows::ApplicationModel::Calls {

enum class CellularDtmfMode
{
    Continuous = 0,
    Burst = 1,
};

enum class PhoneAudioRoutingEndpoint
{
    Default = 0,
    Bluetooth = 1,
    Speakerphone = 2,
};

enum class PhoneCallHistoryEntryMedia
{
    Audio = 0,
    Video = 1,
};

enum class PhoneCallHistoryEntryOtherAppReadAccess
{
    Full = 0,
    SystemOnly = 1,
};

enum class PhoneCallHistoryEntryQueryDesiredMedia : unsigned
{
    None = 0x0,
    Audio = 0x1,
    Video = 0x2,
    All = 0xFFFFFFFF,
};

DEFINE_ENUM_FLAG_OPERATORS(PhoneCallHistoryEntryQueryDesiredMedia)

enum class PhoneCallHistoryEntryRawAddressKind
{
    PhoneNumber = 0,
    Custom = 1,
};

enum class PhoneCallHistorySourceIdKind
{
    CellularPhoneLineId = 0,
    PackageFamilyName = 1,
};

enum class PhoneCallHistoryStoreAccessType
{
    AppEntriesReadWrite = 0,
    AllEntriesLimitedReadWrite = 1,
    AllEntriesReadWrite = 2,
};

enum class PhoneCallMedia
{
    Audio = 0,
    AudioAndVideo = 1,
};

enum class PhoneLineNetworkOperatorDisplayTextLocation
{
    Default = 0,
    Tile = 1,
    Dialer = 2,
    InCallUI = 3,
};

enum class PhoneLineTransport
{
    Cellular = 0,
    VoipApp = 1,
};

enum class PhoneLineWatcherStatus
{
    Created = 0,
    Started = 1,
    EnumerationCompleted = 2,
    Stopped = 3,
};

enum class PhoneNetworkState
{
    Unknown = 0,
    NoSignal = 1,
    Deregistered = 2,
    Denied = 3,
    Searching = 4,
    Home = 5,
    RoamingInternational = 6,
    RoamingDomestic = 7,
};

enum class PhoneSimState
{
    Unknown = 0,
    PinNotRequired = 1,
    PinUnlocked = 2,
    PinLocked = 3,
    PukLocked = 4,
    NotInserted = 5,
    Invalid = 6,
    Disabled = 7,
};

enum class PhoneVoicemailType
{
    None = 0,
    Traditional = 1,
    Visual = 2,
};

enum class VoipPhoneCallMedia : unsigned
{
    None = 0x0,
    Audio = 0x1,
    Video = 0x2,
};

DEFINE_ENUM_FLAG_OPERATORS(VoipPhoneCallMedia)

enum class VoipPhoneCallRejectReason
{
    UserIgnored = 0,
    TimedOut = 1,
    OtherIncomingCall = 2,
    EmergencyCallExists = 3,
    InvalidCallState = 4,
};

enum class VoipPhoneCallResourceReservationStatus
{
    Success = 0,
    ResourcesNotAvailable = 1,
};

enum class VoipPhoneCallState
{
    Ended = 0,
    Held = 1,
    Active = 2,
    Incoming = 3,
    Outgoing = 4,
};

}

}
