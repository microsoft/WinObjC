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

// WindowsUIXaml.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WXDependencyObject, WXDependencyPropertyChangedEventArgs, WXApplicationInitializationCallbackParams, WXCornerRadiusHelper,
    WXDurationHelper, WXGridLengthHelper, WXPointHelper, WXRectHelper, WXSizeHelper, WXThicknessHelper, WXBindingFailedEventArgs,
    WXRoutedEventArgs, WXUnhandledExceptionEventArgs, WXVisualStateChangedEventArgs, WXDataContextChangedEventArgs, WXDataTemplateKey,
    WXDebugSettings, WXDependencyProperty, WXDependencyObjectCollection, WXPropertyMetadata, WXDispatcherTimer, WXDragEventArgs,
    WXRoutedEvent, WXTriggerActionCollection, WXExceptionRoutedEventArgs, WXWindowCreatedEventArgs, WXApplication, WXTriggerCollection,
    WXFrameworkTemplate, WXDataTemplate, WXFrameworkView, WXFrameworkViewSource, WXMediaFailedRoutedEventArgs, WXPropertyPath,
    WXResourceDictionary, WXSetterBase, WXSetter, WXSetterBaseCollection, WXSizeChangedEventArgs, WXStyle, WXTriggerAction, WXTriggerBase,
    WXEventTrigger, WXUIElement, WXFrameworkElement, WXVisualState, WXVisualStateGroup, WXVisualStateManager, WXVisualTransition, WXWindow;
@class WXCornerRadius, WXDuration, WXGridLength, WXThickness;
@protocol WXICornerRadiusHelper
, WXICornerRadiusHelperStatics, WXIDurationHelper, WXIDurationHelperStatics, WXIGridLengthHelper, WXIGridLengthHelperStatics,
    WXIPointHelper, WXIPointHelperStatics, WXIRectHelper, WXIRectHelperStatics, WXISizeHelper, WXISizeHelperStatics, WXIThicknessHelper,
    WXIThicknessHelperStatics, WXIApplicationInitializationCallbackParams, WXIBindingFailedEventArgs, WXIDataContextChangedEventArgs,
    WXIDataTemplate, WXIDataTemplateFactory, WXIDataTemplateKey, WXIDataTemplateKeyFactory, WXIDebugSettings, WXIDebugSettings2,
    WXIDependencyObject, WXIDependencyObjectFactory, WXIDependencyObjectCollectionFactory, WXIDependencyProperty,
    WXIDependencyPropertyStatics, WXIDependencyPropertyChangedEventArgs, WXIDispatcherTimer, WXIDispatcherTimerFactory, WXIDragEventArgs,
    WXIEventTrigger, WXIExceptionRoutedEventArgs, WXIExceptionRoutedEventArgsFactory, WXIApplication, WXIApplicationOverrides,
    WXIApplicationStatics, WXIApplicationFactory, WXIFrameworkElement, WXIFrameworkElementOverrides, WXIFrameworkElementStatics,
    WXIFrameworkElementFactory, WXIFrameworkElement2, WXIFrameworkElementOverrides2, WXIFrameworkElementStatics2, WXIFrameworkTemplate,
    WXIFrameworkTemplateFactory, WXIFrameworkView, WXIFrameworkViewSource, WXIMediaFailedRoutedEventArgs, WXIPropertyMetadata,
    WXIPropertyMetadataStatics, WXIPropertyMetadataFactory, WXIPropertyPath, WXIPropertyPathFactory, WXIResourceDictionary,
    WXIResourceDictionaryFactory, WXIRoutedEvent, WXIRoutedEventArgs, WXIRoutedEventArgsFactory, WXISetter, WXISetterFactory, WXISetterBase,
    WXISetterBaseFactory, WXISetterBaseCollection, WXISizeChangedEventArgs, WXIStyle, WXIStyleFactory, WXITriggerAction,
    WXITriggerActionFactory, WXITriggerBase, WXITriggerBaseFactory, WXIUIElement, WXIUIElementOverrides, WXIUIElementStatics,
    WXIUIElementFactory, WXIUIElement2, WXIUIElementStatics2, WXIUnhandledExceptionEventArgs, WXIVisualState,
    WXIVisualStateChangedEventArgs, WXIVisualStateGroup, WXIVisualStateManager, WXIVisualStateManagerOverrides,
    WXIVisualStateManagerProtected, WXIVisualStateManagerStatics, WXIVisualStateManagerFactory, WXIVisualTransition,
    WXIVisualTransitionFactory, WXIWindow, WXIWindowStatics, WXIWindowCreatedEventArgs;

// Windows.UI.Xaml.ApplicationTheme
enum _WXApplicationTheme {
    WXApplicationThemeLight = 0,
    WXApplicationThemeDark = 1,
};
typedef unsigned WXApplicationTheme;

// Windows.UI.Xaml.DurationType
enum _WXDurationType {
    WXDurationTypeAutomatic = 0,
    WXDurationTypeTimeSpan = 1,
    WXDurationTypeForever = 2,
};
typedef unsigned WXDurationType;

// Windows.UI.Xaml.ElementTheme
enum _WXElementTheme {
    WXElementThemeDefault = 0,
    WXElementThemeLight = 1,
    WXElementThemeDark = 2,
};
typedef unsigned WXElementTheme;

// Windows.UI.Xaml.FlowDirection
enum _WXFlowDirection {
    WXFlowDirectionLeftToRight = 0,
    WXFlowDirectionRightToLeft = 1,
};
typedef unsigned WXFlowDirection;

// Windows.UI.Xaml.FocusState
enum _WXFocusState {
    WXFocusStateUnfocused = 0,
    WXFocusStatePointer = 1,
    WXFocusStateKeyboard = 2,
    WXFocusStateProgrammatic = 3,
};
typedef unsigned WXFocusState;

// Windows.UI.Xaml.FontCapitals
enum _WXFontCapitals {
    WXFontCapitalsNormal = 0,
    WXFontCapitalsAllSmallCaps = 1,
    WXFontCapitalsSmallCaps = 2,
    WXFontCapitalsAllPetiteCaps = 3,
    WXFontCapitalsPetiteCaps = 4,
    WXFontCapitalsUnicase = 5,
    WXFontCapitalsTitling = 6,
};
typedef unsigned WXFontCapitals;

// Windows.UI.Xaml.FontEastAsianLanguage
enum _WXFontEastAsianLanguage {
    WXFontEastAsianLanguageNormal = 0,
    WXFontEastAsianLanguageHojoKanji = 1,
    WXFontEastAsianLanguageJis04 = 2,
    WXFontEastAsianLanguageJis78 = 3,
    WXFontEastAsianLanguageJis83 = 4,
    WXFontEastAsianLanguageJis90 = 5,
    WXFontEastAsianLanguageNlcKanji = 6,
    WXFontEastAsianLanguageSimplified = 7,
    WXFontEastAsianLanguageTraditional = 8,
    WXFontEastAsianLanguageTraditionalNames = 9,
};
typedef unsigned WXFontEastAsianLanguage;

// Windows.UI.Xaml.FontEastAsianWidths
enum _WXFontEastAsianWidths {
    WXFontEastAsianWidthsNormal = 0,
    WXFontEastAsianWidthsFull = 1,
    WXFontEastAsianWidthsHalf = 2,
    WXFontEastAsianWidthsProportional = 3,
    WXFontEastAsianWidthsQuarter = 4,
    WXFontEastAsianWidthsThird = 5,
};
typedef unsigned WXFontEastAsianWidths;

// Windows.UI.Xaml.FontFraction
enum _WXFontFraction {
    WXFontFractionNormal = 0,
    WXFontFractionStacked = 1,
    WXFontFractionSlashed = 2,
};
typedef unsigned WXFontFraction;

// Windows.UI.Xaml.FontNumeralAlignment
enum _WXFontNumeralAlignment {
    WXFontNumeralAlignmentNormal = 0,
    WXFontNumeralAlignmentProportional = 1,
    WXFontNumeralAlignmentTabular = 2,
};
typedef unsigned WXFontNumeralAlignment;

