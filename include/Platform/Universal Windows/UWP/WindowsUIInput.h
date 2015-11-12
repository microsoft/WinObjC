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

// WindowsUIInput.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUIEdgeGestureEventArgs, WUIEdgeGesture, WUIMouseWheelParameters, WUIGestureRecognizer, WUITappedEventArgs, WUIRightTappedEventArgs,
    WUIHoldingEventArgs, WUIDraggingEventArgs, WUIManipulationStartedEventArgs, WUIManipulationUpdatedEventArgs,
    WUIManipulationInertiaStartingEventArgs, WUIManipulationCompletedEventArgs, WUICrossSlidingEventArgs, WUIPointerPoint,
    WUIPointerPointProperties, WUIPointerVisualizationSettings;
@class WUIManipulationDelta, WUIManipulationVelocities, WUICrossSlideThresholds;
@protocol WUIIEdgeGestureEventArgs
, WUIIEdgeGestureStatics, WUIIEdgeGesture, WUIITappedEventArgs, WUIIRightTappedEventArgs, WUIIHoldingEventArgs, WUIIDraggingEventArgs,
    WUIIManipulationStartedEventArgs, WUIIManipulationUpdatedEventArgs, WUIIManipulationInertiaStartingEventArgs,
    WUIIManipulationCompletedEventArgs, WUIICrossSlidingEventArgs, WUIIMouseWheelParameters, WUIIGestureRecognizer, WUIIPointerPointStatics,
    WUIIPointerPointTransform, WUIIPointerPoint, WUIIPointerPointProperties, WUIIPointerPointProperties2, WUIIPointerVisualizationSettings,
    WUIIPointerVisualizationSettingsStatics;

// Windows.UI.Input.EdgeGestureKind
enum _WUIEdgeGestureKind {
    WUIEdgeGestureKindTouch = 0,
    WUIEdgeGestureKindKeyboard = 1,
    WUIEdgeGestureKindMouse = 2,
};
typedef unsigned WUIEdgeGestureKind;

// Windows.UI.Input.HoldingState
enum _WUIHoldingState {
    WUIHoldingStateStarted = 0,
    WUIHoldingStateCompleted = 1,
    WUIHoldingStateCanceled = 2,
};
typedef unsigned WUIHoldingState;

// Windows.UI.Input.DraggingState
enum _WUIDraggingState {
    WUIDraggingStateStarted = 0,
    WUIDraggingStateContinuing = 1,
    WUIDraggingStateCompleted = 2,
};
typedef unsigned WUIDraggingState;

// Windows.UI.Input.CrossSlidingState
enum _WUICrossSlidingState {
    WUICrossSlidingStateStarted = 0,
    WUICrossSlidingStateDragging = 1,
    WUICrossSlidingStateSelecting = 2,
    WUICrossSlidingStateSelectSpeedBumping = 3,
    WUICrossSlidingStateSpeedBumping = 4,
    WUICrossSlidingStateRearranging = 5,
    WUICrossSlidingStateCompleted = 6,
};
typedef unsigned WUICrossSlidingState;

// Windows.UI.Input.GestureSettings
enum _WUIGestureSettings {
    WUIGestureSettingsNone = 0,
    WUIGestureSettingsTap = 1,
    WUIGestureSettingsDoubleTap = 2,
    WUIGestureSettingsHold = 4,
    WUIGestureSettingsHoldWithMouse = 8,
    WUIGestureSettingsRightTap = 16,
    WUIGestureSettingsDrag = 32,
    WUIGestureSettingsManipulationTranslateX = 64,
    WUIGestureSettingsManipulationTranslateY = 128,
    WUIGestureSettingsManipulationTranslateRailsX = 256,
    WUIGestureSettingsManipulationTranslateRailsY = 512,
    WUIGestureSettingsManipulationRotate = 1024,
    WUIGestureSettingsManipulationScale = 2048,
    WUIGestureSettingsManipulationTranslateInertia = 4096,
    WUIGestureSettingsManipulationRotateInertia = 8192,
    WUIGestureSettingsManipulationScaleInertia = 16384,
    WUIGestureSettingsCrossSlide = 32768,
    WUIGestureSettingsManipulationMultipleFingerPanning = 65536,
};
typedef unsigned WUIGestureSettings;

