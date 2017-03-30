// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Controls.Maps.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Controls::Maps {

struct WINRT_EBO CustomMapTileDataSource :
    Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource,
    impl::bases<CustomMapTileDataSource, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Controls::Maps::MapTileDataSource>,
    impl::require<CustomMapTileDataSource, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapTileDataSource>
{
    CustomMapTileDataSource(std::nullptr_t) noexcept {}
    CustomMapTileDataSource();
};

struct WINRT_EBO HttpMapTileDataSource :
    Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource,
    impl::bases<HttpMapTileDataSource, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Controls::Maps::MapTileDataSource>,
    impl::require<HttpMapTileDataSource, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapTileDataSource>
{
    HttpMapTileDataSource(std::nullptr_t) noexcept {}
    HttpMapTileDataSource();
    HttpMapTileDataSource(hstring_view uriFormatString);
};

struct WINRT_EBO LocalMapTileDataSource :
    Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource,
    impl::bases<LocalMapTileDataSource, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Controls::Maps::MapTileDataSource>,
    impl::require<LocalMapTileDataSource, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapTileDataSource>
{
    LocalMapTileDataSource(std::nullptr_t) noexcept {}
    LocalMapTileDataSource();
    LocalMapTileDataSource(hstring_view uriFormatString);
};

struct WINRT_EBO MapActualCameraChangedEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs,
    impl::require<MapActualCameraChangedEventArgs, Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs2>
{
    MapActualCameraChangedEventArgs(std::nullptr_t) noexcept {}
    MapActualCameraChangedEventArgs();
};

struct WINRT_EBO MapActualCameraChangingEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs,
    impl::require<MapActualCameraChangingEventArgs, Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs2>
{
    MapActualCameraChangingEventArgs(std::nullptr_t) noexcept {}
    MapActualCameraChangingEventArgs();
};

struct WINRT_EBO MapCamera :
    Windows::UI::Xaml::Controls::Maps::IMapCamera,
    impl::bases<MapCamera, Windows::UI::Xaml::DependencyObject>,
    impl::require<MapCamera, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    MapCamera(std::nullptr_t) noexcept {}
    MapCamera(const Windows::Devices::Geolocation::Geopoint & location);
    MapCamera(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees);
    MapCamera(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees, double pitchInDegrees);
    MapCamera(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees, double pitchInDegrees, double rollInDegrees, double fieldOfViewInDegrees);
};