// Windows.UI.Xaml.FontNumeralStyle
enum _WXFontNumeralStyle {
    WXFontNumeralStyleNormal = 0,
    WXFontNumeralStyleLining = 1,
    WXFontNumeralStyleOldStyle = 2,
};
typedef unsigned WXFontNumeralStyle;

// Windows.UI.Xaml.FontVariants
enum _WXFontVariants {
    WXFontVariantsNormal = 0,
    WXFontVariantsSuperscript = 1,
    WXFontVariantsSubscript = 2,
    WXFontVariantsOrdinal = 3,
    WXFontVariantsInferior = 4,
    WXFontVariantsRuby = 5,
};
typedef unsigned WXFontVariants;

// Windows.UI.Xaml.GridUnitType
enum _WXGridUnitType {
    WXGridUnitTypeAuto = 0,
    WXGridUnitTypePixel = 1,
    WXGridUnitTypeStar = 2,
};
typedef unsigned WXGridUnitType;

// Windows.UI.Xaml.HorizontalAlignment
enum _WXHorizontalAlignment {
    WXHorizontalAlignmentLeft = 0,
    WXHorizontalAlignmentCenter = 1,
    WXHorizontalAlignmentRight = 2,
    WXHorizontalAlignmentStretch = 3,
};
typedef unsigned WXHorizontalAlignment;

// Windows.UI.Xaml.LineStackingStrategy
enum _WXLineStackingStrategy {
    WXLineStackingStrategyMaxHeight = 0,
    WXLineStackingStrategyBlockLineHeight = 1,
    WXLineStackingStrategyBaselineToBaseline = 2,
};
typedef unsigned WXLineStackingStrategy;

// Windows.UI.Xaml.OpticalMarginAlignment
enum _WXOpticalMarginAlignment {
    WXOpticalMarginAlignmentNone = 0,
    WXOpticalMarginAlignmentTrimSideBearings = 1,
};
typedef unsigned WXOpticalMarginAlignment;

// Windows.UI.Xaml.TextAlignment
enum _WXTextAlignment {
    WXTextAlignmentCenter = 0,
    WXTextAlignmentLeft = 1,
    WXTextAlignmentRight = 2,
    WXTextAlignmentJustify = 3,
};
typedef unsigned WXTextAlignment;

// Windows.UI.Xaml.TextLineBounds
enum _WXTextLineBounds {
    WXTextLineBoundsFull = 0,
    WXTextLineBoundsTrimToCapHeight = 1,
    WXTextLineBoundsTrimToBaseline = 2,
    WXTextLineBoundsTight = 3,
};
typedef unsigned WXTextLineBounds;

// Windows.UI.Xaml.TextReadingOrder
enum _WXTextReadingOrder {
    WXTextReadingOrderDefault = 0,
    WXTextReadingOrderDetectFromContent = 1,
};
typedef unsigned WXTextReadingOrder;

// Windows.UI.Xaml.TextTrimming
enum _WXTextTrimming {
    WXTextTrimmingNone = 0,
    WXTextTrimmingCharacterEllipsis = 1,
    WXTextTrimmingWordEllipsis = 2,
    WXTextTrimmingClip = 3,
};
typedef unsigned WXTextTrimming;

// Windows.UI.Xaml.TextWrapping
enum _WXTextWrapping {
    WXTextWrappingNoWrap = 1,
    WXTextWrappingWrap = 2,
    WXTextWrappingWrapWholeWords = 3,
};
typedef unsigned WXTextWrapping;

// Windows.UI.Xaml.VerticalAlignment
enum _WXVerticalAlignment {
    WXVerticalAlignmentTop = 0,
    WXVerticalAlignmentCenter = 1,
    WXVerticalAlignmentBottom = 2,
    WXVerticalAlignmentStretch = 3,
};
typedef unsigned WXVerticalAlignment;

// Windows.UI.Xaml.Visibility
enum _WXVisibility {
    WXVisibilityVisible = 0,
    WXVisibilityCollapsed = 1,
};
typedef unsigned WXVisibility;

#include "WindowsFoundation.h"
#include "WindowsUICore.h"
#include "WindowsApplicationModelActivation.h"
#include "WindowsUIXamlInterop.h"
#include "WindowsUIXamlControls.h"
#include "WindowsUIXamlMediaAnimation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsUIXamlMedia.h"
#include "WindowsApplicationModelDataTransfer.h"
#include "WindowsUIXamlControlsPrimitives.h"
#include "WindowsUIXamlData.h"
#include "WindowsUIXamlInput.h"
#include "WindowsUIXamlAutomationPeers.h"
#include "WindowsApplicationModelCore.h"
// Windows.UI.Xaml.ApplicationInitializationCallback
#ifndef __WXApplicationInitializationCallback__DEFINED
#define __WXApplicationInitializationCallback__DEFINED
typedef void (^WXApplicationInitializationCallback)(WXApplicationInitializationCallbackParams* p);
#endif // __WXApplicationInitializationCallback__DEFINED

// Windows.UI.Xaml.BindingFailedEventHandler
#ifndef __WXBindingFailedEventHandler__DEFINED
#define __WXBindingFailedEventHandler__DEFINED
typedef void (^WXBindingFailedEventHandler)(RTObject* sender, WXBindingFailedEventArgs* e);
#endif // __WXBindingFailedEventHandler__DEFINED

// Windows.UI.Xaml.CreateDefaultValueCallback
#ifndef __WXCreateDefaultValueCallback__DEFINED
#define __WXCreateDefaultValueCallback__DEFINED
typedef void (^WXCreateDefaultValueCallback)();
#endif // __WXCreateDefaultValueCallback__DEFINED

// Windows.UI.Xaml.DragEventHandler
#ifndef __WXDragEventHandler__DEFINED
#define __WXDragEventHandler__DEFINED
typedef void (^WXDragEventHandler)(RTObject* sender, WXDragEventArgs* e);
#endif // __WXDragEventHandler__DEFINED

// Windows.UI.Xaml.Input.DoubleTappedEventHandler
#ifndef __WUXIDoubleTappedEventHandler__DEFINED
#define __WUXIDoubleTappedEventHandler__DEFINED
typedef void (^WUXIDoubleTappedEventHandler)(RTObject* sender, WUXIDoubleTappedRoutedEventArgs* e);
#endif // __WUXIDoubleTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.HoldingEventHandler
#ifndef __WUXIHoldingEventHandler__DEFINED
#define __WUXIHoldingEventHandler__DEFINED
typedef void (^WUXIHoldingEventHandler)(RTObject* sender, WUXIHoldingRoutedEventArgs* e);
#endif // __WUXIHoldingEventHandler__DEFINED

// Windows.UI.Xaml.Input.KeyEventHandler
#ifndef __WUXIKeyEventHandler__DEFINED
#define __WUXIKeyEventHandler__DEFINED
typedef void (^WUXIKeyEventHandler)(RTObject* sender, WUXIKeyRoutedEventArgs* e);
#endif // __WUXIKeyEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationCompletedEventHandler
#ifndef __WUXIManipulationCompletedEventHandler__DEFINED
#define __WUXIManipulationCompletedEventHandler__DEFINED
typedef void (^WUXIManipulationCompletedEventHandler)(RTObject* sender, WUXIManipulationCompletedRoutedEventArgs* e);
#endif // __WUXIManipulationCompletedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationDeltaEventHandler
#ifndef __WUXIManipulationDeltaEventHandler__DEFINED
#define __WUXIManipulationDeltaEventHandler__DEFINED
typedef void (^WUXIManipulationDeltaEventHandler)(RTObject* sender, WUXIManipulationDeltaRoutedEventArgs* e);
#endif // __WUXIManipulationDeltaEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationInertiaStartingEventHandler
#ifndef __WUXIManipulationInertiaStartingEventHandler__DEFINED
#define __WUXIManipulationInertiaStartingEventHandler__DEFINED
typedef void (^WUXIManipulationInertiaStartingEventHandler)(RTObject* sender, WUXIManipulationInertiaStartingRoutedEventArgs* e);
#endif // __WUXIManipulationInertiaStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartedEventHandler
#ifndef __WUXIManipulationStartedEventHandler__DEFINED
#define __WUXIManipulationStartedEventHandler__DEFINED
typedef void (^WUXIManipulationStartedEventHandler)(RTObject* sender, WUXIManipulationStartedRoutedEventArgs* e);
#endif // __WUXIManipulationStartedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartingEventHandler
#ifndef __WUXIManipulationStartingEventHandler__DEFINED
#define __WUXIManipulationStartingEventHandler__DEFINED
typedef void (^WUXIManipulationStartingEventHandler)(RTObject* sender, WUXIManipulationStartingRoutedEventArgs* e);
#endif // __WUXIManipulationStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.PointerEventHandler
#ifndef __WUXIPointerEventHandler__DEFINED
#define __WUXIPointerEventHandler__DEFINED
typedef void (^WUXIPointerEventHandler)(RTObject* sender, WUXIPointerRoutedEventArgs* e);
#endif // __WUXIPointerEventHandler__DEFINED

