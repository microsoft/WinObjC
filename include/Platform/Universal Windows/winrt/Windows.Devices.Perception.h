// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Enumeration.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Media.Devices.Core.3.h"
#include "internal/Windows.Graphics.Imaging.3.h"
#include "internal/Windows.Media.3.h"
#include "internal/Windows.Devices.Perception.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics> : produce_base<D, Windows::Devices::Perception::IKnownCameraIntrinsicsPropertiesStatics>
{
    HRESULT __stdcall get_FocalLength(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocalLength());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrincipalPoint(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrincipalPoint());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RadialDistortion(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RadialDistortion());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TangentialDistortion(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TangentialDistortion());
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
struct produce<D, Windows::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics> : produce_base<D, Windows::Devices::Perception::IKnownPerceptionColorFrameSourcePropertiesStatics>
{
    HRESULT __stdcall get_Exposure(impl::abi_arg_out<hstring> value) noexcept override
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

    HRESULT __stdcall get_AutoExposureEnabled(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoExposureEnabled());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExposureCompensation(impl::abi_arg_out<hstring> value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::Devices::Perception::IKnownPerceptionDepthFrameSourcePropertiesStatics> : produce_base<D, Windows::Devices::Perception::IKnownPerceptionDepthFrameSourcePropertiesStatics>
{
    HRESULT __stdcall get_MinDepth(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinDepth());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxDepth(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxDepth());
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
struct produce<D, Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics> : produce_base<D, Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics>
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

    HRESULT __stdcall get_PhysicalDeviceIds(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhysicalDeviceIds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrameKind(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameKind());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceModelVersion(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceModelVersion());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnclosureLocation(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnclosureLocation());
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
struct produce<D, Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics2> : produce_base<D, Windows::Devices::Perception::IKnownPerceptionFrameSourcePropertiesStatics2>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
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
struct produce<D, Windows::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics> : produce_base<D, Windows::Devices::Perception::IKnownPerceptionInfraredFrameSourcePropertiesStatics>
{
    HRESULT __stdcall get_Exposure(impl::abi_arg_out<hstring> value) noexcept override
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

    HRESULT __stdcall get_AutoExposureEnabled(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoExposureEnabled());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExposureCompensation(impl::abi_arg_out<hstring> value) noexcept override
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

    HRESULT __stdcall get_ActiveIlluminationEnabled(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActiveIlluminationEnabled());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AmbientSubtractionEnabled(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AmbientSubtractionEnabled());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StructureLightPatternEnabled(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StructureLightPatternEnabled());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InterleavedIlluminationEnabled(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InterleavedIlluminationEnabled());
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
struct produce<D, Windows::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics> : produce_base<D, Windows::Devices::Perception::IKnownPerceptionVideoFrameSourcePropertiesStatics>
{
    HRESULT __stdcall get_VideoProfile(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoProfile());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedVideoProfiles(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedVideoProfiles());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AvailableVideoProfiles(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AvailableVideoProfiles());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsMirrored(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMirrored());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CameraIntrinsics(impl::abi_arg_out<hstring> value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics> : produce_base<D, Windows::Devices::Perception::IKnownPerceptionVideoProfilePropertiesStatics>
{
    HRESULT __stdcall get_BitmapPixelFormat(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapPixelFormat());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BitmapAlphaMode(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapAlphaMode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Width(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Width());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Height(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Height());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrameDuration(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameDuration());
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
struct produce<D, Windows::Devices::Perception::IPerceptionColorFrame> : produce_base<D, Windows::Devices::Perception::IPerceptionColorFrame>
{
    HRESULT __stdcall get_VideoFrame(impl::abi_arg_out<Windows::Media::IVideoFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoFrame());
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
struct produce<D, Windows::Devices::Perception::IPerceptionColorFrameArrivedEventArgs> : produce_base<D, Windows::Devices::Perception::IPerceptionColorFrameArrivedEventArgs>
{
    HRESULT __stdcall get_RelativeTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelativeTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryOpenFrame(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionColorFrame> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryOpenFrame());
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
struct produce<D, Windows::Devices::Perception::IPerceptionColorFrameReader> : produce_base<D, Windows::Devices::Perception::IPerceptionColorFrameReader>
{
    HRESULT __stdcall add_FrameArrived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameReader, Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().FrameArrived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameReader, Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs> *>(&handler)));
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

    HRESULT __stdcall get_Source(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionColorFrameSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPaused(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPaused());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsPaused(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPaused(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryReadLatestFrame(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionColorFrame> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryReadLatestFrame());
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
struct produce<D, Windows::Devices::Perception::IPerceptionColorFrameSource> : produce_base<D, Windows::Devices::Perception::IPerceptionColorFrameSource>
{
    HRESULT __stdcall add_AvailableChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AvailableChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AvailableChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AvailableChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ActiveChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ActiveChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ActiveChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActiveChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PropertiesChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PropertiesChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PropertiesChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PropertiesChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_VideoProfileChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().VideoProfileChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VideoProfileChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoProfileChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CameraIntrinsicsChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CameraIntrinsicsChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CameraIntrinsicsChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraIntrinsicsChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_DeviceKind(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceKind());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Available(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Available());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Active(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Active());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsControlled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsControlled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> value) noexcept override
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

    HRESULT __stdcall get_SupportedVideoProfiles(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedVideoProfiles());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AvailableVideoProfiles(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AvailableVideoProfiles());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoProfile(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionVideoProfile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoProfile());
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

    HRESULT __stdcall abi_AcquireControlSession(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionControlSession> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AcquireControlSession());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CanControlIndependentlyFrom(impl::abi_arg_in<hstring> targetId, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CanControlIndependentlyFrom(*reinterpret_cast<const hstring *>(&targetId)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsCorrelatedWith(impl::abi_arg_in<hstring> targetId, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsCorrelatedWith(*reinterpret_cast<const hstring *>(&targetId)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetTransformTo(impl::abi_arg_in<hstring> targetId, impl::abi_arg_out<Windows::Foundation::Numerics::float4x4> result, bool * hasResult) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *hasResult = detach_abi(this->shim().TryGetTransformTo(*reinterpret_cast<const hstring *>(&targetId), *result));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetDepthCorrelatedCameraIntrinsicsAsync(impl::abi_arg_in<Windows::Devices::Perception::IPerceptionDepthFrameSource> correlatedDepthFrameSource, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetDepthCorrelatedCameraIntrinsicsAsync(*reinterpret_cast<const Windows::Devices::Perception::PerceptionDepthFrameSource *>(&correlatedDepthFrameSource)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetDepthCorrelatedCoordinateMapperAsync(impl::abi_arg_in<hstring> targetSourceId, impl::abi_arg_in<Windows::Devices::Perception::IPerceptionDepthFrameSource> correlatedDepthFrameSource, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetDepthCorrelatedCoordinateMapperAsync(*reinterpret_cast<const hstring *>(&targetSourceId), *reinterpret_cast<const Windows::Devices::Perception::PerceptionDepthFrameSource *>(&correlatedDepthFrameSource)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetVideoProfileAsync(impl::abi_arg_in<Windows::Devices::Perception::IPerceptionControlSession> controlSession, impl::abi_arg_in<Windows::Devices::Perception::IPerceptionVideoProfile> profile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TrySetVideoProfileAsync(*reinterpret_cast<const Windows::Devices::Perception::PerceptionControlSession *>(&controlSession), *reinterpret_cast<const Windows::Devices::Perception::PerceptionVideoProfile *>(&profile)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenReader(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionColorFrameReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().OpenReader());
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
struct produce<D, Windows::Devices::Perception::IPerceptionColorFrameSource2> : produce_base<D, Windows::Devices::Perception::IPerceptionColorFrameSource2>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
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
struct produce<D, Windows::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs> : produce_base<D, Windows::Devices::Perception::IPerceptionColorFrameSourceAddedEventArgs>
{
    HRESULT __stdcall get_FrameSource(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionColorFrameSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameSource());
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
struct produce<D, Windows::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs> : produce_base<D, Windows::Devices::Perception::IPerceptionColorFrameSourceRemovedEventArgs>
{
    HRESULT __stdcall get_FrameSource(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionColorFrameSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameSource());
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
struct produce<D, Windows::Devices::Perception::IPerceptionColorFrameSourceStatics> : produce_base<D, Windows::Devices::Perception::IPerceptionColorFrameSourceStatics>
{
    HRESULT __stdcall abi_CreateWatcher(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher> watcher) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *watcher = detach_abi(this->shim().CreateWatcher());
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionColorFrameSource>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindAllAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionColorFrameSource>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus>> result) noexcept override
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

template <typename D>
struct produce<D, Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher> : produce_base<D, Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher>
{
    HRESULT __stdcall add_SourceAdded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SourceAdded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SourceAdded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceAdded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SourceRemoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SourceRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SourceRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Stopped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Stopped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Stopped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EnumerationCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EnumerationCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EnumerationCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Devices::Enumeration::DeviceWatcherStatus * value) noexcept override
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

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Perception::IPerceptionControlSession> : produce_base<D, Windows::Devices::Perception::IPerceptionControlSession>
{
    HRESULT __stdcall add_ControlLost(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionControlSession, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ControlLost(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionControlSession, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ControlLost(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ControlLost(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetPropertyAsync(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::IInspectable> value, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TrySetPropertyAsync(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value)));
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
struct produce<D, Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics> : produce_base<D, Windows::Devices::Perception::IPerceptionDepthCorrelatedCameraIntrinsics>
{
    HRESULT __stdcall abi_UnprojectPixelAtCorrelatedDepth(impl::abi_arg_in<Windows::Foundation::Point> pixelCoordinate, impl::abi_arg_in<Windows::Devices::Perception::IPerceptionDepthFrame> depthFrame, impl::abi_arg_out<Windows::Foundation::Numerics::float3> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UnprojectPixelAtCorrelatedDepth(*reinterpret_cast<const Windows::Foundation::Point *>(&pixelCoordinate), *reinterpret_cast<const Windows::Devices::Perception::PerceptionDepthFrame *>(&depthFrame)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnprojectPixelsAtCorrelatedDepth(uint32_t __sourceCoordinatesSize, impl::abi_arg_in<Windows::Foundation::Point> * sourceCoordinates, impl::abi_arg_in<Windows::Devices::Perception::IPerceptionDepthFrame> depthFrame, uint32_t __resultsSize, impl::abi_arg_out<Windows::Foundation::Numerics::float3> results) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnprojectPixelsAtCorrelatedDepth(*reinterpret_cast<const Windows::Foundation::Point *>(&sourceCoordinates), *reinterpret_cast<const Windows::Devices::Perception::PerceptionDepthFrame *>(&depthFrame), *results);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnprojectRegionPixelsAtCorrelatedDepthAsync(impl::abi_arg_in<Windows::Foundation::Rect> region, impl::abi_arg_in<Windows::Devices::Perception::IPerceptionDepthFrame> depthFrame, uint32_t __resultsSize, impl::abi_arg_out<Windows::Foundation::Numerics::float3> results, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UnprojectRegionPixelsAtCorrelatedDepthAsync(*reinterpret_cast<const Windows::Foundation::Rect *>(&region), *reinterpret_cast<const Windows::Devices::Perception::PerceptionDepthFrame *>(&depthFrame), *results));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnprojectAllPixelsAtCorrelatedDepthAsync(impl::abi_arg_in<Windows::Devices::Perception::IPerceptionDepthFrame> depthFrame, uint32_t __resultsSize, impl::abi_arg_out<Windows::Foundation::Numerics::float3> results, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UnprojectAllPixelsAtCorrelatedDepthAsync(*reinterpret_cast<const Windows::Devices::Perception::PerceptionDepthFrame *>(&depthFrame), *results));
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
struct produce<D, Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper> : produce_base<D, Windows::Devices::Perception::IPerceptionDepthCorrelatedCoordinateMapper>
{
    HRESULT __stdcall abi_MapPixelToTarget(impl::abi_arg_in<Windows::Foundation::Point> sourcePixelCoordinate, impl::abi_arg_in<Windows::Devices::Perception::IPerceptionDepthFrame> depthFrame, impl::abi_arg_out<Windows::Foundation::Point> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MapPixelToTarget(*reinterpret_cast<const Windows::Foundation::Point *>(&sourcePixelCoordinate), *reinterpret_cast<const Windows::Devices::Perception::PerceptionDepthFrame *>(&depthFrame)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MapPixelsToTarget(uint32_t __sourceCoordinatesSize, impl::abi_arg_in<Windows::Foundation::Point> * sourceCoordinates, impl::abi_arg_in<Windows::Devices::Perception::IPerceptionDepthFrame> depthFrame, uint32_t __resultsSize, impl::abi_arg_out<Windows::Foundation::Point> results) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MapPixelsToTarget(*reinterpret_cast<const Windows::Foundation::Point *>(&sourceCoordinates), *reinterpret_cast<const Windows::Devices::Perception::PerceptionDepthFrame *>(&depthFrame), *results);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MapRegionOfPixelsToTargetAsync(impl::abi_arg_in<Windows::Foundation::Rect> region, impl::abi_arg_in<Windows::Devices::Perception::IPerceptionDepthFrame> depthFrame, uint32_t __targetCoordinatesSize, impl::abi_arg_out<Windows::Foundation::Point> targetCoordinates, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MapRegionOfPixelsToTargetAsync(*reinterpret_cast<const Windows::Foundation::Rect *>(&region), *reinterpret_cast<const Windows::Devices::Perception::PerceptionDepthFrame *>(&depthFrame), *targetCoordinates));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MapAllPixelsToTargetAsync(impl::abi_arg_in<Windows::Devices::Perception::IPerceptionDepthFrame> depthFrame, uint32_t __targetCoordinatesSize, impl::abi_arg_out<Windows::Foundation::Point> targetCoordinates, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().MapAllPixelsToTargetAsync(*reinterpret_cast<const Windows::Devices::Perception::PerceptionDepthFrame *>(&depthFrame), *targetCoordinates));
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
struct produce<D, Windows::Devices::Perception::IPerceptionDepthFrame> : produce_base<D, Windows::Devices::Perception::IPerceptionDepthFrame>
{
    HRESULT __stdcall get_VideoFrame(impl::abi_arg_out<Windows::Media::IVideoFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoFrame());
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
struct produce<D, Windows::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs> : produce_base<D, Windows::Devices::Perception::IPerceptionDepthFrameArrivedEventArgs>
{
    HRESULT __stdcall get_RelativeTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelativeTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryOpenFrame(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionDepthFrame> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryOpenFrame());
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
struct produce<D, Windows::Devices::Perception::IPerceptionDepthFrameReader> : produce_base<D, Windows::Devices::Perception::IPerceptionDepthFrameReader>
{
    HRESULT __stdcall add_FrameArrived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameReader, Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().FrameArrived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameReader, Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> *>(&handler)));
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

    HRESULT __stdcall get_Source(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionDepthFrameSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPaused(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPaused());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsPaused(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPaused(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryReadLatestFrame(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionDepthFrame> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryReadLatestFrame());
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
struct produce<D, Windows::Devices::Perception::IPerceptionDepthFrameSource> : produce_base<D, Windows::Devices::Perception::IPerceptionDepthFrameSource>
{
    HRESULT __stdcall add_AvailableChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AvailableChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AvailableChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AvailableChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ActiveChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ActiveChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ActiveChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActiveChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PropertiesChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PropertiesChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PropertiesChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PropertiesChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_VideoProfileChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().VideoProfileChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VideoProfileChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoProfileChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CameraIntrinsicsChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CameraIntrinsicsChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CameraIntrinsicsChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraIntrinsicsChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_DeviceKind(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceKind());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Available(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Available());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Active(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Active());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsControlled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsControlled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> value) noexcept override
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

    HRESULT __stdcall get_SupportedVideoProfiles(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedVideoProfiles());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AvailableVideoProfiles(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AvailableVideoProfiles());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoProfile(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionVideoProfile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoProfile());
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

    HRESULT __stdcall abi_AcquireControlSession(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionControlSession> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().AcquireControlSession());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CanControlIndependentlyFrom(impl::abi_arg_in<hstring> targetId, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CanControlIndependentlyFrom(*reinterpret_cast<const hstring *>(&targetId)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsCorrelatedWith(impl::abi_arg_in<hstring> targetId, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsCorrelatedWith(*reinterpret_cast<const hstring *>(&targetId)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetTransformTo(impl::abi_arg_in<hstring> targetId, impl::abi_arg_out<Windows::Foundation::Numerics::float4x4> result, bool * hasResult) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *hasResult = detach_abi(this->shim().TryGetTransformTo(*reinterpret_cast<const hstring *>(&targetId), *result));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetDepthCorrelatedCameraIntrinsicsAsync(impl::abi_arg_in<Windows::Devices::Perception::IPerceptionDepthFrameSource> target, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetDepthCorrelatedCameraIntrinsicsAsync(*reinterpret_cast<const Windows::Devices::Perception::PerceptionDepthFrameSource *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetDepthCorrelatedCoordinateMapperAsync(impl::abi_arg_in<hstring> targetId, impl::abi_arg_in<Windows::Devices::Perception::IPerceptionDepthFrameSource> depthFrameSourceToMapWith, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetDepthCorrelatedCoordinateMapperAsync(*reinterpret_cast<const hstring *>(&targetId), *reinterpret_cast<const Windows::Devices::Perception::PerceptionDepthFrameSource *>(&depthFrameSourceToMapWith)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetVideoProfileAsync(impl::abi_arg_in<Windows::Devices::Perception::IPerceptionControlSession> controlSession, impl::abi_arg_in<Windows::Devices::Perception::IPerceptionVideoProfile> profile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TrySetVideoProfileAsync(*reinterpret_cast<const Windows::Devices::Perception::PerceptionControlSession *>(&controlSession), *reinterpret_cast<const Windows::Devices::Perception::PerceptionVideoProfile *>(&profile)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenReader(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionDepthFrameReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().OpenReader());
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
struct produce<D, Windows::Devices::Perception::IPerceptionDepthFrameSource2> : produce_base<D, Windows::Devices::Perception::IPerceptionDepthFrameSource2>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
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
struct produce<D, Windows::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs> : produce_base<D, Windows::Devices::Perception::IPerceptionDepthFrameSourceAddedEventArgs>
{
    HRESULT __stdcall get_FrameSource(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionDepthFrameSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameSource());
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
struct produce<D, Windows::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs> : produce_base<D, Windows::Devices::Perception::IPerceptionDepthFrameSourceRemovedEventArgs>
{
    HRESULT __stdcall get_FrameSource(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionDepthFrameSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameSource());
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
struct produce<D, Windows::Devices::Perception::IPerceptionDepthFrameSourceStatics> : produce_base<D, Windows::Devices::Perception::IPerceptionDepthFrameSourceStatics>
{
    HRESULT __stdcall abi_CreateWatcher(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher> watcher) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *watcher = detach_abi(this->shim().CreateWatcher());
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionDepthFrameSource>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindAllAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthFrameSource>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus>> result) noexcept override
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

template <typename D>
struct produce<D, Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher> : produce_base<D, Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher>
{
    HRESULT __stdcall add_SourceAdded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SourceAdded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SourceAdded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceAdded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SourceRemoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SourceRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SourceRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Stopped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Stopped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Stopped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EnumerationCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EnumerationCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EnumerationCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Devices::Enumeration::DeviceWatcherStatus * value) noexcept override
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

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs> : produce_base<D, Windows::Devices::Perception::IPerceptionFrameSourcePropertiesChangedEventArgs>
{
    HRESULT __stdcall get_CollectionChange(Windows::Foundation::Collections::CollectionChange * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CollectionChange());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Key(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Key());
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
struct produce<D, Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult> : produce_base<D, Windows::Devices::Perception::IPerceptionFrameSourcePropertyChangeResult>
{
    HRESULT __stdcall get_Status(Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus * value) noexcept override
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

    HRESULT __stdcall get_NewValue(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewValue());
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
struct produce<D, Windows::Devices::Perception::IPerceptionInfraredFrame> : produce_base<D, Windows::Devices::Perception::IPerceptionInfraredFrame>
{
    HRESULT __stdcall get_VideoFrame(impl::abi_arg_out<Windows::Media::IVideoFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoFrame());
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
struct produce<D, Windows::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs> : produce_base<D, Windows::Devices::Perception::IPerceptionInfraredFrameArrivedEventArgs>
{
    HRESULT __stdcall get_RelativeTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelativeTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryOpenFrame(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionInfraredFrame> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryOpenFrame());
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
struct produce<D, Windows::Devices::Perception::IPerceptionInfraredFrameReader> : produce_base<D, Windows::Devices::Perception::IPerceptionInfraredFrameReader>
{
    HRESULT __stdcall add_FrameArrived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameReader, Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().FrameArrived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameReader, Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> *>(&handler)));
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

    HRESULT __stdcall get_Source(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionInfraredFrameSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPaused(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPaused());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsPaused(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPaused(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryReadLatestFrame(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionInfraredFrame> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryReadLatestFrame());
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
struct produce<D, Windows::Devices::Perception::IPerceptionInfraredFrameSource> : produce_base<D, Windows::Devices::Perception::IPerceptionInfraredFrameSource>
{
    HRESULT __stdcall add_AvailableChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AvailableChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AvailableChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AvailableChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ActiveChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ActiveChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ActiveChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActiveChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PropertiesChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PropertiesChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PropertiesChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PropertiesChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_VideoProfileChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().VideoProfileChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VideoProfileChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoProfileChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CameraIntrinsicsChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CameraIntrinsicsChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CameraIntrinsicsChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraIntrinsicsChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_DeviceKind(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceKind());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Available(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Available());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Active(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Active());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsControlled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsControlled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> value) noexcept override
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

    HRESULT __stdcall get_SupportedVideoProfiles(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedVideoProfiles());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AvailableVideoProfiles(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AvailableVideoProfiles());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoProfile(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionVideoProfile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoProfile());
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

    HRESULT __stdcall abi_AcquireControlSession(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionControlSession> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().AcquireControlSession());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CanControlIndependentlyFrom(impl::abi_arg_in<hstring> targetId, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CanControlIndependentlyFrom(*reinterpret_cast<const hstring *>(&targetId)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsCorrelatedWith(impl::abi_arg_in<hstring> targetId, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsCorrelatedWith(*reinterpret_cast<const hstring *>(&targetId)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetTransformTo(impl::abi_arg_in<hstring> targetId, impl::abi_arg_out<Windows::Foundation::Numerics::float4x4> result, bool * hasResult) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *hasResult = detach_abi(this->shim().TryGetTransformTo(*reinterpret_cast<const hstring *>(&targetId), *result));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetDepthCorrelatedCameraIntrinsicsAsync(impl::abi_arg_in<Windows::Devices::Perception::IPerceptionDepthFrameSource> target, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetDepthCorrelatedCameraIntrinsicsAsync(*reinterpret_cast<const Windows::Devices::Perception::PerceptionDepthFrameSource *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetDepthCorrelatedCoordinateMapperAsync(impl::abi_arg_in<hstring> targetId, impl::abi_arg_in<Windows::Devices::Perception::IPerceptionDepthFrameSource> depthFrameSourceToMapWith, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryGetDepthCorrelatedCoordinateMapperAsync(*reinterpret_cast<const hstring *>(&targetId), *reinterpret_cast<const Windows::Devices::Perception::PerceptionDepthFrameSource *>(&depthFrameSourceToMapWith)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetVideoProfileAsync(impl::abi_arg_in<Windows::Devices::Perception::IPerceptionControlSession> controlSession, impl::abi_arg_in<Windows::Devices::Perception::IPerceptionVideoProfile> profile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TrySetVideoProfileAsync(*reinterpret_cast<const Windows::Devices::Perception::PerceptionControlSession *>(&controlSession), *reinterpret_cast<const Windows::Devices::Perception::PerceptionVideoProfile *>(&profile)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenReader(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionInfraredFrameReader> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().OpenReader());
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
struct produce<D, Windows::Devices::Perception::IPerceptionInfraredFrameSource2> : produce_base<D, Windows::Devices::Perception::IPerceptionInfraredFrameSource2>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
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
struct produce<D, Windows::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs> : produce_base<D, Windows::Devices::Perception::IPerceptionInfraredFrameSourceAddedEventArgs>
{
    HRESULT __stdcall get_FrameSource(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionInfraredFrameSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameSource());
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
struct produce<D, Windows::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs> : produce_base<D, Windows::Devices::Perception::IPerceptionInfraredFrameSourceRemovedEventArgs>
{
    HRESULT __stdcall get_FrameSource(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionInfraredFrameSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameSource());
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
struct produce<D, Windows::Devices::Perception::IPerceptionInfraredFrameSourceStatics> : produce_base<D, Windows::Devices::Perception::IPerceptionInfraredFrameSourceStatics>
{
    HRESULT __stdcall abi_CreateWatcher(impl::abi_arg_out<Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher> watcher) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *watcher = detach_abi(this->shim().CreateWatcher());
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionInfraredFrameSource>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindAllAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> id, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionInfraredFrameSource>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&id)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus>> result) noexcept override
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

template <typename D>
struct produce<D, Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher> : produce_base<D, Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher>
{
    HRESULT __stdcall add_SourceAdded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SourceAdded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SourceAdded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceAdded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SourceRemoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SourceRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SourceRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Stopped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Stopped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Stopped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EnumerationCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EnumerationCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EnumerationCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Devices::Enumeration::DeviceWatcherStatus * value) noexcept override
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

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Perception::IPerceptionVideoProfile> : produce_base<D, Windows::Devices::Perception::IPerceptionVideoProfile>
{
    HRESULT __stdcall get_BitmapPixelFormat(Windows::Graphics::Imaging::BitmapPixelFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapPixelFormat());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BitmapAlphaMode(Windows::Graphics::Imaging::BitmapAlphaMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapAlphaMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Width(int32_t * value) noexcept override
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

    HRESULT __stdcall get_Height(int32_t * value) noexcept override
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

    HRESULT __stdcall get_FrameDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsEqual(impl::abi_arg_in<Windows::Devices::Perception::IPerceptionVideoProfile> other, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsEqual(*reinterpret_cast<const Windows::Devices::Perception::PerceptionVideoProfile *>(&other)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Perception {

template <typename D> event_token impl_IPerceptionColorFrameSourceWatcher<D>::SourceAdded(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceWatcher)->add_SourceAdded(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionColorFrameSourceWatcher> impl_IPerceptionColorFrameSourceWatcher<D>::SourceAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceAddedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionColorFrameSourceWatcher>(this, &ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher::remove_SourceAdded, SourceAdded(handler));
}

template <typename D> void impl_IPerceptionColorFrameSourceWatcher<D>::SourceAdded(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceWatcher)->remove_SourceAdded(token));
}

template <typename D> event_token impl_IPerceptionColorFrameSourceWatcher<D>::SourceRemoved(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceWatcher)->add_SourceRemoved(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionColorFrameSourceWatcher> impl_IPerceptionColorFrameSourceWatcher<D>::SourceRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Devices::Perception::PerceptionColorFrameSourceRemovedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionColorFrameSourceWatcher>(this, &ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher::remove_SourceRemoved, SourceRemoved(handler));
}

template <typename D> void impl_IPerceptionColorFrameSourceWatcher<D>::SourceRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceWatcher)->remove_SourceRemoved(token));
}

template <typename D> event_token impl_IPerceptionColorFrameSourceWatcher<D>::Stopped(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceWatcher)->add_Stopped(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionColorFrameSourceWatcher> impl_IPerceptionColorFrameSourceWatcher<D>::Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionColorFrameSourceWatcher>(this, &ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher::remove_Stopped, Stopped(handler));
}

template <typename D> void impl_IPerceptionColorFrameSourceWatcher<D>::Stopped(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceWatcher)->remove_Stopped(token));
}

template <typename D> event_token impl_IPerceptionColorFrameSourceWatcher<D>::EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceWatcher)->add_EnumerationCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionColorFrameSourceWatcher> impl_IPerceptionColorFrameSourceWatcher<D>::EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionColorFrameSourceWatcher>(this, &ABI::Windows::Devices::Perception::IPerceptionColorFrameSourceWatcher::remove_EnumerationCompleted, EnumerationCompleted(handler));
}

template <typename D> void impl_IPerceptionColorFrameSourceWatcher<D>::EnumerationCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceWatcher)->remove_EnumerationCompleted(token));
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcherStatus impl_IPerceptionColorFrameSourceWatcher<D>::Status() const
{
    Windows::Devices::Enumeration::DeviceWatcherStatus value {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceWatcher)->get_Status(&value));
    return value;
}

template <typename D> void impl_IPerceptionColorFrameSourceWatcher<D>::Start() const
{
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceWatcher)->abi_Start());
}

template <typename D> void impl_IPerceptionColorFrameSourceWatcher<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceWatcher)->abi_Stop());
}

template <typename D> event_token impl_IPerceptionDepthFrameSourceWatcher<D>::SourceAdded(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceWatcher)->add_SourceAdded(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionDepthFrameSourceWatcher> impl_IPerceptionDepthFrameSourceWatcher<D>::SourceAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceAddedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionDepthFrameSourceWatcher>(this, &ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher::remove_SourceAdded, SourceAdded(handler));
}

template <typename D> void impl_IPerceptionDepthFrameSourceWatcher<D>::SourceAdded(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceWatcher)->remove_SourceAdded(token));
}

template <typename D> event_token impl_IPerceptionDepthFrameSourceWatcher<D>::SourceRemoved(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceWatcher)->add_SourceRemoved(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionDepthFrameSourceWatcher> impl_IPerceptionDepthFrameSourceWatcher<D>::SourceRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Devices::Perception::PerceptionDepthFrameSourceRemovedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionDepthFrameSourceWatcher>(this, &ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher::remove_SourceRemoved, SourceRemoved(handler));
}

template <typename D> void impl_IPerceptionDepthFrameSourceWatcher<D>::SourceRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceWatcher)->remove_SourceRemoved(token));
}

template <typename D> event_token impl_IPerceptionDepthFrameSourceWatcher<D>::Stopped(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceWatcher)->add_Stopped(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionDepthFrameSourceWatcher> impl_IPerceptionDepthFrameSourceWatcher<D>::Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionDepthFrameSourceWatcher>(this, &ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher::remove_Stopped, Stopped(handler));
}

template <typename D> void impl_IPerceptionDepthFrameSourceWatcher<D>::Stopped(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceWatcher)->remove_Stopped(token));
}

template <typename D> event_token impl_IPerceptionDepthFrameSourceWatcher<D>::EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceWatcher)->add_EnumerationCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionDepthFrameSourceWatcher> impl_IPerceptionDepthFrameSourceWatcher<D>::EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionDepthFrameSourceWatcher>(this, &ABI::Windows::Devices::Perception::IPerceptionDepthFrameSourceWatcher::remove_EnumerationCompleted, EnumerationCompleted(handler));
}

template <typename D> void impl_IPerceptionDepthFrameSourceWatcher<D>::EnumerationCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceWatcher)->remove_EnumerationCompleted(token));
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcherStatus impl_IPerceptionDepthFrameSourceWatcher<D>::Status() const
{
    Windows::Devices::Enumeration::DeviceWatcherStatus value {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceWatcher)->get_Status(&value));
    return value;
}

template <typename D> void impl_IPerceptionDepthFrameSourceWatcher<D>::Start() const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceWatcher)->abi_Start());
}

template <typename D> void impl_IPerceptionDepthFrameSourceWatcher<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceWatcher)->abi_Stop());
}

template <typename D> event_token impl_IPerceptionInfraredFrameSourceWatcher<D>::SourceAdded(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceWatcher)->add_SourceAdded(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionInfraredFrameSourceWatcher> impl_IPerceptionInfraredFrameSourceWatcher<D>::SourceAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceAddedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionInfraredFrameSourceWatcher>(this, &ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher::remove_SourceAdded, SourceAdded(handler));
}

template <typename D> void impl_IPerceptionInfraredFrameSourceWatcher<D>::SourceAdded(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceWatcher)->remove_SourceAdded(token));
}

template <typename D> event_token impl_IPerceptionInfraredFrameSourceWatcher<D>::SourceRemoved(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceWatcher)->add_SourceRemoved(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionInfraredFrameSourceWatcher> impl_IPerceptionInfraredFrameSourceWatcher<D>::SourceRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Devices::Perception::PerceptionInfraredFrameSourceRemovedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionInfraredFrameSourceWatcher>(this, &ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher::remove_SourceRemoved, SourceRemoved(handler));
}

template <typename D> void impl_IPerceptionInfraredFrameSourceWatcher<D>::SourceRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceWatcher)->remove_SourceRemoved(token));
}

template <typename D> event_token impl_IPerceptionInfraredFrameSourceWatcher<D>::Stopped(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceWatcher)->add_Stopped(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionInfraredFrameSourceWatcher> impl_IPerceptionInfraredFrameSourceWatcher<D>::Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionInfraredFrameSourceWatcher>(this, &ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher::remove_Stopped, Stopped(handler));
}

template <typename D> void impl_IPerceptionInfraredFrameSourceWatcher<D>::Stopped(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceWatcher)->remove_Stopped(token));
}

template <typename D> event_token impl_IPerceptionInfraredFrameSourceWatcher<D>::EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceWatcher)->add_EnumerationCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionInfraredFrameSourceWatcher> impl_IPerceptionInfraredFrameSourceWatcher<D>::EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionInfraredFrameSourceWatcher>(this, &ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSourceWatcher::remove_EnumerationCompleted, EnumerationCompleted(handler));
}

template <typename D> void impl_IPerceptionInfraredFrameSourceWatcher<D>::EnumerationCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceWatcher)->remove_EnumerationCompleted(token));
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcherStatus impl_IPerceptionInfraredFrameSourceWatcher<D>::Status() const
{
    Windows::Devices::Enumeration::DeviceWatcherStatus value {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceWatcher)->get_Status(&value));
    return value;
}

template <typename D> void impl_IPerceptionInfraredFrameSourceWatcher<D>::Start() const
{
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceWatcher)->abi_Start());
}

template <typename D> void impl_IPerceptionInfraredFrameSourceWatcher<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceWatcher)->abi_Stop());
}

template <typename D> Windows::Devices::Perception::PerceptionColorFrameSource impl_IPerceptionColorFrameSourceAddedEventArgs<D>::FrameSource() const
{
    Windows::Devices::Perception::PerceptionColorFrameSource value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceAddedEventArgs)->get_FrameSource(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionColorFrameSource impl_IPerceptionColorFrameSourceRemovedEventArgs<D>::FrameSource() const
{
    Windows::Devices::Perception::PerceptionColorFrameSource value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceRemovedEventArgs)->get_FrameSource(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionDepthFrameSource impl_IPerceptionDepthFrameSourceAddedEventArgs<D>::FrameSource() const
{
    Windows::Devices::Perception::PerceptionDepthFrameSource value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceAddedEventArgs)->get_FrameSource(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionDepthFrameSource impl_IPerceptionDepthFrameSourceRemovedEventArgs<D>::FrameSource() const
{
    Windows::Devices::Perception::PerceptionDepthFrameSource value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceRemovedEventArgs)->get_FrameSource(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionInfraredFrameSource impl_IPerceptionInfraredFrameSourceAddedEventArgs<D>::FrameSource() const
{
    Windows::Devices::Perception::PerceptionInfraredFrameSource value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceAddedEventArgs)->get_FrameSource(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionInfraredFrameSource impl_IPerceptionInfraredFrameSourceRemovedEventArgs<D>::FrameSource() const
{
    Windows::Devices::Perception::PerceptionInfraredFrameSource value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceRemovedEventArgs)->get_FrameSource(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionFrameSourcePropertiesStatics<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionFrameSourcePropertiesStatics)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionFrameSourcePropertiesStatics<D>::PhysicalDeviceIds() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionFrameSourcePropertiesStatics)->get_PhysicalDeviceIds(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionFrameSourcePropertiesStatics<D>::FrameKind() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionFrameSourcePropertiesStatics)->get_FrameKind(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionFrameSourcePropertiesStatics<D>::DeviceModelVersion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionFrameSourcePropertiesStatics)->get_DeviceModelVersion(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionFrameSourcePropertiesStatics<D>::EnclosureLocation() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionFrameSourcePropertiesStatics)->get_EnclosureLocation(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionFrameSourcePropertiesStatics2<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionFrameSourcePropertiesStatics2)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionVideoFrameSourcePropertiesStatics<D>::VideoProfile() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionVideoFrameSourcePropertiesStatics)->get_VideoProfile(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionVideoFrameSourcePropertiesStatics<D>::SupportedVideoProfiles() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionVideoFrameSourcePropertiesStatics)->get_SupportedVideoProfiles(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionVideoFrameSourcePropertiesStatics<D>::AvailableVideoProfiles() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionVideoFrameSourcePropertiesStatics)->get_AvailableVideoProfiles(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionVideoFrameSourcePropertiesStatics<D>::IsMirrored() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionVideoFrameSourcePropertiesStatics)->get_IsMirrored(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionVideoFrameSourcePropertiesStatics<D>::CameraIntrinsics() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionVideoFrameSourcePropertiesStatics)->get_CameraIntrinsics(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>::Exposure() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionInfraredFrameSourcePropertiesStatics)->get_Exposure(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>::AutoExposureEnabled() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionInfraredFrameSourcePropertiesStatics)->get_AutoExposureEnabled(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>::ExposureCompensation() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionInfraredFrameSourcePropertiesStatics)->get_ExposureCompensation(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>::ActiveIlluminationEnabled() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionInfraredFrameSourcePropertiesStatics)->get_ActiveIlluminationEnabled(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>::AmbientSubtractionEnabled() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionInfraredFrameSourcePropertiesStatics)->get_AmbientSubtractionEnabled(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>::StructureLightPatternEnabled() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionInfraredFrameSourcePropertiesStatics)->get_StructureLightPatternEnabled(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionInfraredFrameSourcePropertiesStatics<D>::InterleavedIlluminationEnabled() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionInfraredFrameSourcePropertiesStatics)->get_InterleavedIlluminationEnabled(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionDepthFrameSourcePropertiesStatics<D>::MinDepth() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionDepthFrameSourcePropertiesStatics)->get_MinDepth(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionDepthFrameSourcePropertiesStatics<D>::MaxDepth() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionDepthFrameSourcePropertiesStatics)->get_MaxDepth(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionColorFrameSourcePropertiesStatics<D>::Exposure() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionColorFrameSourcePropertiesStatics)->get_Exposure(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionColorFrameSourcePropertiesStatics<D>::AutoExposureEnabled() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionColorFrameSourcePropertiesStatics)->get_AutoExposureEnabled(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionColorFrameSourcePropertiesStatics<D>::ExposureCompensation() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionColorFrameSourcePropertiesStatics)->get_ExposureCompensation(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionVideoProfilePropertiesStatics<D>::BitmapPixelFormat() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionVideoProfilePropertiesStatics)->get_BitmapPixelFormat(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionVideoProfilePropertiesStatics<D>::BitmapAlphaMode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionVideoProfilePropertiesStatics)->get_BitmapAlphaMode(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionVideoProfilePropertiesStatics<D>::Width() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionVideoProfilePropertiesStatics)->get_Width(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionVideoProfilePropertiesStatics<D>::Height() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionVideoProfilePropertiesStatics)->get_Height(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownPerceptionVideoProfilePropertiesStatics<D>::FrameDuration() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownPerceptionVideoProfilePropertiesStatics)->get_FrameDuration(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownCameraIntrinsicsPropertiesStatics<D>::FocalLength() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownCameraIntrinsicsPropertiesStatics)->get_FocalLength(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownCameraIntrinsicsPropertiesStatics<D>::PrincipalPoint() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownCameraIntrinsicsPropertiesStatics)->get_PrincipalPoint(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownCameraIntrinsicsPropertiesStatics<D>::RadialDistortion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownCameraIntrinsicsPropertiesStatics)->get_RadialDistortion(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownCameraIntrinsicsPropertiesStatics<D>::TangentialDistortion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownCameraIntrinsicsPropertiesStatics)->get_TangentialDistortion(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus impl_IPerceptionFrameSourcePropertyChangeResult<D>::Status() const
{
    Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus value {};
    check_hresult(WINRT_SHIM(IPerceptionFrameSourcePropertyChangeResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IPerceptionFrameSourcePropertyChangeResult<D>::NewValue() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IPerceptionFrameSourcePropertyChangeResult)->get_NewValue(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::CollectionChange impl_IPerceptionFrameSourcePropertiesChangedEventArgs<D>::CollectionChange() const
{
    Windows::Foundation::Collections::CollectionChange value {};
    check_hresult(WINRT_SHIM(IPerceptionFrameSourcePropertiesChangedEventArgs)->get_CollectionChange(&value));
    return value;
}

template <typename D> hstring impl_IPerceptionFrameSourcePropertiesChangedEventArgs<D>::Key() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionFrameSourcePropertiesChangedEventArgs)->get_Key(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher impl_IPerceptionInfraredFrameSourceStatics<D>::CreateWatcher() const
{
    Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher watcher { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceStatics)->abi_CreateWatcher(put_abi(watcher)));
    return watcher;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionInfraredFrameSource>> impl_IPerceptionInfraredFrameSourceStatics<D>::FindAllAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionInfraredFrameSource>> result;
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceStatics)->abi_FindAllAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionInfraredFrameSource> impl_IPerceptionInfraredFrameSourceStatics<D>::FromIdAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionInfraredFrameSource> result;
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceStatics)->abi_FromIdAsync(get_abi(id), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> impl_IPerceptionInfraredFrameSourceStatics<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> result;
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSourceStatics)->abi_RequestAccessAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher impl_IPerceptionDepthFrameSourceStatics<D>::CreateWatcher() const
{
    Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher watcher { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceStatics)->abi_CreateWatcher(put_abi(watcher)));
    return watcher;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionDepthFrameSource>> impl_IPerceptionDepthFrameSourceStatics<D>::FindAllAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionDepthFrameSource>> result;
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceStatics)->abi_FindAllAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthFrameSource> impl_IPerceptionDepthFrameSourceStatics<D>::FromIdAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthFrameSource> result;
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceStatics)->abi_FromIdAsync(get_abi(id), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> impl_IPerceptionDepthFrameSourceStatics<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> result;
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSourceStatics)->abi_RequestAccessAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Perception::PerceptionColorFrameSourceWatcher impl_IPerceptionColorFrameSourceStatics<D>::CreateWatcher() const
{
    Windows::Devices::Perception::PerceptionColorFrameSourceWatcher watcher { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceStatics)->abi_CreateWatcher(put_abi(watcher)));
    return watcher;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionColorFrameSource>> impl_IPerceptionColorFrameSourceStatics<D>::FindAllAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionColorFrameSource>> result;
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceStatics)->abi_FindAllAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionColorFrameSource> impl_IPerceptionColorFrameSourceStatics<D>::FromIdAsync(hstring_view id) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionColorFrameSource> result;
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceStatics)->abi_FromIdAsync(get_abi(id), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> impl_IPerceptionColorFrameSourceStatics<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> result;
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSourceStatics)->abi_RequestAccessAsync(put_abi(result)));
    return result;
}

template <typename D> event_token impl_IPerceptionColorFrameSource<D>::AvailableChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->add_AvailableChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionColorFrameSource> impl_IPerceptionColorFrameSource<D>::AvailableChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionColorFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionColorFrameSource::remove_AvailableChanged, AvailableChanged(handler));
}

template <typename D> void impl_IPerceptionColorFrameSource<D>::AvailableChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->remove_AvailableChanged(token));
}

template <typename D> event_token impl_IPerceptionColorFrameSource<D>::ActiveChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->add_ActiveChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionColorFrameSource> impl_IPerceptionColorFrameSource<D>::ActiveChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionColorFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionColorFrameSource::remove_ActiveChanged, ActiveChanged(handler));
}

template <typename D> void impl_IPerceptionColorFrameSource<D>::ActiveChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->remove_ActiveChanged(token));
}

template <typename D> event_token impl_IPerceptionColorFrameSource<D>::PropertiesChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->add_PropertiesChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionColorFrameSource> impl_IPerceptionColorFrameSource<D>::PropertiesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionColorFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionColorFrameSource::remove_PropertiesChanged, PropertiesChanged(handler));
}

template <typename D> void impl_IPerceptionColorFrameSource<D>::PropertiesChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->remove_PropertiesChanged(token));
}

template <typename D> event_token impl_IPerceptionColorFrameSource<D>::VideoProfileChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->add_VideoProfileChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionColorFrameSource> impl_IPerceptionColorFrameSource<D>::VideoProfileChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionColorFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionColorFrameSource::remove_VideoProfileChanged, VideoProfileChanged(handler));
}

template <typename D> void impl_IPerceptionColorFrameSource<D>::VideoProfileChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->remove_VideoProfileChanged(token));
}

template <typename D> event_token impl_IPerceptionColorFrameSource<D>::CameraIntrinsicsChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->add_CameraIntrinsicsChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionColorFrameSource> impl_IPerceptionColorFrameSource<D>::CameraIntrinsicsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionColorFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionColorFrameSource::remove_CameraIntrinsicsChanged, CameraIntrinsicsChanged(handler));
}

template <typename D> void impl_IPerceptionColorFrameSource<D>::CameraIntrinsicsChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->remove_CameraIntrinsicsChanged(token));
}

template <typename D> hstring impl_IPerceptionColorFrameSource<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPerceptionColorFrameSource<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPerceptionColorFrameSource<D>::DeviceKind() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->get_DeviceKind(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPerceptionColorFrameSource<D>::Available() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->get_Available(&value));
    return value;
}

