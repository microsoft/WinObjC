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

// WindowsDevicesSensors.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESSENSORSEXPORT
#define OBJCUWPWINDOWSDEVICESSENSORSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesSensors.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDSSensorDataThresholdTriggerDetails, WDSAccelerometer, WDSAccelerometerReading, WDSAccelerometerReadingChangedEventArgs, WDSAccelerometerShakenEventArgs, WDSInclinometer, WDSInclinometerReading, WDSInclinometerReadingChangedEventArgs, WDSGyrometer, WDSGyrometerReading, WDSGyrometerReadingChangedEventArgs, WDSCompass, WDSCompassReading, WDSCompassReadingChangedEventArgs, WDSLightSensor, WDSLightSensorReading, WDSLightSensorReadingChangedEventArgs, WDSSensorRotationMatrix, WDSSensorQuaternion, WDSOrientationSensor, WDSOrientationSensorReading, WDSOrientationSensorReadingChangedEventArgs, WDSSimpleOrientationSensor, WDSSimpleOrientationSensorOrientationChangedEventArgs, WDSMagnetometer, WDSMagnetometerReading, WDSMagnetometerReadingChangedEventArgs, WDSActivitySensor, WDSActivitySensorReading, WDSActivitySensorReadingChangedEventArgs, WDSActivitySensorReadingChangeReport, WDSActivitySensorTriggerDetails, WDSBarometer, WDSBarometerReading, WDSBarometerReadingChangedEventArgs, WDSPedometerReading, WDSPedometer, WDSPedometerReadingChangedEventArgs, WDSPedometerDataThreshold, WDSProximitySensor, WDSProximitySensorReading, WDSProximitySensorReadingChangedEventArgs, WDSProximitySensorDisplayOnOffController, WDSProximitySensorDataThreshold, WDSAltimeter, WDSAltimeterReading, WDSAltimeterReadingChangedEventArgs;
@protocol WDSISensorDataThreshold, WDSISensorDataThresholdTriggerDetails, WDSIAccelerometerDeviceId, WDSIAccelerometerStatics, WDSIAccelerometerStatics2, WDSIAccelerometerStatics3, WDSIAccelerometer, WDSIAccelerometer2, WDSIAccelerometer3, WDSIAccelerometer4, WDSIAccelerometerReading, WDSIAccelerometerReading2, WDSIAccelerometerReadingChangedEventArgs, WDSIAccelerometerShakenEventArgs, WDSIInclinometerDeviceId, WDSIInclinometerStatics, WDSIInclinometerStatics2, WDSIInclinometerStatics3, WDSIInclinometerStatics4, WDSIInclinometer, WDSIInclinometer2, WDSIInclinometer3, WDSIInclinometerReading, WDSIInclinometerReading2, WDSIInclinometerReadingYawAccuracy, WDSIInclinometerReadingChangedEventArgs, WDSIGyrometerDeviceId, WDSIGyrometerStatics, WDSIGyrometerStatics2, WDSIGyrometer, WDSIGyrometer2, WDSIGyrometer3, WDSIGyrometerReading, WDSIGyrometerReading2, WDSIGyrometerReadingChangedEventArgs, WDSICompassDeviceId, WDSICompassStatics, WDSICompassStatics2, WDSICompass, WDSICompass2, WDSICompass3, WDSICompassReading, WDSICompassReading2, WDSICompassReadingHeadingAccuracy, WDSICompassReadingChangedEventArgs, WDSILightSensorDeviceId, WDSILightSensorStatics, WDSILightSensorStatics2, WDSILightSensor, WDSILightSensor2, WDSILightSensorReading, WDSILightSensorReading2, WDSILightSensorReadingChangedEventArgs, WDSISensorRotationMatrix, WDSISensorQuaternion, WDSIOrientationSensorDeviceId, WDSIOrientationSensorStatics, WDSIOrientationSensorStatics2, WDSIOrientationSensorStatics3, WDSIOrientationSensorStatics4, WDSIOrientationSensor, WDSIOrientationSensor2, WDSIOrientationSensor3, WDSIOrientationSensorReading, WDSIOrientationSensorReading2, WDSIOrientationSensorReadingYawAccuracy, WDSIOrientationSensorReadingChangedEventArgs, WDSISimpleOrientationSensorDeviceId, WDSISimpleOrientationSensorStatics, WDSISimpleOrientationSensor, WDSISimpleOrientationSensor2, WDSISimpleOrientationSensorOrientationChangedEventArgs, WDSIMagnetometerDeviceId, WDSIMagnetometerStatics, WDSIMagnetometerStatics2, WDSIMagnetometer, WDSIMagnetometer2, WDSIMagnetometer3, WDSIMagnetometerReading, WDSIMagnetometerReading2, WDSIMagnetometerReadingChangedEventArgs, WDSIActivitySensorStatics, WDSIActivitySensor, WDSIActivitySensorReading, WDSIActivitySensorReadingChangedEventArgs, WDSIActivitySensorReadingChangeReport, WDSIActivitySensorTriggerDetails, WDSIBarometerStatics, WDSIBarometerStatics2, WDSIBarometer, WDSIBarometer2, WDSIBarometerReading, WDSIBarometerReading2, WDSIBarometerReadingChangedEventArgs, WDSIPedometerReading, WDSIPedometerReadingChangedEventArgs, WDSIPedometerStatics, WDSIPedometerStatics2, WDSIPedometer2, WDSIPedometer, WDSIPedometerDataThresholdFactory, WDSIProximitySensorStatics, WDSIProximitySensor, WDSIProximitySensorReadingChangedEventArgs, WDSIProximitySensorReading, WDSIProximitySensorDataThresholdFactory, WDSIProximitySensorStatics2, WDSIAltimeterStatics, WDSIAltimeter, WDSIAltimeter2, WDSIAltimeterReading, WDSIAltimeterReading2, WDSIAltimeterReadingChangedEventArgs;

