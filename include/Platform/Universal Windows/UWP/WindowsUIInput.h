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

// WindowsUIInput.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUIEdgeGestureEventArgs, WUIEdgeGesture, WUIKeyboardDeliveryInterceptor, WUIMouseWheelParameters, WUIGestureRecognizer, WUITappedEventArgs, WUIRightTappedEventArgs, WUIHoldingEventArgs, WUIDraggingEventArgs, WUIManipulationStartedEventArgs, WUIManipulationUpdatedEventArgs, WUIManipulationInertiaStartingEventArgs, WUIManipulationCompletedEventArgs, WUICrossSlidingEventArgs, WUIPointerPoint, WUIPointerPointProperties, WUIPointerVisualizationSettings, WUIRadialControllerScreenContact, WUIRadialControllerMenu, WUIRadialController, WUIRadialControllerScreenContactStartedEventArgs, WUIRadialControllerScreenContactContinuedEventArgs, WUIRadialControllerRotationChangedEventArgs, WUIRadialControllerButtonClickedEventArgs, WUIRadialControllerControlAcquiredEventArgs, WUIRadialControllerButtonPressedEventArgs, WUIRadialControllerButtonHoldingEventArgs, WUIRadialControllerButtonReleasedEventArgs, WUIRadialControllerMenuItem, WUIRadialControllerConfiguration, WUIRadialControllerScreenContactEndedEventArgs;
@class WUIManipulationDelta, WUIManipulationVelocities, WUICrossSlideThresholds;
@protocol WUIIEdgeGestureEventArgs, WUIIEdgeGestureStatics, WUIIEdgeGesture, WUIIKeyboardDeliveryInterceptor, WUIIKeyboardDeliveryInterceptorStatics, WUIITappedEventArgs, WUIIRightTappedEventArgs, WUIIHoldingEventArgs, WUIIDraggingEventArgs, WUIIManipulationStartedEventArgs, WUIIManipulationUpdatedEventArgs, WUIIManipulationInertiaStartingEventArgs, WUIIManipulationCompletedEventArgs, WUIICrossSlidingEventArgs, WUIIMouseWheelParameters, WUIIGestureRecognizer, WUIIPointerPointStatics, WUIIPointerPointTransform, WUIIPointerPoint, WUIIPointerPointProperties, WUIIPointerPointProperties2, WUIIPointerVisualizationSettings, WUIIPointerVisualizationSettingsStatics, WUIIRadialControllerScreenContact, WUIIRadialControllerRotationChangedEventArgs, WUIIRadialControllerRotationChangedEventArgs2, WUIIRadialControllerButtonPressedEventArgs, WUIIRadialControllerButtonHoldingEventArgs, WUIIRadialControllerButtonReleasedEventArgs, WUIIRadialControllerScreenContactStartedEventArgs, WUIIRadialControllerScreenContactStartedEventArgs2, WUIIRadialControllerScreenContactContinuedEventArgs, WUIIRadialControllerScreenContactContinuedEventArgs2, WUIIRadialControllerScreenContactEndedEventArgs, WUIIRadialControllerButtonClickedEventArgs, WUIIRadialControllerButtonClickedEventArgs2, WUIIRadialControllerControlAcquiredEventArgs, WUIIRadialControllerControlAcquiredEventArgs2, WUIIRadialController, WUIIRadialController2, WUIIRadialControllerStatics, WUIIRadialControllerMenu, WUIIRadialControllerMenuItemStatics, WUIIRadialControllerMenuItemStatics2, WUIIRadialControllerMenuItem, WUIIRadialControllerConfiguration, WUIIRadialControllerConfigurationStatics, WUIIRadialControllerConfiguration2, WUIIRadialControllerConfigurationStatics2;

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

// Windows.UI.Input.RadialControllerSystemMenuItemKind
enum _WUIRadialControllerSystemMenuItemKind {
    WUIRadialControllerSystemMenuItemKindScroll = 0,
    WUIRadialControllerSystemMenuItemKindZoom = 1,
    WUIRadialControllerSystemMenuItemKindUndoRedo = 2,
    WUIRadialControllerSystemMenuItemKindVolume = 3,
    WUIRadialControllerSystemMenuItemKindNextPreviousTrack = 4,
};
typedef unsigned WUIRadialControllerSystemMenuItemKind;

