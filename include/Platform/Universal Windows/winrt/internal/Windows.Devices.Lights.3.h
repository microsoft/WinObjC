// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Lights.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Lights {

struct WINRT_EBO Lamp :
    Windows::Devices::Lights::ILamp
{
    Lamp(std::nullptr_t) noexcept {}
    static hstring GetDeviceSelector();
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Lights::Lamp> FromIdAsync(hstring_view deviceId);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Lights::Lamp> GetDefaultAsync();
};

struct WINRT_EBO LampAvailabilityChangedEventArgs :
    Windows::Devices::Lights::ILampAvailabilityChangedEventArgs
{
    LampAvailabilityChangedEventArgs(std::nullptr_t) noexcept {}
};

}

}
