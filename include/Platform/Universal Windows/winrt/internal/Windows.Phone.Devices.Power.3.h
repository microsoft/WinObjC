// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.Devices.Power.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Phone::Devices::Power {

struct WINRT_EBO Battery :
    Windows::Phone::Devices::Power::IBattery
{
    Battery(std::nullptr_t) noexcept {}
    static Windows::Phone::Devices::Power::Battery GetDefault();
};

}

}
