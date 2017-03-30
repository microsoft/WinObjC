// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Spi.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Spi {

struct WINRT_EBO SpiBusInfo :
    Windows::Devices::Spi::ISpiBusInfo
{
    SpiBusInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpiConnectionSettings :
    Windows::Devices::Spi::ISpiConnectionSettings
{
    SpiConnectionSettings(std::nullptr_t) noexcept {}
    SpiConnectionSettings(int32_t chipSelectLine);
};

struct WINRT_EBO SpiController :
    Windows::Devices::Spi::ISpiController
{
    SpiController(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Spi::SpiController> GetDefaultAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::SpiController>> GetControllersAsync(const Windows::Devices::Spi::Provider::ISpiProvider & provider);
};

struct WINRT_EBO SpiDevice :
    Windows::Devices::Spi::ISpiDevice
{
    SpiDevice(std::nullptr_t) noexcept {}
    static hstring GetDeviceSelector();
    static hstring GetDeviceSelector(hstring_view friendlyName);
    static Windows::Devices::Spi::SpiBusInfo GetBusInfo(hstring_view busId);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Spi::SpiDevice> FromIdAsync(hstring_view busId, const Windows::Devices::Spi::SpiConnectionSettings & settings);
};

}

}