template <typename D> bool impl_IPerceptionColorFrameSource<D>::Active() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->get_Active(&value));
    return value;
}

template <typename D> bool impl_IPerceptionColorFrameSource<D>::IsControlled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->get_IsControlled(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IPerceptionColorFrameSource<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> impl_IPerceptionColorFrameSource<D>::SupportedVideoProfiles() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> value;
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->get_SupportedVideoProfiles(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> impl_IPerceptionColorFrameSource<D>::AvailableVideoProfiles() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> value;
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->get_AvailableVideoProfiles(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionVideoProfile impl_IPerceptionColorFrameSource<D>::VideoProfile() const
{
    Windows::Devices::Perception::PerceptionVideoProfile value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->get_VideoProfile(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::Core::CameraIntrinsics impl_IPerceptionColorFrameSource<D>::CameraIntrinsics() const
{
    Windows::Media::Devices::Core::CameraIntrinsics value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->get_CameraIntrinsics(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionControlSession impl_IPerceptionColorFrameSource<D>::AcquireControlSession() const
{
    Windows::Devices::Perception::PerceptionControlSession value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->abi_AcquireControlSession(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPerceptionColorFrameSource<D>::CanControlIndependentlyFrom(hstring_view targetId) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->abi_CanControlIndependentlyFrom(get_abi(targetId), &result));
    return result;
}

template <typename D> bool impl_IPerceptionColorFrameSource<D>::IsCorrelatedWith(hstring_view targetId) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->abi_IsCorrelatedWith(get_abi(targetId), &result));
    return result;
}

template <typename D> bool impl_IPerceptionColorFrameSource<D>::TryGetTransformTo(hstring_view targetId, Windows::Foundation::Numerics::float4x4 & result) const
{
    bool hasResult {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->abi_TryGetTransformTo(get_abi(targetId), put_abi(result), &hasResult));
    return hasResult;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> impl_IPerceptionColorFrameSource<D>::TryGetDepthCorrelatedCameraIntrinsicsAsync(const Windows::Devices::Perception::PerceptionDepthFrameSource & correlatedDepthFrameSource) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> result;
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->abi_TryGetDepthCorrelatedCameraIntrinsicsAsync(get_abi(correlatedDepthFrameSource), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> impl_IPerceptionColorFrameSource<D>::TryGetDepthCorrelatedCoordinateMapperAsync(hstring_view targetSourceId, const Windows::Devices::Perception::PerceptionDepthFrameSource & correlatedDepthFrameSource) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> result;
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->abi_TryGetDepthCorrelatedCoordinateMapperAsync(get_abi(targetSourceId), get_abi(correlatedDepthFrameSource), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> impl_IPerceptionColorFrameSource<D>::TrySetVideoProfileAsync(const Windows::Devices::Perception::PerceptionControlSession & controlSession, const Windows::Devices::Perception::PerceptionVideoProfile & profile) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> result;
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->abi_TrySetVideoProfileAsync(get_abi(controlSession), get_abi(profile), put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Perception::PerceptionColorFrameReader impl_IPerceptionColorFrameSource<D>::OpenReader() const
{
    Windows::Devices::Perception::PerceptionColorFrameReader result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource)->abi_OpenReader(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IPerceptionColorFrameSource2<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionColorFrameSource2)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IPerceptionDepthFrameSource<D>::AvailableChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->add_AvailableChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionDepthFrameSource> impl_IPerceptionDepthFrameSource<D>::AvailableChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionDepthFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource::remove_AvailableChanged, AvailableChanged(handler));
}

template <typename D> void impl_IPerceptionDepthFrameSource<D>::AvailableChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->remove_AvailableChanged(token));
}

template <typename D> event_token impl_IPerceptionDepthFrameSource<D>::ActiveChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->add_ActiveChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionDepthFrameSource> impl_IPerceptionDepthFrameSource<D>::ActiveChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionDepthFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource::remove_ActiveChanged, ActiveChanged(handler));
}

template <typename D> void impl_IPerceptionDepthFrameSource<D>::ActiveChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->remove_ActiveChanged(token));
}

template <typename D> event_token impl_IPerceptionDepthFrameSource<D>::PropertiesChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->add_PropertiesChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionDepthFrameSource> impl_IPerceptionDepthFrameSource<D>::PropertiesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionDepthFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource::remove_PropertiesChanged, PropertiesChanged(handler));
}

