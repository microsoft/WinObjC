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

// MicrosoftAdvertisingWinRTUI.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPMICROSOFTADVERTISINGEXPORT
#define OBJCUWPMICROSOFTADVERTISINGEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_MSAds_BUILD
#pragma comment(lib, "ObjCUWPMicrosoftAdvertising.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class MAWUAdErrorEventArgs, MAWUManipulationStateChangedEventArgs, MAWUPointerMoveEventArgs, MAWUMouseWheelEventArgs, MAWUPointerDownEventArgs, MAWUAdControl, MAWUExpandProperties, MAWUblank, MAWUInterstitialAd, MAWUVpaidEventArgs;
@protocol MAWU__IAdErrorEventArgsPublicNonVirtuals, MAWU__IManipulationStateChangedEventArgsPublicNonVirtuals, MAWU__IManipulationStateChangedEventArgsFactory, MAWU__IPointerMoveEventArgsPublicNonVirtuals, MAWU__IMouseWheelEventArgsPublicNonVirtuals, MAWU__IPointerDownEventArgsPublicNonVirtuals, MAWU__IAdControlPublicNonVirtuals, MAWU__IAdControlProtectedNonVirtuals, MAWU__IExpandPropertiesPublicNonVirtuals, MAWU__IExpandPropertiesFactory, MAWU__IExpandPropertiesStatics, MAWUIAdvertisingWebBrowser, MAWU__IblankPublicNonVirtuals, MAWU__IInterstitialAdPublicNonVirtuals, MAWU__IInterstitialAdProtectedNonVirtuals, MAWU__IVpaidEventArgsPublicNonVirtuals;

// Microsoft.Advertising.WinRT.UI.AdType
enum _MAWUAdType {
    MAWUAdTypeVideo = 0,
};
typedef unsigned MAWUAdType;

// Microsoft.Advertising.WinRT.UI.InterstitialAdState
enum _MAWUInterstitialAdState {
    MAWUInterstitialAdStateNotReady = 0,
    MAWUInterstitialAdStateReady = 1,
    MAWUInterstitialAdStateShowing = 2,
    MAWUInterstitialAdStateClosed = 3,
};
typedef unsigned MAWUInterstitialAdState;

// Microsoft.Advertising.WinRT.UI.RichMediaAdState
enum _MAWURichMediaAdState {
    MAWURichMediaAdStateDefault = 0,
    MAWURichMediaAdStateResized = 1,
    MAWURichMediaAdStateExpanded = 2,
    MAWURichMediaAdStateHidden = 3,
    MAWURichMediaAdStateSuspended = 4,
};
typedef unsigned MAWURichMediaAdState;

// Microsoft.Advertising.WinRT.UI.RichMediaActionType
enum _MAWURichMediaActionType {
    MAWURichMediaActionTypeSms = 0,
    MAWURichMediaActionTypeMail = 1,
    MAWURichMediaActionTypeCall = 2,
    MAWURichMediaActionTypeMedia = 3,
    MAWURichMediaActionTypeWeb = 4,
    MAWURichMediaActionTypeClose = 5,
    MAWURichMediaActionTypeExpand = 6,
    MAWURichMediaActionTypeResize = 7,
    MAWURichMediaActionTypeHide = 8,
    MAWURichMediaActionTypeShow = 9,
    MAWURichMediaActionTypeStorePicture = 10,
    MAWURichMediaActionTypeMarketplace = 11,
    MAWURichMediaActionTypeUserEngaged = 12,
    MAWURichMediaActionTypeUserDisengaged = 13,
};
typedef unsigned MAWURichMediaActionType;

// Microsoft.Advertising.WinRT.UI.VastErrorCode
enum _MAWUVastErrorCode {
    MAWUVastErrorCodeVastGeneralLinearError = 400,
    MAWUVastErrorCodeVastFileNotFound = 401,
    MAWUVastErrorCodeVastMediaTimeout = 402,
    MAWUVastErrorCodeVastNoSupportedMedia = 403,
    MAWUVastErrorCodeVastUnableToPlayFile = 405,
    MAWUVastErrorCodeGeneralVpaidError = 901,
};
typedef unsigned MAWUVastErrorCode;

