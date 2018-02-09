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

// WindowsUIXamlInput.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIXAMLEXPORT
#define OBJCUWPWINDOWSUIXAMLEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIXaml.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUXIPointer, WUXIAccessKeyDisplayRequestedEventArgs, WUXIAccessKeyDisplayDismissedEventArgs, WUXIAccessKeyInvokedEventArgs, WUXIProcessKeyboardAcceleratorEventArgs, WUXIAccessKeyManager, WUXIInertiaExpansionBehavior, WUXIInertiaRotationBehavior, WUXIInertiaTranslationBehavior, WUXIKeyboardAcceleratorInvokedEventArgs, WUXIManipulationPivot, WUXICharacterReceivedRoutedEventArgs, WUXIContextRequestedEventArgs, WUXIDoubleTappedRoutedEventArgs, WUXIGettingFocusEventArgs, WUXIHoldingRoutedEventArgs, WUXIInputScope, WUXIInputScopeName, WUXIKeyboardAccelerator, WUXIKeyRoutedEventArgs, WUXILosingFocusEventArgs, WUXIManipulationCompletedRoutedEventArgs, WUXIManipulationDeltaRoutedEventArgs, WUXIManipulationInertiaStartingRoutedEventArgs, WUXIManipulationStartedRoutedEventArgs, WUXIManipulationStartingRoutedEventArgs, WUXINoFocusCandidateFoundEventArgs, WUXIPointerRoutedEventArgs, WUXIRightTappedRoutedEventArgs, WUXITappedRoutedEventArgs, WUXIFindNextElementOptions, WUXIFocusManager;
@protocol WUXIICommand, WUXIIAccessKeyDisplayDismissedEventArgs, WUXIIAccessKeyDisplayRequestedEventArgs, WUXIIAccessKeyInvokedEventArgs, WUXIIAccessKeyManager, WUXIIAccessKeyManagerStatics, WUXIIAccessKeyManagerStatics2, WUXIIInertiaExpansionBehavior, WUXIIInertiaRotationBehavior, WUXIIInertiaTranslationBehavior, WUXIIKeyboardAcceleratorInvokedEventArgs, WUXIIManipulationPivot, WUXIIManipulationPivotFactory, WUXIIPointer, WUXIIProcessKeyboardAcceleratorEventArgs, WUXIICharacterReceivedRoutedEventArgs, WUXIIContextRequestedEventArgs, WUXIIDoubleTappedRoutedEventArgs, WUXIIGettingFocusEventArgs, WUXIIHoldingRoutedEventArgs, WUXIIInputScope, WUXIIInputScopeName, WUXIIInputScopeNameFactory, WUXIIKeyboardAccelerator, WUXIIKeyboardAcceleratorStatics, WUXIIKeyboardAcceleratorFactory, WUXIIKeyRoutedEventArgs, WUXIIKeyRoutedEventArgs2, WUXIIKeyRoutedEventArgs3, WUXIILosingFocusEventArgs, WUXIIManipulationCompletedRoutedEventArgs, WUXIIManipulationDeltaRoutedEventArgs, WUXIIManipulationInertiaStartingRoutedEventArgs, WUXIIManipulationStartedRoutedEventArgs, WUXIIManipulationStartedRoutedEventArgsFactory, WUXIIManipulationStartingRoutedEventArgs, WUXIINoFocusCandidateFoundEventArgs, WUXIIPointerRoutedEventArgs, WUXIIPointerRoutedEventArgs2, WUXIIRightTappedRoutedEventArgs, WUXIITappedRoutedEventArgs, WUXIIFindNextElementOptions, WUXIIFocusManager, WUXIIFocusManagerStatics, WUXIIFocusManagerStatics2, WUXIIFocusManagerStatics3, WUXIIFocusManagerStatics4;

