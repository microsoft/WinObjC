//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsUIXamlControlsMaps.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
#define OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIXamlControlsMaps.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUXCMMapStyleSheetEntries, WUXCMMapStyleSheetEntryStates, WUXCMMapActualCameraChangedEventArgs, WUXCMMapActualCameraChangingEventArgs, WUXCMMapContextRequestedEventArgs, WUXCMMapCustomExperienceChangedEventArgs, WUXCMMapElementClickEventArgs, WUXCMMapElementPointerEnteredEventArgs, WUXCMMapElementPointerExitedEventArgs, WUXCMMapElementsLayerClickEventArgs, WUXCMMapElementsLayerContextRequestedEventArgs, WUXCMMapElementsLayerPointerEnteredEventArgs, WUXCMMapElementsLayerPointerExitedEventArgs, WUXCMMapRightTappedEventArgs, WUXCMMapTargetCameraChangedEventArgs, WUXCMMapTileBitmapRequestDeferral, WUXCMMapTileBitmapRequest, WUXCMMapTileBitmapRequestedEventArgs, WUXCMMapTileUriRequestDeferral, WUXCMMapTileUriRequest, WUXCMMapTileUriRequestedEventArgs, WUXCMMapCamera, WUXCMMapCustomExperience, WUXCMMapElement, WUXCMMapInputEventArgs, WUXCMMapItemsControl, WUXCMMapLayer, WUXCMMapModel3D, WUXCMMapRouteView, WUXCMMapScene, WUXCMMapStyleSheet, WUXCMMapTileDataSource, WUXCMMapTileSource, WUXCMStreetsidePanorama, WUXCMCustomMapTileDataSource, WUXCMHttpMapTileDataSource, WUXCMLocalMapTileDataSource, WUXCMMapBillboard, WUXCMMapElement3D, WUXCMMapElementsLayer, WUXCMMapIcon, WUXCMMapPolygon, WUXCMMapPolyline, WUXCMStreetsideExperience, WUXCMMapControl, WUXCMMapControlBusinessLandmarkClickEventArgs, WUXCMMapControlTransitFeatureClickEventArgs, WUXCMMapControlBusinessLandmarkRightTappedEventArgs, WUXCMMapControlTransitFeatureRightTappedEventArgs, WUXCMMapControlBusinessLandmarkPointerEnteredEventArgs, WUXCMMapControlTransitFeaturePointerEnteredEventArgs, WUXCMMapControlBusinessLandmarkPointerExitedEventArgs, WUXCMMapControlTransitFeaturePointerExitedEventArgs, WUXCMMapControlDataHelper;
@class WUXCMMapZoomLevelRange;
@protocol WUXCMIMapStyleSheetEntriesStatics, WUXCMIMapStyleSheetEntryStatesStatics, WUXCMIMapActualCameraChangedEventArgs, WUXCMIMapActualCameraChangedEventArgs2, WUXCMIMapActualCameraChangingEventArgs, WUXCMIMapActualCameraChangingEventArgs2, WUXCMIMapContextRequestedEventArgs, WUXCMIMapCustomExperienceChangedEventArgs, WUXCMIMapElementClickEventArgs, WUXCMIMapElementPointerEnteredEventArgs, WUXCMIMapElementPointerExitedEventArgs, WUXCMIMapElementsLayerClickEventArgs, WUXCMIMapElementsLayerContextRequestedEventArgs, WUXCMIMapElementsLayerPointerEnteredEventArgs, WUXCMIMapElementsLayerPointerExitedEventArgs, WUXCMIMapRightTappedEventArgs, WUXCMIMapTargetCameraChangedEventArgs, WUXCMIMapTargetCameraChangedEventArgs2, WUXCMIMapTileBitmapRequest, WUXCMIMapTileBitmapRequestDeferral, WUXCMIMapTileBitmapRequestedEventArgs, WUXCMIMapTileUriRequest, WUXCMIMapTileUriRequestDeferral, WUXCMIMapTileUriRequestedEventArgs, WUXCMIMapCamera, WUXCMIMapCameraFactory, WUXCMIMapCustomExperience, WUXCMIMapCustomExperienceFactory, WUXCMIMapElement, WUXCMIMapElementStatics, WUXCMIMapElementFactory, WUXCMIMapElement2, WUXCMIMapElementStatics2, WUXCMIMapElement3, WUXCMIMapElementStatics3, WUXCMIMapInputEventArgs, WUXCMIMapItemsControl, WUXCMIMapItemsControlStatics, WUXCMIMapLayer, WUXCMIMapLayerStatics, WUXCMIMapLayerFactory, WUXCMIMapModel3D, WUXCMIMapModel3DStatics, WUXCMIMapModel3DFactory, WUXCMIMapRouteView, WUXCMIMapRouteViewFactory, WUXCMIMapScene, WUXCMIMapSceneStatics, WUXCMIMapStyleSheet, WUXCMIMapStyleSheetStatics, WUXCMIMapTileDataSource, WUXCMIMapTileDataSourceFactory, WUXCMIMapTileSource, WUXCMIMapTileSourceStatics, WUXCMIMapTileSourceFactory, WUXCMIStreetsidePanorama, WUXCMIStreetsidePanoramaStatics, WUXCMICustomMapTileDataSource, WUXCMICustomMapTileDataSourceFactory, WUXCMIHttpMapTileDataSource, WUXCMIHttpMapTileDataSourceFactory, WUXCMILocalMapTileDataSource, WUXCMILocalMapTileDataSourceFactory, WUXCMIMapBillboard, WUXCMIMapBillboardStatics, WUXCMIMapBillboardFactory, WUXCMIMapElement3D, WUXCMIMapElement3DStatics, WUXCMIMapElementsLayer, WUXCMIMapElementsLayerStatics, WUXCMIMapIcon, WUXCMIMapIconStatics, WUXCMIMapIcon2, WUXCMIMapIconStatics2, WUXCMIMapPolygon, WUXCMIMapPolygonStatics, WUXCMIMapPolygon2, WUXCMIMapPolyline, WUXCMIMapPolylineStatics, WUXCMIStreetsideExperience, WUXCMIStreetsideExperienceFactory, WUXCMIMapControl, WUXCMIMapControlStatics, WUXCMIMapControl2, WUXCMIMapControlStatics2, WUXCMIMapControl3, WUXCMIMapControl4, WUXCMIMapControlStatics4, WUXCMIMapControl5, WUXCMIMapControlStatics5, WUXCMIMapControl6, WUXCMIMapControlStatics6, WUXCMIMapControlDataHelper, WUXCMIMapControlDataHelper2, WUXCMIMapControlDataHelperStatics, WUXCMIMapControlDataHelperFactory, WUXCMIMapControlBusinessLandmarkClickEventArgs, WUXCMIMapControlTransitFeatureClickEventArgs, WUXCMIMapControlBusinessLandmarkRightTappedEventArgs, WUXCMIMapControlTransitFeatureRightTappedEventArgs, WUXCMIMapControlBusinessLandmarkPointerEnteredEventArgs, WUXCMIMapControlTransitFeaturePointerEnteredEventArgs, WUXCMIMapControlBusinessLandmarkPointerExitedEventArgs, WUXCMIMapControlTransitFeaturePointerExitedEventArgs;

// Windows.UI.Xaml.Controls.Maps.MapAnimationKind
enum _WUXCMMapAnimationKind {
    WUXCMMapAnimationKindDefault = 0,
    WUXCMMapAnimationKindNone = 1,
    WUXCMMapAnimationKindLinear = 2,
    WUXCMMapAnimationKindBow = 3,
};
typedef unsigned WUXCMMapAnimationKind;

// Windows.UI.Xaml.Controls.Maps.MapCameraChangeReason
enum _WUXCMMapCameraChangeReason {
    WUXCMMapCameraChangeReasonSystem = 0,
    WUXCMMapCameraChangeReasonUserInteraction = 1,
    WUXCMMapCameraChangeReasonProgrammatic = 2,
};
typedef unsigned WUXCMMapCameraChangeReason;

// Windows.UI.Xaml.Controls.Maps.MapColorScheme
enum _WUXCMMapColorScheme {
    WUXCMMapColorSchemeLight = 0,
    WUXCMMapColorSchemeDark = 1,
};
typedef unsigned WUXCMMapColorScheme;

// Windows.UI.Xaml.Controls.Maps.MapElementCollisionBehavior
enum _WUXCMMapElementCollisionBehavior {
    WUXCMMapElementCollisionBehaviorHide = 0,
    WUXCMMapElementCollisionBehaviorRemainVisible = 1,
};
typedef unsigned WUXCMMapElementCollisionBehavior;

// Windows.UI.Xaml.Controls.Maps.MapInteractionMode
enum _WUXCMMapInteractionMode {
    WUXCMMapInteractionModeAuto = 0,
    WUXCMMapInteractionModeDisabled = 1,
    WUXCMMapInteractionModeGestureOnly = 2,
    WUXCMMapInteractionModePointerAndKeyboard = 2,
    WUXCMMapInteractionModeControlOnly = 3,
    WUXCMMapInteractionModeGestureAndControl = 4,
    WUXCMMapInteractionModePointerKeyboardAndControl = 4,
    WUXCMMapInteractionModePointerOnly = 5,
};
typedef unsigned WUXCMMapInteractionMode;

// Windows.UI.Xaml.Controls.Maps.MapLoadingStatus
enum _WUXCMMapLoadingStatus {
    WUXCMMapLoadingStatusLoading = 0,
    WUXCMMapLoadingStatusLoaded = 1,
    WUXCMMapLoadingStatusDataUnavailable = 2,
};
typedef unsigned WUXCMMapLoadingStatus;

// Windows.UI.Xaml.Controls.Maps.MapModel3DShadingOption
enum _WUXCMMapModel3DShadingOption {
    WUXCMMapModel3DShadingOptionDefault = 0,
    WUXCMMapModel3DShadingOptionFlat = 1,
    WUXCMMapModel3DShadingOptionSmooth = 2,
};
typedef unsigned WUXCMMapModel3DShadingOption;

// Windows.UI.Xaml.Controls.Maps.MapPanInteractionMode
enum _WUXCMMapPanInteractionMode {
    WUXCMMapPanInteractionModeAuto = 0,
    WUXCMMapPanInteractionModeDisabled = 1,
};
typedef unsigned WUXCMMapPanInteractionMode;

// Windows.UI.Xaml.Controls.Maps.MapProjection
enum _WUXCMMapProjection {
    WUXCMMapProjectionWebMercator = 0,
    WUXCMMapProjectionGlobe = 1,
};
typedef unsigned WUXCMMapProjection;

// Windows.UI.Xaml.Controls.Maps.MapStyle
enum _WUXCMMapStyle {
    WUXCMMapStyleNone = 0,
    WUXCMMapStyleRoad = 1,
    WUXCMMapStyleAerial = 2,
    WUXCMMapStyleAerialWithRoads = 3,
    WUXCMMapStyleTerrain = 4,
    WUXCMMapStyleAerial3D = 5,
    WUXCMMapStyleAerial3DWithRoads = 6,
    WUXCMMapStyleCustom = 7,
};
typedef unsigned WUXCMMapStyle;

