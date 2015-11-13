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

// WindowsUIXamlMediaAnimation.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUXMAKeyTimeHelper, WUXMARepeatBehaviorHelper, WUXMATransitionCollection, WUXMABeginStoryboard, WUXMAColorKeyFrameCollection,
    WUXMAColorKeyFrame, WUXMADiscreteColorKeyFrame, WUXMADoubleKeyFrameCollection, WUXMADoubleKeyFrame, WUXMADiscreteDoubleKeyFrame,
    WUXMAEasingColorKeyFrame, WUXMAEasingDoubleKeyFrame, WUXMAEasingFunctionBase, WUXMABackEase, WUXMABounceEase, WUXMACircleEase,
    WUXMACubicEase, WUXMAElasticEase, WUXMAExponentialEase, WUXMAKeySpline, WUXMALinearColorKeyFrame, WUXMALinearDoubleKeyFrame,
    WUXMANavigationTransitionInfo, WUXMAObjectKeyFrameCollection, WUXMAObjectKeyFrame, WUXMADiscreteObjectKeyFrame,
    WUXMAPointKeyFrameCollection, WUXMAPointKeyFrame, WUXMADiscretePointKeyFrame, WUXMAEasingPointKeyFrame, WUXMALinearPointKeyFrame,
    WUXMAPowerEase, WUXMAQuadraticEase, WUXMAQuarticEase, WUXMAQuinticEase, WUXMASineEase, WUXMASplineColorKeyFrame,
    WUXMASplineDoubleKeyFrame, WUXMASplinePointKeyFrame, WUXMATimelineCollection, WUXMATimeline, WUXMAStoryboard, WUXMAColorAnimation,
    WUXMAColorAnimationUsingKeyFrames, WUXMADoubleAnimation, WUXMADoubleAnimationUsingKeyFrames, WUXMADragItemThemeAnimation,
    WUXMADragOverThemeAnimation, WUXMADropTargetItemThemeAnimation, WUXMAFadeInThemeAnimation, WUXMAFadeOutThemeAnimation,
    WUXMAObjectAnimationUsingKeyFrames, WUXMAPointAnimation, WUXMAPointAnimationUsingKeyFrames, WUXMAPointerDownThemeAnimation,
    WUXMAPointerUpThemeAnimation, WUXMAPopInThemeAnimation, WUXMAPopOutThemeAnimation, WUXMARepositionThemeAnimation,
    WUXMASplitCloseThemeAnimation, WUXMASplitOpenThemeAnimation, WUXMASwipeBackThemeAnimation, WUXMASwipeHintThemeAnimation,
    WUXMATransition, WUXMAAddDeleteThemeTransition, WUXMAContentThemeTransition, WUXMAEdgeUIThemeTransition, WUXMAEntranceThemeTransition,
    WUXMAPaneThemeTransition, WUXMAPopupThemeTransition, WUXMAReorderThemeTransition, WUXMARepositionThemeTransition;