// Windows.UI.Xaml.Input.FocusInputDeviceKind
enum _WUXIFocusInputDeviceKind {
    WUXIFocusInputDeviceKindNone = 0,
    WUXIFocusInputDeviceKindMouse = 1,
    WUXIFocusInputDeviceKindTouch = 2,
    WUXIFocusInputDeviceKindPen = 3,
    WUXIFocusInputDeviceKindKeyboard = 4,
    WUXIFocusInputDeviceKindGameController = 5,
};
typedef unsigned WUXIFocusInputDeviceKind;

// Windows.UI.Xaml.Input.FocusNavigationDirection
enum _WUXIFocusNavigationDirection {
    WUXIFocusNavigationDirectionNext = 0,
    WUXIFocusNavigationDirectionPrevious = 1,
    WUXIFocusNavigationDirectionUp = 2,
    WUXIFocusNavigationDirectionDown = 3,
    WUXIFocusNavigationDirectionLeft = 4,
    WUXIFocusNavigationDirectionRight = 5,
    WUXIFocusNavigationDirectionNone = 6,
};
typedef unsigned WUXIFocusNavigationDirection;

// Windows.UI.Xaml.Input.InputScopeNameValue
enum _WUXIInputScopeNameValue {
    WUXIInputScopeNameValueDefault = 0,
    WUXIInputScopeNameValueUrl = 1,
    WUXIInputScopeNameValueEmailSmtpAddress = 5,
    WUXIInputScopeNameValuePersonalFullName = 7,
    WUXIInputScopeNameValueCurrencyAmountAndSymbol = 20,
    WUXIInputScopeNameValueCurrencyAmount = 21,
    WUXIInputScopeNameValueDateMonthNumber = 23,
    WUXIInputScopeNameValueDateDayNumber = 24,
    WUXIInputScopeNameValueDateYear = 25,
    WUXIInputScopeNameValueDigits = 28,
    WUXIInputScopeNameValueNumber = 29,
    WUXIInputScopeNameValuePassword = 31,
    WUXIInputScopeNameValueTelephoneNumber = 32,
    WUXIInputScopeNameValueTelephoneCountryCode = 33,
    WUXIInputScopeNameValueTelephoneAreaCode = 34,
    WUXIInputScopeNameValueTelephoneLocalNumber = 35,
    WUXIInputScopeNameValueTimeHour = 37,
    WUXIInputScopeNameValueTimeMinutesOrSeconds = 38,
    WUXIInputScopeNameValueNumberFullWidth = 39,
    WUXIInputScopeNameValueAlphanumericHalfWidth = 40,
    WUXIInputScopeNameValueAlphanumericFullWidth = 41,
    WUXIInputScopeNameValueHiragana = 44,
    WUXIInputScopeNameValueKatakanaHalfWidth = 45,
    WUXIInputScopeNameValueKatakanaFullWidth = 46,
    WUXIInputScopeNameValueHanja = 47,
    WUXIInputScopeNameValueHangulHalfWidth = 48,
    WUXIInputScopeNameValueHangulFullWidth = 49,
    WUXIInputScopeNameValueSearch = 50,
    WUXIInputScopeNameValueFormula = 51,
    WUXIInputScopeNameValueSearchIncremental = 52,
    WUXIInputScopeNameValueChineseHalfWidth = 53,
    WUXIInputScopeNameValueChineseFullWidth = 54,
    WUXIInputScopeNameValueNativeScript = 55,
    WUXIInputScopeNameValueText = 57,
    WUXIInputScopeNameValueChat = 58,
    WUXIInputScopeNameValueNameOrPhoneNumber = 59,
    WUXIInputScopeNameValueEmailNameOrAddress = 60,
    WUXIInputScopeNameValueMaps = 62,
    WUXIInputScopeNameValueNumericPassword = 63,
    WUXIInputScopeNameValueNumericPin = 64,
    WUXIInputScopeNameValueAlphanumericPin = 65,
    WUXIInputScopeNameValueFormulaNumber = 67,
    WUXIInputScopeNameValueChatWithoutEmoji = 68,
};
typedef unsigned WUXIInputScopeNameValue;

