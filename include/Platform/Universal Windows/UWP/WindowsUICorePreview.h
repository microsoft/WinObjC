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

// WindowsUICorePreview.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUICOREPREVIEWEXPORT
#define OBJCUWPWINDOWSUICOREPREVIEWEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUICorePreview.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUCPSystemNavigationCloseRequestedPreviewEventArgs, WUCPSystemNavigationManagerPreview;
@protocol WUCPISystemNavigationManagerPreview, WUCPISystemNavigationManagerPreviewStatics, WUCPISystemNavigationCloseRequestedPreviewEventArgs;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.UI.Core.Preview.SystemNavigationCloseRequestedPreviewEventArgs
#ifndef __WUCPSystemNavigationCloseRequestedPreviewEventArgs_DEFINED__
#define __WUCPSystemNavigationCloseRequestedPreviewEventArgs_DEFINED__

OBJCUWPWINDOWSUICOREPREVIEWEXPORT
@interface WUCPSystemNavigationCloseRequestedPreviewEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
- (WFDeferral*)getDeferral;
@end

#endif // __WUCPSystemNavigationCloseRequestedPreviewEventArgs_DEFINED__

// Windows.UI.Core.Preview.SystemNavigationManagerPreview
#ifndef __WUCPSystemNavigationManagerPreview_DEFINED__
#define __WUCPSystemNavigationManagerPreview_DEFINED__

OBJCUWPWINDOWSUICOREPREVIEWEXPORT
@interface WUCPSystemNavigationManagerPreview : RTObject
+ (WUCPSystemNavigationManagerPreview*)getForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addCloseRequestedEvent:(void(^)(RTObject*, WUCPSystemNavigationCloseRequestedPreviewEventArgs*))del;
- (void)removeCloseRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUCPSystemNavigationManagerPreview_DEFINED__