// Windows.UI.Xaml.Input.RightTappedEventHandler
#ifndef __WUXIRightTappedEventHandler__DEFINED
#define __WUXIRightTappedEventHandler__DEFINED
typedef void (^WUXIRightTappedEventHandler)(RTObject* sender, WUXIRightTappedRoutedEventArgs* e);
#endif // __WUXIRightTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.TappedEventHandler
#ifndef __WUXITappedEventHandler__DEFINED
#define __WUXITappedEventHandler__DEFINED
typedef void (^WUXITappedEventHandler)(RTObject* sender, WUXITappedRoutedEventArgs* e);
#endif // __WUXITappedEventHandler__DEFINED

// Windows.UI.Xaml.PropertyChangedCallback
#ifndef __WXPropertyChangedCallback__DEFINED
#define __WXPropertyChangedCallback__DEFINED
typedef void (^WXPropertyChangedCallback)(WXDependencyObject* d, WXDependencyPropertyChangedEventArgs* e);
#endif // __WXPropertyChangedCallback__DEFINED

// Windows.UI.Xaml.RoutedEventHandler
#ifndef __WXRoutedEventHandler__DEFINED
#define __WXRoutedEventHandler__DEFINED
typedef void (^WXRoutedEventHandler)(RTObject* sender, WXRoutedEventArgs* e);
#endif // __WXRoutedEventHandler__DEFINED

// Windows.UI.Xaml.SizeChangedEventHandler
#ifndef __WXSizeChangedEventHandler__DEFINED
#define __WXSizeChangedEventHandler__DEFINED
typedef void (^WXSizeChangedEventHandler)(RTObject* sender, WXSizeChangedEventArgs* e);
#endif // __WXSizeChangedEventHandler__DEFINED

// Windows.UI.Xaml.SuspendingEventHandler
#ifndef __WXSuspendingEventHandler__DEFINED
#define __WXSuspendingEventHandler__DEFINED
typedef void (^WXSuspendingEventHandler)(RTObject* sender, WASuspendingEventArgs* e);
#endif // __WXSuspendingEventHandler__DEFINED

// Windows.UI.Xaml.UnhandledExceptionEventHandler
#ifndef __WXUnhandledExceptionEventHandler__DEFINED
#define __WXUnhandledExceptionEventHandler__DEFINED
typedef void (^WXUnhandledExceptionEventHandler)(RTObject* sender, WXUnhandledExceptionEventArgs* e);
#endif // __WXUnhandledExceptionEventHandler__DEFINED

// Windows.UI.Xaml.VisualStateChangedEventHandler
#ifndef __WXVisualStateChangedEventHandler__DEFINED
#define __WXVisualStateChangedEventHandler__DEFINED
typedef void (^WXVisualStateChangedEventHandler)(RTObject* sender, WXVisualStateChangedEventArgs* e);
#endif // __WXVisualStateChangedEventHandler__DEFINED

// Windows.UI.Xaml.WindowActivatedEventHandler
#ifndef __WXWindowActivatedEventHandler__DEFINED
#define __WXWindowActivatedEventHandler__DEFINED
typedef void (^WXWindowActivatedEventHandler)(RTObject* sender, WUCWindowActivatedEventArgs* e);
#endif // __WXWindowActivatedEventHandler__DEFINED

// Windows.UI.Xaml.WindowClosedEventHandler
#ifndef __WXWindowClosedEventHandler__DEFINED
#define __WXWindowClosedEventHandler__DEFINED
typedef void (^WXWindowClosedEventHandler)(RTObject* sender, WUCCoreWindowEventArgs* e);
#endif // __WXWindowClosedEventHandler__DEFINED

// Windows.UI.Xaml.WindowSizeChangedEventHandler
#ifndef __WXWindowSizeChangedEventHandler__DEFINED
#define __WXWindowSizeChangedEventHandler__DEFINED
typedef void (^WXWindowSizeChangedEventHandler)(RTObject* sender, WUCWindowSizeChangedEventArgs* e);
#endif // __WXWindowSizeChangedEventHandler__DEFINED

// Windows.UI.Xaml.WindowVisibilityChangedEventHandler
#ifndef __WXWindowVisibilityChangedEventHandler__DEFINED
#define __WXWindowVisibilityChangedEventHandler__DEFINED
typedef void (^WXWindowVisibilityChangedEventHandler)(RTObject* sender, WUCVisibilityChangedEventArgs* e);
#endif // __WXWindowVisibilityChangedEventHandler__DEFINED

// [struct] Windows.UI.Xaml.CornerRadius
WINRT_EXPORT
@interface WXCornerRadius : NSObject
+ (instancetype) new;
@property double topLeft;
@property double topRight;
@property double bottomRight;
@property double bottomLeft;
@end

// [struct] Windows.UI.Xaml.Duration
WINRT_EXPORT
@interface WXDuration : NSObject
+ (instancetype) new;
@property (copy) WFTimeSpan* timeSpan;
@property WXDurationType type;
@end

// [struct] Windows.UI.Xaml.GridLength
WINRT_EXPORT
@interface WXGridLength : NSObject
+ (instancetype) new;
@property double value;
@property WXGridUnitType gridUnitType;
@end

// [struct] Windows.UI.Xaml.Thickness
WINRT_EXPORT
@interface WXThickness : NSObject
+ (instancetype) new;
@property double left;
@property double top;
@property double right;
@property double bottom;
@end

// Windows.UI.Xaml.CreateDefaultValueCallback
#ifndef __WXCreateDefaultValueCallback__DEFINED
#define __WXCreateDefaultValueCallback__DEFINED
typedef void (^WXCreateDefaultValueCallback)();
#endif // __WXCreateDefaultValueCallback__DEFINED

// Windows.UI.Xaml.PropertyChangedCallback
#ifndef __WXPropertyChangedCallback__DEFINED
#define __WXPropertyChangedCallback__DEFINED
typedef void (^WXPropertyChangedCallback)(WXDependencyObject* d, WXDependencyPropertyChangedEventArgs* e);
#endif // __WXPropertyChangedCallback__DEFINED

// Windows.UI.Xaml.ApplicationInitializationCallback
#ifndef __WXApplicationInitializationCallback__DEFINED
#define __WXApplicationInitializationCallback__DEFINED
typedef void (^WXApplicationInitializationCallback)(WXApplicationInitializationCallbackParams* p);
#endif // __WXApplicationInitializationCallback__DEFINED

// Windows.UI.Xaml.BindingFailedEventHandler
#ifndef __WXBindingFailedEventHandler__DEFINED
#define __WXBindingFailedEventHandler__DEFINED
typedef void (^WXBindingFailedEventHandler)(RTObject* sender, WXBindingFailedEventArgs* e);
#endif // __WXBindingFailedEventHandler__DEFINED

// Windows.UI.Xaml.DependencyPropertyChangedEventHandler
#ifndef __WXDependencyPropertyChangedEventHandler__DEFINED
#define __WXDependencyPropertyChangedEventHandler__DEFINED
typedef void (^WXDependencyPropertyChangedEventHandler)(RTObject* sender, WXDependencyPropertyChangedEventArgs* e);
#endif // __WXDependencyPropertyChangedEventHandler__DEFINED

// Windows.UI.Xaml.DragEventHandler
#ifndef __WXDragEventHandler__DEFINED
#define __WXDragEventHandler__DEFINED
typedef void (^WXDragEventHandler)(RTObject* sender, WXDragEventArgs* e);
#endif // __WXDragEventHandler__DEFINED

