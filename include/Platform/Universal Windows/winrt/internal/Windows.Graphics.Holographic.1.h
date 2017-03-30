// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Graphics.Holographic.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Graphics.DirectX.Direct3D11.0.h"
#include "Windows.Perception.0.h"
#include "Windows.Perception.Spatial.0.h"
#include "Windows.UI.Core.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Perception.Spatial.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Graphics::Holographic {

struct HolographicStereoTransform
{
    Windows::Foundation::Numerics::float4x4 Left;
    Windows::Foundation::Numerics::float4x4 Right;
};

struct HolographicAdapterId
{
    uint32_t LowPart;
    int32_t HighPart;
};

}

namespace Windows::Graphics::Holographic {

using HolographicStereoTransform = ABI::Windows::Graphics::Holographic::HolographicStereoTransform;
using HolographicAdapterId = ABI::Windows::Graphics::Holographic::HolographicAdapterId;

}

namespace ABI::Windows::Graphics::Holographic {

struct __declspec(uuid("e4e98445-9bed-4980-9ba0-e87680d1cb74")) __declspec(novtable) IHolographicCamera : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RenderTargetSize(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall get_ViewportScaleFactor(double * value) = 0;
    virtual HRESULT __stdcall put_ViewportScaleFactor(double value) = 0;
    virtual HRESULT __stdcall get_IsStereo(bool * value) = 0;
    virtual HRESULT __stdcall get_Id(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetNearPlaneDistance(double value) = 0;
    virtual HRESULT __stdcall abi_SetFarPlaneDistance(double value) = 0;
};

struct __declspec(uuid("0d7d7e30-12de-45bd-912b-c7f6561599d1")) __declspec(novtable) IHolographicCameraPose : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HolographicCamera(Windows::Graphics::Holographic::IHolographicCamera ** value) = 0;
    virtual HRESULT __stdcall get_Viewport(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall abi_TryGetViewTransform(Windows::Perception::Spatial::ISpatialCoordinateSystem * coordinateSystem, Windows::Foundation::IReference<Windows::Graphics::Holographic::HolographicStereoTransform> ** value) = 0;
    virtual HRESULT __stdcall get_ProjectionTransform(Windows::Graphics::Holographic::HolographicStereoTransform * value) = 0;
    virtual HRESULT __stdcall abi_TryGetCullingFrustum(Windows::Perception::Spatial::ISpatialCoordinateSystem * coordinateSystem, Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingFrustum> ** value) = 0;
    virtual HRESULT __stdcall abi_TryGetVisibleFrustum(Windows::Perception::Spatial::ISpatialCoordinateSystem * coordinateSystem, Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingFrustum> ** value) = 0;
    virtual HRESULT __stdcall get_NearPlaneDistance(double * value) = 0;
    virtual HRESULT __stdcall get_FarPlaneDistance(double * value) = 0;
};

struct __declspec(uuid("8eac2ed1-5bf4-4e16-8236-ae0800c11d0d")) __declspec(novtable) IHolographicCameraRenderingParameters : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetFocusPoint(Windows::Perception::Spatial::ISpatialCoordinateSystem * coordinateSystem, Windows::Foundation::Numerics::float3 position) = 0;
    virtual HRESULT __stdcall abi_SetFocusPointWithNormal(Windows::Perception::Spatial::ISpatialCoordinateSystem * coordinateSystem, Windows::Foundation::Numerics::float3 position, Windows::Foundation::Numerics::float3 normal) = 0;
    virtual HRESULT __stdcall abi_SetFocusPointWithNormalLinearVelocity(Windows::Perception::Spatial::ISpatialCoordinateSystem * coordinateSystem, Windows::Foundation::Numerics::float3 position, Windows::Foundation::Numerics::float3 normal, Windows::Foundation::Numerics::float3 linearVelocity) = 0;
    virtual HRESULT __stdcall get_Direct3D11Device(Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice ** value) = 0;
    virtual HRESULT __stdcall get_Direct3D11BackBuffer(Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface ** value) = 0;
};

struct __declspec(uuid("c6988eb6-a8b9-3054-a6eb-d624b6536375")) __declspec(novtable) IHolographicFrame : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AddedCameras(Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCamera> ** value) = 0;
    virtual HRESULT __stdcall get_RemovedCameras(Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCamera> ** value) = 0;
    virtual HRESULT __stdcall abi_GetRenderingParameters(Windows::Graphics::Holographic::IHolographicCameraPose * cameraPose, Windows::Graphics::Holographic::IHolographicCameraRenderingParameters ** value) = 0;
    virtual HRESULT __stdcall get_Duration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_CurrentPrediction(Windows::Graphics::Holographic::IHolographicFramePrediction ** value) = 0;
    virtual HRESULT __stdcall abi_UpdateCurrentPrediction() = 0;
    virtual HRESULT __stdcall abi_PresentUsingCurrentPrediction(winrt::Windows::Graphics::Holographic::HolographicFramePresentResult * result) = 0;
    virtual HRESULT __stdcall abi_PresentUsingCurrentPredictionWithBehavior(winrt::Windows::Graphics::Holographic::HolographicFramePresentWaitBehavior waitBehavior, winrt::Windows::Graphics::Holographic::HolographicFramePresentResult * result) = 0;
    virtual HRESULT __stdcall abi_WaitForFrameToFinish() = 0;
};

