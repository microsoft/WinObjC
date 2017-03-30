// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Sensors.Custom.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
#define WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
template <> struct __declspec(uuid("09335560-6c6b-5a26-9348-97b781132b20")) __declspec(novtable) IKeyValuePair<hstring, Windows::Foundation::IInspectable> : impl_IKeyValuePair<hstring, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
#define WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
template <> struct __declspec(uuid("bb78502a-f79d-54fa-92c9-90c5039fdf7e")) __declspec(novtable) IMapView<hstring, Windows::Foundation::IInspectable> : impl_IMapView<hstring, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_7fbfbe55_9674_54e3_a269_9caa820ed23c
#define WINRT_GENERIC_7fbfbe55_9674_54e3_a269_9caa820ed23c
template <> struct __declspec(uuid("7fbfbe55-9674-54e3-a269-9caa820ed23c")) __declspec(novtable) IAsyncOperation<Windows::Devices::Sensors::Custom::CustomSensor> : impl_IAsyncOperation<Windows::Devices::Sensors::Custom::CustomSensor> {};
#endif

#ifndef WINRT_GENERIC_aa9460cb_f08c_5963_b232_cc4075e984e7
#define WINRT_GENERIC_aa9460cb_f08c_5963_b232_cc4075e984e7
template <> struct __declspec(uuid("aa9460cb-f08c-5963-b232-cc4075e984e7")) __declspec(novtable) TypedEventHandler<Windows::Devices::Sensors::Custom::CustomSensor, Windows::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Sensors::Custom::CustomSensor, Windows::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_808b62d7_6e02_5680_a59e_118a98a4e70f
#define WINRT_GENERIC_808b62d7_6e02_5680_a59e_118a98a4e70f
template <> struct __declspec(uuid("808b62d7-6e02-5680-a59e-118a98a4e70f")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Sensors::Custom::CustomSensor> : impl_AsyncOperationCompletedHandler<Windows::Devices::Sensors::Custom::CustomSensor> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
#define WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
template <> struct __declspec(uuid("fe2f3d47-5d47-5499-8374-430c7cda0204")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif

#ifndef WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
#define WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
template <> struct __declspec(uuid("5db5fa32-707c-5849-a06b-91c8eb9d10e8")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace Windows::Devices::Sensors::Custom {

struct ICustomSensor :
    Windows::Foundation::IInspectable,
    impl::consume<ICustomSensor>
{
    ICustomSensor(std::nullptr_t = nullptr) noexcept {}
};

struct ICustomSensorReading :
    Windows::Foundation::IInspectable,
    impl::consume<ICustomSensorReading>
{
    ICustomSensorReading(std::nullptr_t = nullptr) noexcept {}
};

struct ICustomSensorReadingChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ICustomSensorReadingChangedEventArgs>
{
    ICustomSensorReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ICustomSensorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICustomSensorStatics>
{
    ICustomSensorStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
