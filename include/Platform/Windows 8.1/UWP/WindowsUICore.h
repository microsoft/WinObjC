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

// WindowsUICore.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUCCoreDispatcher, WUCCoreCursor, WUCCoreWindow, WUCWindowActivatedEventArgs, WUCAutomationProviderRequestedEventArgs,
    WUCCharacterReceivedEventArgs, WUCCoreWindowEventArgs, WUCInputEnabledEventArgs, WUCKeyEventArgs, WUCPointerEventArgs,
    WUCTouchHitTestingEventArgs, WUCWindowSizeChangedEventArgs, WUCVisibilityChangedEventArgs, WUCIdleDispatchedHandlerArgs,
    WUCAcceleratorKeyEventArgs, WUCCoreAcceleratorKeys, WUCCoreWindowResizeManager, WUCCoreIndependentInputSource,
    WUCCoreComponentInputSource, WUCCoreWindowPopupShowingEventArgs, WUCCoreWindowDialog, WUCCoreWindowFlyout;
@class WUCCorePhysicalKeyStatus, WUCCoreProximityEvaluation;
@protocol WUCICoreWindowEventArgs
, WUCIAutomationProviderRequestedEventArgs, WUCICharacterReceivedEventArgs, WUCIInputEnabledEventArgs, WUCIKeyEventArgs,
    WUCIPointerEventArgs, WUCITouchHitTestingEventArgs, WUCIWindowActivatedEventArgs, WUCIWindowSizeChangedEventArgs,
    WUCIVisibilityChangedEventArgs, WUCICoreWindow, WUCICoreWindowStatic, WUCIAcceleratorKeyEventArgs, WUCICoreAcceleratorKeys,
    WUCICoreDispatcher, WUCICoreDispatcherWithTaskPriority, WUCIIdleDispatchedHandlerArgs, WUCICoreCursor, WUCICoreCursorFactory,
    WUCIInitializeWithCoreWindow, WUCICoreWindowResizeManager, WUCICoreWindowResizeManagerLayoutCapability,
    WUCICoreWindowResizeManagerStatics, WUCICoreInputSourceBase, WUCICorePointerInputSource, WUCICoreKeyboardInputSource,
    WUCICoreComponentFocusable, WUCICoreTouchHitTesting, WUCICoreWindowPopupShowingEventArgs, WUCICoreWindowDialog,
    WUCICoreWindowDialogFactory, WUCICoreWindowFlyout, WUCICoreWindowFlyoutFactory;

// Windows.UI.Core.CoreWindowActivationState
enum _WUCCoreWindowActivationState {
    WUCCoreWindowActivationStateCodeActivated = 0,
    WUCCoreWindowActivationStateDeactivated = 1,
    WUCCoreWindowActivationStatePointerActivated = 2,
};
typedef unsigned WUCCoreWindowActivationState;

// Windows.UI.Core.CoreCursorType
enum _WUCCoreCursorType {
    WUCCoreCursorTypeArrow = 0,
    WUCCoreCursorTypeCross = 1,
    WUCCoreCursorTypeCustom = 2,
    WUCCoreCursorTypeHand = 3,
    WUCCoreCursorTypeHelp = 4,
    WUCCoreCursorTypeIBeam = 5,
    WUCCoreCursorTypeSizeAll = 6,
    WUCCoreCursorTypeSizeNortheastSouthwest = 7,
    WUCCoreCursorTypeSizeNorthSouth = 8,
    WUCCoreCursorTypeSizeNorthwestSoutheast = 9,
    WUCCoreCursorTypeSizeWestEast = 10,
    WUCCoreCursorTypeUniversalNo = 11,
    WUCCoreCursorTypeUpArrow = 12,
    WUCCoreCursorTypeWait = 13,
};
typedef unsigned WUCCoreCursorType;

// Windows.UI.Core.CoreDispatcherPriority
enum _WUCCoreDispatcherPriority {
    WUCCoreDispatcherPriorityIdle = -2,
    WUCCoreDispatcherPriorityLow = -1,
    WUCCoreDispatcherPriorityNormal = 0,
    WUCCoreDispatcherPriorityHigh = 1,
};
typedef unsigned WUCCoreDispatcherPriority;

