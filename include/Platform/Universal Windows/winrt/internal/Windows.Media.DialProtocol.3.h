// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.DialProtocol.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::DialProtocol {

struct WINRT_EBO DialApp :
    Windows::Media::DialProtocol::IDialApp
{
    DialApp(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DialAppStateDetails :
    Windows::Media::DialProtocol::IDialAppStateDetails
{
    DialAppStateDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DialDevice :
    Windows::Media::DialProtocol::IDialDevice,
    impl::require<DialDevice, Windows::Media::DialProtocol::IDialDevice2>
{
    DialDevice(std::nullptr_t) noexcept {}
    static hstring GetDeviceSelector(hstring_view appName);
    static Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice> FromIdAsync(hstring_view value);
    static Windows::Foundation::IAsyncOperation<bool> DeviceInfoSupportsDialAsync(const Windows::Devices::Enumeration::DeviceInformation & device);
};

struct WINRT_EBO DialDevicePicker :
    Windows::Media::DialProtocol::IDialDevicePicker
{
    DialDevicePicker(std::nullptr_t) noexcept {}
    DialDevicePicker();
};

struct WINRT_EBO DialDevicePickerFilter :
    Windows::Media::DialProtocol::IDialDevicePickerFilter
{
    DialDevicePickerFilter(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DialDeviceSelectedEventArgs :
    Windows::Media::DialProtocol::IDialDeviceSelectedEventArgs
{
    DialDeviceSelectedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DialDisconnectButtonClickedEventArgs :
    Windows::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs
{
    DialDisconnectButtonClickedEventArgs(std::nullptr_t) noexcept {}
};

}

}
