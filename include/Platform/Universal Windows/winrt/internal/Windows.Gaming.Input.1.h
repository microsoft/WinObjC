// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Gaming.Input.0.h"
#include "Windows.Gaming.Input.ForceFeedback.0.h"
#include "Windows.System.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.System.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Gaming::Input {

struct ArcadeStickReading
{
    uint64_t Timestamp;
    winrt::Windows::Gaming::Input::ArcadeStickButtons Buttons;
};

struct GamepadReading
{
    uint64_t Timestamp;
    winrt::Windows::Gaming::Input::GamepadButtons Buttons;
    double LeftTrigger;
    double RightTrigger;
    double LeftThumbstickX;
    double LeftThumbstickY;
    double RightThumbstickX;
    double RightThumbstickY;
};

struct GamepadVibration
{
    double LeftMotor;
    double RightMotor;
    double LeftTrigger;
    double RightTrigger;
};

struct RacingWheelReading
{
    uint64_t Timestamp;
    winrt::Windows::Gaming::Input::RacingWheelButtons Buttons;
    int32_t PatternShifterGear;
    double Wheel;
    double Throttle;
    double Brake;
    double Clutch;
    double Handbrake;
};

struct UINavigationReading
{
    uint64_t Timestamp;
    winrt::Windows::Gaming::Input::RequiredUINavigationButtons RequiredButtons;
    winrt::Windows::Gaming::Input::OptionalUINavigationButtons OptionalButtons;
};

}

namespace Windows::Gaming::Input {

using ArcadeStickReading = ABI::Windows::Gaming::Input::ArcadeStickReading;
using GamepadReading = ABI::Windows::Gaming::Input::GamepadReading;
using GamepadVibration = ABI::Windows::Gaming::Input::GamepadVibration;
using RacingWheelReading = ABI::Windows::Gaming::Input::RacingWheelReading;
using UINavigationReading = ABI::Windows::Gaming::Input::UINavigationReading;

}

namespace ABI::Windows::Gaming::Input {

struct __declspec(uuid("b14a539d-befb-4c81-8051-15ecf3b13036")) __declspec(novtable) IArcadeStick : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetButtonLabel(winrt::Windows::Gaming::Input::ArcadeStickButtons button, winrt::Windows::Gaming::Input::GameControllerButtonLabel * value) = 0;
    virtual HRESULT __stdcall abi_GetCurrentReading(Windows::Gaming::Input::ArcadeStickReading * value) = 0;
};

struct __declspec(uuid("5c37b8c8-37b1-4ad8-9458-200f1a30018e")) __declspec(novtable) IArcadeStickStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_ArcadeStickAdded(Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ArcadeStickAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_ArcadeStickRemoved(Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ArcadeStickRemoved(event_token token) = 0;
    virtual HRESULT __stdcall get_ArcadeSticks(Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::ArcadeStick> ** value) = 0;
};

struct __declspec(uuid("1baf6522-5f64-42c5-8267-b9fe2215bfbd")) __declspec(novtable) IGameController : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_HeadsetConnected(Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::Gaming::Input::Headset> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_HeadsetConnected(event_token token) = 0;
    virtual HRESULT __stdcall add_HeadsetDisconnected(Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::Gaming::Input::Headset> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_HeadsetDisconnected(event_token token) = 0;
    virtual HRESULT __stdcall add_UserChanged(Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::System::UserChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UserChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_Headset(Windows::Gaming::Input::IHeadset ** value) = 0;
    virtual HRESULT __stdcall get_IsWireless(bool * value) = 0;
    virtual HRESULT __stdcall get_User(Windows::System::IUser ** value) = 0;
};

struct __declspec(uuid("bc7bb43c-0a69-3903-9e9d-a50f86a45de5")) __declspec(novtable) IGamepad : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Vibration(Windows::Gaming::Input::GamepadVibration * value) = 0;
    virtual HRESULT __stdcall put_Vibration(Windows::Gaming::Input::GamepadVibration value) = 0;
    virtual HRESULT __stdcall abi_GetCurrentReading(Windows::Gaming::Input::GamepadReading * value) = 0;
};

struct __declspec(uuid("3c1689bd-5915-4245-b0c0-c89fae0308ff")) __declspec(novtable) IGamepad2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetButtonLabel(winrt::Windows::Gaming::Input::GamepadButtons button, winrt::Windows::Gaming::Input::GameControllerButtonLabel * value) = 0;
};

struct __declspec(uuid("8bbce529-d49c-39e9-9560-e47dde96b7c8")) __declspec(novtable) IGamepadStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_GamepadAdded(Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_GamepadAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_GamepadRemoved(Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_GamepadRemoved(event_token token) = 0;
    virtual HRESULT __stdcall get_Gamepads(Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::Gamepad> ** value) = 0;
};

struct __declspec(uuid("3fd156ef-6925-3fa8-9181-029c5223ae3b")) __declspec(novtable) IHeadset : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CaptureDeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_RenderDeviceId(hstring * value) = 0;
};

struct __declspec(uuid("f546656f-e106-4c82-a90f-554012904b85")) __declspec(novtable) IRacingWheel : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HasClutch(bool * value) = 0;
    virtual HRESULT __stdcall get_HasHandbrake(bool * value) = 0;
    virtual HRESULT __stdcall get_HasPatternShifter(bool * value) = 0;
    virtual HRESULT __stdcall get_MaxPatternShifterGear(int32_t * value) = 0;
    virtual HRESULT __stdcall get_MaxWheelAngle(double * value) = 0;
    virtual HRESULT __stdcall get_WheelMotor(Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor ** value) = 0;
    virtual HRESULT __stdcall abi_GetButtonLabel(winrt::Windows::Gaming::Input::RacingWheelButtons button, winrt::Windows::Gaming::Input::GameControllerButtonLabel * value) = 0;
    virtual HRESULT __stdcall abi_GetCurrentReading(Windows::Gaming::Input::RacingWheelReading * value) = 0;
};

