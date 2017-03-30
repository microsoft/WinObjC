// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Graphics.Effects.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Graphics::Effects {

struct __declspec(uuid("cb51c0ce-8fe6-4636-b202-861faa07d8f3")) __declspec(novtable) IGraphicsEffect : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * name) = 0;
    virtual HRESULT __stdcall put_Name(hstring name) = 0;
};

struct __declspec(uuid("2d8f9ddc-4339-4eb9-9216-f9deb75658a2")) __declspec(novtable) IGraphicsEffectSource : Windows::Foundation::IInspectable
{
};

}

namespace ABI {


}

namespace Windows::Graphics::Effects {

template <typename D>
struct WINRT_EBO impl_IGraphicsEffect
{
    hstring Name() const;
    void Name(hstring_view name) const;
};

template <typename D>
struct WINRT_EBO impl_IGraphicsEffectSource
{
};

}

namespace impl {

template <> struct traits<Windows::Graphics::Effects::IGraphicsEffect>
{
    using abi = ABI::Windows::Graphics::Effects::IGraphicsEffect;
    template <typename D> using consume = Windows::Graphics::Effects::impl_IGraphicsEffect<D>;
};

template <> struct traits<Windows::Graphics::Effects::IGraphicsEffectSource>
{
    using abi = ABI::Windows::Graphics::Effects::IGraphicsEffectSource;
    template <typename D> using consume = Windows::Graphics::Effects::impl_IGraphicsEffectSource<D>;
};

}

}
