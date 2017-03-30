// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Controls::Maps {

struct MapZoomLevelRange;

}

namespace Windows::UI::Xaml::Controls::Maps {

using MapZoomLevelRange = ABI::Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange;

}

namespace ABI::Windows::UI::Xaml::Controls::Maps {

struct ICustomMapTileDataSource;
struct ICustomMapTileDataSourceFactory;
struct IHttpMapTileDataSource;
struct IHttpMapTileDataSourceFactory;
struct ILocalMapTileDataSource;
struct ILocalMapTileDataSourceFactory;
struct IMapActualCameraChangedEventArgs;
struct IMapActualCameraChangedEventArgs2;
struct IMapActualCameraChangingEventArgs;
struct IMapActualCameraChangingEventArgs2;
struct IMapCamera;
struct IMapCameraFactory;
struct IMapControl;
struct IMapControl2;
struct IMapControl3;
struct IMapControl4;
struct IMapControlBusinessLandmarkClickEventArgs;
struct IMapControlBusinessLandmarkPointerEnteredEventArgs;
struct IMapControlBusinessLandmarkPointerExitedEventArgs;
struct IMapControlBusinessLandmarkRightTappedEventArgs;
struct IMapControlDataHelper;
struct IMapControlDataHelper2;
struct IMapControlDataHelperFactory;
struct IMapControlStatics;
struct IMapControlStatics2;
struct IMapControlStatics4;
struct IMapControlTransitFeatureClickEventArgs;
struct IMapControlTransitFeaturePointerEnteredEventArgs;
struct IMapControlTransitFeaturePointerExitedEventArgs;
struct IMapControlTransitFeatureRightTappedEventArgs;
struct IMapCustomExperience;
struct IMapCustomExperienceChangedEventArgs;
struct IMapCustomExperienceFactory;
struct IMapElement;
struct IMapElement2;
struct IMapElementClickEventArgs;
struct IMapElementFactory;
struct IMapElementPointerEnteredEventArgs;
struct IMapElementPointerExitedEventArgs;
struct IMapElementStatics;
struct IMapElementStatics2;
struct IMapIcon;
struct IMapIcon2;
struct IMapIconStatics;
struct IMapIconStatics2;
struct IMapInputEventArgs;
struct IMapItemsControl;
struct IMapItemsControlStatics;
struct IMapPolygon;
struct IMapPolygon2;
struct IMapPolygonStatics;
struct IMapPolyline;
struct IMapPolylineStatics;
struct IMapRightTappedEventArgs;
struct IMapRouteView;
struct IMapRouteViewFactory;
struct IMapScene;
struct IMapSceneStatics;
struct IMapTargetCameraChangedEventArgs;
struct IMapTargetCameraChangedEventArgs2;
struct IMapTileBitmapRequest;
struct IMapTileBitmapRequestDeferral;
struct IMapTileBitmapRequestedEventArgs;
struct IMapTileDataSource;
struct IMapTileDataSourceFactory;
struct IMapTileSource;
struct IMapTileSourceFactory;
struct IMapTileSourceStatics;
struct IMapTileUriRequest;
struct IMapTileUriRequestDeferral;
struct IMapTileUriRequestedEventArgs;
struct IStreetsideExperience;
struct IStreetsideExperienceFactory;
struct IStreetsidePanorama;
struct IStreetsidePanoramaStatics;
struct CustomMapTileDataSource;
struct HttpMapTileDataSource;
struct LocalMapTileDataSource;
struct MapActualCameraChangedEventArgs;
struct MapActualCameraChangingEventArgs;
struct MapCamera;
struct MapControl;
struct MapControlBusinessLandmarkClickEventArgs;
struct MapControlBusinessLandmarkPointerEnteredEventArgs;
struct MapControlBusinessLandmarkPointerExitedEventArgs;
struct MapControlBusinessLandmarkRightTappedEventArgs;
struct MapControlDataHelper;
struct MapControlTransitFeatureClickEventArgs;
struct MapControlTransitFeaturePointerEnteredEventArgs;
struct MapControlTransitFeaturePointerExitedEventArgs;
struct MapControlTransitFeatureRightTappedEventArgs;
struct MapCustomExperience;
struct MapCustomExperienceChangedEventArgs;
struct MapElement;
struct MapElementClickEventArgs;
struct MapElementPointerEnteredEventArgs;
struct MapElementPointerExitedEventArgs;
struct MapIcon;
struct MapInputEventArgs;
struct MapItemsControl;
struct MapPolygon;
struct MapPolyline;
struct MapRightTappedEventArgs;
struct MapRouteView;
struct MapScene;
struct MapTargetCameraChangedEventArgs;
struct MapTileBitmapRequest;
struct MapTileBitmapRequestDeferral;
struct MapTileBitmapRequestedEventArgs;
struct MapTileDataSource;
struct MapTileSource;
struct MapTileUriRequest;
struct MapTileUriRequestDeferral;
struct MapTileUriRequestedEventArgs;
struct StreetsideExperience;
struct StreetsidePanorama;

}

