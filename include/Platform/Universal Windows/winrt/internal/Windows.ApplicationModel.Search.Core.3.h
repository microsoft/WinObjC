// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Search.Core.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Search::Core {

struct WINRT_EBO RequestingFocusOnKeyboardInputEventArgs :
    Windows::ApplicationModel::Search::Core::IRequestingFocusOnKeyboardInputEventArgs
{
    RequestingFocusOnKeyboardInputEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SearchSuggestion :
    Windows::ApplicationModel::Search::Core::ISearchSuggestion
{
    SearchSuggestion(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SearchSuggestionManager :
    Windows::ApplicationModel::Search::Core::ISearchSuggestionManager
{
    SearchSuggestionManager(std::nullptr_t) noexcept {}
    SearchSuggestionManager();
};

struct WINRT_EBO SearchSuggestionsRequestedEventArgs :
    Windows::ApplicationModel::Search::Core::ISearchSuggestionsRequestedEventArgs
{
    SearchSuggestionsRequestedEventArgs(std::nullptr_t) noexcept {}
};

}

}