@class WUXMAKeyTime, WUXMARepeatBehavior;
@protocol WUXMAIKeyTimeHelper
, WUXMAIKeyTimeHelperStatics, WUXMAIRepeatBehaviorHelper, WUXMAIRepeatBehaviorHelperStatics, WUXMAIAddDeleteThemeTransition, WUXMAIBackEase,
    WUXMAIBackEaseStatics, WUXMAIBeginStoryboard, WUXMAIBeginStoryboardStatics, WUXMAIBounceEase, WUXMAIBounceEaseStatics, WUXMAICircleEase,
    WUXMAIColorAnimation, WUXMAIColorAnimationStatics, WUXMAIColorAnimationUsingKeyFrames, WUXMAIColorAnimationUsingKeyFramesStatics,
    WUXMAIColorKeyFrame, WUXMAIColorKeyFrameStatics, WUXMAIColorKeyFrameFactory, WUXMAIContentThemeTransition,
    WUXMAIContentThemeTransitionStatics, WUXMAICubicEase, WUXMAIDiscreteColorKeyFrame, WUXMAIDiscreteDoubleKeyFrame,
    WUXMAIDiscreteObjectKeyFrame, WUXMAIDiscretePointKeyFrame, WUXMAIDoubleAnimation, WUXMAIDoubleAnimationStatics,
    WUXMAIDoubleAnimationUsingKeyFrames, WUXMAIDoubleAnimationUsingKeyFramesStatics, WUXMAIDoubleKeyFrame, WUXMAIDoubleKeyFrameStatics,
    WUXMAIDoubleKeyFrameFactory, WUXMAIDragItemThemeAnimation, WUXMAIDragItemThemeAnimationStatics, WUXMAIDragOverThemeAnimation,
    WUXMAIDragOverThemeAnimationStatics, WUXMAIDropTargetItemThemeAnimation, WUXMAIDropTargetItemThemeAnimationStatics,
    WUXMAIEasingColorKeyFrame, WUXMAIEasingColorKeyFrameStatics, WUXMAIEasingDoubleKeyFrame, WUXMAIEasingDoubleKeyFrameStatics,
    WUXMAIEasingFunctionBase, WUXMAIEasingFunctionBaseStatics, WUXMAIEasingFunctionBaseFactory, WUXMAIEasingPointKeyFrame,
    WUXMAIEasingPointKeyFrameStatics, WUXMAIEdgeUIThemeTransition, WUXMAIEdgeUIThemeTransitionStatics, WUXMAIElasticEase,
    WUXMAIElasticEaseStatics, WUXMAIEntranceThemeTransition, WUXMAIEntranceThemeTransitionStatics, WUXMAIExponentialEase,
    WUXMAIExponentialEaseStatics, WUXMAIFadeInThemeAnimation, WUXMAIFadeInThemeAnimationStatics, WUXMAIFadeOutThemeAnimation,
    WUXMAIFadeOutThemeAnimationStatics, WUXMAIKeySpline, WUXMAILinearColorKeyFrame, WUXMAILinearDoubleKeyFrame, WUXMAILinearPointKeyFrame,
    WUXMAINavigationTransitionInfo, WUXMAINavigationTransitionInfoOverrides, WUXMAINavigationTransitionInfoFactory,
    WUXMAIObjectAnimationUsingKeyFrames, WUXMAIObjectAnimationUsingKeyFramesStatics, WUXMAIObjectKeyFrame, WUXMAIObjectKeyFrameStatics,
    WUXMAIObjectKeyFrameFactory, WUXMAIPaneThemeTransition, WUXMAIPaneThemeTransitionStatics, WUXMAIPointAnimation,
    WUXMAIPointAnimationStatics, WUXMAIPointAnimationUsingKeyFrames, WUXMAIPointAnimationUsingKeyFramesStatics,
    WUXMAIPointerDownThemeAnimation, WUXMAIPointerDownThemeAnimationStatics, WUXMAIPointerUpThemeAnimation,
    WUXMAIPointerUpThemeAnimationStatics, WUXMAIPointKeyFrame, WUXMAIPointKeyFrameStatics, WUXMAIPointKeyFrameFactory,
    WUXMAIPopInThemeAnimation, WUXMAIPopInThemeAnimationStatics, WUXMAIPopOutThemeAnimation, WUXMAIPopOutThemeAnimationStatics,
    WUXMAIPopupThemeTransition, WUXMAIPopupThemeTransitionStatics, WUXMAIPowerEase, WUXMAIPowerEaseStatics, WUXMAIQuadraticEase,
    WUXMAIQuarticEase, WUXMAIQuinticEase, WUXMAIReorderThemeTransition, WUXMAIRepositionThemeAnimation,
    WUXMAIRepositionThemeAnimationStatics, WUXMAIRepositionThemeTransition, WUXMAISineEase, WUXMAISplineColorKeyFrame,
    WUXMAISplineColorKeyFrameStatics, WUXMAISplineDoubleKeyFrame, WUXMAISplineDoubleKeyFrameStatics, WUXMAISplinePointKeyFrame,
    WUXMAISplinePointKeyFrameStatics, WUXMAISplitCloseThemeAnimation, WUXMAISplitCloseThemeAnimationStatics, WUXMAISplitOpenThemeAnimation,
    WUXMAISplitOpenThemeAnimationStatics, WUXMAIStoryboard, WUXMAIStoryboardStatics, WUXMAISwipeBackThemeAnimation,
    WUXMAISwipeBackThemeAnimationStatics, WUXMAISwipeHintThemeAnimation, WUXMAISwipeHintThemeAnimationStatics, WUXMAITimeline,
    WUXMAITimelineStatics, WUXMAITimelineFactory, WUXMAITransition, WUXMAITransitionFactory;

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

#include "WindowsFoundation.h"
#include "WindowsUIXaml.h"
#include "WindowsUIXamlControlsPrimitives.h"
#include "WindowsUI.h"
#include "WindowsUICore.h"

// [struct] Windows.UI.Xaml.Media.Animation.KeyTime
WINRT_EXPORT
@interface WUXMAKeyTime : NSObject
+ (instancetype) new;
@property (copy) WFTimeSpan* timeSpan;
@end

// [struct] Windows.UI.Xaml.Media.Animation.RepeatBehavior
WINRT_EXPORT
@interface WUXMARepeatBehavior : NSObject
+ (instancetype) new;
@property double count;
@property (copy) WFTimeSpan* duration;
@property WUXMARepeatBehaviorType type;
@end

// Windows.UI.Xaml.Media.Animation.KeyTimeHelper
#ifndef __WUXMAKeyTimeHelper_DEFINED__
#define __WUXMAKeyTimeHelper_DEFINED__

WINRT_EXPORT
@interface WUXMAKeyTimeHelper : RTObject
+ (WUXMAKeyTime*)fromTimeSpan:(WFTimeSpan*)timeSpan;
@end

#endif // __WUXMAKeyTimeHelper_DEFINED__

