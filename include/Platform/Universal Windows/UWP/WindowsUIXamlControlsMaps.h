//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include "interopBase.h"
@class WUXCMMapActualCameraChangedEventArgs, WUXCMMapActualCameraChangingEventArgs, WUXCMMapCustomExperienceChangedEventArgs,
    WUXCMMapElementClickEventArgs, WUXCMMapElementPointerEnteredEventArgs, WUXCMMapElementPointerExitedEventArgs,
    WUXCMMapTargetCameraChangedEventArgs, WUXCMMapTileBitmapRequestDeferral, WUXCMMapTileBitmapRequest,
    WUXCMMapTileBitmapRequestedEventArgs, WUXCMMapTileUriRequestDeferral, WUXCMMapTileUriRequest, WUXCMMapTileUriRequestedEventArgs,
    WUXCMMapCamera, WUXCMMapCustomExperience, WUXCMMapElement, WUXCMMapInputEventArgs, WUXCMMapItemsControl, WUXCMMapRouteView,
    WUXCMMapScene, WUXCMMapTileDataSource, WUXCMMapTileSource, WUXCMStreetsidePanorama, WUXCMCustomMapTileDataSource,
    WUXCMHttpMapTileDataSource, WUXCMLocalMapTileDataSource, WUXCMMapIcon, WUXCMMapPolygon, WUXCMMapPolyline, WUXCMStreetsideExperience,
    WUXCMMapControl;
@class WUXCMMapZoomLevelRange;
@protocol WUXCMIMapActualCameraChangedEventArgs
, WUXCMIMapActualCameraChangingEventArgs, WUXCMIMapCustomExperienceChangedEventArgs, WUXCMIMapElementClickEventArgs,
    WUXCMIMapElementPointerEnteredEventArgs, WUXCMIMapElementPointerExitedEventArgs, WUXCMIMapTargetCameraChangedEventArgs,
    WUXCMIMapTileBitmapRequest, WUXCMIMapTileBitmapRequestDeferral, WUXCMIMapTileBitmapRequestedEventArgs, WUXCMIMapTileUriRequest,
    WUXCMIMapTileUriRequestDeferral, WUXCMIMapTileUriRequestedEventArgs, WUXCMIMapCamera, WUXCMIMapCameraFactory, WUXCMIMapCustomExperience,
    WUXCMIMapCustomExperienceFactory, WUXCMIMapElement, WUXCMIMapElementStatics, WUXCMIMapElementFactory, WUXCMIMapElement2,
    WUXCMIMapElementStatics2, WUXCMIMapInputEventArgs, WUXCMIMapItemsControl, WUXCMIMapItemsControlStatics, WUXCMIMapRouteView,
    WUXCMIMapRouteViewFactory, WUXCMIMapScene, WUXCMIMapSceneStatics, WUXCMIMapTileDataSource, WUXCMIMapTileDataSourceFactory,
    WUXCMIMapTileSource, WUXCMIMapTileSourceStatics, WUXCMIMapTileSourceFactory, WUXCMIStreetsidePanorama, WUXCMIStreetsidePanoramaStatics,
    WUXCMICustomMapTileDataSource, WUXCMICustomMapTileDataSourceFactory, WUXCMIHttpMapTileDataSource, WUXCMIHttpMapTileDataSourceFactory,
    WUXCMILocalMapTileDataSource, WUXCMILocalMapTileDataSourceFactory, WUXCMIMapIcon, WUXCMIMapIconStatics, WUXCMIMapIcon2,
    WUXCMIMapIconStatics2, WUXCMIMapPolygon, WUXCMIMapPolygonStatics, WUXCMIMapPolyline, WUXCMIMapPolylineStatics,
    WUXCMIStreetsideExperience, WUXCMIStreetsideExperienceFactory, WUXCMIMapControl, WUXCMIMapControlStatics, WUXCMIMapControl2,
    WUXCMIMapControlStatics2;

// Windows.UI.Xaml.Controls.Maps.MapAnimationKind
enum _WUXCMMapAnimationKind {
    WUXCMMapAnimationKindDefault = 0,
    WUXCMMapAnimationKindNone = 1,
    WUXCMMapAnimationKindLinear = 2,
    WUXCMMapAnimationKindBow = 3,
};
typedef unsigned WUXCMMapAnimationKind;

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
    WUXCMMapInteractionModeControlOnly = 3,
    WUXCMMapInteractionModeGestureAndControl = 4,
};
typedef unsigned WUXCMMapInteractionMode;

// Windows.UI.Xaml.Controls.Maps.MapLoadingStatus
enum _WUXCMMapLoadingStatus {
    WUXCMMapLoadingStatusLoading = 0,
    WUXCMMapLoadingStatusLoaded = 1,
};
typedef unsigned WUXCMMapLoadingStatus;

// Windows.UI.Xaml.Controls.Maps.MapPanInteractionMode
enum _WUXCMMapPanInteractionMode {
    WUXCMMapPanInteractionModeAuto = 0,
    WUXCMMapPanInteractionModeDisabled = 1,
};
typedef unsigned WUXCMMapPanInteractionMode;