// Windows.UI.Input.PointerUpdateKind
enum _WUIPointerUpdateKind {
    WUIPointerUpdateKindOther = 0,
    WUIPointerUpdateKindLeftButtonPressed = 1,
    WUIPointerUpdateKindLeftButtonReleased = 2,
    WUIPointerUpdateKindRightButtonPressed = 3,
    WUIPointerUpdateKindRightButtonReleased = 4,
    WUIPointerUpdateKindMiddleButtonPressed = 5,
    WUIPointerUpdateKindMiddleButtonReleased = 6,
    WUIPointerUpdateKindXButton1Pressed = 7,
    WUIPointerUpdateKindXButton1Released = 8,
    WUIPointerUpdateKindXButton2Pressed = 9,
    WUIPointerUpdateKindXButton2Released = 10,
};
typedef unsigned WUIPointerUpdateKind;

#include "WindowsDevicesInput.h"
#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// [struct] Windows.UI.Input.ManipulationDelta
WINRT_EXPORT
@interface WUIManipulationDelta : NSObject
+ (instancetype) new;
@property (copy) WFPoint* translation;
@property float scale;
@property float rotation;
@property float expansion;
@end

// [struct] Windows.UI.Input.ManipulationVelocities
WINRT_EXPORT
@interface WUIManipulationVelocities : NSObject
+ (instancetype) new;
@property (copy) WFPoint* linear;
@property float angular;
@property float expansion;
@end

// [struct] Windows.UI.Input.CrossSlideThresholds
WINRT_EXPORT
@interface WUICrossSlideThresholds : NSObject
+ (instancetype) new;
@property float selectionStart;
@property float speedBumpStart;
@property float speedBumpEnd;
@property float rearrangeStart;
@end

// Windows.UI.Input.IPointerPointTransform
#ifndef __WUIIPointerPointTransform_DEFINED__
#define __WUIIPointerPointTransform_DEFINED__

@protocol WUIIPointerPointTransform
@property (readonly) RTObject<WUIIPointerPointTransform>* inverse;
- (BOOL)tryTransform:(WFPoint*)inPoint outPoint:(WFPoint**)outPoint;
- (WFRect*)transformBounds:(WFRect*)rect;
@end

#endif // __WUIIPointerPointTransform_DEFINED__

// Windows.UI.Input.EdgeGestureEventArgs
#ifndef __WUIEdgeGestureEventArgs_DEFINED__
#define __WUIEdgeGestureEventArgs_DEFINED__

WINRT_EXPORT
@interface WUIEdgeGestureEventArgs : RTObject
@property (readonly) WUIEdgeGestureKind kind;
@end

#endif // __WUIEdgeGestureEventArgs_DEFINED__

// Windows.UI.Input.EdgeGesture
#ifndef __WUIEdgeGesture_DEFINED__
#define __WUIEdgeGesture_DEFINED__

WINRT_EXPORT
@interface WUIEdgeGesture : RTObject
+ (WUIEdgeGesture*)getForCurrentView;
- (EventRegistrationToken)addCanceledEvent:(void (^)(WUIEdgeGesture*, WUIEdgeGestureEventArgs*))del;
- (void)removeCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCompletedEvent:(void (^)(WUIEdgeGesture*, WUIEdgeGestureEventArgs*))del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStartingEvent:(void (^)(WUIEdgeGesture*, WUIEdgeGestureEventArgs*))del;
- (void)removeStartingEvent:(EventRegistrationToken)tok;
@end

#endif // __WUIEdgeGesture_DEFINED__

// Windows.UI.Input.MouseWheelParameters
#ifndef __WUIMouseWheelParameters_DEFINED__
#define __WUIMouseWheelParameters_DEFINED__

WINRT_EXPORT
@interface WUIMouseWheelParameters : RTObject
@property (copy) WFPoint* pageTranslation;
@property float deltaScale;
@property float deltaRotationAngle;
@property (copy) WFPoint* charTranslation;
@end

#endif // __WUIMouseWheelParameters_DEFINED__

// Windows.UI.Input.GestureRecognizer
#ifndef __WUIGestureRecognizer_DEFINED__
#define __WUIGestureRecognizer_DEFINED__

