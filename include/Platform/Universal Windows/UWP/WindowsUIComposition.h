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

// WindowsUIComposition.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUICOMPOSITIONEXPORT
#define OBJCUWPWINDOWSUICOMPOSITIONEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIComposition.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUCCompositionObject, WUCCompositionAnimation, WUCCompositionBatchCompletedEventArgs, WUCCompositionEasingFunction, WUCCompositionBrush, WUCCompositionEffectBrush, WUCCompositionEffectSourceParameter, WUCCompositionGraphicsDevice, WUCCompositor, WUCCompositionPropertySet, WUCCompositionDrawingSurface, WUCCompositionColorBrush, WUCCompositionEffectFactory, WUCCompositionScopedBatch, WUCCompositionSurfaceBrush, WUCCompositionTarget, WUCCompositionCommitBatch, WUCCompositionAnimationGroup, WUCCompositionBackdropBrush, WUCCompositionMaskBrush, WUCCompositionNineGridBrush, WUCCubicBezierEasingFunction, WUCExpressionAnimation, WUCImplicitAnimationCollection, WUCLinearEasingFunction, WUCRenderingDeviceReplacedEventArgs, WUCCompositionShadow, WUCDropShadow, WUCStepEasingFunction, WUCVisual, WUCContainerVisual, WUCSpriteVisual, WUCLayerVisual, WUCCompositionClip, WUCInsetClip, WUCVisualCollection, WUCVisualUnorderedCollection, WUCCompositionLight, WUCAmbientLight, WUCDistantLight, WUCPointLight, WUCSpotLight, WUCKeyFrameAnimation, WUCColorKeyFrameAnimation, WUCQuaternionKeyFrameAnimation, WUCScalarKeyFrameAnimation, WUCVector2KeyFrameAnimation, WUCVector3KeyFrameAnimation, WUCVector4KeyFrameAnimation;
@protocol WUCIAmbientLight, WUCIColorKeyFrameAnimation, WUCICompositionAnimation, WUCICompositionAnimation2, WUCICompositionAnimationBase, WUCICompositionAnimationGroup, WUCICompositionBackdropBrush, WUCICompositionBatchCompletedEventArgs, WUCICompositionBrush, WUCICompositionClip, WUCICompositionClip2, WUCICompositionColorBrush, WUCICompositionCommitBatch, WUCICompositionDrawingSurface, WUCICompositionEasingFunction, WUCICompositionEffectBrush, WUCICompositionEffectFactory, WUCICompositionEffectSourceParameter, WUCICompositionEffectSourceParameterFactory, WUCICompositionGraphicsDevice, WUCICompositionLight, WUCICompositionMaskBrush, WUCICompositionNineGridBrush, WUCICompositionObject, WUCICompositionObject2, WUCICompositionPropertySet, WUCICompositionPropertySet2, WUCICompositionScopedBatch, WUCICompositionShadow, WUCICompositionSurface, WUCICompositionSurfaceBrush, WUCICompositionSurfaceBrush2, WUCICompositionTarget, WUCICompositor, WUCICompositor2, WUCIContainerVisual, WUCICubicBezierEasingFunction, WUCIDistantLight, WUCIDropShadow, WUCIExpressionAnimation, WUCIImplicitAnimationCollection, WUCIInsetClip, WUCIKeyFrameAnimation, WUCIKeyFrameAnimation2, WUCILayerVisual, WUCILinearEasingFunction, WUCIPointLight, WUCIQuaternionKeyFrameAnimation, WUCIRenderingDeviceReplacedEventArgs, WUCIScalarKeyFrameAnimation, WUCISpotLight, WUCISpriteVisual, WUCISpriteVisual2, WUCIStepEasingFunction, WUCIVector2KeyFrameAnimation, WUCIVector3KeyFrameAnimation, WUCIVector4KeyFrameAnimation, WUCIVisual, WUCIVisualCollection, WUCIVisualUnorderedCollection, WUCICompositionAnimationFactory, WUCICompositionBrushFactory, WUCICompositionClipFactory, WUCICompositionEasingFunctionFactory, WUCICompositionLightFactory, WUCICompositionObjectFactory, WUCICompositionShadowFactory, WUCIContainerVisualFactory, WUCIKeyFrameAnimationFactory, WUCIVisualFactory;

// Windows.UI.Composition.AnimationDirection
enum _WUCAnimationDirection {
    WUCAnimationDirectionNormal = 0,
    WUCAnimationDirectionReverse = 1,
    WUCAnimationDirectionAlternate = 2,
    WUCAnimationDirectionAlternateReverse = 3,
};
typedef unsigned WUCAnimationDirection;

// Windows.UI.Composition.AnimationIterationBehavior
enum _WUCAnimationIterationBehavior {
    WUCAnimationIterationBehaviorCount = 0,
    WUCAnimationIterationBehaviorForever = 1,
};
typedef unsigned WUCAnimationIterationBehavior;

