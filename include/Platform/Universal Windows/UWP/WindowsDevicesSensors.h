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

// WindowsDevicesSensors.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDSAccelerometer, WDSAccelerometerReading, WDSAccelerometerReadingChangedEventArgs, WDSAccelerometerShakenEventArgs, WDSInclinometer,
    WDSInclinometerReading, WDSInclinometerReadingChangedEventArgs, WDSGyrometer, WDSGyrometerReading, WDSGyrometerReadingChangedEventArgs,
    WDSCompass, WDSCompassReading, WDSCompassReadingChangedEventArgs, WDSLightSensor, WDSLightSensorReading,
    WDSLightSensorReadingChangedEventArgs, WDSSensorRotationMatrix, WDSSensorQuaternion, WDSOrientationSensor, WDSOrientationSensorReading,
    WDSOrientationSensorReadingChangedEventArgs, WDSSimpleOrientationSensor, WDSSimpleOrientationSensorOrientationChangedEventArgs,
    WDSMagnetometer, WDSMagnetometerReading, WDSMagnetometerReadingChangedEventArgs, WDSActivitySensor, WDSActivitySensorReading,
    WDSActivitySensorReadingChangedEventArgs, WDSActivitySensorReadingChangeReport, WDSActivitySensorTriggerDetails, WDSBarometer,
    WDSBarometerReading, WDSBarometerReadingChangedEventArgs, WDSPedometerReading, WDSPedometer, WDSPedometerReadingChangedEventArgs,
    WDSProximitySensor, WDSProximitySensorReading, WDSProximitySensorReadingChangedEventArgs, WDSProximitySensorDisplayOnOffController,
    WDSAltimeter, WDSAltimeterReading, WDSAltimeterReadingChangedEventArgs;
@protocol WDSIAccelerometerDeviceId
, WDSIAccelerometerStatics, WDSIAccelerometer, WDSIAccelerometer2, WDSIAccelerometer3, WDSIAccelerometerReading,
    WDSIAccelerometerReadingChangedEventArgs, WDSIAccelerometerShakenEventArgs, WDSIInclinometerDeviceId, WDSIInclinometerStatics,
    WDSIInclinometerStatics2, WDSIInclinometer, WDSIInclinometer2, WDSIInclinometerReading, WDSIInclinometerReadingYawAccuracy,
    WDSIInclinometerReadingChangedEventArgs, WDSIGyrometerDeviceId, WDSIGyrometerStatics, WDSIGyrometer, WDSIGyrometer2,
    WDSIGyrometerReading, WDSIGyrometerReadingChangedEventArgs, WDSICompassDeviceId, WDSICompassStatics, WDSICompass, WDSICompass2,
    WDSICompassReading, WDSICompassReadingHeadingAccuracy, WDSICompassReadingChangedEventArgs, WDSILightSensorDeviceId,
    WDSILightSensorStatics, WDSILightSensor, WDSILightSensorReading, WDSILightSensorReadingChangedEventArgs, WDSISensorRotationMatrix,
    WDSISensorQuaternion, WDSIOrientationSensorDeviceId, WDSIOrientationSensorStatics, WDSIOrientationSensorStatics2, WDSIOrientationSensor,
    WDSIOrientationSensor2, WDSIOrientationSensorReading, WDSIOrientationSensorReadingYawAccuracy,
    WDSIOrientationSensorReadingChangedEventArgs, WDSISimpleOrientationSensorDeviceId, WDSISimpleOrientationSensorStatics,
    WDSISimpleOrientationSensor, WDSISimpleOrientationSensor2, WDSISimpleOrientationSensorOrientationChangedEventArgs,
    WDSIMagnetometerDeviceId, WDSIMagnetometerStatics, WDSIMagnetometer, WDSIMagnetometer2, WDSIMagnetometerReading,
    WDSIMagnetometerReadingChangedEventArgs, WDSIActivitySensorStatics, WDSIActivitySensor, WDSIActivitySensorReading,
    WDSIActivitySensorReadingChangedEventArgs, WDSIActivitySensorReadingChangeReport, WDSIActivitySensorTriggerDetails,
    WDSIBarometerStatics, WDSIBarometer, WDSIBarometerReading, WDSIBarometerReadingChangedEventArgs, WDSIPedometerReading,
    WDSIPedometerReadingChangedEventArgs, WDSIPedometerStatics, WDSIPedometer, WDSIProximitySensorStatics, WDSIProximitySensor,
    WDSIProximitySensorReadingChangedEventArgs, WDSIProximitySensorReading, WDSIAltimeterStatics, WDSIAltimeter, WDSIAltimeterReading,
    WDSIAltimeterReadingChangedEventArgs;

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

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsGraphicsDisplay.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Sensors.Accelerometer
#ifndef __WDSAccelerometer_DEFINED__
#define __WDSAccelerometer_DEFINED__