template <typename D> void impl_IPerceptionDepthFrameSource<D>::PropertiesChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->remove_PropertiesChanged(token));
}

template <typename D> event_token impl_IPerceptionDepthFrameSource<D>::VideoProfileChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->add_VideoProfileChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionDepthFrameSource> impl_IPerceptionDepthFrameSource<D>::VideoProfileChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionDepthFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource::remove_VideoProfileChanged, VideoProfileChanged(handler));
}

template <typename D> void impl_IPerceptionDepthFrameSource<D>::VideoProfileChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->remove_VideoProfileChanged(token));
}

template <typename D> event_token impl_IPerceptionDepthFrameSource<D>::CameraIntrinsicsChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->add_CameraIntrinsicsChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionDepthFrameSource> impl_IPerceptionDepthFrameSource<D>::CameraIntrinsicsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionDepthFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionDepthFrameSource::remove_CameraIntrinsicsChanged, CameraIntrinsicsChanged(handler));
}

template <typename D> void impl_IPerceptionDepthFrameSource<D>::CameraIntrinsicsChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->remove_CameraIntrinsicsChanged(token));
}

template <typename D> hstring impl_IPerceptionDepthFrameSource<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPerceptionDepthFrameSource<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPerceptionDepthFrameSource<D>::DeviceKind() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->get_DeviceKind(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPerceptionDepthFrameSource<D>::Available() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->get_Available(&value));
    return value;
}