#include "MicrosoftAdvertising.h"
#include "UWP/WindowsUIXamlInput.h"
#include "UWP/WindowsUIXaml.h"
#include "UWP/WindowsFoundation.h"
#include "UWP/WindowsUIXamlControls.h"
#include "UWP/WindowsUIXamlMediaAnimation.h"
#include "UWP/WindowsApplicationModelDataTransfer.h"
#include "UWP/WindowsUIXamlMedia.h"
#include "UWP/WindowsUIInput.h"
#include "UWP/WindowsUIXamlAutomationPeers.h"
#include "UWP/WindowsUIXamlMarkup.h"
#include "UWP/WindowsUIXamlControlsPrimitives.h"
#include "UWP/WindowsUIXamlData.h"
#include "UWP/WindowsUIXamlMediaMedia3D.h"
#include "UWP/WindowsUICore.h"
#include "UWP/WindowsUIText.h"
// Windows.UI.Xaml.DependencyPropertyChangedCallback
#ifndef __WXDependencyPropertyChangedCallback__DEFINED
#define __WXDependencyPropertyChangedCallback__DEFINED
typedef void(^WXDependencyPropertyChangedCallback)(WXDependencyObject* sender, WXDependencyProperty* dp);
#endif // __WXDependencyPropertyChangedCallback__DEFINED

// Windows.UI.Xaml.DependencyPropertyChangedEventHandler
#ifndef __WXDependencyPropertyChangedEventHandler__DEFINED
#define __WXDependencyPropertyChangedEventHandler__DEFINED
typedef void(^WXDependencyPropertyChangedEventHandler)(RTObject* sender, WXDependencyPropertyChangedEventArgs* e);
#endif // __WXDependencyPropertyChangedEventHandler__DEFINED

// Windows.UI.Xaml.DragEventHandler
#ifndef __WXDragEventHandler__DEFINED
#define __WXDragEventHandler__DEFINED
typedef void(^WXDragEventHandler)(RTObject* sender, WXDragEventArgs* e);
#endif // __WXDragEventHandler__DEFINED

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

// Windows.UI.Xaml.RoutedEventHandler
#ifndef __WXRoutedEventHandler__DEFINED
#define __WXRoutedEventHandler__DEFINED
typedef void(^WXRoutedEventHandler)(RTObject* sender, WXRoutedEventArgs* e);
#endif // __WXRoutedEventHandler__DEFINED

// Windows.UI.Xaml.SizeChangedEventHandler
#ifndef __WXSizeChangedEventHandler__DEFINED
#define __WXSizeChangedEventHandler__DEFINED
typedef void(^WXSizeChangedEventHandler)(RTObject* sender, WXSizeChangedEventArgs* e);
#endif // __WXSizeChangedEventHandler__DEFINED


#import <Foundation/Foundation.h>

// Microsoft.Advertising.WinRT.UI.ExpandedCloseDelegate
#ifndef __MAWUExpandedCloseDelegate__DEFINED
#define __MAWUExpandedCloseDelegate__DEFINED
typedef void(^MAWUExpandedCloseDelegate)();
#endif // __MAWUExpandedCloseDelegate__DEFINED

// Microsoft.Advertising.WinRT.UI.IAdvertisingWebBrowser
#ifndef __MAWUIAdvertisingWebBrowser_DEFINED__
#define __MAWUIAdvertisingWebBrowser_DEFINED__

@protocol MAWUIAdvertisingWebBrowser
- (double)getContainerWidth;
- (double)getContainerHeight;
- (void)expand1:(WFUri*)uri expandProperties:(MAWUExpandProperties*)expandProperties isLegacyAd:(BOOL)isLegacyAd;
- (void)expand2:(WFUri*)uri expandProperties:(MAWUExpandProperties*)expandProperties;
- (void)resize:(double)width height:(double)height;
- (void)updateExpandProperties:(MAWUExpandProperties*)expandProps;
- (void)setUseCustomClose:(BOOL)useCustomClose;
- (void)raiseAdLoadFailedEvent:(NSString *)message;
- (void)closeExpandedView;
@end

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MAWUIAdvertisingWebBrowser : RTObject <MAWUIAdvertisingWebBrowser>
@end

#endif // __MAWUIAdvertisingWebBrowser_DEFINED__

// Microsoft.Advertising.WinRT.UI.AdErrorEventArgs
#ifndef __MAWUAdErrorEventArgs_DEFINED__
#define __MAWUAdErrorEventArgs_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MAWUAdErrorEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * errorMessage;
@property (readonly) MAErrorCode errorCode;
@end

