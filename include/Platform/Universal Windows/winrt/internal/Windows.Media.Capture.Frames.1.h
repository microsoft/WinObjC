// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.Capture.Frames.0.h"
#include "Windows.Devices.Enumeration.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Graphics.DirectX.Direct3D11.0.h"
#include "Windows.Graphics.Imaging.0.h"
#include "Windows.Media.0.h"
#include "Windows.Media.Capture.0.h"
#include "Windows.Media.Devices.0.h"
#include "Windows.Media.Devices.Core.0.h"
#include "Windows.Media.MediaProperties.0.h"
#include "Windows.Perception.Spatial.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Capture::Frames {

struct __declspec(uuid("b5b153c7-9b84-4062-b79c-a365b2596854")) __declspec(novtable) IBufferMediaFrame : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameReference(Windows::Media::Capture::Frames::IMediaFrameReference ** value) = 0;
    virtual HRESULT __stdcall get_Buffer(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("47135e4f-8549-45c0-925b-80d35efdb10a")) __declspec(novtable) IDepthMediaFrame : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameReference(Windows::Media::Capture::Frames::IMediaFrameReference ** value) = 0;
    virtual HRESULT __stdcall get_VideoMediaFrame(Windows::Media::Capture::Frames::IVideoMediaFrame ** value) = 0;
    virtual HRESULT __stdcall get_DepthFormat(Windows::Media::Capture::Frames::IDepthMediaFrameFormat ** value) = 0;
    virtual HRESULT __stdcall abi_TryCreateCoordinateMapper(Windows::Media::Devices::Core::ICameraIntrinsics * cameraIntrinsics, Windows::Perception::Spatial::ISpatialCoordinateSystem * coordinateSystem, Windows::Media::Devices::Core::IDepthCorrelatedCoordinateMapper ** value) = 0;
};

struct __declspec(uuid("c312cf40-d729-453e-8780-2e04f140d28e")) __declspec(novtable) IDepthMediaFrameFormat : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_VideoFormat(Windows::Media::Capture::Frames::IVideoMediaFrameFormat ** value) = 0;
    virtual HRESULT __stdcall get_DepthScaleInMeters(double * value) = 0;
};

struct __declspec(uuid("3fd13503-004b-4f0e-91ac-465299b41658")) __declspec(novtable) IInfraredMediaFrame : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameReference(Windows::Media::Capture::Frames::IMediaFrameReference ** value) = 0;
    virtual HRESULT __stdcall get_VideoMediaFrame(Windows::Media::Capture::Frames::IVideoMediaFrame ** value) = 0;
    virtual HRESULT __stdcall get_IsIlluminated(bool * value) = 0;
};

struct __declspec(uuid("0b430add-a490-4435-ada1-9affd55239f7")) __declspec(novtable) IMediaFrameArrivedEventArgs : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("71902b4e-b279-4a97-a9db-bd5a2fb78f39")) __declspec(novtable) IMediaFrameFormat : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MajorType(hstring * value) = 0;
    virtual HRESULT __stdcall get_Subtype(hstring * value) = 0;
    virtual HRESULT __stdcall get_FrameRate(Windows::Media::MediaProperties::IMediaRatio ** value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_VideoFormat(Windows::Media::Capture::Frames::IVideoMediaFrameFormat ** value) = 0;
};

struct __declspec(uuid("e4c94395-2028-48ed-90b0-d1c1b162e24c")) __declspec(novtable) IMediaFrameReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_FrameArrived(Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Frames::MediaFrameReader, Windows::Media::Capture::Frames::MediaFrameArrivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FrameArrived(event_token token) = 0;
    virtual HRESULT __stdcall abi_TryAcquireLatestFrame(Windows::Media::Capture::Frames::IMediaFrameReference ** value) = 0;
    virtual HRESULT __stdcall abi_StartAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Capture::Frames::MediaFrameReaderStartStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_StopAsync(Windows::Foundation::IAsyncAction ** action) = 0;
};