// Windows.UI.Xaml.ExceptionRoutedEventHandler
#ifndef __WXExceptionRoutedEventHandler__DEFINED
#define __WXExceptionRoutedEventHandler__DEFINED
typedef void (^WXExceptionRoutedEventHandler)(RTObject* sender, WXExceptionRoutedEventArgs* e);
#endif // __WXExceptionRoutedEventHandler__DEFINED

// Windows.UI.Xaml.RoutedEventHandler
#ifndef __WXRoutedEventHandler__DEFINED
#define __WXRoutedEventHandler__DEFINED
typedef void (^WXRoutedEventHandler)(RTObject* sender, WXRoutedEventArgs* e);
#endif // __WXRoutedEventHandler__DEFINED

// Windows.UI.Xaml.SizeChangedEventHandler
#ifndef __WXSizeChangedEventHandler__DEFINED
#define __WXSizeChangedEventHandler__DEFINED
typedef void (^WXSizeChangedEventHandler)(RTObject* sender, WXSizeChangedEventArgs* e);
#endif // __WXSizeChangedEventHandler__DEFINED

// Windows.UI.Xaml.SuspendingEventHandler
#ifndef __WXSuspendingEventHandler__DEFINED
#define __WXSuspendingEventHandler__DEFINED
typedef void (^WXSuspendingEventHandler)(RTObject* sender, WASuspendingEventArgs* e);
#endif // __WXSuspendingEventHandler__DEFINED

// Windows.UI.Xaml.UnhandledExceptionEventHandler
#ifndef __WXUnhandledExceptionEventHandler__DEFINED
#define __WXUnhandledExceptionEventHandler__DEFINED
typedef void (^WXUnhandledExceptionEventHandler)(RTObject* sender, WXUnhandledExceptionEventArgs* e);
#endif // __WXUnhandledExceptionEventHandler__DEFINED

// Windows.UI.Xaml.VisualStateChangedEventHandler
#ifndef __WXVisualStateChangedEventHandler__DEFINED
#define __WXVisualStateChangedEventHandler__DEFINED
typedef void (^WXVisualStateChangedEventHandler)(RTObject* sender, WXVisualStateChangedEventArgs* e);
#endif // __WXVisualStateChangedEventHandler__DEFINED

// Windows.UI.Xaml.WindowActivatedEventHandler
#ifndef __WXWindowActivatedEventHandler__DEFINED
#define __WXWindowActivatedEventHandler__DEFINED
typedef void (^WXWindowActivatedEventHandler)(RTObject* sender, WUCWindowActivatedEventArgs* e);
#endif // __WXWindowActivatedEventHandler__DEFINED

// Windows.UI.Xaml.WindowClosedEventHandler
#ifndef __WXWindowClosedEventHandler__DEFINED
#define __WXWindowClosedEventHandler__DEFINED
typedef void (^WXWindowClosedEventHandler)(RTObject* sender, WUCCoreWindowEventArgs* e);
#endif // __WXWindowClosedEventHandler__DEFINED

// Windows.UI.Xaml.WindowSizeChangedEventHandler
#ifndef __WXWindowSizeChangedEventHandler__DEFINED
#define __WXWindowSizeChangedEventHandler__DEFINED
typedef void (^WXWindowSizeChangedEventHandler)(RTObject* sender, WUCWindowSizeChangedEventArgs* e);
#endif // __WXWindowSizeChangedEventHandler__DEFINED

// Windows.UI.Xaml.WindowVisibilityChangedEventHandler
#ifndef __WXWindowVisibilityChangedEventHandler__DEFINED
#define __WXWindowVisibilityChangedEventHandler__DEFINED
typedef void (^WXWindowVisibilityChangedEventHandler)(RTObject* sender, WUCVisibilityChangedEventArgs* e);
#endif // __WXWindowVisibilityChangedEventHandler__DEFINED

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

// Windows.UI.Xaml.DependencyPropertyChangedEventArgs
#ifndef __WXDependencyPropertyChangedEventArgs_DEFINED__
#define __WXDependencyPropertyChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXDependencyPropertyChangedEventArgs : RTObject
@property (readonly) RTObject* newValue;
@property (readonly) RTObject* oldValue;
@property (readonly) WXDependencyProperty* property ;
@end

#endif // __WXDependencyPropertyChangedEventArgs_DEFINED__

// Windows.UI.Xaml.ApplicationInitializationCallbackParams
#ifndef __WXApplicationInitializationCallbackParams_DEFINED__
#define __WXApplicationInitializationCallbackParams_DEFINED__

WINRT_EXPORT
@interface WXApplicationInitializationCallbackParams : RTObject
@end

#endif // __WXApplicationInitializationCallbackParams_DEFINED__

// Windows.UI.Xaml.CornerRadiusHelper
#ifndef __WXCornerRadiusHelper_DEFINED__
#define __WXCornerRadiusHelper_DEFINED__

WINRT_EXPORT
@interface WXCornerRadiusHelper : RTObject
+ (WXCornerRadius*)fromRadii:(double)topLeft topRight:(double)topRight bottomRight:(double)bottomRight bottomLeft:(double)bottomLeft;
+ (WXCornerRadius*)fromUniformRadius:(double)uniformRadius;
@end

#endif // __WXCornerRadiusHelper_DEFINED__

// Windows.UI.Xaml.DurationHelper
#ifndef __WXDurationHelper_DEFINED__
#define __WXDurationHelper_DEFINED__

WINRT_EXPORT
@interface WXDurationHelper : RTObject
+ (int)compare:(WXDuration*)duration1 duration2:(WXDuration*)duration2;
+ (WXDuration*)fromTimeSpan:(WFTimeSpan*)timeSpan;
+ (BOOL)getHasTimeSpan:(WXDuration*)target;
+ (WXDuration*)add:(WXDuration*)target duration:(WXDuration*)duration;
+ (BOOL)equals:(WXDuration*)target value:(WXDuration*)value;
+ (WXDuration*)subtract:(WXDuration*)target duration:(WXDuration*)duration;
+ (WXDuration*)automatic;
+ (WXDuration*)forever;
@end

#endif // __WXDurationHelper_DEFINED__

// Windows.UI.Xaml.GridLengthHelper
#ifndef __WXGridLengthHelper_DEFINED__
#define __WXGridLengthHelper_DEFINED__

WINRT_EXPORT
@interface WXGridLengthHelper : RTObject
+ (WXGridLength*)fromPixels:(double)pixels;
+ (WXGridLength*)fromValueAndType:(double)value type:(WXGridUnitType)type;
+ (BOOL)getIsAbsolute:(WXGridLength*)target;
+ (BOOL)getIsAuto:(WXGridLength*)target;
+ (BOOL)getIsStar:(WXGridLength*)target;
+ (BOOL)equals:(WXGridLength*)target value:(WXGridLength*)value;
+ (WXGridLength*)Auto;
@end

#endif // __WXGridLengthHelper_DEFINED__

// Windows.UI.Xaml.PointHelper
#ifndef __WXPointHelper_DEFINED__
#define __WXPointHelper_DEFINED__

WINRT_EXPORT
@interface WXPointHelper : RTObject
+ (WFPoint*)fromCoordinates:(float)x y:(float)y;
@end

#endif // __WXPointHelper_DEFINED__

// Windows.UI.Xaml.RectHelper
#ifndef __WXRectHelper_DEFINED__
#define __WXRectHelper_DEFINED__

WINRT_EXPORT
@interface WXRectHelper : RTObject
+ (WFRect*)fromCoordinatesAndDimensions:(float)x y:(float)y width:(float)width height:(float)height;
+ (WFRect*)fromPoints:(WFPoint*)point1 point2:(WFPoint*)point2;
+ (WFRect*)fromLocationAndSize:(WFPoint*)location size:(WFSize*)size;
+ (BOOL)getIsEmpty:(WFRect*)target;
+ (float)getBottom:(WFRect*)target;
+ (float)getLeft:(WFRect*)target;
+ (float)getRight:(WFRect*)target;
+ (float)getTop:(WFRect*)target;
+ (BOOL)contains:(WFRect*)target point:(WFPoint*)point;
+ (BOOL)equals:(WFRect*)target value:(WFRect*)value;
+ (WFRect*)intersect:(WFRect*)target rect:(WFRect*)rect;
+ (WFRect*)unionWithPoint:(WFRect*)target point:(WFPoint*)point;
+ (WFRect*)unionWithRect:(WFRect*)target rect:(WFRect*)rect;
+ (WFRect*)empty;
@end

