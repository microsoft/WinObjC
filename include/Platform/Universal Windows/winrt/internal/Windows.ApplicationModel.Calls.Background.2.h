// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Calls.Background.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Calls::Background {

struct IPhoneCallBlockedTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneCallBlockedTriggerDetails>
{
    IPhoneCallBlockedTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneCallOriginDataRequestTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneCallOriginDataRequestTriggerDetails>
{
    IPhoneCallOriginDataRequestTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneLineChangedTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneLineChangedTriggerDetails>
{
    IPhoneLineChangedTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IPhoneNewVoicemailMessageTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IPhoneNewVoicemailMessageTriggerDetails>
{
    IPhoneNewVoicemailMessageTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

}

}
