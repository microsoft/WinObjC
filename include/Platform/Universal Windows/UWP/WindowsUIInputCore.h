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

// WindowsUIInputCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIINPUTCOREEXPORT
#define OBJCUWPWINDOWSUIINPUTCOREEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIInputCore.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUICRadialControllerIndependentInputSource;
@protocol WUICIRadialControllerIndependentInputSourceStatics, WUICIRadialControllerIndependentInputSource;

#include "WindowsUICore.h"
#include "WindowsApplicationModelCore.h"
#include "WindowsUIInput.h"

#import <Foundation/Foundation.h>

// Windows.UI.Input.Core.RadialControllerIndependentInputSource
#ifndef __WUICRadialControllerIndependentInputSource_DEFINED__
#define __WUICRadialControllerIndependentInputSource_DEFINED__

OBJCUWPWINDOWSUIINPUTCOREEXPORT
@interface WUICRadialControllerIndependentInputSource : RTObject
+ (WUICRadialControllerIndependentInputSource*)createForView:(WACCoreApplicationView*)view;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIRadialController* controller;
@property (readonly) WUCCoreDispatcher* dispatcher;
@end

#endif // __WUICRadialControllerIndependentInputSource_DEFINED__

