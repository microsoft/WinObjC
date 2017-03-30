// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Graphics.Printing3D.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Graphics::Printing3D {

template <typename H> struct impl_Print3DTaskSourceRequestedHandler : implements<impl_Print3DTaskSourceRequestedHandler<H>, abi<Print3DTaskSourceRequestedHandler>>, H
{
    impl_Print3DTaskSourceRequestedHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrint3DTaskSourceRequestedArgs> args) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Graphics::Printing3D::Print3DTaskSourceRequestedArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Graphics::Printing3D {

struct WINRT_EBO Print3DManager :
    Windows::Graphics::Printing3D::IPrint3DManager
{
    Print3DManager(std::nullptr_t) noexcept {}
    static Windows::Graphics::Printing3D::Print3DManager GetForCurrentView();
    static Windows::Foundation::IAsyncOperation<bool> ShowPrintUIAsync();
};

struct WINRT_EBO Print3DTask :
    Windows::Graphics::Printing3D::IPrint3DTask
{
    Print3DTask(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Print3DTaskCompletedEventArgs :
    Windows::Graphics::Printing3D::IPrint3DTaskCompletedEventArgs
{
    Print3DTaskCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Print3DTaskRequest :
    Windows::Graphics::Printing3D::IPrint3DTaskRequest
{
    Print3DTaskRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Print3DTaskRequestedEventArgs :
    Windows::Graphics::Printing3D::IPrint3DTaskRequestedEventArgs
{
    Print3DTaskRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Print3DTaskSourceChangedEventArgs :
    Windows::Graphics::Printing3D::IPrint3DTaskSourceChangedEventArgs
{
    Print3DTaskSourceChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Print3DTaskSourceRequestedArgs :
    Windows::Graphics::Printing3D::IPrint3DTaskSourceRequestedArgs
{
    Print3DTaskSourceRequestedArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Printing3D3MFPackage :
    Windows::Graphics::Printing3D::IPrinting3D3MFPackage
{
    Printing3D3MFPackage(std::nullptr_t) noexcept {}
    Printing3D3MFPackage();
    static Windows::Foundation::IAsyncOperation<Windows::Graphics::Printing3D::Printing3D3MFPackage> LoadAsync(const Windows::Storage::Streams::IRandomAccessStream & value);
};

struct WINRT_EBO Printing3DBaseMaterial :
    Windows::Graphics::Printing3D::IPrinting3DBaseMaterial
{
    Printing3DBaseMaterial(std::nullptr_t) noexcept {}
    Printing3DBaseMaterial();
    static hstring Abs();
    static hstring Pla();
};

struct WINRT_EBO Printing3DBaseMaterialGroup :
    Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroup
{
    Printing3DBaseMaterialGroup(std::nullptr_t) noexcept {}
    Printing3DBaseMaterialGroup(uint32_t MaterialGroupId);
};

struct WINRT_EBO Printing3DColorMaterial :
    Windows::Graphics::Printing3D::IPrinting3DColorMaterial,
    impl::require<Printing3DColorMaterial, Windows::Graphics::Printing3D::IPrinting3DColorMaterial2>
{
    Printing3DColorMaterial(std::nullptr_t) noexcept {}
    Printing3DColorMaterial();
};

struct WINRT_EBO Printing3DColorMaterialGroup :
    Windows::Graphics::Printing3D::IPrinting3DColorMaterialGroup
{
    Printing3DColorMaterialGroup(std::nullptr_t) noexcept {}
    Printing3DColorMaterialGroup(uint32_t MaterialGroupId);
};

struct WINRT_EBO Printing3DComponent :
    Windows::Graphics::Printing3D::IPrinting3DComponent
{
    Printing3DComponent(std::nullptr_t) noexcept {}
    Printing3DComponent();
};

struct WINRT_EBO Printing3DComponentWithMatrix :
    Windows::Graphics::Printing3D::IPrinting3DComponentWithMatrix
{
    Printing3DComponentWithMatrix(std::nullptr_t) noexcept {}
    Printing3DComponentWithMatrix();
};

struct WINRT_EBO Printing3DCompositeMaterial :
    Windows::Graphics::Printing3D::IPrinting3DCompositeMaterial
{
    Printing3DCompositeMaterial(std::nullptr_t) noexcept {}
    Printing3DCompositeMaterial();
};

struct WINRT_EBO Printing3DCompositeMaterialGroup :
    Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup,
    impl::require<Printing3DCompositeMaterialGroup, Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup2>
{
    Printing3DCompositeMaterialGroup(std::nullptr_t) noexcept {}
    Printing3DCompositeMaterialGroup(uint32_t MaterialGroupId);
};

struct WINRT_EBO Printing3DFaceReductionOptions :
    Windows::Graphics::Printing3D::IPrinting3DFaceReductionOptions
{
    Printing3DFaceReductionOptions(std::nullptr_t) noexcept {}
    Printing3DFaceReductionOptions();
};

struct WINRT_EBO Printing3DMaterial :
    Windows::Graphics::Printing3D::IPrinting3DMaterial
{
    Printing3DMaterial(std::nullptr_t) noexcept {}
    Printing3DMaterial();
};

struct WINRT_EBO Printing3DMesh :
    Windows::Graphics::Printing3D::IPrinting3DMesh
{
    Printing3DMesh(std::nullptr_t) noexcept {}
    Printing3DMesh();
};

struct WINRT_EBO Printing3DMeshVerificationResult :
    Windows::Graphics::Printing3D::IPrinting3DMeshVerificationResult
{
    Printing3DMeshVerificationResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Printing3DModel :
    Windows::Graphics::Printing3D::IPrinting3DModel,
    impl::require<Printing3DModel, Windows::Graphics::Printing3D::IPrinting3DModel2>
{
    Printing3DModel(std::nullptr_t) noexcept {}
    Printing3DModel();
};

struct WINRT_EBO Printing3DModelTexture :
    Windows::Graphics::Printing3D::IPrinting3DModelTexture
{
    Printing3DModelTexture(std::nullptr_t) noexcept {}
    Printing3DModelTexture();
};

struct WINRT_EBO Printing3DMultiplePropertyMaterial :
    Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterial
{
    Printing3DMultiplePropertyMaterial(std::nullptr_t) noexcept {}
    Printing3DMultiplePropertyMaterial();
};

struct WINRT_EBO Printing3DMultiplePropertyMaterialGroup :
    Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup
{
    Printing3DMultiplePropertyMaterialGroup(std::nullptr_t) noexcept {}
    Printing3DMultiplePropertyMaterialGroup(uint32_t MaterialGroupId);
};

struct WINRT_EBO Printing3DTexture2CoordMaterial :
    Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial
{
    Printing3DTexture2CoordMaterial(std::nullptr_t) noexcept {}
    Printing3DTexture2CoordMaterial();
};

struct WINRT_EBO Printing3DTexture2CoordMaterialGroup :
    Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup,
    impl::require<Printing3DTexture2CoordMaterialGroup, Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup2>
{
    Printing3DTexture2CoordMaterialGroup(std::nullptr_t) noexcept {}
    Printing3DTexture2CoordMaterialGroup(uint32_t MaterialGroupId);
};

struct WINRT_EBO Printing3DTextureResource :
    Windows::Graphics::Printing3D::IPrinting3DTextureResource
{
    Printing3DTextureResource(std::nullptr_t) noexcept {}
    Printing3DTextureResource();
};

}

}
