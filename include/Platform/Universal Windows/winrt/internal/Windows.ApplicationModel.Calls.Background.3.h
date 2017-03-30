// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Calls.Background.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Calls::Background {

struct WINRT_EBO PhoneCallBlockedTriggerDetails :
    Windows::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails
{
    PhoneCallBlockedTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhoneCallOriginDataRequestTriggerDetails :
    Windows::ApplicationModel::Calls::Background::IPhoneCallOriginDataRequestTriggerDetails
{
    PhoneCallOriginDataRequestTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhoneLineChangedTriggerDetails :
    Windows::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails
{
    PhoneLineChangedTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhoneNewVoicemailMessageTriggerDetails :
    Windows::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails
{
    PhoneNewVoicemailMessageTriggerDetails(std::nullptr_t) noexcept {}
};

}

}
