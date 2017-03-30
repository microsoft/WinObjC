// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Input.Inking.Core.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Input::Inking::Core {

struct WINRT_EBO CoreInkIndependentInputSource :
    Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource
{
    CoreInkIndependentInputSource(std::nullptr_t) noexcept {}
    static Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource Create(const Windows::UI::Input::Inking::InkPresenter & inkPresenter);
};

struct WINRT_EBO CoreWetStrokeUpdateEventArgs :
    Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs
{
    CoreWetStrokeUpdateEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreWetStrokeUpdateSource :
    Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource
{
    CoreWetStrokeUpdateSource(std::nullptr_t) noexcept {}
    static Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource Create(const Windows::UI::Input::Inking::InkPresenter & inkPresenter);
};

}

}