// Windows.UI.Xaml.Input.KeyboardNavigationMode
enum _WUXIKeyboardNavigationMode {
    WUXIKeyboardNavigationModeLocal = 0,
    WUXIKeyboardNavigationModeCycle = 1,
    WUXIKeyboardNavigationModeOnce = 2,
};
typedef unsigned WUXIKeyboardNavigationMode;

// Windows.UI.Xaml.Input.KeyTipPlacementMode
enum _WUXIKeyTipPlacementMode {
    WUXIKeyTipPlacementModeAuto = 0,
    WUXIKeyTipPlacementModeBottom = 1,
    WUXIKeyTipPlacementModeTop = 2,
    WUXIKeyTipPlacementModeLeft = 3,
    WUXIKeyTipPlacementModeRight = 4,
    WUXIKeyTipPlacementModeCenter = 5,
    WUXIKeyTipPlacementModeHidden = 6,
};
typedef unsigned WUXIKeyTipPlacementMode;

// Windows.UI.Xaml.Input.ManipulationModes
enum _WUXIManipulationModes {
    WUXIManipulationModesNone = 0,
    WUXIManipulationModesTranslateX = 1,
    WUXIManipulationModesTranslateY = 2,
    WUXIManipulationModesTranslateRailsX = 4,
    WUXIManipulationModesTranslateRailsY = 8,
    WUXIManipulationModesRotate = 16,
    WUXIManipulationModesScale = 32,
    WUXIManipulationModesTranslateInertia = 64,
    WUXIManipulationModesRotateInertia = 128,
    WUXIManipulationModesScaleInertia = 256,
    WUXIManipulationModesAll = 65535,
    WUXIManipulationModesSystem = 65536,
};
typedef unsigned WUXIManipulationModes;

// Windows.UI.Xaml.Input.XYFocusKeyboardNavigationMode
enum _WUXIXYFocusKeyboardNavigationMode {
    WUXIXYFocusKeyboardNavigationModeAuto = 0,
    WUXIXYFocusKeyboardNavigationModeEnabled = 1,
    WUXIXYFocusKeyboardNavigationModeDisabled = 2,
};
typedef unsigned WUXIXYFocusKeyboardNavigationMode;

// Windows.UI.Xaml.Input.XYFocusNavigationStrategy
enum _WUXIXYFocusNavigationStrategy {
    WUXIXYFocusNavigationStrategyAuto = 0,
    WUXIXYFocusNavigationStrategyProjection = 1,
    WUXIXYFocusNavigationStrategyNavigationDirectionDistance = 2,
    WUXIXYFocusNavigationStrategyRectilinearDistance = 3,
};
typedef unsigned WUXIXYFocusNavigationStrategy;

// Windows.UI.Xaml.Input.XYFocusNavigationStrategyOverride
enum _WUXIXYFocusNavigationStrategyOverride {
    WUXIXYFocusNavigationStrategyOverrideNone = 0,
    WUXIXYFocusNavigationStrategyOverrideAuto = 1,
    WUXIXYFocusNavigationStrategyOverrideProjection = 2,
    WUXIXYFocusNavigationStrategyOverrideNavigationDirectionDistance = 3,
    WUXIXYFocusNavigationStrategyOverrideRectilinearDistance = 4,
};
typedef unsigned WUXIXYFocusNavigationStrategyOverride;

#include "WindowsUIXaml.h"
#include "WindowsDevicesInput.h"
#include "WindowsFoundation.h"
#include "WindowsSystem.h"
#include "WindowsUICore.h"
#include "WindowsUIInput.h"
// Windows.UI.Xaml.DependencyPropertyChangedCallback
#ifndef __WXDependencyPropertyChangedCallback__DEFINED
#define __WXDependencyPropertyChangedCallback__DEFINED
typedef void(^WXDependencyPropertyChangedCallback)(WXDependencyObject* sender, WXDependencyProperty* dp);
#endif // __WXDependencyPropertyChangedCallback__DEFINED


#import <Foundation/Foundation.h>