struct WINRT_EBO MapControl :
    Windows::UI::Xaml::Controls::Maps::IMapControl,
    impl::bases<MapControl, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<MapControl, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::Maps::IMapControl2, Windows::UI::Xaml::Controls::Maps::IMapControl3, Windows::UI::Xaml::Controls::Maps::IMapControl4>
{
    MapControl(std::nullptr_t) noexcept {}
    MapControl();
    using impl_IFrameworkElement::Style;
    using impl_IMapControl::Style;
    static Windows::UI::Xaml::DependencyProperty CenterProperty();
    static Windows::UI::Xaml::DependencyProperty ChildrenProperty();
    static Windows::UI::Xaml::DependencyProperty ColorSchemeProperty();
    static Windows::UI::Xaml::DependencyProperty DesiredPitchProperty();
    static Windows::UI::Xaml::DependencyProperty HeadingProperty();
    static Windows::UI::Xaml::DependencyProperty LandmarksVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty LoadingStatusProperty();
    static Windows::UI::Xaml::DependencyProperty MapServiceTokenProperty();
    static Windows::UI::Xaml::DependencyProperty PedestrianFeaturesVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty PitchProperty();
    static Windows::UI::Xaml::DependencyProperty StyleProperty();
    static Windows::UI::Xaml::DependencyProperty TrafficFlowVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty TransformOriginProperty();
    static Windows::UI::Xaml::DependencyProperty WatermarkModeProperty();
    static Windows::UI::Xaml::DependencyProperty ZoomLevelProperty();
    static Windows::UI::Xaml::DependencyProperty MapElementsProperty();
    static Windows::UI::Xaml::DependencyProperty RoutesProperty();
    static Windows::UI::Xaml::DependencyProperty TileSourcesProperty();
    static Windows::UI::Xaml::DependencyProperty LocationProperty();
    static Windows::Devices::Geolocation::Geopoint GetLocation(const Windows::UI::Xaml::DependencyObject & element);
    static void SetLocation(const Windows::UI::Xaml::DependencyObject & element, const Windows::Devices::Geolocation::Geopoint & value);
    static Windows::UI::Xaml::DependencyProperty NormalizedAnchorPointProperty();
    static Windows::Foundation::Point GetNormalizedAnchorPoint(const Windows::UI::Xaml::DependencyObject & element);
    static void SetNormalizedAnchorPoint(const Windows::UI::Xaml::DependencyObject & element, const Windows::Foundation::Point & value);
    static Windows::UI::Xaml::DependencyProperty BusinessLandmarksVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty TransitFeaturesVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty PanInteractionModeProperty();
    static Windows::UI::Xaml::DependencyProperty RotateInteractionModeProperty();
    static Windows::UI::Xaml::DependencyProperty TiltInteractionModeProperty();
    static Windows::UI::Xaml::DependencyProperty ZoomInteractionModeProperty();
    static Windows::UI::Xaml::DependencyProperty Is3DSupportedProperty();
    static Windows::UI::Xaml::DependencyProperty IsStreetsideSupportedProperty();
    static Windows::UI::Xaml::DependencyProperty SceneProperty();
    static Windows::UI::Xaml::DependencyProperty BusinessLandmarksEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty TransitFeaturesEnabledProperty();
};

struct WINRT_EBO MapControlBusinessLandmarkClickEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkClickEventArgs
{
    MapControlBusinessLandmarkClickEventArgs(std::nullptr_t) noexcept {}
    MapControlBusinessLandmarkClickEventArgs();
};

struct WINRT_EBO MapControlBusinessLandmarkPointerEnteredEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerEnteredEventArgs
{
    MapControlBusinessLandmarkPointerEnteredEventArgs(std::nullptr_t) noexcept {}
    MapControlBusinessLandmarkPointerEnteredEventArgs();
};

struct WINRT_EBO MapControlBusinessLandmarkPointerExitedEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerExitedEventArgs
{
    MapControlBusinessLandmarkPointerExitedEventArgs(std::nullptr_t) noexcept {}
    MapControlBusinessLandmarkPointerExitedEventArgs();
};

struct WINRT_EBO MapControlBusinessLandmarkRightTappedEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkRightTappedEventArgs
{
    MapControlBusinessLandmarkRightTappedEventArgs(std::nullptr_t) noexcept {}
    MapControlBusinessLandmarkRightTappedEventArgs();
};

struct WINRT_EBO MapControlDataHelper :
    Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper,
    impl::bases<MapControlDataHelper, Windows::UI::Xaml::DependencyObject>,
    impl::require<MapControlDataHelper, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2>
{
    MapControlDataHelper(std::nullptr_t) noexcept {}
    MapControlDataHelper(const Windows::UI::Xaml::Controls::Maps::MapControl & map);
};

struct WINRT_EBO MapControlTransitFeatureClickEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureClickEventArgs
{
    MapControlTransitFeatureClickEventArgs(std::nullptr_t) noexcept {}
    MapControlTransitFeatureClickEventArgs();
};

struct WINRT_EBO MapControlTransitFeaturePointerEnteredEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerEnteredEventArgs
{
    MapControlTransitFeaturePointerEnteredEventArgs(std::nullptr_t) noexcept {}
    MapControlTransitFeaturePointerEnteredEventArgs();
};

struct WINRT_EBO MapControlTransitFeaturePointerExitedEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerExitedEventArgs
{
    MapControlTransitFeaturePointerExitedEventArgs(std::nullptr_t) noexcept {}
    MapControlTransitFeaturePointerExitedEventArgs();
};

