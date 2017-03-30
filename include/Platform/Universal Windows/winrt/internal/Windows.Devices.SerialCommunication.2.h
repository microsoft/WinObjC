// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.SerialCommunication.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_44ef26ed_c1ff_546a_a46b_6a37de9187fb
#define WINRT_GENERIC_44ef26ed_c1ff_546a_a46b_6a37de9187fb
template <> struct __declspec(uuid("44ef26ed-c1ff-546a-a46b-6a37de9187fb")) __declspec(novtable) IAsyncOperation<Windows::Devices::SerialCommunication::SerialDevice> : impl_IAsyncOperation<Windows::Devices::SerialCommunication::SerialDevice> {};
#endif

#ifndef WINRT_GENERIC_d92ea323_b7bf_5e02_b9fb_c61f97d080e9
#define WINRT_GENERIC_d92ea323_b7bf_5e02_b9fb_c61f97d080e9
template <> struct __declspec(uuid("d92ea323-b7bf-5e02-b9fb-c61f97d080e9")) __declspec(novtable) TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::ErrorReceivedEventArgs> : impl_TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::ErrorReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_e496c3ef_5802_5ac4_ac2e_96bc23fa9447
#define WINRT_GENERIC_e496c3ef_5802_5ac4_ac2e_96bc23fa9447
template <> struct __declspec(uuid("e496c3ef-5802-5ac4-ac2e-96bc23fa9447")) __declspec(novtable) TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::PinChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::SerialCommunication::SerialDevice, Windows::Devices::SerialCommunication::PinChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_84a34b33_06fc_5e63_8ee2_eab4ff69acb7
#define WINRT_GENERIC_84a34b33_06fc_5e63_8ee2_eab4ff69acb7
template <> struct __declspec(uuid("84a34b33-06fc-5e63-8ee2-eab4ff69acb7")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::SerialCommunication::SerialDevice> : impl_AsyncOperationCompletedHandler<Windows::Devices::SerialCommunication::SerialDevice> {};
#endif


}

namespace Windows::Devices::SerialCommunication {

struct IErrorReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IErrorReceivedEventArgs>
{
    IErrorReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPinChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPinChangedEventArgs>
{
    IPinChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISerialDevice :
    Windows::Foundation::IInspectable,
    impl::consume<ISerialDevice>,
    impl::require<ISerialDevice, Windows::Foundation::IClosable>
{
    ISerialDevice(std::nullptr_t = nullptr) noexcept {}
};

struct ISerialDeviceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISerialDeviceStatics>
{
    ISerialDeviceStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