// Windows.UI.Xaml.Controls.Maps.MapStyle
enum _WUXCMMapStyle {
    WUXCMMapStyleNone = 0,
    WUXCMMapStyleRoad = 1,
    WUXCMMapStyleAerial = 2,
    WUXCMMapStyleAerialWithRoads = 3,
    WUXCMMapStyleTerrain = 4,
    WUXCMMapStyleAerial3D = 5,
    WUXCMMapStyleAerial3DWithRoads = 6,
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

// Windows.UI.Xaml.Controls.Maps.MapWatermarkMode
enum _WUXCMMapWatermarkMode {
    WUXCMMapWatermarkModeAutomatic = 0,
    WUXCMMapWatermarkModeOn = 1,
};
typedef unsigned WUXCMMapWatermarkMode;

#include "WindowsUICore.h"
#include "WindowsFoundation.h"
#include "WindowsUIXamlMediaMedia3D.h"
#include "WindowsDevicesGeolocation.h"
#include "WindowsStorageStreams.h"
#include "WindowsUIXamlMediaAnimation.h"
#include "WindowsUIXamlControls.h"
#include "WindowsFoundationCollections.h"
#include "WindowsUIXaml.h"
#include "WindowsUIXamlData.h"
#include "WindowsUI.h"
#include "WindowsServicesMaps.h"
#include "WindowsApplicationModelDataTransfer.h"
#include "WindowsUIXamlMedia.h"
#include "WindowsUIText.h"
#include "WindowsUIXamlInput.h"
#include "WindowsUIInput.h"
#include "WindowsUIXamlAutomationPeers.h"
// Windows.UI.Xaml.DependencyPropertyChangedCallback
#ifndef __WXDependencyPropertyChangedCallback__DEFINED
#define __WXDependencyPropertyChangedCallback__DEFINED
typedef void (^WXDependencyPropertyChangedCallback)(WXDependencyObject* sender, WXDependencyProperty* dp);
#endif // __WXDependencyPropertyChangedCallback__DEFINED

// Windows.UI.Xaml.DependencyPropertyChangedEventHandler
#ifndef __WXDependencyPropertyChangedEventHandler__DEFINED
#define __WXDependencyPropertyChangedEventHandler__DEFINED
typedef void (^WXDependencyPropertyChangedEventHandler)(RTObject* sender, WXDependencyPropertyChangedEventArgs* e);
#endif // __WXDependencyPropertyChangedEventHandler__DEFINED

// Windows.UI.Xaml.DragEventHandler
#ifndef __WXDragEventHandler__DEFINED
#define __WXDragEventHandler__DEFINED
typedef void (^WXDragEventHandler)(RTObject* sender, WXDragEventArgs* e);
#endif // __WXDragEventHandler__DEFINED

// Windows.UI.Xaml.Input.DoubleTappedEventHandler
#ifndef __WUXIDoubleTappedEventHandler__DEFINED
#define __WUXIDoubleTappedEventHandler__DEFINED
typedef void (^WUXIDoubleTappedEventHandler)(RTObject* sender, WUXIDoubleTappedRoutedEventArgs* e);
#endif // __WUXIDoubleTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.HoldingEventHandler
#ifndef __WUXIHoldingEventHandler__DEFINED
#define __WUXIHoldingEventHandler__DEFINED
typedef void (^WUXIHoldingEventHandler)(RTObject* sender, WUXIHoldingRoutedEventArgs* e);
#endif // __WUXIHoldingEventHandler__DEFINED

// Windows.UI.Xaml.Input.KeyEventHandler
#ifndef __WUXIKeyEventHandler__DEFINED
#define __WUXIKeyEventHandler__DEFINED
typedef void (^WUXIKeyEventHandler)(RTObject* sender, WUXIKeyRoutedEventArgs* e);
#endif // __WUXIKeyEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationCompletedEventHandler
#ifndef __WUXIManipulationCompletedEventHandler__DEFINED
#define __WUXIManipulationCompletedEventHandler__DEFINED
typedef void (^WUXIManipulationCompletedEventHandler)(RTObject* sender, WUXIManipulationCompletedRoutedEventArgs* e);
#endif // __WUXIManipulationCompletedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationDeltaEventHandler
#ifndef __WUXIManipulationDeltaEventHandler__DEFINED
#define __WUXIManipulationDeltaEventHandler__DEFINED
typedef void (^WUXIManipulationDeltaEventHandler)(RTObject* sender, WUXIManipulationDeltaRoutedEventArgs* e);
#endif // __WUXIManipulationDeltaEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationInertiaStartingEventHandler
#ifndef __WUXIManipulationInertiaStartingEventHandler__DEFINED
#define __WUXIManipulationInertiaStartingEventHandler__DEFINED
typedef void (^WUXIManipulationInertiaStartingEventHandler)(RTObject* sender, WUXIManipulationInertiaStartingRoutedEventArgs* e);
#endif // __WUXIManipulationInertiaStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartedEventHandler
#ifndef __WUXIManipulationStartedEventHandler__DEFINED
#define __WUXIManipulationStartedEventHandler__DEFINED
typedef void (^WUXIManipulationStartedEventHandler)(RTObject* sender, WUXIManipulationStartedRoutedEventArgs* e);
#endif // __WUXIManipulationStartedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartingEventHandler
#ifndef __WUXIManipulationStartingEventHandler__DEFINED
#define __WUXIManipulationStartingEventHandler__DEFINED
typedef void (^WUXIManipulationStartingEventHandler)(RTObject* sender, WUXIManipulationStartingRoutedEventArgs* e);
#endif // __WUXIManipulationStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.PointerEventHandler
#ifndef __WUXIPointerEventHandler__DEFINED
#define __WUXIPointerEventHandler__DEFINED
typedef void (^WUXIPointerEventHandler)(RTObject* sender, WUXIPointerRoutedEventArgs* e);
#endif // __WUXIPointerEventHandler__DEFINED

// Windows.UI.Xaml.Input.RightTappedEventHandler
#ifndef __WUXIRightTappedEventHandler__DEFINED
#define __WUXIRightTappedEventHandler__DEFINED
typedef void (^WUXIRightTappedEventHandler)(RTObject* sender, WUXIRightTappedRoutedEventArgs* e);
#endif // __WUXIRightTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.TappedEventHandler
#ifndef __WUXITappedEventHandler__DEFINED
#define __WUXITappedEventHandler__DEFINED
typedef void (^WUXITappedEventHandler)(RTObject* sender, WUXITappedRoutedEventArgs* e);
#endif // __WUXITappedEventHandler__DEFINED

// Windows.UI.Xaml.RoutedEventHandler
#ifndef __WXRoutedEventHandler__DEFINED
#define __WXRoutedEventHandler__DEFINED
typedef void (^WXRoutedEventHandler)(RTObject* sender, WXRoutedEventArgs* e);
#endif // __WXRoutedEventHandler__DEFINED

// Windows.UI.Xaml.SizeChangedEventHandler
#ifndef __WXSizeChangedEventHandler__DEFINED
#define __WXSizeChangedEventHandler__DEFINED
typedef void (^WXSizeChangedEventHandler)(RTObject* sender, WXSizeChangedEventArgs* e);
#endif // __WXSizeChangedEventHandler__DEFINED

#import <Foundation/Foundation.h>

// [struct] Windows.UI.Xaml.Controls.Maps.MapZoomLevelRange
WINRT_EXPORT
@interface WUXCMMapZoomLevelRange : NSObject
+ (instancetype) new;
@property double min;
@property double max;
@end

// Windows.UI.Xaml.Controls.Maps.MapActualCameraChangedEventArgs
#ifndef __WUXCMMapActualCameraChangedEventArgs_DEFINED__
#define __WUXCMMapActualCameraChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCMMapActualCameraChangedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WUXCMMapCamera* camera;
@end

#endif // __WUXCMMapActualCameraChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapActualCameraChangingEventArgs
#ifndef __WUXCMMapActualCameraChangingEventArgs_DEFINED__
#define __WUXCMMapActualCameraChangingEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCMMapActualCameraChangingEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WUXCMMapCamera* camera;
@end

#endif // __WUXCMMapActualCameraChangingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapCustomExperienceChangedEventArgs
#ifndef __WUXCMMapCustomExperienceChangedEventArgs_DEFINED__
#define __WUXCMMapCustomExperienceChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCMMapCustomExperienceChangedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXCMMapCustomExperienceChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapElementClickEventArgs
#ifndef __WUXCMMapElementClickEventArgs_DEFINED__
#define __WUXCMMapElementClickEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCMMapElementClickEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WDGGeopoint* location;
@property (readonly) NSMutableArray* mapElements;
@property (readonly) WFPoint* position;
@end

#endif // __WUXCMMapElementClickEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapElementPointerEnteredEventArgs
#ifndef __WUXCMMapElementPointerEnteredEventArgs_DEFINED__
#define __WUXCMMapElementPointerEnteredEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCMMapElementPointerEnteredEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WDGGeopoint* location;
@property (readonly) WUXCMMapElement* mapElement;
@property (readonly) WFPoint* position;
@end

#endif // __WUXCMMapElementPointerEnteredEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapElementPointerExitedEventArgs
#ifndef __WUXCMMapElementPointerExitedEventArgs_DEFINED__
#define __WUXCMMapElementPointerExitedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCMMapElementPointerExitedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WDGGeopoint* location;
@property (readonly) WUXCMMapElement* mapElement;
@property (readonly) WFPoint* position;
@end

#endif // __WUXCMMapElementPointerExitedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTargetCameraChangedEventArgs
#ifndef __WUXCMMapTargetCameraChangedEventArgs_DEFINED__
#define __WUXCMMapTargetCameraChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCMMapTargetCameraChangedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WUXCMMapCamera* camera;
@end

#endif // __WUXCMMapTargetCameraChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileBitmapRequestDeferral
#ifndef __WUXCMMapTileBitmapRequestDeferral_DEFINED__
#define __WUXCMMapTileBitmapRequestDeferral_DEFINED__

WINRT_EXPORT
@interface WUXCMMapTileBitmapRequestDeferral : RTObject
+ (instancetype)create ACTIVATOR;
- (void)complete;
@end

#endif // __WUXCMMapTileBitmapRequestDeferral_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileBitmapRequest
#ifndef __WUXCMMapTileBitmapRequest_DEFINED__
#define __WUXCMMapTileBitmapRequest_DEFINED__

WINRT_EXPORT
@interface WUXCMMapTileBitmapRequest : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject<WSSIRandomAccessStreamReference>* pixelData;
- (WUXCMMapTileBitmapRequestDeferral*)getDeferral;
@end

#endif // __WUXCMMapTileBitmapRequest_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileBitmapRequestedEventArgs
#ifndef __WUXCMMapTileBitmapRequestedEventArgs_DEFINED__
#define __WUXCMMapTileBitmapRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCMMapTileBitmapRequestedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WUXCMMapTileBitmapRequest* request;
@property (readonly) int x;
@property (readonly) int y;
@property (readonly) int zoomLevel;
@end

#endif // __WUXCMMapTileBitmapRequestedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileUriRequestDeferral
#ifndef __WUXCMMapTileUriRequestDeferral_DEFINED__
#define __WUXCMMapTileUriRequestDeferral_DEFINED__

WINRT_EXPORT
@interface WUXCMMapTileUriRequestDeferral : RTObject
+ (instancetype)create ACTIVATOR;
- (void)complete;
@end

#endif // __WUXCMMapTileUriRequestDeferral_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileUriRequest
#ifndef __WUXCMMapTileUriRequest_DEFINED__
#define __WUXCMMapTileUriRequest_DEFINED__

WINRT_EXPORT
@interface WUXCMMapTileUriRequest : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) WFUri* uri;
- (WUXCMMapTileUriRequestDeferral*)getDeferral;
@end

