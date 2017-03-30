// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Gaming::Input {

struct ArcadeStickReading;
struct GamepadReading;
struct GamepadVibration;
struct RacingWheelReading;
struct UINavigationReading;

}

namespace Windows::Gaming::Input {

using ArcadeStickReading = ABI::Windows::Gaming::Input::ArcadeStickReading;
using GamepadReading = ABI::Windows::Gaming::Input::GamepadReading;
using GamepadVibration = ABI::Windows::Gaming::Input::GamepadVibration;
using RacingWheelReading = ABI::Windows::Gaming::Input::RacingWheelReading;
using UINavigationReading = ABI::Windows::Gaming::Input::UINavigationReading;

}

namespace ABI::Windows::Gaming::Input {

struct IArcadeStick;
struct IArcadeStickStatics;
struct IGameController;
struct IGamepad;
struct IGamepad2;
struct IGamepadStatics;
struct IHeadset;
struct IRacingWheel;
struct IRacingWheelStatics;
struct IUINavigationController;
struct IUINavigationControllerStatics;
struct ArcadeStick;
struct Gamepad;
struct Headset;
struct RacingWheel;
struct UINavigationController;

}

namespace Windows::Gaming::Input {

struct IArcadeStick;
struct IArcadeStickStatics;
struct IGameController;
struct IGamepad;
struct IGamepad2;
struct IGamepadStatics;
struct IHeadset;
struct IRacingWheel;
struct IRacingWheelStatics;
struct IUINavigationController;
struct IUINavigationControllerStatics;
struct ArcadeStick;
struct Gamepad;
struct Headset;
struct RacingWheel;
struct UINavigationController;

}

namespace Windows::Gaming::Input {

template <typename T> struct impl_IArcadeStick;
template <typename T> struct impl_IArcadeStickStatics;
template <typename T> struct impl_IGameController;
template <typename T> struct impl_IGamepad;
template <typename T> struct impl_IGamepad2;
template <typename T> struct impl_IGamepadStatics;
template <typename T> struct impl_IHeadset;
template <typename T> struct impl_IRacingWheel;
template <typename T> struct impl_IRacingWheelStatics;
template <typename T> struct impl_IUINavigationController;
template <typename T> struct impl_IUINavigationControllerStatics;

}

namespace Windows::Gaming::Input {

enum class ArcadeStickButtons : unsigned
{
    None = 0x0,
    StickUp = 0x1,
    StickDown = 0x2,
    StickLeft = 0x4,
    StickRight = 0x8,
    Action1 = 0x10,
    Action2 = 0x20,
    Action3 = 0x40,
    Action4 = 0x80,
    Action5 = 0x100,
    Action6 = 0x200,
    Special1 = 0x400,
    Special2 = 0x800,
};

DEFINE_ENUM_FLAG_OPERATORS(ArcadeStickButtons)

enum class GameControllerButtonLabel
{
    None = 0,
    XboxBack = 1,
    XboxStart = 2,
    XboxMenu = 3,
    XboxView = 4,
    XboxUp = 5,
    XboxDown = 6,
    XboxLeft = 7,
    XboxRight = 8,
    XboxA = 9,
    XboxB = 10,
    XboxX = 11,
    XboxY = 12,
    XboxLeftBumper = 13,
    XboxLeftTrigger = 14,
    XboxLeftStickButton = 15,
    XboxRightBumper = 16,
    XboxRightTrigger = 17,
    XboxRightStickButton = 18,
    XboxPaddle1 = 19,
    XboxPaddle2 = 20,
    XboxPaddle3 = 21,
    XboxPaddle4 = 22,
    Mode = 23,
    Select = 24,
    Menu = 25,
    View = 26,
    Back = 27,
    Start = 28,
    Options = 29,
    Share = 30,
    Up = 31,
    Down = 32,
    Left = 33,
    Right = 34,
    LetterA = 35,
    LetterB = 36,
    LetterC = 37,
    LetterL = 38,
    LetterR = 39,
    LetterX = 40,
    LetterY = 41,
    LetterZ = 42,
    Cross = 43,
    Circle = 44,
    Square = 45,
    Triangle = 46,
    LeftBumper = 47,
    LeftTrigger = 48,
    LeftStickButton = 49,
    Left1 = 50,
    Left2 = 51,
    Left3 = 52,
    RightBumper = 53,
    RightTrigger = 54,
    RightStickButton = 55,
    Right1 = 56,
    Right2 = 57,
    Right3 = 58,
    Paddle1 = 59,
    Paddle2 = 60,
    Paddle3 = 61,
    Paddle4 = 62,
    Plus = 63,
    Minus = 64,
    DownLeftArrow = 65,
    DialLeft = 66,
    DialRight = 67,
    Suspension = 68,
};

enum class GamepadButtons : unsigned
{
    None = 0x0,
    Menu = 0x1,
    View = 0x2,
    A = 0x4,
    B = 0x8,
    X = 0x10,
    Y = 0x20,
    DPadUp = 0x40,
    DPadDown = 0x80,
    DPadLeft = 0x100,
    DPadRight = 0x200,
    LeftShoulder = 0x400,
    RightShoulder = 0x800,
    LeftThumbstick = 0x1000,
    RightThumbstick = 0x2000,
    Paddle1 = 0x4000,
    Paddle2 = 0x8000,
    Paddle3 = 0x10000,
    Paddle4 = 0x20000,
};

DEFINE_ENUM_FLAG_OPERATORS(GamepadButtons)

enum class OptionalUINavigationButtons : unsigned
{
    None = 0x0,
    Context1 = 0x1,
    Context2 = 0x2,
    Context3 = 0x4,
    Context4 = 0x8,
    PageUp = 0x10,
    PageDown = 0x20,
    PageLeft = 0x40,
    PageRight = 0x80,
    ScrollUp = 0x100,
    ScrollDown = 0x200,
    ScrollLeft = 0x400,
    ScrollRight = 0x800,
};

DEFINE_ENUM_FLAG_OPERATORS(OptionalUINavigationButtons)

enum class RacingWheelButtons : unsigned
{
    None = 0x0,
    PreviousGear = 0x1,
    NextGear = 0x2,
    DPadUp = 0x4,
    DPadDown = 0x8,
    DPadLeft = 0x10,
    DPadRight = 0x20,
    Button1 = 0x40,
    Button2 = 0x80,
    Button3 = 0x100,
    Button4 = 0x200,
    Button5 = 0x400,
    Button6 = 0x800,
    Button7 = 0x1000,
    Button8 = 0x2000,
    Button9 = 0x4000,
    Button10 = 0x8000,
    Button11 = 0x10000,
    Button12 = 0x20000,
    Button13 = 0x40000,
    Button14 = 0x80000,
    Button15 = 0x100000,
    Button16 = 0x200000,
};

DEFINE_ENUM_FLAG_OPERATORS(RacingWheelButtons)

enum class RequiredUINavigationButtons : unsigned
{
    None = 0x0,
    Menu = 0x1,
    View = 0x2,
    Accept = 0x4,
    Cancel = 0x8,
    Up = 0x10,
    Down = 0x20,
    Left = 0x40,
    Right = 0x80,
};

DEFINE_ENUM_FLAG_OPERATORS(RequiredUINavigationButtons)

}

}
