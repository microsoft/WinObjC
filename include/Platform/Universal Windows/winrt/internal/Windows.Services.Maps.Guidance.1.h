// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Services.Maps.Guidance.0.h"
#include "Windows.Devices.Geolocation.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Services.Maps.0.h"
#include "Windows.UI.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Services::Maps::Guidance {

struct __declspec(uuid("ca2aa24a-c7c2-4d4c-9d7c-499576bceddb")) __declspec(novtable) IGuidanceAudioNotificationRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AudioNotification(winrt::Windows::Services::Maps::Guidance::GuidanceAudioNotificationKind * value) = 0;
    virtual HRESULT __stdcall get_AudioFilePaths(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_AudioText(hstring * value) = 0;
};

struct __declspec(uuid("8404d114-6581-43b7-ac15-c9079bf90df1")) __declspec(novtable) IGuidanceLaneInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LaneMarkers(winrt::Windows::Services::Maps::Guidance::GuidanceLaneMarkers * value) = 0;
    virtual HRESULT __stdcall get_IsOnRoute(bool * value) = 0;
};

struct __declspec(uuid("fc09326c-ecc9-4928-a2a1-7232b99b94a1")) __declspec(novtable) IGuidanceManeuver : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StartLocation(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall get_DistanceFromRouteStart(int32_t * value) = 0;
    virtual HRESULT __stdcall get_DistanceFromPreviousManeuver(int32_t * value) = 0;
    virtual HRESULT __stdcall get_DepartureRoadName(hstring * value) = 0;
    virtual HRESULT __stdcall get_NextRoadName(hstring * value) = 0;
    virtual HRESULT __stdcall get_DepartureShortRoadName(hstring * value) = 0;
    virtual HRESULT __stdcall get_NextShortRoadName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Kind(winrt::Windows::Services::Maps::Guidance::GuidanceManeuverKind * value) = 0;
    virtual HRESULT __stdcall get_StartAngle(int32_t * value) = 0;
    virtual HRESULT __stdcall get_EndAngle(int32_t * value) = 0;
    virtual HRESULT __stdcall get_RoadSignpost(Windows::Services::Maps::Guidance::IGuidanceRoadSignpost ** value) = 0;
    virtual HRESULT __stdcall get_InstructionText(hstring * value) = 0;
};

struct __declspec(uuid("b7acb168-2912-4a99-aff1-798609b981fe")) __declspec(novtable) IGuidanceMapMatchedCoordinate : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Location(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall get_CurrentHeading(double * value) = 0;
    virtual HRESULT __stdcall get_CurrentSpeed(double * value) = 0;
    virtual HRESULT __stdcall get_IsOnStreet(bool * value) = 0;
    virtual HRESULT __stdcall get_Road(Windows::Services::Maps::Guidance::IGuidanceRoadSegment ** value) = 0;
};