template <typename D> bool impl_IPerceptionDepthFrameSource<D>::Active() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->get_Active(&value));
    return value;
}

template <typename D> bool impl_IPerceptionDepthFrameSource<D>::IsControlled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->get_IsControlled(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IPerceptionDepthFrameSource<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> impl_IPerceptionDepthFrameSource<D>::SupportedVideoProfiles() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> value;
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->get_SupportedVideoProfiles(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> impl_IPerceptionDepthFrameSource<D>::AvailableVideoProfiles() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> value;
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->get_AvailableVideoProfiles(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionVideoProfile impl_IPerceptionDepthFrameSource<D>::VideoProfile() const
{
    Windows::Devices::Perception::PerceptionVideoProfile value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->get_VideoProfile(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::Core::CameraIntrinsics impl_IPerceptionDepthFrameSource<D>::CameraIntrinsics() const
{
    Windows::Media::Devices::Core::CameraIntrinsics value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->get_CameraIntrinsics(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionControlSession impl_IPerceptionDepthFrameSource<D>::AcquireControlSession() const
{
    Windows::Devices::Perception::PerceptionControlSession result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->abi_AcquireControlSession(put_abi(result)));
    return result;
}

template <typename D> bool impl_IPerceptionDepthFrameSource<D>::CanControlIndependentlyFrom(hstring_view targetId) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->abi_CanControlIndependentlyFrom(get_abi(targetId), &result));
    return result;
}

template <typename D> bool impl_IPerceptionDepthFrameSource<D>::IsCorrelatedWith(hstring_view targetId) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->abi_IsCorrelatedWith(get_abi(targetId), &result));
    return result;
}

template <typename D> bool impl_IPerceptionDepthFrameSource<D>::TryGetTransformTo(hstring_view targetId, Windows::Foundation::Numerics::float4x4 & result) const
{
    bool hasResult {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->abi_TryGetTransformTo(get_abi(targetId), put_abi(result), &hasResult));
    return hasResult;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> impl_IPerceptionDepthFrameSource<D>::TryGetDepthCorrelatedCameraIntrinsicsAsync(const Windows::Devices::Perception::PerceptionDepthFrameSource & target) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> result;
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->abi_TryGetDepthCorrelatedCameraIntrinsicsAsync(get_abi(target), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> impl_IPerceptionDepthFrameSource<D>::TryGetDepthCorrelatedCoordinateMapperAsync(hstring_view targetId, const Windows::Devices::Perception::PerceptionDepthFrameSource & depthFrameSourceToMapWith) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> result;
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->abi_TryGetDepthCorrelatedCoordinateMapperAsync(get_abi(targetId), get_abi(depthFrameSourceToMapWith), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> impl_IPerceptionDepthFrameSource<D>::TrySetVideoProfileAsync(const Windows::Devices::Perception::PerceptionControlSession & controlSession, const Windows::Devices::Perception::PerceptionVideoProfile & profile) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> result;
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->abi_TrySetVideoProfileAsync(get_abi(controlSession), get_abi(profile), put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Perception::PerceptionDepthFrameReader impl_IPerceptionDepthFrameSource<D>::OpenReader() const
{
    Windows::Devices::Perception::PerceptionDepthFrameReader result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource)->abi_OpenReader(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IPerceptionDepthFrameSource2<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameSource2)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IPerceptionInfraredFrameSource<D>::AvailableChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->add_AvailableChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionInfraredFrameSource> impl_IPerceptionInfraredFrameSource<D>::AvailableChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionInfraredFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource::remove_AvailableChanged, AvailableChanged(handler));
}

template <typename D> void impl_IPerceptionInfraredFrameSource<D>::AvailableChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->remove_AvailableChanged(token));
}

template <typename D> event_token impl_IPerceptionInfraredFrameSource<D>::ActiveChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->add_ActiveChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionInfraredFrameSource> impl_IPerceptionInfraredFrameSource<D>::ActiveChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionInfraredFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource::remove_ActiveChanged, ActiveChanged(handler));
}

