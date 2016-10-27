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

#ifndef OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
#define OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_UI_Composition.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUCCompositionObject, WUCCompositionEffect, WUCCompositionEffectFactoryLoadResult, WUCCompositionEffectSourceParameter,
    WUCCompositionImageOptions, WUCCompositionImage, WUCCompositionImageLoadResult, WUCCompositor, WUCCompositionAnimation,
    WUCCompositionPropertyAnimator, WUCAnimationEndedEventArgs, WUCCompositionPropertySet, WUCCompositionGraphicsDevice,
    WUCCompositionEffectFactory, WUCCompositionTarget, WUCExpressionAnimation, WUCCompositionEasingFunction, WUCCubicBezierEasingFunction,
    WUCLinearEasingFunction, WUCVisual, WUCContainerVisual, WUCEffectVisual, WUCImageVisual, WUCSolidColorVisual, WUCCompositionClip,
    WUCInsetClip, WUCVisualCollection, WUCKeyFrameAnimation, WUCScalarKeyFrameAnimation, WUCVector2KeyFrameAnimation,
    WUCVector3KeyFrameAnimation, WUCVector4KeyFrameAnimation;
@protocol WUCIAnimationEndedEventArgs
, WUCICompositionAnimation, WUCICompositionClip, WUCICompositionEasingFunction, WUCICompositionEffect, WUCICompositionSurface,
    WUCICompositionEffectFactory, WUCICompositionEffectFactoryLoadResult, WUCICompositionEffectSourceParameter,
    WUCICompositionEffectSourceParameterFactory, WUCICompositionGraphicsDevice, WUCICompositionImage, WUCICompositionImageLoadResult,
    WUCICompositionImageOptions, WUCICompositionObject, WUCICompositionPropertyAnimator, WUCICompositionPropertySet, WUCICompositionTarget,
    WUCICompositor, WUCIContainerVisual, WUCICubicBezierEasingFunction, WUCIEffectVisual, WUCIExpressionAnimation, WUCIImageVisual,
    WUCIInsetClip, WUCIKeyFrameAnimation, WUCILinearEasingFunction, WUCIScalarKeyFrameAnimation, WUCISolidColorVisual,
    WUCIVector2KeyFrameAnimation, WUCIVector3KeyFrameAnimation, WUCIVector4KeyFrameAnimation, WUCIVisual, WUCIVisualCollection,
    WUCICompositionAnimationFactory, WUCICompositionClipFactory, WUCICompositionEasingFunctionFactory, WUCICompositionObjectFactory,
    WUCIContainerVisualFactory, WUCIKeyFrameAnimationFactory, WUCIVisualFactory;

// Windows.UI.Composition.AnimationEndReason
enum _WUCAnimationEndReason {
    WUCAnimationEndReasonStopped = 0,
    WUCAnimationEndReasonCompleted = 1,
    WUCAnimationEndReasonDisconnected = 2,
};
typedef unsigned WUCAnimationEndReason;

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

// Windows.UI.Composition.CompositionEffectFactoryLoadStatus
enum _WUCCompositionEffectFactoryLoadStatus {
    WUCCompositionEffectFactoryLoadStatusSuccess = 0,
    WUCCompositionEffectFactoryLoadStatusEffectTooComplex = 1,
    WUCCompositionEffectFactoryLoadStatusOther = 2,
};
typedef unsigned WUCCompositionEffectFactoryLoadStatus;

// Windows.UI.Composition.CompositionGetValueStatus
enum _WUCCompositionGetValueStatus {
    WUCCompositionGetValueStatusSucceeded = 0,
    WUCCompositionGetValueStatusTypeMismatch = 1,
    WUCCompositionGetValueStatusNotFound = 2,
};
typedef unsigned WUCCompositionGetValueStatus;

// Windows.UI.Composition.CompositionImageLoadStatus
enum _WUCCompositionImageLoadStatus {
    WUCCompositionImageLoadStatusSuccess = 0,
    WUCCompositionImageLoadStatusFileAccessError = 1,
    WUCCompositionImageLoadStatusDecodeError = 2,
    WUCCompositionImageLoadStatusNotEnoughResources = 3,
    WUCCompositionImageLoadStatusOther = 4,
};
typedef unsigned WUCCompositionImageLoadStatus;

// Windows.UI.Composition.CompositionImageProgressStage
enum _WUCCompositionImageProgressStage {
    WUCCompositionImageProgressStageNone = 0,
    WUCCompositionImageProgressStageHeaderDecoded = 30,
};
typedef unsigned WUCCompositionImageProgressStage;

