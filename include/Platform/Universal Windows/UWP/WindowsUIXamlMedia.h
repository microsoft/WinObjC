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

// WindowsUIXamlMedia.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIXAMLEXPORT
#define OBJCUWPWINDOWSUIXAMLEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIXaml.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUXMVisualTreeHelper, WUXMPartialMediaFailureDetectedEventArgs, WUXMMatrixHelper, WUXMBrushCollection, WUXMCompositionTarget, WUXMDoubleCollection, WUXMFontFamily, WUXMMediaTransportControlsThumbnailRequestedEventArgs, WUXMPointCollection, WUXMRenderingEventArgs, WUXMTimelineMarkerCollection, WUXMTransformCollection, WUXMBrush, WUXMCacheMode, WUXMGeneralTransform, WUXMGeometry, WUXMImageSource, WUXMPathSegment, WUXMProjection, WUXMRateChangedRoutedEventArgs, WUXMTimelineMarker, WUXMTimelineMarkerRoutedEventArgs, WUXMXamlLight, WUXMBitmapCache, WUXMMatrix3DProjection, WUXMPlaneProjection, WUXMRectangleGeometry, WUXMSolidColorBrush, WUXMTransform, WUXMCompositeTransform, WUXMMatrixTransform, WUXMRotateTransform, WUXMScaleTransform, WUXMSkewTransform, WUXMTransformGroup, WUXMTranslateTransform, WUXMGeometryCollection, WUXMGradientStopCollection, WUXMLoadedImageSourceLoadCompletedEventArgs, WUXMLoadedImageSurface, WUXMPathFigureCollection, WUXMPathSegmentCollection, WUXMGradientStop, WUXMPathFigure, WUXMArcSegment, WUXMBezierSegment, WUXMEllipseGeometry, WUXMGeometryGroup, WUXMGradientBrush, WUXMLineGeometry, WUXMLineSegment, WUXMPathGeometry, WUXMPolyBezierSegment, WUXMPolyLineSegment, WUXMPolyQuadraticBezierSegment, WUXMQuadraticBezierSegment, WUXMTileBrush, WUXMXamlCompositionBrushBase, WUXMAcrylicBrush, WUXMRevealBrush, WUXMRevealBorderBrush, WUXMRevealBackgroundBrush, WUXMImageBrush, WUXMLinearGradientBrush;
@class WUXMMatrix;
@protocol WUXMIAcrylicBrush, WUXMIAcrylicBrushStatics, WUXMIAcrylicBrushFactory, WUXMIRevealBrush, WUXMIRevealBrushFactory, WUXMIRevealBrushStatics, WUXMIRevealBorderBrushFactory, WUXMIRevealBorderBrush, WUXMIRevealBackgroundBrushFactory, WUXMIRevealBackgroundBrush, WUXMIVisualTreeHelper, WUXMIVisualTreeHelperStatics, WUXMIVisualTreeHelperStatics2, WUXMIPartialMediaFailureDetectedEventArgs, WUXMIPartialMediaFailureDetectedEventArgs2, WUXMIMatrixHelper, WUXMIMatrixHelperStatics, WUXMICompositionTarget, WUXMICompositionTargetStatics, WUXMIFontFamily, WUXMIFontFamilyFactory, WUXMIFontFamilyStatics2, WUXMIMediaTransportControlsThumbnailRequestedEventArgs, WUXMIRenderingEventArgs, WUXMIBrush, WUXMIBrushStatics, WUXMIBrushFactory, WUXMICacheMode, WUXMICacheModeFactory, WUXMIGeneralTransform, WUXMIGeneralTransformOverrides, WUXMIGeneralTransformFactory, WUXMIGeometry, WUXMIGeometryStatics, WUXMIGeometryFactory, WUXMIImageSource, WUXMIImageSourceFactory, WUXMIPathSegment, WUXMIPathSegmentFactory, WUXMIProjection, WUXMIProjectionFactory, WUXMIRateChangedRoutedEventArgs, WUXMITimelineMarker, WUXMITimelineMarkerStatics, WUXMITimelineMarkerRoutedEventArgs, WUXMIXamlLight, WUXMIXamlLightOverrides, WUXMIXamlLightProtected, WUXMIXamlLightStatics, WUXMIXamlLightFactory, WUXMIBitmapCache, WUXMIMatrix3DProjection, WUXMIMatrix3DProjectionStatics, WUXMIPlaneProjection, WUXMIPlaneProjectionStatics, WUXMIRectangleGeometry, WUXMIRectangleGeometryStatics, WUXMISolidColorBrush, WUXMISolidColorBrushStatics, WUXMISolidColorBrushFactory, WUXMITransform, WUXMITransformFactory, WUXMICompositeTransform, WUXMICompositeTransformStatics, WUXMIMatrixTransform, WUXMIMatrixTransformStatics, WUXMIRotateTransform, WUXMIRotateTransformStatics, WUXMIScaleTransform, WUXMIScaleTransformStatics, WUXMISkewTransform, WUXMISkewTransformStatics, WUXMITransformGroup, WUXMITransformGroupStatics, WUXMITranslateTransform, WUXMITranslateTransformStatics, WUXMILoadedImageSourceLoadCompletedEventArgs, WUXMILoadedImageSurface, WUXMILoadedImageSurfaceStatics, WUXMIGradientStop, WUXMIGradientStopStatics, WUXMIPathFigure, WUXMIPathFigureStatics, WUXMIArcSegment, WUXMIArcSegmentStatics, WUXMIBezierSegment, WUXMIBezierSegmentStatics, WUXMIEllipseGeometry, WUXMIEllipseGeometryStatics, WUXMIGeometryGroup, WUXMIGeometryGroupStatics, WUXMIGradientBrush, WUXMIGradientBrushStatics, WUXMIGradientBrushFactory, WUXMILineGeometry, WUXMILineGeometryStatics, WUXMILineSegment, WUXMILineSegmentStatics, WUXMIPathGeometry, WUXMIPathGeometryStatics, WUXMIPolyBezierSegment, WUXMIPolyBezierSegmentStatics, WUXMIPolyLineSegment, WUXMIPolyLineSegmentStatics, WUXMIPolyQuadraticBezierSegment, WUXMIPolyQuadraticBezierSegmentStatics, WUXMIQuadraticBezierSegment, WUXMIQuadraticBezierSegmentStatics, WUXMITileBrush, WUXMITileBrushStatics, WUXMITileBrushFactory, WUXMIXamlCompositionBrushBase, WUXMIXamlCompositionBrushBaseOverrides, WUXMIXamlCompositionBrushBaseProtected, WUXMIXamlCompositionBrushBaseStatics, WUXMIXamlCompositionBrushBaseFactory, WUXMIImageBrush, WUXMIImageBrushStatics, WUXMILinearGradientBrush, WUXMILinearGradientBrushStatics, WUXMILinearGradientBrushFactory;

