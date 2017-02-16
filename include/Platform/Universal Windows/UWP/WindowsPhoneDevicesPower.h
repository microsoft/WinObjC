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

// WindowsPhoneDevicesPower.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_PHONE_DEVICES_POWER_EXPORT
#define OBJCUWP_WINDOWS_PHONE_DEVICES_POWER_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Phone_Devices_Power.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPDPBattery;
@protocol WPDPIBatteryStatics, WPDPIBattery;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Phone.Devices.Power.Battery
#ifndef __WPDPBattery_DEFINED__
#define __WPDPBattery_DEFINED__

OBJCUWP_WINDOWS_PHONE_DEVICES_POWER_EXPORT
@interface WPDPBattery : RTObject
+ (WPDPBattery*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int remainingChargePercent;
@property (readonly) WFTimeSpan* remainingDischargeTime;
- (EventRegistrationToken)addRemainingChargePercentChangedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeRemainingChargePercentChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WPDPBattery_DEFINED__