template <typename D> void impl_IPerceptionInfraredFrameSource<D>::ActiveChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->remove_ActiveChanged(token));
}

template <typename D> event_token impl_IPerceptionInfraredFrameSource<D>::PropertiesChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->add_PropertiesChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionInfraredFrameSource> impl_IPerceptionInfraredFrameSource<D>::PropertiesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Devices::Perception::PerceptionFrameSourcePropertiesChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionInfraredFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource::remove_PropertiesChanged, PropertiesChanged(handler));
}

template <typename D> void impl_IPerceptionInfraredFrameSource<D>::PropertiesChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->remove_PropertiesChanged(token));
}

template <typename D> event_token impl_IPerceptionInfraredFrameSource<D>::VideoProfileChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->add_VideoProfileChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionInfraredFrameSource> impl_IPerceptionInfraredFrameSource<D>::VideoProfileChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionInfraredFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource::remove_VideoProfileChanged, VideoProfileChanged(handler));
}

template <typename D> void impl_IPerceptionInfraredFrameSource<D>::VideoProfileChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->remove_VideoProfileChanged(token));
}

template <typename D> event_token impl_IPerceptionInfraredFrameSource<D>::CameraIntrinsicsChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->add_CameraIntrinsicsChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionInfraredFrameSource> impl_IPerceptionInfraredFrameSource<D>::CameraIntrinsicsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionInfraredFrameSource>(this, &ABI::Windows::Devices::Perception::IPerceptionInfraredFrameSource::remove_CameraIntrinsicsChanged, CameraIntrinsicsChanged(handler));
}