// Windows.Devices.Sensors.MagnetometerAccuracy
enum _WDSMagnetometerAccuracy {
    WDSMagnetometerAccuracyUnknown = 0,
    WDSMagnetometerAccuracyUnreliable = 1,
    WDSMagnetometerAccuracyApproximate = 2,
    WDSMagnetometerAccuracyHigh = 3,
};
typedef unsigned WDSMagnetometerAccuracy;

// Windows.Devices.Sensors.ActivityType
enum _WDSActivityType {
    WDSActivityTypeUnknown = 0,
    WDSActivityTypeIdle = 1,
    WDSActivityTypeStationary = 2,
    WDSActivityTypeFidgeting = 3,
    WDSActivityTypeWalking = 4,
    WDSActivityTypeRunning = 5,
    WDSActivityTypeInVehicle = 6,
    WDSActivityTypeBiking = 7,
};
typedef unsigned WDSActivityType;

// Windows.Devices.Sensors.ActivitySensorReadingConfidence
enum _WDSActivitySensorReadingConfidence {
    WDSActivitySensorReadingConfidenceHigh = 0,
    WDSActivitySensorReadingConfidenceLow = 1,
};
typedef unsigned WDSActivitySensorReadingConfidence;

// Windows.Devices.Sensors.SensorReadingType
enum _WDSSensorReadingType {
    WDSSensorReadingTypeAbsolute = 0,
    WDSSensorReadingTypeRelative = 1,
};
typedef unsigned WDSSensorReadingType;

// Windows.Devices.Sensors.AccelerometerReadingType
enum _WDSAccelerometerReadingType {
    WDSAccelerometerReadingTypeStandard = 0,
    WDSAccelerometerReadingTypeLinear = 1,
    WDSAccelerometerReadingTypeGravity = 2,
};
typedef unsigned WDSAccelerometerReadingType;

// Windows.Devices.Sensors.SensorOptimizationGoal
enum _WDSSensorOptimizationGoal {
    WDSSensorOptimizationGoalPrecision = 0,
    WDSSensorOptimizationGoalPowerEfficiency = 1,
};
typedef unsigned WDSSensorOptimizationGoal;

// Windows.Devices.Sensors.SensorType
enum _WDSSensorType {
    WDSSensorTypeAccelerometer = 0,
    WDSSensorTypeActivitySensor = 1,
    WDSSensorTypeBarometer = 2,
    WDSSensorTypeCompass = 3,
    WDSSensorTypeCustomSensor = 4,
    WDSSensorTypeGyroscope = 5,
    WDSSensorTypeProximitySensor = 6,
    WDSSensorTypeInclinometer = 7,
    WDSSensorTypeLightSensor = 8,
    WDSSensorTypeOrientationSensor = 9,
    WDSSensorTypePedometer = 10,
    WDSSensorTypeRelativeInclinometer = 11,
    WDSSensorTypeRelativeOrientationSensor = 12,
    WDSSensorTypeSimpleOrientationSensor = 13,
};
typedef unsigned WDSSensorType;

