// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Perception.0.h"
#include "Windows.Devices.Enumeration.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.Graphics.Imaging.0.h"
#include "Windows.Media.0.h"
#include "Windows.Media.Devices.Core.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Perception {

struct __declspec(uuid("08c03978-437a-4d97-a663-fd3195600249")) __declspec(novtable) IKnownCameraIntrinsicsPropertiesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FocalLength(hstring * value) = 0;
    virtual HRESULT __stdcall get_PrincipalPoint(hstring * value) = 0;
    virtual HRESULT __stdcall get_RadialDistortion(hstring * value) = 0;
    virtual HRESULT __stdcall get_TangentialDistortion(hstring * value) = 0;
};

struct __declspec(uuid("5df1cca2-01f8-4a87-b859-d5e5b7e1de4b")) __declspec(novtable) IKnownPerceptionColorFrameSourcePropertiesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Exposure(hstring * value) = 0;
    virtual HRESULT __stdcall get_AutoExposureEnabled(hstring * value) = 0;
    virtual HRESULT __stdcall get_ExposureCompensation(hstring * value) = 0;
};

struct __declspec(uuid("5df1cca2-01f8-4a87-b859-d5e5b7e1de4a")) __declspec(novtable) IKnownPerceptionDepthFrameSourcePropertiesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MinDepth(hstring * value) = 0;
    virtual HRESULT __stdcall get_MaxDepth(hstring * value) = 0;
};

struct __declspec(uuid("5df1cca2-01f8-4a87-b859-d5e5b7e1de47")) __declspec(novtable) IKnownPerceptionFrameSourcePropertiesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_PhysicalDeviceIds(hstring * value) = 0;
    virtual HRESULT __stdcall get_FrameKind(hstring * value) = 0;
    virtual HRESULT __stdcall get_DeviceModelVersion(hstring * value) = 0;
    virtual HRESULT __stdcall get_EnclosureLocation(hstring * value) = 0;
};

struct __declspec(uuid("a9c86871-05dc-4a4d-8a5c-a4ecf26bbc46")) __declspec(novtable) IKnownPerceptionFrameSourcePropertiesStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("5df1cca2-01f8-4a87-b859-d5e5b7e1de49")) __declspec(novtable) IKnownPerceptionInfraredFrameSourcePropertiesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Exposure(hstring * value) = 0;
    virtual HRESULT __stdcall get_AutoExposureEnabled(hstring * value) = 0;
    virtual HRESULT __stdcall get_ExposureCompensation(hstring * value) = 0;
    virtual HRESULT __stdcall get_ActiveIlluminationEnabled(hstring * value) = 0;
    virtual HRESULT __stdcall get_AmbientSubtractionEnabled(hstring * value) = 0;
    virtual HRESULT __stdcall get_StructureLightPatternEnabled(hstring * value) = 0;
    virtual HRESULT __stdcall get_InterleavedIlluminationEnabled(hstring * value) = 0;
};

struct __declspec(uuid("5df1cca2-01f8-4a87-b859-d5e5b7e1de48")) __declspec(novtable) IKnownPerceptionVideoFrameSourcePropertiesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_VideoProfile(hstring * value) = 0;
    virtual HRESULT __stdcall get_SupportedVideoProfiles(hstring * value) = 0;
    virtual HRESULT __stdcall get_AvailableVideoProfiles(hstring * value) = 0;
    virtual HRESULT __stdcall get_IsMirrored(hstring * value) = 0;
    virtual HRESULT __stdcall get_CameraIntrinsics(hstring * value) = 0;
};

struct __declspec(uuid("8f08e2e7-5a76-43e3-a13a-da3d91a9ef98")) __declspec(novtable) IKnownPerceptionVideoProfilePropertiesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BitmapPixelFormat(hstring * value) = 0;
    virtual HRESULT __stdcall get_BitmapAlphaMode(hstring * value) = 0;
    virtual HRESULT __stdcall get_Width(hstring * value) = 0;
    virtual HRESULT __stdcall get_Height(hstring * value) = 0;
    virtual HRESULT __stdcall get_FrameDuration(hstring * value) = 0;
};

struct __declspec(uuid("fe621549-2cbf-4f94-9861-f817ea317747")) __declspec(novtable) IPerceptionColorFrame : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_VideoFrame(Windows::Media::IVideoFrame ** value) = 0;
};

struct __declspec(uuid("8fad02d5-86f7-4d8d-b966-5a3761ba9f59")) __declspec(novtable) IPerceptionColorFrameArrivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RelativeTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall abi_TryOpenFrame(Windows::Devices::Perception::IPerceptionColorFrame ** result) = 0;
};

