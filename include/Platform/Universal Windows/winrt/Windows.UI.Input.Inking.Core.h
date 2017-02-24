// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Input.Inking.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.Input.Inking.Core.3.h"
#include "Windows.UI.Input.Inking.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource> : produce_base<D, Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>
{
    HRESULT __stdcall add_PointerEntering(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerEntering(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerEntering(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerEntering(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerHovering(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerHovering(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerHovering(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerHovering(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerExiting(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerExiting(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerExiting(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerExiting(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerPressing(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerPressing(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerPressing(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerPressing(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerMoving(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerMoving(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerMoving(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerMoving(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerReleasing(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerReleasing(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerReleasing(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerReleasing(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerLost(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerLost(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerLost(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerLost(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InkPresenter(impl::abi_arg_out<Windows::UI::Input::Inking::IInkPresenter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InkPresenter());
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
struct produce<D, Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSourceStatics> : produce_base<D, Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSourceStatics>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::UI::Input::Inking::IInkPresenter> inkPresenter, impl::abi_arg_out<Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource> inkIndependentInputSource) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *inkIndependentInputSource = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::UI::Input::Inking::InkPresenter *>(&inkPresenter)));
            return S_OK;
        }
        catch (...)
        {
            *inkIndependentInputSource = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs> : produce_base<D, Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs>
{
    HRESULT __stdcall get_NewInkPoints(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Input::Inking::InkPoint>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewInkPoints());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Disposition(Windows::UI::Input::Inking::Core::CoreWetStrokeDisposition * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Disposition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Disposition(Windows::UI::Input::Inking::Core::CoreWetStrokeDisposition value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Disposition(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource> : produce_base<D, Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource>
{
    HRESULT __stdcall add_WetStrokeStarting(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().WetStrokeStarting(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_WetStrokeStarting(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WetStrokeStarting(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_WetStrokeContinuing(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().WetStrokeContinuing(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_WetStrokeContinuing(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WetStrokeContinuing(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_WetStrokeStopping(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().WetStrokeStopping(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_WetStrokeStopping(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WetStrokeStopping(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_WetStrokeCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().WetStrokeCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_WetStrokeCompleted(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WetStrokeCompleted(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_WetStrokeCanceled(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().WetStrokeCanceled(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_WetStrokeCanceled(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WetStrokeCanceled(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InkPresenter(impl::abi_arg_out<Windows::UI::Input::Inking::IInkPresenter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InkPresenter());
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
struct produce<D, Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSourceStatics> : produce_base<D, Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSourceStatics>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::UI::Input::Inking::IInkPresenter> inkPresenter, impl::abi_arg_out<Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource> WetStrokeUpdateSource) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *WetStrokeUpdateSource = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::UI::Input::Inking::InkPresenter *>(&inkPresenter)));
            return S_OK;
        }
        catch (...)
        {
            *WetStrokeUpdateSource = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Input::Inking::Core {

template <typename D> event_token impl_ICoreInkIndependentInputSource<D>::PointerEntering(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->add_PointerEntering(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreInkIndependentInputSource> impl_ICoreInkIndependentInputSource<D>::PointerEntering(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreInkIndependentInputSource>(this, &ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource::remove_PointerEntering, PointerEntering(handler));
}

template <typename D> void impl_ICoreInkIndependentInputSource<D>::PointerEntering(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->remove_PointerEntering(cookie));
}

template <typename D> event_token impl_ICoreInkIndependentInputSource<D>::PointerHovering(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->add_PointerHovering(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreInkIndependentInputSource> impl_ICoreInkIndependentInputSource<D>::PointerHovering(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreInkIndependentInputSource>(this, &ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource::remove_PointerHovering, PointerHovering(handler));
}

template <typename D> void impl_ICoreInkIndependentInputSource<D>::PointerHovering(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->remove_PointerHovering(cookie));
}

template <typename D> event_token impl_ICoreInkIndependentInputSource<D>::PointerExiting(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->add_PointerExiting(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreInkIndependentInputSource> impl_ICoreInkIndependentInputSource<D>::PointerExiting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreInkIndependentInputSource>(this, &ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource::remove_PointerExiting, PointerExiting(handler));
}

template <typename D> void impl_ICoreInkIndependentInputSource<D>::PointerExiting(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->remove_PointerExiting(cookie));
}

template <typename D> event_token impl_ICoreInkIndependentInputSource<D>::PointerPressing(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->add_PointerPressing(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreInkIndependentInputSource> impl_ICoreInkIndependentInputSource<D>::PointerPressing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreInkIndependentInputSource>(this, &ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource::remove_PointerPressing, PointerPressing(handler));
}

template <typename D> void impl_ICoreInkIndependentInputSource<D>::PointerPressing(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->remove_PointerPressing(cookie));
}

template <typename D> event_token impl_ICoreInkIndependentInputSource<D>::PointerMoving(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->add_PointerMoving(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreInkIndependentInputSource> impl_ICoreInkIndependentInputSource<D>::PointerMoving(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreInkIndependentInputSource>(this, &ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource::remove_PointerMoving, PointerMoving(handler));
}

template <typename D> void impl_ICoreInkIndependentInputSource<D>::PointerMoving(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->remove_PointerMoving(cookie));
}

template <typename D> event_token impl_ICoreInkIndependentInputSource<D>::PointerReleasing(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->add_PointerReleasing(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreInkIndependentInputSource> impl_ICoreInkIndependentInputSource<D>::PointerReleasing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreInkIndependentInputSource>(this, &ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource::remove_PointerReleasing, PointerReleasing(handler));
}

template <typename D> void impl_ICoreInkIndependentInputSource<D>::PointerReleasing(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->remove_PointerReleasing(cookie));
}

template <typename D> event_token impl_ICoreInkIndependentInputSource<D>::PointerLost(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->add_PointerLost(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreInkIndependentInputSource> impl_ICoreInkIndependentInputSource<D>::PointerLost(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreInkIndependentInputSource>(this, &ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource::remove_PointerLost, PointerLost(handler));
}

template <typename D> void impl_ICoreInkIndependentInputSource<D>::PointerLost(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->remove_PointerLost(cookie));
}

template <typename D> Windows::UI::Input::Inking::InkPresenter impl_ICoreInkIndependentInputSource<D>::InkPresenter() const
{
    Windows::UI::Input::Inking::InkPresenter value { nullptr };
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSource)->get_InkPresenter(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource impl_ICoreInkIndependentInputSourceStatics<D>::Create(const Windows::UI::Input::Inking::InkPresenter & inkPresenter) const
{
    Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource inkIndependentInputSource { nullptr };
    check_hresult(WINRT_SHIM(ICoreInkIndependentInputSourceStatics)->abi_Create(get_abi(inkPresenter), put_abi(inkIndependentInputSource)));
    return inkIndependentInputSource;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Input::Inking::InkPoint> impl_ICoreWetStrokeUpdateEventArgs<D>::NewInkPoints() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Input::Inking::InkPoint> value;
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateEventArgs)->get_NewInkPoints(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_ICoreWetStrokeUpdateEventArgs<D>::PointerId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateEventArgs)->get_PointerId(&value));
    return value;
}

template <typename D> Windows::UI::Input::Inking::Core::CoreWetStrokeDisposition impl_ICoreWetStrokeUpdateEventArgs<D>::Disposition() const
{
    Windows::UI::Input::Inking::Core::CoreWetStrokeDisposition value {};
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateEventArgs)->get_Disposition(&value));
    return value;
}

template <typename D> void impl_ICoreWetStrokeUpdateEventArgs<D>::Disposition(Windows::UI::Input::Inking::Core::CoreWetStrokeDisposition value) const
{
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateEventArgs)->put_Disposition(value));
}

template <typename D> event_token impl_ICoreWetStrokeUpdateSource<D>::WetStrokeStarting(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateSource)->add_WetStrokeStarting(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWetStrokeUpdateSource> impl_ICoreWetStrokeUpdateSource<D>::WetStrokeStarting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWetStrokeUpdateSource>(this, &ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource::remove_WetStrokeStarting, WetStrokeStarting(handler));
}

template <typename D> void impl_ICoreWetStrokeUpdateSource<D>::WetStrokeStarting(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateSource)->remove_WetStrokeStarting(cookie));
}

template <typename D> event_token impl_ICoreWetStrokeUpdateSource<D>::WetStrokeContinuing(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateSource)->add_WetStrokeContinuing(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWetStrokeUpdateSource> impl_ICoreWetStrokeUpdateSource<D>::WetStrokeContinuing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWetStrokeUpdateSource>(this, &ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource::remove_WetStrokeContinuing, WetStrokeContinuing(handler));
}

template <typename D> void impl_ICoreWetStrokeUpdateSource<D>::WetStrokeContinuing(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateSource)->remove_WetStrokeContinuing(cookie));
}

template <typename D> event_token impl_ICoreWetStrokeUpdateSource<D>::WetStrokeStopping(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateSource)->add_WetStrokeStopping(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWetStrokeUpdateSource> impl_ICoreWetStrokeUpdateSource<D>::WetStrokeStopping(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWetStrokeUpdateSource>(this, &ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource::remove_WetStrokeStopping, WetStrokeStopping(handler));
}

template <typename D> void impl_ICoreWetStrokeUpdateSource<D>::WetStrokeStopping(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateSource)->remove_WetStrokeStopping(cookie));
}

template <typename D> event_token impl_ICoreWetStrokeUpdateSource<D>::WetStrokeCompleted(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateSource)->add_WetStrokeCompleted(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWetStrokeUpdateSource> impl_ICoreWetStrokeUpdateSource<D>::WetStrokeCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWetStrokeUpdateSource>(this, &ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource::remove_WetStrokeCompleted, WetStrokeCompleted(handler));
}

template <typename D> void impl_ICoreWetStrokeUpdateSource<D>::WetStrokeCompleted(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateSource)->remove_WetStrokeCompleted(cookie));
}

template <typename D> event_token impl_ICoreWetStrokeUpdateSource<D>::WetStrokeCanceled(const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateSource)->add_WetStrokeCanceled(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWetStrokeUpdateSource> impl_ICoreWetStrokeUpdateSource<D>::WetStrokeCanceled(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWetStrokeUpdateSource>(this, &ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource::remove_WetStrokeCanceled, WetStrokeCanceled(handler));
}

template <typename D> void impl_ICoreWetStrokeUpdateSource<D>::WetStrokeCanceled(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateSource)->remove_WetStrokeCanceled(cookie));
}

template <typename D> Windows::UI::Input::Inking::InkPresenter impl_ICoreWetStrokeUpdateSource<D>::InkPresenter() const
{
    Windows::UI::Input::Inking::InkPresenter value { nullptr };
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateSource)->get_InkPresenter(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource impl_ICoreWetStrokeUpdateSourceStatics<D>::Create(const Windows::UI::Input::Inking::InkPresenter & inkPresenter) const
{
    Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource WetStrokeUpdateSource { nullptr };
    check_hresult(WINRT_SHIM(ICoreWetStrokeUpdateSourceStatics)->abi_Create(get_abi(inkPresenter), put_abi(WetStrokeUpdateSource)));
    return WetStrokeUpdateSource;
}

inline Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource CoreInkIndependentInputSource::Create(const Windows::UI::Input::Inking::InkPresenter & inkPresenter)
{
    return get_activation_factory<CoreInkIndependentInputSource, ICoreInkIndependentInputSourceStatics>().Create(inkPresenter);
}

inline Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource CoreWetStrokeUpdateSource::Create(const Windows::UI::Input::Inking::InkPresenter & inkPresenter)
{
    return get_activation_factory<CoreWetStrokeUpdateSource, ICoreWetStrokeUpdateSourceStatics>().Create(inkPresenter);
}

}

}
#pragma warning(pop)
