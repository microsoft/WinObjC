// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Phone.System.Power.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::System::Power {

struct __declspec(uuid("25de8fd0-1c5b-11e1-bddb-0800200c9a66")) __declspec(novtable) IPowerManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PowerSavingMode(winrt::Windows::Phone::System::Power::PowerSavingMode * value) = 0;
    virtual HRESULT __stdcall add_PowerSavingModeChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * changeHandler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PowerSavingModeChanged(event_token token) = 0;
};

struct __declspec(uuid("596236cf-1918-4551-a466-c51aae373bf8")) __declspec(novtable) IPowerManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PowerSavingModeEnabled(bool * value) = 0;
};

}

namespace ABI {


}

namespace Windows::Phone::System::Power {

template <typename D>
struct WINRT_EBO impl_IPowerManagerStatics
{
    Windows::Phone::System::Power::PowerSavingMode PowerSavingMode() const;
    event_token PowerSavingModeChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & changeHandler) const;
    using PowerSavingModeChanged_revoker = event_revoker<IPowerManagerStatics>;
    PowerSavingModeChanged_revoker PowerSavingModeChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & changeHandler) const;
    void PowerSavingModeChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IPowerManagerStatics2
{
    bool PowerSavingModeEnabled() const;
};

}

namespace impl {

template <> struct traits<Windows::Phone::System::Power::IPowerManagerStatics>
{
    using abi = ABI::Windows::Phone::System::Power::IPowerManagerStatics;
    template <typename D> using consume = Windows::Phone::System::Power::impl_IPowerManagerStatics<D>;
};

template <> struct traits<Windows::Phone::System::Power::IPowerManagerStatics2>
{
    using abi = ABI::Windows::Phone::System::Power::IPowerManagerStatics2;
    template <typename D> using consume = Windows::Phone::System::Power::impl_IPowerManagerStatics2<D>;
};

template <> struct traits<Windows::Phone::System::Power::PowerManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.System.Power.PowerManager"; }
};

}

}
