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

// WindowsPhoneUIInput.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSPHONEUIINPUTEXPORT
#define OBJCUWPWINDOWSPHONEUIINPUTEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsPhoneUIInput.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPUIBackPressedEventArgs, WPUICameraEventArgs, WPUIHardwareButtons;
@protocol WPUIIHardwareButtonsStatics, WPUIIHardwareButtonsStatics2, WPUIIBackPressedEventArgs, WPUIICameraEventArgs;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Phone.UI.Input.BackPressedEventArgs
#ifndef __WPUIBackPressedEventArgs_DEFINED__
#define __WPUIBackPressedEventArgs_DEFINED__

OBJCUWPWINDOWSPHONEUIINPUTEXPORT
@interface WPUIBackPressedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@end

#endif // __WPUIBackPressedEventArgs_DEFINED__

// Windows.Phone.UI.Input.CameraEventArgs
#ifndef __WPUICameraEventArgs_DEFINED__
#define __WPUICameraEventArgs_DEFINED__

OBJCUWPWINDOWSPHONEUIINPUTEXPORT
@interface WPUICameraEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WPUICameraEventArgs_DEFINED__

// Windows.Phone.UI.Input.HardwareButtons
#ifndef __WPUIHardwareButtons_DEFINED__
#define __WPUIHardwareButtons_DEFINED__

OBJCUWPWINDOWSPHONEUIINPUTEXPORT
@interface WPUIHardwareButtons : RTObject
+ (EventRegistrationToken)addBackPressedEvent:(void(^)(RTObject*, WPUIBackPressedEventArgs*))del;
+ (void)removeBackPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addCameraHalfPressedEvent:(void(^)(RTObject*, WPUICameraEventArgs*))del;
+ (void)removeCameraHalfPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addCameraPressedEvent:(void(^)(RTObject*, WPUICameraEventArgs*))del;
+ (void)removeCameraPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addCameraReleasedEvent:(void(^)(RTObject*, WPUICameraEventArgs*))del;
+ (void)removeCameraReleasedEvent:(EventRegistrationToken)tok;
@end

#endif // __WPUIHardwareButtons_DEFINED__