// Windows.UI.Xaml.Controls.Maps.MapTileLayer
enum _WUXCMMapTileLayer {
    WUXCMMapTileLayerLabelOverlay = 0,
    WUXCMMapTileLayerRoadOverlay = 1,
    WUXCMMapTileLayerAreaOverlay = 2,
    WUXCMMapTileLayerBackgroundOverlay = 3,
    WUXCMMapTileLayerBackgroundReplacement = 4,
};
typedef unsigned WUXCMMapTileLayer;

// Windows.UI.Xaml.Controls.Maps.MapVisibleRegionKind
enum _WUXCMMapVisibleRegionKind {
    WUXCMMapVisibleRegionKindNear = 0,
    WUXCMMapVisibleRegionKindFull = 1,
};
typedef unsigned WUXCMMapVisibleRegionKind;

// Windows.UI.Xaml.Controls.Maps.MapWatermarkMode
enum _WUXCMMapWatermarkMode {
    WUXCMMapWatermarkModeAutomatic = 0,
    WUXCMMapWatermarkModeOn = 1,
};
typedef unsigned WUXCMMapWatermarkMode;

#include "WindowsFoundation.h"
#include "WindowsFoundationNumerics.h"
#include "WindowsUIXamlMediaMedia3D.h"
#include "WindowsDevicesGeolocation.h"
#include "WindowsStorageStreams.h"
#include "WindowsServicesMapsLocalSearch.h"
#include "WindowsUIXaml.h"
#include "WindowsUIXamlControlsPrimitives.h"
#include "WindowsUIXamlData.h"
#include "WindowsUI.h"
#include "WindowsServicesMaps.h"
#include "WindowsUICore.h"
#include "WindowsUIXamlMediaAnimation.h"
#include "WindowsUIXamlControls.h"
#include "WindowsApplicationModelDataTransfer.h"
#include "WindowsUIXamlMedia.h"
#include "WindowsUIText.h"
#include "WindowsUIXamlInput.h"
#include "WindowsUIInput.h"
#include "WindowsUIXamlAutomationPeers.h"
// Windows.UI.Xaml.DependencyPropertyChangedCallback
#ifndef __WXDependencyPropertyChangedCallback__DEFINED
#define __WXDependencyPropertyChangedCallback__DEFINED
typedef void(^WXDependencyPropertyChangedCallback)(WXDependencyObject* sender, WXDependencyProperty* dp);
#endif // __WXDependencyPropertyChangedCallback__DEFINED

// Windows.UI.Xaml.DependencyPropertyChangedEventHandler
#ifndef __WXDependencyPropertyChangedEventHandler__DEFINED
#define __WXDependencyPropertyChangedEventHandler__DEFINED
typedef void(^WXDependencyPropertyChangedEventHandler)(RTObject* sender, WXDependencyPropertyChangedEventArgs* e);
#endif // __WXDependencyPropertyChangedEventHandler__DEFINED

// Windows.UI.Xaml.DragEventHandler
#ifndef __WXDragEventHandler__DEFINED
#define __WXDragEventHandler__DEFINED
typedef void(^WXDragEventHandler)(RTObject* sender, WXDragEventArgs* e);
#endif // __WXDragEventHandler__DEFINED

// Windows.UI.Xaml.Input.DoubleTappedEventHandler
#ifndef __WUXIDoubleTappedEventHandler__DEFINED
#define __WUXIDoubleTappedEventHandler__DEFINED
typedef void(^WUXIDoubleTappedEventHandler)(RTObject* sender, WUXIDoubleTappedRoutedEventArgs* e);
#endif // __WUXIDoubleTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.HoldingEventHandler
#ifndef __WUXIHoldingEventHandler__DEFINED
#define __WUXIHoldingEventHandler__DEFINED
typedef void(^WUXIHoldingEventHandler)(RTObject* sender, WUXIHoldingRoutedEventArgs* e);
#endif // __WUXIHoldingEventHandler__DEFINED

// Windows.UI.Xaml.Input.KeyEventHandler
#ifndef __WUXIKeyEventHandler__DEFINED
#define __WUXIKeyEventHandler__DEFINED
typedef void(^WUXIKeyEventHandler)(RTObject* sender, WUXIKeyRoutedEventArgs* e);
#endif // __WUXIKeyEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationCompletedEventHandler
#ifndef __WUXIManipulationCompletedEventHandler__DEFINED
#define __WUXIManipulationCompletedEventHandler__DEFINED
typedef void(^WUXIManipulationCompletedEventHandler)(RTObject* sender, WUXIManipulationCompletedRoutedEventArgs* e);
#endif // __WUXIManipulationCompletedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationDeltaEventHandler
#ifndef __WUXIManipulationDeltaEventHandler__DEFINED
#define __WUXIManipulationDeltaEventHandler__DEFINED
typedef void(^WUXIManipulationDeltaEventHandler)(RTObject* sender, WUXIManipulationDeltaRoutedEventArgs* e);
#endif // __WUXIManipulationDeltaEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationInertiaStartingEventHandler
#ifndef __WUXIManipulationInertiaStartingEventHandler__DEFINED
#define __WUXIManipulationInertiaStartingEventHandler__DEFINED
typedef void(^WUXIManipulationInertiaStartingEventHandler)(RTObject* sender, WUXIManipulationInertiaStartingRoutedEventArgs* e);
#endif // __WUXIManipulationInertiaStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartedEventHandler
#ifndef __WUXIManipulationStartedEventHandler__DEFINED
#define __WUXIManipulationStartedEventHandler__DEFINED
typedef void(^WUXIManipulationStartedEventHandler)(RTObject* sender, WUXIManipulationStartedRoutedEventArgs* e);
#endif // __WUXIManipulationStartedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartingEventHandler
#ifndef __WUXIManipulationStartingEventHandler__DEFINED
#define __WUXIManipulationStartingEventHandler__DEFINED
typedef void(^WUXIManipulationStartingEventHandler)(RTObject* sender, WUXIManipulationStartingRoutedEventArgs* e);
#endif // __WUXIManipulationStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.PointerEventHandler
#ifndef __WUXIPointerEventHandler__DEFINED
#define __WUXIPointerEventHandler__DEFINED
typedef void(^WUXIPointerEventHandler)(RTObject* sender, WUXIPointerRoutedEventArgs* e);
#endif // __WUXIPointerEventHandler__DEFINED

// Windows.UI.Xaml.Input.RightTappedEventHandler
#ifndef __WUXIRightTappedEventHandler__DEFINED
#define __WUXIRightTappedEventHandler__DEFINED
typedef void(^WUXIRightTappedEventHandler)(RTObject* sender, WUXIRightTappedRoutedEventArgs* e);
#endif // __WUXIRightTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.TappedEventHandler
#ifndef __WUXITappedEventHandler__DEFINED
#define __WUXITappedEventHandler__DEFINED
typedef void(^WUXITappedEventHandler)(RTObject* sender, WUXITappedRoutedEventArgs* e);
#endif // __WUXITappedEventHandler__DEFINED

// Windows.UI.Xaml.RoutedEventHandler
#ifndef __WXRoutedEventHandler__DEFINED
#define __WXRoutedEventHandler__DEFINED
typedef void(^WXRoutedEventHandler)(RTObject* sender, WXRoutedEventArgs* e);
#endif // __WXRoutedEventHandler__DEFINED

// Windows.UI.Xaml.SizeChangedEventHandler
#ifndef __WXSizeChangedEventHandler__DEFINED
#define __WXSizeChangedEventHandler__DEFINED
typedef void(^WXSizeChangedEventHandler)(RTObject* sender, WXSizeChangedEventArgs* e);
#endif // __WXSizeChangedEventHandler__DEFINED


#import <Foundation/Foundation.h>

// [struct] Windows.UI.Xaml.Controls.Maps.MapZoomLevelRange
OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapZoomLevelRange : NSObject
+ (instancetype)new;
@property double min;
@property double max;
@end

// Windows.UI.Xaml.Controls.Maps.MapStyleSheetEntries
#ifndef __WUXCMMapStyleSheetEntries_DEFINED__
#define __WUXCMMapStyleSheetEntries_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapStyleSheetEntries : RTObject
+ (NSString *)adminDistrict;
+ (NSString *)adminDistrictCapital;
+ (NSString *)airport;
+ (NSString *)area;
+ (NSString *)arterialRoad;
+ (NSString *)building;
+ (NSString *)business;
+ (NSString *)capital;
+ (NSString *)cemetery;
+ (NSString *)continent;
+ (NSString *)controlledAccessHighway;
+ (NSString *)countryRegion;
+ (NSString *)countryRegionCapital;
+ (NSString *)district;
+ (NSString *)drivingRoute;
+ (NSString *)education;
+ (NSString *)educationBuilding;
+ (NSString *)foodPoint;
+ (NSString *)forest;
+ (NSString *)golfCourse;
+ (NSString *)highSpeedRamp;
+ (NSString *)highway;
+ (NSString *)indigenousPeoplesReserve;
+ (NSString *)island;
+ (NSString *)majorRoad;
+ (NSString *)medical;
+ (NSString *)medicalBuilding;
+ (NSString *)military;
+ (NSString *)naturalPoint;
+ (NSString *)nautical;
+ (NSString *)neighborhood;
+ (NSString *)park;
+ (NSString *)peak;
+ (NSString *)playingField;
+ (NSString *)point;
+ (NSString *)pointOfInterest;
+ (NSString *)political;
+ (NSString *)populatedPlace;
+ (NSString *)railway;
+ (NSString *)ramp;
+ (NSString *)reserve;
+ (NSString *)river;
+ (NSString *)road;
+ (NSString *)roadExit;
+ (NSString *)roadShield;
+ (NSString *)routeLine;
+ (NSString *)runway;
+ (NSString *)sand;
+ (NSString *)shoppingCenter;
+ (NSString *)stadium;
+ (NSString *)street;
+ (NSString *)structure;
+ (NSString *)tollRoad;
+ (NSString *)trail;
+ (NSString *)transit;
+ (NSString *)transitBuilding;
+ (NSString *)transportation;
+ (NSString *)unpavedStreet;
+ (NSString *)vegetation;
+ (NSString *)volcanicPeak;
+ (NSString *)walkingRoute;
+ (NSString *)water;
+ (NSString *)waterPoint;
+ (NSString *)waterRoute;
@end

#endif // __WUXCMMapStyleSheetEntries_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapStyleSheetEntryStates
#ifndef __WUXCMMapStyleSheetEntryStates_DEFINED__
#define __WUXCMMapStyleSheetEntryStates_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapStyleSheetEntryStates : RTObject
+ (NSString *)disabled;
+ (NSString *)hover;
+ (NSString *)selected;
@end

#endif // __WUXCMMapStyleSheetEntryStates_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapActualCameraChangedEventArgs
#ifndef __WUXCMMapActualCameraChangedEventArgs_DEFINED__
#define __WUXCMMapActualCameraChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapActualCameraChangedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUXCMMapCamera* camera;
@property (readonly) WUXCMMapCameraChangeReason changeReason;
@end

#endif // __WUXCMMapActualCameraChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapActualCameraChangingEventArgs
#ifndef __WUXCMMapActualCameraChangingEventArgs_DEFINED__
#define __WUXCMMapActualCameraChangingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapActualCameraChangingEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUXCMMapCamera* camera;
@property (readonly) WUXCMMapCameraChangeReason changeReason;
@end

#endif // __WUXCMMapActualCameraChangingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapContextRequestedEventArgs
#ifndef __WUXCMMapContextRequestedEventArgs_DEFINED__
#define __WUXCMMapContextRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapContextRequestedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGeopoint* location;
@property (readonly) NSArray* /* WUXCMMapElement* */ mapElements;
@property (readonly) WFPoint* position;
@end

#endif // __WUXCMMapContextRequestedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapCustomExperienceChangedEventArgs
#ifndef __WUXCMMapCustomExperienceChangedEventArgs_DEFINED__
#define __WUXCMMapCustomExperienceChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapCustomExperienceChangedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXCMMapCustomExperienceChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapElementClickEventArgs
#ifndef __WUXCMMapElementClickEventArgs_DEFINED__
#define __WUXCMMapElementClickEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapElementClickEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGeopoint* location;
@property (readonly) NSMutableArray* /* WUXCMMapElement* */ mapElements;
@property (readonly) WFPoint* position;
@end

#endif // __WUXCMMapElementClickEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapElementPointerEnteredEventArgs
#ifndef __WUXCMMapElementPointerEnteredEventArgs_DEFINED__
#define __WUXCMMapElementPointerEnteredEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapElementPointerEnteredEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGeopoint* location;
@property (readonly) WUXCMMapElement* mapElement;
@property (readonly) WFPoint* position;
@end

#endif // __WUXCMMapElementPointerEnteredEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapElementPointerExitedEventArgs
#ifndef __WUXCMMapElementPointerExitedEventArgs_DEFINED__
#define __WUXCMMapElementPointerExitedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapElementPointerExitedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGeopoint* location;
@property (readonly) WUXCMMapElement* mapElement;
@property (readonly) WFPoint* position;
@end

#endif // __WUXCMMapElementPointerExitedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapElementsLayerClickEventArgs
#ifndef __WUXCMMapElementsLayerClickEventArgs_DEFINED__
#define __WUXCMMapElementsLayerClickEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapElementsLayerClickEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGeopoint* location;
@property (readonly) NSMutableArray* /* WUXCMMapElement* */ mapElements;
@property (readonly) WFPoint* position;
@end

#endif // __WUXCMMapElementsLayerClickEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapElementsLayerContextRequestedEventArgs
#ifndef __WUXCMMapElementsLayerContextRequestedEventArgs_DEFINED__
#define __WUXCMMapElementsLayerContextRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapElementsLayerContextRequestedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGeopoint* location;
@property (readonly) NSArray* /* WUXCMMapElement* */ mapElements;
@property (readonly) WFPoint* position;
@end

#endif // __WUXCMMapElementsLayerContextRequestedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapElementsLayerPointerEnteredEventArgs
#ifndef __WUXCMMapElementsLayerPointerEnteredEventArgs_DEFINED__
#define __WUXCMMapElementsLayerPointerEnteredEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapElementsLayerPointerEnteredEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGeopoint* location;
@property (readonly) WUXCMMapElement* mapElement;
@property (readonly) WFPoint* position;
@end

#endif // __WUXCMMapElementsLayerPointerEnteredEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapElementsLayerPointerExitedEventArgs
#ifndef __WUXCMMapElementsLayerPointerExitedEventArgs_DEFINED__
#define __WUXCMMapElementsLayerPointerExitedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapElementsLayerPointerExitedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGeopoint* location;
@property (readonly) WUXCMMapElement* mapElement;
@property (readonly) WFPoint* position;
@end

#endif // __WUXCMMapElementsLayerPointerExitedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapRightTappedEventArgs
#ifndef __WUXCMMapRightTappedEventArgs_DEFINED__
#define __WUXCMMapRightTappedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapRightTappedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGeopoint* location;
@property (readonly) WFPoint* position;
@end

#endif // __WUXCMMapRightTappedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTargetCameraChangedEventArgs
#ifndef __WUXCMMapTargetCameraChangedEventArgs_DEFINED__
#define __WUXCMMapTargetCameraChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapTargetCameraChangedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUXCMMapCamera* camera;
@property (readonly) WUXCMMapCameraChangeReason changeReason;
@end

#endif // __WUXCMMapTargetCameraChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileBitmapRequestDeferral
#ifndef __WUXCMMapTileBitmapRequestDeferral_DEFINED__
#define __WUXCMMapTileBitmapRequestDeferral_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapTileBitmapRequestDeferral : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WUXCMMapTileBitmapRequestDeferral_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileBitmapRequest
#ifndef __WUXCMMapTileBitmapRequest_DEFINED__
#define __WUXCMMapTileBitmapRequest_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapTileBitmapRequest : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject<WSSIRandomAccessStreamReference>* pixelData;
- (WUXCMMapTileBitmapRequestDeferral*)getDeferral;
@end

#endif // __WUXCMMapTileBitmapRequest_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileBitmapRequestedEventArgs
#ifndef __WUXCMMapTileBitmapRequestedEventArgs_DEFINED__
#define __WUXCMMapTileBitmapRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapTileBitmapRequestedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUXCMMapTileBitmapRequest* request;
@property (readonly) int x;
@property (readonly) int y;
@property (readonly) int zoomLevel;
@end

#endif // __WUXCMMapTileBitmapRequestedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileUriRequestDeferral
#ifndef __WUXCMMapTileUriRequestDeferral_DEFINED__
#define __WUXCMMapTileUriRequestDeferral_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapTileUriRequestDeferral : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WUXCMMapTileUriRequestDeferral_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileUriRequest
#ifndef __WUXCMMapTileUriRequest_DEFINED__
#define __WUXCMMapTileUriRequest_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapTileUriRequest : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* uri;
- (WUXCMMapTileUriRequestDeferral*)getDeferral;
@end

#endif // __WUXCMMapTileUriRequest_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileUriRequestedEventArgs
#ifndef __WUXCMMapTileUriRequestedEventArgs_DEFINED__
#define __WUXCMMapTileUriRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapTileUriRequestedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUXCMMapTileUriRequest* request;
@property (readonly) int x;
@property (readonly) int y;
@property (readonly) int zoomLevel;
@end

#endif // __WUXCMMapTileUriRequestedEventArgs_DEFINED__

// Windows.UI.Xaml.DependencyObject
#ifndef __WXDependencyObject_DEFINED__
#define __WXDependencyObject_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WXDependencyObject : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUCCoreDispatcher* dispatcher;
- (RTObject*)getValue:(WXDependencyProperty*)dp;
- (void)setValue:(WXDependencyProperty*)dp value:(RTObject*)value;
- (void)clearValue:(WXDependencyProperty*)dp;
- (RTObject*)readLocalValue:(WXDependencyProperty*)dp;
- (RTObject*)getAnimationBaseValue:(WXDependencyProperty*)dp;
- (int64_t)registerPropertyChangedCallback:(WXDependencyProperty*)dp callback:(WXDependencyPropertyChangedCallback)callback;
- (void)unregisterPropertyChangedCallback:(WXDependencyProperty*)dp token:(int64_t)token;
@end

#endif // __WXDependencyObject_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapCamera
#ifndef __WUXCMMapCamera_DEFINED__
#define __WUXCMMapCamera_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapCamera : WXDependencyObject
+ (WUXCMMapCamera*)makeInstanceWithLocation:(WDGGeopoint*)location ACTIVATOR;
+ (WUXCMMapCamera*)makeInstanceWithLocationAndHeading:(WDGGeopoint*)location headingInDegrees:(double)headingInDegrees ACTIVATOR;
+ (WUXCMMapCamera*)makeInstanceWithLocationHeadingAndPitch:(WDGGeopoint*)location headingInDegrees:(double)headingInDegrees pitchInDegrees:(double)pitchInDegrees ACTIVATOR;
+ (WUXCMMapCamera*)makeInstanceWithLocationHeadingPitchRollAndFieldOfView:(WDGGeopoint*)location headingInDegrees:(double)headingInDegrees pitchInDegrees:(double)pitchInDegrees rollInDegrees:(double)rollInDegrees fieldOfViewInDegrees:(double)fieldOfViewInDegrees ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double roll;
@property double pitch;
@property (retain) WDGGeopoint* location;
@property double heading;
@property double fieldOfView;
@end

#endif // __WUXCMMapCamera_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapCustomExperience
#ifndef __WUXCMMapCustomExperience_DEFINED__
#define __WUXCMMapCustomExperience_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapCustomExperience : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXCMMapCustomExperience_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapElement
#ifndef __WUXCMMapElement_DEFINED__
#define __WUXCMMapElement_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapElement : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property int zIndex;
@property BOOL visible;
@property int mapTabIndex;
@property (retain) RTObject* tag;
@property (retain) NSString * mapStyleSheetEntryState;
@property (retain) NSString * mapStyleSheetEntry;
+ (WXDependencyProperty*)visibleProperty;
+ (WXDependencyProperty*)zIndexProperty;
+ (WXDependencyProperty*)mapTabIndexProperty;
+ (WXDependencyProperty*)mapStyleSheetEntryProperty;
+ (WXDependencyProperty*)mapStyleSheetEntryStateProperty;
+ (WXDependencyProperty*)tagProperty;
@end

#endif // __WUXCMMapElement_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapInputEventArgs
#ifndef __WUXCMMapInputEventArgs_DEFINED__
#define __WUXCMMapInputEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapInputEventArgs : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGeopoint* location;
@property (readonly) WFPoint* position;
@end

#endif // __WUXCMMapInputEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapItemsControl
#ifndef __WUXCMMapItemsControl_DEFINED__
#define __WUXCMMapItemsControl_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapItemsControl : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject* itemsSource;
@property (retain) WXDataTemplate* itemTemplate;
@property (readonly) NSMutableArray* /* WXDependencyObject* */ items;
+ (WXDependencyProperty*)itemTemplateProperty;
+ (WXDependencyProperty*)itemsProperty;
+ (WXDependencyProperty*)itemsSourceProperty;
@end

#endif // __WUXCMMapItemsControl_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapLayer
#ifndef __WUXCMMapLayer_DEFINED__
#define __WUXCMMapLayer_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapLayer : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property int zIndex;
@property BOOL visible;
@property int mapTabIndex;
+ (WXDependencyProperty*)mapTabIndexProperty;
+ (WXDependencyProperty*)visibleProperty;
+ (WXDependencyProperty*)zIndexProperty;
@end

#endif // __WUXCMMapLayer_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapModel3D
#ifndef __WUXCMMapModel3D_DEFINED__
#define __WUXCMMapModel3D_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapModel3D : WXDependencyObject
+ (void)createFrom3MFAsync:(RTObject<WSSIRandomAccessStreamReference>*)source success:(void (^)(WUXCMMapModel3D*))success failure:(void (^)(NSError*))failure;
+ (void)createFrom3MFWithShadingOptionAsync:(RTObject<WSSIRandomAccessStreamReference>*)source shadingOption:(WUXCMMapModel3DShadingOption)shadingOption success:(void (^)(WUXCMMapModel3D*))success failure:(void (^)(NSError*))failure;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXCMMapModel3D_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapRouteView
#ifndef __WUXCMMapRouteView_DEFINED__
#define __WUXCMMapRouteView_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapRouteView : WXDependencyObject
+ (WUXCMMapRouteView*)makeInstanceWithMapRoute:(WSMMapRoute*)route ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUColor* routeColor;
@property (retain) WUColor* outlineColor;
@property (readonly) WSMMapRoute* route;
@end

