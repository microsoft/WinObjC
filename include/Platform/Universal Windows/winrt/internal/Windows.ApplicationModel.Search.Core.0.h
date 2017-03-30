// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Search::Core {

struct IRequestingFocusOnKeyboardInputEventArgs;
struct ISearchSuggestion;
struct ISearchSuggestionManager;
struct ISearchSuggestionsRequestedEventArgs;
struct RequestingFocusOnKeyboardInputEventArgs;
struct SearchSuggestion;
struct SearchSuggestionManager;
struct SearchSuggestionsRequestedEventArgs;

}

namespace Windows::ApplicationModel::Search::Core {

struct IRequestingFocusOnKeyboardInputEventArgs;
struct ISearchSuggestion;
struct ISearchSuggestionManager;
struct ISearchSuggestionsRequestedEventArgs;
struct RequestingFocusOnKeyboardInputEventArgs;
struct SearchSuggestion;
struct SearchSuggestionManager;
struct SearchSuggestionsRequestedEventArgs;

}

namespace Windows::ApplicationModel::Search::Core {

template <typename T> struct impl_IRequestingFocusOnKeyboardInputEventArgs;
template <typename T> struct impl_ISearchSuggestion;
template <typename T> struct impl_ISearchSuggestionManager;
template <typename T> struct impl_ISearchSuggestionsRequestedEventArgs;

}

namespace Windows::ApplicationModel::Search::Core {

enum class SearchSuggestionKind
{
    Query = 0,
    Result = 1,
    Separator = 2,
};

}

}
