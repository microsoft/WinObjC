// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Gpio.Provider.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Gpio::Provider {

struct WINRT_EBO GpioPinProviderValueChangedEventArgs :
    Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs
{
    GpioPinProviderValueChangedEventArgs(std::nullptr_t) noexcept {}
    GpioPinProviderValueChangedEventArgs(Windows::Devices::Gpio::Provider::ProviderGpioPinEdge edge);
};

}

}
