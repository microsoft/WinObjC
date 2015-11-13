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

// WindowsUIXamlNavigation.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUXNNavigationEventArgs, WUXNNavigatingCancelEventArgs, WUXNNavigationFailedEventArgs, WUXNPageStackEntry;
@protocol WUXNINavigatingCancelEventArgs
, WUXNINavigatingCancelEventArgs2, WUXNINavigationEventArgs, WUXNINavigationEventArgs2, WUXNINavigationFailedEventArgs, WUXNIPageStackEntry,
    WUXNIPageStackEntryStatics, WUXNIPageStackEntryFactory;

// Windows.UI.Xaml.Navigation.NavigationCacheMode
enum _WUXNNavigationCacheMode {
    WUXNNavigationCacheModeDisabled = 0,
    WUXNNavigationCacheModeRequired = 1,
    WUXNNavigationCacheModeEnabled = 2,
};
typedef unsigned WUXNNavigationCacheMode;

// Windows.UI.Xaml.Navigation.NavigationMode
enum _WUXNNavigationMode {
    WUXNNavigationModeNew = 0,
    WUXNNavigationModeBack = 1,
    WUXNNavigationModeForward = 2,
    WUXNNavigationModeRefresh = 3,
};
typedef unsigned WUXNNavigationMode;

#include "WindowsUIXamlInterop.h"
#include "WindowsUIXamlMediaAnimation.h"
#include "WindowsFoundation.h"
#include "WindowsUIXaml.h"
#include "WindowsUICore.h"

// Windows.UI.Xaml.Navigation.LoadCompletedEventHandler
#ifndef __WUXNLoadCompletedEventHandler__DEFINED
#define __WUXNLoadCompletedEventHandler__DEFINED
typedef void (^WUXNLoadCompletedEventHandler)(RTObject* sender, WUXNNavigationEventArgs* e);
#endif // __WUXNLoadCompletedEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.NavigatedEventHandler
#ifndef __WUXNNavigatedEventHandler__DEFINED
#define __WUXNNavigatedEventHandler__DEFINED
typedef void (^WUXNNavigatedEventHandler)(RTObject* sender, WUXNNavigationEventArgs* e);
#endif // __WUXNNavigatedEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.NavigatingCancelEventHandler
#ifndef __WUXNNavigatingCancelEventHandler__DEFINED
#define __WUXNNavigatingCancelEventHandler__DEFINED
typedef void (^WUXNNavigatingCancelEventHandler)(RTObject* sender, WUXNNavigatingCancelEventArgs* e);
#endif // __WUXNNavigatingCancelEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.NavigationFailedEventHandler
#ifndef __WUXNNavigationFailedEventHandler__DEFINED
#define __WUXNNavigationFailedEventHandler__DEFINED
typedef void (^WUXNNavigationFailedEventHandler)(RTObject* sender, WUXNNavigationFailedEventArgs* e);
#endif // __WUXNNavigationFailedEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.NavigationStoppedEventHandler
#ifndef __WUXNNavigationStoppedEventHandler__DEFINED
#define __WUXNNavigationStoppedEventHandler__DEFINED
typedef void (^WUXNNavigationStoppedEventHandler)(RTObject* sender, WUXNNavigationEventArgs* e);
#endif // __WUXNNavigationStoppedEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.NavigationEventArgs
#ifndef __WUXNNavigationEventArgs_DEFINED__
#define __WUXNNavigationEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXNNavigationEventArgs : RTObject
@property (readonly) WUXMANavigationTransitionInfo* navigationTransitionInfo;
@property (copy) WFUri* uri;
@property (readonly) RTObject* content;
@property (readonly) WUXNNavigationMode navigationMode;
@property (readonly) RTObject* parameter;
@property (readonly) WUXITypeName* sourcePageType;
@end

#endif // __WUXNNavigationEventArgs_DEFINED__

// Windows.UI.Xaml.Navigation.NavigatingCancelEventArgs
#ifndef __WUXNNavigatingCancelEventArgs_DEFINED__
#define __WUXNNavigatingCancelEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXNNavigatingCancelEventArgs : RTObject
@property (readonly) WUXMANavigationTransitionInfo* navigationTransitionInfo;
@property (readonly) RTObject* parameter;
@property BOOL cancel;
@property (readonly) WUXNNavigationMode navigationMode;
@property (readonly) WUXITypeName* sourcePageType;
@end

#endif // __WUXNNavigatingCancelEventArgs_DEFINED__

// Windows.UI.Xaml.Navigation.NavigationFailedEventArgs
#ifndef __WUXNNavigationFailedEventArgs_DEFINED__
#define __WUXNNavigationFailedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXNNavigationFailedEventArgs : RTObject
@property BOOL handled;
@property (readonly) HRESULT exception;
@property (readonly) WUXITypeName* sourcePageType;
@end

#endif // __WUXNNavigationFailedEventArgs_DEFINED__

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

// Windows.UI.Xaml.Navigation.PageStackEntry
#ifndef __WUXNPageStackEntry_DEFINED__
#define __WUXNPageStackEntry_DEFINED__

WINRT_EXPORT
@interface WUXNPageStackEntry : WXDependencyObject
+ (WUXNPageStackEntry*)createInstance:(WUXITypeName*)sourcePageType
                            parameter:(RTObject*)parameter
             navigationTransitionInfo:(WUXMANavigationTransitionInfo*)navigationTransitionInfo ACTIVATOR;
@property (readonly) WUXMANavigationTransitionInfo* navigationTransitionInfo;
@property (readonly) RTObject* parameter;
@property (readonly) WUXITypeName* sourcePageType;
+ (WXDependencyProperty*)sourcePageTypeProperty;
@end

#endif // __WUXNPageStackEntry_DEFINED__
