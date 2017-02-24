// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.UI.Text.3.h"
#include "internal/Windows.Globalization.Fonts.3.h"
#include "Windows.Globalization.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Globalization::Fonts::ILanguageFont> : produce_base<D, Windows::Globalization::Fonts::ILanguageFont>
{
    HRESULT __stdcall get_FontFamily(impl::abi_arg_out<hstring> value) noexcept override
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

    HRESULT __stdcall get_FontWeight(impl::abi_arg_out<Windows::UI::Text::FontWeight> weight) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *weight = detach_abi(this->shim().FontWeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontStretch(Windows::UI::Text::FontStretch * stretch) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *stretch = detach_abi(this->shim().FontStretch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontStyle(Windows::UI::Text::FontStyle * style) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *style = detach_abi(this->shim().FontStyle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScaleFactor(double * scale) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *scale = detach_abi(this->shim().ScaleFactor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::Fonts::ILanguageFontGroup> : produce_base<D, Windows::Globalization::Fonts::ILanguageFontGroup>
{
    HRESULT __stdcall get_UITextFont(impl::abi_arg_out<Windows::Globalization::Fonts::ILanguageFont> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UITextFont());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UIHeadingFont(impl::abi_arg_out<Windows::Globalization::Fonts::ILanguageFont> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UIHeadingFont());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UITitleFont(impl::abi_arg_out<Windows::Globalization::Fonts::ILanguageFont> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UITitleFont());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UICaptionFont(impl::abi_arg_out<Windows::Globalization::Fonts::ILanguageFont> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UICaptionFont());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UINotificationHeadingFont(impl::abi_arg_out<Windows::Globalization::Fonts::ILanguageFont> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UINotificationHeadingFont());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TraditionalDocumentFont(impl::abi_arg_out<Windows::Globalization::Fonts::ILanguageFont> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TraditionalDocumentFont());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ModernDocumentFont(impl::abi_arg_out<Windows::Globalization::Fonts::ILanguageFont> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ModernDocumentFont());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DocumentHeadingFont(impl::abi_arg_out<Windows::Globalization::Fonts::ILanguageFont> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DocumentHeadingFont());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FixedWidthTextFont(impl::abi_arg_out<Windows::Globalization::Fonts::ILanguageFont> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FixedWidthTextFont());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DocumentAlternate1Font(impl::abi_arg_out<Windows::Globalization::Fonts::ILanguageFont> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DocumentAlternate1Font());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DocumentAlternate2Font(impl::abi_arg_out<Windows::Globalization::Fonts::ILanguageFont> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DocumentAlternate2Font());
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
struct produce<D, Windows::Globalization::Fonts::ILanguageFontGroupFactory> : produce_base<D, Windows::Globalization::Fonts::ILanguageFontGroupFactory>
{
    HRESULT __stdcall abi_CreateLanguageFontGroup(impl::abi_arg_in<hstring> languageTag, impl::abi_arg_out<Windows::Globalization::Fonts::ILanguageFontGroup> recommendedFonts) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *recommendedFonts = detach_abi(this->shim().CreateLanguageFontGroup(*reinterpret_cast<const hstring *>(&languageTag)));
            return S_OK;
        }
        catch (...)
        {
            *recommendedFonts = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Globalization::Fonts {

template <typename D> Windows::Globalization::Fonts::LanguageFont impl_ILanguageFontGroup<D>::UITextFont() const
{
    Windows::Globalization::Fonts::LanguageFont value { nullptr };
    check_hresult(WINRT_SHIM(ILanguageFontGroup)->get_UITextFont(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::Fonts::LanguageFont impl_ILanguageFontGroup<D>::UIHeadingFont() const
{
    Windows::Globalization::Fonts::LanguageFont value { nullptr };
    check_hresult(WINRT_SHIM(ILanguageFontGroup)->get_UIHeadingFont(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::Fonts::LanguageFont impl_ILanguageFontGroup<D>::UITitleFont() const
{
    Windows::Globalization::Fonts::LanguageFont value { nullptr };
    check_hresult(WINRT_SHIM(ILanguageFontGroup)->get_UITitleFont(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::Fonts::LanguageFont impl_ILanguageFontGroup<D>::UICaptionFont() const
{
    Windows::Globalization::Fonts::LanguageFont value { nullptr };
    check_hresult(WINRT_SHIM(ILanguageFontGroup)->get_UICaptionFont(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::Fonts::LanguageFont impl_ILanguageFontGroup<D>::UINotificationHeadingFont() const
{
    Windows::Globalization::Fonts::LanguageFont value { nullptr };
    check_hresult(WINRT_SHIM(ILanguageFontGroup)->get_UINotificationHeadingFont(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::Fonts::LanguageFont impl_ILanguageFontGroup<D>::TraditionalDocumentFont() const
{
    Windows::Globalization::Fonts::LanguageFont value { nullptr };
    check_hresult(WINRT_SHIM(ILanguageFontGroup)->get_TraditionalDocumentFont(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::Fonts::LanguageFont impl_ILanguageFontGroup<D>::ModernDocumentFont() const
{
    Windows::Globalization::Fonts::LanguageFont value { nullptr };
    check_hresult(WINRT_SHIM(ILanguageFontGroup)->get_ModernDocumentFont(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::Fonts::LanguageFont impl_ILanguageFontGroup<D>::DocumentHeadingFont() const
{
    Windows::Globalization::Fonts::LanguageFont value { nullptr };
    check_hresult(WINRT_SHIM(ILanguageFontGroup)->get_DocumentHeadingFont(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::Fonts::LanguageFont impl_ILanguageFontGroup<D>::FixedWidthTextFont() const
{
    Windows::Globalization::Fonts::LanguageFont value { nullptr };
    check_hresult(WINRT_SHIM(ILanguageFontGroup)->get_FixedWidthTextFont(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::Fonts::LanguageFont impl_ILanguageFontGroup<D>::DocumentAlternate1Font() const
{
    Windows::Globalization::Fonts::LanguageFont value { nullptr };
    check_hresult(WINRT_SHIM(ILanguageFontGroup)->get_DocumentAlternate1Font(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::Fonts::LanguageFont impl_ILanguageFontGroup<D>::DocumentAlternate2Font() const
{
    Windows::Globalization::Fonts::LanguageFont value { nullptr };
    check_hresult(WINRT_SHIM(ILanguageFontGroup)->get_DocumentAlternate2Font(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::Fonts::LanguageFontGroup impl_ILanguageFontGroupFactory<D>::CreateLanguageFontGroup(hstring_view languageTag) const
{
    Windows::Globalization::Fonts::LanguageFontGroup recommendedFonts { nullptr };
    check_hresult(WINRT_SHIM(ILanguageFontGroupFactory)->abi_CreateLanguageFontGroup(get_abi(languageTag), put_abi(recommendedFonts)));
    return recommendedFonts;
}

template <typename D> hstring impl_ILanguageFont<D>::FontFamily() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILanguageFont)->get_FontFamily(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Text::FontWeight impl_ILanguageFont<D>::FontWeight() const
{
    Windows::UI::Text::FontWeight weight {};
    check_hresult(WINRT_SHIM(ILanguageFont)->get_FontWeight(put_abi(weight)));
    return weight;
}

template <typename D> Windows::UI::Text::FontStretch impl_ILanguageFont<D>::FontStretch() const
{
    Windows::UI::Text::FontStretch stretch {};
    check_hresult(WINRT_SHIM(ILanguageFont)->get_FontStretch(&stretch));
    return stretch;
}

template <typename D> Windows::UI::Text::FontStyle impl_ILanguageFont<D>::FontStyle() const
{
    Windows::UI::Text::FontStyle style {};
    check_hresult(WINRT_SHIM(ILanguageFont)->get_FontStyle(&style));
    return style;
}

template <typename D> double impl_ILanguageFont<D>::ScaleFactor() const
{
    double scale {};
    check_hresult(WINRT_SHIM(ILanguageFont)->get_ScaleFactor(&scale));
    return scale;
}

inline LanguageFontGroup::LanguageFontGroup(hstring_view languageTag) :
    LanguageFontGroup(get_activation_factory<LanguageFontGroup, ILanguageFontGroupFactory>().CreateLanguageFontGroup(languageTag))
{}

}

}
#pragma warning(pop)
