// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Graphics.Effects.3.h"
#include "internal/Windows.UI.Composition.Effects.3.h"
#include "Windows.UI.Composition.h"
#include "Windows.Graphics.Effects.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Composition::Effects::ISceneLightingEffect> : produce_base<D, Windows::UI::Composition::Effects::ISceneLightingEffect>
{
    HRESULT __stdcall get_AmbientAmount(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AmbientAmount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AmbientAmount(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AmbientAmount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DiffuseAmount(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DiffuseAmount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DiffuseAmount(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DiffuseAmount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NormalMapSource(impl::abi_arg_out<Windows::Graphics::Effects::IGraphicsEffectSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NormalMapSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NormalMapSource(impl::abi_arg_in<Windows::Graphics::Effects::IGraphicsEffectSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NormalMapSource(*reinterpret_cast<const Windows::Graphics::Effects::IGraphicsEffectSource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpecularAmount(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpecularAmount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SpecularAmount(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SpecularAmount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpecularShine(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpecularShine());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SpecularShine(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SpecularShine(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Composition::Effects {

template <typename D> float impl_ISceneLightingEffect<D>::AmbientAmount() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISceneLightingEffect)->get_AmbientAmount(&value));
    return value;
}

template <typename D> void impl_ISceneLightingEffect<D>::AmbientAmount(float value) const
{
    check_hresult(WINRT_SHIM(ISceneLightingEffect)->put_AmbientAmount(value));
}

template <typename D> float impl_ISceneLightingEffect<D>::DiffuseAmount() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISceneLightingEffect)->get_DiffuseAmount(&value));
    return value;
}

template <typename D> void impl_ISceneLightingEffect<D>::DiffuseAmount(float value) const
{
    check_hresult(WINRT_SHIM(ISceneLightingEffect)->put_DiffuseAmount(value));
}

template <typename D> Windows::Graphics::Effects::IGraphicsEffectSource impl_ISceneLightingEffect<D>::NormalMapSource() const
{
    Windows::Graphics::Effects::IGraphicsEffectSource value;
    check_hresult(WINRT_SHIM(ISceneLightingEffect)->get_NormalMapSource(put_abi(value)));
    return value;
}

template <typename D> void impl_ISceneLightingEffect<D>::NormalMapSource(const Windows::Graphics::Effects::IGraphicsEffectSource & value) const
{
    check_hresult(WINRT_SHIM(ISceneLightingEffect)->put_NormalMapSource(get_abi(value)));
}

template <typename D> float impl_ISceneLightingEffect<D>::SpecularAmount() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISceneLightingEffect)->get_SpecularAmount(&value));
    return value;
}

template <typename D> void impl_ISceneLightingEffect<D>::SpecularAmount(float value) const
{
    check_hresult(WINRT_SHIM(ISceneLightingEffect)->put_SpecularAmount(value));
}

template <typename D> float impl_ISceneLightingEffect<D>::SpecularShine() const
{
    float value {};
    check_hresult(WINRT_SHIM(ISceneLightingEffect)->get_SpecularShine(&value));
    return value;
}

template <typename D> void impl_ISceneLightingEffect<D>::SpecularShine(float value) const
{
    check_hresult(WINRT_SHIM(ISceneLightingEffect)->put_SpecularShine(value));
}

inline SceneLightingEffect::SceneLightingEffect() :
    SceneLightingEffect(activate_instance<SceneLightingEffect>())
{}

}

}
#pragma warning(pop)