#endif // __MAWUAdErrorEventArgs_DEFINED__

// Microsoft.Advertising.WinRT.UI.ManipulationStateChangedEventArgs
#ifndef __MAWUManipulationStateChangedEventArgs_DEFINED__
#define __MAWUManipulationStateChangedEventArgs_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MAWUManipulationStateChangedEventArgs : RTObject
+ (MAWUManipulationStateChangedEventArgs*)makeInstance1:(int)current last:(int)last ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int lastState;
@property (readonly) int currentState;
@end

#endif // __MAWUManipulationStateChangedEventArgs_DEFINED__

// Microsoft.Advertising.WinRT.UI.PointerMoveEventArgs
#ifndef __MAWUPointerMoveEventArgs_DEFINED__
#define __MAWUPointerMoveEventArgs_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MAWUPointerMoveEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFPoint* mouseCoordinate;
@end

#endif // __MAWUPointerMoveEventArgs_DEFINED__

// Microsoft.Advertising.WinRT.UI.MouseWheelEventArgs
#ifndef __MAWUMouseWheelEventArgs_DEFINED__
#define __MAWUMouseWheelEventArgs_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MAWUMouseWheelEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int wheelDelta;
@property (readonly) BOOL ctrlKeyPressed;
@property (readonly) MAWUPointerMoveEventArgs* pointerCoordinate;
@end

#endif // __MAWUMouseWheelEventArgs_DEFINED__

// Microsoft.Advertising.WinRT.UI.PointerDownEventArgs
#ifndef __MAWUPointerDownEventArgs_DEFINED__
#define __MAWUPointerDownEventArgs_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MAWUPointerDownEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int keyCode;
@property (readonly) NSString * pointerType;
@property (readonly) MAWUPointerMoveEventArgs* pointerCoordinate;
@end

#endif // __MAWUPointerDownEventArgs_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.IScrollSnapPointsInfo
#ifndef __WUXCPIScrollSnapPointsInfo_DEFINED__
#define __WUXCPIScrollSnapPointsInfo_DEFINED__

@protocol WUXCPIScrollSnapPointsInfo
@property (readonly) BOOL areHorizontalSnapPointsRegular;
@property (readonly) BOOL areVerticalSnapPointsRegular;
- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (NSArray* /* float */)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
@end

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WUXCPIScrollSnapPointsInfo : RTObject <WUXCPIScrollSnapPointsInfo>
@end

#endif // __WUXCPIScrollSnapPointsInfo_DEFINED__

// Windows.UI.Xaml.Controls.IInsertionPanel
#ifndef __WXCIInsertionPanel_DEFINED__
#define __WXCIInsertionPanel_DEFINED__

@protocol WXCIInsertionPanel
- (void)getInsertionIndexes:(WFPoint*)position first:(int*)first second:(int*)second;
@end

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WXCIInsertionPanel : RTObject <WXCIInsertionPanel>
@end

#endif // __WXCIInsertionPanel_DEFINED__

// Windows.UI.Xaml.IFrameworkElementOverrides
#ifndef __WXIFrameworkElementOverrides_DEFINED__
#define __WXIFrameworkElementOverrides_DEFINED__

@protocol WXIFrameworkElementOverrides
- (WFSize*)measureOverride:(WFSize*)availableSize;
- (WFSize*)arrangeOverride:(WFSize*)finalSize;
- (void)onApplyTemplate;
@end

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WXIFrameworkElementOverrides : RTObject <WXIFrameworkElementOverrides>
@end

#endif // __WXIFrameworkElementOverrides_DEFINED__

// Windows.UI.Xaml.IFrameworkElementOverrides2
#ifndef __WXIFrameworkElementOverrides2_DEFINED__
#define __WXIFrameworkElementOverrides2_DEFINED__

@protocol WXIFrameworkElementOverrides2
- (BOOL)goToElementStateCore:(NSString *)stateName useTransitions:(BOOL)useTransitions;
@end

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WXIFrameworkElementOverrides2 : RTObject <WXIFrameworkElementOverrides2>
@end

#endif // __WXIFrameworkElementOverrides2_DEFINED__

// Windows.UI.Xaml.IUIElementOverrides
#ifndef __WXIUIElementOverrides_DEFINED__
#define __WXIUIElementOverrides_DEFINED__

