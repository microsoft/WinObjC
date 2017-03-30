// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Spi.Provider.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_96a4919b_3229_5e41_8b10_c8198c44f10c
#define WINRT_GENERIC_96a4919b_3229_5e41_8b10_c8198c44f10c
template <> struct __declspec(uuid("96a4919b-3229-5e41-8b10-c8198c44f10c")) __declspec(novtable) IVectorView<Windows::Devices::Spi::Provider::ISpiControllerProvider> : impl_IVectorView<Windows::Devices::Spi::Provider::ISpiControllerProvider> {};
#endif

#ifndef WINRT_GENERIC_cf1d15d3_a6c8_56dd_80c8_e8d960262277
#define WINRT_GENERIC_cf1d15d3_a6c8_56dd_80c8_e8d960262277
template <> struct __declspec(uuid("cf1d15d3-a6c8-56dd-80c8-e8d960262277")) __declspec(novtable) IIterator<Windows::Devices::Spi::Provider::ISpiControllerProvider> : impl_IIterator<Windows::Devices::Spi::Provider::ISpiControllerProvider> {};
#endif

#ifndef WINRT_GENERIC_71ba027d_8c84_58b1_8d66_9177c11698eb
#define WINRT_GENERIC_71ba027d_8c84_58b1_8d66_9177c11698eb
template <> struct __declspec(uuid("71ba027d-8c84-58b1-8d66-9177c11698eb")) __declspec(novtable) IIterable<Windows::Devices::Spi::Provider::ISpiControllerProvider> : impl_IIterable<Windows::Devices::Spi::Provider::ISpiControllerProvider> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b3af3490_dede_59d1_b562_1f6be71ae139
#define WINRT_GENERIC_b3af3490_dede_59d1_b562_1f6be71ae139
template <> struct __declspec(uuid("b3af3490-dede-59d1-b562-1f6be71ae139")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::Provider::ISpiControllerProvider>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::Provider::ISpiControllerProvider>> {};
#endif

#ifndef WINRT_GENERIC_e9e2ae03_42d6_5211_ab52_325e722e2611
#define WINRT_GENERIC_e9e2ae03_42d6_5211_ab52_325e722e2611
template <> struct __declspec(uuid("e9e2ae03-42d6-5211-ab52-325e722e2611")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::Provider::ISpiControllerProvider>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::Provider::ISpiControllerProvider>> {};
#endif


}

namespace Windows::Devices::Spi::Provider {

struct IProviderSpiConnectionSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IProviderSpiConnectionSettings>
{
    IProviderSpiConnectionSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IProviderSpiConnectionSettingsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IProviderSpiConnectionSettingsFactory>
{
    IProviderSpiConnectionSettingsFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ISpiControllerProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ISpiControllerProvider>
{
    ISpiControllerProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ISpiDeviceProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ISpiDeviceProvider>,
    impl::require<ISpiDeviceProvider, Windows::Foundation::IClosable>
{
    ISpiDeviceProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ISpiProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ISpiProvider>
{
    ISpiProvider(std::nullptr_t = nullptr) noexcept {}
};

}

}
