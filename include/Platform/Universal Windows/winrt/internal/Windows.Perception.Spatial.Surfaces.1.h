// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Perception.Spatial.Surfaces.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Graphics.DirectX.0.h"
#include "Windows.Perception.Spatial.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Graphics.DirectX.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Perception.Spatial.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Perception::Spatial::Surfaces {

struct __declspec(uuid("f8e9ebe7-39b7-3962-bb03-57f56e1fb0a1")) __declspec(novtable) ISpatialSurfaceInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(GUID * value) = 0;
    virtual HRESULT __stdcall get_UpdateTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall abi_TryGetBounds(Windows::Perception::Spatial::ISpatialCoordinateSystem * coordinateSystem, Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingOrientedBox> ** value) = 0;
    virtual HRESULT __stdcall abi_TryComputeLatestMeshAsync(double maxTrianglesPerCubicMeter, Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh> ** value) = 0;
    virtual HRESULT __stdcall abi_TryComputeLatestMeshWithOptionsAsync(double maxTrianglesPerCubicMeter, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions * options, Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh> ** value) = 0;
};

struct __declspec(uuid("108f57d9-df0d-3950-a0fd-f972c77c27b4")) __declspec(novtable) ISpatialSurfaceMesh : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SurfaceInfo(Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo ** value) = 0;
    virtual HRESULT __stdcall get_CoordinateSystem(Windows::Perception::Spatial::ISpatialCoordinateSystem ** value) = 0;
    virtual HRESULT __stdcall get_TriangleIndices(Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer ** value) = 0;
    virtual HRESULT __stdcall get_VertexPositions(Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer ** value) = 0;
    virtual HRESULT __stdcall get_VertexPositionScale(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall get_VertexNormals(Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer ** value) = 0;
};

struct __declspec(uuid("93cf59e0-871f-33f8-98b2-03d101458f6f")) __declspec(novtable) ISpatialSurfaceMeshBuffer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Format(winrt::Windows::Graphics::DirectX::DirectXPixelFormat * value) = 0;
    virtual HRESULT __stdcall get_Stride(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ElementCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Data(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("d2759f89-3572-3d2d-a10d-5fee9394aa37")) __declspec(novtable) ISpatialSurfaceMeshOptions : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_VertexPositionFormat(winrt::Windows::Graphics::DirectX::DirectXPixelFormat * value) = 0;
    virtual HRESULT __stdcall put_VertexPositionFormat(winrt::Windows::Graphics::DirectX::DirectXPixelFormat value) = 0;
    virtual HRESULT __stdcall get_TriangleIndexFormat(winrt::Windows::Graphics::DirectX::DirectXPixelFormat * value) = 0;
    virtual HRESULT __stdcall put_TriangleIndexFormat(winrt::Windows::Graphics::DirectX::DirectXPixelFormat value) = 0;
    virtual HRESULT __stdcall get_VertexNormalFormat(winrt::Windows::Graphics::DirectX::DirectXPixelFormat * value) = 0;
    virtual HRESULT __stdcall put_VertexNormalFormat(winrt::Windows::Graphics::DirectX::DirectXPixelFormat value) = 0;
    virtual HRESULT __stdcall get_IncludeVertexNormals(bool * value) = 0;
    virtual HRESULT __stdcall put_IncludeVertexNormals(bool value) = 0;
};

struct __declspec(uuid("9b340abf-9781-4505-8935-013575caae5e")) __declspec(novtable) ISpatialSurfaceMeshOptionsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SupportedVertexPositionFormats(Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> ** value) = 0;
    virtual HRESULT __stdcall get_SupportedTriangleIndexFormats(Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> ** value) = 0;
    virtual HRESULT __stdcall get_SupportedVertexNormalFormats(Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> ** value) = 0;
};

struct __declspec(uuid("10b69819-ddca-3483-ac3a-748fe8c86df5")) __declspec(novtable) ISpatialSurfaceObserver : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetObservedSurfaces(Windows::Foundation::Collections::IMapView<GUID, Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo> ** value) = 0;
    virtual HRESULT __stdcall abi_SetBoundingVolume(Windows::Perception::Spatial::ISpatialBoundingVolume * bounds) = 0;
    virtual HRESULT __stdcall abi_SetBoundingVolumes(Windows::Foundation::Collections::IIterable<Windows::Perception::Spatial::SpatialBoundingVolume> * bounds) = 0;
    virtual HRESULT __stdcall add_ObservedSurfacesChanged(Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::Surfaces::SpatialSurfaceObserver, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ObservedSurfacesChanged(event_token token) = 0;
};

struct __declspec(uuid("165951ed-2108-4168-9175-87e027bc9285")) __declspec(novtable) ISpatialSurfaceObserverStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus> ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo> { using default_interface = Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo; };
template <> struct traits<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh> { using default_interface = Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMesh; };
template <> struct traits<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer> { using default_interface = Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer; };
template <> struct traits<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshOptions> { using default_interface = Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions; };
template <> struct traits<Windows::Perception::Spatial::Surfaces::SpatialSurfaceObserver> { using default_interface = Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserver; };

}

