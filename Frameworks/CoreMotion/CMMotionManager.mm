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
#import "CoreMotionInternal.h"
#import "UWP/WindowsDevicesSensors.h"
#import "UWP/WindowsGraphicsDisplay.h"

// iOS uses (double)seconds while WINRT uses (uint)milliseconds. Thus (double)c_intervalScaleFactor for conversions.
static const double c_intervalScaleFactor = 1000.0;

// For gyrometer values iOS uses unit as radians per sec. while WinRT uses degrees per sec. 
static const double c_degreeToRadians = M_PI / 180;

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

@end


@implementation CMMotionManager 

- (instancetype)init {

    if (self = [super init]) {        
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

        self.accelerometerToken = [self.accelerometer addReadingChangedEvent:
            ^void(WDSAccelerometer* sender, WDSAccelerometerReadingChangedEventArgs* e) {

                WDSAccelerometerReading* reading = e.reading;

                CMAccelerometerData* data = [[CMAccelerometerData alloc] initWithValues:reading.accelerationX 
                                                                                      y:reading.accelerationY
                                                                                      z:reading.accelerationZ];
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
            self.accelerometer.reportInterval = static_cast<unsigned int>(self.accelerometerUpdateInterval * c_intervalScaleFactor);
        } 
    }               
}


/**
 @Status Interoperable
 @Notes
*/
- (void) stopAccelerometerUpdates {
    @synchronized(self) {

        if (self.accelerometerActive) {
            self.accelerometerActive = false;
        
            // the reportInterval is set to 0, the default value.
            self.accelerometer.reportInterval = 0;
        
            if (self.accelerometerToken.value != 0) {
                [self.accelerometer removeReadingChangedEvent:self.accelerometerToken];
                self.accelerometerToken = {0};
            }
        
            if (self.accelerometerQueue) {
                [self.accelerometerQueue cancelAllOperations];
                self.accelerometerQueue = nil;
            }
        }
    }                         
 }


// getter function for on-demand reading from sensor
 -(CMAccelerometerData*)accelerometerData {
    WDSAccelerometerReading* reading = [self.accelerometer getCurrentReading];

    _accelerometerData = [[CMAccelerometerData alloc] initWithValues:reading.accelerationX 
                                                                   y:reading.accelerationY
                                                                   z:reading.accelerationZ];
    return _accelerometerData;
 }


-(void)setAccelerometerUpdateInterval:(NSTimeInterval)updateInterval {
    @synchronized(self) {
        
        // iOS uses seconds while WINRT uses milliseconds, hence the multiplication/division by c_intervalScaleFactor
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
                CMGyroData* data = [[CMGyroData alloc] initWithValues:reading.angularVelocityX * c_degreeToRadians
                                                                    y:reading.angularVelocityY * c_degreeToRadians
                                                                    z:reading.angularVelocityZ * c_degreeToRadians];
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
            self.gyrometer.reportInterval = static_cast<unsigned int>(self.gyroUpdateInterval * c_intervalScaleFactor);
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


 // getter function for on-demand reading from sensor
 -(CMGyroData*)gyroData {
    WDSGyrometerReading* reading = [self.gyrometer getCurrentReading];

    // For gyrometer values iOS uses unit as radians per sec. while WinRT uses degrees per sec. 
    _gyroData = [[CMGyroData alloc] initWithValues:reading.angularVelocityX * c_degreeToRadians 
                                                 y:reading.angularVelocityY * c_degreeToRadians
                                                 z:reading.angularVelocityZ * c_degreeToRadians];
    return _gyroData;
 }


 -(void)setGyroUpdateInterval:(NSTimeInterval)updateInterval {
    @synchronized(self) {
        
        // iOS uses seconds while WINRT uses milliseconds, hence the multiplication/division by c_intervalScaleFactor
        if (updateInterval * c_intervalScaleFactor < self.gyrometer.minimumReportInterval) {
            _gyroUpdateInterval = self.gyrometer.minimumReportInterval / c_intervalScaleFactor;
            NSTraceInfo(TAG, @"gyroUpdateInterval capped to minimum supported value: %d", _gyroUpdateInterval);
        } else {
            _gyroUpdateInterval = updateInterval;
        }
        
        self.gyrometer.reportInterval = static_cast<unsigned int>(self.gyroUpdateInterval * c_intervalScaleFactor);
    }
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