WINRT_EXPORT
@interface WUIGestureRecognizer : RTObject
+ (instancetype)create ACTIVATOR;
@property float inertiaRotationDeceleration;
@property float inertiaRotationAngle;
@property float inertiaExpansionDeceleration;
@property float inertiaExpansion;
@property BOOL autoProcessInertia;
@property (copy) WUICrossSlideThresholds* crossSlideThresholds;
@property BOOL crossSlideExact;
@property WUIGestureSettings gestureSettings;
@property float inertiaTranslationDeceleration;
@property BOOL showGestureFeedback;
@property float pivotRadius;
@property BOOL crossSlideHorizontally;
@property (copy) WFPoint* pivotCenter;
@property BOOL manipulationExact;
@property float inertiaTranslationDisplacement;
@property (readonly) BOOL isActive;
@property (readonly) BOOL isInertial;
@property (readonly) WUIMouseWheelParameters* mouseWheelParameters;
- (EventRegistrationToken)addCrossSlidingEvent:(void (^)(WUIGestureRecognizer*, WUICrossSlidingEventArgs*))del;
- (void)removeCrossSlidingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDraggingEvent:(void (^)(WUIGestureRecognizer*, WUIDraggingEventArgs*))del;
- (void)removeDraggingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHoldingEvent:(void (^)(WUIGestureRecognizer*, WUIHoldingEventArgs*))del;
- (void)removeHoldingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationCompletedEvent:(void (^)(WUIGestureRecognizer*, WUIManipulationCompletedEventArgs*))del;
- (void)removeManipulationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationInertiaStartingEvent:(void (^)(WUIGestureRecognizer*,
                                                                        WUIManipulationInertiaStartingEventArgs*))del;
- (void)removeManipulationInertiaStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationStartedEvent:(void (^)(WUIGestureRecognizer*, WUIManipulationStartedEventArgs*))del;
- (void)removeManipulationStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationUpdatedEvent:(void (^)(WUIGestureRecognizer*, WUIManipulationUpdatedEventArgs*))del;
- (void)removeManipulationUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRightTappedEvent:(void (^)(WUIGestureRecognizer*, WUIRightTappedEventArgs*))del;
- (void)removeRightTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTappedEvent:(void (^)(WUIGestureRecognizer*, WUITappedEventArgs*))del;
- (void)removeTappedEvent:(EventRegistrationToken)tok;
- (BOOL)canBeDoubleTap:(WUIPointerPoint*)value;
- (void)processDownEvent:(WUIPointerPoint*)value;
- (void)processMoveEvents:(id<NSFastEnumeration> /* WUIPointerPoint* */)value;
- (void)processUpEvent:(WUIPointerPoint*)value;
- (void)processMouseWheelEvent:(WUIPointerPoint*)value isShiftKeyDown:(BOOL)isShiftKeyDown isControlKeyDown:(BOOL)isControlKeyDown;
- (void)processInertia;
- (void)completeGesture;
@end

#endif // __WUIGestureRecognizer_DEFINED__

// Windows.UI.Input.TappedEventArgs
#ifndef __WUITappedEventArgs_DEFINED__
#define __WUITappedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUITappedEventArgs : RTObject
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@property (readonly) unsigned int tapCount;
@end

#endif // __WUITappedEventArgs_DEFINED__

// Windows.UI.Input.RightTappedEventArgs
#ifndef __WUIRightTappedEventArgs_DEFINED__
#define __WUIRightTappedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUIRightTappedEventArgs : RTObject
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@end

#endif // __WUIRightTappedEventArgs_DEFINED__

// Windows.UI.Input.HoldingEventArgs
#ifndef __WUIHoldingEventArgs_DEFINED__
#define __WUIHoldingEventArgs_DEFINED__

WINRT_EXPORT
@interface WUIHoldingEventArgs : RTObject
@property (readonly) WUIHoldingState holdingState;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@end

#endif // __WUIHoldingEventArgs_DEFINED__

// Windows.UI.Input.DraggingEventArgs
#ifndef __WUIDraggingEventArgs_DEFINED__
#define __WUIDraggingEventArgs_DEFINED__

WINRT_EXPORT
@interface WUIDraggingEventArgs : RTObject
@property (readonly) WUIDraggingState draggingState;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@end

#endif // __WUIDraggingEventArgs_DEFINED__

// Windows.UI.Input.ManipulationStartedEventArgs
#ifndef __WUIManipulationStartedEventArgs_DEFINED__
#define __WUIManipulationStartedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUIManipulationStartedEventArgs : RTObject
@property (readonly) WUIManipulationDelta* cumulative;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@end

#endif // __WUIManipulationStartedEventArgs_DEFINED__

// Windows.UI.Input.ManipulationUpdatedEventArgs
#ifndef __WUIManipulationUpdatedEventArgs_DEFINED__
#define __WUIManipulationUpdatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUIManipulationUpdatedEventArgs : RTObject
@property (readonly) WUIManipulationDelta* cumulative;
@property (readonly) WUIManipulationDelta* delta;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@property (readonly) WUIManipulationVelocities* velocities;
@end

#endif // __WUIManipulationUpdatedEventArgs_DEFINED__

// Windows.UI.Input.ManipulationInertiaStartingEventArgs
#ifndef __WUIManipulationInertiaStartingEventArgs_DEFINED__
#define __WUIManipulationInertiaStartingEventArgs_DEFINED__

