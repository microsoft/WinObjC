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

// WindowsUIXamlMediaAnimation.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIXAMLEXPORT
#define OBJCUWPWINDOWSUIXAMLEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIXaml.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUXMAKeyTimeHelper, WUXMARepeatBehaviorHelper, WUXMATransitionCollection, WUXMADoubleKeyFrameCollection, WUXMAObjectKeyFrameCollection, WUXMATimelineCollection, WUXMADoubleKeyFrame, WUXMAEasingFunctionBase, WUXMAKeySpline, WUXMANavigationTransitionInfo, WUXMAObjectKeyFrame, WUXMATimeline, WUXMATransition, WUXMAAddDeleteThemeTransition, WUXMABackEase, WUXMABeginStoryboard, WUXMABounceEase, WUXMACircleEase, WUXMAColorAnimation, WUXMAContentThemeTransition, WUXMACubicEase, WUXMADiscreteDoubleKeyFrame, WUXMADiscreteObjectKeyFrame, WUXMADoubleAnimation, WUXMADoubleAnimationUsingKeyFrames, WUXMAEasingDoubleKeyFrame, WUXMAEdgeUIThemeTransition, WUXMAElasticEase, WUXMAEntranceThemeTransition, WUXMAExponentialEase, WUXMALinearDoubleKeyFrame, WUXMAObjectAnimationUsingKeyFrames, WUXMAPaneThemeTransition, WUXMAPointAnimation, WUXMAPopupThemeTransition, WUXMAPowerEase, WUXMAQuadraticEase, WUXMAQuarticEase, WUXMAQuinticEase, WUXMAReorderThemeTransition, WUXMARepositionThemeTransition, WUXMASineEase, WUXMASplineDoubleKeyFrame, WUXMAStoryboard, WUXMAColorKeyFrameCollection, WUXMAConnectedAnimation, WUXMAConnectedAnimationService, WUXMAPointKeyFrameCollection, WUXMAColorKeyFrame, WUXMAPointKeyFrame, WUXMAColorAnimationUsingKeyFrames, WUXMADiscreteColorKeyFrame, WUXMADiscretePointKeyFrame, WUXMADragItemThemeAnimation, WUXMADragOverThemeAnimation, WUXMADrillInThemeAnimation, WUXMADrillOutThemeAnimation, WUXMADropTargetItemThemeAnimation, WUXMAEasingColorKeyFrame, WUXMAEasingPointKeyFrame, WUXMAFadeInThemeAnimation, WUXMAFadeOutThemeAnimation, WUXMALinearColorKeyFrame, WUXMALinearPointKeyFrame, WUXMAPointAnimationUsingKeyFrames, WUXMAPointerDownThemeAnimation, WUXMAPointerUpThemeAnimation, WUXMAPopInThemeAnimation, WUXMAPopOutThemeAnimation, WUXMARepositionThemeAnimation, WUXMASplineColorKeyFrame, WUXMASplinePointKeyFrame, WUXMASplitCloseThemeAnimation, WUXMASplitOpenThemeAnimation, WUXMASwipeBackThemeAnimation, WUXMASwipeHintThemeAnimation, WUXMACommonNavigationTransitionInfo, WUXMAContinuumNavigationTransitionInfo, WUXMADrillInNavigationTransitionInfo, WUXMAEntranceNavigationTransitionInfo, WUXMANavigationThemeTransition, WUXMASlideNavigationTransitionInfo, WUXMASuppressNavigationTransitionInfo;
@class WUXMAKeyTime, WUXMARepeatBehavior;
@protocol WUXMAIKeyTimeHelper, WUXMAIKeyTimeHelperStatics, WUXMAIRepeatBehaviorHelper, WUXMAIRepeatBehaviorHelperStatics, WUXMAIDoubleKeyFrame, WUXMAIDoubleKeyFrameStatics, WUXMAIDoubleKeyFrameFactory, WUXMAIEasingFunctionBase, WUXMAIEasingFunctionBaseStatics, WUXMAIEasingFunctionBaseFactory, WUXMAIKeySpline, WUXMAINavigationTransitionInfo, WUXMAINavigationTransitionInfoOverrides, WUXMAINavigationTransitionInfoFactory, WUXMAIObjectKeyFrame, WUXMAIObjectKeyFrameStatics, WUXMAIObjectKeyFrameFactory, WUXMAITimeline, WUXMAITimelineStatics, WUXMAITimelineFactory, WUXMAITransition, WUXMAITransitionFactory, WUXMAIAddDeleteThemeTransition, WUXMAIBackEase, WUXMAIBackEaseStatics, WUXMAIBeginStoryboard, WUXMAIBeginStoryboardStatics, WUXMAIBounceEase, WUXMAIBounceEaseStatics, WUXMAICircleEase, WUXMAIColorAnimation, WUXMAIColorAnimationStatics, WUXMAIContentThemeTransition, WUXMAIContentThemeTransitionStatics, WUXMAICubicEase, WUXMAIDiscreteDoubleKeyFrame, WUXMAIDiscreteObjectKeyFrame, WUXMAIDoubleAnimation, WUXMAIDoubleAnimationStatics, WUXMAIDoubleAnimationUsingKeyFrames, WUXMAIDoubleAnimationUsingKeyFramesStatics, WUXMAIEasingDoubleKeyFrame, WUXMAIEasingDoubleKeyFrameStatics, WUXMAIEdgeUIThemeTransition, WUXMAIEdgeUIThemeTransitionStatics, WUXMAIElasticEase, WUXMAIElasticEaseStatics, WUXMAIEntranceThemeTransition, WUXMAIEntranceThemeTransitionStatics, WUXMAIExponentialEase, WUXMAIExponentialEaseStatics, WUXMAILinearDoubleKeyFrame, WUXMAIObjectAnimationUsingKeyFrames, WUXMAIObjectAnimationUsingKeyFramesStatics, WUXMAIPaneThemeTransition, WUXMAIPaneThemeTransitionStatics, WUXMAIPointAnimation, WUXMAIPointAnimationStatics, WUXMAIPopupThemeTransition, WUXMAIPopupThemeTransitionStatics, WUXMAIPowerEase, WUXMAIPowerEaseStatics, WUXMAIQuadraticEase, WUXMAIQuarticEase, WUXMAIQuinticEase, WUXMAIReorderThemeTransition, WUXMAIRepositionThemeTransition, WUXMAIRepositionThemeTransition2, WUXMAIRepositionThemeTransitionStatics2, WUXMAISineEase, WUXMAISplineDoubleKeyFrame, WUXMAISplineDoubleKeyFrameStatics, WUXMAIStoryboard, WUXMAIStoryboardStatics, WUXMAIConnectedAnimation, WUXMAIConnectedAnimation2, WUXMAIConnectedAnimationService, WUXMAIConnectedAnimationServiceStatics, WUXMAIColorKeyFrame, WUXMAIColorKeyFrameStatics, WUXMAIColorKeyFrameFactory, WUXMAIPointKeyFrame, WUXMAIPointKeyFrameStatics, WUXMAIPointKeyFrameFactory, WUXMAIColorAnimationUsingKeyFrames, WUXMAIColorAnimationUsingKeyFramesStatics, WUXMAIDiscreteColorKeyFrame, WUXMAIDiscretePointKeyFrame, WUXMAIDragItemThemeAnimation, WUXMAIDragItemThemeAnimationStatics, WUXMAIDragOverThemeAnimation, WUXMAIDragOverThemeAnimationStatics, WUXMAIDrillInThemeAnimation, WUXMAIDrillInThemeAnimationStatics, WUXMAIDrillOutThemeAnimation, WUXMAIDrillOutThemeAnimationStatics, WUXMAIDropTargetItemThemeAnimation, WUXMAIDropTargetItemThemeAnimationStatics, WUXMAIEasingColorKeyFrame, WUXMAIEasingColorKeyFrameStatics, WUXMAIEasingPointKeyFrame, WUXMAIEasingPointKeyFrameStatics, WUXMAIFadeInThemeAnimation, WUXMAIFadeInThemeAnimationStatics, WUXMAIFadeOutThemeAnimation, WUXMAIFadeOutThemeAnimationStatics, WUXMAILinearColorKeyFrame, WUXMAILinearPointKeyFrame, WUXMAIPointAnimationUsingKeyFrames, WUXMAIPointAnimationUsingKeyFramesStatics, WUXMAIPointerDownThemeAnimation, WUXMAIPointerDownThemeAnimationStatics, WUXMAIPointerUpThemeAnimation, WUXMAIPointerUpThemeAnimationStatics, WUXMAIPopInThemeAnimation, WUXMAIPopInThemeAnimationStatics, WUXMAIPopOutThemeAnimation, WUXMAIPopOutThemeAnimationStatics, WUXMAIRepositionThemeAnimation, WUXMAIRepositionThemeAnimationStatics, WUXMAISplineColorKeyFrame, WUXMAISplineColorKeyFrameStatics, WUXMAISplinePointKeyFrame, WUXMAISplinePointKeyFrameStatics, WUXMAISplitCloseThemeAnimation, WUXMAISplitCloseThemeAnimationStatics, WUXMAISplitOpenThemeAnimation, WUXMAISplitOpenThemeAnimationStatics, WUXMAISwipeBackThemeAnimation, WUXMAISwipeBackThemeAnimationStatics, WUXMAISwipeHintThemeAnimation, WUXMAISwipeHintThemeAnimationStatics, WUXMAICommonNavigationTransitionInfo, WUXMAICommonNavigationTransitionInfoStatics, WUXMAIContinuumNavigationTransitionInfo, WUXMAIContinuumNavigationTransitionInfoStatics, WUXMAIDrillInNavigationTransitionInfo, WUXMAIEntranceNavigationTransitionInfo, WUXMAIEntranceNavigationTransitionInfoStatics, WUXMAINavigationThemeTransition, WUXMAINavigationThemeTransitionStatics, WUXMAISlideNavigationTransitionInfo, WUXMAISuppressNavigationTransitionInfo;

