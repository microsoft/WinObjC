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

// WindowsUIXamlMedia.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUXMVisualTreeHelper, WUXMPartialMediaFailureDetectedEventArgs, WUXMMatrixHelper, WUXMCompositionTarget, WUXMDoubleCollection,
    WUXMFontFamily, WUXMGeometryCollection, WUXMGradientStopCollection, WUXMPathFigureCollection, WUXMPathSegmentCollection,
    WUXMPointCollection, WUXMRenderingEventArgs, WUXMTimelineMarkerCollection, WUXMTransformCollection, WUXMBrush, WUXMCacheMode,
    WUXMGeneralTransform, WUXMGeometry, WUXMGradientStop, WUXMImageSource, WUXMPathFigure, WUXMPathSegment, WUXMProjection,
    WUXMRateChangedRoutedEventArgs, WUXMTimelineMarker, WUXMTimelineMarkerRoutedEventArgs, WUXMArcSegment, WUXMBezierSegment,
    WUXMBitmapCache, WUXMEllipseGeometry, WUXMGeometryGroup, WUXMGradientBrush, WUXMLineGeometry, WUXMLineSegment, WUXMMatrix3DProjection,
    WUXMPathGeometry, WUXMPlaneProjection, WUXMPolyBezierSegment, WUXMPolyLineSegment, WUXMPolyQuadraticBezierSegment,
    WUXMQuadraticBezierSegment, WUXMRectangleGeometry, WUXMSolidColorBrush, WUXMTileBrush, WUXMTransform, WUXMCompositeTransform,
    WUXMImageBrush, WUXMLinearGradientBrush, WUXMMatrixTransform, WUXMRotateTransform, WUXMScaleTransform, WUXMSkewTransform,
    WUXMTransformGroup, WUXMTranslateTransform;
@class WUXMMatrix;
@class RTArray_C_Double, RTArray_C_WFPoint, RTArray_C_WUXMGeometry, RTArray_C_WUXMGradientStop, RTArray_C_WUXMPathFigure,
    RTArray_C_WUXMPathSegment, RTArray_C_WUXMTimelineMarker, RTArray_C_WUXMTransform;