// Windows.UI.Xaml.Media.AcrylicBackgroundSource
enum _WUXMAcrylicBackgroundSource {
    WUXMAcrylicBackgroundSourceHostBackdrop = 0,
    WUXMAcrylicBackgroundSourceBackdrop = 1,
};
typedef unsigned WUXMAcrylicBackgroundSource;

// Windows.UI.Xaml.Media.RevealBrushState
enum _WUXMRevealBrushState {
    WUXMRevealBrushStateNormal = 0,
    WUXMRevealBrushStatePointerOver = 1,
    WUXMRevealBrushStatePressed = 2,
};
typedef unsigned WUXMRevealBrushState;

// Windows.UI.Xaml.Media.MediaElementState
enum _WUXMMediaElementState {
    WUXMMediaElementStateClosed = 0,
    WUXMMediaElementStateOpening = 1,
    WUXMMediaElementStateBuffering = 2,
    WUXMMediaElementStatePlaying = 3,
    WUXMMediaElementStatePaused = 4,
    WUXMMediaElementStateStopped = 5,
};
typedef unsigned WUXMMediaElementState;

// Windows.UI.Xaml.Media.AudioCategory
enum _WUXMAudioCategory {
    WUXMAudioCategoryOther = 0,
    WUXMAudioCategoryForegroundOnlyMedia = 1,
    WUXMAudioCategoryBackgroundCapableMedia = 2,
    WUXMAudioCategoryCommunications = 3,
    WUXMAudioCategoryAlerts = 4,
    WUXMAudioCategorySoundEffects = 5,
    WUXMAudioCategoryGameEffects = 6,
    WUXMAudioCategoryGameMedia = 7,
    WUXMAudioCategoryGameChat = 8,
    WUXMAudioCategorySpeech = 9,
    WUXMAudioCategoryMovie = 10,
    WUXMAudioCategoryMedia = 11,
};
typedef unsigned WUXMAudioCategory;

// Windows.UI.Xaml.Media.AudioDeviceType
enum _WUXMAudioDeviceType {
    WUXMAudioDeviceTypeConsole = 0,
    WUXMAudioDeviceTypeMultimedia = 1,
    WUXMAudioDeviceTypeCommunications = 2,
};
typedef unsigned WUXMAudioDeviceType;

// Windows.UI.Xaml.Media.BrushMappingMode
enum _WUXMBrushMappingMode {
    WUXMBrushMappingModeAbsolute = 0,
    WUXMBrushMappingModeRelativeToBoundingBox = 1,
};
typedef unsigned WUXMBrushMappingMode;

// Windows.UI.Xaml.Media.ColorInterpolationMode
enum _WUXMColorInterpolationMode {
    WUXMColorInterpolationModeScRgbLinearInterpolation = 0,
    WUXMColorInterpolationModeSRgbLinearInterpolation = 1,
};
typedef unsigned WUXMColorInterpolationMode;

// Windows.UI.Xaml.Media.ElementCompositeMode
enum _WUXMElementCompositeMode {
    WUXMElementCompositeModeInherit = 0,
    WUXMElementCompositeModeSourceOver = 1,
    WUXMElementCompositeModeMinBlend = 2,
};
typedef unsigned WUXMElementCompositeMode;

// Windows.UI.Xaml.Media.FastPlayFallbackBehaviour
enum _WUXMFastPlayFallbackBehaviour {
    WUXMFastPlayFallbackBehaviourSkip = 0,
    WUXMFastPlayFallbackBehaviourHide = 1,
    WUXMFastPlayFallbackBehaviourDisable = 2,
};
typedef unsigned WUXMFastPlayFallbackBehaviour;

// Windows.UI.Xaml.Media.FillRule
enum _WUXMFillRule {
    WUXMFillRuleEvenOdd = 0,
    WUXMFillRuleNonzero = 1,
};
typedef unsigned WUXMFillRule;

// Windows.UI.Xaml.Media.GradientSpreadMethod
enum _WUXMGradientSpreadMethod {
    WUXMGradientSpreadMethodPad = 0,
    WUXMGradientSpreadMethodReflect = 1,
    WUXMGradientSpreadMethodRepeat = 2,
};
typedef unsigned WUXMGradientSpreadMethod;

// Windows.UI.Xaml.Media.MediaCanPlayResponse
enum _WUXMMediaCanPlayResponse {
    WUXMMediaCanPlayResponseNotSupported = 0,
    WUXMMediaCanPlayResponseMaybe = 1,
    WUXMMediaCanPlayResponseProbably = 2,
};
typedef unsigned WUXMMediaCanPlayResponse;

// Windows.UI.Xaml.Media.PenLineCap
enum _WUXMPenLineCap {
    WUXMPenLineCapFlat = 0,
    WUXMPenLineCapSquare = 1,
    WUXMPenLineCapRound = 2,
    WUXMPenLineCapTriangle = 3,
};
typedef unsigned WUXMPenLineCap;

// Windows.UI.Xaml.Media.PenLineJoin
enum _WUXMPenLineJoin {
    WUXMPenLineJoinMiter = 0,
    WUXMPenLineJoinBevel = 1,
    WUXMPenLineJoinRound = 2,
};
typedef unsigned WUXMPenLineJoin;

// Windows.UI.Xaml.Media.Stereo3DVideoPackingMode
enum _WUXMStereo3DVideoPackingMode {
    WUXMStereo3DVideoPackingModeNone = 0,
    WUXMStereo3DVideoPackingModeSideBySide = 1,
    WUXMStereo3DVideoPackingModeTopBottom = 2,
};
typedef unsigned WUXMStereo3DVideoPackingMode;

// Windows.UI.Xaml.Media.Stereo3DVideoRenderMode
enum _WUXMStereo3DVideoRenderMode {
    WUXMStereo3DVideoRenderModeMono = 0,
    WUXMStereo3DVideoRenderModeStereo = 1,
};
typedef unsigned WUXMStereo3DVideoRenderMode;

