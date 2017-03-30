// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Controls.Maps.0.h"
#include "Windows.Devices.Geolocation.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Services.Maps.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.UI.0.h"
#include "Windows.UI.Xaml.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Devices.Geolocation.1.h"
#include "Windows.Services.Maps.LocalSearch.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Controls::Maps {

struct MapZoomLevelRange
{
    double Min;
    double Max;
};

}

namespace Windows::UI::Xaml::Controls::Maps {

using MapZoomLevelRange = ABI::Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange;

}

namespace ABI::Windows::UI::Xaml::Controls::Maps {

struct __declspec(uuid("65da384a-2db1-4be1-b155-3d0c9ecf4799")) __declspec(novtable) ICustomMapTileDataSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_BitmapRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::CustomMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BitmapRequested(event_token token) = 0;
};

struct __declspec(uuid("c8477947-c955-4f22-9444-a1d8d744af11")) __declspec(novtable) ICustomMapTileDataSourceFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource ** instance) = 0;
};

struct __declspec(uuid("9d03cb5c-fd79-4795-87be-7e54ca0b37d0")) __declspec(novtable) IHttpMapTileDataSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UriFormatString(hstring * value) = 0;
    virtual HRESULT __stdcall put_UriFormatString(hstring value) = 0;
    virtual HRESULT __stdcall get_AdditionalRequestHeaders(Windows::Foundation::Collections::IMap<hstring, hstring> ** value) = 0;
    virtual HRESULT __stdcall get_AllowCaching(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowCaching(bool value) = 0;
    virtual HRESULT __stdcall add_UriRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UriRequested(event_token token) = 0;
};

struct __declspec(uuid("53b4b107-84dc-4291-89f8-6d0bb612a055")) __declspec(novtable) IHttpMapTileDataSourceFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateInstanceWithUriFormatString(hstring uriFormatString, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource ** instance) = 0;
};

struct __declspec(uuid("616257b5-9108-4f12-8bf4-bb3c8f6274e5")) __declspec(novtable) ILocalMapTileDataSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UriFormatString(hstring * value) = 0;
    virtual HRESULT __stdcall put_UriFormatString(hstring value) = 0;
    virtual HRESULT __stdcall add_UriRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UriRequested(event_token token) = 0;
};

struct __declspec(uuid("c5cfe9fc-72ac-4839-8a0d-011f24693c79")) __declspec(novtable) ILocalMapTileDataSourceFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateInstanceWithUriFormatString(hstring uriFormatString, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource ** instance) = 0;
};

struct __declspec(uuid("daa080da-b7f4-422c-a618-bbaa7c1d814c")) __declspec(novtable) IMapActualCameraChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Camera(Windows::UI::Xaml::Controls::Maps::IMapCamera ** value) = 0;
};

struct __declspec(uuid("7ba4c7e5-10dc-455a-9d04-1d72fb6d9b93")) __declspec(novtable) IMapActualCameraChangedEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ChangeReason(winrt::Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason * value) = 0;
};

struct __declspec(uuid("6b0dbed6-93f7-4682-8de5-a47a1cc7a945")) __declspec(novtable) IMapActualCameraChangingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Camera(Windows::UI::Xaml::Controls::Maps::IMapCamera ** value) = 0;
};

struct __declspec(uuid("f2867897-40ac-4e8a-a927-510f3846a47e")) __declspec(novtable) IMapActualCameraChangingEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ChangeReason(winrt::Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason * value) = 0;
};

struct __declspec(uuid("53a6b623-c0f8-4d8b-ad1e-a59598ea840b")) __declspec(novtable) IMapCamera : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Location(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall put_Location(Windows::Devices::Geolocation::IGeopoint * value) = 0;
    virtual HRESULT __stdcall get_Heading(double * value) = 0;
    virtual HRESULT __stdcall put_Heading(double value) = 0;
    virtual HRESULT __stdcall get_Pitch(double * value) = 0;
    virtual HRESULT __stdcall put_Pitch(double value) = 0;
    virtual HRESULT __stdcall get_Roll(double * value) = 0;
    virtual HRESULT __stdcall put_Roll(double value) = 0;
    virtual HRESULT __stdcall get_FieldOfView(double * value) = 0;
    virtual HRESULT __stdcall put_FieldOfView(double value) = 0;
};

