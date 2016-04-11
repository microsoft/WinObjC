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
#import "CMMotionManagerInternal.h"
#import "UWP/WindowsDevicesSensors.h"
#import "UWP/WindowsGraphicsDisplay.h"
#import "UWP/WindowsFoundation.h"
#import "Windows.h"

// Timestamps for readings are in seconds for iOS and in 100-nanoseconds for WinRT
static const double c_secondToHundredNanoseconds = 10000000.0;

// GetTickCount64() unit is millisecond and SystemTime unit is 100-nanosecond
static const double c_millisecondToHundredNanoseconds = 10000.0;

// iOS uses (double)seconds while WinRT uses (uint)milliseconds. Thus (double)c_secondToMilliseconds for conversions.
static const double c_secondToMilliseconds= 1000.0;

// For gyrometer values iOS uses unit as radians per sec. while WinRT uses degrees per sec. 
static const double c_degreeToRadian = M_PI / 180;

static double _bootTime;

// Converting from number of 100-nanosecond intervals passed after midnight on January 1, 1601
// to number of seconds passed since the devices booted.
inline double toSecondsSinceBoot(WFDateTime*time) {  
    return (static_cast<double>(time.universalTime) - _bootTime) / c_secondToHundredNanoseconds;
}

static const wchar_t* TAG = L"CMMotionManager";
NSString* const CMErrorDomain = @"CMErrorDomain";


@interface CMMotionManager ()

@property WDSAccelerometer* accelerometer;
@property EventRegistrationToken accelerometerToken;
@property NSOperationQueue* accelerometerQueue;
@property (readwrite, nonatomic, getter=isAccelerometerActive) BOOL accelerometerActive;
@property (readwrite, nonatomic, getter=isAccelerometerAvailable) BOOL accelerometerAvailable;
@property (readwrite) CMAccelerometerData* accelerometerData; 

@property WDSGyrometer* gyrometer;
@property EventRegistrationToken gyrometerToken;
@property NSOperationQueue* gyroQueue; 
@property (readwrite, nonatomic, getter=isGyroActive) BOOL gyroActive;
@property (readwrite, nonatomic, getter=isGyroAvailable) BOOL gyroAvailable;
@property (readwrite) CMGyroData* gyroData; 

@property WDSMagnetometer* magnetometer;
@property EventRegistrationToken magnetometerToken;
@property NSOperationQueue* magnetometerQueue; 
@property (readwrite, nonatomic, getter=isMagnetometerActive) BOOL magnetometerActive;
@property (readwrite, nonatomic, getter=isMagnetometerAvailable) BOOL magnetometerAvailable;
@property (readwrite) CMMagnetometerData* magnetometerData; 

@end


@implementation CMMotionManager 

