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

// WindowsDevicesSensorsCustom.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDSCCustomSensor, WDSCCustomSensorReading, WDSCCustomSensorReadingChangedEventArgs;
@protocol WDSCICustomSensorStatics
, WDSCICustomSensor, WDSCICustomSensorReading, WDSCICustomSensorReadingChangedEventArgs;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Sensors.Custom.CustomSensor
#ifndef __WDSCCustomSensor_DEFINED__
#define __WDSCCustomSensor_DEFINED__

WINRT_EXPORT
@interface WDSCCustomSensor : RTObject
+ (NSString*)getDeviceSelector:(WFGUID*)interfaceId;
+ (void)fromIdAsync:(NSString*)sensorId success:(void (^)(WDSCCustomSensor*))success failure:(void (^)(NSError*))failure;
@property unsigned int reportInterval;
@property (readonly) NSString* deviceId;
@property (readonly) unsigned int minimumReportInterval;
- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSCCustomSensor*, WDSCCustomSensorReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSCCustomSensorReading*)getCurrentReading;
@end

#endif // __WDSCCustomSensor_DEFINED__

// Windows.Devices.Sensors.Custom.CustomSensorReading
#ifndef __WDSCCustomSensorReading_DEFINED__
#define __WDSCCustomSensorReading_DEFINED__

WINRT_EXPORT
@interface WDSCCustomSensorReading : RTObject
@property (readonly) NSDictionary* properties;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSCCustomSensorReading_DEFINED__

// Windows.Devices.Sensors.Custom.CustomSensorReadingChangedEventArgs
#ifndef __WDSCCustomSensorReadingChangedEventArgs_DEFINED__
#define __WDSCCustomSensorReadingChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSCCustomSensorReadingChangedEventArgs : RTObject
@property (readonly) WDSCCustomSensorReading* reading;
@end

#endif // __WDSCCustomSensorReadingChangedEventArgs_DEFINED__
