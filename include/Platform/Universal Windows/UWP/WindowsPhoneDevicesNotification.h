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

#ifndef OBJCUWP_WINDOWS_PHONE_DEVICES_NOTIFICATION_EXPORT
#define OBJCUWP_WINDOWS_PHONE_DEVICES_NOTIFICATION_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Phone_Devices_Notification.lib")
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

OBJCUWP_WINDOWS_PHONE_DEVICES_NOTIFICATION_EXPORT
@interface WPDNVibrationDevice : RTObject
+ (WPDNVibrationDevice*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)vibrate:(WFTimeSpan*)duration;
- (void)cancel;
@end

#endif // __WPDNVibrationDevice_DEFINED__

