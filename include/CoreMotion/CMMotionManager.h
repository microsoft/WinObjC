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
#pragma once

#import <CoreMotion/CMAttitude.h>
#import <CoreMotion/CoreMotionExport.h>
#import <Foundation/NSObject.h>
#import <objc/runtime.h>


@class CMAccelerometerData;
@class NSError;
@class CMGyroData;
@class CMMagnetometerData;
@class CMDeviceMotion;
@class NSString;
@class NSOperationQueue;

typedef void (^CMAccelerometerHandler)(CMAccelerometerData* accelerometerData, NSError* error);
typedef void (^CMGyroHandler)(CMGyroData* gyroData, NSError* error);
typedef void (^CMMagnetometerHandler)(CMMagnetometerData* magnetometerData, NSError* error);
typedef void (^CMDeviceMotionHandler)(CMDeviceMotion* motion, NSError* error);

typedef enum {
    CMErrorNULL = 100,
    CMErrorDeviceRequiresMovement,
    CMErrorTrueNorthNotAvailable,
    CMErrorUnknown,
    CMErrorMotionActivityNotAvailable,
    CMErrorMotionActivityNotAuthorized,
    CMErrorMotionActivityNotEntitled,
    CMErrorInvalidParameter
} CMError;

COREMOTION_EXPORT NSString* const CMErrorDomain;

COREMOTION_EXPORT_CLASS
@interface CMMotionManager : NSObject
@property (assign, nonatomic) NSTimeInterval accelerometerUpdateInterval;
- (void)startAccelerometerUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMAccelerometerHandler)handler;
- (void)startAccelerometerUpdates;
- (void)stopAccelerometerUpdates;
@property (readonly, nonatomic, getter=isAccelerometerActive) BOOL accelerometerActive;
@property (readonly, nonatomic, getter=isAccelerometerAvailable) BOOL accelerometerAvailable;
@property (readonly, nonatomic) CMAccelerometerData* accelerometerData;

@property (assign, nonatomic) NSTimeInterval gyroUpdateInterval;
- (void)startGyroUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMGyroHandler)handler;
- (void)startGyroUpdates;
- (void)stopGyroUpdates;
@property (readonly, nonatomic, getter=isGyroActive) BOOL gyroActive;
@property (readonly, nonatomic, getter=isGyroAvailable) BOOL gyroAvailable;
@property (readonly, nonatomic) CMGyroData* gyroData;

@property (assign, nonatomic) NSTimeInterval magnetometerUpdateInterval;
- (void)startMagnetometerUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMMagnetometerHandler)handler;
- (void)startMagnetometerUpdates;
- (void)stopMagnetometerUpdates;
@property (readonly, nonatomic, getter=isMagnetometerActive) BOOL magnetometerActive;
@property (readonly, nonatomic, getter=isMagnetometerAvailable) BOOL magnetometerAvailable;
@property (readonly, nonatomic) CMMagnetometerData* magnetometerData;

@property (assign, nonatomic) BOOL showsDeviceMovementDisplay STUB_PROPERTY;
@property (assign, nonatomic) NSTimeInterval deviceMotionUpdateInterval;
- (void)startDeviceMotionUpdatesUsingReferenceFrame:(CMAttitudeReferenceFrame)referenceFrame
                                            toQueue:(NSOperationQueue*)queue
                                        withHandler:(CMDeviceMotionHandler)handler STUB_METHOD;
- (void)startDeviceMotionUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMDeviceMotionHandler)handler;
- (void)startDeviceMotionUpdatesUsingReferenceFrame:(CMAttitudeReferenceFrame)referenceFrame STUB_METHOD;
- (void)startDeviceMotionUpdates;
- (void)stopDeviceMotionUpdates;
@property (readonly, nonatomic) CMAttitudeReferenceFrame attitudeReferenceFrame STUB_PROPERTY;
+ (CMAttitudeReferenceFrame)availableAttitudeReferenceFrames STUB_METHOD;
@property (readonly, nonatomic, getter=isDeviceMotionActive) BOOL deviceMotionActive;
@property (readonly, nonatomic, getter=isDeviceMotionAvailable) BOOL deviceMotionAvailable;
@property (readonly, nonatomic) CMDeviceMotion* deviceMotion;
@end
