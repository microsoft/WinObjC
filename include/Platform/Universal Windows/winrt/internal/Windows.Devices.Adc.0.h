// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Adc {

struct IAdcChannel;
struct IAdcController;
struct IAdcControllerStatics;
struct IAdcControllerStatics2;
struct AdcChannel;
struct AdcController;

}

namespace Windows::Devices::Adc {

struct IAdcChannel;
struct IAdcController;
struct IAdcControllerStatics;
struct IAdcControllerStatics2;
struct AdcChannel;
struct AdcController;

}

namespace Windows::Devices::Adc {

template <typename T> struct impl_IAdcChannel;
template <typename T> struct impl_IAdcController;
template <typename T> struct impl_IAdcControllerStatics;
template <typename T> struct impl_IAdcControllerStatics2;

}

namespace Windows::Devices::Adc {

enum class AdcChannelMode
{
    SingleEnded = 0,
    Differential = 1,
};

}

}
