// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Graphics.Display.3.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Graphics::Display {

template <typename L> DisplayPropertiesEventHandler::DisplayPropertiesEventHandler(L lambda) :
    DisplayPropertiesEventHandler(impl::make_delegate<impl_DisplayPropertiesEventHandler<L>, DisplayPropertiesEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> DisplayPropertiesEventHandler::DisplayPropertiesEventHandler(F * function) :
    DisplayPropertiesEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> DisplayPropertiesEventHandler::DisplayPropertiesEventHandler(O * object, M method) :
    DisplayPropertiesEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void DisplayPropertiesEventHandler::operator()(const Windows::Foundation::IInspectable & sender) const
{
    check_hresult((*(abi<DisplayPropertiesEventHandler> **)this)->abi_Invoke(get_abi(sender)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Graphics::Display::IDisplayInformation> : produce_base<D, Windows::Graphics::Display::IDisplayInformation>
{
    HRESULT __stdcall get_CurrentOrientation(Windows::Graphics::Display::DisplayOrientations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentOrientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NativeOrientation(Windows::Graphics::Display::DisplayOrientations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NativeOrientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_OrientationChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().OrientationChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_OrientationChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OrientationChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResolutionScale(Windows::Graphics::Display::ResolutionScale * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResolutionScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LogicalDpi(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LogicalDpi());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RawDpiX(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawDpiX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RawDpiY(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawDpiY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DpiChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DpiChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DpiChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DpiChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StereoEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StereoEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StereoEnabledChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().StereoEnabledChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StereoEnabledChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StereoEnabledChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetColorProfileAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetColorProfileAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ColorProfileChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ColorProfileChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ColorProfileChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorProfileChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Display::IDisplayInformation2> : produce_base<D, Windows::Graphics::Display::IDisplayInformation2>
{
    HRESULT __stdcall get_RawPixelsPerViewPixel(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawPixelsPerViewPixel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Display::IDisplayInformation3> : produce_base<D, Windows::Graphics::Display::IDisplayInformation3>
{
    HRESULT __stdcall get_DiagonalSizeInInches(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DiagonalSizeInInches());
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
struct produce<D, Windows::Graphics::Display::IDisplayInformation4> : produce_base<D, Windows::Graphics::Display::IDisplayInformation4>
{
    HRESULT __stdcall get_ScreenWidthInRawPixels(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScreenWidthInRawPixels());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScreenHeightInRawPixels(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScreenHeightInRawPixels());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Display::IDisplayInformationStatics> : produce_base<D, Windows::Graphics::Display::IDisplayInformationStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::Graphics::Display::IDisplayInformation> current) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *current = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *current = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoRotationPreferences(Windows::Graphics::Display::DisplayOrientations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoRotationPreferences());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoRotationPreferences(Windows::Graphics::Display::DisplayOrientations value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoRotationPreferences(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DisplayContentsInvalidated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DisplayContentsInvalidated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DisplayContentsInvalidated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayContentsInvalidated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Display::IDisplayPropertiesStatics> : produce_base<D, Windows::Graphics::Display::IDisplayPropertiesStatics>
{
    HRESULT __stdcall get_CurrentOrientation(Windows::Graphics::Display::DisplayOrientations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentOrientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NativeOrientation(Windows::Graphics::Display::DisplayOrientations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NativeOrientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoRotationPreferences(Windows::Graphics::Display::DisplayOrientations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoRotationPreferences());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoRotationPreferences(Windows::Graphics::Display::DisplayOrientations value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoRotationPreferences(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_OrientationChanged(impl::abi_arg_in<Windows::Graphics::Display::DisplayPropertiesEventHandler> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().OrientationChanged(*reinterpret_cast<const Windows::Graphics::Display::DisplayPropertiesEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_OrientationChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OrientationChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResolutionScale(Windows::Graphics::Display::ResolutionScale * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResolutionScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LogicalDpi(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LogicalDpi());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_LogicalDpiChanged(impl::abi_arg_in<Windows::Graphics::Display::DisplayPropertiesEventHandler> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().LogicalDpiChanged(*reinterpret_cast<const Windows::Graphics::Display::DisplayPropertiesEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LogicalDpiChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogicalDpiChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StereoEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StereoEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StereoEnabledChanged(impl::abi_arg_in<Windows::Graphics::Display::DisplayPropertiesEventHandler> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().StereoEnabledChanged(*reinterpret_cast<const Windows::Graphics::Display::DisplayPropertiesEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StereoEnabledChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StereoEnabledChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetColorProfileAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetColorProfileAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ColorProfileChanged(impl::abi_arg_in<Windows::Graphics::Display::DisplayPropertiesEventHandler> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ColorProfileChanged(*reinterpret_cast<const Windows::Graphics::Display::DisplayPropertiesEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ColorProfileChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorProfileChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DisplayContentsInvalidated(impl::abi_arg_in<Windows::Graphics::Display::DisplayPropertiesEventHandler> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DisplayContentsInvalidated(*reinterpret_cast<const Windows::Graphics::Display::DisplayPropertiesEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DisplayContentsInvalidated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayContentsInvalidated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Graphics::Display {

template <typename D> Windows::Graphics::Display::DisplayInformation impl_IDisplayInformationStatics<D>::GetForCurrentView() const
{
    Windows::Graphics::Display::DisplayInformation current { nullptr };
    check_hresult(WINRT_SHIM(IDisplayInformationStatics)->abi_GetForCurrentView(put_abi(current)));
    return current;
}

template <typename D> Windows::Graphics::Display::DisplayOrientations impl_IDisplayInformationStatics<D>::AutoRotationPreferences() const
{
    Windows::Graphics::Display::DisplayOrientations value {};
    check_hresult(WINRT_SHIM(IDisplayInformationStatics)->get_AutoRotationPreferences(&value));
    return value;
}

template <typename D> void impl_IDisplayInformationStatics<D>::AutoRotationPreferences(Windows::Graphics::Display::DisplayOrientations value) const
{
    check_hresult(WINRT_SHIM(IDisplayInformationStatics)->put_AutoRotationPreferences(value));
}

template <typename D> event_token impl_IDisplayInformationStatics<D>::DisplayContentsInvalidated(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDisplayInformationStatics)->add_DisplayContentsInvalidated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDisplayInformationStatics> impl_IDisplayInformationStatics<D>::DisplayContentsInvalidated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDisplayInformationStatics>(this, &ABI::Windows::Graphics::Display::IDisplayInformationStatics::remove_DisplayContentsInvalidated, DisplayContentsInvalidated(handler));
}

template <typename D> void impl_IDisplayInformationStatics<D>::DisplayContentsInvalidated(event_token token) const
{
    check_hresult(WINRT_SHIM(IDisplayInformationStatics)->remove_DisplayContentsInvalidated(token));
}

template <typename D> Windows::Graphics::Display::DisplayOrientations impl_IDisplayInformation<D>::CurrentOrientation() const
{
    Windows::Graphics::Display::DisplayOrientations value {};
    check_hresult(WINRT_SHIM(IDisplayInformation)->get_CurrentOrientation(&value));
    return value;
}

template <typename D> Windows::Graphics::Display::DisplayOrientations impl_IDisplayInformation<D>::NativeOrientation() const
{
    Windows::Graphics::Display::DisplayOrientations value {};
    check_hresult(WINRT_SHIM(IDisplayInformation)->get_NativeOrientation(&value));
    return value;
}

template <typename D> event_token impl_IDisplayInformation<D>::OrientationChanged(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDisplayInformation)->add_OrientationChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDisplayInformation> impl_IDisplayInformation<D>::OrientationChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDisplayInformation>(this, &ABI::Windows::Graphics::Display::IDisplayInformation::remove_OrientationChanged, OrientationChanged(handler));
}

template <typename D> void impl_IDisplayInformation<D>::OrientationChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IDisplayInformation)->remove_OrientationChanged(token));
}

template <typename D> Windows::Graphics::Display::ResolutionScale impl_IDisplayInformation<D>::ResolutionScale() const
{
    Windows::Graphics::Display::ResolutionScale value {};
    check_hresult(WINRT_SHIM(IDisplayInformation)->get_ResolutionScale(&value));
    return value;
}

template <typename D> float impl_IDisplayInformation<D>::LogicalDpi() const
{
    float value {};
    check_hresult(WINRT_SHIM(IDisplayInformation)->get_LogicalDpi(&value));
    return value;
}

template <typename D> float impl_IDisplayInformation<D>::RawDpiX() const
{
    float value {};
    check_hresult(WINRT_SHIM(IDisplayInformation)->get_RawDpiX(&value));
    return value;
}

template <typename D> float impl_IDisplayInformation<D>::RawDpiY() const
{
    float value {};
    check_hresult(WINRT_SHIM(IDisplayInformation)->get_RawDpiY(&value));
    return value;
}

template <typename D> event_token impl_IDisplayInformation<D>::DpiChanged(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDisplayInformation)->add_DpiChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDisplayInformation> impl_IDisplayInformation<D>::DpiChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDisplayInformation>(this, &ABI::Windows::Graphics::Display::IDisplayInformation::remove_DpiChanged, DpiChanged(handler));
}

template <typename D> void impl_IDisplayInformation<D>::DpiChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IDisplayInformation)->remove_DpiChanged(token));
}

template <typename D> bool impl_IDisplayInformation<D>::StereoEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDisplayInformation)->get_StereoEnabled(&value));
    return value;
}

template <typename D> event_token impl_IDisplayInformation<D>::StereoEnabledChanged(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDisplayInformation)->add_StereoEnabledChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDisplayInformation> impl_IDisplayInformation<D>::StereoEnabledChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDisplayInformation>(this, &ABI::Windows::Graphics::Display::IDisplayInformation::remove_StereoEnabledChanged, StereoEnabledChanged(handler));
}

template <typename D> void impl_IDisplayInformation<D>::StereoEnabledChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IDisplayInformation)->remove_StereoEnabledChanged(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> impl_IDisplayInformation<D>::GetColorProfileAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> asyncInfo;
    check_hresult(WINRT_SHIM(IDisplayInformation)->abi_GetColorProfileAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> event_token impl_IDisplayInformation<D>::ColorProfileChanged(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDisplayInformation)->add_ColorProfileChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDisplayInformation> impl_IDisplayInformation<D>::ColorProfileChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDisplayInformation>(this, &ABI::Windows::Graphics::Display::IDisplayInformation::remove_ColorProfileChanged, ColorProfileChanged(handler));
}

template <typename D> void impl_IDisplayInformation<D>::ColorProfileChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IDisplayInformation)->remove_ColorProfileChanged(token));
}

template <typename D> double impl_IDisplayInformation2<D>::RawPixelsPerViewPixel() const
{
    double value {};
    check_hresult(WINRT_SHIM(IDisplayInformation2)->get_RawPixelsPerViewPixel(&value));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_IDisplayInformation3<D>::DiagonalSizeInInches() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IDisplayInformation3)->get_DiagonalSizeInInches(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IDisplayInformation4<D>::ScreenWidthInRawPixels() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IDisplayInformation4)->get_ScreenWidthInRawPixels(&value));
    return value;
}

template <typename D> uint32_t impl_IDisplayInformation4<D>::ScreenHeightInRawPixels() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IDisplayInformation4)->get_ScreenHeightInRawPixels(&value));
    return value;
}

template <typename D> Windows::Graphics::Display::DisplayOrientations impl_IDisplayPropertiesStatics<D>::CurrentOrientation() const
{
    Windows::Graphics::Display::DisplayOrientations value {};
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->get_CurrentOrientation(&value));
    return value;
}

template <typename D> Windows::Graphics::Display::DisplayOrientations impl_IDisplayPropertiesStatics<D>::NativeOrientation() const
{
    Windows::Graphics::Display::DisplayOrientations value {};
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->get_NativeOrientation(&value));
    return value;
}

template <typename D> Windows::Graphics::Display::DisplayOrientations impl_IDisplayPropertiesStatics<D>::AutoRotationPreferences() const
{
    Windows::Graphics::Display::DisplayOrientations value {};
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->get_AutoRotationPreferences(&value));
    return value;
}

template <typename D> void impl_IDisplayPropertiesStatics<D>::AutoRotationPreferences(Windows::Graphics::Display::DisplayOrientations value) const
{
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->put_AutoRotationPreferences(value));
}

template <typename D> event_token impl_IDisplayPropertiesStatics<D>::OrientationChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->add_OrientationChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDisplayPropertiesStatics> impl_IDisplayPropertiesStatics<D>::OrientationChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const
{
    return impl::make_event_revoker<D, IDisplayPropertiesStatics>(this, &ABI::Windows::Graphics::Display::IDisplayPropertiesStatics::remove_OrientationChanged, OrientationChanged(handler));
}

template <typename D> void impl_IDisplayPropertiesStatics<D>::OrientationChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->remove_OrientationChanged(token));
}

template <typename D> Windows::Graphics::Display::ResolutionScale impl_IDisplayPropertiesStatics<D>::ResolutionScale() const
{
    Windows::Graphics::Display::ResolutionScale value {};
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->get_ResolutionScale(&value));
    return value;
}

template <typename D> float impl_IDisplayPropertiesStatics<D>::LogicalDpi() const
{
    float value {};
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->get_LogicalDpi(&value));
    return value;
}

template <typename D> event_token impl_IDisplayPropertiesStatics<D>::LogicalDpiChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->add_LogicalDpiChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDisplayPropertiesStatics> impl_IDisplayPropertiesStatics<D>::LogicalDpiChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const
{
    return impl::make_event_revoker<D, IDisplayPropertiesStatics>(this, &ABI::Windows::Graphics::Display::IDisplayPropertiesStatics::remove_LogicalDpiChanged, LogicalDpiChanged(handler));
}

template <typename D> void impl_IDisplayPropertiesStatics<D>::LogicalDpiChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->remove_LogicalDpiChanged(token));
}

template <typename D> bool impl_IDisplayPropertiesStatics<D>::StereoEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->get_StereoEnabled(&value));
    return value;
}