#endif // __WUXCMMapRouteView_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapScene
#ifndef __WUXCMMapScene_DEFINED__
#define __WUXCMMapScene_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapScene : WXDependencyObject
+ (WUXCMMapScene*)createFromBoundingBox:(WDGGeoboundingBox*)bounds;
+ (WUXCMMapScene*)createFromBoundingBoxWithHeadingAndPitch:(WDGGeoboundingBox*)bounds headingInDegrees:(double)headingInDegrees pitchInDegrees:(double)pitchInDegrees;
+ (WUXCMMapScene*)createFromCamera:(WUXCMMapCamera*)camera;
+ (WUXCMMapScene*)createFromLocation:(WDGGeopoint*)location;
+ (WUXCMMapScene*)createFromLocationWithHeadingAndPitch:(WDGGeopoint*)location headingInDegrees:(double)headingInDegrees pitchInDegrees:(double)pitchInDegrees;
+ (WUXCMMapScene*)createFromLocationAndRadius:(WDGGeopoint*)location radiusInMeters:(double)radiusInMeters;
+ (WUXCMMapScene*)createFromLocationAndRadiusWithHeadingAndPitch:(WDGGeopoint*)location radiusInMeters:(double)radiusInMeters headingInDegrees:(double)headingInDegrees pitchInDegrees:(double)pitchInDegrees;
+ (WUXCMMapScene*)createFromLocations:(id<NSFastEnumeration> /* WDGGeopoint* */)locations;
+ (WUXCMMapScene*)createFromLocationsWithHeadingAndPitch:(id<NSFastEnumeration> /* WDGGeopoint* */)locations headingInDegrees:(double)headingInDegrees pitchInDegrees:(double)pitchInDegrees;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUXCMMapCamera* targetCamera;
- (EventRegistrationToken)addTargetCameraChangedEvent:(void(^)(WUXCMMapScene*, WUXCMMapTargetCameraChangedEventArgs*))del;
- (void)removeTargetCameraChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCMMapScene_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapStyleSheet
#ifndef __WUXCMMapStyleSheet_DEFINED__
#define __WUXCMMapStyleSheet_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapStyleSheet : WXDependencyObject
+ (WUXCMMapStyleSheet*)aerial;
+ (WUXCMMapStyleSheet*)aerialWithOverlay;
+ (WUXCMMapStyleSheet*)roadLight;
+ (WUXCMMapStyleSheet*)roadDark;
+ (WUXCMMapStyleSheet*)roadHighContrastLight;
+ (WUXCMMapStyleSheet*)roadHighContrastDark;
+ (WUXCMMapStyleSheet*)combine:(id<NSFastEnumeration> /* WUXCMMapStyleSheet* */)styleSheets;
+ (WUXCMMapStyleSheet*)parseFromJson:(NSString *)styleAsJson;
+ (BOOL)tryParseFromJson:(NSString *)styleAsJson styleSheet:(WUXCMMapStyleSheet**)styleSheet;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXCMMapStyleSheet_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileDataSource
#ifndef __WUXCMMapTileDataSource_DEFINED__
#define __WUXCMMapTileDataSource_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapTileDataSource : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXCMMapTileDataSource_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileSource
#ifndef __WUXCMMapTileSource_DEFINED__
#define __WUXCMMapTileSource_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapTileSource : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isTransparencyEnabled;
@property BOOL isRetryEnabled;
@property BOOL isFadingEnabled;
@property (retain) WUXCMMapTileDataSource* dataSource;
@property (retain) WDGGeoboundingBox* bounds;
@property BOOL allowOverstretch;
@property (retain) WUXCMMapZoomLevelRange* zoomLevelRange;
@property int zIndex;
@property BOOL visible;
@property int tilePixelSize;
@property WUXCMMapTileLayer layer;
+ (WXDependencyProperty*)allowOverstretchProperty;
+ (WXDependencyProperty*)boundsProperty;
+ (WXDependencyProperty*)dataSourceProperty;
+ (WXDependencyProperty*)isFadingEnabledProperty;
+ (WXDependencyProperty*)isRetryEnabledProperty;
+ (WXDependencyProperty*)isTransparencyEnabledProperty;
+ (WXDependencyProperty*)layerProperty;
+ (WXDependencyProperty*)tilePixelSizeProperty;
+ (WXDependencyProperty*)visibleProperty;
+ (WXDependencyProperty*)zIndexProperty;
+ (WXDependencyProperty*)zoomLevelRangeProperty;
@end

#endif // __WUXCMMapTileSource_DEFINED__