struct __declspec(uuid("f6b88641-f0dc-4044-8dc9-961cedd05bad")) __declspec(novtable) IMediaFrameReference : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SourceKind(winrt::Windows::Media::Capture::Frames::MediaFrameSourceKind * value) = 0;
    virtual HRESULT __stdcall get_Format(Windows::Media::Capture::Frames::IMediaFrameFormat ** value) = 0;
    virtual HRESULT __stdcall get_SystemRelativeTime(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall get_Duration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_BufferMediaFrame(Windows::Media::Capture::Frames::IBufferMediaFrame ** value) = 0;
    virtual HRESULT __stdcall get_VideoMediaFrame(Windows::Media::Capture::Frames::IVideoMediaFrame ** value) = 0;
    virtual HRESULT __stdcall get_CoordinateSystem(Windows::Perception::Spatial::ISpatialCoordinateSystem ** value) = 0;
};

struct __declspec(uuid("d6782953-90db-46a8-8add-2aa884a8d253")) __declspec(novtable) IMediaFrameSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Info(Windows::Media::Capture::Frames::IMediaFrameSourceInfo ** value) = 0;
    virtual HRESULT __stdcall get_Controller(Windows::Media::Capture::Frames::IMediaFrameSourceController ** value) = 0;
    virtual HRESULT __stdcall get_SupportedFormats(Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameFormat> ** value) = 0;
    virtual HRESULT __stdcall get_CurrentFormat(Windows::Media::Capture::Frames::IMediaFrameFormat ** value) = 0;
    virtual HRESULT __stdcall abi_SetFormatAsync(Windows::Media::Capture::Frames::IMediaFrameFormat * format, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall add_FormatChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Frames::MediaFrameSource, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FormatChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_TryGetCameraIntrinsics(Windows::Media::Capture::Frames::IMediaFrameFormat * format, Windows::Media::Devices::Core::ICameraIntrinsics ** value) = 0;
};

struct __declspec(uuid("6d076635-316d-4b8f-b7b6-eeb04a8c6525")) __declspec(novtable) IMediaFrameSourceController : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetPropertyAsync(hstring propertyId, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyResult> ** value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyAsync(hstring propertyId, Windows::Foundation::IInspectable * propertyValue, Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus> ** value) = 0;
    virtual HRESULT __stdcall get_VideoDeviceController(Windows::Media::Devices::IVideoDeviceController ** value) = 0;
};

struct __declspec(uuid("088616c2-3a64-4bd5-bd2b-e7c898d2f37a")) __declspec(novtable) IMediaFrameSourceGetPropertyResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyStatus * value) = 0;
    virtual HRESULT __stdcall get_Value(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("7f605b87-4832-4b5f-ae3d-412faab37d34")) __declspec(novtable) IMediaFrameSourceGroup : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_SourceInfos(Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameSourceInfo> ** value) = 0;
};

struct __declspec(uuid("1c48bfc5-436f-4508-94cf-d5d8b7326445")) __declspec(novtable) IMediaFrameSourceGroupStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindAllAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameSourceGroup>> ** value) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameSourceGroup> ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * value) = 0;
};

struct __declspec(uuid("87bdc9cd-4601-408f-91cf-038318cd0af3")) __declspec(novtable) IMediaFrameSourceInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_MediaStreamType(winrt::Windows::Media::Capture::MediaStreamType * value) = 0;
    virtual HRESULT __stdcall get_SourceKind(winrt::Windows::Media::Capture::Frames::MediaFrameSourceKind * value) = 0;
    virtual HRESULT __stdcall get_SourceGroup(Windows::Media::Capture::Frames::IMediaFrameSourceGroup ** value) = 0;
    virtual HRESULT __stdcall get_DeviceInformation(Windows::Devices::Enumeration::IDeviceInformation ** value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_CoordinateSystem(Windows::Perception::Spatial::ISpatialCoordinateSystem ** value) = 0;
};