// Windows.UI.Composition.AnimationStopBehavior
enum _WUCAnimationStopBehavior {
    WUCAnimationStopBehaviorLeaveCurrentValue = 0,
    WUCAnimationStopBehaviorSetToInitialValue = 1,
    WUCAnimationStopBehaviorSetToFinalValue = 2,
};
typedef unsigned WUCAnimationStopBehavior;

// Windows.UI.Composition.CompositionBatchTypes
enum _WUCCompositionBatchTypes {
    WUCCompositionBatchTypesNone = 0,
    WUCCompositionBatchTypesAnimation = 1,
    WUCCompositionBatchTypesEffect = 2,
};
typedef unsigned WUCCompositionBatchTypes;

// Windows.UI.Composition.CompositionBackfaceVisibility
enum _WUCCompositionBackfaceVisibility {
    WUCCompositionBackfaceVisibilityInherit = 0,
    WUCCompositionBackfaceVisibilityVisible = 1,
    WUCCompositionBackfaceVisibilityHidden = 2,
};
typedef unsigned WUCCompositionBackfaceVisibility;

// Windows.UI.Composition.CompositionBitmapInterpolationMode
enum _WUCCompositionBitmapInterpolationMode {
    WUCCompositionBitmapInterpolationModeNearestNeighbor = 0,
    WUCCompositionBitmapInterpolationModeLinear = 1,
};
typedef unsigned WUCCompositionBitmapInterpolationMode;

// Windows.UI.Composition.CompositionBorderMode
enum _WUCCompositionBorderMode {
    WUCCompositionBorderModeInherit = 0,
    WUCCompositionBorderModeSoft = 1,
    WUCCompositionBorderModeHard = 2,
};
typedef unsigned WUCCompositionBorderMode;

// Windows.UI.Composition.CompositionColorSpace
enum _WUCCompositionColorSpace {
    WUCCompositionColorSpaceAuto = 0,
    WUCCompositionColorSpaceHsl = 1,
    WUCCompositionColorSpaceRgb = 2,
};
typedef unsigned WUCCompositionColorSpace;

// Windows.UI.Composition.CompositionCompositeMode
enum _WUCCompositionCompositeMode {
    WUCCompositionCompositeModeInherit = 0,
    WUCCompositionCompositeModeSourceOver = 1,
    WUCCompositionCompositeModeDestinationInvert = 2,
    WUCCompositionCompositeModeMinBlend = 3,
};
typedef unsigned WUCCompositionCompositeMode;

// Windows.UI.Composition.CompositionEffectFactoryLoadStatus
enum _WUCCompositionEffectFactoryLoadStatus {
    WUCCompositionEffectFactoryLoadStatusSuccess = 0,
    WUCCompositionEffectFactoryLoadStatusEffectTooComplex = 1,
    WUCCompositionEffectFactoryLoadStatusPending = 2,
    WUCCompositionEffectFactoryLoadStatusOther = -1,
};
typedef unsigned WUCCompositionEffectFactoryLoadStatus;

// Windows.UI.Composition.CompositionGetValueStatus
enum _WUCCompositionGetValueStatus {
    WUCCompositionGetValueStatusSucceeded = 0,
    WUCCompositionGetValueStatusTypeMismatch = 1,
    WUCCompositionGetValueStatusNotFound = 2,
};
typedef unsigned WUCCompositionGetValueStatus;

// Windows.UI.Composition.CompositionStretch
enum _WUCCompositionStretch {
    WUCCompositionStretchNone = 0,
    WUCCompositionStretchFill = 1,
    WUCCompositionStretchUniform = 2,
    WUCCompositionStretchUniformToFill = 3,
};
typedef unsigned WUCCompositionStretch;

#include "WindowsUI.h"
#include "WindowsFoundationNumerics.h"
#include "WindowsFoundation.h"
#include "WindowsGraphicsDirectX.h"
#include "WindowsGraphicsEffects.h"
#include "WindowsUICore.h"

#import <Foundation/Foundation.h>

// Windows.UI.Composition.ICompositionAnimationBase
#ifndef __WUCICompositionAnimationBase_DEFINED__
#define __WUCICompositionAnimationBase_DEFINED__

@protocol WUCICompositionAnimationBase
@end

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCICompositionAnimationBase : RTObject <WUCICompositionAnimationBase>
@end

#endif // __WUCICompositionAnimationBase_DEFINED__

// Windows.UI.Composition.ICompositionSurface
#ifndef __WUCICompositionSurface_DEFINED__
#define __WUCICompositionSurface_DEFINED__

@protocol WUCICompositionSurface
@end

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCICompositionSurface : RTObject <WUCICompositionSurface>
@end

