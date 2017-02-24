// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Gaming.Input.ForceFeedback.3.h"
#include "internal/Windows.Gaming.Input.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Gaming::Input::IArcadeStick> : produce_base<D, Windows::Gaming::Input::IArcadeStick>
{
    HRESULT __stdcall abi_GetButtonLabel(Windows::Gaming::Input::ArcadeStickButtons button, Windows::Gaming::Input::GameControllerButtonLabel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetButtonLabel(button));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Gaming::Input::ArcadeStickReading> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCurrentReading());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::IArcadeStickStatics> : produce_base<D, Windows::Gaming::Input::IArcadeStickStatics>
{
    HRESULT __stdcall add_ArcadeStickAdded(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ArcadeStickAdded(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ArcadeStickAdded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ArcadeStickAdded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ArcadeStickRemoved(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ArcadeStickRemoved(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ArcadeStickRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ArcadeStickRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ArcadeSticks(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::ArcadeStick>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ArcadeSticks());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::IGameController> : produce_base<D, Windows::Gaming::Input::IGameController>
{
    HRESULT __stdcall add_HeadsetConnected(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::Gaming::Input::Headset>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().HeadsetConnected(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::Gaming::Input::Headset> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_HeadsetConnected(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HeadsetConnected(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_HeadsetDisconnected(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::Gaming::Input::Headset>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().HeadsetDisconnected(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::Gaming::Input::Headset> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_HeadsetDisconnected(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HeadsetDisconnected(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_UserChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::System::UserChangedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UserChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::System::UserChangedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UserChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Headset(impl::abi_arg_out<Windows::Gaming::Input::IHeadset> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Headset());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsWireless(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsWireless());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_User(impl::abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().User());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::IGamepad> : produce_base<D, Windows::Gaming::Input::IGamepad>
{
    HRESULT __stdcall get_Vibration(impl::abi_arg_out<Windows::Gaming::Input::GamepadVibration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Vibration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Vibration(impl::abi_arg_in<Windows::Gaming::Input::GamepadVibration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Vibration(*reinterpret_cast<const Windows::Gaming::Input::GamepadVibration *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Gaming::Input::GamepadReading> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCurrentReading());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::IGamepad2> : produce_base<D, Windows::Gaming::Input::IGamepad2>
{
    HRESULT __stdcall abi_GetButtonLabel(Windows::Gaming::Input::GamepadButtons button, Windows::Gaming::Input::GameControllerButtonLabel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetButtonLabel(button));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::IGamepadStatics> : produce_base<D, Windows::Gaming::Input::IGamepadStatics>
{
    HRESULT __stdcall add_GamepadAdded(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().GamepadAdded(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_GamepadAdded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GamepadAdded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_GamepadRemoved(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().GamepadRemoved(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_GamepadRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GamepadRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gamepads(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::Gamepad>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gamepads());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::IHeadset> : produce_base<D, Windows::Gaming::Input::IHeadset>
{
    HRESULT __stdcall get_CaptureDeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CaptureDeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RenderDeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RenderDeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::IRacingWheel> : produce_base<D, Windows::Gaming::Input::IRacingWheel>
{
    HRESULT __stdcall get_HasClutch(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasClutch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasHandbrake(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasHandbrake());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasPatternShifter(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasPatternShifter());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxPatternShifterGear(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPatternShifterGear());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxWheelAngle(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxWheelAngle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WheelMotor(impl::abi_arg_out<Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WheelMotor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetButtonLabel(Windows::Gaming::Input::RacingWheelButtons button, Windows::Gaming::Input::GameControllerButtonLabel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetButtonLabel(button));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Gaming::Input::RacingWheelReading> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCurrentReading());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::IRacingWheelStatics> : produce_base<D, Windows::Gaming::Input::IRacingWheelStatics>
{
    HRESULT __stdcall add_RacingWheelAdded(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RacingWheelAdded(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RacingWheelAdded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RacingWheelAdded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RacingWheelRemoved(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RacingWheelRemoved(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RacingWheelRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RacingWheelRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RacingWheels(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::RacingWheel>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RacingWheels());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::IUINavigationController> : produce_base<D, Windows::Gaming::Input::IUINavigationController>
{
    HRESULT __stdcall abi_GetCurrentReading(impl::abi_arg_out<Windows::Gaming::Input::UINavigationReading> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCurrentReading());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetOptionalButtonLabel(Windows::Gaming::Input::OptionalUINavigationButtons button, Windows::Gaming::Input::GameControllerButtonLabel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetOptionalButtonLabel(button));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRequiredButtonLabel(Windows::Gaming::Input::RequiredUINavigationButtons button, Windows::Gaming::Input::GameControllerButtonLabel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetRequiredButtonLabel(button));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Gaming::Input::IUINavigationControllerStatics> : produce_base<D, Windows::Gaming::Input::IUINavigationControllerStatics>
{
    HRESULT __stdcall add_UINavigationControllerAdded(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UINavigationControllerAdded(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UINavigationControllerAdded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UINavigationControllerAdded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_UINavigationControllerRemoved(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UINavigationControllerRemoved(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UINavigationControllerRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UINavigationControllerRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UINavigationControllers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::UINavigationController>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UINavigationControllers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Gaming::Input {

template <typename D> event_token impl_IGameController<D>::HeadsetConnected(const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::Gaming::Input::Headset> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGameController)->add_HeadsetConnected(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IGameController> impl_IGameController<D>::HeadsetConnected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::Gaming::Input::Headset> & value) const
{
    return impl::make_event_revoker<D, IGameController>(this, &ABI::Windows::Gaming::Input::IGameController::remove_HeadsetConnected, HeadsetConnected(value));
}

template <typename D> void impl_IGameController<D>::HeadsetConnected(event_token token) const
{
    check_hresult(WINRT_SHIM(IGameController)->remove_HeadsetConnected(token));
}

template <typename D> event_token impl_IGameController<D>::HeadsetDisconnected(const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::Gaming::Input::Headset> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGameController)->add_HeadsetDisconnected(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IGameController> impl_IGameController<D>::HeadsetDisconnected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::Gaming::Input::Headset> & value) const
{
    return impl::make_event_revoker<D, IGameController>(this, &ABI::Windows::Gaming::Input::IGameController::remove_HeadsetDisconnected, HeadsetDisconnected(value));
}

template <typename D> void impl_IGameController<D>::HeadsetDisconnected(event_token token) const
{
    check_hresult(WINRT_SHIM(IGameController)->remove_HeadsetDisconnected(token));
}

template <typename D> event_token impl_IGameController<D>::UserChanged(const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::System::UserChangedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGameController)->add_UserChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IGameController> impl_IGameController<D>::UserChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Gaming::Input::IGameController, Windows::System::UserChangedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IGameController>(this, &ABI::Windows::Gaming::Input::IGameController::remove_UserChanged, UserChanged(value));
}

template <typename D> void impl_IGameController<D>::UserChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IGameController)->remove_UserChanged(token));
}

template <typename D> Windows::Gaming::Input::Headset impl_IGameController<D>::Headset() const
{
    Windows::Gaming::Input::Headset value { nullptr };
    check_hresult(WINRT_SHIM(IGameController)->get_Headset(put_abi(value)));
    return value;
}

template <typename D> bool impl_IGameController<D>::IsWireless() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGameController)->get_IsWireless(&value));
    return value;
}

template <typename D> Windows::System::User impl_IGameController<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IGameController)->get_User(put_abi(value)));
    return value;
}

template <typename D> Windows::Gaming::Input::GameControllerButtonLabel impl_IArcadeStick<D>::GetButtonLabel(Windows::Gaming::Input::ArcadeStickButtons button) const
{
    Windows::Gaming::Input::GameControllerButtonLabel value {};
    check_hresult(WINRT_SHIM(IArcadeStick)->abi_GetButtonLabel(button, &value));
    return value;
}

template <typename D> Windows::Gaming::Input::ArcadeStickReading impl_IArcadeStick<D>::GetCurrentReading() const
{
    Windows::Gaming::Input::ArcadeStickReading value {};
    check_hresult(WINRT_SHIM(IArcadeStick)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IArcadeStickStatics<D>::ArcadeStickAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IArcadeStickStatics)->add_ArcadeStickAdded(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IArcadeStickStatics> impl_IArcadeStickStatics<D>::ArcadeStickAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value) const
{
    return impl::make_event_revoker<D, IArcadeStickStatics>(this, &ABI::Windows::Gaming::Input::IArcadeStickStatics::remove_ArcadeStickAdded, ArcadeStickAdded(value));
}

template <typename D> void impl_IArcadeStickStatics<D>::ArcadeStickAdded(event_token token) const
{
    check_hresult(WINRT_SHIM(IArcadeStickStatics)->remove_ArcadeStickAdded(token));
}

template <typename D> event_token impl_IArcadeStickStatics<D>::ArcadeStickRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IArcadeStickStatics)->add_ArcadeStickRemoved(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IArcadeStickStatics> impl_IArcadeStickStatics<D>::ArcadeStickRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value) const
{
    return impl::make_event_revoker<D, IArcadeStickStatics>(this, &ABI::Windows::Gaming::Input::IArcadeStickStatics::remove_ArcadeStickRemoved, ArcadeStickRemoved(value));
}

template <typename D> void impl_IArcadeStickStatics<D>::ArcadeStickRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(IArcadeStickStatics)->remove_ArcadeStickRemoved(token));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::ArcadeStick> impl_IArcadeStickStatics<D>::ArcadeSticks() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::ArcadeStick> value;
    check_hresult(WINRT_SHIM(IArcadeStickStatics)->get_ArcadeSticks(put_abi(value)));
    return value;
}

template <typename D> Windows::Gaming::Input::GamepadVibration impl_IGamepad<D>::Vibration() const
{
    Windows::Gaming::Input::GamepadVibration value {};
    check_hresult(WINRT_SHIM(IGamepad)->get_Vibration(put_abi(value)));
    return value;
}

template <typename D> void impl_IGamepad<D>::Vibration(const Windows::Gaming::Input::GamepadVibration & value) const
{
    check_hresult(WINRT_SHIM(IGamepad)->put_Vibration(get_abi(value)));
}

template <typename D> Windows::Gaming::Input::GamepadReading impl_IGamepad<D>::GetCurrentReading() const
{
    Windows::Gaming::Input::GamepadReading value {};
    check_hresult(WINRT_SHIM(IGamepad)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> Windows::Gaming::Input::GameControllerButtonLabel impl_IGamepad2<D>::GetButtonLabel(Windows::Gaming::Input::GamepadButtons button) const
{
    Windows::Gaming::Input::GameControllerButtonLabel value {};
    check_hresult(WINRT_SHIM(IGamepad2)->abi_GetButtonLabel(button, &value));
    return value;
}

template <typename D> event_token impl_IGamepadStatics<D>::GamepadAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGamepadStatics)->add_GamepadAdded(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IGamepadStatics> impl_IGamepadStatics<D>::GamepadAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value) const
{
    return impl::make_event_revoker<D, IGamepadStatics>(this, &ABI::Windows::Gaming::Input::IGamepadStatics::remove_GamepadAdded, GamepadAdded(value));
}

template <typename D> void impl_IGamepadStatics<D>::GamepadAdded(event_token token) const
{
    check_hresult(WINRT_SHIM(IGamepadStatics)->remove_GamepadAdded(token));
}

template <typename D> event_token impl_IGamepadStatics<D>::GamepadRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGamepadStatics)->add_GamepadRemoved(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IGamepadStatics> impl_IGamepadStatics<D>::GamepadRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value) const
{
    return impl::make_event_revoker<D, IGamepadStatics>(this, &ABI::Windows::Gaming::Input::IGamepadStatics::remove_GamepadRemoved, GamepadRemoved(value));
}

template <typename D> void impl_IGamepadStatics<D>::GamepadRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(IGamepadStatics)->remove_GamepadRemoved(token));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::Gamepad> impl_IGamepadStatics<D>::Gamepads() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::Gamepad> value;
    check_hresult(WINRT_SHIM(IGamepadStatics)->get_Gamepads(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHeadset<D>::CaptureDeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHeadset)->get_CaptureDeviceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHeadset<D>::RenderDeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHeadset)->get_RenderDeviceId(put_abi(value)));
    return value;
}

template <typename D> bool impl_IRacingWheel<D>::HasClutch() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRacingWheel)->get_HasClutch(&value));
    return value;
}

template <typename D> bool impl_IRacingWheel<D>::HasHandbrake() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRacingWheel)->get_HasHandbrake(&value));
    return value;
}

template <typename D> bool impl_IRacingWheel<D>::HasPatternShifter() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRacingWheel)->get_HasPatternShifter(&value));
    return value;
}

template <typename D> int32_t impl_IRacingWheel<D>::MaxPatternShifterGear() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IRacingWheel)->get_MaxPatternShifterGear(&value));
    return value;
}

template <typename D> double impl_IRacingWheel<D>::MaxWheelAngle() const
{
    double value {};
    check_hresult(WINRT_SHIM(IRacingWheel)->get_MaxWheelAngle(&value));
    return value;
}

template <typename D> Windows::Gaming::Input::ForceFeedback::ForceFeedbackMotor impl_IRacingWheel<D>::WheelMotor() const
{
    Windows::Gaming::Input::ForceFeedback::ForceFeedbackMotor value { nullptr };
    check_hresult(WINRT_SHIM(IRacingWheel)->get_WheelMotor(put_abi(value)));
    return value;
}

template <typename D> Windows::Gaming::Input::GameControllerButtonLabel impl_IRacingWheel<D>::GetButtonLabel(Windows::Gaming::Input::RacingWheelButtons button) const
{
    Windows::Gaming::Input::GameControllerButtonLabel value {};
    check_hresult(WINRT_SHIM(IRacingWheel)->abi_GetButtonLabel(button, &value));
    return value;
}

template <typename D> Windows::Gaming::Input::RacingWheelReading impl_IRacingWheel<D>::GetCurrentReading() const
{
    Windows::Gaming::Input::RacingWheelReading value {};
    check_hresult(WINRT_SHIM(IRacingWheel)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IRacingWheelStatics<D>::RacingWheelAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IRacingWheelStatics)->add_RacingWheelAdded(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IRacingWheelStatics> impl_IRacingWheelStatics<D>::RacingWheelAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value) const
{
    return impl::make_event_revoker<D, IRacingWheelStatics>(this, &ABI::Windows::Gaming::Input::IRacingWheelStatics::remove_RacingWheelAdded, RacingWheelAdded(value));
}

template <typename D> void impl_IRacingWheelStatics<D>::RacingWheelAdded(event_token token) const
{
    check_hresult(WINRT_SHIM(IRacingWheelStatics)->remove_RacingWheelAdded(token));
}

template <typename D> event_token impl_IRacingWheelStatics<D>::RacingWheelRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IRacingWheelStatics)->add_RacingWheelRemoved(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IRacingWheelStatics> impl_IRacingWheelStatics<D>::RacingWheelRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value) const
{
    return impl::make_event_revoker<D, IRacingWheelStatics>(this, &ABI::Windows::Gaming::Input::IRacingWheelStatics::remove_RacingWheelRemoved, RacingWheelRemoved(value));
}

template <typename D> void impl_IRacingWheelStatics<D>::RacingWheelRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(IRacingWheelStatics)->remove_RacingWheelRemoved(token));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::RacingWheel> impl_IRacingWheelStatics<D>::RacingWheels() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::RacingWheel> value;
    check_hresult(WINRT_SHIM(IRacingWheelStatics)->get_RacingWheels(put_abi(value)));
    return value;
}

template <typename D> Windows::Gaming::Input::UINavigationReading impl_IUINavigationController<D>::GetCurrentReading() const
{
    Windows::Gaming::Input::UINavigationReading value {};
    check_hresult(WINRT_SHIM(IUINavigationController)->abi_GetCurrentReading(put_abi(value)));
    return value;
}

template <typename D> Windows::Gaming::Input::GameControllerButtonLabel impl_IUINavigationController<D>::GetOptionalButtonLabel(Windows::Gaming::Input::OptionalUINavigationButtons button) const
{
    Windows::Gaming::Input::GameControllerButtonLabel value {};
    check_hresult(WINRT_SHIM(IUINavigationController)->abi_GetOptionalButtonLabel(button, &value));
    return value;
}

template <typename D> Windows::Gaming::Input::GameControllerButtonLabel impl_IUINavigationController<D>::GetRequiredButtonLabel(Windows::Gaming::Input::RequiredUINavigationButtons button) const
{
    Windows::Gaming::Input::GameControllerButtonLabel value {};
    check_hresult(WINRT_SHIM(IUINavigationController)->abi_GetRequiredButtonLabel(button, &value));
    return value;
}

template <typename D> event_token impl_IUINavigationControllerStatics<D>::UINavigationControllerAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUINavigationControllerStatics)->add_UINavigationControllerAdded(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUINavigationControllerStatics> impl_IUINavigationControllerStatics<D>::UINavigationControllerAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value) const
{
    return impl::make_event_revoker<D, IUINavigationControllerStatics>(this, &ABI::Windows::Gaming::Input::IUINavigationControllerStatics::remove_UINavigationControllerAdded, UINavigationControllerAdded(value));
}

template <typename D> void impl_IUINavigationControllerStatics<D>::UINavigationControllerAdded(event_token token) const
{
    check_hresult(WINRT_SHIM(IUINavigationControllerStatics)->remove_UINavigationControllerAdded(token));
}

template <typename D> event_token impl_IUINavigationControllerStatics<D>::UINavigationControllerRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUINavigationControllerStatics)->add_UINavigationControllerRemoved(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUINavigationControllerStatics> impl_IUINavigationControllerStatics<D>::UINavigationControllerRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value) const
{
    return impl::make_event_revoker<D, IUINavigationControllerStatics>(this, &ABI::Windows::Gaming::Input::IUINavigationControllerStatics::remove_UINavigationControllerRemoved, UINavigationControllerRemoved(value));
}

template <typename D> void impl_IUINavigationControllerStatics<D>::UINavigationControllerRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(IUINavigationControllerStatics)->remove_UINavigationControllerRemoved(token));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::UINavigationController> impl_IUINavigationControllerStatics<D>::UINavigationControllers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::UINavigationController> value;
    check_hresult(WINRT_SHIM(IUINavigationControllerStatics)->get_UINavigationControllers(put_abi(value)));
    return value;
}

inline event_token ArcadeStick::ArcadeStickAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value)
{
    return get_activation_factory<ArcadeStick, IArcadeStickStatics>().ArcadeStickAdded(value);
}

inline factory_event_revoker<IArcadeStickStatics> ArcadeStick::ArcadeStickAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value)
{
    auto factory = get_activation_factory<ArcadeStick, IArcadeStickStatics>();
    return { factory, &ABI::Windows::Gaming::Input::IArcadeStickStatics::remove_ArcadeStickAdded, factory.ArcadeStickAdded(value) };
}

inline void ArcadeStick::ArcadeStickAdded(event_token token)
{
    get_activation_factory<ArcadeStick, IArcadeStickStatics>().ArcadeStickAdded(token);
}

inline event_token ArcadeStick::ArcadeStickRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value)
{
    return get_activation_factory<ArcadeStick, IArcadeStickStatics>().ArcadeStickRemoved(value);
}

inline factory_event_revoker<IArcadeStickStatics> ArcadeStick::ArcadeStickRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::ArcadeStick> & value)
{
    auto factory = get_activation_factory<ArcadeStick, IArcadeStickStatics>();
    return { factory, &ABI::Windows::Gaming::Input::IArcadeStickStatics::remove_ArcadeStickRemoved, factory.ArcadeStickRemoved(value) };
}

inline void ArcadeStick::ArcadeStickRemoved(event_token token)
{
    get_activation_factory<ArcadeStick, IArcadeStickStatics>().ArcadeStickRemoved(token);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::ArcadeStick> ArcadeStick::ArcadeSticks()
{
    return get_activation_factory<ArcadeStick, IArcadeStickStatics>().ArcadeSticks();
}

inline event_token Gamepad::GamepadAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value)
{
    return get_activation_factory<Gamepad, IGamepadStatics>().GamepadAdded(value);
}

inline factory_event_revoker<IGamepadStatics> Gamepad::GamepadAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value)
{
    auto factory = get_activation_factory<Gamepad, IGamepadStatics>();
    return { factory, &ABI::Windows::Gaming::Input::IGamepadStatics::remove_GamepadAdded, factory.GamepadAdded(value) };
}

inline void Gamepad::GamepadAdded(event_token token)
{
    get_activation_factory<Gamepad, IGamepadStatics>().GamepadAdded(token);
}

inline event_token Gamepad::GamepadRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value)
{
    return get_activation_factory<Gamepad, IGamepadStatics>().GamepadRemoved(value);
}