// Windows.UI.Xaml.Media.Stretch
enum _WUXMStretch {
    WUXMStretchNone = 0,
    WUXMStretchFill = 1,
    WUXMStretchUniform = 2,
    WUXMStretchUniformToFill = 3,
};
typedef unsigned WUXMStretch;

// Windows.UI.Xaml.Media.StyleSimulations
enum _WUXMStyleSimulations {
    WUXMStyleSimulationsNone = 0,
    WUXMStyleSimulationsBoldSimulation = 1,
    WUXMStyleSimulationsItalicSimulation = 2,
    WUXMStyleSimulationsBoldItalicSimulation = 3,
};
typedef unsigned WUXMStyleSimulations;

// Windows.UI.Xaml.Media.SweepDirection
enum _WUXMSweepDirection {
    WUXMSweepDirectionCounterclockwise = 0,
    WUXMSweepDirectionClockwise = 1,
};
typedef unsigned WUXMSweepDirection;

// Windows.UI.Xaml.Media.AlignmentX
enum _WUXMAlignmentX {
    WUXMAlignmentXLeft = 0,
    WUXMAlignmentXCenter = 1,
    WUXMAlignmentXRight = 2,
};
typedef unsigned WUXMAlignmentX;

// Windows.UI.Xaml.Media.AlignmentY
enum _WUXMAlignmentY {
    WUXMAlignmentYTop = 0,
    WUXMAlignmentYCenter = 1,
    WUXMAlignmentYBottom = 2,
};
typedef unsigned WUXMAlignmentY;

// Windows.UI.Xaml.Media.LoadedImageSourceLoadStatus
enum _WUXMLoadedImageSourceLoadStatus {
    WUXMLoadedImageSourceLoadStatusSuccess = 0,
    WUXMLoadedImageSourceLoadStatusNetworkError = 1,
    WUXMLoadedImageSourceLoadStatusInvalidFormat = 2,
    WUXMLoadedImageSourceLoadStatusOther = 3,
};
typedef unsigned WUXMLoadedImageSourceLoadStatus;

#include "WindowsStorageStreams.h"
#include "WindowsUI.h"
#include "WindowsUIXamlControlsPrimitives.h"
#include "WindowsFoundation.h"
#include "WindowsUIComposition.h"
#include "WindowsUIXaml.h"
#include "WindowsUIXamlMediaMedia3D.h"
#include "WindowsMediaPlayback.h"
#include "WindowsUICore.h"
// Windows.UI.Xaml.DependencyPropertyChangedCallback
#ifndef __WXDependencyPropertyChangedCallback__DEFINED
#define __WXDependencyPropertyChangedCallback__DEFINED
typedef void(^WXDependencyPropertyChangedCallback)(WXDependencyObject* sender, WXDependencyProperty* dp);
#endif // __WXDependencyPropertyChangedCallback__DEFINED

// Windows.UI.Xaml.ExceptionRoutedEventHandler
#ifndef __WXExceptionRoutedEventHandler__DEFINED
#define __WXExceptionRoutedEventHandler__DEFINED
typedef void(^WXExceptionRoutedEventHandler)(RTObject* sender, WXExceptionRoutedEventArgs* e);
#endif // __WXExceptionRoutedEventHandler__DEFINED

// Windows.UI.Xaml.RoutedEventHandler
#ifndef __WXRoutedEventHandler__DEFINED
#define __WXRoutedEventHandler__DEFINED
typedef void(^WXRoutedEventHandler)(RTObject* sender, WXRoutedEventArgs* e);
#endif // __WXRoutedEventHandler__DEFINED


#import <Foundation/Foundation.h>

// [struct] Windows.UI.Xaml.Media.Matrix
OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMMatrix : NSObject
+ (instancetype)new;
@property double m11;
@property double m12;
@property double m21;
@property double m22;
@property double offsetX;
@property double offsetY;
@end

// Windows.UI.Xaml.Media.RateChangedRoutedEventHandler
#ifndef __WUXMRateChangedRoutedEventHandler__DEFINED
#define __WUXMRateChangedRoutedEventHandler__DEFINED
typedef void(^WUXMRateChangedRoutedEventHandler)(RTObject* sender, WUXMRateChangedRoutedEventArgs* e);
#endif // __WUXMRateChangedRoutedEventHandler__DEFINED

// Windows.UI.Xaml.Media.TimelineMarkerRoutedEventHandler
#ifndef __WUXMTimelineMarkerRoutedEventHandler__DEFINED
#define __WUXMTimelineMarkerRoutedEventHandler__DEFINED
typedef void(^WUXMTimelineMarkerRoutedEventHandler)(RTObject* sender, WUXMTimelineMarkerRoutedEventArgs* e);
#endif // __WUXMTimelineMarkerRoutedEventHandler__DEFINED

// Windows.UI.Xaml.Media.IGeneralTransformOverrides
#ifndef __WUXMIGeneralTransformOverrides_DEFINED__
#define __WUXMIGeneralTransformOverrides_DEFINED__

@protocol WUXMIGeneralTransformOverrides
@property (readonly) WUXMGeneralTransform* inverseCore;
- (BOOL)tryTransformCore:(WFPoint*)inPoint outPoint:(WFPoint**)outPoint;
- (WFRect*)transformBoundsCore:(WFRect*)rect;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMIGeneralTransformOverrides : RTObject <WUXMIGeneralTransformOverrides>
@end

#endif // __WUXMIGeneralTransformOverrides_DEFINED__

// Windows.UI.Xaml.Media.IXamlLightOverrides
#ifndef __WUXMIXamlLightOverrides_DEFINED__
#define __WUXMIXamlLightOverrides_DEFINED__

@protocol WUXMIXamlLightOverrides
- (NSString *)getId;
- (void)onConnected:(WXUIElement*)newElement;
- (void)onDisconnected:(WXUIElement*)oldElement;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMIXamlLightOverrides : RTObject <WUXMIXamlLightOverrides>
@end

#endif // __WUXMIXamlLightOverrides_DEFINED__

// Windows.UI.Xaml.Media.IXamlCompositionBrushBaseOverrides
#ifndef __WUXMIXamlCompositionBrushBaseOverrides_DEFINED__
#define __WUXMIXamlCompositionBrushBaseOverrides_DEFINED__