@protocol WXIUIElementOverrides
- (WUXAPAutomationPeer*)onCreateAutomationPeer;
- (void)onDisconnectVisualChildren;
- (id<NSFastEnumeration> /* id<NSFastEnumeration> < WFPoint* > */)findSubElementsForTouchTargeting:(WFPoint*)point boundingRect:(WFRect*)boundingRect;
@end

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WXIUIElementOverrides : RTObject <WXIUIElementOverrides>
@end

#endif // __WXIUIElementOverrides_DEFINED__

// Windows.UI.Xaml.DependencyObject
#ifndef __WXDependencyObject_DEFINED__
#define __WXDependencyObject_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
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

// Windows.UI.Xaml.UIElement
#ifndef __WXUIElement_DEFINED__
#define __WXUIElement_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WXUIElement : WXDependencyObject
+ (BOOL)tryStartDirectManipulation:(WUXIPointer*)value;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isHitTestVisible;
@property BOOL isDoubleTapEnabled;
@property double opacity;
@property (retain) WUXMProjection* projection;
@property (retain) WUXMRectangleGeometry* clip;
@property (retain) WUXMCacheMode* cacheMode;
@property WUXIManipulationModes manipulationMode;
@property BOOL isTapEnabled;
@property BOOL isRightTapEnabled;
@property BOOL isHoldingEnabled;
@property BOOL allowDrop;
@property WXVisibility visibility;
@property BOOL useLayoutRounding;
@property (retain) WUXMATransitionCollection* transitions;
@property (retain) WFPoint* renderTransformOrigin;
@property (retain) WUXMTransform* renderTransform;
@property (readonly) NSArray* /* WUXIPointer* */ pointerCaptures;
@property (readonly) WFSize* desiredSize;
@property (readonly) WFSize* renderSize;
@property WUXMElementCompositeMode compositeMode;
@property (retain) WUXMMTransform3D* transform3D;
@property BOOL canDrag;
@property BOOL isAccessKeyScope;
@property BOOL exitDisplayModeOnAccessKeyInvoked;
@property (retain) WUXCPFlyoutBase* contextFlyout;
@property (retain) WXDependencyObject* accessKeyScopeOwner;
@property (retain) NSString * accessKey;
+ (WXDependencyProperty*)isRightTapEnabledProperty;
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
+ (WXDependencyProperty*)compositeModeProperty;
+ (WXDependencyProperty*)canDragProperty;
+ (WXDependencyProperty*)transform3DProperty;
+ (WXDependencyProperty*)accessKeyScopeOwnerProperty;
+ (WXDependencyProperty*)contextFlyoutProperty;
+ (WXDependencyProperty*)exitDisplayModeOnAccessKeyInvokedProperty;
+ (WXDependencyProperty*)isAccessKeyScopeProperty;
+ (WXDependencyProperty*)accessKeyProperty;
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
- (EventRegistrationToken)addDragStartingEvent:(void(^)(WXUIElement*, WXDragStartingEventArgs*))del;
- (void)removeDragStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDropCompletedEvent:(void(^)(WXUIElement*, WXDropCompletedEventArgs*))del;
- (void)removeDropCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccessKeyDisplayDismissedEvent:(void(^)(WXUIElement*, WUXIAccessKeyDisplayDismissedEventArgs*))del;
- (void)removeAccessKeyDisplayDismissedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccessKeyDisplayRequestedEvent:(void(^)(WXUIElement*, WUXIAccessKeyDisplayRequestedEventArgs*))del;
- (void)removeAccessKeyDisplayRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccessKeyInvokedEvent:(void(^)(WXUIElement*, WUXIAccessKeyInvokedEventArgs*))del;
- (void)removeAccessKeyInvokedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addContextCanceledEvent:(void(^)(WXUIElement*, WXRoutedEventArgs*))del;
- (void)removeContextCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addContextRequestedEvent:(void(^)(WXUIElement*, WUXIContextRequestedEventArgs*))del;
- (void)removeContextRequestedEvent:(EventRegistrationToken)tok;
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
- (void)startDragAsync:(WUIPointerPoint*)pointerPoint success:(void (^)(WADDataPackageOperation))success failure:(void (^)(NSError*))failure;
@end

#endif // __WXUIElement_DEFINED__

