// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.UI.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Devices.Geolocation.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Services.Maps.3.h"
#include "internal/Windows.Services.Maps.Guidance.3.h"
#include "Windows.Services.Maps.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceAudioNotificationRequestedEventArgs> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceAudioNotificationRequestedEventArgs>
{
    HRESULT __stdcall get_AudioNotification(Windows::Services::Maps::Guidance::GuidanceAudioNotificationKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioNotification());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioFilePaths(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioFilePaths());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioText());
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
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceLaneInfo> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceLaneInfo>
{
    HRESULT __stdcall get_LaneMarkers(Windows::Services::Maps::Guidance::GuidanceLaneMarkers * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LaneMarkers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsOnRoute(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOnRoute());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceManeuver> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceManeuver>
{
    HRESULT __stdcall get_StartLocation(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartLocation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DistanceFromRouteStart(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DistanceFromRouteStart());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DistanceFromPreviousManeuver(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DistanceFromPreviousManeuver());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DepartureRoadName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DepartureRoadName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NextRoadName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NextRoadName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DepartureShortRoadName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DepartureShortRoadName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NextShortRoadName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NextShortRoadName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::Services::Maps::Guidance::GuidanceManeuverKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StartAngle(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartAngle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndAngle(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndAngle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoadSignpost(impl::abi_arg_out<Windows::Services::Maps::Guidance::IGuidanceRoadSignpost> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoadSignpost());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InstructionText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InstructionText());
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
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate>
{
    HRESULT __stdcall get_Location(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentHeading(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentHeading());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentSpeed(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentSpeed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsOnStreet(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOnStreet());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Road(impl::abi_arg_out<Windows::Services::Maps::Guidance::IGuidanceRoadSegment> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Road());
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
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceNavigator> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceNavigator>
{
    HRESULT __stdcall abi_StartNavigating(impl::abi_arg_in<Windows::Services::Maps::Guidance::IGuidanceRoute> route) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartNavigating(*reinterpret_cast<const Windows::Services::Maps::Guidance::GuidanceRoute *>(&route));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartSimulating(impl::abi_arg_in<Windows::Services::Maps::Guidance::IGuidanceRoute> route, int32_t speedInMetersPerSecond) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartSimulating(*reinterpret_cast<const Windows::Services::Maps::Guidance::GuidanceRoute *>(&route), speedInMetersPerSecond);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartTracking() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartTracking();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Pause() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Pause();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Resume() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resume();
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

    HRESULT __stdcall abi_RepeatLastAudioNotification() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RepeatLastAudioNotification();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioMeasurementSystem(Windows::Services::Maps::Guidance::GuidanceAudioMeasurementSystem * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioMeasurementSystem());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AudioMeasurementSystem(Windows::Services::Maps::Guidance::GuidanceAudioMeasurementSystem value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioMeasurementSystem(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioNotifications(Windows::Services::Maps::Guidance::GuidanceAudioNotifications * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioNotifications());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AudioNotifications(Windows::Services::Maps::Guidance::GuidanceAudioNotifications value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioNotifications(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_GuidanceUpdated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceUpdatedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().GuidanceUpdated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceUpdatedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_GuidanceUpdated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GuidanceUpdated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DestinationReached(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DestinationReached(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DestinationReached(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DestinationReached(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Rerouting(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Rerouting(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Rerouting(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rerouting(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Rerouted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceReroutedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Rerouted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceReroutedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Rerouted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rerouted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RerouteFailed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RerouteFailed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RerouteFailed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RerouteFailed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_UserLocationLost(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UserLocationLost(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UserLocationLost(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserLocationLost(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_UserLocationRestored(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UserLocationRestored(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UserLocationRestored(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserLocationRestored(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetGuidanceVoice(int32_t voiceId, impl::abi_arg_in<hstring> voiceFolder) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetGuidanceVoice(voiceId, *reinterpret_cast<const hstring *>(&voiceFolder));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateUserLocation(impl::abi_arg_in<Windows::Devices::Geolocation::IGeocoordinate> userLocation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateUserLocation(*reinterpret_cast<const Windows::Devices::Geolocation::Geocoordinate *>(&userLocation));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateUserLocationWithPositionOverride(impl::abi_arg_in<Windows::Devices::Geolocation::IGeocoordinate> userLocation, impl::abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> positionOverride) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateUserLocation(*reinterpret_cast<const Windows::Devices::Geolocation::Geocoordinate *>(&userLocation), *reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&positionOverride));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceNavigator2> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceNavigator2>
{
    HRESULT __stdcall add_AudioNotificationRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceAudioNotificationRequestedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AudioNotificationRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceAudioNotificationRequestedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AudioNotificationRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioNotificationRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsGuidanceAudioMuted(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsGuidanceAudioMuted());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsGuidanceAudioMuted(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsGuidanceAudioMuted(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceNavigatorStatics> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceNavigatorStatics>
{
    HRESULT __stdcall abi_GetCurrent(impl::abi_arg_out<Windows::Services::Maps::Guidance::IGuidanceNavigator> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetCurrent());
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
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceNavigatorStatics2> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceNavigatorStatics2>
{
    HRESULT __stdcall get_UseAppProvidedVoice(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UseAppProvidedVoice());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceReroutedEventArgs> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceReroutedEventArgs>
{
    HRESULT __stdcall get_Route(impl::abi_arg_out<Windows::Services::Maps::Guidance::IGuidanceRoute> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Route());
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
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceRoadSegment> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceRoadSegment>
{
    HRESULT __stdcall get_RoadName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoadName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShortRoadName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShortRoadName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpeedLimit(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpeedLimit());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TravelTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TravelTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Path(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopath> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Path());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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

    HRESULT __stdcall get_IsHighway(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHighway());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTunnel(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTunnel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTollRoad(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTollRoad());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceRoadSignpost> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceRoadSignpost>
{
    HRESULT __stdcall get_ExitNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Exit(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Exit());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ForegroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ForegroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitDirections(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitDirections());
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
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceRoute> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceRoute>
{
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

    HRESULT __stdcall get_Distance(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Distance());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Maneuvers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceManeuver>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Maneuvers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BoundingBox(impl::abi_arg_out<Windows::Devices::Geolocation::IGeoboundingBox> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BoundingBox());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Path(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopath> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Path());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoadSegments(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceRoadSegment>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoadSegments());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConvertToMapRoute(impl::abi_arg_out<Windows::Services::Maps::IMapRoute> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ConvertToMapRoute());
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
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceRouteStatics> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceRouteStatics>
{
    HRESULT __stdcall abi_CanCreateFromMapRoute(impl::abi_arg_in<Windows::Services::Maps::IMapRoute> mapRoute, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CanCreateFromMapRoute(*reinterpret_cast<const Windows::Services::Maps::MapRoute *>(&mapRoute)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryCreateFromMapRoute(impl::abi_arg_in<Windows::Services::Maps::IMapRoute> mapRoute, impl::abi_arg_out<Windows::Services::Maps::Guidance::IGuidanceRoute> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryCreateFromMapRoute(*reinterpret_cast<const Windows::Services::Maps::MapRoute *>(&mapRoute)));
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
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector>
{
    HRESULT __stdcall get_Enabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Enabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Enabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Enabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearLocalData() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearLocalData();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpeedTrigger(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpeedTrigger());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SpeedTrigger(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SpeedTrigger(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UploadFrequency(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UploadFrequency());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UploadFrequency(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UploadFrequency(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceTelemetryCollectorStatics> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceTelemetryCollectorStatics>
{
    HRESULT __stdcall abi_GetCurrent(impl::abi_arg_out<Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetCurrent());
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
struct produce<D, Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs> : produce_base<D, Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>
{
    HRESULT __stdcall get_Mode(Windows::Services::Maps::Guidance::GuidanceMode * value) noexcept override
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

    HRESULT __stdcall get_NextManeuver(impl::abi_arg_out<Windows::Services::Maps::Guidance::IGuidanceManeuver> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NextManeuver());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NextManeuverDistance(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NextManeuverDistance());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AfterNextManeuver(impl::abi_arg_out<Windows::Services::Maps::Guidance::IGuidanceManeuver> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AfterNextManeuver());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AfterNextManeuverDistance(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AfterNextManeuverDistance());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DistanceToDestination(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DistanceToDestination());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ElapsedDistance(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ElapsedDistance());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ElapsedTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ElapsedTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TimeToDestination(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimeToDestination());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoadName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoadName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Route(impl::abi_arg_out<Windows::Services::Maps::Guidance::IGuidanceRoute> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Route());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentLocation(impl::abi_arg_out<Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CurrentLocation());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsNewManeuver(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsNewManeuver());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LaneInfo(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceLaneInfo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LaneInfo());
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

namespace Windows::Services::Maps::Guidance {

template <typename D> hstring impl_IGuidanceRoadSignpost<D>::ExitNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGuidanceRoadSignpost)->get_ExitNumber(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGuidanceRoadSignpost<D>::Exit() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGuidanceRoadSignpost)->get_Exit(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Color impl_IGuidanceRoadSignpost<D>::BackgroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IGuidanceRoadSignpost)->get_BackgroundColor(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Color impl_IGuidanceRoadSignpost<D>::ForegroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IGuidanceRoadSignpost)->get_ForegroundColor(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IGuidanceRoadSignpost<D>::ExitDirections() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IGuidanceRoadSignpost)->get_ExitDirections(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IGuidanceManeuver<D>::StartLocation() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceManeuver)->get_StartLocation(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IGuidanceManeuver<D>::DistanceFromRouteStart() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGuidanceManeuver)->get_DistanceFromRouteStart(&value));
    return value;
}

template <typename D> int32_t impl_IGuidanceManeuver<D>::DistanceFromPreviousManeuver() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGuidanceManeuver)->get_DistanceFromPreviousManeuver(&value));
    return value;
}

template <typename D> hstring impl_IGuidanceManeuver<D>::DepartureRoadName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGuidanceManeuver)->get_DepartureRoadName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGuidanceManeuver<D>::NextRoadName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGuidanceManeuver)->get_NextRoadName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGuidanceManeuver<D>::DepartureShortRoadName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGuidanceManeuver)->get_DepartureShortRoadName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGuidanceManeuver<D>::NextShortRoadName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGuidanceManeuver)->get_NextShortRoadName(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceManeuverKind impl_IGuidanceManeuver<D>::Kind() const
{
    Windows::Services::Maps::Guidance::GuidanceManeuverKind value {};
    check_hresult(WINRT_SHIM(IGuidanceManeuver)->get_Kind(&value));
    return value;
}

template <typename D> int32_t impl_IGuidanceManeuver<D>::StartAngle() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGuidanceManeuver)->get_StartAngle(&value));
    return value;
}

template <typename D> int32_t impl_IGuidanceManeuver<D>::EndAngle() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGuidanceManeuver)->get_EndAngle(&value));
    return value;
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceRoadSignpost impl_IGuidanceManeuver<D>::RoadSignpost() const
{
    Windows::Services::Maps::Guidance::GuidanceRoadSignpost value { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceManeuver)->get_RoadSignpost(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGuidanceManeuver<D>::InstructionText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGuidanceManeuver)->get_InstructionText(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceMode impl_IGuidanceUpdatedEventArgs<D>::Mode() const
{
    Windows::Services::Maps::Guidance::GuidanceMode value {};
    check_hresult(WINRT_SHIM(IGuidanceUpdatedEventArgs)->get_Mode(&value));
    return value;
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceManeuver impl_IGuidanceUpdatedEventArgs<D>::NextManeuver() const
{
    Windows::Services::Maps::Guidance::GuidanceManeuver value { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceUpdatedEventArgs)->get_NextManeuver(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IGuidanceUpdatedEventArgs<D>::NextManeuverDistance() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGuidanceUpdatedEventArgs)->get_NextManeuverDistance(&value));
    return value;
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceManeuver impl_IGuidanceUpdatedEventArgs<D>::AfterNextManeuver() const
{
    Windows::Services::Maps::Guidance::GuidanceManeuver value { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceUpdatedEventArgs)->get_AfterNextManeuver(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IGuidanceUpdatedEventArgs<D>::AfterNextManeuverDistance() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGuidanceUpdatedEventArgs)->get_AfterNextManeuverDistance(&value));
    return value;
}

template <typename D> int32_t impl_IGuidanceUpdatedEventArgs<D>::DistanceToDestination() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGuidanceUpdatedEventArgs)->get_DistanceToDestination(&value));
    return value;
}

template <typename D> int32_t impl_IGuidanceUpdatedEventArgs<D>::ElapsedDistance() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGuidanceUpdatedEventArgs)->get_ElapsedDistance(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IGuidanceUpdatedEventArgs<D>::ElapsedTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IGuidanceUpdatedEventArgs)->get_ElapsedTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IGuidanceUpdatedEventArgs<D>::TimeToDestination() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IGuidanceUpdatedEventArgs)->get_TimeToDestination(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGuidanceUpdatedEventArgs<D>::RoadName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGuidanceUpdatedEventArgs)->get_RoadName(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceRoute impl_IGuidanceUpdatedEventArgs<D>::Route() const
{
    Windows::Services::Maps::Guidance::GuidanceRoute result { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceUpdatedEventArgs)->get_Route(put_abi(result)));
    return result;
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceMapMatchedCoordinate impl_IGuidanceUpdatedEventArgs<D>::CurrentLocation() const
{
    Windows::Services::Maps::Guidance::GuidanceMapMatchedCoordinate result { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceUpdatedEventArgs)->get_CurrentLocation(put_abi(result)));
    return result;
}

template <typename D> bool impl_IGuidanceUpdatedEventArgs<D>::IsNewManeuver() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGuidanceUpdatedEventArgs)->get_IsNewManeuver(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceLaneInfo> impl_IGuidanceUpdatedEventArgs<D>::LaneInfo() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceLaneInfo> value;
    check_hresult(WINRT_SHIM(IGuidanceUpdatedEventArgs)->get_LaneInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceRoute impl_IGuidanceReroutedEventArgs<D>::Route() const
{
    Windows::Services::Maps::Guidance::GuidanceRoute result { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceReroutedEventArgs)->get_Route(put_abi(result)));
    return result;
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceAudioNotificationKind impl_IGuidanceAudioNotificationRequestedEventArgs<D>::AudioNotification() const
{
    Windows::Services::Maps::Guidance::GuidanceAudioNotificationKind value {};
    check_hresult(WINRT_SHIM(IGuidanceAudioNotificationRequestedEventArgs)->get_AudioNotification(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IGuidanceAudioNotificationRequestedEventArgs<D>::AudioFilePaths() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IGuidanceAudioNotificationRequestedEventArgs)->get_AudioFilePaths(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGuidanceAudioNotificationRequestedEventArgs<D>::AudioText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGuidanceAudioNotificationRequestedEventArgs)->get_AudioText(put_abi(value)));
    return value;
}

template <typename D> void impl_IGuidanceNavigator<D>::StartNavigating(const Windows::Services::Maps::Guidance::GuidanceRoute & route) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->abi_StartNavigating(get_abi(route)));
}

template <typename D> void impl_IGuidanceNavigator<D>::StartSimulating(const Windows::Services::Maps::Guidance::GuidanceRoute & route, int32_t speedInMetersPerSecond) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->abi_StartSimulating(get_abi(route), speedInMetersPerSecond));
}

template <typename D> void impl_IGuidanceNavigator<D>::StartTracking() const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->abi_StartTracking());
}

template <typename D> void impl_IGuidanceNavigator<D>::Pause() const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->abi_Pause());
}

template <typename D> void impl_IGuidanceNavigator<D>::Resume() const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->abi_Resume());
}

template <typename D> void impl_IGuidanceNavigator<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->abi_Stop());
}

template <typename D> void impl_IGuidanceNavigator<D>::RepeatLastAudioNotification() const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->abi_RepeatLastAudioNotification());
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceAudioMeasurementSystem impl_IGuidanceNavigator<D>::AudioMeasurementSystem() const
{
    Windows::Services::Maps::Guidance::GuidanceAudioMeasurementSystem value {};
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->get_AudioMeasurementSystem(&value));
    return value;
}

template <typename D> void impl_IGuidanceNavigator<D>::AudioMeasurementSystem(Windows::Services::Maps::Guidance::GuidanceAudioMeasurementSystem value) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->put_AudioMeasurementSystem(value));
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceAudioNotifications impl_IGuidanceNavigator<D>::AudioNotifications() const
{
    Windows::Services::Maps::Guidance::GuidanceAudioNotifications value {};
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->get_AudioNotifications(&value));
    return value;
}

template <typename D> void impl_IGuidanceNavigator<D>::AudioNotifications(Windows::Services::Maps::Guidance::GuidanceAudioNotifications value) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->put_AudioNotifications(value));
}

template <typename D> event_token impl_IGuidanceNavigator<D>::GuidanceUpdated(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceUpdatedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->add_GuidanceUpdated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGuidanceNavigator> impl_IGuidanceNavigator<D>::GuidanceUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceUpdatedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IGuidanceNavigator>(this, &ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator::remove_GuidanceUpdated, GuidanceUpdated(handler));
}

template <typename D> void impl_IGuidanceNavigator<D>::GuidanceUpdated(event_token token) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->remove_GuidanceUpdated(token));
}

template <typename D> event_token impl_IGuidanceNavigator<D>::DestinationReached(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->add_DestinationReached(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGuidanceNavigator> impl_IGuidanceNavigator<D>::DestinationReached(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IGuidanceNavigator>(this, &ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator::remove_DestinationReached, DestinationReached(handler));
}

template <typename D> void impl_IGuidanceNavigator<D>::DestinationReached(event_token token) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->remove_DestinationReached(token));
}

template <typename D> event_token impl_IGuidanceNavigator<D>::Rerouting(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->add_Rerouting(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGuidanceNavigator> impl_IGuidanceNavigator<D>::Rerouting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IGuidanceNavigator>(this, &ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator::remove_Rerouting, Rerouting(handler));
}

template <typename D> void impl_IGuidanceNavigator<D>::Rerouting(event_token token) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->remove_Rerouting(token));
}

template <typename D> event_token impl_IGuidanceNavigator<D>::Rerouted(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceReroutedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->add_Rerouted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGuidanceNavigator> impl_IGuidanceNavigator<D>::Rerouted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceReroutedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IGuidanceNavigator>(this, &ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator::remove_Rerouted, Rerouted(handler));
}

template <typename D> void impl_IGuidanceNavigator<D>::Rerouted(event_token token) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->remove_Rerouted(token));
}

template <typename D> event_token impl_IGuidanceNavigator<D>::RerouteFailed(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->add_RerouteFailed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGuidanceNavigator> impl_IGuidanceNavigator<D>::RerouteFailed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IGuidanceNavigator>(this, &ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator::remove_RerouteFailed, RerouteFailed(handler));
}

template <typename D> void impl_IGuidanceNavigator<D>::RerouteFailed(event_token token) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->remove_RerouteFailed(token));
}

template <typename D> event_token impl_IGuidanceNavigator<D>::UserLocationLost(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->add_UserLocationLost(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGuidanceNavigator> impl_IGuidanceNavigator<D>::UserLocationLost(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IGuidanceNavigator>(this, &ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator::remove_UserLocationLost, UserLocationLost(handler));
}

template <typename D> void impl_IGuidanceNavigator<D>::UserLocationLost(event_token token) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->remove_UserLocationLost(token));
}

template <typename D> event_token impl_IGuidanceNavigator<D>::UserLocationRestored(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->add_UserLocationRestored(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGuidanceNavigator> impl_IGuidanceNavigator<D>::UserLocationRestored(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IGuidanceNavigator>(this, &ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator::remove_UserLocationRestored, UserLocationRestored(handler));
}

template <typename D> void impl_IGuidanceNavigator<D>::UserLocationRestored(event_token token) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->remove_UserLocationRestored(token));
}

template <typename D> void impl_IGuidanceNavigator<D>::SetGuidanceVoice(int32_t voiceId, hstring_view voiceFolder) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->abi_SetGuidanceVoice(voiceId, get_abi(voiceFolder)));
}

template <typename D> void impl_IGuidanceNavigator<D>::UpdateUserLocation(const Windows::Devices::Geolocation::Geocoordinate & userLocation) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->abi_UpdateUserLocation(get_abi(userLocation)));
}

template <typename D> void impl_IGuidanceNavigator<D>::UpdateUserLocation(const Windows::Devices::Geolocation::Geocoordinate & userLocation, const Windows::Devices::Geolocation::BasicGeoposition & positionOverride) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator)->abi_UpdateUserLocationWithPositionOverride(get_abi(userLocation), get_abi(positionOverride)));
}

template <typename D> event_token impl_IGuidanceNavigator2<D>::AudioNotificationRequested(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceAudioNotificationRequestedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGuidanceNavigator2)->add_AudioNotificationRequested(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IGuidanceNavigator2> impl_IGuidanceNavigator2<D>::AudioNotificationRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceAudioNotificationRequestedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IGuidanceNavigator2>(this, &ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator2::remove_AudioNotificationRequested, AudioNotificationRequested(value));
}

template <typename D> void impl_IGuidanceNavigator2<D>::AudioNotificationRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator2)->remove_AudioNotificationRequested(token));
}

