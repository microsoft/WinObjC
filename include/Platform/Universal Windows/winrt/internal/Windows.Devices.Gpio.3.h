// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Gpio.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Gpio {

struct WINRT_EBO GpioController :
    Windows::Devices::Gpio::IGpioController
{
    GpioController(std::nullptr_t) noexcept {}
    static Windows::Devices::Gpio::GpioController GetDefault();
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Gpio::GpioController>> GetControllersAsync(const Windows::Devices::Gpio::Provider::IGpioProvider & provider);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Gpio::GpioController> GetDefaultAsync();
};

struct WINRT_EBO GpioPin :
    Windows::Devices::Gpio::IGpioPin
{
    GpioPin(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GpioPinValueChangedEventArgs :
    Windows::Devices::Gpio::IGpioPinValueChangedEventArgs
{
    GpioPinValueChangedEventArgs(std::nullptr_t) noexcept {}
};

}

}