// Windows.UI.Xaml.Controls.Maps.StreetsidePanorama
#ifndef __WUXCMStreetsidePanorama_DEFINED__
#define __WUXCMStreetsidePanorama_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMStreetsidePanorama : WXDependencyObject
+ (void)findNearbyWithLocationAsync:(WDGGeopoint*)location success:(void (^)(WUXCMStreetsidePanorama*))success failure:(void (^)(NSError*))failure;
+ (void)findNearbyWithLocationAndRadiusAsync:(WDGGeopoint*)location radiusInMeters:(double)radiusInMeters success:(void (^)(WUXCMStreetsidePanorama*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGeopoint* location;
@end

#endif // __WUXCMStreetsidePanorama_DEFINED__

// Windows.UI.Xaml.Controls.Maps.CustomMapTileDataSource
#ifndef __WUXCMCustomMapTileDataSource_DEFINED__
#define __WUXCMCustomMapTileDataSource_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMCustomMapTileDataSource : WUXCMMapTileDataSource
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addBitmapRequestedEvent:(void(^)(WUXCMCustomMapTileDataSource*, WUXCMMapTileBitmapRequestedEventArgs*))del;
- (void)removeBitmapRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCMCustomMapTileDataSource_DEFINED__

// Windows.UI.Xaml.Controls.Maps.HttpMapTileDataSource
#ifndef __WUXCMHttpMapTileDataSource_DEFINED__
#define __WUXCMHttpMapTileDataSource_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMHttpMapTileDataSource : WUXCMMapTileDataSource
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * uriFormatString;
@property BOOL allowCaching;
@property (readonly) NSMutableDictionary* /* NSString *, NSString * */ additionalRequestHeaders;
- (EventRegistrationToken)addUriRequestedEvent:(void(^)(WUXCMHttpMapTileDataSource*, WUXCMMapTileUriRequestedEventArgs*))del;
- (void)removeUriRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCMHttpMapTileDataSource_DEFINED__

// Windows.UI.Xaml.Controls.Maps.LocalMapTileDataSource
#ifndef __WUXCMLocalMapTileDataSource_DEFINED__
#define __WUXCMLocalMapTileDataSource_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMLocalMapTileDataSource : WUXCMMapTileDataSource
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * uriFormatString;
- (EventRegistrationToken)addUriRequestedEvent:(void(^)(WUXCMLocalMapTileDataSource*, WUXCMMapTileUriRequestedEventArgs*))del;
- (void)removeUriRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCMLocalMapTileDataSource_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapBillboard
#ifndef __WUXCMMapBillboard_DEFINED__
#define __WUXCMMapBillboard_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapBillboard : WUXCMMapElement
+ (WUXCMMapBillboard*)makeInstanceFromCamera:(WUXCMMapCamera*)camera ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFPoint* normalizedAnchorPoint;
@property (retain) WDGGeopoint* location;
@property (retain) RTObject<WSSIRandomAccessStreamReference>* image;
@property WUXCMMapElementCollisionBehavior collisionBehaviorDesired;
@property (readonly) WUXCMMapCamera* referenceCamera;
+ (WXDependencyProperty*)collisionBehaviorDesiredProperty;
+ (WXDependencyProperty*)locationProperty;
+ (WXDependencyProperty*)normalizedAnchorPointProperty;
@end

#endif // __WUXCMMapBillboard_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapElement3D
#ifndef __WUXCMMapElement3D_DEFINED__
#define __WUXCMMapElement3D_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapElement3D : WUXCMMapElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFNVector3* scale;
@property double roll;
@property double pitch;
@property (retain) WUXCMMapModel3D* model;
@property (retain) WDGGeopoint* location;
@property double heading;
+ (WXDependencyProperty*)headingProperty;
+ (WXDependencyProperty*)locationProperty;
+ (WXDependencyProperty*)pitchProperty;
+ (WXDependencyProperty*)rollProperty;
+ (WXDependencyProperty*)scaleProperty;
@end

#endif // __WUXCMMapElement3D_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapElementsLayer
#ifndef __WUXCMMapElementsLayer_DEFINED__
#define __WUXCMMapElementsLayer_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapElementsLayer : WUXCMMapLayer
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSMutableArray* /* WUXCMMapElement* */ mapElements;
+ (WXDependencyProperty*)mapElementsProperty;
- (EventRegistrationToken)addMapContextRequestedEvent:(void(^)(WUXCMMapElementsLayer*, WUXCMMapElementsLayerContextRequestedEventArgs*))del;
- (void)removeMapContextRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapElementClickEvent:(void(^)(WUXCMMapElementsLayer*, WUXCMMapElementsLayerClickEventArgs*))del;
- (void)removeMapElementClickEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapElementPointerEnteredEvent:(void(^)(WUXCMMapElementsLayer*, WUXCMMapElementsLayerPointerEnteredEventArgs*))del;
- (void)removeMapElementPointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapElementPointerExitedEvent:(void(^)(WUXCMMapElementsLayer*, WUXCMMapElementsLayerPointerExitedEventArgs*))del;
- (void)removeMapElementPointerExitedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCMMapElementsLayer_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapIcon
#ifndef __WUXCMMapIcon_DEFINED__
#define __WUXCMMapIcon_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapIcon : WUXCMMapElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * title;
@property (retain) WFPoint* normalizedAnchorPoint;
@property (retain) WDGGeopoint* location;
@property (retain) RTObject<WSSIRandomAccessStreamReference>* image;
@property WUXCMMapElementCollisionBehavior collisionBehaviorDesired;
+ (WXDependencyProperty*)locationProperty;
+ (WXDependencyProperty*)normalizedAnchorPointProperty;
+ (WXDependencyProperty*)titleProperty;
+ (WXDependencyProperty*)collisionBehaviorDesiredProperty;
@end

#endif // __WUXCMMapIcon_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapPolygon
#ifndef __WUXCMMapPolygon_DEFINED__
#define __WUXCMMapPolygon_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapPolygon : WUXCMMapElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double strokeThickness;
@property BOOL strokeDashed;
@property (retain) WUColor* strokeColor;
@property (retain) WDGGeopath* path;
@property (retain) WUColor* fillColor;
@property (readonly) NSMutableArray* /* WDGGeopath* */ paths;
+ (WXDependencyProperty*)pathProperty;
+ (WXDependencyProperty*)strokeDashedProperty;
+ (WXDependencyProperty*)strokeThicknessProperty;
@end

#endif // __WUXCMMapPolygon_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapPolyline
#ifndef __WUXCMMapPolyline_DEFINED__
#define __WUXCMMapPolyline_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapPolyline : WUXCMMapElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double strokeThickness;
@property BOOL strokeDashed;
@property (retain) WUColor* strokeColor;
@property (retain) WDGGeopath* path;
+ (WXDependencyProperty*)pathProperty;
+ (WXDependencyProperty*)strokeDashedProperty;
@end

#endif // __WUXCMMapPolyline_DEFINED__

// Windows.UI.Xaml.Controls.Maps.StreetsideExperience
#ifndef __WUXCMStreetsideExperience_DEFINED__
#define __WUXCMStreetsideExperience_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMStreetsideExperience : WUXCMMapCustomExperience
+ (WUXCMStreetsideExperience*)makeInstanceWithPanorama:(WUXCMStreetsidePanorama*)panorama ACTIVATOR;
+ (WUXCMStreetsideExperience*)makeInstanceWithPanoramaHeadingPitchAndFieldOfView:(WUXCMStreetsidePanorama*)panorama headingInDegrees:(double)headingInDegrees pitchInDegrees:(double)pitchInDegrees fieldOfViewInDegrees:(double)fieldOfViewInDegrees ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL zoomButtonsVisible;
@property BOOL streetLabelsVisible;
@property BOOL overviewMapVisible;
@property BOOL exitButtonVisible;
@property BOOL cursorVisible;
@property BOOL addressTextVisible;
@end

#endif // __WUXCMStreetsideExperience_DEFINED__

// Windows.UI.Xaml.Controls.IControlOverrides
#ifndef __WXCIControlOverrides_DEFINED__
#define __WXCIControlOverrides_DEFINED__

@protocol WXCIControlOverrides
- (void)onPointerEntered:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerPressed:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerMoved:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerReleased:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerExited:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerCaptureLost:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerCanceled:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerWheelChanged:(WUXIPointerRoutedEventArgs*)e;
- (void)onTapped:(WUXITappedRoutedEventArgs*)e;
- (void)onDoubleTapped:(WUXIDoubleTappedRoutedEventArgs*)e;
- (void)onHolding:(WUXIHoldingRoutedEventArgs*)e;
- (void)onRightTapped:(WUXIRightTappedRoutedEventArgs*)e;
- (void)onManipulationStarting:(WUXIManipulationStartingRoutedEventArgs*)e;
- (void)onManipulationInertiaStarting:(WUXIManipulationInertiaStartingRoutedEventArgs*)e;
- (void)onManipulationStarted:(WUXIManipulationStartedRoutedEventArgs*)e;
- (void)onManipulationDelta:(WUXIManipulationDeltaRoutedEventArgs*)e;
- (void)onManipulationCompleted:(WUXIManipulationCompletedRoutedEventArgs*)e;
- (void)onKeyUp:(WUXIKeyRoutedEventArgs*)e;
- (void)onKeyDown:(WUXIKeyRoutedEventArgs*)e;
- (void)onGotFocus:(WXRoutedEventArgs*)e;
- (void)onLostFocus:(WXRoutedEventArgs*)e;
- (void)onDragEnter:(WXDragEventArgs*)e;
- (void)onDragLeave:(WXDragEventArgs*)e;
- (void)onDragOver:(WXDragEventArgs*)e;
- (void)onDrop:(WXDragEventArgs*)e;
@end

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WXCIControlOverrides : RTObject <WXCIControlOverrides>
@end

#endif // __WXCIControlOverrides_DEFINED__

// Windows.UI.Xaml.Controls.IControlOverrides6
#ifndef __WXCIControlOverrides6_DEFINED__
#define __WXCIControlOverrides6_DEFINED__

@protocol WXCIControlOverrides6
- (void)onPreviewKeyDown:(WUXIKeyRoutedEventArgs*)e;
- (void)onPreviewKeyUp:(WUXIKeyRoutedEventArgs*)e;
- (void)onCharacterReceived:(WUXICharacterReceivedRoutedEventArgs*)e;
@end

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WXCIControlOverrides6 : RTObject <WXCIControlOverrides6>
@end

#endif // __WXCIControlOverrides6_DEFINED__

// Windows.UI.Xaml.IFrameworkElementOverrides
#ifndef __WXIFrameworkElementOverrides_DEFINED__
#define __WXIFrameworkElementOverrides_DEFINED__

@protocol WXIFrameworkElementOverrides
- (WFSize*)measureOverride:(WFSize*)availableSize;
- (WFSize*)arrangeOverride:(WFSize*)finalSize;
- (void)onApplyTemplate;
@end

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WXIFrameworkElementOverrides : RTObject <WXIFrameworkElementOverrides>
@end

#endif // __WXIFrameworkElementOverrides_DEFINED__

// Windows.UI.Xaml.IFrameworkElementOverrides2
#ifndef __WXIFrameworkElementOverrides2_DEFINED__
#define __WXIFrameworkElementOverrides2_DEFINED__

@protocol WXIFrameworkElementOverrides2
- (BOOL)goToElementStateCore:(NSString *)stateName useTransitions:(BOOL)useTransitions;
@end

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WXIFrameworkElementOverrides2 : RTObject <WXIFrameworkElementOverrides2>
@end

#endif // __WXIFrameworkElementOverrides2_DEFINED__

// Windows.UI.Xaml.IUIElementOverrides
#ifndef __WXIUIElementOverrides_DEFINED__
#define __WXIUIElementOverrides_DEFINED__

@protocol WXIUIElementOverrides
- (WUXAPAutomationPeer*)onCreateAutomationPeer;
- (void)onDisconnectVisualChildren;
- (id<NSFastEnumeration> /* id<NSFastEnumeration> < WFPoint* > */)findSubElementsForTouchTargeting:(WFPoint*)point boundingRect:(WFRect*)boundingRect;
@end

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WXIUIElementOverrides : RTObject <WXIUIElementOverrides>
@end

#endif // __WXIUIElementOverrides_DEFINED__

// Windows.UI.Xaml.IUIElementOverrides7
#ifndef __WXIUIElementOverrides7_DEFINED__
#define __WXIUIElementOverrides7_DEFINED__

@protocol WXIUIElementOverrides7
- (id<NSFastEnumeration> /* WXDependencyObject* */)getChildrenInTabFocusOrder;
- (void)onProcessKeyboardAccelerators:(WUXIProcessKeyboardAcceleratorEventArgs*)args;
@end

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WXIUIElementOverrides7 : RTObject <WXIUIElementOverrides7>
@end

#endif // __WXIUIElementOverrides7_DEFINED__

// Windows.UI.Xaml.UIElement
#ifndef __WXUIElement_DEFINED__
#define __WXUIElement_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WXUIElement : WXDependencyObject
+ (BOOL)tryStartDirectManipulation:(WUXIPointer*)value;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isTapEnabled;
@property (retain) WUXMProjection* projection;
@property BOOL isRightTapEnabled;
@property BOOL isHoldingEnabled;
@property BOOL isHitTestVisible;
@property BOOL isDoubleTapEnabled;
@property BOOL allowDrop;
@property WUXIManipulationModes manipulationMode;
@property (retain) WUXMRectangleGeometry* clip;
@property (retain) WUXMCacheMode* cacheMode;
@property WXVisibility visibility;
@property BOOL useLayoutRounding;
@property (retain) WUXMATransitionCollection* transitions;
@property (retain) WFPoint* renderTransformOrigin;
@property (retain) WUXMTransform* renderTransform;
@property double opacity;
@property (readonly) WFSize* desiredSize;
@property (readonly) NSArray* /* WUXIPointer* */ pointerCaptures;
@property (readonly) WFSize* renderSize;
@property WUXMElementCompositeMode compositeMode;
@property (retain) WUXMMTransform3D* transform3D;
@property BOOL canDrag;
@property BOOL isAccessKeyScope;
@property BOOL exitDisplayModeOnAccessKeyInvoked;
@property (retain) WUXCPFlyoutBase* contextFlyout;
@property (retain) WXDependencyObject* accessKeyScopeOwner;
@property (retain) NSString * accessKey;
@property double keyTipHorizontalOffset;
@property WXElementHighContrastAdjustment highContrastAdjustment;
@property WUXIXYFocusNavigationStrategy xYFocusUpNavigationStrategy;
@property WUXIXYFocusNavigationStrategy xYFocusRightNavigationStrategy;
@property WUXIXYFocusNavigationStrategy xYFocusLeftNavigationStrategy;
@property WUXIXYFocusKeyboardNavigationMode xYFocusKeyboardNavigation;
@property WUXIXYFocusNavigationStrategy xYFocusDownNavigationStrategy;
@property WUXIKeyboardNavigationMode tabFocusNavigation;
@property double keyTipVerticalOffset;
@property WUXIKeyTipPlacementMode keyTipPlacementMode;
@property (readonly) NSMutableArray* /* WUXMXamlLight* */ lights;
@property (readonly) NSMutableArray* /* WUXIKeyboardAccelerator* */ keyboardAccelerators;
+ (WXDependencyProperty*)opacityProperty;
+ (WXDependencyProperty*)allowDropProperty;
+ (WXDependencyProperty*)cacheModeProperty;
+ (WXDependencyProperty*)clipProperty;
+ (WXRoutedEvent*)doubleTappedEvent;
+ (WXRoutedEvent*)dragEnterEvent;
+ (WXRoutedEvent*)dragLeaveEvent;
+ (WXRoutedEvent*)dragOverEvent;
+ (WXRoutedEvent*)dropEvent;
+ (WXRoutedEvent*)holdingEvent;
+ (WXDependencyProperty*)isDoubleTapEnabledProperty;
+ (WXDependencyProperty*)isHitTestVisibleProperty;
+ (WXDependencyProperty*)isHoldingEnabledProperty;
+ (WXDependencyProperty*)isRightTapEnabledProperty;
+ (WXDependencyProperty*)isTapEnabledProperty;
+ (WXRoutedEvent*)keyDownEvent;
+ (WXRoutedEvent*)keyUpEvent;
+ (WXRoutedEvent*)manipulationCompletedEvent;
+ (WXRoutedEvent*)manipulationDeltaEvent;
+ (WXRoutedEvent*)manipulationInertiaStartingEvent;
+ (WXDependencyProperty*)manipulationModeProperty;
+ (WXRoutedEvent*)manipulationStartedEvent;
+ (WXRoutedEvent*)manipulationStartingEvent;
+ (WXRoutedEvent*)pointerCanceledEvent;
+ (WXRoutedEvent*)pointerCaptureLostEvent;
+ (WXDependencyProperty*)pointerCapturesProperty;
+ (WXRoutedEvent*)pointerEnteredEvent;
+ (WXRoutedEvent*)pointerExitedEvent;
+ (WXRoutedEvent*)pointerMovedEvent;
+ (WXRoutedEvent*)pointerPressedEvent;
+ (WXRoutedEvent*)pointerReleasedEvent;
+ (WXRoutedEvent*)pointerWheelChangedEvent;
+ (WXDependencyProperty*)projectionProperty;
+ (WXDependencyProperty*)renderTransformOriginProperty;
+ (WXDependencyProperty*)renderTransformProperty;
+ (WXRoutedEvent*)rightTappedEvent;
+ (WXRoutedEvent*)tappedEvent;
+ (WXDependencyProperty*)transitionsProperty;
+ (WXDependencyProperty*)useLayoutRoundingProperty;
+ (WXDependencyProperty*)visibilityProperty;
+ (WXDependencyProperty*)compositeModeProperty;
+ (WXDependencyProperty*)transform3DProperty;
+ (WXDependencyProperty*)canDragProperty;
+ (WXDependencyProperty*)accessKeyProperty;
+ (WXDependencyProperty*)isAccessKeyScopeProperty;
+ (WXDependencyProperty*)exitDisplayModeOnAccessKeyInvokedProperty;
+ (WXDependencyProperty*)contextFlyoutProperty;
+ (WXDependencyProperty*)accessKeyScopeOwnerProperty;
+ (WXDependencyProperty*)xYFocusKeyboardNavigationProperty;
+ (WXDependencyProperty*)xYFocusLeftNavigationStrategyProperty;
+ (WXDependencyProperty*)xYFocusRightNavigationStrategyProperty;
+ (WXDependencyProperty*)xYFocusUpNavigationStrategyProperty;
+ (WXDependencyProperty*)highContrastAdjustmentProperty;
+ (WXDependencyProperty*)xYFocusDownNavigationStrategyProperty;
+ (WXDependencyProperty*)keyTipHorizontalOffsetProperty;
+ (WXDependencyProperty*)keyTipPlacementModeProperty;
+ (WXDependencyProperty*)keyTipVerticalOffsetProperty;
+ (WXDependencyProperty*)lightsProperty;
+ (WXDependencyProperty*)tabFocusNavigationProperty;
+ (WXRoutedEvent*)noFocusCandidateFoundEvent;
+ (WXRoutedEvent*)losingFocusEvent;
+ (WXRoutedEvent*)gettingFocusEvent;
+ (WXRoutedEvent*)characterReceivedEvent;
+ (WXRoutedEvent*)previewKeyUpEvent;
+ (WXRoutedEvent*)previewKeyDownEvent;
- (EventRegistrationToken)addDoubleTappedEvent:(WUXIDoubleTappedEventHandler)del;
- (void)removeDoubleTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragEnterEvent:(WXDragEventHandler)del;
- (void)removeDragEnterEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragLeaveEvent:(WXDragEventHandler)del;
- (void)removeDragLeaveEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragOverEvent:(WXDragEventHandler)del;
- (void)removeDragOverEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDropEvent:(WXDragEventHandler)del;
- (void)removeDropEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addGotFocusEvent:(WXRoutedEventHandler)del;
- (void)removeGotFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHoldingEvent:(WUXIHoldingEventHandler)del;
- (void)removeHoldingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyDownEvent:(WUXIKeyEventHandler)del;
- (void)removeKeyDownEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyUpEvent:(WUXIKeyEventHandler)del;
- (void)removeKeyUpEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLostFocusEvent:(WXRoutedEventHandler)del;
- (void)removeLostFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationCompletedEvent:(WUXIManipulationCompletedEventHandler)del;
- (void)removeManipulationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationDeltaEvent:(WUXIManipulationDeltaEventHandler)del;
- (void)removeManipulationDeltaEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationInertiaStartingEvent:(WUXIManipulationInertiaStartingEventHandler)del;
- (void)removeManipulationInertiaStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationStartedEvent:(WUXIManipulationStartedEventHandler)del;
- (void)removeManipulationStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationStartingEvent:(WUXIManipulationStartingEventHandler)del;
- (void)removeManipulationStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerCanceledEvent:(WUXIPointerEventHandler)del;
- (void)removePointerCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerCaptureLostEvent:(WUXIPointerEventHandler)del;
- (void)removePointerCaptureLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerEnteredEvent:(WUXIPointerEventHandler)del;
- (void)removePointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerExitedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerMovedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerMovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerPressedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerReleasedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerReleasedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerWheelChangedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerWheelChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRightTappedEvent:(WUXIRightTappedEventHandler)del;
- (void)removeRightTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTappedEvent:(WUXITappedEventHandler)del;
- (void)removeTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragStartingEvent:(void(^)(WXUIElement*, WXDragStartingEventArgs*))del;
- (void)removeDragStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDropCompletedEvent:(void(^)(WXUIElement*, WXDropCompletedEventArgs*))del;
- (void)removeDropCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccessKeyDisplayDismissedEvent:(void(^)(WXUIElement*, WUXIAccessKeyDisplayDismissedEventArgs*))del;
- (void)removeAccessKeyDisplayDismissedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccessKeyDisplayRequestedEvent:(void(^)(WXUIElement*, WUXIAccessKeyDisplayRequestedEventArgs*))del;
- (void)removeAccessKeyDisplayRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccessKeyInvokedEvent:(void(^)(WXUIElement*, WUXIAccessKeyInvokedEventArgs*))del;
- (void)removeAccessKeyInvokedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addContextCanceledEvent:(void(^)(WXUIElement*, WXRoutedEventArgs*))del;
- (void)removeContextCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addContextRequestedEvent:(void(^)(WXUIElement*, WUXIContextRequestedEventArgs*))del;
- (void)removeContextRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addGettingFocusEvent:(void(^)(WXUIElement*, WUXIGettingFocusEventArgs*))del;
- (void)removeGettingFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLosingFocusEvent:(void(^)(WXUIElement*, WUXILosingFocusEventArgs*))del;
- (void)removeLosingFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNoFocusCandidateFoundEvent:(void(^)(WXUIElement*, WUXINoFocusCandidateFoundEventArgs*))del;
- (void)removeNoFocusCandidateFoundEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCharacterReceivedEvent:(void(^)(WXUIElement*, WUXICharacterReceivedRoutedEventArgs*))del;
- (void)removeCharacterReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPreviewKeyDownEvent:(WUXIKeyEventHandler)del;
- (void)removePreviewKeyDownEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPreviewKeyUpEvent:(WUXIKeyEventHandler)del;
- (void)removePreviewKeyUpEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addProcessKeyboardAcceleratorsEvent:(void(^)(WXUIElement*, WUXIProcessKeyboardAcceleratorEventArgs*))del;
- (void)removeProcessKeyboardAcceleratorsEvent:(EventRegistrationToken)tok;
- (void)measure:(WFSize*)availableSize;
- (void)arrange:(WFRect*)finalRect;
- (BOOL)capturePointer:(WUXIPointer*)value;
- (void)releasePointerCapture:(WUXIPointer*)value;
- (void)releasePointerCaptures;
- (void)addHandler:(WXRoutedEvent*)routedEvent handler:(RTObject*)handler handledEventsToo:(BOOL)handledEventsToo;
- (void)removeHandler:(WXRoutedEvent*)routedEvent handler:(RTObject*)handler;
- (WUXMGeneralTransform*)transformToVisual:(WXUIElement*)visual;
- (void)invalidateMeasure;
- (void)invalidateArrange;
- (void)updateLayout;
- (WUXAPAutomationPeer*)onCreateAutomationPeer;
- (void)onDisconnectVisualChildren;
- (id<NSFastEnumeration> /* id<NSFastEnumeration> < WFPoint* > */)findSubElementsForTouchTargeting:(WFPoint*)point boundingRect:(WFRect*)boundingRect;
- (BOOL)cancelDirectManipulations;
- (void)startDragAsync:(WUIPointerPoint*)pointerPoint success:(void (^)(WADDataPackageOperation))success failure:(void (^)(NSError*))failure;
- (void)startBringIntoView;
- (void)startBringIntoViewWithOptions:(WXBringIntoViewOptions*)options;
- (void)tryInvokeKeyboardAccelerator:(WUXIProcessKeyboardAcceleratorEventArgs*)args;
- (id<NSFastEnumeration> /* WXDependencyObject* */)getChildrenInTabFocusOrder;
- (void)onProcessKeyboardAccelerators:(WUXIProcessKeyboardAcceleratorEventArgs*)args;
@end

#endif // __WXUIElement_DEFINED__

// Windows.UI.Xaml.FrameworkElement
#ifndef __WXFrameworkElement_DEFINED__
#define __WXFrameworkElement_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WXFrameworkElement : WXUIElement
+ (void)deferTree:(WXDependencyObject*)element;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double height;
@property WXFlowDirection flowDirection;
@property (retain) RTObject* dataContext;
@property (retain) NSString * name;
@property double minWidth;
@property (retain) WXResourceDictionary* resources;
@property double minHeight;
@property double maxWidth;
@property double maxHeight;
@property (retain) WXThickness* margin;
@property (retain) NSString * language;
@property WXHorizontalAlignment horizontalAlignment;
@property WXVerticalAlignment verticalAlignment;
@property double width;
@property (retain) RTObject* tag;
@property (retain) WXStyle* style;
@property (readonly) double actualWidth;
@property (readonly) WFUri* baseUri;
@property (readonly) double actualHeight;
@property (readonly) WXDependencyObject* parent;
@property (readonly) WXTriggerCollection* triggers;
@property WXElementTheme requestedTheme;
@property (retain) WXThickness* focusVisualSecondaryThickness;
@property (retain) WUXMBrush* focusVisualSecondaryBrush;
@property (retain) WXThickness* focusVisualPrimaryThickness;
@property (retain) WUXMBrush* focusVisualPrimaryBrush;
@property (retain) WXThickness* focusVisualMargin;
@property BOOL allowFocusWhenDisabled;
@property BOOL allowFocusOnInteraction;
@property (readonly) WXElementTheme actualTheme;
+ (WXDependencyProperty*)nameProperty;
+ (WXDependencyProperty*)actualHeightProperty;
+ (WXDependencyProperty*)actualWidthProperty;
+ (WXDependencyProperty*)dataContextProperty;
+ (WXDependencyProperty*)flowDirectionProperty;
+ (WXDependencyProperty*)heightProperty;
+ (WXDependencyProperty*)horizontalAlignmentProperty;
+ (WXDependencyProperty*)languageProperty;
+ (WXDependencyProperty*)marginProperty;
+ (WXDependencyProperty*)maxHeightProperty;
+ (WXDependencyProperty*)maxWidthProperty;
+ (WXDependencyProperty*)minHeightProperty;
+ (WXDependencyProperty*)minWidthProperty;
+ (WXDependencyProperty*)styleProperty;
+ (WXDependencyProperty*)tagProperty;
+ (WXDependencyProperty*)verticalAlignmentProperty;
+ (WXDependencyProperty*)widthProperty;
+ (WXDependencyProperty*)requestedThemeProperty;
+ (WXDependencyProperty*)focusVisualSecondaryThicknessProperty;
+ (WXDependencyProperty*)allowFocusOnInteractionProperty;
+ (WXDependencyProperty*)allowFocusWhenDisabledProperty;
+ (WXDependencyProperty*)focusVisualMarginProperty;
+ (WXDependencyProperty*)focusVisualPrimaryBrushProperty;
+ (WXDependencyProperty*)focusVisualPrimaryThicknessProperty;
+ (WXDependencyProperty*)focusVisualSecondaryBrushProperty;
+ (WXDependencyProperty*)actualThemeProperty;
- (EventRegistrationToken)addLayoutUpdatedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeLayoutUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadedEvent:(WXRoutedEventHandler)del;
- (void)removeLoadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSizeChangedEvent:(WXSizeChangedEventHandler)del;
- (void)removeSizeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnloadedEvent:(WXRoutedEventHandler)del;
- (void)removeUnloadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDataContextChangedEvent:(void(^)(WXFrameworkElement*, WXDataContextChangedEventArgs*))del;
- (void)removeDataContextChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadingEvent:(void(^)(WXFrameworkElement*, RTObject*))del;
- (void)removeLoadingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addActualThemeChangedEvent:(void(^)(WXFrameworkElement*, RTObject*))del;
- (void)removeActualThemeChangedEvent:(EventRegistrationToken)tok;
- (RTObject*)findName:(NSString *)name;
- (void)setBinding:(WXDependencyProperty*)dp binding:(WUXDBindingBase*)binding;
- (WFSize*)measureOverride:(WFSize*)availableSize;
- (WFSize*)arrangeOverride:(WFSize*)finalSize;
- (void)onApplyTemplate;
- (WUXDBindingExpression*)getBindingExpression:(WXDependencyProperty*)dp;
- (BOOL)goToElementStateCore:(NSString *)stateName useTransitions:(BOOL)useTransitions;
@end

#endif // __WXFrameworkElement_DEFINED__

// Windows.UI.Xaml.Controls.Control
#ifndef __WXCControl_DEFINED__
#define __WXCControl_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WXCControl : WXFrameworkElement
+ (BOOL)getIsTemplateFocusTarget:(WXFrameworkElement*)element;
+ (void)setIsTemplateFocusTarget:(WXFrameworkElement*)element value:(BOOL)value;
+ (BOOL)getIsTemplateKeyTipTarget:(WXDependencyObject*)element;
+ (void)setIsTemplateKeyTipTarget:(WXDependencyObject*)element value:(BOOL)value;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double fontSize;
@property (retain) WUXMFontFamily* fontFamily;
@property int tabIndex;
@property int characterSpacing;
@property (retain) WXThickness* borderThickness;
@property (retain) WUXMBrush* borderBrush;
@property WUTFontStretch fontStretch;
@property BOOL isTabStop;
@property BOOL isEnabled;
@property WXHorizontalAlignment horizontalContentAlignment;
@property (retain) WXThickness* padding;
@property (retain) WUXMBrush* foreground;
@property (retain) WUTFontWeight* fontWeight;
@property WUTFontStyle fontStyle;
@property (retain) WUXMBrush* background;
@property WXVerticalAlignment verticalContentAlignment;
@property (retain) WXCControlTemplate* Template;
@property WUXIKeyboardNavigationMode tabNavigation;
@property (readonly) WXFocusState focusState;
@property BOOL isTextScaleFactorEnabled;
@property BOOL useSystemFocusVisuals;
@property (retain) WXDependencyObject* xYFocusDown;
@property (retain) WXDependencyObject* xYFocusUp;
@property BOOL isFocusEngagementEnabled;
@property (retain) WXDependencyObject* xYFocusLeft;
@property (retain) WXDependencyObject* xYFocusRight;
@property WXCRequiresPointer requiresPointer;
@property WXElementSoundMode elementSoundMode;
@property BOOL isFocusEngaged;
@property (retain) WFUri* defaultStyleResourceUri;
+ (WXDependencyProperty*)fontWeightProperty;
+ (WXDependencyProperty*)backgroundProperty;
+ (WXDependencyProperty*)borderBrushProperty;
+ (WXDependencyProperty*)borderThicknessProperty;
+ (WXDependencyProperty*)characterSpacingProperty;
+ (WXDependencyProperty*)defaultStyleKeyProperty;
+ (WXDependencyProperty*)focusStateProperty;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)fontStretchProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)foregroundProperty;
+ (WXDependencyProperty*)horizontalContentAlignmentProperty;
+ (WXDependencyProperty*)isEnabledProperty;
+ (WXDependencyProperty*)isTabStopProperty;
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)tabIndexProperty;
+ (WXDependencyProperty*)tabNavigationProperty;
+ (WXDependencyProperty*)templateProperty;
+ (WXDependencyProperty*)verticalContentAlignmentProperty;
+ (WXDependencyProperty*)isTextScaleFactorEnabledProperty;
+ (WXDependencyProperty*)isTemplateFocusTargetProperty;
+ (WXDependencyProperty*)useSystemFocusVisualsProperty;
+ (WXDependencyProperty*)requiresPointerProperty;
+ (WXDependencyProperty*)xYFocusDownProperty;
+ (WXDependencyProperty*)xYFocusLeftProperty;
+ (WXDependencyProperty*)xYFocusUpProperty;
+ (WXDependencyProperty*)xYFocusRightProperty;
+ (WXDependencyProperty*)elementSoundModeProperty;
+ (WXDependencyProperty*)isFocusEngagedProperty;
+ (WXDependencyProperty*)isFocusEngagementEnabledProperty;
+ (WXDependencyProperty*)isTemplateKeyTipTargetProperty;
+ (WXDependencyProperty*)defaultStyleResourceUriProperty;
- (EventRegistrationToken)addIsEnabledChangedEvent:(WXDependencyPropertyChangedEventHandler)del;
- (void)removeIsEnabledChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFocusDisengagedEvent:(void(^)(WXCControl*, WXCFocusDisengagedEventArgs*))del;
- (void)removeFocusDisengagedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFocusEngagedEvent:(void(^)(WXCControl*, WXCFocusEngagedEventArgs*))del;
- (void)removeFocusEngagedEvent:(EventRegistrationToken)tok;
- (BOOL)applyTemplate;
- (BOOL)focus:(WXFocusState)value;
- (void)onPointerEntered:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerPressed:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerMoved:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerReleased:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerExited:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerCaptureLost:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerCanceled:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerWheelChanged:(WUXIPointerRoutedEventArgs*)e;
- (void)onTapped:(WUXITappedRoutedEventArgs*)e;
- (void)onDoubleTapped:(WUXIDoubleTappedRoutedEventArgs*)e;
- (void)onHolding:(WUXIHoldingRoutedEventArgs*)e;
- (void)onRightTapped:(WUXIRightTappedRoutedEventArgs*)e;
- (void)onManipulationStarting:(WUXIManipulationStartingRoutedEventArgs*)e;
- (void)onManipulationInertiaStarting:(WUXIManipulationInertiaStartingRoutedEventArgs*)e;
- (void)onManipulationStarted:(WUXIManipulationStartedRoutedEventArgs*)e;
- (void)onManipulationDelta:(WUXIManipulationDeltaRoutedEventArgs*)e;
- (void)onManipulationCompleted:(WUXIManipulationCompletedRoutedEventArgs*)e;
- (void)onKeyUp:(WUXIKeyRoutedEventArgs*)e;
- (void)onKeyDown:(WUXIKeyRoutedEventArgs*)e;
- (void)onGotFocus:(WXRoutedEventArgs*)e;
- (void)onLostFocus:(WXRoutedEventArgs*)e;
- (void)onDragEnter:(WXDragEventArgs*)e;
- (void)onDragLeave:(WXDragEventArgs*)e;
- (void)onDragOver:(WXDragEventArgs*)e;
- (void)onDrop:(WXDragEventArgs*)e;
- (WXDependencyObject*)getTemplateChild:(NSString *)childName;
- (void)removeFocusEngagement;
- (void)onPreviewKeyDown:(WUXIKeyRoutedEventArgs*)e;
- (void)onPreviewKeyUp:(WUXIKeyRoutedEventArgs*)e;
- (void)onCharacterReceived:(WUXICharacterReceivedRoutedEventArgs*)e;
@end

