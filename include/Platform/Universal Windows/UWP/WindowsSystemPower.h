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

// WindowsSystemPower.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSPPowerManager, WSPBackgroundEnergyManager, WSPForegroundEnergyManager;
@protocol WSPIPowerManagerStatics
, WSPIBackgroundEnergyManagerStatics, WSPIForegroundEnergyManagerStatics;

// Windows.System.Power.BatteryStatus
enum _WSPBatteryStatus {
    WSPBatteryStatusNotPresent = 0,
    WSPBatteryStatusDischarging = 1,
    WSPBatteryStatusIdle = 2,
    WSPBatteryStatusCharging = 3,
};
typedef unsigned WSPBatteryStatus;

// Windows.System.Power.EnergySaverStatus
enum _WSPEnergySaverStatus {
    WSPEnergySaverStatusDisabled = 0,
    WSPEnergySaverStatusOff = 1,
    WSPEnergySaverStatusOn = 2,
};
typedef unsigned WSPEnergySaverStatus;

// Windows.System.Power.PowerSupplyStatus
enum _WSPPowerSupplyStatus {
    WSPPowerSupplyStatusNotPresent = 0,
    WSPPowerSupplyStatusInadequate = 1,
    WSPPowerSupplyStatusAdequate = 2,
};
typedef unsigned WSPPowerSupplyStatus;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.System.Power.PowerManager
#ifndef __WSPPowerManager_DEFINED__
#define __WSPPowerManager_DEFINED__

WINRT_EXPORT
@interface WSPPowerManager : RTObject
+ (WSPBatteryStatus)batteryStatus;
+ (WSPEnergySaverStatus)energySaverStatus;
+ (WSPPowerSupplyStatus)powerSupplyStatus;
+ (int)remainingChargePercent;
+ (WFTimeSpan*)remainingDischargeTime;
+ (EventRegistrationToken)addBatteryStatusChangedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeBatteryStatusChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addEnergySaverStatusChangedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeEnergySaverStatusChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addPowerSupplyStatusChangedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removePowerSupplyStatusChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addRemainingChargePercentChangedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeRemainingChargePercentChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addRemainingDischargeTimeChangedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeRemainingDischargeTimeChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WSPPowerManager_DEFINED__

// Windows.System.Power.BackgroundEnergyManager
#ifndef __WSPBackgroundEnergyManager_DEFINED__
#define __WSPBackgroundEnergyManager_DEFINED__

WINRT_EXPORT
@interface WSPBackgroundEnergyManager : RTObject
+ (unsigned int)excessiveUsageLevel;
+ (unsigned int)lowUsageLevel;
+ (unsigned int)maxAcceptableUsageLevel;
+ (unsigned int)nearMaxAcceptableUsageLevel;
+ (unsigned int)nearTerminationUsageLevel;
+ (unsigned int)recentEnergyUsage;
+ (unsigned int)recentEnergyUsageLevel;
+ (unsigned int)terminationUsageLevel;
+ (EventRegistrationToken)addRecentEnergyUsageIncreasedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeRecentEnergyUsageIncreasedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addRecentEnergyUsageReturnedToLowEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeRecentEnergyUsageReturnedToLowEvent:(EventRegistrationToken)tok;
@end

#endif // __WSPBackgroundEnergyManager_DEFINED__

// Windows.System.Power.ForegroundEnergyManager
#ifndef __WSPForegroundEnergyManager_DEFINED__
#define __WSPForegroundEnergyManager_DEFINED__

WINRT_EXPORT
@interface WSPForegroundEnergyManager : RTObject
+ (unsigned int)excessiveUsageLevel;
+ (unsigned int)lowUsageLevel;
+ (unsigned int)maxAcceptableUsageLevel;
+ (unsigned int)nearMaxAcceptableUsageLevel;
+ (unsigned int)recentEnergyUsage;
+ (unsigned int)recentEnergyUsageLevel;
+ (EventRegistrationToken)addRecentEnergyUsageIncreasedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeRecentEnergyUsageIncreasedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addRecentEnergyUsageReturnedToLowEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeRecentEnergyUsageReturnedToLowEvent:(EventRegistrationToken)tok;
@end

#endif // __WSPForegroundEnergyManager_DEFINED__