@protocol WUXMIXamlCompositionBrushBaseOverrides
- (void)onConnected;
- (void)onDisconnected;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMIXamlCompositionBrushBaseOverrides : RTObject <WUXMIXamlCompositionBrushBaseOverrides>
@end

#endif // __WUXMIXamlCompositionBrushBaseOverrides_DEFINED__

// Windows.UI.Xaml.Media.VisualTreeHelper
#ifndef __WUXMVisualTreeHelper_DEFINED__
#define __WUXMVisualTreeHelper_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMVisualTreeHelper : RTObject
+ (NSArray* /* WUXCPPopup* */)getOpenPopups:(WXWindow*)window;
+ (id<NSFastEnumeration> /* WXUIElement* */)findElementsInHostCoordinatesPoint:(WFPoint*)intersectingPoint subtree:(WXUIElement*)subtree;
+ (id<NSFastEnumeration> /* WXUIElement* */)findElementsInHostCoordinatesRect:(WFRect*)intersectingRect subtree:(WXUIElement*)subtree;
+ (id<NSFastEnumeration> /* WXUIElement* */)findAllElementsInHostCoordinatesPoint:(WFPoint*)intersectingPoint subtree:(WXUIElement*)subtree includeAllElements:(BOOL)includeAllElements;
+ (id<NSFastEnumeration> /* WXUIElement* */)findAllElementsInHostCoordinatesRect:(WFRect*)intersectingRect subtree:(WXUIElement*)subtree includeAllElements:(BOOL)includeAllElements;
+ (WXDependencyObject*)getChild:(WXDependencyObject*)reference childIndex:(int)childIndex;
+ (int)getChildrenCount:(WXDependencyObject*)reference;
+ (WXDependencyObject*)getParent:(WXDependencyObject*)reference;
+ (void)disconnectChildrenRecursive:(WXUIElement*)element;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMVisualTreeHelper_DEFINED__

// Windows.UI.Xaml.Media.PartialMediaFailureDetectedEventArgs
#ifndef __WUXMPartialMediaFailureDetectedEventArgs_DEFINED__
#define __WUXMPartialMediaFailureDetectedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMPartialMediaFailureDetectedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMPFailedMediaStreamKind streamKind;
@property (readonly) HRESULT extendedError;
@end

#endif // __WUXMPartialMediaFailureDetectedEventArgs_DEFINED__

// Windows.UI.Xaml.Media.MatrixHelper
#ifndef __WUXMMatrixHelper_DEFINED__
#define __WUXMMatrixHelper_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMMatrixHelper : RTObject
+ (WUXMMatrix*)fromElements:(double)m11 m12:(double)m12 m21:(double)m21 m22:(double)m22 offsetX:(double)offsetX offsetY:(double)offsetY;
+ (BOOL)getIsIdentity:(WUXMMatrix*)target;
+ (WFPoint*)transform:(WUXMMatrix*)target point:(WFPoint*)point;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (WUXMMatrix*)identity;
@end

#endif // __WUXMMatrixHelper_DEFINED__

// Windows.UI.Xaml.Media.BrushCollection
#ifndef __WUXMBrushCollection_DEFINED__
#define __WUXMBrushCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMBrushCollection : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMBrushCollection_DEFINED__

// Windows.UI.Xaml.Media.CompositionTarget
#ifndef __WUXMCompositionTarget_DEFINED__
#define __WUXMCompositionTarget_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMCompositionTarget : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (EventRegistrationToken)addRenderingEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeRenderingEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addSurfaceContentsLostEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeSurfaceContentsLostEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXMCompositionTarget_DEFINED__

// Windows.UI.Xaml.Media.DoubleCollection
#ifndef __WUXMDoubleCollection_DEFINED__
#define __WUXMDoubleCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMDoubleCollection : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMDoubleCollection_DEFINED__

// Windows.UI.Xaml.Media.FontFamily
#ifndef __WUXMFontFamily_DEFINED__
#define __WUXMFontFamily_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMFontFamily : RTObject
+ (WUXMFontFamily*)makeInstanceWithName:(NSString *)familyName ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * source;
+ (WUXMFontFamily*)xamlAutoFontFamily;
@end

#endif // __WUXMFontFamily_DEFINED__

// Windows.UI.Xaml.Media.MediaTransportControlsThumbnailRequestedEventArgs
#ifndef __WUXMMediaTransportControlsThumbnailRequestedEventArgs_DEFINED__
#define __WUXMMediaTransportControlsThumbnailRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMMediaTransportControlsThumbnailRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)setThumbnailImage:(RTObject<WSSIInputStream>*)source;
- (WFDeferral*)getDeferral;
@end

#endif // __WUXMMediaTransportControlsThumbnailRequestedEventArgs_DEFINED__

// Windows.UI.Xaml.Media.PointCollection
#ifndef __WUXMPointCollection_DEFINED__
#define __WUXMPointCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMPointCollection : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMPointCollection_DEFINED__

// Windows.UI.Xaml.Media.RenderingEventArgs
#ifndef __WUXMRenderingEventArgs_DEFINED__
#define __WUXMRenderingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMRenderingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* renderingTime;
@end

#endif // __WUXMRenderingEventArgs_DEFINED__

// Windows.UI.Xaml.Media.TimelineMarkerCollection
#ifndef __WUXMTimelineMarkerCollection_DEFINED__
#define __WUXMTimelineMarkerCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMTimelineMarkerCollection : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMTimelineMarkerCollection_DEFINED__

// Windows.UI.Xaml.Media.TransformCollection
#ifndef __WUXMTransformCollection_DEFINED__
#define __WUXMTransformCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMTransformCollection : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMTransformCollection_DEFINED__

// Windows.UI.Xaml.DependencyObject
#ifndef __WXDependencyObject_DEFINED__
#define __WXDependencyObject_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
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

// Windows.UI.Xaml.Media.Brush
#ifndef __WUXMBrush_DEFINED__
#define __WUXMBrush_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMBrush : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMTransform* transform;
@property (retain) WUXMTransform* relativeTransform;
@property double opacity;
+ (WXDependencyProperty*)opacityProperty;
+ (WXDependencyProperty*)relativeTransformProperty;
+ (WXDependencyProperty*)transformProperty;
@end

#endif // __WUXMBrush_DEFINED__

