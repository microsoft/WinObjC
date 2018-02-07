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

// WindowsApplicationModelCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WACAppListEntry, WACCoreApplication, WACCoreApplicationView, WACCoreApplicationViewTitleBar, WACUnhandledErrorDetectedEventArgs, WACHostedViewClosingEventArgs, WACUnhandledError;
@protocol WACIAppListEntry, WACIAppListEntry2, WACIFrameworkView, WACIFrameworkViewSource, WACICoreApplication, WACICoreApplicationUseCount, WACICoreApplicationExit, WACICoreApplication2, WACICoreApplication3, WACICoreImmersiveApplication, WACICoreImmersiveApplication2, WACICoreImmersiveApplication3, WACICoreApplicationUnhandledError, WACICoreApplicationView, WACICoreApplicationView2, WACICoreApplicationView3, WACICoreApplicationView5, WACICoreApplicationView6, WACIHostedViewClosingEventArgs, WACICoreApplicationViewTitleBar, WACIUnhandledErrorDetectedEventArgs, WACIUnhandledError;

// Windows.ApplicationModel.Core.AppRestartFailureReason
enum _WACAppRestartFailureReason {
    WACAppRestartFailureReasonRestartPending = 0,
    WACAppRestartFailureReasonNotInForeground = 1,
    WACAppRestartFailureReasonInvalidUser = 2,
    WACAppRestartFailureReasonOther = 3,
};
typedef unsigned WACAppRestartFailureReason;

#include "WindowsFoundationCollections.h"
#include "WindowsSystem.h"
#include "WindowsApplicationModel.h"
#include "WindowsUICore.h"
#include "WindowsFoundation.h"
#include "WindowsApplicationModelActivation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Core.IFrameworkView
#ifndef __WACIFrameworkView_DEFINED__
#define __WACIFrameworkView_DEFINED__

@protocol WACIFrameworkView
- (void)Initialize:(WACCoreApplicationView*)applicationView;
- (void)setWindow:(WUCCoreWindow*)window;
- (void)Load:(NSString *)entryPoint;
- (void)run;
- (void)uninitialize;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACIFrameworkView : RTObject <WACIFrameworkView>
@end

#endif // __WACIFrameworkView_DEFINED__

// Windows.ApplicationModel.Core.IFrameworkViewSource
#ifndef __WACIFrameworkViewSource_DEFINED__
#define __WACIFrameworkViewSource_DEFINED__

@protocol WACIFrameworkViewSource
- (RTObject<WACIFrameworkView>*)createView;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACIFrameworkViewSource : RTObject <WACIFrameworkViewSource>
@end

#endif // __WACIFrameworkViewSource_DEFINED__

// Windows.ApplicationModel.Core.ICoreApplicationUnhandledError
#ifndef __WACICoreApplicationUnhandledError_DEFINED__
#define __WACICoreApplicationUnhandledError_DEFINED__

@protocol WACICoreApplicationUnhandledError
- (EventRegistrationToken)addUnhandledErrorDetectedEvent:(void(^)(RTObject*, WACUnhandledErrorDetectedEventArgs*))del;
- (void)removeUnhandledErrorDetectedEvent:(EventRegistrationToken)tok;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACICoreApplicationUnhandledError : RTObject <WACICoreApplicationUnhandledError>
@end

#endif // __WACICoreApplicationUnhandledError_DEFINED__

// Windows.ApplicationModel.Core.AppListEntry
#ifndef __WACAppListEntry_DEFINED__
#define __WACAppListEntry_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACAppListEntry : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAAppDisplayInfo* displayInfo;
@property (readonly) NSString * appUserModelId;
- (void)launchAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACAppListEntry_DEFINED__