inline factory_event_revoker<IGamepadStatics> Gamepad::GamepadRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::Gamepad> & value)
{
    auto factory = get_activation_factory<Gamepad, IGamepadStatics>();
    return { factory, &ABI::Windows::Gaming::Input::IGamepadStatics::remove_GamepadRemoved, factory.GamepadRemoved(value) };
}

inline void Gamepad::GamepadRemoved(event_token token)
{
    get_activation_factory<Gamepad, IGamepadStatics>().GamepadRemoved(token);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::Gamepad> Gamepad::Gamepads()
{
    return get_activation_factory<Gamepad, IGamepadStatics>().Gamepads();
}

inline event_token RacingWheel::RacingWheelAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value)
{
    return get_activation_factory<RacingWheel, IRacingWheelStatics>().RacingWheelAdded(value);
}

inline factory_event_revoker<IRacingWheelStatics> RacingWheel::RacingWheelAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value)
{
    auto factory = get_activation_factory<RacingWheel, IRacingWheelStatics>();
    return { factory, &ABI::Windows::Gaming::Input::IRacingWheelStatics::remove_RacingWheelAdded, factory.RacingWheelAdded(value) };
}

inline void RacingWheel::RacingWheelAdded(event_token token)
{
    get_activation_factory<RacingWheel, IRacingWheelStatics>().RacingWheelAdded(token);
}

