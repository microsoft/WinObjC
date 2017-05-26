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

// WindowsUIInputSpatial.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
#define OBJCUWPWINDOWSUIINPUTSPATIALEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIInputSpatial.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUISSpatialInteractionSourceLocation, WUISSpatialPointerPose, WUISSpatialInteractionSource, WUISSpatialInteractionSourceProperties,
    WUISSpatialManipulationDelta, WUISSpatialInteractionSourceState, WUISSpatialGestureRecognizer, WUISSpatialRecognitionStartedEventArgs,
    WUISSpatialRecognitionEndedEventArgs, WUISSpatialTappedEventArgs, WUISSpatialHoldStartedEventArgs, WUISSpatialHoldCompletedEventArgs,
    WUISSpatialHoldCanceledEventArgs, WUISSpatialManipulationStartedEventArgs, WUISSpatialManipulationUpdatedEventArgs,
    WUISSpatialManipulationCompletedEventArgs, WUISSpatialManipulationCanceledEventArgs, WUISSpatialNavigationStartedEventArgs,
    WUISSpatialNavigationUpdatedEventArgs, WUISSpatialNavigationCompletedEventArgs, WUISSpatialNavigationCanceledEventArgs,
    WUISSpatialInteraction, WUISSpatialInteractionManager, WUISSpatialInteractionSourceEventArgs, WUISSpatialInteractionDetectedEventArgs;
@protocol WUISISpatialInteractionSourceLocation
, WUISISpatialInteractionSourceLocation2, WUISISpatialInteractionSource, WUISISpatialInteractionSourceProperties, WUISISpatialPointerPose,
    WUISISpatialPointerPoseStatics, WUISISpatialInteractionSourceState, WUISISpatialRecognitionStartedEventArgs,
    WUISISpatialRecognitionEndedEventArgs, WUISISpatialTappedEventArgs, WUISISpatialHoldStartedEventArgs,
    WUISISpatialHoldCompletedEventArgs, WUISISpatialHoldCanceledEventArgs, WUISISpatialManipulationDelta,
    WUISISpatialManipulationStartedEventArgs, WUISISpatialManipulationUpdatedEventArgs, WUISISpatialManipulationCompletedEventArgs,
    WUISISpatialManipulationCanceledEventArgs, WUISISpatialNavigationStartedEventArgs, WUISISpatialNavigationUpdatedEventArgs,
    WUISISpatialNavigationCompletedEventArgs, WUISISpatialNavigationCanceledEventArgs, WUISISpatialInteraction,
    WUISISpatialGestureRecognizer, WUISISpatialGestureRecognizerFactory, WUISISpatialInteractionDetectedEventArgs,
    WUISISpatialInteractionSourceEventArgs, WUISISpatialInteractionManager, WUISISpatialInteractionManagerStatics;

// Windows.UI.Input.Spatial.SpatialInteractionSourceKind
enum _WUISSpatialInteractionSourceKind {
    WUISSpatialInteractionSourceKindOther = 0,
    WUISSpatialInteractionSourceKindHand = 1,
    WUISSpatialInteractionSourceKindVoice = 2,
    WUISSpatialInteractionSourceKindController = 3,
};
typedef unsigned WUISSpatialInteractionSourceKind;

// Windows.UI.Input.Spatial.SpatialGestureSettings
enum _WUISSpatialGestureSettings {
    WUISSpatialGestureSettingsNone = 0,
    WUISSpatialGestureSettingsTap = 1,
    WUISSpatialGestureSettingsDoubleTap = 2,
    WUISSpatialGestureSettingsHold = 4,
    WUISSpatialGestureSettingsManipulationTranslate = 8,
    WUISSpatialGestureSettingsNavigationX = 16,
    WUISSpatialGestureSettingsNavigationY = 32,
    WUISSpatialGestureSettingsNavigationZ = 64,
    WUISSpatialGestureSettingsNavigationRailsX = 128,
    WUISSpatialGestureSettingsNavigationRailsY = 256,
    WUISSpatialGestureSettingsNavigationRailsZ = 512,
};
typedef unsigned WUISSpatialGestureSettings;

#include "WindowsPerceptionPeople.h"
#include "WindowsPerception.h"
#include "WindowsFoundationNumerics.h"
#include "WindowsPerceptionSpatial.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.UI.Input.Spatial.SpatialInteractionSourceLocation
#ifndef __WUISSpatialInteractionSourceLocation_DEFINED__
#define __WUISSpatialInteractionSourceLocation_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialInteractionSourceLocation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) id /* WFNVector3* */ position;
@property (readonly) id /* WFNVector3* */ velocity;
@property (readonly) id /* WFNQuaternion* */ orientation;
@end

