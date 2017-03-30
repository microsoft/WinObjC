// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Power.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_4d4aa646_767f_5645_af5c_546464d3ec09
#define WINRT_GENERIC_4d4aa646_767f_5645_af5c_546464d3ec09
template <> struct __declspec(uuid("4d4aa646-767f-5645-af5c-546464d3ec09")) __declspec(novtable) TypedEventHandler<Windows::Devices::Power::Battery, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Devices::Power::Battery, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_548cefbd_bc8a_5fa0_8df2_957440fc8bf4
#define WINRT_GENERIC_548cefbd_bc8a_5fa0_8df2_957440fc8bf4
template <> struct __declspec(uuid("548cefbd-bc8a-5fa0-8df2-957440fc8bf4")) __declspec(novtable) IReference<int32_t> : impl_IReference<int32_t> {};
#endif

#ifndef WINRT_GENERIC_daa3d556_1529_56d2_a5f8_bfb6c22a3dfe
#define WINRT_GENERIC_daa3d556_1529_56d2_a5f8_bfb6c22a3dfe
template <> struct __declspec(uuid("daa3d556-1529-56d2-a5f8-bfb6c22a3dfe")) __declspec(novtable) IAsyncOperation<Windows::Devices::Power::Battery> : impl_IAsyncOperation<Windows::Devices::Power::Battery> {};
#endif

#ifndef WINRT_GENERIC_97f82115_3822_507b_82e6_2777b336e98e
#define WINRT_GENERIC_97f82115_3822_507b_82e6_2777b336e98e
template <> struct __declspec(uuid("97f82115-3822-507b-82e6-2777b336e98e")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Power::Battery> : impl_AsyncOperationCompletedHandler<Windows::Devices::Power::Battery> {};
#endif


}

namespace Windows::Devices::Power {

struct IBattery :
    Windows::Foundation::IInspectable,
    impl::consume<IBattery>
{
    IBattery(std::nullptr_t = nullptr) noexcept {}
};

struct IBatteryReport :
    Windows::Foundation::IInspectable,
    impl::consume<IBatteryReport>
{
    IBatteryReport(std::nullptr_t = nullptr) noexcept {}
};

struct IBatteryStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IBatteryStatics>
{
    IBatteryStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