// Windows.UI.Xaml.Input.DoubleTappedEventHandler
#ifndef __WUXIDoubleTappedEventHandler__DEFINED
#define __WUXIDoubleTappedEventHandler__DEFINED
typedef void(^WUXIDoubleTappedEventHandler)(RTObject* sender, WUXIDoubleTappedRoutedEventArgs* e);
#endif // __WUXIDoubleTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.HoldingEventHandler
#ifndef __WUXIHoldingEventHandler__DEFINED
#define __WUXIHoldingEventHandler__DEFINED
typedef void(^WUXIHoldingEventHandler)(RTObject* sender, WUXIHoldingRoutedEventArgs* e);
#endif // __WUXIHoldingEventHandler__DEFINED

// Windows.UI.Xaml.Input.KeyEventHandler
#ifndef __WUXIKeyEventHandler__DEFINED
#define __WUXIKeyEventHandler__DEFINED
typedef void(^WUXIKeyEventHandler)(RTObject* sender, WUXIKeyRoutedEventArgs* e);
#endif // __WUXIKeyEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationCompletedEventHandler
#ifndef __WUXIManipulationCompletedEventHandler__DEFINED
#define __WUXIManipulationCompletedEventHandler__DEFINED
typedef void(^WUXIManipulationCompletedEventHandler)(RTObject* sender, WUXIManipulationCompletedRoutedEventArgs* e);
#endif // __WUXIManipulationCompletedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationDeltaEventHandler
#ifndef __WUXIManipulationDeltaEventHandler__DEFINED
#define __WUXIManipulationDeltaEventHandler__DEFINED
typedef void(^WUXIManipulationDeltaEventHandler)(RTObject* sender, WUXIManipulationDeltaRoutedEventArgs* e);
#endif // __WUXIManipulationDeltaEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationInertiaStartingEventHandler
#ifndef __WUXIManipulationInertiaStartingEventHandler__DEFINED
#define __WUXIManipulationInertiaStartingEventHandler__DEFINED
typedef void(^WUXIManipulationInertiaStartingEventHandler)(RTObject* sender, WUXIManipulationInertiaStartingRoutedEventArgs* e);
#endif // __WUXIManipulationInertiaStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartedEventHandler
#ifndef __WUXIManipulationStartedEventHandler__DEFINED
#define __WUXIManipulationStartedEventHandler__DEFINED
typedef void(^WUXIManipulationStartedEventHandler)(RTObject* sender, WUXIManipulationStartedRoutedEventArgs* e);
#endif // __WUXIManipulationStartedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartingEventHandler
#ifndef __WUXIManipulationStartingEventHandler__DEFINED
#define __WUXIManipulationStartingEventHandler__DEFINED
typedef void(^WUXIManipulationStartingEventHandler)(RTObject* sender, WUXIManipulationStartingRoutedEventArgs* e);
#endif // __WUXIManipulationStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.PointerEventHandler
#ifndef __WUXIPointerEventHandler__DEFINED
#define __WUXIPointerEventHandler__DEFINED
typedef void(^WUXIPointerEventHandler)(RTObject* sender, WUXIPointerRoutedEventArgs* e);
#endif // __WUXIPointerEventHandler__DEFINED

// Windows.UI.Xaml.Input.RightTappedEventHandler
#ifndef __WUXIRightTappedEventHandler__DEFINED
#define __WUXIRightTappedEventHandler__DEFINED
typedef void(^WUXIRightTappedEventHandler)(RTObject* sender, WUXIRightTappedRoutedEventArgs* e);
#endif // __WUXIRightTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.TappedEventHandler
#ifndef __WUXITappedEventHandler__DEFINED
#define __WUXITappedEventHandler__DEFINED
typedef void(^WUXITappedEventHandler)(RTObject* sender, WUXITappedRoutedEventArgs* e);
#endif // __WUXITappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ICommand
#ifndef __WUXIICommand_DEFINED__
#define __WUXIICommand_DEFINED__

@protocol WUXIICommand
- (EventRegistrationToken)addCanExecuteChangedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeCanExecuteChangedEvent:(EventRegistrationToken)tok;
- (BOOL)canExecute:(RTObject*)parameter;
- (void)execute:(RTObject*)parameter;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIICommand : RTObject <WUXIICommand>
@end