// Windows.Devices.Sensors.SimpleOrientation
enum _WDSSimpleOrientation {
    WDSSimpleOrientationNotRotated = 0,
    WDSSimpleOrientationRotated90DegreesCounterclockwise = 1,
    WDSSimpleOrientationRotated180DegreesCounterclockwise = 2,
    WDSSimpleOrientationRotated270DegreesCounterclockwise = 3,
    WDSSimpleOrientationFaceup = 4,
    WDSSimpleOrientationFacedown = 5,
};
typedef unsigned WDSSimpleOrientation;

// Windows.Devices.Sensors.PedometerStepKind
enum _WDSPedometerStepKind {
    WDSPedometerStepKindUnknown = 0,
    WDSPedometerStepKindWalking = 1,
    WDSPedometerStepKindRunning = 2,
};
typedef unsigned WDSPedometerStepKind;

#include "WindowsFoundation.h"
#include "WindowsGraphicsDisplay.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Sensors.ISensorDataThreshold
#ifndef __WDSISensorDataThreshold_DEFINED__
#define __WDSISensorDataThreshold_DEFINED__

@protocol WDSISensorDataThreshold
@end

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSISensorDataThreshold : RTObject <WDSISensorDataThreshold>
@end

#endif // __WDSISensorDataThreshold_DEFINED__

// Windows.Devices.Sensors.SensorDataThresholdTriggerDetails
#ifndef __WDSSensorDataThresholdTriggerDetails_DEFINED__
#define __WDSSensorDataThresholdTriggerDetails_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSSensorDataThresholdTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * deviceId;
@property (readonly) WDSSensorType sensorType;
@end

#endif // __WDSSensorDataThresholdTriggerDetails_DEFINED__

