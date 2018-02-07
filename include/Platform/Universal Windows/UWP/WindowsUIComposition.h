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

@class WUCCompositionObject, WUCInitialValueExpressionCollection, WUCCompositionCapabilities, WUCCompositionColorGradientStop, WUCCompositionBatchCompletedEventArgs, WUCCompositionEasingFunction, WUCCompositionBrush, WUCCompositionEffectBrush, WUCCompositionEffectSourceParameter, WUCCompositionColorGradientStopCollection, WUCCompositionGraphicsDevice, WUCCompositor, WUCCompositionPropertySet, WUCCompositionDrawingSurface, WUCCompositionVirtualDrawingSurface, WUCCompositionColorBrush, WUCCompositionEffectFactory, WUCCompositionScopedBatch, WUCCompositionSurfaceBrush, WUCCompositionTarget, WUCCompositionCommitBatch, WUCCompositionAnimationGroup, WUCCompositionBackdropBrush, WUCCompositionMaskBrush, WUCCompositionNineGridBrush, WUCCubicBezierEasingFunction, WUCImplicitAnimationCollection, WUCCompositionShadow, WUCDropShadow, WUCLinearEasingFunction, WUCRenderingDeviceReplacedEventArgs, WUCStepEasingFunction, WUCCompositionClip, WUCInsetClip, WUCVisualCollection, WUCVisualUnorderedCollection, WUCCompositionAnimation, WUCExpressionAnimation, WUCVisual, WUCContainerVisual, WUCSpriteVisual, WUCLayerVisual, WUCCompositionGradientBrush, WUCCompositionLinearGradientBrush, WUCCompositionLight, WUCAmbientLight, WUCDistantLight, WUCPointLight, WUCSpotLight, WUCKeyFrameAnimation, WUCColorKeyFrameAnimation, WUCQuaternionKeyFrameAnimation, WUCScalarKeyFrameAnimation, WUCVector2KeyFrameAnimation, WUCVector3KeyFrameAnimation, WUCVector4KeyFrameAnimation, WUCNaturalMotionAnimation, WUCScalarNaturalMotionAnimation, WUCSpringScalarNaturalMotionAnimation, WUCVector2NaturalMotionAnimation, WUCSpringVector2NaturalMotionAnimation, WUCVector3NaturalMotionAnimation, WUCSpringVector3NaturalMotionAnimation;
@protocol WUCIAmbientLight, WUCIAmbientLight2, WUCIColorKeyFrameAnimation, WUCICompositionAnimation, WUCICompositionAnimation2, WUCICompositionAnimation3, WUCICompositionAnimationBase, WUCICompositionAnimationGroup, WUCICompositionBackdropBrush, WUCICompositionBatchCompletedEventArgs, WUCICompositionBrush, WUCICompositionCapabilities, WUCICompositionCapabilitiesStatics, WUCICompositionClip, WUCICompositionClip2, WUCICompositionColorBrush, WUCICompositionColorGradientStop, WUCICompositionColorGradientStopCollection, WUCICompositionCommitBatch, WUCICompositionDrawingSurface, WUCICompositionDrawingSurface2, WUCICompositionEasingFunction, WUCICompositionEffectBrush, WUCICompositionEffectFactory, WUCICompositionEffectSourceParameter, WUCICompositionEffectSourceParameterFactory, WUCICompositionGradientBrush, WUCICompositionGraphicsDevice, WUCICompositionGraphicsDevice2, WUCICompositionLight, WUCICompositionLight2, WUCICompositionLinearGradientBrush, WUCICompositionMaskBrush, WUCICompositionNineGridBrush, WUCICompositionObject, WUCICompositionObject2, WUCICompositionObject3, WUCICompositionPropertySet, WUCICompositionPropertySet2, WUCICompositionScopedBatch, WUCICompositionShadow, WUCICompositionSurface, WUCICompositionSurfaceBrush, WUCICompositionSurfaceBrush2, WUCICompositionTarget, WUCICompositionVirtualDrawingSurface, WUCICompositor, WUCICompositor2, WUCICompositor3, WUCICompositor4, WUCIContainerVisual, WUCICubicBezierEasingFunction, WUCIDistantLight, WUCIDistantLight2, WUCIDropShadow, WUCIDropShadow2, WUCIExpressionAnimation, WUCIImplicitAnimationCollection, WUCIInsetClip, WUCIKeyFrameAnimation, WUCIKeyFrameAnimation2, WUCIKeyFrameAnimation3, WUCILayerVisual, WUCILayerVisual2, WUCILinearEasingFunction, WUCINaturalMotionAnimation, WUCIPointLight, WUCIPointLight2, WUCIQuaternionKeyFrameAnimation, WUCIRenderingDeviceReplacedEventArgs, WUCIScalarKeyFrameAnimation, WUCIScalarNaturalMotionAnimation, WUCISpotLight, WUCISpotLight2, WUCISpringScalarNaturalMotionAnimation, WUCISpringVector2NaturalMotionAnimation, WUCISpringVector3NaturalMotionAnimation, WUCISpriteVisual, WUCISpriteVisual2, WUCIStepEasingFunction, WUCIVector2KeyFrameAnimation, WUCIVector2NaturalMotionAnimation, WUCIVector3NaturalMotionAnimation, WUCIVector3KeyFrameAnimation, WUCIVector4KeyFrameAnimation, WUCIVisual, WUCIVisual2, WUCIVisualCollection, WUCIVisualUnorderedCollection, WUCICompositionAnimationFactory, WUCICompositionBrushFactory, WUCICompositionClipFactory, WUCICompositionGradientBrushFactory, WUCICompositionDrawingSurfaceFactory, WUCICompositionEasingFunctionFactory, WUCICompositionLightFactory, WUCICompositionObjectFactory, WUCICompositionShadowFactory, WUCICompositionTargetFactory, WUCICompositionVirtualDrawingSurfaceFactory, WUCIContainerVisualFactory, WUCIKeyFrameAnimationFactory, WUCINaturalMotionAnimationFactory, WUCIScalarNaturalMotionAnimationFactory, WUCIVector2NaturalMotionAnimationFactory, WUCIVector3NaturalMotionAnimationFactory, WUCIVisualFactory;

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