#endif // __WUXIICommand_DEFINED__

// Windows.UI.Xaml.Input.Pointer
#ifndef __WUXIPointer_DEFINED__
#define __WUXIPointer_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIPointer : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isInContact;
@property (readonly) BOOL isInRange;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) unsigned int pointerId;
@end

#endif // __WUXIPointer_DEFINED__

// Windows.UI.Xaml.Input.AccessKeyDisplayRequestedEventArgs
#ifndef __WUXIAccessKeyDisplayRequestedEventArgs_DEFINED__
#define __WUXIAccessKeyDisplayRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIAccessKeyDisplayRequestedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * pressedKeys;
@end

#endif // __WUXIAccessKeyDisplayRequestedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.AccessKeyDisplayDismissedEventArgs
#ifndef __WUXIAccessKeyDisplayDismissedEventArgs_DEFINED__
#define __WUXIAccessKeyDisplayDismissedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIAccessKeyDisplayDismissedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXIAccessKeyDisplayDismissedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.AccessKeyInvokedEventArgs
#ifndef __WUXIAccessKeyInvokedEventArgs_DEFINED__
#define __WUXIAccessKeyInvokedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIAccessKeyInvokedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@end

#endif // __WUXIAccessKeyInvokedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.ProcessKeyboardAcceleratorEventArgs
#ifndef __WUXIProcessKeyboardAcceleratorEventArgs_DEFINED__
#define __WUXIProcessKeyboardAcceleratorEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIProcessKeyboardAcceleratorEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WSVirtualKey key;
@property (readonly) WSVirtualKeyModifiers modifiers;
@end

#endif // __WUXIProcessKeyboardAcceleratorEventArgs_DEFINED__

// Windows.UI.Xaml.Input.AccessKeyManager
#ifndef __WUXIAccessKeyManager_DEFINED__
#define __WUXIAccessKeyManager_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIAccessKeyManager : RTObject
+ (void)exitDisplayMode;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (BOOL)isDisplayModeEnabled;
+ (BOOL)areKeyTipsEnabled;
+ (void)setAreKeyTipsEnabled:(BOOL)value;
+ (EventRegistrationToken)addIsDisplayModeEnabledChangedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeIsDisplayModeEnabledChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXIAccessKeyManager_DEFINED__

// Windows.UI.Xaml.Input.InertiaExpansionBehavior
#ifndef __WUXIInertiaExpansionBehavior_DEFINED__
#define __WUXIInertiaExpansionBehavior_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIInertiaExpansionBehavior : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double desiredExpansion;
@property double desiredDeceleration;
@end

#endif // __WUXIInertiaExpansionBehavior_DEFINED__

// Windows.UI.Xaml.Input.InertiaRotationBehavior
#ifndef __WUXIInertiaRotationBehavior_DEFINED__
#define __WUXIInertiaRotationBehavior_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIInertiaRotationBehavior : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double desiredRotation;
@property double desiredDeceleration;
@end

#endif // __WUXIInertiaRotationBehavior_DEFINED__

// Windows.UI.Xaml.Input.InertiaTranslationBehavior
#ifndef __WUXIInertiaTranslationBehavior_DEFINED__
#define __WUXIInertiaTranslationBehavior_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIInertiaTranslationBehavior : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double desiredDisplacement;
@property double desiredDeceleration;
@end

#endif // __WUXIInertiaTranslationBehavior_DEFINED__

// Windows.UI.Xaml.Input.KeyboardAcceleratorInvokedEventArgs
#ifndef __WUXIKeyboardAcceleratorInvokedEventArgs_DEFINED__
#define __WUXIKeyboardAcceleratorInvokedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIKeyboardAcceleratorInvokedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WXDependencyObject* element;
@end

