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

#include "interopBase.h"
@class WDPBatteryReport, WDPBattery;
@protocol WDPIBattery
, WDPIBatteryReport, WDPIBatteryStatics;

#include "WindowsFoundation.h"
#include "WindowsSystemPower.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Power.BatteryReport
#ifndef __WDPBatteryReport_DEFINED__
#define __WDPBatteryReport_DEFINED__

WINRT_EXPORT
@interface WDPBatteryReport : RTObject
@property (readonly) id chargeRateInMilliwatts;
@property (readonly) id designCapacityInMilliwattHours;
@property (readonly) id fullChargeCapacityInMilliwattHours;
@property (readonly) id remainingCapacityInMilliwattHours;
@property (readonly) WSPBatteryStatus status;
@end

#endif // __WDPBatteryReport_DEFINED__

// Windows.Devices.Power.Battery
#ifndef __WDPBattery_DEFINED__
#define __WDPBattery_DEFINED__

WINRT_EXPORT
@interface WDPBattery : RTObject
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDPBattery*))success failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelector;
@property (readonly) NSString* deviceId;
+ (WDPBattery*)aggregateBattery;
- (EventRegistrationToken)addReportUpdatedEvent:(void (^)(WDPBattery*, RTObject*))del;
- (void)removeReportUpdatedEvent:(EventRegistrationToken)tok;
- (WDPBatteryReport*)getReport;
@end

#endif // __WDPBattery_DEFINED__