WINRT_EXPORT
@interface WDSAccelerometer : RTObject
+ (WDSAccelerometer*)getDefault;
@property unsigned int reportInterval;
@property (readonly) unsigned int minimumReportInterval;
@property WGDDisplayOrientations readingTransform;
@property unsigned int reportLatency;
@property (readonly) unsigned int maxBatchSize;
@property (readonly) NSString* deviceId;
- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSAccelerometer*, WDSAccelerometerReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addShakenEvent:(void (^)(WDSAccelerometer*, WDSAccelerometerShakenEventArgs*))del;
- (void)removeShakenEvent:(EventRegistrationToken)tok;
- (WDSAccelerometerReading*)getCurrentReading;
@end

#endif // __WDSAccelerometer_DEFINED__

// Windows.Devices.Sensors.AccelerometerReading
#ifndef __WDSAccelerometerReading_DEFINED__
#define __WDSAccelerometerReading_DEFINED__

WINRT_EXPORT
@interface WDSAccelerometerReading : RTObject
@property (readonly) double accelerationX;
@property (readonly) double accelerationY;
@property (readonly) double accelerationZ;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSAccelerometerReading_DEFINED__

// Windows.Devices.Sensors.AccelerometerReadingChangedEventArgs
#ifndef __WDSAccelerometerReadingChangedEventArgs_DEFINED__
#define __WDSAccelerometerReadingChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSAccelerometerReadingChangedEventArgs : RTObject
@property (readonly) WDSAccelerometerReading* reading;
@end

#endif // __WDSAccelerometerReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.AccelerometerShakenEventArgs
#ifndef __WDSAccelerometerShakenEventArgs_DEFINED__
#define __WDSAccelerometerShakenEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSAccelerometerShakenEventArgs : RTObject
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSAccelerometerShakenEventArgs_DEFINED__

// Windows.Devices.Sensors.Inclinometer
#ifndef __WDSInclinometer_DEFINED__
#define __WDSInclinometer_DEFINED__

WINRT_EXPORT
@interface WDSInclinometer : RTObject
+ (WDSInclinometer*)getDefaultForRelativeReadings;
+ (WDSInclinometer*)getDefault;
@property unsigned int reportInterval;
@property (readonly) unsigned int minimumReportInterval;
@property WGDDisplayOrientations readingTransform;
@property (readonly) WDSSensorReadingType readingType;
@property (readonly) NSString* deviceId;
- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSInclinometer*, WDSInclinometerReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSInclinometerReading*)getCurrentReading;
@end

#endif // __WDSInclinometer_DEFINED__

// Windows.Devices.Sensors.InclinometerReading
#ifndef __WDSInclinometerReading_DEFINED__
#define __WDSInclinometerReading_DEFINED__

WINRT_EXPORT
@interface WDSInclinometerReading : RTObject
@property (readonly) float pitchDegrees;
@property (readonly) float rollDegrees;
@property (readonly) WFDateTime* timestamp;
@property (readonly) float yawDegrees;
@property (readonly) WDSMagnetometerAccuracy yawAccuracy;
@end

#endif // __WDSInclinometerReading_DEFINED__

// Windows.Devices.Sensors.InclinometerReadingChangedEventArgs
#ifndef __WDSInclinometerReadingChangedEventArgs_DEFINED__
#define __WDSInclinometerReadingChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSInclinometerReadingChangedEventArgs : RTObject
@property (readonly) WDSInclinometerReading* reading;
@end

#endif // __WDSInclinometerReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.Gyrometer
#ifndef __WDSGyrometer_DEFINED__
#define __WDSGyrometer_DEFINED__

WINRT_EXPORT
@interface WDSGyrometer : RTObject
+ (WDSGyrometer*)getDefault;
@property unsigned int reportInterval;
@property (readonly) unsigned int minimumReportInterval;
@property WGDDisplayOrientations readingTransform;
@property (readonly) NSString* deviceId;
- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSGyrometer*, WDSGyrometerReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSGyrometerReading*)getCurrentReading;
@end