// Windows.UI.Xaml.Media.Animation.ClockState
enum _WUXMAClockState {
    WUXMAClockStateActive = 0,
    WUXMAClockStateFilling = 1,
    WUXMAClockStateStopped = 2,
};
typedef unsigned WUXMAClockState;

// Windows.UI.Xaml.Media.Animation.EasingMode
enum _WUXMAEasingMode {
    WUXMAEasingModeEaseOut = 0,
    WUXMAEasingModeEaseIn = 1,
    WUXMAEasingModeEaseInOut = 2,
};
typedef unsigned WUXMAEasingMode;

// Windows.UI.Xaml.Media.Animation.FillBehavior
enum _WUXMAFillBehavior {
    WUXMAFillBehaviorHoldEnd = 0,
    WUXMAFillBehaviorStop = 1,
};
typedef unsigned WUXMAFillBehavior;

// Windows.UI.Xaml.Media.Animation.RepeatBehaviorType
enum _WUXMARepeatBehaviorType {
    WUXMARepeatBehaviorTypeCount = 0,
    WUXMARepeatBehaviorTypeDuration = 1,
    WUXMARepeatBehaviorTypeForever = 2,
};
typedef unsigned WUXMARepeatBehaviorType;

// Windows.UI.Xaml.Media.Animation.ConnectedAnimationComponent
enum _WUXMAConnectedAnimationComponent {
    WUXMAConnectedAnimationComponentOffsetX = 0,
    WUXMAConnectedAnimationComponentOffsetY = 1,
    WUXMAConnectedAnimationComponentCrossFade = 2,
    WUXMAConnectedAnimationComponentScale = 3,
};
typedef unsigned WUXMAConnectedAnimationComponent;

#include "WindowsUIXamlControls.h"
#include "WindowsFoundation.h"
#include "WindowsUIComposition.h"
#include "WindowsUIXaml.h"
#include "WindowsUIXamlControlsPrimitives.h"
#include "WindowsUI.h"
#include "WindowsUICore.h"
// Windows.UI.Xaml.DependencyPropertyChangedCallback
#ifndef __WXDependencyPropertyChangedCallback__DEFINED
#define __WXDependencyPropertyChangedCallback__DEFINED
typedef void(^WXDependencyPropertyChangedCallback)(WXDependencyObject* sender, WXDependencyProperty* dp);
#endif // __WXDependencyPropertyChangedCallback__DEFINED