// Windows.UI.Composition.CompositionStretch
enum _WUCCompositionStretch {
    WUCCompositionStretchNone = 0,
    WUCCompositionStretchFill = 1,
    WUCCompositionStretchUniform = 2,
    WUCCompositionStretchUniformToFill = 3,
};
typedef unsigned WUCCompositionStretch;

#include "WindowsFoundationNumerics.h"
#include "WindowsFoundation.h"
#include "WindowsGraphicsEffects.h"
#include "WindowsUICore.h"
#include "WindowsUI.h"

#import <Foundation/Foundation.h>

// Windows.UI.Composition.ICompositionSurface
#ifndef __WUCICompositionSurface_DEFINED__
#define __WUCICompositionSurface_DEFINED__

@protocol WUCICompositionSurface
@end

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCICompositionSurface : RTObject <WUCICompositionSurface>
@end

#endif // __WUCICompositionSurface_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.UI.Composition.CompositionObject
#ifndef __WUCCompositionObject_DEFINED__
#define __WUCCompositionObject_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionObject : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WUCCompositor* compositor;
@property (readonly) WUCCoreDispatcher* dispatcher;
@property (readonly) WUCCompositionPropertySet* properties;
- (WUCCompositionPropertyAnimator*)connectAnimation:(NSString*)propertyName animation:(WUCCompositionAnimation*)animation;
- (void)disconnectAnimation:(NSString*)propertyName;
- (void)close;
@end

#endif // __WUCCompositionObject_DEFINED__

// Windows.UI.Composition.CompositionEffect
#ifndef __WUCCompositionEffect_DEFINED__
#define __WUCCompositionEffect_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionEffect : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (RTObject<WUCICompositionSurface>*)getSourceParameter:(NSString*)name;
- (void)setSourceParameter:(NSString*)name source:(RTObject<WUCICompositionSurface>*)source;
@end

#endif // __WUCCompositionEffect_DEFINED__

// Windows.UI.Composition.CompositionEffectFactoryLoadResult
#ifndef __WUCCompositionEffectFactoryLoadResult_DEFINED__
#define __WUCCompositionEffectFactoryLoadResult_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionEffectFactoryLoadResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) WUCCompositionEffectFactoryLoadStatus status;
@end

#endif // __WUCCompositionEffectFactoryLoadResult_DEFINED__

// Windows.Graphics.Effects.IGraphicsEffectSource
#ifndef __WGEIGraphicsEffectSource_DEFINED__
#define __WGEIGraphicsEffectSource_DEFINED__

@protocol WGEIGraphicsEffectSource
@end

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WGEIGraphicsEffectSource : RTObject <WGEIGraphicsEffectSource>
@end

#endif // __WGEIGraphicsEffectSource_DEFINED__

// Windows.UI.Composition.CompositionEffectSourceParameter
#ifndef __WUCCompositionEffectSourceParameter_DEFINED__
#define __WUCCompositionEffectSourceParameter_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionEffectSourceParameter : RTObject <WGEIGraphicsEffectSource>
+ (WUCCompositionEffectSourceParameter*)make:(NSString*)name ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSString* name;
@end

#endif // __WUCCompositionEffectSourceParameter_DEFINED__

// Windows.UI.Composition.CompositionImageOptions
#ifndef __WUCCompositionImageOptions_DEFINED__
#define __WUCCompositionImageOptions_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionImageOptions : RTObject
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property int decodeWidth;
@property int decodeHeight;
@end

#endif // __WUCCompositionImageOptions_DEFINED__

// Windows.UI.Composition.CompositionImage
#ifndef __WUCCompositionImage_DEFINED__
#define __WUCCompositionImage_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionImage : WUCCompositionObject <WUCICompositionSurface>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WFSize* size;
- (void)completeLoadAsyncWithSuccess:(void (^)(WUCCompositionImageLoadResult*))success
                            progress:(void (^)(WUCCompositionImageProgressStage))progress
                             failure:(void (^)(NSError*))failure;
@end

#endif // __WUCCompositionImage_DEFINED__

// Windows.UI.Composition.CompositionImageLoadResult
#ifndef __WUCCompositionImageLoadResult_DEFINED__
#define __WUCCompositionImageLoadResult_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionImageLoadResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) WUCCompositionImageLoadStatus status;
@end

#endif // __WUCCompositionImageLoadResult_DEFINED__