#endif // __WDSGyrometer_DEFINED__

// Windows.Devices.Sensors.GyrometerReading
#ifndef __WDSGyrometerReading_DEFINED__
#define __WDSGyrometerReading_DEFINED__

WINRT_EXPORT
@interface WDSGyrometerReading : RTObject
@property (readonly) double angularVelocityX;
@property (readonly) double angularVelocityY;
@property (readonly) double angularVelocityZ;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSGyrometerReading_DEFINED__

// Windows.Devices.Sensors.GyrometerReadingChangedEventArgs
#ifndef __WDSGyrometerReadingChangedEventArgs_DEFINED__
#define __WDSGyrometerReadingChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSGyrometerReadingChangedEventArgs : RTObject
@property (readonly) WDSGyrometerReading* reading;
@end

#endif // __WDSGyrometerReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.Compass
#ifndef __WDSCompass_DEFINED__
#define __WDSCompass_DEFINED__

WINRT_EXPORT
@interface WDSCompass : RTObject
+ (WDSCompass*)getDefault;
@property unsigned int reportInterval;
@property (readonly) unsigned int minimumReportInterval;
@property WGDDisplayOrientations readingTransform;
@property (readonly) NSString* deviceId;
- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSCompass*, WDSCompassReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSCompassReading*)getCurrentReading;
@end

#endif // __WDSCompass_DEFINED__

// Windows.Devices.Sensors.CompassReading
#ifndef __WDSCompassReading_DEFINED__
#define __WDSCompassReading_DEFINED__

WINRT_EXPORT
@interface WDSCompassReading : RTObject
@property (readonly) double headingMagneticNorth;
@property (readonly) id headingTrueNorth;
@property (readonly) WFDateTime* timestamp;
@property (readonly) WDSMagnetometerAccuracy headingAccuracy;
@end

#endif // __WDSCompassReading_DEFINED__

// Windows.Devices.Sensors.CompassReadingChangedEventArgs
#ifndef __WDSCompassReadingChangedEventArgs_DEFINED__
#define __WDSCompassReadingChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSCompassReadingChangedEventArgs : RTObject
@property (readonly) WDSCompassReading* reading;
@end

#endif // __WDSCompassReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.LightSensor
#ifndef __WDSLightSensor_DEFINED__
#define __WDSLightSensor_DEFINED__

WINRT_EXPORT
@interface WDSLightSensor : RTObject
+ (WDSLightSensor*)getDefault;
@property unsigned int reportInterval;
@property (readonly) unsigned int minimumReportInterval;
@property (readonly) NSString* deviceId;
- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSLightSensor*, WDSLightSensorReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSLightSensorReading*)getCurrentReading;
@end

#endif // __WDSLightSensor_DEFINED__

// Windows.Devices.Sensors.LightSensorReading
#ifndef __WDSLightSensorReading_DEFINED__
#define __WDSLightSensorReading_DEFINED__

WINRT_EXPORT
@interface WDSLightSensorReading : RTObject
@property (readonly) float illuminanceInLux;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSLightSensorReading_DEFINED__

// Windows.Devices.Sensors.LightSensorReadingChangedEventArgs
#ifndef __WDSLightSensorReadingChangedEventArgs_DEFINED__
#define __WDSLightSensorReadingChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSLightSensorReadingChangedEventArgs : RTObject
@property (readonly) WDSLightSensorReading* reading;
@end

#endif // __WDSLightSensorReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.SensorRotationMatrix
#ifndef __WDSSensorRotationMatrix_DEFINED__
#define __WDSSensorRotationMatrix_DEFINED__

WINRT_EXPORT
@interface WDSSensorRotationMatrix : RTObject
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

WINRT_EXPORT
@interface WDSSensorQuaternion : RTObject
@property (readonly) float w;
@property (readonly) float x;
@property (readonly) float y;
@property (readonly) float z;
@end

#endif // __WDSSensorQuaternion_DEFINED__

// Windows.Devices.Sensors.OrientationSensor
#ifndef __WDSOrientationSensor_DEFINED__
#define __WDSOrientationSensor_DEFINED__