WINRT_EXPORT
@interface WUIManipulationInertiaStartingEventArgs : RTObject
@property (readonly) WUIManipulationDelta* cumulative;
@property (readonly) WUIManipulationDelta* delta;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@property (readonly) WUIManipulationVelocities* velocities;
@end

#endif // __WUIManipulationInertiaStartingEventArgs_DEFINED__

// Windows.UI.Input.ManipulationCompletedEventArgs
#ifndef __WUIManipulationCompletedEventArgs_DEFINED__
#define __WUIManipulationCompletedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUIManipulationCompletedEventArgs : RTObject
@property (readonly) WUIManipulationDelta* cumulative;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@property (readonly) WUIManipulationVelocities* velocities;
@end

#endif // __WUIManipulationCompletedEventArgs_DEFINED__

// Windows.UI.Input.CrossSlidingEventArgs
#ifndef __WUICrossSlidingEventArgs_DEFINED__
#define __WUICrossSlidingEventArgs_DEFINED__

WINRT_EXPORT
@interface WUICrossSlidingEventArgs : RTObject
@property (readonly) WUICrossSlidingState crossSlidingState;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@end

#endif // __WUICrossSlidingEventArgs_DEFINED__

// Windows.UI.Input.PointerPoint
#ifndef __WUIPointerPoint_DEFINED__
#define __WUIPointerPoint_DEFINED__

WINRT_EXPORT
@interface WUIPointerPoint : RTObject
+ (WUIPointerPoint*)getCurrentPoint:(unsigned int)pointerId;
+ (NSMutableArray*)getIntermediatePoints:(unsigned int)pointerId;
+ (WUIPointerPoint*)getCurrentPointTransformed:(unsigned int)pointerId transform:(RTObject<WUIIPointerPointTransform>*)transform;
+ (NSMutableArray*)getIntermediatePointsTransformed:(unsigned int)pointerId transform:(RTObject<WUIIPointerPointTransform>*)transform;
@property (readonly) unsigned int frameId;
@property (readonly) BOOL isInContact;
@property (readonly) WDIPointerDevice* pointerDevice;
@property (readonly) unsigned int pointerId;
@property (readonly) WFPoint* position;
@property (readonly) WUIPointerPointProperties* properties;
@property (readonly) WFPoint* rawPosition;
@property (readonly) uint64_t timestamp;
@end

#endif // __WUIPointerPoint_DEFINED__

// Windows.UI.Input.PointerPointProperties
#ifndef __WUIPointerPointProperties_DEFINED__
#define __WUIPointerPointProperties_DEFINED__

WINRT_EXPORT
@interface WUIPointerPointProperties : RTObject
@property (readonly) WFRect* contactRect;
@property (readonly) WFRect* contactRectRaw;
@property (readonly) BOOL isBarrelButtonPressed;
@property (readonly) BOOL isCanceled;
@property (readonly) BOOL isEraser;
@property (readonly) BOOL isHorizontalMouseWheel;
@property (readonly) BOOL isInRange;
@property (readonly) BOOL isInverted;
@property (readonly) BOOL isLeftButtonPressed;
@property (readonly) BOOL isMiddleButtonPressed;
@property (readonly) BOOL isPrimary;
@property (readonly) BOOL isRightButtonPressed;
@property (readonly) BOOL isXButton1Pressed;
@property (readonly) BOOL isXButton2Pressed;
@property (readonly) int mouseWheelDelta;
@property (readonly) float orientation;
@property (readonly) WUIPointerUpdateKind pointerUpdateKind;
@property (readonly) float pressure;
@property (readonly) BOOL touchConfidence;
@property (readonly) float twist;
@property (readonly) float xTilt;
@property (readonly) float yTilt;
@property (readonly) id zDistance;
- (BOOL)hasUsage:(unsigned int)usagePage usageId:(unsigned int)usageId;
- (int)getUsageValue:(unsigned int)usagePage usageId:(unsigned int)usageId;
@end

#endif // __WUIPointerPointProperties_DEFINED__

// Windows.UI.Input.PointerVisualizationSettings
#ifndef __WUIPointerVisualizationSettings_DEFINED__
#define __WUIPointerVisualizationSettings_DEFINED__

WINRT_EXPORT
@interface WUIPointerVisualizationSettings : RTObject
+ (WUIPointerVisualizationSettings*)getForCurrentView;
@property BOOL isContactFeedbackEnabled;
@property BOOL isBarrelButtonFeedbackEnabled;
@end

#endif // __WUIPointerVisualizationSettings_DEFINED__