template <typename D> event_token impl_IDisplayPropertiesStatics<D>::StereoEnabledChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->add_StereoEnabledChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDisplayPropertiesStatics> impl_IDisplayPropertiesStatics<D>::StereoEnabledChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const
{
    return impl::make_event_revoker<D, IDisplayPropertiesStatics>(this, &ABI::Windows::Graphics::Display::IDisplayPropertiesStatics::remove_StereoEnabledChanged, StereoEnabledChanged(handler));
}

template <typename D> void impl_IDisplayPropertiesStatics<D>::StereoEnabledChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->remove_StereoEnabledChanged(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> impl_IDisplayPropertiesStatics<D>::GetColorProfileAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> asyncInfo;
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->abi_GetColorProfileAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> event_token impl_IDisplayPropertiesStatics<D>::ColorProfileChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->add_ColorProfileChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDisplayPropertiesStatics> impl_IDisplayPropertiesStatics<D>::ColorProfileChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const
{
    return impl::make_event_revoker<D, IDisplayPropertiesStatics>(this, &ABI::Windows::Graphics::Display::IDisplayPropertiesStatics::remove_ColorProfileChanged, ColorProfileChanged(handler));
}

template <typename D> void impl_IDisplayPropertiesStatics<D>::ColorProfileChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->remove_ColorProfileChanged(token));
}

