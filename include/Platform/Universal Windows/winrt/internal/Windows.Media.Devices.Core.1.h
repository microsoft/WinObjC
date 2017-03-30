// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.Devices.Core.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Media.MediaProperties.0.h"
#include "Windows.Perception.Spatial.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Devices::Core {

struct __declspec(uuid("0aa6ed32-6589-49da-afde-594270ca0aac")) __declspec(novtable) ICameraIntrinsics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FocalLength(Windows::Foundation::Numerics::float2 * value) = 0;
    virtual HRESULT __stdcall get_PrincipalPoint(Windows::Foundation::Numerics::float2 * value) = 0;
    virtual HRESULT __stdcall get_RadialDistortion(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall get_TangentialDistortion(Windows::Foundation::Numerics::float2 * value) = 0;
    virtual HRESULT __stdcall get_ImageWidth(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ImageHeight(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_ProjectOntoFrame(Windows::Foundation::Numerics::float3 coordinate, Windows::Foundation::Point * result) = 0;
    virtual HRESULT __stdcall abi_UnprojectAtUnitDepth(Windows::Foundation::Point pixelCoordinate, Windows::Foundation::Numerics::float2 * result) = 0;
    virtual HRESULT __stdcall abi_ProjectManyOntoFrame(uint32_t __coordinatesSize, Windows::Foundation::Numerics::float3 * coordinates, uint32_t __resultsSize, Windows::Foundation::Point * results) = 0;
    virtual HRESULT __stdcall abi_UnprojectPixelsAtUnitDepth(uint32_t __pixelCoordinatesSize, Windows::Foundation::Point * pixelCoordinates, uint32_t __resultsSize, Windows::Foundation::Numerics::float2 * results) = 0;
};

struct __declspec(uuid("0cdaa447-0798-4b4d-839f-c5ec414db27a")) __declspec(novtable) ICameraIntrinsics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UndistortedProjectionTransform(Windows::Foundation::Numerics::float4x4 * value) = 0;
    virtual HRESULT __stdcall abi_DistortPoint(Windows::Foundation::Point input, Windows::Foundation::Point * result) = 0;
    virtual HRESULT __stdcall abi_DistortPoints(uint32_t __inputsSize, Windows::Foundation::Point * inputs, uint32_t __resultsSize, Windows::Foundation::Point * results) = 0;
    virtual HRESULT __stdcall abi_UndistortPoint(Windows::Foundation::Point input, Windows::Foundation::Point * result) = 0;
    virtual HRESULT __stdcall abi_UndistortPoints(uint32_t __inputsSize, Windows::Foundation::Point * inputs, uint32_t __resultsSize, Windows::Foundation::Point * results) = 0;
};

struct __declspec(uuid("c0ddc486-2132-4a34-a659-9bfe2a055712")) __declspec(novtable) ICameraIntrinsicsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Foundation::Numerics::float2 focalLength, Windows::Foundation::Numerics::float2 principalPoint, Windows::Foundation::Numerics::float3 radialDistortion, Windows::Foundation::Numerics::float2 tangentialDistortion, uint32_t imageWidth, uint32_t imageHeight, Windows::Media::Devices::Core::ICameraIntrinsics ** result) = 0;
};

struct __declspec(uuid("f95d89fb-8af0-4cb0-926d-696866e5046a")) __declspec(novtable) IDepthCorrelatedCoordinateMapper : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_UnprojectPoint(Windows::Foundation::Point sourcePoint, Windows::Perception::Spatial::ISpatialCoordinateSystem * targetCoordinateSystem, Windows::Foundation::Numerics::float3 * result) = 0;
    virtual HRESULT __stdcall abi_UnprojectPoints(uint32_t __sourcePointsSize, Windows::Foundation::Point * sourcePoints, Windows::Perception::Spatial::ISpatialCoordinateSystem * targetCoordinateSystem, uint32_t __resultsSize, Windows::Foundation::Numerics::float3 * results) = 0;
    virtual HRESULT __stdcall abi_MapPoint(Windows::Foundation::Point sourcePoint, Windows::Perception::Spatial::ISpatialCoordinateSystem * targetCoordinateSystem, Windows::Media::Devices::Core::ICameraIntrinsics * targetCameraIntrinsics, Windows::Foundation::Point * result) = 0;
    virtual HRESULT __stdcall abi_MapPoints(uint32_t __sourcePointsSize, Windows::Foundation::Point * sourcePoints, Windows::Perception::Spatial::ISpatialCoordinateSystem * targetCoordinateSystem, Windows::Media::Devices::Core::ICameraIntrinsics * targetCameraIntrinsics, uint32_t __resultsSize, Windows::Foundation::Point * results) = 0;
};