// Windows.UI.Composition.Compositor
#ifndef __WUCCompositor_DEFINED__
#define __WUCCompositor_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositor : RTObject <WFIClosable>
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WUCCompositionGraphicsDevice* defaultGraphicsDevice;
- (WUCContainerVisual*)createContainerVisual;
- (WUCCubicBezierEasingFunction*)createCubicBezierEasingFunction:(WFNVector2*)controlPoint1 controlPoint2:(WFNVector2*)controlPoint2;
- (WUCCompositionEffectFactory*)createEffectFactory:(RTObject<WGEIGraphicsEffect>*)graphicsEffect;
- (WUCCompositionEffectFactory*)createEffectFactoryWithProperties:(RTObject<WGEIGraphicsEffect>*)graphicsEffect
                                             animatableProperties:(id<NSFastEnumeration> /* NSString * */)animatableProperties;
- (WUCEffectVisual*)createEffectVisual;
- (WUCExpressionAnimation*)createExpressionAnimation;
- (WUCExpressionAnimation*)createExpressionAnimationWithExpression:(NSString*)expression;
- (WUCImageVisual*)createImageVisual;
- (WUCInsetClip*)createInsetClip;
- (WUCInsetClip*)createInsetClipWithInsets:(float)leftInset
                                  topInset:(float)topInset
                                rightInset:(float)rightInset
                               bottomInset:(float)bottomInset;
- (WUCLinearEasingFunction*)createLinearEasingFunction;
- (WUCCompositionPropertySet*)createPropertySet;
- (WUCScalarKeyFrameAnimation*)createScalarKeyFrameAnimation;
- (WUCSolidColorVisual*)createSolidColorVisual;
- (WUCCompositionTarget*)createTargetForCurrentView;
- (WUCVector2KeyFrameAnimation*)createVector2KeyFrameAnimation;
- (WUCVector3KeyFrameAnimation*)createVector3KeyFrameAnimation;
- (WUCVector4KeyFrameAnimation*)createVector4KeyFrameAnimation;
- (void)close;
@end

#endif // __WUCCompositor_DEFINED__

// Windows.UI.Composition.CompositionAnimation
#ifndef __WUCCompositionAnimation_DEFINED__
#define __WUCCompositionAnimation_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionAnimation : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)clearAllParameters;
- (void)clearParameter:(NSString*)key;
- (void)setMatrix3x2Parameter:(NSString*)key value:(WFNMatrix3x2*)value;
- (void)setMatrix4x4Parameter:(NSString*)key value:(WFNMatrix4x4*)value;
- (void)setReferenceParameter:(NSString*)key compositionObject:(WUCCompositionObject*)compositionObject;
- (void)setScalarParameter:(NSString*)key value:(float)value;
- (void)setVector2Parameter:(NSString*)key value:(WFNVector2*)value;
- (void)setVector3Parameter:(NSString*)key value:(WFNVector3*)value;
- (void)setVector4Parameter:(NSString*)key value:(WFNVector4*)value;
@end

#endif // __WUCCompositionAnimation_DEFINED__

// Windows.UI.Composition.CompositionPropertyAnimator
#ifndef __WUCCompositionPropertyAnimator_DEFINED__
#define __WUCCompositionPropertyAnimator_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionPropertyAnimator : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (EventRegistrationToken)addAnimationEndedEvent:(void (^)(WUCCompositionPropertyAnimator*, WUCAnimationEndedEventArgs*))del;
- (void)removeAnimationEndedEvent:(EventRegistrationToken)tok;
- (void)pause;
- (void)start;
- (void)stop;
@end

#endif // __WUCCompositionPropertyAnimator_DEFINED__

// Windows.UI.Composition.AnimationEndedEventArgs
#ifndef __WUCAnimationEndedEventArgs_DEFINED__
#define __WUCAnimationEndedEventArgs_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCAnimationEndedEventArgs : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WUCAnimationEndReason actualEndReason;
@end

#endif // __WUCAnimationEndedEventArgs_DEFINED__

