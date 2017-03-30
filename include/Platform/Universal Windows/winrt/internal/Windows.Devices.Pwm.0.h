// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Pwm {

struct IPwmController;
struct IPwmControllerStatics;
struct IPwmControllerStatics2;
struct IPwmPin;
struct PwmController;
struct PwmPin;

}

namespace Windows::Devices::Pwm {

struct IPwmController;
struct IPwmControllerStatics;
struct IPwmControllerStatics2;
struct IPwmPin;
struct PwmController;
struct PwmPin;

}

namespace Windows::Devices::Pwm {

template <typename T> struct impl_IPwmController;
template <typename T> struct impl_IPwmControllerStatics;
template <typename T> struct impl_IPwmControllerStatics2;
template <typename T> struct impl_IPwmPin;

}

namespace Windows::Devices::Pwm {

enum class PwmPulsePolarity
{
    ActiveHigh = 0,
    ActiveLow = 1,
};

}

}
