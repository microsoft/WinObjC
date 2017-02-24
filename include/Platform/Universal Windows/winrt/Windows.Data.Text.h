// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Data.Text.3.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Data::Text {

template <typename L> SelectableWordSegmentsTokenizingHandler::SelectableWordSegmentsTokenizingHandler(L lambda) :
    SelectableWordSegmentsTokenizingHandler(impl::make_delegate<impl_SelectableWordSegmentsTokenizingHandler<L>, SelectableWordSegmentsTokenizingHandler>(std::forward<L>(lambda)))
{}

template <typename F> SelectableWordSegmentsTokenizingHandler::SelectableWordSegmentsTokenizingHandler(F * function) :
    SelectableWordSegmentsTokenizingHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> SelectableWordSegmentsTokenizingHandler::SelectableWordSegmentsTokenizingHandler(O * object, M method) :
    SelectableWordSegmentsTokenizingHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void SelectableWordSegmentsTokenizingHandler::operator()(iterable<Windows::Data::Text::SelectableWordSegment> precedingWords, iterable<Windows::Data::Text::SelectableWordSegment> words) const
{
    check_hresult((*(abi<SelectableWordSegmentsTokenizingHandler> **)this)->abi_Invoke(get_abi(precedingWords), get_abi(words)));
}

template <typename L> WordSegmentsTokenizingHandler::WordSegmentsTokenizingHandler(L lambda) :
    WordSegmentsTokenizingHandler(impl::make_delegate<impl_WordSegmentsTokenizingHandler<L>, WordSegmentsTokenizingHandler>(std::forward<L>(lambda)))
{}

