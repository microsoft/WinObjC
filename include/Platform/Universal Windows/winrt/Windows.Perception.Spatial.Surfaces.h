// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Graphics.DirectX.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Perception.Spatial.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Perception.Spatial.Surfaces.3.h"
#include "Windows.Perception.Spatial.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo> : produce_base<D, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo>
{
    HRESULT __stdcall get_Id(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UpdateTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UpdateTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetBounds(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_out<Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingOrientedBox>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryGetBounds(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryComputeLatestMeshAsync(double maxTrianglesPerCubicMeter, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryComputeLatestMeshAsync(maxTrianglesPerCubicMeter));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryComputeLatestMeshWithOptionsAsync(double maxTrianglesPerCubicMeter, impl::abi_arg_in<Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryComputeLatestMeshAsync(maxTrianglesPerCubicMeter, *reinterpret_cast<const Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMesh> : produce_base<D, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMesh>
{
    HRESULT __stdcall get_SurfaceInfo(impl::abi_arg_out<Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SurfaceInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CoordinateSystem(impl::abi_arg_out<Windows::Perception::Spatial::ISpatialCoordinateSystem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CoordinateSystem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TriangleIndices(impl::abi_arg_out<Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TriangleIndices());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VertexPositions(impl::abi_arg_out<Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VertexPositions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VertexPositionScale(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VertexPositionScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VertexNormals(impl::abi_arg_out<Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VertexNormals());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer> : produce_base<D, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer>
{
    HRESULT __stdcall get_Format(Windows::Graphics::DirectX::DirectXPixelFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Format());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Stride(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Stride());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ElementCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ElementCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions> : produce_base<D, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions>
{
    HRESULT __stdcall get_VertexPositionFormat(Windows::Graphics::DirectX::DirectXPixelFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VertexPositionFormat());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VertexPositionFormat(Windows::Graphics::DirectX::DirectXPixelFormat value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VertexPositionFormat(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TriangleIndexFormat(Windows::Graphics::DirectX::DirectXPixelFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TriangleIndexFormat());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TriangleIndexFormat(Windows::Graphics::DirectX::DirectXPixelFormat value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TriangleIndexFormat(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VertexNormalFormat(Windows::Graphics::DirectX::DirectXPixelFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VertexNormalFormat());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VertexNormalFormat(Windows::Graphics::DirectX::DirectXPixelFormat value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VertexNormalFormat(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncludeVertexNormals(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncludeVertexNormals());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IncludeVertexNormals(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncludeVertexNormals(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptionsStatics> : produce_base<D, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptionsStatics>
{
    HRESULT __stdcall get_SupportedVertexPositionFormats(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedVertexPositionFormats());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedTriangleIndexFormats(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedTriangleIndexFormats());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedVertexNormalFormats(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedVertexNormalFormats());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserver> : produce_base<D, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserver>
{
    HRESULT __stdcall abi_GetObservedSurfaces(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<GUID, Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetObservedSurfaces());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetBoundingVolume(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialBoundingVolume> bounds) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBoundingVolume(*reinterpret_cast<const Windows::Perception::Spatial::SpatialBoundingVolume *>(&bounds));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetBoundingVolumes(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Perception::Spatial::SpatialBoundingVolume>> bounds) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBoundingVolumes(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Perception::Spatial::SpatialBoundingVolume> *>(&bounds));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ObservedSurfacesChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::Surfaces::SpatialSurfaceObserver, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ObservedSurfacesChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::Surfaces::SpatialSurfaceObserver, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ObservedSurfacesChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ObservedSurfacesChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics> : produce_base<D, Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics>
{
    HRESULT __stdcall abi_RequestAccessAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAccessAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Perception::Spatial::Surfaces {

template <typename D> Windows::Graphics::DirectX::DirectXPixelFormat impl_ISpatialSurfaceMeshBuffer<D>::Format() const
{
    Windows::Graphics::DirectX::DirectXPixelFormat value {};
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshBuffer)->get_Format(&value));
    return value;
}

template <typename D> uint32_t impl_ISpatialSurfaceMeshBuffer<D>::Stride() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshBuffer)->get_Stride(&value));
    return value;
}

template <typename D> uint32_t impl_ISpatialSurfaceMeshBuffer<D>::ElementCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshBuffer)->get_ElementCount(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISpatialSurfaceMeshBuffer<D>::Data() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshBuffer)->get_Data(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo impl_ISpatialSurfaceMesh<D>::SurfaceInfo() const
{
    Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialSurfaceMesh)->get_SurfaceInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialCoordinateSystem impl_ISpatialSurfaceMesh<D>::CoordinateSystem() const
{
    Windows::Perception::Spatial::SpatialCoordinateSystem value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialSurfaceMesh)->get_CoordinateSystem(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer impl_ISpatialSurfaceMesh<D>::TriangleIndices() const
{
    Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialSurfaceMesh)->get_TriangleIndices(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer impl_ISpatialSurfaceMesh<D>::VertexPositions() const
{
    Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialSurfaceMesh)->get_VertexPositions(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_ISpatialSurfaceMesh<D>::VertexPositionScale() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(ISpatialSurfaceMesh)->get_VertexPositionScale(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer impl_ISpatialSurfaceMesh<D>::VertexNormals() const
{
    Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshBuffer value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialSurfaceMesh)->get_VertexNormals(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> impl_ISpatialSurfaceMeshOptionsStatics<D>::SupportedVertexPositionFormats() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> value;
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshOptionsStatics)->get_SupportedVertexPositionFormats(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> impl_ISpatialSurfaceMeshOptionsStatics<D>::SupportedTriangleIndexFormats() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> value;
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshOptionsStatics)->get_SupportedTriangleIndexFormats(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> impl_ISpatialSurfaceMeshOptionsStatics<D>::SupportedVertexNormalFormats() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> value;
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshOptionsStatics)->get_SupportedVertexNormalFormats(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::DirectX::DirectXPixelFormat impl_ISpatialSurfaceMeshOptions<D>::VertexPositionFormat() const
{
    Windows::Graphics::DirectX::DirectXPixelFormat value {};
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshOptions)->get_VertexPositionFormat(&value));
    return value;
}

template <typename D> void impl_ISpatialSurfaceMeshOptions<D>::VertexPositionFormat(Windows::Graphics::DirectX::DirectXPixelFormat value) const
{
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshOptions)->put_VertexPositionFormat(value));
}

template <typename D> Windows::Graphics::DirectX::DirectXPixelFormat impl_ISpatialSurfaceMeshOptions<D>::TriangleIndexFormat() const
{
    Windows::Graphics::DirectX::DirectXPixelFormat value {};
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshOptions)->get_TriangleIndexFormat(&value));
    return value;
}

template <typename D> void impl_ISpatialSurfaceMeshOptions<D>::TriangleIndexFormat(Windows::Graphics::DirectX::DirectXPixelFormat value) const
{
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshOptions)->put_TriangleIndexFormat(value));
}

template <typename D> Windows::Graphics::DirectX::DirectXPixelFormat impl_ISpatialSurfaceMeshOptions<D>::VertexNormalFormat() const
{
    Windows::Graphics::DirectX::DirectXPixelFormat value {};
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshOptions)->get_VertexNormalFormat(&value));
    return value;
}

template <typename D> void impl_ISpatialSurfaceMeshOptions<D>::VertexNormalFormat(Windows::Graphics::DirectX::DirectXPixelFormat value) const
{
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshOptions)->put_VertexNormalFormat(value));
}

template <typename D> bool impl_ISpatialSurfaceMeshOptions<D>::IncludeVertexNormals() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshOptions)->get_IncludeVertexNormals(&value));
    return value;
}

template <typename D> void impl_ISpatialSurfaceMeshOptions<D>::IncludeVertexNormals(bool value) const
{
    check_hresult(WINRT_SHIM(ISpatialSurfaceMeshOptions)->put_IncludeVertexNormals(value));
}

template <typename D> GUID impl_ISpatialSurfaceInfo<D>::Id() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(ISpatialSurfaceInfo)->get_Id(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISpatialSurfaceInfo<D>::UpdateTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISpatialSurfaceInfo)->get_UpdateTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingOrientedBox> impl_ISpatialSurfaceInfo<D>::TryGetBounds(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem) const
{
    Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingOrientedBox> value;
    check_hresult(WINRT_SHIM(ISpatialSurfaceInfo)->abi_TryGetBounds(get_abi(coordinateSystem), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh> impl_ISpatialSurfaceInfo<D>::TryComputeLatestMeshAsync(double maxTrianglesPerCubicMeter) const
{
    Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh> value;
    check_hresult(WINRT_SHIM(ISpatialSurfaceInfo)->abi_TryComputeLatestMeshAsync(maxTrianglesPerCubicMeter, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh> impl_ISpatialSurfaceInfo<D>::TryComputeLatestMeshAsync(double maxTrianglesPerCubicMeter, const Windows::Perception::Spatial::Surfaces::SpatialSurfaceMeshOptions & options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh> value;
    check_hresult(WINRT_SHIM(ISpatialSurfaceInfo)->abi_TryComputeLatestMeshWithOptionsAsync(maxTrianglesPerCubicMeter, get_abi(options), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus> impl_ISpatialSurfaceObserverStatics<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus> result;
    check_hresult(WINRT_SHIM(ISpatialSurfaceObserverStatics)->abi_RequestAccessAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IMapView<GUID, Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo> impl_ISpatialSurfaceObserver<D>::GetObservedSurfaces() const
{
    Windows::Foundation::Collections::IMapView<GUID, Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo> value;
    check_hresult(WINRT_SHIM(ISpatialSurfaceObserver)->abi_GetObservedSurfaces(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpatialSurfaceObserver<D>::SetBoundingVolume(const Windows::Perception::Spatial::SpatialBoundingVolume & bounds) const
{
    check_hresult(WINRT_SHIM(ISpatialSurfaceObserver)->abi_SetBoundingVolume(get_abi(bounds)));
}

template <typename D> void impl_ISpatialSurfaceObserver<D>::SetBoundingVolumes(iterable<Windows::Perception::Spatial::SpatialBoundingVolume> bounds) const
{
    check_hresult(WINRT_SHIM(ISpatialSurfaceObserver)->abi_SetBoundingVolumes(get_abi(bounds)));
}

template <typename D> event_token impl_ISpatialSurfaceObserver<D>::ObservedSurfacesChanged(const Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::Surfaces::SpatialSurfaceObserver, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISpatialSurfaceObserver)->add_ObservedSurfacesChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISpatialSurfaceObserver> impl_ISpatialSurfaceObserver<D>::ObservedSurfacesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::Surfaces::SpatialSurfaceObserver, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ISpatialSurfaceObserver>(this, &ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserver::remove_ObservedSurfacesChanged, ObservedSurfacesChanged(handler));
}

template <typename D> void impl_ISpatialSurfaceObserver<D>::ObservedSurfacesChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(ISpatialSurfaceObserver)->remove_ObservedSurfacesChanged(token));
}

inline SpatialSurfaceMeshOptions::SpatialSurfaceMeshOptions() :
    SpatialSurfaceMeshOptions(activate_instance<SpatialSurfaceMeshOptions>())
{}

inline Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> SpatialSurfaceMeshOptions::SupportedVertexPositionFormats()
{
    return get_activation_factory<SpatialSurfaceMeshOptions, ISpatialSurfaceMeshOptionsStatics>().SupportedVertexPositionFormats();
}

inline Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> SpatialSurfaceMeshOptions::SupportedTriangleIndexFormats()
{
    return get_activation_factory<SpatialSurfaceMeshOptions, ISpatialSurfaceMeshOptionsStatics>().SupportedTriangleIndexFormats();
}

inline Windows::Foundation::Collections::IVectorView<winrt::Windows::Graphics::DirectX::DirectXPixelFormat> SpatialSurfaceMeshOptions::SupportedVertexNormalFormats()
{
    return get_activation_factory<SpatialSurfaceMeshOptions, ISpatialSurfaceMeshOptionsStatics>().SupportedVertexNormalFormats();
}

inline SpatialSurfaceObserver::SpatialSurfaceObserver() :
    SpatialSurfaceObserver(activate_instance<SpatialSurfaceObserver>())
{}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus> SpatialSurfaceObserver::RequestAccessAsync()
{
    return get_activation_factory<SpatialSurfaceObserver, ISpatialSurfaceObserverStatics>().RequestAccessAsync();
}

}

}
#pragma warning(pop)
