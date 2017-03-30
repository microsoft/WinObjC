// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Pwm.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Pwm {

struct WINRT_EBO PwmController :
    Windows::Devices::Pwm::IPwmController
{
    PwmController(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Pwm::PwmController>> GetControllersAsync(const Windows::Devices::Pwm::Provider::IPwmProvider & provider);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Pwm::PwmController> GetDefaultAsync();
};

struct WINRT_EBO PwmPin :
    Windows::Devices::Pwm::IPwmPin
{
    PwmPin(std::nullptr_t) noexcept {}
};

}

}