#endif // __WXRectHelper_DEFINED__

// Windows.UI.Xaml.SizeHelper
#ifndef __WXSizeHelper_DEFINED__
#define __WXSizeHelper_DEFINED__

WINRT_EXPORT
@interface WXSizeHelper : RTObject
+ (WFSize*)fromDimensions:(float)width height:(float)height;
+ (BOOL)getIsEmpty:(WFSize*)target;
+ (BOOL)equals:(WFSize*)target value:(WFSize*)value;
+ (WFSize*)empty;
@end

#endif // __WXSizeHelper_DEFINED__

// Windows.UI.Xaml.ThicknessHelper
#ifndef __WXThicknessHelper_DEFINED__
#define __WXThicknessHelper_DEFINED__

WINRT_EXPORT
@interface WXThicknessHelper : RTObject
+ (WXThickness*)fromLengths:(double)left top:(double)top right:(double)right bottom:(double)bottom;
+ (WXThickness*)fromUniformLength:(double)uniformLength;
@end

#endif // __WXThicknessHelper_DEFINED__

// Windows.UI.Xaml.BindingFailedEventArgs
#ifndef __WXBindingFailedEventArgs_DEFINED__
#define __WXBindingFailedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXBindingFailedEventArgs : RTObject
@property (readonly) NSString* message;
@end

#endif // __WXBindingFailedEventArgs_DEFINED__

// Windows.UI.Xaml.RoutedEventArgs
#ifndef __WXRoutedEventArgs_DEFINED__
#define __WXRoutedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXRoutedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) RTObject* originalSource;
@end

#endif // __WXRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.UnhandledExceptionEventArgs
#ifndef __WXUnhandledExceptionEventArgs_DEFINED__
#define __WXUnhandledExceptionEventArgs_DEFINED__

WINRT_EXPORT
@interface WXUnhandledExceptionEventArgs : RTObject
@property BOOL handled;
@property (readonly) HRESULT exception;
@property (readonly) NSString* message;
@end

#endif // __WXUnhandledExceptionEventArgs_DEFINED__

// Windows.UI.Xaml.VisualStateChangedEventArgs
#ifndef __WXVisualStateChangedEventArgs_DEFINED__
#define __WXVisualStateChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXVisualStateChangedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) WXVisualState* oldState;
@property (copy) WXVisualState* newState;
@property (copy) WXCControl* control;
@end

#endif // __WXVisualStateChangedEventArgs_DEFINED__

// Windows.UI.Xaml.DataContextChangedEventArgs
#ifndef __WXDataContextChangedEventArgs_DEFINED__
#define __WXDataContextChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXDataContextChangedEventArgs : RTObject
@property BOOL handled;
@property (readonly) RTObject* newValue;
@end

#endif // __WXDataContextChangedEventArgs_DEFINED__

// Windows.UI.Xaml.DataTemplateKey
#ifndef __WXDataTemplateKey_DEFINED__
#define __WXDataTemplateKey_DEFINED__

WINRT_EXPORT
@interface WXDataTemplateKey : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject* dataType;
@end

#endif // __WXDataTemplateKey_DEFINED__

// Windows.UI.Xaml.DebugSettings
#ifndef __WXDebugSettings_DEFINED__
#define __WXDebugSettings_DEFINED__

WINRT_EXPORT
@interface WXDebugSettings : RTObject
@property BOOL isOverdrawHeatMapEnabled;
@property BOOL isBindingTracingEnabled;
@property BOOL enableFrameRateCounter;
@property BOOL enableRedrawRegions;
- (EventRegistrationToken)addBindingFailedEvent:(WXBindingFailedEventHandler)del;
- (void)removeBindingFailedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXDebugSettings_DEFINED__

// Windows.UI.Xaml.DependencyProperty
#ifndef __WXDependencyProperty_DEFINED__
#define __WXDependencyProperty_DEFINED__

WINRT_EXPORT
@interface WXDependencyProperty : RTObject
+ (WXDependencyProperty*)Register:(NSString*)name
                     propertyType:(WUXITypeName*)propertyType
                        ownerType:(WUXITypeName*)ownerType
                     typeMetadata:(WXPropertyMetadata*)typeMetadata;
+ (WXDependencyProperty*)registerAttached:(NSString*)name
                             propertyType:(WUXITypeName*)propertyType
                                ownerType:(WUXITypeName*)ownerType
                          defaultMetadata:(WXPropertyMetadata*)defaultMetadata;
+ (RTObject*)unsetValue;
- (WXPropertyMetadata*)getMetadata:(WUXITypeName*)forType;
@end

#endif // __WXDependencyProperty_DEFINED__

// Windows.UI.Xaml.DependencyObjectCollection
#ifndef __WXDependencyObjectCollection_DEFINED__
#define __WXDependencyObjectCollection_DEFINED__

WINRT_EXPORT
@interface WXDependencyObjectCollection : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
// Could not generate add_VectorChanged (Can't marshal
// Windows.Foundation.Collections.VectorChangedEventHandler`1<Windows.UI.Xaml.DependencyObject>)
- (void)removeVectorChangedEvent:(EventRegistrationToken)tok;
// Could not find base class Windows.Foundation.Collections.IObservableVector`1<Windows.UI.Xaml.DependencyObject> type information
@end

#endif // __WXDependencyObjectCollection_DEFINED__

// Windows.UI.Xaml.PropertyMetadata
#ifndef __WXPropertyMetadata_DEFINED__
#define __WXPropertyMetadata_DEFINED__

WINRT_EXPORT
@interface WXPropertyMetadata : RTObject
+ (WXPropertyMetadata*)createWithDefaultValue:(RTObject*)defaultValue;
+ (WXPropertyMetadata*)createWithDefaultValueAndCallback:(RTObject*)defaultValue
                                 propertyChangedCallback:(WXPropertyChangedCallback)propertyChangedCallback;
+ (WXPropertyMetadata*)createWithFactory:(WXCreateDefaultValueCallback)createDefaultValueCallback;
+ (WXPropertyMetadata*)createWithFactoryAndCallback:(WXCreateDefaultValueCallback)createDefaultValueCallback
                            propertyChangedCallback:(WXPropertyChangedCallback)propertyChangedCallback;
@property (readonly) WXCreateDefaultValueCallback createDefaultValueCallback;
@property (readonly) RTObject* defaultValue;
@end

#endif // __WXPropertyMetadata_DEFINED__

// Windows.UI.Xaml.DispatcherTimer
#ifndef __WXDispatcherTimer_DEFINED__
#define __WXDispatcherTimer_DEFINED__

WINRT_EXPORT
@interface WXDispatcherTimer : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) WFTimeSpan* interval;
@property (readonly) BOOL isEnabled;
- (EventRegistrationToken)addTickEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeTickEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WXDispatcherTimer_DEFINED__

// Windows.UI.Xaml.DragEventArgs
#ifndef __WXDragEventArgs_DEFINED__
#define __WXDragEventArgs_DEFINED__

WINRT_EXPORT
@interface WXDragEventArgs : WXRoutedEventArgs
@property BOOL handled;
@property (copy) WADDataPackage* data;
- (WFPoint*)getPosition:(WXUIElement*)relativeTo;
@end

#endif // __WXDragEventArgs_DEFINED__

// Windows.UI.Xaml.RoutedEvent
#ifndef __WXRoutedEvent_DEFINED__
#define __WXRoutedEvent_DEFINED__

WINRT_EXPORT
@interface WXRoutedEvent : RTObject
@end

#endif // __WXRoutedEvent_DEFINED__

// Windows.UI.Xaml.TriggerActionCollection
#ifndef __WXTriggerActionCollection_DEFINED__
#define __WXTriggerActionCollection_DEFINED__

WINRT_EXPORT
@interface WXTriggerActionCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
@end

#endif // __WXTriggerActionCollection_DEFINED__