// Windows.UI.Core.CoreProcessEventsOption
enum _WUCCoreProcessEventsOption {
    WUCCoreProcessEventsOptionProcessOneAndAllPending = 0,
    WUCCoreProcessEventsOptionProcessOneIfPresent = 1,
    WUCCoreProcessEventsOptionProcessUntilQuit = 2,
    WUCCoreProcessEventsOptionProcessAllIfPresent = 3,
};
typedef unsigned WUCCoreProcessEventsOption;

// Windows.UI.Core.CoreWindowFlowDirection
enum _WUCCoreWindowFlowDirection {
    WUCCoreWindowFlowDirectionLeftToRight = 0,
    WUCCoreWindowFlowDirectionRightToLeft = 1,
};
typedef unsigned WUCCoreWindowFlowDirection;

// Windows.UI.Core.CoreVirtualKeyStates
enum _WUCCoreVirtualKeyStates {
    WUCCoreVirtualKeyStatesNone = 0,
    WUCCoreVirtualKeyStatesDown = 1,
    WUCCoreVirtualKeyStatesLocked = 2,
};
typedef unsigned WUCCoreVirtualKeyStates;

// Windows.UI.Core.CoreAcceleratorKeyEventType
enum _WUCCoreAcceleratorKeyEventType {
    WUCCoreAcceleratorKeyEventTypeCharacter = 2,
    WUCCoreAcceleratorKeyEventTypeDeadCharacter = 3,
    WUCCoreAcceleratorKeyEventTypeKeyDown = 0,
    WUCCoreAcceleratorKeyEventTypeKeyUp = 1,
    WUCCoreAcceleratorKeyEventTypeSystemCharacter = 6,
    WUCCoreAcceleratorKeyEventTypeSystemDeadCharacter = 7,
    WUCCoreAcceleratorKeyEventTypeSystemKeyDown = 4,
    WUCCoreAcceleratorKeyEventTypeSystemKeyUp = 5,
    WUCCoreAcceleratorKeyEventTypeUnicodeCharacter = 8,
};
typedef unsigned WUCCoreAcceleratorKeyEventType;

// Windows.UI.Core.CoreProximityEvaluationScore
enum _WUCCoreProximityEvaluationScore {
    WUCCoreProximityEvaluationScoreClosest = 0,
    WUCCoreProximityEvaluationScoreFarthest = 2147483647,
};
typedef unsigned WUCCoreProximityEvaluationScore;

// Windows.UI.Core.CoreInputDeviceTypes
enum _WUCCoreInputDeviceTypes {
    WUCCoreInputDeviceTypesNone = 0,
    WUCCoreInputDeviceTypesTouch = 1,
    WUCCoreInputDeviceTypesPen = 2,
    WUCCoreInputDeviceTypesMouse = 4,
};
typedef unsigned WUCCoreInputDeviceTypes;

#include "WindowsSystem.h"
#include "WindowsUIInput.h"
#include "WindowsFoundationCollections.h"
#include "WindowsUIPopups.h"
#include "WindowsFoundation.h"
// Windows.UI.Core.DispatchedHandler
#ifndef __WUCDispatchedHandler__DEFINED
#define __WUCDispatchedHandler__DEFINED
typedef void (^WUCDispatchedHandler)();
#endif // __WUCDispatchedHandler__DEFINED

// Windows.UI.Core.IdleDispatchedHandler
#ifndef __WUCIdleDispatchedHandler__DEFINED
#define __WUCIdleDispatchedHandler__DEFINED
typedef void (^WUCIdleDispatchedHandler)(WUCIdleDispatchedHandlerArgs* e);
#endif // __WUCIdleDispatchedHandler__DEFINED

// Windows.UI.Popups.UICommandInvokedHandler
#ifndef __WUPUICommandInvokedHandler__DEFINED
#define __WUPUICommandInvokedHandler__DEFINED
typedef void (^WUPUICommandInvokedHandler)(RTObject<WUPIUICommand>* command);
#endif // __WUPUICommandInvokedHandler__DEFINED