struct __declspec(uuid("520f4de1-5c0a-4e79-a81e-6abe02bb2739")) __declspec(novtable) IHolographicFramePrediction : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CameraPoses(Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCameraPose> ** value) = 0;
    virtual HRESULT __stdcall get_Timestamp(Windows::Perception::IPerceptionTimestamp ** value) = 0;
};

struct __declspec(uuid("4380dba6-5e78-434f-807c-3433d1efe8b7")) __declspec(novtable) IHolographicSpace : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PrimaryAdapterId(Windows::Graphics::Holographic::HolographicAdapterId * value) = 0;
    virtual HRESULT __stdcall abi_SetDirect3D11Device(Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice * value) = 0;
    virtual HRESULT __stdcall add_CameraAdded(Windows::Foundation::TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_CameraAdded(event_token cookie) = 0;
    virtual HRESULT __stdcall add_CameraRemoved(Windows::Foundation::TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_CameraRemoved(event_token cookie) = 0;
    virtual HRESULT __stdcall abi_CreateNextFrame(Windows::Graphics::Holographic::IHolographicFrame ** value) = 0;
};

struct __declspec(uuid("58f1da35-bbb3-3c8f-993d-6c80e7feb99f")) __declspec(novtable) IHolographicSpaceCameraAddedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Camera(Windows::Graphics::Holographic::IHolographicCamera ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("805444a8-f2ae-322e-8da9-836a0a95a4c1")) __declspec(novtable) IHolographicSpaceCameraRemovedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Camera(Windows::Graphics::Holographic::IHolographicCamera ** value) = 0;
};

struct __declspec(uuid("364e6064-c8f2-3ba1-8391-66b8489e67fd")) __declspec(novtable) IHolographicSpaceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateForCoreWindow(Windows::UI::Core::ICoreWindow * window, Windows::Graphics::Holographic::IHolographicSpace ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Graphics::Holographic::HolographicCamera> { using default_interface = Windows::Graphics::Holographic::IHolographicCamera; };
template <> struct traits<Windows::Graphics::Holographic::HolographicCameraPose> { using default_interface = Windows::Graphics::Holographic::IHolographicCameraPose; };
template <> struct traits<Windows::Graphics::Holographic::HolographicCameraRenderingParameters> { using default_interface = Windows::Graphics::Holographic::IHolographicCameraRenderingParameters; };
template <> struct traits<Windows::Graphics::Holographic::HolographicFrame> { using default_interface = Windows::Graphics::Holographic::IHolographicFrame; };
template <> struct traits<Windows::Graphics::Holographic::HolographicFramePrediction> { using default_interface = Windows::Graphics::Holographic::IHolographicFramePrediction; };
template <> struct traits<Windows::Graphics::Holographic::HolographicSpace> { using default_interface = Windows::Graphics::Holographic::IHolographicSpace; };
template <> struct traits<Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs> { using default_interface = Windows::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs; };
template <> struct traits<Windows::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs> { using default_interface = Windows::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs; };

}