@protocol WUXMIVisualTreeHelper
, WUXMIVisualTreeHelperStatics, WUXMIVisualTreeHelperStatics2, WUXMIPartialMediaFailureDetectedEventArgs, WUXMIMatrixHelper,
    WUXMIMatrixHelperStatics, WUXMICompositionTarget, WUXMICompositionTargetStatics, WUXMIFontFamily, WUXMIFontFamilyFactory,
    WUXMIRenderingEventArgs, WUXMIBrush, WUXMIBrushStatics, WUXMIBrushFactory, WUXMICacheMode, WUXMICacheModeFactory, WUXMIGeneralTransform,
    WUXMIGeneralTransformOverrides, WUXMIGeneralTransformFactory, WUXMIGeometry, WUXMIGeometryStatics, WUXMIGeometryFactory,
    WUXMIGradientStop, WUXMIGradientStopStatics, WUXMIImageSource, WUXMIImageSourceFactory, WUXMIPathFigure, WUXMIPathFigureStatics,
    WUXMIPathSegment, WUXMIPathSegmentFactory, WUXMIProjection, WUXMIProjectionFactory, WUXMIRateChangedRoutedEventArgs,
    WUXMITimelineMarker, WUXMITimelineMarkerStatics, WUXMITimelineMarkerRoutedEventArgs, WUXMIArcSegment, WUXMIArcSegmentStatics,
    WUXMIBezierSegment, WUXMIBezierSegmentStatics, WUXMIBitmapCache, WUXMIEllipseGeometry, WUXMIEllipseGeometryStatics, WUXMIGeometryGroup,
    WUXMIGeometryGroupStatics, WUXMIGradientBrush, WUXMIGradientBrushStatics, WUXMIGradientBrushFactory, WUXMILineGeometry,
    WUXMILineGeometryStatics, WUXMILineSegment, WUXMILineSegmentStatics, WUXMIMatrix3DProjection, WUXMIMatrix3DProjectionStatics,
    WUXMIPathGeometry, WUXMIPathGeometryStatics, WUXMIPlaneProjection, WUXMIPlaneProjectionStatics, WUXMIPolyBezierSegment,
    WUXMIPolyBezierSegmentStatics, WUXMIPolyLineSegment, WUXMIPolyLineSegmentStatics, WUXMIPolyQuadraticBezierSegment,
    WUXMIPolyQuadraticBezierSegmentStatics, WUXMIQuadraticBezierSegment, WUXMIQuadraticBezierSegmentStatics, WUXMIRectangleGeometry,
    WUXMIRectangleGeometryStatics, WUXMISolidColorBrush, WUXMISolidColorBrushStatics, WUXMISolidColorBrushFactory, WUXMITileBrush,
    WUXMITileBrushStatics, WUXMITileBrushFactory, WUXMITransform, WUXMITransformFactory, WUXMICompositeTransform,
    WUXMICompositeTransformStatics, WUXMIImageBrush, WUXMIImageBrushStatics, WUXMILinearGradientBrush, WUXMILinearGradientBrushStatics,
    WUXMILinearGradientBrushFactory, WUXMIMatrixTransform, WUXMIMatrixTransformStatics, WUXMIRotateTransform, WUXMIRotateTransformStatics,
    WUXMIScaleTransform, WUXMIScaleTransformStatics, WUXMISkewTransform, WUXMISkewTransformStatics, WUXMITransformGroup,
    WUXMITransformGroupStatics, WUXMITranslateTransform, WUXMITranslateTransformStatics;

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

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsUIXaml.h"
#include "WindowsUIXamlControlsPrimitives.h"
#include "WindowsUI.h"
#include "WindowsUIXamlMediaMedia3D.h"
#include "WindowsMediaPlayback.h"
#include "WindowsUICore.h"
// Windows.UI.Xaml.DependencyPropertyChangedCallback
#ifndef __WXDependencyPropertyChangedCallback__DEFINED
#define __WXDependencyPropertyChangedCallback__DEFINED
typedef void (^WXDependencyPropertyChangedCallback)(WXDependencyObject* sender, WXDependencyProperty* dp);
#endif // __WXDependencyPropertyChangedCallback__DEFINED

// Windows.UI.Xaml.ExceptionRoutedEventHandler
#ifndef __WXExceptionRoutedEventHandler__DEFINED
#define __WXExceptionRoutedEventHandler__DEFINED
typedef void (^WXExceptionRoutedEventHandler)(RTObject* sender, WXExceptionRoutedEventArgs* e);
#endif // __WXExceptionRoutedEventHandler__DEFINED

// Windows.UI.Xaml.RoutedEventHandler
#ifndef __WXRoutedEventHandler__DEFINED
#define __WXRoutedEventHandler__DEFINED
typedef void (^WXRoutedEventHandler)(RTObject* sender, WXRoutedEventArgs* e);
#endif // __WXRoutedEventHandler__DEFINED

#import <Foundation/Foundation.h>

// [struct] Windows.UI.Xaml.Media.Matrix
WINRT_EXPORT
@interface WUXMMatrix : NSObject
+ (instancetype) new;
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
typedef void (^WUXMRateChangedRoutedEventHandler)(RTObject* sender, WUXMRateChangedRoutedEventArgs* e);
#endif // __WUXMRateChangedRoutedEventHandler__DEFINED

// Windows.UI.Xaml.Media.TimelineMarkerRoutedEventHandler
#ifndef __WUXMTimelineMarkerRoutedEventHandler__DEFINED
#define __WUXMTimelineMarkerRoutedEventHandler__DEFINED
typedef void (^WUXMTimelineMarkerRoutedEventHandler)(RTObject* sender, WUXMTimelineMarkerRoutedEventArgs* e);
#endif // __WUXMTimelineMarkerRoutedEventHandler__DEFINED

// Windows.UI.Xaml.Media.IGeneralTransformOverrides
#ifndef __WUXMIGeneralTransformOverrides_DEFINED__
#define __WUXMIGeneralTransformOverrides_DEFINED__

