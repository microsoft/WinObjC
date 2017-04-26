//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <CoreMotion/CoreMotion.h>
#import <StubReturn.h>
#import <NSLogging.h>
#import <chrono>
#import "CMMotionManagerInternal.h"
#import "UWP/WindowsGraphicsDisplay.h"
#import "windows.h"
#import "CppWinRTHelpers.h"

#include "COMIncludes.h"
#import <winrt/Windows.Foundation.h>
#import <winrt/Windows.Graphics.Display.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::Devices::Sensors;
using namespace winrt::Windows::Graphics::Display;
namespace WF = winrt::Windows::Foundation;

// iOS uses (double)seconds while WinRT uses (uint)milliseconds. Thus (double)c_secondToMilliseconds for conversions.
static const double c_secondToMilliseconds = 1000.0;

// For gyrometer values iOS uses unit as radians per sec. while WinRT uses degrees per sec.
static const double c_degreeToRadian = M_PI / 180;

// For converting quaternion from landscape to portrait reference frame.
static const double c_cos45 = cos(-45 * c_degreeToRadian);

static WF::DateTime _bootTime;

// Converting from WF::DateTime to number of seconds passed since the devices booted.
inline double toSecondsSinceBoot(const WF::DateTime& time) {
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(time - _bootTime);
    return millis.count() / c_secondToMilliseconds;
}

static const wchar_t* TAG = L"CMMotionManager";
NSString* const CMErrorDomain = @"CMErrorDomain";

@interface CMMotionManager ()

@property winrt::event_token accelerometerToken;
@property NSOperationQueue* accelerometerQueue;
@property (readwrite, nonatomic, getter=isAccelerometerActive) BOOL accelerometerActive;
@property (readwrite, nonatomic, getter=isAccelerometerAvailable) BOOL accelerometerAvailable;
@property (readwrite) CMAccelerometerData* accelerometerData;

@property winrt::event_token gyrometerToken;
@property NSOperationQueue* gyroQueue;
@property (readwrite, nonatomic, getter=isGyroActive) BOOL gyroActive;
@property (readwrite, nonatomic, getter=isGyroAvailable) BOOL gyroAvailable;
@property (readwrite) CMGyroData* gyroData;

@property winrt::event_token magnetometerToken;
@property NSOperationQueue* magnetometerQueue;
@property (readwrite, nonatomic, getter=isMagnetometerActive) BOOL magnetometerActive;
@property (readwrite, nonatomic, getter=isMagnetometerAvailable) BOOL magnetometerAvailable;
@property (readwrite) CMMagnetometerData* magnetometerData;

// The orientation sensors returns rotation matrix and quaternion.
// We will use the rotation matrix to calculate pitch, roll and yaw values.
@property winrt::event_token deviceMotionToken;
@property NSOperationQueue* deviceMotionQueue;
@property (readwrite, nonatomic, getter=isDeviceMotionActive) BOOL deviceMotionActive;
@property (readwrite, nonatomic, getter=isDeviceMotionAvailable) BOOL deviceMotionAvailable;
@property (readwrite) CMDeviceMotion* deviceMotion;

@end

@implementation CMMotionManager {
    TrivialDefaultConstructor<Accelerometer> _accelerometer;
    TrivialDefaultConstructor<Gyrometer> _gyrometer;
    TrivialDefaultConstructor<Magnetometer> _magnetometer;
    TrivialDefaultConstructor<OrientationSensor> _orientation;
}