#endif // __WUISSpatialInteractionSourceLocation_DEFINED__

// Windows.UI.Input.Spatial.SpatialPointerPose
#ifndef __WUISSpatialPointerPose_DEFINED__
#define __WUISSpatialPointerPose_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialPointerPose : RTObject
+ (WUISSpatialPointerPose*)tryGetAtTimestamp:(WPSSpatialCoordinateSystem*)coordinateSystem timestamp:(WPPerceptionTimestamp*)timestamp;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WPPHeadPose* head;
@property (readonly) WPPerceptionTimestamp* timestamp;
@end

#endif // __WUISSpatialPointerPose_DEFINED__

// Windows.UI.Input.Spatial.SpatialInteractionSource
#ifndef __WUISSpatialInteractionSource_DEFINED__
#define __WUISSpatialInteractionSource_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialInteractionSource : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int id;
@property (readonly) WUISSpatialInteractionSourceKind kind;
@end

#endif // __WUISSpatialInteractionSource_DEFINED__

// Windows.UI.Input.Spatial.SpatialInteractionSourceProperties
#ifndef __WUISSpatialInteractionSourceProperties_DEFINED__
#define __WUISSpatialInteractionSourceProperties_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialInteractionSourceProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) double sourceLossRisk;
- (id /* WFNVector3* */)tryGetSourceLossMitigationDirection:(WPSSpatialCoordinateSystem*)coordinateSystem;
- (WUISSpatialInteractionSourceLocation*)tryGetLocation:(WPSSpatialCoordinateSystem*)coordinateSystem;
@end

#endif // __WUISSpatialInteractionSourceProperties_DEFINED__

// Windows.UI.Input.Spatial.SpatialManipulationDelta
#ifndef __WUISSpatialManipulationDelta_DEFINED__
#define __WUISSpatialManipulationDelta_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialManipulationDelta : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WFNVector3* translation;
@end

#endif // __WUISSpatialManipulationDelta_DEFINED__

// Windows.UI.Input.Spatial.SpatialInteractionSourceState
#ifndef __WUISSpatialInteractionSourceState_DEFINED__
#define __WUISSpatialInteractionSourceState_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialInteractionSourceState : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isPressed;
@property (readonly) WUISSpatialInteractionSourceProperties* properties;
@property (readonly) WUISSpatialInteractionSource* source;
@property (readonly) WPPerceptionTimestamp* timestamp;
- (WUISSpatialPointerPose*)tryGetPointerPose:(WPSSpatialCoordinateSystem*)coordinateSystem;
@end

#endif // __WUISSpatialInteractionSourceState_DEFINED__

// Windows.UI.Input.Spatial.SpatialGestureRecognizer
#ifndef __WUISSpatialGestureRecognizer_DEFINED__
#define __WUISSpatialGestureRecognizer_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialGestureRecognizer : RTObject
+ (WUISSpatialGestureRecognizer*)make:(WUISSpatialGestureSettings)settings ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialGestureSettings gestureSettings;
- (EventRegistrationToken)addHoldCanceledEvent:(void (^)(WUISSpatialGestureRecognizer*, WUISSpatialHoldCanceledEventArgs*))del;
- (void)removeHoldCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHoldCompletedEvent:(void (^)(WUISSpatialGestureRecognizer*, WUISSpatialHoldCompletedEventArgs*))del;
- (void)removeHoldCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHoldStartedEvent:(void (^)(WUISSpatialGestureRecognizer*, WUISSpatialHoldStartedEventArgs*))del;
- (void)removeHoldStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationCanceledEvent:(void (^)(WUISSpatialGestureRecognizer*,
                                                                 WUISSpatialManipulationCanceledEventArgs*))del;
- (void)removeManipulationCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationCompletedEvent:(void (^)(WUISSpatialGestureRecognizer*,
                                                                  WUISSpatialManipulationCompletedEventArgs*))del;
- (void)removeManipulationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationStartedEvent:(void (^)(WUISSpatialGestureRecognizer*,
                                                                WUISSpatialManipulationStartedEventArgs*))del;
- (void)removeManipulationStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationUpdatedEvent:(void (^)(WUISSpatialGestureRecognizer*,
                                                                WUISSpatialManipulationUpdatedEventArgs*))del;
- (void)removeManipulationUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNavigationCanceledEvent:(void (^)(WUISSpatialGestureRecognizer*, WUISSpatialNavigationCanceledEventArgs*))del;
- (void)removeNavigationCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNavigationCompletedEvent:(void (^)(WUISSpatialGestureRecognizer*,
                                                                WUISSpatialNavigationCompletedEventArgs*))del;