@protocol WUXMIGeneralTransformOverrides
@property (readonly) WUXMGeneralTransform* inverseCore;
- (BOOL)tryTransformCore:(WFPoint*)inPoint outPoint:(WFPoint**)outPoint;
- (WFRect*)transformBoundsCore:(WFRect*)rect;
@end

#endif // __WUXMIGeneralTransformOverrides_DEFINED__

// Windows.UI.Xaml.Media.VisualTreeHelper
#ifndef __WUXMVisualTreeHelper_DEFINED__
#define __WUXMVisualTreeHelper_DEFINED__

WINRT_EXPORT
@interface WUXMVisualTreeHelper : RTObject
+ (id<NSFastEnumeration>)findElementsInHostCoordinatesPoint:(WFPoint*)intersectingPoint subtree:(WXUIElement*)subtree;
+ (id<NSFastEnumeration>)findElementsInHostCoordinatesRect:(WFRect*)intersectingRect subtree:(WXUIElement*)subtree;
+ (id<NSFastEnumeration>)findAllElementsInHostCoordinatesPoint:(WFPoint*)intersectingPoint
                                                       subtree:(WXUIElement*)subtree
                                            includeAllElements:(BOOL)includeAllElements;
+ (id<NSFastEnumeration>)findAllElementsInHostCoordinatesRect:(WFRect*)intersectingRect
                                                      subtree:(WXUIElement*)subtree
                                           includeAllElements:(BOOL)includeAllElements;
+ (WXDependencyObject*)getChild:(WXDependencyObject*)reference childIndex:(int)childIndex;
+ (int)getChildrenCount:(WXDependencyObject*)reference;
+ (WXDependencyObject*)getParent:(WXDependencyObject*)reference;
+ (void)disconnectChildrenRecursive:(WXUIElement*)element;
+ (NSArray*)getOpenPopups:(WXWindow*)window;
@end

#endif // __WUXMVisualTreeHelper_DEFINED__

// Windows.UI.Xaml.Media.PartialMediaFailureDetectedEventArgs
#ifndef __WUXMPartialMediaFailureDetectedEventArgs_DEFINED__
#define __WUXMPartialMediaFailureDetectedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXMPartialMediaFailureDetectedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WMPFailedMediaStreamKind streamKind;
@end

#endif // __WUXMPartialMediaFailureDetectedEventArgs_DEFINED__

// Windows.UI.Xaml.Media.MatrixHelper
#ifndef __WUXMMatrixHelper_DEFINED__
#define __WUXMMatrixHelper_DEFINED__

WINRT_EXPORT
@interface WUXMMatrixHelper : RTObject
+ (WUXMMatrix*)fromElements:(double)m11 m12:(double)m12 m21:(double)m21 m22:(double)m22 offsetX:(double)offsetX offsetY:(double)offsetY;
+ (BOOL)getIsIdentity:(WUXMMatrix*)target;
+ (WFPoint*)transform:(WUXMMatrix*)target point:(WFPoint*)point;
+ (WUXMMatrix*)identity;
@end

#endif // __WUXMMatrixHelper_DEFINED__

// Windows.UI.Xaml.Media.CompositionTarget
#ifndef __WUXMCompositionTarget_DEFINED__
#define __WUXMCompositionTarget_DEFINED__

WINRT_EXPORT
@interface WUXMCompositionTarget : RTObject
+ (EventRegistrationToken)addRenderingEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeRenderingEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addSurfaceContentsLostEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeSurfaceContentsLostEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXMCompositionTarget_DEFINED__

// Windows.UI.Xaml.Media.DoubleCollection
#ifndef __WUXMDoubleCollection_DEFINED__
#define __WUXMDoubleCollection_DEFINED__

WINRT_EXPORT
@interface WUXMDoubleCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