#endif // __WUXCMMapTileUriRequest_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileUriRequestedEventArgs
#ifndef __WUXCMMapTileUriRequestedEventArgs_DEFINED__
#define __WUXCMMapTileUriRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCMMapTileUriRequestedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WUXCMMapTileUriRequest* request;
@property (readonly) int x;
@property (readonly) int y;
@property (readonly) int zoomLevel;
@end

#endif // __WUXCMMapTileUriRequestedEventArgs_DEFINED__

// Windows.UI.Xaml.DependencyObject
#ifndef __WXDependencyObject_DEFINED__
#define __WXDependencyObject_DEFINED__

WINRT_EXPORT
@interface WXDependencyObject : RTObject
+ (instancetype)create ACTIVATOR;
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

WINRT_EXPORT
@interface WUXCMMapCamera : WXDependencyObject
+ (WUXCMMapCamera*)createInstanceWithLocation:(WDGGeopoint*)location ACTIVATOR;
+ (WUXCMMapCamera*)createInstanceWithLocationAndHeading:(WDGGeopoint*)location headingInDegrees:(double)headingInDegrees ACTIVATOR;
+ (WUXCMMapCamera*)createInstanceWithLocationHeadingAndPitch:(WDGGeopoint*)location
                                            headingInDegrees:(double)headingInDegrees
                                              pitchInDegrees:(double)pitchInDegrees ACTIVATOR;
