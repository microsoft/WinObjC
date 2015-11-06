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

// WindowsApplicationModelCore.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WACAppListEntry, WACCoreApplication, WACCoreApplicationView, WACCoreApplicationViewTitleBar, WACUnhandledErrorDetectedEventArgs,
    WACHostedViewClosingEventArgs, WACUnhandledError;
@protocol WACIAppListEntry
, WACIFrameworkView, WACIFrameworkViewSource, WACICoreApplication, WACICoreApplicationUseCount, WACICoreApplicationExit,
    WACICoreImmersiveApplication, WACICoreImmersiveApplication2, WACICoreImmersiveApplication3, WACICoreApplicationUnhandledError,
    WACICoreApplicationView, WACICoreApplicationView2, WACICoreApplicationView3, WACIHostedViewClosingEventArgs,
    WACICoreApplicationViewTitleBar, WACIUnhandledErrorDetectedEventArgs, WACIUnhandledError;

#include "WindowsFoundationCollections.h"
#include "WindowsApplicationModel.h"
#include "WindowsFoundation.h"
#include "WindowsUICore.h"
#include "WindowsApplicationModelActivation.h"

#import <Foundation/Foundation.h>

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

// Windows.ApplicationModel.Core.IFrameworkViewSource
#ifndef __WACIFrameworkViewSource_DEFINED__
#define __WACIFrameworkViewSource_DEFINED__

@protocol WACIFrameworkViewSource
- (RTObject<WACIFrameworkView>*)createView;
@end

#endif // __WACIFrameworkViewSource_DEFINED__

// Windows.ApplicationModel.Core.ICoreApplicationUnhandledError
#ifndef __WACICoreApplicationUnhandledError_DEFINED__
#define __WACICoreApplicationUnhandledError_DEFINED__

@protocol WACICoreApplicationUnhandledError
- (EventRegistrationToken)addUnhandledErrorDetectedEvent:(void (^)(RTObject*, WACUnhandledErrorDetectedEventArgs*))del;
- (void)removeUnhandledErrorDetectedEvent:(EventRegistrationToken)tok;
@end

#endif // __WACICoreApplicationUnhandledError_DEFINED__

// Windows.ApplicationModel.Core.AppListEntry
#ifndef __WACAppListEntry_DEFINED__
#define __WACAppListEntry_DEFINED__

WINRT_EXPORT
@interface WACAppListEntry : RTObject
@property (readonly) WAAppDisplayInfo* displayInfo;
- (void)launchAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACAppListEntry_DEFINED__

// Windows.ApplicationModel.Core.CoreApplication
#ifndef __WACCoreApplication_DEFINED__
#define __WACCoreApplication_DEFINED__

WINRT_EXPORT
@interface WACCoreApplication : RTObject
+ (WACCoreApplicationView*)createNewViewFromMainView;
+ (WACCoreApplicationView*)createNewView:(NSString*)runtimeType entryPoint:(NSString*)entryPoint;
+ (WACCoreApplicationView*)createNewViewWithViewSource:(RTObject<WACIFrameworkViewSource>*)viewSource;
+ (WACCoreApplicationView*)getCurrentView;
+ (void)run:(RTObject<WACIFrameworkViewSource>*)viewSource;
+ (void)runWithActivationFactories:(RTObject<WFIGetActivationFactory>*)activationFactoryCallback;
+ (void)incrementApplicationUseCount;
+ (void)decrementApplicationUseCount;
+ (void)exit;
+ (NSString*)id;
+ (RTObject<WFCIPropertySet>*)properties;
+ (WACCoreApplicationView*)mainView;
+ (NSArray*)views;
+ (EventRegistrationToken)addUnhandledErrorDetectedEvent:(void (^)(RTObject*, WACUnhandledErrorDetectedEventArgs*))del;
+ (void)removeUnhandledErrorDetectedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addExitingEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeExitingEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addResumingEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeResumingEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addSuspendingEvent:(void (^)(RTObject*, WASuspendingEventArgs*))del;
+ (void)removeSuspendingEvent:(EventRegistrationToken)tok;
@end

#endif // __WACCoreApplication_DEFINED__

// Windows.ApplicationModel.Core.CoreApplicationView
#ifndef __WACCoreApplicationView_DEFINED__
#define __WACCoreApplicationView_DEFINED__

WINRT_EXPORT
@interface WACCoreApplicationView : RTObject
@property (readonly) WUCCoreWindow* coreWindow;
@property (readonly) BOOL isHosted;
@property (readonly) BOOL isMain;
@property (readonly) WUCCoreDispatcher* dispatcher;
@property (readonly) BOOL isComponent;
@property (readonly) WACCoreApplicationViewTitleBar* titleBar;
- (EventRegistrationToken)addActivatedEvent:(void (^)(WACCoreApplicationView*, RTObject<WAAIActivatedEventArgs>*))del;
- (void)removeActivatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHostedViewClosingEvent:(void (^)(WACCoreApplicationView*, WACHostedViewClosingEventArgs*))del;
- (void)removeHostedViewClosingEvent:(EventRegistrationToken)tok;
@end

#endif // __WACCoreApplicationView_DEFINED__

// Windows.ApplicationModel.Core.CoreApplicationViewTitleBar
#ifndef __WACCoreApplicationViewTitleBar_DEFINED__
#define __WACCoreApplicationViewTitleBar_DEFINED__

WINRT_EXPORT
@interface WACCoreApplicationViewTitleBar : RTObject
@property BOOL extendViewIntoTitleBar;
@property (readonly) double height;
@property (readonly) BOOL isVisible;
@property (readonly) double systemOverlayLeftInset;
@property (readonly) double systemOverlayRightInset;
- (EventRegistrationToken)addIsVisibleChangedEvent:(void (^)(WACCoreApplicationViewTitleBar*, RTObject*))del;
- (void)removeIsVisibleChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLayoutMetricsChangedEvent:(void (^)(WACCoreApplicationViewTitleBar*, RTObject*))del;
- (void)removeLayoutMetricsChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WACCoreApplicationViewTitleBar_DEFINED__

// Windows.ApplicationModel.Core.UnhandledErrorDetectedEventArgs
#ifndef __WACUnhandledErrorDetectedEventArgs_DEFINED__
#define __WACUnhandledErrorDetectedEventArgs_DEFINED__

WINRT_EXPORT
@interface WACUnhandledErrorDetectedEventArgs : RTObject
@property (readonly) WACUnhandledError* unhandledError;
@end

#endif // __WACUnhandledErrorDetectedEventArgs_DEFINED__

// Windows.ApplicationModel.Core.HostedViewClosingEventArgs
#ifndef __WACHostedViewClosingEventArgs_DEFINED__
#define __WACHostedViewClosingEventArgs_DEFINED__

WINRT_EXPORT
@interface WACHostedViewClosingEventArgs : RTObject
- (WFDeferral*)getDeferral;
@end

#endif // __WACHostedViewClosingEventArgs_DEFINED__

// Windows.ApplicationModel.Core.UnhandledError
#ifndef __WACUnhandledError_DEFINED__
#define __WACUnhandledError_DEFINED__

WINRT_EXPORT
@interface WACUnhandledError : RTObject
@property (readonly) BOOL handled;
- (void)propagate;
@end

#endif // __WACUnhandledError_DEFINED__
