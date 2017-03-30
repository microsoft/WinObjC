// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Composition.Effects.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Composition::Effects {

struct WINRT_EBO SceneLightingEffect :
    Windows::UI::Composition::Effects::ISceneLightingEffect,
    impl::require<SceneLightingEffect, Windows::Graphics::Effects::IGraphicsEffectSource, Windows::Graphics::Effects::IGraphicsEffect>
{
    SceneLightingEffect(std::nullptr_t) noexcept {}
    SceneLightingEffect();
};

}

}