// Windows.UI.Xaml.Media.CacheMode
#ifndef __WUXMCacheMode_DEFINED__
#define __WUXMCacheMode_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMCacheMode : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMCacheMode_DEFINED__

// Windows.UI.Xaml.Media.GeneralTransform
#ifndef __WUXMGeneralTransform_DEFINED__
#define __WUXMGeneralTransform_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMGeneralTransform : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUXMGeneralTransform* inverse;
- (WFPoint*)transformPoint:(WFPoint*)point;
- (BOOL)tryTransform:(WFPoint*)inPoint outPoint:(WFPoint**)outPoint;
- (WFRect*)transformBounds:(WFRect*)rect;
- (BOOL)tryTransformCore:(WFPoint*)inPoint outPoint:(WFPoint**)outPoint;
- (WFRect*)transformBoundsCore:(WFRect*)rect;
@end

#endif // __WUXMGeneralTransform_DEFINED__

// Windows.UI.Xaml.Media.Geometry
#ifndef __WUXMGeometry_DEFINED__
#define __WUXMGeometry_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMGeometry : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMTransform* transform;
@property (readonly) WFRect* bounds;
+ (WUXMGeometry*)empty;
+ (double)standardFlatteningTolerance;
+ (WXDependencyProperty*)transformProperty;
@end

#endif // __WUXMGeometry_DEFINED__

// Windows.UI.Xaml.Media.ImageSource
#ifndef __WUXMImageSource_DEFINED__
#define __WUXMImageSource_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMImageSource : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMImageSource_DEFINED__

// Windows.UI.Xaml.Media.PathSegment
#ifndef __WUXMPathSegment_DEFINED__
#define __WUXMPathSegment_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMPathSegment : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMPathSegment_DEFINED__

// Windows.UI.Xaml.Media.Projection
#ifndef __WUXMProjection_DEFINED__
#define __WUXMProjection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMProjection : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMProjection_DEFINED__

// Windows.UI.Xaml.RoutedEventArgs
#ifndef __WXRoutedEventArgs_DEFINED__
#define __WXRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXRoutedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject* originalSource;
@end

#endif // __WXRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Media.RateChangedRoutedEventArgs
#ifndef __WUXMRateChangedRoutedEventArgs_DEFINED__
#define __WUXMRateChangedRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMRateChangedRoutedEventArgs : WXRoutedEventArgs
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMRateChangedRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Media.TimelineMarker
#ifndef __WUXMTimelineMarker_DEFINED__
#define __WUXMTimelineMarker_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMTimelineMarker : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * type;
@property (retain) WFTimeSpan* time;
@property (retain) NSString * text;
+ (WXDependencyProperty*)textProperty;
+ (WXDependencyProperty*)timeProperty;
+ (WXDependencyProperty*)typeProperty;
@end

#endif // __WUXMTimelineMarker_DEFINED__

// Windows.UI.Xaml.Media.TimelineMarkerRoutedEventArgs
#ifndef __WUXMTimelineMarkerRoutedEventArgs_DEFINED__
#define __WUXMTimelineMarkerRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMTimelineMarkerRoutedEventArgs : WXRoutedEventArgs
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMTimelineMarker* marker;
@end

#endif // __WUXMTimelineMarkerRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Media.XamlLight
#ifndef __WUXMXamlLight_DEFINED__
#define __WUXMXamlLight_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMXamlLight : WXDependencyObject
+ (void)addTargetElement:(NSString *)lightId element:(WXUIElement*)element;
+ (void)removeTargetElement:(NSString *)lightId element:(WXUIElement*)element;
+ (void)addTargetBrush:(NSString *)lightId brush:(WUXMBrush*)brush;
+ (void)removeTargetBrush:(NSString *)lightId brush:(WUXMBrush*)brush;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (NSString *)getId;
- (void)onConnected:(WXUIElement*)newElement;
- (void)onDisconnected:(WXUIElement*)oldElement;
@end

#endif // __WUXMXamlLight_DEFINED__

// Windows.UI.Xaml.Media.BitmapCache
#ifndef __WUXMBitmapCache_DEFINED__
#define __WUXMBitmapCache_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMBitmapCache : WUXMCacheMode
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMBitmapCache_DEFINED__

// Windows.UI.Xaml.Media.Matrix3DProjection
#ifndef __WUXMMatrix3DProjection_DEFINED__
#define __WUXMMatrix3DProjection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMMatrix3DProjection : WUXMProjection
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMMMatrix3D* projectionMatrix;
+ (WXDependencyProperty*)projectionMatrixProperty;
@end

#endif // __WUXMMatrix3DProjection_DEFINED__

// Windows.UI.Xaml.Media.PlaneProjection
#ifndef __WUXMPlaneProjection_DEFINED__
#define __WUXMPlaneProjection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMPlaneProjection : WUXMProjection
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double localOffsetX;
@property double globalOffsetZ;
@property double globalOffsetY;
@property double globalOffsetX;
@property double centerOfRotationZ;
@property double centerOfRotationY;
@property double centerOfRotationX;
@property double rotationZ;
@property double rotationY;
@property double rotationX;
@property double localOffsetZ;
@property double localOffsetY;
@property (readonly) WUXMMMatrix3D* projectionMatrix;
+ (WXDependencyProperty*)centerOfRotationXProperty;
+ (WXDependencyProperty*)centerOfRotationYProperty;
+ (WXDependencyProperty*)centerOfRotationZProperty;
+ (WXDependencyProperty*)globalOffsetXProperty;
+ (WXDependencyProperty*)globalOffsetYProperty;
+ (WXDependencyProperty*)globalOffsetZProperty;
+ (WXDependencyProperty*)localOffsetXProperty;
+ (WXDependencyProperty*)localOffsetYProperty;
+ (WXDependencyProperty*)localOffsetZProperty;
+ (WXDependencyProperty*)projectionMatrixProperty;
+ (WXDependencyProperty*)rotationXProperty;
+ (WXDependencyProperty*)rotationYProperty;
+ (WXDependencyProperty*)rotationZProperty;
@end

#endif // __WUXMPlaneProjection_DEFINED__

// Windows.UI.Xaml.Media.RectangleGeometry
#ifndef __WUXMRectangleGeometry_DEFINED__
#define __WUXMRectangleGeometry_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMRectangleGeometry : WUXMGeometry
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFRect* rect;
+ (WXDependencyProperty*)rectProperty;
@end

