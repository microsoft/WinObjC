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

// WindowsDevicesPower.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_DEVICES_POWER_EXPORT
#define OBJCUWP_WINDOWS_DEVICES_POWER_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Devices_Power.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDPBatteryReport, WDPBattery;
@protocol WDPIBattery
, WDPIBatteryReport, WDPIBatteryStatics;

#include "WindowsFoundation.h"
#include "WindowsSystemPower.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Power.BatteryReport
#ifndef __WDPBatteryReport_DEFINED__
#define __WDPBatteryReport_DEFINED__

OBJCUWP_WINDOWS_DEVICES_POWER_EXPORT
@interface WDPBatteryReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) id /* int */ chargeRateInMilliwatts;
@property (readonly) id /* int */ designCapacityInMilliwattHours;
@property (readonly) id /* int */ fullChargeCapacityInMilliwattHours;
@property (readonly) id /* int */ remainingCapacityInMilliwattHours;
@property (readonly) WSPBatteryStatus status;
@end

#endif // __WDPBatteryReport_DEFINED__

// Windows.Devices.Power.Battery
#ifndef __WDPBattery_DEFINED__
#define __WDPBattery_DEFINED__

OBJCUWP_WINDOWS_DEVICES_POWER_EXPORT
@interface WDPBattery : RTObject
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDPBattery*))success failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelector;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSString* deviceId;
+ (WDPBattery*)aggregateBattery;
- (EventRegistrationToken)addReportUpdatedEvent:(void (^)(WDPBattery*, RTObject*))del;
- (void)removeReportUpdatedEvent:(EventRegistrationToken)tok;
- (WDPBatteryReport*)getReport;
@end

#endif // __WDPBattery_DEFINED__