template <typename D> event_token impl_IDisplayPropertiesStatics<D>::DisplayContentsInvalidated(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->add_DisplayContentsInvalidated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDisplayPropertiesStatics> impl_IDisplayPropertiesStatics<D>::DisplayContentsInvalidated(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const
{
    return impl::make_event_revoker<D, IDisplayPropertiesStatics>(this, &ABI::Windows::Graphics::Display::IDisplayPropertiesStatics::remove_DisplayContentsInvalidated, DisplayContentsInvalidated(handler));
}

template <typename D> void impl_IDisplayPropertiesStatics<D>::DisplayContentsInvalidated(event_token token) const
{
    check_hresult(WINRT_SHIM(IDisplayPropertiesStatics)->remove_DisplayContentsInvalidated(token));
}

inline Windows::Graphics::Display::DisplayInformation DisplayInformation::GetForCurrentView()
{
    return get_activation_factory<DisplayInformation, IDisplayInformationStatics>().GetForCurrentView();
}

inline Windows::Graphics::Display::DisplayOrientations DisplayInformation::AutoRotationPreferences()
{
    return get_activation_factory<DisplayInformation, IDisplayInformationStatics>().AutoRotationPreferences();
}

inline void DisplayInformation::AutoRotationPreferences(Windows::Graphics::Display::DisplayOrientations value)
{
    get_activation_factory<DisplayInformation, IDisplayInformationStatics>().AutoRotationPreferences(value);
}

inline event_token DisplayInformation::DisplayContentsInvalidated(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<DisplayInformation, IDisplayInformationStatics>().DisplayContentsInvalidated(handler);
}

inline factory_event_revoker<IDisplayInformationStatics> DisplayInformation::DisplayContentsInvalidated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<DisplayInformation, IDisplayInformationStatics>();
    return { factory, &ABI::Windows::Graphics::Display::IDisplayInformationStatics::remove_DisplayContentsInvalidated, factory.DisplayContentsInvalidated(handler) };
}

inline void DisplayInformation::DisplayContentsInvalidated(event_token token)
{
    get_activation_factory<DisplayInformation, IDisplayInformationStatics>().DisplayContentsInvalidated(token);
}

inline Windows::Graphics::Display::DisplayOrientations DisplayProperties::CurrentOrientation()
{
    return get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().CurrentOrientation();
}

inline Windows::Graphics::Display::DisplayOrientations DisplayProperties::NativeOrientation()
{
    return get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().NativeOrientation();
}

inline Windows::Graphics::Display::DisplayOrientations DisplayProperties::AutoRotationPreferences()
{
    return get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().AutoRotationPreferences();
}

inline void DisplayProperties::AutoRotationPreferences(Windows::Graphics::Display::DisplayOrientations value)
{
    get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().AutoRotationPreferences(value);
}

inline event_token DisplayProperties::OrientationChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler)
{
    return get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().OrientationChanged(handler);
}

