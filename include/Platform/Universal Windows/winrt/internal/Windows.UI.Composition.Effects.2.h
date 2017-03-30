// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Composition.Effects.1.h"
#include "Windows.Graphics.Effects.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Composition::Effects {

struct ISceneLightingEffect :
    Windows::Foundation::IInspectable,
    impl::consume<ISceneLightingEffect>
{
    ISceneLightingEffect(std::nullptr_t = nullptr) noexcept {}
};

}

}
