// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Search.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Storage.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Search {

struct __declspec(uuid("eeaeb062-743d-456e-84a3-23f06f2d15d7")) __declspec(novtable) ILocalContentSuggestionSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Enabled(bool value) = 0;
    virtual HRESULT __stdcall get_Enabled(bool * value) = 0;
    virtual HRESULT __stdcall get_Locations(Windows::Foundation::Collections::IVector<Windows::Storage::StorageFolder> ** value) = 0;
    virtual HRESULT __stdcall put_AqsFilter(hstring value) = 0;
    virtual HRESULT __stdcall get_AqsFilter(hstring * value) = 0;
    virtual HRESULT __stdcall get_PropertiesToMatch(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
};

struct __declspec(uuid("fdacec38-3700-4d73-91a1-2f998674238a")) __declspec(novtable) ISearchPane : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_SearchHistoryEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_SearchHistoryEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_SearchHistoryContext(hstring value) = 0;
    virtual HRESULT __stdcall get_SearchHistoryContext(hstring * value) = 0;
    virtual HRESULT __stdcall put_PlaceholderText(hstring value) = 0;
    virtual HRESULT __stdcall get_PlaceholderText(hstring * value) = 0;
    virtual HRESULT __stdcall get_QueryText(hstring * value) = 0;
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
    virtual HRESULT __stdcall get_Visible(bool * value) = 0;
    virtual HRESULT __stdcall add_VisibilityChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneVisibilityChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VisibilityChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_QueryChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneQueryChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_QueryChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_SuggestionsRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneSuggestionsRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SuggestionsRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_QuerySubmitted(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneQuerySubmittedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_QuerySubmitted(event_token token) = 0;
    virtual HRESULT __stdcall add_ResultSuggestionChosen(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneResultSuggestionChosenEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ResultSuggestionChosen(event_token token) = 0;
    virtual HRESULT __stdcall abi_SetLocalContentSuggestionSettings(Windows::ApplicationModel::Search::ILocalContentSuggestionSettings * settings) = 0;
    virtual HRESULT __stdcall abi_ShowOverloadDefault() = 0;
    virtual HRESULT __stdcall abi_ShowOverloadWithQuery(hstring query) = 0;
    virtual HRESULT __stdcall put_ShowOnKeyboardInput(bool value) = 0;
    virtual HRESULT __stdcall get_ShowOnKeyboardInput(bool * value) = 0;
    virtual HRESULT __stdcall abi_TrySetQueryText(hstring query, bool * succeeded) = 0;
};

struct __declspec(uuid("3c064fe9-2351-4248-a529-7110f464a785")) __declspec(novtable) ISearchPaneQueryChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_QueryText(hstring * value) = 0;
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
    virtual HRESULT __stdcall get_LinguisticDetails(Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails ** value) = 0;
};

struct __declspec(uuid("82fb460e-0940-4b6d-b8d0-642b30989e15")) __declspec(novtable) ISearchPaneQueryLinguisticDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_QueryTextAlternatives(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_QueryTextCompositionStart(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_QueryTextCompositionLength(uint32_t * value) = 0;
};

struct __declspec(uuid("143ba4fc-e9c5-4736-91b2-e8eb9cb88356")) __declspec(novtable) ISearchPaneQuerySubmittedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_QueryText(hstring * value) = 0;
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
};

struct __declspec(uuid("460c92e5-4c32-4538-a4d4-b6b4400d140f")) __declspec(novtable) ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LinguisticDetails(Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails ** value) = 0;
};

struct __declspec(uuid("c8316cc0-aed2-41e0-bce0-c26ca74f85ec")) __declspec(novtable) ISearchPaneResultSuggestionChosenEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Tag(hstring * value) = 0;
};

struct __declspec(uuid("9572adf1-8f1d-481f-a15b-c61655f16a0e")) __declspec(novtable) ISearchPaneStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::ApplicationModel::Search::ISearchPane ** searchPane) = 0;
};

struct __declspec(uuid("00732830-50f1-4d03-99ac-c6644c8ed8b5")) __declspec(novtable) ISearchPaneStaticsWithHideThisApplication : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_HideThisApplication() = 0;
};

struct __declspec(uuid("81b10b1c-e561-4093-9b4d-2ad482794a53")) __declspec(novtable) ISearchPaneSuggestionsRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsCanceled(bool * value) = 0;
    virtual HRESULT __stdcall get_SearchSuggestionCollection(Windows::ApplicationModel::Search::ISearchSuggestionCollection ** collection) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequestDeferral ** deferral) = 0;
};

struct __declspec(uuid("a0d009f7-8748-4ee2-ad44-afa6be997c51")) __declspec(novtable) ISearchPaneSuggestionsRequestDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("c89b8a2f-ac56-4460-8d2f-80023bec4fc5")) __declspec(novtable) ISearchPaneSuggestionsRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequest ** value) = 0;
};