// Windows.UI.Input.RadialControllerMenuKnownIcon
enum _WUIRadialControllerMenuKnownIcon {
    WUIRadialControllerMenuKnownIconScroll = 0,
    WUIRadialControllerMenuKnownIconZoom = 1,
    WUIRadialControllerMenuKnownIconUndoRedo = 2,
    WUIRadialControllerMenuKnownIconVolume = 3,
    WUIRadialControllerMenuKnownIconNextPreviousTrack = 4,
    WUIRadialControllerMenuKnownIconRuler = 5,
    WUIRadialControllerMenuKnownIconInkColor = 6,
    WUIRadialControllerMenuKnownIconInkThickness = 7,
    WUIRadialControllerMenuKnownIconPenType = 8,
};
typedef unsigned WUIRadialControllerMenuKnownIcon;

#include "WindowsDevicesInput.h"
#include "WindowsFoundation.h"
#include "WindowsDevicesHaptics.h"
#include "WindowsUICore.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// [struct] Windows.UI.Input.ManipulationDelta
OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIManipulationDelta : NSObject
+ (instancetype)new;
@property (retain) WFPoint* translation;
@property float scale;
@property float rotation;
@property float expansion;
@end

// [struct] Windows.UI.Input.ManipulationVelocities
OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIManipulationVelocities : NSObject
+ (instancetype)new;
@property (retain) WFPoint* linear;
@property float angular;
@property float expansion;
@end

// [struct] Windows.UI.Input.CrossSlideThresholds
OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUICrossSlideThresholds : NSObject
+ (instancetype)new;
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

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIIPointerPointTransform : RTObject <WUIIPointerPointTransform>
@end

#endif // __WUIIPointerPointTransform_DEFINED__

// Windows.UI.Input.EdgeGestureEventArgs
#ifndef __WUIEdgeGestureEventArgs_DEFINED__
#define __WUIEdgeGestureEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIEdgeGestureEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIEdgeGestureKind kind;
@end

#endif // __WUIEdgeGestureEventArgs_DEFINED__

// Windows.UI.Input.EdgeGesture
#ifndef __WUIEdgeGesture_DEFINED__
#define __WUIEdgeGesture_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIEdgeGesture : RTObject
+ (WUIEdgeGesture*)getForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addCanceledEvent:(void(^)(WUIEdgeGesture*, WUIEdgeGestureEventArgs*))del;
- (void)removeCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCompletedEvent:(void(^)(WUIEdgeGesture*, WUIEdgeGestureEventArgs*))del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStartingEvent:(void(^)(WUIEdgeGesture*, WUIEdgeGestureEventArgs*))del;
- (void)removeStartingEvent:(EventRegistrationToken)tok;
@end

#endif // __WUIEdgeGesture_DEFINED__

// Windows.UI.Input.KeyboardDeliveryInterceptor
#ifndef __WUIKeyboardDeliveryInterceptor_DEFINED__
#define __WUIKeyboardDeliveryInterceptor_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIKeyboardDeliveryInterceptor : RTObject
+ (WUIKeyboardDeliveryInterceptor*)getForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isInterceptionEnabledWhenInForeground;
- (EventRegistrationToken)addKeyDownEvent:(void(^)(WUIKeyboardDeliveryInterceptor*, WUCKeyEventArgs*))del;
- (void)removeKeyDownEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyUpEvent:(void(^)(WUIKeyboardDeliveryInterceptor*, WUCKeyEventArgs*))del;
- (void)removeKeyUpEvent:(EventRegistrationToken)tok;
@end

#endif // __WUIKeyboardDeliveryInterceptor_DEFINED__

// Windows.UI.Input.MouseWheelParameters
#ifndef __WUIMouseWheelParameters_DEFINED__
#define __WUIMouseWheelParameters_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIMouseWheelParameters : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFPoint* pageTranslation;
@property float deltaScale;
@property float deltaRotationAngle;
@property (retain) WFPoint* charTranslation;
@end

