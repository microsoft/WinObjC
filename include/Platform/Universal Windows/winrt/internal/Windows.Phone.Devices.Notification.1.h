// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Phone.Devices.Notification.0.h"
#include "Windows.Foundation.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::Devices::Notification {

struct __declspec(uuid("1b4a6595-cfcd-4e08-92fb-c1906d04498c")) __declspec(novtable) IVibrationDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Vibrate(Windows::Foundation::TimeSpan duration) = 0;
    virtual HRESULT __stdcall abi_Cancel() = 0;
};

struct __declspec(uuid("332fd2f1-1c69-4c91-949e-4bb67a85bdc7")) __declspec(novtable) IVibrationDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Phone::Devices::Notification::IVibrationDevice ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Phone::Devices::Notification::VibrationDevice> { using default_interface = Windows::Phone::Devices::Notification::IVibrationDevice; };

}

namespace Windows::Phone::Devices::Notification {

template <typename D>
struct WINRT_EBO impl_IVibrationDevice
{
    void Vibrate(const Windows::Foundation::TimeSpan & duration) const;
    void Cancel() const;
};

template <typename D>
struct WINRT_EBO impl_IVibrationDeviceStatics
{
    Windows::Phone::Devices::Notification::VibrationDevice GetDefault() const;
};

}

namespace impl {

template <> struct traits<Windows::Phone::Devices::Notification::IVibrationDevice>
{
    using abi = ABI::Windows::Phone::Devices::Notification::IVibrationDevice;
    template <typename D> using consume = Windows::Phone::Devices::Notification::impl_IVibrationDevice<D>;
};

template <> struct traits<Windows::Phone::Devices::Notification::IVibrationDeviceStatics>
{
    using abi = ABI::Windows::Phone::Devices::Notification::IVibrationDeviceStatics;
    template <typename D> using consume = Windows::Phone::Devices::Notification::impl_IVibrationDeviceStatics<D>;
};

template <> struct traits<Windows::Phone::Devices::Notification::VibrationDevice>
{
    using abi = ABI::Windows::Phone::Devices::Notification::VibrationDevice;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.Devices.Notification.VibrationDevice"; }
};

}

}
