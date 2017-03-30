// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.I2c.Provider.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_511f8a39_98ca_550d_af25_1df2c1193c01
#define WINRT_GENERIC_511f8a39_98ca_550d_af25_1df2c1193c01
template <> struct __declspec(uuid("511f8a39-98ca-550d-af25-1df2c1193c01")) __declspec(novtable) IVectorView<Windows::Devices::I2c::Provider::II2cControllerProvider> : impl_IVectorView<Windows::Devices::I2c::Provider::II2cControllerProvider> {};
#endif

#ifndef WINRT_GENERIC_f6232961_c660_50a1_82e8_12892fcd91f7
#define WINRT_GENERIC_f6232961_c660_50a1_82e8_12892fcd91f7
template <> struct __declspec(uuid("f6232961-c660-50a1-82e8-12892fcd91f7")) __declspec(novtable) IIterator<Windows::Devices::I2c::Provider::II2cControllerProvider> : impl_IIterator<Windows::Devices::I2c::Provider::II2cControllerProvider> {};
#endif

#ifndef WINRT_GENERIC_11341a6c_3a02_5f73_9db8_c3ec5823e35d
#define WINRT_GENERIC_11341a6c_3a02_5f73_9db8_c3ec5823e35d
template <> struct __declspec(uuid("11341a6c-3a02-5f73-9db8-c3ec5823e35d")) __declspec(novtable) IIterable<Windows::Devices::I2c::Provider::II2cControllerProvider> : impl_IIterable<Windows::Devices::I2c::Provider::II2cControllerProvider> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5fe77838_1125_5b2c_a281_e06a3dfbb76e
#define WINRT_GENERIC_5fe77838_1125_5b2c_a281_e06a3dfbb76e
template <> struct __declspec(uuid("5fe77838-1125-5b2c-a281-e06a3dfbb76e")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::Provider::II2cControllerProvider>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::Provider::II2cControllerProvider>> {};
#endif

#ifndef WINRT_GENERIC_771e22ed_da9e_50be_b730_a3bada6bfb25
#define WINRT_GENERIC_771e22ed_da9e_50be_b730_a3bada6bfb25
template <> struct __declspec(uuid("771e22ed-da9e-50be-b730-a3bada6bfb25")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::Provider::II2cControllerProvider>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::Provider::II2cControllerProvider>> {};
#endif


}

namespace Windows::Devices::I2c::Provider {

struct II2cControllerProvider :
    Windows::Foundation::IInspectable,
    impl::consume<II2cControllerProvider>
{
    II2cControllerProvider(std::nullptr_t = nullptr) noexcept {}
};

struct II2cDeviceProvider :
    Windows::Foundation::IInspectable,
    impl::consume<II2cDeviceProvider>,
    impl::require<II2cDeviceProvider, Windows::Foundation::IClosable>
{
    II2cDeviceProvider(std::nullptr_t = nullptr) noexcept {}
};

struct II2cProvider :
    Windows::Foundation::IInspectable,
    impl::consume<II2cProvider>
{
    II2cProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IProviderI2cConnectionSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IProviderI2cConnectionSettings>
{
    IProviderI2cConnectionSettings(std::nullptr_t = nullptr) noexcept {}
};

}

}