template <typename D> bool impl_IGuidanceNavigator2<D>::IsGuidanceAudioMuted() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGuidanceNavigator2)->get_IsGuidanceAudioMuted(&value));
    return value;
}

template <typename D> void impl_IGuidanceNavigator2<D>::IsGuidanceAudioMuted(bool value) const
{
    check_hresult(WINRT_SHIM(IGuidanceNavigator2)->put_IsGuidanceAudioMuted(value));
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceNavigator impl_IGuidanceNavigatorStatics<D>::GetCurrent() const
{
    Windows::Services::Maps::Guidance::GuidanceNavigator result { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceNavigatorStatics)->abi_GetCurrent(put_abi(result)));
    return result;
}

template <typename D> bool impl_IGuidanceNavigatorStatics2<D>::UseAppProvidedVoice() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGuidanceNavigatorStatics2)->get_UseAppProvidedVoice(&value));
    return value;
}

template <typename D> hstring impl_IGuidanceRoadSegment<D>::RoadName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGuidanceRoadSegment)->get_RoadName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGuidanceRoadSegment<D>::ShortRoadName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGuidanceRoadSegment)->get_ShortRoadName(put_abi(value)));
    return value;
}

template <typename D> double impl_IGuidanceRoadSegment<D>::SpeedLimit() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGuidanceRoadSegment)->get_SpeedLimit(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IGuidanceRoadSegment<D>::TravelTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IGuidanceRoadSegment)->get_TravelTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopath impl_IGuidanceRoadSegment<D>::Path() const
{
    Windows::Devices::Geolocation::Geopath value { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceRoadSegment)->get_Path(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGuidanceRoadSegment<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGuidanceRoadSegment)->get_Id(put_abi(value)));
    return value;
}

