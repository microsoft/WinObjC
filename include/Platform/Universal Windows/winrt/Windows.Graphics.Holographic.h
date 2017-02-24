// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Graphics.DirectX.Direct3D11.3.h"
#include "internal/Windows.UI.Core.3.h"
#include "internal/Windows.Perception.Spatial.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Perception.3.h"
#include "internal/Windows.Graphics.Holographic.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Graphics::Holographic::IHolographicCamera> : produce_base<D, Windows::Graphics::Holographic::IHolographicCamera>
{
    HRESULT __stdcall get_RenderTargetSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RenderTargetSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ViewportScaleFactor(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ViewportScaleFactor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ViewportScaleFactor(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ViewportScaleFactor(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStereo(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStereo());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(uint32_t * value) noexcept override
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

    HRESULT __stdcall abi_SetNearPlaneDistance(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetNearPlaneDistance(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetFarPlaneDistance(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFarPlaneDistance(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Holographic::IHolographicCameraPose> : produce_base<D, Windows::Graphics::Holographic::IHolographicCameraPose>
{
    HRESULT __stdcall get_HolographicCamera(impl::abi_arg_out<Windows::Graphics::Holographic::IHolographicCamera> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HolographicCamera());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Viewport(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Viewport());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetViewTransform(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_out<Windows::Foundation::IReference<Windows::Graphics::Holographic::HolographicStereoTransform>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryGetViewTransform(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProjectionTransform(impl::abi_arg_out<Windows::Graphics::Holographic::HolographicStereoTransform> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProjectionTransform());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetCullingFrustum(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_out<Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingFrustum>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryGetCullingFrustum(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetVisibleFrustum(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_out<Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingFrustum>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryGetVisibleFrustum(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NearPlaneDistance(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NearPlaneDistance());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FarPlaneDistance(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FarPlaneDistance());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Holographic::IHolographicCameraRenderingParameters> : produce_base<D, Windows::Graphics::Holographic::IHolographicCameraRenderingParameters>
{
    HRESULT __stdcall abi_SetFocusPoint(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_in<Windows::Foundation::Numerics::float3> position) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFocusPoint(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&position));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetFocusPointWithNormal(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_in<Windows::Foundation::Numerics::float3> position, impl::abi_arg_in<Windows::Foundation::Numerics::float3> normal) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFocusPoint(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&position), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&normal));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetFocusPointWithNormalLinearVelocity(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_in<Windows::Foundation::Numerics::float3> position, impl::abi_arg_in<Windows::Foundation::Numerics::float3> normal, impl::abi_arg_in<Windows::Foundation::Numerics::float3> linearVelocity) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFocusPoint(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&position), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&normal), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&linearVelocity));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Direct3D11Device(impl::abi_arg_out<Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Direct3D11Device());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Direct3D11BackBuffer(impl::abi_arg_out<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Direct3D11BackBuffer());
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
struct produce<D, Windows::Graphics::Holographic::IHolographicFrame> : produce_base<D, Windows::Graphics::Holographic::IHolographicFrame>
{
    HRESULT __stdcall get_AddedCameras(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCamera>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AddedCameras());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemovedCameras(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCamera>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemovedCameras());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRenderingParameters(impl::abi_arg_in<Windows::Graphics::Holographic::IHolographicCameraPose> cameraPose, impl::abi_arg_out<Windows::Graphics::Holographic::IHolographicCameraRenderingParameters> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetRenderingParameters(*reinterpret_cast<const Windows::Graphics::Holographic::HolographicCameraPose *>(&cameraPose)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentPrediction(impl::abi_arg_out<Windows::Graphics::Holographic::IHolographicFramePrediction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentPrediction());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateCurrentPrediction() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateCurrentPrediction();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PresentUsingCurrentPrediction(Windows::Graphics::Holographic::HolographicFramePresentResult * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PresentUsingCurrentPrediction());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PresentUsingCurrentPredictionWithBehavior(Windows::Graphics::Holographic::HolographicFramePresentWaitBehavior waitBehavior, Windows::Graphics::Holographic::HolographicFramePresentResult * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PresentUsingCurrentPrediction(waitBehavior));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WaitForFrameToFinish() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WaitForFrameToFinish();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Holographic::IHolographicFramePrediction> : produce_base<D, Windows::Graphics::Holographic::IHolographicFramePrediction>
{
    HRESULT __stdcall get_CameraPoses(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCameraPose>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CameraPoses());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Perception::IPerceptionTimestamp> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
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
struct produce<D, Windows::Graphics::Holographic::IHolographicSpace> : produce_base<D, Windows::Graphics::Holographic::IHolographicSpace>
{
    HRESULT __stdcall get_PrimaryAdapterId(impl::abi_arg_out<Windows::Graphics::Holographic::HolographicAdapterId> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrimaryAdapterId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDirect3D11Device(impl::abi_arg_in<Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDirect3D11Device(*reinterpret_cast<const Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CameraAdded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().CameraAdded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CameraAdded(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraAdded(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CameraRemoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().CameraRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CameraRemoved(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraRemoved(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateNextFrame(impl::abi_arg_out<Windows::Graphics::Holographic::IHolographicFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateNextFrame());
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
struct produce<D, Windows::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs> : produce_base<D, Windows::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs>
{
    HRESULT __stdcall get_Camera(impl::abi_arg_out<Windows::Graphics::Holographic::IHolographicCamera> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Camera());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs> : produce_base<D, Windows::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs>
{
    HRESULT __stdcall get_Camera(impl::abi_arg_out<Windows::Graphics::Holographic::IHolographicCamera> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Camera());
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
struct produce<D, Windows::Graphics::Holographic::IHolographicSpaceStatics> : produce_base<D, Windows::Graphics::Holographic::IHolographicSpaceStatics>
{
    HRESULT __stdcall abi_CreateForCoreWindow(impl::abi_arg_in<Windows::UI::Core::ICoreWindow> window, impl::abi_arg_out<Windows::Graphics::Holographic::IHolographicSpace> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateForCoreWindow(*reinterpret_cast<const Windows::UI::Core::CoreWindow *>(&window)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Graphics::Holographic {

template <typename D> Windows::Foundation::Size impl_IHolographicCamera<D>::RenderTargetSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IHolographicCamera)->get_RenderTargetSize(put_abi(value)));
    return value;
}

template <typename D> double impl_IHolographicCamera<D>::ViewportScaleFactor() const
{
    double value {};
    check_hresult(WINRT_SHIM(IHolographicCamera)->get_ViewportScaleFactor(&value));
    return value;
}

template <typename D> void impl_IHolographicCamera<D>::ViewportScaleFactor(double value) const
{
    check_hresult(WINRT_SHIM(IHolographicCamera)->put_ViewportScaleFactor(value));
}

template <typename D> bool impl_IHolographicCamera<D>::IsStereo() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IHolographicCamera)->get_IsStereo(&value));
    return value;
}

template <typename D> uint32_t impl_IHolographicCamera<D>::Id() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IHolographicCamera)->get_Id(&value));
    return value;
}

template <typename D> void impl_IHolographicCamera<D>::SetNearPlaneDistance(double value) const
{
    check_hresult(WINRT_SHIM(IHolographicCamera)->abi_SetNearPlaneDistance(value));
}

template <typename D> void impl_IHolographicCamera<D>::SetFarPlaneDistance(double value) const
{
    check_hresult(WINRT_SHIM(IHolographicCamera)->abi_SetFarPlaneDistance(value));
}

template <typename D> Windows::Graphics::Holographic::HolographicCamera impl_IHolographicSpaceCameraAddedEventArgs<D>::Camera() const
{
    Windows::Graphics::Holographic::HolographicCamera value { nullptr };
    check_hresult(WINRT_SHIM(IHolographicSpaceCameraAddedEventArgs)->get_Camera(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IHolographicSpaceCameraAddedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IHolographicSpaceCameraAddedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Holographic::HolographicCamera impl_IHolographicSpaceCameraRemovedEventArgs<D>::Camera() const
{
    Windows::Graphics::Holographic::HolographicCamera value { nullptr };
    check_hresult(WINRT_SHIM(IHolographicSpaceCameraRemovedEventArgs)->get_Camera(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Holographic::HolographicAdapterId impl_IHolographicSpace<D>::PrimaryAdapterId() const
{
    Windows::Graphics::Holographic::HolographicAdapterId value {};
    check_hresult(WINRT_SHIM(IHolographicSpace)->get_PrimaryAdapterId(put_abi(value)));
    return value;
}

template <typename D> void impl_IHolographicSpace<D>::SetDirect3D11Device(const Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice & value) const
{
    check_hresult(WINRT_SHIM(IHolographicSpace)->abi_SetDirect3D11Device(get_abi(value)));
}

template <typename D> event_token impl_IHolographicSpace<D>::CameraAdded(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IHolographicSpace)->add_CameraAdded(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IHolographicSpace> impl_IHolographicSpace<D>::CameraAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IHolographicSpace>(this, &ABI::Windows::Graphics::Holographic::IHolographicSpace::remove_CameraAdded, CameraAdded(handler));
}

template <typename D> void impl_IHolographicSpace<D>::CameraAdded(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IHolographicSpace)->remove_CameraAdded(cookie));
}

template <typename D> event_token impl_IHolographicSpace<D>::CameraRemoved(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IHolographicSpace)->add_CameraRemoved(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IHolographicSpace> impl_IHolographicSpace<D>::CameraRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IHolographicSpace>(this, &ABI::Windows::Graphics::Holographic::IHolographicSpace::remove_CameraRemoved, CameraRemoved(handler));
}

template <typename D> void impl_IHolographicSpace<D>::CameraRemoved(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IHolographicSpace)->remove_CameraRemoved(cookie));
}

template <typename D> Windows::Graphics::Holographic::HolographicFrame impl_IHolographicSpace<D>::CreateNextFrame() const
{
    Windows::Graphics::Holographic::HolographicFrame value { nullptr };
    check_hresult(WINRT_SHIM(IHolographicSpace)->abi_CreateNextFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Holographic::HolographicSpace impl_IHolographicSpaceStatics<D>::CreateForCoreWindow(const Windows::UI::Core::CoreWindow & window) const
{
    Windows::Graphics::Holographic::HolographicSpace value { nullptr };
    check_hresult(WINRT_SHIM(IHolographicSpaceStatics)->abi_CreateForCoreWindow(get_abi(window), put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Holographic::HolographicCamera impl_IHolographicCameraPose<D>::HolographicCamera() const
{
    Windows::Graphics::Holographic::HolographicCamera value { nullptr };
    check_hresult(WINRT_SHIM(IHolographicCameraPose)->get_HolographicCamera(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IHolographicCameraPose<D>::Viewport() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IHolographicCameraPose)->get_Viewport(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Graphics::Holographic::HolographicStereoTransform> impl_IHolographicCameraPose<D>::TryGetViewTransform(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem) const
{
    Windows::Foundation::IReference<Windows::Graphics::Holographic::HolographicStereoTransform> value;
    check_hresult(WINRT_SHIM(IHolographicCameraPose)->abi_TryGetViewTransform(get_abi(coordinateSystem), put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Holographic::HolographicStereoTransform impl_IHolographicCameraPose<D>::ProjectionTransform() const
{
    Windows::Graphics::Holographic::HolographicStereoTransform value {};
    check_hresult(WINRT_SHIM(IHolographicCameraPose)->get_ProjectionTransform(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingFrustum> impl_IHolographicCameraPose<D>::TryGetCullingFrustum(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem) const
{
    Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingFrustum> value;
    check_hresult(WINRT_SHIM(IHolographicCameraPose)->abi_TryGetCullingFrustum(get_abi(coordinateSystem), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingFrustum> impl_IHolographicCameraPose<D>::TryGetVisibleFrustum(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem) const
{
    Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingFrustum> value;
    check_hresult(WINRT_SHIM(IHolographicCameraPose)->abi_TryGetVisibleFrustum(get_abi(coordinateSystem), put_abi(value)));
    return value;
}

template <typename D> double impl_IHolographicCameraPose<D>::NearPlaneDistance() const
{
    double value {};
    check_hresult(WINRT_SHIM(IHolographicCameraPose)->get_NearPlaneDistance(&value));
    return value;
}

template <typename D> double impl_IHolographicCameraPose<D>::FarPlaneDistance() const
{
    double value {};
    check_hresult(WINRT_SHIM(IHolographicCameraPose)->get_FarPlaneDistance(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCameraPose> impl_IHolographicFramePrediction<D>::CameraPoses() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCameraPose> value;
    check_hresult(WINRT_SHIM(IHolographicFramePrediction)->get_CameraPoses(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::PerceptionTimestamp impl_IHolographicFramePrediction<D>::Timestamp() const
{
    Windows::Perception::PerceptionTimestamp value { nullptr };
    check_hresult(WINRT_SHIM(IHolographicFramePrediction)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> void impl_IHolographicCameraRenderingParameters<D>::SetFocusPoint(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Foundation::Numerics::float3 & position) const
{
    check_hresult(WINRT_SHIM(IHolographicCameraRenderingParameters)->abi_SetFocusPoint(get_abi(coordinateSystem), get_abi(position)));
}

template <typename D> void impl_IHolographicCameraRenderingParameters<D>::SetFocusPoint(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Foundation::Numerics::float3 & position, const Windows::Foundation::Numerics::float3 & normal) const
{
    check_hresult(WINRT_SHIM(IHolographicCameraRenderingParameters)->abi_SetFocusPointWithNormal(get_abi(coordinateSystem), get_abi(position), get_abi(normal)));
}

template <typename D> void impl_IHolographicCameraRenderingParameters<D>::SetFocusPoint(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Foundation::Numerics::float3 & position, const Windows::Foundation::Numerics::float3 & normal, const Windows::Foundation::Numerics::float3 & linearVelocity) const
{
    check_hresult(WINRT_SHIM(IHolographicCameraRenderingParameters)->abi_SetFocusPointWithNormalLinearVelocity(get_abi(coordinateSystem), get_abi(position), get_abi(normal), get_abi(linearVelocity)));
}

template <typename D> Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice impl_IHolographicCameraRenderingParameters<D>::Direct3D11Device() const
{
    Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice value;
    check_hresult(WINRT_SHIM(IHolographicCameraRenderingParameters)->get_Direct3D11Device(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface impl_IHolographicCameraRenderingParameters<D>::Direct3D11BackBuffer() const
{
    Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface value;
    check_hresult(WINRT_SHIM(IHolographicCameraRenderingParameters)->get_Direct3D11BackBuffer(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCamera> impl_IHolographicFrame<D>::AddedCameras() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCamera> value;
    check_hresult(WINRT_SHIM(IHolographicFrame)->get_AddedCameras(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCamera> impl_IHolographicFrame<D>::RemovedCameras() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCamera> value;
    check_hresult(WINRT_SHIM(IHolographicFrame)->get_RemovedCameras(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Holographic::HolographicCameraRenderingParameters impl_IHolographicFrame<D>::GetRenderingParameters(const Windows::Graphics::Holographic::HolographicCameraPose & cameraPose) const
{
    Windows::Graphics::Holographic::HolographicCameraRenderingParameters value { nullptr };
    check_hresult(WINRT_SHIM(IHolographicFrame)->abi_GetRenderingParameters(get_abi(cameraPose), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IHolographicFrame<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IHolographicFrame)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Holographic::HolographicFramePrediction impl_IHolographicFrame<D>::CurrentPrediction() const
{
    Windows::Graphics::Holographic::HolographicFramePrediction value { nullptr };
    check_hresult(WINRT_SHIM(IHolographicFrame)->get_CurrentPrediction(put_abi(value)));
    return value;
}

template <typename D> void impl_IHolographicFrame<D>::UpdateCurrentPrediction() const
{
    check_hresult(WINRT_SHIM(IHolographicFrame)->abi_UpdateCurrentPrediction());
}

template <typename D> Windows::Graphics::Holographic::HolographicFramePresentResult impl_IHolographicFrame<D>::PresentUsingCurrentPrediction() const
{
    Windows::Graphics::Holographic::HolographicFramePresentResult result {};
    check_hresult(WINRT_SHIM(IHolographicFrame)->abi_PresentUsingCurrentPrediction(&result));
    return result;
}

template <typename D> Windows::Graphics::Holographic::HolographicFramePresentResult impl_IHolographicFrame<D>::PresentUsingCurrentPrediction(Windows::Graphics::Holographic::HolographicFramePresentWaitBehavior waitBehavior) const
{
    Windows::Graphics::Holographic::HolographicFramePresentResult result {};
    check_hresult(WINRT_SHIM(IHolographicFrame)->abi_PresentUsingCurrentPredictionWithBehavior(waitBehavior, &result));
    return result;
}

template <typename D> void impl_IHolographicFrame<D>::WaitForFrameToFinish() const
{
    check_hresult(WINRT_SHIM(IHolographicFrame)->abi_WaitForFrameToFinish());
}

inline Windows::Graphics::Holographic::HolographicSpace HolographicSpace::CreateForCoreWindow(const Windows::UI::Core::CoreWindow & window)
{
    return get_activation_factory<HolographicSpace, IHolographicSpaceStatics>().CreateForCoreWindow(window);
}

}

}
#pragma warning(pop)