// [struct] Windows.UI.Core.CorePhysicalKeyStatus
WINRT_EXPORT
@interface WUCCorePhysicalKeyStatus : NSObject
+ (instancetype) new;
@property unsigned repeatCount;
@property unsigned scanCode;
@property BOOL isExtendedKey;
@property BOOL isMenuKeyDown;
@property BOOL wasKeyDown;
@property BOOL isKeyReleased;
@end

// [struct] Windows.UI.Core.CoreProximityEvaluation
WINRT_EXPORT
@interface WUCCoreProximityEvaluation : NSObject
+ (instancetype) new;
@property int score;
@property (copy) WFPoint* adjustedPoint;
@end

// Windows.UI.Core.DispatchedHandler
#ifndef __WUCDispatchedHandler__DEFINED
#define __WUCDispatchedHandler__DEFINED
typedef void (^WUCDispatchedHandler)();
#endif // __WUCDispatchedHandler__DEFINED

// Windows.UI.Core.IdleDispatchedHandler
#ifndef __WUCIdleDispatchedHandler__DEFINED
#define __WUCIdleDispatchedHandler__DEFINED
typedef void (^WUCIdleDispatchedHandler)(WUCIdleDispatchedHandlerArgs* e);
#endif // __WUCIdleDispatchedHandler__DEFINED

// Windows.UI.Core.ICoreWindowEventArgs
#ifndef __WUCICoreWindowEventArgs_DEFINED__
#define __WUCICoreWindowEventArgs_DEFINED__

@protocol WUCICoreWindowEventArgs
@property BOOL handled;
@end

#endif // __WUCICoreWindowEventArgs_DEFINED__

// Windows.UI.Core.ICoreWindow
#ifndef __WUCICoreWindow_DEFINED__
#define __WUCICoreWindow_DEFINED__

@protocol WUCICoreWindow
@property (readonly) RTObject* automationHostProvider;
@property (readonly) WFRect* bounds;
@property (readonly) RTObject<WFCIPropertySet>* customProperties;
@property (readonly) WUCCoreDispatcher* dispatcher;
@property WUCCoreWindowFlowDirection flowDirection;
@property BOOL isInputEnabled;
@property (copy) WUCCoreCursor* pointerCursor;
@property (readonly) WFPoint* pointerPosition;
@property (readonly) BOOL visible;
- (EventRegistrationToken)addActivatedEvent:(void (^)(WUCCoreWindow*, WUCWindowActivatedEventArgs*))del;
- (void)removeActivatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAutomationProviderRequestedEvent:(void (^)(WUCCoreWindow*, WUCAutomationProviderRequestedEventArgs*))del;
- (void)removeAutomationProviderRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCharacterReceivedEvent:(void (^)(WUCCoreWindow*, WUCCharacterReceivedEventArgs*))del;
- (void)removeCharacterReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addClosedEvent:(void (^)(WUCCoreWindow*, WUCCoreWindowEventArgs*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addInputEnabledEvent:(void (^)(WUCCoreWindow*, WUCInputEnabledEventArgs*))del;
- (void)removeInputEnabledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyDownEvent:(void (^)(WUCCoreWindow*, WUCKeyEventArgs*))del;
- (void)removeKeyDownEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyUpEvent:(void (^)(WUCCoreWindow*, WUCKeyEventArgs*))del;
- (void)removeKeyUpEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerCaptureLostEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))del;
- (void)removePointerCaptureLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerEnteredEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))del;
- (void)removePointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerExitedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))del;
- (void)removePointerExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerMovedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))del;
- (void)removePointerMovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerPressedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))del;
- (void)removePointerPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerReleasedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))del;
- (void)removePointerReleasedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerWheelChangedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))del;
- (void)removePointerWheelChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSizeChangedEvent:(void (^)(WUCCoreWindow*, WUCWindowSizeChangedEventArgs*))del;
- (void)removeSizeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTouchHitTestingEvent:(void (^)(WUCCoreWindow*, WUCTouchHitTestingEventArgs*))del;
- (void)removeTouchHitTestingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVisibilityChangedEvent:(void (^)(WUCCoreWindow*, WUCVisibilityChangedEventArgs*))del;
- (void)removeVisibilityChangedEvent:(EventRegistrationToken)tok;
- (void)activate;
- (void)close;
- (WUCCoreVirtualKeyStates)getAsyncKeyState:(WSVirtualKey)virtualKey;
- (WUCCoreVirtualKeyStates)getKeyState:(WSVirtualKey)virtualKey;
- (void)releasePointerCapture;
- (void)setPointerCapture;
@end

