// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Phone.UI.Input.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Phone::UI::Input::IBackPressedEventArgs> : produce_base<D, Windows::Phone::UI::Input::IBackPressedEventArgs>
{
    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::UI::Input::ICameraEventArgs> : produce_base<D, Windows::Phone::UI::Input::ICameraEventArgs>
{};

template <typename D>
struct produce<D, Windows::Phone::UI::Input::IHardwareButtonsStatics> : produce_base<D, Windows::Phone::UI::Input::IHardwareButtonsStatics>
{
    HRESULT __stdcall add_BackPressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Phone::UI::Input::BackPressedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BackPressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::BackPressedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BackPressed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackPressed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::UI::Input::IHardwareButtonsStatics2> : produce_base<D, Windows::Phone::UI::Input::IHardwareButtonsStatics2>
{
    HRESULT __stdcall add_CameraHalfPressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CameraHalfPressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CameraHalfPressed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraHalfPressed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CameraPressed(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CameraPressed(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CameraPressed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraPressed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CameraReleased(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CameraReleased(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CameraReleased(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraReleased(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Phone::UI::Input {

template <typename D> event_token impl_IHardwareButtonsStatics<D>::BackPressed(const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::BackPressedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IHardwareButtonsStatics)->add_BackPressed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IHardwareButtonsStatics> impl_IHardwareButtonsStatics<D>::BackPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::BackPressedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IHardwareButtonsStatics>(this, &ABI::Windows::Phone::UI::Input::IHardwareButtonsStatics::remove_BackPressed, BackPressed(handler));
}

template <typename D> void impl_IHardwareButtonsStatics<D>::BackPressed(event_token token) const
{
    check_hresult(WINRT_SHIM(IHardwareButtonsStatics)->remove_BackPressed(token));
}

template <typename D> event_token impl_IHardwareButtonsStatics2<D>::CameraHalfPressed(const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IHardwareButtonsStatics2)->add_CameraHalfPressed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IHardwareButtonsStatics2> impl_IHardwareButtonsStatics2<D>::CameraHalfPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IHardwareButtonsStatics2>(this, &ABI::Windows::Phone::UI::Input::IHardwareButtonsStatics2::remove_CameraHalfPressed, CameraHalfPressed(handler));
}

template <typename D> void impl_IHardwareButtonsStatics2<D>::CameraHalfPressed(event_token token) const
{
    check_hresult(WINRT_SHIM(IHardwareButtonsStatics2)->remove_CameraHalfPressed(token));
}

template <typename D> event_token impl_IHardwareButtonsStatics2<D>::CameraPressed(const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IHardwareButtonsStatics2)->add_CameraPressed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IHardwareButtonsStatics2> impl_IHardwareButtonsStatics2<D>::CameraPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IHardwareButtonsStatics2>(this, &ABI::Windows::Phone::UI::Input::IHardwareButtonsStatics2::remove_CameraPressed, CameraPressed(handler));
}

template <typename D> void impl_IHardwareButtonsStatics2<D>::CameraPressed(event_token token) const
{
    check_hresult(WINRT_SHIM(IHardwareButtonsStatics2)->remove_CameraPressed(token));
}

template <typename D> event_token impl_IHardwareButtonsStatics2<D>::CameraReleased(const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IHardwareButtonsStatics2)->add_CameraReleased(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IHardwareButtonsStatics2> impl_IHardwareButtonsStatics2<D>::CameraReleased(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IHardwareButtonsStatics2>(this, &ABI::Windows::Phone::UI::Input::IHardwareButtonsStatics2::remove_CameraReleased, CameraReleased(handler));
}

template <typename D> void impl_IHardwareButtonsStatics2<D>::CameraReleased(event_token token) const
{
    check_hresult(WINRT_SHIM(IHardwareButtonsStatics2)->remove_CameraReleased(token));
}

template <typename D> bool impl_IBackPressedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBackPressedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IBackPressedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IBackPressedEventArgs)->put_Handled(value));
}

inline event_token HardwareButtons::BackPressed(const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::BackPressedEventArgs> & handler)
{
    return get_activation_factory<HardwareButtons, IHardwareButtonsStatics>().BackPressed(handler);
}

inline factory_event_revoker<IHardwareButtonsStatics> HardwareButtons::BackPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::BackPressedEventArgs> & handler)
{
    auto factory = get_activation_factory<HardwareButtons, IHardwareButtonsStatics>();
    return { factory, &ABI::Windows::Phone::UI::Input::IHardwareButtonsStatics::remove_BackPressed, factory.BackPressed(handler) };
}

inline void HardwareButtons::BackPressed(event_token token)
{
    get_activation_factory<HardwareButtons, IHardwareButtonsStatics>().BackPressed(token);
}

inline event_token HardwareButtons::CameraHalfPressed(const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler)
{
    return get_activation_factory<HardwareButtons, IHardwareButtonsStatics2>().CameraHalfPressed(handler);
}

inline factory_event_revoker<IHardwareButtonsStatics2> HardwareButtons::CameraHalfPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler)
{
    auto factory = get_activation_factory<HardwareButtons, IHardwareButtonsStatics2>();
    return { factory, &ABI::Windows::Phone::UI::Input::IHardwareButtonsStatics2::remove_CameraHalfPressed, factory.CameraHalfPressed(handler) };
}

inline void HardwareButtons::CameraHalfPressed(event_token token)
{
    get_activation_factory<HardwareButtons, IHardwareButtonsStatics2>().CameraHalfPressed(token);
}

inline event_token HardwareButtons::CameraPressed(const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler)
{
    return get_activation_factory<HardwareButtons, IHardwareButtonsStatics2>().CameraPressed(handler);
}

inline factory_event_revoker<IHardwareButtonsStatics2> HardwareButtons::CameraPressed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler)
{
    auto factory = get_activation_factory<HardwareButtons, IHardwareButtonsStatics2>();
    return { factory, &ABI::Windows::Phone::UI::Input::IHardwareButtonsStatics2::remove_CameraPressed, factory.CameraPressed(handler) };
}

inline void HardwareButtons::CameraPressed(event_token token)
{
    get_activation_factory<HardwareButtons, IHardwareButtonsStatics2>().CameraPressed(token);
}

inline event_token HardwareButtons::CameraReleased(const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler)
{
    return get_activation_factory<HardwareButtons, IHardwareButtonsStatics2>().CameraReleased(handler);
}

inline factory_event_revoker<IHardwareButtonsStatics2> HardwareButtons::CameraReleased(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Phone::UI::Input::CameraEventArgs> & handler)
{
    auto factory = get_activation_factory<HardwareButtons, IHardwareButtonsStatics2>();
    return { factory, &ABI::Windows::Phone::UI::Input::IHardwareButtonsStatics2::remove_CameraReleased, factory.CameraReleased(handler) };
}

inline void HardwareButtons::CameraReleased(event_token token)
{
    get_activation_factory<HardwareButtons, IHardwareButtonsStatics2>().CameraReleased(token);
}

}

}
#pragma warning(pop)