+ (WUXCMMapCamera*)createInstanceWithLocationHeadingPitchRollAndFieldOfView:(WDGGeopoint*)location
                                                           headingInDegrees:(double)headingInDegrees
                                                             pitchInDegrees:(double)pitchInDegrees
                                                              rollInDegrees:(double)rollInDegrees
                                                       fieldOfViewInDegrees:(double)fieldOfViewInDegrees ACTIVATOR;
@property double roll;
@property double pitch;
@property (copy) WDGGeopoint* location;
@property double heading;
@property double fieldOfView;
@end

#endif // __WUXCMMapCamera_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapCustomExperience
#ifndef __WUXCMMapCustomExperience_DEFINED__
#define __WUXCMMapCustomExperience_DEFINED__

WINRT_EXPORT
@interface WUXCMMapCustomExperience : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXCMMapCustomExperience_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapElement
#ifndef __WUXCMMapElement_DEFINED__
#define __WUXCMMapElement_DEFINED__

WINRT_EXPORT
@interface WUXCMMapElement : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property int zIndex;
@property BOOL visible;
@property int mapTabIndex;
+ (WXDependencyProperty*)visibleProperty;
+ (WXDependencyProperty*)zIndexProperty;
+ (WXDependencyProperty*)mapTabIndexProperty;
@end

#endif // __WUXCMMapElement_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapInputEventArgs
#ifndef __WUXCMMapInputEventArgs_DEFINED__
#define __WUXCMMapInputEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCMMapInputEventArgs : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WDGGeopoint* location;
@property (readonly) WFPoint* position;
@end

#endif // __WUXCMMapInputEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapItemsControl
#ifndef __WUXCMMapItemsControl_DEFINED__
#define __WUXCMMapItemsControl_DEFINED__

WINRT_EXPORT
@interface WUXCMMapItemsControl : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject* itemsSource;
@property (copy) WXDataTemplate* itemTemplate;
@property (readonly) NSMutableArray* items;
+ (WXDependencyProperty*)itemTemplateProperty;
+ (WXDependencyProperty*)itemsProperty;
+ (WXDependencyProperty*)itemsSourceProperty;
@end

#endif // __WUXCMMapItemsControl_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapRouteView
#ifndef __WUXCMMapRouteView_DEFINED__
#define __WUXCMMapRouteView_DEFINED__

WINRT_EXPORT
@interface WUXCMMapRouteView : WXDependencyObject
@property (copy) WUColor* routeColor;
@property (copy) WUColor* outlineColor;
@property (readonly) WSMMapRoute* route;
@end

#endif // __WUXCMMapRouteView_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapScene
#ifndef __WUXCMMapScene_DEFINED__
#define __WUXCMMapScene_DEFINED__

WINRT_EXPORT
@interface WUXCMMapScene : WXDependencyObject
+ (WUXCMMapScene*)createFromBoundingBox:(WDGGeoboundingBox*)bounds;
+ (WUXCMMapScene*)createFromBoundingBoxWithHeadingAndPitch:(WDGGeoboundingBox*)bounds
                                          headingInDegrees:(double)headingInDegrees
                                            pitchInDegrees:(double)pitchInDegrees;
+ (WUXCMMapScene*)createFromCamera:(WUXCMMapCamera*)camera;
+ (WUXCMMapScene*)createFromLocation:(WDGGeopoint*)location;
+ (WUXCMMapScene*)createFromLocationWithHeadingAndPitch:(WDGGeopoint*)location
                                       headingInDegrees:(double)headingInDegrees
                                         pitchInDegrees:(double)pitchInDegrees;
+ (WUXCMMapScene*)createFromLocationAndRadius:(WDGGeopoint*)location radiusInMeters:(double)radiusInMeters;
+ (WUXCMMapScene*)createFromLocationAndRadiusWithHeadingAndPitch:(WDGGeopoint*)location
                                                  radiusInMeters:(double)radiusInMeters
                                                headingInDegrees:(double)headingInDegrees
                                                  pitchInDegrees:(double)pitchInDegrees;
+ (WUXCMMapScene*)createFromLocations:(id<NSFastEnumeration> /* WDGGeopoint* */)locations;
+ (WUXCMMapScene*)createFromLocationsWithHeadingAndPitch:(id<NSFastEnumeration> /* WDGGeopoint* */)locations
                                        headingInDegrees:(double)headingInDegrees
                                          pitchInDegrees:(double)pitchInDegrees;
@property (readonly) WUXCMMapCamera* targetCamera;
- (EventRegistrationToken)addTargetCameraChangedEvent:(void (^)(WUXCMMapScene*, WUXCMMapTargetCameraChangedEventArgs*))del;
- (void)removeTargetCameraChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCMMapScene_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileDataSource
#ifndef __WUXCMMapTileDataSource_DEFINED__
#define __WUXCMMapTileDataSource_DEFINED__

WINRT_EXPORT
@interface WUXCMMapTileDataSource : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXCMMapTileDataSource_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapTileSource
#ifndef __WUXCMMapTileSource_DEFINED__
#define __WUXCMMapTileSource_DEFINED__

WINRT_EXPORT
@interface WUXCMMapTileSource : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property BOOL isTransparencyEnabled;
@property BOOL isRetryEnabled;
@property BOOL isFadingEnabled;
@property (copy) WUXCMMapTileDataSource* dataSource;
@property (copy) WDGGeoboundingBox* bounds;
@property BOOL allowOverstretch;
@property (copy) WUXCMMapZoomLevelRange* zoomLevelRange;
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