#endif // __WUCICoreWindow_DEFINED__

// Windows.UI.Core.ICoreAcceleratorKeys
#ifndef __WUCICoreAcceleratorKeys_DEFINED__
#define __WUCICoreAcceleratorKeys_DEFINED__

@protocol WUCICoreAcceleratorKeys
- (EventRegistrationToken)addAcceleratorKeyActivatedEvent:(void (^)(WUCCoreDispatcher*, WUCAcceleratorKeyEventArgs*))del;
- (void)removeAcceleratorKeyActivatedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUCICoreAcceleratorKeys_DEFINED__

// Windows.UI.Core.IInitializeWithCoreWindow
#ifndef __WUCIInitializeWithCoreWindow_DEFINED__
#define __WUCIInitializeWithCoreWindow_DEFINED__

@protocol WUCIInitializeWithCoreWindow
- (void)initialize:(WUCCoreWindow*)window;
@end

#endif // __WUCIInitializeWithCoreWindow_DEFINED__

// Windows.UI.Core.ICoreInputSourceBase
#ifndef __WUCICoreInputSourceBase_DEFINED__
#define __WUCICoreInputSourceBase_DEFINED__

@protocol WUCICoreInputSourceBase
@property (readonly) WUCCoreDispatcher* dispatcher;
@property BOOL isInputEnabled;
- (EventRegistrationToken)addInputEnabledEvent:(void (^)(RTObject*, WUCInputEnabledEventArgs*))del;
- (void)removeInputEnabledEvent:(EventRegistrationToken)tok;
@end

#endif // __WUCICoreInputSourceBase_DEFINED__

// Windows.UI.Core.ICorePointerInputSource
#ifndef __WUCICorePointerInputSource_DEFINED__
#define __WUCICorePointerInputSource_DEFINED__

@protocol WUCICorePointerInputSource
@property (readonly) BOOL hasCapture;
@property (copy) WUCCoreCursor* pointerCursor;
@property (readonly) WFPoint* pointerPosition;
- (EventRegistrationToken)addPointerCaptureLostEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerCaptureLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerEnteredEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerExitedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerMovedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerMovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerPressedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerReleasedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerReleasedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerWheelChangedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerWheelChangedEvent:(EventRegistrationToken)tok;
- (void)releasePointerCapture;
- (void)setPointerCapture;
@end

#endif // __WUCICorePointerInputSource_DEFINED__

// Windows.UI.Core.CoreDispatcher
#ifndef __WUCCoreDispatcher_DEFINED__
#define __WUCCoreDispatcher_DEFINED__

WINRT_EXPORT
@interface WUCCoreDispatcher : RTObject <WUCICoreAcceleratorKeys>
@property (readonly) BOOL hasThreadAccess;
@property WUCCoreDispatcherPriority currentPriority;
- (EventRegistrationToken)addAcceleratorKeyActivatedEvent:(void (^)(WUCCoreDispatcher*, WUCAcceleratorKeyEventArgs*))del;
- (void)removeAcceleratorKeyActivatedEvent:(EventRegistrationToken)tok;
- (void)processEvents:(WUCCoreProcessEventsOption)options;
- (RTObject<WFIAsyncAction>*)runAsync:(WUCCoreDispatcherPriority)priority agileCallback:(WUCDispatchedHandler)agileCallback;
- (RTObject<WFIAsyncAction>*)runIdleAsync:(WUCIdleDispatchedHandler)agileCallback;
- (BOOL)shouldYield;
- (BOOL)shouldYieldToPriority:(WUCCoreDispatcherPriority)priority;
- (void)stopProcessEvents;
@end

#endif // __WUCCoreDispatcher_DEFINED__

// Windows.UI.Core.CoreCursor
#ifndef __WUCCoreCursor_DEFINED__
#define __WUCCoreCursor_DEFINED__

