// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.ApplicationModel.Search.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.Search.Core.3.h"
#include "Windows.ApplicationModel.Search.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Search::Core::IRequestingFocusOnKeyboardInputEventArgs> : produce_base<D, Windows::ApplicationModel::Search::Core::IRequestingFocusOnKeyboardInputEventArgs>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Search::Core::ISearchSuggestion> : produce_base<D, Windows::ApplicationModel::Search::Core::ISearchSuggestion>
{
    HRESULT __stdcall get_Kind(Windows::ApplicationModel::Search::Core::SearchSuggestionKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_Tag(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Tag());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DetailText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DetailText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Image(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Image());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ImageAlternateText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImageAlternateText());
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
struct produce<D, Windows::ApplicationModel::Search::Core::ISearchSuggestionManager> : produce_base<D, Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>
{
    HRESULT __stdcall get_SearchHistoryEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SearchHistoryEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SearchHistoryEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SearchHistoryEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SearchHistoryContext(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SearchHistoryContext());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SearchHistoryContext(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SearchHistoryContext(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetLocalContentSuggestionSettings(impl::abi_arg_in<Windows::ApplicationModel::Search::ILocalContentSuggestionSettings> settings) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetLocalContentSuggestionSettings(*reinterpret_cast<const Windows::ApplicationModel::Search::LocalContentSuggestionSettings *>(&settings));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetQuery(impl::abi_arg_in<hstring> queryText) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetQuery(*reinterpret_cast<const hstring *>(&queryText));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetQueryWithLanguage(impl::abi_arg_in<hstring> queryText, impl::abi_arg_in<hstring> language) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetQuery(*reinterpret_cast<const hstring *>(&queryText), *reinterpret_cast<const hstring *>(&language));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetQueryWithSearchQueryLinguisticDetails(impl::abi_arg_in<hstring> queryText, impl::abi_arg_in<hstring> language, impl::abi_arg_in<Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails> linguisticDetails) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetQuery(*reinterpret_cast<const hstring *>(&queryText), *reinterpret_cast<const hstring *>(&language), *reinterpret_cast<const Windows::ApplicationModel::Search::SearchQueryLinguisticDetails *>(&linguisticDetails));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Suggestions(impl::abi_arg_out<Windows::Foundation::Collections::IObservableVector<Windows::ApplicationModel::Search::Core::SearchSuggestion>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Suggestions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddToHistory(impl::abi_arg_in<hstring> queryText) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddToHistory(*reinterpret_cast<const hstring *>(&queryText));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddToHistoryWithLanguage(impl::abi_arg_in<hstring> queryText, impl::abi_arg_in<hstring> language) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddToHistory(*reinterpret_cast<const hstring *>(&queryText), *reinterpret_cast<const hstring *>(&language));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearHistory() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearHistory();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SuggestionsRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::Core::SearchSuggestionManager, Windows::ApplicationModel::Search::Core::SearchSuggestionsRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SuggestionsRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::Core::SearchSuggestionManager, Windows::ApplicationModel::Search::Core::SearchSuggestionsRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SuggestionsRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuggestionsRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RequestingFocusOnKeyboardInput(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::Core::SearchSuggestionManager, Windows::ApplicationModel::Search::Core::RequestingFocusOnKeyboardInputEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RequestingFocusOnKeyboardInput(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::Core::SearchSuggestionManager, Windows::ApplicationModel::Search::Core::RequestingFocusOnKeyboardInputEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RequestingFocusOnKeyboardInput(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestingFocusOnKeyboardInput(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Search::Core::ISearchSuggestionsRequestedEventArgs> : produce_base<D, Windows::ApplicationModel::Search::Core::ISearchSuggestionsRequestedEventArgs>
{
    HRESULT __stdcall get_QueryText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QueryText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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

    HRESULT __stdcall get_LinguisticDetails(impl::abi_arg_out<Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LinguisticDetails());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Search::ISearchSuggestionsRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Request());
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

namespace Windows::ApplicationModel::Search::Core {

template <typename D> Windows::ApplicationModel::Search::Core::SearchSuggestionKind impl_ISearchSuggestion<D>::Kind() const
{
    Windows::ApplicationModel::Search::Core::SearchSuggestionKind value {};
    check_hresult(WINRT_SHIM(ISearchSuggestion)->get_Kind(&value));
    return value;
}

template <typename D> hstring impl_ISearchSuggestion<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISearchSuggestion)->get_Text(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISearchSuggestion<D>::Tag() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISearchSuggestion)->get_Tag(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISearchSuggestion<D>::DetailText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISearchSuggestion)->get_DetailText(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_ISearchSuggestion<D>::Image() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(ISearchSuggestion)->get_Image(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISearchSuggestion<D>::ImageAlternateText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISearchSuggestion)->get_ImageAlternateText(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISearchSuggestionsRequestedEventArgs<D>::QueryText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISearchSuggestionsRequestedEventArgs)->get_QueryText(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISearchSuggestionsRequestedEventArgs<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISearchSuggestionsRequestedEventArgs)->get_Language(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Search::SearchQueryLinguisticDetails impl_ISearchSuggestionsRequestedEventArgs<D>::LinguisticDetails() const
{
    Windows::ApplicationModel::Search::SearchQueryLinguisticDetails value { nullptr };
    check_hresult(WINRT_SHIM(ISearchSuggestionsRequestedEventArgs)->get_LinguisticDetails(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Search::SearchSuggestionsRequest impl_ISearchSuggestionsRequestedEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Search::SearchSuggestionsRequest value { nullptr };
    check_hresult(WINRT_SHIM(ISearchSuggestionsRequestedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> bool impl_ISearchSuggestionManager<D>::SearchHistoryEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->get_SearchHistoryEnabled(&value));
    return value;
}

template <typename D> void impl_ISearchSuggestionManager<D>::SearchHistoryEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->put_SearchHistoryEnabled(value));
}

template <typename D> hstring impl_ISearchSuggestionManager<D>::SearchHistoryContext() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->get_SearchHistoryContext(put_abi(value)));
    return value;
}

template <typename D> void impl_ISearchSuggestionManager<D>::SearchHistoryContext(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->put_SearchHistoryContext(get_abi(value)));
}

template <typename D> void impl_ISearchSuggestionManager<D>::SetLocalContentSuggestionSettings(const Windows::ApplicationModel::Search::LocalContentSuggestionSettings & settings) const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->abi_SetLocalContentSuggestionSettings(get_abi(settings)));
}

template <typename D> void impl_ISearchSuggestionManager<D>::SetQuery(hstring_view queryText) const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->abi_SetQuery(get_abi(queryText)));
}

template <typename D> void impl_ISearchSuggestionManager<D>::SetQuery(hstring_view queryText, hstring_view language) const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->abi_SetQueryWithLanguage(get_abi(queryText), get_abi(language)));
}

template <typename D> void impl_ISearchSuggestionManager<D>::SetQuery(hstring_view queryText, hstring_view language, const Windows::ApplicationModel::Search::SearchQueryLinguisticDetails & linguisticDetails) const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->abi_SetQueryWithSearchQueryLinguisticDetails(get_abi(queryText), get_abi(language), get_abi(linguisticDetails)));
}

template <typename D> Windows::Foundation::Collections::IObservableVector<Windows::ApplicationModel::Search::Core::SearchSuggestion> impl_ISearchSuggestionManager<D>::Suggestions() const
{
    Windows::Foundation::Collections::IObservableVector<Windows::ApplicationModel::Search::Core::SearchSuggestion> value;
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->get_Suggestions(put_abi(value)));
    return value;
}

