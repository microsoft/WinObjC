// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Perception.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Perception {

struct KnownCameraIntrinsicsProperties
{
    KnownCameraIntrinsicsProperties() = delete;
    static hstring FocalLength();
    static hstring PrincipalPoint();
    static hstring RadialDistortion();
    static hstring TangentialDistortion();
};

struct KnownPerceptionColorFrameSourceProperties
{
    KnownPerceptionColorFrameSourceProperties() = delete;
    static hstring Exposure();
    static hstring AutoExposureEnabled();
    static hstring ExposureCompensation();
};

struct KnownPerceptionDepthFrameSourceProperties
{
    KnownPerceptionDepthFrameSourceProperties() = delete;
    static hstring MinDepth();
    static hstring MaxDepth();
};

struct KnownPerceptionFrameSourceProperties
{
    KnownPerceptionFrameSourceProperties() = delete;
    static hstring Id();
    static hstring PhysicalDeviceIds();
    static hstring FrameKind();
    static hstring DeviceModelVersion();
    static hstring EnclosureLocation();
    static hstring DeviceId();
};

struct KnownPerceptionInfraredFrameSourceProperties
{
    KnownPerceptionInfraredFrameSourceProperties() = delete;
    static hstring Exposure();
    static hstring AutoExposureEnabled();
    static hstring ExposureCompensation();
    static hstring ActiveIlluminationEnabled();
    static hstring AmbientSubtractionEnabled();
    static hstring StructureLightPatternEnabled();
    static hstring InterleavedIlluminationEnabled();
};

struct KnownPerceptionVideoFrameSourceProperties
{
    KnownPerceptionVideoFrameSourceProperties() = delete;
    static hstring VideoProfile();
    static hstring SupportedVideoProfiles();
    static hstring AvailableVideoProfiles();
    static hstring IsMirrored();
    static hstring CameraIntrinsics();
};

struct KnownPerceptionVideoProfileProperties
{
    KnownPerceptionVideoProfileProperties() = delete;
    static hstring BitmapPixelFormat();
    static hstring BitmapAlphaMode();
    static hstring Width();
    static hstring Height();
    static hstring FrameDuration();
};

struct WINRT_EBO PerceptionColorFrame :
    Windows::Devices::Perception::IPerceptionColorFrame
{
    PerceptionColorFrame(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionColorFrameArrivedEventArgs :
    Windows::Devices::Perception::IPerceptionColorFrameArrivedEventArgs
{
    PerceptionColorFrameArrivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionColorFrameReader :
    Windows::Devices::Perception::IPerceptionColorFrameReader
{
    PerceptionColorFrameReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionColorFrameSource :
    Windows::Devices::Perception::IPerceptionColorFrameSource,
    impl::require<PerceptionColorFrameSource, Windows::Devices::Perception::IPerceptionColorFrameSource2>
{
    PerceptionColorFrameSource(std::nullptr_t) noexcept {}
    static Windows::Devices::Perception::PerceptionColorFrameSourceWatcher CreateWatcher();
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionColorFrameSource>> FindAllAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionColorFrameSource> FromIdAsync(hstring_view id);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> RequestAccessAsync();
};

struct WINRT_EBO PerceptionColorFrameSourceAddedEventArgs :
    Windows::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs
{
    PerceptionColorFrameSourceAddedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionColorFrameSourceRemovedEventArgs :
    Windows::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs
{
    PerceptionColorFrameSourceRemovedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionColorFrameSourceWatcher :
    Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher
{
    PerceptionColorFrameSourceWatcher(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionControlSession :
    Windows::Devices::Perception::IPerceptionControlSession
{
    PerceptionControlSession(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionDepthCorrelatedCameraIntrinsics :
    Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics
{
    PerceptionDepthCorrelatedCameraIntrinsics(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionDepthCorrelatedCoordinateMapper :
    Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper
{
    PerceptionDepthCorrelatedCoordinateMapper(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionDepthFrame :
    Windows::Devices::Perception::IPerceptionDepthFrame
{
    PerceptionDepthFrame(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionDepthFrameArrivedEventArgs :
    Windows::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs
{
    PerceptionDepthFrameArrivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionDepthFrameReader :
    Windows::Devices::Perception::IPerceptionDepthFrameReader
{
    PerceptionDepthFrameReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionDepthFrameSource :
    Windows::Devices::Perception::IPerceptionDepthFrameSource,
    impl::require<PerceptionDepthFrameSource, Windows::Devices::Perception::IPerceptionDepthFrameSource2>
{
    PerceptionDepthFrameSource(std::nullptr_t) noexcept {}
    static Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher CreateWatcher();
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionDepthFrameSource>> FindAllAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthFrameSource> FromIdAsync(hstring_view id);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> RequestAccessAsync();
};

struct WINRT_EBO PerceptionDepthFrameSourceAddedEventArgs :
    Windows::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs
{
    PerceptionDepthFrameSourceAddedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionDepthFrameSourceRemovedEventArgs :
    Windows::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs
{
    PerceptionDepthFrameSourceRemovedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionDepthFrameSourceWatcher :
    Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher
{
    PerceptionDepthFrameSourceWatcher(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionFrameSourcePropertiesChangedEventArgs :
    Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs
{
    PerceptionFrameSourcePropertiesChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionFrameSourcePropertyChangeResult :
    Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult
{
    PerceptionFrameSourcePropertyChangeResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionInfraredFrame :
    Windows::Devices::Perception::IPerceptionInfraredFrame
{
    PerceptionInfraredFrame(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionInfraredFrameArrivedEventArgs :
    Windows::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs
{
    PerceptionInfraredFrameArrivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionInfraredFrameReader :
    Windows::Devices::Perception::IPerceptionInfraredFrameReader
{
    PerceptionInfraredFrameReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionInfraredFrameSource :
    Windows::Devices::Perception::IPerceptionInfraredFrameSource,
    impl::require<PerceptionInfraredFrameSource, Windows::Devices::Perception::IPerceptionInfraredFrameSource2>
{
    PerceptionInfraredFrameSource(std::nullptr_t) noexcept {}
    static Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher CreateWatcher();
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionInfraredFrameSource>> FindAllAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionInfraredFrameSource> FromIdAsync(hstring_view id);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> RequestAccessAsync();
};

struct WINRT_EBO PerceptionInfraredFrameSourceAddedEventArgs :
    Windows::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs
{
    PerceptionInfraredFrameSourceAddedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionInfraredFrameSourceRemovedEventArgs :
    Windows::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs
{
    PerceptionInfraredFrameSourceRemovedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionInfraredFrameSourceWatcher :
    Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher
{
    PerceptionInfraredFrameSourceWatcher(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PerceptionVideoProfile :
    Windows::Devices::Perception::IPerceptionVideoProfile
{
    PerceptionVideoProfile(std::nullptr_t) noexcept {}
};

}

}