WINRT_EXPORT
@interface WUXCMStreetsidePanorama : WXDependencyObject
+ (void)findNearbyWithLocationAsync:(WDGGeopoint*)location
                            success:(void (^)(WUXCMStreetsidePanorama*))success
                            failure:(void (^)(NSError*))failure;
+ (void)findNearbyWithLocationAndRadiusAsync:(WDGGeopoint*)location
                              radiusInMeters:(double)radiusInMeters
                                     success:(void (^)(WUXCMStreetsidePanorama*))success
                                     failure:(void (^)(NSError*))failure;
@property (readonly) WDGGeopoint* location;
@end

#endif // __WUXCMStreetsidePanorama_DEFINED__

// Windows.UI.Xaml.Controls.Maps.CustomMapTileDataSource
#ifndef __WUXCMCustomMapTileDataSource_DEFINED__
#define __WUXCMCustomMapTileDataSource_DEFINED__

WINRT_EXPORT
@interface WUXCMCustomMapTileDataSource : WUXCMMapTileDataSource
+ (instancetype)create ACTIVATOR;
- (EventRegistrationToken)addBitmapRequestedEvent:(void (^)(WUXCMCustomMapTileDataSource*, WUXCMMapTileBitmapRequestedEventArgs*))del;
- (void)removeBitmapRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCMCustomMapTileDataSource_DEFINED__

// Windows.UI.Xaml.Controls.Maps.HttpMapTileDataSource
#ifndef __WUXCMHttpMapTileDataSource_DEFINED__
#define __WUXCMHttpMapTileDataSource_DEFINED__

WINRT_EXPORT
@interface WUXCMHttpMapTileDataSource : WUXCMMapTileDataSource
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* uriFormatString;
@property BOOL allowCaching;
@property (readonly) NSMutableDictionary* additionalRequestHeaders;
- (EventRegistrationToken)addUriRequestedEvent:(void (^)(WUXCMHttpMapTileDataSource*, WUXCMMapTileUriRequestedEventArgs*))del;
- (void)removeUriRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCMHttpMapTileDataSource_DEFINED__

// Windows.UI.Xaml.Controls.Maps.LocalMapTileDataSource
#ifndef __WUXCMLocalMapTileDataSource_DEFINED__
#define __WUXCMLocalMapTileDataSource_DEFINED__

WINRT_EXPORT
@interface WUXCMLocalMapTileDataSource : WUXCMMapTileDataSource
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* uriFormatString;
- (EventRegistrationToken)addUriRequestedEvent:(void (^)(WUXCMLocalMapTileDataSource*, WUXCMMapTileUriRequestedEventArgs*))del;
- (void)removeUriRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCMLocalMapTileDataSource_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapIcon
#ifndef __WUXCMMapIcon_DEFINED__
#define __WUXCMMapIcon_DEFINED__

WINRT_EXPORT
@interface WUXCMMapIcon : WUXCMMapElement
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* title;
@property (copy) WFPoint* normalizedAnchorPoint;
@property (copy) WDGGeopoint* location;
@property (copy) RTObject<WSSIRandomAccessStreamReference>* image;
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

WINRT_EXPORT
@interface WUXCMMapPolygon : WUXCMMapElement
+ (instancetype)create ACTIVATOR;
@property double strokeThickness;
@property BOOL strokeDashed;
@property (copy) WUColor* strokeColor;
@property (copy) WDGGeopath* path;
@property (copy) WUColor* fillColor;
+ (WXDependencyProperty*)pathProperty;
+ (WXDependencyProperty*)strokeDashedProperty;
+ (WXDependencyProperty*)strokeThicknessProperty;
@end

#endif // __WUXCMMapPolygon_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapPolyline
#ifndef __WUXCMMapPolyline_DEFINED__
#define __WUXCMMapPolyline_DEFINED__

WINRT_EXPORT
@interface WUXCMMapPolyline : WUXCMMapElement
+ (instancetype)create ACTIVATOR;
@property double strokeThickness;
@property BOOL strokeDashed;
@property (copy) WUColor* strokeColor;
@property (copy) WDGGeopath* path;
+ (WXDependencyProperty*)pathProperty;
+ (WXDependencyProperty*)strokeDashedProperty;
@end

#endif // __WUXCMMapPolyline_DEFINED__

// Windows.UI.Xaml.Controls.Maps.StreetsideExperience
#ifndef __WUXCMStreetsideExperience_DEFINED__
#define __WUXCMStreetsideExperience_DEFINED__

WINRT_EXPORT
@interface WUXCMStreetsideExperience : WUXCMMapCustomExperience
+ (WUXCMStreetsideExperience*)createInstanceWithPanorama:(WUXCMStreetsidePanorama*)panorama ACTIVATOR;
+ (WUXCMStreetsideExperience*)createInstanceWithPanoramaHeadingPitchAndFieldOfView:(WUXCMStreetsidePanorama*)panorama
                                                                  headingInDegrees:(double)headingInDegrees
                                                                    pitchInDegrees:(double)pitchInDegrees
                                                              fieldOfViewInDegrees:(double)fieldOfViewInDegrees ACTIVATOR;
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

#endif // __WXCIControlOverrides_DEFINED__

// Windows.UI.Xaml.IFrameworkElementOverrides
#ifndef __WXIFrameworkElementOverrides_DEFINED__
#define __WXIFrameworkElementOverrides_DEFINED__

@protocol WXIFrameworkElementOverrides
- (WFSize*)measureOverride:(WFSize*)availableSize;
- (WFSize*)arrangeOverride:(WFSize*)finalSize;
- (void)onApplyTemplate;
@end

#endif // __WXIFrameworkElementOverrides_DEFINED__

// Windows.UI.Xaml.IFrameworkElementOverrides2
#ifndef __WXIFrameworkElementOverrides2_DEFINED__
#define __WXIFrameworkElementOverrides2_DEFINED__