#import <Foundation/Foundation.h>

// [struct] Windows.UI.Xaml.Media.Animation.KeyTime
OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAKeyTime : NSObject
+ (instancetype)new;
@property (retain) WFTimeSpan* timeSpan;
@end

// [struct] Windows.UI.Xaml.Media.Animation.RepeatBehavior
OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMARepeatBehavior : NSObject
+ (instancetype)new;
@property double count;
@property (retain) WFTimeSpan* duration;
@property WUXMARepeatBehaviorType type;
@end

// Windows.UI.Xaml.Media.Animation.INavigationTransitionInfoOverrides
#ifndef __WUXMAINavigationTransitionInfoOverrides_DEFINED__
#define __WUXMAINavigationTransitionInfoOverrides_DEFINED__

@protocol WUXMAINavigationTransitionInfoOverrides
- (NSString *)getNavigationStateCore;
- (void)setNavigationStateCore:(NSString *)navigationState;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAINavigationTransitionInfoOverrides : RTObject <WUXMAINavigationTransitionInfoOverrides>
@end

#endif // __WUXMAINavigationTransitionInfoOverrides_DEFINED__

// Windows.UI.Xaml.Media.Animation.KeyTimeHelper
#ifndef __WUXMAKeyTimeHelper_DEFINED__
#define __WUXMAKeyTimeHelper_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAKeyTimeHelper : RTObject
+ (WUXMAKeyTime*)fromTimeSpan:(WFTimeSpan*)timeSpan;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMAKeyTimeHelper_DEFINED__

// Windows.UI.Xaml.Media.Animation.RepeatBehaviorHelper
#ifndef __WUXMARepeatBehaviorHelper_DEFINED__
#define __WUXMARepeatBehaviorHelper_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMARepeatBehaviorHelper : RTObject
+ (WUXMARepeatBehavior*)fromCount:(double)count;
+ (WUXMARepeatBehavior*)fromDuration:(WFTimeSpan*)duration;
+ (BOOL)getHasCount:(WUXMARepeatBehavior*)target;
+ (BOOL)getHasDuration:(WUXMARepeatBehavior*)target;
+ (BOOL)equals:(WUXMARepeatBehavior*)target value:(WUXMARepeatBehavior*)value;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (WUXMARepeatBehavior*)forever;
@end

#endif // __WUXMARepeatBehaviorHelper_DEFINED__

// Windows.UI.Xaml.Media.Animation.TransitionCollection
#ifndef __WUXMATransitionCollection_DEFINED__
#define __WUXMATransitionCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMATransitionCollection : RTObject
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

#endif // __WUXMATransitionCollection_DEFINED__

// Windows.UI.Xaml.Media.Animation.DoubleKeyFrameCollection
#ifndef __WUXMADoubleKeyFrameCollection_DEFINED__
#define __WUXMADoubleKeyFrameCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMADoubleKeyFrameCollection : RTObject
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

#endif // __WUXMADoubleKeyFrameCollection_DEFINED__

// Windows.UI.Xaml.Media.Animation.ObjectKeyFrameCollection
#ifndef __WUXMAObjectKeyFrameCollection_DEFINED__
#define __WUXMAObjectKeyFrameCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAObjectKeyFrameCollection : RTObject
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

#endif // __WUXMAObjectKeyFrameCollection_DEFINED__

// Windows.UI.Xaml.Media.Animation.TimelineCollection
#ifndef __WUXMATimelineCollection_DEFINED__
#define __WUXMATimelineCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMATimelineCollection : RTObject
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

#endif // __WUXMATimelineCollection_DEFINED__

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

// Windows.UI.Xaml.Media.Animation.DoubleKeyFrame
#ifndef __WUXMADoubleKeyFrame_DEFINED__
#define __WUXMADoubleKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMADoubleKeyFrame : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double value;
@property (retain) WUXMAKeyTime* keyTime;
+ (WXDependencyProperty*)keyTimeProperty;
+ (WXDependencyProperty*)valueProperty;
@end

#endif // __WUXMADoubleKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.EasingFunctionBase
#ifndef __WUXMAEasingFunctionBase_DEFINED__
#define __WUXMAEasingFunctionBase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAEasingFunctionBase : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXMAEasingMode easingMode;
+ (WXDependencyProperty*)easingModeProperty;
- (double)ease:(double)normalizedTime;
@end

#endif // __WUXMAEasingFunctionBase_DEFINED__

// Windows.UI.Xaml.Media.Animation.KeySpline
#ifndef __WUXMAKeySpline_DEFINED__
#define __WUXMAKeySpline_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAKeySpline : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFPoint* controlPoint2;
@property (retain) WFPoint* controlPoint1;
@end

#endif // __WUXMAKeySpline_DEFINED__

// Windows.UI.Xaml.Media.Animation.NavigationTransitionInfo
#ifndef __WUXMANavigationTransitionInfo_DEFINED__
#define __WUXMANavigationTransitionInfo_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMANavigationTransitionInfo : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (NSString *)getNavigationStateCore;
- (void)setNavigationStateCore:(NSString *)navigationState;
@end

#endif // __WUXMANavigationTransitionInfo_DEFINED__

// Windows.UI.Xaml.Media.Animation.ObjectKeyFrame
#ifndef __WUXMAObjectKeyFrame_DEFINED__
#define __WUXMAObjectKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAObjectKeyFrame : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject* value;
@property (retain) WUXMAKeyTime* keyTime;
+ (WXDependencyProperty*)keyTimeProperty;
+ (WXDependencyProperty*)valueProperty;
@end

#endif // __WUXMAObjectKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.Timeline
#ifndef __WUXMATimeline_DEFINED__
#define __WUXMATimeline_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMATimeline : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double speedRatio;
@property (retain) WUXMARepeatBehavior* repeatBehavior;
@property WUXMAFillBehavior fillBehavior;
@property (retain) WXDuration* duration;
@property (retain) id /* WFTimeSpan* */ beginTime;
@property BOOL autoReverse;
+ (BOOL)allowDependentAnimations;
+ (void)setAllowDependentAnimations:(BOOL)value;
+ (WXDependencyProperty*)autoReverseProperty;
+ (WXDependencyProperty*)beginTimeProperty;
+ (WXDependencyProperty*)durationProperty;
+ (WXDependencyProperty*)fillBehaviorProperty;
+ (WXDependencyProperty*)repeatBehaviorProperty;
+ (WXDependencyProperty*)speedRatioProperty;
- (EventRegistrationToken)addCompletedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXMATimeline_DEFINED__