template <typename F> WordSegmentsTokenizingHandler::WordSegmentsTokenizingHandler(F * function) :
    WordSegmentsTokenizingHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> WordSegmentsTokenizingHandler::WordSegmentsTokenizingHandler(O * object, M method) :
    WordSegmentsTokenizingHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void WordSegmentsTokenizingHandler::operator()(iterable<Windows::Data::Text::WordSegment> precedingWords, iterable<Windows::Data::Text::WordSegment> words) const
{
    check_hresult((*(abi<WordSegmentsTokenizingHandler> **)this)->abi_Invoke(get_abi(precedingWords), get_abi(words)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Data::Text::IAlternateWordForm> : produce_base<D, Windows::Data::Text::IAlternateWordForm>
{
    HRESULT __stdcall get_SourceTextSegment(impl::abi_arg_out<Windows::Data::Text::TextSegment> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceTextSegment());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlternateText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlternateText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NormalizationFormat(Windows::Data::Text::AlternateNormalizationFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NormalizationFormat());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::ISelectableWordSegment> : produce_base<D, Windows::Data::Text::ISelectableWordSegment>
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

    HRESULT __stdcall get_SourceTextSegment(impl::abi_arg_out<Windows::Data::Text::TextSegment> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceTextSegment());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::ISelectableWordsSegmenter> : produce_base<D, Windows::Data::Text::ISelectableWordsSegmenter>
{
    HRESULT __stdcall get_ResolvedLanguage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResolvedLanguage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTokenAt(impl::abi_arg_in<hstring> text, uint32_t startIndex, impl::abi_arg_out<Windows::Data::Text::ISelectableWordSegment> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetTokenAt(*reinterpret_cast<const hstring *>(&text), startIndex));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTokens(impl::abi_arg_in<hstring> text, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Data::Text::SelectableWordSegment>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetTokens(*reinterpret_cast<const hstring *>(&text)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Tokenize(impl::abi_arg_in<hstring> text, uint32_t startIndex, impl::abi_arg_in<Windows::Data::Text::SelectableWordSegmentsTokenizingHandler> handler) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Tokenize(*reinterpret_cast<const hstring *>(&text), startIndex, *reinterpret_cast<const Windows::Data::Text::SelectableWordSegmentsTokenizingHandler *>(&handler));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::ISelectableWordsSegmenterFactory> : produce_base<D, Windows::Data::Text::ISelectableWordsSegmenterFactory>
{
    HRESULT __stdcall abi_CreateWithLanguage(impl::abi_arg_in<hstring> language, impl::abi_arg_out<Windows::Data::Text::ISelectableWordsSegmenter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithLanguage(*reinterpret_cast<const hstring *>(&language)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::ISemanticTextQuery> : produce_base<D, Windows::Data::Text::ISemanticTextQuery>
{
    HRESULT __stdcall abi_Find(impl::abi_arg_in<hstring> content, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Find(*reinterpret_cast<const hstring *>(&content)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindInProperty(impl::abi_arg_in<hstring> propertyContent, impl::abi_arg_in<hstring> propertyName, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindInProperty(*reinterpret_cast<const hstring *>(&propertyContent), *reinterpret_cast<const hstring *>(&propertyName)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::ISemanticTextQueryFactory> : produce_base<D, Windows::Data::Text::ISemanticTextQueryFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> aqsFilter, impl::abi_arg_out<Windows::Data::Text::ISemanticTextQuery> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&aqsFilter)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithLanguage(impl::abi_arg_in<hstring> aqsFilter, impl::abi_arg_in<hstring> filterLanguage, impl::abi_arg_out<Windows::Data::Text::ISemanticTextQuery> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithLanguage(*reinterpret_cast<const hstring *>(&aqsFilter), *reinterpret_cast<const hstring *>(&filterLanguage)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::ITextConversionGenerator> : produce_base<D, Windows::Data::Text::ITextConversionGenerator>
{
    HRESULT __stdcall get_ResolvedLanguage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResolvedLanguage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LanguageAvailableButNotInstalled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LanguageAvailableButNotInstalled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCandidatesAsync(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetCandidatesAsync(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCandidatesWithMaxCountAsync(impl::abi_arg_in<hstring> input, uint32_t maxCandidates, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetCandidatesAsync(*reinterpret_cast<const hstring *>(&input), maxCandidates));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::ITextConversionGeneratorFactory> : produce_base<D, Windows::Data::Text::ITextConversionGeneratorFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> languageTag, impl::abi_arg_out<Windows::Data::Text::ITextConversionGenerator> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&languageTag)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::ITextPhoneme> : produce_base<D, Windows::Data::Text::ITextPhoneme>
{
    HRESULT __stdcall get_DisplayText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadingText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadingText());
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
struct produce<D, Windows::Data::Text::ITextPredictionGenerator> : produce_base<D, Windows::Data::Text::ITextPredictionGenerator>
{
    HRESULT __stdcall get_ResolvedLanguage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResolvedLanguage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LanguageAvailableButNotInstalled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LanguageAvailableButNotInstalled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCandidatesAsync(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetCandidatesAsync(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCandidatesWithMaxCountAsync(impl::abi_arg_in<hstring> input, uint32_t maxCandidates, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetCandidatesAsync(*reinterpret_cast<const hstring *>(&input), maxCandidates));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::ITextPredictionGeneratorFactory> : produce_base<D, Windows::Data::Text::ITextPredictionGeneratorFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> languageTag, impl::abi_arg_out<Windows::Data::Text::ITextPredictionGenerator> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&languageTag)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::ITextReverseConversionGenerator> : produce_base<D, Windows::Data::Text::ITextReverseConversionGenerator>
{
    HRESULT __stdcall get_ResolvedLanguage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResolvedLanguage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LanguageAvailableButNotInstalled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LanguageAvailableButNotInstalled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConvertBackAsync(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ConvertBackAsync(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::ITextReverseConversionGenerator2> : produce_base<D, Windows::Data::Text::ITextReverseConversionGenerator2>
{
    HRESULT __stdcall abi_GetPhonemesAsync(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextPhoneme>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetPhonemesAsync(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::ITextReverseConversionGeneratorFactory> : produce_base<D, Windows::Data::Text::ITextReverseConversionGeneratorFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> languageTag, impl::abi_arg_out<Windows::Data::Text::ITextReverseConversionGenerator> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&languageTag)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::IUnicodeCharactersStatics> : produce_base<D, Windows::Data::Text::IUnicodeCharactersStatics>
{
    HRESULT __stdcall abi_GetCodepointFromSurrogatePair(uint32_t highSurrogate, uint32_t lowSurrogate, uint32_t * codepoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *codepoint = detach_abi(this->shim().GetCodepointFromSurrogatePair(highSurrogate, lowSurrogate));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSurrogatePairFromCodepoint(uint32_t codepoint, wchar_t * highSurrogate, wchar_t * lowSurrogate) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetSurrogatePairFromCodepoint(codepoint, *highSurrogate, *lowSurrogate);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsHighSurrogate(uint32_t codepoint, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHighSurrogate(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsLowSurrogate(uint32_t codepoint, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsLowSurrogate(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsSupplementary(uint32_t codepoint, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSupplementary(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsNoncharacter(uint32_t codepoint, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsNoncharacter(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsWhitespace(uint32_t codepoint, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsWhitespace(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsAlphabetic(uint32_t codepoint, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAlphabetic(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsCased(uint32_t codepoint, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCased(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsUppercase(uint32_t codepoint, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsUppercase(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsLowercase(uint32_t codepoint, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsLowercase(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsIdStart(uint32_t codepoint, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsIdStart(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsIdContinue(uint32_t codepoint, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsIdContinue(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsGraphemeBase(uint32_t codepoint, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsGraphemeBase(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsGraphemeExtend(uint32_t codepoint, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsGraphemeExtend(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNumericType(uint32_t codepoint, Windows::Data::Text::UnicodeNumericType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetNumericType(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetGeneralCategory(uint32_t codepoint, Windows::Data::Text::UnicodeGeneralCategory * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetGeneralCategory(codepoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::IWordSegment> : produce_base<D, Windows::Data::Text::IWordSegment>
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

    HRESULT __stdcall get_SourceTextSegment(impl::abi_arg_out<Windows::Data::Text::TextSegment> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceTextSegment());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlternateForms(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Data::Text::AlternateWordForm>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlternateForms());
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
struct produce<D, Windows::Data::Text::IWordsSegmenter> : produce_base<D, Windows::Data::Text::IWordsSegmenter>
{
    HRESULT __stdcall get_ResolvedLanguage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResolvedLanguage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTokenAt(impl::abi_arg_in<hstring> text, uint32_t startIndex, impl::abi_arg_out<Windows::Data::Text::IWordSegment> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetTokenAt(*reinterpret_cast<const hstring *>(&text), startIndex));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTokens(impl::abi_arg_in<hstring> text, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Data::Text::WordSegment>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetTokens(*reinterpret_cast<const hstring *>(&text)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Tokenize(impl::abi_arg_in<hstring> text, uint32_t startIndex, impl::abi_arg_in<Windows::Data::Text::WordSegmentsTokenizingHandler> handler) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Tokenize(*reinterpret_cast<const hstring *>(&text), startIndex, *reinterpret_cast<const Windows::Data::Text::WordSegmentsTokenizingHandler *>(&handler));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Text::IWordsSegmenterFactory> : produce_base<D, Windows::Data::Text::IWordsSegmenterFactory>
{
    HRESULT __stdcall abi_CreateWithLanguage(impl::abi_arg_in<hstring> language, impl::abi_arg_out<Windows::Data::Text::IWordsSegmenter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithLanguage(*reinterpret_cast<const hstring *>(&language)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Data::Text {

template <typename D> Windows::Data::Text::SemanticTextQuery impl_ISemanticTextQueryFactory<D>::Create(hstring_view aqsFilter) const
{
    Windows::Data::Text::SemanticTextQuery result { nullptr };
    check_hresult(WINRT_SHIM(ISemanticTextQueryFactory)->abi_Create(get_abi(aqsFilter), put_abi(result)));
    return result;
}

template <typename D> Windows::Data::Text::SemanticTextQuery impl_ISemanticTextQueryFactory<D>::CreateWithLanguage(hstring_view aqsFilter, hstring_view filterLanguage) const
{
    Windows::Data::Text::SemanticTextQuery result { nullptr };
    check_hresult(WINRT_SHIM(ISemanticTextQueryFactory)->abi_CreateWithLanguage(get_abi(aqsFilter), get_abi(filterLanguage), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment> impl_ISemanticTextQuery<D>::Find(hstring_view content) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment> result;
    check_hresult(WINRT_SHIM(ISemanticTextQuery)->abi_Find(get_abi(content), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment> impl_ISemanticTextQuery<D>::FindInProperty(hstring_view propertyContent, hstring_view propertyName) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment> result;
    check_hresult(WINRT_SHIM(ISemanticTextQuery)->abi_FindInProperty(get_abi(propertyContent), get_abi(propertyName), put_abi(result)));
    return result;
}

template <typename D> uint32_t impl_IUnicodeCharactersStatics<D>::GetCodepointFromSurrogatePair(uint32_t highSurrogate, uint32_t lowSurrogate) const
{
    uint32_t codepoint {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_GetCodepointFromSurrogatePair(highSurrogate, lowSurrogate, &codepoint));
    return codepoint;
}

template <typename D> void impl_IUnicodeCharactersStatics<D>::GetSurrogatePairFromCodepoint(uint32_t codepoint, wchar_t & highSurrogate, wchar_t & lowSurrogate) const
{
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_GetSurrogatePairFromCodepoint(codepoint, &highSurrogate, &lowSurrogate));
}

template <typename D> bool impl_IUnicodeCharactersStatics<D>::IsHighSurrogate(uint32_t codepoint) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_IsHighSurrogate(codepoint, &value));
    return value;
}

template <typename D> bool impl_IUnicodeCharactersStatics<D>::IsLowSurrogate(uint32_t codepoint) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_IsLowSurrogate(codepoint, &value));
    return value;
}

template <typename D> bool impl_IUnicodeCharactersStatics<D>::IsSupplementary(uint32_t codepoint) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_IsSupplementary(codepoint, &value));
    return value;
}

template <typename D> bool impl_IUnicodeCharactersStatics<D>::IsNoncharacter(uint32_t codepoint) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_IsNoncharacter(codepoint, &value));
    return value;
}

template <typename D> bool impl_IUnicodeCharactersStatics<D>::IsWhitespace(uint32_t codepoint) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_IsWhitespace(codepoint, &value));
    return value;
}

template <typename D> bool impl_IUnicodeCharactersStatics<D>::IsAlphabetic(uint32_t codepoint) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_IsAlphabetic(codepoint, &value));
    return value;
}

template <typename D> bool impl_IUnicodeCharactersStatics<D>::IsCased(uint32_t codepoint) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_IsCased(codepoint, &value));
    return value;
}

template <typename D> bool impl_IUnicodeCharactersStatics<D>::IsUppercase(uint32_t codepoint) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_IsUppercase(codepoint, &value));
    return value;
}

template <typename D> bool impl_IUnicodeCharactersStatics<D>::IsLowercase(uint32_t codepoint) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_IsLowercase(codepoint, &value));
    return value;
}

template <typename D> bool impl_IUnicodeCharactersStatics<D>::IsIdStart(uint32_t codepoint) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_IsIdStart(codepoint, &value));
    return value;
}

template <typename D> bool impl_IUnicodeCharactersStatics<D>::IsIdContinue(uint32_t codepoint) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_IsIdContinue(codepoint, &value));
    return value;
}

template <typename D> bool impl_IUnicodeCharactersStatics<D>::IsGraphemeBase(uint32_t codepoint) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_IsGraphemeBase(codepoint, &value));
    return value;
}

template <typename D> bool impl_IUnicodeCharactersStatics<D>::IsGraphemeExtend(uint32_t codepoint) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_IsGraphemeExtend(codepoint, &value));
    return value;
}

template <typename D> Windows::Data::Text::UnicodeNumericType impl_IUnicodeCharactersStatics<D>::GetNumericType(uint32_t codepoint) const
{
    Windows::Data::Text::UnicodeNumericType value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_GetNumericType(codepoint, &value));
    return value;
}

template <typename D> Windows::Data::Text::UnicodeGeneralCategory impl_IUnicodeCharactersStatics<D>::GetGeneralCategory(uint32_t codepoint) const
{
    Windows::Data::Text::UnicodeGeneralCategory value {};
    check_hresult(WINRT_SHIM(IUnicodeCharactersStatics)->abi_GetGeneralCategory(codepoint, &value));
    return value;
}

template <typename D> Windows::Data::Text::TextSegment impl_IAlternateWordForm<D>::SourceTextSegment() const
{
    Windows::Data::Text::TextSegment value {};
    check_hresult(WINRT_SHIM(IAlternateWordForm)->get_SourceTextSegment(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAlternateWordForm<D>::AlternateText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAlternateWordForm)->get_AlternateText(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Text::AlternateNormalizationFormat impl_IAlternateWordForm<D>::NormalizationFormat() const
{
    Windows::Data::Text::AlternateNormalizationFormat value {};
    check_hresult(WINRT_SHIM(IAlternateWordForm)->get_NormalizationFormat(&value));
    return value;
}

template <typename D> hstring impl_ISelectableWordSegment<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISelectableWordSegment)->get_Text(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Text::TextSegment impl_ISelectableWordSegment<D>::SourceTextSegment() const
{
    Windows::Data::Text::TextSegment value {};
    check_hresult(WINRT_SHIM(ISelectableWordSegment)->get_SourceTextSegment(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWordSegment<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWordSegment)->get_Text(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Text::TextSegment impl_IWordSegment<D>::SourceTextSegment() const
{
    Windows::Data::Text::TextSegment value {};
    check_hresult(WINRT_SHIM(IWordSegment)->get_SourceTextSegment(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Data::Text::AlternateWordForm> impl_IWordSegment<D>::AlternateForms() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Data::Text::AlternateWordForm> value;
    check_hresult(WINRT_SHIM(IWordSegment)->get_AlternateForms(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWordsSegmenter<D>::ResolvedLanguage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWordsSegmenter)->get_ResolvedLanguage(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Text::WordSegment impl_IWordsSegmenter<D>::GetTokenAt(hstring_view text, uint32_t startIndex) const
{
    Windows::Data::Text::WordSegment result { nullptr };
    check_hresult(WINRT_SHIM(IWordsSegmenter)->abi_GetTokenAt(get_abi(text), startIndex, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Data::Text::WordSegment> impl_IWordsSegmenter<D>::GetTokens(hstring_view text) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Data::Text::WordSegment> result;
    check_hresult(WINRT_SHIM(IWordsSegmenter)->abi_GetTokens(get_abi(text), put_abi(result)));
    return result;
}

template <typename D> void impl_IWordsSegmenter<D>::Tokenize(hstring_view text, uint32_t startIndex, const Windows::Data::Text::WordSegmentsTokenizingHandler & handler) const
{
    check_hresult(WINRT_SHIM(IWordsSegmenter)->abi_Tokenize(get_abi(text), startIndex, get_abi(handler)));
}

template <typename D> Windows::Data::Text::WordsSegmenter impl_IWordsSegmenterFactory<D>::CreateWithLanguage(hstring_view language) const
{
    Windows::Data::Text::WordsSegmenter result { nullptr };
    check_hresult(WINRT_SHIM(IWordsSegmenterFactory)->abi_CreateWithLanguage(get_abi(language), put_abi(result)));
    return result;
}

template <typename D> hstring impl_ISelectableWordsSegmenter<D>::ResolvedLanguage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISelectableWordsSegmenter)->get_ResolvedLanguage(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Text::SelectableWordSegment impl_ISelectableWordsSegmenter<D>::GetTokenAt(hstring_view text, uint32_t startIndex) const
{
    Windows::Data::Text::SelectableWordSegment result { nullptr };
    check_hresult(WINRT_SHIM(ISelectableWordsSegmenter)->abi_GetTokenAt(get_abi(text), startIndex, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Data::Text::SelectableWordSegment> impl_ISelectableWordsSegmenter<D>::GetTokens(hstring_view text) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Data::Text::SelectableWordSegment> result;
    check_hresult(WINRT_SHIM(ISelectableWordsSegmenter)->abi_GetTokens(get_abi(text), put_abi(result)));
    return result;
}

template <typename D> void impl_ISelectableWordsSegmenter<D>::Tokenize(hstring_view text, uint32_t startIndex, const Windows::Data::Text::SelectableWordSegmentsTokenizingHandler & handler) const
{
    check_hresult(WINRT_SHIM(ISelectableWordsSegmenter)->abi_Tokenize(get_abi(text), startIndex, get_abi(handler)));
}

template <typename D> Windows::Data::Text::SelectableWordsSegmenter impl_ISelectableWordsSegmenterFactory<D>::CreateWithLanguage(hstring_view language) const
{
    Windows::Data::Text::SelectableWordsSegmenter result { nullptr };
    check_hresult(WINRT_SHIM(ISelectableWordsSegmenterFactory)->abi_CreateWithLanguage(get_abi(language), put_abi(result)));
    return result;
}

template <typename D> hstring impl_ITextPredictionGenerator<D>::ResolvedLanguage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITextPredictionGenerator)->get_ResolvedLanguage(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITextPredictionGenerator<D>::LanguageAvailableButNotInstalled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITextPredictionGenerator)->get_LanguageAvailableButNotInstalled(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> impl_ITextPredictionGenerator<D>::GetCandidatesAsync(hstring_view input) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> result;
    check_hresult(WINRT_SHIM(ITextPredictionGenerator)->abi_GetCandidatesAsync(get_abi(input), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> impl_ITextPredictionGenerator<D>::GetCandidatesAsync(hstring_view input, uint32_t maxCandidates) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> result;
    check_hresult(WINRT_SHIM(ITextPredictionGenerator)->abi_GetCandidatesWithMaxCountAsync(get_abi(input), maxCandidates, put_abi(result)));
    return result;
}

template <typename D> Windows::Data::Text::TextPredictionGenerator impl_ITextPredictionGeneratorFactory<D>::Create(hstring_view languageTag) const
{
    Windows::Data::Text::TextPredictionGenerator result { nullptr };
    check_hresult(WINRT_SHIM(ITextPredictionGeneratorFactory)->abi_Create(get_abi(languageTag), put_abi(result)));
    return result;
}

template <typename D> hstring impl_ITextConversionGenerator<D>::ResolvedLanguage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITextConversionGenerator)->get_ResolvedLanguage(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITextConversionGenerator<D>::LanguageAvailableButNotInstalled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITextConversionGenerator)->get_LanguageAvailableButNotInstalled(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> impl_ITextConversionGenerator<D>::GetCandidatesAsync(hstring_view input) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> result;
    check_hresult(WINRT_SHIM(ITextConversionGenerator)->abi_GetCandidatesAsync(get_abi(input), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> impl_ITextConversionGenerator<D>::GetCandidatesAsync(hstring_view input, uint32_t maxCandidates) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> result;
    check_hresult(WINRT_SHIM(ITextConversionGenerator)->abi_GetCandidatesWithMaxCountAsync(get_abi(input), maxCandidates, put_abi(result)));
    return result;
}

template <typename D> Windows::Data::Text::TextConversionGenerator impl_ITextConversionGeneratorFactory<D>::Create(hstring_view languageTag) const
{
    Windows::Data::Text::TextConversionGenerator result { nullptr };
    check_hresult(WINRT_SHIM(ITextConversionGeneratorFactory)->abi_Create(get_abi(languageTag), put_abi(result)));
    return result;
}

template <typename D> hstring impl_ITextReverseConversionGenerator<D>::ResolvedLanguage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITextReverseConversionGenerator)->get_ResolvedLanguage(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITextReverseConversionGenerator<D>::LanguageAvailableButNotInstalled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITextReverseConversionGenerator)->get_LanguageAvailableButNotInstalled(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ITextReverseConversionGenerator<D>::ConvertBackAsync(hstring_view input) const
{
    Windows::Foundation::IAsyncOperation<hstring> result;
    check_hresult(WINRT_SHIM(ITextReverseConversionGenerator)->abi_ConvertBackAsync(get_abi(input), put_abi(result)));
    return result;
}

template <typename D> Windows::Data::Text::TextReverseConversionGenerator impl_ITextReverseConversionGeneratorFactory<D>::Create(hstring_view languageTag) const
{
    Windows::Data::Text::TextReverseConversionGenerator result { nullptr };
    check_hresult(WINRT_SHIM(ITextReverseConversionGeneratorFactory)->abi_Create(get_abi(languageTag), put_abi(result)));
    return result;
}

template <typename D> hstring impl_ITextPhoneme<D>::DisplayText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITextPhoneme)->get_DisplayText(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ITextPhoneme<D>::ReadingText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITextPhoneme)->get_ReadingText(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextPhoneme>> impl_ITextReverseConversionGenerator2<D>::GetPhonemesAsync(hstring_view input) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextPhoneme>> result;
    check_hresult(WINRT_SHIM(ITextReverseConversionGenerator2)->abi_GetPhonemesAsync(get_abi(input), put_abi(result)));
    return result;
}

inline SelectableWordsSegmenter::SelectableWordsSegmenter(hstring_view language) :
    SelectableWordsSegmenter(get_activation_factory<SelectableWordsSegmenter, ISelectableWordsSegmenterFactory>().CreateWithLanguage(language))
{}

inline SemanticTextQuery::SemanticTextQuery(hstring_view aqsFilter) :
    SemanticTextQuery(get_activation_factory<SemanticTextQuery, ISemanticTextQueryFactory>().Create(aqsFilter))
{}

inline SemanticTextQuery::SemanticTextQuery(hstring_view aqsFilter, hstring_view filterLanguage) :
    SemanticTextQuery(get_activation_factory<SemanticTextQuery, ISemanticTextQueryFactory>().CreateWithLanguage(aqsFilter, filterLanguage))
{}

inline TextConversionGenerator::TextConversionGenerator(hstring_view languageTag) :
    TextConversionGenerator(get_activation_factory<TextConversionGenerator, ITextConversionGeneratorFactory>().Create(languageTag))
{}

inline TextPredictionGenerator::TextPredictionGenerator(hstring_view languageTag) :
    TextPredictionGenerator(get_activation_factory<TextPredictionGenerator, ITextPredictionGeneratorFactory>().Create(languageTag))
{}

inline TextReverseConversionGenerator::TextReverseConversionGenerator(hstring_view languageTag) :
    TextReverseConversionGenerator(get_activation_factory<TextReverseConversionGenerator, ITextReverseConversionGeneratorFactory>().Create(languageTag))
{}

inline uint32_t UnicodeCharacters::GetCodepointFromSurrogatePair(uint32_t highSurrogate, uint32_t lowSurrogate)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().GetCodepointFromSurrogatePair(highSurrogate, lowSurrogate);
}

inline void UnicodeCharacters::GetSurrogatePairFromCodepoint(uint32_t codepoint, wchar_t & highSurrogate, wchar_t & lowSurrogate)
{
    get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().GetSurrogatePairFromCodepoint(codepoint, highSurrogate, lowSurrogate);
}

inline bool UnicodeCharacters::IsHighSurrogate(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().IsHighSurrogate(codepoint);
}

inline bool UnicodeCharacters::IsLowSurrogate(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().IsLowSurrogate(codepoint);
}

inline bool UnicodeCharacters::IsSupplementary(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().IsSupplementary(codepoint);
}

inline bool UnicodeCharacters::IsNoncharacter(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().IsNoncharacter(codepoint);
}

inline bool UnicodeCharacters::IsWhitespace(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().IsWhitespace(codepoint);
}

inline bool UnicodeCharacters::IsAlphabetic(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().IsAlphabetic(codepoint);
}

inline bool UnicodeCharacters::IsCased(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().IsCased(codepoint);
}

inline bool UnicodeCharacters::IsUppercase(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().IsUppercase(codepoint);
}

inline bool UnicodeCharacters::IsLowercase(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().IsLowercase(codepoint);
}

inline bool UnicodeCharacters::IsIdStart(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().IsIdStart(codepoint);
}

inline bool UnicodeCharacters::IsIdContinue(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().IsIdContinue(codepoint);
}

inline bool UnicodeCharacters::IsGraphemeBase(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().IsGraphemeBase(codepoint);
}

inline bool UnicodeCharacters::IsGraphemeExtend(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().IsGraphemeExtend(codepoint);
}

inline Windows::Data::Text::UnicodeNumericType UnicodeCharacters::GetNumericType(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().GetNumericType(codepoint);
}

inline Windows::Data::Text::UnicodeGeneralCategory UnicodeCharacters::GetGeneralCategory(uint32_t codepoint)
{
    return get_activation_factory<UnicodeCharacters, IUnicodeCharactersStatics>().GetGeneralCategory(codepoint);
}

inline WordsSegmenter::WordsSegmenter(hstring_view language) :
    WordsSegmenter(get_activation_factory<WordsSegmenter, IWordsSegmenterFactory>().CreateWithLanguage(language))
{}

}

}
#pragma warning(pop)