@protocol WXIFrameworkElementOverrides2
- (BOOL)goToElementStateCore:(NSString*)stateName useTransitions:(BOOL)useTransitions;
@end

#endif // __WXIFrameworkElementOverrides2_DEFINED__

// Windows.UI.Xaml.IUIElementOverrides
#ifndef __WXIUIElementOverrides_DEFINED__
#define __WXIUIElementOverrides_DEFINED__

@protocol WXIUIElementOverrides
- (WUXAPAutomationPeer*)onCreateAutomationPeer;
- (void)onDisconnectVisualChildren;
- (id<NSFastEnumeration>)findSubElementsForTouchTargeting:(WFPoint*)point boundingRect:(WFRect*)boundingRect;
@end

#endif // __WXIUIElementOverrides_DEFINED__

// Windows.UI.Xaml.UIElement
#ifndef __WXUIElement_DEFINED__
#define __WXUIElement_DEFINED__

WINRT_EXPORT
@interface WXUIElement : WXDependencyObject
+ (BOOL)tryStartDirectManipulation:(WUXIPointer*)value;
@property BOOL isRightTapEnabled;
@property (copy) WUXMProjection* projection;
@property BOOL allowDrop;
@property BOOL isHitTestVisible;
@property double opacity;
@property (copy) WUXMCacheMode* cacheMode;
@property BOOL isDoubleTapEnabled;
@property BOOL isTapEnabled;
@property WXVisibility visibility;
@property BOOL useLayoutRounding;
@property (copy) WUXMRectangleGeometry* clip;
@property (copy) WUXMATransitionCollection* transitions;
@property (copy) WFPoint* renderTransformOrigin;
@property (copy) WUXMTransform* renderTransform;
@property BOOL isHoldingEnabled;
@property WUXIManipulationModes manipulationMode;
@property (readonly) WFSize* renderSize;
@property (readonly) NSArray* pointerCaptures;
@property (readonly) WFSize* desiredSize;
@property WUXMElementCompositeMode compositeMode;
@property (copy) WUXMMTransform3D* transform3D;
@property BOOL canDrag;
+ (WXRoutedEvent*)dropEvent;
+ (WXDependencyProperty*)allowDropProperty;
+ (WXDependencyProperty*)cacheModeProperty;
+ (WXDependencyProperty*)clipProperty;
+ (WXRoutedEvent*)doubleTappedEvent;
+ (WXRoutedEvent*)dragEnterEvent;
+ (WXRoutedEvent*)dragLeaveEvent;
+ (WXRoutedEvent*)dragOverEvent;
+ (WXRoutedEvent*)pointerCanceledEvent;
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
+ (WXDependencyProperty*)opacityProperty;
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
- (EventRegistrationToken)addDragStartingEvent:(void (^)(WXUIElement*, WXDragStartingEventArgs*))del;
- (void)removeDragStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDropCompletedEvent:(void (^)(WXUIElement*, WXDropCompletedEventArgs*))del;
- (void)removeDropCompletedEvent:(EventRegistrationToken)tok;
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
- (id<NSFastEnumeration>)findSubElementsForTouchTargeting:(WFPoint*)point boundingRect:(WFRect*)boundingRect;
- (BOOL)cancelDirectManipulations;
- (void)startDragAsync:(WUIPointerPoint*)pointerPoint
               success:(void (^)(WADDataPackageOperation))success
               failure:(void (^)(NSError*))failure;
@end

#endif // __WXUIElement_DEFINED__

// Windows.UI.Xaml.FrameworkElement
#ifndef __WXFrameworkElement_DEFINED__
#define __WXFrameworkElement_DEFINED__

WINRT_EXPORT
@interface WXFrameworkElement : WXUIElement
+ (instancetype)create ACTIVATOR;
@property (copy) WXThickness* margin;
@property (copy) NSString* language;
@property WXHorizontalAlignment horizontalAlignment;
@property double height;
@property WXFlowDirection flowDirection;
@property (copy) RTObject* dataContext;
@property WXVerticalAlignment verticalAlignment;
@property double maxWidth;
@property double maxHeight;
@property double minHeight;
@property double width;
@property (copy) RTObject* tag;
@property (copy) WXStyle* style;
@property (copy) WXResourceDictionary* resources;
@property (copy) NSString* name;
@property double minWidth;
@property (readonly) double actualWidth;
@property (readonly) WFUri* baseUri;
@property (readonly) WXTriggerCollection* triggers;
@property (readonly) double actualHeight;
@property (readonly) WXDependencyObject* parent;
@property WXElementTheme requestedTheme;
+ (WXDependencyProperty*)flowDirectionProperty;
+ (WXDependencyProperty*)actualHeightProperty;
+ (WXDependencyProperty*)actualWidthProperty;
+ (WXDependencyProperty*)dataContextProperty;
+ (WXDependencyProperty*)maxWidthProperty;
+ (WXDependencyProperty*)heightProperty;
+ (WXDependencyProperty*)horizontalAlignmentProperty;
+ (WXDependencyProperty*)languageProperty;
+ (WXDependencyProperty*)marginProperty;
+ (WXDependencyProperty*)maxHeightProperty;
+ (WXDependencyProperty*)minHeightProperty;
+ (WXDependencyProperty*)minWidthProperty;
+ (WXDependencyProperty*)nameProperty;
+ (WXDependencyProperty*)styleProperty;
+ (WXDependencyProperty*)tagProperty;
+ (WXDependencyProperty*)verticalAlignmentProperty;
+ (WXDependencyProperty*)widthProperty;
+ (WXDependencyProperty*)requestedThemeProperty;
- (EventRegistrationToken)addLayoutUpdatedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeLayoutUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadedEvent:(WXRoutedEventHandler)del;
- (void)removeLoadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSizeChangedEvent:(WXSizeChangedEventHandler)del;
- (void)removeSizeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnloadedEvent:(WXRoutedEventHandler)del;
- (void)removeUnloadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDataContextChangedEvent:(void (^)(WXFrameworkElement*, WXDataContextChangedEventArgs*))del;
- (void)removeDataContextChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadingEvent:(void (^)(WXFrameworkElement*, RTObject*))del;
- (void)removeLoadingEvent:(EventRegistrationToken)tok;
- (RTObject*)findName:(NSString*)name;
- (void)setBinding:(WXDependencyProperty*)dp binding:(WUXDBindingBase*)binding;
- (WFSize*)measureOverride:(WFSize*)availableSize;
- (WFSize*)arrangeOverride:(WFSize*)finalSize;
- (void)onApplyTemplate;
- (WUXDBindingExpression*)getBindingExpression:(WXDependencyProperty*)dp;
- (BOOL)goToElementStateCore:(NSString*)stateName useTransitions:(BOOL)useTransitions;
@end

