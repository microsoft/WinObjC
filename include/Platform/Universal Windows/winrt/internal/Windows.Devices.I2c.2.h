// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.I2c.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_1e8a7cd8_e41b_5a41_82b1_80055012ae00
#define WINRT_GENERIC_1e8a7cd8_e41b_5a41_82b1_80055012ae00
template <> struct __declspec(uuid("1e8a7cd8-e41b-5a41-82b1-80055012ae00")) __declspec(novtable) IAsyncOperation<Windows::Devices::I2c::I2cDevice> : impl_IAsyncOperation<Windows::Devices::I2c::I2cDevice> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_c5dd481d_a441_5a8c_865f_08fa31490de5
#define WINRT_GENERIC_c5dd481d_a441_5a8c_865f_08fa31490de5
template <> struct __declspec(uuid("c5dd481d-a441-5a8c-865f-08fa31490de5")) __declspec(novtable) IVectorView<Windows::Devices::I2c::I2cController> : impl_IVectorView<Windows::Devices::I2c::I2cController> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_a4fb1dd4_80c9_5a61_ae8d_c8a7afc03275
#define WINRT_GENERIC_a4fb1dd4_80c9_5a61_ae8d_c8a7afc03275
template <> struct __declspec(uuid("a4fb1dd4-80c9-5a61-ae8d-c8a7afc03275")) __declspec(novtable) IAsyncOperation<Windows::Devices::I2c::I2cController> : impl_IAsyncOperation<Windows::Devices::I2c::I2cController> {};
#endif

#ifndef WINRT_GENERIC_2df5bb6a_5e73_5ae3_a0b2_22e1c9d8ef4d
#define WINRT_GENERIC_2df5bb6a_5e73_5ae3_a0b2_22e1c9d8ef4d
template <> struct __declspec(uuid("2df5bb6a-5e73-5ae3-a0b2-22e1c9d8ef4d")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::I2c::I2cDevice> : impl_AsyncOperationCompletedHandler<Windows::Devices::I2c::I2cDevice> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8f6822fc_e4ea_5b35_939a_27f3b3d550d2
#define WINRT_GENERIC_8f6822fc_e4ea_5b35_939a_27f3b3d550d2
template <> struct __declspec(uuid("8f6822fc-e4ea-5b35-939a-27f3b3d550d2")) __declspec(novtable) IIterator<Windows::Devices::I2c::I2cController> : impl_IIterator<Windows::Devices::I2c::I2cController> {};
#endif

#ifndef WINRT_GENERIC_a5ee8233_2429_5b26_9a02_993e4e7edfa9
#define WINRT_GENERIC_a5ee8233_2429_5b26_9a02_993e4e7edfa9
template <> struct __declspec(uuid("a5ee8233-2429-5b26-9a02-993e4e7edfa9")) __declspec(novtable) IIterable<Windows::Devices::I2c::I2cController> : impl_IIterable<Windows::Devices::I2c::I2cController> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_6ff64b72_a5aa_5986_b563_27612afb373c
#define WINRT_GENERIC_6ff64b72_a5aa_5986_b563_27612afb373c
template <> struct __declspec(uuid("6ff64b72-a5aa-5986-b563-27612afb373c")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::I2c::I2cController> : impl_AsyncOperationCompletedHandler<Windows::Devices::I2c::I2cController> {};
#endif

#ifndef WINRT_GENERIC_77f52ff7_aba0_54bb_891a_49351a838e33
#define WINRT_GENERIC_77f52ff7_aba0_54bb_891a_49351a838e33
template <> struct __declspec(uuid("77f52ff7-aba0-54bb-891a-49351a838e33")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::I2cController>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::I2cController>> {};
#endif

#ifndef WINRT_GENERIC_3b9d7cb1_ae0b_56af_8ed5_6856b1e7cd5b
#define WINRT_GENERIC_3b9d7cb1_ae0b_56af_8ed5_6856b1e7cd5b
template <> struct __declspec(uuid("3b9d7cb1-ae0b-56af-8ed5-6856b1e7cd5b")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::I2cController>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::I2cController>> {};
#endif


}

namespace Windows::Devices::I2c {

struct II2cConnectionSettings :
    Windows::Foundation::IInspectable,
    impl::consume<II2cConnectionSettings>
{
    II2cConnectionSettings(std::nullptr_t = nullptr) noexcept {}
};

struct II2cConnectionSettingsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<II2cConnectionSettingsFactory>
{
    II2cConnectionSettingsFactory(std::nullptr_t = nullptr) noexcept {}
};

struct II2cController :
    Windows::Foundation::IInspectable,
    impl::consume<II2cController>
{
    II2cController(std::nullptr_t = nullptr) noexcept {}
};

struct II2cControllerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<II2cControllerStatics>
{
    II2cControllerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct II2cDevice :
    Windows::Foundation::IInspectable,
    impl::consume<II2cDevice>,
    impl::require<II2cDevice, Windows::Foundation::IClosable>
{
    II2cDevice(std::nullptr_t = nullptr) noexcept {}
};

struct II2cDeviceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<II2cDeviceStatics>
{
    II2cDeviceStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