struct __declspec(uuid("a8ffae60-4e9e-4377-a789-e24c4ae7e544")) __declspec(novtable) IFrameControlCapabilities : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Exposure(Windows::Media::Devices::Core::IFrameExposureCapabilities ** value) = 0;
    virtual HRESULT __stdcall get_ExposureCompensation(Windows::Media::Devices::Core::IFrameExposureCompensationCapabilities ** value) = 0;
    virtual HRESULT __stdcall get_IsoSpeed(Windows::Media::Devices::Core::IFrameIsoSpeedCapabilities ** value) = 0;
    virtual HRESULT __stdcall get_Focus(Windows::Media::Devices::Core::IFrameFocusCapabilities ** value) = 0;
    virtual HRESULT __stdcall get_PhotoConfirmationSupported(bool * value) = 0;
};

struct __declspec(uuid("ce9b0464-4730-440f-bd3e-efe8a8f230a8")) __declspec(novtable) IFrameControlCapabilities2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Flash(Windows::Media::Devices::Core::IFrameFlashCapabilities ** value) = 0;
};

struct __declspec(uuid("c16459d9-baef-4052-9177-48aff2af7522")) __declspec(novtable) IFrameController : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExposureControl(Windows::Media::Devices::Core::IFrameExposureControl ** value) = 0;
    virtual HRESULT __stdcall get_ExposureCompensationControl(Windows::Media::Devices::Core::IFrameExposureCompensationControl ** value) = 0;
    virtual HRESULT __stdcall get_IsoSpeedControl(Windows::Media::Devices::Core::IFrameIsoSpeedControl ** value) = 0;
    virtual HRESULT __stdcall get_FocusControl(Windows::Media::Devices::Core::IFrameFocusControl ** value) = 0;
    virtual HRESULT __stdcall get_PhotoConfirmationEnabled(Windows::Foundation::IReference<bool> ** value) = 0;
    virtual HRESULT __stdcall put_PhotoConfirmationEnabled(Windows::Foundation::IReference<bool> * value) = 0;
};

struct __declspec(uuid("00d3bc75-d87c-485b-8a09-5c358568b427")) __declspec(novtable) IFrameController2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FlashControl(Windows::Media::Devices::Core::IFrameFlashControl ** value) = 0;
};

struct __declspec(uuid("bdbe9ce3-3985-4e72-97c2-0590d61307a1")) __declspec(novtable) IFrameExposureCapabilities : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_Min(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Max(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Step(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("b988a823-8065-41ee-b04f-722265954500")) __declspec(novtable) IFrameExposureCompensationCapabilities : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_Min(float * value) = 0;
    virtual HRESULT __stdcall get_Max(float * value) = 0;
    virtual HRESULT __stdcall get_Step(float * value) = 0;
};

struct __declspec(uuid("e95896c9-f7f9-48ca-8591-a26531cb1578")) __declspec(novtable) IFrameExposureCompensationControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Value(Windows::Foundation::IReference<float> ** value) = 0;
    virtual HRESULT __stdcall put_Value(Windows::Foundation::IReference<float> * value) = 0;
};

struct __declspec(uuid("b1605a61-ffaf-4752-b621-f5b6f117f432")) __declspec(novtable) IFrameExposureControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Auto(bool * value) = 0;
    virtual HRESULT __stdcall put_Auto(bool value) = 0;
    virtual HRESULT __stdcall get_Value(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall put_Value(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> * value) = 0;
};