#endif // __WXFrameworkElement_DEFINED__

// Windows.UI.Xaml.Controls.Control
#ifndef __WXCControl_DEFINED__
#define __WXCControl_DEFINED__

WINRT_EXPORT
@interface WXCControl : WXFrameworkElement
+ (BOOL)getIsTemplateFocusTarget:(WXFrameworkElement*)element;
+ (void)setIsTemplateFocusTarget:(WXFrameworkElement*)element value:(BOOL)value;
+ (instancetype)create ACTIVATOR;
@property (copy) WUTFontWeight* fontWeight;
@property WUTFontStyle fontStyle;
@property WUTFontStretch fontStretch;
@property double fontSize;
@property (copy) WUXMBrush* background;
@property (copy) WUXMFontFamily* fontFamily;
@property (copy) WUXMBrush* foreground;
@property int characterSpacing;
@property (copy) WXThickness* borderThickness;
@property (copy) WUXMBrush* borderBrush;
@property WXHorizontalAlignment horizontalContentAlignment;
@property WXVerticalAlignment verticalContentAlignment;
@property (copy) WXCControlTemplate* Template;
@property int tabIndex;
@property (copy) WXThickness* padding;
@property BOOL isTabStop;
@property BOOL isEnabled;
@property WUXIKeyboardNavigationMode tabNavigation;
@property (readonly) WXFocusState focusState;
@property BOOL isTextScaleFactorEnabled;
@property BOOL useSystemFocusVisuals;
@property (copy) RTObject* defaultStyleKey;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)backgroundProperty;
+ (WXDependencyProperty*)borderBrushProperty;
+ (WXDependencyProperty*)borderThicknessProperty;
+ (WXDependencyProperty*)characterSpacingProperty;
+ (WXDependencyProperty*)defaultStyleKeyProperty;
+ (WXDependencyProperty*)focusStateProperty;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)fontStretchProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)fontWeightProperty;
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
+ (WXDependencyProperty*)useSystemFocusVisualsProperty;
+ (WXDependencyProperty*)isTemplateFocusTargetProperty;
- (EventRegistrationToken)addIsEnabledChangedEvent:(WXDependencyPropertyChangedEventHandler)del;
- (void)removeIsEnabledChangedEvent:(EventRegistrationToken)tok;
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
- (WXDependencyObject*)getTemplateChild:(NSString*)childName;
@end

#endif // __WXCControl_DEFINED__

// Windows.UI.Xaml.Controls.Maps.MapControl
#ifndef __WUXCMMapControl_DEFINED__
#define __WUXCMMapControl_DEFINED__