// Windows.Devices.Sensors.Accelerometer
#ifndef __WDSAccelerometer_DEFINED__
#define __WDSAccelerometer_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSAccelerometer : RTObject
+ (WDSAccelerometer*)getDefault;
+ (WDSAccelerometer*)getDefaultWithAccelerometerReadingType:(WDSAccelerometerReadingType)readingType;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDSAccelerometer*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector:(WDSAccelerometerReadingType)readingType;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int reportInterval;
@property (readonly) unsigned int minimumReportInterval;
@property WGDDisplayOrientations readingTransform;
@property unsigned int reportLatency;
@property (readonly) unsigned int maxBatchSize;
@property (readonly) WDSAccelerometerReadingType readingType;
@property (readonly) NSString * deviceId;
- (EventRegistrationToken)addReadingChangedEvent:(void(^)(WDSAccelerometer*, WDSAccelerometerReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addShakenEvent:(void(^)(WDSAccelerometer*, WDSAccelerometerShakenEventArgs*))del;
- (void)removeShakenEvent:(EventRegistrationToken)tok;
- (WDSAccelerometerReading*)getCurrentReading;
@end

#endif // __WDSAccelerometer_DEFINED__

// Windows.Devices.Sensors.AccelerometerReading
#ifndef __WDSAccelerometerReading_DEFINED__
#define __WDSAccelerometerReading_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSAccelerometerReading : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) double accelerationX;
@property (readonly) double accelerationY;
@property (readonly) double accelerationZ;
@property (readonly) WFDateTime* timestamp;
@property (readonly) id /* WFTimeSpan* */ performanceCount;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ properties;
@end

#endif // __WDSAccelerometerReading_DEFINED__

// Windows.Devices.Sensors.AccelerometerReadingChangedEventArgs
#ifndef __WDSAccelerometerReadingChangedEventArgs_DEFINED__
#define __WDSAccelerometerReadingChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSAccelerometerReadingChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSAccelerometerReading* reading;
@end

#endif // __WDSAccelerometerReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.AccelerometerShakenEventArgs
#ifndef __WDSAccelerometerShakenEventArgs_DEFINED__
#define __WDSAccelerometerShakenEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSAccelerometerShakenEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSAccelerometerShakenEventArgs_DEFINED__

// Windows.Devices.Sensors.Inclinometer
#ifndef __WDSInclinometer_DEFINED__
#define __WDSInclinometer_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSInclinometer : RTObject
+ (WDSInclinometer*)getDefaultForRelativeReadings;
+ (NSString *)getDeviceSelector:(WDSSensorReadingType)readingType;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDSInclinometer*))success failure:(void (^)(NSError*))failure;
+ (WDSInclinometer*)getDefaultWithSensorReadingType:(WDSSensorReadingType)sensorReadingtype;
+ (WDSInclinometer*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int reportInterval;
@property (readonly) unsigned int minimumReportInterval;
@property WGDDisplayOrientations readingTransform;
@property (readonly) WDSSensorReadingType readingType;
@property unsigned int reportLatency;
@property (readonly) unsigned int maxBatchSize;
@property (readonly) NSString * deviceId;
- (EventRegistrationToken)addReadingChangedEvent:(void(^)(WDSInclinometer*, WDSInclinometerReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSInclinometerReading*)getCurrentReading;
@end

#endif // __WDSInclinometer_DEFINED__

// Windows.Devices.Sensors.InclinometerReading
#ifndef __WDSInclinometerReading_DEFINED__
#define __WDSInclinometerReading_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSInclinometerReading : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) float pitchDegrees;
@property (readonly) float rollDegrees;
@property (readonly) WFDateTime* timestamp;
@property (readonly) float yawDegrees;
@property (readonly) id /* WFTimeSpan* */ performanceCount;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ properties;
@property (readonly) WDSMagnetometerAccuracy yawAccuracy;
@end

#endif // __WDSInclinometerReading_DEFINED__

// Windows.Devices.Sensors.InclinometerReadingChangedEventArgs
#ifndef __WDSInclinometerReadingChangedEventArgs_DEFINED__
#define __WDSInclinometerReadingChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSInclinometerReadingChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSInclinometerReading* reading;
@end

#endif // __WDSInclinometerReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.Gyrometer
#ifndef __WDSGyrometer_DEFINED__
#define __WDSGyrometer_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSGyrometer : RTObject
+ (NSString *)getDeviceSelector;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDSGyrometer*))success failure:(void (^)(NSError*))failure;
+ (WDSGyrometer*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int reportInterval;
@property (readonly) unsigned int minimumReportInterval;
@property WGDDisplayOrientations readingTransform;
@property unsigned int reportLatency;
@property (readonly) unsigned int maxBatchSize;
@property (readonly) NSString * deviceId;
- (EventRegistrationToken)addReadingChangedEvent:(void(^)(WDSGyrometer*, WDSGyrometerReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSGyrometerReading*)getCurrentReading;
@end

#endif // __WDSGyrometer_DEFINED__

// Windows.Devices.Sensors.GyrometerReading
#ifndef __WDSGyrometerReading_DEFINED__
#define __WDSGyrometerReading_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSGyrometerReading : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) double angularVelocityX;
@property (readonly) double angularVelocityY;
@property (readonly) double angularVelocityZ;
@property (readonly) WFDateTime* timestamp;
@property (readonly) id /* WFTimeSpan* */ performanceCount;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ properties;
@end

#endif // __WDSGyrometerReading_DEFINED__

// Windows.Devices.Sensors.GyrometerReadingChangedEventArgs
#ifndef __WDSGyrometerReadingChangedEventArgs_DEFINED__
#define __WDSGyrometerReadingChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSGyrometerReadingChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSGyrometerReading* reading;
@end

#endif // __WDSGyrometerReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.Compass
#ifndef __WDSCompass_DEFINED__
#define __WDSCompass_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSCompass : RTObject
+ (WDSCompass*)getDefault;
+ (NSString *)getDeviceSelector;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDSCompass*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int reportInterval;
@property (readonly) unsigned int minimumReportInterval;
@property WGDDisplayOrientations readingTransform;
@property unsigned int reportLatency;
@property (readonly) unsigned int maxBatchSize;
@property (readonly) NSString * deviceId;
- (EventRegistrationToken)addReadingChangedEvent:(void(^)(WDSCompass*, WDSCompassReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSCompassReading*)getCurrentReading;
@end

#endif // __WDSCompass_DEFINED__

// Windows.Devices.Sensors.CompassReading
#ifndef __WDSCompassReading_DEFINED__
#define __WDSCompassReading_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSCompassReading : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) double headingMagneticNorth;
@property (readonly) id /* double */ headingTrueNorth;
@property (readonly) WFDateTime* timestamp;
@property (readonly) id /* WFTimeSpan* */ performanceCount;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ properties;
@property (readonly) WDSMagnetometerAccuracy headingAccuracy;
@end

#endif // __WDSCompassReading_DEFINED__

// Windows.Devices.Sensors.CompassReadingChangedEventArgs
#ifndef __WDSCompassReadingChangedEventArgs_DEFINED__
#define __WDSCompassReadingChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSCompassReadingChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSCompassReading* reading;
@end

#endif // __WDSCompassReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.LightSensor
#ifndef __WDSLightSensor_DEFINED__
#define __WDSLightSensor_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSLightSensor : RTObject
+ (WDSLightSensor*)getDefault;
+ (NSString *)getDeviceSelector;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDSLightSensor*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int reportInterval;
@property (readonly) unsigned int minimumReportInterval;
@property unsigned int reportLatency;
@property (readonly) unsigned int maxBatchSize;
@property (readonly) NSString * deviceId;
- (EventRegistrationToken)addReadingChangedEvent:(void(^)(WDSLightSensor*, WDSLightSensorReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSLightSensorReading*)getCurrentReading;
@end

#endif // __WDSLightSensor_DEFINED__

// Windows.Devices.Sensors.LightSensorReading
#ifndef __WDSLightSensorReading_DEFINED__
#define __WDSLightSensorReading_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSLightSensorReading : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) float illuminanceInLux;
@property (readonly) WFDateTime* timestamp;
@property (readonly) id /* WFTimeSpan* */ performanceCount;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ properties;
@end

#endif // __WDSLightSensorReading_DEFINED__

// Windows.Devices.Sensors.LightSensorReadingChangedEventArgs
#ifndef __WDSLightSensorReadingChangedEventArgs_DEFINED__
#define __WDSLightSensorReadingChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSLightSensorReadingChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSLightSensorReading* reading;
@end

#endif // __WDSLightSensorReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.SensorRotationMatrix
#ifndef __WDSSensorRotationMatrix_DEFINED__
#define __WDSSensorRotationMatrix_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSSensorRotationMatrix : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) float m11;
@property (readonly) float m12;
@property (readonly) float m13;
@property (readonly) float m21;
@property (readonly) float m22;
@property (readonly) float m23;
@property (readonly) float m31;
@property (readonly) float m32;
@property (readonly) float m33;
@end

#endif // __WDSSensorRotationMatrix_DEFINED__

// Windows.Devices.Sensors.SensorQuaternion
#ifndef __WDSSensorQuaternion_DEFINED__
#define __WDSSensorQuaternion_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSSensorQuaternion : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) float w;
@property (readonly) float x;
@property (readonly) float y;
@property (readonly) float z;
@end

#endif // __WDSSensorQuaternion_DEFINED__

// Windows.Devices.Sensors.OrientationSensor
#ifndef __WDSOrientationSensor_DEFINED__
#define __WDSOrientationSensor_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSOrientationSensor : RTObject
+ (WDSOrientationSensor*)getDefault;
+ (WDSOrientationSensor*)getDefaultForRelativeReadings;
+ (NSString *)getDeviceSelector:(WDSSensorReadingType)readingType;
+ (NSString *)getDeviceSelectorWithSensorReadingTypeAndSensorOptimizationGoal:(WDSSensorReadingType)readingType optimizationGoal:(WDSSensorOptimizationGoal)optimizationGoal;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDSOrientationSensor*))success failure:(void (^)(NSError*))failure;
+ (WDSOrientationSensor*)getDefaultWithSensorReadingType:(WDSSensorReadingType)sensorReadingtype;
+ (WDSOrientationSensor*)getDefaultWithSensorReadingTypeAndSensorOptimizationGoal:(WDSSensorReadingType)sensorReadingType optimizationGoal:(WDSSensorOptimizationGoal)optimizationGoal;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int reportInterval;
@property (readonly) unsigned int minimumReportInterval;
@property WGDDisplayOrientations readingTransform;
@property (readonly) WDSSensorReadingType readingType;
@property unsigned int reportLatency;
@property (readonly) unsigned int maxBatchSize;
@property (readonly) NSString * deviceId;
- (EventRegistrationToken)addReadingChangedEvent:(void(^)(WDSOrientationSensor*, WDSOrientationSensorReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSOrientationSensorReading*)getCurrentReading;
@end

#endif // __WDSOrientationSensor_DEFINED__

// Windows.Devices.Sensors.OrientationSensorReading
#ifndef __WDSOrientationSensorReading_DEFINED__
#define __WDSOrientationSensorReading_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSOrientationSensorReading : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSSensorQuaternion* quaternion;
@property (readonly) WDSSensorRotationMatrix* rotationMatrix;
@property (readonly) WFDateTime* timestamp;
@property (readonly) id /* WFTimeSpan* */ performanceCount;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ properties;
@property (readonly) WDSMagnetometerAccuracy yawAccuracy;
@end

#endif // __WDSOrientationSensorReading_DEFINED__

// Windows.Devices.Sensors.OrientationSensorReadingChangedEventArgs
#ifndef __WDSOrientationSensorReadingChangedEventArgs_DEFINED__
#define __WDSOrientationSensorReadingChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSOrientationSensorReadingChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSOrientationSensorReading* reading;
@end

#endif // __WDSOrientationSensorReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.SimpleOrientationSensor
#ifndef __WDSSimpleOrientationSensor_DEFINED__
#define __WDSSimpleOrientationSensor_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSSimpleOrientationSensor : RTObject
+ (WDSSimpleOrientationSensor*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WGDDisplayOrientations readingTransform;
@property (readonly) NSString * deviceId;
- (EventRegistrationToken)addOrientationChangedEvent:(void(^)(WDSSimpleOrientationSensor*, WDSSimpleOrientationSensorOrientationChangedEventArgs*))del;
- (void)removeOrientationChangedEvent:(EventRegistrationToken)tok;
- (WDSSimpleOrientation)getCurrentOrientation;
@end

#endif // __WDSSimpleOrientationSensor_DEFINED__

// Windows.Devices.Sensors.SimpleOrientationSensorOrientationChangedEventArgs
#ifndef __WDSSimpleOrientationSensorOrientationChangedEventArgs_DEFINED__
#define __WDSSimpleOrientationSensorOrientationChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSSimpleOrientationSensorOrientationChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSSimpleOrientation orientation;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSSimpleOrientationSensorOrientationChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.Magnetometer
#ifndef __WDSMagnetometer_DEFINED__
#define __WDSMagnetometer_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSMagnetometer : RTObject
+ (NSString *)getDeviceSelector;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDSMagnetometer*))success failure:(void (^)(NSError*))failure;
+ (WDSMagnetometer*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int reportInterval;
@property (readonly) unsigned int minimumReportInterval;
@property WGDDisplayOrientations readingTransform;
@property unsigned int reportLatency;
@property (readonly) unsigned int maxBatchSize;
@property (readonly) NSString * deviceId;
- (EventRegistrationToken)addReadingChangedEvent:(void(^)(WDSMagnetometer*, WDSMagnetometerReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSMagnetometerReading*)getCurrentReading;
@end

#endif // __WDSMagnetometer_DEFINED__

// Windows.Devices.Sensors.MagnetometerReading
#ifndef __WDSMagnetometerReading_DEFINED__
#define __WDSMagnetometerReading_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSMagnetometerReading : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSMagnetometerAccuracy directionalAccuracy;
@property (readonly) float magneticFieldX;
@property (readonly) float magneticFieldY;
@property (readonly) float magneticFieldZ;
@property (readonly) WFDateTime* timestamp;
@property (readonly) id /* WFTimeSpan* */ performanceCount;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ properties;
@end

#endif // __WDSMagnetometerReading_DEFINED__

// Windows.Devices.Sensors.MagnetometerReadingChangedEventArgs
#ifndef __WDSMagnetometerReadingChangedEventArgs_DEFINED__
#define __WDSMagnetometerReadingChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSMagnetometerReadingChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSMagnetometerReading* reading;
@end

#endif // __WDSMagnetometerReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.ActivitySensor
#ifndef __WDSActivitySensor_DEFINED__
#define __WDSActivitySensor_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSActivitySensor : RTObject
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDSActivitySensor*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDSActivitySensor*))success failure:(void (^)(NSError*))failure;
+ (void)getSystemHistoryAsync:(WFDateTime*)fromTime success:(void (^)(NSArray* /* WDSActivitySensorReading* */))success failure:(void (^)(NSError*))failure;
+ (void)getSystemHistoryWithDurationAsync:(WFDateTime*)fromTime duration:(WFTimeSpan*)duration success:(void (^)(NSArray* /* WDSActivitySensorReading* */))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * deviceId;
@property (readonly) unsigned int minimumReportInterval;
@property (readonly) double powerInMilliwatts;
@property (readonly) NSMutableArray* /* WDSActivityType */ subscribedActivities;
@property (readonly) NSArray* /* WDSActivityType */ supportedActivities;
- (EventRegistrationToken)addReadingChangedEvent:(void(^)(WDSActivitySensor*, WDSActivitySensorReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (void)getCurrentReadingAsyncWithSuccess:(void (^)(WDSActivitySensorReading*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDSActivitySensor_DEFINED__

// Windows.Devices.Sensors.ActivitySensorReading
#ifndef __WDSActivitySensorReading_DEFINED__
#define __WDSActivitySensorReading_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSActivitySensorReading : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSActivityType activity;
@property (readonly) WDSActivitySensorReadingConfidence confidence;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSActivitySensorReading_DEFINED__

// Windows.Devices.Sensors.ActivitySensorReadingChangedEventArgs
#ifndef __WDSActivitySensorReadingChangedEventArgs_DEFINED__
#define __WDSActivitySensorReadingChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSActivitySensorReadingChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSActivitySensorReading* reading;
@end

#endif // __WDSActivitySensorReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.ActivitySensorReadingChangeReport
#ifndef __WDSActivitySensorReadingChangeReport_DEFINED__
#define __WDSActivitySensorReadingChangeReport_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSActivitySensorReadingChangeReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSActivitySensorReading* reading;
@end

#endif // __WDSActivitySensorReadingChangeReport_DEFINED__

// Windows.Devices.Sensors.ActivitySensorTriggerDetails
#ifndef __WDSActivitySensorTriggerDetails_DEFINED__
#define __WDSActivitySensorTriggerDetails_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSActivitySensorTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (NSArray* /* WDSActivitySensorReadingChangeReport* */)readReports;
@end

#endif // __WDSActivitySensorTriggerDetails_DEFINED__

// Windows.Devices.Sensors.Barometer
#ifndef __WDSBarometer_DEFINED__
#define __WDSBarometer_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSBarometer : RTObject
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDSBarometer*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
+ (WDSBarometer*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int reportInterval;
@property (readonly) NSString * deviceId;
@property (readonly) unsigned int minimumReportInterval;
@property unsigned int reportLatency;
@property (readonly) unsigned int maxBatchSize;
- (EventRegistrationToken)addReadingChangedEvent:(void(^)(WDSBarometer*, WDSBarometerReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSBarometerReading*)getCurrentReading;
@end

#endif // __WDSBarometer_DEFINED__

// Windows.Devices.Sensors.BarometerReading
#ifndef __WDSBarometerReading_DEFINED__
#define __WDSBarometerReading_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSBarometerReading : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) double stationPressureInHectopascals;
@property (readonly) WFDateTime* timestamp;
@property (readonly) id /* WFTimeSpan* */ performanceCount;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ properties;
@end

#endif // __WDSBarometerReading_DEFINED__

// Windows.Devices.Sensors.BarometerReadingChangedEventArgs
#ifndef __WDSBarometerReadingChangedEventArgs_DEFINED__
#define __WDSBarometerReadingChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSBarometerReadingChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSBarometerReading* reading;
@end

#endif // __WDSBarometerReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.PedometerReading
#ifndef __WDSPedometerReading_DEFINED__
#define __WDSPedometerReading_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSPedometerReading : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int cumulativeSteps;
@property (readonly) WFTimeSpan* cumulativeStepsDuration;
@property (readonly) WDSPedometerStepKind stepKind;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSPedometerReading_DEFINED__

// Windows.Devices.Sensors.Pedometer
#ifndef __WDSPedometer_DEFINED__
#define __WDSPedometer_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSPedometer : RTObject
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDSPedometer*))success failure:(void (^)(NSError*))failure;
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDSPedometer*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
+ (void)getSystemHistoryAsync:(WFDateTime*)fromTime success:(void (^)(NSArray* /* WDSPedometerReading* */))success failure:(void (^)(NSError*))failure;
+ (void)getSystemHistoryWithDurationAsync:(WFDateTime*)fromTime duration:(WFTimeSpan*)duration success:(void (^)(NSArray* /* WDSPedometerReading* */))success failure:(void (^)(NSError*))failure;
+ (NSArray* /* WDSPedometerReading* */)getReadingsFromTriggerDetails:(WDSSensorDataThresholdTriggerDetails*)triggerDetails;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int reportInterval;
@property (readonly) NSString * deviceId;
@property (readonly) unsigned int minimumReportInterval;
@property (readonly) double powerInMilliwatts;
- (EventRegistrationToken)addReadingChangedEvent:(void(^)(WDSPedometer*, WDSPedometerReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (NSDictionary* /* WDSPedometerStepKind, WDSPedometerReading* */)getCurrentReadings;
@end

#endif // __WDSPedometer_DEFINED__

// Windows.Devices.Sensors.PedometerReadingChangedEventArgs
#ifndef __WDSPedometerReadingChangedEventArgs_DEFINED__
#define __WDSPedometerReadingChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSPedometerReadingChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSPedometerReading* reading;
@end

#endif // __WDSPedometerReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.PedometerDataThreshold
#ifndef __WDSPedometerDataThreshold_DEFINED__
#define __WDSPedometerDataThreshold_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSPedometerDataThreshold : RTObject <WDSISensorDataThreshold>
+ (WDSPedometerDataThreshold*)make:(WDSPedometer*)sensor stepGoal:(int)stepGoal ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WDSPedometerDataThreshold_DEFINED__

// Windows.Devices.Sensors.ProximitySensor
#ifndef __WDSProximitySensor_DEFINED__
#define __WDSProximitySensor_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSProximitySensor : RTObject
+ (NSString *)getDeviceSelector;
+ (WDSProximitySensor*)fromId:(NSString *)sensorId;
+ (NSArray* /* WDSProximitySensorReading* */)getReadingsFromTriggerDetails:(WDSSensorDataThresholdTriggerDetails*)triggerDetails;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * deviceId;
@property (readonly) id /* unsigned int */ maxDistanceInMillimeters;
@property (readonly) id /* unsigned int */ minDistanceInMillimeters;
- (EventRegistrationToken)addReadingChangedEvent:(void(^)(WDSProximitySensor*, WDSProximitySensorReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSProximitySensorReading*)getCurrentReading;
- (WDSProximitySensorDisplayOnOffController*)createDisplayOnOffController;
@end

#endif // __WDSProximitySensor_DEFINED__

// Windows.Devices.Sensors.ProximitySensorReading
#ifndef __WDSProximitySensorReading_DEFINED__
#define __WDSProximitySensorReading_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSProximitySensorReading : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) id /* unsigned int */ distanceInMillimeters;
@property (readonly) BOOL isDetected;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSProximitySensorReading_DEFINED__

// Windows.Devices.Sensors.ProximitySensorReadingChangedEventArgs
#ifndef __WDSProximitySensorReadingChangedEventArgs_DEFINED__
#define __WDSProximitySensorReadingChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSProximitySensorReadingChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSProximitySensorReading* reading;
@end

#endif // __WDSProximitySensorReadingChangedEventArgs_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Sensors.ProximitySensorDisplayOnOffController
#ifndef __WDSProximitySensorDisplayOnOffController_DEFINED__
#define __WDSProximitySensorDisplayOnOffController_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSProximitySensorDisplayOnOffController : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)close;
@end

#endif // __WDSProximitySensorDisplayOnOffController_DEFINED__

// Windows.Devices.Sensors.ProximitySensorDataThreshold
#ifndef __WDSProximitySensorDataThreshold_DEFINED__
#define __WDSProximitySensorDataThreshold_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSProximitySensorDataThreshold : RTObject <WDSISensorDataThreshold>
+ (WDSProximitySensorDataThreshold*)make:(WDSProximitySensor*)sensor ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WDSProximitySensorDataThreshold_DEFINED__

// Windows.Devices.Sensors.Altimeter
#ifndef __WDSAltimeter_DEFINED__
#define __WDSAltimeter_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSAltimeter : RTObject
+ (WDSAltimeter*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int reportInterval;
@property (readonly) NSString * deviceId;
@property (readonly) unsigned int minimumReportInterval;
@property unsigned int reportLatency;
@property (readonly) unsigned int maxBatchSize;
- (EventRegistrationToken)addReadingChangedEvent:(void(^)(WDSAltimeter*, WDSAltimeterReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSAltimeterReading*)getCurrentReading;
@end

#endif // __WDSAltimeter_DEFINED__

// Windows.Devices.Sensors.AltimeterReading
#ifndef __WDSAltimeterReading_DEFINED__
#define __WDSAltimeterReading_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSAltimeterReading : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) double altitudeChangeInMeters;
@property (readonly) WFDateTime* timestamp;
@property (readonly) id /* WFTimeSpan* */ performanceCount;
@property (readonly) NSDictionary* /* NSString *, RTObject* */ properties;
@end

#endif // __WDSAltimeterReading_DEFINED__

// Windows.Devices.Sensors.AltimeterReadingChangedEventArgs
#ifndef __WDSAltimeterReadingChangedEventArgs_DEFINED__
#define __WDSAltimeterReadingChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESSENSORSEXPORT
@interface WDSAltimeterReadingChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSAltimeterReading* reading;
@end

#endif // __WDSAltimeterReadingChangedEventArgs_DEFINED__