template <typename D> void impl_ISearchSuggestionManager<D>::AddToHistory(hstring_view queryText) const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->abi_AddToHistory(get_abi(queryText)));
}

template <typename D> void impl_ISearchSuggestionManager<D>::AddToHistory(hstring_view queryText, hstring_view language) const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->abi_AddToHistoryWithLanguage(get_abi(queryText), get_abi(language)));
}

template <typename D> void impl_ISearchSuggestionManager<D>::ClearHistory() const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->abi_ClearHistory());
}

template <typename D> event_token impl_ISearchSuggestionManager<D>::SuggestionsRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::Core::SearchSuggestionManager, Windows::ApplicationModel::Search::Core::SearchSuggestionsRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->add_SuggestionsRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISearchSuggestionManager> impl_ISearchSuggestionManager<D>::SuggestionsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::Core::SearchSuggestionManager, Windows::ApplicationModel::Search::Core::SearchSuggestionsRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISearchSuggestionManager>(this, &ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager::remove_SuggestionsRequested, SuggestionsRequested(handler));
}

template <typename D> void impl_ISearchSuggestionManager<D>::SuggestionsRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->remove_SuggestionsRequested(token));
}

template <typename D> event_token impl_ISearchSuggestionManager<D>::RequestingFocusOnKeyboardInput(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::Core::SearchSuggestionManager, Windows::ApplicationModel::Search::Core::RequestingFocusOnKeyboardInputEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->add_RequestingFocusOnKeyboardInput(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISearchSuggestionManager> impl_ISearchSuggestionManager<D>::RequestingFocusOnKeyboardInput(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::Core::SearchSuggestionManager, Windows::ApplicationModel::Search::Core::RequestingFocusOnKeyboardInputEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISearchSuggestionManager>(this, &ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager::remove_RequestingFocusOnKeyboardInput, RequestingFocusOnKeyboardInput(handler));
}

template <typename D> void impl_ISearchSuggestionManager<D>::RequestingFocusOnKeyboardInput(event_token token) const
{
    check_hresult(WINRT_SHIM(ISearchSuggestionManager)->remove_RequestingFocusOnKeyboardInput(token));
}

inline SearchSuggestionManager::SearchSuggestionManager() :
    SearchSuggestionManager(activate_instance<SearchSuggestionManager>())
{}

}

}
#pragma warning(pop)
