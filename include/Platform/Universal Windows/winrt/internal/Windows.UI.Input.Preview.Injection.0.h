// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Input::Preview::Injection {

struct InjectedInputRectangle;
struct InjectedInputPoint;
struct InjectedInputPointerInfo;

}

namespace Windows::UI::Input::Preview::Injection {

using InjectedInputRectangle = ABI::Windows::UI::Input::Preview::Injection::InjectedInputRectangle;
using InjectedInputPoint = ABI::Windows::UI::Input::Preview::Injection::InjectedInputPoint;
using InjectedInputPointerInfo = ABI::Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo;

}

namespace ABI::Windows::UI::Input::Preview::Injection {

struct IInjectedInputKeyboardInfo;
struct IInjectedInputMouseInfo;
struct IInjectedInputPenInfo;
struct IInjectedInputTouchInfo;
struct IInputInjector;
struct IInputInjectorStatics;
struct InjectedInputKeyboardInfo;
struct InjectedInputMouseInfo;
struct InjectedInputPenInfo;
struct InjectedInputTouchInfo;
struct InputInjector;

}

namespace Windows::UI::Input::Preview::Injection {

struct IInjectedInputKeyboardInfo;
struct IInjectedInputMouseInfo;
struct IInjectedInputPenInfo;
struct IInjectedInputTouchInfo;
struct IInputInjector;
struct IInputInjectorStatics;
struct InjectedInputKeyboardInfo;
struct InjectedInputMouseInfo;
struct InjectedInputPenInfo;
struct InjectedInputTouchInfo;
struct InputInjector;

}

namespace Windows::UI::Input::Preview::Injection {

template <typename T> struct impl_IInjectedInputKeyboardInfo;
template <typename T> struct impl_IInjectedInputMouseInfo;
template <typename T> struct impl_IInjectedInputPenInfo;
template <typename T> struct impl_IInjectedInputTouchInfo;
template <typename T> struct impl_IInputInjector;
template <typename T> struct impl_IInputInjectorStatics;

}

namespace Windows::UI::Input::Preview::Injection {

enum class InjectedInputButtonChangeKind
{
    None = 0,
    FirstButtonDown = 1,
    FirstButtonUp = 2,
    SecondButtonDown = 3,
    SecondButtonUp = 4,
    ThirdButtonDown = 5,
    ThirdButtonUp = 6,
    FourthButtonDown = 7,
    FourthButtonUp = 8,
    FifthButtonDown = 9,
    FifthButtonUp = 10,
};

enum class InjectedInputKeyOptions : unsigned
{
    None = 0x0,
    ExtendedKey = 0x1,
    KeyUp = 0x2,
    ScanCode = 0x8,
    Unicode = 0x4,
};

DEFINE_ENUM_FLAG_OPERATORS(InjectedInputKeyOptions)

enum class InjectedInputMouseOptions : unsigned
{
    None = 0x0,
    Move = 0x1,
    LeftDown = 0x2,
    LeftUp = 0x4,
    RightDown = 0x8,
    RightUp = 0x10,
    MiddleDown = 0x20,
    MiddleUp = 0x40,
    XDown = 0x80,
    XUp = 0x100,
    Wheel = 0x800,
    HWheel = 0x1000,
    MoveNoCoalesce = 0x2000,
    VirtualDesk = 0x4000,
    Absolute = 0x8000,
};

DEFINE_ENUM_FLAG_OPERATORS(InjectedInputMouseOptions)

enum class InjectedInputPenButtons : unsigned
{
    None = 0x0,
    Barrel = 0x1,
    Inverted = 0x2,
    Eraser = 0x4,
};

DEFINE_ENUM_FLAG_OPERATORS(InjectedInputPenButtons)

enum class InjectedInputPenParameters : unsigned
{
    None = 0x0,
    Pressure = 0x1,
    Rotation = 0x2,
    TiltX = 0x4,
    TiltY = 0x8,
};

DEFINE_ENUM_FLAG_OPERATORS(InjectedInputPenParameters)

enum class InjectedInputPointerOptions : unsigned
{
    None = 0x0,
    New = 0x1,
    InRange = 0x2,
    InContact = 0x4,
    FirstButton = 0x10,
    SecondButton = 0x20,
    Primary = 0x2000,
    Confidence = 0x4000,
    Canceled = 0x8000,
    PointerDown = 0x10000,
    Update = 0x20000,
    PointerUp = 0x40000,
    CaptureChanged = 0x200000,
};

DEFINE_ENUM_FLAG_OPERATORS(InjectedInputPointerOptions)

enum class InjectedInputShortcut
{
    Back = 0,
    Start = 1,
    Search = 2,
};

enum class InjectedInputTouchParameters : unsigned
{
    None = 0x0,
    Contact = 0x1,
    Orientation = 0x2,
    Pressure = 0x4,
};

DEFINE_ENUM_FLAG_OPERATORS(InjectedInputTouchParameters)

enum class InjectedInputVisualizationMode
{
    None = 0,
    Default = 1,
    Indirect = 2,
};

}

}