- (void)insertObject:(id)obj atIndex:(NSUInteger)idx;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)obj;
- (void)addObject:(id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMDoubleCollection_DEFINED__

// Windows.UI.Xaml.Media.FontFamily
#ifndef __WUXMFontFamily_DEFINED__
#define __WUXMFontFamily_DEFINED__

WINRT_EXPORT
@interface WUXMFontFamily : RTObject
@property (readonly) NSString* source;
@end

#endif // __WUXMFontFamily_DEFINED__

// Windows.UI.Xaml.Media.GeometryCollection
#ifndef __WUXMGeometryCollection_DEFINED__
#define __WUXMGeometryCollection_DEFINED__

WINRT_EXPORT
@interface WUXMGeometryCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

- (void)insertObject:(id)obj atIndex:(NSUInteger)idx;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)obj;
- (void)addObject:(id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMGeometryCollection_DEFINED__

// Windows.UI.Xaml.Media.GradientStopCollection
#ifndef __WUXMGradientStopCollection_DEFINED__
#define __WUXMGradientStopCollection_DEFINED__

WINRT_EXPORT
@interface WUXMGradientStopCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

- (void)insertObject:(id)obj atIndex:(NSUInteger)idx;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)obj;
- (void)addObject:(id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMGradientStopCollection_DEFINED__

// Windows.UI.Xaml.Media.PathFigureCollection
#ifndef __WUXMPathFigureCollection_DEFINED__
#define __WUXMPathFigureCollection_DEFINED__

WINRT_EXPORT
@interface WUXMPathFigureCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

- (void)insertObject:(id)obj atIndex:(NSUInteger)idx;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)obj;
- (void)addObject:(id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMPathFigureCollection_DEFINED__

// Windows.UI.Xaml.Media.PathSegmentCollection
#ifndef __WUXMPathSegmentCollection_DEFINED__
#define __WUXMPathSegmentCollection_DEFINED__

WINRT_EXPORT
@interface WUXMPathSegmentCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

- (void)insertObject:(id)obj atIndex:(NSUInteger)idx;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)obj;
- (void)addObject:(id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMPathSegmentCollection_DEFINED__

// Windows.UI.Xaml.Media.PointCollection
#ifndef __WUXMPointCollection_DEFINED__
#define __WUXMPointCollection_DEFINED__

WINRT_EXPORT
@interface WUXMPointCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

- (void)insertObject:(id)obj atIndex:(NSUInteger)idx;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)obj;
- (void)addObject:(id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMPointCollection_DEFINED__

// Windows.UI.Xaml.Media.RenderingEventArgs
#ifndef __WUXMRenderingEventArgs_DEFINED__
#define __WUXMRenderingEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXMRenderingEventArgs : RTObject
@property (readonly) WFTimeSpan* renderingTime;
@end

#endif // __WUXMRenderingEventArgs_DEFINED__

// Windows.UI.Xaml.Media.TimelineMarkerCollection
#ifndef __WUXMTimelineMarkerCollection_DEFINED__
#define __WUXMTimelineMarkerCollection_DEFINED__

WINRT_EXPORT
@interface WUXMTimelineMarkerCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

- (void)insertObject:(id)obj atIndex:(NSUInteger)idx;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)obj;
- (void)addObject:(id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMTimelineMarkerCollection_DEFINED__

// Windows.UI.Xaml.Media.TransformCollection
#ifndef __WUXMTransformCollection_DEFINED__
#define __WUXMTransformCollection_DEFINED__

WINRT_EXPORT
@interface WUXMTransformCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

- (void)insertObject:(id)obj atIndex:(NSUInteger)idx;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)obj;
- (void)addObject:(id)obj;
- (void)removeLastObject;

@end

#endif // __WUXMTransformCollection_DEFINED__

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

// Windows.UI.Xaml.Media.Brush
#ifndef __WUXMBrush_DEFINED__
#define __WUXMBrush_DEFINED__

WINRT_EXPORT
@interface WUXMBrush : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMTransform* transform;
@property (copy) WUXMTransform* relativeTransform;
@property double opacity;
+ (WXDependencyProperty*)opacityProperty;
+ (WXDependencyProperty*)relativeTransformProperty;
+ (WXDependencyProperty*)transformProperty;
@end

#endif // __WUXMBrush_DEFINED__

// Windows.UI.Xaml.Media.CacheMode
#ifndef __WUXMCacheMode_DEFINED__
#define __WUXMCacheMode_DEFINED__

