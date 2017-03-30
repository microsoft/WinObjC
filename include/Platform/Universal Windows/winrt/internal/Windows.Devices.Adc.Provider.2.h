// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Adc.Provider.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_7c4789c0_8445_5757_aab7_659cbf50aaa7
#define WINRT_GENERIC_7c4789c0_8445_5757_aab7_659cbf50aaa7
template <> struct __declspec(uuid("7c4789c0-8445-5757-aab7-659cbf50aaa7")) __declspec(novtable) IVectorView<Windows::Devices::Adc::Provider::IAdcControllerProvider> : impl_IVectorView<Windows::Devices::Adc::Provider::IAdcControllerProvider> {};
#endif

#ifndef WINRT_GENERIC_b43acf15_a24a_5b00_b710_1737ba550a18
#define WINRT_GENERIC_b43acf15_a24a_5b00_b710_1737ba550a18
template <> struct __declspec(uuid("b43acf15-a24a-5b00-b710-1737ba550a18")) __declspec(novtable) IIterator<Windows::Devices::Adc::Provider::IAdcControllerProvider> : impl_IIterator<Windows::Devices::Adc::Provider::IAdcControllerProvider> {};
#endif

#ifndef WINRT_GENERIC_30047155_1f71_5223_8482_e5159d0137d0
#define WINRT_GENERIC_30047155_1f71_5223_8482_e5159d0137d0
template <> struct __declspec(uuid("30047155-1f71-5223-8482-e5159d0137d0")) __declspec(novtable) IIterable<Windows::Devices::Adc::Provider::IAdcControllerProvider> : impl_IIterable<Windows::Devices::Adc::Provider::IAdcControllerProvider> {};
#endif


}

namespace Windows::Devices::Adc::Provider {

struct IAdcControllerProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IAdcControllerProvider>
{
    IAdcControllerProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IAdcProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IAdcProvider>
{
    IAdcProvider(std::nullptr_t = nullptr) noexcept {}
};

}

}