struct __declspec(uuid("08f17ef7-8e3f-4d9a-be8a-108f9a012c67")) __declspec(novtable) IGuidanceNavigator : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_StartNavigating(Windows::Services::Maps::Guidance::IGuidanceRoute * route) = 0;
    virtual HRESULT __stdcall abi_StartSimulating(Windows::Services::Maps::Guidance::IGuidanceRoute * route, int32_t speedInMetersPerSecond) = 0;
    virtual HRESULT __stdcall abi_StartTracking() = 0;
    virtual HRESULT __stdcall abi_Pause() = 0;
    virtual HRESULT __stdcall abi_Resume() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall abi_RepeatLastAudioNotification() = 0;
    virtual HRESULT __stdcall get_AudioMeasurementSystem(winrt::Windows::Services::Maps::Guidance::GuidanceAudioMeasurementSystem * value) = 0;
    virtual HRESULT __stdcall put_AudioMeasurementSystem(winrt::Windows::Services::Maps::Guidance::GuidanceAudioMeasurementSystem value) = 0;
    virtual HRESULT __stdcall get_AudioNotifications(winrt::Windows::Services::Maps::Guidance::GuidanceAudioNotifications * value) = 0;
    virtual HRESULT __stdcall put_AudioNotifications(winrt::Windows::Services::Maps::Guidance::GuidanceAudioNotifications value) = 0;
    virtual HRESULT __stdcall add_GuidanceUpdated(Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceUpdatedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_GuidanceUpdated(event_token token) = 0;
    virtual HRESULT __stdcall add_DestinationReached(Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DestinationReached(event_token token) = 0;
    virtual HRESULT __stdcall add_Rerouting(Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Rerouting(event_token token) = 0;
    virtual HRESULT __stdcall add_Rerouted(Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceReroutedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Rerouted(event_token token) = 0;
    virtual HRESULT __stdcall add_RerouteFailed(Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RerouteFailed(event_token token) = 0;
    virtual HRESULT __stdcall add_UserLocationLost(Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UserLocationLost(event_token token) = 0;
    virtual HRESULT __stdcall add_UserLocationRestored(Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UserLocationRestored(event_token token) = 0;
    virtual HRESULT __stdcall abi_SetGuidanceVoice(int32_t voiceId, hstring voiceFolder) = 0;
    virtual HRESULT __stdcall abi_UpdateUserLocation(Windows::Devices::Geolocation::IGeocoordinate * userLocation) = 0;
    virtual HRESULT __stdcall abi_UpdateUserLocationWithPositionOverride(Windows::Devices::Geolocation::IGeocoordinate * userLocation, Windows::Devices::Geolocation::BasicGeoposition positionOverride) = 0;
};

struct __declspec(uuid("6cdc50d1-041c-4bf3-b633-a101fc2f6b57")) __declspec(novtable) IGuidanceNavigator2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_AudioNotificationRequested(Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceAudioNotificationRequestedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AudioNotificationRequested(event_token token) = 0;
    virtual HRESULT __stdcall get_IsGuidanceAudioMuted(bool * value) = 0;
    virtual HRESULT __stdcall put_IsGuidanceAudioMuted(bool value) = 0;
};

struct __declspec(uuid("00fd9513-4456-4e66-a143-3add6be08426")) __declspec(novtable) IGuidanceNavigatorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrent(Windows::Services::Maps::Guidance::IGuidanceNavigator ** result) = 0;
};

struct __declspec(uuid("54c5c3e2-7784-4c85-8c95-d0c6efb43965")) __declspec(novtable) IGuidanceNavigatorStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UseAppProvidedVoice(bool * value) = 0;
};

struct __declspec(uuid("115d4008-d528-454e-bb94-a50341d2c9f1")) __declspec(novtable) IGuidanceReroutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Route(Windows::Services::Maps::Guidance::IGuidanceRoute ** result) = 0;
};

struct __declspec(uuid("b32758a6-be78-4c63-afe7-6c2957479b3e")) __declspec(novtable) IGuidanceRoadSegment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RoadName(hstring * value) = 0;
    virtual HRESULT __stdcall get_ShortRoadName(hstring * value) = 0;
    virtual HRESULT __stdcall get_SpeedLimit(double * value) = 0;
    virtual HRESULT __stdcall get_TravelTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Path(Windows::Devices::Geolocation::IGeopath ** value) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_IsHighway(bool * value) = 0;
    virtual HRESULT __stdcall get_IsTunnel(bool * value) = 0;
    virtual HRESULT __stdcall get_IsTollRoad(bool * value) = 0;
};

struct __declspec(uuid("f1a728b6-f77a-4742-8312-53300f9845f0")) __declspec(novtable) IGuidanceRoadSignpost : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExitNumber(hstring * value) = 0;
    virtual HRESULT __stdcall get_Exit(hstring * value) = 0;
    virtual HRESULT __stdcall get_BackgroundColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_ForegroundColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_ExitDirections(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
};

struct __declspec(uuid("3a14545d-801a-40bd-a286-afb2010cce6c")) __declspec(novtable) IGuidanceRoute : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Duration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Distance(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Maneuvers(Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceManeuver> ** value) = 0;
    virtual HRESULT __stdcall get_BoundingBox(Windows::Devices::Geolocation::IGeoboundingBox ** value) = 0;
    virtual HRESULT __stdcall get_Path(Windows::Devices::Geolocation::IGeopath ** value) = 0;
    virtual HRESULT __stdcall get_RoadSegments(Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceRoadSegment> ** value) = 0;
    virtual HRESULT __stdcall abi_ConvertToMapRoute(Windows::Services::Maps::IMapRoute ** result) = 0;
};

struct __declspec(uuid("f56d926a-55ed-49c1-b09c-4b8223b50db3")) __declspec(novtable) IGuidanceRouteStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CanCreateFromMapRoute(Windows::Services::Maps::IMapRoute * mapRoute, bool * result) = 0;
    virtual HRESULT __stdcall abi_TryCreateFromMapRoute(Windows::Services::Maps::IMapRoute * mapRoute, Windows::Services::Maps::Guidance::IGuidanceRoute ** result) = 0;
};

struct __declspec(uuid("db1f8da5-b878-4d92-98dd-347d23d38262")) __declspec(novtable) IGuidanceTelemetryCollector : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Enabled(bool * value) = 0;
    virtual HRESULT __stdcall put_Enabled(bool value) = 0;
    virtual HRESULT __stdcall abi_ClearLocalData() = 0;
    virtual HRESULT __stdcall get_SpeedTrigger(double * value) = 0;
    virtual HRESULT __stdcall put_SpeedTrigger(double value) = 0;
    virtual HRESULT __stdcall get_UploadFrequency(int32_t * value) = 0;
    virtual HRESULT __stdcall put_UploadFrequency(int32_t value) = 0;
};