struct __declspec(uuid("3ac12cd5-581b-4936-9f94-69f1e6514c7d")) __declspec(novtable) IRacingWheelStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_RacingWheelAdded(Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RacingWheelAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_RacingWheelRemoved(Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RacingWheelRemoved(event_token token) = 0;
    virtual HRESULT __stdcall get_RacingWheels(Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::RacingWheel> ** value) = 0;
};

struct __declspec(uuid("e5aeefdd-f50e-4a55-8cdc-d33229548175")) __declspec(novtable) IUINavigationController : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrentReading(Windows::Gaming::Input::UINavigationReading * value) = 0;
    virtual HRESULT __stdcall abi_GetOptionalButtonLabel(winrt::Windows::Gaming::Input::OptionalUINavigationButtons button, winrt::Windows::Gaming::Input::GameControllerButtonLabel * value) = 0;
    virtual HRESULT __stdcall abi_GetRequiredButtonLabel(winrt::Windows::Gaming::Input::RequiredUINavigationButtons button, winrt::Windows::Gaming::Input::GameControllerButtonLabel * value) = 0;
};

struct __declspec(uuid("2f14930a-f6f8-4a48-8d89-94786cca0c2e")) __declspec(novtable) IUINavigationControllerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_UINavigationControllerAdded(Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UINavigationControllerAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_UINavigationControllerRemoved(Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UINavigationControllerRemoved(event_token token) = 0;
    virtual HRESULT __stdcall get_UINavigationControllers(Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::UINavigationController> ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Gaming::Input::ArcadeStick> { using default_interface = Windows::Gaming::Input::IArcadeStick; };
template <> struct traits<Windows::Gaming::Input::Gamepad> { using default_interface = Windows::Gaming::Input::IGamepad; };
template <> struct traits<Windows::Gaming::Input::Headset> { using default_interface = Windows::Gaming::Input::IHeadset; };
template <> struct traits<Windows::Gaming::Input::RacingWheel> { using default_interface = Windows::Gaming::Input::IRacingWheel; };
template <> struct traits<Windows::Gaming::Input::UINavigationController> { using default_interface = Windows::Gaming::Input::IUINavigationController; };

}

namespace Windows::Gaming::Input {

template <typename D>
struct WINRT_EBO impl_IArcadeStick
{
    Windows::Gaming::Input::GameControllerButtonLabel GetButtonLabel(Windows::Gaming::Input::ArcadeStickButtons button) const;
    Windows::Gaming::Input::ArcadeStickReading GetCurrentReading() const;
};

template <typename D>
struct WINRT_EBO impl_IArcadeStickStatics
{
    event_token ArcadeStickAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value) const;
    using ArcadeStickAdded_revoker = event_revoker<IArcadeStickStatics>;
    ArcadeStickAdded_revoker ArcadeStickAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value) const;
    void ArcadeStickAdded(event_token token) const;
    event_token ArcadeStickRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value) const;
    using ArcadeStickRemoved_revoker = event_revoker<IArcadeStickStatics>;
    ArcadeStickRemoved_revoker ArcadeStickRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value) const;
    void ArcadeStickRemoved(event_token token) const;
    Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::ArcadeStick> ArcadeSticks() const;
};

