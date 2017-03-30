// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Casting.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Casting {

struct WINRT_EBO CastingConnection :
    Windows::Media::Casting::ICastingConnection
{
    CastingConnection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CastingConnectionErrorOccurredEventArgs :
    Windows::Media::Casting::ICastingConnectionErrorOccurredEventArgs
{
    CastingConnectionErrorOccurredEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CastingDevice :
    Windows::Media::Casting::ICastingDevice
{
    CastingDevice(std::nullptr_t) noexcept {}
    static hstring GetDeviceSelector(Windows::Media::Casting::CastingPlaybackTypes type);
    static Windows::Foundation::IAsyncOperation<hstring> GetDeviceSelectorFromCastingSourceAsync(const Windows::Media::Casting::CastingSource & castingSource);
    static Windows::Foundation::IAsyncOperation<Windows::Media::Casting::CastingDevice> FromIdAsync(hstring_view value);
    static Windows::Foundation::IAsyncOperation<bool> DeviceInfoSupportsCastingAsync(const Windows::Devices::Enumeration::DeviceInformation & device);
};

struct WINRT_EBO CastingDevicePicker :
    Windows::Media::Casting::ICastingDevicePicker
{
    CastingDevicePicker(std::nullptr_t) noexcept {}
    CastingDevicePicker();
};

struct WINRT_EBO CastingDevicePickerFilter :
    Windows::Media::Casting::ICastingDevicePickerFilter
{
    CastingDevicePickerFilter(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CastingDeviceSelectedEventArgs :
    Windows::Media::Casting::ICastingDeviceSelectedEventArgs
{
    CastingDeviceSelectedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CastingSource :
    Windows::Media::Casting::ICastingSource
{
    CastingSource(std::nullptr_t) noexcept {}
};

}

}