WINRT_EXPORT
@interface WUXMCacheMode : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMCacheMode_DEFINED__

// Windows.UI.Xaml.Media.GeneralTransform
#ifndef __WUXMGeneralTransform_DEFINED__
#define __WUXMGeneralTransform_DEFINED__

WINRT_EXPORT
@interface WUXMGeneralTransform : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WUXMGeneralTransform* inverse;
@property (readonly) WUXMGeneralTransform* inverseCore;
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

WINRT_EXPORT
@interface WUXMGeometry : WXDependencyObject
@property (copy) WUXMTransform* transform;
@property (readonly) WFRect* bounds;
+ (WUXMGeometry*)empty;
+ (double)standardFlatteningTolerance;
+ (WXDependencyProperty*)transformProperty;
@end

#endif // __WUXMGeometry_DEFINED__

// Windows.UI.Xaml.Media.GradientStop
#ifndef __WUXMGradientStop_DEFINED__
#define __WUXMGradientStop_DEFINED__

WINRT_EXPORT
@interface WUXMGradientStop : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property double offset;
@property (copy) WUColor* color;
+ (WXDependencyProperty*)colorProperty;
+ (WXDependencyProperty*)offsetProperty;
@end

#endif // __WUXMGradientStop_DEFINED__

// Windows.UI.Xaml.Media.ImageSource
#ifndef __WUXMImageSource_DEFINED__
#define __WUXMImageSource_DEFINED__

WINRT_EXPORT
@interface WUXMImageSource : WXDependencyObject
@end

#endif // __WUXMImageSource_DEFINED__

// Windows.UI.Xaml.Media.PathFigure
#ifndef __WUXMPathFigure_DEFINED__
#define __WUXMPathFigure_DEFINED__

WINRT_EXPORT
@interface WUXMPathFigure : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (copy) WFPoint* startPoint;
@property (copy) WUXMPathSegmentCollection* segments;
@property BOOL isFilled;
@property BOOL isClosed;
+ (WXDependencyProperty*)isClosedProperty;
+ (WXDependencyProperty*)isFilledProperty;
+ (WXDependencyProperty*)segmentsProperty;
+ (WXDependencyProperty*)startPointProperty;
@end

#endif // __WUXMPathFigure_DEFINED__

// Windows.UI.Xaml.Media.PathSegment
#ifndef __WUXMPathSegment_DEFINED__
#define __WUXMPathSegment_DEFINED__

WINRT_EXPORT
@interface WUXMPathSegment : WXDependencyObject
@end

#endif // __WUXMPathSegment_DEFINED__

// Windows.UI.Xaml.Media.Projection
#ifndef __WUXMProjection_DEFINED__
#define __WUXMProjection_DEFINED__

WINRT_EXPORT
@interface WUXMProjection : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMProjection_DEFINED__

// Windows.UI.Xaml.RoutedEventArgs
#ifndef __WXRoutedEventArgs_DEFINED__
#define __WXRoutedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXRoutedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) RTObject* originalSource;
@end

#endif // __WXRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Media.RateChangedRoutedEventArgs
#ifndef __WUXMRateChangedRoutedEventArgs_DEFINED__
#define __WUXMRateChangedRoutedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXMRateChangedRoutedEventArgs : WXRoutedEventArgs
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMRateChangedRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Media.TimelineMarker
#ifndef __WUXMTimelineMarker_DEFINED__
#define __WUXMTimelineMarker_DEFINED__

WINRT_EXPORT
@interface WUXMTimelineMarker : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* type;
@property (copy) WFTimeSpan* time;
@property (copy) NSString* text;
+ (WXDependencyProperty*)textProperty;
+ (WXDependencyProperty*)timeProperty;
+ (WXDependencyProperty*)typeProperty;
@end

#endif // __WUXMTimelineMarker_DEFINED__

// Windows.UI.Xaml.Media.TimelineMarkerRoutedEventArgs
#ifndef __WUXMTimelineMarkerRoutedEventArgs_DEFINED__
#define __WUXMTimelineMarkerRoutedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXMTimelineMarkerRoutedEventArgs : WXRoutedEventArgs
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMTimelineMarker* marker;
@end

#endif // __WUXMTimelineMarkerRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Media.ArcSegment
#ifndef __WUXMArcSegment_DEFINED__
#define __WUXMArcSegment_DEFINED__

WINRT_EXPORT
@interface WUXMArcSegment : WUXMPathSegment
+ (instancetype)create ACTIVATOR;
@property WUXMSweepDirection sweepDirection;
@property (copy) WFSize* size;
@property double rotationAngle;
@property (copy) WFPoint* point;
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

WINRT_EXPORT
@interface WUXMBezierSegment : WUXMPathSegment
+ (instancetype)create ACTIVATOR;
@property (copy) WFPoint* point3;
@property (copy) WFPoint* point2;
@property (copy) WFPoint* point1;
+ (WXDependencyProperty*)point1Property;
+ (WXDependencyProperty*)point2Property;
+ (WXDependencyProperty*)point3Property;
@end

#endif // __WUXMBezierSegment_DEFINED__

// Windows.UI.Xaml.Media.BitmapCache
#ifndef __WUXMBitmapCache_DEFINED__
#define __WUXMBitmapCache_DEFINED__

WINRT_EXPORT
@interface WUXMBitmapCache : WUXMCacheMode
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMBitmapCache_DEFINED__

// Windows.UI.Xaml.Media.EllipseGeometry
#ifndef __WUXMEllipseGeometry_DEFINED__
#define __WUXMEllipseGeometry_DEFINED__

WINRT_EXPORT
@interface WUXMEllipseGeometry : WUXMGeometry
+ (instancetype)create ACTIVATOR;
@property double radiusY;
@property double radiusX;
@property (copy) WFPoint* center;
+ (WXDependencyProperty*)centerProperty;
+ (WXDependencyProperty*)radiusXProperty;
+ (WXDependencyProperty*)radiusYProperty;
@end

#endif // __WUXMEllipseGeometry_DEFINED__

// Windows.UI.Xaml.Media.GeometryGroup
#ifndef __WUXMGeometryGroup_DEFINED__
#define __WUXMGeometryGroup_DEFINED__

WINRT_EXPORT
@interface WUXMGeometryGroup : WUXMGeometry
+ (instancetype)create ACTIVATOR;
@property WUXMFillRule fillRule;
@property (copy) WUXMGeometryCollection* children;
+ (WXDependencyProperty*)childrenProperty;
+ (WXDependencyProperty*)fillRuleProperty;
@end

#endif // __WUXMGeometryGroup_DEFINED__

// Windows.UI.Xaml.Media.GradientBrush
#ifndef __WUXMGradientBrush_DEFINED__
#define __WUXMGradientBrush_DEFINED__

WINRT_EXPORT
@interface WUXMGradientBrush : WUXMBrush
+ (instancetype)create ACTIVATOR;
@property WUXMGradientSpreadMethod spreadMethod;
@property WUXMBrushMappingMode mappingMode;
@property (copy) WUXMGradientStopCollection* gradientStops;
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

WINRT_EXPORT
@interface WUXMLineGeometry : WUXMGeometry
+ (instancetype)create ACTIVATOR;
@property (copy) WFPoint* startPoint;
@property (copy) WFPoint* endPoint;
+ (WXDependencyProperty*)endPointProperty;
+ (WXDependencyProperty*)startPointProperty;
@end

#endif // __WUXMLineGeometry_DEFINED__

// Windows.UI.Xaml.Media.LineSegment
#ifndef __WUXMLineSegment_DEFINED__
#define __WUXMLineSegment_DEFINED__

WINRT_EXPORT
@interface WUXMLineSegment : WUXMPathSegment
+ (instancetype)create ACTIVATOR;
@property (copy) WFPoint* point;
+ (WXDependencyProperty*)pointProperty;
@end

#endif // __WUXMLineSegment_DEFINED__

// Windows.UI.Xaml.Media.Matrix3DProjection
#ifndef __WUXMMatrix3DProjection_DEFINED__
#define __WUXMMatrix3DProjection_DEFINED__