template <typename D> void impl_IPerceptionInfraredFrameSource<D>::CameraIntrinsicsChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->remove_CameraIntrinsicsChanged(token));
}

template <typename D> hstring impl_IPerceptionInfraredFrameSource<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPerceptionInfraredFrameSource<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPerceptionInfraredFrameSource<D>::DeviceKind() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->get_DeviceKind(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPerceptionInfraredFrameSource<D>::Available() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->get_Available(&value));
    return value;
}

template <typename D> bool impl_IPerceptionInfraredFrameSource<D>::Active() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->get_Active(&value));
    return value;
}

template <typename D> bool impl_IPerceptionInfraredFrameSource<D>::IsControlled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->get_IsControlled(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IPerceptionInfraredFrameSource<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> impl_IPerceptionInfraredFrameSource<D>::SupportedVideoProfiles() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> value;
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->get_SupportedVideoProfiles(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> impl_IPerceptionInfraredFrameSource<D>::AvailableVideoProfiles() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionVideoProfile> value;
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->get_AvailableVideoProfiles(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionVideoProfile impl_IPerceptionInfraredFrameSource<D>::VideoProfile() const
{
    Windows::Devices::Perception::PerceptionVideoProfile value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->get_VideoProfile(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Devices::Core::CameraIntrinsics impl_IPerceptionInfraredFrameSource<D>::CameraIntrinsics() const
{
    Windows::Media::Devices::Core::CameraIntrinsics value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->get_CameraIntrinsics(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionControlSession impl_IPerceptionInfraredFrameSource<D>::AcquireControlSession() const
{
    Windows::Devices::Perception::PerceptionControlSession result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->abi_AcquireControlSession(put_abi(result)));
    return result;
}

template <typename D> bool impl_IPerceptionInfraredFrameSource<D>::CanControlIndependentlyFrom(hstring_view targetId) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->abi_CanControlIndependentlyFrom(get_abi(targetId), &result));
    return result;
}

template <typename D> bool impl_IPerceptionInfraredFrameSource<D>::IsCorrelatedWith(hstring_view targetId) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->abi_IsCorrelatedWith(get_abi(targetId), &result));
    return result;
}

template <typename D> bool impl_IPerceptionInfraredFrameSource<D>::TryGetTransformTo(hstring_view targetId, Windows::Foundation::Numerics::float4x4 & result) const
{
    bool hasResult {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->abi_TryGetTransformTo(get_abi(targetId), put_abi(result), &hasResult));
    return hasResult;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> impl_IPerceptionInfraredFrameSource<D>::TryGetDepthCorrelatedCameraIntrinsicsAsync(const Windows::Devices::Perception::PerceptionDepthFrameSource & target) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCameraIntrinsics> result;
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->abi_TryGetDepthCorrelatedCameraIntrinsicsAsync(get_abi(target), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> impl_IPerceptionInfraredFrameSource<D>::TryGetDepthCorrelatedCoordinateMapperAsync(hstring_view targetId, const Windows::Devices::Perception::PerceptionDepthFrameSource & depthFrameSourceToMapWith) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthCorrelatedCoordinateMapper> result;
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->abi_TryGetDepthCorrelatedCoordinateMapperAsync(get_abi(targetId), get_abi(depthFrameSourceToMapWith), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> impl_IPerceptionInfraredFrameSource<D>::TrySetVideoProfileAsync(const Windows::Devices::Perception::PerceptionControlSession & controlSession, const Windows::Devices::Perception::PerceptionVideoProfile & profile) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> result;
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->abi_TrySetVideoProfileAsync(get_abi(controlSession), get_abi(profile), put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Perception::PerceptionInfraredFrameReader impl_IPerceptionInfraredFrameSource<D>::OpenReader() const
{
    Windows::Devices::Perception::PerceptionInfraredFrameReader result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource)->abi_OpenReader(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IPerceptionInfraredFrameSource2<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameSource2)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Imaging::BitmapPixelFormat impl_IPerceptionVideoProfile<D>::BitmapPixelFormat() const
{
    Windows::Graphics::Imaging::BitmapPixelFormat value {};
    check_hresult(WINRT_SHIM(IPerceptionVideoProfile)->get_BitmapPixelFormat(&value));
    return value;
}

template <typename D> Windows::Graphics::Imaging::BitmapAlphaMode impl_IPerceptionVideoProfile<D>::BitmapAlphaMode() const
{
    Windows::Graphics::Imaging::BitmapAlphaMode value {};
    check_hresult(WINRT_SHIM(IPerceptionVideoProfile)->get_BitmapAlphaMode(&value));
    return value;
}

template <typename D> int32_t impl_IPerceptionVideoProfile<D>::Width() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IPerceptionVideoProfile)->get_Width(&value));
    return value;
}

template <typename D> int32_t impl_IPerceptionVideoProfile<D>::Height() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IPerceptionVideoProfile)->get_Height(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IPerceptionVideoProfile<D>::FrameDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IPerceptionVideoProfile)->get_FrameDuration(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPerceptionVideoProfile<D>::IsEqual(const Windows::Devices::Perception::PerceptionVideoProfile & other) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IPerceptionVideoProfile)->abi_IsEqual(get_abi(other), &result));
    return result;
}