// Windows.UI.Composition.CompositionPropertySet
#ifndef __WUCCompositionPropertySet_DEFINED__
#define __WUCCompositionPropertySet_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionPropertySet : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)insertMatrix3x2:(NSString*)propertyName value:(WFNMatrix3x2*)value;
- (void)insertMatrix4x4:(NSString*)propertyName value:(WFNMatrix4x4*)value;
- (void)insertScalar:(NSString*)propertyName value:(float)value;
- (void)insertVector2:(NSString*)propertyName value:(WFNVector2*)value;
- (void)insertVector3:(NSString*)propertyName value:(WFNVector3*)value;
- (void)insertVector4:(NSString*)propertyName value:(WFNVector4*)value;
- (WUCCompositionGetValueStatus)tryGetMatrix3x2:(NSString*)propertyName value:(WFNMatrix3x2**)value;
- (WUCCompositionGetValueStatus)tryGetMatrix4x4:(NSString*)propertyName value:(WFNMatrix4x4**)value;
- (WUCCompositionGetValueStatus)tryGetScalar:(NSString*)propertyName value:(float*)value;
- (WUCCompositionGetValueStatus)tryGetVector2:(NSString*)propertyName value:(WFNVector2**)value;
- (WUCCompositionGetValueStatus)tryGetVector3:(NSString*)propertyName value:(WFNVector3**)value;
- (WUCCompositionGetValueStatus)tryGetVector4:(NSString*)propertyName value:(WFNVector4**)value;
@end

#endif // __WUCCompositionPropertySet_DEFINED__

// Windows.UI.Composition.CompositionGraphicsDevice
#ifndef __WUCCompositionGraphicsDevice_DEFINED__
#define __WUCCompositionGraphicsDevice_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionGraphicsDevice : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (WUCCompositionImage*)createImageFromUri:(WFUri*)uri;
- (WUCCompositionImage*)createImageFromUriWithOptions:(WFUri*)uri options:(WUCCompositionImageOptions*)options;
@end

#endif // __WUCCompositionGraphicsDevice_DEFINED__

