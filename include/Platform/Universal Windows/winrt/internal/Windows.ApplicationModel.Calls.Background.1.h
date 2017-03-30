// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Calls.Background.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Calls::Background {

struct __declspec(uuid("a4a690a2-e4c1-427f-864e-e470477ddb67")) __declspec(novtable) IPhoneCallBlockedTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PhoneNumber(hstring * value) = 0;
    virtual HRESULT __stdcall get_LineId(GUID * value) = 0;
    virtual HRESULT __stdcall get_CallBlockedReason(winrt::Windows::ApplicationModel::Calls::Background::PhoneCallBlockedReason * value) = 0;
};

struct __declspec(uuid("6e9b5b3f-c54b-4e82-4cc9-e329a4184592")) __declspec(novtable) IPhoneCallOriginDataRequestTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RequestId(GUID * result) = 0;
    virtual HRESULT __stdcall get_PhoneNumber(hstring * result) = 0;
};

struct __declspec(uuid("c6d321e7-d11d-40d8-b2b7-e40a01d66249")) __declspec(novtable) IPhoneLineChangedTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LineId(GUID * result) = 0;
    virtual HRESULT __stdcall get_ChangeType(winrt::Windows::ApplicationModel::Calls::Background::PhoneLineChangeKind * result) = 0;
    virtual HRESULT __stdcall abi_HasLinePropertyChanged(winrt::Windows::ApplicationModel::Calls::Background::PhoneLineProperties lineProperty, bool * result) = 0;
};

struct __declspec(uuid("13a8c01b-b831-48d3-8ba9-8d22a6580dcf")) __declspec(novtable) IPhoneNewVoicemailMessageTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LineId(GUID * result) = 0;
    virtual HRESULT __stdcall get_VoicemailCount(int32_t * result) = 0;
    virtual HRESULT __stdcall get_OperatorMessage(hstring * result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Calls::Background::PhoneCallBlockedTriggerDetails> { using default_interface = Windows::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails; };
template <> struct traits<Windows::ApplicationModel::Calls::Background::PhoneCallOriginDataRequestTriggerDetails> { using default_interface = Windows::ApplicationModel::Calls::Background::IPhoneCallOriginDataRequestTriggerDetails; };
template <> struct traits<Windows::ApplicationModel::Calls::Background::PhoneLineChangedTriggerDetails> { using default_interface = Windows::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails; };
template <> struct traits<Windows::ApplicationModel::Calls::Background::PhoneNewVoicemailMessageTriggerDetails> { using default_interface = Windows::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails; };

}

namespace Windows::ApplicationModel::Calls::Background {

template <typename D>
struct WINRT_EBO impl_IPhoneCallBlockedTriggerDetails
{
    hstring PhoneNumber() const;
    GUID LineId() const;
    Windows::ApplicationModel::Calls::Background::PhoneCallBlockedReason CallBlockedReason() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneCallOriginDataRequestTriggerDetails
{
    GUID RequestId() const;
    hstring PhoneNumber() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneLineChangedTriggerDetails
{
    GUID LineId() const;
    Windows::ApplicationModel::Calls::Background::PhoneLineChangeKind ChangeType() const;
    bool HasLinePropertyChanged(Windows::ApplicationModel::Calls::Background::PhoneLineProperties lineProperty) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneNewVoicemailMessageTriggerDetails
{
    GUID LineId() const;
    int32_t VoicemailCount() const;
    hstring OperatorMessage() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails;
    template <typename D> using consume = Windows::ApplicationModel::Calls::Background::impl_IPhoneCallBlockedTriggerDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::Background::IPhoneCallOriginDataRequestTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Calls::Background::IPhoneCallOriginDataRequestTriggerDetails;
    template <typename D> using consume = Windows::ApplicationModel::Calls::Background::impl_IPhoneCallOriginDataRequestTriggerDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails;
    template <typename D> using consume = Windows::ApplicationModel::Calls::Background::impl_IPhoneLineChangedTriggerDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails;
    template <typename D> using consume = Windows::ApplicationModel::Calls::Background::impl_IPhoneNewVoicemailMessageTriggerDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Calls::Background::PhoneCallBlockedTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Calls::Background::PhoneCallBlockedTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.Background.PhoneCallBlockedTriggerDetails"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::Background::PhoneCallOriginDataRequestTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Calls::Background::PhoneCallOriginDataRequestTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.Background.PhoneCallOriginDataRequestTriggerDetails"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::Background::PhoneLineChangedTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Calls::Background::PhoneLineChangedTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.Background.PhoneLineChangedTriggerDetails"; }
};

template <> struct traits<Windows::ApplicationModel::Calls::Background::PhoneNewVoicemailMessageTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Calls::Background::PhoneNewVoicemailMessageTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Calls.Background.PhoneNewVoicemailMessageTriggerDetails"; }
};

}

}