#endif // __WUCICompositionSurface_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.UI.Composition.CompositionObject
#ifndef __WUCCompositionObject_DEFINED__
#define __WUCCompositionObject_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionObject : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUCCompositor* compositor;
@property (readonly) WUCCoreDispatcher* dispatcher;
@property (readonly) WUCCompositionPropertySet* properties;
@property (retain) WUCImplicitAnimationCollection* implicitAnimations;
@property (retain) NSString * comment;
- (void)startAnimation:(NSString *)propertyName animation:(WUCCompositionAnimation*)animation;
- (void)stopAnimation:(NSString *)propertyName;
- (void)close;
- (void)startAnimationGroup:(RTObject<WUCICompositionAnimationBase>*)value;
- (void)stopAnimationGroup:(RTObject<WUCICompositionAnimationBase>*)value;
@end

#endif // __WUCCompositionObject_DEFINED__

// Windows.UI.Composition.CompositionAnimation
#ifndef __WUCCompositionAnimation_DEFINED__
#define __WUCCompositionAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionAnimation : WUCCompositionObject <WUCICompositionAnimationBase>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * target;
- (void)clearAllParameters;
- (void)clearParameter:(NSString *)key;
- (void)setColorParameter:(NSString *)key value:(WUColor*)value;
- (void)setMatrix3x2Parameter:(NSString *)key value:(WFNMatrix3x2*)value;
- (void)setMatrix4x4Parameter:(NSString *)key value:(WFNMatrix4x4*)value;
- (void)setQuaternionParameter:(NSString *)key value:(WFNQuaternion*)value;
- (void)setReferenceParameter:(NSString *)key compositionObject:(WUCCompositionObject*)compositionObject;
- (void)setScalarParameter:(NSString *)key value:(float)value;
- (void)setVector2Parameter:(NSString *)key value:(WFNVector2*)value;
- (void)setVector3Parameter:(NSString *)key value:(WFNVector3*)value;
- (void)setVector4Parameter:(NSString *)key value:(WFNVector4*)value;
- (void)setBooleanParameter:(NSString *)key value:(BOOL)value;
@end

#endif // __WUCCompositionAnimation_DEFINED__

// Windows.UI.Composition.CompositionBatchCompletedEventArgs
#ifndef __WUCCompositionBatchCompletedEventArgs_DEFINED__
#define __WUCCompositionBatchCompletedEventArgs_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionBatchCompletedEventArgs : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUCCompositionBatchCompletedEventArgs_DEFINED__

// Windows.UI.Composition.CompositionEasingFunction
#ifndef __WUCCompositionEasingFunction_DEFINED__
#define __WUCCompositionEasingFunction_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionEasingFunction : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUCCompositionEasingFunction_DEFINED__

// Windows.UI.Composition.CompositionBrush
#ifndef __WUCCompositionBrush_DEFINED__
#define __WUCCompositionBrush_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionBrush : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUCCompositionBrush_DEFINED__

// Windows.UI.Composition.CompositionEffectBrush
#ifndef __WUCCompositionEffectBrush_DEFINED__
#define __WUCCompositionEffectBrush_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionEffectBrush : WUCCompositionBrush
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WUCCompositionBrush*)getSourceParameter:(NSString *)name;
- (void)setSourceParameter:(NSString *)name source:(WUCCompositionBrush*)source;
@end

#endif // __WUCCompositionEffectBrush_DEFINED__

// Windows.Graphics.Effects.IGraphicsEffectSource
#ifndef __WGEIGraphicsEffectSource_DEFINED__
#define __WGEIGraphicsEffectSource_DEFINED__

@protocol WGEIGraphicsEffectSource
@end

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WGEIGraphicsEffectSource : RTObject <WGEIGraphicsEffectSource>
@end

#endif // __WGEIGraphicsEffectSource_DEFINED__

// Windows.UI.Composition.CompositionEffectSourceParameter
#ifndef __WUCCompositionEffectSourceParameter_DEFINED__
#define __WUCCompositionEffectSourceParameter_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionEffectSourceParameter : RTObject <WGEIGraphicsEffectSource>
+ (WUCCompositionEffectSourceParameter*)make:(NSString *)name ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * name;
@end

#endif // __WUCCompositionEffectSourceParameter_DEFINED__

// Windows.UI.Composition.CompositionGraphicsDevice
#ifndef __WUCCompositionGraphicsDevice_DEFINED__
#define __WUCCompositionGraphicsDevice_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionGraphicsDevice : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addRenderingDeviceReplacedEvent:(void(^)(WUCCompositionGraphicsDevice*, WUCRenderingDeviceReplacedEventArgs*))del;
- (void)removeRenderingDeviceReplacedEvent:(EventRegistrationToken)tok;
- (WUCCompositionDrawingSurface*)createDrawingSurface:(WFSize*)sizePixels pixelFormat:(WGDDirectXPixelFormat)pixelFormat alphaMode:(WGDDirectXAlphaMode)alphaMode;
@end