- (void)removeNavigationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNavigationStartedEvent:(void (^)(WUISSpatialGestureRecognizer*, WUISSpatialNavigationStartedEventArgs*))del;
- (void)removeNavigationStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNavigationUpdatedEvent:(void (^)(WUISSpatialGestureRecognizer*, WUISSpatialNavigationUpdatedEventArgs*))del;
- (void)removeNavigationUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRecognitionEndedEvent:(void (^)(WUISSpatialGestureRecognizer*, WUISSpatialRecognitionEndedEventArgs*))del;
- (void)removeRecognitionEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRecognitionStartedEvent:(void (^)(WUISSpatialGestureRecognizer*, WUISSpatialRecognitionStartedEventArgs*))del;
- (void)removeRecognitionStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTappedEvent:(void (^)(WUISSpatialGestureRecognizer*, WUISSpatialTappedEventArgs*))del;
- (void)removeTappedEvent:(EventRegistrationToken)tok;
- (void)captureInteraction:(WUISSpatialInteraction*)interaction;
- (void)cancelPendingGestures;
- (BOOL)trySetGestureSettings:(WUISSpatialGestureSettings)settings;
@end

#endif // __WUISSpatialGestureRecognizer_DEFINED__

// Windows.UI.Input.Spatial.SpatialRecognitionStartedEventArgs
#ifndef __WUISSpatialRecognitionStartedEventArgs_DEFINED__
#define __WUISSpatialRecognitionStartedEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialRecognitionStartedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
- (WUISSpatialPointerPose*)tryGetPointerPose:(WPSSpatialCoordinateSystem*)coordinateSystem;
- (BOOL)isGesturePossible:(WUISSpatialGestureSettings)gesture;
@end

#endif // __WUISSpatialRecognitionStartedEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialRecognitionEndedEventArgs
#ifndef __WUISSpatialRecognitionEndedEventArgs_DEFINED__
#define __WUISSpatialRecognitionEndedEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialRecognitionEndedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
@end

#endif // __WUISSpatialRecognitionEndedEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialTappedEventArgs
#ifndef __WUISSpatialTappedEventArgs_DEFINED__
#define __WUISSpatialTappedEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialTappedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
@property (readonly) unsigned int tapCount;
- (WUISSpatialPointerPose*)tryGetPointerPose:(WPSSpatialCoordinateSystem*)coordinateSystem;
@end

#endif // __WUISSpatialTappedEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialHoldStartedEventArgs
#ifndef __WUISSpatialHoldStartedEventArgs_DEFINED__
#define __WUISSpatialHoldStartedEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialHoldStartedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
- (WUISSpatialPointerPose*)tryGetPointerPose:(WPSSpatialCoordinateSystem*)coordinateSystem;
@end

#endif // __WUISSpatialHoldStartedEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialHoldCompletedEventArgs
#ifndef __WUISSpatialHoldCompletedEventArgs_DEFINED__
#define __WUISSpatialHoldCompletedEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialHoldCompletedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
@end

#endif // __WUISSpatialHoldCompletedEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialHoldCanceledEventArgs
#ifndef __WUISSpatialHoldCanceledEventArgs_DEFINED__
#define __WUISSpatialHoldCanceledEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialHoldCanceledEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
@end

#endif // __WUISSpatialHoldCanceledEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialManipulationStartedEventArgs
#ifndef __WUISSpatialManipulationStartedEventArgs_DEFINED__
#define __WUISSpatialManipulationStartedEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialManipulationStartedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
- (WUISSpatialPointerPose*)tryGetPointerPose:(WPSSpatialCoordinateSystem*)coordinateSystem;
@end

#endif // __WUISSpatialManipulationStartedEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialManipulationUpdatedEventArgs
#ifndef __WUISSpatialManipulationUpdatedEventArgs_DEFINED__
#define __WUISSpatialManipulationUpdatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialManipulationUpdatedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
- (WUISSpatialManipulationDelta*)tryGetCumulativeDelta:(WPSSpatialCoordinateSystem*)coordinateSystem;
@end

#endif // __WUISSpatialManipulationUpdatedEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialManipulationCompletedEventArgs
#ifndef __WUISSpatialManipulationCompletedEventArgs_DEFINED__
#define __WUISSpatialManipulationCompletedEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialManipulationCompletedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
- (WUISSpatialManipulationDelta*)tryGetCumulativeDelta:(WPSSpatialCoordinateSystem*)coordinateSystem;
@end

#endif // __WUISSpatialManipulationCompletedEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialManipulationCanceledEventArgs
#ifndef __WUISSpatialManipulationCanceledEventArgs_DEFINED__
#define __WUISSpatialManipulationCanceledEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialManipulationCanceledEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
@end

#endif // __WUISSpatialManipulationCanceledEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialNavigationStartedEventArgs
#ifndef __WUISSpatialNavigationStartedEventArgs_DEFINED__
#define __WUISSpatialNavigationStartedEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialNavigationStartedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
@property (readonly) BOOL isNavigatingX;
@property (readonly) BOOL isNavigatingY;
@property (readonly) BOOL isNavigatingZ;
- (WUISSpatialPointerPose*)tryGetPointerPose:(WPSSpatialCoordinateSystem*)coordinateSystem;
@end

#endif // __WUISSpatialNavigationStartedEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialNavigationUpdatedEventArgs
#ifndef __WUISSpatialNavigationUpdatedEventArgs_DEFINED__
#define __WUISSpatialNavigationUpdatedEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialNavigationUpdatedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
@property (readonly) WFNVector3* normalizedOffset;
@end

#endif // __WUISSpatialNavigationUpdatedEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialNavigationCompletedEventArgs
#ifndef __WUISSpatialNavigationCompletedEventArgs_DEFINED__
#define __WUISSpatialNavigationCompletedEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialNavigationCompletedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
@property (readonly) WFNVector3* normalizedOffset;
@end

#endif // __WUISSpatialNavigationCompletedEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialNavigationCanceledEventArgs
#ifndef __WUISSpatialNavigationCanceledEventArgs_DEFINED__
#define __WUISSpatialNavigationCanceledEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialNavigationCanceledEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
@end

#endif // __WUISSpatialNavigationCanceledEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialInteraction
#ifndef __WUISSpatialInteraction_DEFINED__
#define __WUISSpatialInteraction_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialInteraction : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceState* sourceState;
@end

#endif // __WUISSpatialInteraction_DEFINED__

// Windows.UI.Input.Spatial.SpatialInteractionManager
#ifndef __WUISSpatialInteractionManager_DEFINED__
#define __WUISSpatialInteractionManager_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialInteractionManager : RTObject
+ (WUISSpatialInteractionManager*)getForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addInteractionDetectedEvent:(void (^)(WUISSpatialInteractionManager*,
                                                                WUISSpatialInteractionDetectedEventArgs*))del;
- (void)removeInteractionDetectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSourceDetectedEvent:(void (^)(WUISSpatialInteractionManager*, WUISSpatialInteractionSourceEventArgs*))del;
- (void)removeSourceDetectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSourceLostEvent:(void (^)(WUISSpatialInteractionManager*, WUISSpatialInteractionSourceEventArgs*))del;
- (void)removeSourceLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSourcePressedEvent:(void (^)(WUISSpatialInteractionManager*, WUISSpatialInteractionSourceEventArgs*))del;
- (void)removeSourcePressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSourceReleasedEvent:(void (^)(WUISSpatialInteractionManager*, WUISSpatialInteractionSourceEventArgs*))del;
- (void)removeSourceReleasedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSourceUpdatedEvent:(void (^)(WUISSpatialInteractionManager*, WUISSpatialInteractionSourceEventArgs*))del;
- (void)removeSourceUpdatedEvent:(EventRegistrationToken)tok;
- (NSArray* /* WUISSpatialInteractionSourceState* */)getDetectedSourcesAtTimestamp:(WPPerceptionTimestamp*)timeStamp;
@end

#endif // __WUISSpatialInteractionManager_DEFINED__

// Windows.UI.Input.Spatial.SpatialInteractionSourceEventArgs
#ifndef __WUISSpatialInteractionSourceEventArgs_DEFINED__
#define __WUISSpatialInteractionSourceEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialInteractionSourceEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteractionSourceState* state;
@end

#endif // __WUISSpatialInteractionSourceEventArgs_DEFINED__

// Windows.UI.Input.Spatial.SpatialInteractionDetectedEventArgs
#ifndef __WUISSpatialInteractionDetectedEventArgs_DEFINED__
#define __WUISSpatialInteractionDetectedEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTSPATIALEXPORT
@interface WUISSpatialInteractionDetectedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WUISSpatialInteraction* interaction;
@property (readonly) WUISSpatialInteractionSourceKind interactionSourceKind;
- (WUISSpatialPointerPose*)tryGetPointerPose:(WPSSpatialCoordinateSystem*)coordinateSystem;
@end

#endif // __WUISSpatialInteractionDetectedEventArgs_DEFINED__
