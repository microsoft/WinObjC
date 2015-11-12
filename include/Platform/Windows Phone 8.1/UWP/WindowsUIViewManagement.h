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

// WindowsUIViewManagement.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUVApplicationView, WUVApplicationViewConsolidatedEventArgs, WUVApplicationViewSwitcher, WUVProjectionManager,
    WUVInputPaneVisibilityEventArgs, WUVInputPane, WUVAccessibilitySettings, WUVUISettings;
@protocol WUVIApplicationViewSwitcherStatics
, WUVIApplicationViewInteropStatics, WUVIApplicationViewStatics, WUVIApplicationViewStatics2, WUVIApplicationView,
    WUVIApplicationViewConsolidatedEventArgs, WUVIProjectionManagerStatics, WUVIInputPaneVisibilityEventArgs, WUVIInputPane,
    WUVIInputPaneStatics, WUVIAccessibilitySettings, WUVIUISettings;

// Windows.UI.ViewManagement.ApplicationViewState
enum _WUVApplicationViewState {
    WUVApplicationViewStateFullScreenLandscape = 0,
    WUVApplicationViewStateFilled = 1,
    WUVApplicationViewStateSnapped = 2,
    WUVApplicationViewStateFullScreenPortrait = 3,
};
typedef unsigned WUVApplicationViewState;

// Windows.UI.ViewManagement.ApplicationViewOrientation
enum _WUVApplicationViewOrientation {
    WUVApplicationViewOrientationLandscape = 0,
    WUVApplicationViewOrientationPortrait = 1,
};
typedef unsigned WUVApplicationViewOrientation;

// Windows.UI.ViewManagement.ApplicationViewSwitchingOptions
enum _WUVApplicationViewSwitchingOptions {
    WUVApplicationViewSwitchingOptionsDefault = 0,
    WUVApplicationViewSwitchingOptionsSkipAnimation = 1,
    WUVApplicationViewSwitchingOptionsConsolidateViews = 2,
};
typedef unsigned WUVApplicationViewSwitchingOptions;

// Windows.UI.ViewManagement.ViewSizePreference
enum _WUVViewSizePreference {
    WUVViewSizePreferenceDefault = 0,
    WUVViewSizePreferenceUseLess = 1,
    WUVViewSizePreferenceUseHalf = 2,
    WUVViewSizePreferenceUseMore = 3,
    WUVViewSizePreferenceUseMinimum = 4,
    WUVViewSizePreferenceUseNone = 5,
};
typedef unsigned WUVViewSizePreference;

// Windows.UI.ViewManagement.HandPreference
enum _WUVHandPreference {
    WUVHandPreferenceLeftHanded = 0,
    WUVHandPreferenceRightHanded = 1,
};
typedef unsigned WUVHandPreference;

// Windows.UI.ViewManagement.UIElementType
enum _WUVUIElementType {
    WUVUIElementTypeActiveCaption = 0,
    WUVUIElementTypeBackground = 1,
    WUVUIElementTypeButtonFace = 2,
    WUVUIElementTypeButtonText = 3,
    WUVUIElementTypeCaptionText = 4,
    WUVUIElementTypeGrayText = 5,
    WUVUIElementTypeHighlight = 6,
    WUVUIElementTypeHighlightText = 7,
    WUVUIElementTypeHotlight = 8,
    WUVUIElementTypeInactiveCaption = 9,
    WUVUIElementTypeInactiveCaptionText = 10,
    WUVUIElementTypeWindow = 11,
    WUVUIElementTypeWindowText = 12,
};
typedef unsigned WUVUIElementType;

#include "WindowsUI.h"
#include "WindowsFoundation.h"
#include "WindowsUICore.h"

// Windows.UI.ViewManagement.ApplicationView
#ifndef __WUVApplicationView_DEFINED__
#define __WUVApplicationView_DEFINED__

WINRT_EXPORT
@interface WUVApplicationView : RTObject
+ (int)getApplicationViewIdForWindow:(RTObject<WUCICoreWindow>*)window;
+ (BOOL)tryUnsnap;
+ (WUVApplicationView*)getForCurrentView;
@property (copy) NSString* title;
@property BOOL isScreenCaptureEnabled;
@property (readonly) BOOL adjacentToLeftDisplayEdge;
@property (readonly) BOOL adjacentToRightDisplayEdge;
@property (readonly) int id;
@property (readonly) BOOL isFullScreen;
@property (readonly) BOOL isOnLockScreen;
@property (readonly) WUVApplicationViewOrientation orientation;
+ (BOOL)terminateAppOnFinalViewClose;
+ (void)setTerminateAppOnFinalViewClose:(BOOL)value;
+ (WUVApplicationViewState)value;
- (EventRegistrationToken)addConsolidatedEvent:(void (^)(WUVApplicationView*, WUVApplicationViewConsolidatedEventArgs*))del;
- (void)removeConsolidatedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUVApplicationView_DEFINED__

// Windows.UI.ViewManagement.ApplicationViewConsolidatedEventArgs
#ifndef __WUVApplicationViewConsolidatedEventArgs_DEFINED__
#define __WUVApplicationViewConsolidatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUVApplicationViewConsolidatedEventArgs : RTObject
@property (readonly) BOOL isUserInitiated;
@end

#endif // __WUVApplicationViewConsolidatedEventArgs_DEFINED__