struct __declspec(uuid("bb9341a2-5ebe-4f62-8223-0e2b05bfbbd0")) __declspec(novtable) IFrameFlashCapabilities : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_RedEyeReductionSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_PowerSupported(bool * value) = 0;
};

struct __declspec(uuid("75d5f6c7-bd45-4fab-9375-45ac04b332c2")) __declspec(novtable) IFrameFlashControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Mode(winrt::Windows::Media::Devices::Core::FrameFlashMode * value) = 0;
    virtual HRESULT __stdcall put_Mode(winrt::Windows::Media::Devices::Core::FrameFlashMode value) = 0;
    virtual HRESULT __stdcall get_Auto(bool * value) = 0;
    virtual HRESULT __stdcall put_Auto(bool value) = 0;
    virtual HRESULT __stdcall get_RedEyeReduction(bool * value) = 0;
    virtual HRESULT __stdcall put_RedEyeReduction(bool value) = 0;
    virtual HRESULT __stdcall get_PowerPercent(float * value) = 0;
    virtual HRESULT __stdcall put_PowerPercent(float value) = 0;
};

struct __declspec(uuid("7b25cd58-01c0-4065-9c40-c1a721425c1a")) __declspec(novtable) IFrameFocusCapabilities : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_Min(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Max(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Step(uint32_t * value) = 0;
};

struct __declspec(uuid("272df1d0-d912-4214-a67b-e38a8d48d8c6")) __declspec(novtable) IFrameFocusControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Value(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall put_Value(Windows::Foundation::IReference<uint32_t> * value) = 0;
};

struct __declspec(uuid("16bdff61-6df6-4ac9-b92a-9f6ecd1ad2fa")) __declspec(novtable) IFrameIsoSpeedCapabilities : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_Min(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Max(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Step(uint32_t * value) = 0;
};

struct __declspec(uuid("1a03efed-786a-4c75-a557-7ab9a85f588c")) __declspec(novtable) IFrameIsoSpeedControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Auto(bool * value) = 0;
    virtual HRESULT __stdcall put_Auto(bool value) = 0;
    virtual HRESULT __stdcall get_Value(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall put_Value(Windows::Foundation::IReference<uint32_t> * value) = 0;
};

struct __declspec(uuid("7fbff880-ed8c-43fd-a7c3-b35809e4229a")) __declspec(novtable) IVariablePhotoSequenceController : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Supported(bool * value) = 0;
    virtual HRESULT __stdcall get_MaxPhotosPerSecond(float * value) = 0;
    virtual HRESULT __stdcall get_PhotosPerSecondLimit(float * value) = 0;
    virtual HRESULT __stdcall put_PhotosPerSecondLimit(float value) = 0;
    virtual HRESULT __stdcall abi_GetHighestConcurrentFrameRate(Windows::Media::MediaProperties::IMediaEncodingProperties * captureProperties, Windows::Media::MediaProperties::IMediaRatio ** value) = 0;
    virtual HRESULT __stdcall abi_GetCurrentFrameRate(Windows::Media::MediaProperties::IMediaRatio ** value) = 0;
    virtual HRESULT __stdcall get_FrameCapabilities(Windows::Media::Devices::Core::IFrameControlCapabilities ** value) = 0;
    virtual HRESULT __stdcall get_DesiredFrameControllers(Windows::Foundation::Collections::IVector<Windows::Media::Devices::Core::FrameController> ** items) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::Devices::Core::CameraIntrinsics> { using default_interface = Windows::Media::Devices::Core::ICameraIntrinsics; };
template <> struct traits<Windows::Media::Devices::Core::DepthCorrelatedCoordinateMapper> { using default_interface = Windows::Media::Devices::Core::IDepthCorrelatedCoordinateMapper; };
template <> struct traits<Windows::Media::Devices::Core::FrameControlCapabilities> { using default_interface = Windows::Media::Devices::Core::IFrameControlCapabilities; };
template <> struct traits<Windows::Media::Devices::Core::FrameController> { using default_interface = Windows::Media::Devices::Core::IFrameController; };
template <> struct traits<Windows::Media::Devices::Core::FrameExposureCapabilities> { using default_interface = Windows::Media::Devices::Core::IFrameExposureCapabilities; };
template <> struct traits<Windows::Media::Devices::Core::FrameExposureCompensationCapabilities> { using default_interface = Windows::Media::Devices::Core::IFrameExposureCompensationCapabilities; };
template <> struct traits<Windows::Media::Devices::Core::FrameExposureCompensationControl> { using default_interface = Windows::Media::Devices::Core::IFrameExposureCompensationControl; };
template <> struct traits<Windows::Media::Devices::Core::FrameExposureControl> { using default_interface = Windows::Media::Devices::Core::IFrameExposureControl; };
template <> struct traits<Windows::Media::Devices::Core::FrameFlashCapabilities> { using default_interface = Windows::Media::Devices::Core::IFrameFlashCapabilities; };
template <> struct traits<Windows::Media::Devices::Core::FrameFlashControl> { using default_interface = Windows::Media::Devices::Core::IFrameFlashControl; };
template <> struct traits<Windows::Media::Devices::Core::FrameFocusCapabilities> { using default_interface = Windows::Media::Devices::Core::IFrameFocusCapabilities; };
template <> struct traits<Windows::Media::Devices::Core::FrameFocusControl> { using default_interface = Windows::Media::Devices::Core::IFrameFocusControl; };
template <> struct traits<Windows::Media::Devices::Core::FrameIsoSpeedCapabilities> { using default_interface = Windows::Media::Devices::Core::IFrameIsoSpeedCapabilities; };
template <> struct traits<Windows::Media::Devices::Core::FrameIsoSpeedControl> { using default_interface = Windows::Media::Devices::Core::IFrameIsoSpeedControl; };
template <> struct traits<Windows::Media::Devices::Core::VariablePhotoSequenceController> { using default_interface = Windows::Media::Devices::Core::IVariablePhotoSequenceController; };

}

namespace Windows::Media::Devices::Core {

template <typename D>
struct WINRT_EBO impl_ICameraIntrinsics
{
    Windows::Foundation::Numerics::float2 FocalLength() const;
    Windows::Foundation::Numerics::float2 PrincipalPoint() const;
    Windows::Foundation::Numerics::float3 RadialDistortion() const;
    Windows::Foundation::Numerics::float2 TangentialDistortion() const;
    uint32_t ImageWidth() const;
    uint32_t ImageHeight() const;
    Windows::Foundation::Point ProjectOntoFrame(const Windows::Foundation::Numerics::float3 & coordinate) const;
    Windows::Foundation::Numerics::float2 UnprojectAtUnitDepth(const Windows::Foundation::Point & pixelCoordinate) const;
    void ProjectManyOntoFrame(array_view<const Windows::Foundation::Numerics::float3> coordinates, array_view<Windows::Foundation::Point> results) const;
    void UnprojectPixelsAtUnitDepth(array_view<const Windows::Foundation::Point> pixelCoordinates, array_view<Windows::Foundation::Numerics::float2> results) const;
};

template <typename D>
struct WINRT_EBO impl_ICameraIntrinsics2
{
    Windows::Foundation::Numerics::float4x4 UndistortedProjectionTransform() const;
    Windows::Foundation::Point DistortPoint(const Windows::Foundation::Point & input) const;
    void DistortPoints(array_view<const Windows::Foundation::Point> inputs, array_view<Windows::Foundation::Point> results) const;
    Windows::Foundation::Point UndistortPoint(const Windows::Foundation::Point & input) const;
    void UndistortPoints(array_view<const Windows::Foundation::Point> inputs, array_view<Windows::Foundation::Point> results) const;
};

template <typename D>
struct WINRT_EBO impl_ICameraIntrinsicsFactory
{
    Windows::Media::Devices::Core::CameraIntrinsics Create(const Windows::Foundation::Numerics::float2 & focalLength, const Windows::Foundation::Numerics::float2 & principalPoint, const Windows::Foundation::Numerics::float3 & radialDistortion, const Windows::Foundation::Numerics::float2 & tangentialDistortion, uint32_t imageWidth, uint32_t imageHeight) const;
};

template <typename D>
struct WINRT_EBO impl_IDepthCorrelatedCoordinateMapper
{
    Windows::Foundation::Numerics::float3 UnprojectPoint(const Windows::Foundation::Point & sourcePoint, const Windows::Perception::Spatial::SpatialCoordinateSystem & targetCoordinateSystem) const;
    void UnprojectPoints(array_view<const Windows::Foundation::Point> sourcePoints, const Windows::Perception::Spatial::SpatialCoordinateSystem & targetCoordinateSystem, array_view<Windows::Foundation::Numerics::float3> results) const;
    Windows::Foundation::Point MapPoint(const Windows::Foundation::Point & sourcePoint, const Windows::Perception::Spatial::SpatialCoordinateSystem & targetCoordinateSystem, const Windows::Media::Devices::Core::CameraIntrinsics & targetCameraIntrinsics) const;
    void MapPoints(array_view<const Windows::Foundation::Point> sourcePoints, const Windows::Perception::Spatial::SpatialCoordinateSystem & targetCoordinateSystem, const Windows::Media::Devices::Core::CameraIntrinsics & targetCameraIntrinsics, array_view<Windows::Foundation::Point> results) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameControlCapabilities
{
    Windows::Media::Devices::Core::FrameExposureCapabilities Exposure() const;
    Windows::Media::Devices::Core::FrameExposureCompensationCapabilities ExposureCompensation() const;
    Windows::Media::Devices::Core::FrameIsoSpeedCapabilities IsoSpeed() const;
    Windows::Media::Devices::Core::FrameFocusCapabilities Focus() const;
    bool PhotoConfirmationSupported() const;
};

template <typename D>
struct WINRT_EBO impl_IFrameControlCapabilities2
{
    Windows::Media::Devices::Core::FrameFlashCapabilities Flash() const;
};

template <typename D>
struct WINRT_EBO impl_IFrameController
{
    Windows::Media::Devices::Core::FrameExposureControl ExposureControl() const;
    Windows::Media::Devices::Core::FrameExposureCompensationControl ExposureCompensationControl() const;
    Windows::Media::Devices::Core::FrameIsoSpeedControl IsoSpeedControl() const;
    Windows::Media::Devices::Core::FrameFocusControl FocusControl() const;
    Windows::Foundation::IReference<bool> PhotoConfirmationEnabled() const;
    void PhotoConfirmationEnabled(const optional<bool> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameController2
{
    Windows::Media::Devices::Core::FrameFlashControl FlashControl() const;
};

template <typename D>
struct WINRT_EBO impl_IFrameExposureCapabilities
{
    bool Supported() const;
    Windows::Foundation::TimeSpan Min() const;
    Windows::Foundation::TimeSpan Max() const;
    Windows::Foundation::TimeSpan Step() const;
};

template <typename D>
struct WINRT_EBO impl_IFrameExposureCompensationCapabilities
{
    bool Supported() const;
    float Min() const;
    float Max() const;
    float Step() const;
};

template <typename D>
struct WINRT_EBO impl_IFrameExposureCompensationControl
{
    Windows::Foundation::IReference<float> Value() const;
    void Value(const optional<float> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameExposureControl
{
    bool Auto() const;
    void Auto(bool value) const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> Value() const;
    void Value(const optional<Windows::Foundation::TimeSpan> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameFlashCapabilities
{
    bool Supported() const;
    bool RedEyeReductionSupported() const;
    bool PowerSupported() const;
};

template <typename D>
struct WINRT_EBO impl_IFrameFlashControl
{
    Windows::Media::Devices::Core::FrameFlashMode Mode() const;
    void Mode(Windows::Media::Devices::Core::FrameFlashMode value) const;
    bool Auto() const;
    void Auto(bool value) const;
    bool RedEyeReduction() const;
    void RedEyeReduction(bool value) const;
    float PowerPercent() const;
    void PowerPercent(float value) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameFocusCapabilities
{
    bool Supported() const;
    uint32_t Min() const;
    uint32_t Max() const;
    uint32_t Step() const;
};

template <typename D>
struct WINRT_EBO impl_IFrameFocusControl
{
    Windows::Foundation::IReference<uint32_t> Value() const;
    void Value(const optional<uint32_t> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameIsoSpeedCapabilities
{
    bool Supported() const;
    uint32_t Min() const;
    uint32_t Max() const;
    uint32_t Step() const;
};

template <typename D>
struct WINRT_EBO impl_IFrameIsoSpeedControl
{
    bool Auto() const;
    void Auto(bool value) const;
    Windows::Foundation::IReference<uint32_t> Value() const;
    void Value(const optional<uint32_t> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IVariablePhotoSequenceController
{
    bool Supported() const;
    float MaxPhotosPerSecond() const;
    float PhotosPerSecondLimit() const;
    void PhotosPerSecondLimit(float value) const;
    Windows::Media::MediaProperties::MediaRatio GetHighestConcurrentFrameRate(const Windows::Media::MediaProperties::IMediaEncodingProperties & captureProperties) const;
    Windows::Media::MediaProperties::MediaRatio GetCurrentFrameRate() const;
    Windows::Media::Devices::Core::FrameControlCapabilities FrameCapabilities() const;
    Windows::Foundation::Collections::IVector<Windows::Media::Devices::Core::FrameController> DesiredFrameControllers() const;
};

}

namespace impl {

template <> struct traits<Windows::Media::Devices::Core::ICameraIntrinsics>
{
    using abi = ABI::Windows::Media::Devices::Core::ICameraIntrinsics;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_ICameraIntrinsics<D>;
};

template <> struct traits<Windows::Media::Devices::Core::ICameraIntrinsics2>
{
    using abi = ABI::Windows::Media::Devices::Core::ICameraIntrinsics2;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_ICameraIntrinsics2<D>;
};

template <> struct traits<Windows::Media::Devices::Core::ICameraIntrinsicsFactory>
{
    using abi = ABI::Windows::Media::Devices::Core::ICameraIntrinsicsFactory;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_ICameraIntrinsicsFactory<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IDepthCorrelatedCoordinateMapper>
{
    using abi = ABI::Windows::Media::Devices::Core::IDepthCorrelatedCoordinateMapper;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IDepthCorrelatedCoordinateMapper<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IFrameControlCapabilities>
{
    using abi = ABI::Windows::Media::Devices::Core::IFrameControlCapabilities;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IFrameControlCapabilities<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IFrameControlCapabilities2>
{
    using abi = ABI::Windows::Media::Devices::Core::IFrameControlCapabilities2;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IFrameControlCapabilities2<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IFrameController>
{
    using abi = ABI::Windows::Media::Devices::Core::IFrameController;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IFrameController<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IFrameController2>
{
    using abi = ABI::Windows::Media::Devices::Core::IFrameController2;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IFrameController2<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IFrameExposureCapabilities>
{
    using abi = ABI::Windows::Media::Devices::Core::IFrameExposureCapabilities;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IFrameExposureCapabilities<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IFrameExposureCompensationCapabilities>
{
    using abi = ABI::Windows::Media::Devices::Core::IFrameExposureCompensationCapabilities;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IFrameExposureCompensationCapabilities<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IFrameExposureCompensationControl>
{
    using abi = ABI::Windows::Media::Devices::Core::IFrameExposureCompensationControl;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IFrameExposureCompensationControl<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IFrameExposureControl>
{
    using abi = ABI::Windows::Media::Devices::Core::IFrameExposureControl;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IFrameExposureControl<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IFrameFlashCapabilities>
{
    using abi = ABI::Windows::Media::Devices::Core::IFrameFlashCapabilities;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IFrameFlashCapabilities<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IFrameFlashControl>
{
    using abi = ABI::Windows::Media::Devices::Core::IFrameFlashControl;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IFrameFlashControl<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IFrameFocusCapabilities>
{
    using abi = ABI::Windows::Media::Devices::Core::IFrameFocusCapabilities;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IFrameFocusCapabilities<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IFrameFocusControl>
{
    using abi = ABI::Windows::Media::Devices::Core::IFrameFocusControl;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IFrameFocusControl<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IFrameIsoSpeedCapabilities>
{
    using abi = ABI::Windows::Media::Devices::Core::IFrameIsoSpeedCapabilities;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IFrameIsoSpeedCapabilities<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IFrameIsoSpeedControl>
{
    using abi = ABI::Windows::Media::Devices::Core::IFrameIsoSpeedControl;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IFrameIsoSpeedControl<D>;
};

template <> struct traits<Windows::Media::Devices::Core::IVariablePhotoSequenceController>
{
    using abi = ABI::Windows::Media::Devices::Core::IVariablePhotoSequenceController;
    template <typename D> using consume = Windows::Media::Devices::Core::impl_IVariablePhotoSequenceController<D>;
};

template <> struct traits<Windows::Media::Devices::Core::CameraIntrinsics>
{
    using abi = ABI::Windows::Media::Devices::Core::CameraIntrinsics;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.CameraIntrinsics"; }
};

template <> struct traits<Windows::Media::Devices::Core::DepthCorrelatedCoordinateMapper>
{
    using abi = ABI::Windows::Media::Devices::Core::DepthCorrelatedCoordinateMapper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.DepthCorrelatedCoordinateMapper"; }
};

template <> struct traits<Windows::Media::Devices::Core::FrameControlCapabilities>
{
    using abi = ABI::Windows::Media::Devices::Core::FrameControlCapabilities;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.FrameControlCapabilities"; }
};

template <> struct traits<Windows::Media::Devices::Core::FrameController>
{
    using abi = ABI::Windows::Media::Devices::Core::FrameController;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.FrameController"; }
};

template <> struct traits<Windows::Media::Devices::Core::FrameExposureCapabilities>
{
    using abi = ABI::Windows::Media::Devices::Core::FrameExposureCapabilities;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.FrameExposureCapabilities"; }
};

template <> struct traits<Windows::Media::Devices::Core::FrameExposureCompensationCapabilities>
{
    using abi = ABI::Windows::Media::Devices::Core::FrameExposureCompensationCapabilities;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.FrameExposureCompensationCapabilities"; }
};

template <> struct traits<Windows::Media::Devices::Core::FrameExposureCompensationControl>
{
    using abi = ABI::Windows::Media::Devices::Core::FrameExposureCompensationControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.FrameExposureCompensationControl"; }
};

template <> struct traits<Windows::Media::Devices::Core::FrameExposureControl>
{
    using abi = ABI::Windows::Media::Devices::Core::FrameExposureControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.FrameExposureControl"; }
};

template <> struct traits<Windows::Media::Devices::Core::FrameFlashCapabilities>
{
    using abi = ABI::Windows::Media::Devices::Core::FrameFlashCapabilities;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.FrameFlashCapabilities"; }
};

template <> struct traits<Windows::Media::Devices::Core::FrameFlashControl>
{
    using abi = ABI::Windows::Media::Devices::Core::FrameFlashControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.FrameFlashControl"; }
};

template <> struct traits<Windows::Media::Devices::Core::FrameFocusCapabilities>
{
    using abi = ABI::Windows::Media::Devices::Core::FrameFocusCapabilities;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.FrameFocusCapabilities"; }
};

template <> struct traits<Windows::Media::Devices::Core::FrameFocusControl>
{
    using abi = ABI::Windows::Media::Devices::Core::FrameFocusControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.FrameFocusControl"; }
};

template <> struct traits<Windows::Media::Devices::Core::FrameIsoSpeedCapabilities>
{
    using abi = ABI::Windows::Media::Devices::Core::FrameIsoSpeedCapabilities;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.FrameIsoSpeedCapabilities"; }
};

template <> struct traits<Windows::Media::Devices::Core::FrameIsoSpeedControl>
{
    using abi = ABI::Windows::Media::Devices::Core::FrameIsoSpeedControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.FrameIsoSpeedControl"; }
};

template <> struct traits<Windows::Media::Devices::Core::VariablePhotoSequenceController>
{
    using abi = ABI::Windows::Media::Devices::Core::VariablePhotoSequenceController;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Devices.Core.VariablePhotoSequenceController"; }
};

}

}