struct __declspec(uuid("3c4d3046-ac4b-49f2-97d6-020e6182cb9c")) __declspec(novtable) ISearchPaneVisibilityChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Visible(bool * value) = 0;
};

struct __declspec(uuid("46a1205b-69c9-4745-b72f-a8a4fc8f24ae")) __declspec(novtable) ISearchQueryLinguisticDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_QueryTextAlternatives(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_QueryTextCompositionStart(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_QueryTextCompositionLength(uint32_t * value) = 0;
};

struct __declspec(uuid("cac6c3b8-3c64-4dfd-ad9f-479e4d4065a4")) __declspec(novtable) ISearchQueryLinguisticDetailsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::Collections::IIterable<hstring> * queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength, Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails ** value) = 0;
};

struct __declspec(uuid("323a8a4b-fbea-4446-abbc-3da7915fdd3a")) __declspec(novtable) ISearchSuggestionCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Size(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_AppendQuerySuggestion(hstring text) = 0;
    virtual HRESULT __stdcall abi_AppendQuerySuggestions(Windows::Foundation::Collections::IIterable<hstring> * suggestions) = 0;
    virtual HRESULT __stdcall abi_AppendResultSuggestion(hstring text, hstring detailText, hstring tag, Windows::Storage::Streams::IRandomAccessStreamReference * image, hstring imageAlternateText) = 0;
    virtual HRESULT __stdcall abi_AppendSearchSeparator(hstring label) = 0;
};

struct __declspec(uuid("4e4e26a7-44e5-4039-9099-6000ead1f0c6")) __declspec(novtable) ISearchSuggestionsRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsCanceled(bool * value) = 0;
    virtual HRESULT __stdcall get_SearchSuggestionCollection(Windows::ApplicationModel::Search::ISearchSuggestionCollection ** collection) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral ** deferral) = 0;
};

struct __declspec(uuid("b71598a9-c065-456d-a845-1eccec5dc28b")) __declspec(novtable) ISearchSuggestionsRequestDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Search::LocalContentSuggestionSettings> { using default_interface = Windows::ApplicationModel::Search::ILocalContentSuggestionSettings; };
template <> struct traits<Windows::ApplicationModel::Search::SearchPane> { using default_interface = Windows::ApplicationModel::Search::ISearchPane; };
template <> struct traits<Windows::ApplicationModel::Search::SearchPaneQueryChangedEventArgs> { using default_interface = Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Search::SearchPaneQueryLinguisticDetails> { using default_interface = Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails; };
template <> struct traits<Windows::ApplicationModel::Search::SearchPaneQuerySubmittedEventArgs> { using default_interface = Windows::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Search::SearchPaneResultSuggestionChosenEventArgs> { using default_interface = Windows::ApplicationModel::Search::ISearchPaneResultSuggestionChosenEventArgs; };
template <> struct traits<Windows::ApplicationModel::Search::SearchPaneSuggestionsRequest> { using default_interface = Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequest; };
template <> struct traits<Windows::ApplicationModel::Search::SearchPaneSuggestionsRequestDeferral> { using default_interface = Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequestDeferral; };
template <> struct traits<Windows::ApplicationModel::Search::SearchPaneSuggestionsRequestedEventArgs> { using default_interface = Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequestedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Search::SearchPaneVisibilityChangedEventArgs> { using default_interface = Windows::ApplicationModel::Search::ISearchPaneVisibilityChangedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Search::SearchQueryLinguisticDetails> { using default_interface = Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails; };
template <> struct traits<Windows::ApplicationModel::Search::SearchSuggestionCollection> { using default_interface = Windows::ApplicationModel::Search::ISearchSuggestionCollection; };
template <> struct traits<Windows::ApplicationModel::Search::SearchSuggestionsRequest> { using default_interface = Windows::ApplicationModel::Search::ISearchSuggestionsRequest; };
template <> struct traits<Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral> { using default_interface = Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral; };

}

namespace Windows::ApplicationModel::Search {

template <typename D>
struct WINRT_EBO impl_ILocalContentSuggestionSettings
{
    void Enabled(bool value) const;
    bool Enabled() const;
    Windows::Foundation::Collections::IVector<Windows::Storage::StorageFolder> Locations() const;
    void AqsFilter(hstring_view value) const;
    hstring AqsFilter() const;
    Windows::Foundation::Collections::IVector<hstring> PropertiesToMatch() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchPane
{
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] void SearchHistoryEnabled(bool value) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] bool SearchHistoryEnabled() const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] void SearchHistoryContext(hstring_view value) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] hstring SearchHistoryContext() const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] void PlaceholderText(hstring_view value) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] hstring PlaceholderText() const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] hstring QueryText() const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] hstring Language() const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] bool Visible() const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] event_token VisibilityChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneVisibilityChangedEventArgs> & handler) const;
    using VisibilityChanged_revoker = event_revoker<ISearchPane>;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] VisibilityChanged_revoker VisibilityChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneVisibilityChangedEventArgs> & handler) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] void VisibilityChanged(event_token token) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] event_token QueryChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneQueryChangedEventArgs> & handler) const;
    using QueryChanged_revoker = event_revoker<ISearchPane>;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] QueryChanged_revoker QueryChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneQueryChangedEventArgs> & handler) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] void QueryChanged(event_token token) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] event_token SuggestionsRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneSuggestionsRequestedEventArgs> & handler) const;
    using SuggestionsRequested_revoker = event_revoker<ISearchPane>;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] SuggestionsRequested_revoker SuggestionsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneSuggestionsRequestedEventArgs> & handler) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] void SuggestionsRequested(event_token token) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] event_token QuerySubmitted(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneQuerySubmittedEventArgs> & handler) const;
    using QuerySubmitted_revoker = event_revoker<ISearchPane>;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] QuerySubmitted_revoker QuerySubmitted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneQuerySubmittedEventArgs> & handler) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] void QuerySubmitted(event_token token) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] event_token ResultSuggestionChosen(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneResultSuggestionChosenEventArgs> & handler) const;
    using ResultSuggestionChosen_revoker = event_revoker<ISearchPane>;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] ResultSuggestionChosen_revoker ResultSuggestionChosen(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Search::SearchPane, Windows::ApplicationModel::Search::SearchPaneResultSuggestionChosenEventArgs> & handler) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] void ResultSuggestionChosen(event_token token) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] void SetLocalContentSuggestionSettings(const Windows::ApplicationModel::Search::LocalContentSuggestionSettings & settings) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] void Show() const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] void Show(hstring_view query) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] void ShowOnKeyboardInput(bool value) const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] bool ShowOnKeyboardInput() const;
    [[deprecated("ISearchPane may be altered or unavailable for releases after Windows 10.")]] bool TrySetQueryText(hstring_view query) const;
};

