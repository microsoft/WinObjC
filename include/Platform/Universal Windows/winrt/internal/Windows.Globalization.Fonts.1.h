// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Globalization.Fonts.0.h"
#include "Windows.UI.Text.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Globalization::Fonts {

struct __declspec(uuid("b12e5c3a-b76d-459b-beeb-901151cd77d1")) __declspec(novtable) ILanguageFont : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FontFamily(hstring * value) = 0;
    virtual HRESULT __stdcall get_FontWeight(Windows::UI::Text::FontWeight * weight) = 0;
    virtual HRESULT __stdcall get_FontStretch(winrt::Windows::UI::Text::FontStretch * stretch) = 0;
    virtual HRESULT __stdcall get_FontStyle(winrt::Windows::UI::Text::FontStyle * style) = 0;
    virtual HRESULT __stdcall get_ScaleFactor(double * scale) = 0;
};

struct __declspec(uuid("f33a7fc3-3a5c-4aea-b9ff-b39fb242f7f6")) __declspec(novtable) ILanguageFontGroup : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UITextFont(Windows::Globalization::Fonts::ILanguageFont ** value) = 0;
    virtual HRESULT __stdcall get_UIHeadingFont(Windows::Globalization::Fonts::ILanguageFont ** value) = 0;
    virtual HRESULT __stdcall get_UITitleFont(Windows::Globalization::Fonts::ILanguageFont ** value) = 0;
    virtual HRESULT __stdcall get_UICaptionFont(Windows::Globalization::Fonts::ILanguageFont ** value) = 0;
    virtual HRESULT __stdcall get_UINotificationHeadingFont(Windows::Globalization::Fonts::ILanguageFont ** value) = 0;
    virtual HRESULT __stdcall get_TraditionalDocumentFont(Windows::Globalization::Fonts::ILanguageFont ** value) = 0;
    virtual HRESULT __stdcall get_ModernDocumentFont(Windows::Globalization::Fonts::ILanguageFont ** value) = 0;
    virtual HRESULT __stdcall get_DocumentHeadingFont(Windows::Globalization::Fonts::ILanguageFont ** value) = 0;
    virtual HRESULT __stdcall get_FixedWidthTextFont(Windows::Globalization::Fonts::ILanguageFont ** value) = 0;
    virtual HRESULT __stdcall get_DocumentAlternate1Font(Windows::Globalization::Fonts::ILanguageFont ** value) = 0;
    virtual HRESULT __stdcall get_DocumentAlternate2Font(Windows::Globalization::Fonts::ILanguageFont ** value) = 0;
};

struct __declspec(uuid("fcaeac67-4e77-49c7-b856-dde934fc735b")) __declspec(novtable) ILanguageFontGroupFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateLanguageFontGroup(hstring languageTag, Windows::Globalization::Fonts::ILanguageFontGroup ** recommendedFonts) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Globalization::Fonts::LanguageFont> { using default_interface = Windows::Globalization::Fonts::ILanguageFont; };
template <> struct traits<Windows::Globalization::Fonts::LanguageFontGroup> { using default_interface = Windows::Globalization::Fonts::ILanguageFontGroup; };

}

namespace Windows::Globalization::Fonts {

template <typename D>
struct WINRT_EBO impl_ILanguageFont
{
    hstring FontFamily() const;
    Windows::UI::Text::FontWeight FontWeight() const;
    Windows::UI::Text::FontStretch FontStretch() const;
    Windows::UI::Text::FontStyle FontStyle() const;
    double ScaleFactor() const;
};

template <typename D>
struct WINRT_EBO impl_ILanguageFontGroup
{
    Windows::Globalization::Fonts::LanguageFont UITextFont() const;
    Windows::Globalization::Fonts::LanguageFont UIHeadingFont() const;
    Windows::Globalization::Fonts::LanguageFont UITitleFont() const;
    Windows::Globalization::Fonts::LanguageFont UICaptionFont() const;
    Windows::Globalization::Fonts::LanguageFont UINotificationHeadingFont() const;
    Windows::Globalization::Fonts::LanguageFont TraditionalDocumentFont() const;
    Windows::Globalization::Fonts::LanguageFont ModernDocumentFont() const;
    Windows::Globalization::Fonts::LanguageFont DocumentHeadingFont() const;
    Windows::Globalization::Fonts::LanguageFont FixedWidthTextFont() const;
    Windows::Globalization::Fonts::LanguageFont DocumentAlternate1Font() const;
    Windows::Globalization::Fonts::LanguageFont DocumentAlternate2Font() const;
};

template <typename D>
struct WINRT_EBO impl_ILanguageFontGroupFactory
{
    Windows::Globalization::Fonts::LanguageFontGroup CreateLanguageFontGroup(hstring_view languageTag) const;
};

}

namespace impl {

template <> struct traits<Windows::Globalization::Fonts::ILanguageFont>
{
    using abi = ABI::Windows::Globalization::Fonts::ILanguageFont;
    template <typename D> using consume = Windows::Globalization::Fonts::impl_ILanguageFont<D>;
};

template <> struct traits<Windows::Globalization::Fonts::ILanguageFontGroup>
{
    using abi = ABI::Windows::Globalization::Fonts::ILanguageFontGroup;
    template <typename D> using consume = Windows::Globalization::Fonts::impl_ILanguageFontGroup<D>;
};

template <> struct traits<Windows::Globalization::Fonts::ILanguageFontGroupFactory>
{
    using abi = ABI::Windows::Globalization::Fonts::ILanguageFontGroupFactory;
    template <typename D> using consume = Windows::Globalization::Fonts::impl_ILanguageFontGroupFactory<D>;
};

template <> struct traits<Windows::Globalization::Fonts::LanguageFont>
{
    using abi = ABI::Windows::Globalization::Fonts::LanguageFont;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Globalization.Fonts.LanguageFont"; }
};

template <> struct traits<Windows::Globalization::Fonts::LanguageFontGroup>
{
    using abi = ABI::Windows::Globalization::Fonts::LanguageFontGroup;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Globalization.Fonts.LanguageFontGroup"; }
};

}

}