// Windows.UI.Xaml.ExceptionRoutedEventArgs
#ifndef __WXExceptionRoutedEventArgs_DEFINED__
#define __WXExceptionRoutedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXExceptionRoutedEventArgs : WXRoutedEventArgs
@property (readonly) NSString* errorMessage;
@end

#endif // __WXExceptionRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.WindowCreatedEventArgs
#ifndef __WXWindowCreatedEventArgs_DEFINED__
#define __WXWindowCreatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXWindowCreatedEventArgs : RTObject
@property (readonly) WXWindow* window;
@end

#endif // __WXWindowCreatedEventArgs_DEFINED__

// Windows.UI.Xaml.Application
#ifndef __WXApplication_DEFINED__
#define __WXApplication_DEFINED__

WINRT_EXPORT
@interface WXApplication : RTObject
+ (void)start:(WXApplicationInitializationCallback)callback;
+ (void)loadComponent:(RTObject*)component resourceLocator:(WFUri*)resourceLocator;
+ (void)loadComponentWithResourceLocation:(RTObject*)component
                          resourceLocator:(WFUri*)resourceLocator
                componentResourceLocation:(WUXCPComponentResourceLocation)componentResourceLocation;
+ (instancetype)create ACTIVATOR;
@property (copy) WXResourceDictionary* resources;
@property WXApplicationTheme requestedTheme;
@property (readonly) WXDebugSettings* debugSettings;
+ (WXApplication*)current;
- (EventRegistrationToken)addResumingEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeResumingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSuspendingEvent:(WXSuspendingEventHandler)del;
- (void)removeSuspendingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnhandledExceptionEvent:(WXUnhandledExceptionEventHandler)del;
- (void)removeUnhandledExceptionEvent:(EventRegistrationToken)tok;
- (void)exit;
- (void)onActivated:(RTObject<WAAIActivatedEventArgs>*)args;
- (void)onLaunched:(WAALaunchActivatedEventArgs*)args;
- (void)onFileActivated:(WAAFileActivatedEventArgs*)args;
- (void)onSearchActivated:(WAASearchActivatedEventArgs*)args;
- (void)onShareTargetActivated:(WAAShareTargetActivatedEventArgs*)args;
- (void)onFileOpenPickerActivated:(WAAFileOpenPickerActivatedEventArgs*)args;
- (void)onFileSavePickerActivated:(WAAFileSavePickerActivatedEventArgs*)args;
- (void)onCachedFileUpdaterActivated:(WAACachedFileUpdaterActivatedEventArgs*)args;
- (void)onWindowCreated:(WXWindowCreatedEventArgs*)args;
@end

#endif // __WXApplication_DEFINED__

// Windows.UI.Xaml.TriggerCollection
#ifndef __WXTriggerCollection_DEFINED__
#define __WXTriggerCollection_DEFINED__

WINRT_EXPORT
@interface WXTriggerCollection : RTObject
@property (readonly) unsigned size;
@end

#endif // __WXTriggerCollection_DEFINED__

// Windows.UI.Xaml.FrameworkTemplate
#ifndef __WXFrameworkTemplate_DEFINED__
#define __WXFrameworkTemplate_DEFINED__

WINRT_EXPORT
@interface WXFrameworkTemplate : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXFrameworkTemplate_DEFINED__

// Windows.UI.Xaml.DataTemplate
#ifndef __WXDataTemplate_DEFINED__
#define __WXDataTemplate_DEFINED__

WINRT_EXPORT
@interface WXDataTemplate : WXFrameworkTemplate
+ (instancetype)create ACTIVATOR;
- (WXDependencyObject*)loadContent;
@end

#endif // __WXDataTemplate_DEFINED__

// Windows.ApplicationModel.Core.IFrameworkView
#ifndef __WACIFrameworkView_DEFINED__
#define __WACIFrameworkView_DEFINED__

@protocol WACIFrameworkView
- (void)initialize:(WACCoreApplicationView*)applicationView;
- (void)setWindow:(WUCCoreWindow*)window;
- (void)load:(NSString*)entryPoint;
- (void)run;
- (void)uninitialize;
@end

#endif // __WACIFrameworkView_DEFINED__

// Windows.UI.Xaml.FrameworkView
#ifndef __WXFrameworkView_DEFINED__
#define __WXFrameworkView_DEFINED__

WINRT_EXPORT
@interface WXFrameworkView : RTObject <WACIFrameworkView>
+ (instancetype)create ACTIVATOR;
- (void)initialize:(WACCoreApplicationView*)applicationView;
- (void)setWindow:(WUCCoreWindow*)window;
- (void)load:(NSString*)entryPoint;
- (void)run;
- (void)uninitialize;
@end

#endif // __WXFrameworkView_DEFINED__

// Windows.ApplicationModel.Core.IFrameworkViewSource
#ifndef __WACIFrameworkViewSource_DEFINED__
#define __WACIFrameworkViewSource_DEFINED__

@protocol WACIFrameworkViewSource
- (RTObject<WACIFrameworkView>*)createView;
@end

#endif // __WACIFrameworkViewSource_DEFINED__

// Windows.UI.Xaml.FrameworkViewSource
#ifndef __WXFrameworkViewSource_DEFINED__
#define __WXFrameworkViewSource_DEFINED__

WINRT_EXPORT
@interface WXFrameworkViewSource : RTObject <WACIFrameworkViewSource>
+ (instancetype)create ACTIVATOR;
- (RTObject<WACIFrameworkView>*)createView;
@end

#endif // __WXFrameworkViewSource_DEFINED__

// Windows.UI.Xaml.MediaFailedRoutedEventArgs
#ifndef __WXMediaFailedRoutedEventArgs_DEFINED__
#define __WXMediaFailedRoutedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXMediaFailedRoutedEventArgs : WXExceptionRoutedEventArgs
@property (readonly) NSString* errorTrace;
@end

#endif // __WXMediaFailedRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.PropertyPath
#ifndef __WXPropertyPath_DEFINED__
#define __WXPropertyPath_DEFINED__

WINRT_EXPORT
@interface WXPropertyPath : WXDependencyObject
+ (WXPropertyPath*)createInstance:(NSString*)path ACTIVATOR;
@property (readonly) NSString* path;
@end

#endif // __WXPropertyPath_DEFINED__

// Windows.UI.Xaml.ResourceDictionary
#ifndef __WXResourceDictionary_DEFINED__
#define __WXResourceDictionary_DEFINED__

WINRT_EXPORT
@interface WXResourceDictionary : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
@property (copy) WFUri* source;
@property (readonly) id<NSFastEnumeration> /*WXResourceDictionary*/ mergedDictionaries;
// Failed to generate property ThemeDictionaries (Can't marshal Windows.Foundation.Collections.IMap`2<System.Object,System.Object>)
// Failed to generate member get_ThemeDictionaries (Can't marshal Windows.Foundation.Collections.IMap`2<System.Object,System.Object>)
// Could not find base class Windows.Foundation.Collections.IMap`2<System.Object,System.Object> type information
@end

#endif // __WXResourceDictionary_DEFINED__

// Windows.UI.Xaml.SetterBase
#ifndef __WXSetterBase_DEFINED__
#define __WXSetterBase_DEFINED__

WINRT_EXPORT
@interface WXSetterBase : WXDependencyObject
@property (readonly) BOOL isSealed;
@end

#endif // __WXSetterBase_DEFINED__

// Windows.UI.Xaml.Setter
#ifndef __WXSetter_DEFINED__
#define __WXSetter_DEFINED__

WINRT_EXPORT
@interface WXSetter : WXSetterBase
+ (instancetype)create ACTIVATOR;
+ (WXSetter*)createInstance:(WXDependencyProperty*)targetProperty value:(RTObject*)value ACTIVATOR;
@property (copy) RTObject* value;
@property (copy) WXDependencyProperty* property ;
@end

#endif // __WXSetter_DEFINED__

// Windows.UI.Xaml.SetterBaseCollection
#ifndef __WXSetterBaseCollection_DEFINED__
#define __WXSetterBaseCollection_DEFINED__

WINRT_EXPORT
@interface WXSetterBaseCollection : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
@property (readonly) BOOL isSealed;
@end

#endif // __WXSetterBaseCollection_DEFINED__