template <typename D> bool impl_IGuidanceRoadSegment<D>::IsHighway() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGuidanceRoadSegment)->get_IsHighway(&value));
    return value;
}

template <typename D> bool impl_IGuidanceRoadSegment<D>::IsTunnel() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGuidanceRoadSegment)->get_IsTunnel(&value));
    return value;
}

template <typename D> bool impl_IGuidanceRoadSegment<D>::IsTollRoad() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGuidanceRoadSegment)->get_IsTollRoad(&value));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IGuidanceMapMatchedCoordinate<D>::Location() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceMapMatchedCoordinate)->get_Location(put_abi(value)));
    return value;
}

template <typename D> double impl_IGuidanceMapMatchedCoordinate<D>::CurrentHeading() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGuidanceMapMatchedCoordinate)->get_CurrentHeading(&value));
    return value;
}

template <typename D> double impl_IGuidanceMapMatchedCoordinate<D>::CurrentSpeed() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGuidanceMapMatchedCoordinate)->get_CurrentSpeed(&value));
    return value;
}

template <typename D> bool impl_IGuidanceMapMatchedCoordinate<D>::IsOnStreet() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGuidanceMapMatchedCoordinate)->get_IsOnStreet(&value));
    return value;
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceRoadSegment impl_IGuidanceMapMatchedCoordinate<D>::Road() const
{
    Windows::Services::Maps::Guidance::GuidanceRoadSegment value { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceMapMatchedCoordinate)->get_Road(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceTelemetryCollector impl_IGuidanceTelemetryCollectorStatics<D>::GetCurrent() const
{
    Windows::Services::Maps::Guidance::GuidanceTelemetryCollector result { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceTelemetryCollectorStatics)->abi_GetCurrent(put_abi(result)));
    return result;
}

template <typename D> bool impl_IGuidanceTelemetryCollector<D>::Enabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGuidanceTelemetryCollector)->get_Enabled(&value));
    return value;
}

