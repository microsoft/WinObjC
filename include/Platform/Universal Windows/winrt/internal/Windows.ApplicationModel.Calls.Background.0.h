// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Calls::Background {

struct IPhoneCallBlockedTriggerDetails;
struct IPhoneCallOriginDataRequestTriggerDetails;
struct IPhoneLineChangedTriggerDetails;
struct IPhoneNewVoicemailMessageTriggerDetails;
struct PhoneCallBlockedTriggerDetails;
struct PhoneCallOriginDataRequestTriggerDetails;
struct PhoneLineChangedTriggerDetails;
struct PhoneNewVoicemailMessageTriggerDetails;

}

namespace Windows::ApplicationModel::Calls::Background {

struct IPhoneCallBlockedTriggerDetails;
struct IPhoneCallOriginDataRequestTriggerDetails;
struct IPhoneLineChangedTriggerDetails;
struct IPhoneNewVoicemailMessageTriggerDetails;
struct PhoneCallBlockedTriggerDetails;
struct PhoneCallOriginDataRequestTriggerDetails;
struct PhoneLineChangedTriggerDetails;
struct PhoneNewVoicemailMessageTriggerDetails;

}

namespace Windows::ApplicationModel::Calls::Background {

template <typename T> struct impl_IPhoneCallBlockedTriggerDetails;
template <typename T> struct impl_IPhoneCallOriginDataRequestTriggerDetails;
template <typename T> struct impl_IPhoneLineChangedTriggerDetails;
template <typename T> struct impl_IPhoneNewVoicemailMessageTriggerDetails;

}

namespace Windows::ApplicationModel::Calls::Background {

enum class PhoneCallBlockedReason
{
    InCallBlockingList = 0,
    PrivateNumber = 1,
    UnknownNumber = 2,
};

enum class PhoneLineChangeKind
{
    Added = 0,
    Removed = 1,
    PropertiesChanged = 2,
};

enum class PhoneLineProperties : unsigned
{
    None = 0x0,
    BrandingOptions = 0x1,
    CanDial = 0x2,
    CellularDetails = 0x4,
    DisplayColor = 0x8,
    DisplayName = 0x10,
    NetworkName = 0x20,
    NetworkState = 0x40,
    Transport = 0x80,
    Voicemail = 0x100,
};

DEFINE_ENUM_FLAG_OPERATORS(PhoneLineProperties)

enum class PhoneTriggerType
{
    NewVoicemailMessage = 0,
    CallHistoryChanged = 1,
    LineChanged = 2,
    AirplaneModeDisabledForEmergencyCall = 3,
    CallOriginDataRequest = 4,
    CallBlocked = 5,
};

}

}
