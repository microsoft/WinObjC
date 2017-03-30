// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Search.Core.0.h"
#include "Windows.ApplicationModel.Search.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Search::Core {

struct __declspec(uuid("a1195f27-b1a7-41a2-879d-6a68687e5985")) __declspec(novtable) IRequestingFocusOnKeyboardInputEventArgs : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("5b5554b0-1527-437b-95c5-8d18d2b8af55")) __declspec(novtable) ISearchSuggestion : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Kind(winrt::Windows::ApplicationModel::Search::Core::SearchSuggestionKind * value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall get_Tag(hstring * value) = 0;
    virtual HRESULT __stdcall get_DetailText(hstring * value) = 0;
    virtual HRESULT __stdcall get_Image(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall get_ImageAlternateText(hstring * value) = 0;
};

struct __declspec(uuid("3f0c50a1-cb9d-497b-b500-3c04ac959ad2")) __declspec(novtable) ISearchSuggestionManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SearchHistoryEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_SearchHistoryEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_SearchHistoryContext(hstring * value) = 0;
    virtual HRESULT __stdcall put_SearchHistoryContext(hstring value) = 0;
    virtual HRESULT __stdcall abi_SetLocalContentSuggestionSettings(Windows::ApplicationModel::Search::ILocalContentSuggestionSettings * settings) = 0;
    virtual HRESULT __stdcall abi_SetQuery(hstring queryText) = 0;
    virtual HRESULT __stdcall abi_SetQueryWithLanguage(hstring queryText, hstring language) = 0;
    virtual HRESULT __stdcall abi_SetQueryWithSearchQueryLinguisticDetails(hstring queryText, hstring language, Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails * linguisticDetails) = 0;
    virtual HRESULT __stdcall get_Suggestions(Windows::Foundation::Collections::IObservableVector<Windows::ApplicationModel::Search::Core::SearchSuggestion> ** value) = 0;
    virtual HRESULT __stdcall abi_AddToHistory(hstring queryText) = 0;
    virtual HRESULT __stdcall abi_AddToHistoryWithLanguage(hstring queryText, hstring language) = 0;
    virtual HRESULT __stdcall abi_ClearHistory() = 0;
    virtual HRESULT __stdcall add_SuggestionsRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::Core::SearchSuggestionManager, Windows::ApplicationModel::Search::Core::SearchSuggestionsRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SuggestionsRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_RequestingFocusOnKeyboardInput(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::Core::SearchSuggestionManager, Windows::ApplicationModel::Search::Core::RequestingFocusOnKeyboardInputEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RequestingFocusOnKeyboardInput(event_token token) = 0;
};

struct __declspec(uuid("6fd519e5-9e7e-4ab4-8be3-c76b1bd4344a")) __declspec(novtable) ISearchSuggestionsRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_QueryText(hstring * value) = 0;
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
    virtual HRESULT __stdcall get_LinguisticDetails(Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails ** value) = 0;
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Search::ISearchSuggestionsRequest ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Search::Core::RequestingFocusOnKeyboardInputEventArgs> { using default_interface = Windows::ApplicationModel::Search::Core::IRequestingFocusOnKeyboardInputEventArgs; };
template <> struct traits<Windows::ApplicationModel::Search::Core::SearchSuggestion> { using default_interface = Windows::ApplicationModel::Search::Core::ISearchSuggestion; };
template <> struct traits<Windows::ApplicationModel::Search::Core::SearchSuggestionManager> { using default_interface = Windows::ApplicationModel::Search::Core::ISearchSuggestionManager; };
template <> struct traits<Windows::ApplicationModel::Search::Core::SearchSuggestionsRequestedEventArgs> { using default_interface = Windows::ApplicationModel::Search::Core::ISearchSuggestionsRequestedEventArgs; };

}

