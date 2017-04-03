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

// WindowsPhoneDevicesNotification.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSPHONEDEVICESNOTIFICATIONEXPORT
#define OBJCUWPWINDOWSPHONEDEVICESNOTIFICATIONEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsPhoneDevicesNotification.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPDNVibrationDevice;
@protocol WPDNIVibrationDeviceStatics, WPDNIVibrationDevice;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Phone.Devices.Notification.VibrationDevice
#ifndef __WPDNVibrationDevice_DEFINED__
#define __WPDNVibrationDevice_DEFINED__

OBJCUWPWINDOWSPHONEDEVICESNOTIFICATIONEXPORT
@interface WPDNVibrationDevice : RTObject
+ (WPDNVibrationDevice*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)vibrate:(WFTimeSpan*)duration;
- (void)cancel;
@end

#endif // __WPDNVibrationDevice_DEFINED__