// Windows.UI.Xaml.FrameworkElement
#ifndef __WXFrameworkElement_DEFINED__
#define __WXFrameworkElement_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WXFrameworkElement : WXUIElement
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double height;
@property WXFlowDirection flowDirection;
@property double minHeight;
@property (retain) RTObject* dataContext;
@property (retain) NSString * name;
@property double minWidth;
@property double maxWidth;
@property double maxHeight;
@property (retain) WXThickness* margin;
@property (retain) NSString * language;
@property WXHorizontalAlignment horizontalAlignment;
@property (retain) WXResourceDictionary* resources;
@property double width;
@property WXVerticalAlignment verticalAlignment;
@property (retain) RTObject* tag;
@property (retain) WXStyle* style;
@property (readonly) WFUri* baseUri;
@property (readonly) double actualHeight;
@property (readonly) WXDependencyObject* parent;
@property (readonly) WXTriggerCollection* triggers;
@property (readonly) double actualWidth;
@property WXElementTheme requestedTheme;
@property (retain) WXThickness* focusVisualMargin;
@property (retain) WUXMBrush* focusVisualSecondaryBrush;
@property (retain) WXThickness* focusVisualPrimaryThickness;
@property (retain) WUXMBrush* focusVisualPrimaryBrush;
@property BOOL allowFocusWhenDisabled;
@property BOOL allowFocusOnInteraction;
@property (retain) WXThickness* focusVisualSecondaryThickness;
+ (WXDependencyProperty*)styleProperty;
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
+ (WXDependencyProperty*)tagProperty;
+ (WXDependencyProperty*)verticalAlignmentProperty;
+ (WXDependencyProperty*)widthProperty;
+ (WXDependencyProperty*)requestedThemeProperty;
+ (WXDependencyProperty*)allowFocusOnInteractionProperty;
+ (WXDependencyProperty*)allowFocusWhenDisabledProperty;
+ (WXDependencyProperty*)focusVisualMarginProperty;
+ (WXDependencyProperty*)focusVisualPrimaryBrushProperty;
+ (WXDependencyProperty*)focusVisualPrimaryThicknessProperty;
+ (WXDependencyProperty*)focusVisualSecondaryBrushProperty;
+ (WXDependencyProperty*)focusVisualSecondaryThicknessProperty;
- (EventRegistrationToken)addLayoutUpdatedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeLayoutUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadedEvent:(WXRoutedEventHandler)del;
- (void)removeLoadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSizeChangedEvent:(WXSizeChangedEventHandler)del;
- (void)removeSizeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnloadedEvent:(WXRoutedEventHandler)del;
- (void)removeUnloadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDataContextChangedEvent:(void(^)(WXFrameworkElement*, WXDataContextChangedEventArgs*))del;
- (void)removeDataContextChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadingEvent:(void(^)(WXFrameworkElement*, RTObject*))del;
- (void)removeLoadingEvent:(EventRegistrationToken)tok;
- (RTObject*)findName:(NSString *)name;
- (void)setBinding:(WXDependencyProperty*)dp binding:(WUXDBindingBase*)binding;
- (WUXDBindingExpression*)getBindingExpression:(WXDependencyProperty*)dp;
@end

#endif // __WXFrameworkElement_DEFINED__

// Windows.UI.Xaml.Controls.Panel
#ifndef __WXCPanel_DEFINED__
#define __WXCPanel_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WXCPanel : WXFrameworkElement
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMATransitionCollection* childrenTransitions;
@property (retain) WUXMBrush* background;
@property (readonly) WXCUIElementCollection* children;
@property (readonly) BOOL isItemsHost;
+ (WXDependencyProperty*)backgroundProperty;
+ (WXDependencyProperty*)childrenTransitionsProperty;
+ (WXDependencyProperty*)isItemsHostProperty;
@end

#endif // __WXCPanel_DEFINED__