#endif // __WUCCompositionGraphicsDevice_DEFINED__

// Windows.UI.Composition.Compositor
#ifndef __WUCCompositor_DEFINED__
#define __WUCCompositor_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositor : RTObject <WFIClosable>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WUCColorKeyFrameAnimation*)createColorKeyFrameAnimation;
- (WUCCompositionColorBrush*)createColorBrush;
- (WUCCompositionColorBrush*)createColorBrushWithColor:(WUColor*)color;
- (WUCContainerVisual*)createContainerVisual;
- (WUCCubicBezierEasingFunction*)createCubicBezierEasingFunction:(WFNVector2*)controlPoint1 controlPoint2:(WFNVector2*)controlPoint2;
- (WUCCompositionEffectFactory*)createEffectFactory:(RTObject<WGEIGraphicsEffect>*)graphicsEffect;
- (WUCCompositionEffectFactory*)createEffectFactoryWithProperties:(RTObject<WGEIGraphicsEffect>*)graphicsEffect animatableProperties:(id<NSFastEnumeration> /* NSString * */)animatableProperties;
- (WUCExpressionAnimation*)createExpressionAnimation;
- (WUCExpressionAnimation*)createExpressionAnimationWithExpression:(NSString *)expression;
- (WUCInsetClip*)createInsetClip;
- (WUCInsetClip*)createInsetClipWithInsets:(float)leftInset topInset:(float)topInset rightInset:(float)rightInset bottomInset:(float)bottomInset;
- (WUCLinearEasingFunction*)createLinearEasingFunction;
- (WUCCompositionPropertySet*)createPropertySet;
- (WUCQuaternionKeyFrameAnimation*)createQuaternionKeyFrameAnimation;
- (WUCScalarKeyFrameAnimation*)createScalarKeyFrameAnimation;
- (WUCCompositionScopedBatch*)createScopedBatch:(WUCCompositionBatchTypes)batchType;
- (WUCSpriteVisual*)createSpriteVisual;
- (WUCCompositionSurfaceBrush*)createSurfaceBrush;
- (WUCCompositionSurfaceBrush*)createSurfaceBrushWithSurface:(RTObject<WUCICompositionSurface>*)surface;
- (WUCCompositionTarget*)createTargetForCurrentView;
- (WUCVector2KeyFrameAnimation*)createVector2KeyFrameAnimation;
- (WUCVector3KeyFrameAnimation*)createVector3KeyFrameAnimation;
- (WUCVector4KeyFrameAnimation*)createVector4KeyFrameAnimation;
- (WUCCompositionCommitBatch*)getCommitBatch:(WUCCompositionBatchTypes)batchType;
- (void)close;
- (WUCAmbientLight*)createAmbientLight;
- (WUCCompositionAnimationGroup*)createAnimationGroup;
- (WUCCompositionBackdropBrush*)createBackdropBrush;
- (WUCDistantLight*)createDistantLight;
- (WUCDropShadow*)createDropShadow;
- (WUCImplicitAnimationCollection*)createImplicitAnimationCollection;
- (WUCLayerVisual*)createLayerVisual;
- (WUCCompositionMaskBrush*)createMaskBrush;
- (WUCCompositionNineGridBrush*)createNineGridBrush;
- (WUCPointLight*)createPointLight;
- (WUCSpotLight*)createSpotLight;
- (WUCStepEasingFunction*)createStepEasingFunction;
- (WUCStepEasingFunction*)createStepEasingFunctionWithStepCount:(int)stepCount;
@end

#endif // __WUCCompositor_DEFINED__

// Windows.UI.Composition.CompositionPropertySet
#ifndef __WUCCompositionPropertySet_DEFINED__
#define __WUCCompositionPropertySet_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionPropertySet : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)insertColor:(NSString *)propertyName value:(WUColor*)value;
- (void)insertMatrix3x2:(NSString *)propertyName value:(WFNMatrix3x2*)value;
- (void)insertMatrix4x4:(NSString *)propertyName value:(WFNMatrix4x4*)value;
- (void)insertQuaternion:(NSString *)propertyName value:(WFNQuaternion*)value;
- (void)insertScalar:(NSString *)propertyName value:(float)value;
- (void)insertVector2:(NSString *)propertyName value:(WFNVector2*)value;
- (void)insertVector3:(NSString *)propertyName value:(WFNVector3*)value;
- (void)insertVector4:(NSString *)propertyName value:(WFNVector4*)value;
- (WUCCompositionGetValueStatus)tryGetColor:(NSString *)propertyName value:(WUColor**)value;
- (WUCCompositionGetValueStatus)tryGetMatrix3x2:(NSString *)propertyName value:(WFNMatrix3x2**)value;
- (WUCCompositionGetValueStatus)tryGetMatrix4x4:(NSString *)propertyName value:(WFNMatrix4x4**)value;
- (WUCCompositionGetValueStatus)tryGetQuaternion:(NSString *)propertyName value:(WFNQuaternion**)value;
- (WUCCompositionGetValueStatus)tryGetScalar:(NSString *)propertyName value:(float*)value;
- (WUCCompositionGetValueStatus)tryGetVector2:(NSString *)propertyName value:(WFNVector2**)value;
- (WUCCompositionGetValueStatus)tryGetVector3:(NSString *)propertyName value:(WFNVector3**)value;
- (WUCCompositionGetValueStatus)tryGetVector4:(NSString *)propertyName value:(WFNVector4**)value;
- (void)insertBoolean:(NSString *)propertyName value:(BOOL)value;
- (WUCCompositionGetValueStatus)tryGetBoolean:(NSString *)propertyName value:(BOOL*)value;
@end