struct __declspec(uuid("7650f56e-b9f5-461b-83ad-f222af2aaadc")) __declspec(novtable) IPerceptionColorFrameReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_FrameArrived(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameReader, Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FrameArrived(event_token token) = 0;
    virtual HRESULT __stdcall get_Source(Windows::Devices::Perception::IPerceptionColorFrameSource ** value) = 0;
    virtual HRESULT __stdcall get_IsPaused(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPaused(bool value) = 0;
    virtual HRESULT __stdcall abi_TryReadLatestFrame(Windows::Devices::Perception::IPerceptionColorFrame ** result) = 0;
};

struct __declspec(uuid("dc6dba7c-0b58-468d-9ca1-6db04cc0477c")) __declspec(novtable) IPerceptionColorFrameSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_AvailableChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AvailableChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ActiveChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ActiveChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_PropertiesChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PropertiesChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_VideoProfileChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VideoProfileChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_CameraIntrinsicsChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CameraIntrinsicsChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_DeviceKind(hstring * value) = 0;
    virtual HRESULT __stdcall get_Available(bool * value) = 0;
    virtual HRESULT __stdcall get_Active(bool * value) = 0;
    virtual HRESULT __stdcall get_IsControlled(bool * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_SupportedVideoProfiles(Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> ** value) = 0;
    virtual HRESULT __stdcall get_AvailableVideoProfiles(Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> ** value) = 0;
    virtual HRESULT __stdcall get_VideoProfile(Windows::Devices::Perception::IPerceptionVideoProfile ** value) = 0;
    virtual HRESULT __stdcall get_CameraIntrinsics(Windows::Media::Devices::Core::ICameraIntrinsics ** value) = 0;
    virtual HRESULT __stdcall abi_AcquireControlSession(Windows::Devices::Perception::IPerceptionControlSession ** value) = 0;
    virtual HRESULT __stdcall abi_CanControlIndependentlyFrom(hstring targetId, bool * result) = 0;
    virtual HRESULT __stdcall abi_IsCorrelatedWith(hstring targetId, bool * result) = 0;
    virtual HRESULT __stdcall abi_TryGetTransformTo(hstring targetId, Windows::Foundation::Numerics::float4x4 * result, bool * hasResult) = 0;
    virtual HRESULT __stdcall abi_TryGetDepthCorrelatedCameraIntrinsicsAsync(Windows::Devices::Perception::IPerceptionDepthFrameSource * correlatedDepthFrameSource, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> ** result) = 0;
    virtual HRESULT __stdcall abi_TryGetDepthCorrelatedCoordinateMapperAsync(hstring targetSourceId, Windows::Devices::Perception::IPerceptionDepthFrameSource * correlatedDepthFrameSource, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> ** result) = 0;
    virtual HRESULT __stdcall abi_TrySetVideoProfileAsync(Windows::Devices::Perception::IPerceptionControlSession * controlSession, Windows::Devices::Perception::IPerceptionVideoProfile * profile, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_OpenReader(Windows::Devices::Perception::IPerceptionColorFrameReader ** result) = 0;
};

struct __declspec(uuid("f88008e5-5631-45ed-ad98-8c6aa04cfb91")) __declspec(novtable) IPerceptionColorFrameSource2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("d16bf4e6-da24-442c-bbd5-55549b5b94f3")) __declspec(novtable) IPerceptionColorFrameSourceAddedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameSource(Windows::Devices::Perception::IPerceptionColorFrameSource ** value) = 0;
};

struct __declspec(uuid("d277fa69-eb4c-42ef-ba4f-288f615c93c1")) __declspec(novtable) IPerceptionColorFrameSourceRemovedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameSource(Windows::Devices::Perception::IPerceptionColorFrameSource ** value) = 0;
};

struct __declspec(uuid("5df3cca2-01f8-4a87-b859-d5e5b7e1de49")) __declspec(novtable) IPerceptionColorFrameSourceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWatcher(Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher ** watcher) = 0;
    virtual HRESULT __stdcall abi_FindAllAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionColorFrameSource>> ** result) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionColorFrameSource> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> ** result) = 0;
};

struct __declspec(uuid("96bd1392-e667-40c4-89f9-1462dea6a9cc")) __declspec(novtable) IPerceptionColorFrameSourceWatcher : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_SourceAdded(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_SourceRemoved(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceRemoved(event_token token) = 0;
    virtual HRESULT __stdcall add_Stopped(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Stopped(event_token token) = 0;
    virtual HRESULT __stdcall add_EnumerationCompleted(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EnumerationCompleted(event_token token) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Enumeration::DeviceWatcherStatus * value) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
};

struct __declspec(uuid("99998653-5a3d-417f-9239-f1889e548b48")) __declspec(novtable) IPerceptionControlSession : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_ControlLost(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionControlSession, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ControlLost(event_token token) = 0;
    virtual HRESULT __stdcall abi_TrySetPropertyAsync(hstring name, Windows::Foundation::IInspectable * value, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> ** result) = 0;
};

struct __declspec(uuid("6548ca01-86de-5be1-6582-807fcf4c95cf")) __declspec(novtable) IPerceptionDepthCorrelatedCameraIntrinsics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_UnprojectPixelAtCorrelatedDepth(Windows::Foundation::Point pixelCoordinate, Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, Windows::Foundation::Numerics::float3 * result) = 0;
    virtual HRESULT __stdcall abi_UnprojectPixelsAtCorrelatedDepth(uint32_t __sourceCoordinatesSize, Windows::Foundation::Point * sourceCoordinates, Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, uint32_t __resultsSize, Windows::Foundation::Numerics::float3 * results) = 0;
    virtual HRESULT __stdcall abi_UnprojectRegionPixelsAtCorrelatedDepthAsync(Windows::Foundation::Rect region, Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, uint32_t __resultsSize, Windows::Foundation::Numerics::float3 * results, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_UnprojectAllPixelsAtCorrelatedDepthAsync(Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, uint32_t __resultsSize, Windows::Foundation::Numerics::float3 * results, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("5b4d9d1d-b5f6-469c-b8c2-b97a45e6863b")) __declspec(novtable) IPerceptionDepthCorrelatedCoordinateMapper : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_MapPixelToTarget(Windows::Foundation::Point sourcePixelCoordinate, Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, Windows::Foundation::Point * result) = 0;
    virtual HRESULT __stdcall abi_MapPixelsToTarget(uint32_t __sourceCoordinatesSize, Windows::Foundation::Point * sourceCoordinates, Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, uint32_t __resultsSize, Windows::Foundation::Point * results) = 0;
    virtual HRESULT __stdcall abi_MapRegionOfPixelsToTargetAsync(Windows::Foundation::Rect region, Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, uint32_t __targetCoordinatesSize, Windows::Foundation::Point * targetCoordinates, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_MapAllPixelsToTargetAsync(Windows::Devices::Perception::IPerceptionDepthFrame * depthFrame, uint32_t __targetCoordinatesSize, Windows::Foundation::Point * targetCoordinates, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("a37b81fc-9906-4ffd-9161-0024b360b657")) __declspec(novtable) IPerceptionDepthFrame : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_VideoFrame(Windows::Media::IVideoFrame ** value) = 0;
};

struct __declspec(uuid("443d25b2-b282-4637-9173-ac978435c985")) __declspec(novtable) IPerceptionDepthFrameArrivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RelativeTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall abi_TryOpenFrame(Windows::Devices::Perception::IPerceptionDepthFrame ** result) = 0;
};

struct __declspec(uuid("b1a3c09f-299b-4612-a4f7-270f25a096ec")) __declspec(novtable) IPerceptionDepthFrameReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_FrameArrived(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameReader, Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FrameArrived(event_token token) = 0;
    virtual HRESULT __stdcall get_Source(Windows::Devices::Perception::IPerceptionDepthFrameSource ** value) = 0;
    virtual HRESULT __stdcall get_IsPaused(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPaused(bool value) = 0;
    virtual HRESULT __stdcall abi_TryReadLatestFrame(Windows::Devices::Perception::IPerceptionDepthFrame ** result) = 0;
};

struct __declspec(uuid("79d433d6-47fb-4df1-bfc9-f01d40bd9942")) __declspec(novtable) IPerceptionDepthFrameSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_AvailableChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AvailableChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ActiveChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ActiveChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_PropertiesChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PropertiesChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_VideoProfileChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VideoProfileChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_CameraIntrinsicsChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CameraIntrinsicsChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_DeviceKind(hstring * value) = 0;
    virtual HRESULT __stdcall get_Available(bool * value) = 0;
    virtual HRESULT __stdcall get_Active(bool * value) = 0;
    virtual HRESULT __stdcall get_IsControlled(bool * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_SupportedVideoProfiles(Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> ** value) = 0;
    virtual HRESULT __stdcall get_AvailableVideoProfiles(Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> ** value) = 0;
    virtual HRESULT __stdcall get_VideoProfile(Windows::Devices::Perception::IPerceptionVideoProfile ** value) = 0;
    virtual HRESULT __stdcall get_CameraIntrinsics(Windows::Media::Devices::Core::ICameraIntrinsics ** value) = 0;
    virtual HRESULT __stdcall abi_AcquireControlSession(Windows::Devices::Perception::IPerceptionControlSession ** result) = 0;
    virtual HRESULT __stdcall abi_CanControlIndependentlyFrom(hstring targetId, bool * result) = 0;
    virtual HRESULT __stdcall abi_IsCorrelatedWith(hstring targetId, bool * result) = 0;
    virtual HRESULT __stdcall abi_TryGetTransformTo(hstring targetId, Windows::Foundation::Numerics::float4x4 * result, bool * hasResult) = 0;
    virtual HRESULT __stdcall abi_TryGetDepthCorrelatedCameraIntrinsicsAsync(Windows::Devices::Perception::IPerceptionDepthFrameSource * target, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> ** result) = 0;
    virtual HRESULT __stdcall abi_TryGetDepthCorrelatedCoordinateMapperAsync(hstring targetId, Windows::Devices::Perception::IPerceptionDepthFrameSource * depthFrameSourceToMapWith, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> ** result) = 0;
    virtual HRESULT __stdcall abi_TrySetVideoProfileAsync(Windows::Devices::Perception::IPerceptionControlSession * controlSession, Windows::Devices::Perception::IPerceptionVideoProfile * profile, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_OpenReader(Windows::Devices::Perception::IPerceptionDepthFrameReader ** result) = 0;
};

struct __declspec(uuid("e3d23d2e-6e2c-4e6d-91d9-704cd8dff79d")) __declspec(novtable) IPerceptionDepthFrameSource2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("93a48168-8bf8-45d2-a2f8-4ac0931cc7a6")) __declspec(novtable) IPerceptionDepthFrameSourceAddedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameSource(Windows::Devices::Perception::IPerceptionDepthFrameSource ** value) = 0;
};

struct __declspec(uuid("a0c0cc4d-e96c-4d81-86dd-38b95e49c6df")) __declspec(novtable) IPerceptionDepthFrameSourceRemovedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameSource(Windows::Devices::Perception::IPerceptionDepthFrameSource ** value) = 0;
};

struct __declspec(uuid("5df3cca2-01f8-4a87-b859-d5e5b7e1de48")) __declspec(novtable) IPerceptionDepthFrameSourceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWatcher(Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher ** watcher) = 0;
    virtual HRESULT __stdcall abi_FindAllAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionDepthFrameSource>> ** result) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthFrameSource> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> ** result) = 0;
};