struct WINRT_EBO MapControlTransitFeatureRightTappedEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureRightTappedEventArgs
{
    MapControlTransitFeatureRightTappedEventArgs(std::nullptr_t) noexcept {}
    MapControlTransitFeatureRightTappedEventArgs();
};

struct WINRT_EBO MapCustomExperience :
    Windows::UI::Xaml::Controls::Maps::IMapCustomExperience,
    impl::bases<MapCustomExperience, Windows::UI::Xaml::DependencyObject>,
    impl::require<MapCustomExperience, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    MapCustomExperience(std::nullptr_t) noexcept {}
    MapCustomExperience();
};

struct WINRT_EBO MapCustomExperienceChangedEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapCustomExperienceChangedEventArgs
{
    MapCustomExperienceChangedEventArgs(std::nullptr_t) noexcept {}
    MapCustomExperienceChangedEventArgs();
};

struct WINRT_EBO MapElement :
    Windows::UI::Xaml::Controls::Maps::IMapElement,
    impl::bases<MapElement, Windows::UI::Xaml::DependencyObject>,
    impl::require<MapElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapElement2>
{
    MapElement(std::nullptr_t) noexcept {}
    MapElement();
    static Windows::UI::Xaml::DependencyProperty ZIndexProperty();
    static Windows::UI::Xaml::DependencyProperty VisibleProperty();
    static Windows::UI::Xaml::DependencyProperty MapTabIndexProperty();
};

struct WINRT_EBO MapElementClickEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapElementClickEventArgs
{
    MapElementClickEventArgs(std::nullptr_t) noexcept {}
    MapElementClickEventArgs();
};

struct WINRT_EBO MapElementPointerEnteredEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapElementPointerEnteredEventArgs
{
    MapElementPointerEnteredEventArgs(std::nullptr_t) noexcept {}
    MapElementPointerEnteredEventArgs();
};

struct WINRT_EBO MapElementPointerExitedEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapElementPointerExitedEventArgs
{
    MapElementPointerExitedEventArgs(std::nullptr_t) noexcept {}
    MapElementPointerExitedEventArgs();
};

struct WINRT_EBO MapIcon :
    Windows::UI::Xaml::Controls::Maps::IMapIcon,
    impl::bases<MapIcon, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Controls::Maps::MapElement>,
    impl::require<MapIcon, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapElement, Windows::UI::Xaml::Controls::Maps::IMapElement2, Windows::UI::Xaml::Controls::Maps::IMapIcon2>
{
    MapIcon(std::nullptr_t) noexcept {}
    MapIcon();
    static Windows::UI::Xaml::DependencyProperty LocationProperty();
    static Windows::UI::Xaml::DependencyProperty TitleProperty();
    static Windows::UI::Xaml::DependencyProperty NormalizedAnchorPointProperty();
    static Windows::UI::Xaml::DependencyProperty CollisionBehaviorDesiredProperty();
};

struct WINRT_EBO MapInputEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapInputEventArgs,
    impl::bases<MapInputEventArgs, Windows::UI::Xaml::DependencyObject>,
    impl::require<MapInputEventArgs, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    MapInputEventArgs(std::nullptr_t) noexcept {}
    MapInputEventArgs();
};

struct WINRT_EBO MapItemsControl :
    Windows::UI::Xaml::Controls::Maps::IMapItemsControl,
    impl::bases<MapItemsControl, Windows::UI::Xaml::DependencyObject>,
    impl::require<MapItemsControl, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    MapItemsControl(std::nullptr_t) noexcept {}
    MapItemsControl();
    static Windows::UI::Xaml::DependencyProperty ItemsSourceProperty();
    static Windows::UI::Xaml::DependencyProperty ItemsProperty();
    static Windows::UI::Xaml::DependencyProperty ItemTemplateProperty();
};