#endif // __WUCCompositionPropertySet_DEFINED__

// Windows.UI.Composition.CompositionDrawingSurface
#ifndef __WUCCompositionDrawingSurface_DEFINED__
#define __WUCCompositionDrawingSurface_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionDrawingSurface : WUCCompositionObject <WUCICompositionSurface>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGDDirectXAlphaMode alphaMode;
@property (readonly) WGDDirectXPixelFormat pixelFormat;
@property (readonly) WFSize* size;
@end

#endif // __WUCCompositionDrawingSurface_DEFINED__

// Windows.UI.Composition.CompositionColorBrush
#ifndef __WUCCompositionColorBrush_DEFINED__
#define __WUCCompositionColorBrush_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionColorBrush : WUCCompositionBrush
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUColor* color;
@end

#endif // __WUCCompositionColorBrush_DEFINED__

// Windows.UI.Composition.CompositionEffectFactory
#ifndef __WUCCompositionEffectFactory_DEFINED__
#define __WUCCompositionEffectFactory_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionEffectFactory : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) WUCCompositionEffectFactoryLoadStatus loadStatus;
- (WUCCompositionEffectBrush*)createBrush;
@end

#endif // __WUCCompositionEffectFactory_DEFINED__

// Windows.UI.Composition.CompositionScopedBatch
#ifndef __WUCCompositionScopedBatch_DEFINED__
#define __WUCCompositionScopedBatch_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionScopedBatch : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isActive;
@property (readonly) BOOL isEnded;
- (EventRegistrationToken)addCompletedEvent:(void(^)(RTObject*, WUCCompositionBatchCompletedEventArgs*))del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
- (void)end;
- (void)resume;
- (void)suspend;
@end

#endif // __WUCCompositionScopedBatch_DEFINED__

// Windows.UI.Composition.CompositionSurfaceBrush
#ifndef __WUCCompositionSurfaceBrush_DEFINED__
#define __WUCCompositionSurfaceBrush_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionSurfaceBrush : WUCCompositionBrush
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property float verticalAlignmentRatio;
@property (retain) RTObject<WUCICompositionSurface>* surface;
@property WUCCompositionStretch stretch;
@property float horizontalAlignmentRatio;
@property WUCCompositionBitmapInterpolationMode bitmapInterpolationMode;
@property (retain) WFNVector2* anchorPoint;
@property (retain) WFNMatrix3x2* transformMatrix;
@property (retain) WFNVector2* scale;
@property float rotationAngleInDegrees;
@property float rotationAngle;
@property (retain) WFNVector2* offset;
@property (retain) WFNVector2* centerPoint;
@end

#endif // __WUCCompositionSurfaceBrush_DEFINED__

// Windows.UI.Composition.CompositionTarget
#ifndef __WUCCompositionTarget_DEFINED__
#define __WUCCompositionTarget_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionTarget : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUCVisual* root;
@end

#endif // __WUCCompositionTarget_DEFINED__

// Windows.UI.Composition.CompositionCommitBatch
#ifndef __WUCCompositionCommitBatch_DEFINED__
#define __WUCCompositionCommitBatch_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionCommitBatch : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isActive;
@property (readonly) BOOL isEnded;
- (EventRegistrationToken)addCompletedEvent:(void(^)(RTObject*, WUCCompositionBatchCompletedEventArgs*))del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUCCompositionCommitBatch_DEFINED__

// Windows.UI.Composition.CompositionAnimationGroup
#ifndef __WUCCompositionAnimationGroup_DEFINED__
#define __WUCCompositionAnimationGroup_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionAnimationGroup : WUCCompositionObject <WUCICompositionAnimationBase>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int count;
- (void)add:(WUCCompositionAnimation*)value;
- (void)remove:(WUCCompositionAnimation*)value;
- (void)removeAll;
@end

#endif // __WUCCompositionAnimationGroup_DEFINED__

// Windows.UI.Composition.CompositionBackdropBrush
#ifndef __WUCCompositionBackdropBrush_DEFINED__
#define __WUCCompositionBackdropBrush_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionBackdropBrush : WUCCompositionBrush
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUCCompositionBackdropBrush_DEFINED__