// Windows.UI.Composition.AnimationDelayBehavior
enum _WUCAnimationDelayBehavior {
    WUCAnimationDelayBehaviorSetInitialValueAfterDelay = 0,
    WUCAnimationDelayBehaviorSetInitialValueBeforeDelay = 1,
};
typedef unsigned WUCAnimationDelayBehavior;

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
    WUCCompositionColorSpaceHslLinear = 3,
    WUCCompositionColorSpaceRgbLinear = 4,
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

// Windows.UI.Composition.CompositionDropShadowSourcePolicy
enum _WUCCompositionDropShadowSourcePolicy {
    WUCCompositionDropShadowSourcePolicyDefault = 0,
    WUCCompositionDropShadowSourcePolicyInheritFromVisualContent = 1,
};
typedef unsigned WUCCompositionDropShadowSourcePolicy;

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

// Windows.UI.Composition.CompositionGradientExtendMode
enum _WUCCompositionGradientExtendMode {
    WUCCompositionGradientExtendModeClamp = 0,
    WUCCompositionGradientExtendModeWrap = 1,
    WUCCompositionGradientExtendModeMirror = 2,
};
typedef unsigned WUCCompositionGradientExtendMode;

// Windows.UI.Composition.CompositionStretch
enum _WUCCompositionStretch {
    WUCCompositionStretchNone = 0,
    WUCCompositionStretchFill = 1,
    WUCCompositionStretchUniform = 2,
    WUCCompositionStretchUniformToFill = 3,
};
typedef unsigned WUCCompositionStretch;