namespace Windows::UI::Xaml::Controls::Maps {

struct ICustomMapTileDataSource;
struct ICustomMapTileDataSourceFactory;
struct IHttpMapTileDataSource;
struct IHttpMapTileDataSourceFactory;
struct ILocalMapTileDataSource;
struct ILocalMapTileDataSourceFactory;
struct IMapActualCameraChangedEventArgs;
struct IMapActualCameraChangedEventArgs2;
struct IMapActualCameraChangingEventArgs;
struct IMapActualCameraChangingEventArgs2;
struct IMapCamera;
struct IMapCameraFactory;
struct IMapControl;
struct IMapControl2;
struct IMapControl3;
struct IMapControl4;
struct IMapControlBusinessLandmarkClickEventArgs;
struct IMapControlBusinessLandmarkPointerEnteredEventArgs;
struct IMapControlBusinessLandmarkPointerExitedEventArgs;
struct IMapControlBusinessLandmarkRightTappedEventArgs;
struct IMapControlDataHelper;
struct IMapControlDataHelper2;
struct IMapControlDataHelperFactory;
struct IMapControlStatics;
struct IMapControlStatics2;
struct IMapControlStatics4;
struct IMapControlTransitFeatureClickEventArgs;
struct IMapControlTransitFeaturePointerEnteredEventArgs;
struct IMapControlTransitFeaturePointerExitedEventArgs;
struct IMapControlTransitFeatureRightTappedEventArgs;
struct IMapCustomExperience;
struct IMapCustomExperienceChangedEventArgs;
struct IMapCustomExperienceFactory;
struct IMapElement;
struct IMapElement2;
struct IMapElementClickEventArgs;
struct IMapElementFactory;
struct IMapElementPointerEnteredEventArgs;
struct IMapElementPointerExitedEventArgs;
struct IMapElementStatics;
struct IMapElementStatics2;
struct IMapIcon;
struct IMapIcon2;
struct IMapIconStatics;
struct IMapIconStatics2;
struct IMapInputEventArgs;
struct IMapItemsControl;
struct IMapItemsControlStatics;
struct IMapPolygon;
struct IMapPolygon2;
struct IMapPolygonStatics;
struct IMapPolyline;
struct IMapPolylineStatics;
struct IMapRightTappedEventArgs;
struct IMapRouteView;
struct IMapRouteViewFactory;
struct IMapScene;
struct IMapSceneStatics;
struct IMapTargetCameraChangedEventArgs;
struct IMapTargetCameraChangedEventArgs2;
struct IMapTileBitmapRequest;
struct IMapTileBitmapRequestDeferral;
struct IMapTileBitmapRequestedEventArgs;
struct IMapTileDataSource;
struct IMapTileDataSourceFactory;
struct IMapTileSource;
struct IMapTileSourceFactory;
struct IMapTileSourceStatics;
struct IMapTileUriRequest;
struct IMapTileUriRequestDeferral;
struct IMapTileUriRequestedEventArgs;
struct IStreetsideExperience;
struct IStreetsideExperienceFactory;
struct IStreetsidePanorama;
struct IStreetsidePanoramaStatics;
struct CustomMapTileDataSource;
struct HttpMapTileDataSource;
struct LocalMapTileDataSource;
struct MapActualCameraChangedEventArgs;
struct MapActualCameraChangingEventArgs;
struct MapCamera;
struct MapControl;
struct MapControlBusinessLandmarkClickEventArgs;
struct MapControlBusinessLandmarkPointerEnteredEventArgs;
struct MapControlBusinessLandmarkPointerExitedEventArgs;
struct MapControlBusinessLandmarkRightTappedEventArgs;
struct MapControlDataHelper;
struct MapControlTransitFeatureClickEventArgs;
struct MapControlTransitFeaturePointerEnteredEventArgs;
struct MapControlTransitFeaturePointerExitedEventArgs;
struct MapControlTransitFeatureRightTappedEventArgs;
struct MapCustomExperience;
struct MapCustomExperienceChangedEventArgs;
struct MapElement;
struct MapElementClickEventArgs;
struct MapElementPointerEnteredEventArgs;
struct MapElementPointerExitedEventArgs;
struct MapIcon;
struct MapInputEventArgs;
struct MapItemsControl;
struct MapPolygon;
struct MapPolyline;
struct MapRightTappedEventArgs;
struct MapRouteView;
struct MapScene;
struct MapTargetCameraChangedEventArgs;
struct MapTileBitmapRequest;
struct MapTileBitmapRequestDeferral;
struct MapTileBitmapRequestedEventArgs;
struct MapTileDataSource;
struct MapTileSource;
struct MapTileUriRequest;
struct MapTileUriRequestDeferral;
struct MapTileUriRequestedEventArgs;
struct StreetsideExperience;
struct StreetsidePanorama;

}

