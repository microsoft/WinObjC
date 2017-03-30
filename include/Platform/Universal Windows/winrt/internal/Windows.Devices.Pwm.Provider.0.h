// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Pwm::Provider {

struct IPwmControllerProvider;
struct IPwmProvider;

}

namespace Windows::Devices::Pwm::Provider {

struct IPwmControllerProvider;
struct IPwmProvider;

}

namespace Windows::Devices::Pwm::Provider {

template <typename T> struct impl_IPwmControllerProvider;
template <typename T> struct impl_IPwmProvider;

}

}