#endif // __WUXIKeyboardAcceleratorInvokedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.ManipulationPivot
#ifndef __WUXIManipulationPivot_DEFINED__
#define __WUXIManipulationPivot_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIManipulationPivot : RTObject
+ (WUXIManipulationPivot*)makeInstanceWithCenterAndRadius:(WFPoint*)center radius:(double)radius ACTIVATOR;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double radius;
@property (retain) WFPoint* center;
@end

#endif // __WUXIManipulationPivot_DEFINED__

// Windows.UI.Xaml.RoutedEventArgs
#ifndef __WXRoutedEventArgs_DEFINED__
#define __WXRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXRoutedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject* originalSource;
@end

#endif // __WXRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.CharacterReceivedRoutedEventArgs
#ifndef __WUXICharacterReceivedRoutedEventArgs_DEFINED__
#define __WUXICharacterReceivedRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXICharacterReceivedRoutedEventArgs : WXRoutedEventArgs
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) wchar_t character;
@property (readonly) WUCCorePhysicalKeyStatus* keyStatus;
@end

#endif // __WUXICharacterReceivedRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.ContextRequestedEventArgs
#ifndef __WUXIContextRequestedEventArgs_DEFINED__
#define __WUXIContextRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIContextRequestedEventArgs : WXRoutedEventArgs
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
- (BOOL)tryGetPosition:(WXUIElement*)relativeTo point:(WFPoint**)point;
@end

#endif // __WUXIContextRequestedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.DoubleTappedRoutedEventArgs
#ifndef __WUXIDoubleTappedRoutedEventArgs_DEFINED__
#define __WUXIDoubleTappedRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIDoubleTappedRoutedEventArgs : WXRoutedEventArgs
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
- (WFPoint*)getPosition:(WXUIElement*)relativeTo;
@end

#endif // __WUXIDoubleTappedRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.GettingFocusEventArgs
#ifndef __WUXIGettingFocusEventArgs_DEFINED__
#define __WUXIGettingFocusEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIGettingFocusEventArgs : WXRoutedEventArgs
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXDependencyObject* newFocusedElement __attribute__ ((ns_returns_not_retained));
@property BOOL handled;
@property BOOL cancel;
@property (readonly) WUXIFocusNavigationDirection direction;
@property (readonly) WXFocusState focusState;
@property (readonly) WUXIFocusInputDeviceKind inputDevice;
@property (readonly) WXDependencyObject* oldFocusedElement;
@end

#endif // __WUXIGettingFocusEventArgs_DEFINED__

// Windows.UI.Xaml.Input.HoldingRoutedEventArgs
#ifndef __WUXIHoldingRoutedEventArgs_DEFINED__
#define __WUXIHoldingRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIHoldingRoutedEventArgs : WXRoutedEventArgs
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WUIHoldingState holdingState;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
- (WFPoint*)getPosition:(WXUIElement*)relativeTo;
@end

#endif // __WUXIHoldingRoutedEventArgs_DEFINED__

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

// Windows.UI.Xaml.Input.InputScope
#ifndef __WUXIInputScope_DEFINED__
#define __WUXIInputScope_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIInputScope : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* WUXIInputScopeName* */ names;
@end

#endif // __WUXIInputScope_DEFINED__

// Windows.UI.Xaml.Input.InputScopeName
#ifndef __WUXIInputScopeName_DEFINED__
#define __WUXIInputScopeName_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIInputScopeName : WXDependencyObject
+ (WUXIInputScopeName*)makeInstance:(WUXIInputScopeNameValue)nameValue ACTIVATOR;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXIInputScopeNameValue nameValue;
@end

#endif // __WUXIInputScopeName_DEFINED__

// Windows.UI.Xaml.Input.KeyboardAccelerator
#ifndef __WUXIKeyboardAccelerator_DEFINED__
#define __WUXIKeyboardAccelerator_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIKeyboardAccelerator : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXDependencyObject* scopeOwner;
@property WSVirtualKeyModifiers modifiers;
@property WSVirtualKey key;
@property BOOL isEnabled;
+ (WXDependencyProperty*)isEnabledProperty;
+ (WXDependencyProperty*)keyProperty;
+ (WXDependencyProperty*)modifiersProperty;
+ (WXDependencyProperty*)scopeOwnerProperty;
- (EventRegistrationToken)addInvokedEvent:(void(^)(WUXIKeyboardAccelerator*, WUXIKeyboardAcceleratorInvokedEventArgs*))del;
- (void)removeInvokedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXIKeyboardAccelerator_DEFINED__