// Windows.UI.Composition.CompositionMaskBrush
#ifndef __WUCCompositionMaskBrush_DEFINED__
#define __WUCCompositionMaskBrush_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionMaskBrush : WUCCompositionBrush
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUCCompositionBrush* source;
@property (retain) WUCCompositionBrush* mask;
@end

#endif // __WUCCompositionMaskBrush_DEFINED__

// Windows.UI.Composition.CompositionNineGridBrush
#ifndef __WUCCompositionNineGridBrush_DEFINED__
#define __WUCCompositionNineGridBrush_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionNineGridBrush : WUCCompositionBrush
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property float topInsetScale;
@property float topInset;
@property (retain) WUCCompositionBrush* source;
@property float rightInsetScale;
@property float rightInset;
@property float leftInsetScale;
@property float leftInset;
@property BOOL isCenterHollow;
@property float bottomInsetScale;
@property float bottomInset;
- (void)setInsets:(float)inset;
- (void)setInsetsWithValues:(float)left top:(float)top right:(float)right bottom:(float)bottom;
- (void)setInsetScales:(float)scale;
- (void)setInsetScalesWithValues:(float)left top:(float)top right:(float)right bottom:(float)bottom;
@end

#endif // __WUCCompositionNineGridBrush_DEFINED__

// Windows.UI.Composition.CubicBezierEasingFunction
#ifndef __WUCCubicBezierEasingFunction_DEFINED__
#define __WUCCubicBezierEasingFunction_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCubicBezierEasingFunction : WUCCompositionEasingFunction
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFNVector2* controlPoint1;
@property (readonly) WFNVector2* controlPoint2;
@end

#endif // __WUCCubicBezierEasingFunction_DEFINED__

// Windows.UI.Composition.ExpressionAnimation
#ifndef __WUCExpressionAnimation_DEFINED__
#define __WUCExpressionAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCExpressionAnimation : WUCCompositionAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * expression;
@end

#endif // __WUCExpressionAnimation_DEFINED__

// Windows.UI.Composition.ImplicitAnimationCollection
#ifndef __WUCImplicitAnimationCollection_DEFINED__
#define __WUCImplicitAnimationCollection_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCImplicitAnimationCollection : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (id)objectForKey: (id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject: (id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

