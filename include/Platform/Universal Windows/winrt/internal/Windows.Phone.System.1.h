// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Phone.System.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::System {

struct __declspec(uuid("49c36560-97e1-4d99-8bfb-befeaa6ace6d")) __declspec(novtable) ISystemProtectionStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ScreenLocked(bool * value) = 0;
};

struct __declspec(uuid("0692fa3f-8f11-4c4b-aa0d-87d7af7b1779")) __declspec(novtable) ISystemProtectionUnlockStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestScreenUnlock() = 0;
};

}

namespace ABI {


}

namespace Windows::Phone::System {

template <typename D>
struct WINRT_EBO impl_ISystemProtectionStatics
{
    bool ScreenLocked() const;
};

template <typename D>
struct WINRT_EBO impl_ISystemProtectionUnlockStatics
{
    void RequestScreenUnlock() const;
};

}

namespace impl {

template <> struct traits<Windows::Phone::System::ISystemProtectionStatics>
{
    using abi = ABI::Windows::Phone::System::ISystemProtectionStatics;
    template <typename D> using consume = Windows::Phone::System::impl_ISystemProtectionStatics<D>;
};

template <> struct traits<Windows::Phone::System::ISystemProtectionUnlockStatics>
{
    using abi = ABI::Windows::Phone::System::ISystemProtectionUnlockStatics;
    template <typename D> using consume = Windows::Phone::System::impl_ISystemProtectionUnlockStatics<D>;
};

template <> struct traits<Windows::Phone::System::SystemProtection>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.System.SystemProtection"; }
};

}

}