WINRT_EXPORT
@interface WDSOrientationSensor : RTObject
+ (WDSOrientationSensor*)getDefault;
+ (WDSOrientationSensor*)getDefaultForRelativeReadings;
@property unsigned int reportInterval;
@property (readonly) unsigned int minimumReportInterval;
@property WGDDisplayOrientations readingTransform;
@property (readonly) WDSSensorReadingType readingType;
@property (readonly) NSString* deviceId;
- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSOrientationSensor*, WDSOrientationSensorReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSOrientationSensorReading*)getCurrentReading;
@end

#endif // __WDSOrientationSensor_DEFINED__

// Windows.Devices.Sensors.OrientationSensorReading
#ifndef __WDSOrientationSensorReading_DEFINED__
#define __WDSOrientationSensorReading_DEFINED__

WINRT_EXPORT
@interface WDSOrientationSensorReading : RTObject
@property (readonly) WDSSensorQuaternion* quaternion;
@property (readonly) WDSSensorRotationMatrix* rotationMatrix;
@property (readonly) WFDateTime* timestamp;
@property (readonly) WDSMagnetometerAccuracy yawAccuracy;
@end

#endif // __WDSOrientationSensorReading_DEFINED__

// Windows.Devices.Sensors.OrientationSensorReadingChangedEventArgs
#ifndef __WDSOrientationSensorReadingChangedEventArgs_DEFINED__
#define __WDSOrientationSensorReadingChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSOrientationSensorReadingChangedEventArgs : RTObject
@property (readonly) WDSOrientationSensorReading* reading;
@end

#endif // __WDSOrientationSensorReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.SimpleOrientationSensor
#ifndef __WDSSimpleOrientationSensor_DEFINED__
#define __WDSSimpleOrientationSensor_DEFINED__

WINRT_EXPORT
@interface WDSSimpleOrientationSensor : RTObject
+ (WDSSimpleOrientationSensor*)getDefault;
@property WGDDisplayOrientations readingTransform;
@property (readonly) NSString* deviceId;
- (EventRegistrationToken)addOrientationChangedEvent:(void (^)(WDSSimpleOrientationSensor*,
                                                               WDSSimpleOrientationSensorOrientationChangedEventArgs*))del;
- (void)removeOrientationChangedEvent:(EventRegistrationToken)tok;
- (WDSSimpleOrientation)getCurrentOrientation;
@end

#endif // __WDSSimpleOrientationSensor_DEFINED__

// Windows.Devices.Sensors.SimpleOrientationSensorOrientationChangedEventArgs
#ifndef __WDSSimpleOrientationSensorOrientationChangedEventArgs_DEFINED__
#define __WDSSimpleOrientationSensorOrientationChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSSimpleOrientationSensorOrientationChangedEventArgs : RTObject
@property (readonly) WDSSimpleOrientation orientation;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSSimpleOrientationSensorOrientationChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.Magnetometer
#ifndef __WDSMagnetometer_DEFINED__
#define __WDSMagnetometer_DEFINED__

WINRT_EXPORT
@interface WDSMagnetometer : RTObject
+ (WDSMagnetometer*)getDefault;
@property unsigned int reportInterval;
@property (readonly) unsigned int minimumReportInterval;
@property WGDDisplayOrientations readingTransform;
@property (readonly) NSString* deviceId;
- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSMagnetometer*, WDSMagnetometerReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSMagnetometerReading*)getCurrentReading;
@end

#endif // __WDSMagnetometer_DEFINED__

// Windows.Devices.Sensors.MagnetometerReading
#ifndef __WDSMagnetometerReading_DEFINED__
#define __WDSMagnetometerReading_DEFINED__

WINRT_EXPORT
@interface WDSMagnetometerReading : RTObject
@property (readonly) WDSMagnetometerAccuracy directionalAccuracy;
@property (readonly) float magneticFieldX;
@property (readonly) float magneticFieldY;
@property (readonly) float magneticFieldZ;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSMagnetometerReading_DEFINED__

// Windows.Devices.Sensors.MagnetometerReadingChangedEventArgs
#ifndef __WDSMagnetometerReadingChangedEventArgs_DEFINED__
#define __WDSMagnetometerReadingChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSMagnetometerReadingChangedEventArgs : RTObject
@property (readonly) WDSMagnetometerReading* reading;
@end

#endif // __WDSMagnetometerReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.ActivitySensor
#ifndef __WDSActivitySensor_DEFINED__
#define __WDSActivitySensor_DEFINED__