struct __declspec(uuid("780e96d1-8d02-4d2b-ada4-5ba624a0eb10")) __declspec(novtable) IPerceptionDepthFrameSourceWatcher : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_SourceAdded(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_SourceRemoved(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceRemoved(event_token token) = 0;
    virtual HRESULT __stdcall add_Stopped(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Stopped(event_token token) = 0;
    virtual HRESULT __stdcall add_EnumerationCompleted(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EnumerationCompleted(event_token token) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Enumeration::DeviceWatcherStatus * value) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
};

struct __declspec(uuid("6c68e068-bcf1-4ecc-b891-7625d1244b6b")) __declspec(novtable) IPerceptionFrameSourcePropertiesChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CollectionChange(winrt::Windows::Foundation::Collections::CollectionChange * value) = 0;
    virtual HRESULT __stdcall get_Key(hstring * value) = 0;
};

struct __declspec(uuid("1e33390a-3c90-4d22-b898-f42bba6418ff")) __declspec(novtable) IPerceptionFrameSourcePropertyChangeResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus * value) = 0;
    virtual HRESULT __stdcall get_NewValue(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("b0886276-849e-4c7a-8ae6-b56064532153")) __declspec(novtable) IPerceptionInfraredFrame : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_VideoFrame(Windows::Media::IVideoFrame ** value) = 0;
};

struct __declspec(uuid("9f77fac7-b4bd-4857-9d50-be8ef075daef")) __declspec(novtable) IPerceptionInfraredFrameArrivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RelativeTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall abi_TryOpenFrame(Windows::Devices::Perception::IPerceptionInfraredFrame ** result) = 0;
};