#include "WindowsUI.h"
#include "WindowsSystem.h"
#include "WindowsGraphics.h"
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
@property (readonly) WSDispatcherQueue* dispatcherQueue;
- (void)startAnimation:(NSString *)propertyName animation:(WUCCompositionAnimation*)animation;
- (void)stopAnimation:(NSString *)propertyName;
- (void)close;
- (void)startAnimationGroup:(RTObject<WUCICompositionAnimationBase>*)value;
- (void)stopAnimationGroup:(RTObject<WUCICompositionAnimationBase>*)value;
@end

#endif // __WUCCompositionObject_DEFINED__

// Windows.UI.Composition.InitialValueExpressionCollection
#ifndef __WUCInitialValueExpressionCollection_DEFINED__
#define __WUCInitialValueExpressionCollection_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCInitialValueExpressionCollection : WUCCompositionObject
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

#endif // __WUCInitialValueExpressionCollection_DEFINED__

// Windows.UI.Composition.CompositionCapabilities
#ifndef __WUCCompositionCapabilities_DEFINED__
#define __WUCCompositionCapabilities_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionCapabilities : RTObject
+ (WUCCompositionCapabilities*)getForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addChangedEvent:(void(^)(WUCCompositionCapabilities*, RTObject*))del;
- (void)removeChangedEvent:(EventRegistrationToken)tok;
- (BOOL)areEffectsSupported;
- (BOOL)areEffectsFast;
@end

#endif // __WUCCompositionCapabilities_DEFINED__

// Windows.UI.Composition.CompositionColorGradientStop
#ifndef __WUCCompositionColorGradientStop_DEFINED__
#define __WUCCompositionColorGradientStop_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionColorGradientStop : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property float offset;
@property (retain) WUColor* color;
@end

#endif // __WUCCompositionColorGradientStop_DEFINED__

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

// Windows.UI.Composition.CompositionColorGradientStopCollection
#ifndef __WUCCompositionColorGradientStopCollection_DEFINED__
#define __WUCCompositionColorGradientStopCollection_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionColorGradientStopCollection : RTObject
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

#endif // __WUCCompositionColorGradientStopCollection_DEFINED__

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
- (WUCCompositionDrawingSurface*)createDrawingSurface2:(WGSizeInt32*)sizePixels pixelFormat:(WGDDirectXPixelFormat)pixelFormat alphaMode:(WGDDirectXAlphaMode)alphaMode;
- (WUCCompositionVirtualDrawingSurface*)createVirtualDrawingSurface:(WGSizeInt32*)sizePixels pixelFormat:(WGDDirectXPixelFormat)pixelFormat alphaMode:(WGDDirectXAlphaMode)alphaMode;
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
- (WUCCompositionBackdropBrush*)createHostBackdropBrush;
- (WUCCompositionColorGradientStop*)createColorGradientStop;
- (WUCCompositionColorGradientStop*)createColorGradientStopWithOffsetAndColor:(float)offset color:(WUColor*)color;
- (WUCCompositionLinearGradientBrush*)createLinearGradientBrush;
- (WUCSpringScalarNaturalMotionAnimation*)createSpringScalarAnimation;
- (WUCSpringVector2NaturalMotionAnimation*)createSpringVector2Animation;
- (WUCSpringVector3NaturalMotionAnimation*)createSpringVector3Animation;
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
@property (readonly) WGSizeInt32* sizeInt32;
- (void)resize:(WGSizeInt32*)sizePixels;
- (void)scroll:(WGPointInt32*)offset;
- (void)scrollRect:(WGPointInt32*)offset scrollRect:(WGRectInt32*)scrollRect;
- (void)scrollWithClip:(WGPointInt32*)offset clipRect:(WGRectInt32*)clipRect;
- (void)scrollRectWithClip:(WGPointInt32*)offset clipRect:(WGRectInt32*)clipRect scrollRect:(WGRectInt32*)scrollRect;
@end

