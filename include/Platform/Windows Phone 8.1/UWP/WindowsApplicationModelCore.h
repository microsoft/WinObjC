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
@class WACCoreApplication, WACCoreApplicationView, WACUnhandledErrorDetectedEventArgs, WACUnhandledError;
@protocol WACIFrameworkView
, WACIFrameworkViewSource, WACICoreApplication, WACICoreApplicationUseCount, WACICoreApplicationExit, WACICoreImmersiveApplication,
    WACICoreImmersiveApplication2, WACICoreApplicationUnhandledError, WACICoreApplicationView, WACICoreApplicationView2,
    WACIUnhandledErrorDetectedEventArgs, WACIUnhandledError;

#include "WindowsFoundationCollections.h"
#include "WindowsUICore.h"
#include "WindowsFoundation.h"
#include "WindowsApplicationModel.h"
#include "WindowsApplicationModelActivation.h"

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

// Windows.ApplicationModel.Core.CoreApplication
#ifndef __WACCoreApplication_DEFINED__
#define __WACCoreApplication_DEFINED__

WINRT_EXPORT
@interface WACCoreApplication : RTObject
+ (WACCoreApplicationView*)createNewView:(NSString*)runtimeType entryPoint:(NSString*)entryPoint;
+ (WACCoreApplicationView*)getCurrentView;
+ (void)run:(RTObject<WACIFrameworkViewSource>*)viewSource;
+ (void)runWithActivationFactories:(RTObject<WFIGetActivationFactory>*)activationFactoryCallback;
+ (WACCoreApplicationView*)createNewViewFromMainView;
+ (void)exit;
+ (void)incrementApplicationUseCount;
+ (void)decrementApplicationUseCount;
+ (WACCoreApplicationView*)mainView;
+ (id<NSFastEnumeration> /*WACCoreApplicationView*/)views;
+ (NSString*)id;
+ (RTObject<WFCIPropertySet>*)properties;
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
- (EventRegistrationToken)addActivatedEvent:(void (^)(WACCoreApplicationView*, RTObject<WAAIActivatedEventArgs>*))del;
- (void)removeActivatedEvent:(EventRegistrationToken)tok;
@end

#endif // __WACCoreApplicationView_DEFINED__

// Windows.ApplicationModel.Core.UnhandledErrorDetectedEventArgs
#ifndef __WACUnhandledErrorDetectedEventArgs_DEFINED__
#define __WACUnhandledErrorDetectedEventArgs_DEFINED__

WINRT_EXPORT
@interface WACUnhandledErrorDetectedEventArgs : RTObject
@property (readonly) WACUnhandledError* unhandledError;
@end

#endif // __WACUnhandledErrorDetectedEventArgs_DEFINED__

// Windows.ApplicationModel.Core.UnhandledError
#ifndef __WACUnhandledError_DEFINED__
#define __WACUnhandledError_DEFINED__

WINRT_EXPORT
@interface WACUnhandledError : RTObject
@property (readonly) BOOL handled;
- (void)propagate;
@end

#endif // __WACUnhandledError_DEFINED__