WINRT_EXPORT
@interface WUCCoreCursor : RTObject
+ (WUCCoreCursor*)createCursor:(WUCCoreCursorType)type id:(unsigned)id ACTIVATOR;
@property (readonly) unsigned id;
@property (readonly) WUCCoreCursorType type;
@end

#endif // __WUCCoreCursor_DEFINED__

// Windows.UI.Core.CoreWindow
#ifndef __WUCCoreWindow_DEFINED__
#define __WUCCoreWindow_DEFINED__

WINRT_EXPORT
@interface WUCCoreWindow : RTObject <WUCICoreWindow>
+ (WUCCoreWindow*)getForCurrentThread;
@property (copy) WUCCoreCursor* pointerCursor;
@property BOOL isInputEnabled;
@property WUCCoreWindowFlowDirection flowDirection;
@property (readonly) RTObject* automationHostProvider;
@property (readonly) WFRect* bounds;
@property (readonly) RTObject<WFCIPropertySet>* customProperties;
@property (readonly) WUCCoreDispatcher* dispatcher;
@property (readonly) WFPoint* pointerPosition;
@property (readonly) BOOL visible;
- (EventRegistrationToken)addActivatedEvent:(void (^)(WUCCoreWindow*, WUCWindowActivatedEventArgs*))del;
- (void)removeActivatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAutomationProviderRequestedEvent:(void (^)(WUCCoreWindow*, WUCAutomationProviderRequestedEventArgs*))del;
- (void)removeAutomationProviderRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCharacterReceivedEvent:(void (^)(WUCCoreWindow*, WUCCharacterReceivedEventArgs*))del;
- (void)removeCharacterReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addClosedEvent:(void (^)(WUCCoreWindow*, WUCCoreWindowEventArgs*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addInputEnabledEvent:(void (^)(WUCCoreWindow*, WUCInputEnabledEventArgs*))del;
- (void)removeInputEnabledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyDownEvent:(void (^)(WUCCoreWindow*, WUCKeyEventArgs*))del;
- (void)removeKeyDownEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyUpEvent:(void (^)(WUCCoreWindow*, WUCKeyEventArgs*))del;
- (void)removeKeyUpEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerCaptureLostEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))del;
- (void)removePointerCaptureLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerEnteredEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))del;
- (void)removePointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerExitedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))del;
- (void)removePointerExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerMovedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))del;
- (void)removePointerMovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerPressedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))del;
- (void)removePointerPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerReleasedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))del;
- (void)removePointerReleasedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerWheelChangedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))del;
- (void)removePointerWheelChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSizeChangedEvent:(void (^)(WUCCoreWindow*, WUCWindowSizeChangedEventArgs*))del;
- (void)removeSizeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTouchHitTestingEvent:(void (^)(WUCCoreWindow*, WUCTouchHitTestingEventArgs*))del;
- (void)removeTouchHitTestingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVisibilityChangedEvent:(void (^)(WUCCoreWindow*, WUCVisibilityChangedEventArgs*))del;
- (void)removeVisibilityChangedEvent:(EventRegistrationToken)tok;
- (void)activate;
- (void)close;
- (WUCCoreVirtualKeyStates)getAsyncKeyState:(WSVirtualKey)virtualKey;
- (WUCCoreVirtualKeyStates)getKeyState:(WSVirtualKey)virtualKey;
- (void)releasePointerCapture;
- (void)setPointerCapture;
@end

#endif // __WUCCoreWindow_DEFINED__

// Windows.UI.Core.WindowActivatedEventArgs
#ifndef __WUCWindowActivatedEventArgs_DEFINED__
#define __WUCWindowActivatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUCWindowActivatedEventArgs : RTObject <WUCICoreWindowEventArgs>
@property (readonly) WUCCoreWindowActivationState windowActivationState;
@property BOOL handled;
@end

#endif // __WUCWindowActivatedEventArgs_DEFINED__

// Windows.UI.Core.AutomationProviderRequestedEventArgs
#ifndef __WUCAutomationProviderRequestedEventArgs_DEFINED__
#define __WUCAutomationProviderRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUCAutomationProviderRequestedEventArgs : RTObject <WUCICoreWindowEventArgs>
@property BOOL handled;
@property (copy) RTObject* automationProvider;
@end