// Windows.UI.Xaml.Media.Animation.RepeatBehaviorHelper
#ifndef __WUXMARepeatBehaviorHelper_DEFINED__
#define __WUXMARepeatBehaviorHelper_DEFINED__

WINRT_EXPORT
@interface WUXMARepeatBehaviorHelper : RTObject
+ (WUXMARepeatBehavior*)fromCount:(double)count;
+ (WUXMARepeatBehavior*)fromDuration:(WFTimeSpan*)duration;
+ (BOOL)getHasCount:(WUXMARepeatBehavior*)target;
+ (BOOL)getHasDuration:(WUXMARepeatBehavior*)target;
+ (BOOL)equals:(WUXMARepeatBehavior*)target value:(WUXMARepeatBehavior*)value;
+ (WUXMARepeatBehavior*)forever;
@end

#endif // __WUXMARepeatBehaviorHelper_DEFINED__

// Windows.UI.Xaml.Media.Animation.TransitionCollection
#ifndef __WUXMATransitionCollection_DEFINED__
#define __WUXMATransitionCollection_DEFINED__

WINRT_EXPORT
@interface WUXMATransitionCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
@end

#endif // __WUXMATransitionCollection_DEFINED__

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
@end

#endif // __WXDependencyObject_DEFINED__

// Windows.UI.Xaml.TriggerAction
#ifndef __WXTriggerAction_DEFINED__
#define __WXTriggerAction_DEFINED__

WINRT_EXPORT
@interface WXTriggerAction : WXDependencyObject
@end

#endif // __WXTriggerAction_DEFINED__

// Windows.UI.Xaml.Media.Animation.BeginStoryboard
#ifndef __WUXMABeginStoryboard_DEFINED__
#define __WUXMABeginStoryboard_DEFINED__

WINRT_EXPORT
@interface WUXMABeginStoryboard : WXTriggerAction
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMAStoryboard* storyboard;
+ (WXDependencyProperty*)storyboardProperty;
@end

#endif // __WUXMABeginStoryboard_DEFINED__

// Windows.UI.Xaml.Media.Animation.ColorKeyFrameCollection
#ifndef __WUXMAColorKeyFrameCollection_DEFINED__
#define __WUXMAColorKeyFrameCollection_DEFINED__

WINRT_EXPORT
@interface WUXMAColorKeyFrameCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
@end

#endif // __WUXMAColorKeyFrameCollection_DEFINED__

// Windows.UI.Xaml.Media.Animation.ColorKeyFrame
#ifndef __WUXMAColorKeyFrame_DEFINED__
#define __WUXMAColorKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMAColorKeyFrame : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (copy) WUColor* value;
@property (copy) WUXMAKeyTime* keyTime;
+ (WXDependencyProperty*)keyTimeProperty;
+ (WXDependencyProperty*)valueProperty;
@end

#endif // __WUXMAColorKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.DiscreteColorKeyFrame
#ifndef __WUXMADiscreteColorKeyFrame_DEFINED__
#define __WUXMADiscreteColorKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMADiscreteColorKeyFrame : WUXMAColorKeyFrame
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMADiscreteColorKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.DoubleKeyFrameCollection
#ifndef __WUXMADoubleKeyFrameCollection_DEFINED__
#define __WUXMADoubleKeyFrameCollection_DEFINED__

WINRT_EXPORT
@interface WUXMADoubleKeyFrameCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
@end

#endif // __WUXMADoubleKeyFrameCollection_DEFINED__

// Windows.UI.Xaml.Media.Animation.DoubleKeyFrame
#ifndef __WUXMADoubleKeyFrame_DEFINED__
#define __WUXMADoubleKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMADoubleKeyFrame : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property double value;
@property (copy) WUXMAKeyTime* keyTime;
+ (WXDependencyProperty*)keyTimeProperty;
+ (WXDependencyProperty*)valueProperty;
@end

#endif // __WUXMADoubleKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.DiscreteDoubleKeyFrame
#ifndef __WUXMADiscreteDoubleKeyFrame_DEFINED__
#define __WUXMADiscreteDoubleKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMADiscreteDoubleKeyFrame : WUXMADoubleKeyFrame
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMADiscreteDoubleKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.EasingColorKeyFrame
#ifndef __WUXMAEasingColorKeyFrame_DEFINED__
#define __WUXMAEasingColorKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMAEasingColorKeyFrame : WUXMAColorKeyFrame
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMAEasingFunctionBase* easingFunction;
+ (WXDependencyProperty*)easingFunctionProperty;
@end

#endif // __WUXMAEasingColorKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.EasingDoubleKeyFrame
#ifndef __WUXMAEasingDoubleKeyFrame_DEFINED__
#define __WUXMAEasingDoubleKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMAEasingDoubleKeyFrame : WUXMADoubleKeyFrame
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMAEasingFunctionBase* easingFunction;
+ (WXDependencyProperty*)easingFunctionProperty;
@end

#endif // __WUXMAEasingDoubleKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.EasingFunctionBase
#ifndef __WUXMAEasingFunctionBase_DEFINED__
#define __WUXMAEasingFunctionBase_DEFINED__

