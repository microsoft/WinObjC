// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Media.Capture.3.h"
#include "internal/Windows.Devices.Enumeration.3.h"
#include "internal/Windows.Perception.Spatial.3.h"
#include "internal/Windows.Media.Devices.Core.3.h"
#include "internal/Windows.Media.Devices.3.h"
#include "internal/Windows.Media.MediaProperties.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Graphics.Imaging.3.h"
#include "internal/Windows.Graphics.DirectX.Direct3D11.3.h"
#include "internal/Windows.Media.3.h"
#include "internal/Windows.Media.Capture.Frames.3.h"
#include "Windows.Media.Capture.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::Capture::Frames::IBufferMediaFrame> : produce_base<D, Windows::Media::Capture::Frames::IBufferMediaFrame>
{
    HRESULT __stdcall get_FrameReference(impl::abi_arg_out<Windows::Media::Capture::Frames::IMediaFrameReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameReference());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Buffer(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Buffer());
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
struct produce<D, Windows::Media::Capture::Frames::IDepthMediaFrame> : produce_base<D, Windows::Media::Capture::Frames::IDepthMediaFrame>
{
    HRESULT __stdcall get_FrameReference(impl::abi_arg_out<Windows::Media::Capture::Frames::IMediaFrameReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameReference());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoMediaFrame(impl::abi_arg_out<Windows::Media::Capture::Frames::IVideoMediaFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoMediaFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DepthFormat(impl::abi_arg_out<Windows::Media::Capture::Frames::IDepthMediaFrameFormat> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DepthFormat());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryCreateCoordinateMapper(impl::abi_arg_in<Windows::Media::Devices::Core::ICameraIntrinsics> cameraIntrinsics, impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_out<Windows::Media::Devices::Core::IDepthCorrelatedCoordinateMapper> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryCreateCoordinateMapper(*reinterpret_cast<const Windows::Media::Devices::Core::CameraIntrinsics *>(&cameraIntrinsics), *reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem)));
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
struct produce<D, Windows::Media::Capture::Frames::IDepthMediaFrameFormat> : produce_base<D, Windows::Media::Capture::Frames::IDepthMediaFrameFormat>
{
    HRESULT __stdcall get_VideoFormat(impl::abi_arg_out<Windows::Media::Capture::Frames::IVideoMediaFrameFormat> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoFormat());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DepthScaleInMeters(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DepthScaleInMeters());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::Frames::IInfraredMediaFrame> : produce_base<D, Windows::Media::Capture::Frames::IInfraredMediaFrame>
{
    HRESULT __stdcall get_FrameReference(impl::abi_arg_out<Windows::Media::Capture::Frames::IMediaFrameReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameReference());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoMediaFrame(impl::abi_arg_out<Windows::Media::Capture::Frames::IVideoMediaFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoMediaFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsIlluminated(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsIlluminated());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::Frames::IMediaFrameArrivedEventArgs> : produce_base<D, Windows::Media::Capture::Frames::IMediaFrameArrivedEventArgs>
{};

template <typename D>
struct produce<D, Windows::Media::Capture::Frames::IMediaFrameFormat> : produce_base<D, Windows::Media::Capture::Frames::IMediaFrameFormat>
{
    HRESULT __stdcall get_MajorType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MajorType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Subtype(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subtype());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrameRate(impl::abi_arg_out<Windows::Media::MediaProperties::IMediaRatio> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameRate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoFormat(impl::abi_arg_out<Windows::Media::Capture::Frames::IVideoMediaFrameFormat> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoFormat());
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
struct produce<D, Windows::Media::Capture::Frames::IMediaFrameReader> : produce_base<D, Windows::Media::Capture::Frames::IMediaFrameReader>
{
    HRESULT __stdcall add_FrameArrived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Frames::MediaFrameReader, Windows::Media::Capture::Frames::MediaFrameArrivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().FrameArrived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Frames::MediaFrameReader, Windows::Media::Capture::Frames::MediaFrameArrivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_FrameArrived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FrameArrived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryAcquireLatestFrame(impl::abi_arg_out<Windows::Media::Capture::Frames::IMediaFrameReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryAcquireLatestFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Capture::Frames::MediaFrameReaderStartStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StartAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_abi(this->shim().StopAsync());
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Capture::Frames::IMediaFrameReference> : produce_base<D, Windows::Media::Capture::Frames::IMediaFrameReference>
{
    HRESULT __stdcall get_SourceKind(Windows::Media::Capture::Frames::MediaFrameSourceKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Format(impl::abi_arg_out<Windows::Media::Capture::Frames::IMediaFrameFormat> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Format());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemRelativeTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemRelativeTime());
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

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BufferMediaFrame(impl::abi_arg_out<Windows::Media::Capture::Frames::IBufferMediaFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BufferMediaFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoMediaFrame(impl::abi_arg_out<Windows::Media::Capture::Frames::IVideoMediaFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoMediaFrame());
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
};

template <typename D>
struct produce<D, Windows::Media::Capture::Frames::IMediaFrameSource> : produce_base<D, Windows::Media::Capture::Frames::IMediaFrameSource>
{
    HRESULT __stdcall get_Info(impl::abi_arg_out<Windows::Media::Capture::Frames::IMediaFrameSourceInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Info());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Controller(impl::abi_arg_out<Windows::Media::Capture::Frames::IMediaFrameSourceController> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Controller());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedFormats(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameFormat>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedFormats());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentFormat(impl::abi_arg_out<Windows::Media::Capture::Frames::IMediaFrameFormat> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentFormat());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetFormatAsync(impl::abi_arg_in<Windows::Media::Capture::Frames::IMediaFrameFormat> format, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SetFormatAsync(*reinterpret_cast<const Windows::Media::Capture::Frames::MediaFrameFormat *>(&format)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_FormatChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Frames::MediaFrameSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().FormatChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Frames::MediaFrameSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_FormatChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FormatChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetCameraIntrinsics(impl::abi_arg_in<Windows::Media::Capture::Frames::IMediaFrameFormat> format, impl::abi_arg_out<Windows::Media::Devices::Core::ICameraIntrinsics> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryGetCameraIntrinsics(*reinterpret_cast<const Windows::Media::Capture::Frames::MediaFrameFormat *>(&format)));
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
struct produce<D, Windows::Media::Capture::Frames::IMediaFrameSourceController> : produce_base<D, Windows::Media::Capture::Frames::IMediaFrameSourceController>
{
    HRESULT __stdcall abi_GetPropertyAsync(impl::abi_arg_in<hstring> propertyId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetPropertyAsync(*reinterpret_cast<const hstring *>(&propertyId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyAsync(impl::abi_arg_in<hstring> propertyId, impl::abi_arg_in<Windows::Foundation::IInspectable> propertyValue, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SetPropertyAsync(*reinterpret_cast<const hstring *>(&propertyId), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&propertyValue)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoDeviceController(impl::abi_arg_out<Windows::Media::Devices::IVideoDeviceController> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoDeviceController());
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
struct produce<D, Windows::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult> : produce_base<D, Windows::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult>
{
    HRESULT __stdcall get_Status(Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
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
struct produce<D, Windows::Media::Capture::Frames::IMediaFrameSourceGroup> : produce_base<D, Windows::Media::Capture::Frames::IMediaFrameSourceGroup>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceInfos(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameSourceInfo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceInfos());
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
struct produce<D, Windows::Media::Capture::Frames::IMediaFrameSourceGroupStatics> : produce_base<D, Windows::Media::Capture::Frames::IMediaFrameSourceGroupStatics>
{
    HRESULT __stdcall abi_FindAllAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameSourceGroup>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FindAllAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameSourceGroup>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector());
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
struct produce<D, Windows::Media::Capture::Frames::IMediaFrameSourceInfo> : produce_base<D, Windows::Media::Capture::Frames::IMediaFrameSourceInfo>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaStreamType(Windows::Media::Capture::MediaStreamType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaStreamType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceKind(Windows::Media::Capture::Frames::MediaFrameSourceKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceGroup(impl::abi_arg_out<Windows::Media::Capture::Frames::IMediaFrameSourceGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceGroup());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceInformation(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
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
};

template <typename D>
struct produce<D, Windows::Media::Capture::Frames::IVideoMediaFrame> : produce_base<D, Windows::Media::Capture::Frames::IVideoMediaFrame>
{
    HRESULT __stdcall get_FrameReference(impl::abi_arg_out<Windows::Media::Capture::Frames::IMediaFrameReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameReference());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoFormat(impl::abi_arg_out<Windows::Media::Capture::Frames::IVideoMediaFrameFormat> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoFormat());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SoftwareBitmap(impl::abi_arg_out<Windows::Graphics::Imaging::ISoftwareBitmap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SoftwareBitmap());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Direct3DSurface(impl::abi_arg_out<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Direct3DSurface());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CameraIntrinsics(impl::abi_arg_out<Windows::Media::Devices::Core::ICameraIntrinsics> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CameraIntrinsics());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InfraredMediaFrame(impl::abi_arg_out<Windows::Media::Capture::Frames::IInfraredMediaFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InfraredMediaFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DepthMediaFrame(impl::abi_arg_out<Windows::Media::Capture::Frames::IDepthMediaFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DepthMediaFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetVideoFrame(impl::abi_arg_out<Windows::Media::IVideoFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetVideoFrame());
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
struct produce<D, Windows::Media::Capture::Frames::IVideoMediaFrameFormat> : produce_base<D, Windows::Media::Capture::Frames::IVideoMediaFrameFormat>
{
    HRESULT __stdcall get_MediaFrameFormat(impl::abi_arg_out<Windows::Media::Capture::Frames::IMediaFrameFormat> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaFrameFormat());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DepthFormat(impl::abi_arg_out<Windows::Media::Capture::Frames::IDepthMediaFrameFormat> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DepthFormat());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Width(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Width());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Height(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Height());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::Capture::Frames {

template <typename D> hstring impl_IMediaFrameSourceGroup<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaFrameSourceGroup)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMediaFrameSourceGroup<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaFrameSourceGroup)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameSourceInfo> impl_IMediaFrameSourceGroup<D>::SourceInfos() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameSourceInfo> value;
    check_hresult(WINRT_SHIM(IMediaFrameSourceGroup)->get_SourceInfos(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameSourceGroup>> impl_IMediaFrameSourceGroupStatics<D>::FindAllAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameSourceGroup>> value;
    check_hresult(WINRT_SHIM(IMediaFrameSourceGroupStatics)->abi_FindAllAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameSourceGroup> impl_IMediaFrameSourceGroupStatics<D>::FromIdAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameSourceGroup> value;
    check_hresult(WINRT_SHIM(IMediaFrameSourceGroupStatics)->abi_FromIdAsync(get_abi(id), put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMediaFrameSourceGroupStatics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaFrameSourceGroupStatics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMediaFrameSourceInfo<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaFrameSourceInfo)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::MediaStreamType impl_IMediaFrameSourceInfo<D>::MediaStreamType() const
{
    Windows::Media::Capture::MediaStreamType value {};
    check_hresult(WINRT_SHIM(IMediaFrameSourceInfo)->get_MediaStreamType(&value));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameSourceKind impl_IMediaFrameSourceInfo<D>::SourceKind() const
{
    Windows::Media::Capture::Frames::MediaFrameSourceKind value {};
    check_hresult(WINRT_SHIM(IMediaFrameSourceInfo)->get_SourceKind(&value));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameSourceGroup impl_IMediaFrameSourceInfo<D>::SourceGroup() const
{
    Windows::Media::Capture::Frames::MediaFrameSourceGroup value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameSourceInfo)->get_SourceGroup(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IMediaFrameSourceInfo<D>::DeviceInformation() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameSourceInfo)->get_DeviceInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable> impl_IMediaFrameSourceInfo<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IMediaFrameSourceInfo)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialCoordinateSystem impl_IMediaFrameSourceInfo<D>::CoordinateSystem() const
{
    Windows::Perception::Spatial::SpatialCoordinateSystem value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameSourceInfo)->get_CoordinateSystem(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameSourceInfo impl_IMediaFrameSource<D>::Info() const
{
    Windows::Media::Capture::Frames::MediaFrameSourceInfo value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameSource)->get_Info(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameSourceController impl_IMediaFrameSource<D>::Controller() const
{
    Windows::Media::Capture::Frames::MediaFrameSourceController value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameSource)->get_Controller(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameFormat> impl_IMediaFrameSource<D>::SupportedFormats() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameFormat> value;
    check_hresult(WINRT_SHIM(IMediaFrameSource)->get_SupportedFormats(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameFormat impl_IMediaFrameSource<D>::CurrentFormat() const
{
    Windows::Media::Capture::Frames::MediaFrameFormat value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameSource)->get_CurrentFormat(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaFrameSource<D>::SetFormatAsync(const Windows::Media::Capture::Frames::MediaFrameFormat & format) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IMediaFrameSource)->abi_SetFormatAsync(get_abi(format), put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMediaFrameSource<D>::FormatChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Frames::MediaFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaFrameSource)->add_FormatChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaFrameSource> impl_IMediaFrameSource<D>::FormatChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Frames::MediaFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaFrameSource>(this, &ABI::Windows::Media::Capture::Frames::IMediaFrameSource::remove_FormatChanged, FormatChanged(handler));
}

template <typename D> void impl_IMediaFrameSource<D>::FormatChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaFrameSource)->remove_FormatChanged(token));
}

template <typename D> Windows::Media::Devices::Core::CameraIntrinsics impl_IMediaFrameSource<D>::TryGetCameraIntrinsics(const Windows::Media::Capture::Frames::MediaFrameFormat & format) const
{
    Windows::Media::Devices::Core::CameraIntrinsics value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameSource)->abi_TryGetCameraIntrinsics(get_abi(format), put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMediaFrameReader<D>::FrameArrived(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Frames::MediaFrameReader, Windows::Media::Capture::Frames::MediaFrameArrivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaFrameReader)->add_FrameArrived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaFrameReader> impl_IMediaFrameReader<D>::FrameArrived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Frames::MediaFrameReader, Windows::Media::Capture::Frames::MediaFrameArrivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaFrameReader>(this, &ABI::Windows::Media::Capture::Frames::IMediaFrameReader::remove_FrameArrived, FrameArrived(handler));
}

template <typename D> void impl_IMediaFrameReader<D>::FrameArrived(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaFrameReader)->remove_FrameArrived(token));
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameReference impl_IMediaFrameReader<D>::TryAcquireLatestFrame() const
{
    Windows::Media::Capture::Frames::MediaFrameReference value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameReader)->abi_TryAcquireLatestFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Capture::Frames::MediaFrameReaderStartStatus> impl_IMediaFrameReader<D>::StartAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Capture::Frames::MediaFrameReaderStartStatus> operation;
    check_hresult(WINRT_SHIM(IMediaFrameReader)->abi_StartAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMediaFrameReader<D>::StopAsync() const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(WINRT_SHIM(IMediaFrameReader)->abi_StopAsync(put_abi(action)));
    return action;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyResult> impl_IMediaFrameSourceController<D>::GetPropertyAsync(hstring_view propertyId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyResult> value;
    check_hresult(WINRT_SHIM(IMediaFrameSourceController)->abi_GetPropertyAsync(get_abi(propertyId), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus> impl_IMediaFrameSourceController<D>::SetPropertyAsync(hstring_view propertyId, const Windows::Foundation::IInspectable & propertyValue) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus> value;
    check_hresult(WINRT_SHIM(IMediaFrameSourceController)->abi_SetPropertyAsync(get_abi(propertyId), get_abi(propertyValue), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::VideoDeviceController impl_IMediaFrameSourceController<D>::VideoDeviceController() const
{
    Windows::Media::Devices::VideoDeviceController value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameSourceController)->get_VideoDeviceController(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyStatus impl_IMediaFrameSourceGetPropertyResult<D>::Status() const
{
    Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyStatus value {};
    check_hresult(WINRT_SHIM(IMediaFrameSourceGetPropertyResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IMediaFrameSourceGetPropertyResult<D>::Value() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IMediaFrameSourceGetPropertyResult)->get_Value(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMediaFrameFormat<D>::MajorType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaFrameFormat)->get_MajorType(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMediaFrameFormat<D>::Subtype() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaFrameFormat)->get_Subtype(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::MediaProperties::MediaRatio impl_IMediaFrameFormat<D>::FrameRate() const
{
    Windows::Media::MediaProperties::MediaRatio value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameFormat)->get_FrameRate(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable> impl_IMediaFrameFormat<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IMediaFrameFormat)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::VideoMediaFrameFormat impl_IMediaFrameFormat<D>::VideoFormat() const
{
    Windows::Media::Capture::Frames::VideoMediaFrameFormat value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameFormat)->get_VideoFormat(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameFormat impl_IVideoMediaFrameFormat<D>::MediaFrameFormat() const
{
    Windows::Media::Capture::Frames::MediaFrameFormat value { nullptr };
    check_hresult(WINRT_SHIM(IVideoMediaFrameFormat)->get_MediaFrameFormat(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::DepthMediaFrameFormat impl_IVideoMediaFrameFormat<D>::DepthFormat() const
{
    Windows::Media::Capture::Frames::DepthMediaFrameFormat value { nullptr };
    check_hresult(WINRT_SHIM(IVideoMediaFrameFormat)->get_DepthFormat(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IVideoMediaFrameFormat<D>::Width() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IVideoMediaFrameFormat)->get_Width(&value));
    return value;
}

template <typename D> uint32_t impl_IVideoMediaFrameFormat<D>::Height() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IVideoMediaFrameFormat)->get_Height(&value));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameSourceKind impl_IMediaFrameReference<D>::SourceKind() const
{
    Windows::Media::Capture::Frames::MediaFrameSourceKind value {};
    check_hresult(WINRT_SHIM(IMediaFrameReference)->get_SourceKind(&value));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameFormat impl_IMediaFrameReference<D>::Format() const
{
    Windows::Media::Capture::Frames::MediaFrameFormat value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameReference)->get_Format(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IMediaFrameReference<D>::SystemRelativeTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IMediaFrameReference)->get_SystemRelativeTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaFrameReference<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaFrameReference)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable> impl_IMediaFrameReference<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IMediaFrameReference)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::BufferMediaFrame impl_IMediaFrameReference<D>::BufferMediaFrame() const
{
    Windows::Media::Capture::Frames::BufferMediaFrame value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameReference)->get_BufferMediaFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::VideoMediaFrame impl_IMediaFrameReference<D>::VideoMediaFrame() const
{
    Windows::Media::Capture::Frames::VideoMediaFrame value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameReference)->get_VideoMediaFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialCoordinateSystem impl_IMediaFrameReference<D>::CoordinateSystem() const
{
    Windows::Perception::Spatial::SpatialCoordinateSystem value { nullptr };
    check_hresult(WINRT_SHIM(IMediaFrameReference)->get_CoordinateSystem(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameReference impl_IBufferMediaFrame<D>::FrameReference() const
{
    Windows::Media::Capture::Frames::MediaFrameReference value { nullptr };
    check_hresult(WINRT_SHIM(IBufferMediaFrame)->get_FrameReference(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IBufferMediaFrame<D>::Buffer() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IBufferMediaFrame)->get_Buffer(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameReference impl_IVideoMediaFrame<D>::FrameReference() const
{
    Windows::Media::Capture::Frames::MediaFrameReference value { nullptr };
    check_hresult(WINRT_SHIM(IVideoMediaFrame)->get_FrameReference(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::VideoMediaFrameFormat impl_IVideoMediaFrame<D>::VideoFormat() const
{
    Windows::Media::Capture::Frames::VideoMediaFrameFormat value { nullptr };
    check_hresult(WINRT_SHIM(IVideoMediaFrame)->get_VideoFormat(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Imaging::SoftwareBitmap impl_IVideoMediaFrame<D>::SoftwareBitmap() const
{
    Windows::Graphics::Imaging::SoftwareBitmap value { nullptr };
    check_hresult(WINRT_SHIM(IVideoMediaFrame)->get_SoftwareBitmap(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface impl_IVideoMediaFrame<D>::Direct3DSurface() const
{
    Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface value;
    check_hresult(WINRT_SHIM(IVideoMediaFrame)->get_Direct3DSurface(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::Core::CameraIntrinsics impl_IVideoMediaFrame<D>::CameraIntrinsics() const
{
    Windows::Media::Devices::Core::CameraIntrinsics value { nullptr };
    check_hresult(WINRT_SHIM(IVideoMediaFrame)->get_CameraIntrinsics(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::InfraredMediaFrame impl_IVideoMediaFrame<D>::InfraredMediaFrame() const
{
    Windows::Media::Capture::Frames::InfraredMediaFrame value { nullptr };
    check_hresult(WINRT_SHIM(IVideoMediaFrame)->get_InfraredMediaFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::DepthMediaFrame impl_IVideoMediaFrame<D>::DepthMediaFrame() const
{
    Windows::Media::Capture::Frames::DepthMediaFrame value { nullptr };
    check_hresult(WINRT_SHIM(IVideoMediaFrame)->get_DepthMediaFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::VideoFrame impl_IVideoMediaFrame<D>::GetVideoFrame() const
{
    Windows::Media::VideoFrame value { nullptr };
    check_hresult(WINRT_SHIM(IVideoMediaFrame)->abi_GetVideoFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameReference impl_IInfraredMediaFrame<D>::FrameReference() const
{
    Windows::Media::Capture::Frames::MediaFrameReference value { nullptr };
    check_hresult(WINRT_SHIM(IInfraredMediaFrame)->get_FrameReference(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::VideoMediaFrame impl_IInfraredMediaFrame<D>::VideoMediaFrame() const
{
    Windows::Media::Capture::Frames::VideoMediaFrame value { nullptr };
    check_hresult(WINRT_SHIM(IInfraredMediaFrame)->get_VideoMediaFrame(put_abi(value)));
    return value;
}

template <typename D> bool impl_IInfraredMediaFrame<D>::IsIlluminated() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IInfraredMediaFrame)->get_IsIlluminated(&value));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::MediaFrameReference impl_IDepthMediaFrame<D>::FrameReference() const
{
    Windows::Media::Capture::Frames::MediaFrameReference value { nullptr };
    check_hresult(WINRT_SHIM(IDepthMediaFrame)->get_FrameReference(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::VideoMediaFrame impl_IDepthMediaFrame<D>::VideoMediaFrame() const
{
    Windows::Media::Capture::Frames::VideoMediaFrame value { nullptr };
    check_hresult(WINRT_SHIM(IDepthMediaFrame)->get_VideoMediaFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::DepthMediaFrameFormat impl_IDepthMediaFrame<D>::DepthFormat() const
{
    Windows::Media::Capture::Frames::DepthMediaFrameFormat value { nullptr };
    check_hresult(WINRT_SHIM(IDepthMediaFrame)->get_DepthFormat(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::Core::DepthCorrelatedCoordinateMapper impl_IDepthMediaFrame<D>::TryCreateCoordinateMapper(const Windows::Media::Devices::Core::CameraIntrinsics & cameraIntrinsics, const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem) const
{
    Windows::Media::Devices::Core::DepthCorrelatedCoordinateMapper value { nullptr };
    check_hresult(WINRT_SHIM(IDepthMediaFrame)->abi_TryCreateCoordinateMapper(get_abi(cameraIntrinsics), get_abi(coordinateSystem), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::Frames::VideoMediaFrameFormat impl_IDepthMediaFrameFormat<D>::VideoFormat() const
{
    Windows::Media::Capture::Frames::VideoMediaFrameFormat value { nullptr };
    check_hresult(WINRT_SHIM(IDepthMediaFrameFormat)->get_VideoFormat(put_abi(value)));
    return value;
}

template <typename D> double impl_IDepthMediaFrameFormat<D>::DepthScaleInMeters() const
{
    double value {};
    check_hresult(WINRT_SHIM(IDepthMediaFrameFormat)->get_DepthScaleInMeters(&value));
    return value;
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameSourceGroup>> MediaFrameSourceGroup::FindAllAsync()
{
    return get_activation_factory<MediaFrameSourceGroup, IMediaFrameSourceGroupStatics>().FindAllAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameSourceGroup> MediaFrameSourceGroup::FromIdAsync(hstring_view id)
{
    return get_activation_factory<MediaFrameSourceGroup, IMediaFrameSourceGroupStatics>().FromIdAsync(id);
}

inline hstring MediaFrameSourceGroup::GetDeviceSelector()
{
    return get_activation_factory<MediaFrameSourceGroup, IMediaFrameSourceGroupStatics>().GetDeviceSelector();
}

}

}
#pragma warning(pop)