// Windows.UI.Xaml.Media.Animation.Transition
#ifndef __WUXMATransition_DEFINED__
#define __WUXMATransition_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMATransition : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMATransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.AddDeleteThemeTransition
#ifndef __WUXMAAddDeleteThemeTransition_DEFINED__
#define __WUXMAAddDeleteThemeTransition_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAAddDeleteThemeTransition : WUXMATransition
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMAAddDeleteThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.BackEase
#ifndef __WUXMABackEase_DEFINED__
#define __WUXMABackEase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMABackEase : WUXMAEasingFunctionBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double amplitude;
+ (WXDependencyProperty*)amplitudeProperty;
@end

#endif // __WUXMABackEase_DEFINED__

// Windows.UI.Xaml.TriggerAction
#ifndef __WXTriggerAction_DEFINED__
#define __WXTriggerAction_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXTriggerAction : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXTriggerAction_DEFINED__

// Windows.UI.Xaml.Media.Animation.BeginStoryboard
#ifndef __WUXMABeginStoryboard_DEFINED__
#define __WUXMABeginStoryboard_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMABeginStoryboard : WXTriggerAction
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMAStoryboard* storyboard;
+ (WXDependencyProperty*)storyboardProperty;
@end

#endif // __WUXMABeginStoryboard_DEFINED__

// Windows.UI.Xaml.Media.Animation.BounceEase
#ifndef __WUXMABounceEase_DEFINED__
#define __WUXMABounceEase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMABounceEase : WUXMAEasingFunctionBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double bounciness;
@property int bounces;
+ (WXDependencyProperty*)bouncesProperty;
+ (WXDependencyProperty*)bouncinessProperty;
@end

#endif // __WUXMABounceEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.CircleEase
#ifndef __WUXMACircleEase_DEFINED__
#define __WUXMACircleEase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMACircleEase : WUXMAEasingFunctionBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMACircleEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.ColorAnimation
#ifndef __WUXMAColorAnimation_DEFINED__
#define __WUXMAColorAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAColorAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* WUColor* */ to;
@property (retain) id /* WUColor* */ from;
@property BOOL enableDependentAnimation;
@property (retain) WUXMAEasingFunctionBase* easingFunction;
@property (retain) id /* WUColor* */ by;
+ (WXDependencyProperty*)byProperty;
+ (WXDependencyProperty*)easingFunctionProperty;
+ (WXDependencyProperty*)enableDependentAnimationProperty;
+ (WXDependencyProperty*)fromProperty;
+ (WXDependencyProperty*)toProperty;
@end

#endif // __WUXMAColorAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.ContentThemeTransition
#ifndef __WUXMAContentThemeTransition_DEFINED__
#define __WUXMAContentThemeTransition_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAContentThemeTransition : WUXMATransition
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double verticalOffset;
@property double horizontalOffset;
+ (WXDependencyProperty*)horizontalOffsetProperty;
+ (WXDependencyProperty*)verticalOffsetProperty;
@end

#endif // __WUXMAContentThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.CubicEase
#ifndef __WUXMACubicEase_DEFINED__
#define __WUXMACubicEase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMACubicEase : WUXMAEasingFunctionBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMACubicEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.DiscreteDoubleKeyFrame
#ifndef __WUXMADiscreteDoubleKeyFrame_DEFINED__
#define __WUXMADiscreteDoubleKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMADiscreteDoubleKeyFrame : WUXMADoubleKeyFrame
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMADiscreteDoubleKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.DiscreteObjectKeyFrame
#ifndef __WUXMADiscreteObjectKeyFrame_DEFINED__
#define __WUXMADiscreteObjectKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMADiscreteObjectKeyFrame : WUXMAObjectKeyFrame
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMADiscreteObjectKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.DoubleAnimation
#ifndef __WUXMADoubleAnimation_DEFINED__
#define __WUXMADoubleAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMADoubleAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* double */ to;
@property (retain) id /* double */ from;
@property BOOL enableDependentAnimation;
@property (retain) WUXMAEasingFunctionBase* easingFunction;
@property (retain) id /* double */ by;
+ (WXDependencyProperty*)byProperty;
+ (WXDependencyProperty*)easingFunctionProperty;
+ (WXDependencyProperty*)enableDependentAnimationProperty;
+ (WXDependencyProperty*)fromProperty;
+ (WXDependencyProperty*)toProperty;
@end

#endif // __WUXMADoubleAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.DoubleAnimationUsingKeyFrames
#ifndef __WUXMADoubleAnimationUsingKeyFrames_DEFINED__
#define __WUXMADoubleAnimationUsingKeyFrames_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMADoubleAnimationUsingKeyFrames : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL enableDependentAnimation;
@property (readonly) WUXMADoubleKeyFrameCollection* keyFrames;
+ (WXDependencyProperty*)enableDependentAnimationProperty;
@end

#endif // __WUXMADoubleAnimationUsingKeyFrames_DEFINED__

// Windows.UI.Xaml.Media.Animation.EasingDoubleKeyFrame
#ifndef __WUXMAEasingDoubleKeyFrame_DEFINED__
#define __WUXMAEasingDoubleKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAEasingDoubleKeyFrame : WUXMADoubleKeyFrame
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMAEasingFunctionBase* easingFunction;
+ (WXDependencyProperty*)easingFunctionProperty;
@end

#endif // __WUXMAEasingDoubleKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.EdgeUIThemeTransition
#ifndef __WUXMAEdgeUIThemeTransition_DEFINED__
#define __WUXMAEdgeUIThemeTransition_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAEdgeUIThemeTransition : WUXMATransition
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXCPEdgeTransitionLocation edge;
+ (WXDependencyProperty*)edgeProperty;
@end