#endif // __WUCAutomationProviderRequestedEventArgs_DEFINED__

// Windows.UI.Core.CharacterReceivedEventArgs
#ifndef __WUCCharacterReceivedEventArgs_DEFINED__
#define __WUCCharacterReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUCCharacterReceivedEventArgs : RTObject <WUCICoreWindowEventArgs>
@property BOOL handled;
@property (readonly) unsigned keyCode;
@property (readonly) WUCCorePhysicalKeyStatus* keyStatus;
@end

#endif // __WUCCharacterReceivedEventArgs_DEFINED__

// Windows.UI.Core.CoreWindowEventArgs
#ifndef __WUCCoreWindowEventArgs_DEFINED__
#define __WUCCoreWindowEventArgs_DEFINED__

WINRT_EXPORT
@interface WUCCoreWindowEventArgs : RTObject <WUCICoreWindowEventArgs>
@property BOOL handled;
@end

#endif // __WUCCoreWindowEventArgs_DEFINED__

// Windows.UI.Core.InputEnabledEventArgs
#ifndef __WUCInputEnabledEventArgs_DEFINED__
#define __WUCInputEnabledEventArgs_DEFINED__

WINRT_EXPORT
@interface WUCInputEnabledEventArgs : RTObject <WUCICoreWindowEventArgs>
@property (readonly) BOOL inputEnabled;
@property BOOL handled;
@end

#endif // __WUCInputEnabledEventArgs_DEFINED__

// Windows.UI.Core.KeyEventArgs
#ifndef __WUCKeyEventArgs_DEFINED__
#define __WUCKeyEventArgs_DEFINED__

WINRT_EXPORT
@interface WUCKeyEventArgs : RTObject <WUCICoreWindowEventArgs>
@property (readonly) WUCCorePhysicalKeyStatus* keyStatus;
@property (readonly) WSVirtualKey virtualKey;
@property BOOL handled;
@end

#endif // __WUCKeyEventArgs_DEFINED__

// Windows.UI.Core.PointerEventArgs
#ifndef __WUCPointerEventArgs_DEFINED__
#define __WUCPointerEventArgs_DEFINED__

WINRT_EXPORT
@interface WUCPointerEventArgs : RTObject <WUCICoreWindowEventArgs>
@property (readonly) WUIPointerPoint* currentPoint;
@property (readonly) WSVirtualKeyModifiers keyModifiers;
@property BOOL handled;
- (id<NSFastEnumeration> /*WUIPointerPoint*/)getIntermediatePoints;
@end

#endif // __WUCPointerEventArgs_DEFINED__

// Windows.UI.Core.TouchHitTestingEventArgs
#ifndef __WUCTouchHitTestingEventArgs_DEFINED__
#define __WUCTouchHitTestingEventArgs_DEFINED__

WINRT_EXPORT
@interface WUCTouchHitTestingEventArgs : RTObject <WUCICoreWindowEventArgs>
@property (copy) WUCCoreProximityEvaluation* proximityEvaluation;
@property (readonly) WFRect* boundingBox;
@property (readonly) WFPoint* point;
@property BOOL handled;
- (WUCCoreProximityEvaluation*)evaluateProximityToRect:(WFRect*)controlBoundingBox;
- (WUCCoreProximityEvaluation*)evaluateProximityToPolygon:(id<NSFastEnumeration> /*WFPoint*/)controlVertices;
@end

#endif // __WUCTouchHitTestingEventArgs_DEFINED__

// Windows.UI.Core.WindowSizeChangedEventArgs
#ifndef __WUCWindowSizeChangedEventArgs_DEFINED__
#define __WUCWindowSizeChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUCWindowSizeChangedEventArgs : RTObject <WUCICoreWindowEventArgs>
@property BOOL handled;
@property (readonly) WFSize* size;
@end

#endif // __WUCWindowSizeChangedEventArgs_DEFINED__

// Windows.UI.Core.VisibilityChangedEventArgs
#ifndef __WUCVisibilityChangedEventArgs_DEFINED__
#define __WUCVisibilityChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUCVisibilityChangedEventArgs : RTObject <WUCICoreWindowEventArgs>
@property (readonly) BOOL visible;
@property BOOL handled;
@end