template <typename D>
struct WINRT_EBO impl_ISearchPaneQueryChangedEventArgs
{
    [[deprecated("ISearchPaneQueryChangedEventArgs may be altered or unavailable for releases after Windows 10.")]] hstring QueryText() const;
    [[deprecated("ISearchPaneQueryChangedEventArgs may be altered or unavailable for releases after Windows 10.")]] hstring Language() const;
    [[deprecated("ISearchPaneQueryChangedEventArgs may be altered or unavailable for releases after Windows 10.")]] Windows::ApplicationModel::Search::SearchPaneQueryLinguisticDetails LinguisticDetails() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchPaneQueryLinguisticDetails
{
    Windows::Foundation::Collections::IVectorView<hstring> QueryTextAlternatives() const;
    uint32_t QueryTextCompositionStart() const;
    uint32_t QueryTextCompositionLength() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchPaneQuerySubmittedEventArgs
{
    [[deprecated("ISearchPaneQuerySubmittedEventArgs may be altered or unavailable for releases after Windows 10.")]] hstring QueryText() const;
    [[deprecated("ISearchPaneQuerySubmittedEventArgs may be altered or unavailable for releases after Windows 10.")]] hstring Language() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails
{
    [[deprecated("ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails may be altered or unavailable for releases after Windows 10.")]] Windows::ApplicationModel::Search::SearchPaneQueryLinguisticDetails LinguisticDetails() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchPaneResultSuggestionChosenEventArgs
{
    [[deprecated("ISearchPaneResultSuggestionChosenEventArgs may be altered or unavailable for releases after Windows 10.")]] hstring Tag() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchPaneStatics
{
    [[deprecated("ISearchPaneStatics may be altered or unavailable for releases after Windows 10.")]] Windows::ApplicationModel::Search::SearchPane GetForCurrentView() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchPaneStaticsWithHideThisApplication
{
    [[deprecated("ISearchPaneStaticsWithHideThisApplication may be altered or unavailable for releases after Windows 10.")]] void HideThisApplication() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchPaneSuggestionsRequest
{
    [[deprecated("ISearchPaneSuggestionsRequest may be altered or unavailable for releases after Windows 10.")]] bool IsCanceled() const;
    [[deprecated("ISearchPaneSuggestionsRequest may be altered or unavailable for releases after Windows 10.")]] Windows::ApplicationModel::Search::SearchSuggestionCollection SearchSuggestionCollection() const;
    [[deprecated("ISearchPaneSuggestionsRequest may be altered or unavailable for releases after Windows 10.")]] Windows::ApplicationModel::Search::SearchPaneSuggestionsRequestDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchPaneSuggestionsRequestDeferral
{
    [[deprecated("ISearchPaneSuggestionsRequestDeferral may be altered or unavailable for releases after Windows 10.")]] void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchPaneSuggestionsRequestedEventArgs
{
    [[deprecated("ISearchPaneSuggestionsRequestedEventArgs may be altered or unavailable for releases after Windows 10.")]] Windows::ApplicationModel::Search::SearchPaneSuggestionsRequest Request() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchPaneVisibilityChangedEventArgs
{
    [[deprecated("ISearchPaneVisibilityChangedEventArgs may be altered or unavailable for releases after Windows 10.")]] bool Visible() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchQueryLinguisticDetails
{
    Windows::Foundation::Collections::IVectorView<hstring> QueryTextAlternatives() const;
    uint32_t QueryTextCompositionStart() const;
    uint32_t QueryTextCompositionLength() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchQueryLinguisticDetailsFactory
{
    Windows::ApplicationModel::Search::SearchQueryLinguisticDetails CreateInstance(iterable<hstring> queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength) const;
};

template <typename D>
struct WINRT_EBO impl_ISearchSuggestionCollection
{
    uint32_t Size() const;
    void AppendQuerySuggestion(hstring_view text) const;
    void AppendQuerySuggestions(iterable<hstring> suggestions) const;
    void AppendResultSuggestion(hstring_view text, hstring_view detailText, hstring_view tag, const Windows::Storage::Streams::IRandomAccessStreamReference & image, hstring_view imageAlternateText) const;
    void AppendSearchSeparator(hstring_view label) const;
};

template <typename D>
struct WINRT_EBO impl_ISearchSuggestionsRequest
{
    bool IsCanceled() const;
    Windows::ApplicationModel::Search::SearchSuggestionCollection SearchSuggestionCollection() const;
    Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchSuggestionsRequestDeferral
{
    void Complete() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Search::ILocalContentSuggestionSettings>
{
    using abi = ABI::Windows::ApplicationModel::Search::ILocalContentSuggestionSettings;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ILocalContentSuggestionSettings<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchPane>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchPane;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchPane<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchPaneQueryChangedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchPaneQueryLinguisticDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchPaneQuerySubmittedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchPaneResultSuggestionChosenEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchPaneResultSuggestionChosenEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchPaneResultSuggestionChosenEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchPaneStatics>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchPaneStatics;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchPaneStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchPaneStaticsWithHideThisApplication>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchPaneStaticsWithHideThisApplication;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchPaneStaticsWithHideThisApplication<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequest>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequest;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchPaneSuggestionsRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequestDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequestDeferral;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchPaneSuggestionsRequestDeferral<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequestedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequestedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchPaneSuggestionsRequestedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchPaneVisibilityChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchPaneVisibilityChangedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchPaneVisibilityChangedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchQueryLinguisticDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchQueryLinguisticDetailsFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchSuggestionCollection>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchSuggestionCollection;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchSuggestionCollection<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchSuggestionsRequest>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchSuggestionsRequest;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchSuggestionsRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral;
    template <typename D> using consume = Windows::ApplicationModel::Search::impl_ISearchSuggestionsRequestDeferral<D>;
};

template <> struct traits<Windows::ApplicationModel::Search::LocalContentSuggestionSettings>
{
    using abi = ABI::Windows::ApplicationModel::Search::LocalContentSuggestionSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.LocalContentSuggestionSettings"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchPane>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchPane;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchPane"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchPaneQueryChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchPaneQueryChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchPaneQueryChangedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchPaneQueryLinguisticDetails>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchPaneQueryLinguisticDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchPaneQueryLinguisticDetails"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchPaneQuerySubmittedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchPaneQuerySubmittedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchPaneQuerySubmittedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchPaneResultSuggestionChosenEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchPaneResultSuggestionChosenEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchPaneResultSuggestionChosenEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchPaneSuggestionsRequest>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchPaneSuggestionsRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchPaneSuggestionsRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchPaneSuggestionsRequestDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchPaneSuggestionsRequestDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchPaneSuggestionsRequestDeferral"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchPaneSuggestionsRequestedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchPaneSuggestionsRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchPaneSuggestionsRequestedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchPaneVisibilityChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchPaneVisibilityChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchPaneVisibilityChangedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchQueryLinguisticDetails>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchQueryLinguisticDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchQueryLinguisticDetails"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchSuggestionCollection>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchSuggestionCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchSuggestionCollection"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchSuggestionsRequest>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchSuggestionsRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchSuggestionsRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Search::SearchSuggestionsRequestDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Search.SearchSuggestionsRequestDeferral"; }
};

}

}