WINRT_EXPORT
@interface WUXMAEasingFunctionBase : WXDependencyObject
@property WUXMAEasingMode easingMode;
+ (WXDependencyProperty*)easingModeProperty;
- (double)ease:(double)normalizedTime;
@end

#endif // __WUXMAEasingFunctionBase_DEFINED__

// Windows.UI.Xaml.Media.Animation.BackEase
#ifndef __WUXMABackEase_DEFINED__
#define __WUXMABackEase_DEFINED__

WINRT_EXPORT
@interface WUXMABackEase : WUXMAEasingFunctionBase
+ (instancetype)create ACTIVATOR;
@property double amplitude;
+ (WXDependencyProperty*)amplitudeProperty;
@end

#endif // __WUXMABackEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.BounceEase
#ifndef __WUXMABounceEase_DEFINED__
#define __WUXMABounceEase_DEFINED__

WINRT_EXPORT
@interface WUXMABounceEase : WUXMAEasingFunctionBase
+ (instancetype)create ACTIVATOR;
@property double bounciness;
@property int bounces;
+ (WXDependencyProperty*)bouncesProperty;
+ (WXDependencyProperty*)bouncinessProperty;
@end

#endif // __WUXMABounceEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.CircleEase
#ifndef __WUXMACircleEase_DEFINED__
#define __WUXMACircleEase_DEFINED__

WINRT_EXPORT
@interface WUXMACircleEase : WUXMAEasingFunctionBase
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMACircleEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.CubicEase
#ifndef __WUXMACubicEase_DEFINED__
#define __WUXMACubicEase_DEFINED__

WINRT_EXPORT
@interface WUXMACubicEase : WUXMAEasingFunctionBase
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMACubicEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.ElasticEase
#ifndef __WUXMAElasticEase_DEFINED__
#define __WUXMAElasticEase_DEFINED__

WINRT_EXPORT
@interface WUXMAElasticEase : WUXMAEasingFunctionBase
+ (instancetype)create ACTIVATOR;
@property double springiness;
@property int oscillations;
+ (WXDependencyProperty*)oscillationsProperty;
+ (WXDependencyProperty*)springinessProperty;
@end

#endif // __WUXMAElasticEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.ExponentialEase
#ifndef __WUXMAExponentialEase_DEFINED__
#define __WUXMAExponentialEase_DEFINED__

WINRT_EXPORT
@interface WUXMAExponentialEase : WUXMAEasingFunctionBase
+ (instancetype)create ACTIVATOR;
@property double exponent;
+ (WXDependencyProperty*)exponentProperty;
@end

#endif // __WUXMAExponentialEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.KeySpline
#ifndef __WUXMAKeySpline_DEFINED__
#define __WUXMAKeySpline_DEFINED__

WINRT_EXPORT
@interface WUXMAKeySpline : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (copy) WFPoint* controlPoint2;
@property (copy) WFPoint* controlPoint1;
@end

#endif // __WUXMAKeySpline_DEFINED__

// Windows.UI.Xaml.Media.Animation.LinearColorKeyFrame
#ifndef __WUXMALinearColorKeyFrame_DEFINED__
#define __WUXMALinearColorKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMALinearColorKeyFrame : WUXMAColorKeyFrame
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMALinearColorKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.LinearDoubleKeyFrame
#ifndef __WUXMALinearDoubleKeyFrame_DEFINED__
#define __WUXMALinearDoubleKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMALinearDoubleKeyFrame : WUXMADoubleKeyFrame
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMALinearDoubleKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.NavigationTransitionInfo
#ifndef __WUXMANavigationTransitionInfo_DEFINED__
#define __WUXMANavigationTransitionInfo_DEFINED__

WINRT_EXPORT
@interface WUXMANavigationTransitionInfo : WXDependencyObject
+ (instancetype)create ACTIVATOR;
- (NSString*)getNavigationStateCore;
- (void)setNavigationStateCore:(NSString*)navigationState;
@end

#endif // __WUXMANavigationTransitionInfo_DEFINED__

// Windows.UI.Xaml.Media.Animation.ObjectKeyFrameCollection
#ifndef __WUXMAObjectKeyFrameCollection_DEFINED__
#define __WUXMAObjectKeyFrameCollection_DEFINED__

WINRT_EXPORT
@interface WUXMAObjectKeyFrameCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
@end

#endif // __WUXMAObjectKeyFrameCollection_DEFINED__

// Windows.UI.Xaml.Media.Animation.ObjectKeyFrame
#ifndef __WUXMAObjectKeyFrame_DEFINED__
#define __WUXMAObjectKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMAObjectKeyFrame : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject* value;
@property (copy) WUXMAKeyTime* keyTime;
+ (WXDependencyProperty*)keyTimeProperty;
+ (WXDependencyProperty*)valueProperty;
@end

