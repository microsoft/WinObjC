// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.I2c.Provider.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::I2c::Provider {

struct WINRT_EBO ProviderI2cConnectionSettings :
    Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings
{
    ProviderI2cConnectionSettings(std::nullptr_t) noexcept {}
};

}

}
