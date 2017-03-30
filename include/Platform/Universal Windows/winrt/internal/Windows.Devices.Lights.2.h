// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Lights.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_52a69dfd_f0d6_5931_b8e1_f38066d71bf2
#define WINRT_GENERIC_52a69dfd_f0d6_5931_b8e1_f38066d71bf2
template <> struct __declspec(uuid("52a69dfd-f0d6-5931-b8e1-f38066d71bf2")) __declspec(novtable) IAsyncOperation<Windows::Devices::Lights::Lamp> : impl_IAsyncOperation<Windows::Devices::Lights::Lamp> {};
#endif

#ifndef WINRT_GENERIC_556a02d9_7685_576f_89ca_b62dc481d29d
#define WINRT_GENERIC_556a02d9_7685_576f_89ca_b62dc481d29d
template <> struct __declspec(uuid("556a02d9-7685-576f-89ca-b62dc481d29d")) __declspec(novtable) TypedEventHandler<Windows::Devices::Lights::Lamp, Windows::Devices::Lights::LampAvailabilityChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Lights::Lamp, Windows::Devices::Lights::LampAvailabilityChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_191a8c6e_60dd_5a21_a53c_bf3f940a1dde
#define WINRT_GENERIC_191a8c6e_60dd_5a21_a53c_bf3f940a1dde
template <> struct __declspec(uuid("191a8c6e-60dd-5a21-a53c-bf3f940a1dde")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Lights::Lamp> : impl_AsyncOperationCompletedHandler<Windows::Devices::Lights::Lamp> {};
#endif


}

namespace Windows::Devices::Lights {

struct ILamp :
    Windows::Foundation::IInspectable,
    impl::consume<ILamp>,
    impl::require<ILamp, Windows::Foundation::IClosable>
{
    ILamp(std::nullptr_t = nullptr) noexcept {}
};

struct ILampAvailabilityChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ILampAvailabilityChangedEventArgs>
{
    ILampAvailabilityChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ILampStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ILampStatics>
{
    ILampStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