- (instancetype)init {
    if (self = [super init]) {
        // GetTickCount64() returns the number of milliseconds passed since device boot
        ULONGLONG ticks = GetTickCount64();
        _bootTime = winrt::clock::now() - std::chrono::milliseconds(ticks);

        _accelerometer = Accelerometer::GetDefault();
        _accelerometerActive = false;

        if (_accelerometer) {
            _accelerometerAvailable = true;

            // The ref. frame is portrait-mode for iOS, while it is different across devices running Windows.
            _accelerometer.ReadingTransform(DisplayOrientations::Portrait);
        } else {
            _accelerometerAvailable = false;
            NSTraceInfo(TAG, @"Accelerometer not found!");
        }

        _gyrometer = Gyrometer::GetDefault();
        _gyroActive = false;

        if (_gyrometer) {
            _gyroAvailable = true;

            // The ref. frame is portrait-mode for iOS, while it is different across devices running Windows.
            _gyrometer.ReadingTransform(DisplayOrientations::Portrait);
        } else {
            _gyroAvailable = false;
            NSTraceInfo(TAG, @"Gyrometer not found!");
        }

        _magnetometer = Magnetometer::GetDefault();
        _magnetometerActive = false;

        if (_magnetometer) {
            _magnetometerAvailable = true;

            // The ref. frame is portrait-mode for iOS, while it is different across devices running Windows.
            _magnetometer.ReadingTransform(DisplayOrientations::Portrait);
        } else {
            _magnetometerAvailable = false;
            NSTraceInfo(TAG, @"Magnetometer not found!");
        }

        _orientation = OrientationSensor::GetDefault();
        _deviceMotionActive = false;

        if (_orientation) {
            _deviceMotionAvailable = true;

            // The range for pitch and roll is different (and swapped) across iOS and WinRT.
            // Hence we set the reference orientation to landscape and then swap the readings to match iOS behaviour.
            _orientation.ReadingTransform(DisplayOrientations::Landscape);
        } else {
            _deviceMotionAvailable = false;
            NSTraceInfo(TAG, @"DeviceMotion not found!");
        }
    }

    return self;
}

// We convert the reference frame from landscape orientation to portrait orientation.
// Conversion is based on  https://msdn.microsoft.com/en-us/library/windows/apps/dn440593.aspx
// For the quaternion conversion we assume the x and y component of Qref are zero.
// For roll and pitch we swap the values.
+ (CMAttitude*)toAttitude:(const SensorRotationMatrix&)rm quaternion:(const SensorQuaternion&)q {
    CMRotationMatrix rotationMatrix = { rm.M21(), rm.M22(), rm.M23(), -rm.M11(), -rm.M12(), -rm.M13(), rm.M31(), rm.M32(), rm.M33() };

    CMQuaternion quaternion = { (q.X() + q.Y()) * c_cos45, (-q.X() + q.Y()) * c_cos45, (q.Z() - q.W()) * c_cos45, (q.Z() + q.W()) * c_cos45 };

    CMAttitude* attitude = [[CMAttitude alloc] initWithValues:-atan2(rm.M32(), rm.M33())
                                                        pitch:atan2(-rm.M31(), sqrt(rm.M32() * rm.M32() + rm.M33() * rm.M33()))
                                                          yaw:atan2(-rm.M11(), rm.M21())
                                               rotationMatrix:rotationMatrix
                                                   quaternion:quaternion];
    return attitude;
}