struct __declspec(uuid("7960ce18-d39b-4fc8-a04a-929734c6756c")) __declspec(novtable) IPerceptionInfraredFrameReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_FrameArrived(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameReader, Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FrameArrived(event_token token) = 0;
    virtual HRESULT __stdcall get_Source(Windows::Devices::Perception::IPerceptionInfraredFrameSource ** value) = 0;
    virtual HRESULT __stdcall get_IsPaused(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPaused(bool value) = 0;
    virtual HRESULT __stdcall abi_TryReadLatestFrame(Windows::Devices::Perception::IPerceptionInfraredFrame ** result) = 0;
};

struct __declspec(uuid("55b08742-1808-494e-9e30-9d2a7be8f700")) __declspec(novtable) IPerceptionInfraredFrameSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_AvailableChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AvailableChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ActiveChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ActiveChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_PropertiesChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PropertiesChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_VideoProfileChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VideoProfileChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_CameraIntrinsicsChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CameraIntrinsicsChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_DeviceKind(hstring * value) = 0;
    virtual HRESULT __stdcall get_Available(bool * value) = 0;
    virtual HRESULT __stdcall get_Active(bool * value) = 0;
    virtual HRESULT __stdcall get_IsControlled(bool * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_SupportedVideoProfiles(Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> ** value) = 0;
    virtual HRESULT __stdcall get_AvailableVideoProfiles(Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> ** value) = 0;
    virtual HRESULT __stdcall get_VideoProfile(Windows::Devices::Perception::IPerceptionVideoProfile ** value) = 0;
    virtual HRESULT __stdcall get_CameraIntrinsics(Windows::Media::Devices::Core::ICameraIntrinsics ** value) = 0;
    virtual HRESULT __stdcall abi_AcquireControlSession(Windows::Devices::Perception::IPerceptionControlSession ** result) = 0;
    virtual HRESULT __stdcall abi_CanControlIndependentlyFrom(hstring targetId, bool * result) = 0;
    virtual HRESULT __stdcall abi_IsCorrelatedWith(hstring targetId, bool * result) = 0;
    virtual HRESULT __stdcall abi_TryGetTransformTo(hstring targetId, Windows::Foundation::Numerics::float4x4 * result, bool * hasResult) = 0;
    virtual HRESULT __stdcall abi_TryGetDepthCorrelatedCameraIntrinsicsAsync(Windows::Devices::Perception::IPerceptionDepthFrameSource * target, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> ** result) = 0;
    virtual HRESULT __stdcall abi_TryGetDepthCorrelatedCoordinateMapperAsync(hstring targetId, Windows::Devices::Perception::IPerceptionDepthFrameSource * depthFrameSourceToMapWith, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> ** result) = 0;
    virtual HRESULT __stdcall abi_TrySetVideoProfileAsync(Windows::Devices::Perception::IPerceptionControlSession * controlSession, Windows::Devices::Perception::IPerceptionVideoProfile * profile, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_OpenReader(Windows::Devices::Perception::IPerceptionInfraredFrameReader ** result) = 0;
};

struct __declspec(uuid("dcd4d798-4b0b-4300-8d85-410817faa032")) __declspec(novtable) IPerceptionInfraredFrameSource2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
};

struct __declspec(uuid("6d334120-95ce-4660-907a-d98035aa2b7c")) __declspec(novtable) IPerceptionInfraredFrameSourceAddedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameSource(Windows::Devices::Perception::IPerceptionInfraredFrameSource ** value) = 0;
};

struct __declspec(uuid("ea1a8071-7a70-4a61-af94-07303853f695")) __declspec(novtable) IPerceptionInfraredFrameSourceRemovedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameSource(Windows::Devices::Perception::IPerceptionInfraredFrameSource ** value) = 0;
};

struct __declspec(uuid("5df3cca2-01f8-4a87-b859-d5e5b7e1de47")) __declspec(novtable) IPerceptionInfraredFrameSourceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWatcher(Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher ** watcher) = 0;
    virtual HRESULT __stdcall abi_FindAllAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionInfraredFrameSource>> ** result) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionInfraredFrameSource> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> ** result) = 0;
};

