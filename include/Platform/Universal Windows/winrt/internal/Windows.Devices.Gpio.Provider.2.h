// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Gpio.Provider.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_af259d89_9e01_529e_a879_c6763142d160
#define WINRT_GENERIC_af259d89_9e01_529e_a879_c6763142d160
template <> struct __declspec(uuid("af259d89-9e01-529e-a879-c6763142d160")) __declspec(novtable) TypedEventHandler<Windows::Devices::Gpio::Provider::IGpioPinProvider, Windows::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Gpio::Provider::IGpioPinProvider, Windows::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_f429355f_7a16_5dcf_a575_db7d2a20eced
#define WINRT_GENERIC_f429355f_7a16_5dcf_a575_db7d2a20eced
template <> struct __declspec(uuid("f429355f-7a16-5dcf-a575-db7d2a20eced")) __declspec(novtable) IVectorView<Windows::Devices::Gpio::Provider::IGpioControllerProvider> : impl_IVectorView<Windows::Devices::Gpio::Provider::IGpioControllerProvider> {};
#endif

#ifndef WINRT_GENERIC_6ac0edb9_e3c9_5840_8aa8_1bc45366f6ca
#define WINRT_GENERIC_6ac0edb9_e3c9_5840_8aa8_1bc45366f6ca
template <> struct __declspec(uuid("6ac0edb9-e3c9-5840-8aa8-1bc45366f6ca")) __declspec(novtable) IIterator<Windows::Devices::Gpio::Provider::IGpioControllerProvider> : impl_IIterator<Windows::Devices::Gpio::Provider::IGpioControllerProvider> {};
#endif

#ifndef WINRT_GENERIC_09212bd4_851b_52bd_b82c_421bf3d6f511
#define WINRT_GENERIC_09212bd4_851b_52bd_b82c_421bf3d6f511
template <> struct __declspec(uuid("09212bd4-851b-52bd-b82c-421bf3d6f511")) __declspec(novtable) IIterable<Windows::Devices::Gpio::Provider::IGpioControllerProvider> : impl_IIterable<Windows::Devices::Gpio::Provider::IGpioControllerProvider> {};
#endif


}

namespace Windows::Devices::Gpio::Provider {

struct IGpioControllerProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IGpioControllerProvider>
{
    IGpioControllerProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IGpioPinProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IGpioPinProvider>
{
    IGpioPinProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IGpioPinProviderValueChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IGpioPinProviderValueChangedEventArgs>
{
    IGpioPinProviderValueChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IGpioPinProviderValueChangedEventArgsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IGpioPinProviderValueChangedEventArgsFactory>
{
    IGpioPinProviderValueChangedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IGpioProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IGpioProvider>
{
    IGpioProvider(std::nullptr_t = nullptr) noexcept {}
};

}

}
