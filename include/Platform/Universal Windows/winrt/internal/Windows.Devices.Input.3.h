// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Input.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Input {

struct WINRT_EBO KeyboardCapabilities :
    Windows::Devices::Input::IKeyboardCapabilities
{
    KeyboardCapabilities(std::nullptr_t) noexcept {}
    KeyboardCapabilities();
};

struct WINRT_EBO MouseCapabilities :
    Windows::Devices::Input::IMouseCapabilities
{
    MouseCapabilities(std::nullptr_t) noexcept {}
    MouseCapabilities();
};

struct WINRT_EBO MouseDevice :
    Windows::Devices::Input::IMouseDevice
{
    MouseDevice(std::nullptr_t) noexcept {}
    static Windows::Devices::Input::MouseDevice GetForCurrentView();
};

struct WINRT_EBO MouseEventArgs :
    Windows::Devices::Input::IMouseEventArgs
{
    MouseEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PointerDevice :
    Windows::Devices::Input::IPointerDevice,
    impl::require<PointerDevice, Windows::Devices::Input::IPointerDevice2>
{
    PointerDevice(std::nullptr_t) noexcept {}
    static Windows::Devices::Input::PointerDevice GetPointerDevice(uint32_t pointerId);
    static Windows::Foundation::Collections::IVectorView<Windows::Devices::Input::PointerDevice> GetPointerDevices();
};

struct WINRT_EBO TouchCapabilities :
    Windows::Devices::Input::ITouchCapabilities
{
    TouchCapabilities(std::nullptr_t) noexcept {}
    TouchCapabilities();
};

}

}