-(void)setObject: (id)obj forKey: (id)key;
-(void)setObject:(id)object forKeyedSubscript:(id)key;
-(void)removeObjectForKey: (id)key;
-(void)removeAllObjects;
-(void)removeObjectsForKeys:(NSArray*)keys;
-(void)addEntriesFromDictionary:(NSDictionary*)otherDict;
-(void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;
-(void)setDictionary: (NSDictionary*)dict;
@end

#endif // __WUCImplicitAnimationCollection_DEFINED__

// Windows.UI.Composition.LinearEasingFunction
#ifndef __WUCLinearEasingFunction_DEFINED__
#define __WUCLinearEasingFunction_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCLinearEasingFunction : WUCCompositionEasingFunction
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUCLinearEasingFunction_DEFINED__

// Windows.UI.Composition.RenderingDeviceReplacedEventArgs
#ifndef __WUCRenderingDeviceReplacedEventArgs_DEFINED__
#define __WUCRenderingDeviceReplacedEventArgs_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCRenderingDeviceReplacedEventArgs : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUCCompositionGraphicsDevice* graphicsDevice;
@end

#endif // __WUCRenderingDeviceReplacedEventArgs_DEFINED__

// Windows.UI.Composition.CompositionShadow
#ifndef __WUCCompositionShadow_DEFINED__
#define __WUCCompositionShadow_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionShadow : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUCCompositionShadow_DEFINED__

// Windows.UI.Composition.DropShadow
#ifndef __WUCDropShadow_DEFINED__
#define __WUCDropShadow_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCDropShadow : WUCCompositionShadow
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property float opacity;
@property (retain) WFNVector3* offset;
@property (retain) WUCCompositionBrush* mask;
@property (retain) WUColor* color;
@property float blurRadius;
@end

#endif // __WUCDropShadow_DEFINED__

// Windows.UI.Composition.StepEasingFunction
#ifndef __WUCStepEasingFunction_DEFINED__
#define __WUCStepEasingFunction_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCStepEasingFunction : WUCCompositionEasingFunction
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property int stepCount;
@property BOOL isInitialStepSingleFrame;
@property BOOL isFinalStepSingleFrame;
@property int initialStep;
@property int finalStep;
@end

#endif // __WUCStepEasingFunction_DEFINED__

// Windows.UI.Composition.Visual
#ifndef __WUCVisual_DEFINED__
#define __WUCVisual_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCVisual : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFNVector3* offset;
@property BOOL isVisible;
@property WUCCompositionCompositeMode compositeMode;
@property (retain) WUCCompositionClip* clip;
@property (retain) WFNVector3* centerPoint;
@property WUCCompositionBorderMode borderMode;
@property (retain) WFNVector3* scale;
@property WUCCompositionBackfaceVisibility backfaceVisibility;
@property (retain) WFNVector2* anchorPoint;
@property float rotationAngleInDegrees;
@property (retain) WFNVector2* size;
@property (retain) WFNVector3* rotationAxis;
@property (retain) WFNMatrix4x4* transformMatrix;
@property float rotationAngle;
@property (retain) WFNQuaternion* orientation;
@property float opacity;
@property (readonly) WUCContainerVisual* parent;
@end

#endif // __WUCVisual_DEFINED__

// Windows.UI.Composition.ContainerVisual
#ifndef __WUCContainerVisual_DEFINED__
#define __WUCContainerVisual_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCContainerVisual : WUCVisual
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUCVisualCollection* children;
@end

#endif // __WUCContainerVisual_DEFINED__

// Windows.UI.Composition.SpriteVisual
#ifndef __WUCSpriteVisual_DEFINED__
#define __WUCSpriteVisual_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCSpriteVisual : WUCContainerVisual
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUCCompositionBrush* brush;
@property (retain) WUCCompositionShadow* shadow;
@end

#endif // __WUCSpriteVisual_DEFINED__

// Windows.UI.Composition.LayerVisual
#ifndef __WUCLayerVisual_DEFINED__
#define __WUCLayerVisual_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCLayerVisual : WUCContainerVisual
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUCCompositionEffectBrush* effect;
@end

#endif // __WUCLayerVisual_DEFINED__

// Windows.UI.Composition.CompositionClip
#ifndef __WUCCompositionClip_DEFINED__
#define __WUCCompositionClip_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionClip : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFNMatrix3x2* transformMatrix;
@property (retain) WFNVector2* scale;
@property float rotationAngleInDegrees;
@property float rotationAngle;
@property (retain) WFNVector2* offset;
@property (retain) WFNVector2* centerPoint;
@property (retain) WFNVector2* anchorPoint;
@end

#endif // __WUCCompositionClip_DEFINED__

// Windows.UI.Composition.InsetClip
#ifndef __WUCInsetClip_DEFINED__
#define __WUCInsetClip_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCInsetClip : WUCCompositionClip
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property float topInset;
@property float rightInset;
@property float leftInset;
@property float bottomInset;
@end

#endif // __WUCInsetClip_DEFINED__

// Windows.UI.Composition.VisualCollection
#ifndef __WUCVisualCollection_DEFINED__
#define __WUCVisualCollection_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCVisualCollection : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int count;
- (void)insertAbove:(WUCVisual*)newChild sibling:(WUCVisual*)sibling;
- (void)insertAtBottom:(WUCVisual*)newChild;
- (void)insertAtTop:(WUCVisual*)newChild;
- (void)insertBelow:(WUCVisual*)newChild sibling:(WUCVisual*)sibling;
- (void)remove:(WUCVisual*)child;
- (void)removeAll;
@end

#endif // __WUCVisualCollection_DEFINED__

// Windows.UI.Composition.VisualUnorderedCollection
#ifndef __WUCVisualUnorderedCollection_DEFINED__
#define __WUCVisualUnorderedCollection_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCVisualUnorderedCollection : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int count;
- (void)add:(WUCVisual*)newVisual;
- (void)remove:(WUCVisual*)visual;
- (void)removeAll;
@end

#endif // __WUCVisualUnorderedCollection_DEFINED__

// Windows.UI.Composition.CompositionLight
#ifndef __WUCCompositionLight_DEFINED__
#define __WUCCompositionLight_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionLight : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUCVisualUnorderedCollection* targets;
@end

#endif // __WUCCompositionLight_DEFINED__

// Windows.UI.Composition.AmbientLight
#ifndef __WUCAmbientLight_DEFINED__
#define __WUCAmbientLight_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCAmbientLight : WUCCompositionLight
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUColor* color;
@end

#endif // __WUCAmbientLight_DEFINED__

// Windows.UI.Composition.DistantLight
#ifndef __WUCDistantLight_DEFINED__
#define __WUCDistantLight_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCDistantLight : WUCCompositionLight
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFNVector3* direction;
@property (retain) WUCVisual* coordinateSpace;
@property (retain) WUColor* color;
@end

#endif // __WUCDistantLight_DEFINED__

// Windows.UI.Composition.PointLight
#ifndef __WUCPointLight_DEFINED__
#define __WUCPointLight_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCPointLight : WUCCompositionLight
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property float quadraticAttenuation;
@property (retain) WFNVector3* offset;
@property float linearAttenuation;
@property (retain) WUCVisual* coordinateSpace;
@property float constantAttenuation;
@property (retain) WUColor* color;
@end

#endif // __WUCPointLight_DEFINED__

// Windows.UI.Composition.SpotLight
#ifndef __WUCSpotLight_DEFINED__
#define __WUCSpotLight_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCSpotLight : WUCCompositionLight
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUColor* innerConeColor;
@property float innerConeAngleInDegrees;
@property float innerConeAngle;
@property (retain) WFNVector3* direction;
@property (retain) WUCVisual* coordinateSpace;
@property float constantAttenuation;
@property float quadraticAttenuation;
@property (retain) WUColor* outerConeColor;
@property float outerConeAngleInDegrees;
@property float outerConeAngle;
@property (retain) WFNVector3* offset;
@property float linearAttenuation;
@end

#endif // __WUCSpotLight_DEFINED__

// Windows.UI.Composition.KeyFrameAnimation
#ifndef __WUCKeyFrameAnimation_DEFINED__
#define __WUCKeyFrameAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCKeyFrameAnimation : WUCCompositionAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUCAnimationStopBehavior stopBehavior;
@property int iterationCount;
@property WUCAnimationIterationBehavior iterationBehavior;
@property (retain) WFTimeSpan* duration;
@property (retain) WFTimeSpan* delayTime;
@property (readonly) int keyFrameCount;
@property WUCAnimationDirection direction;
- (void)insertExpressionKeyFrame:(float)normalizedProgressKey value:(NSString *)value;
- (void)insertExpressionKeyFrameWithEasingFunction:(float)normalizedProgressKey value:(NSString *)value easingFunction:(WUCCompositionEasingFunction*)easingFunction;
@end

#endif // __WUCKeyFrameAnimation_DEFINED__

// Windows.UI.Composition.ColorKeyFrameAnimation
#ifndef __WUCColorKeyFrameAnimation_DEFINED__
#define __WUCColorKeyFrameAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCColorKeyFrameAnimation : WUCKeyFrameAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUCCompositionColorSpace interpolationColorSpace;
- (void)insertKeyFrame:(float)normalizedProgressKey value:(WUColor*)value;
- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey value:(WUColor*)value easingFunction:(WUCCompositionEasingFunction*)easingFunction;
@end

#endif // __WUCColorKeyFrameAnimation_DEFINED__

// Windows.UI.Composition.QuaternionKeyFrameAnimation
#ifndef __WUCQuaternionKeyFrameAnimation_DEFINED__
#define __WUCQuaternionKeyFrameAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCQuaternionKeyFrameAnimation : WUCKeyFrameAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)insertKeyFrame:(float)normalizedProgressKey value:(WFNQuaternion*)value;
- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey value:(WFNQuaternion*)value easingFunction:(WUCCompositionEasingFunction*)easingFunction;
@end

#endif // __WUCQuaternionKeyFrameAnimation_DEFINED__

// Windows.UI.Composition.ScalarKeyFrameAnimation
#ifndef __WUCScalarKeyFrameAnimation_DEFINED__
#define __WUCScalarKeyFrameAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCScalarKeyFrameAnimation : WUCKeyFrameAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)insertKeyFrame:(float)normalizedProgressKey value:(float)value;
- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey value:(float)value easingFunction:(WUCCompositionEasingFunction*)easingFunction;
@end

#endif // __WUCScalarKeyFrameAnimation_DEFINED__

// Windows.UI.Composition.Vector2KeyFrameAnimation
#ifndef __WUCVector2KeyFrameAnimation_DEFINED__
#define __WUCVector2KeyFrameAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCVector2KeyFrameAnimation : WUCKeyFrameAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)insertKeyFrame:(float)normalizedProgressKey value:(WFNVector2*)value;
- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey value:(WFNVector2*)value easingFunction:(WUCCompositionEasingFunction*)easingFunction;
@end

#endif // __WUCVector2KeyFrameAnimation_DEFINED__

// Windows.UI.Composition.Vector3KeyFrameAnimation
#ifndef __WUCVector3KeyFrameAnimation_DEFINED__
#define __WUCVector3KeyFrameAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCVector3KeyFrameAnimation : WUCKeyFrameAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)insertKeyFrame:(float)normalizedProgressKey value:(WFNVector3*)value;
- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey value:(WFNVector3*)value easingFunction:(WUCCompositionEasingFunction*)easingFunction;
@end

#endif // __WUCVector3KeyFrameAnimation_DEFINED__

// Windows.UI.Composition.Vector4KeyFrameAnimation
#ifndef __WUCVector4KeyFrameAnimation_DEFINED__
#define __WUCVector4KeyFrameAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCVector4KeyFrameAnimation : WUCKeyFrameAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)insertKeyFrame:(float)normalizedProgressKey value:(WFNVector4*)value;
- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey value:(WFNVector4*)value easingFunction:(WUCCompositionEasingFunction*)easingFunction;
@end

#endif // __WUCVector4KeyFrameAnimation_DEFINED__