#endif // __WUXMAEdgeUIThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.ElasticEase
#ifndef __WUXMAElasticEase_DEFINED__
#define __WUXMAElasticEase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAElasticEase : WUXMAEasingFunctionBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double springiness;
@property int oscillations;
+ (WXDependencyProperty*)oscillationsProperty;
+ (WXDependencyProperty*)springinessProperty;
@end

#endif // __WUXMAElasticEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.EntranceThemeTransition
#ifndef __WUXMAEntranceThemeTransition_DEFINED__
#define __WUXMAEntranceThemeTransition_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAEntranceThemeTransition : WUXMATransition
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isStaggeringEnabled;
@property double fromVerticalOffset;
@property double fromHorizontalOffset;
+ (WXDependencyProperty*)fromHorizontalOffsetProperty;
+ (WXDependencyProperty*)fromVerticalOffsetProperty;
+ (WXDependencyProperty*)isStaggeringEnabledProperty;
@end

#endif // __WUXMAEntranceThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.ExponentialEase
#ifndef __WUXMAExponentialEase_DEFINED__
#define __WUXMAExponentialEase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAExponentialEase : WUXMAEasingFunctionBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double exponent;
+ (WXDependencyProperty*)exponentProperty;
@end

#endif // __WUXMAExponentialEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.LinearDoubleKeyFrame
#ifndef __WUXMALinearDoubleKeyFrame_DEFINED__
#define __WUXMALinearDoubleKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMALinearDoubleKeyFrame : WUXMADoubleKeyFrame
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMALinearDoubleKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.ObjectAnimationUsingKeyFrames
#ifndef __WUXMAObjectAnimationUsingKeyFrames_DEFINED__
#define __WUXMAObjectAnimationUsingKeyFrames_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAObjectAnimationUsingKeyFrames : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL enableDependentAnimation;
@property (readonly) WUXMAObjectKeyFrameCollection* keyFrames;
+ (WXDependencyProperty*)enableDependentAnimationProperty;
@end

#endif // __WUXMAObjectAnimationUsingKeyFrames_DEFINED__

// Windows.UI.Xaml.Media.Animation.PaneThemeTransition
#ifndef __WUXMAPaneThemeTransition_DEFINED__
#define __WUXMAPaneThemeTransition_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAPaneThemeTransition : WUXMATransition
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXCPEdgeTransitionLocation edge;
+ (WXDependencyProperty*)edgeProperty;
@end

#endif // __WUXMAPaneThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.PointAnimation
#ifndef __WUXMAPointAnimation_DEFINED__
#define __WUXMAPointAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAPointAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* WFPoint* */ to;
@property (retain) id /* WFPoint* */ from;
@property BOOL enableDependentAnimation;
@property (retain) WUXMAEasingFunctionBase* easingFunction;
@property (retain) id /* WFPoint* */ by;
+ (WXDependencyProperty*)byProperty;
+ (WXDependencyProperty*)easingFunctionProperty;
+ (WXDependencyProperty*)enableDependentAnimationProperty;
+ (WXDependencyProperty*)fromProperty;
+ (WXDependencyProperty*)toProperty;
@end

#endif // __WUXMAPointAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.PopupThemeTransition
#ifndef __WUXMAPopupThemeTransition_DEFINED__
#define __WUXMAPopupThemeTransition_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAPopupThemeTransition : WUXMATransition
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double fromVerticalOffset;
@property double fromHorizontalOffset;
+ (WXDependencyProperty*)fromHorizontalOffsetProperty;
+ (WXDependencyProperty*)fromVerticalOffsetProperty;
@end

#endif // __WUXMAPopupThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.PowerEase
#ifndef __WUXMAPowerEase_DEFINED__
#define __WUXMAPowerEase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAPowerEase : WUXMAEasingFunctionBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double power;
+ (WXDependencyProperty*)powerProperty;
@end

#endif // __WUXMAPowerEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.QuadraticEase
#ifndef __WUXMAQuadraticEase_DEFINED__
#define __WUXMAQuadraticEase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAQuadraticEase : WUXMAEasingFunctionBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMAQuadraticEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.QuarticEase
#ifndef __WUXMAQuarticEase_DEFINED__
#define __WUXMAQuarticEase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAQuarticEase : WUXMAEasingFunctionBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMAQuarticEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.QuinticEase
#ifndef __WUXMAQuinticEase_DEFINED__
#define __WUXMAQuinticEase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAQuinticEase : WUXMAEasingFunctionBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMAQuinticEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.ReorderThemeTransition
#ifndef __WUXMAReorderThemeTransition_DEFINED__
#define __WUXMAReorderThemeTransition_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAReorderThemeTransition : WUXMATransition
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMAReorderThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.RepositionThemeTransition
#ifndef __WUXMARepositionThemeTransition_DEFINED__
#define __WUXMARepositionThemeTransition_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMARepositionThemeTransition : WUXMATransition
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isStaggeringEnabled;
+ (WXDependencyProperty*)isStaggeringEnabledProperty;
@end

#endif // __WUXMARepositionThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.SineEase
#ifndef __WUXMASineEase_DEFINED__
#define __WUXMASineEase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMASineEase : WUXMAEasingFunctionBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMASineEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.SplineDoubleKeyFrame
#ifndef __WUXMASplineDoubleKeyFrame_DEFINED__
#define __WUXMASplineDoubleKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMASplineDoubleKeyFrame : WUXMADoubleKeyFrame
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMAKeySpline* keySpline;
+ (WXDependencyProperty*)keySplineProperty;
@end

#endif // __WUXMASplineDoubleKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.Storyboard
#ifndef __WUXMAStoryboard_DEFINED__
#define __WUXMAStoryboard_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAStoryboard : WUXMATimeline
+ (NSString *)getTargetProperty:(WUXMATimeline*)element;
+ (void)setTargetProperty:(WUXMATimeline*)element path:(NSString *)path;
+ (NSString *)getTargetName:(WUXMATimeline*)element;
+ (void)setTargetName:(WUXMATimeline*)element name:(NSString *)name;
+ (void)setTarget:(WUXMATimeline*)timeline target:(WXDependencyObject*)target;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUXMATimelineCollection* children;
+ (WXDependencyProperty*)targetNameProperty;
+ (WXDependencyProperty*)targetPropertyProperty;
- (void)seek:(WFTimeSpan*)offset;
- (void)stop;
- (void)begin;
- (void)pause;
- (void)resume;
- (WUXMAClockState)getCurrentState;
- (WFTimeSpan*)getCurrentTime;
- (void)seekAlignedToLastTick:(WFTimeSpan*)offset;
- (void)skipToFill;
@end