// Windows.ApplicationModel.Core.CoreApplication
#ifndef __WACCoreApplication_DEFINED__
#define __WACCoreApplication_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACCoreApplication : RTObject
+ (void)exit;
+ (WACCoreApplicationView*)createNewView:(NSString *)runtimeType entryPoint:(NSString *)entryPoint;
+ (void)enablePrelaunch:(BOOL)value;
+ (void)requestRestartAsync:(NSString *)launchArguments success:(void (^)(WACAppRestartFailureReason))success failure:(void (^)(NSError*))failure;
+ (void)requestRestartForUserAsync:(WSUser*)user launchArguments:(NSString *)launchArguments success:(void (^)(WACAppRestartFailureReason))success failure:(void (^)(NSError*))failure;
+ (WACCoreApplicationView*)getCurrentView;
+ (void)run:(RTObject<WACIFrameworkViewSource>*)viewSource;
+ (void)runWithActivationFactories:(RTObject<WFIGetActivationFactory>*)activationFactoryCallback;
+ (void)incrementApplicationUseCount;
+ (void)decrementApplicationUseCount;
+ (WACCoreApplicationView*)createNewViewFromMainView;
+ (WACCoreApplicationView*)createNewViewWithViewSource:(RTObject<WACIFrameworkViewSource>*)viewSource;
+ (NSString *)id;
+ (RTObject<WFCIPropertySet>*)properties;
+ (WACCoreApplicationView*)mainView;
+ (NSArray* /* WACCoreApplicationView* */)views;
+ (EventRegistrationToken)addUnhandledErrorDetectedEvent:(void(^)(RTObject*, WACUnhandledErrorDetectedEventArgs*))del;
+ (void)removeUnhandledErrorDetectedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addExitingEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeExitingEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addBackgroundActivatedEvent:(void(^)(RTObject*, WAABackgroundActivatedEventArgs*))del;
+ (void)removeBackgroundActivatedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addEnteredBackgroundEvent:(void(^)(RTObject*, WAEnteredBackgroundEventArgs*))del;
+ (void)removeEnteredBackgroundEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addLeavingBackgroundEvent:(void(^)(RTObject*, WALeavingBackgroundEventArgs*))del;
+ (void)removeLeavingBackgroundEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addResumingEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeResumingEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addSuspendingEvent:(void(^)(RTObject*, WASuspendingEventArgs*))del;
+ (void)removeSuspendingEvent:(EventRegistrationToken)tok;
@end

#endif // __WACCoreApplication_DEFINED__

// Windows.ApplicationModel.Core.CoreApplicationView
#ifndef __WACCoreApplicationView_DEFINED__
#define __WACCoreApplicationView_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACCoreApplicationView : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUCCoreWindow* coreWindow;
@property (readonly) BOOL isHosted;
@property (readonly) BOOL isMain;
@property (readonly) WUCCoreDispatcher* dispatcher;
@property (readonly) BOOL isComponent;
@property (readonly) WACCoreApplicationViewTitleBar* titleBar;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@property (readonly) WSDispatcherQueue* dispatcherQueue;
- (EventRegistrationToken)addActivatedEvent:(void(^)(WACCoreApplicationView*, RTObject<WAAIActivatedEventArgs>*))del;
- (void)removeActivatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHostedViewClosingEvent:(void(^)(WACCoreApplicationView*, WACHostedViewClosingEventArgs*))del;
- (void)removeHostedViewClosingEvent:(EventRegistrationToken)tok;
@end

#endif // __WACCoreApplicationView_DEFINED__

// Windows.ApplicationModel.Core.CoreApplicationViewTitleBar
#ifndef __WACCoreApplicationViewTitleBar_DEFINED__
#define __WACCoreApplicationViewTitleBar_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACCoreApplicationViewTitleBar : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL extendViewIntoTitleBar;
@property (readonly) double height;
@property (readonly) BOOL isVisible;
@property (readonly) double systemOverlayLeftInset;
@property (readonly) double systemOverlayRightInset;
- (EventRegistrationToken)addIsVisibleChangedEvent:(void(^)(WACCoreApplicationViewTitleBar*, RTObject*))del;
- (void)removeIsVisibleChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLayoutMetricsChangedEvent:(void(^)(WACCoreApplicationViewTitleBar*, RTObject*))del;
- (void)removeLayoutMetricsChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WACCoreApplicationViewTitleBar_DEFINED__

// Windows.ApplicationModel.Core.UnhandledErrorDetectedEventArgs
#ifndef __WACUnhandledErrorDetectedEventArgs_DEFINED__
#define __WACUnhandledErrorDetectedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACUnhandledErrorDetectedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WACUnhandledError* unhandledError;
@end

#endif // __WACUnhandledErrorDetectedEventArgs_DEFINED__

// Windows.ApplicationModel.Core.HostedViewClosingEventArgs
#ifndef __WACHostedViewClosingEventArgs_DEFINED__
#define __WACHostedViewClosingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACHostedViewClosingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WFDeferral*)getDeferral;
@end

#endif // __WACHostedViewClosingEventArgs_DEFINED__

// Windows.ApplicationModel.Core.UnhandledError
#ifndef __WACUnhandledError_DEFINED__
#define __WACUnhandledError_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACUnhandledError : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL handled;
- (void)propagate;
@end

#endif // __WACUnhandledError_DEFINED__

