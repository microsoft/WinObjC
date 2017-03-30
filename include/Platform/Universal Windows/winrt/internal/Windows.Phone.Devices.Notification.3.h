// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.Devices.Notification.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Phone::Devices::Notification {

struct WINRT_EBO VibrationDevice :
    Windows::Phone::Devices::Notification::IVibrationDevice
{
    VibrationDevice(std::nullptr_t) noexcept {}
    static Windows::Phone::Devices::Notification::VibrationDevice GetDefault();
};

}

}