struct __declspec(uuid("36532047-f160-44fb-b578-94577ca05990")) __declspec(novtable) IGuidanceTelemetryCollectorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCurrent(Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector ** result) = 0;
};

struct __declspec(uuid("fdac160b-9e8d-4de3-a9fa-b06321d18db9")) __declspec(novtable) IGuidanceUpdatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Mode(winrt::Windows::Services::Maps::Guidance::GuidanceMode * value) = 0;
    virtual HRESULT __stdcall get_NextManeuver(Windows::Services::Maps::Guidance::IGuidanceManeuver ** value) = 0;
    virtual HRESULT __stdcall get_NextManeuverDistance(int32_t * value) = 0;
    virtual HRESULT __stdcall get_AfterNextManeuver(Windows::Services::Maps::Guidance::IGuidanceManeuver ** value) = 0;
    virtual HRESULT __stdcall get_AfterNextManeuverDistance(int32_t * value) = 0;
    virtual HRESULT __stdcall get_DistanceToDestination(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ElapsedDistance(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ElapsedTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_TimeToDestination(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_RoadName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Route(Windows::Services::Maps::Guidance::IGuidanceRoute ** result) = 0;
    virtual HRESULT __stdcall get_CurrentLocation(Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate ** result) = 0;
    virtual HRESULT __stdcall get_IsNewManeuver(bool * value) = 0;
    virtual HRESULT __stdcall get_LaneInfo(Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceLaneInfo> ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Services::Maps::Guidance::GuidanceAudioNotificationRequestedEventArgs> { using default_interface = Windows::Services::Maps::Guidance::IGuidanceAudioNotificationRequestedEventArgs; };
template <> struct traits<Windows::Services::Maps::Guidance::GuidanceLaneInfo> { using default_interface = Windows::Services::Maps::Guidance::IGuidanceLaneInfo; };
template <> struct traits<Windows::Services::Maps::Guidance::GuidanceManeuver> { using default_interface = Windows::Services::Maps::Guidance::IGuidanceManeuver; };
template <> struct traits<Windows::Services::Maps::Guidance::GuidanceMapMatchedCoordinate> { using default_interface = Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate; };
template <> struct traits<Windows::Services::Maps::Guidance::GuidanceNavigator> { using default_interface = Windows::Services::Maps::Guidance::IGuidanceNavigator; };
template <> struct traits<Windows::Services::Maps::Guidance::GuidanceReroutedEventArgs> { using default_interface = Windows::Services::Maps::Guidance::IGuidanceReroutedEventArgs; };
template <> struct traits<Windows::Services::Maps::Guidance::GuidanceRoadSegment> { using default_interface = Windows::Services::Maps::Guidance::IGuidanceRoadSegment; };
template <> struct traits<Windows::Services::Maps::Guidance::GuidanceRoadSignpost> { using default_interface = Windows::Services::Maps::Guidance::IGuidanceRoadSignpost; };
template <> struct traits<Windows::Services::Maps::Guidance::GuidanceRoute> { using default_interface = Windows::Services::Maps::Guidance::IGuidanceRoute; };
template <> struct traits<Windows::Services::Maps::Guidance::GuidanceTelemetryCollector> { using default_interface = Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector; };
template <> struct traits<Windows::Services::Maps::Guidance::GuidanceUpdatedEventArgs> { using default_interface = Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs; };

}

namespace Windows::Services::Maps::Guidance {

template <typename D>
struct WINRT_EBO impl_IGuidanceAudioNotificationRequestedEventArgs
{
    Windows::Services::Maps::Guidance::GuidanceAudioNotificationKind AudioNotification() const;
    Windows::Foundation::Collections::IVectorView<hstring> AudioFilePaths() const;
    hstring AudioText() const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceLaneInfo
{
    Windows::Services::Maps::Guidance::GuidanceLaneMarkers LaneMarkers() const;
    bool IsOnRoute() const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceManeuver
{
    Windows::Devices::Geolocation::Geopoint StartLocation() const;
    int32_t DistanceFromRouteStart() const;
    int32_t DistanceFromPreviousManeuver() const;
    hstring DepartureRoadName() const;
    hstring NextRoadName() const;
    hstring DepartureShortRoadName() const;
    hstring NextShortRoadName() const;
    Windows::Services::Maps::Guidance::GuidanceManeuverKind Kind() const;
    int32_t StartAngle() const;
    int32_t EndAngle() const;
    Windows::Services::Maps::Guidance::GuidanceRoadSignpost RoadSignpost() const;
    hstring InstructionText() const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceMapMatchedCoordinate
{
    Windows::Devices::Geolocation::Geopoint Location() const;
    double CurrentHeading() const;
    double CurrentSpeed() const;
    bool IsOnStreet() const;
    Windows::Services::Maps::Guidance::GuidanceRoadSegment Road() const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceNavigator
{
    void StartNavigating(const Windows::Services::Maps::Guidance::GuidanceRoute & route) const;
    void StartSimulating(const Windows::Services::Maps::Guidance::GuidanceRoute & route, int32_t speedInMetersPerSecond) const;
    void StartTracking() const;
    void Pause() const;
    void Resume() const;
    void Stop() const;
    void RepeatLastAudioNotification() const;
    Windows::Services::Maps::Guidance::GuidanceAudioMeasurementSystem AudioMeasurementSystem() const;
    void AudioMeasurementSystem(Windows::Services::Maps::Guidance::GuidanceAudioMeasurementSystem value) const;
    Windows::Services::Maps::Guidance::GuidanceAudioNotifications AudioNotifications() const;
    void AudioNotifications(Windows::Services::Maps::Guidance::GuidanceAudioNotifications value) const;
    event_token GuidanceUpdated(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceUpdatedEventArgs> & handler) const;
    using GuidanceUpdated_revoker = event_revoker<IGuidanceNavigator>;
    GuidanceUpdated_revoker GuidanceUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceUpdatedEventArgs> & handler) const;
    void GuidanceUpdated(event_token token) const;
    event_token DestinationReached(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const;
    using DestinationReached_revoker = event_revoker<IGuidanceNavigator>;
    DestinationReached_revoker DestinationReached(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const;
    void DestinationReached(event_token token) const;
    event_token Rerouting(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const;
    using Rerouting_revoker = event_revoker<IGuidanceNavigator>;
    Rerouting_revoker Rerouting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const;
    void Rerouting(event_token token) const;
    event_token Rerouted(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceReroutedEventArgs> & handler) const;
    using Rerouted_revoker = event_revoker<IGuidanceNavigator>;
    Rerouted_revoker Rerouted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceReroutedEventArgs> & handler) const;
    void Rerouted(event_token token) const;
    event_token RerouteFailed(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const;
    using RerouteFailed_revoker = event_revoker<IGuidanceNavigator>;
    RerouteFailed_revoker RerouteFailed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const;
    void RerouteFailed(event_token token) const;
    event_token UserLocationLost(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const;
    using UserLocationLost_revoker = event_revoker<IGuidanceNavigator>;
    UserLocationLost_revoker UserLocationLost(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const;
    void UserLocationLost(event_token token) const;
    event_token UserLocationRestored(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const;
    using UserLocationRestored_revoker = event_revoker<IGuidanceNavigator>;
    UserLocationRestored_revoker UserLocationRestored(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Foundation::IInspectable> & handler) const;
    void UserLocationRestored(event_token token) const;
    void SetGuidanceVoice(int32_t voiceId, hstring_view voiceFolder) const;
    void UpdateUserLocation(const Windows::Devices::Geolocation::Geocoordinate & userLocation) const;
    void UpdateUserLocation(const Windows::Devices::Geolocation::Geocoordinate & userLocation, const Windows::Devices::Geolocation::BasicGeoposition & positionOverride) const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceNavigator2
{
    event_token AudioNotificationRequested(const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceAudioNotificationRequestedEventArgs> & value) const;
    using AudioNotificationRequested_revoker = event_revoker<IGuidanceNavigator2>;
    AudioNotificationRequested_revoker AudioNotificationRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Maps::Guidance::GuidanceNavigator, Windows::Services::Maps::Guidance::GuidanceAudioNotificationRequestedEventArgs> & value) const;
    void AudioNotificationRequested(event_token token) const;
    bool IsGuidanceAudioMuted() const;
    void IsGuidanceAudioMuted(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceNavigatorStatics
{
    Windows::Services::Maps::Guidance::GuidanceNavigator GetCurrent() const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceNavigatorStatics2
{
    bool UseAppProvidedVoice() const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceReroutedEventArgs
{
    Windows::Services::Maps::Guidance::GuidanceRoute Route() const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceRoadSegment
{
    hstring RoadName() const;
    hstring ShortRoadName() const;
    double SpeedLimit() const;
    Windows::Foundation::TimeSpan TravelTime() const;
    Windows::Devices::Geolocation::Geopath Path() const;
    hstring Id() const;
    bool IsHighway() const;
    bool IsTunnel() const;
    bool IsTollRoad() const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceRoadSignpost
{
    hstring ExitNumber() const;
    hstring Exit() const;
    Windows::UI::Color BackgroundColor() const;
    Windows::UI::Color ForegroundColor() const;
    Windows::Foundation::Collections::IVectorView<hstring> ExitDirections() const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceRoute
{
    Windows::Foundation::TimeSpan Duration() const;
    int32_t Distance() const;
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceManeuver> Maneuvers() const;
    Windows::Devices::Geolocation::GeoboundingBox BoundingBox() const;
    Windows::Devices::Geolocation::Geopath Path() const;
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceRoadSegment> RoadSegments() const;
    Windows::Services::Maps::MapRoute ConvertToMapRoute() const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceRouteStatics
{
    bool CanCreateFromMapRoute(const Windows::Services::Maps::MapRoute & mapRoute) const;
    Windows::Services::Maps::Guidance::GuidanceRoute TryCreateFromMapRoute(const Windows::Services::Maps::MapRoute & mapRoute) const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceTelemetryCollector
{
    bool Enabled() const;
    void Enabled(bool value) const;
    void ClearLocalData() const;
    double SpeedTrigger() const;
    void SpeedTrigger(double value) const;
    int32_t UploadFrequency() const;
    void UploadFrequency(int32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceTelemetryCollectorStatics
{
    Windows::Services::Maps::Guidance::GuidanceTelemetryCollector GetCurrent() const;
};

template <typename D>
struct WINRT_EBO impl_IGuidanceUpdatedEventArgs
{
    Windows::Services::Maps::Guidance::GuidanceMode Mode() const;
    Windows::Services::Maps::Guidance::GuidanceManeuver NextManeuver() const;
    int32_t NextManeuverDistance() const;
    Windows::Services::Maps::Guidance::GuidanceManeuver AfterNextManeuver() const;
    int32_t AfterNextManeuverDistance() const;
    int32_t DistanceToDestination() const;
    int32_t ElapsedDistance() const;
    Windows::Foundation::TimeSpan ElapsedTime() const;
    Windows::Foundation::TimeSpan TimeToDestination() const;
    hstring RoadName() const;
    Windows::Services::Maps::Guidance::GuidanceRoute Route() const;
    Windows::Services::Maps::Guidance::GuidanceMapMatchedCoordinate CurrentLocation() const;
    bool IsNewManeuver() const;
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::Guidance::GuidanceLaneInfo> LaneInfo() const;
};

}

namespace impl {

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceAudioNotificationRequestedEventArgs>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceAudioNotificationRequestedEventArgs;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceAudioNotificationRequestedEventArgs<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceLaneInfo>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceLaneInfo;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceLaneInfo<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceManeuver>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceManeuver<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceMapMatchedCoordinate<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceNavigator>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceNavigator<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceNavigator2>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator2;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceNavigator2<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceNavigatorStatics>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceNavigatorStatics;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceNavigatorStatics<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceNavigatorStatics2>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceNavigatorStatics2;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceNavigatorStatics2<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceReroutedEventArgs>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceReroutedEventArgs;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceReroutedEventArgs<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceRoadSegment>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSegment;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceRoadSegment<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceRoadSignpost>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSignpost;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceRoadSignpost<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceRoute>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceRoute;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceRoute<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceRouteStatics>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceRouteStatics;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceRouteStatics<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceTelemetryCollector<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceTelemetryCollectorStatics>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceTelemetryCollectorStatics;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceTelemetryCollectorStatics<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>
{
    using abi = ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs;
    template <typename D> using consume = Windows::Services::Maps::Guidance::impl_IGuidanceUpdatedEventArgs<D>;
};

template <> struct traits<Windows::Services::Maps::Guidance::GuidanceAudioNotificationRequestedEventArgs>
{
    using abi = ABI::Windows::Services::Maps::Guidance::GuidanceAudioNotificationRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.Guidance.GuidanceAudioNotificationRequestedEventArgs"; }
};

template <> struct traits<Windows::Services::Maps::Guidance::GuidanceLaneInfo>
{
    using abi = ABI::Windows::Services::Maps::Guidance::GuidanceLaneInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.Guidance.GuidanceLaneInfo"; }
};

template <> struct traits<Windows::Services::Maps::Guidance::GuidanceManeuver>
{
    using abi = ABI::Windows::Services::Maps::Guidance::GuidanceManeuver;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.Guidance.GuidanceManeuver"; }
};

template <> struct traits<Windows::Services::Maps::Guidance::GuidanceMapMatchedCoordinate>
{
    using abi = ABI::Windows::Services::Maps::Guidance::GuidanceMapMatchedCoordinate;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.Guidance.GuidanceMapMatchedCoordinate"; }
};

template <> struct traits<Windows::Services::Maps::Guidance::GuidanceNavigator>
{
    using abi = ABI::Windows::Services::Maps::Guidance::GuidanceNavigator;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.Guidance.GuidanceNavigator"; }
};

template <> struct traits<Windows::Services::Maps::Guidance::GuidanceReroutedEventArgs>
{
    using abi = ABI::Windows::Services::Maps::Guidance::GuidanceReroutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.Guidance.GuidanceReroutedEventArgs"; }
};

template <> struct traits<Windows::Services::Maps::Guidance::GuidanceRoadSegment>
{
    using abi = ABI::Windows::Services::Maps::Guidance::GuidanceRoadSegment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.Guidance.GuidanceRoadSegment"; }
};

template <> struct traits<Windows::Services::Maps::Guidance::GuidanceRoadSignpost>
{
    using abi = ABI::Windows::Services::Maps::Guidance::GuidanceRoadSignpost;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.Guidance.GuidanceRoadSignpost"; }
};

template <> struct traits<Windows::Services::Maps::Guidance::GuidanceRoute>
{
    using abi = ABI::Windows::Services::Maps::Guidance::GuidanceRoute;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.Guidance.GuidanceRoute"; }
};

template <> struct traits<Windows::Services::Maps::Guidance::GuidanceTelemetryCollector>
{
    using abi = ABI::Windows::Services::Maps::Guidance::GuidanceTelemetryCollector;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.Guidance.GuidanceTelemetryCollector"; }
};

template <> struct traits<Windows::Services::Maps::Guidance::GuidanceUpdatedEventArgs>
{
    using abi = ABI::Windows::Services::Maps::Guidance::GuidanceUpdatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.Guidance.GuidanceUpdatedEventArgs"; }
};

}

}