struct WINRT_EBO MapPolygon :
    Windows::UI::Xaml::Controls::Maps::IMapPolygon,
    impl::bases<MapPolygon, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Controls::Maps::MapElement>,
    impl::require<MapPolygon, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapElement, Windows::UI::Xaml::Controls::Maps::IMapElement2, Windows::UI::Xaml::Controls::Maps::IMapPolygon2>
{
    MapPolygon(std::nullptr_t) noexcept {}
    MapPolygon();
    static Windows::UI::Xaml::DependencyProperty PathProperty();
    static Windows::UI::Xaml::DependencyProperty StrokeThicknessProperty();
    static Windows::UI::Xaml::DependencyProperty StrokeDashedProperty();
};

struct WINRT_EBO MapPolyline :
    Windows::UI::Xaml::Controls::Maps::IMapPolyline,
    impl::bases<MapPolyline, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Controls::Maps::MapElement>,
    impl::require<MapPolyline, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapElement, Windows::UI::Xaml::Controls::Maps::IMapElement2>
{
    MapPolyline(std::nullptr_t) noexcept {}
    MapPolyline();
    static Windows::UI::Xaml::DependencyProperty PathProperty();
    static Windows::UI::Xaml::DependencyProperty StrokeDashedProperty();
};

struct WINRT_EBO MapRightTappedEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapRightTappedEventArgs
{
    MapRightTappedEventArgs(std::nullptr_t) noexcept {}
    MapRightTappedEventArgs();
};

struct WINRT_EBO MapRouteView :
    Windows::UI::Xaml::Controls::Maps::IMapRouteView,
    impl::bases<MapRouteView, Windows::UI::Xaml::DependencyObject>,
    impl::require<MapRouteView, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    MapRouteView(std::nullptr_t) noexcept {}
    MapRouteView(const Windows::Services::Maps::MapRoute & route);
};

struct WINRT_EBO MapScene :
    Windows::UI::Xaml::Controls::Maps::IMapScene,
    impl::bases<MapScene, Windows::UI::Xaml::DependencyObject>,
    impl::require<MapScene, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    MapScene(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Controls::Maps::MapScene CreateFromBoundingBox(const Windows::Devices::Geolocation::GeoboundingBox & bounds);
    static Windows::UI::Xaml::Controls::Maps::MapScene CreateFromBoundingBox(const Windows::Devices::Geolocation::GeoboundingBox & bounds, double headingInDegrees, double pitchInDegrees);
    static Windows::UI::Xaml::Controls::Maps::MapScene CreateFromCamera(const Windows::UI::Xaml::Controls::Maps::MapCamera & camera);
    static Windows::UI::Xaml::Controls::Maps::MapScene CreateFromLocation(const Windows::Devices::Geolocation::Geopoint & location);
    static Windows::UI::Xaml::Controls::Maps::MapScene CreateFromLocation(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees, double pitchInDegrees);
    static Windows::UI::Xaml::Controls::Maps::MapScene CreateFromLocationAndRadius(const Windows::Devices::Geolocation::Geopoint & location, double radiusInMeters);
    static Windows::UI::Xaml::Controls::Maps::MapScene CreateFromLocationAndRadius(const Windows::Devices::Geolocation::Geopoint & location, double radiusInMeters, double headingInDegrees, double pitchInDegrees);
    static Windows::UI::Xaml::Controls::Maps::MapScene CreateFromLocations(iterable<Windows::Devices::Geolocation::Geopoint> locations);
    static Windows::UI::Xaml::Controls::Maps::MapScene CreateFromLocations(iterable<Windows::Devices::Geolocation::Geopoint> locations, double headingInDegrees, double pitchInDegrees);
};

struct WINRT_EBO MapTargetCameraChangedEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs,
    impl::require<MapTargetCameraChangedEventArgs, Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs2>
{
    MapTargetCameraChangedEventArgs(std::nullptr_t) noexcept {}
    MapTargetCameraChangedEventArgs();
};

struct WINRT_EBO MapTileBitmapRequest :
    Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequest
{
    MapTileBitmapRequest(std::nullptr_t) noexcept {}
    MapTileBitmapRequest();
};