template <typename D>
struct WINRT_EBO impl_IGameController
{
    event_token HeadsetConnected(const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::Gaming::Input::Headset> & value) const;
    using HeadsetConnected_revoker = event_revoker<IGameController>;
    HeadsetConnected_revoker HeadsetConnected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::Gaming::Input::Headset> & value) const;
    void HeadsetConnected(event_token token) const;
    event_token HeadsetDisconnected(const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::Gaming::Input::Headset> & value) const;
    using HeadsetDisconnected_revoker = event_revoker<IGameController>;
    HeadsetDisconnected_revoker HeadsetDisconnected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::Gaming::Input::Headset> & value) const;
    void HeadsetDisconnected(event_token token) const;
    event_token UserChanged(const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::System::UserChangedEventArgs> & value) const;
    using UserChanged_revoker = event_revoker<IGameController>;
    UserChanged_revoker UserChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::System::UserChangedEventArgs> & value) const;
    void UserChanged(event_token token) const;
    Windows::Gaming::Input::Headset Headset() const;
    bool IsWireless() const;
    Windows::System::User User() const;
};

template <typename D>
struct WINRT_EBO impl_IGamepad
{
    Windows::Gaming::Input::GamepadVibration Vibration() const;
    void Vibration(const Windows::Gaming::Input::GamepadVibration & value) const;
    Windows::Gaming::Input::GamepadReading GetCurrentReading() const;
};

template <typename D>
struct WINRT_EBO impl_IGamepad2
{
    Windows::Gaming::Input::GameControllerButtonLabel GetButtonLabel(Windows::Gaming::Input::GamepadButtons button) const;
};

template <typename D>
struct WINRT_EBO impl_IGamepadStatics
{
    event_token GamepadAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value) const;
    using GamepadAdded_revoker = event_revoker<IGamepadStatics>;
    GamepadAdded_revoker GamepadAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value) const;
    void GamepadAdded(event_token token) const;
    event_token GamepadRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value) const;
    using GamepadRemoved_revoker = event_revoker<IGamepadStatics>;
    GamepadRemoved_revoker GamepadRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value) const;
    void GamepadRemoved(event_token token) const;
    Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::Gamepad> Gamepads() const;
};

template <typename D>
struct WINRT_EBO impl_IHeadset
{
    hstring CaptureDeviceId() const;
    hstring RenderDeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_IRacingWheel
{
    bool HasClutch() const;
    bool HasHandbrake() const;
    bool HasPatternShifter() const;
    int32_t MaxPatternShifterGear() const;
    double MaxWheelAngle() const;
    Windows::Gaming::Input::ForceFeedback::ForceFeedbackMotor WheelMotor() const;
    Windows::Gaming::Input::GameControllerButtonLabel GetButtonLabel(Windows::Gaming::Input::RacingWheelButtons button) const;
    Windows::Gaming::Input::RacingWheelReading GetCurrentReading() const;
};

template <typename D>
struct WINRT_EBO impl_IRacingWheelStatics
{
    event_token RacingWheelAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value) const;
    using RacingWheelAdded_revoker = event_revoker<IRacingWheelStatics>;
    RacingWheelAdded_revoker RacingWheelAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value) const;
    void RacingWheelAdded(event_token token) const;
    event_token RacingWheelRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value) const;
    using RacingWheelRemoved_revoker = event_revoker<IRacingWheelStatics>;
    RacingWheelRemoved_revoker RacingWheelRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value) const;
    void RacingWheelRemoved(event_token token) const;
    Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::RacingWheel> RacingWheels() const;
};

template <typename D>
struct WINRT_EBO impl_IUINavigationController
{
    Windows::Gaming::Input::UINavigationReading GetCurrentReading() const;
    Windows::Gaming::Input::GameControllerButtonLabel GetOptionalButtonLabel(Windows::Gaming::Input::OptionalUINavigationButtons button) const;
    Windows::Gaming::Input::GameControllerButtonLabel GetRequiredButtonLabel(Windows::Gaming::Input::RequiredUINavigationButtons button) const;
};

