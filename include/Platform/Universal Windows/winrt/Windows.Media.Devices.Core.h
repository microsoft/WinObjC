// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Media.MediaProperties.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Perception.Spatial.3.h"
#include "internal/Windows.Media.Devices.Core.3.h"
#include "Windows.Media.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::Devices::Core::ICameraIntrinsics> : produce_base<D, Windows::Media::Devices::Core::ICameraIntrinsics>
{
    HRESULT __stdcall get_FocalLength(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocalLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrincipalPoint(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrincipalPoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RadialDistortion(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RadialDistortion());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TangentialDistortion(impl::abi_arg_out<Windows::Foundation::Numerics::float2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TangentialDistortion());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ImageWidth(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImageWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ImageHeight(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImageHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProjectOntoFrame(impl::abi_arg_in<Windows::Foundation::Numerics::float3> coordinate, impl::abi_arg_out<Windows::Foundation::Point> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ProjectOntoFrame(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&coordinate)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnprojectAtUnitDepth(impl::abi_arg_in<Windows::Foundation::Point> pixelCoordinate, impl::abi_arg_out<Windows::Foundation::Numerics::float2> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UnprojectAtUnitDepth(*reinterpret_cast<const Windows::Foundation::Point *>(&pixelCoordinate)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProjectManyOntoFrame(uint32_t __coordinatesSize, impl::abi_arg_in<Windows::Foundation::Numerics::float3> * coordinates, uint32_t __resultsSize, impl::abi_arg_out<Windows::Foundation::Point> results) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProjectManyOntoFrame(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&coordinates), *results);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnprojectPixelsAtUnitDepth(uint32_t __pixelCoordinatesSize, impl::abi_arg_in<Windows::Foundation::Point> * pixelCoordinates, uint32_t __resultsSize, impl::abi_arg_out<Windows::Foundation::Numerics::float2> results) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnprojectPixelsAtUnitDepth(*reinterpret_cast<const Windows::Foundation::Point *>(&pixelCoordinates), *results);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::ICameraIntrinsics2> : produce_base<D, Windows::Media::Devices::Core::ICameraIntrinsics2>
{
    HRESULT __stdcall get_UndistortedProjectionTransform(impl::abi_arg_out<Windows::Foundation::Numerics::float4x4> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UndistortedProjectionTransform());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DistortPoint(impl::abi_arg_in<Windows::Foundation::Point> input, impl::abi_arg_out<Windows::Foundation::Point> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DistortPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DistortPoints(uint32_t __inputsSize, impl::abi_arg_in<Windows::Foundation::Point> * inputs, uint32_t __resultsSize, impl::abi_arg_out<Windows::Foundation::Point> results) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DistortPoints(*reinterpret_cast<const Windows::Foundation::Point *>(&inputs), *results);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UndistortPoint(impl::abi_arg_in<Windows::Foundation::Point> input, impl::abi_arg_out<Windows::Foundation::Point> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UndistortPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UndistortPoints(uint32_t __inputsSize, impl::abi_arg_in<Windows::Foundation::Point> * inputs, uint32_t __resultsSize, impl::abi_arg_out<Windows::Foundation::Point> results) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UndistortPoints(*reinterpret_cast<const Windows::Foundation::Point *>(&inputs), *results);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::ICameraIntrinsicsFactory> : produce_base<D, Windows::Media::Devices::Core::ICameraIntrinsicsFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::Numerics::float2> focalLength, impl::abi_arg_in<Windows::Foundation::Numerics::float2> principalPoint, impl::abi_arg_in<Windows::Foundation::Numerics::float3> radialDistortion, impl::abi_arg_in<Windows::Foundation::Numerics::float2> tangentialDistortion, uint32_t imageWidth, uint32_t imageHeight, impl::abi_arg_out<Windows::Media::Devices::Core::ICameraIntrinsics> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&focalLength), *reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&principalPoint), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&radialDistortion), *reinterpret_cast<const Windows::Foundation::Numerics::float2 *>(&tangentialDistortion), imageWidth, imageHeight));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::IDepthCorrelatedCoordinateMapper> : produce_base<D, Windows::Media::Devices::Core::IDepthCorrelatedCoordinateMapper>
{
    HRESULT __stdcall abi_UnprojectPoint(impl::abi_arg_in<Windows::Foundation::Point> sourcePoint, impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> targetCoordinateSystem, impl::abi_arg_out<Windows::Foundation::Numerics::float3> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UnprojectPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&sourcePoint), *reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&targetCoordinateSystem)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnprojectPoints(uint32_t __sourcePointsSize, impl::abi_arg_in<Windows::Foundation::Point> * sourcePoints, impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> targetCoordinateSystem, uint32_t __resultsSize, impl::abi_arg_out<Windows::Foundation::Numerics::float3> results) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnprojectPoints(*reinterpret_cast<const Windows::Foundation::Point *>(&sourcePoints), *reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&targetCoordinateSystem), *results);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MapPoint(impl::abi_arg_in<Windows::Foundation::Point> sourcePoint, impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> targetCoordinateSystem, impl::abi_arg_in<Windows::Media::Devices::Core::ICameraIntrinsics> targetCameraIntrinsics, impl::abi_arg_out<Windows::Foundation::Point> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MapPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&sourcePoint), *reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&targetCoordinateSystem), *reinterpret_cast<const Windows::Media::Devices::Core::CameraIntrinsics *>(&targetCameraIntrinsics)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MapPoints(uint32_t __sourcePointsSize, impl::abi_arg_in<Windows::Foundation::Point> * sourcePoints, impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> targetCoordinateSystem, impl::abi_arg_in<Windows::Media::Devices::Core::ICameraIntrinsics> targetCameraIntrinsics, uint32_t __resultsSize, impl::abi_arg_out<Windows::Foundation::Point> results) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MapPoints(*reinterpret_cast<const Windows::Foundation::Point *>(&sourcePoints), *reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&targetCoordinateSystem), *reinterpret_cast<const Windows::Media::Devices::Core::CameraIntrinsics *>(&targetCameraIntrinsics), *results);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::IFrameControlCapabilities> : produce_base<D, Windows::Media::Devices::Core::IFrameControlCapabilities>
{
    HRESULT __stdcall get_Exposure(impl::abi_arg_out<Windows::Media::Devices::Core::IFrameExposureCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Exposure());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExposureCompensation(impl::abi_arg_out<Windows::Media::Devices::Core::IFrameExposureCompensationCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExposureCompensation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsoSpeed(impl::abi_arg_out<Windows::Media::Devices::Core::IFrameIsoSpeedCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsoSpeed());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Focus(impl::abi_arg_out<Windows::Media::Devices::Core::IFrameFocusCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Focus());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhotoConfirmationSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhotoConfirmationSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::IFrameControlCapabilities2> : produce_base<D, Windows::Media::Devices::Core::IFrameControlCapabilities2>
{
    HRESULT __stdcall get_Flash(impl::abi_arg_out<Windows::Media::Devices::Core::IFrameFlashCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Flash());
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
struct produce<D, Windows::Media::Devices::Core::IFrameController> : produce_base<D, Windows::Media::Devices::Core::IFrameController>
{
    HRESULT __stdcall get_ExposureControl(impl::abi_arg_out<Windows::Media::Devices::Core::IFrameExposureControl> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExposureControl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExposureCompensationControl(impl::abi_arg_out<Windows::Media::Devices::Core::IFrameExposureCompensationControl> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExposureCompensationControl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsoSpeedControl(impl::abi_arg_out<Windows::Media::Devices::Core::IFrameIsoSpeedControl> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsoSpeedControl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FocusControl(impl::abi_arg_out<Windows::Media::Devices::Core::IFrameFocusControl> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocusControl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhotoConfirmationEnabled(impl::abi_arg_out<Windows::Foundation::IReference<bool>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhotoConfirmationEnabled());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PhotoConfirmationEnabled(impl::abi_arg_in<Windows::Foundation::IReference<bool>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PhotoConfirmationEnabled(*reinterpret_cast<const Windows::Foundation::IReference<bool> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::IFrameController2> : produce_base<D, Windows::Media::Devices::Core::IFrameController2>
{
    HRESULT __stdcall get_FlashControl(impl::abi_arg_out<Windows::Media::Devices::Core::IFrameFlashControl> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FlashControl());
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
struct produce<D, Windows::Media::Devices::Core::IFrameExposureCapabilities> : produce_base<D, Windows::Media::Devices::Core::IFrameExposureCapabilities>
{
    HRESULT __stdcall get_Supported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Supported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Min(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Min());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Max(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Max());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Step(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Step());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::IFrameExposureCompensationCapabilities> : produce_base<D, Windows::Media::Devices::Core::IFrameExposureCompensationCapabilities>
{
    HRESULT __stdcall get_Supported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Supported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Min(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Min());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Max(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Max());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Step(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Step());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::IFrameExposureCompensationControl> : produce_base<D, Windows::Media::Devices::Core::IFrameExposureCompensationControl>
{
    HRESULT __stdcall get_Value(impl::abi_arg_out<Windows::Foundation::IReference<float>> value) noexcept override
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

    HRESULT __stdcall put_Value(impl::abi_arg_in<Windows::Foundation::IReference<float>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<const Windows::Foundation::IReference<float> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::IFrameExposureControl> : produce_base<D, Windows::Media::Devices::Core::IFrameExposureControl>
{
    HRESULT __stdcall get_Auto(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Auto());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Auto(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Auto(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
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

    HRESULT __stdcall put_Value(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::IFrameFlashCapabilities> : produce_base<D, Windows::Media::Devices::Core::IFrameFlashCapabilities>
{
    HRESULT __stdcall get_Supported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Supported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RedEyeReductionSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RedEyeReductionSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PowerSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PowerSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::IFrameFlashControl> : produce_base<D, Windows::Media::Devices::Core::IFrameFlashControl>
{
    HRESULT __stdcall get_Mode(Windows::Media::Devices::Core::FrameFlashMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Mode(Windows::Media::Devices::Core::FrameFlashMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Auto(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Auto());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Auto(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Auto(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RedEyeReduction(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RedEyeReduction());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RedEyeReduction(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RedEyeReduction(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PowerPercent(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PowerPercent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PowerPercent(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PowerPercent(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::IFrameFocusCapabilities> : produce_base<D, Windows::Media::Devices::Core::IFrameFocusCapabilities>
{
    HRESULT __stdcall get_Supported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Supported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Min(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Min());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Max(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Max());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Step(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Step());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::IFrameFocusControl> : produce_base<D, Windows::Media::Devices::Core::IFrameFocusControl>
{
    HRESULT __stdcall get_Value(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
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

    HRESULT __stdcall put_Value(impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::IFrameIsoSpeedCapabilities> : produce_base<D, Windows::Media::Devices::Core::IFrameIsoSpeedCapabilities>
{
    HRESULT __stdcall get_Supported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Supported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Min(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Min());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Max(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Max());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Step(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Step());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::IFrameIsoSpeedControl> : produce_base<D, Windows::Media::Devices::Core::IFrameIsoSpeedControl>
{
    HRESULT __stdcall get_Auto(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Auto());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Auto(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Auto(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
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

    HRESULT __stdcall put_Value(impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Devices::Core::IVariablePhotoSequenceController> : produce_base<D, Windows::Media::Devices::Core::IVariablePhotoSequenceController>
{
    HRESULT __stdcall get_Supported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Supported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxPhotosPerSecond(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPhotosPerSecond());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhotosPerSecondLimit(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhotosPerSecondLimit());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PhotosPerSecondLimit(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PhotosPerSecondLimit(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHighestConcurrentFrameRate(impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProperties> captureProperties, impl::abi_arg_out<Windows::Media::MediaProperties::IMediaRatio> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetHighestConcurrentFrameRate(*reinterpret_cast<const Windows::Media::MediaProperties::IMediaEncodingProperties *>(&captureProperties)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentFrameRate(impl::abi_arg_out<Windows::Media::MediaProperties::IMediaRatio> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCurrentFrameRate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrameCapabilities(impl::abi_arg_out<Windows::Media::Devices::Core::IFrameControlCapabilities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameCapabilities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredFrameControllers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Media::Devices::Core::FrameController>> items) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *items = detach_abi(this->shim().DesiredFrameControllers());
            return S_OK;
        }
        catch (...)
        {
            *items = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::Devices::Core {

template <typename D> bool impl_IFrameExposureCapabilities<D>::Supported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFrameExposureCapabilities)->get_Supported(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IFrameExposureCapabilities<D>::Min() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IFrameExposureCapabilities)->get_Min(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IFrameExposureCapabilities<D>::Max() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IFrameExposureCapabilities)->get_Max(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IFrameExposureCapabilities<D>::Step() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IFrameExposureCapabilities)->get_Step(put_abi(value)));
    return value;
}

template <typename D> bool impl_IFrameExposureCompensationCapabilities<D>::Supported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFrameExposureCompensationCapabilities)->get_Supported(&value));
    return value;
}

template <typename D> float impl_IFrameExposureCompensationCapabilities<D>::Min() const
{
    float value {};
    check_hresult(WINRT_SHIM(IFrameExposureCompensationCapabilities)->get_Min(&value));
    return value;
}

template <typename D> float impl_IFrameExposureCompensationCapabilities<D>::Max() const
{
    float value {};
    check_hresult(WINRT_SHIM(IFrameExposureCompensationCapabilities)->get_Max(&value));
    return value;
}

template <typename D> float impl_IFrameExposureCompensationCapabilities<D>::Step() const
{
    float value {};
    check_hresult(WINRT_SHIM(IFrameExposureCompensationCapabilities)->get_Step(&value));
    return value;
}

template <typename D> bool impl_IFrameIsoSpeedCapabilities<D>::Supported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFrameIsoSpeedCapabilities)->get_Supported(&value));
    return value;
}

template <typename D> uint32_t impl_IFrameIsoSpeedCapabilities<D>::Min() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IFrameIsoSpeedCapabilities)->get_Min(&value));
    return value;
}

template <typename D> uint32_t impl_IFrameIsoSpeedCapabilities<D>::Max() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IFrameIsoSpeedCapabilities)->get_Max(&value));
    return value;
}

template <typename D> uint32_t impl_IFrameIsoSpeedCapabilities<D>::Step() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IFrameIsoSpeedCapabilities)->get_Step(&value));
    return value;
}

template <typename D> bool impl_IFrameFocusCapabilities<D>::Supported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFrameFocusCapabilities)->get_Supported(&value));
    return value;
}

template <typename D> uint32_t impl_IFrameFocusCapabilities<D>::Min() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IFrameFocusCapabilities)->get_Min(&value));
    return value;
}

template <typename D> uint32_t impl_IFrameFocusCapabilities<D>::Max() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IFrameFocusCapabilities)->get_Max(&value));
    return value;
}

template <typename D> uint32_t impl_IFrameFocusCapabilities<D>::Step() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IFrameFocusCapabilities)->get_Step(&value));
    return value;
}

template <typename D> bool impl_IFrameFlashCapabilities<D>::Supported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFrameFlashCapabilities)->get_Supported(&value));
    return value;
}

template <typename D> bool impl_IFrameFlashCapabilities<D>::RedEyeReductionSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFrameFlashCapabilities)->get_RedEyeReductionSupported(&value));
    return value;
}

template <typename D> bool impl_IFrameFlashCapabilities<D>::PowerSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFrameFlashCapabilities)->get_PowerSupported(&value));
    return value;
}

template <typename D> Windows::Media::Devices::Core::FrameExposureCapabilities impl_IFrameControlCapabilities<D>::Exposure() const
{
    Windows::Media::Devices::Core::FrameExposureCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(IFrameControlCapabilities)->get_Exposure(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::Core::FrameExposureCompensationCapabilities impl_IFrameControlCapabilities<D>::ExposureCompensation() const
{
    Windows::Media::Devices::Core::FrameExposureCompensationCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(IFrameControlCapabilities)->get_ExposureCompensation(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::Core::FrameIsoSpeedCapabilities impl_IFrameControlCapabilities<D>::IsoSpeed() const
{
    Windows::Media::Devices::Core::FrameIsoSpeedCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(IFrameControlCapabilities)->get_IsoSpeed(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::Core::FrameFocusCapabilities impl_IFrameControlCapabilities<D>::Focus() const
{
    Windows::Media::Devices::Core::FrameFocusCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(IFrameControlCapabilities)->get_Focus(put_abi(value)));
    return value;
}

template <typename D> bool impl_IFrameControlCapabilities<D>::PhotoConfirmationSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFrameControlCapabilities)->get_PhotoConfirmationSupported(&value));
    return value;
}

template <typename D> Windows::Media::Devices::Core::FrameFlashCapabilities impl_IFrameControlCapabilities2<D>::Flash() const
{
    Windows::Media::Devices::Core::FrameFlashCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(IFrameControlCapabilities2)->get_Flash(put_abi(value)));
    return value;
}

template <typename D> bool impl_IFrameExposureControl<D>::Auto() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFrameExposureControl)->get_Auto(&value));
    return value;
}

template <typename D> void impl_IFrameExposureControl<D>::Auto(bool value) const
{
    check_hresult(WINRT_SHIM(IFrameExposureControl)->put_Auto(value));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IFrameExposureControl<D>::Value() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IFrameExposureControl)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameExposureControl<D>::Value(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IFrameExposureControl)->put_Value(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<float> impl_IFrameExposureCompensationControl<D>::Value() const
{
    Windows::Foundation::IReference<float> value;
    check_hresult(WINRT_SHIM(IFrameExposureCompensationControl)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameExposureCompensationControl<D>::Value(const optional<float> & value) const
{
    check_hresult(WINRT_SHIM(IFrameExposureCompensationControl)->put_Value(get_abi(value)));
}

template <typename D> bool impl_IFrameIsoSpeedControl<D>::Auto() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFrameIsoSpeedControl)->get_Auto(&value));
    return value;
}

template <typename D> void impl_IFrameIsoSpeedControl<D>::Auto(bool value) const
{
    check_hresult(WINRT_SHIM(IFrameIsoSpeedControl)->put_Auto(value));
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IFrameIsoSpeedControl<D>::Value() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IFrameIsoSpeedControl)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameIsoSpeedControl<D>::Value(const optional<uint32_t> & value) const
{
    check_hresult(WINRT_SHIM(IFrameIsoSpeedControl)->put_Value(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IFrameFocusControl<D>::Value() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IFrameFocusControl)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameFocusControl<D>::Value(const optional<uint32_t> & value) const
{
    check_hresult(WINRT_SHIM(IFrameFocusControl)->put_Value(get_abi(value)));
}

template <typename D> Windows::Media::Devices::Core::FrameFlashMode impl_IFrameFlashControl<D>::Mode() const
{
    Windows::Media::Devices::Core::FrameFlashMode value {};
    check_hresult(WINRT_SHIM(IFrameFlashControl)->get_Mode(&value));
    return value;
}

template <typename D> void impl_IFrameFlashControl<D>::Mode(Windows::Media::Devices::Core::FrameFlashMode value) const
{
    check_hresult(WINRT_SHIM(IFrameFlashControl)->put_Mode(value));
}

template <typename D> bool impl_IFrameFlashControl<D>::Auto() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFrameFlashControl)->get_Auto(&value));
    return value;
}

template <typename D> void impl_IFrameFlashControl<D>::Auto(bool value) const
{
    check_hresult(WINRT_SHIM(IFrameFlashControl)->put_Auto(value));
}

template <typename D> bool impl_IFrameFlashControl<D>::RedEyeReduction() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFrameFlashControl)->get_RedEyeReduction(&value));
    return value;
}

template <typename D> void impl_IFrameFlashControl<D>::RedEyeReduction(bool value) const
{
    check_hresult(WINRT_SHIM(IFrameFlashControl)->put_RedEyeReduction(value));
}

template <typename D> float impl_IFrameFlashControl<D>::PowerPercent() const
{
    float value {};
    check_hresult(WINRT_SHIM(IFrameFlashControl)->get_PowerPercent(&value));
    return value;
}

template <typename D> void impl_IFrameFlashControl<D>::PowerPercent(float value) const
{
    check_hresult(WINRT_SHIM(IFrameFlashControl)->put_PowerPercent(value));
}

template <typename D> Windows::Media::Devices::Core::FrameExposureControl impl_IFrameController<D>::ExposureControl() const
{
    Windows::Media::Devices::Core::FrameExposureControl value { nullptr };
    check_hresult(WINRT_SHIM(IFrameController)->get_ExposureControl(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::Core::FrameExposureCompensationControl impl_IFrameController<D>::ExposureCompensationControl() const
{
    Windows::Media::Devices::Core::FrameExposureCompensationControl value { nullptr };
    check_hresult(WINRT_SHIM(IFrameController)->get_ExposureCompensationControl(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::Core::FrameIsoSpeedControl impl_IFrameController<D>::IsoSpeedControl() const
{
    Windows::Media::Devices::Core::FrameIsoSpeedControl value { nullptr };
    check_hresult(WINRT_SHIM(IFrameController)->get_IsoSpeedControl(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::Core::FrameFocusControl impl_IFrameController<D>::FocusControl() const
{
    Windows::Media::Devices::Core::FrameFocusControl value { nullptr };
    check_hresult(WINRT_SHIM(IFrameController)->get_FocusControl(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<bool> impl_IFrameController<D>::PhotoConfirmationEnabled() const
{
    Windows::Foundation::IReference<bool> value;
    check_hresult(WINRT_SHIM(IFrameController)->get_PhotoConfirmationEnabled(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameController<D>::PhotoConfirmationEnabled(const optional<bool> & value) const
{
    check_hresult(WINRT_SHIM(IFrameController)->put_PhotoConfirmationEnabled(get_abi(value)));
}

template <typename D> Windows::Media::Devices::Core::FrameFlashControl impl_IFrameController2<D>::FlashControl() const
{
    Windows::Media::Devices::Core::FrameFlashControl value { nullptr };
    check_hresult(WINRT_SHIM(IFrameController2)->get_FlashControl(put_abi(value)));
    return value;
}

template <typename D> bool impl_IVariablePhotoSequenceController<D>::Supported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceController)->get_Supported(&value));
    return value;
}

template <typename D> float impl_IVariablePhotoSequenceController<D>::MaxPhotosPerSecond() const
{
    float value {};
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceController)->get_MaxPhotosPerSecond(&value));
    return value;
}

template <typename D> float impl_IVariablePhotoSequenceController<D>::PhotosPerSecondLimit() const
{
    float value {};
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceController)->get_PhotosPerSecondLimit(&value));
    return value;
}

template <typename D> void impl_IVariablePhotoSequenceController<D>::PhotosPerSecondLimit(float value) const
{
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceController)->put_PhotosPerSecondLimit(value));
}

template <typename D> Windows::Media::MediaProperties::MediaRatio impl_IVariablePhotoSequenceController<D>::GetHighestConcurrentFrameRate(const Windows::Media::MediaProperties::IMediaEncodingProperties & captureProperties) const
{
    Windows::Media::MediaProperties::MediaRatio value { nullptr };
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceController)->abi_GetHighestConcurrentFrameRate(get_abi(captureProperties), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::MediaProperties::MediaRatio impl_IVariablePhotoSequenceController<D>::GetCurrentFrameRate() const
{
    Windows::Media::MediaProperties::MediaRatio value { nullptr };
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceController)->abi_GetCurrentFrameRate(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::Core::FrameControlCapabilities impl_IVariablePhotoSequenceController<D>::FrameCapabilities() const
{
    Windows::Media::Devices::Core::FrameControlCapabilities value { nullptr };
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceController)->get_FrameCapabilities(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Media::Devices::Core::FrameController> impl_IVariablePhotoSequenceController<D>::DesiredFrameControllers() const
{
    Windows::Foundation::Collections::IVector<Windows::Media::Devices::Core::FrameController> items;
    check_hresult(WINRT_SHIM(IVariablePhotoSequenceController)->get_DesiredFrameControllers(put_abi(items)));
    return items;
}

template <typename D> Windows::Media::Devices::Core::CameraIntrinsics impl_ICameraIntrinsicsFactory<D>::Create(const Windows::Foundation::Numerics::float2 & focalLength, const Windows::Foundation::Numerics::float2 & principalPoint, const Windows::Foundation::Numerics::float3 & radialDistortion, const Windows::Foundation::Numerics::float2 & tangentialDistortion, uint32_t imageWidth, uint32_t imageHeight) const
{
    Windows::Media::Devices::Core::CameraIntrinsics result { nullptr };
    check_hresult(WINRT_SHIM(ICameraIntrinsicsFactory)->abi_Create(get_abi(focalLength), get_abi(principalPoint), get_abi(radialDistortion), get_abi(tangentialDistortion), imageWidth, imageHeight, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Numerics::float2 impl_ICameraIntrinsics<D>::FocalLength() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(ICameraIntrinsics)->get_FocalLength(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float2 impl_ICameraIntrinsics<D>::PrincipalPoint() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(ICameraIntrinsics)->get_PrincipalPoint(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_ICameraIntrinsics<D>::RadialDistortion() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(ICameraIntrinsics)->get_RadialDistortion(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float2 impl_ICameraIntrinsics<D>::TangentialDistortion() const
{
    Windows::Foundation::Numerics::float2 value {};
    check_hresult(WINRT_SHIM(ICameraIntrinsics)->get_TangentialDistortion(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_ICameraIntrinsics<D>::ImageWidth() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICameraIntrinsics)->get_ImageWidth(&value));
    return value;
}

template <typename D> uint32_t impl_ICameraIntrinsics<D>::ImageHeight() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICameraIntrinsics)->get_ImageHeight(&value));
    return value;
}

template <typename D> Windows::Foundation::Point impl_ICameraIntrinsics<D>::ProjectOntoFrame(const Windows::Foundation::Numerics::float3 & coordinate) const
{
    Windows::Foundation::Point result {};
    check_hresult(WINRT_SHIM(ICameraIntrinsics)->abi_ProjectOntoFrame(get_abi(coordinate), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Numerics::float2 impl_ICameraIntrinsics<D>::UnprojectAtUnitDepth(const Windows::Foundation::Point & pixelCoordinate) const
{
    Windows::Foundation::Numerics::float2 result {};
    check_hresult(WINRT_SHIM(ICameraIntrinsics)->abi_UnprojectAtUnitDepth(get_abi(pixelCoordinate), put_abi(result)));
    return result;
}

template <typename D> void impl_ICameraIntrinsics<D>::ProjectManyOntoFrame(array_view<const Windows::Foundation::Numerics::float3> coordinates, array_view<Windows::Foundation::Point> results) const
{
    check_hresult(WINRT_SHIM(ICameraIntrinsics)->abi_ProjectManyOntoFrame(coordinates.size(), get_abi(coordinates), results.size(), get_abi(results)));
}

template <typename D> void impl_ICameraIntrinsics<D>::UnprojectPixelsAtUnitDepth(array_view<const Windows::Foundation::Point> pixelCoordinates, array_view<Windows::Foundation::Numerics::float2> results) const
{
    check_hresult(WINRT_SHIM(ICameraIntrinsics)->abi_UnprojectPixelsAtUnitDepth(pixelCoordinates.size(), get_abi(pixelCoordinates), results.size(), get_abi(results)));
}

template <typename D> Windows::Foundation::Numerics::float4x4 impl_ICameraIntrinsics2<D>::UndistortedProjectionTransform() const
{
    Windows::Foundation::Numerics::float4x4 value {};
    check_hresult(WINRT_SHIM(ICameraIntrinsics2)->get_UndistortedProjectionTransform(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_ICameraIntrinsics2<D>::DistortPoint(const Windows::Foundation::Point & input) const
{
    Windows::Foundation::Point result {};
    check_hresult(WINRT_SHIM(ICameraIntrinsics2)->abi_DistortPoint(get_abi(input), put_abi(result)));
    return result;
}

template <typename D> void impl_ICameraIntrinsics2<D>::DistortPoints(array_view<const Windows::Foundation::Point> inputs, array_view<Windows::Foundation::Point> results) const
{
    check_hresult(WINRT_SHIM(ICameraIntrinsics2)->abi_DistortPoints(inputs.size(), get_abi(inputs), results.size(), get_abi(results)));
}

template <typename D> Windows::Foundation::Point impl_ICameraIntrinsics2<D>::UndistortPoint(const Windows::Foundation::Point & input) const
{
    Windows::Foundation::Point result {};
    check_hresult(WINRT_SHIM(ICameraIntrinsics2)->abi_UndistortPoint(get_abi(input), put_abi(result)));
    return result;
}

template <typename D> void impl_ICameraIntrinsics2<D>::UndistortPoints(array_view<const Windows::Foundation::Point> inputs, array_view<Windows::Foundation::Point> results) const
{
    check_hresult(WINRT_SHIM(ICameraIntrinsics2)->abi_UndistortPoints(inputs.size(), get_abi(inputs), results.size(), get_abi(results)));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IDepthCorrelatedCoordinateMapper<D>::UnprojectPoint(const Windows::Foundation::Point & sourcePoint, const Windows::Perception::Spatial::SpatialCoordinateSystem & targetCoordinateSystem) const
{
    Windows::Foundation::Numerics::float3 result {};
    check_hresult(WINRT_SHIM(IDepthCorrelatedCoordinateMapper)->abi_UnprojectPoint(get_abi(sourcePoint), get_abi(targetCoordinateSystem), put_abi(result)));
    return result;
}

template <typename D> void impl_IDepthCorrelatedCoordinateMapper<D>::UnprojectPoints(array_view<const Windows::Foundation::Point> sourcePoints, const Windows::Perception::Spatial::SpatialCoordinateSystem & targetCoordinateSystem, array_view<Windows::Foundation::Numerics::float3> results) const
{
    check_hresult(WINRT_SHIM(IDepthCorrelatedCoordinateMapper)->abi_UnprojectPoints(sourcePoints.size(), get_abi(sourcePoints), get_abi(targetCoordinateSystem), results.size(), get_abi(results)));
}

template <typename D> Windows::Foundation::Point impl_IDepthCorrelatedCoordinateMapper<D>::MapPoint(const Windows::Foundation::Point & sourcePoint, const Windows::Perception::Spatial::SpatialCoordinateSystem & targetCoordinateSystem, const Windows::Media::Devices::Core::CameraIntrinsics & targetCameraIntrinsics) const
{
    Windows::Foundation::Point result {};
    check_hresult(WINRT_SHIM(IDepthCorrelatedCoordinateMapper)->abi_MapPoint(get_abi(sourcePoint), get_abi(targetCoordinateSystem), get_abi(targetCameraIntrinsics), put_abi(result)));
    return result;
}

template <typename D> void impl_IDepthCorrelatedCoordinateMapper<D>::MapPoints(array_view<const Windows::Foundation::Point> sourcePoints, const Windows::Perception::Spatial::SpatialCoordinateSystem & targetCoordinateSystem, const Windows::Media::Devices::Core::CameraIntrinsics & targetCameraIntrinsics, array_view<Windows::Foundation::Point> results) const
{
    check_hresult(WINRT_SHIM(IDepthCorrelatedCoordinateMapper)->abi_MapPoints(sourcePoints.size(), get_abi(sourcePoints), get_abi(targetCoordinateSystem), get_abi(targetCameraIntrinsics), results.size(), get_abi(results)));
}

inline FrameController::FrameController() :
    FrameController(activate_instance<FrameController>())
{}

}

}
#pragma warning(pop)