#endif // __WXCControl_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapControl
#ifndef __WUXCMMapControl_DEFINED__
#define __WUXCMMapControl_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapControl : WXCControl
+ (WDGGeopoint*)getLocation:(WXDependencyObject*)element;
+ (void)setLocation:(WXDependencyObject*)element value:(WDGGeopoint*)value;
+ (WFPoint*)getNormalizedAnchorPoint:(WXDependencyObject*)element;
+ (void)setNormalizedAnchorPoint:(WXDependencyObject*)element value:(WFPoint*)value;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL landmarksVisible;
@property double heading;
@property double desiredPitch;
@property WUXCMMapColorScheme colorScheme;
@property BOOL pedestrianFeaturesVisible;
@property WUXCMMapWatermarkMode watermarkMode;
@property double zoomLevel;
@property WUXCMMapStyle style;
@property (retain) NSString * mapServiceToken;
@property (retain) WFPoint* transformOrigin;
@property BOOL trafficFlowVisible;
@property (retain) WDGGeopoint* center;
@property (readonly) NSMutableArray* /* WXDependencyObject* */ children;
@property (readonly) WUXCMMapLoadingStatus loadingStatus;
@property (readonly) NSMutableArray* /* WUXCMMapElement* */ mapElements;
@property (readonly) double maxZoomLevel;
@property (readonly) double minZoomLevel;
@property (readonly) double pitch;
@property (readonly) NSMutableArray* /* WUXCMMapRouteView* */ routes;
@property (readonly) NSMutableArray* /* WUXCMMapTileSource* */ tileSources;
@property WUXCMMapInteractionMode rotateInteractionMode;
@property BOOL transitFeaturesVisible;
@property WUXCMMapInteractionMode tiltInteractionMode;
@property (retain) WUXCMMapScene* scene;
@property WUXCMMapInteractionMode zoomInteractionMode;
@property WUXCMMapPanInteractionMode panInteractionMode;
@property BOOL businessLandmarksVisible;
@property (retain) WUXCMMapCustomExperience* customExperience;
@property (readonly) WUXCMMapCamera* targetCamera;
@property (readonly) WUXCMMapCamera* actualCamera;
@property (readonly) BOOL is3DSupported;
@property (readonly) BOOL isStreetsideSupported;
@property BOOL transitFeaturesEnabled;
@property BOOL businessLandmarksEnabled;
@property (retain) WXThickness* viewPadding;
@property (retain) WUXCMMapStyleSheet* styleSheet;
@property WUXCMMapProjection mapProjection;
@property (retain) NSMutableArray* /* WUXCMMapLayer* */ layers;
+ (WXDependencyProperty*)tileSourcesProperty;
+ (WXDependencyProperty*)trafficFlowVisibleProperty;
+ (WXDependencyProperty*)transformOriginProperty;
+ (WXDependencyProperty*)watermarkModeProperty;
+ (WXDependencyProperty*)zoomLevelProperty;
+ (WXDependencyProperty*)locationProperty;
+ (WXDependencyProperty*)centerProperty;
+ (WXDependencyProperty*)childrenProperty;
+ (WXDependencyProperty*)colorSchemeProperty;
+ (WXDependencyProperty*)desiredPitchProperty;
+ (WXDependencyProperty*)headingProperty;
+ (WXDependencyProperty*)landmarksVisibleProperty;
+ (WXDependencyProperty*)loadingStatusProperty;
+ (WXDependencyProperty*)mapElementsProperty;
+ (WXDependencyProperty*)mapServiceTokenProperty;
+ (WXDependencyProperty*)normalizedAnchorPointProperty;
+ (WXDependencyProperty*)pedestrianFeaturesVisibleProperty;
+ (WXDependencyProperty*)pitchProperty;
+ (WXDependencyProperty*)routesProperty;
+ (WXDependencyProperty*)styleProperty;
+ (WXDependencyProperty*)zoomInteractionModeProperty;
+ (WXDependencyProperty*)sceneProperty;
+ (WXDependencyProperty*)businessLandmarksVisibleProperty;
+ (WXDependencyProperty*)is3DSupportedProperty;
+ (WXDependencyProperty*)isStreetsideSupportedProperty;
+ (WXDependencyProperty*)panInteractionModeProperty;
+ (WXDependencyProperty*)rotateInteractionModeProperty;
+ (WXDependencyProperty*)tiltInteractionModeProperty;
+ (WXDependencyProperty*)transitFeaturesVisibleProperty;
+ (WXDependencyProperty*)businessLandmarksEnabledProperty;
+ (WXDependencyProperty*)transitFeaturesEnabledProperty;
+ (WXDependencyProperty*)mapProjectionProperty;
+ (WXDependencyProperty*)styleSheetProperty;
+ (WXDependencyProperty*)viewPaddingProperty;
+ (WXDependencyProperty*)layersProperty;
- (EventRegistrationToken)addCenterChangedEvent:(void(^)(WUXCMMapControl*, RTObject*))del;
- (void)removeCenterChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHeadingChangedEvent:(void(^)(WUXCMMapControl*, RTObject*))del;
- (void)removeHeadingChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadingStatusChangedEvent:(void(^)(WUXCMMapControl*, RTObject*))del;
- (void)removeLoadingStatusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapDoubleTappedEvent:(void(^)(WUXCMMapControl*, WUXCMMapInputEventArgs*))del;
- (void)removeMapDoubleTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapHoldingEvent:(void(^)(WUXCMMapControl*, WUXCMMapInputEventArgs*))del;
- (void)removeMapHoldingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapTappedEvent:(void(^)(WUXCMMapControl*, WUXCMMapInputEventArgs*))del;
- (void)removeMapTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPitchChangedEvent:(void(^)(WUXCMMapControl*, RTObject*))del;
- (void)removePitchChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTransformOriginChangedEvent:(void(^)(WUXCMMapControl*, RTObject*))del;
- (void)removeTransformOriginChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addZoomLevelChangedEvent:(void(^)(WUXCMMapControl*, RTObject*))del;
- (void)removeZoomLevelChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addActualCameraChangedEvent:(void(^)(WUXCMMapControl*, WUXCMMapActualCameraChangedEventArgs*))del;
- (void)removeActualCameraChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addActualCameraChangingEvent:(void(^)(WUXCMMapControl*, WUXCMMapActualCameraChangingEventArgs*))del;
- (void)removeActualCameraChangingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCustomExperienceChangedEvent:(void(^)(WUXCMMapControl*, WUXCMMapCustomExperienceChangedEventArgs*))del;
- (void)removeCustomExperienceChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapElementClickEvent:(void(^)(WUXCMMapControl*, WUXCMMapElementClickEventArgs*))del;
- (void)removeMapElementClickEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapElementPointerEnteredEvent:(void(^)(WUXCMMapControl*, WUXCMMapElementPointerEnteredEventArgs*))del;
- (void)removeMapElementPointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapElementPointerExitedEvent:(void(^)(WUXCMMapControl*, WUXCMMapElementPointerExitedEventArgs*))del;
- (void)removeMapElementPointerExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTargetCameraChangedEvent:(void(^)(WUXCMMapControl*, WUXCMMapTargetCameraChangedEventArgs*))del;
- (void)removeTargetCameraChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapRightTappedEvent:(void(^)(WUXCMMapControl*, WUXCMMapRightTappedEventArgs*))del;
- (void)removeMapRightTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapContextRequestedEvent:(void(^)(WUXCMMapControl*, WUXCMMapContextRequestedEventArgs*))del;
- (void)removeMapContextRequestedEvent:(EventRegistrationToken)tok;
- (NSArray* /* WUXCMMapElement* */)findMapElementsAtOffset:(WFPoint*)offset;
- (void)getLocationFromOffset:(WFPoint*)offset location:(WDGGeopoint**)location;
- (void)getOffsetFromLocation:(WDGGeopoint*)location offset:(WFPoint**)offset;
- (void)isLocationInView:(WDGGeopoint*)location isInView:(BOOL*)isInView;
- (void)trySetViewBoundsAsync:(WDGGeoboundingBox*)bounds margin:(id /* WXThickness* */)margin animation:(WUXCMMapAnimationKind)animation success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)trySetViewWithCenterAsync:(WDGGeopoint*)center success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)trySetViewWithCenterAndZoomAsync:(WDGGeopoint*)center zoomLevel:(id /* double */)zoomLevel success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)trySetViewWithCenterZoomHeadingAndPitchAsync:(WDGGeopoint*)center zoomLevel:(id /* double */)zoomLevel heading:(id /* double */)heading desiredPitch:(id /* double */)desiredPitch success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)trySetViewWithCenterZoomHeadingPitchAndAnimationAsync:(WDGGeopoint*)center zoomLevel:(id /* double */)zoomLevel heading:(id /* double */)heading desiredPitch:(id /* double */)desiredPitch animation:(WUXCMMapAnimationKind)animation success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)startContinuousRotate:(double)rateInDegreesPerSecond;
- (void)stopContinuousRotate;
- (void)startContinuousTilt:(double)rateInDegreesPerSecond;
- (void)stopContinuousTilt;
- (void)startContinuousZoom:(double)rateOfChangePerSecond;
- (void)stopContinuousZoom;
- (void)tryRotateAsync:(double)degrees success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryRotateToAsync:(double)angleInDegrees success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryTiltAsync:(double)degrees success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryTiltToAsync:(double)angleInDegrees success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryZoomInAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryZoomOutAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryZoomToAsync:(double)zoomLevel success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)trySetSceneAsync:(WUXCMMapScene*)scene success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)trySetSceneWithAnimationAsync:(WUXCMMapScene*)scene animationKind:(WUXCMMapAnimationKind)animationKind success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (WDGGeopath*)getVisibleRegion:(WUXCMMapVisibleRegionKind)region;
- (NSArray* /* WUXCMMapElement* */)findMapElementsAtOffsetWithRadius:(WFPoint*)offset radius:(double)radius;
- (void)getLocationFromOffsetWithReferenceSystem:(WFPoint*)offset desiredReferenceSystem:(WDGAltitudeReferenceSystem)desiredReferenceSystem location:(WDGGeopoint**)location;
- (void)startContinuousPan:(double)horizontalPixelsPerSecond verticalPixelsPerSecond:(double)verticalPixelsPerSecond;
- (void)stopContinuousPan;
- (void)tryPanAsync:(double)horizontalPixels verticalPixels:(double)verticalPixels success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryPanToAsync:(WDGGeopoint*)location success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (BOOL)tryGetLocationFromOffset:(WFPoint*)offset location:(WDGGeopoint**)location;
- (BOOL)tryGetLocationFromOffsetWithReferenceSystem:(WFPoint*)offset desiredReferenceSystem:(WDGAltitudeReferenceSystem)desiredReferenceSystem location:(WDGGeopoint**)location;
@end