struct __declspec(uuid("383cff99-d70c-444d-a8b0-720c2e66fe3b")) __declspec(novtable) IPerceptionInfraredFrameSourceWatcher : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_SourceAdded(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_SourceRemoved(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceRemoved(event_token token) = 0;
    virtual HRESULT __stdcall add_Stopped(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Stopped(event_token token) = 0;
    virtual HRESULT __stdcall add_EnumerationCompleted(Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EnumerationCompleted(event_token token) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Enumeration::DeviceWatcherStatus * value) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
};

struct __declspec(uuid("75763ea3-011a-470e-8225-6f05ade25648")) __declspec(novtable) IPerceptionVideoProfile : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BitmapPixelFormat(winrt::Windows::Graphics::Imaging::BitmapPixelFormat * value) = 0;
    virtual HRESULT __stdcall get_BitmapAlphaMode(winrt::Windows::Graphics::Imaging::BitmapAlphaMode * value) = 0;
    virtual HRESULT __stdcall get_Width(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Height(int32_t * value) = 0;
    virtual HRESULT __stdcall get_FrameDuration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall abi_IsEqual(Windows::Devices::Perception::IPerceptionVideoProfile * other, bool * result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrame> { using default_interface = Windows::Devices::Perception::IPerceptionColorFrame; };
template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionColorFrameArrivedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameReader> { using default_interface = Windows::Devices::Perception::IPerceptionColorFrameReader; };
template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSource> { using default_interface = Windows::Devices::Perception::IPerceptionColorFrameSource; };
template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher> { using default_interface = Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher; };
template <> struct traits<Windows::Devices::Perception::PerceptionControlSession> { using default_interface = Windows::Devices::Perception::IPerceptionControlSession; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> { using default_interface = Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> { using default_interface = Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrame> { using default_interface = Windows::Devices::Perception::IPerceptionDepthFrame; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameReader> { using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameReader; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSource> { using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameSource; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher> { using default_interface = Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher; };
template <> struct traits<Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> { using default_interface = Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult; };
template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrame> { using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrame; };
template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameReader> { using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameReader; };
template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSource> { using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameSource; };
template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> { using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs; };
template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher> { using default_interface = Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher; };
template <> struct traits<Windows::Devices::Perception::PerceptionVideoProfile> { using default_interface = Windows::Devices::Perception::IPerceptionVideoProfile; };

}

namespace Windows::Devices::Perception {

template <typename D>
struct WINRT_EBO impl_IKnownCameraIntrinsicsPropertiesStatics
{
    hstring FocalLength() const;
    hstring PrincipalPoint() const;
    hstring RadialDistortion() const;
    hstring TangentialDistortion() const;
};

template <typename D>
struct WINRT_EBO impl_IKnownPerceptionColorFrameSourcePropertiesStatics
{
    hstring Exposure() const;
    hstring AutoExposureEnabled() const;
    hstring ExposureCompensation() const;
};

template <typename D>
struct WINRT_EBO impl_IKnownPerceptionDepthFrameSourcePropertiesStatics
{
    hstring MinDepth() const;
    hstring MaxDepth() const;
};

template <typename D>
struct WINRT_EBO impl_IKnownPerceptionFrameSourcePropertiesStatics
{
    hstring Id() const;
    hstring PhysicalDeviceIds() const;
    hstring FrameKind() const;
    hstring DeviceModelVersion() const;
    hstring EnclosureLocation() const;
};

template <typename D>
struct WINRT_EBO impl_IKnownPerceptionFrameSourcePropertiesStatics2
{
    hstring DeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_IKnownPerceptionInfraredFrameSourcePropertiesStatics
{
    hstring Exposure() const;
    hstring AutoExposureEnabled() const;
    hstring ExposureCompensation() const;
    hstring ActiveIlluminationEnabled() const;
    hstring AmbientSubtractionEnabled() const;
    hstring StructureLightPatternEnabled() const;
    hstring InterleavedIlluminationEnabled() const;
};

template <typename D>
struct WINRT_EBO impl_IKnownPerceptionVideoFrameSourcePropertiesStatics
{
    hstring VideoProfile() const;
    hstring SupportedVideoProfiles() const;
    hstring AvailableVideoProfiles() const;
    hstring IsMirrored() const;
    hstring CameraIntrinsics() const;
};

template <typename D>
struct WINRT_EBO impl_IKnownPerceptionVideoProfilePropertiesStatics
{
    hstring BitmapPixelFormat() const;
    hstring BitmapAlphaMode() const;
    hstring Width() const;
    hstring Height() const;
    hstring FrameDuration() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionColorFrame
{
    Windows::Media::VideoFrame VideoFrame() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionColorFrameArrivedEventArgs
{
    Windows::Foundation::TimeSpan RelativeTime() const;
    Windows::Devices::Perception::PerceptionColorFrame TryOpenFrame() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionColorFrameReader
{
    event_token FrameArrived(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameReader, Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs> & handler) const;
    using FrameArrived_revoker = event_revoker<IPerceptionColorFrameReader>;
    FrameArrived_revoker FrameArrived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameReader, Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs> & handler) const;
    void FrameArrived(event_token token) const;
    Windows::Devices::Perception::PerceptionColorFrameSource Source() const;
    bool IsPaused() const;
    void IsPaused(bool value) const;
    Windows::Devices::Perception::PerceptionColorFrame TryReadLatestFrame() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionColorFrameSource
{
    event_token AvailableChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const;
    using AvailableChanged_revoker = event_revoker<IPerceptionColorFrameSource>;
    AvailableChanged_revoker AvailableChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const;
    void AvailableChanged(event_token token) const;
    event_token ActiveChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const;
    using ActiveChanged_revoker = event_revoker<IPerceptionColorFrameSource>;
    ActiveChanged_revoker ActiveChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const;
    void ActiveChanged(event_token token) const;
    event_token PropertiesChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> & handler) const;
    using PropertiesChanged_revoker = event_revoker<IPerceptionColorFrameSource>;
    PropertiesChanged_revoker PropertiesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> & handler) const;
    void PropertiesChanged(event_token token) const;
    event_token VideoProfileChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const;
    using VideoProfileChanged_revoker = event_revoker<IPerceptionColorFrameSource>;
    VideoProfileChanged_revoker VideoProfileChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const;
    void VideoProfileChanged(event_token token) const;
    event_token CameraIntrinsicsChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const;
    using CameraIntrinsicsChanged_revoker = event_revoker<IPerceptionColorFrameSource>;
    CameraIntrinsicsChanged_revoker CameraIntrinsicsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const;
    void CameraIntrinsicsChanged(event_token token) const;
    hstring Id() const;
    hstring DisplayName() const;
    hstring DeviceKind() const;
    bool Available() const;
    bool Active() const;
    bool IsControlled() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> Properties() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> SupportedVideoProfiles() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> AvailableVideoProfiles() const;
    Windows::Devices::Perception::PerceptionVideoProfile VideoProfile() const;
    Windows::Media::Devices::Core::CameraIntrinsics CameraIntrinsics() const;
    Windows::Devices::Perception::PerceptionControlSession AcquireControlSession() const;
    bool CanControlIndependentlyFrom(hstring_view targetId) const;
    bool IsCorrelatedWith(hstring_view targetId) const;
    bool TryGetTransformTo(hstring_view targetId, Windows::Foundation::Numerics::float4x4 & result) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> TryGetDepthCorrelatedCameraIntrinsicsAsync(const Windows::Devices::Perception::PerceptionDepthFrameSource & correlatedDepthFrameSource) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> TryGetDepthCorrelatedCoordinateMapperAsync(hstring_view targetSourceId, const Windows::Devices::Perception::PerceptionDepthFrameSource & correlatedDepthFrameSource) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> TrySetVideoProfileAsync(const Windows::Devices::Perception::PerceptionControlSession & controlSession, const Windows::Devices::Perception::PerceptionVideoProfile & profile) const;
    Windows::Devices::Perception::PerceptionColorFrameReader OpenReader() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionColorFrameSource2
{
    hstring DeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionColorFrameSourceAddedEventArgs
{
    Windows::Devices::Perception::PerceptionColorFrameSource FrameSource() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionColorFrameSourceRemovedEventArgs
{
    Windows::Devices::Perception::PerceptionColorFrameSource FrameSource() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionColorFrameSourceStatics
{
    Windows::Devices::Perception::PerceptionColorFrameSourceWatcher CreateWatcher() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionColorFrameSource>> FindAllAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionColorFrameSource> FromIdAsync(hstring_view id) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> RequestAccessAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionColorFrameSourceWatcher
{
    event_token SourceAdded(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> & handler) const;
    using SourceAdded_revoker = event_revoker<IPerceptionColorFrameSourceWatcher>;
    SourceAdded_revoker SourceAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> & handler) const;
    void SourceAdded(event_token token) const;
    event_token SourceRemoved(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> & handler) const;
    using SourceRemoved_revoker = event_revoker<IPerceptionColorFrameSourceWatcher>;
    SourceRemoved_revoker SourceRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> & handler) const;
    void SourceRemoved(event_token token) const;
    event_token Stopped(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const;
    using Stopped_revoker = event_revoker<IPerceptionColorFrameSourceWatcher>;
    Stopped_revoker Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const;
    void Stopped(event_token token) const;
    event_token EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const;
    using EnumerationCompleted_revoker = event_revoker<IPerceptionColorFrameSourceWatcher>;
    EnumerationCompleted_revoker EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const;
    void EnumerationCompleted(event_token token) const;
    Windows::Devices::Enumeration::DeviceWatcherStatus Status() const;
    void Start() const;
    void Stop() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionControlSession
{
    event_token ControlLost(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionControlSession, Windows::Foundation::IInspectable> & handler) const;
    using ControlLost_revoker = event_revoker<IPerceptionControlSession>;
    ControlLost_revoker ControlLost(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionControlSession, Windows::Foundation::IInspectable> & handler) const;
    void ControlLost(event_token token) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> TrySetPropertyAsync(hstring_view name, const Windows::Foundation::IInspectable & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionDepthCorrelatedCameraIntrinsics
{
    Windows::Foundation::Numerics::float3 UnprojectPixelAtCorrelatedDepth(const Windows::Foundation::Point & pixelCoordinate, const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame) const;
    void UnprojectPixelsAtCorrelatedDepth(array_view<const Windows::Foundation::Point> sourceCoordinates, const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame, array_view<Windows::Foundation::Numerics::float3> results) const;
    Windows::Foundation::IAsyncAction UnprojectRegionPixelsAtCorrelatedDepthAsync(const Windows::Foundation::Rect & region, const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame, array_view<Windows::Foundation::Numerics::float3> results) const;
    Windows::Foundation::IAsyncAction UnprojectAllPixelsAtCorrelatedDepthAsync(const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame, array_view<Windows::Foundation::Numerics::float3> results) const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionDepthCorrelatedCoordinateMapper
{
    Windows::Foundation::Point MapPixelToTarget(const Windows::Foundation::Point & sourcePixelCoordinate, const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame) const;
    void MapPixelsToTarget(array_view<const Windows::Foundation::Point> sourceCoordinates, const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame, array_view<Windows::Foundation::Point> results) const;
    Windows::Foundation::IAsyncAction MapRegionOfPixelsToTargetAsync(const Windows::Foundation::Rect & region, const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame, array_view<Windows::Foundation::Point> targetCoordinates) const;
    Windows::Foundation::IAsyncAction MapAllPixelsToTargetAsync(const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame, array_view<Windows::Foundation::Point> targetCoordinates) const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionDepthFrame
{
    Windows::Media::VideoFrame VideoFrame() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionDepthFrameArrivedEventArgs
{
    Windows::Foundation::TimeSpan RelativeTime() const;
    Windows::Devices::Perception::PerceptionDepthFrame TryOpenFrame() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionDepthFrameReader
{
    event_token FrameArrived(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameReader, Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> & handler) const;
    using FrameArrived_revoker = event_revoker<IPerceptionDepthFrameReader>;
    FrameArrived_revoker FrameArrived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameReader, Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> & handler) const;
    void FrameArrived(event_token token) const;
    Windows::Devices::Perception::PerceptionDepthFrameSource Source() const;
    bool IsPaused() const;
    void IsPaused(bool value) const;
    Windows::Devices::Perception::PerceptionDepthFrame TryReadLatestFrame() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionDepthFrameSource
{
    event_token AvailableChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const;
    using AvailableChanged_revoker = event_revoker<IPerceptionDepthFrameSource>;
    AvailableChanged_revoker AvailableChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const;
    void AvailableChanged(event_token token) const;
    event_token ActiveChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const;
    using ActiveChanged_revoker = event_revoker<IPerceptionDepthFrameSource>;
    ActiveChanged_revoker ActiveChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const;
    void ActiveChanged(event_token token) const;
    event_token PropertiesChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> & handler) const;
    using PropertiesChanged_revoker = event_revoker<IPerceptionDepthFrameSource>;
    PropertiesChanged_revoker PropertiesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> & handler) const;
    void PropertiesChanged(event_token token) const;
    event_token VideoProfileChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const;
    using VideoProfileChanged_revoker = event_revoker<IPerceptionDepthFrameSource>;
    VideoProfileChanged_revoker VideoProfileChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const;
    void VideoProfileChanged(event_token token) const;
    event_token CameraIntrinsicsChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const;
    using CameraIntrinsicsChanged_revoker = event_revoker<IPerceptionDepthFrameSource>;
    CameraIntrinsicsChanged_revoker CameraIntrinsicsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const;
    void CameraIntrinsicsChanged(event_token token) const;
    hstring Id() const;
    hstring DisplayName() const;
    hstring DeviceKind() const;
    bool Available() const;
    bool Active() const;
    bool IsControlled() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> Properties() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> SupportedVideoProfiles() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> AvailableVideoProfiles() const;
    Windows::Devices::Perception::PerceptionVideoProfile VideoProfile() const;
    Windows::Media::Devices::Core::CameraIntrinsics CameraIntrinsics() const;
    Windows::Devices::Perception::PerceptionControlSession AcquireControlSession() const;
    bool CanControlIndependentlyFrom(hstring_view targetId) const;
    bool IsCorrelatedWith(hstring_view targetId) const;
    bool TryGetTransformTo(hstring_view targetId, Windows::Foundation::Numerics::float4x4 & result) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> TryGetDepthCorrelatedCameraIntrinsicsAsync(const Windows::Devices::Perception::PerceptionDepthFrameSource & target) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> TryGetDepthCorrelatedCoordinateMapperAsync(hstring_view targetId, const Windows::Devices::Perception::PerceptionDepthFrameSource & depthFrameSourceToMapWith) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> TrySetVideoProfileAsync(const Windows::Devices::Perception::PerceptionControlSession & controlSession, const Windows::Devices::Perception::PerceptionVideoProfile & profile) const;
    Windows::Devices::Perception::PerceptionDepthFrameReader OpenReader() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionDepthFrameSource2
{
    hstring DeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionDepthFrameSourceAddedEventArgs
{
    Windows::Devices::Perception::PerceptionDepthFrameSource FrameSource() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionDepthFrameSourceRemovedEventArgs
{
    Windows::Devices::Perception::PerceptionDepthFrameSource FrameSource() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionDepthFrameSourceStatics
{
    Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher CreateWatcher() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionDepthFrameSource>> FindAllAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthFrameSource> FromIdAsync(hstring_view id) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> RequestAccessAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionDepthFrameSourceWatcher
{
    event_token SourceAdded(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> & handler) const;
    using SourceAdded_revoker = event_revoker<IPerceptionDepthFrameSourceWatcher>;
    SourceAdded_revoker SourceAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> & handler) const;
    void SourceAdded(event_token token) const;
    event_token SourceRemoved(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> & handler) const;
    using SourceRemoved_revoker = event_revoker<IPerceptionDepthFrameSourceWatcher>;
    SourceRemoved_revoker SourceRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> & handler) const;
    void SourceRemoved(event_token token) const;
    event_token Stopped(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const;
    using Stopped_revoker = event_revoker<IPerceptionDepthFrameSourceWatcher>;
    Stopped_revoker Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const;
    void Stopped(event_token token) const;
    event_token EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const;
    using EnumerationCompleted_revoker = event_revoker<IPerceptionDepthFrameSourceWatcher>;
    EnumerationCompleted_revoker EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const;
    void EnumerationCompleted(event_token token) const;
    Windows::Devices::Enumeration::DeviceWatcherStatus Status() const;
    void Start() const;
    void Stop() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionFrameSourcePropertiesChangedEventArgs
{
    Windows::Foundation::Collections::CollectionChange CollectionChange() const;
    hstring Key() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionFrameSourcePropertyChangeResult
{
    Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus Status() const;
    Windows::Foundation::IInspectable NewValue() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionInfraredFrame
{
    Windows::Media::VideoFrame VideoFrame() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionInfraredFrameArrivedEventArgs
{
    Windows::Foundation::TimeSpan RelativeTime() const;
    Windows::Devices::Perception::PerceptionInfraredFrame TryOpenFrame() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionInfraredFrameReader
{
    event_token FrameArrived(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameReader, Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> & handler) const;
    using FrameArrived_revoker = event_revoker<IPerceptionInfraredFrameReader>;
    FrameArrived_revoker FrameArrived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameReader, Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> & handler) const;
    void FrameArrived(event_token token) const;
    Windows::Devices::Perception::PerceptionInfraredFrameSource Source() const;
    bool IsPaused() const;
    void IsPaused(bool value) const;
    Windows::Devices::Perception::PerceptionInfraredFrame TryReadLatestFrame() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionInfraredFrameSource
{
    event_token AvailableChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const;
    using AvailableChanged_revoker = event_revoker<IPerceptionInfraredFrameSource>;
    AvailableChanged_revoker AvailableChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const;
    void AvailableChanged(event_token token) const;
    event_token ActiveChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const;
    using ActiveChanged_revoker = event_revoker<IPerceptionInfraredFrameSource>;
    ActiveChanged_revoker ActiveChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const;
    void ActiveChanged(event_token token) const;
    event_token PropertiesChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> & handler) const;
    using PropertiesChanged_revoker = event_revoker<IPerceptionInfraredFrameSource>;
    PropertiesChanged_revoker PropertiesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> & handler) const;
    void PropertiesChanged(event_token token) const;
    event_token VideoProfileChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const;
    using VideoProfileChanged_revoker = event_revoker<IPerceptionInfraredFrameSource>;
    VideoProfileChanged_revoker VideoProfileChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const;
    void VideoProfileChanged(event_token token) const;
    event_token CameraIntrinsicsChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const;
    using CameraIntrinsicsChanged_revoker = event_revoker<IPerceptionInfraredFrameSource>;
    CameraIntrinsicsChanged_revoker CameraIntrinsicsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const;
    void CameraIntrinsicsChanged(event_token token) const;
    hstring Id() const;
    hstring DisplayName() const;
    hstring DeviceKind() const;
    bool Available() const;
    bool Active() const;
    bool IsControlled() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> Properties() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> SupportedVideoProfiles() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> AvailableVideoProfiles() const;
    Windows::Devices::Perception::PerceptionVideoProfile VideoProfile() const;
    Windows::Media::Devices::Core::CameraIntrinsics CameraIntrinsics() const;
    Windows::Devices::Perception::PerceptionControlSession AcquireControlSession() const;
    bool CanControlIndependentlyFrom(hstring_view targetId) const;
    bool IsCorrelatedWith(hstring_view targetId) const;
    bool TryGetTransformTo(hstring_view targetId, Windows::Foundation::Numerics::float4x4 & result) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> TryGetDepthCorrelatedCameraIntrinsicsAsync(const Windows::Devices::Perception::PerceptionDepthFrameSource & target) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> TryGetDepthCorrelatedCoordinateMapperAsync(hstring_view targetId, const Windows::Devices::Perception::PerceptionDepthFrameSource & depthFrameSourceToMapWith) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> TrySetVideoProfileAsync(const Windows::Devices::Perception::PerceptionControlSession & controlSession, const Windows::Devices::Perception::PerceptionVideoProfile & profile) const;
    Windows::Devices::Perception::PerceptionInfraredFrameReader OpenReader() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionInfraredFrameSource2
{
    hstring DeviceId() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionInfraredFrameSourceAddedEventArgs
{
    Windows::Devices::Perception::PerceptionInfraredFrameSource FrameSource() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionInfraredFrameSourceRemovedEventArgs
{
    Windows::Devices::Perception::PerceptionInfraredFrameSource FrameSource() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionInfraredFrameSourceStatics
{
    Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher CreateWatcher() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionInfraredFrameSource>> FindAllAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionInfraredFrameSource> FromIdAsync(hstring_view id) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> RequestAccessAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionInfraredFrameSourceWatcher
{
    event_token SourceAdded(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> & handler) const;
    using SourceAdded_revoker = event_revoker<IPerceptionInfraredFrameSourceWatcher>;
    SourceAdded_revoker SourceAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> & handler) const;
    void SourceAdded(event_token token) const;
    event_token SourceRemoved(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> & handler) const;
    using SourceRemoved_revoker = event_revoker<IPerceptionInfraredFrameSourceWatcher>;
    SourceRemoved_revoker SourceRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> & handler) const;
    void SourceRemoved(event_token token) const;
    event_token Stopped(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const;
    using Stopped_revoker = event_revoker<IPerceptionInfraredFrameSourceWatcher>;
    Stopped_revoker Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const;
    void Stopped(event_token token) const;
    event_token EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const;
    using EnumerationCompleted_revoker = event_revoker<IPerceptionInfraredFrameSourceWatcher>;
    EnumerationCompleted_revoker EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const;
    void EnumerationCompleted(event_token token) const;
    Windows::Devices::Enumeration::DeviceWatcherStatus Status() const;
    void Start() const;
    void Stop() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionVideoProfile
{
    Windows::Graphics::Imaging::BitmapPixelFormat BitmapPixelFormat() const;
    Windows::Graphics::Imaging::BitmapAlphaMode BitmapAlphaMode() const;
    int32_t Width() const;
    int32_t Height() const;
    Windows::Foundation::TimeSpan FrameDuration() const;
    bool IsEqual(const Windows::Devices::Perception::PerceptionVideoProfile & other) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics>
{
    using abi = ABI::Windows::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownCameraIntrinsicsPropertiesStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics>
{
    using abi = ABI::Windows::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownPerceptionColorFrameSourcePropertiesStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IKnownPerceptionDepthFrameSourcePropertiesStatics>
{
    using abi = ABI::Windows::Devices::Perception::IKnownPerceptionDepthFrameSourcePropertiesStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownPerceptionDepthFrameSourcePropertiesStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics>
{
    using abi = ABI::Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownPerceptionFrameSourcePropertiesStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics2>
{
    using abi = ABI::Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics2;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownPerceptionFrameSourcePropertiesStatics2<D>;
};

template <> struct traits<Windows::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics>
{
    using abi = ABI::Windows::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics>
{
    using abi = ABI::Windows::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownPerceptionVideoFrameSourcePropertiesStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics>
{
    using abi = ABI::Windows::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IKnownPerceptionVideoProfilePropertiesStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrame>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrame;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrame<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameArrivedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameArrivedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameArrivedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameReader>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameReader;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameReader<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameSource>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameSource;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameSource<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameSource2>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameSource2;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameSource2<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameSourceAddedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameSourceRemovedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameSourceStatics>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameSourceStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionColorFrameSourceWatcher<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionControlSession>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionControlSession;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionControlSession<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthCorrelatedCameraIntrinsics<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthCorrelatedCoordinateMapper<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrame>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrame;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrame<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameArrivedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameReader>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameReader;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameReader<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameSource>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameSource<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameSource2>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource2;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameSource2<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameSourceAddedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameSourceRemovedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameSourceStatics>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameSourceStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionDepthFrameSourceWatcher<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionFrameSourcePropertiesChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionFrameSourcePropertyChangeResult<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrame>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrame;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrame<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameArrivedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameReader>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameReader;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameReader<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameSource>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameSource<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameSource2>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource2;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameSource2<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameSourceAddedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameSourceRemovedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameSourceStatics>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceStatics;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameSourceStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionInfraredFrameSourceWatcher<D>;
};

template <> struct traits<Windows::Devices::Perception::IPerceptionVideoProfile>
{
    using abi = ABI::Windows::Devices::Perception::IPerceptionVideoProfile;
    template <typename D> using consume = Windows::Devices::Perception::impl_IPerceptionVideoProfile<D>;
};

template <> struct traits<Windows::Devices::Perception::KnownCameraIntrinsicsProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.KnownCameraIntrinsicsProperties"; }
};

template <> struct traits<Windows::Devices::Perception::KnownPerceptionColorFrameSourceProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.KnownPerceptionColorFrameSourceProperties"; }
};

template <> struct traits<Windows::Devices::Perception::KnownPerceptionDepthFrameSourceProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.KnownPerceptionDepthFrameSourceProperties"; }
};

template <> struct traits<Windows::Devices::Perception::KnownPerceptionFrameSourceProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.KnownPerceptionFrameSourceProperties"; }
};

template <> struct traits<Windows::Devices::Perception::KnownPerceptionInfraredFrameSourceProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.KnownPerceptionInfraredFrameSourceProperties"; }
};

template <> struct traits<Windows::Devices::Perception::KnownPerceptionVideoFrameSourceProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.KnownPerceptionVideoFrameSourceProperties"; }
};

template <> struct traits<Windows::Devices::Perception::KnownPerceptionVideoProfileProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.KnownPerceptionVideoProfileProperties"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrame>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionColorFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionColorFrame"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionColorFrameArrivedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameReader>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionColorFrameReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionColorFrameReader"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSource>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionColorFrameSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionColorFrameSource"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionColorFrameSourceAddedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionColorFrameSourceRemovedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionColorFrameSourceWatcher;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionColorFrameSourceWatcher"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionControlSession>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionControlSession;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionControlSession"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthCorrelatedCameraIntrinsics"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthCorrelatedCoordinateMapper"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrame>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthFrame"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthFrameArrivedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameReader>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthFrameReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthFrameReader"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSource>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthFrameSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthFrameSource"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthFrameSourceAddedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthFrameSourceRemovedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionDepthFrameSourceWatcher"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionFrameSourcePropertiesChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionFrameSourcePropertyChangeResult"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrame>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionInfraredFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionInfraredFrame"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionInfraredFrameArrivedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameReader>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionInfraredFrameReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionInfraredFrameReader"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSource>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionInfraredFrameSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionInfraredFrameSource"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionInfraredFrameSourceAddedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionInfraredFrameSourceRemovedEventArgs"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionInfraredFrameSourceWatcher"; }
};

template <> struct traits<Windows::Devices::Perception::PerceptionVideoProfile>
{
    using abi = ABI::Windows::Devices::Perception::PerceptionVideoProfile;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.PerceptionVideoProfile"; }
};

}

}
