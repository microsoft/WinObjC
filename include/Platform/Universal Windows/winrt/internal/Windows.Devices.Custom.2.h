// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Custom.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif

#ifndef WINRT_GENERIC_ef60385f_be78_584b_aaef_7829ada2b0de
#define WINRT_GENERIC_ef60385f_be78_584b_aaef_7829ada2b0de
template <> struct __declspec(uuid("ef60385f-be78-584b-aaef-7829ada2b0de")) __declspec(novtable) IAsyncOperation<uint32_t> : impl_IAsyncOperation<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_2a6344aa_0568_548e_a1a2_b6bb451d228c
#define WINRT_GENERIC_2a6344aa_0568_548e_a1a2_b6bb451d228c
template <> struct __declspec(uuid("2a6344aa-0568-548e-a1a2-b6bb451d228c")) __declspec(novtable) IAsyncOperation<Windows::Devices::Custom::CustomDevice> : impl_IAsyncOperation<Windows::Devices::Custom::CustomDevice> {};
#endif

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif

#ifndef WINRT_GENERIC_9343b6e7_e3d2_5e4a_ab2d_2bce4919a6a4
#define WINRT_GENERIC_9343b6e7_e3d2_5e4a_ab2d_2bce4919a6a4
template <> struct __declspec(uuid("9343b6e7-e3d2-5e4a-ab2d-2bce4919a6a4")) __declspec(novtable) AsyncOperationCompletedHandler<uint32_t> : impl_AsyncOperationCompletedHandler<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_1fdd39b0_e0e5_5c59_b27d_a549b1075ce9
#define WINRT_GENERIC_1fdd39b0_e0e5_5c59_b27d_a549b1075ce9
template <> struct __declspec(uuid("1fdd39b0-e0e5-5c59-b27d-a549b1075ce9")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Custom::CustomDevice> : impl_AsyncOperationCompletedHandler<Windows::Devices::Custom::CustomDevice> {};
#endif


}

namespace Windows::Devices::Custom {

struct ICustomDevice :
    Windows::Foundation::IInspectable,
    impl::consume<ICustomDevice>
{
    ICustomDevice(std::nullptr_t = nullptr) noexcept {}
};

struct ICustomDeviceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICustomDeviceStatics>
{
    ICustomDeviceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IIOControlCode :
    Windows::Foundation::IInspectable,
    impl::consume<IIOControlCode>
{
    IIOControlCode(std::nullptr_t = nullptr) noexcept {}
};

struct IIOControlCodeFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IIOControlCodeFactory>
{
    IIOControlCodeFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IKnownDeviceTypesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKnownDeviceTypesStatics>
{
    IKnownDeviceTypesStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
