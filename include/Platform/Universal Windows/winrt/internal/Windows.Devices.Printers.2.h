// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Printers.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_7cfc4a8f_5eb7_5af7_bc9f_78a7e407cd2e
#define WINRT_GENERIC_7cfc4a8f_5eb7_5af7_bc9f_78a7e407cd2e
template <> struct __declspec(uuid("7cfc4a8f-5eb7-5af7-bc9f-78a7e407cd2e")) __declspec(novtable) IAsyncOperation<Windows::Devices::Printers::Print3DDevice> : impl_IAsyncOperation<Windows::Devices::Printers::Print3DDevice> {};
#endif

#ifndef WINRT_GENERIC_c4a57c5e_32b0_55b3_ad13_ce1c23041ed6
#define WINRT_GENERIC_c4a57c5e_32b0_55b3_ad13_ce1c23041ed6
template <> struct __declspec(uuid("c4a57c5e-32b0-55b3-ad13-ce1c23041ed6")) __declspec(novtable) IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> : impl_IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> {};
#endif

#ifndef WINRT_GENERIC_8d4b123f_4343_5195_bbc9_b99e956e057f
#define WINRT_GENERIC_8d4b123f_4343_5195_bbc9_b99e956e057f
template <> struct __declspec(uuid("8d4b123f-4343-5195-bbc9-b99e956e057f")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Printers::Print3DDevice> : impl_AsyncOperationCompletedHandler<Windows::Devices::Printers::Print3DDevice> {};
#endif

#ifndef WINRT_GENERIC_3dddecf4_1d39_58e8_83b1_dbed541c7f35
#define WINRT_GENERIC_3dddecf4_1d39_58e8_83b1_dbed541c7f35
template <> struct __declspec(uuid("3dddecf4-1d39-58e8-83b1-dbed541c7f35")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::Streams::IRandomAccessStreamWithContentType> : impl_AsyncOperationCompletedHandler<Windows::Storage::Streams::IRandomAccessStreamWithContentType> {};
#endif


}

namespace Windows::Devices::Printers {

struct IPrint3DDevice :
    Windows::Foundation::IInspectable,
    impl::consume<IPrint3DDevice>
{
    IPrint3DDevice(std::nullptr_t = nullptr) noexcept {}
};

struct IPrint3DDeviceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPrint3DDeviceStatics>
{
    IPrint3DDeviceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintSchema :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintSchema>
{
    IPrintSchema(std::nullptr_t = nullptr) noexcept {}
};

}

}