#endif // __WUXCMMapControl_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapControlBusinessLandmarkClickEventArgs
#ifndef __WUXCMMapControlBusinessLandmarkClickEventArgs_DEFINED__
#define __WUXCMMapControlBusinessLandmarkClickEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapControlBusinessLandmarkClickEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSMLLocalLocation* */ localLocations;
@end

#endif // __WUXCMMapControlBusinessLandmarkClickEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapControlTransitFeatureClickEventArgs
#ifndef __WUXCMMapControlTransitFeatureClickEventArgs_DEFINED__
#define __WUXCMMapControlTransitFeatureClickEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapControlTransitFeatureClickEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayName;
@property (readonly) WDGGeopoint* location;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ transitProperties;
@end

#endif // __WUXCMMapControlTransitFeatureClickEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapControlBusinessLandmarkRightTappedEventArgs
#ifndef __WUXCMMapControlBusinessLandmarkRightTappedEventArgs_DEFINED__
#define __WUXCMMapControlBusinessLandmarkRightTappedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapControlBusinessLandmarkRightTappedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSMLLocalLocation* */ localLocations;
@end

#endif // __WUXCMMapControlBusinessLandmarkRightTappedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapControlTransitFeatureRightTappedEventArgs
#ifndef __WUXCMMapControlTransitFeatureRightTappedEventArgs_DEFINED__
#define __WUXCMMapControlTransitFeatureRightTappedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapControlTransitFeatureRightTappedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayName;
@property (readonly) WDGGeopoint* location;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ transitProperties;
@end

