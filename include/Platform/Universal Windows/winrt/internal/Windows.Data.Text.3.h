// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Data.Text.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Data::Text {

template <typename H> struct impl_SelectableWordSegmentsTokenizingHandler : implements<impl_SelectableWordSegmentsTokenizingHandler<H>, abi<SelectableWordSegmentsTokenizingHandler>>, H
{
    impl_SelectableWordSegmentsTokenizingHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Data::Text::SelectableWordSegment>> precedingWords, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Data::Text::SelectableWordSegment>> words) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Data::Text::SelectableWordSegment> *>(&precedingWords), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Data::Text::SelectableWordSegment> *>(&words));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_WordSegmentsTokenizingHandler : implements<impl_WordSegmentsTokenizingHandler<H>, abi<WordSegmentsTokenizingHandler>>, H
{
    impl_WordSegmentsTokenizingHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Data::Text::WordSegment>> precedingWords, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Data::Text::WordSegment>> words) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Data::Text::WordSegment> *>(&precedingWords), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Data::Text::WordSegment> *>(&words));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Data::Text {

struct WINRT_EBO AlternateWordForm :
    Windows::Data::Text::IAlternateWordForm
{
    AlternateWordForm(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SelectableWordSegment :
    Windows::Data::Text::ISelectableWordSegment
{
    SelectableWordSegment(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SelectableWordsSegmenter :
    Windows::Data::Text::ISelectableWordsSegmenter
{
    SelectableWordsSegmenter(std::nullptr_t) noexcept {}
    SelectableWordsSegmenter(hstring_view language);
};

struct WINRT_EBO SemanticTextQuery :
    Windows::Data::Text::ISemanticTextQuery
{
    SemanticTextQuery(std::nullptr_t) noexcept {}
    SemanticTextQuery(hstring_view aqsFilter);
    SemanticTextQuery(hstring_view aqsFilter, hstring_view filterLanguage);
};

struct WINRT_EBO TextConversionGenerator :
    Windows::Data::Text::ITextConversionGenerator
{
    TextConversionGenerator(std::nullptr_t) noexcept {}
    TextConversionGenerator(hstring_view languageTag);
};

struct WINRT_EBO TextPhoneme :
    Windows::Data::Text::ITextPhoneme
{
    TextPhoneme(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TextPredictionGenerator :
    Windows::Data::Text::ITextPredictionGenerator
{
    TextPredictionGenerator(std::nullptr_t) noexcept {}
    TextPredictionGenerator(hstring_view languageTag);
};

struct WINRT_EBO TextReverseConversionGenerator :
    Windows::Data::Text::ITextReverseConversionGenerator,
    impl::require<TextReverseConversionGenerator, Windows::Data::Text::ITextReverseConversionGenerator2>
{
    TextReverseConversionGenerator(std::nullptr_t) noexcept {}
    TextReverseConversionGenerator(hstring_view languageTag);
};

struct UnicodeCharacters
{
    UnicodeCharacters() = delete;
    static uint32_t GetCodepointFromSurrogatePair(uint32_t highSurrogate, uint32_t lowSurrogate);
    static void GetSurrogatePairFromCodepoint(uint32_t codepoint, wchar_t & highSurrogate, wchar_t & lowSurrogate);
    static bool IsHighSurrogate(uint32_t codepoint);
    static bool IsLowSurrogate(uint32_t codepoint);
    static bool IsSupplementary(uint32_t codepoint);
    static bool IsNoncharacter(uint32_t codepoint);
    static bool IsWhitespace(uint32_t codepoint);
    static bool IsAlphabetic(uint32_t codepoint);
    static bool IsCased(uint32_t codepoint);
    static bool IsUppercase(uint32_t codepoint);
    static bool IsLowercase(uint32_t codepoint);
    static bool IsIdStart(uint32_t codepoint);
    static bool IsIdContinue(uint32_t codepoint);
    static bool IsGraphemeBase(uint32_t codepoint);
    static bool IsGraphemeExtend(uint32_t codepoint);
    static Windows::Data::Text::UnicodeNumericType GetNumericType(uint32_t codepoint);
    static Windows::Data::Text::UnicodeGeneralCategory GetGeneralCategory(uint32_t codepoint);
};

struct WINRT_EBO WordSegment :
    Windows::Data::Text::IWordSegment
{
    WordSegment(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WordsSegmenter :
    Windows::Data::Text::IWordsSegmenter
{
    WordsSegmenter(std::nullptr_t) noexcept {}
    WordsSegmenter(hstring_view language);
};

}

}