// Windows.UI.Xaml.SizeChangedEventArgs
#ifndef __WXSizeChangedEventArgs_DEFINED__
#define __WXSizeChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXSizeChangedEventArgs : WXRoutedEventArgs
@property (readonly) WFSize* newSize;
@property (readonly) WFSize* previousSize;
@end

#endif // __WXSizeChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Style
#ifndef __WXStyle_DEFINED__
#define __WXStyle_DEFINED__

WINRT_EXPORT
@interface WXStyle : WXDependencyObject
+ (instancetype)create ACTIVATOR;
+ (WXStyle*)createInstance:(WUXITypeName*)targetType ACTIVATOR;
@property (copy) WUXITypeName* targetType;
@property (copy) WXStyle* basedOn;
@property (readonly) BOOL isSealed;
@property (readonly) WXSetterBaseCollection* setters;
- (void)seal;
@end

#endif // __WXStyle_DEFINED__

// Windows.UI.Xaml.TriggerAction
#ifndef __WXTriggerAction_DEFINED__
#define __WXTriggerAction_DEFINED__

WINRT_EXPORT
@interface WXTriggerAction : WXDependencyObject
@end

#endif // __WXTriggerAction_DEFINED__

// Windows.UI.Xaml.TriggerBase
#ifndef __WXTriggerBase_DEFINED__
#define __WXTriggerBase_DEFINED__

WINRT_EXPORT
@interface WXTriggerBase : WXDependencyObject
@end

#endif // __WXTriggerBase_DEFINED__

// Windows.UI.Xaml.EventTrigger
#ifndef __WXEventTrigger_DEFINED__
#define __WXEventTrigger_DEFINED__

WINRT_EXPORT
@interface WXEventTrigger : WXTriggerBase
+ (instancetype)create ACTIVATOR;
@property (copy) WXRoutedEvent* routedEvent;
@property (readonly) WXTriggerActionCollection* actions;
@end

#endif // __WXEventTrigger_DEFINED__

// Windows.UI.Xaml.UIElement
#ifndef __WXUIElement_DEFINED__
#define __WXUIElement_DEFINED__

WINRT_EXPORT
@interface WXUIElement : WXDependencyObject
@property BOOL isTapEnabled;
@property BOOL isRightTapEnabled;
@property BOOL isHoldingEnabled;
@property BOOL isHitTestVisible;
@property BOOL isDoubleTapEnabled;
@property WUXIManipulationModes manipulationMode;
@property (copy) WUXMRectangleGeometry* clip;
@property (copy) WUXMCacheMode* cacheMode;
@property BOOL allowDrop;
@property WXVisibility visibility;
@property BOOL useLayoutRounding;
@property (copy) WUXMATransitionCollection* transitions;
@property (copy) WFPoint* renderTransformOrigin;
@property (copy) WUXMTransform* renderTransform;
@property (copy) WUXMProjection* projection;
@property double opacity;
@property (readonly) WFSize* desiredSize;
@property (readonly) id<NSFastEnumeration> /*WUXIPointer*/ pointerCaptures;
@property (readonly) WFSize* renderSize;
@property WUXMElementCompositeMode compositeMode;
+ (WXDependencyProperty*)compositeModeProperty;
+ (WXDependencyProperty*)allowDropProperty;
+ (WXDependencyProperty*)cacheModeProperty;
+ (WXDependencyProperty*)clipProperty;
+ (WXRoutedEvent*)doubleTappedEvent;
+ (WXRoutedEvent*)dragEnterEvent;
+ (WXRoutedEvent*)dragLeaveEvent;
+ (WXRoutedEvent*)dragOverEvent;
+ (WXRoutedEvent*)dropEvent;
+ (WXRoutedEvent*)holdingEvent;
+ (WXDependencyProperty*)isDoubleTapEnabledProperty;
+ (WXDependencyProperty*)isHitTestVisibleProperty;
+ (WXDependencyProperty*)isHoldingEnabledProperty;
+ (WXDependencyProperty*)isRightTapEnabledProperty;
+ (WXDependencyProperty*)isTapEnabledProperty;
+ (WXRoutedEvent*)keyDownEvent;
+ (WXRoutedEvent*)keyUpEvent;
+ (WXRoutedEvent*)manipulationCompletedEvent;
+ (WXRoutedEvent*)manipulationDeltaEvent;
+ (WXRoutedEvent*)manipulationInertiaStartingEvent;
+ (WXDependencyProperty*)manipulationModeProperty;
+ (WXRoutedEvent*)manipulationStartedEvent;
+ (WXRoutedEvent*)manipulationStartingEvent;
+ (WXDependencyProperty*)opacityProperty;
+ (WXRoutedEvent*)pointerCanceledEvent;
+ (WXRoutedEvent*)pointerCaptureLostEvent;
+ (WXDependencyProperty*)pointerCapturesProperty;
+ (WXRoutedEvent*)pointerEnteredEvent;
+ (WXRoutedEvent*)pointerExitedEvent;
+ (WXRoutedEvent*)pointerMovedEvent;
+ (WXRoutedEvent*)pointerPressedEvent;
+ (WXRoutedEvent*)pointerReleasedEvent;
+ (WXRoutedEvent*)pointerWheelChangedEvent;
+ (WXDependencyProperty*)projectionProperty;
+ (WXDependencyProperty*)renderTransformOriginProperty;
+ (WXDependencyProperty*)renderTransformProperty;
+ (WXRoutedEvent*)rightTappedEvent;
+ (WXRoutedEvent*)tappedEvent;
+ (WXDependencyProperty*)transitionsProperty;
+ (WXDependencyProperty*)useLayoutRoundingProperty;
+ (WXDependencyProperty*)visibilityProperty;
- (EventRegistrationToken)addDoubleTappedEvent:(WUXIDoubleTappedEventHandler)del;
- (void)removeDoubleTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragEnterEvent:(WXDragEventHandler)del;
- (void)removeDragEnterEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragLeaveEvent:(WXDragEventHandler)del;
- (void)removeDragLeaveEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragOverEvent:(WXDragEventHandler)del;
- (void)removeDragOverEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDropEvent:(WXDragEventHandler)del;
- (void)removeDropEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addGotFocusEvent:(WXRoutedEventHandler)del;
- (void)removeGotFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHoldingEvent:(WUXIHoldingEventHandler)del;
- (void)removeHoldingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyDownEvent:(WUXIKeyEventHandler)del;
- (void)removeKeyDownEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyUpEvent:(WUXIKeyEventHandler)del;
- (void)removeKeyUpEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLostFocusEvent:(WXRoutedEventHandler)del;
- (void)removeLostFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationCompletedEvent:(WUXIManipulationCompletedEventHandler)del;
- (void)removeManipulationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationDeltaEvent:(WUXIManipulationDeltaEventHandler)del;
- (void)removeManipulationDeltaEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationInertiaStartingEvent:(WUXIManipulationInertiaStartingEventHandler)del;
- (void)removeManipulationInertiaStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationStartedEvent:(WUXIManipulationStartedEventHandler)del;
- (void)removeManipulationStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationStartingEvent:(WUXIManipulationStartingEventHandler)del;
- (void)removeManipulationStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerCanceledEvent:(WUXIPointerEventHandler)del;
- (void)removePointerCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerCaptureLostEvent:(WUXIPointerEventHandler)del;
- (void)removePointerCaptureLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerEnteredEvent:(WUXIPointerEventHandler)del;
- (void)removePointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerExitedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerMovedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerMovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerPressedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerReleasedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerReleasedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerWheelChangedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerWheelChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRightTappedEvent:(WUXIRightTappedEventHandler)del;
- (void)removeRightTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTappedEvent:(WUXITappedEventHandler)del;
- (void)removeTappedEvent:(EventRegistrationToken)tok;
- (void)measure:(WFSize*)availableSize;
- (void)arrange:(WFRect*)finalRect;
- (BOOL)capturePointer:(WUXIPointer*)value;
- (void)releasePointerCapture:(WUXIPointer*)value;
- (void)releasePointerCaptures;
- (void)addHandler:(WXRoutedEvent*)routedEvent handler:(RTObject*)handler handledEventsToo:(BOOL)handledEventsToo;
- (void)removeHandler:(WXRoutedEvent*)routedEvent handler:(RTObject*)handler;
- (WUXMGeneralTransform*)transformToVisual:(WXUIElement*)visual;
- (void)invalidateMeasure;
- (void)invalidateArrange;
- (void)updateLayout;
- (BOOL)cancelDirectManipulations;
- (WUXAPAutomationPeer*)onCreateAutomationPeer;
- (void)onDisconnectVisualChildren;
// Failed to generate member FindSubElementsForTouchTargeting (Cannot marshal contained object of unknown type
// Windows.Foundation.Collections.IIterable`1<Windows.Foundation.Point>)
@end

