//******************************************************************************
//
// Copyright (c) 2016, Intel Corporation.
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

#import <CoreMotion/CMMotionManager.h>
#import <CoreMotion/CMAccelerometerData.h>
#import <StubReturn.h>
#import <NSLogging.h>
#import "CMAccelerometerDataInternal.h"
#import "CMMotionManagerWinRT.h"
#import "UWP/WindowsDevicesSensors.h"

// iOS uses (double)seconds while WINRT uses (uint)milliseconds. Thus (double)c_intervalScaleFactor for conversions.
static const double c_intervalScaleFactor = 1000.0;
static const wchar_t* TAG = L"CMMotionManager";
NSString* const CMErrorDomain = @"CMErrorDomain";

@interface CMMotionManager ()
@property WDSAccelerometer* accelerometer;
@property EventRegistrationToken accelerometerToken;
@property NSOperationQueue* accelerometerQueue;
@property (readwrite, nonatomic, getter=isAccelerometerActive) BOOL accelerometerActive;
@property (readwrite, nonatomic, getter=isAccelerometerAvailable) BOOL accelerometerAvailable;
@end

@implementation CMMotionManager

- (instancetype)init {
    if (self = [super init]) {
        // Calling into C++/CX to determine if the default accelerometer device is available
        // This step is necessary for now as this call using projections [WDSAccelerometer getDefault] does not return NULL
        // as expected for the case where no accelerometer device is available
        if (!checkDefaultAccelerometer()) {
            _accelerometerAvailable = false;
            NSTraceInfo(TAG, @"Accelerometer not found!");
        } else {
            _accelerometerAvailable = true;
            _accelerometer = [WDSAccelerometer getDefault];
        }

        _accelerometerActive = false;
        _accelerometerToken.value = 0;
    }

    return self;
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
            [self.accelerometer addReadingChangedEvent:^void(WDSAccelerometer* sender, WDSAccelerometerReadingChangedEventArgs* e) {

                WDSAccelerometerReading* reading = e.reading;

                CMAccelerometerData* data =
                    [[CMAccelerometerData alloc] initWithValues:reading.accelerationX y:reading.accelerationY z:reading.accelerationZ];
                [queue addOperationWithBlock:^{
                    handler(data, nil);
                }];
            }];
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

            self.accelerometer.reportInterval = static_cast<unsigned int>(self.accelerometerUpdateInterval * c_intervalScaleFactor);
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
            self.accelerometer.reportInterval = 0;

            if (self.accelerometerToken.value != 0) {
                [self.accelerometer removeReadingChangedEvent:self.accelerometerToken];
                self.accelerometerToken = { 0 };
            }

            if (self.accelerometerQueue) {
                [self.accelerometerQueue cancelAllOperations];
                self.accelerometerQueue = nil;
            }
        }
    }
}

// getter function for on-demand reading from sensor
- (CMAccelerometerData*)accelerometerData {
    WDSAccelerometerReading* reading = [self.accelerometer getCurrentReading];

    CMAccelerometerData* data =
        [[CMAccelerometerData alloc] initWithValues:reading.accelerationX y:reading.accelerationY z:reading.accelerationZ];
    return data;
}

- (void)setAccelerometerUpdateInterval:(NSTimeInterval)updateInterval {
    @synchronized(self) {
        // iOS uses (double)seconds while WINRT uses (uint)milliseconds, hence the multiplication/division by (double)c_intervalScaleFactor
        if (updateInterval * c_intervalScaleFactor < self.accelerometer.minimumReportInterval) {
            _accelerometerUpdateInterval = self.accelerometer.minimumReportInterval / c_intervalScaleFactor;
            NSTraceInfo(TAG, @"accelerometerUpdateInterval capped to minimum supported value: %d", _accelerometerUpdateInterval);
        } else {
            _accelerometerUpdateInterval = updateInterval;
        }

        self.accelerometer.reportInterval = static_cast<unsigned int>(self.accelerometerUpdateInterval * c_intervalScaleFactor);
    }
}

/**
 @Status Stub
 @Notes
*/
- (void)startGyroUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMGyroHandler)handler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)startGyroUpdates {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)stopGyroUpdates {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)startMagnetometerUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMMagnetometerHandler)handler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)startMagnetometerUpdates {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)stopMagnetometerUpdates {
    UNIMPLEMENTED();
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
 @Status Stub
 @Notes
*/
- (void)startDeviceMotionUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMDeviceMotionHandler)handler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)startDeviceMotionUpdatesUsingReferenceFrame:(CMAttitudeReferenceFrame)referenceFrame {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)startDeviceMotionUpdates {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)stopDeviceMotionUpdates {
    UNIMPLEMENTED();
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