#endif // __WUIMouseWheelParameters_DEFINED__

// Windows.UI.Input.GestureRecognizer
#ifndef __WUIGestureRecognizer_DEFINED__
#define __WUIGestureRecognizer_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIGestureRecognizer : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property float inertiaRotationDeceleration;
@property float inertiaTranslationDeceleration;
@property float inertiaExpansionDeceleration;
@property float inertiaExpansion;
@property BOOL autoProcessInertia;
@property (retain) WUICrossSlideThresholds* crossSlideThresholds;
@property BOOL crossSlideExact;
@property WUIGestureSettings gestureSettings;
@property float inertiaRotationAngle;
@property BOOL showGestureFeedback;
@property float pivotRadius;
@property BOOL crossSlideHorizontally;
@property (retain) WFPoint* pivotCenter;
@property BOOL manipulationExact;
@property float inertiaTranslationDisplacement;
@property (readonly) BOOL isActive;
@property (readonly) BOOL isInertial;
@property (readonly) WUIMouseWheelParameters* mouseWheelParameters;
- (EventRegistrationToken)addCrossSlidingEvent:(void(^)(WUIGestureRecognizer*, WUICrossSlidingEventArgs*))del;
- (void)removeCrossSlidingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDraggingEvent:(void(^)(WUIGestureRecognizer*, WUIDraggingEventArgs*))del;
- (void)removeDraggingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHoldingEvent:(void(^)(WUIGestureRecognizer*, WUIHoldingEventArgs*))del;
- (void)removeHoldingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationCompletedEvent:(void(^)(WUIGestureRecognizer*, WUIManipulationCompletedEventArgs*))del;
- (void)removeManipulationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationInertiaStartingEvent:(void(^)(WUIGestureRecognizer*, WUIManipulationInertiaStartingEventArgs*))del;
- (void)removeManipulationInertiaStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationStartedEvent:(void(^)(WUIGestureRecognizer*, WUIManipulationStartedEventArgs*))del;
- (void)removeManipulationStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationUpdatedEvent:(void(^)(WUIGestureRecognizer*, WUIManipulationUpdatedEventArgs*))del;
- (void)removeManipulationUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRightTappedEvent:(void(^)(WUIGestureRecognizer*, WUIRightTappedEventArgs*))del;
- (void)removeRightTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTappedEvent:(void(^)(WUIGestureRecognizer*, WUITappedEventArgs*))del;
- (void)removeTappedEvent:(EventRegistrationToken)tok;
- (BOOL)canBeDoubleTap:(WUIPointerPoint*)value;
- (void)processDownEvent:(WUIPointerPoint*)value;
- (void)processMoveEvents:(NSMutableArray* /* WUIPointerPoint* */)value;
- (void)processUpEvent:(WUIPointerPoint*)value;
- (void)processMouseWheelEvent:(WUIPointerPoint*)value isShiftKeyDown:(BOOL)isShiftKeyDown isControlKeyDown:(BOOL)isControlKeyDown;
- (void)processInertia;
- (void)completeGesture;
@end

#endif // __WUIGestureRecognizer_DEFINED__

// Windows.UI.Input.TappedEventArgs
#ifndef __WUITappedEventArgs_DEFINED__
#define __WUITappedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUITappedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@property (readonly) unsigned int tapCount;
@end

#endif // __WUITappedEventArgs_DEFINED__

// Windows.UI.Input.RightTappedEventArgs
#ifndef __WUIRightTappedEventArgs_DEFINED__
#define __WUIRightTappedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRightTappedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@end

#endif // __WUIRightTappedEventArgs_DEFINED__

// Windows.UI.Input.HoldingEventArgs
#ifndef __WUIHoldingEventArgs_DEFINED__
#define __WUIHoldingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIHoldingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIHoldingState holdingState;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@end

#endif // __WUIHoldingEventArgs_DEFINED__

// Windows.UI.Input.DraggingEventArgs
#ifndef __WUIDraggingEventArgs_DEFINED__
#define __WUIDraggingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIDraggingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIDraggingState draggingState;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@end

