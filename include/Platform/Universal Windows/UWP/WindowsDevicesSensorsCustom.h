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

// WindowsDevicesSensorsCustom.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESSENSORSCUSTOMEXPORT
#define OBJCUWPWINDOWSDEVICESSENSORSCUSTOMEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesSensorsCustom.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDSCCustomSensor, WDSCCustomSensorReading, WDSCCustomSensorReadingChangedEventArgs;
@protocol WDSCICustomSensorStatics, WDSCICustomSensor, WDSCICustomSensor2, WDSCICustomSensorReading, WDSCICustomSensorReading2, WDSCICustomSensorReadingChangedEventArgs;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Sensors.Custom.CustomSensor
#ifndef __WDSCCustomSensor_DEFINED__
#define __WDSCCustomSensor_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSCUSTOMEXPORT
@interface WDSCCustomSensor : RTObject
+ (NSString *)getDeviceSelector:(WFGUID*)interfaceId;
+ (void)fromIdAsync:(NSString *)sensorId success:(void (^)(WDSCCustomSensor*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int reportInterval;
@property (readonly) NSString * deviceId;
@property (readonly) unsigned int minimumReportInterval;
@property unsigned int reportLatency;
@property (readonly) unsigned int maxBatchSize;
- (EventRegistrationToken)addReadingChangedEvent:(void(^)(WDSCCustomSensor*, WDSCCustomSensorReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSCCustomSensorReading*)getCurrentReading;
@end

#endif // __WDSCCustomSensor_DEFINED__

// Windows.Devices.Sensors.Custom.CustomSensorReading
#ifndef __WDSCCustomSensorReading_DEFINED__
#define __WDSCCustomSensorReading_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSCUSTOMEXPORT
@interface WDSCCustomSensorReading : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSDictionary* /* NSString *, RTObject* */ properties;
@property (readonly) WFDateTime* timestamp;
@property (readonly) id /* WFTimeSpan* */ performanceCount;
@end

#endif // __WDSCCustomSensorReading_DEFINED__

// Windows.Devices.Sensors.Custom.CustomSensorReadingChangedEventArgs
#ifndef __WDSCCustomSensorReadingChangedEventArgs_DEFINED__
#define __WDSCCustomSensorReadingChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSCUSTOMEXPORT
@interface WDSCCustomSensorReadingChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSCCustomSensorReading* reading;
@end

#endif // __WDSCCustomSensorReadingChangedEventArgs_DEFINED__