namespace Windows::ApplicationModel::Search::Core {

template <typename D>
struct WINRT_EBO impl_IRequestingFocusOnKeyboardInputEventArgs
{
};

template <typename D>
struct WINRT_EBO impl_ISearchSuggestion
{
    Windows::ApplicationModel::Search::Core::SearchSuggestionKind Kind() const;
    hstring Text() const;
    hstring Tag() const;
    hstring DetailText() const;
    Windows::Storage::Streams::IRandomAccessStreamReference Image() const;
    hstring ImageAlternateText() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchSuggestionManager
{
    bool SearchHistoryEnabled() const;
    void SearchHistoryEnabled(bool value) const;
    hstring SearchHistoryContext() const;
    void SearchHistoryContext(hstring_view value) const;
    void SetLocalContentSuggestionSettings(const Windows::ApplicationModel::Search::LocalContentSuggestionSettings & settings) const;
    void SetQuery(hstring_view queryText) const;
    void SetQuery(hstring_view queryText, hstring_view language) const;
    void SetQuery(hstring_view queryText, hstring_view language, const Windows::ApplicationModel::Search::SearchQueryLinguisticDetails & linguisticDetails) const;
    Windows::Foundation::Collections::IObservableVector<Windows::ApplicationModel::Search::Core::SearchSuggestion> Suggestions() const;
    void AddToHistory(hstring_view queryText) const;
    void AddToHistory(hstring_view queryText, hstring_view language) const;
    void ClearHistory() const;
    event_token SuggestionsRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::Core::SearchSuggestionManager, Windows::ApplicationModel::Search::Core::SearchSuggestionsRequestedEventArgs> & handler) const;
    using SuggestionsRequested_revoker = event_revoker<ISearchSuggestionManager>;
    SuggestionsRequested_revoker SuggestionsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::Core::SearchSuggestionManager, Windows::ApplicationModel::Search::Core::SearchSuggestionsRequestedEventArgs> & handler) const;
    void SuggestionsRequested(event_token token) const;
    event_token RequestingFocusOnKeyboardInput(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::Core::SearchSuggestionManager, Windows::ApplicationModel::Search::Core::RequestingFocusOnKeyboardInputEventArgs> & handler) const;
    using RequestingFocusOnKeyboardInput_revoker = event_revoker<ISearchSuggestionManager>;
    RequestingFocusOnKeyboardInput_revoker RequestingFocusOnKeyboardInput(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::Core::SearchSuggestionManager, Windows::ApplicationModel::Search::Core::RequestingFocusOnKeyboardInputEventArgs> & handler) const;
    void RequestingFocusOnKeyboardInput(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ISearchSuggestionsRequestedEventArgs
{
    hstring QueryText() const;
    hstring Language() const;
    Windows::ApplicationModel::Search::SearchQueryLinguisticDetails LinguisticDetails() const;
    Windows::ApplicationModel::Search::SearchSuggestionsRequest Request() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Search::Core::IRequestingFocusOnKeyboardInputEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Search::Core::IRequestingFocusOnKeyboardInputEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Search::Core::impl_IRequestingFocusOnKeyboardInputEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::Core::ISearchSuggestion>
{
    using abi = ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestion;
    template <typename D> using consume = Windows::ApplicationModel::Search::Core::impl_ISearchSuggestion<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>
{
    using abi = ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager;
    template <typename D> using consume = Windows::ApplicationModel::Search::Core::impl_ISearchSuggestionManager<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::Core::ISearchSuggestionsRequestedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionsRequestedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Search::Core::impl_ISearchSuggestionsRequestedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::Core::RequestingFocusOnKeyboardInputEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Search::Core::RequestingFocusOnKeyboardInputEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.Core.RequestingFocusOnKeyboardInputEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Search::Core::SearchSuggestion>
{
    using abi = ABI::Windows::ApplicationModel::Search::Core::SearchSuggestion;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.Core.SearchSuggestion"; }
};

template <> struct traits<Windows::ApplicationModel::Search::Core::SearchSuggestionManager>
{
    using abi = ABI::Windows::ApplicationModel::Search::Core::SearchSuggestionManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.Core.SearchSuggestionManager"; }
};

template <> struct traits<Windows::ApplicationModel::Search::Core::SearchSuggestionsRequestedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Search::Core::SearchSuggestionsRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.Core.SearchSuggestionsRequestedEventArgs"; }
};

}

}