namespace Windows::UI::Xaml::Controls::Maps {

template <typename T> struct impl_ICustomMapTileDataSource;
template <typename T> struct impl_ICustomMapTileDataSourceFactory;
template <typename T> struct impl_IHttpMapTileDataSource;
template <typename T> struct impl_IHttpMapTileDataSourceFactory;
template <typename T> struct impl_ILocalMapTileDataSource;
template <typename T> struct impl_ILocalMapTileDataSourceFactory;
template <typename T> struct impl_IMapActualCameraChangedEventArgs;
template <typename T> struct impl_IMapActualCameraChangedEventArgs2;
template <typename T> struct impl_IMapActualCameraChangingEventArgs;
template <typename T> struct impl_IMapActualCameraChangingEventArgs2;
template <typename T> struct impl_IMapCamera;
template <typename T> struct impl_IMapCameraFactory;
template <typename T> struct impl_IMapControl;
template <typename T> struct impl_IMapControl2;
template <typename T> struct impl_IMapControl3;
template <typename T> struct impl_IMapControl4;
template <typename T> struct impl_IMapControlBusinessLandmarkClickEventArgs;
template <typename T> struct impl_IMapControlBusinessLandmarkPointerEnteredEventArgs;
template <typename T> struct impl_IMapControlBusinessLandmarkPointerExitedEventArgs;
template <typename T> struct impl_IMapControlBusinessLandmarkRightTappedEventArgs;
template <typename T> struct impl_IMapControlDataHelper;
template <typename T> struct impl_IMapControlDataHelper2;
template <typename T> struct impl_IMapControlDataHelperFactory;
template <typename T> struct impl_IMapControlStatics;
template <typename T> struct impl_IMapControlStatics2;
template <typename T> struct impl_IMapControlStatics4;
template <typename T> struct impl_IMapControlTransitFeatureClickEventArgs;
template <typename T> struct impl_IMapControlTransitFeaturePointerEnteredEventArgs;
template <typename T> struct impl_IMapControlTransitFeaturePointerExitedEventArgs;
template <typename T> struct impl_IMapControlTransitFeatureRightTappedEventArgs;
template <typename T> struct impl_IMapCustomExperience;
template <typename T> struct impl_IMapCustomExperienceChangedEventArgs;
template <typename T> struct impl_IMapCustomExperienceFactory;
template <typename T> struct impl_IMapElement;
template <typename T> struct impl_IMapElement2;
template <typename T> struct impl_IMapElementClickEventArgs;
template <typename T> struct impl_IMapElementFactory;
template <typename T> struct impl_IMapElementPointerEnteredEventArgs;
template <typename T> struct impl_IMapElementPointerExitedEventArgs;
template <typename T> struct impl_IMapElementStatics;
template <typename T> struct impl_IMapElementStatics2;
template <typename T> struct impl_IMapIcon;
template <typename T> struct impl_IMapIcon2;
template <typename T> struct impl_IMapIconStatics;
template <typename T> struct impl_IMapIconStatics2;
template <typename T> struct impl_IMapInputEventArgs;
template <typename T> struct impl_IMapItemsControl;
template <typename T> struct impl_IMapItemsControlStatics;
template <typename T> struct impl_IMapPolygon;
template <typename T> struct impl_IMapPolygon2;
template <typename T> struct impl_IMapPolygonStatics;
template <typename T> struct impl_IMapPolyline;
template <typename T> struct impl_IMapPolylineStatics;
template <typename T> struct impl_IMapRightTappedEventArgs;
template <typename T> struct impl_IMapRouteView;
template <typename T> struct impl_IMapRouteViewFactory;
template <typename T> struct impl_IMapScene;
template <typename T> struct impl_IMapSceneStatics;
template <typename T> struct impl_IMapTargetCameraChangedEventArgs;
template <typename T> struct impl_IMapTargetCameraChangedEventArgs2;
template <typename T> struct impl_IMapTileBitmapRequest;
template <typename T> struct impl_IMapTileBitmapRequestDeferral;
template <typename T> struct impl_IMapTileBitmapRequestedEventArgs;
template <typename T> struct impl_IMapTileDataSource;
template <typename T> struct impl_IMapTileDataSourceFactory;
template <typename T> struct impl_IMapTileSource;
template <typename T> struct impl_IMapTileSourceFactory;
template <typename T> struct impl_IMapTileSourceStatics;
template <typename T> struct impl_IMapTileUriRequest;
template <typename T> struct impl_IMapTileUriRequestDeferral;
template <typename T> struct impl_IMapTileUriRequestedEventArgs;
template <typename T> struct impl_IStreetsideExperience;
template <typename T> struct impl_IStreetsideExperienceFactory;
template <typename T> struct impl_IStreetsidePanorama;
template <typename T> struct impl_IStreetsidePanoramaStatics;

}