#endif // __WUXMRectangleGeometry_DEFINED__

// Windows.UI.Xaml.Media.SolidColorBrush
#ifndef __WUXMSolidColorBrush_DEFINED__
#define __WUXMSolidColorBrush_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMSolidColorBrush : WUXMBrush
+ (WUXMSolidColorBrush*)makeInstanceWithColor:(WUColor*)color ACTIVATOR;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUColor* color;
+ (WXDependencyProperty*)colorProperty;
@end

#endif // __WUXMSolidColorBrush_DEFINED__

// Windows.UI.Xaml.Media.Transform
#ifndef __WUXMTransform_DEFINED__
#define __WUXMTransform_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMTransform : WUXMGeneralTransform
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMTransform_DEFINED__

// Windows.UI.Xaml.Media.CompositeTransform
#ifndef __WUXMCompositeTransform_DEFINED__
#define __WUXMCompositeTransform_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMCompositeTransform : WUXMTransform
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double translateY;
@property double translateX;
@property double skewY;
@property double skewX;
@property double scaleY;
@property double scaleX;
@property double rotation;
@property double centerY;
@property double centerX;
+ (WXDependencyProperty*)centerXProperty;
+ (WXDependencyProperty*)centerYProperty;
+ (WXDependencyProperty*)rotationProperty;
+ (WXDependencyProperty*)scaleXProperty;
+ (WXDependencyProperty*)scaleYProperty;
+ (WXDependencyProperty*)skewXProperty;
+ (WXDependencyProperty*)skewYProperty;
+ (WXDependencyProperty*)translateXProperty;
+ (WXDependencyProperty*)translateYProperty;
@end

#endif // __WUXMCompositeTransform_DEFINED__

// Windows.UI.Xaml.Media.MatrixTransform
#ifndef __WUXMMatrixTransform_DEFINED__
#define __WUXMMatrixTransform_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMMatrixTransform : WUXMTransform
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMMatrix* matrix;
+ (WXDependencyProperty*)matrixProperty;
@end

#endif // __WUXMMatrixTransform_DEFINED__

// Windows.UI.Xaml.Media.RotateTransform
#ifndef __WUXMRotateTransform_DEFINED__
#define __WUXMRotateTransform_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMRotateTransform : WUXMTransform
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double centerY;
@property double centerX;
@property double angle;
+ (WXDependencyProperty*)angleProperty;
+ (WXDependencyProperty*)centerXProperty;
+ (WXDependencyProperty*)centerYProperty;
@end

#endif // __WUXMRotateTransform_DEFINED__

// Windows.UI.Xaml.Media.ScaleTransform
#ifndef __WUXMScaleTransform_DEFINED__
#define __WUXMScaleTransform_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMScaleTransform : WUXMTransform
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double scaleY;
@property double scaleX;
@property double centerY;
@property double centerX;
+ (WXDependencyProperty*)centerXProperty;
+ (WXDependencyProperty*)centerYProperty;
+ (WXDependencyProperty*)scaleXProperty;
+ (WXDependencyProperty*)scaleYProperty;
@end

#endif // __WUXMScaleTransform_DEFINED__

// Windows.UI.Xaml.Media.SkewTransform
#ifndef __WUXMSkewTransform_DEFINED__
#define __WUXMSkewTransform_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMSkewTransform : WUXMTransform
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double centerY;
@property double centerX;
@property double angleY;
@property double angleX;
+ (WXDependencyProperty*)angleXProperty;
+ (WXDependencyProperty*)angleYProperty;
+ (WXDependencyProperty*)centerXProperty;
+ (WXDependencyProperty*)centerYProperty;
@end

#endif // __WUXMSkewTransform_DEFINED__

// Windows.UI.Xaml.Media.TransformGroup
#ifndef __WUXMTransformGroup_DEFINED__
#define __WUXMTransformGroup_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMTransformGroup : WUXMTransform
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMTransformCollection* children;
@property (readonly) WUXMMatrix* value;
+ (WXDependencyProperty*)childrenProperty;
@end

#endif // __WUXMTransformGroup_DEFINED__

// Windows.UI.Xaml.Media.TranslateTransform
#ifndef __WUXMTranslateTransform_DEFINED__
#define __WUXMTranslateTransform_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMTranslateTransform : WUXMTransform
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double y;
@property double x;
+ (WXDependencyProperty*)xProperty;
+ (WXDependencyProperty*)yProperty;
@end

#endif // __WUXMTranslateTransform_DEFINED__

// Windows.UI.Xaml.Media.GeometryCollection
#ifndef __WUXMGeometryCollection_DEFINED__
#define __WUXMGeometryCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMGeometryCollection : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMGeometryCollection_DEFINED__

// Windows.UI.Xaml.Media.GradientStopCollection
#ifndef __WUXMGradientStopCollection_DEFINED__
#define __WUXMGradientStopCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMGradientStopCollection : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMGradientStopCollection_DEFINED__

// Windows.UI.Xaml.Media.LoadedImageSourceLoadCompletedEventArgs
#ifndef __WUXMLoadedImageSourceLoadCompletedEventArgs_DEFINED__
#define __WUXMLoadedImageSourceLoadCompletedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMLoadedImageSourceLoadCompletedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUXMLoadedImageSourceLoadStatus status;
@end

#endif // __WUXMLoadedImageSourceLoadCompletedEventArgs_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.UI.Composition.ICompositionSurface
#ifndef __WUCICompositionSurface_DEFINED__
#define __WUCICompositionSurface_DEFINED__

@protocol WUCICompositionSurface
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUCICompositionSurface : RTObject <WUCICompositionSurface>
@end

#endif // __WUCICompositionSurface_DEFINED__