namespace Windows::Perception::Spatial::Surfaces {

template <typename D>
struct WINRT_EBO impl_ISpatialSurfaceInfo
{
    GUID Id() const;
    Windows::Foundation::DateTime UpdateTime() const;
    Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingOrientedBox> TryGetBounds(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem) const;
    Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh> TryComputeLatestMeshAsync(double maxTrianglesPerCubicMeter) const;
    Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh> TryComputeLatestMeshAsync(double maxTrianglesPerCubicMeter, const Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshOptions & options) const;
};

template <typename D>
struct WINRT_EBO impl_ISpatialSurfaceMesh
{
    Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo SurfaceInfo() const;
    Windows::Perception::Spatial::SpatialCoordinateSystem CoordinateSystem() const;
    Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer TriangleIndices() const;
    Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer VertexPositions() const;
    Windows::Foundation::Numerics::float3 VertexPositionScale() const;
    Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer VertexNormals() const;
};

template <typename D>
struct WINRT_EBO impl_ISpatialSurfaceMeshBuffer
{
    Windows::Graphics::DirectX::DirectXPixelFormat Format() const;
    uint32_t Stride() const;
    uint32_t ElementCount() const;
    Windows::Storage::Streams::IBuffer Data() const;
};

template <typename D>
struct WINRT_EBO impl_ISpatialSurfaceMeshOptions
{
    Windows::Graphics::DirectX::DirectXPixelFormat VertexPositionFormat() const;
    void VertexPositionFormat(Windows::Graphics::DirectX::DirectXPixelFormat value) const;
    Windows::Graphics::DirectX::DirectXPixelFormat TriangleIndexFormat() const;
    void TriangleIndexFormat(Windows::Graphics::DirectX::DirectXPixelFormat value) const;
    Windows::Graphics::DirectX::DirectXPixelFormat VertexNormalFormat() const;
    void VertexNormalFormat(Windows::Graphics::DirectX::DirectXPixelFormat value) const;
    bool IncludeVertexNormals() const;
    void IncludeVertexNormals(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ISpatialSurfaceMeshOptionsStatics
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> SupportedVertexPositionFormats() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> SupportedTriangleIndexFormats() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> SupportedVertexNormalFormats() const;
};

template <typename D>
struct WINRT_EBO impl_ISpatialSurfaceObserver
{
    Windows::Foundation::Collections::IMapView<GUID, Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo> GetObservedSurfaces() const;
    void SetBoundingVolume(const Windows::Perception::Spatial::SpatialBoundingVolume & bounds) const;
    void SetBoundingVolumes(iterable<Windows::Perception::Spatial::SpatialBoundingVolume> bounds) const;
    event_token ObservedSurfacesChanged(const Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::Surfaces::SpatialSurfaceObserver, Windows::Foundation::IInspectable> & handler) const;
    using ObservedSurfacesChanged_revoker = event_revoker<ISpatialSurfaceObserver>;
    ObservedSurfacesChanged_revoker ObservedSurfacesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::Surfaces::SpatialSurfaceObserver, Windows::Foundation::IInspectable> & handler) const;
    void ObservedSurfacesChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ISpatialSurfaceObserverStatics
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus> RequestAccessAsync() const;
};

}

namespace impl {

template <> struct traits<Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo>
{
    using abi = ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo;
    template <typename D> using consume = Windows::Perception::Spatial::Surfaces::impl_ISpatialSurfaceInfo<D>;
};

template <> struct traits<Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMesh>
{
    using abi = ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMesh;
    template <typename D> using consume = Windows::Perception::Spatial::Surfaces::impl_ISpatialSurfaceMesh<D>;
};

template <> struct traits<Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer>
{
    using abi = ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer;
    template <typename D> using consume = Windows::Perception::Spatial::Surfaces::impl_ISpatialSurfaceMeshBuffer<D>;
};

template <> struct traits<Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions>
{
    using abi = ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions;
    template <typename D> using consume = Windows::Perception::Spatial::Surfaces::impl_ISpatialSurfaceMeshOptions<D>;
};

template <> struct traits<Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptionsStatics>
{
    using abi = ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptionsStatics;
    template <typename D> using consume = Windows::Perception::Spatial::Surfaces::impl_ISpatialSurfaceMeshOptionsStatics<D>;
};

template <> struct traits<Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserver>
{
    using abi = ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserver;
    template <typename D> using consume = Windows::Perception::Spatial::Surfaces::impl_ISpatialSurfaceObserver<D>;
};

template <> struct traits<Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics>
{
    using abi = ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics;
    template <typename D> using consume = Windows::Perception::Spatial::Surfaces::impl_ISpatialSurfaceObserverStatics<D>;
};

template <> struct traits<Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo>
{
    using abi = ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Perception.Spatial.Surfaces.SpatialSurfaceInfo"; }
};

template <> struct traits<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh>
{
    using abi = ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Perception.Spatial.Surfaces.SpatialSurfaceMesh"; }
};

template <> struct traits<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer>
{
    using abi = ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Perception.Spatial.Surfaces.SpatialSurfaceMeshBuffer"; }
};

template <> struct traits<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshOptions>
{
    using abi = ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshOptions;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Perception.Spatial.Surfaces.SpatialSurfaceMeshOptions"; }
};

template <> struct traits<Windows::Perception::Spatial::Surfaces::SpatialSurfaceObserver>
{
    using abi = ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceObserver;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Perception.Spatial.Surfaces.SpatialSurfaceObserver"; }
};

}

}