#endif // __WUCVisibilityChangedEventArgs_DEFINED__

// Windows.UI.Core.IdleDispatchedHandlerArgs
#ifndef __WUCIdleDispatchedHandlerArgs_DEFINED__
#define __WUCIdleDispatchedHandlerArgs_DEFINED__

WINRT_EXPORT
@interface WUCIdleDispatchedHandlerArgs : RTObject
@property (readonly) BOOL isDispatcherIdle;
@end

#endif // __WUCIdleDispatchedHandlerArgs_DEFINED__

// Windows.UI.Core.AcceleratorKeyEventArgs
#ifndef __WUCAcceleratorKeyEventArgs_DEFINED__
#define __WUCAcceleratorKeyEventArgs_DEFINED__

WINRT_EXPORT
@interface WUCAcceleratorKeyEventArgs : RTObject <WUCICoreWindowEventArgs>
@property BOOL handled;
@property (readonly) WUCCoreAcceleratorKeyEventType eventType;
@property (readonly) WUCCorePhysicalKeyStatus* keyStatus;
@property (readonly) WSVirtualKey virtualKey;
@end

#endif // __WUCAcceleratorKeyEventArgs_DEFINED__

// Windows.UI.Core.CoreAcceleratorKeys
#ifndef __WUCCoreAcceleratorKeys_DEFINED__
#define __WUCCoreAcceleratorKeys_DEFINED__

WINRT_EXPORT
@interface WUCCoreAcceleratorKeys : RTObject <WUCICoreAcceleratorKeys>
- (EventRegistrationToken)addAcceleratorKeyActivatedEvent:(void (^)(WUCCoreDispatcher*, WUCAcceleratorKeyEventArgs*))del;
- (void)removeAcceleratorKeyActivatedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUCCoreAcceleratorKeys_DEFINED__

// Windows.UI.Core.CoreWindowResizeManager
#ifndef __WUCCoreWindowResizeManager_DEFINED__
#define __WUCCoreWindowResizeManager_DEFINED__

WINRT_EXPORT
@interface WUCCoreWindowResizeManager : RTObject
+ (WUCCoreWindowResizeManager*)getForCurrentView;
@property BOOL shouldWaitForLayoutCompletion;
- (void)notifyLayoutCompleted;
@end

#endif // __WUCCoreWindowResizeManager_DEFINED__

// Windows.UI.Core.CoreIndependentInputSource
#ifndef __WUCCoreIndependentInputSource_DEFINED__
#define __WUCCoreIndependentInputSource_DEFINED__

WINRT_EXPORT
@interface WUCCoreIndependentInputSource : RTObject <WUCICoreInputSourceBase, WUCICorePointerInputSource>
@property BOOL isInputEnabled;
@property (readonly) WUCCoreDispatcher* dispatcher;
@property (copy) WUCCoreCursor* pointerCursor;
@property (readonly) BOOL hasCapture;
@property (readonly) WFPoint* pointerPosition;
- (EventRegistrationToken)addInputEnabledEvent:(void (^)(RTObject*, WUCInputEnabledEventArgs*))del;
- (void)removeInputEnabledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerCaptureLostEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerCaptureLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerEnteredEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerExitedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerMovedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerMovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerPressedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerReleasedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerReleasedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerWheelChangedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerWheelChangedEvent:(EventRegistrationToken)tok;
- (void)releasePointerCapture;
- (void)setPointerCapture;
@end

#endif // __WUCCoreIndependentInputSource_DEFINED__

// Windows.UI.Core.CoreComponentInputSource
#ifndef __WUCCoreComponentInputSource_DEFINED__
#define __WUCCoreComponentInputSource_DEFINED__

