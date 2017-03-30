// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.UI.Input.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cb5bc6b5_eee7_57a8_9563_eb0b2b8eb11f
#define WINRT_GENERIC_cb5bc6b5_eee7_57a8_9563_eb0b2b8eb11f
template <> struct __declspec(uuid("cb5bc6b5-eee7-57a8-9563-eb0b2b8eb11f")) __declspec(novtable) EventHandler<Windows::Phone::UI::Input::BackPressedEventArgs> : impl_EventHandler<Windows::Phone::UI::Input::BackPressedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_f5a60452_1495_5198_9c7c_758ddfe6613b
#define WINRT_GENERIC_f5a60452_1495_5198_9c7c_758ddfe6613b
template <> struct __declspec(uuid("f5a60452-1495-5198-9c7c-758ddfe6613b")) __declspec(novtable) EventHandler<Windows::Phone::UI::Input::CameraEventArgs> : impl_EventHandler<Windows::Phone::UI::Input::CameraEventArgs> {};
#endif


}

namespace Windows::Phone::UI::Input {

struct IBackPressedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IBackPressedEventArgs>
{
    IBackPressedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ICameraEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ICameraEventArgs>
{
    ICameraEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IHardwareButtonsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IHardwareButtonsStatics>
{
    IHardwareButtonsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IHardwareButtonsStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IHardwareButtonsStatics2>
{
    IHardwareButtonsStatics2(std::nullptr_t = nullptr) noexcept {}
};

}

}