WINRT_EXPORT
@interface WUXMMatrix3DProjection : WUXMProjection
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMMMatrix3D* projectionMatrix;
+ (WXDependencyProperty*)projectionMatrixProperty;
@end

#endif // __WUXMMatrix3DProjection_DEFINED__

// Windows.UI.Xaml.Media.PathGeometry
#ifndef __WUXMPathGeometry_DEFINED__
#define __WUXMPathGeometry_DEFINED__

WINRT_EXPORT
@interface WUXMPathGeometry : WUXMGeometry
+ (instancetype)create ACTIVATOR;
@property WUXMFillRule fillRule;
@property (copy) WUXMPathFigureCollection* figures;
+ (WXDependencyProperty*)figuresProperty;
+ (WXDependencyProperty*)fillRuleProperty;
@end

#endif // __WUXMPathGeometry_DEFINED__

// Windows.UI.Xaml.Media.PlaneProjection
#ifndef __WUXMPlaneProjection_DEFINED__
#define __WUXMPlaneProjection_DEFINED__

WINRT_EXPORT
@interface WUXMPlaneProjection : WUXMProjection
+ (instancetype)create ACTIVATOR;
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

// Windows.UI.Xaml.Media.PolyBezierSegment
#ifndef __WUXMPolyBezierSegment_DEFINED__
#define __WUXMPolyBezierSegment_DEFINED__

WINRT_EXPORT
@interface WUXMPolyBezierSegment : WUXMPathSegment
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMPointCollection* points;
+ (WXDependencyProperty*)pointsProperty;
@end

#endif // __WUXMPolyBezierSegment_DEFINED__

// Windows.UI.Xaml.Media.PolyLineSegment
#ifndef __WUXMPolyLineSegment_DEFINED__
#define __WUXMPolyLineSegment_DEFINED__

WINRT_EXPORT
@interface WUXMPolyLineSegment : WUXMPathSegment
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMPointCollection* points;
+ (WXDependencyProperty*)pointsProperty;
@end

#endif // __WUXMPolyLineSegment_DEFINED__

// Windows.UI.Xaml.Media.PolyQuadraticBezierSegment
#ifndef __WUXMPolyQuadraticBezierSegment_DEFINED__
#define __WUXMPolyQuadraticBezierSegment_DEFINED__

WINRT_EXPORT
@interface WUXMPolyQuadraticBezierSegment : WUXMPathSegment
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMPointCollection* points;
+ (WXDependencyProperty*)pointsProperty;
@end

#endif // __WUXMPolyQuadraticBezierSegment_DEFINED__

// Windows.UI.Xaml.Media.QuadraticBezierSegment
#ifndef __WUXMQuadraticBezierSegment_DEFINED__
#define __WUXMQuadraticBezierSegment_DEFINED__

WINRT_EXPORT
@interface WUXMQuadraticBezierSegment : WUXMPathSegment
+ (instancetype)create ACTIVATOR;
@property (copy) WFPoint* point2;
@property (copy) WFPoint* point1;
+ (WXDependencyProperty*)point1Property;
+ (WXDependencyProperty*)point2Property;
@end

#endif // __WUXMQuadraticBezierSegment_DEFINED__

// Windows.UI.Xaml.Media.RectangleGeometry
#ifndef __WUXMRectangleGeometry_DEFINED__
#define __WUXMRectangleGeometry_DEFINED__

WINRT_EXPORT
@interface WUXMRectangleGeometry : WUXMGeometry
+ (instancetype)create ACTIVATOR;
@property (copy) WFRect* rect;
+ (WXDependencyProperty*)rectProperty;
@end

#endif // __WUXMRectangleGeometry_DEFINED__

// Windows.UI.Xaml.Media.SolidColorBrush
#ifndef __WUXMSolidColorBrush_DEFINED__
#define __WUXMSolidColorBrush_DEFINED__

WINRT_EXPORT
@interface WUXMSolidColorBrush : WUXMBrush
+ (WUXMSolidColorBrush*)createInstanceWithColor:(WUColor*)color ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (copy) WUColor* color;
+ (WXDependencyProperty*)colorProperty;
@end