// Windows.UI.Xaml.Input.KeyRoutedEventArgs
#ifndef __WUXIKeyRoutedEventArgs_DEFINED__
#define __WUXIKeyRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIKeyRoutedEventArgs : WXRoutedEventArgs
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WSVirtualKey key;
@property (readonly) WUCCorePhysicalKeyStatus* keyStatus;
@property (readonly) WSVirtualKey originalKey;
@property (readonly) NSString * deviceId;
@end

#endif // __WUXIKeyRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.LosingFocusEventArgs
#ifndef __WUXILosingFocusEventArgs_DEFINED__
#define __WUXILosingFocusEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXILosingFocusEventArgs : WXRoutedEventArgs
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXDependencyObject* newFocusedElement __attribute__ ((ns_returns_not_retained));
@property BOOL handled;
@property BOOL cancel;
@property (readonly) WUXIFocusNavigationDirection direction;
@property (readonly) WXFocusState focusState;
@property (readonly) WUXIFocusInputDeviceKind inputDevice;
@property (readonly) WXDependencyObject* oldFocusedElement;
@end

#endif // __WUXILosingFocusEventArgs_DEFINED__

// Windows.UI.Xaml.Input.ManipulationCompletedRoutedEventArgs
#ifndef __WUXIManipulationCompletedRoutedEventArgs_DEFINED__
#define __WUXIManipulationCompletedRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIManipulationCompletedRoutedEventArgs : WXRoutedEventArgs
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WXUIElement* container;
@property (readonly) WUIManipulationDelta* cumulative;
@property (readonly) BOOL isInertial;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@property (readonly) WUIManipulationVelocities* velocities;
@end

#endif // __WUXIManipulationCompletedRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.ManipulationDeltaRoutedEventArgs
#ifndef __WUXIManipulationDeltaRoutedEventArgs_DEFINED__
#define __WUXIManipulationDeltaRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIManipulationDeltaRoutedEventArgs : WXRoutedEventArgs
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WXUIElement* container;
@property (readonly) WUIManipulationDelta* cumulative;
@property (readonly) WUIManipulationDelta* delta;
@property (readonly) BOOL isInertial;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
@property (readonly) WUIManipulationVelocities* velocities;
- (void)complete;
@end

#endif // __WUXIManipulationDeltaRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.ManipulationInertiaStartingRoutedEventArgs
#ifndef __WUXIManipulationInertiaStartingRoutedEventArgs_DEFINED__
#define __WUXIManipulationInertiaStartingRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIManipulationInertiaStartingRoutedEventArgs : WXRoutedEventArgs
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXIInertiaTranslationBehavior* translationBehavior;
@property (retain) WUXIInertiaRotationBehavior* rotationBehavior;
@property BOOL handled;
@property (retain) WUXIInertiaExpansionBehavior* expansionBehavior;
@property (readonly) WXUIElement* container;
@property (readonly) WUIManipulationDelta* cumulative;
@property (readonly) WUIManipulationDelta* delta;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WUIManipulationVelocities* velocities;
@end

#endif // __WUXIManipulationInertiaStartingRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.ManipulationStartedRoutedEventArgs
#ifndef __WUXIManipulationStartedRoutedEventArgs_DEFINED__
#define __WUXIManipulationStartedRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIManipulationStartedRoutedEventArgs : WXRoutedEventArgs
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WXUIElement* container;
@property (readonly) WUIManipulationDelta* cumulative;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFPoint* position;
- (void)complete;
@end