template <typename D> void impl_IGuidanceTelemetryCollector<D>::Enabled(bool value) const
{
    check_hresult(WINRT_SHIM(IGuidanceTelemetryCollector)->put_Enabled(value));
}

template <typename D> void impl_IGuidanceTelemetryCollector<D>::ClearLocalData() const
{
    check_hresult(WINRT_SHIM(IGuidanceTelemetryCollector)->abi_ClearLocalData());
}

template <typename D> double impl_IGuidanceTelemetryCollector<D>::SpeedTrigger() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGuidanceTelemetryCollector)->get_SpeedTrigger(&value));
    return value;
}

template <typename D> void impl_IGuidanceTelemetryCollector<D>::SpeedTrigger(double value) const
{
    check_hresult(WINRT_SHIM(IGuidanceTelemetryCollector)->put_SpeedTrigger(value));
}

template <typename D> int32_t impl_IGuidanceTelemetryCollector<D>::UploadFrequency() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGuidanceTelemetryCollector)->get_UploadFrequency(&value));
    return value;
}

template <typename D> void impl_IGuidanceTelemetryCollector<D>::UploadFrequency(int32_t value) const
{
    check_hresult(WINRT_SHIM(IGuidanceTelemetryCollector)->put_UploadFrequency(value));
}

template <typename D> bool impl_IGuidanceRouteStatics<D>::CanCreateFromMapRoute(const Windows::Services::Maps::MapRoute & mapRoute) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IGuidanceRouteStatics)->abi_CanCreateFromMapRoute(get_abi(mapRoute), &result));
    return result;
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceRoute impl_IGuidanceRouteStatics<D>::TryCreateFromMapRoute(const Windows::Services::Maps::MapRoute & mapRoute) const
{
    Windows::Services::Maps::Guidance::GuidanceRoute result { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceRouteStatics)->abi_TryCreateFromMapRoute(get_abi(mapRoute), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::TimeSpan impl_IGuidanceRoute<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IGuidanceRoute)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IGuidanceRoute<D>::Distance() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGuidanceRoute)->get_Distance(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceManeuver> impl_IGuidanceRoute<D>::Maneuvers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceManeuver> value;
    check_hresult(WINRT_SHIM(IGuidanceRoute)->get_Maneuvers(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::GeoboundingBox impl_IGuidanceRoute<D>::BoundingBox() const
{
    Windows::Devices::Geolocation::GeoboundingBox value { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceRoute)->get_BoundingBox(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopath impl_IGuidanceRoute<D>::Path() const
{
    Windows::Devices::Geolocation::Geopath value { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceRoute)->get_Path(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceRoadSegment> impl_IGuidanceRoute<D>::RoadSegments() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceRoadSegment> value;
    check_hresult(WINRT_SHIM(IGuidanceRoute)->get_RoadSegments(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Maps::MapRoute impl_IGuidanceRoute<D>::ConvertToMapRoute() const
{
    Windows::Services::Maps::MapRoute result { nullptr };
    check_hresult(WINRT_SHIM(IGuidanceRoute)->abi_ConvertToMapRoute(put_abi(result)));
    return result;
}

template <typename D> Windows::Services::Maps::Guidance::GuidanceLaneMarkers impl_IGuidanceLaneInfo<D>::LaneMarkers() const
{
    Windows::Services::Maps::Guidance::GuidanceLaneMarkers value {};
    check_hresult(WINRT_SHIM(IGuidanceLaneInfo)->get_LaneMarkers(&value));
    return value;
}

template <typename D> bool impl_IGuidanceLaneInfo<D>::IsOnRoute() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGuidanceLaneInfo)->get_IsOnRoute(&value));
    return value;
}

inline Windows::Services::Maps::Guidance::GuidanceNavigator GuidanceNavigator::GetCurrent()
{
    return get_activation_factory<GuidanceNavigator, IGuidanceNavigatorStatics>().GetCurrent();
}

inline bool GuidanceNavigator::UseAppProvidedVoice()
{
    return get_activation_factory<GuidanceNavigator, IGuidanceNavigatorStatics2>().UseAppProvidedVoice();
}

inline bool GuidanceRoute::CanCreateFromMapRoute(const Windows::Services::Maps::MapRoute & mapRoute)
{
    return get_activation_factory<GuidanceRoute, IGuidanceRouteStatics>().CanCreateFromMapRoute(mapRoute);
}

inline Windows::Services::Maps::Guidance::GuidanceRoute GuidanceRoute::TryCreateFromMapRoute(const Windows::Services::Maps::MapRoute & mapRoute)
{
    return get_activation_factory<GuidanceRoute, IGuidanceRouteStatics>().TryCreateFromMapRoute(mapRoute);
}

inline Windows::Services::Maps::Guidance::GuidanceTelemetryCollector GuidanceTelemetryCollector::GetCurrent()
{
    return get_activation_factory<GuidanceTelemetryCollector, IGuidanceTelemetryCollectorStatics>().GetCurrent();
}

}

}
#pragma warning(pop)