#endif // __WUXMAObjectKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.DiscreteObjectKeyFrame
#ifndef __WUXMADiscreteObjectKeyFrame_DEFINED__
#define __WUXMADiscreteObjectKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMADiscreteObjectKeyFrame : WUXMAObjectKeyFrame
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMADiscreteObjectKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.PointKeyFrameCollection
#ifndef __WUXMAPointKeyFrameCollection_DEFINED__
#define __WUXMAPointKeyFrameCollection_DEFINED__

WINRT_EXPORT
@interface WUXMAPointKeyFrameCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
@end

#endif // __WUXMAPointKeyFrameCollection_DEFINED__

// Windows.UI.Xaml.Media.Animation.PointKeyFrame
#ifndef __WUXMAPointKeyFrame_DEFINED__
#define __WUXMAPointKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMAPointKeyFrame : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (copy) WFPoint* value;
@property (copy) WUXMAKeyTime* keyTime;
+ (WXDependencyProperty*)keyTimeProperty;
+ (WXDependencyProperty*)valueProperty;
@end

#endif // __WUXMAPointKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.DiscretePointKeyFrame
#ifndef __WUXMADiscretePointKeyFrame_DEFINED__
#define __WUXMADiscretePointKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMADiscretePointKeyFrame : WUXMAPointKeyFrame
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMADiscretePointKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.EasingPointKeyFrame
#ifndef __WUXMAEasingPointKeyFrame_DEFINED__
#define __WUXMAEasingPointKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMAEasingPointKeyFrame : WUXMAPointKeyFrame
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMAEasingFunctionBase* easingFunction;
+ (WXDependencyProperty*)easingFunctionProperty;
@end

#endif // __WUXMAEasingPointKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.LinearPointKeyFrame
#ifndef __WUXMALinearPointKeyFrame_DEFINED__
#define __WUXMALinearPointKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMALinearPointKeyFrame : WUXMAPointKeyFrame
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMALinearPointKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.PowerEase
#ifndef __WUXMAPowerEase_DEFINED__
#define __WUXMAPowerEase_DEFINED__

WINRT_EXPORT
@interface WUXMAPowerEase : WUXMAEasingFunctionBase
+ (instancetype)create ACTIVATOR;
@property double power;
+ (WXDependencyProperty*)powerProperty;
@end

#endif // __WUXMAPowerEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.QuadraticEase
#ifndef __WUXMAQuadraticEase_DEFINED__
#define __WUXMAQuadraticEase_DEFINED__

WINRT_EXPORT
@interface WUXMAQuadraticEase : WUXMAEasingFunctionBase
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMAQuadraticEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.QuarticEase
#ifndef __WUXMAQuarticEase_DEFINED__
#define __WUXMAQuarticEase_DEFINED__

WINRT_EXPORT
@interface WUXMAQuarticEase : WUXMAEasingFunctionBase
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMAQuarticEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.QuinticEase
#ifndef __WUXMAQuinticEase_DEFINED__
#define __WUXMAQuinticEase_DEFINED__

WINRT_EXPORT
@interface WUXMAQuinticEase : WUXMAEasingFunctionBase
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMAQuinticEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.SineEase
#ifndef __WUXMASineEase_DEFINED__
#define __WUXMASineEase_DEFINED__

WINRT_EXPORT
@interface WUXMASineEase : WUXMAEasingFunctionBase
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMASineEase_DEFINED__

// Windows.UI.Xaml.Media.Animation.SplineColorKeyFrame
#ifndef __WUXMASplineColorKeyFrame_DEFINED__
#define __WUXMASplineColorKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMASplineColorKeyFrame : WUXMAColorKeyFrame
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMAKeySpline* keySpline;
+ (WXDependencyProperty*)keySplineProperty;
@end

#endif // __WUXMASplineColorKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.SplineDoubleKeyFrame
#ifndef __WUXMASplineDoubleKeyFrame_DEFINED__
#define __WUXMASplineDoubleKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMASplineDoubleKeyFrame : WUXMADoubleKeyFrame
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMAKeySpline* keySpline;
+ (WXDependencyProperty*)keySplineProperty;
@end

#endif // __WUXMASplineDoubleKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.SplinePointKeyFrame
#ifndef __WUXMASplinePointKeyFrame_DEFINED__
#define __WUXMASplinePointKeyFrame_DEFINED__

WINRT_EXPORT
@interface WUXMASplinePointKeyFrame : WUXMAPointKeyFrame
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMAKeySpline* keySpline;
+ (WXDependencyProperty*)keySplineProperty;
@end

#endif // __WUXMASplinePointKeyFrame_DEFINED__

// Windows.UI.Xaml.Media.Animation.TimelineCollection
#ifndef __WUXMATimelineCollection_DEFINED__
#define __WUXMATimelineCollection_DEFINED__

WINRT_EXPORT
@interface WUXMATimelineCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
@end

#endif // __WUXMATimelineCollection_DEFINED__

// Windows.UI.Xaml.Media.Animation.Timeline
#ifndef __WUXMATimeline_DEFINED__
#define __WUXMATimeline_DEFINED__

