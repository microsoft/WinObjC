// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Input.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_cf5674f1_9808_5a2b_80b8_5684ed0ea816
#define WINRT_GENERIC_cf5674f1_9808_5a2b_80b8_5684ed0ea816
template <> struct __declspec(uuid("cf5674f1-9808-5a2b-80b8-5684ed0ea816")) __declspec(novtable) IVectorView<Windows::Devices::Input::PointerDevice> : impl_IVectorView<Windows::Devices::Input::PointerDevice> {};
#endif

#ifndef WINRT_GENERIC_8e5a2c7e_3830_50d5_92ba_3163c89cbbd0
#define WINRT_GENERIC_8e5a2c7e_3830_50d5_92ba_3163c89cbbd0
template <> struct __declspec(uuid("8e5a2c7e-3830-50d5-92ba-3163c89cbbd0")) __declspec(novtable) IVectorView<Windows::Devices::Input::PointerDeviceUsage> : impl_IVectorView<Windows::Devices::Input::PointerDeviceUsage> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5d72e594_28e4_5895_a34b_ea910f70fdbb
#define WINRT_GENERIC_5d72e594_28e4_5895_a34b_ea910f70fdbb
template <> struct __declspec(uuid("5d72e594-28e4-5895-a34b-ea910f70fdbb")) __declspec(novtable) TypedEventHandler<Windows::Devices::Input::MouseDevice, Windows::Devices::Input::MouseEventArgs> : impl_TypedEventHandler<Windows::Devices::Input::MouseDevice, Windows::Devices::Input::MouseEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_de94641c_7960_5fcd_abe8_d6ba609ef7d3
#define WINRT_GENERIC_de94641c_7960_5fcd_abe8_d6ba609ef7d3
template <> struct __declspec(uuid("de94641c-7960-5fcd-abe8-d6ba609ef7d3")) __declspec(novtable) IIterator<Windows::Devices::Input::PointerDevice> : impl_IIterator<Windows::Devices::Input::PointerDevice> {};
#endif

#ifndef WINRT_GENERIC_ad26662c_845b_5c6d_aeaa_406f48c21ae9
#define WINRT_GENERIC_ad26662c_845b_5c6d_aeaa_406f48c21ae9
template <> struct __declspec(uuid("ad26662c-845b-5c6d-aeaa-406f48c21ae9")) __declspec(novtable) IIterable<Windows::Devices::Input::PointerDevice> : impl_IIterable<Windows::Devices::Input::PointerDevice> {};
#endif

#ifndef WINRT_GENERIC_9ab2160d_11ef_5eca_8dd9_3e13aa4e5f99
#define WINRT_GENERIC_9ab2160d_11ef_5eca_8dd9_3e13aa4e5f99
template <> struct __declspec(uuid("9ab2160d-11ef-5eca-8dd9-3e13aa4e5f99")) __declspec(novtable) IIterator<Windows::Devices::Input::PointerDeviceUsage> : impl_IIterator<Windows::Devices::Input::PointerDeviceUsage> {};
#endif

#ifndef WINRT_GENERIC_592d6618_eaab_5a79_a47a_c7fc0b749a4e
#define WINRT_GENERIC_592d6618_eaab_5a79_a47a_c7fc0b749a4e
template <> struct __declspec(uuid("592d6618-eaab-5a79-a47a-c7fc0b749a4e")) __declspec(novtable) IIterable<Windows::Devices::Input::PointerDeviceUsage> : impl_IIterable<Windows::Devices::Input::PointerDeviceUsage> {};
#endif


}

namespace Windows::Devices::Input {

struct IKeyboardCapabilities :
    Windows::Foundation::IInspectable,
    impl::consume<IKeyboardCapabilities>
{
    IKeyboardCapabilities(std::nullptr_t = nullptr) noexcept {}
};

struct IMouseCapabilities :
    Windows::Foundation::IInspectable,
    impl::consume<IMouseCapabilities>
{
    IMouseCapabilities(std::nullptr_t = nullptr) noexcept {}
};

struct IMouseDevice :
    Windows::Foundation::IInspectable,
    impl::consume<IMouseDevice>
{
    IMouseDevice(std::nullptr_t = nullptr) noexcept {}
};

struct IMouseDeviceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IMouseDeviceStatics>
{
    IMouseDeviceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IMouseEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMouseEventArgs>
{
    IMouseEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPointerDevice :
    Windows::Foundation::IInspectable,
    impl::consume<IPointerDevice>
{
    IPointerDevice(std::nullptr_t = nullptr) noexcept {}
};

struct IPointerDevice2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPointerDevice2>
{
    IPointerDevice2(std::nullptr_t = nullptr) noexcept {}
};

struct IPointerDeviceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPointerDeviceStatics>
{
    IPointerDeviceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ITouchCapabilities :
    Windows::Foundation::IInspectable,
    impl::consume<ITouchCapabilities>
{
    ITouchCapabilities(std::nullptr_t = nullptr) noexcept {}
};

}

}
