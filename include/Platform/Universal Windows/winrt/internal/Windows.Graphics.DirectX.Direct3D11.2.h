// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Graphics.DirectX.Direct3D11.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Graphics.DirectX.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Graphics::DirectX::Direct3D11 {

struct IDirect3DDevice :
    Windows::Foundation::IInspectable,
    impl::consume<IDirect3DDevice>,
    impl::require<IDirect3DDevice, Windows::Foundation::IClosable>
{
    IDirect3DDevice(std::nullptr_t = nullptr) noexcept {}
};

struct IDirect3DSurface :
    Windows::Foundation::IInspectable,
    impl::consume<IDirect3DSurface>,
    impl::require<IDirect3DSurface, Windows::Foundation::IClosable>
{
    IDirect3DSurface(std::nullptr_t = nullptr) noexcept {}
};

}

}