// Windows.UI.Xaml.Controls.StackPanel
#ifndef __WXCStackPanel_DEFINED__
#define __WXCStackPanel_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WXCStackPanel : WXCPanel <WUXCPIScrollSnapPointsInfo, WXCIInsertionPanel>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCOrientation orientation;
@property BOOL areScrollSnapPointsRegular;
@property (retain) WXThickness* padding;
@property (retain) WXCornerRadius* cornerRadius;
@property (retain) WXThickness* borderThickness;
@property (retain) WUXMBrush* borderBrush;
@property (readonly) BOOL areHorizontalSnapPointsRegular;
@property (readonly) BOOL areVerticalSnapPointsRegular;
+ (WXDependencyProperty*)areScrollSnapPointsRegularProperty;
+ (WXDependencyProperty*)orientationProperty;
+ (WXDependencyProperty*)borderBrushProperty;
+ (WXDependencyProperty*)borderThicknessProperty;
+ (WXDependencyProperty*)cornerRadiusProperty;
+ (WXDependencyProperty*)paddingProperty;
- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (NSArray* /* float */)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
- (void)getInsertionIndexes:(WFPoint*)position first:(int*)first second:(int*)second;
@end

#endif // __WXCStackPanel_DEFINED__

// Microsoft.Advertising.WinRT.UI.AdControl
#ifndef __MAWUAdControl_DEFINED__
#define __MAWUAdControl_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MAWUAdControl : WXCStackPanel <WFIClosable>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL hasAd;
@property (readonly) BOOL isSuspended;
@property (retain) NSString * postalCode;
@property (retain) NSString * countryOrRegion;
@property (retain) NSString * keywords;
@property int autoRefreshIntervalInSeconds;
@property BOOL isAutoRefreshEnabled;
@property (readonly) BOOL isEngaged;
@property (retain) NSString * applicationId;
@property (retain) NSString * adUnitId;
- (EventRegistrationToken)addOnManipulationStateChangedEvent:(void(^)(RTObject*, MAWUManipulationStateChangedEventArgs*))del;
- (void)removeOnManipulationStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOnPointerMoveEvent:(void(^)(RTObject*, MAWUPointerMoveEventArgs*))del;
- (void)removeOnPointerMoveEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOnMouseWheelEvent:(void(^)(RTObject*, MAWUMouseWheelEventArgs*))del;
- (void)removeOnMouseWheelEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOnPointerDownEvent:(void(^)(RTObject*, MAWUPointerDownEventArgs*))del;
- (void)removeOnPointerDownEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOnPointerUpEvent:(void(^)(RTObject*, WXRoutedEventArgs*))del;
- (void)removeOnPointerUpEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addIsEngagedChangedEvent:(void(^)(RTObject*, WXRoutedEventArgs*))del;
- (void)removeIsEngagedChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAdRefreshedEvent:(void(^)(RTObject*, WXRoutedEventArgs*))del;
- (void)removeAdRefreshedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addErrorOccurredEvent:(void(^)(RTObject*, MAWUAdErrorEventArgs*))del;
- (void)removeErrorOccurredEvent:(EventRegistrationToken)tok;
- (void)close;
- (void)refresh1;
- (void)addAdTag:(NSString *)tagName tagValue:(NSString *)tagValue;
- (void)removeAdTag:(NSString *)tagName;
- (void)suspend;
- (void)resume;
@end

#endif // __MAWUAdControl_DEFINED__

// Microsoft.Advertising.WinRT.UI.ExpandProperties
#ifndef __MAWUExpandProperties_DEFINED__
#define __MAWUExpandProperties_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MAWUExpandProperties : RTObject
+ (MAWUExpandProperties*)getDefault;
+ (MAWUExpandProperties*)makeInstance1:(int)width height:(int)height useCustomClose:(BOOL)useCustomClose lockOrientation:(BOOL)lockOrientation ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL lockOrientation;
@property (readonly) BOOL isModal;
@property BOOL useCustomClose;
@property int height;
@property int width;
@end

#endif // __MAWUExpandProperties_DEFINED__

// Windows.UI.Xaml.Markup.IComponentConnector
#ifndef __WUXMIComponentConnector_DEFINED__
#define __WUXMIComponentConnector_DEFINED__

@protocol WUXMIComponentConnector
- (void)connect:(int)connectionId target:(RTObject*)target;
@end

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WUXMIComponentConnector : RTObject <WUXMIComponentConnector>
@end

#endif // __WUXMIComponentConnector_DEFINED__

// Windows.UI.Xaml.Markup.IComponentConnector2
#ifndef __WUXMIComponentConnector2_DEFINED__
#define __WUXMIComponentConnector2_DEFINED__