#endif // __WUIDraggingEventArgs_DEFINED__

// Windows.UI.Input.ManipulationStartedEventArgs
#ifndef __WUIManipulationStartedEventArgs_DEFINED__
#define __WUIManipulationStartedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIManipulationStartedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIManipulationDelta* cumulative;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@end

#endif // __WUIManipulationStartedEventArgs_DEFINED__

// Windows.UI.Input.ManipulationUpdatedEventArgs
#ifndef __WUIManipulationUpdatedEventArgs_DEFINED__
#define __WUIManipulationUpdatedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIManipulationUpdatedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIManipulationInertiaStartingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIManipulationCompletedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIManipulationDelta* cumulative;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@property (readonly) WUIManipulationVelocities* velocities;
@end

#endif // __WUIManipulationCompletedEventArgs_DEFINED__

// Windows.UI.Input.CrossSlidingEventArgs
#ifndef __WUICrossSlidingEventArgs_DEFINED__
#define __WUICrossSlidingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUICrossSlidingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUICrossSlidingState crossSlidingState;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@end

#endif // __WUICrossSlidingEventArgs_DEFINED__

// Windows.UI.Input.PointerPoint
#ifndef __WUIPointerPoint_DEFINED__
#define __WUIPointerPoint_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIPointerPoint : RTObject
+ (WUIPointerPoint*)getCurrentPoint:(unsigned int)pointerId;
+ (NSMutableArray* /* WUIPointerPoint* */)getIntermediatePoints:(unsigned int)pointerId;
+ (WUIPointerPoint*)getCurrentPointTransformed:(unsigned int)pointerId transform:(RTObject<WUIIPointerPointTransform>*)transform;
+ (NSMutableArray* /* WUIPointerPoint* */)getIntermediatePointsTransformed:(unsigned int)pointerId transform:(RTObject<WUIIPointerPointTransform>*)transform;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIPointerPointProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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
@property (readonly) id /* float */ zDistance;
- (BOOL)hasUsage:(unsigned int)usagePage usageId:(unsigned int)usageId;
- (int)getUsageValue:(unsigned int)usagePage usageId:(unsigned int)usageId;
@end

#endif // __WUIPointerPointProperties_DEFINED__

// Windows.UI.Input.PointerVisualizationSettings
#ifndef __WUIPointerVisualizationSettings_DEFINED__
#define __WUIPointerVisualizationSettings_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIPointerVisualizationSettings : RTObject
+ (WUIPointerVisualizationSettings*)getForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isContactFeedbackEnabled;
@property BOOL isBarrelButtonFeedbackEnabled;
@end

#endif // __WUIPointerVisualizationSettings_DEFINED__

// Windows.UI.Input.RadialControllerScreenContact
#ifndef __WUIRadialControllerScreenContact_DEFINED__
#define __WUIRadialControllerScreenContact_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRadialControllerScreenContact : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFRect* bounds;
@property (readonly) WFPoint* position;
@end

#endif // __WUIRadialControllerScreenContact_DEFINED__

// Windows.UI.Input.RadialControllerMenu
#ifndef __WUIRadialControllerMenu_DEFINED__
#define __WUIRadialControllerMenu_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRadialControllerMenu : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isEnabled;
@property (readonly) NSMutableArray* /* WUIRadialControllerMenuItem* */ items;
- (WUIRadialControllerMenuItem*)getSelectedMenuItem;
- (void)selectMenuItem:(WUIRadialControllerMenuItem*)menuItem;
- (BOOL)trySelectPreviouslySelectedMenuItem;
@end

#endif // __WUIRadialControllerMenu_DEFINED__

