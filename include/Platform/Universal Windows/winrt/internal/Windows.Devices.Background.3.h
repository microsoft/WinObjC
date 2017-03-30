// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Background.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Background {

struct WINRT_EBO DeviceServicingDetails :
    Windows::Devices::Background::IDeviceServicingDetails
{
    DeviceServicingDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DeviceUseDetails :
    Windows::Devices::Background::IDeviceUseDetails
{
    DeviceUseDetails(std::nullptr_t) noexcept {}
};

}

}
