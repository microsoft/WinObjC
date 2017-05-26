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

// WindowsGamingUI.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGAMINGUIEXPORT
#define OBJCUWPWINDOWSGAMINGUIEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGamingUI.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGUGameBar;
@protocol WGUIGameBarStatics;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Gaming.UI.GameBar
#ifndef __WGUGameBar_DEFINED__
#define __WGUGameBar_DEFINED__

OBJCUWPWINDOWSGAMINGUIEXPORT
@interface WGUGameBar : RTObject
+ (BOOL)isInputRedirected;
+ (BOOL)visible;
+ (EventRegistrationToken)addIsInputRedirectedChangedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeIsInputRedirectedChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addVisibilityChangedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeVisibilityChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WGUGameBar_DEFINED__