@protocol WUXMIComponentConnector2
- (RTObject<WUXMIComponentConnector>*)getBindingConnector:(int)connectionId target:(RTObject*)target;
@end

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WUXMIComponentConnector2 : RTObject <WUXMIComponentConnector2>
@end

#endif // __WUXMIComponentConnector2_DEFINED__

// Windows.UI.Xaml.Controls.IControlOverrides
#ifndef __WXCIControlOverrides_DEFINED__
#define __WXCIControlOverrides_DEFINED__

@protocol WXCIControlOverrides
- (void)onPointerEntered:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerPressed:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerMoved:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerReleased:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerExited:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerCaptureLost:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerCanceled:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerWheelChanged:(WUXIPointerRoutedEventArgs*)e;
- (void)onTapped:(WUXITappedRoutedEventArgs*)e;
- (void)onDoubleTapped:(WUXIDoubleTappedRoutedEventArgs*)e;
- (void)onHolding:(WUXIHoldingRoutedEventArgs*)e;
- (void)onRightTapped:(WUXIRightTappedRoutedEventArgs*)e;
- (void)onManipulationStarting:(WUXIManipulationStartingRoutedEventArgs*)e;
- (void)onManipulationInertiaStarting:(WUXIManipulationInertiaStartingRoutedEventArgs*)e;
- (void)onManipulationStarted:(WUXIManipulationStartedRoutedEventArgs*)e;
- (void)onManipulationDelta:(WUXIManipulationDeltaRoutedEventArgs*)e;
- (void)onManipulationCompleted:(WUXIManipulationCompletedRoutedEventArgs*)e;
- (void)onKeyUp:(WUXIKeyRoutedEventArgs*)e;
- (void)onKeyDown:(WUXIKeyRoutedEventArgs*)e;
- (void)onGotFocus:(WXRoutedEventArgs*)e;
- (void)onLostFocus:(WXRoutedEventArgs*)e;
- (void)onDragEnter:(WXDragEventArgs*)e;
- (void)onDragLeave:(WXDragEventArgs*)e;
- (void)onDragOver:(WXDragEventArgs*)e;
- (void)onDrop:(WXDragEventArgs*)e;
@end

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WXCIControlOverrides : RTObject <WXCIControlOverrides>
@end

#endif // __WXCIControlOverrides_DEFINED__

// Windows.UI.Xaml.Controls.Control
#ifndef __WXCControl_DEFINED__
#define __WXCControl_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WXCControl : WXFrameworkElement
+ (BOOL)getIsTemplateFocusTarget:(WXFrameworkElement*)element;
+ (void)setIsTemplateFocusTarget:(WXFrameworkElement*)element value:(BOOL)value;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double fontSize;
@property (retain) WUXMFontFamily* fontFamily;
@property (retain) WXThickness* padding;
@property int tabIndex;
@property int characterSpacing;
@property (retain) WXThickness* borderThickness;
@property BOOL isEnabled;
@property (retain) WUXMBrush* borderBrush;
@property WUTFontStretch fontStretch;
@property BOOL isTabStop;
@property WXHorizontalAlignment horizontalContentAlignment;
@property (retain) WUXMBrush* foreground;
@property (retain) WUTFontWeight* fontWeight;
@property WUTFontStyle fontStyle;
@property (retain) WUXMBrush* background;
@property WXVerticalAlignment verticalContentAlignment;
@property (retain) WXCControlTemplate* Template;
@property WUXIKeyboardNavigationMode tabNavigation;
@property (readonly) WXFocusState focusState;
@property BOOL isTextScaleFactorEnabled;
@property BOOL useSystemFocusVisuals;
@property (retain) WXDependencyObject* xYFocusRight;
@property BOOL isFocusEngaged;
@property (retain) WXDependencyObject* xYFocusLeft;
@property (retain) WXDependencyObject* xYFocusDown;
@property WXCRequiresPointer requiresPointer;
@property BOOL isFocusEngagementEnabled;
@property WXElementSoundMode elementSoundMode;
@property (retain) WXDependencyObject* xYFocusUp;
+ (WXDependencyProperty*)isEnabledProperty;
+ (WXDependencyProperty*)backgroundProperty;
+ (WXDependencyProperty*)borderBrushProperty;
+ (WXDependencyProperty*)borderThicknessProperty;
+ (WXDependencyProperty*)characterSpacingProperty;
+ (WXDependencyProperty*)defaultStyleKeyProperty;
+ (WXDependencyProperty*)focusStateProperty;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)fontStretchProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)fontWeightProperty;
+ (WXDependencyProperty*)foregroundProperty;
+ (WXDependencyProperty*)horizontalContentAlignmentProperty;
+ (WXDependencyProperty*)isTabStopProperty;
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)tabIndexProperty;
+ (WXDependencyProperty*)tabNavigationProperty;
+ (WXDependencyProperty*)templateProperty;
+ (WXDependencyProperty*)verticalContentAlignmentProperty;
+ (WXDependencyProperty*)isTextScaleFactorEnabledProperty;
+ (WXDependencyProperty*)isTemplateFocusTargetProperty;
+ (WXDependencyProperty*)useSystemFocusVisualsProperty;
+ (WXDependencyProperty*)elementSoundModeProperty;
+ (WXDependencyProperty*)isFocusEngagedProperty;
+ (WXDependencyProperty*)isFocusEngagementEnabledProperty;
+ (WXDependencyProperty*)requiresPointerProperty;
+ (WXDependencyProperty*)xYFocusDownProperty;
+ (WXDependencyProperty*)xYFocusLeftProperty;
+ (WXDependencyProperty*)xYFocusRightProperty;
+ (WXDependencyProperty*)xYFocusUpProperty;
- (EventRegistrationToken)addIsEnabledChangedEvent:(WXDependencyPropertyChangedEventHandler)del;
- (void)removeIsEnabledChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFocusDisengagedEvent:(void(^)(WXCControl*, WXCFocusDisengagedEventArgs*))del;
- (void)removeFocusDisengagedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFocusEngagedEvent:(void(^)(WXCControl*, WXCFocusEngagedEventArgs*))del;
- (void)removeFocusEngagedEvent:(EventRegistrationToken)tok;
- (BOOL)applyTemplate;
- (BOOL)focus:(WXFocusState)value;
- (void)removeFocusEngagement;
@end

