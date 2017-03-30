// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Graphics.DirectX.Direct3D11.0.h"
#include "Windows.Graphics.DirectX.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Graphics::DirectX::Direct3D11 {

struct Direct3DMultisampleDescription
{
    int32_t Count;
    int32_t Quality;
};

struct Direct3DSurfaceDescription
{
    int32_t Width;
    int32_t Height;
    winrt::Windows::Graphics::DirectX::DirectXPixelFormat Format;
    Windows::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription MultisampleDescription;
};

}

namespace Windows::Graphics::DirectX::Direct3D11 {

using Direct3DMultisampleDescription = ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription;
using Direct3DSurfaceDescription = ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription;

}

namespace ABI::Windows::Graphics::DirectX::Direct3D11 {

struct __declspec(uuid("a37624ab-8d5f-4650-9d3e-9eae3d9bc670")) __declspec(novtable) IDirect3DDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Trim() = 0;
};

struct __declspec(uuid("0bf4a146-13c1-4694-bee3-7abf15eaf586")) __declspec(novtable) IDirect3DSurface : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Description(Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription * value) = 0;
};

}

namespace ABI {


}

namespace Windows::Graphics::DirectX::Direct3D11 {

template <typename D>
struct WINRT_EBO impl_IDirect3DDevice
{
    void Trim() const;
};

template <typename D>
struct WINRT_EBO impl_IDirect3DSurface
{
    Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription Description() const;
};

}

namespace impl {

template <> struct traits<Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice>
{
    using abi = ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice;
    template <typename D> using consume = Windows::Graphics::DirectX::Direct3D11::impl_IDirect3DDevice<D>;
};

template <> struct traits<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface>
{
    using abi = ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface;
    template <typename D> using consume = Windows::Graphics::DirectX::Direct3D11::impl_IDirect3DSurface<D>;
};

}

}