inline factory_event_revoker<IDisplayPropertiesStatics> DisplayProperties::OrientationChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler)
{
    auto factory = get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>();
    return { factory, &ABI::Windows::Graphics::Display::IDisplayPropertiesStatics::remove_OrientationChanged, factory.OrientationChanged(handler) };
}

inline void DisplayProperties::OrientationChanged(event_token token)
{
    get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().OrientationChanged(token);
}

inline Windows::Graphics::Display::ResolutionScale DisplayProperties::ResolutionScale()
{
    return get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().ResolutionScale();
}

inline float DisplayProperties::LogicalDpi()
{
    return get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().LogicalDpi();
}

inline event_token DisplayProperties::LogicalDpiChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler)
{
    return get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().LogicalDpiChanged(handler);
}

inline factory_event_revoker<IDisplayPropertiesStatics> DisplayProperties::LogicalDpiChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler)
{
    auto factory = get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>();
    return { factory, &ABI::Windows::Graphics::Display::IDisplayPropertiesStatics::remove_LogicalDpiChanged, factory.LogicalDpiChanged(handler) };
}

inline void DisplayProperties::LogicalDpiChanged(event_token token)
{
    get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().LogicalDpiChanged(token);
}

inline bool DisplayProperties::StereoEnabled()
{
    return get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().StereoEnabled();
}