inline event_token RacingWheel::RacingWheelRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value)
{
    return get_activation_factory<RacingWheel, IRacingWheelStatics>().RacingWheelRemoved(value);
}

inline factory_event_revoker<IRacingWheelStatics> RacingWheel::RacingWheelRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::RacingWheel> & value)
{
    auto factory = get_activation_factory<RacingWheel, IRacingWheelStatics>();
    return { factory, &ABI::Windows::Gaming::Input::IRacingWheelStatics::remove_RacingWheelRemoved, factory.RacingWheelRemoved(value) };
}

inline void RacingWheel::RacingWheelRemoved(event_token token)
{
    get_activation_factory<RacingWheel, IRacingWheelStatics>().RacingWheelRemoved(token);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::RacingWheel> RacingWheel::RacingWheels()
{
    return get_activation_factory<RacingWheel, IRacingWheelStatics>().RacingWheels();
}

inline event_token UINavigationController::UINavigationControllerAdded(const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value)
{
    return get_activation_factory<UINavigationController, IUINavigationControllerStatics>().UINavigationControllerAdded(value);
}

inline factory_event_revoker<IUINavigationControllerStatics> UINavigationController::UINavigationControllerAdded(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value)
{
    auto factory = get_activation_factory<UINavigationController, IUINavigationControllerStatics>();
    return { factory, &ABI::Windows::Gaming::Input::IUINavigationControllerStatics::remove_UINavigationControllerAdded, factory.UINavigationControllerAdded(value) };
}

inline void UINavigationController::UINavigationControllerAdded(event_token token)
{
    get_activation_factory<UINavigationController, IUINavigationControllerStatics>().UINavigationControllerAdded(token);
}

inline event_token UINavigationController::UINavigationControllerRemoved(const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value)
{
    return get_activation_factory<UINavigationController, IUINavigationControllerStatics>().UINavigationControllerRemoved(value);
}

inline factory_event_revoker<IUINavigationControllerStatics> UINavigationController::UINavigationControllerRemoved(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Gaming::Input::UINavigationController> & value)
{
    auto factory = get_activation_factory<UINavigationController, IUINavigationControllerStatics>();
    return { factory, &ABI::Windows::Gaming::Input::IUINavigationControllerStatics::remove_UINavigationControllerRemoved, factory.UINavigationControllerRemoved(value) };
}

inline void UINavigationController::UINavigationControllerRemoved(event_token token)
{
    get_activation_factory<UINavigationController, IUINavigationControllerStatics>().UINavigationControllerRemoved(token);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Gaming::Input::UINavigationController> UINavigationController::UINavigationControllers()
{
    return get_activation_factory<UINavigationController, IUINavigationControllerStatics>().UINavigationControllers();
}

}

}
#pragma warning(pop)