struct __declspec(uuid("00dd4ccb-32bd-4fe1-a013-7cc13cf5dbcf")) __declspec(novtable) IVideoMediaFrame : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameReference(Windows::Media::Capture::Frames::IMediaFrameReference ** value) = 0;
    virtual HRESULT __stdcall get_VideoFormat(Windows::Media::Capture::Frames::IVideoMediaFrameFormat ** value) = 0;
    virtual HRESULT __stdcall get_SoftwareBitmap(Windows::Graphics::Imaging::ISoftwareBitmap ** value) = 0;
    virtual HRESULT __stdcall get_Direct3DSurface(Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface ** value) = 0;
    virtual HRESULT __stdcall get_CameraIntrinsics(Windows::Media::Devices::Core::ICameraIntrinsics ** value) = 0;
    virtual HRESULT __stdcall get_InfraredMediaFrame(Windows::Media::Capture::Frames::IInfraredMediaFrame ** value) = 0;
    virtual HRESULT __stdcall get_DepthMediaFrame(Windows::Media::Capture::Frames::IDepthMediaFrame ** value) = 0;
    virtual HRESULT __stdcall abi_GetVideoFrame(Windows::Media::IVideoFrame ** value) = 0;
};

struct __declspec(uuid("46027fc0-d71b-45c7-8f14-6d9a0ae604e4")) __declspec(novtable) IVideoMediaFrameFormat : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MediaFrameFormat(Windows::Media::Capture::Frames::IMediaFrameFormat ** value) = 0;
    virtual HRESULT __stdcall get_DepthFormat(Windows::Media::Capture::Frames::IDepthMediaFrameFormat ** value) = 0;
    virtual HRESULT __stdcall get_Width(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Height(uint32_t * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::Capture::Frames::BufferMediaFrame> { using default_interface = Windows::Media::Capture::Frames::IBufferMediaFrame; };
template <> struct traits<Windows::Media::Capture::Frames::DepthMediaFrame> { using default_interface = Windows::Media::Capture::Frames::IDepthMediaFrame; };
template <> struct traits<Windows::Media::Capture::Frames::DepthMediaFrameFormat> { using default_interface = Windows::Media::Capture::Frames::IDepthMediaFrameFormat; };
template <> struct traits<Windows::Media::Capture::Frames::InfraredMediaFrame> { using default_interface = Windows::Media::Capture::Frames::IInfraredMediaFrame; };
template <> struct traits<Windows::Media::Capture::Frames::MediaFrameArrivedEventArgs> { using default_interface = Windows::Media::Capture::Frames::IMediaFrameArrivedEventArgs; };
template <> struct traits<Windows::Media::Capture::Frames::MediaFrameFormat> { using default_interface = Windows::Media::Capture::Frames::IMediaFrameFormat; };
template <> struct traits<Windows::Media::Capture::Frames::MediaFrameReader> { using default_interface = Windows::Media::Capture::Frames::IMediaFrameReader; };
template <> struct traits<Windows::Media::Capture::Frames::MediaFrameReference> { using default_interface = Windows::Media::Capture::Frames::IMediaFrameReference; };
template <> struct traits<Windows::Media::Capture::Frames::MediaFrameSource> { using default_interface = Windows::Media::Capture::Frames::IMediaFrameSource; };
template <> struct traits<Windows::Media::Capture::Frames::MediaFrameSourceController> { using default_interface = Windows::Media::Capture::Frames::IMediaFrameSourceController; };
template <> struct traits<Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyResult> { using default_interface = Windows::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult; };
template <> struct traits<Windows::Media::Capture::Frames::MediaFrameSourceGroup> { using default_interface = Windows::Media::Capture::Frames::IMediaFrameSourceGroup; };
template <> struct traits<Windows::Media::Capture::Frames::MediaFrameSourceInfo> { using default_interface = Windows::Media::Capture::Frames::IMediaFrameSourceInfo; };
template <> struct traits<Windows::Media::Capture::Frames::VideoMediaFrame> { using default_interface = Windows::Media::Capture::Frames::IVideoMediaFrame; };
template <> struct traits<Windows::Media::Capture::Frames::VideoMediaFrameFormat> { using default_interface = Windows::Media::Capture::Frames::IVideoMediaFrameFormat; };

}

namespace Windows::Media::Capture::Frames {

template <typename D>
struct WINRT_EBO impl_IBufferMediaFrame
{
    Windows::Media::Capture::Frames::MediaFrameReference FrameReference() const;
    Windows::Storage::Streams::IBuffer Buffer() const;
};

template <typename D>
struct WINRT_EBO impl_IDepthMediaFrame
{
    Windows::Media::Capture::Frames::MediaFrameReference FrameReference() const;
    Windows::Media::Capture::Frames::VideoMediaFrame VideoMediaFrame() const;
    Windows::Media::Capture::Frames::DepthMediaFrameFormat DepthFormat() const;
    Windows::Media::Devices::Core::DepthCorrelatedCoordinateMapper TryCreateCoordinateMapper(const Windows::Media::Devices::Core::CameraIntrinsics & cameraIntrinsics, const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem) const;
};

template <typename D>
struct WINRT_EBO impl_IDepthMediaFrameFormat
{
    Windows::Media::Capture::Frames::VideoMediaFrameFormat VideoFormat() const;
    double DepthScaleInMeters() const;
};

template <typename D>
struct WINRT_EBO impl_IInfraredMediaFrame
{
    Windows::Media::Capture::Frames::MediaFrameReference FrameReference() const;
    Windows::Media::Capture::Frames::VideoMediaFrame VideoMediaFrame() const;
    bool IsIlluminated() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaFrameArrivedEventArgs
{
};

template <typename D>
struct WINRT_EBO impl_IMediaFrameFormat
{
    hstring MajorType() const;
    hstring Subtype() const;
    Windows::Media::MediaProperties::MediaRatio FrameRate() const;
    Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable> Properties() const;
    Windows::Media::Capture::Frames::VideoMediaFrameFormat VideoFormat() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaFrameReader
{
    event_token FrameArrived(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Frames::MediaFrameReader, Windows::Media::Capture::Frames::MediaFrameArrivedEventArgs> & handler) const;
    using FrameArrived_revoker = event_revoker<IMediaFrameReader>;
    FrameArrived_revoker FrameArrived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Frames::MediaFrameReader, Windows::Media::Capture::Frames::MediaFrameArrivedEventArgs> & handler) const;
    void FrameArrived(event_token token) const;
    Windows::Media::Capture::Frames::MediaFrameReference TryAcquireLatestFrame() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Capture::Frames::MediaFrameReaderStartStatus> StartAsync() const;
    Windows::Foundation::IAsyncAction StopAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaFrameReference
{
    Windows::Media::Capture::Frames::MediaFrameSourceKind SourceKind() const;
    Windows::Media::Capture::Frames::MediaFrameFormat Format() const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> SystemRelativeTime() const;
    Windows::Foundation::TimeSpan Duration() const;
    Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable> Properties() const;
    Windows::Media::Capture::Frames::BufferMediaFrame BufferMediaFrame() const;
    Windows::Media::Capture::Frames::VideoMediaFrame VideoMediaFrame() const;
    Windows::Perception::Spatial::SpatialCoordinateSystem CoordinateSystem() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaFrameSource
{
    Windows::Media::Capture::Frames::MediaFrameSourceInfo Info() const;
    Windows::Media::Capture::Frames::MediaFrameSourceController Controller() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameFormat> SupportedFormats() const;
    Windows::Media::Capture::Frames::MediaFrameFormat CurrentFormat() const;
    Windows::Foundation::IAsyncAction SetFormatAsync(const Windows::Media::Capture::Frames::MediaFrameFormat & format) const;
    event_token FormatChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Frames::MediaFrameSource, Windows::Foundation::IInspectable> & handler) const;
    using FormatChanged_revoker = event_revoker<IMediaFrameSource>;
    FormatChanged_revoker FormatChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Capture::Frames::MediaFrameSource, Windows::Foundation::IInspectable> & handler) const;
    void FormatChanged(event_token token) const;
    Windows::Media::Devices::Core::CameraIntrinsics TryGetCameraIntrinsics(const Windows::Media::Capture::Frames::MediaFrameFormat & format) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaFrameSourceController
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyResult> GetPropertyAsync(hstring_view propertyId) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus> SetPropertyAsync(hstring_view propertyId, const Windows::Foundation::IInspectable & propertyValue) const;
    Windows::Media::Devices::VideoDeviceController VideoDeviceController() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaFrameSourceGetPropertyResult
{
    Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyStatus Status() const;
    Windows::Foundation::IInspectable Value() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaFrameSourceGroup
{
    hstring Id() const;
    hstring DisplayName() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameSourceInfo> SourceInfos() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaFrameSourceGroupStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameSourceGroup>> FindAllAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameSourceGroup> FromIdAsync(hstring_view id) const;
    hstring GetDeviceSelector() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaFrameSourceInfo
{
    hstring Id() const;
    Windows::Media::Capture::MediaStreamType MediaStreamType() const;
    Windows::Media::Capture::Frames::MediaFrameSourceKind SourceKind() const;
    Windows::Media::Capture::Frames::MediaFrameSourceGroup SourceGroup() const;
    Windows::Devices::Enumeration::DeviceInformation DeviceInformation() const;
    Windows::Foundation::Collections::IMapView<GUID, Windows::Foundation::IInspectable> Properties() const;
    Windows::Perception::Spatial::SpatialCoordinateSystem CoordinateSystem() const;
};

template <typename D>
struct WINRT_EBO impl_IVideoMediaFrame
{
    Windows::Media::Capture::Frames::MediaFrameReference FrameReference() const;
    Windows::Media::Capture::Frames::VideoMediaFrameFormat VideoFormat() const;
    Windows::Graphics::Imaging::SoftwareBitmap SoftwareBitmap() const;
    Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface Direct3DSurface() const;
    Windows::Media::Devices::Core::CameraIntrinsics CameraIntrinsics() const;
    Windows::Media::Capture::Frames::InfraredMediaFrame InfraredMediaFrame() const;
    Windows::Media::Capture::Frames::DepthMediaFrame DepthMediaFrame() const;
    Windows::Media::VideoFrame GetVideoFrame() const;
};

template <typename D>
struct WINRT_EBO impl_IVideoMediaFrameFormat
{
    Windows::Media::Capture::Frames::MediaFrameFormat MediaFrameFormat() const;
    Windows::Media::Capture::Frames::DepthMediaFrameFormat DepthFormat() const;
    uint32_t Width() const;
    uint32_t Height() const;
};

}

namespace impl {

template <> struct traits<Windows::Media::Capture::Frames::IBufferMediaFrame>
{
    using abi = ABI::Windows::Media::Capture::Frames::IBufferMediaFrame;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IBufferMediaFrame<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IDepthMediaFrame>
{
    using abi = ABI::Windows::Media::Capture::Frames::IDepthMediaFrame;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IDepthMediaFrame<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IDepthMediaFrameFormat>
{
    using abi = ABI::Windows::Media::Capture::Frames::IDepthMediaFrameFormat;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IDepthMediaFrameFormat<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IInfraredMediaFrame>
{
    using abi = ABI::Windows::Media::Capture::Frames::IInfraredMediaFrame;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IInfraredMediaFrame<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IMediaFrameArrivedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::Frames::IMediaFrameArrivedEventArgs;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IMediaFrameArrivedEventArgs<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IMediaFrameFormat>
{
    using abi = ABI::Windows::Media::Capture::Frames::IMediaFrameFormat;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IMediaFrameFormat<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IMediaFrameReader>
{
    using abi = ABI::Windows::Media::Capture::Frames::IMediaFrameReader;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IMediaFrameReader<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IMediaFrameReference>
{
    using abi = ABI::Windows::Media::Capture::Frames::IMediaFrameReference;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IMediaFrameReference<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IMediaFrameSource>
{
    using abi = ABI::Windows::Media::Capture::Frames::IMediaFrameSource;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IMediaFrameSource<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IMediaFrameSourceController>
{
    using abi = ABI::Windows::Media::Capture::Frames::IMediaFrameSourceController;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IMediaFrameSourceController<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult>
{
    using abi = ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IMediaFrameSourceGetPropertyResult<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IMediaFrameSourceGroup>
{
    using abi = ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGroup;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IMediaFrameSourceGroup<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IMediaFrameSourceGroupStatics>
{
    using abi = ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGroupStatics;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IMediaFrameSourceGroupStatics<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IMediaFrameSourceInfo>
{
    using abi = ABI::Windows::Media::Capture::Frames::IMediaFrameSourceInfo;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IMediaFrameSourceInfo<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IVideoMediaFrame>
{
    using abi = ABI::Windows::Media::Capture::Frames::IVideoMediaFrame;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IVideoMediaFrame<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::IVideoMediaFrameFormat>
{
    using abi = ABI::Windows::Media::Capture::Frames::IVideoMediaFrameFormat;
    template <typename D> using consume = Windows::Media::Capture::Frames::impl_IVideoMediaFrameFormat<D>;
};

template <> struct traits<Windows::Media::Capture::Frames::BufferMediaFrame>
{
    using abi = ABI::Windows::Media::Capture::Frames::BufferMediaFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.BufferMediaFrame"; }
};

template <> struct traits<Windows::Media::Capture::Frames::DepthMediaFrame>
{
    using abi = ABI::Windows::Media::Capture::Frames::DepthMediaFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.DepthMediaFrame"; }
};

template <> struct traits<Windows::Media::Capture::Frames::DepthMediaFrameFormat>
{
    using abi = ABI::Windows::Media::Capture::Frames::DepthMediaFrameFormat;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.DepthMediaFrameFormat"; }
};

template <> struct traits<Windows::Media::Capture::Frames::InfraredMediaFrame>
{
    using abi = ABI::Windows::Media::Capture::Frames::InfraredMediaFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.InfraredMediaFrame"; }
};

template <> struct traits<Windows::Media::Capture::Frames::MediaFrameArrivedEventArgs>
{
    using abi = ABI::Windows::Media::Capture::Frames::MediaFrameArrivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.MediaFrameArrivedEventArgs"; }
};

template <> struct traits<Windows::Media::Capture::Frames::MediaFrameFormat>
{
    using abi = ABI::Windows::Media::Capture::Frames::MediaFrameFormat;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.MediaFrameFormat"; }
};

template <> struct traits<Windows::Media::Capture::Frames::MediaFrameReader>
{
    using abi = ABI::Windows::Media::Capture::Frames::MediaFrameReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.MediaFrameReader"; }
};

template <> struct traits<Windows::Media::Capture::Frames::MediaFrameReference>
{
    using abi = ABI::Windows::Media::Capture::Frames::MediaFrameReference;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.MediaFrameReference"; }
};

template <> struct traits<Windows::Media::Capture::Frames::MediaFrameSource>
{
    using abi = ABI::Windows::Media::Capture::Frames::MediaFrameSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.MediaFrameSource"; }
};

template <> struct traits<Windows::Media::Capture::Frames::MediaFrameSourceController>
{
    using abi = ABI::Windows::Media::Capture::Frames::MediaFrameSourceController;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.MediaFrameSourceController"; }
};

template <> struct traits<Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyResult>
{
    using abi = ABI::Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.MediaFrameSourceGetPropertyResult"; }
};

template <> struct traits<Windows::Media::Capture::Frames::MediaFrameSourceGroup>
{
    using abi = ABI::Windows::Media::Capture::Frames::MediaFrameSourceGroup;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.MediaFrameSourceGroup"; }
};

template <> struct traits<Windows::Media::Capture::Frames::MediaFrameSourceInfo>
{
    using abi = ABI::Windows::Media::Capture::Frames::MediaFrameSourceInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.MediaFrameSourceInfo"; }
};

template <> struct traits<Windows::Media::Capture::Frames::VideoMediaFrame>
{
    using abi = ABI::Windows::Media::Capture::Frames::VideoMediaFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.VideoMediaFrame"; }
};

template <> struct traits<Windows::Media::Capture::Frames::VideoMediaFrameFormat>
{
    using abi = ABI::Windows::Media::Capture::Frames::VideoMediaFrameFormat;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Capture.Frames.VideoMediaFrameFormat"; }
};

}

}