// Windows.UI.Xaml.Media.LoadedImageSurface
#ifndef __WUXMLoadedImageSurface_DEFINED__
#define __WUXMLoadedImageSurface_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMLoadedImageSurface : RTObject <WFIClosable, WUCICompositionSurface>
+ (WUXMLoadedImageSurface*)startLoadFromUriWithSize:(WFUri*)uri desiredMaxSize:(WFSize*)desiredMaxSize;
+ (WUXMLoadedImageSurface*)startLoadFromUri:(WFUri*)uri;
+ (WUXMLoadedImageSurface*)startLoadFromStreamWithSize:(RTObject<WSSIRandomAccessStream>*)stream desiredMaxSize:(WFSize*)desiredMaxSize;
+ (WUXMLoadedImageSurface*)startLoadFromStream:(RTObject<WSSIRandomAccessStream>*)stream;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFSize* decodedPhysicalSize;
@property (readonly) WFSize* decodedSize;
@property (readonly) WFSize* naturalSize;
- (EventRegistrationToken)addLoadCompletedEvent:(void(^)(WUXMLoadedImageSurface*, WUXMLoadedImageSourceLoadCompletedEventArgs*))del;
- (void)removeLoadCompletedEvent:(EventRegistrationToken)tok;
- (void)close;
@end

#endif // __WUXMLoadedImageSurface_DEFINED__

// Windows.UI.Xaml.Media.PathFigureCollection
#ifndef __WUXMPathFigureCollection_DEFINED__
#define __WUXMPathFigureCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMPathFigureCollection : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMPathFigureCollection_DEFINED__

// Windows.UI.Xaml.Media.PathSegmentCollection
#ifndef __WUXMPathSegmentCollection_DEFINED__
#define __WUXMPathSegmentCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMPathSegmentCollection : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMPathSegmentCollection_DEFINED__

// Windows.UI.Xaml.Media.GradientStop
#ifndef __WUXMGradientStop_DEFINED__
#define __WUXMGradientStop_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMGradientStop : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double offset;
@property (retain) WUColor* color;
+ (WXDependencyProperty*)colorProperty;
+ (WXDependencyProperty*)offsetProperty;
@end

#endif // __WUXMGradientStop_DEFINED__

// Windows.UI.Xaml.Media.PathFigure
#ifndef __WUXMPathFigure_DEFINED__
#define __WUXMPathFigure_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMPathFigure : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFPoint* startPoint;
@property (retain) WUXMPathSegmentCollection* segments;
@property BOOL isFilled;
@property BOOL isClosed;
+ (WXDependencyProperty*)isClosedProperty;
+ (WXDependencyProperty*)isFilledProperty;
+ (WXDependencyProperty*)segmentsProperty;
+ (WXDependencyProperty*)startPointProperty;
@end

#endif // __WUXMPathFigure_DEFINED__

// Windows.UI.Xaml.Media.ArcSegment
#ifndef __WUXMArcSegment_DEFINED__
#define __WUXMArcSegment_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMArcSegment : WUXMPathSegment
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXMSweepDirection sweepDirection;
@property (retain) WFSize* size;
@property double rotationAngle;
@property (retain) WFPoint* point;
@property BOOL isLargeArc;
+ (WXDependencyProperty*)isLargeArcProperty;
+ (WXDependencyProperty*)pointProperty;
+ (WXDependencyProperty*)rotationAngleProperty;
+ (WXDependencyProperty*)sizeProperty;
+ (WXDependencyProperty*)sweepDirectionProperty;
@end

#endif // __WUXMArcSegment_DEFINED__

// Windows.UI.Xaml.Media.BezierSegment
#ifndef __WUXMBezierSegment_DEFINED__
#define __WUXMBezierSegment_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMBezierSegment : WUXMPathSegment
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFPoint* point3;
@property (retain) WFPoint* point2;
@property (retain) WFPoint* point1;
+ (WXDependencyProperty*)point1Property;
+ (WXDependencyProperty*)point2Property;
+ (WXDependencyProperty*)point3Property;
@end

#endif // __WUXMBezierSegment_DEFINED__

// Windows.UI.Xaml.Media.EllipseGeometry
#ifndef __WUXMEllipseGeometry_DEFINED__
#define __WUXMEllipseGeometry_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMEllipseGeometry : WUXMGeometry
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double radiusY;
@property double radiusX;
@property (retain) WFPoint* center;
+ (WXDependencyProperty*)centerProperty;
+ (WXDependencyProperty*)radiusXProperty;
+ (WXDependencyProperty*)radiusYProperty;
@end

#endif // __WUXMEllipseGeometry_DEFINED__

// Windows.UI.Xaml.Media.GeometryGroup
#ifndef __WUXMGeometryGroup_DEFINED__
#define __WUXMGeometryGroup_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMGeometryGroup : WUXMGeometry
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXMFillRule fillRule;
@property (retain) WUXMGeometryCollection* children;
+ (WXDependencyProperty*)childrenProperty;
+ (WXDependencyProperty*)fillRuleProperty;
@end

#endif // __WUXMGeometryGroup_DEFINED__

// Windows.UI.Xaml.Media.GradientBrush
#ifndef __WUXMGradientBrush_DEFINED__
#define __WUXMGradientBrush_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMGradientBrush : WUXMBrush
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXMGradientSpreadMethod spreadMethod;
@property WUXMBrushMappingMode mappingMode;
@property (retain) WUXMGradientStopCollection* gradientStops;
@property WUXMColorInterpolationMode colorInterpolationMode;
+ (WXDependencyProperty*)colorInterpolationModeProperty;
+ (WXDependencyProperty*)gradientStopsProperty;
+ (WXDependencyProperty*)mappingModeProperty;
+ (WXDependencyProperty*)spreadMethodProperty;
@end

#endif // __WUXMGradientBrush_DEFINED__

// Windows.UI.Xaml.Media.LineGeometry
#ifndef __WUXMLineGeometry_DEFINED__
#define __WUXMLineGeometry_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMLineGeometry : WUXMGeometry
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFPoint* startPoint;
@property (retain) WFPoint* endPoint;
+ (WXDependencyProperty*)endPointProperty;
+ (WXDependencyProperty*)startPointProperty;
@end

#endif // __WUXMLineGeometry_DEFINED__

// Windows.UI.Xaml.Media.LineSegment
#ifndef __WUXMLineSegment_DEFINED__
#define __WUXMLineSegment_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMLineSegment : WUXMPathSegment
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFPoint* point;
+ (WXDependencyProperty*)pointProperty;
@end

#endif // __WUXMLineSegment_DEFINED__

// Windows.UI.Xaml.Media.PathGeometry
#ifndef __WUXMPathGeometry_DEFINED__
#define __WUXMPathGeometry_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMPathGeometry : WUXMGeometry
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXMFillRule fillRule;
@property (retain) WUXMPathFigureCollection* figures;
+ (WXDependencyProperty*)figuresProperty;
+ (WXDependencyProperty*)fillRuleProperty;
@end