#endif // __WUXIManipulationStartedRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.ManipulationStartingRoutedEventArgs
#ifndef __WUXIManipulationStartingRoutedEventArgs_DEFINED__
#define __WUXIManipulationStartingRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIManipulationStartingRoutedEventArgs : WXRoutedEventArgs
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXIManipulationPivot* pivot;
@property WUXIManipulationModes mode;
@property BOOL handled;
@property (retain) WXUIElement* container;
@end

#endif // __WUXIManipulationStartingRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.NoFocusCandidateFoundEventArgs
#ifndef __WUXINoFocusCandidateFoundEventArgs_DEFINED__
#define __WUXINoFocusCandidateFoundEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXINoFocusCandidateFoundEventArgs : WXRoutedEventArgs
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WUXIFocusNavigationDirection direction;
@property (readonly) WUXIFocusInputDeviceKind inputDevice;
@end

#endif // __WUXINoFocusCandidateFoundEventArgs_DEFINED__

// Windows.UI.Xaml.Input.PointerRoutedEventArgs
#ifndef __WUXIPointerRoutedEventArgs_DEFINED__
#define __WUXIPointerRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIPointerRoutedEventArgs : WXRoutedEventArgs
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WSVirtualKeyModifiers keyModifiers;
@property (readonly) WUXIPointer* pointer;
@property (readonly) BOOL isGenerated;
- (WUIPointerPoint*)getCurrentPoint:(WXUIElement*)relativeTo;
- (NSMutableArray* /* WUIPointerPoint* */)getIntermediatePoints:(WXUIElement*)relativeTo;
@end

#endif // __WUXIPointerRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.RightTappedRoutedEventArgs
#ifndef __WUXIRightTappedRoutedEventArgs_DEFINED__
#define __WUXIRightTappedRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIRightTappedRoutedEventArgs : WXRoutedEventArgs
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
- (WFPoint*)getPosition:(WXUIElement*)relativeTo;
@end

#endif // __WUXIRightTappedRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.TappedRoutedEventArgs
#ifndef __WUXITappedRoutedEventArgs_DEFINED__
#define __WUXITappedRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXITappedRoutedEventArgs : WXRoutedEventArgs
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
- (WFPoint*)getPosition:(WXUIElement*)relativeTo;
@end

#endif // __WUXITappedRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Input.FindNextElementOptions
#ifndef __WUXIFindNextElementOptions_DEFINED__
#define __WUXIFindNextElementOptions_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIFindNextElementOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXIXYFocusNavigationStrategyOverride xYFocusNavigationStrategyOverride;
@property (retain) WXDependencyObject* searchRoot;
@property (retain) WFRect* hintRect;
@property (retain) WFRect* exclusionRect;
@end

#endif // __WUXIFindNextElementOptions_DEFINED__

// Windows.UI.Xaml.Input.FocusManager
#ifndef __WUXIFocusManager_DEFINED__
#define __WUXIFocusManager_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXIFocusManager : RTObject
+ (WXUIElement*)findNextFocusableElement:(WUXIFocusNavigationDirection)focusNavigationDirection;
+ (WXUIElement*)findNextFocusableElementWithHint:(WUXIFocusNavigationDirection)focusNavigationDirection hintRect:(WFRect*)hintRect;
+ (BOOL)tryMoveFocus:(WUXIFocusNavigationDirection)focusNavigationDirection;
+ (RTObject*)getFocusedElement;
+ (BOOL)tryMoveFocusWithOptions:(WUXIFocusNavigationDirection)focusNavigationDirection focusNavigationOptions:(WUXIFindNextElementOptions*)focusNavigationOptions;
+ (WXDependencyObject*)findNextElement:(WUXIFocusNavigationDirection)focusNavigationDirection;
+ (WXDependencyObject*)findFirstFocusableElement:(WXDependencyObject*)searchScope;
+ (WXDependencyObject*)findLastFocusableElement:(WXDependencyObject*)searchScope;
+ (WXDependencyObject*)findNextElementWithOptions:(WUXIFocusNavigationDirection)focusNavigationDirection focusNavigationOptions:(WUXIFindNextElementOptions*)focusNavigationOptions;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXIFocusManager_DEFINED__

