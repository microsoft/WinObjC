// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.I2c.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::I2c {

struct WINRT_EBO I2cConnectionSettings :
    Windows::Devices::I2c::II2cConnectionSettings
{
    I2cConnectionSettings(std::nullptr_t) noexcept {}
    I2cConnectionSettings(int32_t slaveAddress);
};

struct WINRT_EBO I2cController :
    Windows::Devices::I2c::II2cController
{
    I2cController(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::I2cController>> GetControllersAsync(const Windows::Devices::I2c::Provider::II2cProvider & provider);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::I2c::I2cController> GetDefaultAsync();
};

struct WINRT_EBO I2cDevice :
    Windows::Devices::I2c::II2cDevice
{
    I2cDevice(std::nullptr_t) noexcept {}
    static hstring GetDeviceSelector();
    static hstring GetDeviceSelector(hstring_view friendlyName);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::I2c::I2cDevice> FromIdAsync(hstring_view deviceId, const Windows::Devices::I2c::I2cConnectionSettings & settings);
};

}

}