#endif // __WUXMPathGeometry_DEFINED__

// Windows.UI.Xaml.Media.PolyBezierSegment
#ifndef __WUXMPolyBezierSegment_DEFINED__
#define __WUXMPolyBezierSegment_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMPolyBezierSegment : WUXMPathSegment
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMPointCollection* points;
+ (WXDependencyProperty*)pointsProperty;
@end

#endif // __WUXMPolyBezierSegment_DEFINED__

// Windows.UI.Xaml.Media.PolyLineSegment
#ifndef __WUXMPolyLineSegment_DEFINED__
#define __WUXMPolyLineSegment_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMPolyLineSegment : WUXMPathSegment
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMPointCollection* points;
+ (WXDependencyProperty*)pointsProperty;
@end

#endif // __WUXMPolyLineSegment_DEFINED__

// Windows.UI.Xaml.Media.PolyQuadraticBezierSegment
#ifndef __WUXMPolyQuadraticBezierSegment_DEFINED__
#define __WUXMPolyQuadraticBezierSegment_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMPolyQuadraticBezierSegment : WUXMPathSegment
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMPointCollection* points;
+ (WXDependencyProperty*)pointsProperty;
@end

#endif // __WUXMPolyQuadraticBezierSegment_DEFINED__

// Windows.UI.Xaml.Media.QuadraticBezierSegment
#ifndef __WUXMQuadraticBezierSegment_DEFINED__
#define __WUXMQuadraticBezierSegment_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMQuadraticBezierSegment : WUXMPathSegment
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFPoint* point2;
@property (retain) WFPoint* point1;
+ (WXDependencyProperty*)point1Property;
+ (WXDependencyProperty*)point2Property;
@end

#endif // __WUXMQuadraticBezierSegment_DEFINED__

// Windows.UI.Xaml.Media.TileBrush
#ifndef __WUXMTileBrush_DEFINED__
#define __WUXMTileBrush_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMTileBrush : WUXMBrush
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXMStretch stretch;
@property WUXMAlignmentY alignmentY;
@property WUXMAlignmentX alignmentX;
+ (WXDependencyProperty*)alignmentXProperty;
+ (WXDependencyProperty*)alignmentYProperty;
+ (WXDependencyProperty*)stretchProperty;
@end

#endif // __WUXMTileBrush_DEFINED__

// Windows.UI.Xaml.Media.XamlCompositionBrushBase
#ifndef __WUXMXamlCompositionBrushBase_DEFINED__
#define __WUXMXamlCompositionBrushBase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMXamlCompositionBrushBase : WUXMBrush
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUColor* fallbackColor;
+ (WXDependencyProperty*)fallbackColorProperty;
- (void)onConnected;
- (void)onDisconnected;
@end

#endif // __WUXMXamlCompositionBrushBase_DEFINED__

// Windows.UI.Xaml.Media.AcrylicBrush
#ifndef __WUXMAcrylicBrush_DEFINED__
#define __WUXMAcrylicBrush_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAcrylicBrush : WUXMXamlCompositionBrushBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* tintTransitionDuration;
@property double tintOpacity;
@property (retain) WUColor* tintColor;
@property WUXMAcrylicBackgroundSource backgroundSource;
@property BOOL alwaysUseFallback;
+ (WXDependencyProperty*)alwaysUseFallbackProperty;
+ (WXDependencyProperty*)backgroundSourceProperty;
+ (WXDependencyProperty*)tintColorProperty;
+ (WXDependencyProperty*)tintOpacityProperty;
+ (WXDependencyProperty*)tintTransitionDurationProperty;
@end

#endif // __WUXMAcrylicBrush_DEFINED__

// Windows.UI.Xaml.Media.RevealBrush
#ifndef __WUXMRevealBrush_DEFINED__
#define __WUXMRevealBrush_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMRevealBrush : WUXMXamlCompositionBrushBase
+ (void)setState:(WXUIElement*)element value:(WUXMRevealBrushState)value;
+ (WUXMRevealBrushState)getState:(WXUIElement*)element;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXApplicationTheme targetTheme;
@property (retain) WUColor* color;
@property BOOL alwaysUseFallback;
+ (WXDependencyProperty*)alwaysUseFallbackProperty;
+ (WXDependencyProperty*)colorProperty;
+ (WXDependencyProperty*)stateProperty;
+ (WXDependencyProperty*)targetThemeProperty;
@end

#endif // __WUXMRevealBrush_DEFINED__

// Windows.UI.Xaml.Media.RevealBorderBrush
#ifndef __WUXMRevealBorderBrush_DEFINED__
#define __WUXMRevealBorderBrush_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMRevealBorderBrush : WUXMRevealBrush
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMRevealBorderBrush_DEFINED__

// Windows.UI.Xaml.Media.RevealBackgroundBrush
#ifndef __WUXMRevealBackgroundBrush_DEFINED__
#define __WUXMRevealBackgroundBrush_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMRevealBackgroundBrush : WUXMRevealBrush
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMRevealBackgroundBrush_DEFINED__

// Windows.UI.Xaml.Media.ImageBrush
#ifndef __WUXMImageBrush_DEFINED__
#define __WUXMImageBrush_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMImageBrush : WUXMTileBrush
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMImageSource* imageSource;
+ (WXDependencyProperty*)imageSourceProperty;
- (EventRegistrationToken)addImageFailedEvent:(WXExceptionRoutedEventHandler)del;
- (void)removeImageFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addImageOpenedEvent:(WXRoutedEventHandler)del;
- (void)removeImageOpenedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXMImageBrush_DEFINED__

// Windows.UI.Xaml.Media.LinearGradientBrush
#ifndef __WUXMLinearGradientBrush_DEFINED__
#define __WUXMLinearGradientBrush_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMLinearGradientBrush : WUXMGradientBrush
+ (instancetype)make __attribute__ ((ns_returns_retained));
+ (WUXMLinearGradientBrush*)makeInstanceWithGradientStopCollectionAndAngle:(WUXMGradientStopCollection*)gradientStopCollection angle:(double)angle ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFPoint* startPoint;
@property (retain) WFPoint* endPoint;
+ (WXDependencyProperty*)endPointProperty;
+ (WXDependencyProperty*)startPointProperty;
@end

#endif // __WUXMLinearGradientBrush_DEFINED__