WINRT_EXPORT
@interface WUXCMMapControl : WXCControl
+ (WDGGeopoint*)getLocation:(WXDependencyObject*)element;
+ (void)setLocation:(WXDependencyObject*)element value:(WDGGeopoint*)value;
+ (WFPoint*)getNormalizedAnchorPoint:(WXDependencyObject*)element;
+ (void)setNormalizedAnchorPoint:(WXDependencyObject*)element value:(WFPoint*)value;
+ (instancetype)create ACTIVATOR;
@property BOOL landmarksVisible;
@property double heading;
@property double desiredPitch;
@property WUXCMMapColorScheme colorScheme;
@property (copy) NSString* mapServiceToken;
@property double zoomLevel;
@property WUXCMMapWatermarkMode watermarkMode;
@property (copy) WFPoint* transformOrigin;
@property (copy) WDGGeopoint* center;
@property BOOL pedestrianFeaturesVisible;
@property WUXCMMapStyle style;
@property BOOL trafficFlowVisible;
@property (readonly) double minZoomLevel;
@property (readonly) NSMutableArray* routes;
@property (readonly) NSMutableArray* tileSources;
@property (readonly) double pitch;
@property (readonly) NSMutableArray* children;
@property (readonly) WUXCMMapLoadingStatus loadingStatus;
@property (readonly) NSMutableArray* mapElements;
@property (readonly) double maxZoomLevel;
@property BOOL transitFeaturesVisible;
@property WUXCMMapInteractionMode tiltInteractionMode;
@property (copy) WUXCMMapScene* scene;
@property WUXCMMapInteractionMode rotateInteractionMode;
@property WUXCMMapPanInteractionMode panInteractionMode;
@property (copy) WUXCMMapCustomExperience* customExperience;
@property BOOL businessLandmarksVisible;
@property WUXCMMapInteractionMode zoomInteractionMode;
@property (readonly) WUXCMMapCamera* targetCamera;
@property (readonly) BOOL isStreetsideSupported;
@property (readonly) WUXCMMapCamera* actualCamera;
@property (readonly) BOOL is3DSupported;
+ (WXDependencyProperty*)trafficFlowVisibleProperty;
+ (WXDependencyProperty*)centerProperty;
+ (WXDependencyProperty*)childrenProperty;
+ (WXDependencyProperty*)colorSchemeProperty;
+ (WXDependencyProperty*)desiredPitchProperty;
+ (WXDependencyProperty*)headingProperty;
+ (WXDependencyProperty*)landmarksVisibleProperty;
+ (WXDependencyProperty*)loadingStatusProperty;
+ (WXDependencyProperty*)locationProperty;
+ (WXDependencyProperty*)mapElementsProperty;
+ (WXDependencyProperty*)mapServiceTokenProperty;
+ (WXDependencyProperty*)normalizedAnchorPointProperty;
+ (WXDependencyProperty*)pedestrianFeaturesVisibleProperty;
+ (WXDependencyProperty*)pitchProperty;
+ (WXDependencyProperty*)routesProperty;
+ (WXDependencyProperty*)styleProperty;
+ (WXDependencyProperty*)tileSourcesProperty;
+ (WXDependencyProperty*)transformOriginProperty;
+ (WXDependencyProperty*)watermarkModeProperty;
+ (WXDependencyProperty*)zoomLevelProperty;
+ (WXDependencyProperty*)businessLandmarksVisibleProperty;
+ (WXDependencyProperty*)is3DSupportedProperty;
+ (WXDependencyProperty*)isStreetsideSupportedProperty;
+ (WXDependencyProperty*)panInteractionModeProperty;
+ (WXDependencyProperty*)rotateInteractionModeProperty;
+ (WXDependencyProperty*)sceneProperty;
+ (WXDependencyProperty*)tiltInteractionModeProperty;
+ (WXDependencyProperty*)transitFeaturesVisibleProperty;
+ (WXDependencyProperty*)zoomInteractionModeProperty;
- (EventRegistrationToken)addCenterChangedEvent:(void (^)(WUXCMMapControl*, RTObject*))del;
- (void)removeCenterChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHeadingChangedEvent:(void (^)(WUXCMMapControl*, RTObject*))del;
- (void)removeHeadingChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadingStatusChangedEvent:(void (^)(WUXCMMapControl*, RTObject*))del;
- (void)removeLoadingStatusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapDoubleTappedEvent:(void (^)(WUXCMMapControl*, WUXCMMapInputEventArgs*))del;
- (void)removeMapDoubleTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapHoldingEvent:(void (^)(WUXCMMapControl*, WUXCMMapInputEventArgs*))del;
- (void)removeMapHoldingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapTappedEvent:(void (^)(WUXCMMapControl*, WUXCMMapInputEventArgs*))del;
- (void)removeMapTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPitchChangedEvent:(void (^)(WUXCMMapControl*, RTObject*))del;
- (void)removePitchChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTransformOriginChangedEvent:(void (^)(WUXCMMapControl*, RTObject*))del;
- (void)removeTransformOriginChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addZoomLevelChangedEvent:(void (^)(WUXCMMapControl*, RTObject*))del;
- (void)removeZoomLevelChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addActualCameraChangedEvent:(void (^)(WUXCMMapControl*, WUXCMMapActualCameraChangedEventArgs*))del;
- (void)removeActualCameraChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addActualCameraChangingEvent:(void (^)(WUXCMMapControl*, WUXCMMapActualCameraChangingEventArgs*))del;
- (void)removeActualCameraChangingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCustomExperienceChangedEvent:(void (^)(WUXCMMapControl*, WUXCMMapCustomExperienceChangedEventArgs*))del;
- (void)removeCustomExperienceChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapElementClickEvent:(void (^)(WUXCMMapControl*, WUXCMMapElementClickEventArgs*))del;
- (void)removeMapElementClickEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapElementPointerEnteredEvent:(void (^)(WUXCMMapControl*, WUXCMMapElementPointerEnteredEventArgs*))del;
- (void)removeMapElementPointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMapElementPointerExitedEvent:(void (^)(WUXCMMapControl*, WUXCMMapElementPointerExitedEventArgs*))del;
- (void)removeMapElementPointerExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTargetCameraChangedEvent:(void (^)(WUXCMMapControl*, WUXCMMapTargetCameraChangedEventArgs*))del;
- (void)removeTargetCameraChangedEvent:(EventRegistrationToken)tok;
- (NSArray*)findMapElementsAtOffset:(WFPoint*)offset;
- (void)getLocationFromOffset:(WFPoint*)offset location:(WDGGeopoint**)location;
- (void)getOffsetFromLocation:(WDGGeopoint*)location offset:(WFPoint**)offset;
- (void)isLocationInView:(WDGGeopoint*)location isInView:(BOOL*)isInView;
- (void)trySetViewBoundsAsync:(WDGGeoboundingBox*)bounds
                       margin:(id /* WXThickness* */)margin
                    animation:(WUXCMMapAnimationKind)animation
                      success:(void (^)(BOOL))success
                      failure:(void (^)(NSError*))failure;
- (void)trySetViewWithCenterAsync:(WDGGeopoint*)center success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)trySetViewWithCenterAndZoomAsync:(WDGGeopoint*)center
                               zoomLevel:(id /* double */)zoomLevel
                                 success:(void (^)(BOOL))success
                                 failure:(void (^)(NSError*))failure;
- (void)trySetViewWithCenterZoomHeadingAndPitchAsync:(WDGGeopoint*)center
                                           zoomLevel:(id /* double */)zoomLevel
                                             heading:(id /* double */)heading
                                        desiredPitch:(id /* double */)desiredPitch
                                             success:(void (^)(BOOL))success
                                             failure:(void (^)(NSError*))failure;
- (void)trySetViewWithCenterZoomHeadingPitchAndAnimationAsync:(WDGGeopoint*)center
                                                    zoomLevel:(id /* double */)zoomLevel
                                                      heading:(id /* double */)heading
                                                 desiredPitch:(id /* double */)desiredPitch
                                                    animation:(WUXCMMapAnimationKind)animation
                                                      success:(void (^)(BOOL))success
                                                      failure:(void (^)(NSError*))failure;
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
- (void)trySetSceneWithAnimationAsync:(WUXCMMapScene*)scene
                        animationKind:(WUXCMMapAnimationKind)animationKind
                              success:(void (^)(BOOL))success
                              failure:(void (^)(NSError*))failure;
@end

#endif // __WUXCMMapControl_DEFINED__