struct __declspec(uuid("ea3b0f16-83af-4ace-8e71-10ad9f1e9e7f")) __declspec(novtable) IMapCameraFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithLocation(Windows::Devices::Geolocation::IGeopoint * location, Windows::UI::Xaml::Controls::Maps::IMapCamera ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateInstanceWithLocationAndHeading(Windows::Devices::Geolocation::IGeopoint * location, double headingInDegrees, Windows::UI::Xaml::Controls::Maps::IMapCamera ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateInstanceWithLocationHeadingAndPitch(Windows::Devices::Geolocation::IGeopoint * location, double headingInDegrees, double pitchInDegrees, Windows::UI::Xaml::Controls::Maps::IMapCamera ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateInstanceWithLocationHeadingPitchRollAndFieldOfView(Windows::Devices::Geolocation::IGeopoint * location, double headingInDegrees, double pitchInDegrees, double rollInDegrees, double fieldOfViewInDegrees, Windows::UI::Xaml::Controls::Maps::IMapCamera ** instance) = 0;
};

struct __declspec(uuid("42d0b851-5256-4747-9e6c-0d11e966141e")) __declspec(novtable) IMapControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Center(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall put_Center(Windows::Devices::Geolocation::IGeopoint * value) = 0;
    virtual HRESULT __stdcall get_Children(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> ** value) = 0;
    virtual HRESULT __stdcall get_ColorScheme(winrt::Windows::UI::Xaml::Controls::Maps::MapColorScheme * value) = 0;
    virtual HRESULT __stdcall put_ColorScheme(winrt::Windows::UI::Xaml::Controls::Maps::MapColorScheme value) = 0;
    virtual HRESULT __stdcall get_DesiredPitch(double * value) = 0;
    virtual HRESULT __stdcall put_DesiredPitch(double value) = 0;
    virtual HRESULT __stdcall get_Heading(double * value) = 0;
    virtual HRESULT __stdcall put_Heading(double value) = 0;
    virtual HRESULT __stdcall get_LandmarksVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_LandmarksVisible(bool value) = 0;
    virtual HRESULT __stdcall get_LoadingStatus(winrt::Windows::UI::Xaml::Controls::Maps::MapLoadingStatus * value) = 0;
    virtual HRESULT __stdcall get_MapServiceToken(hstring * value) = 0;
    virtual HRESULT __stdcall put_MapServiceToken(hstring value) = 0;
    virtual HRESULT __stdcall get_MaxZoomLevel(double * value) = 0;
    virtual HRESULT __stdcall get_MinZoomLevel(double * value) = 0;
    virtual HRESULT __stdcall get_PedestrianFeaturesVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_PedestrianFeaturesVisible(bool value) = 0;
    virtual HRESULT __stdcall get_Pitch(double * value) = 0;
    virtual HRESULT __stdcall get_Style(winrt::Windows::UI::Xaml::Controls::Maps::MapStyle * value) = 0;
    virtual HRESULT __stdcall put_Style(winrt::Windows::UI::Xaml::Controls::Maps::MapStyle value) = 0;
    virtual HRESULT __stdcall get_TrafficFlowVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_TrafficFlowVisible(bool value) = 0;
    virtual HRESULT __stdcall get_TransformOrigin(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_TransformOrigin(Windows::Foundation::Point value) = 0;
    virtual HRESULT __stdcall get_WatermarkMode(winrt::Windows::UI::Xaml::Controls::Maps::MapWatermarkMode * value) = 0;
    virtual HRESULT __stdcall put_WatermarkMode(winrt::Windows::UI::Xaml::Controls::Maps::MapWatermarkMode value) = 0;
    virtual HRESULT __stdcall get_ZoomLevel(double * value) = 0;
    virtual HRESULT __stdcall put_ZoomLevel(double value) = 0;
    virtual HRESULT __stdcall get_MapElements(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapElement> ** value) = 0;
    virtual HRESULT __stdcall get_Routes(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapRouteView> ** value) = 0;
    virtual HRESULT __stdcall get_TileSources(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapTileSource> ** value) = 0;
    virtual HRESULT __stdcall add_CenterChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CenterChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_HeadingChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_HeadingChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_LoadingStatusChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_LoadingStatusChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_MapDoubleTapped(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MapDoubleTapped(event_token token) = 0;
    virtual HRESULT __stdcall add_MapHolding(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MapHolding(event_token token) = 0;
    virtual HRESULT __stdcall add_MapTapped(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MapTapped(event_token token) = 0;
    virtual HRESULT __stdcall add_PitchChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PitchChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_TransformOriginChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TransformOriginChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ZoomLevelChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ZoomLevelChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_FindMapElementsAtOffset(Windows::Foundation::Point offset, Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Controls::Maps::MapElement> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetLocationFromOffset(Windows::Foundation::Point offset, Windows::Devices::Geolocation::IGeopoint ** location) = 0;
    virtual HRESULT __stdcall abi_GetOffsetFromLocation(Windows::Devices::Geolocation::IGeopoint * location, Windows::Foundation::Point * offset) = 0;
    virtual HRESULT __stdcall abi_IsLocationInView(Windows::Devices::Geolocation::IGeopoint * location, bool * isInView) = 0;
    virtual HRESULT __stdcall abi_TrySetViewBoundsAsync(Windows::Devices::Geolocation::IGeoboundingBox * bounds, Windows::Foundation::IReference<Windows::UI::Xaml::Thickness> * margin, winrt::Windows::UI::Xaml::Controls::Maps::MapAnimationKind animation, Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_TrySetViewWithCenterAsync(Windows::Devices::Geolocation::IGeopoint * center, Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_TrySetViewWithCenterAndZoomAsync(Windows::Devices::Geolocation::IGeopoint * center, Windows::Foundation::IReference<double> * zoomLevel, Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_TrySetViewWithCenterZoomHeadingAndPitchAsync(Windows::Devices::Geolocation::IGeopoint * center, Windows::Foundation::IReference<double> * zoomLevel, Windows::Foundation::IReference<double> * heading, Windows::Foundation::IReference<double> * desiredPitch, Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_TrySetViewWithCenterZoomHeadingPitchAndAnimationAsync(Windows::Devices::Geolocation::IGeopoint * center, Windows::Foundation::IReference<double> * zoomLevel, Windows::Foundation::IReference<double> * heading, Windows::Foundation::IReference<double> * desiredPitch, winrt::Windows::UI::Xaml::Controls::Maps::MapAnimationKind animation, Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
};

struct __declspec(uuid("e1fd644d-96ec-4065-b0f0-75281da3654d")) __declspec(novtable) IMapControl2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BusinessLandmarksVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_BusinessLandmarksVisible(bool value) = 0;
    virtual HRESULT __stdcall get_TransitFeaturesVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_TransitFeaturesVisible(bool value) = 0;
    virtual HRESULT __stdcall get_PanInteractionMode(winrt::Windows::UI::Xaml::Controls::Maps::MapPanInteractionMode * value) = 0;
    virtual HRESULT __stdcall put_PanInteractionMode(winrt::Windows::UI::Xaml::Controls::Maps::MapPanInteractionMode value) = 0;
    virtual HRESULT __stdcall get_RotateInteractionMode(winrt::Windows::UI::Xaml::Controls::Maps::MapInteractionMode * value) = 0;
    virtual HRESULT __stdcall put_RotateInteractionMode(winrt::Windows::UI::Xaml::Controls::Maps::MapInteractionMode value) = 0;
    virtual HRESULT __stdcall get_TiltInteractionMode(winrt::Windows::UI::Xaml::Controls::Maps::MapInteractionMode * value) = 0;
    virtual HRESULT __stdcall put_TiltInteractionMode(winrt::Windows::UI::Xaml::Controls::Maps::MapInteractionMode value) = 0;
    virtual HRESULT __stdcall get_ZoomInteractionMode(winrt::Windows::UI::Xaml::Controls::Maps::MapInteractionMode * value) = 0;
    virtual HRESULT __stdcall put_ZoomInteractionMode(winrt::Windows::UI::Xaml::Controls::Maps::MapInteractionMode value) = 0;
    virtual HRESULT __stdcall get_Is3DSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_IsStreetsideSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_Scene(Windows::UI::Xaml::Controls::Maps::IMapScene ** value) = 0;
    virtual HRESULT __stdcall put_Scene(Windows::UI::Xaml::Controls::Maps::IMapScene * value) = 0;
    virtual HRESULT __stdcall get_ActualCamera(Windows::UI::Xaml::Controls::Maps::IMapCamera ** value) = 0;
    virtual HRESULT __stdcall get_TargetCamera(Windows::UI::Xaml::Controls::Maps::IMapCamera ** value) = 0;
    virtual HRESULT __stdcall get_CustomExperience(Windows::UI::Xaml::Controls::Maps::IMapCustomExperience ** value) = 0;
    virtual HRESULT __stdcall put_CustomExperience(Windows::UI::Xaml::Controls::Maps::IMapCustomExperience * value) = 0;
    virtual HRESULT __stdcall add_MapElementClick(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementClickEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MapElementClick(event_token token) = 0;
    virtual HRESULT __stdcall add_MapElementPointerEntered(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementPointerEnteredEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MapElementPointerEntered(event_token token) = 0;
    virtual HRESULT __stdcall add_MapElementPointerExited(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementPointerExitedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MapElementPointerExited(event_token token) = 0;
    virtual HRESULT __stdcall add_ActualCameraChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapActualCameraChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ActualCameraChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ActualCameraChanging(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapActualCameraChangingEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ActualCameraChanging(event_token token) = 0;
    virtual HRESULT __stdcall add_TargetCameraChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TargetCameraChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_CustomExperienceChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapCustomExperienceChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CustomExperienceChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_StartContinuousRotate(double rateInDegreesPerSecond) = 0;
    virtual HRESULT __stdcall abi_StopContinuousRotate() = 0;
    virtual HRESULT __stdcall abi_StartContinuousTilt(double rateInDegreesPerSecond) = 0;
    virtual HRESULT __stdcall abi_StopContinuousTilt() = 0;
    virtual HRESULT __stdcall abi_StartContinuousZoom(double rateOfChangePerSecond) = 0;
    virtual HRESULT __stdcall abi_StopContinuousZoom() = 0;
    virtual HRESULT __stdcall abi_TryRotateAsync(double degrees, Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_TryRotateToAsync(double angleInDegrees, Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_TryTiltAsync(double degrees, Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_TryTiltToAsync(double angleInDegrees, Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_TryZoomInAsync(Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_TryZoomOutAsync(Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_TryZoomToAsync(double zoomLevel, Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_TrySetSceneAsync(Windows::UI::Xaml::Controls::Maps::IMapScene * scene, Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_TrySetSceneWithAnimationAsync(Windows::UI::Xaml::Controls::Maps::IMapScene * scene, winrt::Windows::UI::Xaml::Controls::Maps::MapAnimationKind animationKind, Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
};

struct __declspec(uuid("586328f8-8cdd-40ae-9338-af2a7be845e5")) __declspec(novtable) IMapControl3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_MapRightTapped(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapRightTappedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MapRightTapped(event_token token) = 0;
};

struct __declspec(uuid("068f132a-1817-466d-b7ce-419b3f8e248b")) __declspec(novtable) IMapControl4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BusinessLandmarksEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_BusinessLandmarksEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_TransitFeaturesEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_TransitFeaturesEnabled(bool value) = 0;
    virtual HRESULT __stdcall abi_GetVisibleRegion(winrt::Windows::UI::Xaml::Controls::Maps::MapVisibleRegionKind region, Windows::Devices::Geolocation::IGeopath ** returnValue) = 0;
};

struct __declspec(uuid("5e464922-4a1a-4797-beb7-5cf7754cb867")) __declspec(novtable) IMapControlBusinessLandmarkClickEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LocalLocations(Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> ** value) = 0;
};

struct __declspec(uuid("5e4081a6-ea98-4f95-8caf-5b42696ff504")) __declspec(novtable) IMapControlBusinessLandmarkPointerEnteredEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LocalLocations(Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> ** value) = 0;
};

struct __declspec(uuid("2bb52caf-f24a-46d0-b463-65f719731057")) __declspec(novtable) IMapControlBusinessLandmarkPointerExitedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LocalLocations(Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> ** value) = 0;
};

struct __declspec(uuid("59ab8ae7-f184-4ab1-b0b0-35c8bf0654b2")) __declspec(novtable) IMapControlBusinessLandmarkRightTappedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LocalLocations(Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> ** value) = 0;
};

struct __declspec(uuid("8bb0f09c-14ab-486c-9de5-5a5def0205a2")) __declspec(novtable) IMapControlDataHelper : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_BusinessLandmarkClick(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkClickEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BusinessLandmarkClick(event_token token) = 0;
    virtual HRESULT __stdcall add_TransitFeatureClick(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureClickEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TransitFeatureClick(event_token token) = 0;
    virtual HRESULT __stdcall add_BusinessLandmarkRightTapped(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkRightTappedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BusinessLandmarkRightTapped(event_token token) = 0;
    virtual HRESULT __stdcall add_TransitFeatureRightTapped(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureRightTappedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TransitFeatureRightTapped(event_token token) = 0;
};

struct __declspec(uuid("59ce429e-562f-4c21-a674-0f11decf0fb3")) __declspec(novtable) IMapControlDataHelper2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_BusinessLandmarkPointerEntered(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerEnteredEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BusinessLandmarkPointerEntered(event_token token) = 0;
    virtual HRESULT __stdcall add_TransitFeaturePointerEntered(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerEnteredEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TransitFeaturePointerEntered(event_token token) = 0;
    virtual HRESULT __stdcall add_BusinessLandmarkPointerExited(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerExitedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BusinessLandmarkPointerExited(event_token token) = 0;
    virtual HRESULT __stdcall add_TransitFeaturePointerExited(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerExitedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TransitFeaturePointerExited(event_token token) = 0;
};

struct __declspec(uuid("3b70aa8e-02ef-469c-bbaf-dc2158d4289b")) __declspec(novtable) IMapControlDataHelperFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::UI::Xaml::Controls::Maps::IMapControl * map, Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper ** instance) = 0;
};

struct __declspec(uuid("c2c61795-2147-4f0a-942a-5493a85de807")) __declspec(novtable) IMapControlStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CenterProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ChildrenProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ColorSchemeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DesiredPitchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeadingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LandmarksVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LoadingStatusProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MapServiceTokenProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PedestrianFeaturesVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PitchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TrafficFlowVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TransformOriginProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_WatermarkModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ZoomLevelProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MapElementsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RoutesProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TileSourcesProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LocationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetLocation(Windows::UI::Xaml::IDependencyObject * element, Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall abi_SetLocation(Windows::UI::Xaml::IDependencyObject * element, Windows::Devices::Geolocation::IGeopoint * value) = 0;
    virtual HRESULT __stdcall get_NormalizedAnchorPointProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetNormalizedAnchorPoint(Windows::UI::Xaml::IDependencyObject * element, Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall abi_SetNormalizedAnchorPoint(Windows::UI::Xaml::IDependencyObject * element, Windows::Foundation::Point value) = 0;
};

struct __declspec(uuid("04852b93-b446-4d31-9752-1ec69a5996ae")) __declspec(novtable) IMapControlStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BusinessLandmarksVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TransitFeaturesVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PanInteractionModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RotateInteractionModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TiltInteractionModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ZoomInteractionModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_Is3DSupportedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsStreetsideSupportedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SceneProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("fe785d97-5d13-4fa1-bf1d-84061768c183")) __declspec(novtable) IMapControlStatics4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BusinessLandmarksEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TransitFeaturesEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("76179969-b765-4622-b08a-3072745a4541")) __declspec(novtable) IMapControlTransitFeatureClickEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Location(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall get_TransitProperties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ** value) = 0;
};

struct __declspec(uuid("73911a4e-ec4f-479e-94a1-36e081d0d897")) __declspec(novtable) IMapControlTransitFeaturePointerEnteredEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Location(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall get_TransitProperties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ** value) = 0;
};

struct __declspec(uuid("6a11258d-448d-44e7-bc69-d13d497154e9")) __declspec(novtable) IMapControlTransitFeaturePointerExitedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Location(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall get_TransitProperties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ** value) = 0;
};

struct __declspec(uuid("aea1cc49-a729-4eae-a59a-3ec9a125a028")) __declspec(novtable) IMapControlTransitFeatureRightTappedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Location(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall get_TransitProperties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ** value) = 0;
};

struct __declspec(uuid("64592866-14a3-4e5f-8883-8e9c500eeede")) __declspec(novtable) IMapCustomExperience : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("b9e6fb9b-8fc1-4042-ac34-a61b38bb7514")) __declspec(novtable) IMapCustomExperienceChangedEventArgs : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("7a403fb5-a1b1-4e7f-921e-3e6b8d8ebed6")) __declspec(novtable) IMapCustomExperienceFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::Maps::IMapCustomExperience ** instance) = 0;
};

struct __declspec(uuid("d61fc4df-b245-47f2-9ac2-43c058b1c903")) __declspec(novtable) IMapElement : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ZIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall put_ZIndex(int32_t value) = 0;
    virtual HRESULT __stdcall get_Visible(bool * value) = 0;
    virtual HRESULT __stdcall put_Visible(bool value) = 0;
};

struct __declspec(uuid("6619f261-fba6-4964-a7ff-f1af63ab9cb0")) __declspec(novtable) IMapElement2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MapTabIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall put_MapTabIndex(int32_t value) = 0;
};

struct __declspec(uuid("40168a11-d080-4519-99a1-3149fb8999d0")) __declspec(novtable) IMapElementClickEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_Location(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall get_MapElements(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapElement> ** value) = 0;
};

struct __declspec(uuid("4a30d007-0bd6-47a5-860b-7e7cf5f0c573")) __declspec(novtable) IMapElementFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::Maps::IMapElement ** instance) = 0;
};

struct __declspec(uuid("ab85dd4e-91d7-4b31-8f0a-d390c7d3a2ef")) __declspec(novtable) IMapElementPointerEnteredEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_Location(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall get_MapElement(Windows::UI::Xaml::Controls::Maps::IMapElement ** value) = 0;
};

struct __declspec(uuid("c1a45af9-60c9-4679-9119-20abc75d931f")) __declspec(novtable) IMapElementPointerExitedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_Location(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall get_MapElement(Windows::UI::Xaml::Controls::Maps::IMapElement ** value) = 0;
};

struct __declspec(uuid("e8c71cf2-bfef-4b49-8e99-41b5e3789fd2")) __declspec(novtable) IMapElementStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ZIndexProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("9bf72f30-80fe-4f30-bcc1-fa894050f676")) __declspec(novtable) IMapElementStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MapTabIndexProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("d2096872-23d9-4a2b-8be0-69f3a85482ab")) __declspec(novtable) IMapIcon : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Location(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall put_Location(Windows::Devices::Geolocation::IGeopoint * value) = 0;
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_NormalizedAnchorPoint(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_NormalizedAnchorPoint(Windows::Foundation::Point value) = 0;
    virtual HRESULT __stdcall get_Image(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_Image(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
};

struct __declspec(uuid("611254b9-d8aa-4bbd-a316-badf06911d63")) __declspec(novtable) IMapIcon2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CollisionBehaviorDesired(winrt::Windows::UI::Xaml::Controls::Maps::MapElementCollisionBehavior * value) = 0;
    virtual HRESULT __stdcall put_CollisionBehaviorDesired(winrt::Windows::UI::Xaml::Controls::Maps::MapElementCollisionBehavior value) = 0;
};

struct __declspec(uuid("dcbc9e56-1190-4b5d-9e56-e5b6724aa328")) __declspec(novtable) IMapIconStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LocationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TitleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_NormalizedAnchorPointProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("ff4c306a-cf76-46ab-a12f-b603b986c696")) __declspec(novtable) IMapIconStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CollisionBehaviorDesiredProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("9fc503a0-a8a2-4394-92e9-2247764f2f49")) __declspec(novtable) IMapInputEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_Location(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
};

struct __declspec(uuid("94c2c4d3-b335-42c5-b660-e6a07ec3bddc")) __declspec(novtable) IMapItemsControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemsSource(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_ItemsSource(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_Items(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> ** value) = 0;
    virtual HRESULT __stdcall get_ItemTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_ItemTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
};

struct __declspec(uuid("33a859c7-789b-425c-8a0a-32385896cb4a")) __declspec(novtable) IMapItemsControlStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemsSourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("abda2285-4926-4c3a-a5f9-19df7f69db3d")) __declspec(novtable) IMapPolygon : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Path(Windows::Devices::Geolocation::IGeopath ** value) = 0;
    virtual HRESULT __stdcall put_Path(Windows::Devices::Geolocation::IGeopath * value) = 0;
    virtual HRESULT __stdcall get_StrokeColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_StrokeColor(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall get_StrokeThickness(double * value) = 0;
    virtual HRESULT __stdcall put_StrokeThickness(double value) = 0;
    virtual HRESULT __stdcall get_StrokeDashed(bool * value) = 0;
    virtual HRESULT __stdcall put_StrokeDashed(bool value) = 0;
    virtual HRESULT __stdcall get_FillColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_FillColor(Windows::UI::Color value) = 0;
};

struct __declspec(uuid("96c8a11e-636b-4018-9c2e-acc9122a01b2")) __declspec(novtable) IMapPolygon2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Paths(Windows::Foundation::Collections::IVector<Windows::Devices::Geolocation::Geopath> ** value) = 0;
};

struct __declspec(uuid("37f573be-097b-424c-87cc-2ee042fda6d2")) __declspec(novtable) IMapPolygonStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PathProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StrokeThicknessProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StrokeDashedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("fbad24a2-24df-4a86-8ffa-0f8f4d9ec17d")) __declspec(novtable) IMapPolyline : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Path(Windows::Devices::Geolocation::IGeopath ** value) = 0;
    virtual HRESULT __stdcall put_Path(Windows::Devices::Geolocation::IGeopath * value) = 0;
    virtual HRESULT __stdcall get_StrokeColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_StrokeColor(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall get_StrokeThickness(double * value) = 0;
    virtual HRESULT __stdcall put_StrokeThickness(double value) = 0;
    virtual HRESULT __stdcall get_StrokeDashed(bool * value) = 0;
    virtual HRESULT __stdcall put_StrokeDashed(bool value) = 0;
};

struct __declspec(uuid("61fde44b-1ddf-4303-b809-ec87f58ad065")) __declspec(novtable) IMapPolylineStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PathProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StrokeDashedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("20943171-6fe8-40a6-ad0e-297379b575a7")) __declspec(novtable) IMapRightTappedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall get_Location(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
};

struct __declspec(uuid("740eaec5-bacc-41e1-a67e-dd6513832049")) __declspec(novtable) IMapRouteView : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RouteColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_RouteColor(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall get_OutlineColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_OutlineColor(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall get_Route(Windows::Services::Maps::IMapRoute ** value) = 0;
};

struct __declspec(uuid("f083addf-0066-4628-82fe-ea78c23cec1e")) __declspec(novtable) IMapRouteViewFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithMapRoute(Windows::Services::Maps::IMapRoute * route, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::Maps::IMapRouteView ** instance) = 0;
};

struct __declspec(uuid("8bba10a9-50e7-482c-9789-c688b178ac24")) __declspec(novtable) IMapScene : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TargetCamera(Windows::UI::Xaml::Controls::Maps::IMapCamera ** value) = 0;
    virtual HRESULT __stdcall add_TargetCameraChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapScene, Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TargetCameraChanged(event_token token) = 0;
};

struct __declspec(uuid("03e4ad6c-86ec-44d9-9597-fb75b7deba0a")) __declspec(novtable) IMapSceneStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromBoundingBox(Windows::Devices::Geolocation::IGeoboundingBox * bounds, Windows::UI::Xaml::Controls::Maps::IMapScene ** returnValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromBoundingBoxWithHeadingAndPitch(Windows::Devices::Geolocation::IGeoboundingBox * bounds, double headingInDegrees, double pitchInDegrees, Windows::UI::Xaml::Controls::Maps::IMapScene ** returnValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromCamera(Windows::UI::Xaml::Controls::Maps::IMapCamera * camera, Windows::UI::Xaml::Controls::Maps::IMapScene ** returnValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromLocation(Windows::Devices::Geolocation::IGeopoint * location, Windows::UI::Xaml::Controls::Maps::IMapScene ** returnValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromLocationWithHeadingAndPitch(Windows::Devices::Geolocation::IGeopoint * location, double headingInDegrees, double pitchInDegrees, Windows::UI::Xaml::Controls::Maps::IMapScene ** returnValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromLocationAndRadius(Windows::Devices::Geolocation::IGeopoint * location, double radiusInMeters, Windows::UI::Xaml::Controls::Maps::IMapScene ** returnValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromLocationAndRadiusWithHeadingAndPitch(Windows::Devices::Geolocation::IGeopoint * location, double radiusInMeters, double headingInDegrees, double pitchInDegrees, Windows::UI::Xaml::Controls::Maps::IMapScene ** returnValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromLocations(Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint> * locations, Windows::UI::Xaml::Controls::Maps::IMapScene ** returnValue) = 0;
    virtual HRESULT __stdcall abi_CreateFromLocationsWithHeadingAndPitch(Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint> * locations, double headingInDegrees, double pitchInDegrees, Windows::UI::Xaml::Controls::Maps::IMapScene ** returnValue) = 0;
};

struct __declspec(uuid("dbf00472-e953-4fa8-97d0-ea86359057cf")) __declspec(novtable) IMapTargetCameraChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Camera(Windows::UI::Xaml::Controls::Maps::IMapCamera ** value) = 0;
};

struct __declspec(uuid("97c0b332-f2b6-460b-8d91-ac020a2383dd")) __declspec(novtable) IMapTargetCameraChangedEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ChangeReason(winrt::Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason * value) = 0;
};

struct __declspec(uuid("46733fbc-d89d-472b-b5f6-d7066b0584f4")) __declspec(novtable) IMapTileBitmapRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PixelData(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_PixelData(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestDeferral ** returnValue) = 0;
};

struct __declspec(uuid("fe370542-a4ac-4efa-9665-0490b0cafdd2")) __declspec(novtable) IMapTileBitmapRequestDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("337f691d-9b02-4aa2-8b1e-cc4d91719bf3")) __declspec(novtable) IMapTileBitmapRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_X(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Y(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ZoomLevel(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Request(Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequest ** value) = 0;
};

struct __declspec(uuid("c03d9f5e-be1f-4c69-9969-79467a513c38")) __declspec(novtable) IMapTileDataSource : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("a3920fbd-e446-4648-a74d-fd2c5d557c06")) __declspec(novtable) IMapTileDataSourceFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::Maps::IMapTileDataSource ** instance) = 0;
};

struct __declspec(uuid("88a76e4e-2fdf-4567-9255-1100519c8d62")) __declspec(novtable) IMapTileSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DataSource(Windows::UI::Xaml::Controls::Maps::IMapTileDataSource ** value) = 0;
    virtual HRESULT __stdcall put_DataSource(Windows::UI::Xaml::Controls::Maps::IMapTileDataSource * value) = 0;
    virtual HRESULT __stdcall get_Layer(winrt::Windows::UI::Xaml::Controls::Maps::MapTileLayer * value) = 0;
    virtual HRESULT __stdcall put_Layer(winrt::Windows::UI::Xaml::Controls::Maps::MapTileLayer value) = 0;
    virtual HRESULT __stdcall get_ZoomLevelRange(Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange * value) = 0;
    virtual HRESULT __stdcall put_ZoomLevelRange(Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange value) = 0;
    virtual HRESULT __stdcall get_Bounds(Windows::Devices::Geolocation::IGeoboundingBox ** value) = 0;
    virtual HRESULT __stdcall put_Bounds(Windows::Devices::Geolocation::IGeoboundingBox * value) = 0;
    virtual HRESULT __stdcall get_AllowOverstretch(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowOverstretch(bool value) = 0;
    virtual HRESULT __stdcall get_IsFadingEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsFadingEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsTransparencyEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTransparencyEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsRetryEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsRetryEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_ZIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall put_ZIndex(int32_t value) = 0;
    virtual HRESULT __stdcall get_TilePixelSize(int32_t * value) = 0;
    virtual HRESULT __stdcall put_TilePixelSize(int32_t value) = 0;
    virtual HRESULT __stdcall get_Visible(bool * value) = 0;
    virtual HRESULT __stdcall put_Visible(bool value) = 0;
};

struct __declspec(uuid("cd7f811f-77fa-482b-9d34-71d31d465c48")) __declspec(novtable) IMapTileSourceFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::Maps::IMapTileSource ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateInstanceWithDataSource(Windows::UI::Xaml::Controls::Maps::IMapTileDataSource * dataSource, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::Maps::IMapTileSource ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateInstanceWithDataSourceAndZoomRange(Windows::UI::Xaml::Controls::Maps::IMapTileDataSource * dataSource, Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange zoomLevelRange, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::Maps::IMapTileSource ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateInstanceWithDataSourceZoomRangeAndBounds(Windows::UI::Xaml::Controls::Maps::IMapTileDataSource * dataSource, Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange zoomLevelRange, Windows::Devices::Geolocation::IGeoboundingBox * bounds, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::Maps::IMapTileSource ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateInstanceWithDataSourceZoomRangeBoundsAndTileSize(Windows::UI::Xaml::Controls::Maps::IMapTileDataSource * dataSource, Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange zoomLevelRange, Windows::Devices::Geolocation::IGeoboundingBox * bounds, int32_t tileSizeInPixels, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::Maps::IMapTileSource ** instance) = 0;
};

struct __declspec(uuid("93fcc93c-7035-4603-99b1-e659921b6093")) __declspec(novtable) IMapTileSourceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DataSourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LayerProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ZoomLevelRangeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BoundsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AllowOverstretchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsFadingEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsTransparencyEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsRetryEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ZIndexProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TilePixelSizeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("17402335-3127-45b8-87a7-99f87d4e2745")) __declspec(novtable) IMapTileUriRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_Uri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestDeferral ** returnValue) = 0;
};

struct __declspec(uuid("c117ade0-bf3e-4c51-8faa-4b593cf68eb2")) __declspec(novtable) IMapTileUriRequestDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("d2147b43-1bbf-4b98-8dd3-b7834e407e0d")) __declspec(novtable) IMapTileUriRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_X(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Y(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ZoomLevel(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Request(Windows::UI::Xaml::Controls::Maps::IMapTileUriRequest ** value) = 0;
};

struct __declspec(uuid("a558aec9-e30c-46c8-8116-484691675558")) __declspec(novtable) IStreetsideExperience : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AddressTextVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_AddressTextVisible(bool value) = 0;
    virtual HRESULT __stdcall get_CursorVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_CursorVisible(bool value) = 0;
    virtual HRESULT __stdcall get_OverviewMapVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_OverviewMapVisible(bool value) = 0;
    virtual HRESULT __stdcall get_StreetLabelsVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_StreetLabelsVisible(bool value) = 0;
    virtual HRESULT __stdcall get_ExitButtonVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_ExitButtonVisible(bool value) = 0;
    virtual HRESULT __stdcall get_ZoomButtonsVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_ZoomButtonsVisible(bool value) = 0;
};

struct __declspec(uuid("7a5bcf3c-649e-4342-9995-68a6cf5961a7")) __declspec(novtable) IStreetsideExperienceFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithPanorama(Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama * panorama, Windows::UI::Xaml::Controls::Maps::IStreetsideExperience ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateInstanceWithPanoramaHeadingPitchAndFieldOfView(Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama * panorama, double headingInDegrees, double pitchInDegrees, double fieldOfViewInDegrees, Windows::UI::Xaml::Controls::Maps::IStreetsideExperience ** instance) = 0;
};

struct __declspec(uuid("6fe00fd8-ad60-4664-b539-b1069f16c5af")) __declspec(novtable) IStreetsidePanorama : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Location(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
};

struct __declspec(uuid("d3b47f69-54b3-4ec5-b2a0-4f8204576507")) __declspec(novtable) IStreetsidePanoramaStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindNearbyWithLocationAsync(Windows::Devices::Geolocation::IGeopoint * location, Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_FindNearbyWithLocationAndRadiusAsync(Windows::Devices::Geolocation::IGeopoint * location, double radiusInMeters, Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama> ** returnValue) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Controls::Maps::CustomMapTileDataSource> { using default_interface = Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource> { using default_interface = Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource> { using default_interface = Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapActualCameraChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapActualCameraChangingEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapCamera> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapCamera; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControl> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapControl; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkClickEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkClickEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerEnteredEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerEnteredEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerExitedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerExitedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkRightTappedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkRightTappedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlDataHelper> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureClickEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureClickEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerEnteredEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerEnteredEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerExitedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerExitedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureRightTappedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureRightTappedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapCustomExperience> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapCustomExperience; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapCustomExperienceChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapCustomExperienceChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapElement> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapElement; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapElementClickEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapElementClickEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapElementPointerEnteredEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapElementPointerEnteredEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapElementPointerExitedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapElementPointerExitedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapIcon> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapIcon; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapInputEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapItemsControl> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapItemsControl; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapPolygon> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapPolygon; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapPolyline> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapPolyline; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapRightTappedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapRightTappedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapRouteView> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapRouteView; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapScene> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapScene; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequest> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequest; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestDeferral> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestDeferral; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileDataSource> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapTileDataSource; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileSource> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapTileSource; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileUriRequest> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapTileUriRequest; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileUriRequestDeferral> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestDeferral; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::StreetsideExperience> { using default_interface = Windows::UI::Xaml::Controls::Maps::IStreetsideExperience; };
template <> struct traits<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama> { using default_interface = Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama; };

}

namespace Windows::UI::Xaml::Controls::Maps {

template <typename D>
struct WINRT_EBO impl_ICustomMapTileDataSource
{
    event_token BitmapRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::CustomMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestedEventArgs> & value) const;
    using BitmapRequested_revoker = event_revoker<ICustomMapTileDataSource>;
    BitmapRequested_revoker BitmapRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::CustomMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestedEventArgs> & value) const;
    void BitmapRequested(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ICustomMapTileDataSourceFactory
{
    Windows::UI::Xaml::Controls::Maps::CustomMapTileDataSource CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMapTileDataSource
{
    hstring UriFormatString() const;
    void UriFormatString(hstring_view value) const;
    Windows::Foundation::Collections::IMap<hstring, hstring> AdditionalRequestHeaders() const;
    bool AllowCaching() const;
    void AllowCaching(bool value) const;
    event_token UriRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs> & value) const;
    using UriRequested_revoker = event_revoker<IHttpMapTileDataSource>;
    UriRequested_revoker UriRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs> & value) const;
    void UriRequested(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpMapTileDataSourceFactory
{
    Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
    Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource CreateInstanceWithUriFormatString(hstring_view uriFormatString, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ILocalMapTileDataSource
{
    hstring UriFormatString() const;
    void UriFormatString(hstring_view value) const;
    event_token UriRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs> & value) const;
    using UriRequested_revoker = event_revoker<ILocalMapTileDataSource>;
    UriRequested_revoker UriRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs> & value) const;
    void UriRequested(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ILocalMapTileDataSourceFactory
{
    Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
    Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource CreateInstanceWithUriFormatString(hstring_view uriFormatString, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMapActualCameraChangedEventArgs
{
    Windows::UI::Xaml::Controls::Maps::MapCamera Camera() const;
};

template <typename D>
struct WINRT_EBO impl_IMapActualCameraChangedEventArgs2
{
    Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason ChangeReason() const;
};

template <typename D>
struct WINRT_EBO impl_IMapActualCameraChangingEventArgs
{
    Windows::UI::Xaml::Controls::Maps::MapCamera Camera() const;
};

template <typename D>
struct WINRT_EBO impl_IMapActualCameraChangingEventArgs2
{
    Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason ChangeReason() const;
};

template <typename D>
struct WINRT_EBO impl_IMapCamera
{
    Windows::Devices::Geolocation::Geopoint Location() const;
    void Location(const Windows::Devices::Geolocation::Geopoint & value) const;
    double Heading() const;
    void Heading(double value) const;
    double Pitch() const;
    void Pitch(double value) const;
    double Roll() const;
    void Roll(double value) const;
    double FieldOfView() const;
    void FieldOfView(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IMapCameraFactory
{
    Windows::UI::Xaml::Controls::Maps::MapCamera CreateInstanceWithLocation(const Windows::Devices::Geolocation::Geopoint & location) const;
    Windows::UI::Xaml::Controls::Maps::MapCamera CreateInstanceWithLocationAndHeading(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees) const;
    Windows::UI::Xaml::Controls::Maps::MapCamera CreateInstanceWithLocationHeadingAndPitch(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees, double pitchInDegrees) const;
    Windows::UI::Xaml::Controls::Maps::MapCamera CreateInstanceWithLocationHeadingPitchRollAndFieldOfView(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees, double pitchInDegrees, double rollInDegrees, double fieldOfViewInDegrees) const;
};

template <typename D>
struct WINRT_EBO impl_IMapControl
{
    Windows::Devices::Geolocation::Geopoint Center() const;
    void Center(const Windows::Devices::Geolocation::Geopoint & value) const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> Children() const;
    Windows::UI::Xaml::Controls::Maps::MapColorScheme ColorScheme() const;
    void ColorScheme(Windows::UI::Xaml::Controls::Maps::MapColorScheme value) const;
    double DesiredPitch() const;
    void DesiredPitch(double value) const;
    double Heading() const;
    void Heading(double value) const;
    bool LandmarksVisible() const;
    void LandmarksVisible(bool value) const;
    Windows::UI::Xaml::Controls::Maps::MapLoadingStatus LoadingStatus() const;
    hstring MapServiceToken() const;
    void MapServiceToken(hstring_view value) const;
    double MaxZoomLevel() const;
    double MinZoomLevel() const;
    bool PedestrianFeaturesVisible() const;
    void PedestrianFeaturesVisible(bool value) const;
    double Pitch() const;
    Windows::UI::Xaml::Controls::Maps::MapStyle Style() const;
    void Style(Windows::UI::Xaml::Controls::Maps::MapStyle value) const;
    bool TrafficFlowVisible() const;
    void TrafficFlowVisible(bool value) const;
    Windows::Foundation::Point TransformOrigin() const;
    void TransformOrigin(const Windows::Foundation::Point & value) const;
    Windows::UI::Xaml::Controls::Maps::MapWatermarkMode WatermarkMode() const;
    void WatermarkMode(Windows::UI::Xaml::Controls::Maps::MapWatermarkMode value) const;
    double ZoomLevel() const;
    void ZoomLevel(double value) const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapElement> MapElements() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapRouteView> Routes() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapTileSource> TileSources() const;
    event_token CenterChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const;
    using CenterChanged_revoker = event_revoker<IMapControl>;
    CenterChanged_revoker CenterChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const;
    void CenterChanged(event_token token) const;
    event_token HeadingChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const;
    using HeadingChanged_revoker = event_revoker<IMapControl>;
    HeadingChanged_revoker HeadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const;
    void HeadingChanged(event_token token) const;
    event_token LoadingStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const;
    using LoadingStatusChanged_revoker = event_revoker<IMapControl>;
    LoadingStatusChanged_revoker LoadingStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const;
    void LoadingStatusChanged(event_token token) const;
    event_token MapDoubleTapped(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> & value) const;
    using MapDoubleTapped_revoker = event_revoker<IMapControl>;
    MapDoubleTapped_revoker MapDoubleTapped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> & value) const;
    void MapDoubleTapped(event_token token) const;
    event_token MapHolding(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> & value) const;
    using MapHolding_revoker = event_revoker<IMapControl>;
    MapHolding_revoker MapHolding(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> & value) const;
    void MapHolding(event_token token) const;
    event_token MapTapped(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> & value) const;
    using MapTapped_revoker = event_revoker<IMapControl>;
    MapTapped_revoker MapTapped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> & value) const;
    void MapTapped(event_token token) const;
    event_token PitchChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const;
    using PitchChanged_revoker = event_revoker<IMapControl>;
    PitchChanged_revoker PitchChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const;
    void PitchChanged(event_token token) const;
    event_token TransformOriginChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const;
    using TransformOriginChanged_revoker = event_revoker<IMapControl>;
    TransformOriginChanged_revoker TransformOriginChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const;
    void TransformOriginChanged(event_token token) const;
    event_token ZoomLevelChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const;
    using ZoomLevelChanged_revoker = event_revoker<IMapControl>;
    ZoomLevelChanged_revoker ZoomLevelChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const;
    void ZoomLevelChanged(event_token token) const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Controls::Maps::MapElement> FindMapElementsAtOffset(const Windows::Foundation::Point & offset) const;
    void GetLocationFromOffset(const Windows::Foundation::Point & offset, Windows::Devices::Geolocation::Geopoint & location) const;
    void GetOffsetFromLocation(const Windows::Devices::Geolocation::Geopoint & location, Windows::Foundation::Point & offset) const;
    void IsLocationInView(const Windows::Devices::Geolocation::Geopoint & location, bool & isInView) const;
    Windows::Foundation::IAsyncOperation<bool> TrySetViewBoundsAsync(const Windows::Devices::Geolocation::GeoboundingBox & bounds, const optional<Windows::UI::Xaml::Thickness> & margin, Windows::UI::Xaml::Controls::Maps::MapAnimationKind animation) const;
    Windows::Foundation::IAsyncOperation<bool> TrySetViewAsync(const Windows::Devices::Geolocation::Geopoint & center) const;
    Windows::Foundation::IAsyncOperation<bool> TrySetViewAsync(const Windows::Devices::Geolocation::Geopoint & center, const optional<double> & zoomLevel) const;
    Windows::Foundation::IAsyncOperation<bool> TrySetViewAsync(const Windows::Devices::Geolocation::Geopoint & center, const optional<double> & zoomLevel, const optional<double> & heading, const optional<double> & desiredPitch) const;
    Windows::Foundation::IAsyncOperation<bool> TrySetViewAsync(const Windows::Devices::Geolocation::Geopoint & center, const optional<double> & zoomLevel, const optional<double> & heading, const optional<double> & desiredPitch, Windows::UI::Xaml::Controls::Maps::MapAnimationKind animation) const;
};

template <typename D>
struct WINRT_EBO impl_IMapControl2
{
    bool BusinessLandmarksVisible() const;
    void BusinessLandmarksVisible(bool value) const;
    bool TransitFeaturesVisible() const;
    void TransitFeaturesVisible(bool value) const;
    Windows::UI::Xaml::Controls::Maps::MapPanInteractionMode PanInteractionMode() const;
    void PanInteractionMode(Windows::UI::Xaml::Controls::Maps::MapPanInteractionMode value) const;
    Windows::UI::Xaml::Controls::Maps::MapInteractionMode RotateInteractionMode() const;
    void RotateInteractionMode(Windows::UI::Xaml::Controls::Maps::MapInteractionMode value) const;
    Windows::UI::Xaml::Controls::Maps::MapInteractionMode TiltInteractionMode() const;
    void TiltInteractionMode(Windows::UI::Xaml::Controls::Maps::MapInteractionMode value) const;
    Windows::UI::Xaml::Controls::Maps::MapInteractionMode ZoomInteractionMode() const;
    void ZoomInteractionMode(Windows::UI::Xaml::Controls::Maps::MapInteractionMode value) const;
    bool Is3DSupported() const;
    bool IsStreetsideSupported() const;
    Windows::UI::Xaml::Controls::Maps::MapScene Scene() const;
    void Scene(const Windows::UI::Xaml::Controls::Maps::MapScene & value) const;
    Windows::UI::Xaml::Controls::Maps::MapCamera ActualCamera() const;
    Windows::UI::Xaml::Controls::Maps::MapCamera TargetCamera() const;
    Windows::UI::Xaml::Controls::Maps::MapCustomExperience CustomExperience() const;
    void CustomExperience(const Windows::UI::Xaml::Controls::Maps::MapCustomExperience & value) const;
    event_token MapElementClick(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementClickEventArgs> & value) const;
    using MapElementClick_revoker = event_revoker<IMapControl2>;
    MapElementClick_revoker MapElementClick(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementClickEventArgs> & value) const;
    void MapElementClick(event_token token) const;
    event_token MapElementPointerEntered(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementPointerEnteredEventArgs> & value) const;
    using MapElementPointerEntered_revoker = event_revoker<IMapControl2>;
    MapElementPointerEntered_revoker MapElementPointerEntered(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementPointerEnteredEventArgs> & value) const;
    void MapElementPointerEntered(event_token token) const;
    event_token MapElementPointerExited(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementPointerExitedEventArgs> & value) const;
    using MapElementPointerExited_revoker = event_revoker<IMapControl2>;
    MapElementPointerExited_revoker MapElementPointerExited(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementPointerExitedEventArgs> & value) const;
    void MapElementPointerExited(event_token token) const;
    event_token ActualCameraChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapActualCameraChangedEventArgs> & value) const;
    using ActualCameraChanged_revoker = event_revoker<IMapControl2>;
    ActualCameraChanged_revoker ActualCameraChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapActualCameraChangedEventArgs> & value) const;
    void ActualCameraChanged(event_token token) const;
    event_token ActualCameraChanging(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapActualCameraChangingEventArgs> & value) const;
    using ActualCameraChanging_revoker = event_revoker<IMapControl2>;
    ActualCameraChanging_revoker ActualCameraChanging(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapActualCameraChangingEventArgs> & value) const;
    void ActualCameraChanging(event_token token) const;
    event_token TargetCameraChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs> & value) const;
    using TargetCameraChanged_revoker = event_revoker<IMapControl2>;
    TargetCameraChanged_revoker TargetCameraChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs> & value) const;
    void TargetCameraChanged(event_token token) const;
    event_token CustomExperienceChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapCustomExperienceChangedEventArgs> & value) const;
    using CustomExperienceChanged_revoker = event_revoker<IMapControl2>;
    CustomExperienceChanged_revoker CustomExperienceChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapCustomExperienceChangedEventArgs> & value) const;
    void CustomExperienceChanged(event_token token) const;
    void StartContinuousRotate(double rateInDegreesPerSecond) const;
    void StopContinuousRotate() const;
    void StartContinuousTilt(double rateInDegreesPerSecond) const;
    void StopContinuousTilt() const;
    void StartContinuousZoom(double rateOfChangePerSecond) const;
    void StopContinuousZoom() const;
    Windows::Foundation::IAsyncOperation<bool> TryRotateAsync(double degrees) const;
    Windows::Foundation::IAsyncOperation<bool> TryRotateToAsync(double angleInDegrees) const;
    Windows::Foundation::IAsyncOperation<bool> TryTiltAsync(double degrees) const;
    Windows::Foundation::IAsyncOperation<bool> TryTiltToAsync(double angleInDegrees) const;
    Windows::Foundation::IAsyncOperation<bool> TryZoomInAsync() const;
    Windows::Foundation::IAsyncOperation<bool> TryZoomOutAsync() const;
    Windows::Foundation::IAsyncOperation<bool> TryZoomToAsync(double zoomLevel) const;
    Windows::Foundation::IAsyncOperation<bool> TrySetSceneAsync(const Windows::UI::Xaml::Controls::Maps::MapScene & scene) const;
    Windows::Foundation::IAsyncOperation<bool> TrySetSceneAsync(const Windows::UI::Xaml::Controls::Maps::MapScene & scene, Windows::UI::Xaml::Controls::Maps::MapAnimationKind animationKind) const;
};

template <typename D>
struct WINRT_EBO impl_IMapControl3
{
    event_token MapRightTapped(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapRightTappedEventArgs> & value) const;
    using MapRightTapped_revoker = event_revoker<IMapControl3>;
    MapRightTapped_revoker MapRightTapped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapRightTappedEventArgs> & value) const;
    void MapRightTapped(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IMapControl4
{
    bool BusinessLandmarksEnabled() const;
    void BusinessLandmarksEnabled(bool value) const;
    bool TransitFeaturesEnabled() const;
    void TransitFeaturesEnabled(bool value) const;
    Windows::Devices::Geolocation::Geopath GetVisibleRegion(Windows::UI::Xaml::Controls::Maps::MapVisibleRegionKind region) const;
};

template <typename D>
struct WINRT_EBO impl_IMapControlBusinessLandmarkClickEventArgs
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> LocalLocations() const;
};

template <typename D>
struct WINRT_EBO impl_IMapControlBusinessLandmarkPointerEnteredEventArgs
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> LocalLocations() const;
};

template <typename D>
struct WINRT_EBO impl_IMapControlBusinessLandmarkPointerExitedEventArgs
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> LocalLocations() const;
};

template <typename D>
struct WINRT_EBO impl_IMapControlBusinessLandmarkRightTappedEventArgs
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> LocalLocations() const;
};

template <typename D>
struct WINRT_EBO impl_IMapControlDataHelper
{
    event_token BusinessLandmarkClick(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkClickEventArgs> & value) const;
    using BusinessLandmarkClick_revoker = event_revoker<IMapControlDataHelper>;
    BusinessLandmarkClick_revoker BusinessLandmarkClick(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkClickEventArgs> & value) const;
    void BusinessLandmarkClick(event_token token) const;
    event_token TransitFeatureClick(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureClickEventArgs> & value) const;
    using TransitFeatureClick_revoker = event_revoker<IMapControlDataHelper>;
    TransitFeatureClick_revoker TransitFeatureClick(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureClickEventArgs> & value) const;
    void TransitFeatureClick(event_token token) const;
    event_token BusinessLandmarkRightTapped(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkRightTappedEventArgs> & value) const;
    using BusinessLandmarkRightTapped_revoker = event_revoker<IMapControlDataHelper>;
    BusinessLandmarkRightTapped_revoker BusinessLandmarkRightTapped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkRightTappedEventArgs> & value) const;
    void BusinessLandmarkRightTapped(event_token token) const;
    event_token TransitFeatureRightTapped(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureRightTappedEventArgs> & value) const;
    using TransitFeatureRightTapped_revoker = event_revoker<IMapControlDataHelper>;
    TransitFeatureRightTapped_revoker TransitFeatureRightTapped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureRightTappedEventArgs> & value) const;
    void TransitFeatureRightTapped(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IMapControlDataHelper2
{
    event_token BusinessLandmarkPointerEntered(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerEnteredEventArgs> & value) const;
    using BusinessLandmarkPointerEntered_revoker = event_revoker<IMapControlDataHelper2>;
    BusinessLandmarkPointerEntered_revoker BusinessLandmarkPointerEntered(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerEnteredEventArgs> & value) const;
    void BusinessLandmarkPointerEntered(event_token token) const;
    event_token TransitFeaturePointerEntered(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerEnteredEventArgs> & value) const;
    using TransitFeaturePointerEntered_revoker = event_revoker<IMapControlDataHelper2>;
    TransitFeaturePointerEntered_revoker TransitFeaturePointerEntered(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerEnteredEventArgs> & value) const;
    void TransitFeaturePointerEntered(event_token token) const;
    event_token BusinessLandmarkPointerExited(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerExitedEventArgs> & value) const;
    using BusinessLandmarkPointerExited_revoker = event_revoker<IMapControlDataHelper2>;
    BusinessLandmarkPointerExited_revoker BusinessLandmarkPointerExited(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerExitedEventArgs> & value) const;
    void BusinessLandmarkPointerExited(event_token token) const;
    event_token TransitFeaturePointerExited(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerExitedEventArgs> & value) const;
    using TransitFeaturePointerExited_revoker = event_revoker<IMapControlDataHelper2>;
    TransitFeaturePointerExited_revoker TransitFeaturePointerExited(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerExitedEventArgs> & value) const;
    void TransitFeaturePointerExited(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IMapControlDataHelperFactory
{
    Windows::UI::Xaml::Controls::Maps::MapControlDataHelper CreateInstance(const Windows::UI::Xaml::Controls::Maps::MapControl & map) const;
};

template <typename D>
struct WINRT_EBO impl_IMapControlStatics
{
    Windows::UI::Xaml::DependencyProperty CenterProperty() const;
    Windows::UI::Xaml::DependencyProperty ChildrenProperty() const;
    Windows::UI::Xaml::DependencyProperty ColorSchemeProperty() const;
    Windows::UI::Xaml::DependencyProperty DesiredPitchProperty() const;
    Windows::UI::Xaml::DependencyProperty HeadingProperty() const;
    Windows::UI::Xaml::DependencyProperty LandmarksVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty LoadingStatusProperty() const;
    Windows::UI::Xaml::DependencyProperty MapServiceTokenProperty() const;
    Windows::UI::Xaml::DependencyProperty PedestrianFeaturesVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty PitchProperty() const;
    Windows::UI::Xaml::DependencyProperty StyleProperty() const;
    Windows::UI::Xaml::DependencyProperty TrafficFlowVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty TransformOriginProperty() const;
    Windows::UI::Xaml::DependencyProperty WatermarkModeProperty() const;
    Windows::UI::Xaml::DependencyProperty ZoomLevelProperty() const;
    Windows::UI::Xaml::DependencyProperty MapElementsProperty() const;
    Windows::UI::Xaml::DependencyProperty RoutesProperty() const;
    Windows::UI::Xaml::DependencyProperty TileSourcesProperty() const;
    Windows::UI::Xaml::DependencyProperty LocationProperty() const;
    Windows::Devices::Geolocation::Geopoint GetLocation(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetLocation(const Windows::UI::Xaml::DependencyObject & element, const Windows::Devices::Geolocation::Geopoint & value) const;
    Windows::UI::Xaml::DependencyProperty NormalizedAnchorPointProperty() const;
    Windows::Foundation::Point GetNormalizedAnchorPoint(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetNormalizedAnchorPoint(const Windows::UI::Xaml::DependencyObject & element, const Windows::Foundation::Point & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMapControlStatics2
{
    Windows::UI::Xaml::DependencyProperty BusinessLandmarksVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty TransitFeaturesVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty PanInteractionModeProperty() const;
    Windows::UI::Xaml::DependencyProperty RotateInteractionModeProperty() const;
    Windows::UI::Xaml::DependencyProperty TiltInteractionModeProperty() const;
    Windows::UI::Xaml::DependencyProperty ZoomInteractionModeProperty() const;
    Windows::UI::Xaml::DependencyProperty Is3DSupportedProperty() const;
    Windows::UI::Xaml::DependencyProperty IsStreetsideSupportedProperty() const;
    Windows::UI::Xaml::DependencyProperty SceneProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMapControlStatics4
{
    Windows::UI::Xaml::DependencyProperty BusinessLandmarksEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty TransitFeaturesEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMapControlTransitFeatureClickEventArgs
{
    hstring DisplayName() const;
    Windows::Devices::Geolocation::Geopoint Location() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> TransitProperties() const;
};

template <typename D>
struct WINRT_EBO impl_IMapControlTransitFeaturePointerEnteredEventArgs
{
    hstring DisplayName() const;
    Windows::Devices::Geolocation::Geopoint Location() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> TransitProperties() const;
};

template <typename D>
struct WINRT_EBO impl_IMapControlTransitFeaturePointerExitedEventArgs
{
    hstring DisplayName() const;
    Windows::Devices::Geolocation::Geopoint Location() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> TransitProperties() const;
};

template <typename D>
struct WINRT_EBO impl_IMapControlTransitFeatureRightTappedEventArgs
{
    hstring DisplayName() const;
    Windows::Devices::Geolocation::Geopoint Location() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> TransitProperties() const;
};

template <typename D>
struct WINRT_EBO impl_IMapCustomExperience
{
};

template <typename D>
struct WINRT_EBO impl_IMapCustomExperienceChangedEventArgs
{
};

template <typename D>
struct WINRT_EBO impl_IMapCustomExperienceFactory
{
    Windows::UI::Xaml::Controls::Maps::MapCustomExperience CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMapElement
{
    int32_t ZIndex() const;
    void ZIndex(int32_t value) const;
    bool Visible() const;
    void Visible(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IMapElement2
{
    int32_t MapTabIndex() const;
    void MapTabIndex(int32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IMapElementClickEventArgs
{
    Windows::Foundation::Point Position() const;
    Windows::Devices::Geolocation::Geopoint Location() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapElement> MapElements() const;
};

template <typename D>
struct WINRT_EBO impl_IMapElementFactory
{
    Windows::UI::Xaml::Controls::Maps::MapElement CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMapElementPointerEnteredEventArgs
{
    Windows::Foundation::Point Position() const;
    Windows::Devices::Geolocation::Geopoint Location() const;
    Windows::UI::Xaml::Controls::Maps::MapElement MapElement() const;
};

template <typename D>
struct WINRT_EBO impl_IMapElementPointerExitedEventArgs
{
    Windows::Foundation::Point Position() const;
    Windows::Devices::Geolocation::Geopoint Location() const;
    Windows::UI::Xaml::Controls::Maps::MapElement MapElement() const;
};

template <typename D>
struct WINRT_EBO impl_IMapElementStatics
{
    Windows::UI::Xaml::DependencyProperty ZIndexProperty() const;
    Windows::UI::Xaml::DependencyProperty VisibleProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMapElementStatics2
{
    Windows::UI::Xaml::DependencyProperty MapTabIndexProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMapIcon
{
    Windows::Devices::Geolocation::Geopoint Location() const;
    void Location(const Windows::Devices::Geolocation::Geopoint & value) const;
    hstring Title() const;
    void Title(hstring_view value) const;
    Windows::Foundation::Point NormalizedAnchorPoint() const;
    void NormalizedAnchorPoint(const Windows::Foundation::Point & value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference Image() const;
    void Image(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMapIcon2
{
    Windows::UI::Xaml::Controls::Maps::MapElementCollisionBehavior CollisionBehaviorDesired() const;
    void CollisionBehaviorDesired(Windows::UI::Xaml::Controls::Maps::MapElementCollisionBehavior value) const;
};

template <typename D>
struct WINRT_EBO impl_IMapIconStatics
{
    Windows::UI::Xaml::DependencyProperty LocationProperty() const;
    Windows::UI::Xaml::DependencyProperty TitleProperty() const;
    Windows::UI::Xaml::DependencyProperty NormalizedAnchorPointProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMapIconStatics2
{
    Windows::UI::Xaml::DependencyProperty CollisionBehaviorDesiredProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMapInputEventArgs
{
    Windows::Foundation::Point Position() const;
    Windows::Devices::Geolocation::Geopoint Location() const;
};

template <typename D>
struct WINRT_EBO impl_IMapItemsControl
{
    Windows::Foundation::IInspectable ItemsSource() const;
    void ItemsSource(const Windows::Foundation::IInspectable & value) const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> Items() const;
    Windows::UI::Xaml::DataTemplate ItemTemplate() const;
    void ItemTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMapItemsControlStatics
{
    Windows::UI::Xaml::DependencyProperty ItemsSourceProperty() const;
    Windows::UI::Xaml::DependencyProperty ItemsProperty() const;
    Windows::UI::Xaml::DependencyProperty ItemTemplateProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMapPolygon
{
    Windows::Devices::Geolocation::Geopath Path() const;
    void Path(const Windows::Devices::Geolocation::Geopath & value) const;
    Windows::UI::Color StrokeColor() const;
    void StrokeColor(const Windows::UI::Color & value) const;
    double StrokeThickness() const;
    void StrokeThickness(double value) const;
    bool StrokeDashed() const;
    void StrokeDashed(bool value) const;
    Windows::UI::Color FillColor() const;
    void FillColor(const Windows::UI::Color & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMapPolygon2
{
    Windows::Foundation::Collections::IVector<Windows::Devices::Geolocation::Geopath> Paths() const;
};

template <typename D>
struct WINRT_EBO impl_IMapPolygonStatics
{
    Windows::UI::Xaml::DependencyProperty PathProperty() const;
    Windows::UI::Xaml::DependencyProperty StrokeThicknessProperty() const;
    Windows::UI::Xaml::DependencyProperty StrokeDashedProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMapPolyline
{
    Windows::Devices::Geolocation::Geopath Path() const;
    void Path(const Windows::Devices::Geolocation::Geopath & value) const;
    Windows::UI::Color StrokeColor() const;
    void StrokeColor(const Windows::UI::Color & value) const;
    double StrokeThickness() const;
    void StrokeThickness(double value) const;
    bool StrokeDashed() const;
    void StrokeDashed(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IMapPolylineStatics
{
    Windows::UI::Xaml::DependencyProperty PathProperty() const;
    Windows::UI::Xaml::DependencyProperty StrokeDashedProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMapRightTappedEventArgs
{
    Windows::Foundation::Point Position() const;
    Windows::Devices::Geolocation::Geopoint Location() const;
};

template <typename D>
struct WINRT_EBO impl_IMapRouteView
{
    Windows::UI::Color RouteColor() const;
    void RouteColor(const Windows::UI::Color & value) const;
    Windows::UI::Color OutlineColor() const;
    void OutlineColor(const Windows::UI::Color & value) const;
    Windows::Services::Maps::MapRoute Route() const;
};

template <typename D>
struct WINRT_EBO impl_IMapRouteViewFactory
{
    Windows::UI::Xaml::Controls::Maps::MapRouteView CreateInstanceWithMapRoute(const Windows::Services::Maps::MapRoute & route, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMapScene
{
    Windows::UI::Xaml::Controls::Maps::MapCamera TargetCamera() const;
    event_token TargetCameraChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapScene, Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs> & value) const;
    using TargetCameraChanged_revoker = event_revoker<IMapScene>;
    TargetCameraChanged_revoker TargetCameraChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapScene, Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs> & value) const;
    void TargetCameraChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IMapSceneStatics
{
    Windows::UI::Xaml::Controls::Maps::MapScene CreateFromBoundingBox(const Windows::Devices::Geolocation::GeoboundingBox & bounds) const;
    Windows::UI::Xaml::Controls::Maps::MapScene CreateFromBoundingBox(const Windows::Devices::Geolocation::GeoboundingBox & bounds, double headingInDegrees, double pitchInDegrees) const;
    Windows::UI::Xaml::Controls::Maps::MapScene CreateFromCamera(const Windows::UI::Xaml::Controls::Maps::MapCamera & camera) const;
    Windows::UI::Xaml::Controls::Maps::MapScene CreateFromLocation(const Windows::Devices::Geolocation::Geopoint & location) const;
    Windows::UI::Xaml::Controls::Maps::MapScene CreateFromLocation(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees, double pitchInDegrees) const;
    Windows::UI::Xaml::Controls::Maps::MapScene CreateFromLocationAndRadius(const Windows::Devices::Geolocation::Geopoint & location, double radiusInMeters) const;
    Windows::UI::Xaml::Controls::Maps::MapScene CreateFromLocationAndRadius(const Windows::Devices::Geolocation::Geopoint & location, double radiusInMeters, double headingInDegrees, double pitchInDegrees) const;
    Windows::UI::Xaml::Controls::Maps::MapScene CreateFromLocations(iterable<Windows::Devices::Geolocation::Geopoint> locations) const;
    Windows::UI::Xaml::Controls::Maps::MapScene CreateFromLocations(iterable<Windows::Devices::Geolocation::Geopoint> locations, double headingInDegrees, double pitchInDegrees) const;
};

template <typename D>
struct WINRT_EBO impl_IMapTargetCameraChangedEventArgs
{
    Windows::UI::Xaml::Controls::Maps::MapCamera Camera() const;
};

template <typename D>
struct WINRT_EBO impl_IMapTargetCameraChangedEventArgs2
{
    Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason ChangeReason() const;
};

template <typename D>
struct WINRT_EBO impl_IMapTileBitmapRequest
{
    Windows::Storage::Streams::IRandomAccessStreamReference PixelData() const;
    void PixelData(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IMapTileBitmapRequestDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IMapTileBitmapRequestedEventArgs
{
    int32_t X() const;
    int32_t Y() const;
    int32_t ZoomLevel() const;
    Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequest Request() const;
};

template <typename D>
struct WINRT_EBO impl_IMapTileDataSource
{
};

template <typename D>
struct WINRT_EBO impl_IMapTileDataSourceFactory
{
    Windows::UI::Xaml::Controls::Maps::MapTileDataSource CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMapTileSource
{
    Windows::UI::Xaml::Controls::Maps::MapTileDataSource DataSource() const;
    void DataSource(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & value) const;
    Windows::UI::Xaml::Controls::Maps::MapTileLayer Layer() const;
    void Layer(Windows::UI::Xaml::Controls::Maps::MapTileLayer value) const;
    Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange ZoomLevelRange() const;
    void ZoomLevelRange(const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & value) const;
    Windows::Devices::Geolocation::GeoboundingBox Bounds() const;
    void Bounds(const Windows::Devices::Geolocation::GeoboundingBox & value) const;
    bool AllowOverstretch() const;
    void AllowOverstretch(bool value) const;
    bool IsFadingEnabled() const;
    void IsFadingEnabled(bool value) const;
    bool IsTransparencyEnabled() const;
    void IsTransparencyEnabled(bool value) const;
    bool IsRetryEnabled() const;
    void IsRetryEnabled(bool value) const;
    int32_t ZIndex() const;
    void ZIndex(int32_t value) const;
    int32_t TilePixelSize() const;
    void TilePixelSize(int32_t value) const;
    bool Visible() const;
    void Visible(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IMapTileSourceFactory
{
    Windows::UI::Xaml::Controls::Maps::MapTileSource CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
    Windows::UI::Xaml::Controls::Maps::MapTileSource CreateInstanceWithDataSource(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
    Windows::UI::Xaml::Controls::Maps::MapTileSource CreateInstanceWithDataSourceAndZoomRange(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
    Windows::UI::Xaml::Controls::Maps::MapTileSource CreateInstanceWithDataSourceZoomRangeAndBounds(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange, const Windows::Devices::Geolocation::GeoboundingBox & bounds, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
    Windows::UI::Xaml::Controls::Maps::MapTileSource CreateInstanceWithDataSourceZoomRangeBoundsAndTileSize(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange, const Windows::Devices::Geolocation::GeoboundingBox & bounds, int32_t tileSizeInPixels, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMapTileSourceStatics
{
    Windows::UI::Xaml::DependencyProperty DataSourceProperty() const;
    Windows::UI::Xaml::DependencyProperty LayerProperty() const;
    Windows::UI::Xaml::DependencyProperty ZoomLevelRangeProperty() const;
    Windows::UI::Xaml::DependencyProperty BoundsProperty() const;
    Windows::UI::Xaml::DependencyProperty AllowOverstretchProperty() const;
    Windows::UI::Xaml::DependencyProperty IsFadingEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsTransparencyEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsRetryEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty ZIndexProperty() const;
    Windows::UI::Xaml::DependencyProperty TilePixelSizeProperty() const;
    Windows::UI::Xaml::DependencyProperty VisibleProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMapTileUriRequest
{
    Windows::Foundation::Uri Uri() const;
    void Uri(const Windows::Foundation::Uri & value) const;
    Windows::UI::Xaml::Controls::Maps::MapTileUriRequestDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IMapTileUriRequestDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IMapTileUriRequestedEventArgs
{
    int32_t X() const;
    int32_t Y() const;
    int32_t ZoomLevel() const;
    Windows::UI::Xaml::Controls::Maps::MapTileUriRequest Request() const;
};

template <typename D>
struct WINRT_EBO impl_IStreetsideExperience
{
    bool AddressTextVisible() const;
    void AddressTextVisible(bool value) const;
    bool CursorVisible() const;
    void CursorVisible(bool value) const;
    bool OverviewMapVisible() const;
    void OverviewMapVisible(bool value) const;
    bool StreetLabelsVisible() const;
    void StreetLabelsVisible(bool value) const;
    bool ExitButtonVisible() const;
    void ExitButtonVisible(bool value) const;
    bool ZoomButtonsVisible() const;
    void ZoomButtonsVisible(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IStreetsideExperienceFactory
{
    Windows::UI::Xaml::Controls::Maps::StreetsideExperience CreateInstanceWithPanorama(const Windows::UI::Xaml::Controls::Maps::StreetsidePanorama & panorama) const;
    Windows::UI::Xaml::Controls::Maps::StreetsideExperience CreateInstanceWithPanoramaHeadingPitchAndFieldOfView(const Windows::UI::Xaml::Controls::Maps::StreetsidePanorama & panorama, double headingInDegrees, double pitchInDegrees, double fieldOfViewInDegrees) const;
};

template <typename D>
struct WINRT_EBO impl_IStreetsidePanorama
{
    Windows::Devices::Geolocation::Geopoint Location() const;
};

template <typename D>
struct WINRT_EBO impl_IStreetsidePanoramaStatics
{
    Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama> FindNearbyAsync(const Windows::Devices::Geolocation::Geopoint & location) const;
    Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama> FindNearbyAsync(const Windows::Devices::Geolocation::Geopoint & location, double radiusInMeters) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_ICustomMapTileDataSource<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSourceFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSourceFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_ICustomMapTileDataSourceFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IHttpMapTileDataSource<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSourceFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSourceFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IHttpMapTileDataSourceFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_ILocalMapTileDataSource<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSourceFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSourceFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_ILocalMapTileDataSourceFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapActualCameraChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapActualCameraChangedEventArgs2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapActualCameraChangingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapActualCameraChangingEventArgs2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapCamera>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapCamera;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapCamera<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapCameraFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapCameraFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapCameraFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControl>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControl;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControl<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControl2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControl2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControl3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControl3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControl3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControl4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControl4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControl4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkClickEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkClickEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControlBusinessLandmarkClickEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerEnteredEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerEnteredEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControlBusinessLandmarkPointerEnteredEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerExitedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerExitedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControlBusinessLandmarkPointerExitedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkRightTappedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkRightTappedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControlBusinessLandmarkRightTappedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControlDataHelper<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControlDataHelper2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControlDataHelperFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelperFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControlDataHelperFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControlStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControlStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControlStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControlStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControlStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControlStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControlStatics4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControlStatics4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControlStatics4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureClickEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureClickEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControlTransitFeatureClickEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerEnteredEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerEnteredEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControlTransitFeaturePointerEnteredEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerExitedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerExitedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControlTransitFeaturePointerExitedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureRightTappedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureRightTappedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapControlTransitFeatureRightTappedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapCustomExperience>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapCustomExperience;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapCustomExperience<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapCustomExperienceChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapCustomExperienceChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapCustomExperienceChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapCustomExperienceFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapCustomExperienceFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapCustomExperienceFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapElement>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapElement;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapElement<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapElement2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapElement2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapElement2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapElementClickEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapElementClickEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapElementClickEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapElementFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapElementFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapElementFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapElementPointerEnteredEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapElementPointerEnteredEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapElementPointerEnteredEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapElementPointerExitedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapElementPointerExitedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapElementPointerExitedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapElementStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapElementStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapElementStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapElementStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapElementStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapElementStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapIcon>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapIcon;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapIcon<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapIcon2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapIcon2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapIcon2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapIconStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapIconStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapIconStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapIconStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapIconStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapIconStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapInputEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapInputEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapInputEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapItemsControl>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapItemsControl;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapItemsControl<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapItemsControlStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapItemsControlStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapItemsControlStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapPolygon>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygon;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapPolygon<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapPolygon2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygon2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapPolygon2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapPolygonStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapPolygonStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapPolygonStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapPolyline>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapPolyline;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapPolyline<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapPolylineStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapPolylineStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapPolylineStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapRightTappedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapRightTappedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapRightTappedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapRouteView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapRouteView;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapRouteView<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapRouteViewFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapRouteViewFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapRouteViewFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapScene>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapScene;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapScene<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapSceneStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapSceneStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapSceneStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapTargetCameraChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapTargetCameraChangedEventArgs2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequest>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequest;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapTileBitmapRequest<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestDeferral>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestDeferral;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapTileBitmapRequestDeferral<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapTileBitmapRequestedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapTileDataSource>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapTileDataSource;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapTileDataSource<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapTileDataSourceFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapTileDataSourceFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapTileDataSourceFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapTileSource>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSource;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapTileSource<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapTileSourceFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSourceFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapTileSourceFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapTileSourceStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapTileSourceStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapTileSourceStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapTileUriRequest>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequest;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapTileUriRequest<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestDeferral>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestDeferral;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapTileUriRequestDeferral<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IMapTileUriRequestedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IStreetsideExperience>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperience;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IStreetsideExperience<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IStreetsideExperienceFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IStreetsideExperienceFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IStreetsideExperienceFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IStreetsidePanorama<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::IStreetsidePanoramaStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::IStreetsidePanoramaStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::Maps::impl_IStreetsidePanoramaStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::CustomMapTileDataSource>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::CustomMapTileDataSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.CustomMapTileDataSource"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.HttpMapTileDataSource"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.LocalMapTileDataSource"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapActualCameraChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapActualCameraChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapActualCameraChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapActualCameraChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapActualCameraChangingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapActualCameraChangingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapCamera>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapCamera;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapCamera"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControl>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapControl"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkClickEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkClickEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapControlBusinessLandmarkClickEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerEnteredEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerEnteredEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapControlBusinessLandmarkPointerEnteredEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerExitedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerExitedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapControlBusinessLandmarkPointerExitedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkRightTappedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkRightTappedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapControlBusinessLandmarkRightTappedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlDataHelper>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapControlDataHelper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapControlDataHelper"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureClickEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureClickEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapControlTransitFeatureClickEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerEnteredEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerEnteredEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapControlTransitFeaturePointerEnteredEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerExitedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerExitedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapControlTransitFeaturePointerExitedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureRightTappedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureRightTappedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapControlTransitFeatureRightTappedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapCustomExperience>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapCustomExperience;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapCustomExperience"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapCustomExperienceChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapCustomExperienceChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapCustomExperienceChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapElement>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapElement;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapElement"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapElementClickEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapElementClickEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapElementClickEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapElementPointerEnteredEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapElementPointerEnteredEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapElementPointerEnteredEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapElementPointerExitedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapElementPointerExitedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapElementPointerExitedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapIcon>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapIcon;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapIcon"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapInputEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapInputEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapInputEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapItemsControl>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapItemsControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapItemsControl"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapPolygon>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapPolygon;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapPolygon"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapPolyline>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapPolyline;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapPolyline"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapRightTappedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapRightTappedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapRightTappedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapRouteView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapRouteView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapRouteView"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapScene>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapScene;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapScene"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapTargetCameraChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequest>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapTileBitmapRequest"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestDeferral>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapTileBitmapRequestDeferral"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapTileBitmapRequestedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileDataSource>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapTileDataSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapTileDataSource"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileSource>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapTileSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapTileSource"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileUriRequest>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapTileUriRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapTileUriRequest"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileUriRequestDeferral>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapTileUriRequestDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapTileUriRequestDeferral"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.MapTileUriRequestedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::StreetsideExperience>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::StreetsideExperience;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.StreetsideExperience"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Maps::StreetsidePanorama;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Maps.StreetsidePanorama"; }
};

}

}