WINRT_EXPORT
@interface WUXMATimeline : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property double speedRatio;
@property (copy) WUXMARepeatBehavior* repeatBehavior;
@property WUXMAFillBehavior fillBehavior;
@property (copy) WXDuration* duration;
@property (copy) WFTimeSpan* beginTime;
@property BOOL autoReverse;
+ (BOOL)allowDependentAnimations;
+ (void)setAllowDependentAnimations:(BOOL)value;
+ (WXDependencyProperty*)autoReverseProperty;
+ (WXDependencyProperty*)beginTimeProperty;
+ (WXDependencyProperty*)durationProperty;
+ (WXDependencyProperty*)fillBehaviorProperty;
+ (WXDependencyProperty*)repeatBehaviorProperty;
+ (WXDependencyProperty*)speedRatioProperty;
- (EventRegistrationToken)addCompletedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXMATimeline_DEFINED__

// Windows.UI.Xaml.Media.Animation.Storyboard
#ifndef __WUXMAStoryboard_DEFINED__
#define __WUXMAStoryboard_DEFINED__

WINRT_EXPORT
@interface WUXMAStoryboard : WUXMATimeline
+ (NSString*)getTargetProperty:(WUXMATimeline*)element;
+ (void)setTargetProperty:(WUXMATimeline*)element path:(NSString*)path;
+ (NSString*)getTargetName:(WUXMATimeline*)element;
+ (void)setTargetName:(WUXMATimeline*)element name:(NSString*)name;
+ (void)setTarget:(WUXMATimeline*)timeline target:(WXDependencyObject*)target;
+ (instancetype)create ACTIVATOR;
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

// Windows.UI.Xaml.Media.Animation.ColorAnimation
#ifndef __WUXMAColorAnimation_DEFINED__
#define __WUXMAColorAnimation_DEFINED__

WINRT_EXPORT
@interface WUXMAColorAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) WUColor* to;
@property (copy) WUColor* from;
@property BOOL enableDependentAnimation;
@property (copy) WUXMAEasingFunctionBase* easingFunction;
@property (copy) WUColor* by;
+ (WXDependencyProperty*)byProperty;
+ (WXDependencyProperty*)easingFunctionProperty;
+ (WXDependencyProperty*)enableDependentAnimationProperty;
+ (WXDependencyProperty*)fromProperty;
+ (WXDependencyProperty*)toProperty;
@end

#endif // __WUXMAColorAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.ColorAnimationUsingKeyFrames
#ifndef __WUXMAColorAnimationUsingKeyFrames_DEFINED__
#define __WUXMAColorAnimationUsingKeyFrames_DEFINED__

WINRT_EXPORT
@interface WUXMAColorAnimationUsingKeyFrames : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property BOOL enableDependentAnimation;
@property (readonly) WUXMAColorKeyFrameCollection* keyFrames;
+ (WXDependencyProperty*)enableDependentAnimationProperty;
@end

#endif // __WUXMAColorAnimationUsingKeyFrames_DEFINED__

// Windows.UI.Xaml.Media.Animation.DoubleAnimation
#ifndef __WUXMADoubleAnimation_DEFINED__
#define __WUXMADoubleAnimation_DEFINED__

WINRT_EXPORT
@interface WUXMADoubleAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) NSNumber* to;
@property (copy) NSNumber* from;
@property BOOL enableDependentAnimation;
@property (copy) WUXMAEasingFunctionBase* easingFunction;
@property (copy) NSNumber* by;
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

WINRT_EXPORT
@interface WUXMADoubleAnimationUsingKeyFrames : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property BOOL enableDependentAnimation;
@property (readonly) WUXMADoubleKeyFrameCollection* keyFrames;
+ (WXDependencyProperty*)enableDependentAnimationProperty;
@end

#endif // __WUXMADoubleAnimationUsingKeyFrames_DEFINED__

// Windows.UI.Xaml.Media.Animation.DragItemThemeAnimation
#ifndef __WUXMADragItemThemeAnimation_DEFINED__
#define __WUXMADragItemThemeAnimation_DEFINED__

WINRT_EXPORT
@interface WUXMADragItemThemeAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* targetName;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMADragItemThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.DragOverThemeAnimation
#ifndef __WUXMADragOverThemeAnimation_DEFINED__
#define __WUXMADragOverThemeAnimation_DEFINED__

WINRT_EXPORT
@interface WUXMADragOverThemeAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property double toOffset;
@property (copy) NSString* targetName;
@property WUXCPAnimationDirection direction;
+ (WXDependencyProperty*)directionProperty;
+ (WXDependencyProperty*)targetNameProperty;
+ (WXDependencyProperty*)toOffsetProperty;
@end

#endif // __WUXMADragOverThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.DropTargetItemThemeAnimation
#ifndef __WUXMADropTargetItemThemeAnimation_DEFINED__
#define __WUXMADropTargetItemThemeAnimation_DEFINED__