#endif // __WUCCompositionDrawingSurface_DEFINED__

// Windows.UI.Composition.CompositionVirtualDrawingSurface
#ifndef __WUCCompositionVirtualDrawingSurface_DEFINED__
#define __WUCCompositionVirtualDrawingSurface_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionVirtualDrawingSurface : WUCCompositionDrawingSurface
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)trim:(NSArray* /* WGRectInt32* */)rects;
@end

#endif // __WUCCompositionVirtualDrawingSurface_DEFINED__

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
@property WUCCompositionDropShadowSourcePolicy sourcePolicy;
@end

#endif // __WUCDropShadow_DEFINED__

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

// Windows.UI.Composition.CompositionAnimation
#ifndef __WUCCompositionAnimation_DEFINED__
#define __WUCCompositionAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionAnimation : WUCCompositionObject <WUCICompositionAnimationBase>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * target;
@property (readonly) WUCInitialValueExpressionCollection* initialValueExpressions;
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

// Windows.UI.Composition.Visual
#ifndef __WUCVisual_DEFINED__
#define __WUCVisual_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCVisual : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFNQuaternion* orientation;
@property float opacity;
@property BOOL isVisible;
@property WUCCompositionCompositeMode compositeMode;
@property (retain) WFNVector3* centerPoint;
@property WUCCompositionBorderMode borderMode;
@property (retain) WFNVector3* offset;
@property WUCCompositionBackfaceVisibility backfaceVisibility;
@property (retain) WFNVector2* anchorPoint;
@property (retain) WUCCompositionClip* clip;
@property (retain) WFNMatrix4x4* transformMatrix;
@property (retain) WFNVector2* size;
@property (retain) WFNVector3* scale;
@property (retain) WFNVector3* rotationAxis;
@property float rotationAngleInDegrees;
@property float rotationAngle;
@property (readonly) WUCContainerVisual* parent;
@property (retain) WFNVector3* relativeOffsetAdjustment;
@property (retain) WUCVisual* parentForTransform;
@property (retain) WFNVector2* relativeSizeAdjustment;
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
@property (retain) WUCCompositionShadow* shadow;
@end

#endif // __WUCLayerVisual_DEFINED__

// Windows.UI.Composition.CompositionGradientBrush
#ifndef __WUCCompositionGradientBrush_DEFINED__
#define __WUCCompositionGradientBrush_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionGradientBrush : WUCCompositionBrush
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFNMatrix3x2* transformMatrix;
@property (retain) WFNVector2* scale;
@property float rotationAngleInDegrees;
@property float rotationAngle;
@property (retain) WFNVector2* offset;
@property WUCCompositionColorSpace interpolationSpace;
@property WUCCompositionGradientExtendMode extendMode;
@property (retain) WFNVector2* centerPoint;
@property (retain) WFNVector2* anchorPoint;
@property (readonly) WUCCompositionColorGradientStopCollection* colorStops;
@end

#endif // __WUCCompositionGradientBrush_DEFINED__

// Windows.UI.Composition.CompositionLinearGradientBrush
#ifndef __WUCCompositionLinearGradientBrush_DEFINED__
#define __WUCCompositionLinearGradientBrush_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionLinearGradientBrush : WUCCompositionGradientBrush
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFNVector2* startPoint;
@property (retain) WFNVector2* endPoint;
@end

#endif // __WUCCompositionLinearGradientBrush_DEFINED__