template <typename D> Windows::Foundation::TimeSpan impl_IPerceptionColorFrameArrivedEventArgs<D>::RelativeTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameArrivedEventArgs)->get_RelativeTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionColorFrame impl_IPerceptionColorFrameArrivedEventArgs<D>::TryOpenFrame() const
{
    Windows::Devices::Perception::PerceptionColorFrame result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionColorFrameArrivedEventArgs)->abi_TryOpenFrame(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::TimeSpan impl_IPerceptionDepthFrameArrivedEventArgs<D>::RelativeTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameArrivedEventArgs)->get_RelativeTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionDepthFrame impl_IPerceptionDepthFrameArrivedEventArgs<D>::TryOpenFrame() const
{
    Windows::Devices::Perception::PerceptionDepthFrame result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameArrivedEventArgs)->abi_TryOpenFrame(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::TimeSpan impl_IPerceptionInfraredFrameArrivedEventArgs<D>::RelativeTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameArrivedEventArgs)->get_RelativeTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Perception::PerceptionInfraredFrame impl_IPerceptionInfraredFrameArrivedEventArgs<D>::TryOpenFrame() const
{
    Windows::Devices::Perception::PerceptionInfraredFrame result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameArrivedEventArgs)->abi_TryOpenFrame(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IPerceptionDepthCorrelatedCameraIntrinsics<D>::UnprojectPixelAtCorrelatedDepth(const Windows::Foundation::Point & pixelCoordinate, const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame) const
{
    Windows::Foundation::Numerics::float3 result {};
    check_hresult(WINRT_SHIM(IPerceptionDepthCorrelatedCameraIntrinsics)->abi_UnprojectPixelAtCorrelatedDepth(get_abi(pixelCoordinate), get_abi(depthFrame), put_abi(result)));
    return result;
}

template <typename D> void impl_IPerceptionDepthCorrelatedCameraIntrinsics<D>::UnprojectPixelsAtCorrelatedDepth(array_view<const Windows::Foundation::Point> sourceCoordinates, const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame, array_view<Windows::Foundation::Numerics::float3> results) const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthCorrelatedCameraIntrinsics)->abi_UnprojectPixelsAtCorrelatedDepth(sourceCoordinates.size(), get_abi(sourceCoordinates), get_abi(depthFrame), results.size(), get_abi(results)));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPerceptionDepthCorrelatedCameraIntrinsics<D>::UnprojectRegionPixelsAtCorrelatedDepthAsync(const Windows::Foundation::Rect & region, const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame, array_view<Windows::Foundation::Numerics::float3> results) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPerceptionDepthCorrelatedCameraIntrinsics)->abi_UnprojectRegionPixelsAtCorrelatedDepthAsync(get_abi(region), get_abi(depthFrame), results.size(), get_abi(results), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPerceptionDepthCorrelatedCameraIntrinsics<D>::UnprojectAllPixelsAtCorrelatedDepthAsync(const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame, array_view<Windows::Foundation::Numerics::float3> results) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPerceptionDepthCorrelatedCameraIntrinsics)->abi_UnprojectAllPixelsAtCorrelatedDepthAsync(get_abi(depthFrame), results.size(), get_abi(results), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Point impl_IPerceptionDepthCorrelatedCoordinateMapper<D>::MapPixelToTarget(const Windows::Foundation::Point & sourcePixelCoordinate, const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame) const
{
    Windows::Foundation::Point result {};
    check_hresult(WINRT_SHIM(IPerceptionDepthCorrelatedCoordinateMapper)->abi_MapPixelToTarget(get_abi(sourcePixelCoordinate), get_abi(depthFrame), put_abi(result)));
    return result;
}

template <typename D> void impl_IPerceptionDepthCorrelatedCoordinateMapper<D>::MapPixelsToTarget(array_view<const Windows::Foundation::Point> sourceCoordinates, const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame, array_view<Windows::Foundation::Point> results) const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthCorrelatedCoordinateMapper)->abi_MapPixelsToTarget(sourceCoordinates.size(), get_abi(sourceCoordinates), get_abi(depthFrame), results.size(), get_abi(results)));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPerceptionDepthCorrelatedCoordinateMapper<D>::MapRegionOfPixelsToTargetAsync(const Windows::Foundation::Rect & region, const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame, array_view<Windows::Foundation::Point> targetCoordinates) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPerceptionDepthCorrelatedCoordinateMapper)->abi_MapRegionOfPixelsToTargetAsync(get_abi(region), get_abi(depthFrame), targetCoordinates.size(), get_abi(targetCoordinates), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPerceptionDepthCorrelatedCoordinateMapper<D>::MapAllPixelsToTargetAsync(const Windows::Devices::Perception::PerceptionDepthFrame & depthFrame, array_view<Windows::Foundation::Point> targetCoordinates) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IPerceptionDepthCorrelatedCoordinateMapper)->abi_MapAllPixelsToTargetAsync(get_abi(depthFrame), targetCoordinates.size(), get_abi(targetCoordinates), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IPerceptionControlSession<D>::ControlLost(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionControlSession, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionControlSession)->add_ControlLost(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionControlSession> impl_IPerceptionControlSession<D>::ControlLost(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionControlSession, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionControlSession>(this, &ABI::Windows::Devices::Perception::IPerceptionControlSession::remove_ControlLost, ControlLost(handler));
}

template <typename D> void impl_IPerceptionControlSession<D>::ControlLost(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionControlSession)->remove_ControlLost(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> impl_IPerceptionControlSession<D>::TrySetPropertyAsync(hstring_view name, const Windows::Foundation::IInspectable & value) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeResult> result;
    check_hresult(WINRT_SHIM(IPerceptionControlSession)->abi_TrySetPropertyAsync(get_abi(name), get_abi(value), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IPerceptionColorFrameReader<D>::FrameArrived(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameReader, Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameReader)->add_FrameArrived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionColorFrameReader> impl_IPerceptionColorFrameReader<D>::FrameArrived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionColorFrameReader, Windows::Devices::Perception::PerceptionColorFrameArrivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionColorFrameReader>(this, &ABI::Windows::Devices::Perception::IPerceptionColorFrameReader::remove_FrameArrived, FrameArrived(handler));
}

template <typename D> void impl_IPerceptionColorFrameReader<D>::FrameArrived(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionColorFrameReader)->remove_FrameArrived(token));
}

template <typename D> Windows::Devices::Perception::PerceptionColorFrameSource impl_IPerceptionColorFrameReader<D>::Source() const
{
    Windows::Devices::Perception::PerceptionColorFrameSource value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionColorFrameReader)->get_Source(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPerceptionColorFrameReader<D>::IsPaused() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPerceptionColorFrameReader)->get_IsPaused(&value));
    return value;
}

template <typename D> void impl_IPerceptionColorFrameReader<D>::IsPaused(bool value) const
{
    check_hresult(WINRT_SHIM(IPerceptionColorFrameReader)->put_IsPaused(value));
}

template <typename D> Windows::Devices::Perception::PerceptionColorFrame impl_IPerceptionColorFrameReader<D>::TryReadLatestFrame() const
{
    Windows::Devices::Perception::PerceptionColorFrame result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionColorFrameReader)->abi_TryReadLatestFrame(put_abi(result)));
    return result;
}

template <typename D> event_token impl_IPerceptionDepthFrameReader<D>::FrameArrived(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameReader, Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameReader)->add_FrameArrived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionDepthFrameReader> impl_IPerceptionDepthFrameReader<D>::FrameArrived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionDepthFrameReader, Windows::Devices::Perception::PerceptionDepthFrameArrivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionDepthFrameReader>(this, &ABI::Windows::Devices::Perception::IPerceptionDepthFrameReader::remove_FrameArrived, FrameArrived(handler));
}

template <typename D> void impl_IPerceptionDepthFrameReader<D>::FrameArrived(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameReader)->remove_FrameArrived(token));
}

template <typename D> Windows::Devices::Perception::PerceptionDepthFrameSource impl_IPerceptionDepthFrameReader<D>::Source() const
{
    Windows::Devices::Perception::PerceptionDepthFrameSource value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameReader)->get_Source(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPerceptionDepthFrameReader<D>::IsPaused() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameReader)->get_IsPaused(&value));
    return value;
}

template <typename D> void impl_IPerceptionDepthFrameReader<D>::IsPaused(bool value) const
{
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameReader)->put_IsPaused(value));
}

template <typename D> Windows::Devices::Perception::PerceptionDepthFrame impl_IPerceptionDepthFrameReader<D>::TryReadLatestFrame() const
{
    Windows::Devices::Perception::PerceptionDepthFrame result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionDepthFrameReader)->abi_TryReadLatestFrame(put_abi(result)));
    return result;
}

template <typename D> event_token impl_IPerceptionInfraredFrameReader<D>::FrameArrived(const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameReader, Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameReader)->add_FrameArrived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPerceptionInfraredFrameReader> impl_IPerceptionInfraredFrameReader<D>::FrameArrived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Perception::PerceptionInfraredFrameReader, Windows::Devices::Perception::PerceptionInfraredFrameArrivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPerceptionInfraredFrameReader>(this, &ABI::Windows::Devices::Perception::IPerceptionInfraredFrameReader::remove_FrameArrived, FrameArrived(handler));
}

template <typename D> void impl_IPerceptionInfraredFrameReader<D>::FrameArrived(event_token token) const
{
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameReader)->remove_FrameArrived(token));
}

template <typename D> Windows::Devices::Perception::PerceptionInfraredFrameSource impl_IPerceptionInfraredFrameReader<D>::Source() const
{
    Windows::Devices::Perception::PerceptionInfraredFrameSource value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameReader)->get_Source(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPerceptionInfraredFrameReader<D>::IsPaused() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameReader)->get_IsPaused(&value));
    return value;
}

template <typename D> void impl_IPerceptionInfraredFrameReader<D>::IsPaused(bool value) const
{
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameReader)->put_IsPaused(value));
}

template <typename D> Windows::Devices::Perception::PerceptionInfraredFrame impl_IPerceptionInfraredFrameReader<D>::TryReadLatestFrame() const
{
    Windows::Devices::Perception::PerceptionInfraredFrame result { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrameReader)->abi_TryReadLatestFrame(put_abi(result)));
    return result;
}

template <typename D> Windows::Media::VideoFrame impl_IPerceptionColorFrame<D>::VideoFrame() const
{
    Windows::Media::VideoFrame value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionColorFrame)->get_VideoFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::VideoFrame impl_IPerceptionDepthFrame<D>::VideoFrame() const
{
    Windows::Media::VideoFrame value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionDepthFrame)->get_VideoFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::VideoFrame impl_IPerceptionInfraredFrame<D>::VideoFrame() const
{
    Windows::Media::VideoFrame value { nullptr };
    check_hresult(WINRT_SHIM(IPerceptionInfraredFrame)->get_VideoFrame(put_abi(value)));
    return value;
}

inline hstring KnownCameraIntrinsicsProperties::FocalLength()
{
    return get_activation_factory<KnownCameraIntrinsicsProperties, IKnownCameraIntrinsicsPropertiesStatics>().FocalLength();
}

inline hstring KnownCameraIntrinsicsProperties::PrincipalPoint()
{
    return get_activation_factory<KnownCameraIntrinsicsProperties, IKnownCameraIntrinsicsPropertiesStatics>().PrincipalPoint();
}