#endif // __WUXMAStoryboard_DEFINED__

// Windows.UI.Xaml.Media.Animation.ColorKeyFrameCollection
#ifndef __WUXMAColorKeyFrameCollection_DEFINED__
#define __WUXMAColorKeyFrameCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAColorKeyFrameCollection : RTObject
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

#endif // __WUXMAColorKeyFrameCollection_DEFINED__

// Windows.UI.Xaml.Media.Animation.ConnectedAnimation
#ifndef __WUXMAConnectedAnimation_DEFINED__
#define __WUXMAConnectedAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAConnectedAnimation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isScaleAnimationEnabled;
- (EventRegistrationToken)addCompletedEvent:(void(^)(WUXMAConnectedAnimation*, RTObject*))del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
- (BOOL)tryStart:(WXUIElement*)destination;
- (void)cancel;
- (BOOL)tryStartWithCoordinatedElements:(WXUIElement*)destination coordinatedElements:(id<NSFastEnumeration> /* WXUIElement* */)coordinatedElements;
- (void)setAnimationComponent:(WUXMAConnectedAnimationComponent)component animation:(RTObject<WUCICompositionAnimationBase>*)animation;
@end

#endif // __WUXMAConnectedAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.ConnectedAnimationService
#ifndef __WUXMAConnectedAnimationService_DEFINED__
#define __WUXMAConnectedAnimationService_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAConnectedAnimationService : RTObject
+ (WUXMAConnectedAnimationService*)getForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUCCompositionEasingFunction* defaultEasingFunction;
@property (retain) WFTimeSpan* defaultDuration;
- (WUXMAConnectedAnimation*)prepareToAnimate:(NSString *)key source:(WXUIElement*)source;
- (WUXMAConnectedAnimation*)getAnimation:(NSString *)key;
@end

#endif // __WUXMAConnectedAnimationService_DEFINED__

// Windows.UI.Xaml.Media.Animation.PointKeyFrameCollection
#ifndef __WUXMAPointKeyFrameCollection_DEFINED__
#define __WUXMAPointKeyFrameCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAPointKeyFrameCollection : RTObject
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

#endif // __WUXMAPointKeyFrameCollection_DEFINED__

// Windows.UI.Xaml.Media.Animation.ColorKeyFrame
#ifndef __WUXMAColorKeyFrame_DEFINED__
#define __WUXMAColorKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAColorKeyFrame : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUColor* value;
@property (retain) WUXMAKeyTime* keyTime;
+ (WXDependencyProperty*)keyTimeProperty;
+ (WXDependencyProperty*)valueProperty;
@end

#endif // __WUXMAColorKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.PointKeyFrame
#ifndef __WUXMAPointKeyFrame_DEFINED__
#define __WUXMAPointKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAPointKeyFrame : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFPoint* value;
@property (retain) WUXMAKeyTime* keyTime;
+ (WXDependencyProperty*)keyTimeProperty;
+ (WXDependencyProperty*)valueProperty;
@end

#endif // __WUXMAPointKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.ColorAnimationUsingKeyFrames
#ifndef __WUXMAColorAnimationUsingKeyFrames_DEFINED__
#define __WUXMAColorAnimationUsingKeyFrames_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAColorAnimationUsingKeyFrames : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL enableDependentAnimation;
@property (readonly) WUXMAColorKeyFrameCollection* keyFrames;
+ (WXDependencyProperty*)enableDependentAnimationProperty;
@end

#endif // __WUXMAColorAnimationUsingKeyFrames_DEFINED__

// Windows.UI.Xaml.Media.Animation.DiscreteColorKeyFrame
#ifndef __WUXMADiscreteColorKeyFrame_DEFINED__
#define __WUXMADiscreteColorKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMADiscreteColorKeyFrame : WUXMAColorKeyFrame
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMADiscreteColorKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.DiscretePointKeyFrame
#ifndef __WUXMADiscretePointKeyFrame_DEFINED__
#define __WUXMADiscretePointKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMADiscretePointKeyFrame : WUXMAPointKeyFrame
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMADiscretePointKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.DragItemThemeAnimation
#ifndef __WUXMADragItemThemeAnimation_DEFINED__
#define __WUXMADragItemThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMADragItemThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * targetName;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMADragItemThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.DragOverThemeAnimation
#ifndef __WUXMADragOverThemeAnimation_DEFINED__
#define __WUXMADragOverThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMADragOverThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double toOffset;
@property (retain) NSString * targetName;
@property WUXCPAnimationDirection direction;
+ (WXDependencyProperty*)directionProperty;
+ (WXDependencyProperty*)targetNameProperty;
+ (WXDependencyProperty*)toOffsetProperty;
@end

#endif // __WUXMADragOverThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.DrillInThemeAnimation
#ifndef __WUXMADrillInThemeAnimation_DEFINED__
#define __WUXMADrillInThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMADrillInThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * exitTargetName;
@property (retain) WXDependencyObject* exitTarget;
@property (retain) NSString * entranceTargetName;
@property (retain) WXDependencyObject* entranceTarget;
+ (WXDependencyProperty*)entranceTargetNameProperty;
+ (WXDependencyProperty*)entranceTargetProperty;
+ (WXDependencyProperty*)exitTargetNameProperty;
+ (WXDependencyProperty*)exitTargetProperty;
@end

#endif // __WUXMADrillInThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.DrillOutThemeAnimation
#ifndef __WUXMADrillOutThemeAnimation_DEFINED__
#define __WUXMADrillOutThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMADrillOutThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * exitTargetName;
@property (retain) WXDependencyObject* exitTarget;
@property (retain) NSString * entranceTargetName;
@property (retain) WXDependencyObject* entranceTarget;
+ (WXDependencyProperty*)entranceTargetNameProperty;
+ (WXDependencyProperty*)entranceTargetProperty;
+ (WXDependencyProperty*)exitTargetNameProperty;
+ (WXDependencyProperty*)exitTargetProperty;
@end

