// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Text.Core.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Text::Core {

struct WINRT_EBO CoreTextCompositionCompletedEventArgs :
    Windows::UI::Text::Core::ICoreTextCompositionCompletedEventArgs
{
    CoreTextCompositionCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreTextCompositionSegment :
    Windows::UI::Text::Core::ICoreTextCompositionSegment
{
    CoreTextCompositionSegment(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreTextCompositionStartedEventArgs :
    Windows::UI::Text::Core::ICoreTextCompositionStartedEventArgs
{
    CoreTextCompositionStartedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreTextEditContext :
    Windows::UI::Text::Core::ICoreTextEditContext,
    impl::require<CoreTextEditContext, Windows::UI::Text::Core::ICoreTextEditContext2>
{
    CoreTextEditContext(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreTextFormatUpdatingEventArgs :
    Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs
{
    CoreTextFormatUpdatingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreTextLayoutBounds :
    Windows::UI::Text::Core::ICoreTextLayoutBounds
{
    CoreTextLayoutBounds(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreTextLayoutRequest :
    Windows::UI::Text::Core::ICoreTextLayoutRequest
{
    CoreTextLayoutRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreTextLayoutRequestedEventArgs :
    Windows::UI::Text::Core::ICoreTextLayoutRequestedEventArgs
{
    CoreTextLayoutRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreTextSelectionRequest :
    Windows::UI::Text::Core::ICoreTextSelectionRequest
{
    CoreTextSelectionRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreTextSelectionRequestedEventArgs :
    Windows::UI::Text::Core::ICoreTextSelectionRequestedEventArgs
{
    CoreTextSelectionRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreTextSelectionUpdatingEventArgs :
    Windows::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs
{
    CoreTextSelectionUpdatingEventArgs(std::nullptr_t) noexcept {}
};

struct CoreTextServicesConstants
{
    CoreTextServicesConstants() = delete;
    static wchar_t HiddenCharacter();
};

struct WINRT_EBO CoreTextServicesManager :
    Windows::UI::Text::Core::ICoreTextServicesManager
{
    CoreTextServicesManager(std::nullptr_t) noexcept {}
    static Windows::UI::Text::Core::CoreTextServicesManager GetForCurrentView();
};

struct WINRT_EBO CoreTextTextRequest :
    Windows::UI::Text::Core::ICoreTextTextRequest
{
    CoreTextTextRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreTextTextRequestedEventArgs :
    Windows::UI::Text::Core::ICoreTextTextRequestedEventArgs
{
    CoreTextTextRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreTextTextUpdatingEventArgs :
    Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs
{
    CoreTextTextUpdatingEventArgs(std::nullptr_t) noexcept {}
};

}

}
