// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Adc.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Adc {

struct WINRT_EBO AdcChannel :
    Windows::Devices::Adc::IAdcChannel
{
    AdcChannel(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AdcController :
    Windows::Devices::Adc::IAdcController
{
    AdcController(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Adc::AdcController>> GetControllersAsync(const Windows::Devices::Adc::Provider::IAdcProvider & provider);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Adc::AdcController> GetDefaultAsync();
};

}

}