#endif // __WUXMADrillOutThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.DropTargetItemThemeAnimation
#ifndef __WUXMADropTargetItemThemeAnimation_DEFINED__
#define __WUXMADropTargetItemThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMADropTargetItemThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * targetName;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMADropTargetItemThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.EasingColorKeyFrame
#ifndef __WUXMAEasingColorKeyFrame_DEFINED__
#define __WUXMAEasingColorKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAEasingColorKeyFrame : WUXMAColorKeyFrame
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMAEasingFunctionBase* easingFunction;
+ (WXDependencyProperty*)easingFunctionProperty;
@end

#endif // __WUXMAEasingColorKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.EasingPointKeyFrame
#ifndef __WUXMAEasingPointKeyFrame_DEFINED__
#define __WUXMAEasingPointKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAEasingPointKeyFrame : WUXMAPointKeyFrame
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMAEasingFunctionBase* easingFunction;
+ (WXDependencyProperty*)easingFunctionProperty;
@end

#endif // __WUXMAEasingPointKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.FadeInThemeAnimation
#ifndef __WUXMAFadeInThemeAnimation_DEFINED__
#define __WUXMAFadeInThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAFadeInThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * targetName;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMAFadeInThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.FadeOutThemeAnimation
#ifndef __WUXMAFadeOutThemeAnimation_DEFINED__
#define __WUXMAFadeOutThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAFadeOutThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * targetName;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMAFadeOutThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.LinearColorKeyFrame
#ifndef __WUXMALinearColorKeyFrame_DEFINED__
#define __WUXMALinearColorKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMALinearColorKeyFrame : WUXMAColorKeyFrame
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMALinearColorKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.LinearPointKeyFrame
#ifndef __WUXMALinearPointKeyFrame_DEFINED__
#define __WUXMALinearPointKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMALinearPointKeyFrame : WUXMAPointKeyFrame
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMALinearPointKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.PointAnimationUsingKeyFrames
#ifndef __WUXMAPointAnimationUsingKeyFrames_DEFINED__
#define __WUXMAPointAnimationUsingKeyFrames_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAPointAnimationUsingKeyFrames : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL enableDependentAnimation;
@property (readonly) WUXMAPointKeyFrameCollection* keyFrames;
+ (WXDependencyProperty*)enableDependentAnimationProperty;
@end

#endif // __WUXMAPointAnimationUsingKeyFrames_DEFINED__

// Windows.UI.Xaml.Media.Animation.PointerDownThemeAnimation
#ifndef __WUXMAPointerDownThemeAnimation_DEFINED__
#define __WUXMAPointerDownThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAPointerDownThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * targetName;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMAPointerDownThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.PointerUpThemeAnimation
#ifndef __WUXMAPointerUpThemeAnimation_DEFINED__
#define __WUXMAPointerUpThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAPointerUpThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * targetName;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMAPointerUpThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.PopInThemeAnimation
#ifndef __WUXMAPopInThemeAnimation_DEFINED__
#define __WUXMAPopInThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAPopInThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * targetName;
@property double fromVerticalOffset;
@property double fromHorizontalOffset;
+ (WXDependencyProperty*)fromHorizontalOffsetProperty;
+ (WXDependencyProperty*)fromVerticalOffsetProperty;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMAPopInThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.PopOutThemeAnimation
#ifndef __WUXMAPopOutThemeAnimation_DEFINED__
#define __WUXMAPopOutThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAPopOutThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * targetName;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMAPopOutThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.RepositionThemeAnimation
#ifndef __WUXMARepositionThemeAnimation_DEFINED__
#define __WUXMARepositionThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMARepositionThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * targetName;
@property double fromVerticalOffset;
@property double fromHorizontalOffset;
+ (WXDependencyProperty*)fromHorizontalOffsetProperty;
+ (WXDependencyProperty*)fromVerticalOffsetProperty;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMARepositionThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.SplineColorKeyFrame
#ifndef __WUXMASplineColorKeyFrame_DEFINED__
#define __WUXMASplineColorKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMASplineColorKeyFrame : WUXMAColorKeyFrame
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMAKeySpline* keySpline;
+ (WXDependencyProperty*)keySplineProperty;
@end

#endif // __WUXMASplineColorKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.SplinePointKeyFrame
#ifndef __WUXMASplinePointKeyFrame_DEFINED__
#define __WUXMASplinePointKeyFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMASplinePointKeyFrame : WUXMAPointKeyFrame
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMAKeySpline* keySpline;
+ (WXDependencyProperty*)keySplineProperty;
@end

#endif // __WUXMASplinePointKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.SplitCloseThemeAnimation
#ifndef __WUXMASplitCloseThemeAnimation_DEFINED__
#define __WUXMASplitCloseThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMASplitCloseThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXCPAnimationDirection contentTranslationDirection;
@property (retain) NSString * contentTargetName;
@property (retain) WXDependencyObject* contentTarget;
@property (retain) NSString * closedTargetName;
@property (retain) WXDependencyObject* closedTarget;
@property double closedLength;
@property (retain) NSString * openedTargetName;
@property (retain) WXDependencyObject* openedTarget;
@property double openedLength;
@property double offsetFromCenter;
@property double contentTranslationOffset;
+ (WXDependencyProperty*)closedLengthProperty;
+ (WXDependencyProperty*)closedTargetNameProperty;
+ (WXDependencyProperty*)closedTargetProperty;
+ (WXDependencyProperty*)contentTargetNameProperty;
+ (WXDependencyProperty*)contentTargetProperty;
+ (WXDependencyProperty*)contentTranslationDirectionProperty;
+ (WXDependencyProperty*)contentTranslationOffsetProperty;
+ (WXDependencyProperty*)offsetFromCenterProperty;
+ (WXDependencyProperty*)openedLengthProperty;
+ (WXDependencyProperty*)openedTargetNameProperty;
+ (WXDependencyProperty*)openedTargetProperty;
@end