#endif // __WXUIElement_DEFINED__

// Windows.UI.Xaml.FrameworkElement
#ifndef __WXFrameworkElement_DEFINED__
#define __WXFrameworkElement_DEFINED__

WINRT_EXPORT
@interface WXFrameworkElement : WXUIElement
+ (instancetype)create ACTIVATOR;
@property WXElementTheme requestedTheme;
@property (copy) NSString* name;
@property (copy) NSString* language;
@property WXHorizontalAlignment horizontalAlignment;
@property double height;
@property WXFlowDirection flowDirection;
@property (copy) RTObject* dataContext;
@property double maxWidth;
@property double maxHeight;
@property (copy) WXStyle* style;
@property double width;
@property WXVerticalAlignment verticalAlignment;
@property (copy) RTObject* tag;
@property (copy) WXResourceDictionary* resources;
@property (copy) WXThickness* margin;
@property double minWidth;
@property double minHeight;
@property (readonly) double actualHeight;
@property (readonly) double actualWidth;
@property (readonly) WXDependencyObject* parent;
@property (readonly) WFUri* baseUri;
@property (readonly) WXTriggerCollection* triggers;
+ (WXDependencyProperty*)verticalAlignmentProperty;
+ (WXDependencyProperty*)widthProperty;
+ (WXDependencyProperty*)actualHeightProperty;
+ (WXDependencyProperty*)actualWidthProperty;
+ (WXDependencyProperty*)dataContextProperty;
+ (WXDependencyProperty*)flowDirectionProperty;
+ (WXDependencyProperty*)heightProperty;
+ (WXDependencyProperty*)horizontalAlignmentProperty;
+ (WXDependencyProperty*)languageProperty;
+ (WXDependencyProperty*)marginProperty;
+ (WXDependencyProperty*)maxHeightProperty;
+ (WXDependencyProperty*)maxWidthProperty;
+ (WXDependencyProperty*)minHeightProperty;
+ (WXDependencyProperty*)minWidthProperty;
+ (WXDependencyProperty*)nameProperty;
+ (WXDependencyProperty*)styleProperty;
+ (WXDependencyProperty*)tagProperty;
+ (WXDependencyProperty*)requestedThemeProperty;
- (EventRegistrationToken)addLayoutUpdatedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeLayoutUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadedEvent:(WXRoutedEventHandler)del;
- (void)removeLoadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSizeChangedEvent:(WXSizeChangedEventHandler)del;
- (void)removeSizeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnloadedEvent:(WXRoutedEventHandler)del;
- (void)removeUnloadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDataContextChangedEvent:(void (^)(WXFrameworkElement*, WXDataContextChangedEventArgs*))del;
- (void)removeDataContextChangedEvent:(EventRegistrationToken)tok;
- (RTObject*)findName:(NSString*)name;
- (void)setBinding:(WXDependencyProperty*)dp binding:(WUXDBindingBase*)binding;
- (WUXDBindingExpression*)getBindingExpression:(WXDependencyProperty*)dp;
- (WFSize*)measureOverride:(WFSize*)availableSize;
- (WFSize*)arrangeOverride:(WFSize*)finalSize;
- (void)onApplyTemplate;
- (BOOL)goToElementStateCore:(NSString*)stateName useTransitions:(BOOL)useTransitions;
@end

#endif // __WXFrameworkElement_DEFINED__

// Windows.UI.Xaml.VisualState
#ifndef __WXVisualState_DEFINED__
#define __WXVisualState_DEFINED__

WINRT_EXPORT
@interface WXVisualState : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMAStoryboard* storyboard;
@property (readonly) NSString* name;
@end

#endif // __WXVisualState_DEFINED__

// Windows.UI.Xaml.VisualStateGroup
#ifndef __WXVisualStateGroup_DEFINED__
#define __WXVisualStateGroup_DEFINED__

WINRT_EXPORT
@interface WXVisualStateGroup : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WXVisualState* currentState;
@property (readonly) NSString* name;
@property (readonly) id<NSFastEnumeration> /*WXVisualState*/ states;
@property (readonly) id<NSFastEnumeration> /*WXVisualTransition*/ transitions;
- (EventRegistrationToken)addCurrentStateChangedEvent:(WXVisualStateChangedEventHandler)del;
- (void)removeCurrentStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCurrentStateChangingEvent:(WXVisualStateChangedEventHandler)del;
- (void)removeCurrentStateChangingEvent:(EventRegistrationToken)tok;
@end

#endif // __WXVisualStateGroup_DEFINED__

// Windows.UI.Xaml.VisualStateManager
#ifndef __WXVisualStateManager_DEFINED__
#define __WXVisualStateManager_DEFINED__

WINRT_EXPORT
@interface WXVisualStateManager : WXDependencyObject
+ (id<NSFastEnumeration> /*WXVisualStateGroup*/)getVisualStateGroups:(WXFrameworkElement*)obj;
+ (WXVisualStateManager*)getCustomVisualStateManager:(WXFrameworkElement*)obj;
+ (void)setCustomVisualStateManager:(WXFrameworkElement*)obj value:(WXVisualStateManager*)value;
+ (BOOL)goToState:(WXCControl*)control stateName:(NSString*)stateName useTransitions:(BOOL)useTransitions;
+ (instancetype)create ACTIVATOR;
+ (WXDependencyProperty*)customVisualStateManagerProperty;
- (BOOL)goToStateCore:(WXCControl*)control
         templateRoot:(WXFrameworkElement*)templateRoot
            stateName:(NSString*)stateName
                group:(WXVisualStateGroup*)group
                state:(WXVisualState*)state
       useTransitions:(BOOL)useTransitions;
- (void)raiseCurrentStateChanging:(WXVisualStateGroup*)stateGroup
                         oldState:(WXVisualState*)oldState
                         newState:(WXVisualState*)newState
                          control:(WXCControl*)control;
- (void)raiseCurrentStateChanged:(WXVisualStateGroup*)stateGroup
                        oldState:(WXVisualState*)oldState
                        newState:(WXVisualState*)newState
                         control:(WXCControl*)control;
@end

#endif // __WXVisualStateManager_DEFINED__

// Windows.UI.Xaml.VisualTransition
#ifndef __WXVisualTransition_DEFINED__
#define __WXVisualTransition_DEFINED__

WINRT_EXPORT
@interface WXVisualTransition : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* to;
@property (copy) WUXMAStoryboard* storyboard;
@property (copy) WUXMAEasingFunctionBase* generatedEasingFunction;
@property (copy) WXDuration* generatedDuration;
@property (copy) NSString* from;
@end

#endif // __WXVisualTransition_DEFINED__

// Windows.UI.Xaml.Window
#ifndef __WXWindow_DEFINED__
#define __WXWindow_DEFINED__

WINRT_EXPORT
@interface WXWindow : RTObject
@property (copy) WXUIElement* content;
@property (readonly) WFRect* bounds;
@property (readonly) WUCCoreWindow* coreWindow;
@property (readonly) WUCCoreDispatcher* dispatcher;
@property (readonly) BOOL visible;
+ (WXWindow*)current;
- (EventRegistrationToken)addActivatedEvent:(WXWindowActivatedEventHandler)del;
- (void)removeActivatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addClosedEvent:(WXWindowClosedEventHandler)del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSizeChangedEvent:(WXWindowSizeChangedEventHandler)del;
- (void)removeSizeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVisibilityChangedEvent:(WXWindowVisibilityChangedEventHandler)del;
- (void)removeVisibilityChangedEvent:(EventRegistrationToken)tok;
- (void)activate;
- (void)close;
@end

#endif // __WXWindow_DEFINED__
