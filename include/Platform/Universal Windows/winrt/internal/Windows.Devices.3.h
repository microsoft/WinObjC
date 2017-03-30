// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices {

struct WINRT_EBO LowLevelDevicesAggregateProvider :
    Windows::Devices::ILowLevelDevicesAggregateProvider
{
    LowLevelDevicesAggregateProvider(std::nullptr_t) noexcept {}
    LowLevelDevicesAggregateProvider(const Windows::Devices::Adc::Provider::IAdcControllerProvider & adc, const Windows::Devices::Pwm::Provider::IPwmControllerProvider & pwm, const Windows::Devices::Gpio::Provider::IGpioControllerProvider & gpio, const Windows::Devices::I2c::Provider::II2cControllerProvider & i2c, const Windows::Devices::Spi::Provider::ISpiControllerProvider & spi);
};

struct WINRT_EBO LowLevelDevicesController :
    Windows::Devices::ILowLevelDevicesController
{
    LowLevelDevicesController(std::nullptr_t) noexcept {}
    static Windows::Devices::ILowLevelDevicesAggregateProvider DefaultProvider();
    static void DefaultProvider(const Windows::Devices::ILowLevelDevicesAggregateProvider & value);
};

}

}