WINRT_EXPORT
@interface WUCCoreComponentInputSource : RTObject <WUCICoreInputSourceBase, WUCICorePointerInputSource>
@property (copy) WUCCoreCursor* pointerCursor;
@property (readonly) BOOL hasCapture;
@property (readonly) WFPoint* pointerPosition;
@property (readonly) BOOL hasFocus;
@property BOOL isInputEnabled;
@property (readonly) WUCCoreDispatcher* dispatcher;
- (EventRegistrationToken)addInputEnabledEvent:(void (^)(RTObject*, WUCInputEnabledEventArgs*))del;
- (void)removeInputEnabledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerCaptureLostEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerCaptureLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerEnteredEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerExitedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerMovedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerMovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerPressedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerReleasedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerReleasedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerWheelChangedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))del;
- (void)removePointerWheelChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCharacterReceivedEvent:(void (^)(RTObject*, WUCCharacterReceivedEventArgs*))del;
- (void)removeCharacterReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyDownEvent:(void (^)(RTObject*, WUCKeyEventArgs*))del;
- (void)removeKeyDownEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyUpEvent:(void (^)(RTObject*, WUCKeyEventArgs*))del;
- (void)removeKeyUpEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addGotFocusEvent:(void (^)(RTObject*, WUCCoreWindowEventArgs*))del;
- (void)removeGotFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLostFocusEvent:(void (^)(RTObject*, WUCCoreWindowEventArgs*))del;
- (void)removeLostFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTouchHitTestingEvent:(void (^)(RTObject*, WUCTouchHitTestingEventArgs*))del;
- (void)removeTouchHitTestingEvent:(EventRegistrationToken)tok;
- (void)releasePointerCapture;
- (void)setPointerCapture;
- (WUCCoreVirtualKeyStates)getCurrentKeyState:(WSVirtualKey)virtualKey;
@end

#endif // __WUCCoreComponentInputSource_DEFINED__

// Windows.UI.Core.CoreWindowPopupShowingEventArgs
#ifndef __WUCCoreWindowPopupShowingEventArgs_DEFINED__
#define __WUCCoreWindowPopupShowingEventArgs_DEFINED__

WINRT_EXPORT
@interface WUCCoreWindowPopupShowingEventArgs : RTObject
- (void)setDesiredSize:(WFSize*)value;
@end

#endif // __WUCCoreWindowPopupShowingEventArgs_DEFINED__

// Windows.UI.Core.CoreWindowDialog
#ifndef __WUCCoreWindowDialog_DEFINED__
#define __WUCCoreWindowDialog_DEFINED__

WINRT_EXPORT
@interface WUCCoreWindowDialog : RTObject
+ (WUCCoreWindowDialog*)createWithTitle:(NSString*)title ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* title;
@property int isInteractionDelayed;
@property unsigned defaultCommandIndex;
@property unsigned cancelCommandIndex;
@property (copy) WUPUICommandInvokedHandler backButtonCommand;
@property (readonly) id<NSFastEnumeration> /*WUPIUICommand*/ commands;
@property (readonly) WFSize* maxSize;
@property (readonly) WFSize* minSize;
- (EventRegistrationToken)addShowingEvent:(void (^)(WUCCoreWindow*, WUCCoreWindowPopupShowingEventArgs*))del;
- (void)removeShowingEvent:(EventRegistrationToken)tok;
- (void)showAsyncWithSuccess:(void (^)(RTObject<WUPIUICommand>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WUCCoreWindowDialog_DEFINED__

// Windows.UI.Core.CoreWindowFlyout
#ifndef __WUCCoreWindowFlyout_DEFINED__
#define __WUCCoreWindowFlyout_DEFINED__

WINRT_EXPORT
@interface WUCCoreWindowFlyout : RTObject
+ (WUCCoreWindowFlyout*)create:(WFPoint*)position ACTIVATOR;
+ (WUCCoreWindowFlyout*)createWithTitle:(WFPoint*)position title:(NSString*)title ACTIVATOR;
@property (copy) NSString* title;
@property int isInteractionDelayed;
@property unsigned defaultCommandIndex;
@property (copy) WUPUICommandInvokedHandler backButtonCommand;
@property (readonly) id<NSFastEnumeration> /*WUPIUICommand*/ commands;
@property (readonly) WFSize* maxSize;
@property (readonly) WFSize* minSize;
- (EventRegistrationToken)addShowingEvent:(void (^)(WUCCoreWindow*, WUCCoreWindowPopupShowingEventArgs*))del;
- (void)removeShowingEvent:(EventRegistrationToken)tok;
- (void)showAsyncWithSuccess:(void (^)(RTObject<WUPIUICommand>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WUCCoreWindowFlyout_DEFINED__