WINRT_EXPORT
@interface WDSActivitySensor : RTObject
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDSActivitySensor*))success failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelector;
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDSActivitySensor*))success failure:(void (^)(NSError*))failure;
+ (void)getSystemHistoryAsync:(WFDateTime*)fromTime success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (void)getSystemHistoryWithDurationAsync:(WFDateTime*)fromTime
                                 duration:(WFTimeSpan*)duration
                                  success:(void (^)(NSArray*))success
                                  failure:(void (^)(NSError*))failure;
@property (readonly) NSString* deviceId;
@property (readonly) unsigned int minimumReportInterval;
@property (readonly) double powerInMilliwatts;
@property (readonly) NSMutableArray* subscribedActivities;
@property (readonly) NSArray* supportedActivities;
- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSActivitySensor*, WDSActivitySensorReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (void)getCurrentReadingAsyncWithSuccess:(void (^)(WDSActivitySensorReading*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDSActivitySensor_DEFINED__

// Windows.Devices.Sensors.ActivitySensorReading
#ifndef __WDSActivitySensorReading_DEFINED__
#define __WDSActivitySensorReading_DEFINED__

WINRT_EXPORT
@interface WDSActivitySensorReading : RTObject
@property (readonly) WDSActivityType activity;
@property (readonly) WDSActivitySensorReadingConfidence confidence;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSActivitySensorReading_DEFINED__

// Windows.Devices.Sensors.ActivitySensorReadingChangedEventArgs
#ifndef __WDSActivitySensorReadingChangedEventArgs_DEFINED__
#define __WDSActivitySensorReadingChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSActivitySensorReadingChangedEventArgs : RTObject
@property (readonly) WDSActivitySensorReading* reading;
@end

#endif // __WDSActivitySensorReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.ActivitySensorReadingChangeReport
#ifndef __WDSActivitySensorReadingChangeReport_DEFINED__
#define __WDSActivitySensorReadingChangeReport_DEFINED__

WINRT_EXPORT
@interface WDSActivitySensorReadingChangeReport : RTObject
@property (readonly) WDSActivitySensorReading* reading;
@end

#endif // __WDSActivitySensorReadingChangeReport_DEFINED__

// Windows.Devices.Sensors.ActivitySensorTriggerDetails
#ifndef __WDSActivitySensorTriggerDetails_DEFINED__
#define __WDSActivitySensorTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WDSActivitySensorTriggerDetails : RTObject
- (NSArray*)readReports;
@end

#endif // __WDSActivitySensorTriggerDetails_DEFINED__

// Windows.Devices.Sensors.Barometer
#ifndef __WDSBarometer_DEFINED__
#define __WDSBarometer_DEFINED__

WINRT_EXPORT
@interface WDSBarometer : RTObject
+ (WDSBarometer*)getDefault;
@property unsigned int reportInterval;
@property (readonly) NSString* deviceId;
@property (readonly) unsigned int minimumReportInterval;
- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSBarometer*, WDSBarometerReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSBarometerReading*)getCurrentReading;
@end

#endif // __WDSBarometer_DEFINED__

// Windows.Devices.Sensors.BarometerReading
#ifndef __WDSBarometerReading_DEFINED__
#define __WDSBarometerReading_DEFINED__

WINRT_EXPORT
@interface WDSBarometerReading : RTObject
@property (readonly) double stationPressureInHectopascals;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSBarometerReading_DEFINED__

// Windows.Devices.Sensors.BarometerReadingChangedEventArgs
#ifndef __WDSBarometerReadingChangedEventArgs_DEFINED__
#define __WDSBarometerReadingChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSBarometerReadingChangedEventArgs : RTObject
@property (readonly) WDSBarometerReading* reading;
@end

#endif // __WDSBarometerReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.PedometerReading
#ifndef __WDSPedometerReading_DEFINED__
#define __WDSPedometerReading_DEFINED__

WINRT_EXPORT
@interface WDSPedometerReading : RTObject
@property (readonly) int cumulativeSteps;
@property (readonly) WFTimeSpan* cumulativeStepsDuration;
@property (readonly) WDSPedometerStepKind stepKind;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSPedometerReading_DEFINED__

// Windows.Devices.Sensors.Pedometer
#ifndef __WDSPedometer_DEFINED__
#define __WDSPedometer_DEFINED__

WINRT_EXPORT
@interface WDSPedometer : RTObject
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDSPedometer*))success failure:(void (^)(NSError*))failure;
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDSPedometer*))success failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelector;
+ (void)getSystemHistoryAsync:(WFDateTime*)fromTime success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (void)getSystemHistoryWithDurationAsync:(WFDateTime*)fromTime
                                 duration:(WFTimeSpan*)duration
                                  success:(void (^)(NSArray*))success
                                  failure:(void (^)(NSError*))failure;