// Windows.UI.Input.RadialController
#ifndef __WUIRadialController_DEFINED__
#define __WUIRadialController_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRadialController : RTObject
+ (BOOL)isSupported;
+ (WUIRadialController*)createForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL useAutomaticHapticFeedback;
@property double rotationResolutionInDegrees;
@property (readonly) WUIRadialControllerMenu* menu;
- (EventRegistrationToken)addButtonClickedEvent:(void(^)(WUIRadialController*, WUIRadialControllerButtonClickedEventArgs*))del;
- (void)removeButtonClickedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addControlAcquiredEvent:(void(^)(WUIRadialController*, WUIRadialControllerControlAcquiredEventArgs*))del;
- (void)removeControlAcquiredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addControlLostEvent:(void(^)(WUIRadialController*, RTObject*))del;
- (void)removeControlLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRotationChangedEvent:(void(^)(WUIRadialController*, WUIRadialControllerRotationChangedEventArgs*))del;
- (void)removeRotationChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addScreenContactContinuedEvent:(void(^)(WUIRadialController*, WUIRadialControllerScreenContactContinuedEventArgs*))del;
- (void)removeScreenContactContinuedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addScreenContactEndedEvent:(void(^)(WUIRadialController*, RTObject*))del;
- (void)removeScreenContactEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addScreenContactStartedEvent:(void(^)(WUIRadialController*, WUIRadialControllerScreenContactStartedEventArgs*))del;
- (void)removeScreenContactStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addButtonHoldingEvent:(void(^)(WUIRadialController*, WUIRadialControllerButtonHoldingEventArgs*))del;
- (void)removeButtonHoldingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addButtonPressedEvent:(void(^)(WUIRadialController*, WUIRadialControllerButtonPressedEventArgs*))del;
- (void)removeButtonPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addButtonReleasedEvent:(void(^)(WUIRadialController*, WUIRadialControllerButtonReleasedEventArgs*))del;
- (void)removeButtonReleasedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUIRadialController_DEFINED__

// Windows.UI.Input.RadialControllerScreenContactStartedEventArgs
#ifndef __WUIRadialControllerScreenContactStartedEventArgs_DEFINED__
#define __WUIRadialControllerScreenContactStartedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRadialControllerScreenContactStartedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIRadialControllerScreenContact* contact;
@property (readonly) BOOL isButtonPressed;
@property (readonly) WDHSimpleHapticsController* simpleHapticsController;
@end

#endif // __WUIRadialControllerScreenContactStartedEventArgs_DEFINED__

// Windows.UI.Input.RadialControllerScreenContactContinuedEventArgs
#ifndef __WUIRadialControllerScreenContactContinuedEventArgs_DEFINED__
#define __WUIRadialControllerScreenContactContinuedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRadialControllerScreenContactContinuedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIRadialControllerScreenContact* contact;
@property (readonly) BOOL isButtonPressed;
@property (readonly) WDHSimpleHapticsController* simpleHapticsController;
@end

#endif // __WUIRadialControllerScreenContactContinuedEventArgs_DEFINED__

// Windows.UI.Input.RadialControllerRotationChangedEventArgs
#ifndef __WUIRadialControllerRotationChangedEventArgs_DEFINED__
#define __WUIRadialControllerRotationChangedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRadialControllerRotationChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIRadialControllerScreenContact* contact;
@property (readonly) double rotationDeltaInDegrees;
@property (readonly) BOOL isButtonPressed;
@property (readonly) WDHSimpleHapticsController* simpleHapticsController;
@end

#endif // __WUIRadialControllerRotationChangedEventArgs_DEFINED__

// Windows.UI.Input.RadialControllerButtonClickedEventArgs
#ifndef __WUIRadialControllerButtonClickedEventArgs_DEFINED__
#define __WUIRadialControllerButtonClickedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRadialControllerButtonClickedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIRadialControllerScreenContact* contact;
@property (readonly) WDHSimpleHapticsController* simpleHapticsController;
@end

#endif // __WUIRadialControllerButtonClickedEventArgs_DEFINED__

// Windows.UI.Input.RadialControllerControlAcquiredEventArgs
#ifndef __WUIRadialControllerControlAcquiredEventArgs_DEFINED__
#define __WUIRadialControllerControlAcquiredEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRadialControllerControlAcquiredEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIRadialControllerScreenContact* contact;
@property (readonly) BOOL isButtonPressed;
@property (readonly) WDHSimpleHapticsController* simpleHapticsController;
@end