/**
 @Status Interoperable
 @Notes
*/
- (void)startAccelerometerUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMAccelerometerHandler)handler {
    if (self.accelerometerAvailable) {
        [self startAccelerometerUpdates];
        self.accelerometerQueue = queue;

        self.accelerometerToken =
            _accelerometer.ReadingChanged(objcwinrt::callback([queue, handler] (const Accelerometer& sender, const AccelerometerReadingChangedEventArgs& e) {
                AccelerometerReading reading = e.Reading();

                CMAccelerometerData* data = [[CMAccelerometerData alloc] initWithValues:reading.AccelerationX()
                                                                                      y:reading.AccelerationY()
                                                                                      z:reading.AccelerationZ()
                                                                                   time:toSecondsSinceBoot(reading.Timestamp())];

                [queue addOperationWithBlock:^{
                    handler(data, nil);
                }];
            }));
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (void)startAccelerometerUpdates {
    @synchronized(self) {
        if (self.accelerometerAvailable) {
            if (self.accelerometerActive) {
                [self stopAccelerometerUpdates];
            }

            self.accelerometerActive = true;
            _accelerometer.ReportInterval(static_cast<unsigned int>(self.accelerometerUpdateInterval * c_secondToMilliseconds));
        }
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (void)stopAccelerometerUpdates {
    @synchronized(self) {
        if (self.accelerometerActive) {
            self.accelerometerActive = false;

            // the reportInterval is set to 0, the default value.
            _accelerometer.ReportInterval(0);

            if (self.accelerometerToken.value != 0) {
                _accelerometer.ReadingChanged(self.accelerometerToken);
                self.accelerometerToken = {};
            }

            if (self.accelerometerQueue) {
                [self.accelerometerQueue cancelAllOperations];
                self.accelerometerQueue = nil;
            }
        }
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (CMAccelerometerData*)accelerometerData {
    if (!self.isAccelerometerAvailable) {
        return nil;
    }

    AccelerometerReading reading = _accelerometer.GetCurrentReading();

    _accelerometerData = [[CMAccelerometerData alloc] initWithValues:reading.AccelerationX()
                                                                   y:reading.AccelerationY()
                                                                   z:reading.AccelerationZ()
                                                                time:toSecondsSinceBoot(reading.Timestamp())];
    return _accelerometerData;
}

- (void)setAccelerometerUpdateInterval:(NSTimeInterval)updateInterval {
    @synchronized(self) {
        if (self.isAccelerometerAvailable) {
            // iOS uses seconds while WinRT uses milliseconds, hence the multiplication/division by c_secondToMilliseconds
            if (updateInterval * c_secondToMilliseconds < _accelerometer.MinimumReportInterval()) {
                _accelerometerUpdateInterval = _accelerometer.MinimumReportInterval() / c_secondToMilliseconds;
                _accelerometer.ReportInterval(_accelerometer.MinimumReportInterval());
                NSTraceInfo(TAG, @"accelerometerUpdateInterval capped to minimum supported value: %g", _accelerometerUpdateInterval);
            } else {
                _accelerometerUpdateInterval = updateInterval;
                _accelerometer.ReportInterval(static_cast<unsigned int>(_accelerometerUpdateInterval * c_secondToMilliseconds));
            }
        }
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (void)startGyroUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMGyroHandler)handler {
    if (self.gyroAvailable) {
        [self startGyroUpdates];
        self.gyroQueue = queue;

        self.gyrometerToken = _gyrometer.ReadingChanged(objcwinrt::callback([queue, handler] (const Gyrometer& sender, const GyrometerReadingChangedEventArgs& e) {
            GyrometerReading reading = e.Reading();

            // For gyrometer values iOS uses unit as radians per sec. while WinRT uses degrees per sec.
            CMGyroData* data = [[CMGyroData alloc] initWithValues:reading.AngularVelocityX() * c_degreeToRadian
                                                                y:reading.AngularVelocityY() * c_degreeToRadian
                                                                z:reading.AngularVelocityZ() * c_degreeToRadian
                                                             time:toSecondsSinceBoot(reading.Timestamp())];

            [queue addOperationWithBlock:^{
                handler(data, nil);
            }];
        }));
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (void)startGyroUpdates {
    @synchronized(self) {
        if (self.gyroAvailable) {
            if (self.gyroActive) {
                [self stopGyroUpdates];
            }

            self.gyroActive = true;
            _gyrometer.ReportInterval(static_cast<unsigned int>(self.gyroUpdateInterval * c_secondToMilliseconds));
        }
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (void)stopGyroUpdates {
    @synchronized(self) {
        if (self.gyroActive) {
            self.gyroActive = false;

            // the reportInterval is set to 0, the default value.
            _gyrometer.ReportInterval(0);

            if (self.gyrometerToken.value != 0) {
                _gyrometer.ReadingChanged(self.gyrometerToken);
                self.gyrometerToken = {};
            }

            if (self.gyroQueue) {
                [self.gyroQueue cancelAllOperations];
                self.gyroQueue = nil;
            }
        }
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (CMGyroData*)gyroData {
    if (!self.isGyroAvailable) {
        return nil;
    }

    GyrometerReading reading = _gyrometer.GetCurrentReading();

    // For gyrometer values iOS uses unit as radians per sec. while WinRT uses degrees per sec.
    _gyroData = [[CMGyroData alloc] initWithValues:reading.AngularVelocityX() * c_degreeToRadian
                                                 y:reading.AngularVelocityY() * c_degreeToRadian
                                                 z:reading.AngularVelocityZ() * c_degreeToRadian
                                              time:toSecondsSinceBoot(reading.Timestamp())];
    return _gyroData;
}

- (void)setGyroUpdateInterval:(NSTimeInterval)updateInterval {
    @synchronized(self) {
        if (self.isGyroAvailable) {
            // iOS uses seconds while WinRT uses milliseconds, hence the multiplication/division by c_secondToMilliseconds
            if (updateInterval * c_secondToMilliseconds < _gyrometer.MinimumReportInterval()) {
                _gyroUpdateInterval = _gyrometer.MinimumReportInterval() / c_secondToMilliseconds;
                _gyrometer.ReportInterval(_gyrometer.MinimumReportInterval());
                NSTraceInfo(TAG, @"gyroUpdateInterval capped to minimum supported value: %g", _gyroUpdateInterval);
            } else {
                _gyroUpdateInterval = updateInterval;
                _gyrometer.ReportInterval(static_cast<unsigned int>(_gyroUpdateInterval * c_secondToMilliseconds));
            }
        }
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (void)startMagnetometerUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMMagnetometerHandler)handler {
    if (self.magnetometerAvailable) {
        [self startMagnetometerUpdates];
        self.magnetometerQueue = queue;

        self.magnetometerToken =
            _magnetometer.ReadingChanged(objcwinrt::callback([queue, handler] (const Magnetometer& sender, const MagnetometerReadingChangedEventArgs& e) {
                MagnetometerReading reading = e.Reading();

                CMMagnetometerData* data = [[CMMagnetometerData alloc] initWithValues:reading.MagneticFieldX()
                                                                                    y:reading.MagneticFieldY()
                                                                                    z:reading.MagneticFieldZ()
                                                                                 time:toSecondsSinceBoot(reading.Timestamp())];

                [queue addOperationWithBlock:^{
                    handler(data, nil);
                }];
            }));
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (void)startMagnetometerUpdates {
    @synchronized(self) {
        if (self.magnetometerAvailable) {
            if (self.magnetometerActive) {
                [self stopMagnetometerUpdates];
            }

            self.magnetometerActive = true;

            _magnetometer.ReportInterval(static_cast<unsigned int>(self.magnetometerUpdateInterval * c_secondToMilliseconds));
        }
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (void)stopMagnetometerUpdates {
    @synchronized(self) {
        if (self.magnetometerActive) {
            self.magnetometerActive = false;

            // the reportInterval is set to 0, the default value.
            _magnetometer.ReportInterval(0);

            if (self.magnetometerToken.value != 0) {
                _magnetometer.ReadingChanged(self.magnetometerToken);
                self.magnetometerToken = {};
            }

            if (self.magnetometerQueue) {
                [self.magnetometerQueue cancelAllOperations];
                self.magnetometerQueue = nil;
            }
        }
    }
}

/**
@Status Interoperable
@Notes
*/
- (CMMagnetometerData*)magnetometerData {
    if (!self.isMagnetometerAvailable) {
        return nil;
    }

    MagnetometerReading reading = _magnetometer.GetCurrentReading();

    _magnetometerData = [[CMMagnetometerData alloc] initWithValues:reading.MagneticFieldX()
                                                                 y:reading.MagneticFieldY()
                                                                 z:reading.MagneticFieldZ()
                                                              time:toSecondsSinceBoot(reading.Timestamp())];
    return _magnetometerData;
}

- (void)setMagnetometerUpdateInterval:(NSTimeInterval)updateInterval {
    @synchronized(self) {
        if (self.isMagnetometerAvailable) {
            // iOS uses seconds while WinRT uses milliseconds, hence the multiplication/division by c_secondToMilliseconds
            if (updateInterval * c_secondToMilliseconds < _magnetometer.MinimumReportInterval()) {
                _magnetometerUpdateInterval = _magnetometer.MinimumReportInterval() / c_secondToMilliseconds;
                _magnetometer.ReportInterval(_magnetometer.MinimumReportInterval());
                NSTraceInfo(TAG, @"magnetometerUpdateInterval capped to minimum supported value: %g", _magnetometerUpdateInterval);
            } else {
                _magnetometerUpdateInterval = updateInterval;
                _magnetometer.ReportInterval(static_cast<unsigned int>(_magnetometerUpdateInterval * c_secondToMilliseconds));
            }
        }
    }
}

/**
 @Status Stub
 @Notes
*/
- (void)startDeviceMotionUpdatesUsingReferenceFrame:(CMAttitudeReferenceFrame)referenceFrame
                                            toQueue:(NSOperationQueue*)queue
                                        withHandler:(CMDeviceMotionHandler)handler {
    UNIMPLEMENTED();
}

/**
 @Status Caveat
 @Notes Only attitude property is supported currently.
*/
- (void)startDeviceMotionUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMDeviceMotionHandler)handler {
    if (self.deviceMotionAvailable) {
        [self startDeviceMotionUpdates];
        self.deviceMotionQueue = queue;

        self.deviceMotionToken =
            _orientation.ReadingChanged(objcwinrt::callback([queue, handler] (const OrientationSensor& sender, const OrientationSensorReadingChangedEventArgs& e) {
                OrientationSensorReading reading = e.Reading();

                CMDeviceMotion* deviceMotion =
                    [[CMDeviceMotion alloc] initWithValues:[CMMotionManager toAttitude:reading.RotationMatrix() quaternion:reading.Quaternion()]
                                                      time:toSecondsSinceBoot(reading.Timestamp())];
                [queue addOperationWithBlock:^{
                    handler(deviceMotion, nil);
                }];
            }));
    }
}

/**
 @Status Stub
 @Notes
*/
- (void)startDeviceMotionUpdatesUsingReferenceFrame:(CMAttitudeReferenceFrame)referenceFrame {
    UNIMPLEMENTED();
}

/**
 @Status Caveat
 @Notes Only attitude property is supported currently.
*/
- (void)startDeviceMotionUpdates {
    @synchronized(self) {
        if (self.deviceMotionAvailable) {
            if (self.deviceMotionActive) {
                [self stopDeviceMotionUpdates];
            }

            self.deviceMotionActive = true;
            _orientation.ReportInterval(static_cast<unsigned int>(self.deviceMotionUpdateInterval * c_secondToMilliseconds));
        }
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (void)stopDeviceMotionUpdates {
    @synchronized(self) {
        if (self.deviceMotionAvailable) {
            self.deviceMotionActive = false;

            // the reportInterval is set to 0, the default value.
            _orientation.ReportInterval(0);

            if (self.deviceMotionToken.value != 0) {
                _orientation.ReadingChanged(self.deviceMotionToken);
                self.deviceMotionToken = {};
            }

            if (self.deviceMotionQueue) {
                [self.deviceMotionQueue cancelAllOperations];
                self.deviceMotionQueue = nil;
            }
        }
    }
}

/**
 @Status Caveat
 @Notes Only attitude property is supported currently.
*/
- (CMDeviceMotion*)deviceMotion {
    if (!self.isDeviceMotionAvailable) {
        return nil;
    }

    OrientationSensorReading reading = _orientation.GetCurrentReading();

    _deviceMotion = [[CMDeviceMotion alloc] initWithValues:[CMMotionManager toAttitude:reading.RotationMatrix() quaternion:reading.Quaternion()]
                                                      time:toSecondsSinceBoot(reading.Timestamp())];
    return _deviceMotion;
}

- (void)setDeviceMotionUpdateInterval:(NSTimeInterval)updateInterval {
    @synchronized(self) {
        if (self.isDeviceMotionAvailable) {
            // iOS uses seconds while WinRT uses milliseconds, hence the multiplication/division by c_secondToMilliseconds
            if (updateInterval * c_secondToMilliseconds < _orientation.MinimumReportInterval()) {
                _deviceMotionUpdateInterval = _orientation.MinimumReportInterval() / c_secondToMilliseconds;
                _orientation.ReportInterval(_orientation.MinimumReportInterval());
                NSTraceInfo(TAG, @"deviceMotionUpdateInterval capped to minimum supported value: %g", _deviceMotionUpdateInterval);
            } else {
                _deviceMotionUpdateInterval = updateInterval;
                _orientation.ReportInterval(static_cast<unsigned int>(self.deviceMotionUpdateInterval * c_secondToMilliseconds));
            }
        }
    }
}

/**
 @Status Stub
 @Notes
*/
+ (CMAttitudeReferenceFrame)availableAttitudeReferenceFrames {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
