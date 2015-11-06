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
    WDSOrientationSensorReadingChangedEventArgs, WDSSimpleOrientationSensor, WDSSimpleOrientationSensorOrientationChangedEventArgs;
@protocol WDSIAccelerometerStatics
, WDSIAccelerometer, WDSIAccelerometerReading, WDSIAccelerometerReadingChangedEventArgs, WDSIAccelerometerShakenEventArgs,
    WDSIInclinometerStatics, WDSIInclinometer, WDSIInclinometerReading, WDSIInclinometerReadingYawAccuracy,
    WDSIInclinometerReadingChangedEventArgs, WDSIGyrometerStatics, WDSIGyrometer, WDSIGyrometerReading,
    WDSIGyrometerReadingChangedEventArgs, WDSICompassStatics, WDSICompass, WDSICompassReading, WDSICompassReadingHeadingAccuracy,
    WDSICompassReadingChangedEventArgs, WDSILightSensorStatics, WDSILightSensor, WDSILightSensorReading,
    WDSILightSensorReadingChangedEventArgs, WDSISensorRotationMatrix, WDSISensorQuaternion, WDSIOrientationSensorStatics,
    WDSIOrientationSensor, WDSIOrientationSensorReading, WDSIOrientationSensorReadingYawAccuracy,
    WDSIOrientationSensorReadingChangedEventArgs, WDSISimpleOrientationSensorStatics, WDSISimpleOrientationSensor,
    WDSISimpleOrientationSensorOrientationChangedEventArgs;

// Windows.Devices.Sensors.MagnetometerAccuracy
enum _WDSMagnetometerAccuracy {
    WDSMagnetometerAccuracyUnknown = 0,
    WDSMagnetometerAccuracyUnreliable = 1,
    WDSMagnetometerAccuracyApproximate = 2,
    WDSMagnetometerAccuracyHigh = 3,
};
typedef unsigned WDSMagnetometerAccuracy;

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

#include "WindowsFoundation.h"

// Windows.Devices.Sensors.Accelerometer
#ifndef __WDSAccelerometer_DEFINED__
#define __WDSAccelerometer_DEFINED__

WINRT_EXPORT
@interface WDSAccelerometer : RTObject
+ (WDSAccelerometer*)getDefault;
@property unsigned reportInterval;
@property (readonly) unsigned minimumReportInterval;
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
+ (WDSInclinometer*)getDefault;
@property unsigned reportInterval;
@property (readonly) unsigned minimumReportInterval;
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
@property unsigned reportInterval;
@property (readonly) unsigned minimumReportInterval;
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
@property unsigned reportInterval;
@property (readonly) unsigned minimumReportInterval;
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
@property (readonly) WDSMagnetometerAccuracy headingAccuracy;
@property (readonly) double headingMagneticNorth;
@property (readonly) NSNumber* headingTrueNorth;
@property (readonly) WFDateTime* timestamp;
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
@property unsigned reportInterval;
@property (readonly) unsigned minimumReportInterval;
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
@property unsigned reportInterval;
@property (readonly) unsigned minimumReportInterval;
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
@property (readonly) WDSMagnetometerAccuracy yawAccuracy;
@property (readonly) WDSSensorQuaternion* quaternion;
@property (readonly) WDSSensorRotationMatrix* rotationMatrix;
@property (readonly) WFDateTime* timestamp;
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