#endif // __WUIRadialControllerControlAcquiredEventArgs_DEFINED__

// Windows.UI.Input.RadialControllerButtonPressedEventArgs
#ifndef __WUIRadialControllerButtonPressedEventArgs_DEFINED__
#define __WUIRadialControllerButtonPressedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRadialControllerButtonPressedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIRadialControllerScreenContact* contact;
@property (readonly) WDHSimpleHapticsController* simpleHapticsController;
@end

#endif // __WUIRadialControllerButtonPressedEventArgs_DEFINED__

// Windows.UI.Input.RadialControllerButtonHoldingEventArgs
#ifndef __WUIRadialControllerButtonHoldingEventArgs_DEFINED__
#define __WUIRadialControllerButtonHoldingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRadialControllerButtonHoldingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIRadialControllerScreenContact* contact;
@property (readonly) WDHSimpleHapticsController* simpleHapticsController;
@end

#endif // __WUIRadialControllerButtonHoldingEventArgs_DEFINED__

// Windows.UI.Input.RadialControllerButtonReleasedEventArgs
#ifndef __WUIRadialControllerButtonReleasedEventArgs_DEFINED__
#define __WUIRadialControllerButtonReleasedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRadialControllerButtonReleasedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIRadialControllerScreenContact* contact;
@property (readonly) WDHSimpleHapticsController* simpleHapticsController;
@end

#endif // __WUIRadialControllerButtonReleasedEventArgs_DEFINED__

// Windows.UI.Input.RadialControllerMenuItem
#ifndef __WUIRadialControllerMenuItem_DEFINED__
#define __WUIRadialControllerMenuItem_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRadialControllerMenuItem : RTObject
+ (WUIRadialControllerMenuItem*)createFromFontGlyph:(NSString *)displayText glyph:(NSString *)glyph fontFamily:(NSString *)fontFamily;
+ (WUIRadialControllerMenuItem*)createFromFontGlyphWithUri:(NSString *)displayText glyph:(NSString *)glyph fontFamily:(NSString *)fontFamily fontUri:(WFUri*)fontUri;
+ (WUIRadialControllerMenuItem*)createFromIcon:(NSString *)displayText icon:(WSSRandomAccessStreamReference*)icon;
+ (WUIRadialControllerMenuItem*)createFromKnownIcon:(NSString *)displayText value:(WUIRadialControllerMenuKnownIcon)value;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject* tag;
@property (readonly) NSString * displayText;
- (EventRegistrationToken)addInvokedEvent:(void(^)(WUIRadialControllerMenuItem*, RTObject*))del;
- (void)removeInvokedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUIRadialControllerMenuItem_DEFINED__

// Windows.UI.Input.RadialControllerConfiguration
#ifndef __WUIRadialControllerConfiguration_DEFINED__
#define __WUIRadialControllerConfiguration_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRadialControllerConfiguration : RTObject
+ (WUIRadialControllerConfiguration*)getForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isMenuSuppressed;
@property (retain) WUIRadialController* activeControllerWhenMenuIsSuppressed;
+ (BOOL)isAppControllerEnabled;
+ (void)setIsAppControllerEnabled:(BOOL)value;
+ (WUIRadialController*)appController;
+ (void)setAppController:(WUIRadialController*)value;
- (void)setDefaultMenuItems:(id<NSFastEnumeration> /* WUIRadialControllerSystemMenuItemKind */)buttons;
- (void)resetToDefaultMenuItems;
- (BOOL)trySelectDefaultMenuItem:(WUIRadialControllerSystemMenuItemKind)type;
@end

#endif // __WUIRadialControllerConfiguration_DEFINED__

// Windows.UI.Input.RadialControllerScreenContactEndedEventArgs
#ifndef __WUIRadialControllerScreenContactEndedEventArgs_DEFINED__
#define __WUIRadialControllerScreenContactEndedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WUIRadialControllerScreenContactEndedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isButtonPressed;
@property (readonly) WDHSimpleHapticsController* simpleHapticsController;
@end

#endif // __WUIRadialControllerScreenContactEndedEventArgs_DEFINED__