WINRT_EXPORT
@interface WUXMADropTargetItemThemeAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* targetName;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMADropTargetItemThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.FadeInThemeAnimation
#ifndef __WUXMAFadeInThemeAnimation_DEFINED__
#define __WUXMAFadeInThemeAnimation_DEFINED__

WINRT_EXPORT
@interface WUXMAFadeInThemeAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* targetName;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMAFadeInThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.FadeOutThemeAnimation
#ifndef __WUXMAFadeOutThemeAnimation_DEFINED__
#define __WUXMAFadeOutThemeAnimation_DEFINED__

WINRT_EXPORT
@interface WUXMAFadeOutThemeAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* targetName;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMAFadeOutThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.ObjectAnimationUsingKeyFrames
#ifndef __WUXMAObjectAnimationUsingKeyFrames_DEFINED__
#define __WUXMAObjectAnimationUsingKeyFrames_DEFINED__

WINRT_EXPORT
@interface WUXMAObjectAnimationUsingKeyFrames : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property BOOL enableDependentAnimation;
@property (readonly) WUXMAObjectKeyFrameCollection* keyFrames;
+ (WXDependencyProperty*)enableDependentAnimationProperty;
@end

#endif // __WUXMAObjectAnimationUsingKeyFrames_DEFINED__

// Windows.UI.Xaml.Media.Animation.PointAnimation
#ifndef __WUXMAPointAnimation_DEFINED__
#define __WUXMAPointAnimation_DEFINED__

WINRT_EXPORT
@interface WUXMAPointAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) WFPoint* to;
@property (copy) WFPoint* from;
@property BOOL enableDependentAnimation;
@property (copy) WUXMAEasingFunctionBase* easingFunction;
@property (copy) WFPoint* by;
+ (WXDependencyProperty*)byProperty;
+ (WXDependencyProperty*)easingFunctionProperty;
+ (WXDependencyProperty*)enableDependentAnimationProperty;
+ (WXDependencyProperty*)fromProperty;
+ (WXDependencyProperty*)toProperty;
@end

#endif // __WUXMAPointAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.PointAnimationUsingKeyFrames
#ifndef __WUXMAPointAnimationUsingKeyFrames_DEFINED__
#define __WUXMAPointAnimationUsingKeyFrames_DEFINED__

WINRT_EXPORT
@interface WUXMAPointAnimationUsingKeyFrames : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property BOOL enableDependentAnimation;
@property (readonly) WUXMAPointKeyFrameCollection* keyFrames;
+ (WXDependencyProperty*)enableDependentAnimationProperty;
@end

#endif // __WUXMAPointAnimationUsingKeyFrames_DEFINED__

// Windows.UI.Xaml.Media.Animation.PointerDownThemeAnimation
#ifndef __WUXMAPointerDownThemeAnimation_DEFINED__
#define __WUXMAPointerDownThemeAnimation_DEFINED__

WINRT_EXPORT
@interface WUXMAPointerDownThemeAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* targetName;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMAPointerDownThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.PointerUpThemeAnimation
#ifndef __WUXMAPointerUpThemeAnimation_DEFINED__
#define __WUXMAPointerUpThemeAnimation_DEFINED__

WINRT_EXPORT
@interface WUXMAPointerUpThemeAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* targetName;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMAPointerUpThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.PopInThemeAnimation
#ifndef __WUXMAPopInThemeAnimation_DEFINED__
#define __WUXMAPopInThemeAnimation_DEFINED__

WINRT_EXPORT
@interface WUXMAPopInThemeAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* targetName;
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

WINRT_EXPORT
@interface WUXMAPopOutThemeAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* targetName;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMAPopOutThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.RepositionThemeAnimation
#ifndef __WUXMARepositionThemeAnimation_DEFINED__
#define __WUXMARepositionThemeAnimation_DEFINED__

WINRT_EXPORT
@interface WUXMARepositionThemeAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* targetName;
@property double fromVerticalOffset;
@property double fromHorizontalOffset;
+ (WXDependencyProperty*)fromHorizontalOffsetProperty;
+ (WXDependencyProperty*)fromVerticalOffsetProperty;
+ (WXDependencyProperty*)targetNameProperty;
@end

#endif // __WUXMARepositionThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.SplitCloseThemeAnimation
#ifndef __WUXMASplitCloseThemeAnimation_DEFINED__
#define __WUXMASplitCloseThemeAnimation_DEFINED__

WINRT_EXPORT
@interface WUXMASplitCloseThemeAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* openedTargetName;
@property (copy) WXDependencyObject* openedTarget;
@property double openedLength;
@property double offsetFromCenter;
@property double contentTranslationOffset;
@property WUXCPAnimationDirection contentTranslationDirection;
@property (copy) NSString* contentTargetName;
@property (copy) WXDependencyObject* contentTarget;
@property (copy) NSString* closedTargetName;
@property (copy) WXDependencyObject* closedTarget;
@property double closedLength;
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