#endif // __WUXMASplitCloseThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.SplitOpenThemeAnimation
#ifndef __WUXMASplitOpenThemeAnimation_DEFINED__
#define __WUXMASplitOpenThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMASplitOpenThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXCPAnimationDirection contentTranslationDirection;
@property (retain) NSString * contentTargetName;
@property (retain) WXDependencyObject* contentTarget;
@property (retain) NSString * closedTargetName;
@property (retain) WXDependencyObject* closedTarget;
@property double closedLength;
@property (retain) NSString * openedTargetName;
@property (retain) WXDependencyObject* openedTarget;
@property double openedLength;
@property double offsetFromCenter;
@property double contentTranslationOffset;
+ (WXDependencyProperty*)closedLengthProperty;
+ (WXDependencyProperty*)closedTargetNameProperty;
+ (WXDependencyProperty*)closedTargetProperty;
+ (WXDependencyProperty*)contentTargetNameProperty;
+ (WXDependencyProperty*)contentTargetProperty;
+ (WXDependencyProperty*)contentTranslationDirectionProperty;
+ (WXDependencyProperty*)contentTranslationOffsetProperty;
+ (WXDependencyProperty*)offsetFromCenterProperty;
+ (WXDependencyProperty*)openedLengthProperty;
+ (WXDependencyProperty*)openedTargetNameProperty;
+ (WXDependencyProperty*)openedTargetProperty;
@end

#endif // __WUXMASplitOpenThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.SwipeBackThemeAnimation
#ifndef __WUXMASwipeBackThemeAnimation_DEFINED__
#define __WUXMASwipeBackThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMASwipeBackThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * targetName;
@property double fromVerticalOffset;
@property double fromHorizontalOffset;
+ (WXDependencyProperty*)fromHorizontalOffsetProperty;
+ (WXDependencyProperty*)fromVerticalOffsetProperty;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMASwipeBackThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.SwipeHintThemeAnimation
#ifndef __WUXMASwipeHintThemeAnimation_DEFINED__
#define __WUXMASwipeHintThemeAnimation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMASwipeHintThemeAnimation : WUXMATimeline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double toVerticalOffset;
@property double toHorizontalOffset;
@property (retain) NSString * targetName;
+ (WXDependencyProperty*)targetNameProperty;
+ (WXDependencyProperty*)toHorizontalOffsetProperty;
+ (WXDependencyProperty*)toVerticalOffsetProperty;
@end

#endif // __WUXMASwipeHintThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.CommonNavigationTransitionInfo
#ifndef __WUXMACommonNavigationTransitionInfo_DEFINED__
#define __WUXMACommonNavigationTransitionInfo_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMACommonNavigationTransitionInfo : WUXMANavigationTransitionInfo
+ (BOOL)getIsStaggerElement:(WXUIElement*)element;
+ (void)setIsStaggerElement:(WXUIElement*)element value:(BOOL)value;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isStaggeringEnabled;
+ (WXDependencyProperty*)isStaggerElementProperty;
+ (WXDependencyProperty*)isStaggeringEnabledProperty;
@end

#endif // __WUXMACommonNavigationTransitionInfo_DEFINED__

// Windows.UI.Xaml.Media.Animation.ContinuumNavigationTransitionInfo
#ifndef __WUXMAContinuumNavigationTransitionInfo_DEFINED__
#define __WUXMAContinuumNavigationTransitionInfo_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAContinuumNavigationTransitionInfo : WUXMANavigationTransitionInfo
+ (BOOL)getIsEntranceElement:(WXUIElement*)element;
+ (void)setIsEntranceElement:(WXUIElement*)element value:(BOOL)value;
+ (BOOL)getIsExitElement:(WXUIElement*)element;
+ (void)setIsExitElement:(WXUIElement*)element value:(BOOL)value;
+ (BOOL)getExitElementContainer:(WXCListViewBase*)element;
+ (void)setExitElementContainer:(WXCListViewBase*)element value:(BOOL)value;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXUIElement* exitElement;
+ (WXDependencyProperty*)exitElementContainerProperty;
+ (WXDependencyProperty*)exitElementProperty;
+ (WXDependencyProperty*)isEntranceElementProperty;
+ (WXDependencyProperty*)isExitElementProperty;
@end

#endif // __WUXMAContinuumNavigationTransitionInfo_DEFINED__

// Windows.UI.Xaml.Media.Animation.DrillInNavigationTransitionInfo
#ifndef __WUXMADrillInNavigationTransitionInfo_DEFINED__
#define __WUXMADrillInNavigationTransitionInfo_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMADrillInNavigationTransitionInfo : WUXMANavigationTransitionInfo
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMADrillInNavigationTransitionInfo_DEFINED__

// Windows.UI.Xaml.Media.Animation.EntranceNavigationTransitionInfo
#ifndef __WUXMAEntranceNavigationTransitionInfo_DEFINED__
#define __WUXMAEntranceNavigationTransitionInfo_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMAEntranceNavigationTransitionInfo : WUXMANavigationTransitionInfo
+ (BOOL)getIsTargetElement:(WXUIElement*)element;
+ (void)setIsTargetElement:(WXUIElement*)element value:(BOOL)value;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (WXDependencyProperty*)isTargetElementProperty;
@end

#endif // __WUXMAEntranceNavigationTransitionInfo_DEFINED__

// Windows.UI.Xaml.Media.Animation.NavigationThemeTransition
#ifndef __WUXMANavigationThemeTransition_DEFINED__
#define __WUXMANavigationThemeTransition_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMANavigationThemeTransition : WUXMATransition
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMANavigationTransitionInfo* defaultNavigationTransitionInfo;
+ (WXDependencyProperty*)defaultNavigationTransitionInfoProperty;
@end

#endif // __WUXMANavigationThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.SlideNavigationTransitionInfo
#ifndef __WUXMASlideNavigationTransitionInfo_DEFINED__
#define __WUXMASlideNavigationTransitionInfo_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMASlideNavigationTransitionInfo : WUXMANavigationTransitionInfo
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMASlideNavigationTransitionInfo_DEFINED__

// Windows.UI.Xaml.Media.Animation.SuppressNavigationTransitionInfo
#ifndef __WUXMASuppressNavigationTransitionInfo_DEFINED__
#define __WUXMASuppressNavigationTransitionInfo_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMASuppressNavigationTransitionInfo : WUXMANavigationTransitionInfo
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMASuppressNavigationTransitionInfo_DEFINED__

