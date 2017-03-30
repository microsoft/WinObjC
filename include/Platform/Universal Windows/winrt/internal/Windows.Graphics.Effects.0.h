// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Graphics::Effects {

struct IGraphicsEffect;
struct IGraphicsEffectSource;

}

namespace Windows::Graphics::Effects {

struct IGraphicsEffect;
struct IGraphicsEffectSource;

}

namespace Windows::Graphics::Effects {

template <typename T> struct impl_IGraphicsEffect;
template <typename T> struct impl_IGraphicsEffectSource;

}

}
