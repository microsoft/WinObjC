// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Graphics::DirectX::Direct3D11 {

struct Direct3DMultisampleDescription;
struct Direct3DSurfaceDescription;

}

namespace Windows::Graphics::DirectX::Direct3D11 {

using Direct3DMultisampleDescription = ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription;
using Direct3DSurfaceDescription = ABI::Windows::Graphics::DirectX::Direct3D11::Direct3DSurfaceDescription;

}

namespace ABI::Windows::Graphics::DirectX::Direct3D11 {

struct IDirect3DDevice;
struct IDirect3DSurface;

}

namespace Windows::Graphics::DirectX::Direct3D11 {

struct IDirect3DDevice;
struct IDirect3DSurface;

}

namespace Windows::Graphics::DirectX::Direct3D11 {

template <typename T> struct impl_IDirect3DDevice;
template <typename T> struct impl_IDirect3DSurface;

}

namespace Windows::Graphics::DirectX::Direct3D11 {

enum class Direct3DBindings : unsigned
{
    VertexBuffer = 0x1,
    IndexBuffer = 0x2,
    ConstantBuffer = 0x4,
    ShaderResource = 0x8,
    StreamOutput = 0x10,
    RenderTarget = 0x20,
    DepthStencil = 0x40,
    UnorderedAccess = 0x80,
    Decoder = 0x200,
    VideoEncoder = 0x400,
};

DEFINE_ENUM_FLAG_OPERATORS(Direct3DBindings)

enum class Direct3DUsage
{
    Default = 0,
    Immutable = 1,
    Dynamic = 2,
    Staging = 3,
};

}

}
