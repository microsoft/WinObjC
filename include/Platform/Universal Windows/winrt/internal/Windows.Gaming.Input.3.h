// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Gaming.Input.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Gaming::Input {

struct WINRT_EBO ArcadeStick :
    Windows::Gaming::Input::IArcadeStick
{
    ArcadeStick(std::nullptr_t) noexcept {}
    static event_token ArcadeStickAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value);
    using ArcadeStickAdded_revoker = factory_event_revoker<IArcadeStickStatics>;
    static ArcadeStickAdded_revoker ArcadeStickAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value);
    static void ArcadeStickAdded(event_token token);
    static event_token ArcadeStickRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value);
    using ArcadeStickRemoved_revoker = factory_event_revoker<IArcadeStickStatics>;
    static ArcadeStickRemoved_revoker ArcadeStickRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value);
    static void ArcadeStickRemoved(event_token token);
    static Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::ArcadeStick> ArcadeSticks();
};

struct WINRT_EBO Gamepad :
    Windows::Gaming::Input::IGamepad,
    impl::require<Gamepad, Windows::Gaming::Input::IGamepad2>
{
    Gamepad(std::nullptr_t) noexcept {}
    static event_token GamepadAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value);
    using GamepadAdded_revoker = factory_event_revoker<IGamepadStatics>;
    static GamepadAdded_revoker GamepadAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value);
    static void GamepadAdded(event_token token);
    static event_token GamepadRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value);
    using GamepadRemoved_revoker = factory_event_revoker<IGamepadStatics>;
    static GamepadRemoved_revoker GamepadRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value);
    static void GamepadRemoved(event_token token);
    static Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::Gamepad> Gamepads();
};

struct WINRT_EBO Headset :
    Windows::Gaming::Input::IHeadset
{
    Headset(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RacingWheel :
    Windows::Gaming::Input::IRacingWheel
{
    RacingWheel(std::nullptr_t) noexcept {}
    static event_token RacingWheelAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value);
    using RacingWheelAdded_revoker = factory_event_revoker<IRacingWheelStatics>;
    static RacingWheelAdded_revoker RacingWheelAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value);
    static void RacingWheelAdded(event_token token);
    static event_token RacingWheelRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value);
    using RacingWheelRemoved_revoker = factory_event_revoker<IRacingWheelStatics>;
    static RacingWheelRemoved_revoker RacingWheelRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value);
    static void RacingWheelRemoved(event_token token);
    static Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::RacingWheel> RacingWheels();
};

struct WINRT_EBO UINavigationController :
    Windows::Gaming::Input::IUINavigationController
{
    UINavigationController(std::nullptr_t) noexcept {}
    static event_token UINavigationControllerAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value);
    using UINavigationControllerAdded_revoker = factory_event_revoker<IUINavigationControllerStatics>;
    static UINavigationControllerAdded_revoker UINavigationControllerAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value);
    static void UINavigationControllerAdded(event_token token);
    static event_token UINavigationControllerRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value);
    using UINavigationControllerRemoved_revoker = factory_event_revoker<IUINavigationControllerStatics>;
    static UINavigationControllerRemoved_revoker UINavigationControllerRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value);
    static void UINavigationControllerRemoved(event_token token);
    static Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::UINavigationController> UINavigationControllers();
};

}

}