template <typename D>
struct WINRT_EBO impl_IUINavigationControllerStatics
{
    event_token UINavigationControllerAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value) const;
    using UINavigationControllerAdded_revoker = event_revoker<IUINavigationControllerStatics>;
    UINavigationControllerAdded_revoker UINavigationControllerAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value) const;
    void UINavigationControllerAdded(event_token token) const;
    event_token UINavigationControllerRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value) const;
    using UINavigationControllerRemoved_revoker = event_revoker<IUINavigationControllerStatics>;
    UINavigationControllerRemoved_revoker UINavigationControllerRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value) const;
    void UINavigationControllerRemoved(event_token token) const;
    Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::UINavigationController> UINavigationControllers() const;
};

}

namespace impl {

template <> struct traits<Windows::Gaming::Input::IArcadeStick>
{
    using abi = ABI::Windows::Gaming::Input::IArcadeStick;
    template <typename D> using consume = Windows::Gaming::Input::impl_IArcadeStick<D>;
};

template <> struct traits<Windows::Gaming::Input::IArcadeStickStatics>
{
    using abi = ABI::Windows::Gaming::Input::IArcadeStickStatics;
    template <typename D> using consume = Windows::Gaming::Input::impl_IArcadeStickStatics<D>;
};

template <> struct traits<Windows::Gaming::Input::IGameController>
{
    using abi = ABI::Windows::Gaming::Input::IGameController;
    template <typename D> using consume = Windows::Gaming::Input::impl_IGameController<D>;
};

template <> struct traits<Windows::Gaming::Input::IGamepad>
{
    using abi = ABI::Windows::Gaming::Input::IGamepad;
    template <typename D> using consume = Windows::Gaming::Input::impl_IGamepad<D>;
};

template <> struct traits<Windows::Gaming::Input::IGamepad2>
{
    using abi = ABI::Windows::Gaming::Input::IGamepad2;
    template <typename D> using consume = Windows::Gaming::Input::impl_IGamepad2<D>;
};

template <> struct traits<Windows::Gaming::Input::IGamepadStatics>
{
    using abi = ABI::Windows::Gaming::Input::IGamepadStatics;
    template <typename D> using consume = Windows::Gaming::Input::impl_IGamepadStatics<D>;
};

template <> struct traits<Windows::Gaming::Input::IHeadset>
{
    using abi = ABI::Windows::Gaming::Input::IHeadset;
    template <typename D> using consume = Windows::Gaming::Input::impl_IHeadset<D>;
};

template <> struct traits<Windows::Gaming::Input::IRacingWheel>
{
    using abi = ABI::Windows::Gaming::Input::IRacingWheel;
    template <typename D> using consume = Windows::Gaming::Input::impl_IRacingWheel<D>;
};

template <> struct traits<Windows::Gaming::Input::IRacingWheelStatics>
{
    using abi = ABI::Windows::Gaming::Input::IRacingWheelStatics;
    template <typename D> using consume = Windows::Gaming::Input::impl_IRacingWheelStatics<D>;
};

template <> struct traits<Windows::Gaming::Input::IUINavigationController>
{
    using abi = ABI::Windows::Gaming::Input::IUINavigationController;
    template <typename D> using consume = Windows::Gaming::Input::impl_IUINavigationController<D>;
};

template <> struct traits<Windows::Gaming::Input::IUINavigationControllerStatics>
{
    using abi = ABI::Windows::Gaming::Input::IUINavigationControllerStatics;
    template <typename D> using consume = Windows::Gaming::Input::impl_IUINavigationControllerStatics<D>;
};

template <> struct traits<Windows::Gaming::Input::ArcadeStick>
{
    using abi = ABI::Windows::Gaming::Input::ArcadeStick;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Input.ArcadeStick"; }
};

template <> struct traits<Windows::Gaming::Input::Gamepad>
{
    using abi = ABI::Windows::Gaming::Input::Gamepad;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Input.Gamepad"; }
};

template <> struct traits<Windows::Gaming::Input::Headset>
{
    using abi = ABI::Windows::Gaming::Input::Headset;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Input.Headset"; }
};

template <> struct traits<Windows::Gaming::Input::RacingWheel>
{
    using abi = ABI::Windows::Gaming::Input::RacingWheel;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Input.RacingWheel"; }
};

template <> struct traits<Windows::Gaming::Input::UINavigationController>
{
    using abi = ABI::Windows::Gaming::Input::UINavigationController;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Gaming.Input.UINavigationController"; }
};

}

}
