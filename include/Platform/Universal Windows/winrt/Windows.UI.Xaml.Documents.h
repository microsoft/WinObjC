// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.UI.Xaml.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Xaml.Media.3.h"
#include "internal/Windows.UI.Text.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.Xaml.Documents.3.h"
#include "Windows.UI.Xaml.h"
#include "Windows.Foundation.Collections.h"
#include "internal/Windows.UI.Xaml.Documents.4.h"
#include "internal/Windows.UI.Xaml.Documents.5.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IBlock> : produce_base<D, Windows::UI::Xaml::Documents::IBlock>
{
    HRESULT __stdcall get_TextAlignment(Windows::UI::Xaml::TextAlignment * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextAlignment());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TextAlignment(Windows::UI::Xaml::TextAlignment value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextAlignment(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LineHeight(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LineHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LineHeight(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LineHeight(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LineStackingStrategy(Windows::UI::Xaml::LineStackingStrategy * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LineStackingStrategy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LineStackingStrategy(Windows::UI::Xaml::LineStackingStrategy value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LineStackingStrategy(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Margin(impl::abi_arg_out<Windows::UI::Xaml::Thickness> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Margin());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Margin(impl::abi_arg_in<Windows::UI::Xaml::Thickness> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Margin(*reinterpret_cast<const Windows::UI::Xaml::Thickness *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IBlockFactory> : produce_base<D, Windows::UI::Xaml::Documents::IBlockFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Documents::IBlock> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IBlockStatics> : produce_base<D, Windows::UI::Xaml::Documents::IBlockStatics>
{
    HRESULT __stdcall get_TextAlignmentProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextAlignmentProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LineHeightProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LineHeightProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LineStackingStrategyProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LineStackingStrategyProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MarginProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MarginProperty());
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
struct produce<D, Windows::UI::Xaml::Documents::IBold> : produce_base<D, Windows::UI::Xaml::Documents::IBold>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IGlyphs> : produce_base<D, Windows::UI::Xaml::Documents::IGlyphs>
{
    HRESULT __stdcall get_UnicodeString(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnicodeString());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UnicodeString(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnicodeString(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Indices(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Indices());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Indices(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Indices(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FontUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FontUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StyleSimulations(Windows::UI::Xaml::Media::StyleSimulations * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StyleSimulations());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StyleSimulations(Windows::UI::Xaml::Media::StyleSimulations value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StyleSimulations(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontRenderingEmSize(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontRenderingEmSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FontRenderingEmSize(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FontRenderingEmSize(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OriginX(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OriginX());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OriginX(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OriginX(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OriginY(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OriginY());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OriginY(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OriginY(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Fill(impl::abi_arg_out<Windows::UI::Xaml::Media::IBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Fill());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Fill(impl::abi_arg_in<Windows::UI::Xaml::Media::IBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Fill(*reinterpret_cast<const Windows::UI::Xaml::Media::Brush *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IGlyphs2> : produce_base<D, Windows::UI::Xaml::Documents::IGlyphs2>
{
    HRESULT __stdcall get_IsColorFontEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsColorFontEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsColorFontEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsColorFontEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ColorFontPaletteIndex(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColorFontPaletteIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ColorFontPaletteIndex(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorFontPaletteIndex(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IGlyphsStatics> : produce_base<D, Windows::UI::Xaml::Documents::IGlyphsStatics>
{
    HRESULT __stdcall get_UnicodeStringProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnicodeStringProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IndicesProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IndicesProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontUriProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontUriProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StyleSimulationsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StyleSimulationsProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontRenderingEmSizeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontRenderingEmSizeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OriginXProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OriginXProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OriginYProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OriginYProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FillProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FillProperty());
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
struct produce<D, Windows::UI::Xaml::Documents::IGlyphsStatics2> : produce_base<D, Windows::UI::Xaml::Documents::IGlyphsStatics2>
{
    HRESULT __stdcall get_IsColorFontEnabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsColorFontEnabledProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ColorFontPaletteIndexProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColorFontPaletteIndexProperty());
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
struct produce<D, Windows::UI::Xaml::Documents::IHyperlink> : produce_base<D, Windows::UI::Xaml::Documents::IHyperlink>
{
    HRESULT __stdcall get_NavigateUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NavigateUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NavigateUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NavigateUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Click(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Documents::Hyperlink, Windows::UI::Xaml::Documents::HyperlinkClickEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Click(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Documents::Hyperlink, Windows::UI::Xaml::Documents::HyperlinkClickEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Click(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Click(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IHyperlink2> : produce_base<D, Windows::UI::Xaml::Documents::IHyperlink2>
{
    HRESULT __stdcall get_UnderlineStyle(Windows::UI::Xaml::Documents::UnderlineStyle * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnderlineStyle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UnderlineStyle(Windows::UI::Xaml::Documents::UnderlineStyle value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnderlineStyle(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IHyperlink3> : produce_base<D, Windows::UI::Xaml::Documents::IHyperlink3>
{
    HRESULT __stdcall get_XYFocusLeft(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XYFocusLeft());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_XYFocusLeft(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().XYFocusLeft(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XYFocusRight(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XYFocusRight());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_XYFocusRight(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().XYFocusRight(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XYFocusUp(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XYFocusUp());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_XYFocusUp(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().XYFocusUp(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XYFocusDown(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XYFocusDown());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_XYFocusDown(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().XYFocusDown(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ElementSoundMode(Windows::UI::Xaml::ElementSoundMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ElementSoundMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ElementSoundMode(Windows::UI::Xaml::ElementSoundMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ElementSoundMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IHyperlinkClickEventArgs> : produce_base<D, Windows::UI::Xaml::Documents::IHyperlinkClickEventArgs>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IHyperlinkStatics> : produce_base<D, Windows::UI::Xaml::Documents::IHyperlinkStatics>
{
    HRESULT __stdcall get_NavigateUriProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NavigateUriProperty());
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
struct produce<D, Windows::UI::Xaml::Documents::IHyperlinkStatics2> : produce_base<D, Windows::UI::Xaml::Documents::IHyperlinkStatics2>
{
    HRESULT __stdcall get_UnderlineStyleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnderlineStyleProperty());
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
struct produce<D, Windows::UI::Xaml::Documents::IHyperlinkStatics3> : produce_base<D, Windows::UI::Xaml::Documents::IHyperlinkStatics3>
{
    HRESULT __stdcall get_XYFocusLeftProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XYFocusLeftProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XYFocusRightProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XYFocusRightProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XYFocusUpProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XYFocusUpProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XYFocusDownProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().XYFocusDownProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ElementSoundModeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ElementSoundModeProperty());
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
struct produce<D, Windows::UI::Xaml::Documents::IInline> : produce_base<D, Windows::UI::Xaml::Documents::IInline>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IInlineFactory> : produce_base<D, Windows::UI::Xaml::Documents::IInlineFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Documents::IInline> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IInlineUIContainer> : produce_base<D, Windows::UI::Xaml::Documents::IInlineUIContainer>
{
    HRESULT __stdcall get_Child(impl::abi_arg_out<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Child());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Child(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Child(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IItalic> : produce_base<D, Windows::UI::Xaml::Documents::IItalic>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::ILineBreak> : produce_base<D, Windows::UI::Xaml::Documents::ILineBreak>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IParagraph> : produce_base<D, Windows::UI::Xaml::Documents::IParagraph>
{
    HRESULT __stdcall get_Inlines(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Documents::Inline>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Inlines());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextIndent(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextIndent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TextIndent(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextIndent(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IParagraphStatics> : produce_base<D, Windows::UI::Xaml::Documents::IParagraphStatics>
{
    HRESULT __stdcall get_TextIndentProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextIndentProperty());
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
struct produce<D, Windows::UI::Xaml::Documents::IRun> : produce_base<D, Windows::UI::Xaml::Documents::IRun>
{
    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Text(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Text(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FlowDirection(Windows::UI::Xaml::FlowDirection * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FlowDirection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FlowDirection(Windows::UI::Xaml::FlowDirection value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FlowDirection(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IRunStatics> : produce_base<D, Windows::UI::Xaml::Documents::IRunStatics>
{
    HRESULT __stdcall get_FlowDirectionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FlowDirectionProperty());
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
struct produce<D, Windows::UI::Xaml::Documents::ISpan> : produce_base<D, Windows::UI::Xaml::Documents::ISpan>
{
    HRESULT __stdcall get_Inlines(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Documents::Inline>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Inlines());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Inlines(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Documents::Inline>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Inlines(*reinterpret_cast<const Windows::UI::Xaml::Documents::InlineCollection *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::ISpanFactory> : produce_base<D, Windows::UI::Xaml::Documents::ISpanFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Documents::ISpan> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::ITextElement> : produce_base<D, Windows::UI::Xaml::Documents::ITextElement>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontSize(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FontSize(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FontSize(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontFamily(impl::abi_arg_out<Windows::UI::Xaml::Media::IFontFamily> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontFamily());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FontFamily(impl::abi_arg_in<Windows::UI::Xaml::Media::IFontFamily> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FontFamily(*reinterpret_cast<const Windows::UI::Xaml::Media::FontFamily *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontWeight(impl::abi_arg_out<Windows::UI::Text::FontWeight> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontWeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FontWeight(impl::abi_arg_in<Windows::UI::Text::FontWeight> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FontWeight(*reinterpret_cast<const Windows::UI::Text::FontWeight *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontStyle(Windows::UI::Text::FontStyle * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontStyle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FontStyle(Windows::UI::Text::FontStyle value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FontStyle(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontStretch(Windows::UI::Text::FontStretch * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontStretch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FontStretch(Windows::UI::Text::FontStretch value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FontStretch(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CharacterSpacing(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CharacterSpacing());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CharacterSpacing(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CharacterSpacing(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Foreground(impl::abi_arg_out<Windows::UI::Xaml::Media::IBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Foreground());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Foreground(impl::abi_arg_in<Windows::UI::Xaml::Media::IBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Foreground(*reinterpret_cast<const Windows::UI::Xaml::Media::Brush *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Language(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Language(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentStart(impl::abi_arg_out<Windows::UI::Xaml::Documents::ITextPointer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentStart());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentEnd(impl::abi_arg_out<Windows::UI::Xaml::Documents::ITextPointer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentEnd());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ElementStart(impl::abi_arg_out<Windows::UI::Xaml::Documents::ITextPointer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ElementStart());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ElementEnd(impl::abi_arg_out<Windows::UI::Xaml::Documents::ITextPointer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ElementEnd());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindName(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FindName(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::ITextElement2> : produce_base<D, Windows::UI::Xaml::Documents::ITextElement2>
{
    HRESULT __stdcall get_IsTextScaleFactorEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTextScaleFactorEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsTextScaleFactorEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsTextScaleFactorEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::ITextElement3> : produce_base<D, Windows::UI::Xaml::Documents::ITextElement3>
{
    HRESULT __stdcall get_AllowFocusOnInteraction(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowFocusOnInteraction());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowFocusOnInteraction(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowFocusOnInteraction(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccessKey(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccessKey());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AccessKey(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccessKey(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitDisplayModeOnAccessKeyInvoked(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitDisplayModeOnAccessKeyInvoked());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExitDisplayModeOnAccessKeyInvoked(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExitDisplayModeOnAccessKeyInvoked(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::ITextElementFactory> : produce_base<D, Windows::UI::Xaml::Documents::ITextElementFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::ITextElementOverrides> : produce_base<D, Windows::UI::Xaml::Documents::ITextElementOverrides>
{
    HRESULT __stdcall abi_OnDisconnectVisualChildren() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnDisconnectVisualChildren();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::ITextElementStatics> : produce_base<D, Windows::UI::Xaml::Documents::ITextElementStatics>
{
    HRESULT __stdcall get_FontSizeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontSizeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontFamilyProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontFamilyProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontWeightProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontWeightProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontStyleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontStyleProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontStretchProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontStretchProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CharacterSpacingProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CharacterSpacingProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ForegroundProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ForegroundProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LanguageProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LanguageProperty());
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
struct produce<D, Windows::UI::Xaml::Documents::ITextElementStatics2> : produce_base<D, Windows::UI::Xaml::Documents::ITextElementStatics2>
{
    HRESULT __stdcall get_IsTextScaleFactorEnabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTextScaleFactorEnabledProperty());
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
struct produce<D, Windows::UI::Xaml::Documents::ITextElementStatics3> : produce_base<D, Windows::UI::Xaml::Documents::ITextElementStatics3>
{
    HRESULT __stdcall get_AllowFocusOnInteractionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowFocusOnInteractionProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccessKeyProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccessKeyProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitDisplayModeOnAccessKeyInvokedProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitDisplayModeOnAccessKeyInvokedProperty());
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
struct produce<D, Windows::UI::Xaml::Documents::ITextPointer> : produce_base<D, Windows::UI::Xaml::Documents::ITextPointer>
{
    HRESULT __stdcall get_Parent(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VisualParent(impl::abi_arg_out<Windows::UI::Xaml::IFrameworkElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VisualParent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LogicalDirection(Windows::UI::Xaml::Documents::LogicalDirection * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LogicalDirection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Offset(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Offset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCharacterRect(Windows::UI::Xaml::Documents::LogicalDirection direction, impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetCharacterRect(direction));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPositionAtOffset(int32_t offset, Windows::UI::Xaml::Documents::LogicalDirection direction, impl::abi_arg_out<Windows::UI::Xaml::Documents::ITextPointer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPositionAtOffset(offset, direction));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::ITypography> : produce_base<D, Windows::UI::Xaml::Documents::ITypography>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::ITypographyStatics> : produce_base<D, Windows::UI::Xaml::Documents::ITypographyStatics>
{
    HRESULT __stdcall get_AnnotationAlternatesProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AnnotationAlternatesProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAnnotationAlternates(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetAnnotationAlternates(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetAnnotationAlternates(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetAnnotationAlternates(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EastAsianExpertFormsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EastAsianExpertFormsProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEastAsianExpertForms(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetEastAsianExpertForms(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetEastAsianExpertForms(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetEastAsianExpertForms(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EastAsianLanguageProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EastAsianLanguageProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEastAsianLanguage(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, Windows::UI::Xaml::FontEastAsianLanguage * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetEastAsianLanguage(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetEastAsianLanguage(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, Windows::UI::Xaml::FontEastAsianLanguage value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetEastAsianLanguage(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EastAsianWidthsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EastAsianWidthsProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEastAsianWidths(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, Windows::UI::Xaml::FontEastAsianWidths * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetEastAsianWidths(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetEastAsianWidths(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, Windows::UI::Xaml::FontEastAsianWidths value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetEastAsianWidths(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StandardLigaturesProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StandardLigaturesProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStandardLigatures(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStandardLigatures(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStandardLigatures(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStandardLigatures(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContextualLigaturesProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContextualLigaturesProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContextualLigatures(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetContextualLigatures(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetContextualLigatures(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContextualLigatures(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DiscretionaryLigaturesProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DiscretionaryLigaturesProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDiscretionaryLigatures(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDiscretionaryLigatures(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDiscretionaryLigatures(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDiscretionaryLigatures(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HistoricalLigaturesProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HistoricalLigaturesProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHistoricalLigatures(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetHistoricalLigatures(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetHistoricalLigatures(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetHistoricalLigatures(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StandardSwashesProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StandardSwashesProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStandardSwashes(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStandardSwashes(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStandardSwashes(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStandardSwashes(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContextualSwashesProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContextualSwashesProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContextualSwashes(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetContextualSwashes(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetContextualSwashes(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContextualSwashes(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContextualAlternatesProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContextualAlternatesProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContextualAlternates(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetContextualAlternates(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetContextualAlternates(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContextualAlternates(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticAlternatesProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticAlternatesProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticAlternates(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticAlternates(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticAlternates(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticAlternates(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet1Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet1Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet1(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet1(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet1(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet1(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet2Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet2Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet2(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet2(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet2(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet2(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet3Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet3Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet3(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet3(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet3(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet3(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet4Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet4Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet4(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet4(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet4(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet4(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet5Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet5Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet5(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet5(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet5(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet5(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet6Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet6Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet6(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet6(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet6(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet6(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet7Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet7Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet7(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet7(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet7(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet7(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet8Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet8Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet8(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet8(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet8(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet8(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet9Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet9Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet9(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet9(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet9(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet9(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet10Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet10Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet10(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet10(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet10(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet10(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet11Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet11Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet11(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet11(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet11(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet11(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet12Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet12Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet12(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet12(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet12(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet12(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet13Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet13Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet13(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet13(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet13(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet13(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet14Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet14Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet14(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet14(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet14(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet14(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet15Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet15Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet15(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet15(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet15(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet15(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet16Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet16Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet16(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet16(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet16(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet16(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet17Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet17Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet17(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet17(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet17(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet17(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet18Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet18Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet18(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet18(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet18(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet18(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet19Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet19Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet19(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet19(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet19(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet19(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StylisticSet20Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StylisticSet20Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStylisticSet20(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStylisticSet20(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStylisticSet20(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStylisticSet20(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CapitalsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CapitalsProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCapitals(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, Windows::UI::Xaml::FontCapitals * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCapitals(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetCapitals(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, Windows::UI::Xaml::FontCapitals value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetCapitals(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CapitalSpacingProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CapitalSpacingProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCapitalSpacing(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCapitalSpacing(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetCapitalSpacing(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetCapitalSpacing(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KerningProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KerningProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetKerning(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetKerning(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetKerning(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetKerning(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CaseSensitiveFormsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CaseSensitiveFormsProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCaseSensitiveForms(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCaseSensitiveForms(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetCaseSensitiveForms(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetCaseSensitiveForms(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HistoricalFormsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HistoricalFormsProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHistoricalForms(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetHistoricalForms(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetHistoricalForms(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetHistoricalForms(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FractionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FractionProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFraction(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, Windows::UI::Xaml::FontFraction * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetFraction(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetFraction(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, Windows::UI::Xaml::FontFraction value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFraction(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumeralStyleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NumeralStyleProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNumeralStyle(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, Windows::UI::Xaml::FontNumeralStyle * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetNumeralStyle(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetNumeralStyle(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, Windows::UI::Xaml::FontNumeralStyle value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetNumeralStyle(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumeralAlignmentProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NumeralAlignmentProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNumeralAlignment(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, Windows::UI::Xaml::FontNumeralAlignment * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetNumeralAlignment(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetNumeralAlignment(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, Windows::UI::Xaml::FontNumeralAlignment value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetNumeralAlignment(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SlashedZeroProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SlashedZeroProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSlashedZero(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetSlashedZero(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetSlashedZero(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSlashedZero(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MathematicalGreekProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MathematicalGreekProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMathematicalGreek(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetMathematicalGreek(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetMathematicalGreek(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetMathematicalGreek(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VariantsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VariantsProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetVariants(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, Windows::UI::Xaml::FontVariants * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetVariants(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetVariants(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, Windows::UI::Xaml::FontVariants value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetVariants(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Documents::IUnderline> : produce_base<D, Windows::UI::Xaml::Documents::IUnderline>
{};

}

namespace Windows::UI::Xaml::Documents {

template <typename D> Windows::UI::Xaml::DependencyObject impl_ITextPointer<D>::Parent() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(ITextPointer)->get_Parent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::FrameworkElement impl_ITextPointer<D>::VisualParent() const
{
    Windows::UI::Xaml::FrameworkElement value { nullptr };
    check_hresult(WINRT_SHIM(ITextPointer)->get_VisualParent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Documents::LogicalDirection impl_ITextPointer<D>::LogicalDirection() const
{
    Windows::UI::Xaml::Documents::LogicalDirection value {};
    check_hresult(WINRT_SHIM(ITextPointer)->get_LogicalDirection(&value));
    return value;
}

template <typename D> int32_t impl_ITextPointer<D>::Offset() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ITextPointer)->get_Offset(&value));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_ITextPointer<D>::GetCharacterRect(Windows::UI::Xaml::Documents::LogicalDirection direction) const
{
    Windows::Foundation::Rect returnValue {};
    check_hresult(WINRT_SHIM(ITextPointer)->abi_GetCharacterRect(direction, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Documents::TextPointer impl_ITextPointer<D>::GetPositionAtOffset(int32_t offset, Windows::UI::Xaml::Documents::LogicalDirection direction) const
{
    Windows::UI::Xaml::Documents::TextPointer returnValue { nullptr };
    check_hresult(WINRT_SHIM(ITextPointer)->abi_GetPositionAtOffset(offset, direction, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::AnnotationAlternatesProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_AnnotationAlternatesProperty(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_ITypographyStatics<D>::GetAnnotationAlternates(const Windows::UI::Xaml::DependencyObject & element) const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetAnnotationAlternates(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetAnnotationAlternates(const Windows::UI::Xaml::DependencyObject & element, int32_t value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetAnnotationAlternates(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::EastAsianExpertFormsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_EastAsianExpertFormsProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetEastAsianExpertForms(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetEastAsianExpertForms(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetEastAsianExpertForms(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetEastAsianExpertForms(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::EastAsianLanguageProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_EastAsianLanguageProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::FontEastAsianLanguage impl_ITypographyStatics<D>::GetEastAsianLanguage(const Windows::UI::Xaml::DependencyObject & element) const
{
    Windows::UI::Xaml::FontEastAsianLanguage value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetEastAsianLanguage(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetEastAsianLanguage(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontEastAsianLanguage value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetEastAsianLanguage(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::EastAsianWidthsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_EastAsianWidthsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::FontEastAsianWidths impl_ITypographyStatics<D>::GetEastAsianWidths(const Windows::UI::Xaml::DependencyObject & element) const
{
    Windows::UI::Xaml::FontEastAsianWidths value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetEastAsianWidths(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetEastAsianWidths(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontEastAsianWidths value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetEastAsianWidths(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StandardLigaturesProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StandardLigaturesProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStandardLigatures(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStandardLigatures(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStandardLigatures(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStandardLigatures(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::ContextualLigaturesProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_ContextualLigaturesProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetContextualLigatures(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetContextualLigatures(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetContextualLigatures(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetContextualLigatures(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::DiscretionaryLigaturesProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_DiscretionaryLigaturesProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetDiscretionaryLigatures(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetDiscretionaryLigatures(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetDiscretionaryLigatures(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetDiscretionaryLigatures(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::HistoricalLigaturesProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_HistoricalLigaturesProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetHistoricalLigatures(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetHistoricalLigatures(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetHistoricalLigatures(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetHistoricalLigatures(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StandardSwashesProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StandardSwashesProperty(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_ITypographyStatics<D>::GetStandardSwashes(const Windows::UI::Xaml::DependencyObject & element) const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStandardSwashes(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStandardSwashes(const Windows::UI::Xaml::DependencyObject & element, int32_t value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStandardSwashes(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::ContextualSwashesProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_ContextualSwashesProperty(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_ITypographyStatics<D>::GetContextualSwashes(const Windows::UI::Xaml::DependencyObject & element) const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetContextualSwashes(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetContextualSwashes(const Windows::UI::Xaml::DependencyObject & element, int32_t value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetContextualSwashes(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::ContextualAlternatesProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_ContextualAlternatesProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetContextualAlternates(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetContextualAlternates(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetContextualAlternates(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetContextualAlternates(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticAlternatesProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticAlternatesProperty(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_ITypographyStatics<D>::GetStylisticAlternates(const Windows::UI::Xaml::DependencyObject & element) const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticAlternates(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticAlternates(const Windows::UI::Xaml::DependencyObject & element, int32_t value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticAlternates(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet1Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet1Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet1(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet1(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet1(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet1(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet2Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet2Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet2(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet2(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet2(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet2(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet3Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet3Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet3(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet3(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet3(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet3(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet4Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet4Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet4(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet4(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet4(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet4(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet5Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet5Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet5(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet5(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet5(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet5(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet6Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet6Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet6(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet6(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet6(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet6(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet7Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet7Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet7(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet7(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet7(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet7(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet8Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet8Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet8(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet8(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet8(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet8(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet9Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet9Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet9(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet9(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet9(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet9(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet10Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet10Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet10(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet10(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet10(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet10(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet11Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet11Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet11(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet11(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet11(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet11(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet12Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet12Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet12(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet12(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet12(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet12(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet13Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet13Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet13(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet13(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet13(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet13(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet14Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet14Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet14(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet14(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet14(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet14(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet15Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet15Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet15(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet15(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet15(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet15(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet16Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet16Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet16(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet16(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet16(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet16(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet17Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet17Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet17(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet17(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet17(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet17(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet18Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet18Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet18(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet18(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet18(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet18(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet19Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet19Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet19(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet19(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet19(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet19(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::StylisticSet20Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_StylisticSet20Property(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetStylisticSet20(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetStylisticSet20(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetStylisticSet20(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetStylisticSet20(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::CapitalsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_CapitalsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::FontCapitals impl_ITypographyStatics<D>::GetCapitals(const Windows::UI::Xaml::DependencyObject & element) const
{
    Windows::UI::Xaml::FontCapitals value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetCapitals(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetCapitals(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontCapitals value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetCapitals(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::CapitalSpacingProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_CapitalSpacingProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetCapitalSpacing(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetCapitalSpacing(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetCapitalSpacing(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetCapitalSpacing(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::KerningProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_KerningProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetKerning(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetKerning(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetKerning(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetKerning(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::CaseSensitiveFormsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_CaseSensitiveFormsProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetCaseSensitiveForms(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetCaseSensitiveForms(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetCaseSensitiveForms(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetCaseSensitiveForms(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::HistoricalFormsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_HistoricalFormsProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetHistoricalForms(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetHistoricalForms(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetHistoricalForms(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetHistoricalForms(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::FractionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_FractionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::FontFraction impl_ITypographyStatics<D>::GetFraction(const Windows::UI::Xaml::DependencyObject & element) const
{
    Windows::UI::Xaml::FontFraction value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetFraction(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetFraction(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontFraction value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetFraction(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::NumeralStyleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_NumeralStyleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::FontNumeralStyle impl_ITypographyStatics<D>::GetNumeralStyle(const Windows::UI::Xaml::DependencyObject & element) const
{
    Windows::UI::Xaml::FontNumeralStyle value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetNumeralStyle(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetNumeralStyle(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontNumeralStyle value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetNumeralStyle(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::NumeralAlignmentProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_NumeralAlignmentProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::FontNumeralAlignment impl_ITypographyStatics<D>::GetNumeralAlignment(const Windows::UI::Xaml::DependencyObject & element) const
{
    Windows::UI::Xaml::FontNumeralAlignment value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetNumeralAlignment(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetNumeralAlignment(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontNumeralAlignment value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetNumeralAlignment(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::SlashedZeroProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_SlashedZeroProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetSlashedZero(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetSlashedZero(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetSlashedZero(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetSlashedZero(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::MathematicalGreekProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_MathematicalGreekProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITypographyStatics<D>::GetMathematicalGreek(const Windows::UI::Xaml::DependencyObject & element) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetMathematicalGreek(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetMathematicalGreek(const Windows::UI::Xaml::DependencyObject & element, bool value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetMathematicalGreek(get_abi(element), value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITypographyStatics<D>::VariantsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITypographyStatics)->get_VariantsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::FontVariants impl_ITypographyStatics<D>::GetVariants(const Windows::UI::Xaml::DependencyObject & element) const
{
    Windows::UI::Xaml::FontVariants value {};
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_GetVariants(get_abi(element), &value));
    return value;
}

template <typename D> void impl_ITypographyStatics<D>::SetVariants(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontVariants value) const
{
    check_hresult(WINRT_SHIM(ITypographyStatics)->abi_SetVariants(get_abi(element), value));
}

template <typename D> hstring impl_ITextElement<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITextElement)->get_Name(put_abi(value)));
    return value;
}

template <typename D> double impl_ITextElement<D>::FontSize() const
{
    double value {};
    check_hresult(WINRT_SHIM(ITextElement)->get_FontSize(&value));
    return value;
}

template <typename D> void impl_ITextElement<D>::FontSize(double value) const
{
    check_hresult(WINRT_SHIM(ITextElement)->put_FontSize(value));
}

template <typename D> Windows::UI::Xaml::Media::FontFamily impl_ITextElement<D>::FontFamily() const
{
    Windows::UI::Xaml::Media::FontFamily value { nullptr };
    check_hresult(WINRT_SHIM(ITextElement)->get_FontFamily(put_abi(value)));
    return value;
}

template <typename D> void impl_ITextElement<D>::FontFamily(const Windows::UI::Xaml::Media::FontFamily & value) const
{
    check_hresult(WINRT_SHIM(ITextElement)->put_FontFamily(get_abi(value)));
}

template <typename D> Windows::UI::Text::FontWeight impl_ITextElement<D>::FontWeight() const
{
    Windows::UI::Text::FontWeight value {};
    check_hresult(WINRT_SHIM(ITextElement)->get_FontWeight(put_abi(value)));
    return value;
}

template <typename D> void impl_ITextElement<D>::FontWeight(const Windows::UI::Text::FontWeight & value) const
{
    check_hresult(WINRT_SHIM(ITextElement)->put_FontWeight(get_abi(value)));
}

template <typename D> Windows::UI::Text::FontStyle impl_ITextElement<D>::FontStyle() const
{
    Windows::UI::Text::FontStyle value {};
    check_hresult(WINRT_SHIM(ITextElement)->get_FontStyle(&value));
    return value;
}

template <typename D> void impl_ITextElement<D>::FontStyle(Windows::UI::Text::FontStyle value) const
{
    check_hresult(WINRT_SHIM(ITextElement)->put_FontStyle(value));
}

template <typename D> Windows::UI::Text::FontStretch impl_ITextElement<D>::FontStretch() const
{
    Windows::UI::Text::FontStretch value {};
    check_hresult(WINRT_SHIM(ITextElement)->get_FontStretch(&value));
    return value;
}

template <typename D> void impl_ITextElement<D>::FontStretch(Windows::UI::Text::FontStretch value) const
{
    check_hresult(WINRT_SHIM(ITextElement)->put_FontStretch(value));
}

template <typename D> int32_t impl_ITextElement<D>::CharacterSpacing() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ITextElement)->get_CharacterSpacing(&value));
    return value;
}

template <typename D> void impl_ITextElement<D>::CharacterSpacing(int32_t value) const
{
    check_hresult(WINRT_SHIM(ITextElement)->put_CharacterSpacing(value));
}

template <typename D> Windows::UI::Xaml::Media::Brush impl_ITextElement<D>::Foreground() const
{
    Windows::UI::Xaml::Media::Brush value { nullptr };
    check_hresult(WINRT_SHIM(ITextElement)->get_Foreground(put_abi(value)));
    return value;
}

template <typename D> void impl_ITextElement<D>::Foreground(const Windows::UI::Xaml::Media::Brush & value) const
{
    check_hresult(WINRT_SHIM(ITextElement)->put_Foreground(get_abi(value)));
}

template <typename D> hstring impl_ITextElement<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITextElement)->get_Language(put_abi(value)));
    return value;
}

template <typename D> void impl_ITextElement<D>::Language(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ITextElement)->put_Language(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Documents::TextPointer impl_ITextElement<D>::ContentStart() const
{
    Windows::UI::Xaml::Documents::TextPointer value { nullptr };
    check_hresult(WINRT_SHIM(ITextElement)->get_ContentStart(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Documents::TextPointer impl_ITextElement<D>::ContentEnd() const
{
    Windows::UI::Xaml::Documents::TextPointer value { nullptr };
    check_hresult(WINRT_SHIM(ITextElement)->get_ContentEnd(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Documents::TextPointer impl_ITextElement<D>::ElementStart() const
{
    Windows::UI::Xaml::Documents::TextPointer value { nullptr };
    check_hresult(WINRT_SHIM(ITextElement)->get_ElementStart(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Documents::TextPointer impl_ITextElement<D>::ElementEnd() const
{
    Windows::UI::Xaml::Documents::TextPointer value { nullptr };
    check_hresult(WINRT_SHIM(ITextElement)->get_ElementEnd(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_ITextElement<D>::FindName(hstring_view name) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(ITextElement)->abi_FindName(get_abi(name), put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_ITextElementOverrides<D>::OnDisconnectVisualChildren() const
{
    check_hresult(WINRT_SHIM(ITextElementOverrides)->abi_OnDisconnectVisualChildren());
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITextElementStatics<D>::FontSizeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITextElementStatics)->get_FontSizeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITextElementStatics<D>::FontFamilyProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITextElementStatics)->get_FontFamilyProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITextElementStatics<D>::FontWeightProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITextElementStatics)->get_FontWeightProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITextElementStatics<D>::FontStyleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITextElementStatics)->get_FontStyleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITextElementStatics<D>::FontStretchProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITextElementStatics)->get_FontStretchProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITextElementStatics<D>::CharacterSpacingProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITextElementStatics)->get_CharacterSpacingProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITextElementStatics<D>::ForegroundProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITextElementStatics)->get_ForegroundProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITextElementStatics<D>::LanguageProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITextElementStatics)->get_LanguageProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITextElement2<D>::IsTextScaleFactorEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITextElement2)->get_IsTextScaleFactorEnabled(&value));
    return value;
}

template <typename D> void impl_ITextElement2<D>::IsTextScaleFactorEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ITextElement2)->put_IsTextScaleFactorEnabled(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITextElementStatics2<D>::IsTextScaleFactorEnabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITextElementStatics2)->get_IsTextScaleFactorEnabledProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITextElement3<D>::AllowFocusOnInteraction() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITextElement3)->get_AllowFocusOnInteraction(&value));
    return value;
}

template <typename D> void impl_ITextElement3<D>::AllowFocusOnInteraction(bool value) const
{
    check_hresult(WINRT_SHIM(ITextElement3)->put_AllowFocusOnInteraction(value));
}

template <typename D> hstring impl_ITextElement3<D>::AccessKey() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITextElement3)->get_AccessKey(put_abi(value)));
    return value;
}

template <typename D> void impl_ITextElement3<D>::AccessKey(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ITextElement3)->put_AccessKey(get_abi(value)));
}

template <typename D> bool impl_ITextElement3<D>::ExitDisplayModeOnAccessKeyInvoked() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITextElement3)->get_ExitDisplayModeOnAccessKeyInvoked(&value));
    return value;
}

template <typename D> void impl_ITextElement3<D>::ExitDisplayModeOnAccessKeyInvoked(bool value) const
{
    check_hresult(WINRT_SHIM(ITextElement3)->put_ExitDisplayModeOnAccessKeyInvoked(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITextElementStatics3<D>::AllowFocusOnInteractionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITextElementStatics3)->get_AllowFocusOnInteractionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITextElementStatics3<D>::AccessKeyProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITextElementStatics3)->get_AccessKeyProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ITextElementStatics3<D>::ExitDisplayModeOnAccessKeyInvokedProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ITextElementStatics3)->get_ExitDisplayModeOnAccessKeyInvokedProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::TextAlignment impl_IBlock<D>::TextAlignment() const
{
    Windows::UI::Xaml::TextAlignment value {};
    check_hresult(WINRT_SHIM(IBlock)->get_TextAlignment(&value));
    return value;
}

template <typename D> void impl_IBlock<D>::TextAlignment(Windows::UI::Xaml::TextAlignment value) const
{
    check_hresult(WINRT_SHIM(IBlock)->put_TextAlignment(value));
}

template <typename D> double impl_IBlock<D>::LineHeight() const
{
    double value {};
    check_hresult(WINRT_SHIM(IBlock)->get_LineHeight(&value));
    return value;
}

template <typename D> void impl_IBlock<D>::LineHeight(double value) const
{
    check_hresult(WINRT_SHIM(IBlock)->put_LineHeight(value));
}

template <typename D> Windows::UI::Xaml::LineStackingStrategy impl_IBlock<D>::LineStackingStrategy() const
{
    Windows::UI::Xaml::LineStackingStrategy value {};
    check_hresult(WINRT_SHIM(IBlock)->get_LineStackingStrategy(&value));
    return value;
}

template <typename D> void impl_IBlock<D>::LineStackingStrategy(Windows::UI::Xaml::LineStackingStrategy value) const
{
    check_hresult(WINRT_SHIM(IBlock)->put_LineStackingStrategy(value));
}

template <typename D> Windows::UI::Xaml::Thickness impl_IBlock<D>::Margin() const
{
    Windows::UI::Xaml::Thickness value {};
    check_hresult(WINRT_SHIM(IBlock)->get_Margin(put_abi(value)));
    return value;
}

template <typename D> void impl_IBlock<D>::Margin(const Windows::UI::Xaml::Thickness & value) const
{
    check_hresult(WINRT_SHIM(IBlock)->put_Margin(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBlockStatics<D>::TextAlignmentProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBlockStatics)->get_TextAlignmentProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBlockStatics<D>::LineHeightProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBlockStatics)->get_LineHeightProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBlockStatics<D>::LineStackingStrategyProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBlockStatics)->get_LineStackingStrategyProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBlockStatics<D>::MarginProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBlockStatics)->get_MarginProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Documents::Block impl_IBlockFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Documents::Block instance { nullptr };
    check_hresult(WINRT_SHIM(IBlockFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Documents::Inline impl_IInlineFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Documents::Inline instance { nullptr };
    check_hresult(WINRT_SHIM(IInlineFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::UIElement impl_IInlineUIContainer<D>::Child() const
{
    Windows::UI::Xaml::UIElement value { nullptr };
    check_hresult(WINRT_SHIM(IInlineUIContainer)->get_Child(put_abi(value)));
    return value;
}

template <typename D> void impl_IInlineUIContainer<D>::Child(const Windows::UI::Xaml::UIElement & value) const
{
    check_hresult(WINRT_SHIM(IInlineUIContainer)->put_Child(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Documents::InlineCollection impl_IParagraph<D>::Inlines() const
{
    Windows::UI::Xaml::Documents::InlineCollection value { nullptr };
    check_hresult(WINRT_SHIM(IParagraph)->get_Inlines(put_abi(value)));
    return value;
}

template <typename D> double impl_IParagraph<D>::TextIndent() const
{
    double value {};
    check_hresult(WINRT_SHIM(IParagraph)->get_TextIndent(&value));
    return value;
}

template <typename D> void impl_IParagraph<D>::TextIndent(double value) const
{
    check_hresult(WINRT_SHIM(IParagraph)->put_TextIndent(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IParagraphStatics<D>::TextIndentProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IParagraphStatics)->get_TextIndentProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRun<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRun)->get_Text(put_abi(value)));
    return value;
}

template <typename D> void impl_IRun<D>::Text(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IRun)->put_Text(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::FlowDirection impl_IRun<D>::FlowDirection() const
{
    Windows::UI::Xaml::FlowDirection value {};
    check_hresult(WINRT_SHIM(IRun)->get_FlowDirection(&value));
    return value;
}

template <typename D> void impl_IRun<D>::FlowDirection(Windows::UI::Xaml::FlowDirection value) const
{
    check_hresult(WINRT_SHIM(IRun)->put_FlowDirection(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IRunStatics<D>::FlowDirectionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IRunStatics)->get_FlowDirectionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Documents::InlineCollection impl_ISpan<D>::Inlines() const
{
    Windows::UI::Xaml::Documents::InlineCollection value { nullptr };
    check_hresult(WINRT_SHIM(ISpan)->get_Inlines(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpan<D>::Inlines(const Windows::UI::Xaml::Documents::InlineCollection & value) const
{
    check_hresult(WINRT_SHIM(ISpan)->put_Inlines(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Documents::Span impl_ISpanFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Documents::Span instance { nullptr };
    check_hresult(WINRT_SHIM(ISpanFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> hstring impl_IGlyphs<D>::UnicodeString() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGlyphs)->get_UnicodeString(put_abi(value)));
    return value;
}

template <typename D> void impl_IGlyphs<D>::UnicodeString(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IGlyphs)->put_UnicodeString(get_abi(value)));
}

template <typename D> hstring impl_IGlyphs<D>::Indices() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGlyphs)->get_Indices(put_abi(value)));
    return value;
}

template <typename D> void impl_IGlyphs<D>::Indices(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IGlyphs)->put_Indices(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_IGlyphs<D>::FontUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IGlyphs)->get_FontUri(put_abi(value)));
    return value;
}

template <typename D> void impl_IGlyphs<D>::FontUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IGlyphs)->put_FontUri(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::StyleSimulations impl_IGlyphs<D>::StyleSimulations() const
{
    Windows::UI::Xaml::Media::StyleSimulations value {};
    check_hresult(WINRT_SHIM(IGlyphs)->get_StyleSimulations(&value));
    return value;
}

template <typename D> void impl_IGlyphs<D>::StyleSimulations(Windows::UI::Xaml::Media::StyleSimulations value) const
{
    check_hresult(WINRT_SHIM(IGlyphs)->put_StyleSimulations(value));
}

template <typename D> double impl_IGlyphs<D>::FontRenderingEmSize() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGlyphs)->get_FontRenderingEmSize(&value));
    return value;
}

template <typename D> void impl_IGlyphs<D>::FontRenderingEmSize(double value) const
{
    check_hresult(WINRT_SHIM(IGlyphs)->put_FontRenderingEmSize(value));
}

template <typename D> double impl_IGlyphs<D>::OriginX() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGlyphs)->get_OriginX(&value));
    return value;
}

template <typename D> void impl_IGlyphs<D>::OriginX(double value) const
{
    check_hresult(WINRT_SHIM(IGlyphs)->put_OriginX(value));
}

template <typename D> double impl_IGlyphs<D>::OriginY() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGlyphs)->get_OriginY(&value));
    return value;
}

template <typename D> void impl_IGlyphs<D>::OriginY(double value) const
{
    check_hresult(WINRT_SHIM(IGlyphs)->put_OriginY(value));
}

template <typename D> Windows::UI::Xaml::Media::Brush impl_IGlyphs<D>::Fill() const
{
    Windows::UI::Xaml::Media::Brush value { nullptr };
    check_hresult(WINRT_SHIM(IGlyphs)->get_Fill(put_abi(value)));
    return value;
}

template <typename D> void impl_IGlyphs<D>::Fill(const Windows::UI::Xaml::Media::Brush & value) const
{
    check_hresult(WINRT_SHIM(IGlyphs)->put_Fill(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGlyphsStatics<D>::UnicodeStringProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGlyphsStatics)->get_UnicodeStringProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGlyphsStatics<D>::IndicesProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGlyphsStatics)->get_IndicesProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGlyphsStatics<D>::FontUriProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGlyphsStatics)->get_FontUriProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGlyphsStatics<D>::StyleSimulationsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGlyphsStatics)->get_StyleSimulationsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGlyphsStatics<D>::FontRenderingEmSizeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGlyphsStatics)->get_FontRenderingEmSizeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGlyphsStatics<D>::OriginXProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGlyphsStatics)->get_OriginXProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGlyphsStatics<D>::OriginYProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGlyphsStatics)->get_OriginYProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGlyphsStatics<D>::FillProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGlyphsStatics)->get_FillProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_IGlyphs2<D>::IsColorFontEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGlyphs2)->get_IsColorFontEnabled(&value));
    return value;
}

template <typename D> void impl_IGlyphs2<D>::IsColorFontEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IGlyphs2)->put_IsColorFontEnabled(value));
}

template <typename D> int32_t impl_IGlyphs2<D>::ColorFontPaletteIndex() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGlyphs2)->get_ColorFontPaletteIndex(&value));
    return value;
}

template <typename D> void impl_IGlyphs2<D>::ColorFontPaletteIndex(int32_t value) const
{
    check_hresult(WINRT_SHIM(IGlyphs2)->put_ColorFontPaletteIndex(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGlyphsStatics2<D>::IsColorFontEnabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGlyphsStatics2)->get_IsColorFontEnabledProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IGlyphsStatics2<D>::ColorFontPaletteIndexProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IGlyphsStatics2)->get_ColorFontPaletteIndexProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IHyperlink<D>::NavigateUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IHyperlink)->get_NavigateUri(put_abi(value)));
    return value;
}

template <typename D> void impl_IHyperlink<D>::NavigateUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IHyperlink)->put_NavigateUri(get_abi(value)));
}

template <typename D> event_token impl_IHyperlink<D>::Click(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Documents::Hyperlink, Windows::UI::Xaml::Documents::HyperlinkClickEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IHyperlink)->add_Click(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IHyperlink> impl_IHyperlink<D>::Click(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Documents::Hyperlink, Windows::UI::Xaml::Documents::HyperlinkClickEventArgs> & value) const
{
    return impl::make_event_revoker<D, IHyperlink>(this, &ABI::Windows::UI::Xaml::Documents::IHyperlink::remove_Click, Click(value));
}

template <typename D> void impl_IHyperlink<D>::Click(event_token token) const
{
    check_hresult(WINRT_SHIM(IHyperlink)->remove_Click(token));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IHyperlinkStatics<D>::NavigateUriProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IHyperlinkStatics)->get_NavigateUriProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Documents::UnderlineStyle impl_IHyperlink2<D>::UnderlineStyle() const
{
    Windows::UI::Xaml::Documents::UnderlineStyle value {};
    check_hresult(WINRT_SHIM(IHyperlink2)->get_UnderlineStyle(&value));
    return value;
}

template <typename D> void impl_IHyperlink2<D>::UnderlineStyle(Windows::UI::Xaml::Documents::UnderlineStyle value) const
{
    check_hresult(WINRT_SHIM(IHyperlink2)->put_UnderlineStyle(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IHyperlinkStatics2<D>::UnderlineStyleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IHyperlinkStatics2)->get_UnderlineStyleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_IHyperlink3<D>::XYFocusLeft() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(IHyperlink3)->get_XYFocusLeft(put_abi(value)));
    return value;
}

template <typename D> void impl_IHyperlink3<D>::XYFocusLeft(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(IHyperlink3)->put_XYFocusLeft(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_IHyperlink3<D>::XYFocusRight() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(IHyperlink3)->get_XYFocusRight(put_abi(value)));
    return value;
}

template <typename D> void impl_IHyperlink3<D>::XYFocusRight(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(IHyperlink3)->put_XYFocusRight(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_IHyperlink3<D>::XYFocusUp() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(IHyperlink3)->get_XYFocusUp(put_abi(value)));
    return value;
}

template <typename D> void impl_IHyperlink3<D>::XYFocusUp(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(IHyperlink3)->put_XYFocusUp(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_IHyperlink3<D>::XYFocusDown() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(IHyperlink3)->get_XYFocusDown(put_abi(value)));
    return value;
}

template <typename D> void impl_IHyperlink3<D>::XYFocusDown(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(IHyperlink3)->put_XYFocusDown(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::ElementSoundMode impl_IHyperlink3<D>::ElementSoundMode() const
{
    Windows::UI::Xaml::ElementSoundMode value {};
    check_hresult(WINRT_SHIM(IHyperlink3)->get_ElementSoundMode(&value));
    return value;
}

template <typename D> void impl_IHyperlink3<D>::ElementSoundMode(Windows::UI::Xaml::ElementSoundMode value) const
{
    check_hresult(WINRT_SHIM(IHyperlink3)->put_ElementSoundMode(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IHyperlinkStatics3<D>::XYFocusLeftProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IHyperlinkStatics3)->get_XYFocusLeftProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IHyperlinkStatics3<D>::XYFocusRightProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IHyperlinkStatics3)->get_XYFocusRightProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IHyperlinkStatics3<D>::XYFocusUpProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IHyperlinkStatics3)->get_XYFocusUpProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IHyperlinkStatics3<D>::XYFocusDownProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IHyperlinkStatics3)->get_XYFocusDownProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IHyperlinkStatics3<D>::ElementSoundModeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IHyperlinkStatics3)->get_ElementSoundModeProperty(put_abi(value)));
    return value;
}

inline Windows::UI::Xaml::DependencyProperty Block::TextAlignmentProperty()
{
    return get_activation_factory<Block, IBlockStatics>().TextAlignmentProperty();
}

inline Windows::UI::Xaml::DependencyProperty Block::LineHeightProperty()
{
    return get_activation_factory<Block, IBlockStatics>().LineHeightProperty();
}

inline Windows::UI::Xaml::DependencyProperty Block::LineStackingStrategyProperty()
{
    return get_activation_factory<Block, IBlockStatics>().LineStackingStrategyProperty();
}

inline Windows::UI::Xaml::DependencyProperty Block::MarginProperty()
{
    return get_activation_factory<Block, IBlockStatics>().MarginProperty();
}

inline Bold::Bold() :
    Bold(activate_instance<Bold>())
{}

inline Glyphs::Glyphs() :
    Glyphs(activate_instance<Glyphs>())
{}

inline Windows::UI::Xaml::DependencyProperty Glyphs::UnicodeStringProperty()
{
    return get_activation_factory<Glyphs, IGlyphsStatics>().UnicodeStringProperty();
}

inline Windows::UI::Xaml::DependencyProperty Glyphs::IndicesProperty()
{
    return get_activation_factory<Glyphs, IGlyphsStatics>().IndicesProperty();
}

inline Windows::UI::Xaml::DependencyProperty Glyphs::FontUriProperty()
{
    return get_activation_factory<Glyphs, IGlyphsStatics>().FontUriProperty();
}

inline Windows::UI::Xaml::DependencyProperty Glyphs::StyleSimulationsProperty()
{
    return get_activation_factory<Glyphs, IGlyphsStatics>().StyleSimulationsProperty();
}

inline Windows::UI::Xaml::DependencyProperty Glyphs::FontRenderingEmSizeProperty()
{
    return get_activation_factory<Glyphs, IGlyphsStatics>().FontRenderingEmSizeProperty();
}

inline Windows::UI::Xaml::DependencyProperty Glyphs::OriginXProperty()
{
    return get_activation_factory<Glyphs, IGlyphsStatics>().OriginXProperty();
}

inline Windows::UI::Xaml::DependencyProperty Glyphs::OriginYProperty()
{
    return get_activation_factory<Glyphs, IGlyphsStatics>().OriginYProperty();
}

inline Windows::UI::Xaml::DependencyProperty Glyphs::FillProperty()
{
    return get_activation_factory<Glyphs, IGlyphsStatics>().FillProperty();
}

inline Windows::UI::Xaml::DependencyProperty Glyphs::IsColorFontEnabledProperty()
{
    return get_activation_factory<Glyphs, IGlyphsStatics2>().IsColorFontEnabledProperty();
}

inline Windows::UI::Xaml::DependencyProperty Glyphs::ColorFontPaletteIndexProperty()
{
    return get_activation_factory<Glyphs, IGlyphsStatics2>().ColorFontPaletteIndexProperty();
}

inline Hyperlink::Hyperlink() :
    Hyperlink(activate_instance<Hyperlink>())
{}

inline Windows::UI::Xaml::DependencyProperty Hyperlink::NavigateUriProperty()
{
    return get_activation_factory<Hyperlink, IHyperlinkStatics>().NavigateUriProperty();
}

inline Windows::UI::Xaml::DependencyProperty Hyperlink::UnderlineStyleProperty()
{
    return get_activation_factory<Hyperlink, IHyperlinkStatics2>().UnderlineStyleProperty();
}

inline Windows::UI::Xaml::DependencyProperty Hyperlink::XYFocusLeftProperty()
{
    return get_activation_factory<Hyperlink, IHyperlinkStatics3>().XYFocusLeftProperty();
}

inline Windows::UI::Xaml::DependencyProperty Hyperlink::XYFocusRightProperty()
{
    return get_activation_factory<Hyperlink, IHyperlinkStatics3>().XYFocusRightProperty();
}

inline Windows::UI::Xaml::DependencyProperty Hyperlink::XYFocusUpProperty()
{
    return get_activation_factory<Hyperlink, IHyperlinkStatics3>().XYFocusUpProperty();
}

inline Windows::UI::Xaml::DependencyProperty Hyperlink::XYFocusDownProperty()
{
    return get_activation_factory<Hyperlink, IHyperlinkStatics3>().XYFocusDownProperty();
}

inline Windows::UI::Xaml::DependencyProperty Hyperlink::ElementSoundModeProperty()
{
    return get_activation_factory<Hyperlink, IHyperlinkStatics3>().ElementSoundModeProperty();
}

inline InlineUIContainer::InlineUIContainer() :
    InlineUIContainer(activate_instance<InlineUIContainer>())
{}

inline Italic::Italic() :
    Italic(activate_instance<Italic>())
{}

inline LineBreak::LineBreak() :
    LineBreak(activate_instance<LineBreak>())
{}

inline Paragraph::Paragraph() :
    Paragraph(activate_instance<Paragraph>())
{}

inline Windows::UI::Xaml::DependencyProperty Paragraph::TextIndentProperty()
{
    return get_activation_factory<Paragraph, IParagraphStatics>().TextIndentProperty();
}

inline Run::Run() :
    Run(activate_instance<Run>())
{}

inline Windows::UI::Xaml::DependencyProperty Run::FlowDirectionProperty()
{
    return get_activation_factory<Run, IRunStatics>().FlowDirectionProperty();
}

inline Span::Span()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<Span, ISpanFactory>().CreateInstance(outer, inner));
}

inline Windows::UI::Xaml::DependencyProperty TextElement::FontSizeProperty()
{
    return get_activation_factory<TextElement, ITextElementStatics>().FontSizeProperty();
}

inline Windows::UI::Xaml::DependencyProperty TextElement::FontFamilyProperty()
{
    return get_activation_factory<TextElement, ITextElementStatics>().FontFamilyProperty();
}

inline Windows::UI::Xaml::DependencyProperty TextElement::FontWeightProperty()
{
    return get_activation_factory<TextElement, ITextElementStatics>().FontWeightProperty();
}

inline Windows::UI::Xaml::DependencyProperty TextElement::FontStyleProperty()
{
    return get_activation_factory<TextElement, ITextElementStatics>().FontStyleProperty();
}

inline Windows::UI::Xaml::DependencyProperty TextElement::FontStretchProperty()
{
    return get_activation_factory<TextElement, ITextElementStatics>().FontStretchProperty();
}

inline Windows::UI::Xaml::DependencyProperty TextElement::CharacterSpacingProperty()
{
    return get_activation_factory<TextElement, ITextElementStatics>().CharacterSpacingProperty();
}

inline Windows::UI::Xaml::DependencyProperty TextElement::ForegroundProperty()
{
    return get_activation_factory<TextElement, ITextElementStatics>().ForegroundProperty();
}

inline Windows::UI::Xaml::DependencyProperty TextElement::LanguageProperty()
{
    return get_activation_factory<TextElement, ITextElementStatics>().LanguageProperty();
}

inline Windows::UI::Xaml::DependencyProperty TextElement::IsTextScaleFactorEnabledProperty()
{
    return get_activation_factory<TextElement, ITextElementStatics2>().IsTextScaleFactorEnabledProperty();
}

inline Windows::UI::Xaml::DependencyProperty TextElement::AllowFocusOnInteractionProperty()
{
    return get_activation_factory<TextElement, ITextElementStatics3>().AllowFocusOnInteractionProperty();
}

inline Windows::UI::Xaml::DependencyProperty TextElement::AccessKeyProperty()
{
    return get_activation_factory<TextElement, ITextElementStatics3>().AccessKeyProperty();
}

inline Windows::UI::Xaml::DependencyProperty TextElement::ExitDisplayModeOnAccessKeyInvokedProperty()
{
    return get_activation_factory<TextElement, ITextElementStatics3>().ExitDisplayModeOnAccessKeyInvokedProperty();
}

inline Windows::UI::Xaml::DependencyProperty Typography::AnnotationAlternatesProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().AnnotationAlternatesProperty();
}

inline int32_t Typography::GetAnnotationAlternates(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetAnnotationAlternates(element);
}

inline void Typography::SetAnnotationAlternates(const Windows::UI::Xaml::DependencyObject & element, int32_t value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetAnnotationAlternates(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::EastAsianExpertFormsProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().EastAsianExpertFormsProperty();
}

inline bool Typography::GetEastAsianExpertForms(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetEastAsianExpertForms(element);
}

inline void Typography::SetEastAsianExpertForms(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetEastAsianExpertForms(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::EastAsianLanguageProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().EastAsianLanguageProperty();
}

inline Windows::UI::Xaml::FontEastAsianLanguage Typography::GetEastAsianLanguage(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetEastAsianLanguage(element);
}

inline void Typography::SetEastAsianLanguage(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontEastAsianLanguage value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetEastAsianLanguage(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::EastAsianWidthsProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().EastAsianWidthsProperty();
}

inline Windows::UI::Xaml::FontEastAsianWidths Typography::GetEastAsianWidths(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetEastAsianWidths(element);
}

inline void Typography::SetEastAsianWidths(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontEastAsianWidths value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetEastAsianWidths(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StandardLigaturesProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().StandardLigaturesProperty();
}

inline bool Typography::GetStandardLigatures(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStandardLigatures(element);
}

inline void Typography::SetStandardLigatures(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStandardLigatures(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::ContextualLigaturesProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().ContextualLigaturesProperty();
}

inline bool Typography::GetContextualLigatures(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetContextualLigatures(element);
}

inline void Typography::SetContextualLigatures(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetContextualLigatures(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::DiscretionaryLigaturesProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().DiscretionaryLigaturesProperty();
}

inline bool Typography::GetDiscretionaryLigatures(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetDiscretionaryLigatures(element);
}

inline void Typography::SetDiscretionaryLigatures(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetDiscretionaryLigatures(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::HistoricalLigaturesProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().HistoricalLigaturesProperty();
}

inline bool Typography::GetHistoricalLigatures(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetHistoricalLigatures(element);
}

inline void Typography::SetHistoricalLigatures(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetHistoricalLigatures(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StandardSwashesProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().StandardSwashesProperty();
}

inline int32_t Typography::GetStandardSwashes(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStandardSwashes(element);
}

inline void Typography::SetStandardSwashes(const Windows::UI::Xaml::DependencyObject & element, int32_t value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStandardSwashes(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::ContextualSwashesProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().ContextualSwashesProperty();
}

inline int32_t Typography::GetContextualSwashes(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetContextualSwashes(element);
}

inline void Typography::SetContextualSwashes(const Windows::UI::Xaml::DependencyObject & element, int32_t value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetContextualSwashes(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::ContextualAlternatesProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().ContextualAlternatesProperty();
}

inline bool Typography::GetContextualAlternates(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetContextualAlternates(element);
}

inline void Typography::SetContextualAlternates(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetContextualAlternates(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticAlternatesProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticAlternatesProperty();
}

inline int32_t Typography::GetStylisticAlternates(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticAlternates(element);
}

inline void Typography::SetStylisticAlternates(const Windows::UI::Xaml::DependencyObject & element, int32_t value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticAlternates(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet1Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet1Property();
}

inline bool Typography::GetStylisticSet1(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet1(element);
}

inline void Typography::SetStylisticSet1(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet1(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet2Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet2Property();
}

inline bool Typography::GetStylisticSet2(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet2(element);
}

inline void Typography::SetStylisticSet2(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet2(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet3Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet3Property();
}

inline bool Typography::GetStylisticSet3(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet3(element);
}

inline void Typography::SetStylisticSet3(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet3(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet4Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet4Property();
}

inline bool Typography::GetStylisticSet4(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet4(element);
}

inline void Typography::SetStylisticSet4(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet4(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet5Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet5Property();
}

inline bool Typography::GetStylisticSet5(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet5(element);
}

inline void Typography::SetStylisticSet5(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet5(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet6Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet6Property();
}

inline bool Typography::GetStylisticSet6(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet6(element);
}

inline void Typography::SetStylisticSet6(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet6(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet7Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet7Property();
}

inline bool Typography::GetStylisticSet7(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet7(element);
}

inline void Typography::SetStylisticSet7(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet7(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet8Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet8Property();
}

inline bool Typography::GetStylisticSet8(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet8(element);
}

inline void Typography::SetStylisticSet8(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet8(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet9Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet9Property();
}

inline bool Typography::GetStylisticSet9(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet9(element);
}

inline void Typography::SetStylisticSet9(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet9(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet10Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet10Property();
}

inline bool Typography::GetStylisticSet10(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet10(element);
}

inline void Typography::SetStylisticSet10(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet10(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet11Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet11Property();
}

inline bool Typography::GetStylisticSet11(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet11(element);
}

inline void Typography::SetStylisticSet11(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet11(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet12Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet12Property();
}

inline bool Typography::GetStylisticSet12(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet12(element);
}

inline void Typography::SetStylisticSet12(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet12(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet13Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet13Property();
}

inline bool Typography::GetStylisticSet13(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet13(element);
}

inline void Typography::SetStylisticSet13(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet13(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet14Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet14Property();
}

inline bool Typography::GetStylisticSet14(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet14(element);
}

inline void Typography::SetStylisticSet14(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet14(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet15Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet15Property();
}

inline bool Typography::GetStylisticSet15(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet15(element);
}

inline void Typography::SetStylisticSet15(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet15(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet16Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet16Property();
}

inline bool Typography::GetStylisticSet16(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet16(element);
}

inline void Typography::SetStylisticSet16(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet16(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet17Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet17Property();
}

inline bool Typography::GetStylisticSet17(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet17(element);
}

inline void Typography::SetStylisticSet17(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet17(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet18Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet18Property();
}

inline bool Typography::GetStylisticSet18(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet18(element);
}

inline void Typography::SetStylisticSet18(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet18(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet19Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet19Property();
}

inline bool Typography::GetStylisticSet19(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet19(element);
}

inline void Typography::SetStylisticSet19(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet19(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::StylisticSet20Property()
{
    return get_activation_factory<Typography, ITypographyStatics>().StylisticSet20Property();
}

inline bool Typography::GetStylisticSet20(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetStylisticSet20(element);
}

inline void Typography::SetStylisticSet20(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetStylisticSet20(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::CapitalsProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().CapitalsProperty();
}

inline Windows::UI::Xaml::FontCapitals Typography::GetCapitals(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetCapitals(element);
}

inline void Typography::SetCapitals(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontCapitals value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetCapitals(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::CapitalSpacingProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().CapitalSpacingProperty();
}

inline bool Typography::GetCapitalSpacing(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetCapitalSpacing(element);
}

inline void Typography::SetCapitalSpacing(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetCapitalSpacing(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::KerningProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().KerningProperty();
}

inline bool Typography::GetKerning(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetKerning(element);
}

inline void Typography::SetKerning(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetKerning(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::CaseSensitiveFormsProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().CaseSensitiveFormsProperty();
}

inline bool Typography::GetCaseSensitiveForms(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetCaseSensitiveForms(element);
}

inline void Typography::SetCaseSensitiveForms(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetCaseSensitiveForms(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::HistoricalFormsProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().HistoricalFormsProperty();
}

inline bool Typography::GetHistoricalForms(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetHistoricalForms(element);
}

inline void Typography::SetHistoricalForms(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetHistoricalForms(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::FractionProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().FractionProperty();
}

inline Windows::UI::Xaml::FontFraction Typography::GetFraction(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetFraction(element);
}

inline void Typography::SetFraction(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontFraction value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetFraction(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::NumeralStyleProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().NumeralStyleProperty();
}

inline Windows::UI::Xaml::FontNumeralStyle Typography::GetNumeralStyle(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetNumeralStyle(element);
}

inline void Typography::SetNumeralStyle(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontNumeralStyle value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetNumeralStyle(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::NumeralAlignmentProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().NumeralAlignmentProperty();
}

inline Windows::UI::Xaml::FontNumeralAlignment Typography::GetNumeralAlignment(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetNumeralAlignment(element);
}

inline void Typography::SetNumeralAlignment(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontNumeralAlignment value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetNumeralAlignment(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::SlashedZeroProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().SlashedZeroProperty();
}

inline bool Typography::GetSlashedZero(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetSlashedZero(element);
}

inline void Typography::SetSlashedZero(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetSlashedZero(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::MathematicalGreekProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().MathematicalGreekProperty();
}

inline bool Typography::GetMathematicalGreek(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetMathematicalGreek(element);
}

inline void Typography::SetMathematicalGreek(const Windows::UI::Xaml::DependencyObject & element, bool value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetMathematicalGreek(element, value);
}

inline Windows::UI::Xaml::DependencyProperty Typography::VariantsProperty()
{
    return get_activation_factory<Typography, ITypographyStatics>().VariantsProperty();
}

inline Windows::UI::Xaml::FontVariants Typography::GetVariants(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<Typography, ITypographyStatics>().GetVariants(element);
}

inline void Typography::SetVariants(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontVariants value)
{
    get_activation_factory<Typography, ITypographyStatics>().SetVariants(element, value);
}

inline Underline::Underline() :
    Underline(activate_instance<Underline>())
{}

}

}
#pragma warning(pop)