// Windows.UI.Composition.CompositionLight
#ifndef __WUCCompositionLight_DEFINED__
#define __WUCCompositionLight_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCCompositionLight : WUCCompositionObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUCVisualUnorderedCollection* targets;
@property (readonly) WUCVisualUnorderedCollection* exclusionsFromTargets;
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
@property float intensity;
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
@property float intensity;
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
@property float intensity;
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
@property float linearAttenuation;
@property (retain) WUColor* innerConeColor;
@property float outerConeAngle;
@property float innerConeAngleInDegrees;
@property float innerConeAngle;
@property (retain) WFNVector3* direction;
@property float constantAttenuation;
@property (retain) WUCVisual* coordinateSpace;
@property float quadraticAttenuation;
@property (retain) WUColor* outerConeColor;
@property float outerConeAngleInDegrees;
@property (retain) WFNVector3* offset;
@property float innerConeIntensity;
@property float outerConeIntensity;
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
@property WUCAnimationDelayBehavior delayBehavior;
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

// Windows.UI.Composition.NaturalMotionAnimation
#ifndef __WUCNaturalMotionAnimation_DEFINED__
#define __WUCNaturalMotionAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCNaturalMotionAnimation : WUCCompositionAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUCAnimationStopBehavior stopBehavior;
@property (retain) WFTimeSpan* delayTime;
@property WUCAnimationDelayBehavior delayBehavior;
@end

#endif // __WUCNaturalMotionAnimation_DEFINED__

// Windows.UI.Composition.ScalarNaturalMotionAnimation
#ifndef __WUCScalarNaturalMotionAnimation_DEFINED__
#define __WUCScalarNaturalMotionAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCScalarNaturalMotionAnimation : WUCNaturalMotionAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property float initialVelocity;
@property (retain) id /* float */ initialValue;
@property (retain) id /* float */ finalValue;
@end

#endif // __WUCScalarNaturalMotionAnimation_DEFINED__

// Windows.UI.Composition.SpringScalarNaturalMotionAnimation
#ifndef __WUCSpringScalarNaturalMotionAnimation_DEFINED__
#define __WUCSpringScalarNaturalMotionAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCSpringScalarNaturalMotionAnimation : WUCScalarNaturalMotionAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* period;
@property float dampingRatio;
@end

#endif // __WUCSpringScalarNaturalMotionAnimation_DEFINED__

// Windows.UI.Composition.Vector2NaturalMotionAnimation
#ifndef __WUCVector2NaturalMotionAnimation_DEFINED__
#define __WUCVector2NaturalMotionAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCVector2NaturalMotionAnimation : WUCNaturalMotionAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFNVector2* initialVelocity;
@property (retain) id /* WFNVector2* */ initialValue;
@property (retain) id /* WFNVector2* */ finalValue;
@end

#endif // __WUCVector2NaturalMotionAnimation_DEFINED__

// Windows.UI.Composition.SpringVector2NaturalMotionAnimation
#ifndef __WUCSpringVector2NaturalMotionAnimation_DEFINED__
#define __WUCSpringVector2NaturalMotionAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCSpringVector2NaturalMotionAnimation : WUCVector2NaturalMotionAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* period;
@property float dampingRatio;
@end

#endif // __WUCSpringVector2NaturalMotionAnimation_DEFINED__

// Windows.UI.Composition.Vector3NaturalMotionAnimation
#ifndef __WUCVector3NaturalMotionAnimation_DEFINED__
#define __WUCVector3NaturalMotionAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCVector3NaturalMotionAnimation : WUCNaturalMotionAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFNVector3* initialVelocity;
@property (retain) id /* WFNVector3* */ initialValue;
@property (retain) id /* WFNVector3* */ finalValue;
@end

#endif // __WUCVector3NaturalMotionAnimation_DEFINED__

// Windows.UI.Composition.SpringVector3NaturalMotionAnimation
#ifndef __WUCSpringVector3NaturalMotionAnimation_DEFINED__
#define __WUCSpringVector3NaturalMotionAnimation_DEFINED__

OBJCUWPWINDOWSUICOMPOSITIONEXPORT
@interface WUCSpringVector3NaturalMotionAnimation : WUCVector3NaturalMotionAnimation
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* period;
@property float dampingRatio;
@end

#endif // __WUCSpringVector3NaturalMotionAnimation_DEFINED__