#endif // __WUXCMMapControlTransitFeatureRightTappedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapControlBusinessLandmarkPointerEnteredEventArgs
#ifndef __WUXCMMapControlBusinessLandmarkPointerEnteredEventArgs_DEFINED__
#define __WUXCMMapControlBusinessLandmarkPointerEnteredEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapControlBusinessLandmarkPointerEnteredEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSMLLocalLocation* */ localLocations;
@end

#endif // __WUXCMMapControlBusinessLandmarkPointerEnteredEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapControlTransitFeaturePointerEnteredEventArgs
#ifndef __WUXCMMapControlTransitFeaturePointerEnteredEventArgs_DEFINED__
#define __WUXCMMapControlTransitFeaturePointerEnteredEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapControlTransitFeaturePointerEnteredEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayName;
@property (readonly) WDGGeopoint* location;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ transitProperties;
@end

#endif // __WUXCMMapControlTransitFeaturePointerEnteredEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapControlBusinessLandmarkPointerExitedEventArgs
#ifndef __WUXCMMapControlBusinessLandmarkPointerExitedEventArgs_DEFINED__
#define __WUXCMMapControlBusinessLandmarkPointerExitedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapControlBusinessLandmarkPointerExitedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSMLLocalLocation* */ localLocations;
@end

#endif // __WUXCMMapControlBusinessLandmarkPointerExitedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapControlTransitFeaturePointerExitedEventArgs
#ifndef __WUXCMMapControlTransitFeaturePointerExitedEventArgs_DEFINED__
#define __WUXCMMapControlTransitFeaturePointerExitedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapControlTransitFeaturePointerExitedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayName;
@property (readonly) WDGGeopoint* location;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ transitProperties;
@end

#endif // __WUXCMMapControlTransitFeaturePointerExitedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapControlDataHelper
#ifndef __WUXCMMapControlDataHelper_DEFINED__
#define __WUXCMMapControlDataHelper_DEFINED__

OBJCUWPWINDOWSUIXAMLCONTROLSMAPSEXPORT
@interface WUXCMMapControlDataHelper : WXDependencyObject
+ (WUXCMMapControl*)createMapControl:(BOOL)rasterRenderMode;
+ (WUXCMMapControlDataHelper*)makeInstance:(WUXCMMapControl*)map ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addBusinessLandmarkClickEvent:(void(^)(WUXCMMapControl*, WUXCMMapControlBusinessLandmarkClickEventArgs*))del;
- (void)removeBusinessLandmarkClickEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBusinessLandmarkRightTappedEvent:(void(^)(WUXCMMapControl*, WUXCMMapControlBusinessLandmarkRightTappedEventArgs*))del;
- (void)removeBusinessLandmarkRightTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTransitFeatureClickEvent:(void(^)(WUXCMMapControl*, WUXCMMapControlTransitFeatureClickEventArgs*))del;
- (void)removeTransitFeatureClickEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTransitFeatureRightTappedEvent:(void(^)(WUXCMMapControl*, WUXCMMapControlTransitFeatureRightTappedEventArgs*))del;
- (void)removeTransitFeatureRightTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBusinessLandmarkPointerEnteredEvent:(void(^)(WUXCMMapControl*, WUXCMMapControlBusinessLandmarkPointerEnteredEventArgs*))del;
- (void)removeBusinessLandmarkPointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBusinessLandmarkPointerExitedEvent:(void(^)(WUXCMMapControl*, WUXCMMapControlBusinessLandmarkPointerExitedEventArgs*))del;
- (void)removeBusinessLandmarkPointerExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTransitFeaturePointerEnteredEvent:(void(^)(WUXCMMapControl*, WUXCMMapControlTransitFeaturePointerEnteredEventArgs*))del;
- (void)removeTransitFeaturePointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTransitFeaturePointerExitedEvent:(void(^)(WUXCMMapControl*, WUXCMMapControlTransitFeaturePointerExitedEventArgs*))del;
- (void)removeTransitFeaturePointerExitedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCMMapControlDataHelper_DEFINED__

