// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Background.0.h"
#include "Windows.Foundation.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Background {

struct __declspec(uuid("4aabee29-2344-4ac4-8527-4a8ef6905645")) __declspec(novtable) IDeviceServicingDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Arguments(hstring * value) = 0;
    virtual HRESULT __stdcall get_ExpectedDuration(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("7d565141-557e-4154-b994-e4f7a11fb323")) __declspec(novtable) IDeviceUseDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Arguments(hstring * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Background::DeviceServicingDetails> { using default_interface = Windows::Devices::Background::IDeviceServicingDetails; };
template <> struct traits<Windows::Devices::Background::DeviceUseDetails> { using default_interface = Windows::Devices::Background::IDeviceUseDetails; };

}

namespace Windows::Devices::Background {

template <typename D>
struct WINRT_EBO impl_IDeviceServicingDetails
{
    hstring DeviceId() const;
    hstring Arguments() const;
    Windows::Foundation::TimeSpan ExpectedDuration() const;
};

template <typename D>
struct WINRT_EBO impl_IDeviceUseDetails
{
    hstring DeviceId() const;
    hstring Arguments() const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Background::IDeviceServicingDetails>
{
    using abi = ABI::Windows::Devices::Background::IDeviceServicingDetails;
    template <typename D> using consume = Windows::Devices::Background::impl_IDeviceServicingDetails<D>;
};

template <> struct traits<Windows::Devices::Background::IDeviceUseDetails>
{
    using abi = ABI::Windows::Devices::Background::IDeviceUseDetails;
    template <typename D> using consume = Windows::Devices::Background::impl_IDeviceUseDetails<D>;
};

template <> struct traits<Windows::Devices::Background::DeviceServicingDetails>
{
    using abi = ABI::Windows::Devices::Background::DeviceServicingDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Background.DeviceServicingDetails"; }
};

template <> struct traits<Windows::Devices::Background::DeviceUseDetails>
{
    using abi = ABI::Windows::Devices::Background::DeviceUseDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Background.DeviceUseDetails"; }
};

}

}