struct WINRT_EBO MapTileBitmapRequestDeferral :
    Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestDeferral
{
    MapTileBitmapRequestDeferral(std::nullptr_t) noexcept {}
    MapTileBitmapRequestDeferral();
};

struct WINRT_EBO MapTileBitmapRequestedEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs
{
    MapTileBitmapRequestedEventArgs(std::nullptr_t) noexcept {}
    MapTileBitmapRequestedEventArgs();
};

struct WINRT_EBO MapTileDataSource :
    Windows::UI::Xaml::Controls::Maps::IMapTileDataSource,
    impl::bases<MapTileDataSource, Windows::UI::Xaml::DependencyObject>,
    impl::require<MapTileDataSource, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    MapTileDataSource(std::nullptr_t) noexcept {}
    MapTileDataSource();
};

struct WINRT_EBO MapTileSource :
    Windows::UI::Xaml::Controls::Maps::IMapTileSource,
    impl::bases<MapTileSource, Windows::UI::Xaml::DependencyObject>,
    impl::require<MapTileSource, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    MapTileSource(std::nullptr_t) noexcept {}
    MapTileSource();
    MapTileSource(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource);
    MapTileSource(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange);
    MapTileSource(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange, const Windows::Devices::Geolocation::GeoboundingBox & bounds);
    MapTileSource(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange, const Windows::Devices::Geolocation::GeoboundingBox & bounds, int32_t tileSizeInPixels);
    static Windows::UI::Xaml::DependencyProperty DataSourceProperty();
    static Windows::UI::Xaml::DependencyProperty LayerProperty();
    static Windows::UI::Xaml::DependencyProperty ZoomLevelRangeProperty();
    static Windows::UI::Xaml::DependencyProperty BoundsProperty();
    static Windows::UI::Xaml::DependencyProperty AllowOverstretchProperty();
    static Windows::UI::Xaml::DependencyProperty IsFadingEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsTransparencyEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsRetryEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty ZIndexProperty();
    static Windows::UI::Xaml::DependencyProperty TilePixelSizeProperty();
    static Windows::UI::Xaml::DependencyProperty VisibleProperty();
};

struct WINRT_EBO MapTileUriRequest :
    Windows::UI::Xaml::Controls::Maps::IMapTileUriRequest
{
    MapTileUriRequest(std::nullptr_t) noexcept {}
    MapTileUriRequest();
};

struct WINRT_EBO MapTileUriRequestDeferral :
    Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestDeferral
{
    MapTileUriRequestDeferral(std::nullptr_t) noexcept {}
    MapTileUriRequestDeferral();
};

struct WINRT_EBO MapTileUriRequestedEventArgs :
    Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs
{
    MapTileUriRequestedEventArgs(std::nullptr_t) noexcept {}
    MapTileUriRequestedEventArgs();
};

struct WINRT_EBO StreetsideExperience :
    Windows::UI::Xaml::Controls::Maps::IStreetsideExperience,
    impl::bases<StreetsideExperience, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Controls::Maps::MapCustomExperience>,
    impl::require<StreetsideExperience, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Maps::IMapCustomExperience>
{
    StreetsideExperience(std::nullptr_t) noexcept {}
    StreetsideExperience(const Windows::UI::Xaml::Controls::Maps::StreetsidePanorama & panorama);
    StreetsideExperience(const Windows::UI::Xaml::Controls::Maps::StreetsidePanorama & panorama, double headingInDegrees, double pitchInDegrees, double fieldOfViewInDegrees);
};

struct WINRT_EBO StreetsidePanorama :
    Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama,
    impl::bases<StreetsidePanorama, Windows::UI::Xaml::DependencyObject>,
    impl::require<StreetsidePanorama, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    StreetsidePanorama(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama> FindNearbyAsync(const Windows::Devices::Geolocation::Geopoint & location);
    static Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama> FindNearbyAsync(const Windows::Devices::Geolocation::Geopoint & location, double radiusInMeters);
};

}

}