WINRT_EXPORT
@interface WUXMASplitOpenThemeAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* openedTargetName;
@property (copy) WXDependencyObject* openedTarget;
@property double openedLength;
@property double offsetFromCenter;
@property double contentTranslationOffset;
@property WUXCPAnimationDirection contentTranslationDirection;
@property (copy) NSString* contentTargetName;
@property (copy) WXDependencyObject* contentTarget;
@property (copy) NSString* closedTargetName;
@property (copy) WXDependencyObject* closedTarget;
@property double closedLength;
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

WINRT_EXPORT
@interface WUXMASwipeBackThemeAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* targetName;
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

WINRT_EXPORT
@interface WUXMASwipeHintThemeAnimation : WUXMATimeline
+ (instancetype)create ACTIVATOR;
@property double toVerticalOffset;
@property double toHorizontalOffset;
@property (copy) NSString* targetName;
+ (WXDependencyProperty*)targetNameProperty;
+ (WXDependencyProperty*)toHorizontalOffsetProperty;
+ (WXDependencyProperty*)toVerticalOffsetProperty;
@end

#endif // __WUXMASwipeHintThemeAnimation_DEFINED__

// Windows.UI.Xaml.Media.Animation.Transition
#ifndef __WUXMATransition_DEFINED__
#define __WUXMATransition_DEFINED__

WINRT_EXPORT
@interface WUXMATransition : WXDependencyObject
@end

#endif // __WUXMATransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.AddDeleteThemeTransition
#ifndef __WUXMAAddDeleteThemeTransition_DEFINED__
#define __WUXMAAddDeleteThemeTransition_DEFINED__

WINRT_EXPORT
@interface WUXMAAddDeleteThemeTransition : WUXMATransition
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMAAddDeleteThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.ContentThemeTransition
#ifndef __WUXMAContentThemeTransition_DEFINED__
#define __WUXMAContentThemeTransition_DEFINED__

WINRT_EXPORT
@interface WUXMAContentThemeTransition : WUXMATransition
+ (instancetype)create ACTIVATOR;
@property double verticalOffset;
@property double horizontalOffset;
+ (WXDependencyProperty*)horizontalOffsetProperty;
+ (WXDependencyProperty*)verticalOffsetProperty;
@end

#endif // __WUXMAContentThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.EdgeUIThemeTransition
#ifndef __WUXMAEdgeUIThemeTransition_DEFINED__
#define __WUXMAEdgeUIThemeTransition_DEFINED__

WINRT_EXPORT
@interface WUXMAEdgeUIThemeTransition : WUXMATransition
+ (instancetype)create ACTIVATOR;
@property WUXCPEdgeTransitionLocation edge;
+ (WXDependencyProperty*)edgeProperty;
@end

#endif // __WUXMAEdgeUIThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.EntranceThemeTransition
#ifndef __WUXMAEntranceThemeTransition_DEFINED__
#define __WUXMAEntranceThemeTransition_DEFINED__

WINRT_EXPORT
@interface WUXMAEntranceThemeTransition : WUXMATransition
+ (instancetype)create ACTIVATOR;
@property BOOL isStaggeringEnabled;
@property double fromVerticalOffset;
@property double fromHorizontalOffset;
+ (WXDependencyProperty*)fromHorizontalOffsetProperty;
+ (WXDependencyProperty*)fromVerticalOffsetProperty;
+ (WXDependencyProperty*)isStaggeringEnabledProperty;
@end

#endif // __WUXMAEntranceThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.PaneThemeTransition
#ifndef __WUXMAPaneThemeTransition_DEFINED__
#define __WUXMAPaneThemeTransition_DEFINED__

WINRT_EXPORT
@interface WUXMAPaneThemeTransition : WUXMATransition
+ (instancetype)create ACTIVATOR;
@property WUXCPEdgeTransitionLocation edge;
+ (WXDependencyProperty*)edgeProperty;
@end

#endif // __WUXMAPaneThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.PopupThemeTransition
#ifndef __WUXMAPopupThemeTransition_DEFINED__
#define __WUXMAPopupThemeTransition_DEFINED__

WINRT_EXPORT
@interface WUXMAPopupThemeTransition : WUXMATransition
+ (instancetype)create ACTIVATOR;
@property double fromVerticalOffset;
@property double fromHorizontalOffset;
+ (WXDependencyProperty*)fromHorizontalOffsetProperty;
+ (WXDependencyProperty*)fromVerticalOffsetProperty;
@end

#endif // __WUXMAPopupThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.ReorderThemeTransition
#ifndef __WUXMAReorderThemeTransition_DEFINED__
#define __WUXMAReorderThemeTransition_DEFINED__

WINRT_EXPORT
@interface WUXMAReorderThemeTransition : WUXMATransition
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMAReorderThemeTransition_DEFINED__

// Windows.UI.Xaml.Media.Animation.RepositionThemeTransition
#ifndef __WUXMARepositionThemeTransition_DEFINED__
#define __WUXMARepositionThemeTransition_DEFINED__

WINRT_EXPORT
@interface WUXMARepositionThemeTransition : WUXMATransition
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMARepositionThemeTransition_DEFINED__