inline hstring KnownCameraIntrinsicsProperties::RadialDistortion()
{
    return get_activation_factory<KnownCameraIntrinsicsProperties, IKnownCameraIntrinsicsPropertiesStatics>().RadialDistortion();
}

inline hstring KnownCameraIntrinsicsProperties::TangentialDistortion()
{
    return get_activation_factory<KnownCameraIntrinsicsProperties, IKnownCameraIntrinsicsPropertiesStatics>().TangentialDistortion();
}

inline hstring KnownPerceptionColorFrameSourceProperties::Exposure()
{
    return get_activation_factory<KnownPerceptionColorFrameSourceProperties, IKnownPerceptionColorFrameSourcePropertiesStatics>().Exposure();
}

inline hstring KnownPerceptionColorFrameSourceProperties::AutoExposureEnabled()
{
    return get_activation_factory<KnownPerceptionColorFrameSourceProperties, IKnownPerceptionColorFrameSourcePropertiesStatics>().AutoExposureEnabled();
}

inline hstring KnownPerceptionColorFrameSourceProperties::ExposureCompensation()
{
    return get_activation_factory<KnownPerceptionColorFrameSourceProperties, IKnownPerceptionColorFrameSourcePropertiesStatics>().ExposureCompensation();
}

inline hstring KnownPerceptionDepthFrameSourceProperties::MinDepth()
{
    return get_activation_factory<KnownPerceptionDepthFrameSourceProperties, IKnownPerceptionDepthFrameSourcePropertiesStatics>().MinDepth();
}

inline hstring KnownPerceptionDepthFrameSourceProperties::MaxDepth()
{
    return get_activation_factory<KnownPerceptionDepthFrameSourceProperties, IKnownPerceptionDepthFrameSourcePropertiesStatics>().MaxDepth();
}

inline hstring KnownPerceptionFrameSourceProperties::Id()
{
    return get_activation_factory<KnownPerceptionFrameSourceProperties, IKnownPerceptionFrameSourcePropertiesStatics>().Id();
}

inline hstring KnownPerceptionFrameSourceProperties::PhysicalDeviceIds()
{
    return get_activation_factory<KnownPerceptionFrameSourceProperties, IKnownPerceptionFrameSourcePropertiesStatics>().PhysicalDeviceIds();
}

inline hstring KnownPerceptionFrameSourceProperties::FrameKind()
{
    return get_activation_factory<KnownPerceptionFrameSourceProperties, IKnownPerceptionFrameSourcePropertiesStatics>().FrameKind();
}

inline hstring KnownPerceptionFrameSourceProperties::DeviceModelVersion()
{
    return get_activation_factory<KnownPerceptionFrameSourceProperties, IKnownPerceptionFrameSourcePropertiesStatics>().DeviceModelVersion();
}

inline hstring KnownPerceptionFrameSourceProperties::EnclosureLocation()
{
    return get_activation_factory<KnownPerceptionFrameSourceProperties, IKnownPerceptionFrameSourcePropertiesStatics>().EnclosureLocation();
}

inline hstring KnownPerceptionFrameSourceProperties::DeviceId()
{
    return get_activation_factory<KnownPerceptionFrameSourceProperties, IKnownPerceptionFrameSourcePropertiesStatics2>().DeviceId();
}

inline hstring KnownPerceptionInfraredFrameSourceProperties::Exposure()
{
    return get_activation_factory<KnownPerceptionInfraredFrameSourceProperties, IKnownPerceptionInfraredFrameSourcePropertiesStatics>().Exposure();
}

inline hstring KnownPerceptionInfraredFrameSourceProperties::AutoExposureEnabled()
{
    return get_activation_factory<KnownPerceptionInfraredFrameSourceProperties, IKnownPerceptionInfraredFrameSourcePropertiesStatics>().AutoExposureEnabled();
}

inline hstring KnownPerceptionInfraredFrameSourceProperties::ExposureCompensation()
{
    return get_activation_factory<KnownPerceptionInfraredFrameSourceProperties, IKnownPerceptionInfraredFrameSourcePropertiesStatics>().ExposureCompensation();
}

inline hstring KnownPerceptionInfraredFrameSourceProperties::ActiveIlluminationEnabled()
{
    return get_activation_factory<KnownPerceptionInfraredFrameSourceProperties, IKnownPerceptionInfraredFrameSourcePropertiesStatics>().ActiveIlluminationEnabled();
}

inline hstring KnownPerceptionInfraredFrameSourceProperties::AmbientSubtractionEnabled()
{
    return get_activation_factory<KnownPerceptionInfraredFrameSourceProperties, IKnownPerceptionInfraredFrameSourcePropertiesStatics>().AmbientSubtractionEnabled();
}

inline hstring KnownPerceptionInfraredFrameSourceProperties::StructureLightPatternEnabled()
{
    return get_activation_factory<KnownPerceptionInfraredFrameSourceProperties, IKnownPerceptionInfraredFrameSourcePropertiesStatics>().StructureLightPatternEnabled();
}

inline hstring KnownPerceptionInfraredFrameSourceProperties::InterleavedIlluminationEnabled()
{
    return get_activation_factory<KnownPerceptionInfraredFrameSourceProperties, IKnownPerceptionInfraredFrameSourcePropertiesStatics>().InterleavedIlluminationEnabled();
}

inline hstring KnownPerceptionVideoFrameSourceProperties::VideoProfile()
{
    return get_activation_factory<KnownPerceptionVideoFrameSourceProperties, IKnownPerceptionVideoFrameSourcePropertiesStatics>().VideoProfile();
}

inline hstring KnownPerceptionVideoFrameSourceProperties::SupportedVideoProfiles()
{
    return get_activation_factory<KnownPerceptionVideoFrameSourceProperties, IKnownPerceptionVideoFrameSourcePropertiesStatics>().SupportedVideoProfiles();
}

inline hstring KnownPerceptionVideoFrameSourceProperties::AvailableVideoProfiles()
{
    return get_activation_factory<KnownPerceptionVideoFrameSourceProperties, IKnownPerceptionVideoFrameSourcePropertiesStatics>().AvailableVideoProfiles();
}

inline hstring KnownPerceptionVideoFrameSourceProperties::IsMirrored()
{
    return get_activation_factory<KnownPerceptionVideoFrameSourceProperties, IKnownPerceptionVideoFrameSourcePropertiesStatics>().IsMirrored();
}

inline hstring KnownPerceptionVideoFrameSourceProperties::CameraIntrinsics()
{
    return get_activation_factory<KnownPerceptionVideoFrameSourceProperties, IKnownPerceptionVideoFrameSourcePropertiesStatics>().CameraIntrinsics();
}

inline hstring KnownPerceptionVideoProfileProperties::BitmapPixelFormat()
{
    return get_activation_factory<KnownPerceptionVideoProfileProperties, IKnownPerceptionVideoProfilePropertiesStatics>().BitmapPixelFormat();
}

inline hstring KnownPerceptionVideoProfileProperties::BitmapAlphaMode()
{
    return get_activation_factory<KnownPerceptionVideoProfileProperties, IKnownPerceptionVideoProfilePropertiesStatics>().BitmapAlphaMode();
}

inline hstring KnownPerceptionVideoProfileProperties::Width()
{
    return get_activation_factory<KnownPerceptionVideoProfileProperties, IKnownPerceptionVideoProfilePropertiesStatics>().Width();
}

inline hstring KnownPerceptionVideoProfileProperties::Height()
{
    return get_activation_factory<KnownPerceptionVideoProfileProperties, IKnownPerceptionVideoProfilePropertiesStatics>().Height();
}

inline hstring KnownPerceptionVideoProfileProperties::FrameDuration()
{
    return get_activation_factory<KnownPerceptionVideoProfileProperties, IKnownPerceptionVideoProfilePropertiesStatics>().FrameDuration();
}

inline Windows::Devices::Perception::PerceptionColorFrameSourceWatcher PerceptionColorFrameSource::CreateWatcher()
{
    return get_activation_factory<PerceptionColorFrameSource, IPerceptionColorFrameSourceStatics>().CreateWatcher();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionColorFrameSource>> PerceptionColorFrameSource::FindAllAsync()
{
    return get_activation_factory<PerceptionColorFrameSource, IPerceptionColorFrameSourceStatics>().FindAllAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionColorFrameSource> PerceptionColorFrameSource::FromIdAsync(hstring_view id)
{
    return get_activation_factory<PerceptionColorFrameSource, IPerceptionColorFrameSourceStatics>().FromIdAsync(id);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> PerceptionColorFrameSource::RequestAccessAsync()
{
    return get_activation_factory<PerceptionColorFrameSource, IPerceptionColorFrameSourceStatics>().RequestAccessAsync();
}

inline Windows::Devices::Perception::PerceptionDepthFrameSourceWatcher PerceptionDepthFrameSource::CreateWatcher()
{
    return get_activation_factory<PerceptionDepthFrameSource, IPerceptionDepthFrameSourceStatics>().CreateWatcher();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionDepthFrameSource>> PerceptionDepthFrameSource::FindAllAsync()
{
    return get_activation_factory<PerceptionDepthFrameSource, IPerceptionDepthFrameSourceStatics>().FindAllAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionDepthFrameSource> PerceptionDepthFrameSource::FromIdAsync(hstring_view id)
{
    return get_activation_factory<PerceptionDepthFrameSource, IPerceptionDepthFrameSourceStatics>().FromIdAsync(id);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> PerceptionDepthFrameSource::RequestAccessAsync()
{
    return get_activation_factory<PerceptionDepthFrameSource, IPerceptionDepthFrameSourceStatics>().RequestAccessAsync();
}

inline Windows::Devices::Perception::PerceptionInfraredFrameSourceWatcher PerceptionInfraredFrameSource::CreateWatcher()
{
    return get_activation_factory<PerceptionInfraredFrameSource, IPerceptionInfraredFrameSourceStatics>().CreateWatcher();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::PerceptionInfraredFrameSource>> PerceptionInfraredFrameSource::FindAllAsync()
{
    return get_activation_factory<PerceptionInfraredFrameSource, IPerceptionInfraredFrameSourceStatics>().FindAllAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Perception::PerceptionInfraredFrameSource> PerceptionInfraredFrameSource::FromIdAsync(hstring_view id)
{
    return get_activation_factory<PerceptionInfraredFrameSource, IPerceptionInfraredFrameSourceStatics>().FromIdAsync(id);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Perception::PerceptionFrameSourceAccessStatus> PerceptionInfraredFrameSource::RequestAccessAsync()
{
    return get_activation_factory<PerceptionInfraredFrameSource, IPerceptionInfraredFrameSourceStatics>().RequestAccessAsync();
}

}

}
#pragma warning(pop)
