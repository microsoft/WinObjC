// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Input {

struct PointerDeviceUsage;
struct MouseDelta;

}

namespace Windows::Devices::Input {

using PointerDeviceUsage = ABI::Windows::Devices::Input::PointerDeviceUsage;
using MouseDelta = ABI::Windows::Devices::Input::MouseDelta;

}

namespace ABI::Windows::Devices::Input {

struct IKeyboardCapabilities;
struct IMouseCapabilities;
struct IMouseDevice;
struct IMouseDeviceStatics;
struct IMouseEventArgs;
struct IPointerDevice;
struct IPointerDevice2;
struct IPointerDeviceStatics;
struct ITouchCapabilities;
struct KeyboardCapabilities;
struct MouseCapabilities;
struct MouseDevice;
struct MouseEventArgs;
struct PointerDevice;
struct TouchCapabilities;

}

namespace Windows::Devices::Input {

struct IKeyboardCapabilities;
struct IMouseCapabilities;
struct IMouseDevice;
struct IMouseDeviceStatics;
struct IMouseEventArgs;
struct IPointerDevice;
struct IPointerDevice2;
struct IPointerDeviceStatics;
struct ITouchCapabilities;
struct KeyboardCapabilities;
struct MouseCapabilities;
struct MouseDevice;
struct MouseEventArgs;
struct PointerDevice;
struct TouchCapabilities;

}

namespace Windows::Devices::Input {

template <typename T> struct impl_IKeyboardCapabilities;
template <typename T> struct impl_IMouseCapabilities;
template <typename T> struct impl_IMouseDevice;
template <typename T> struct impl_IMouseDeviceStatics;
template <typename T> struct impl_IMouseEventArgs;
template <typename T> struct impl_IPointerDevice;
template <typename T> struct impl_IPointerDevice2;
template <typename T> struct impl_IPointerDeviceStatics;
template <typename T> struct impl_ITouchCapabilities;

}

namespace Windows::Devices::Input {

enum class PointerDeviceType
{
    Touch = 0,
    Pen = 1,
    Mouse = 2,
};

}

}
