// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Gpio {

struct IGpioController;
struct IGpioControllerStatics;
struct IGpioControllerStatics2;
struct IGpioPin;
struct IGpioPinValueChangedEventArgs;
struct GpioController;
struct GpioPin;
struct GpioPinValueChangedEventArgs;

}

namespace Windows::Devices::Gpio {

struct IGpioController;
struct IGpioControllerStatics;
struct IGpioControllerStatics2;
struct IGpioPin;
struct IGpioPinValueChangedEventArgs;
struct GpioController;
struct GpioPin;
struct GpioPinValueChangedEventArgs;

}

namespace Windows::Devices::Gpio {

template <typename T> struct impl_IGpioController;
template <typename T> struct impl_IGpioControllerStatics;
template <typename T> struct impl_IGpioControllerStatics2;
template <typename T> struct impl_IGpioPin;
template <typename T> struct impl_IGpioPinValueChangedEventArgs;

}

namespace Windows::Devices::Gpio {

enum class GpioOpenStatus
{
    PinOpened = 0,
    PinUnavailable = 1,
    SharingViolation = 2,
};

enum class GpioPinDriveMode
{
    Input = 0,
    Output = 1,
    InputPullUp = 2,
    InputPullDown = 3,
    OutputOpenDrain = 4,
    OutputOpenDrainPullUp = 5,
    OutputOpenSource = 6,
    OutputOpenSourcePullDown = 7,
};

enum class GpioPinEdge
{
    FallingEdge = 0,
    RisingEdge = 1,
};

enum class GpioPinValue
{
    Low = 0,
    High = 1,
};

enum class GpioSharingMode
{
    Exclusive = 0,
    SharedReadOnly = 1,
};

}

}