namespace Windows::Graphics::Holographic {

template <typename D>
struct WINRT_EBO impl_IHolographicCamera
{
    Windows::Foundation::Size RenderTargetSize() const;
    double ViewportScaleFactor() const;
    void ViewportScaleFactor(double value) const;
    bool IsStereo() const;
    uint32_t Id() const;
    void SetNearPlaneDistance(double value) const;
    void SetFarPlaneDistance(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IHolographicCameraPose
{
    Windows::Graphics::Holographic::HolographicCamera HolographicCamera() const;
    Windows::Foundation::Rect Viewport() const;
    Windows::Foundation::IReference<Windows::Graphics::Holographic::HolographicStereoTransform> TryGetViewTransform(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem) const;
    Windows::Graphics::Holographic::HolographicStereoTransform ProjectionTransform() const;
    Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingFrustum> TryGetCullingFrustum(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem) const;
    Windows::Foundation::IReference<Windows::Perception::Spatial::SpatialBoundingFrustum> TryGetVisibleFrustum(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem) const;
    double NearPlaneDistance() const;
    double FarPlaneDistance() const;
};

template <typename D>
struct WINRT_EBO impl_IHolographicCameraRenderingParameters
{
    void SetFocusPoint(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Foundation::Numerics::float3 & position) const;
    void SetFocusPoint(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Foundation::Numerics::float3 & position, const Windows::Foundation::Numerics::float3 & normal) const;
    void SetFocusPoint(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Foundation::Numerics::float3 & position, const Windows::Foundation::Numerics::float3 & normal, const Windows::Foundation::Numerics::float3 & linearVelocity) const;
    Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice Direct3D11Device() const;
    Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface Direct3D11BackBuffer() const;
};

template <typename D>
struct WINRT_EBO impl_IHolographicFrame
{
    Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCamera> AddedCameras() const;
    Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCamera> RemovedCameras() const;
    Windows::Graphics::Holographic::HolographicCameraRenderingParameters GetRenderingParameters(const Windows::Graphics::Holographic::HolographicCameraPose & cameraPose) const;
    Windows::Foundation::TimeSpan Duration() const;
    Windows::Graphics::Holographic::HolographicFramePrediction CurrentPrediction() const;
    void UpdateCurrentPrediction() const;
    Windows::Graphics::Holographic::HolographicFramePresentResult PresentUsingCurrentPrediction() const;
    Windows::Graphics::Holographic::HolographicFramePresentResult PresentUsingCurrentPrediction(Windows::Graphics::Holographic::HolographicFramePresentWaitBehavior waitBehavior) const;
    void WaitForFrameToFinish() const;
};

template <typename D>
struct WINRT_EBO impl_IHolographicFramePrediction
{
    Windows::Foundation::Collections::IVectorView<Windows::Graphics::Holographic::HolographicCameraPose> CameraPoses() const;
    Windows::Perception::PerceptionTimestamp Timestamp() const;
};

template <typename D>
struct WINRT_EBO impl_IHolographicSpace
{
    Windows::Graphics::Holographic::HolographicAdapterId PrimaryAdapterId() const;
    void SetDirect3D11Device(const Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice & value) const;
    event_token CameraAdded(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs> & handler) const;
    using CameraAdded_revoker = event_revoker<IHolographicSpace>;
    CameraAdded_revoker CameraAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs> & handler) const;
    void CameraAdded(event_token cookie) const;
    event_token CameraRemoved(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs> & handler) const;
    using CameraRemoved_revoker = event_revoker<IHolographicSpace>;
    CameraRemoved_revoker CameraRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Holographic::HolographicSpace, Windows::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs> & handler) const;
    void CameraRemoved(event_token cookie) const;
    Windows::Graphics::Holographic::HolographicFrame CreateNextFrame() const;
};

template <typename D>
struct WINRT_EBO impl_IHolographicSpaceCameraAddedEventArgs
{
    Windows::Graphics::Holographic::HolographicCamera Camera() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IHolographicSpaceCameraRemovedEventArgs
{
    Windows::Graphics::Holographic::HolographicCamera Camera() const;
};

template <typename D>
struct WINRT_EBO impl_IHolographicSpaceStatics
{
    Windows::Graphics::Holographic::HolographicSpace CreateForCoreWindow(const Windows::UI::Core::CoreWindow & window) const;
};

}

namespace impl {

template <> struct traits<Windows::Graphics::Holographic::IHolographicCamera>
{
    using abi = ABI::Windows::Graphics::Holographic::IHolographicCamera;
    template <typename D> using consume = Windows::Graphics::Holographic::impl_IHolographicCamera<D>;
};

template <> struct traits<Windows::Graphics::Holographic::IHolographicCameraPose>
{
    using abi = ABI::Windows::Graphics::Holographic::IHolographicCameraPose;
    template <typename D> using consume = Windows::Graphics::Holographic::impl_IHolographicCameraPose<D>;
};

template <> struct traits<Windows::Graphics::Holographic::IHolographicCameraRenderingParameters>
{
    using abi = ABI::Windows::Graphics::Holographic::IHolographicCameraRenderingParameters;
    template <typename D> using consume = Windows::Graphics::Holographic::impl_IHolographicCameraRenderingParameters<D>;
};

template <> struct traits<Windows::Graphics::Holographic::IHolographicFrame>
{
    using abi = ABI::Windows::Graphics::Holographic::IHolographicFrame;
    template <typename D> using consume = Windows::Graphics::Holographic::impl_IHolographicFrame<D>;
};

template <> struct traits<Windows::Graphics::Holographic::IHolographicFramePrediction>
{
    using abi = ABI::Windows::Graphics::Holographic::IHolographicFramePrediction;
    template <typename D> using consume = Windows::Graphics::Holographic::impl_IHolographicFramePrediction<D>;
};

template <> struct traits<Windows::Graphics::Holographic::IHolographicSpace>
{
    using abi = ABI::Windows::Graphics::Holographic::IHolographicSpace;
    template <typename D> using consume = Windows::Graphics::Holographic::impl_IHolographicSpace<D>;
};

template <> struct traits<Windows::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs>
{
    using abi = ABI::Windows::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs;
    template <typename D> using consume = Windows::Graphics::Holographic::impl_IHolographicSpaceCameraAddedEventArgs<D>;
};

template <> struct traits<Windows::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs>
{
    using abi = ABI::Windows::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs;
    template <typename D> using consume = Windows::Graphics::Holographic::impl_IHolographicSpaceCameraRemovedEventArgs<D>;
};

template <> struct traits<Windows::Graphics::Holographic::IHolographicSpaceStatics>
{
    using abi = ABI::Windows::Graphics::Holographic::IHolographicSpaceStatics;
    template <typename D> using consume = Windows::Graphics::Holographic::impl_IHolographicSpaceStatics<D>;
};

template <> struct traits<Windows::Graphics::Holographic::HolographicCamera>
{
    using abi = ABI::Windows::Graphics::Holographic::HolographicCamera;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Holographic.HolographicCamera"; }
};

template <> struct traits<Windows::Graphics::Holographic::HolographicCameraPose>
{
    using abi = ABI::Windows::Graphics::Holographic::HolographicCameraPose;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Holographic.HolographicCameraPose"; }
};

template <> struct traits<Windows::Graphics::Holographic::HolographicCameraRenderingParameters>
{
    using abi = ABI::Windows::Graphics::Holographic::HolographicCameraRenderingParameters;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Holographic.HolographicCameraRenderingParameters"; }
};

template <> struct traits<Windows::Graphics::Holographic::HolographicFrame>
{
    using abi = ABI::Windows::Graphics::Holographic::HolographicFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Holographic.HolographicFrame"; }
};

template <> struct traits<Windows::Graphics::Holographic::HolographicFramePrediction>
{
    using abi = ABI::Windows::Graphics::Holographic::HolographicFramePrediction;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Holographic.HolographicFramePrediction"; }
};

template <> struct traits<Windows::Graphics::Holographic::HolographicSpace>
{
    using abi = ABI::Windows::Graphics::Holographic::HolographicSpace;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Holographic.HolographicSpace"; }
};

template <> struct traits<Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs>
{
    using abi = ABI::Windows::Graphics::Holographic::HolographicSpaceCameraAddedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Holographic.HolographicSpaceCameraAddedEventArgs"; }
};

template <> struct traits<Windows::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs>
{
    using abi = ABI::Windows::Graphics::Holographic::HolographicSpaceCameraRemovedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Holographic.HolographicSpaceCameraRemovedEventArgs"; }
};

}

}
