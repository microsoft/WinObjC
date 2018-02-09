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

// WindowsUIViewManagementCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIVIEWMANAGEMENTCOREEXPORT
#define OBJCUWPWINDOWSUIVIEWMANAGEMENTCOREEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIViewManagementCore.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUVCCoreInputView, WUVCCoreInputViewOcclusionsChangedEventArgs, WUVCCoreInputViewOcclusion;
@protocol WUVCICoreInputViewOcclusion, WUVCICoreInputView, WUVCICoreInputViewStatics, WUVCICoreInputViewOcclusionsChangedEventArgs;

// Windows.UI.ViewManagement.Core.CoreInputViewOcclusionKind
enum _WUVCCoreInputViewOcclusionKind {
    WUVCCoreInputViewOcclusionKindDocked = 0,
    WUVCCoreInputViewOcclusionKindFloating = 1,
    WUVCCoreInputViewOcclusionKindOverlay = 2,
};
typedef unsigned WUVCCoreInputViewOcclusionKind;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.UI.ViewManagement.Core.CoreInputView
#ifndef __WUVCCoreInputView_DEFINED__
#define __WUVCCoreInputView_DEFINED__

OBJCUWPWINDOWSUIVIEWMANAGEMENTCOREEXPORT
@interface WUVCCoreInputView : RTObject
+ (WUVCCoreInputView*)getForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addOcclusionsChangedEvent:(void(^)(WUVCCoreInputView*, WUVCCoreInputViewOcclusionsChangedEventArgs*))del;
- (void)removeOcclusionsChangedEvent:(EventRegistrationToken)tok;
- (NSArray* /* WUVCCoreInputViewOcclusion* */)getCoreInputViewOcclusions;
- (BOOL)tryShowPrimaryView;
- (BOOL)tryHidePrimaryView;
@end

#endif // __WUVCCoreInputView_DEFINED__

// Windows.UI.ViewManagement.Core.CoreInputViewOcclusionsChangedEventArgs
#ifndef __WUVCCoreInputViewOcclusionsChangedEventArgs_DEFINED__
#define __WUVCCoreInputViewOcclusionsChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIVIEWMANAGEMENTCOREEXPORT
@interface WUVCCoreInputViewOcclusionsChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) NSArray* /* WUVCCoreInputViewOcclusion* */ occlusions;
@end

#endif // __WUVCCoreInputViewOcclusionsChangedEventArgs_DEFINED__

// Windows.UI.ViewManagement.Core.CoreInputViewOcclusion
#ifndef __WUVCCoreInputViewOcclusion_DEFINED__
#define __WUVCCoreInputViewOcclusion_DEFINED__

OBJCUWPWINDOWSUIVIEWMANAGEMENTCOREEXPORT
@interface WUVCCoreInputViewOcclusion : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFRect* occludingRect;
@property (readonly) WUVCCoreInputViewOcclusionKind occlusionKind;
@end

#endif // __WUVCCoreInputViewOcclusion_DEFINED__

