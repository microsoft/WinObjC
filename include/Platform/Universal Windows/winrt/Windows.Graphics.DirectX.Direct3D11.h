// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Graphics.DirectX.Direct3D11.3.h"
#include "Windows.Graphics.DirectX.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice> : produce_base<D, Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice>
{
    HRESULT __stdcall abi_Trim() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Trim();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> : produce_base<D, Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface>
{
    HRESULT __stdcall get_Description(impl::abi_arg_out<Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Description());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Graphics::DirectX::Direct3D11 {

template <typename D> void impl_IDirect3DDevice<D>::Trim() const
{
    check_hresult(WINRT_SHIM(IDirect3DDevice)->abi_Trim());
}

template <typename D> Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription impl_IDirect3DSurface<D>::Description() const
{
    Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription value {};
    check_hresult(WINRT_SHIM(IDirect3DSurface)->get_Description(put_abi(value)));
    return value;
}

}

}
#pragma warning(pop)