- (instancetype)init {

    if (self = [super init]) {

       // GetTickCount64() returns the number of milliseconds passed since device boot
       _bootTime = static_cast<double>(GetTickCount64());

       FILETIME fileTime;
       GetSystemTimeAsFileTime(&fileTime);

       ULARGE_INTEGER nowTime;
       nowTime.LowPart = fileTime.dwLowDateTime;
       nowTime.HighPart = fileTime.dwHighDateTime;

       // On iOS the timestamps represent the number of seconds passed since the device booted while 
       // WinRT returns the number of 100-nanosecond intervals passed after midnight on January 1, 1601.
       // Hence we calculate the bootTime as number of 100-nanosecond intervals after midnight on January 1, 1601  
       // till device boot and then we can simply subtract this value from each readings' timestamp.
       _bootTime = static_cast<double>(nowTime.QuadPart) - (_bootTime * c_millisecondToHundredNanoseconds); 
    
       _accelerometer = [WDSAccelerometer getDefault];
       _accelerometerActive = false;
       _accelerometerToken.value = 0;
      
       if (_accelerometer) {
            _accelerometerAvailable = true;

            // The ref. frame is portrait-mode for iOS, while it is different across devices running Windows.
            [_accelerometer setReadingTransform:WGDDisplayOrientationsPortrait];
        } else {
            _accelerometerAvailable = false;
            NSTraceInfo(TAG, @"Accelerometer not found!");  
        }

       _gyrometer = [WDSGyrometer getDefault];
       _gyroActive = false;
       _gyrometerToken.value = 0;
      
       if (_gyrometer) {
            _gyroAvailable = true;

            // The ref. frame is portrait-mode for iOS, while it is different across devices running Windows.
            [_gyrometer setReadingTransform:WGDDisplayOrientationsPortrait];
        } else {
            _gyroAvailable = false;
            NSTraceInfo(TAG, @"Gyrometer not found!");  
        }
        
       _magnetometer = [WDSMagnetometer getDefault];
       _magnetometerActive = false;
       _magnetometerToken.value = 0;
      
       if (_magnetometer) {
            _magnetometerAvailable = true;

            // The ref. frame is portrait-mode for iOS, while it is different across devices running Windows.
            [_magnetometer setReadingTransform:WGDDisplayOrientationsPortrait];
        } else {
            _magnetometerAvailable = false;
            NSTraceInfo(TAG, @"Magnetometer not found!");  
        }
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

                CMAccelerometerData* data = [[CMAccelerometerData alloc] initWithValues:reading.accelerationX 
                                                                                      y:reading.accelerationY
                                                                                      z:reading.accelerationZ
                                                                                   time:toSecondsSinceBoot(reading.timestamp)];
                [queue addOperationWithBlock:^{ handler(data, nil); }];                                   
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
            self.accelerometer.reportInterval = static_cast<unsigned int>(self.accelerometerUpdateInterval * c_secondToMilliseconds);
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


/**
 @Status Interoperable
 @Notes
*/
 -(CMAccelerometerData*)accelerometerData {
     
    WDSAccelerometerReading* reading = [self.accelerometer getCurrentReading];

    _accelerometerData = [[CMAccelerometerData alloc] initWithValues:reading.accelerationX 
                                                                   y:reading.accelerationY
                                                                   z:reading.accelerationZ
                                                                time:toSecondsSinceBoot(reading.timestamp)];
    return _accelerometerData;
 }


-(void)setAccelerometerUpdateInterval:(NSTimeInterval)updateInterval {
    
    @synchronized(self) {
        
        // iOS uses seconds while WinRT uses milliseconds, hence the multiplication/division by c_secondToMilliseconds
        if (updateInterval * c_secondToMilliseconds < self.accelerometer.minimumReportInterval) {
            _accelerometerUpdateInterval = self.accelerometer.minimumReportInterval / c_secondToMilliseconds;
            self.accelerometer.reportInterval =  self.accelerometer.minimumReportInterval;
            NSTraceInfo(TAG, @"accelerometerUpdateInterval capped to minimum supported value: %d", _accelerometerUpdateInterval);
        } else {
            _accelerometerUpdateInterval = updateInterval;
            self.accelerometer.reportInterval = static_cast<unsigned int>(_accelerometerUpdateInterval * c_secondToMilliseconds);
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

        self.gyrometerToken = [self.gyrometer addReadingChangedEvent:
            ^void(WDSGyrometer* sender, WDSGyrometerReadingChangedEventArgs* e) {

                WDSGyrometerReading* reading = e.reading;

                // For gyrometer values iOS uses unit as radians per sec. while WinRT uses degrees per sec. 
                CMGyroData* data = [[CMGyroData alloc] initWithValues:reading.angularVelocityX * c_degreeToRadian
                                                                    y:reading.angularVelocityY * c_degreeToRadian
                                                                    z:reading.angularVelocityZ * c_degreeToRadian
                                                                 time:toSecondsSinceBoot(reading.timestamp)];
                [queue addOperationWithBlock:^{ handler(data, nil); }];                                   
            }];          
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
            self.gyrometer.reportInterval = static_cast<unsigned int>(self.gyroUpdateInterval * c_secondToMilliseconds);
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
            self.gyrometer.reportInterval = 0;
        
            if (self.gyrometerToken.value != 0) {
                [self.gyrometer removeReadingChangedEvent:self.gyrometerToken];
                self.gyrometerToken = {0};
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
 -(CMGyroData*)gyroData {
     
    WDSGyrometerReading* reading = [self.gyrometer getCurrentReading];

    // For gyrometer values iOS uses unit as radians per sec. while WinRT uses degrees per sec. 
    _gyroData = [[CMGyroData alloc] initWithValues:reading.angularVelocityX * c_degreeToRadian 
                                                 y:reading.angularVelocityY * c_degreeToRadian
                                                 z:reading.angularVelocityZ * c_degreeToRadian
                                              time:toSecondsSinceBoot(reading.timestamp)];
    return _gyroData;
 }


 -(void)setGyroUpdateInterval:(NSTimeInterval)updateInterval {
     
    @synchronized(self) {
        
        // iOS uses seconds while WinRT uses milliseconds, hence the multiplication/division by c_secondToMilliseconds
        if (updateInterval * c_secondToMilliseconds < self.gyrometer.minimumReportInterval) {
            _gyroUpdateInterval = self.gyrometer.minimumReportInterval / c_secondToMilliseconds;
            self.gyrometer.reportInterval = self.gyrometer.minimumReportInterval;
            NSTraceInfo(TAG, @"gyroUpdateInterval capped to minimum supported value: %d", _gyroUpdateInterval);
        } else {
            _gyroUpdateInterval = updateInterval;
            self.gyrometer.reportInterval = static_cast<unsigned int>(_gyroUpdateInterval * c_secondToMilliseconds);
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

        self.magnetometerToken = [self.magnetometer addReadingChangedEvent:
            ^void(WDSMagnetometer* sender, WDSMagnetometerReadingChangedEventArgs* e) {

                WDSMagnetometerReading* reading = e.reading;

                CMMagnetometerData* data = [[CMMagnetometerData alloc] initWithValues:reading.magneticFieldX 
                                                                                    y:reading.magneticFieldY
                                                                                    z:reading.magneticFieldZ
                                                                                 time:toSecondsSinceBoot(reading.timestamp)];
                [queue addOperationWithBlock:^{ handler(data, nil); }];                                   
            }];          
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

            self.magnetometer.reportInterval = static_cast<unsigned int>(self.magnetometerUpdateInterval * c_secondToMilliseconds);
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
            self.magnetometer.reportInterval = 0;
        
            if (self.magnetometerToken.value != 0) {
                [self.magnetometer removeReadingChangedEvent:self.magnetometerToken];
                self.magnetometerToken = {0};
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
 -(CMMagnetometerData*)magnetometerData {
     
    WDSMagnetometerReading* reading = [self.magnetometer getCurrentReading];

    _magnetometerData = [[CMMagnetometerData alloc] initWithValues:reading.magneticFieldX 
                                                                 y:reading.magneticFieldY
                                                                 z:reading.magneticFieldZ
                                                              time:toSecondsSinceBoot(reading.timestamp)];
    return _magnetometerData;
 }


-(void)setMagnetometerUpdateInterval:(NSTimeInterval)updateInterval {
    
    @synchronized(self) {
        
        // iOS uses seconds while WinRT uses milliseconds, hence the multiplication/division by c_secondToMilliseconds
        if (updateInterval * c_secondToMilliseconds < self.magnetometer.minimumReportInterval) {
            _magnetometerUpdateInterval = self.magnetometer.minimumReportInterval / c_secondToMilliseconds;
            self.magnetometer.reportInterval = self.magnetometer.minimumReportInterval;
            NSTraceInfo(TAG, @"magnetometerUpdateInterval capped to minimum supported value: %d", _magnetometerUpdateInterval);
        } else {
            _magnetometerUpdateInterval = updateInterval;
            self.magnetometer.reportInterval = static_cast<unsigned int>(_magnetometerUpdateInterval * c_secondToMilliseconds);
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