@property unsigned int reportInterval;
@property (readonly) NSString* deviceId;
@property (readonly) unsigned int minimumReportInterval;
@property (readonly) double powerInMilliwatts;
- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSPedometer*, WDSPedometerReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WDSPedometer_DEFINED__

// Windows.Devices.Sensors.PedometerReadingChangedEventArgs
#ifndef __WDSPedometerReadingChangedEventArgs_DEFINED__
#define __WDSPedometerReadingChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSPedometerReadingChangedEventArgs : RTObject
@property (readonly) WDSPedometerReading* reading;
@end

#endif // __WDSPedometerReadingChangedEventArgs_DEFINED__

// Windows.Devices.Sensors.ProximitySensor
#ifndef __WDSProximitySensor_DEFINED__
#define __WDSProximitySensor_DEFINED__

WINRT_EXPORT
@interface WDSProximitySensor : RTObject
+ (NSString*)getDeviceSelector;
+ (WDSProximitySensor*)fromId:(NSString*)sensorId;
@property (readonly) NSString* deviceId;
@property (readonly) id maxDistanceInMillimeters;
@property (readonly) id minDistanceInMillimeters;
- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSProximitySensor*, WDSProximitySensorReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSProximitySensorReading*)getCurrentReading;
- (WDSProximitySensorDisplayOnOffController*)createDisplayOnOffController;
@end

#endif // __WDSProximitySensor_DEFINED__

// Windows.Devices.Sensors.ProximitySensorReading
#ifndef __WDSProximitySensorReading_DEFINED__
#define __WDSProximitySensorReading_DEFINED__

WINRT_EXPORT
@interface WDSProximitySensorReading : RTObject
@property (readonly) id distanceInMillimeters;
@property (readonly) BOOL isDetected;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSProximitySensorReading_DEFINED__

// Windows.Devices.Sensors.ProximitySensorReadingChangedEventArgs
#ifndef __WDSProximitySensorReadingChangedEventArgs_DEFINED__
#define __WDSProximitySensorReadingChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSProximitySensorReadingChangedEventArgs : RTObject
@property (readonly) WDSProximitySensorReading* reading;
@end

#endif // __WDSProximitySensorReadingChangedEventArgs_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Sensors.ProximitySensorDisplayOnOffController
#ifndef __WDSProximitySensorDisplayOnOffController_DEFINED__
#define __WDSProximitySensorDisplayOnOffController_DEFINED__

WINRT_EXPORT
@interface WDSProximitySensorDisplayOnOffController : RTObject <WFIClosable>
- (void)close;
@end

#endif // __WDSProximitySensorDisplayOnOffController_DEFINED__

// Windows.Devices.Sensors.Altimeter
#ifndef __WDSAltimeter_DEFINED__
#define __WDSAltimeter_DEFINED__

WINRT_EXPORT
@interface WDSAltimeter : RTObject
+ (WDSAltimeter*)getDefault;
@property unsigned int reportInterval;
@property (readonly) NSString* deviceId;
@property (readonly) unsigned int minimumReportInterval;
- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSAltimeter*, WDSAltimeterReadingChangedEventArgs*))del;
- (void)removeReadingChangedEvent:(EventRegistrationToken)tok;
- (WDSAltimeterReading*)getCurrentReading;
@end

#endif // __WDSAltimeter_DEFINED__

// Windows.Devices.Sensors.AltimeterReading
#ifndef __WDSAltimeterReading_DEFINED__
#define __WDSAltimeterReading_DEFINED__

WINRT_EXPORT
@interface WDSAltimeterReading : RTObject
@property (readonly) double altitudeChangeInMeters;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDSAltimeterReading_DEFINED__

// Windows.Devices.Sensors.AltimeterReadingChangedEventArgs
#ifndef __WDSAltimeterReadingChangedEventArgs_DEFINED__
#define __WDSAltimeterReadingChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDSAltimeterReadingChangedEventArgs : RTObject
@property (readonly) WDSAltimeterReading* reading;
@end

#endif // __WDSAltimeterReadingChangedEventArgs_DEFINED__
