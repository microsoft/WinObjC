// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Composition.Effects.0.h"
#include "Windows.Graphics.Effects.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Composition::Effects {

struct __declspec(uuid("91bb5e52-95d1-4f8b-9a5a-6408b24b8c6a")) __declspec(novtable) ISceneLightingEffect : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AmbientAmount(float * value) = 0;
    virtual HRESULT __stdcall put_AmbientAmount(float value) = 0;
    virtual HRESULT __stdcall get_DiffuseAmount(float * value) = 0;
    virtual HRESULT __stdcall put_DiffuseAmount(float value) = 0;
    virtual HRESULT __stdcall get_NormalMapSource(Windows::Graphics::Effects::IGraphicsEffectSource ** value) = 0;
    virtual HRESULT __stdcall put_NormalMapSource(Windows::Graphics::Effects::IGraphicsEffectSource * value) = 0;
    virtual HRESULT __stdcall get_SpecularAmount(float * value) = 0;
    virtual HRESULT __stdcall put_SpecularAmount(float value) = 0;
    virtual HRESULT __stdcall get_SpecularShine(float * value) = 0;
    virtual HRESULT __stdcall put_SpecularShine(float value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Composition::Effects::SceneLightingEffect> { using default_interface = Windows::UI::Composition::Effects::ISceneLightingEffect; };

}

namespace Windows::UI::Composition::Effects {

template <typename D>
struct WINRT_EBO impl_ISceneLightingEffect
{
    float AmbientAmount() const;
    void AmbientAmount(float value) const;
    float DiffuseAmount() const;
    void DiffuseAmount(float value) const;
    Windows::Graphics::Effects::IGraphicsEffectSource NormalMapSource() const;
    void NormalMapSource(const Windows::Graphics::Effects::IGraphicsEffectSource & value) const;
    float SpecularAmount() const;
    void SpecularAmount(float value) const;
    float SpecularShine() const;
    void SpecularShine(float value) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Composition::Effects::ISceneLightingEffect>
{
    using abi = ABI::Windows::UI::Composition::Effects::ISceneLightingEffect;
    template <typename D> using consume = Windows::UI::Composition::Effects::impl_ISceneLightingEffect<D>;
};

template <> struct traits<Windows::UI::Composition::Effects::SceneLightingEffect>
{
    using abi = ABI::Windows::UI::Composition::Effects::SceneLightingEffect;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Composition.Effects.SceneLightingEffect"; }
};

}

}