#endif // __WUXMSolidColorBrush_DEFINED__

// Windows.UI.Xaml.Media.TileBrush
#ifndef __WUXMTileBrush_DEFINED__
#define __WUXMTileBrush_DEFINED__

WINRT_EXPORT
@interface WUXMTileBrush : WUXMBrush
+ (instancetype)create ACTIVATOR;
@property WUXMStretch stretch;
@property WUXMAlignmentY alignmentY;
@property WUXMAlignmentX alignmentX;
+ (WXDependencyProperty*)alignmentXProperty;
+ (WXDependencyProperty*)alignmentYProperty;
+ (WXDependencyProperty*)stretchProperty;
@end

#endif // __WUXMTileBrush_DEFINED__

// Windows.UI.Xaml.Media.Transform
#ifndef __WUXMTransform_DEFINED__
#define __WUXMTransform_DEFINED__

WINRT_EXPORT
@interface WUXMTransform : WUXMGeneralTransform
@end

#endif // __WUXMTransform_DEFINED__

// Windows.UI.Xaml.Media.CompositeTransform
#ifndef __WUXMCompositeTransform_DEFINED__
#define __WUXMCompositeTransform_DEFINED__

WINRT_EXPORT
@interface WUXMCompositeTransform : WUXMTransform
+ (instancetype)create ACTIVATOR;
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

// Windows.UI.Xaml.Media.ImageBrush
#ifndef __WUXMImageBrush_DEFINED__
#define __WUXMImageBrush_DEFINED__

WINRT_EXPORT
@interface WUXMImageBrush : WUXMTileBrush
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMImageSource* imageSource;
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

WINRT_EXPORT
@interface WUXMLinearGradientBrush : WUXMGradientBrush
+ (instancetype)create ACTIVATOR;
+ (WUXMLinearGradientBrush*)createInstanceWithGradientStopCollectionAndAngle:(WUXMGradientStopCollection*)gradientStopCollection
                                                                       angle:(double)angle ACTIVATOR;
@property (copy) WFPoint* startPoint;
@property (copy) WFPoint* endPoint;
+ (WXDependencyProperty*)endPointProperty;
+ (WXDependencyProperty*)startPointProperty;
@end

#endif // __WUXMLinearGradientBrush_DEFINED__

// Windows.UI.Xaml.Media.MatrixTransform
#ifndef __WUXMMatrixTransform_DEFINED__
#define __WUXMMatrixTransform_DEFINED__

WINRT_EXPORT
@interface WUXMMatrixTransform : WUXMTransform
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMMatrix* matrix;
+ (WXDependencyProperty*)matrixProperty;
@end

#endif // __WUXMMatrixTransform_DEFINED__

// Windows.UI.Xaml.Media.RotateTransform
#ifndef __WUXMRotateTransform_DEFINED__
#define __WUXMRotateTransform_DEFINED__

WINRT_EXPORT
@interface WUXMRotateTransform : WUXMTransform
+ (instancetype)create ACTIVATOR;
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

WINRT_EXPORT
@interface WUXMScaleTransform : WUXMTransform
+ (instancetype)create ACTIVATOR;
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

WINRT_EXPORT
@interface WUXMSkewTransform : WUXMTransform
+ (instancetype)create ACTIVATOR;
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

WINRT_EXPORT
@interface WUXMTransformGroup : WUXMTransform
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMTransformCollection* children;
@property (readonly) WUXMMatrix* value;
+ (WXDependencyProperty*)childrenProperty;
@end

#endif // __WUXMTransformGroup_DEFINED__

// Windows.UI.Xaml.Media.TranslateTransform
#ifndef __WUXMTranslateTransform_DEFINED__
#define __WUXMTranslateTransform_DEFINED__

WINRT_EXPORT
@interface WUXMTranslateTransform : WUXMTransform
+ (instancetype)create ACTIVATOR;
@property double y;
@property double x;
+ (WXDependencyProperty*)xProperty;
+ (WXDependencyProperty*)yProperty;
@end

#endif // __WUXMTranslateTransform_DEFINED__