// Windows.UI.Composition.CompositionEffectFactory
#ifndef __WUCCompositionEffectFactory_DEFINED__
#define __WUCCompositionEffectFactory_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionEffectFactory : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (WUCCompositionEffect*)createEffect;
- (void)completeLoadAsyncWithSuccess:(void (^)(WUCCompositionEffectFactoryLoadResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WUCCompositionEffectFactory_DEFINED__

// Windows.UI.Composition.CompositionTarget
#ifndef __WUCCompositionTarget_DEFINED__
#define __WUCCompositionTarget_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionTarget : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (retain) WUCVisual* root;
@end

#endif // __WUCCompositionTarget_DEFINED__

// Windows.UI.Composition.ExpressionAnimation
#ifndef __WUCExpressionAnimation_DEFINED__
#define __WUCExpressionAnimation_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCExpressionAnimation : WUCCompositionAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (retain) NSString* expression;
@end

#endif // __WUCExpressionAnimation_DEFINED__

// Windows.UI.Composition.CompositionEasingFunction
#ifndef __WUCCompositionEasingFunction_DEFINED__
#define __WUCCompositionEasingFunction_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionEasingFunction : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@end

#endif // __WUCCompositionEasingFunction_DEFINED__

// Windows.UI.Composition.CubicBezierEasingFunction
#ifndef __WUCCubicBezierEasingFunction_DEFINED__
#define __WUCCubicBezierEasingFunction_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCubicBezierEasingFunction : WUCCompositionEasingFunction
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WFNVector2* controlPoint1;
@property (readonly) WFNVector2* controlPoint2;
@end

#endif // __WUCCubicBezierEasingFunction_DEFINED__

// Windows.UI.Composition.LinearEasingFunction
#ifndef __WUCLinearEasingFunction_DEFINED__
#define __WUCLinearEasingFunction_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCLinearEasingFunction : WUCCompositionEasingFunction
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@end

#endif // __WUCLinearEasingFunction_DEFINED__

// Windows.UI.Composition.Visual
#ifndef __WUCVisual_DEFINED__
#define __WUCVisual_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCVisual : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (retain) WFNQuaternion* orientation;
@property float opacity;
@property (retain) WFNVector3* offset;
@property (retain) WUCCompositionClip* clip;
@property (retain) WFNVector3* centerPoint;
@property (retain) WFNMatrix4x4* transformMatrix;
@property (retain) WFNVector2* size;
@property (retain) WFNVector3* scale;
@property (retain) WFNVector3* rotationAxis;
@property float rotationAngle;
@property (readonly) WUCContainerVisual* parent;
@end

#endif // __WUCVisual_DEFINED__

// Windows.UI.Composition.ContainerVisual
#ifndef __WUCContainerVisual_DEFINED__
#define __WUCContainerVisual_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCContainerVisual : WUCVisual
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WUCVisualCollection* children;
@end

#endif // __WUCContainerVisual_DEFINED__

// Windows.UI.Composition.EffectVisual
#ifndef __WUCEffectVisual_DEFINED__
#define __WUCEffectVisual_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCEffectVisual : WUCContainerVisual
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (retain) WUCCompositionEffect* effect;
@end

#endif // __WUCEffectVisual_DEFINED__

// Windows.UI.Composition.ImageVisual
#ifndef __WUCImageVisual_DEFINED__
#define __WUCImageVisual_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCImageVisual : WUCContainerVisual
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property float verticalAlignmentRatio;
@property WUCCompositionStretch stretch;
@property (retain) RTObject<WUCICompositionSurface>* image;
@property float horizontalAlignmentRatio;
@end

#endif // __WUCImageVisual_DEFINED__

// Windows.UI.Composition.SolidColorVisual
#ifndef __WUCSolidColorVisual_DEFINED__
#define __WUCSolidColorVisual_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCSolidColorVisual : WUCContainerVisual
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (retain) WUColor* color;
@end

#endif // __WUCSolidColorVisual_DEFINED__

// Windows.UI.Composition.CompositionClip
#ifndef __WUCCompositionClip_DEFINED__
#define __WUCCompositionClip_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCCompositionClip : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@end

#endif // __WUCCompositionClip_DEFINED__

// Windows.UI.Composition.InsetClip
#ifndef __WUCInsetClip_DEFINED__
#define __WUCInsetClip_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCInsetClip : WUCCompositionClip
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
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

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCVisualCollection : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
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

// Windows.UI.Composition.KeyFrameAnimation
#ifndef __WUCKeyFrameAnimation_DEFINED__
#define __WUCKeyFrameAnimation_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCKeyFrameAnimation : WUCCompositionAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property WUCAnimationStopBehavior stopBehavior;
@property int iterationCount;
@property WUCAnimationIterationBehavior iterationBehavior;
@property (retain) WFTimeSpan* duration;
@property (retain) WFTimeSpan* delayTime;
@property (readonly) int keyFrameCount;
- (void)insertExpressionKeyFrame:(float)normalizedProgressKey value:(NSString*)value;
- (void)insertExpressionKeyFrameWithEasingFunction:(float)normalizedProgressKey
                                             value:(NSString*)value
                                    easingFunction:(WUCCompositionEasingFunction*)easingFunction;
@end

#endif // __WUCKeyFrameAnimation_DEFINED__

// Windows.UI.Composition.ScalarKeyFrameAnimation
#ifndef __WUCScalarKeyFrameAnimation_DEFINED__
#define __WUCScalarKeyFrameAnimation_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCScalarKeyFrameAnimation : WUCKeyFrameAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)insertKeyFrame:(float)normalizedProgressKey value:(float)value;
- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey
                                   value:(float)value
                          easingFunction:(WUCCompositionEasingFunction*)easingFunction;
@end

#endif // __WUCScalarKeyFrameAnimation_DEFINED__

// Windows.UI.Composition.Vector2KeyFrameAnimation
#ifndef __WUCVector2KeyFrameAnimation_DEFINED__
#define __WUCVector2KeyFrameAnimation_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCVector2KeyFrameAnimation : WUCKeyFrameAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)insertKeyFrame:(float)normalizedProgressKey value:(WFNVector2*)value;
- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey
                                   value:(WFNVector2*)value
                          easingFunction:(WUCCompositionEasingFunction*)easingFunction;
@end

#endif // __WUCVector2KeyFrameAnimation_DEFINED__

// Windows.UI.Composition.Vector3KeyFrameAnimation
#ifndef __WUCVector3KeyFrameAnimation_DEFINED__
#define __WUCVector3KeyFrameAnimation_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCVector3KeyFrameAnimation : WUCKeyFrameAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)insertKeyFrame:(float)normalizedProgressKey value:(WFNVector3*)value;
- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey
                                   value:(WFNVector3*)value
                          easingFunction:(WUCCompositionEasingFunction*)easingFunction;
@end

#endif // __WUCVector3KeyFrameAnimation_DEFINED__

// Windows.UI.Composition.Vector4KeyFrameAnimation
#ifndef __WUCVector4KeyFrameAnimation_DEFINED__
#define __WUCVector4KeyFrameAnimation_DEFINED__

OBJCUWP_WINDOWS_UI_COMPOSITION_EXPORT
@interface WUCVector4KeyFrameAnimation : WUCKeyFrameAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)insertKeyFrame:(float)normalizedProgressKey value:(WFNVector4*)value;
- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey
                                   value:(WFNVector4*)value
                          easingFunction:(WUCCompositionEasingFunction*)easingFunction;
@end

#endif // __WUCVector4KeyFrameAnimation_DEFINED__