#endif // __WXCControl_DEFINED__

// Windows.UI.Xaml.Controls.UserControl
#ifndef __WXCUserControl_DEFINED__
#define __WXCUserControl_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface WXCUserControl : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXUIElement* content;
+ (WXDependencyProperty*)contentProperty;
@end

#endif // __WXCUserControl_DEFINED__

// Microsoft.Advertising.WinRT.UI.blank
#ifndef __MAWUblank_DEFINED__
#define __MAWUblank_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MAWUblank : WXCUserControl <WUXMIComponentConnector, WUXMIComponentConnector2>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)connect:(int)connectionId target:(RTObject*)target;
- (RTObject<WUXMIComponentConnector>*)getBindingConnector:(int)connectionId target:(RTObject*)target;
- (void)initializeComponent;
@end

#endif // __MAWUblank_DEFINED__

// Microsoft.Advertising.WinRT.UI.InterstitialAd
#ifndef __MAWUInterstitialAd_DEFINED__
#define __MAWUInterstitialAd_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MAWUInterstitialAd : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * postalCode;
@property (retain) NSString * countryOrRegion;
@property (retain) NSString * keywords;
@property unsigned int requestTimeout;
@property (readonly) MAWUInterstitialAdState state;
- (EventRegistrationToken)addErrorOccurredEvent:(void(^)(RTObject*, MAWUAdErrorEventArgs*))del;
- (void)removeErrorOccurredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCancelledEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeCancelledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCompletedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAdReadyEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeAdReadyEvent:(EventRegistrationToken)tok;
- (void)requestAd1:(MAWUAdType)adType applicationId:(NSString *)applicationId adUnitId:(NSString *)adUnitId;
- (void)show;
- (void)close;
- (void)addAdTag:(NSString *)tagName tagValue:(NSString *)tagValue;
- (void)removeAdTag:(NSString *)tagName;
@end

#endif // __MAWUInterstitialAd_DEFINED__

// Microsoft.Advertising.WinRT.UI.VpaidEventArgs
#ifndef __MAWUVpaidEventArgs_DEFINED__
#define __MAWUVpaidEventArgs_DEFINED__

OBJCUWPMICROSOFTADVERTISINGEXPORT
@interface MAWUVpaidEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * message;
@property (readonly) NSString * eventName;
@end

#endif // __MAWUVpaidEventArgs_DEFINED__

