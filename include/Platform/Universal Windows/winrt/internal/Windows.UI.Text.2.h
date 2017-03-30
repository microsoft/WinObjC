// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Text.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Text {

struct IFontWeights :
    Windows::Foundation::IInspectable,
    impl::consume<IFontWeights>
{
    IFontWeights(std::nullptr_t = nullptr) noexcept {}
};

struct IFontWeightsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IFontWeightsStatics>
{
    IFontWeightsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ITextCharacterFormat :
    Windows::Foundation::IInspectable,
    impl::consume<ITextCharacterFormat>
{
    ITextCharacterFormat(std::nullptr_t = nullptr) noexcept {}
};

struct ITextConstantsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ITextConstantsStatics>
{
    ITextConstantsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ITextDocument :
    Windows::Foundation::IInspectable,
    impl::consume<ITextDocument>
{
    ITextDocument(std::nullptr_t = nullptr) noexcept {}
};

struct ITextParagraphFormat :
    Windows::Foundation::IInspectable,
    impl::consume<ITextParagraphFormat>
{
    ITextParagraphFormat(std::nullptr_t = nullptr) noexcept {}
};

struct ITextRange :
    Windows::Foundation::IInspectable,
    impl::consume<ITextRange>
{
    ITextRange(std::nullptr_t = nullptr) noexcept {}
};

struct ITextSelection :
    Windows::Foundation::IInspectable,
    impl::consume<ITextSelection>,
    impl::require<ITextSelection, Windows::UI::Text::ITextRange>
{
    ITextSelection(std::nullptr_t = nullptr) noexcept {}
};

}

}