inline event_token DisplayProperties::StereoEnabledChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler)
{
    return get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().StereoEnabledChanged(handler);
}

inline factory_event_revoker<IDisplayPropertiesStatics> DisplayProperties::StereoEnabledChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler)
{
    auto factory = get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>();
    return { factory, &ABI::Windows::Graphics::Display::IDisplayPropertiesStatics::remove_StereoEnabledChanged, factory.StereoEnabledChanged(handler) };
}

inline void DisplayProperties::StereoEnabledChanged(event_token token)
{
    get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().StereoEnabledChanged(token);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> DisplayProperties::GetColorProfileAsync()
{
    return get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().GetColorProfileAsync();
}

inline event_token DisplayProperties::ColorProfileChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler)
{
    return get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().ColorProfileChanged(handler);
}

inline factory_event_revoker<IDisplayPropertiesStatics> DisplayProperties::ColorProfileChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler)
{
    auto factory = get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>();
    return { factory, &ABI::Windows::Graphics::Display::IDisplayPropertiesStatics::remove_ColorProfileChanged, factory.ColorProfileChanged(handler) };
}

inline void DisplayProperties::ColorProfileChanged(event_token token)
{
    get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().ColorProfileChanged(token);
}

inline event_token DisplayProperties::DisplayContentsInvalidated(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler)
{
    return get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().DisplayContentsInvalidated(handler);
}

inline factory_event_revoker<IDisplayPropertiesStatics> DisplayProperties::DisplayContentsInvalidated(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler)
{
    auto factory = get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>();
    return { factory, &ABI::Windows::Graphics::Display::IDisplayPropertiesStatics::remove_DisplayContentsInvalidated, factory.DisplayContentsInvalidated(handler) };
}

inline void DisplayProperties::DisplayContentsInvalidated(event_token token)
{
    get_activation_factory<DisplayProperties, IDisplayPropertiesStatics>().DisplayContentsInvalidated(token);
}

}

}
#pragma warning(pop)