// Windows.UI.ViewManagement.ApplicationViewSwitcher
#ifndef __WUVApplicationViewSwitcher_DEFINED__
#define __WUVApplicationViewSwitcher_DEFINED__

WINRT_EXPORT
@interface WUVApplicationViewSwitcher : RTObject
+ (void)disableShowingMainViewOnActivation;
+ (void)tryShowAsStandaloneAsync:(int)viewId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)tryShowAsStandaloneWithSizePreferenceAsync:(int)viewId
                                    sizePreference:(WUVViewSizePreference)sizePreference
                                           success:(void (^)(BOOL))success
                                           failure:(void (^)(NSError*))failure;
+ (void)tryShowAsStandaloneWithAnchorViewAndSizePreferenceAsync:(int)viewId
                                                 sizePreference:(WUVViewSizePreference)sizePreference
                                                   anchorViewId:(int)anchorViewId
                                           anchorSizePreference:(WUVViewSizePreference)anchorSizePreference
                                                        success:(void (^)(BOOL))success
                                                        failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)switchAsync:(int)viewId;
+ (RTObject<WFIAsyncAction>*)switchFromViewAsync:(int)toViewId fromViewId:(int)fromViewId;
+ (RTObject<WFIAsyncAction>*)switchFromViewWithOptionsAsync:(int)toViewId
                                                 fromViewId:(int)fromViewId
                                                    options:(WUVApplicationViewSwitchingOptions)options;
+ (void)prepareForCustomAnimatedSwitchAsync:(int)toViewId
                                 fromViewId:(int)fromViewId
                                    options:(WUVApplicationViewSwitchingOptions)options
                                    success:(void (^)(BOOL))success
                                    failure:(void (^)(NSError*))failure;
@end

#endif // __WUVApplicationViewSwitcher_DEFINED__

// Windows.UI.ViewManagement.ProjectionManager
#ifndef __WUVProjectionManager_DEFINED__
#define __WUVProjectionManager_DEFINED__

WINRT_EXPORT
@interface WUVProjectionManager : RTObject
+ (RTObject<WFIAsyncAction>*)startProjectingAsync:(int)projectionViewId anchorViewId:(int)anchorViewId;
+ (RTObject<WFIAsyncAction>*)swapDisplaysForViewsAsync:(int)projectionViewId anchorViewId:(int)anchorViewId;
+ (RTObject<WFIAsyncAction>*)stopProjectingAsync:(int)projectionViewId anchorViewId:(int)anchorViewId;
+ (BOOL)projectionDisplayAvailable;
+ (EventRegistrationToken)addProjectionDisplayAvailableChangedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeProjectionDisplayAvailableChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUVProjectionManager_DEFINED__

// Windows.UI.ViewManagement.InputPaneVisibilityEventArgs
#ifndef __WUVInputPaneVisibilityEventArgs_DEFINED__
#define __WUVInputPaneVisibilityEventArgs_DEFINED__

WINRT_EXPORT
@interface WUVInputPaneVisibilityEventArgs : RTObject
@property BOOL ensuredFocusedElementInView;
@property (readonly) WFRect* occludedRect;
@end

#endif // __WUVInputPaneVisibilityEventArgs_DEFINED__

// Windows.UI.ViewManagement.InputPane
#ifndef __WUVInputPane_DEFINED__
#define __WUVInputPane_DEFINED__

WINRT_EXPORT
@interface WUVInputPane : RTObject
+ (WUVInputPane*)getForCurrentView;
@property (readonly) WFRect* occludedRect;
- (EventRegistrationToken)addHidingEvent:(void (^)(WUVInputPane*, WUVInputPaneVisibilityEventArgs*))del;
- (void)removeHidingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addShowingEvent:(void (^)(WUVInputPane*, WUVInputPaneVisibilityEventArgs*))del;
- (void)removeShowingEvent:(EventRegistrationToken)tok;
@end

#endif // __WUVInputPane_DEFINED__

// Windows.UI.ViewManagement.AccessibilitySettings
#ifndef __WUVAccessibilitySettings_DEFINED__
#define __WUVAccessibilitySettings_DEFINED__

WINRT_EXPORT
@interface WUVAccessibilitySettings : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) BOOL highContrast;
@property (readonly) NSString* highContrastScheme;
- (EventRegistrationToken)addHighContrastChangedEvent:(void (^)(WUVAccessibilitySettings*, RTObject*))del;
- (void)removeHighContrastChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUVAccessibilitySettings_DEFINED__

// Windows.UI.ViewManagement.UISettings
#ifndef __WUVUISettings_DEFINED__
#define __WUVUISettings_DEFINED__

WINRT_EXPORT
@interface WUVUISettings : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) BOOL animationsEnabled;
@property (readonly) unsigned caretBlinkRate;
@property (readonly) BOOL caretBrowsingEnabled;
@property (readonly) unsigned caretWidth;
@property (readonly) WFSize* cursorSize;
@property (readonly) unsigned doubleClickTime;
@property (readonly) WUVHandPreference handPreference;
@property (readonly) unsigned messageDuration;
@property (readonly) unsigned mouseHoverTime;
@property (readonly) WFSize* scrollBarArrowSize;
@property (readonly) WFSize* scrollBarSize;
@property (readonly) WFSize* scrollBarThumbBoxSize;
- (WUColor*)uIElementColor:(WUVUIElementType)desiredElement;
@end

#endif // __WUVUISettings_DEFINED__