namespace Windows::UI::Xaml::Controls::Maps {

enum class MapAnimationKind
{
    Default = 0,
    None = 1,
    Linear = 2,
    Bow = 3,
};

enum class MapCameraChangeReason
{
    System = 0,
    UserInteraction = 1,
    Programmatic = 2,
};

enum class MapColorScheme
{
    Light = 0,
    Dark = 1,
};

enum class MapElementCollisionBehavior
{
    Hide = 0,
    RemainVisible = 1,
};

enum class MapInteractionMode
{
    Auto = 0,
    Disabled = 1,
    GestureOnly = 2,
    PointerAndKeyboard = 2,
    ControlOnly = 3,
    GestureAndControl = 4,
    PointerKeyboardAndControl = 4,
    PointerOnly = 5,
};

enum class MapLoadingStatus
{
    Loading = 0,
    Loaded = 1,
    DataUnavailable = 2,
};

enum class MapPanInteractionMode
{
    Auto = 0,
    Disabled = 1,
};

enum class MapStyle
{
    None = 0,
    Road = 1,
    Aerial = 2,
    AerialWithRoads = 3,
    Terrain = 4,
    Aerial3D = 5,
    Aerial3DWithRoads = 6,
};

enum class MapTileLayer
{
    LabelOverlay = 0,
    RoadOverlay = 1,
    AreaOverlay = 2,
    BackgroundOverlay = 3,
    BackgroundReplacement = 4,
};

enum class MapVisibleRegionKind
{
    Near = 0,
    Full = 1,
};

enum class MapWatermarkMode
{
    Automatic = 0,
    On = 1,
};

}

}
