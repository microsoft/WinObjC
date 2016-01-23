//******************************************************************************
//
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
@interface CMMotionManager : NSObject <NSObject>
@property (assign, nonatomic) NSTimeInterval accelerometerUpdateInterval STUB_PROPERTY;
- (void)startAccelerometerUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMAccelerometerHandler)handler STUB_METHOD;
- (void)startAccelerometerUpdates STUB_METHOD;
- (void)stopAccelerometerUpdates STUB_METHOD;
@property (readonly, nonatomic, getter=isAccelerometerActive) BOOL accelerometerActive STUB_PROPERTY;
@property (readonly, nonatomic, getter=isAccelerometerAvailable) BOOL accelerometerAvailable STUB_PROPERTY;
@property (readonly) CMAccelerometerData* accelerometerData STUB_PROPERTY;
@property (assign, nonatomic) NSTimeInterval gyroUpdateInterval STUB_PROPERTY;
- (void)startGyroUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMGyroHandler)handler STUB_METHOD;
- (void)startGyroUpdates STUB_METHOD;
- (void)stopGyroUpdates STUB_METHOD;
@property (readonly, nonatomic, getter=isGyroActive) BOOL gyroActive STUB_PROPERTY;
@property (readonly, nonatomic, getter=isGyroAvailable) BOOL gyroAvailable STUB_PROPERTY;
@property (readonly) CMGyroData* gyroData STUB_PROPERTY;
@property (assign, nonatomic) NSTimeInterval magnetometerUpdateInterval STUB_PROPERTY;
- (void)startMagnetometerUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMMagnetometerHandler)handler STUB_METHOD;
- (void)startMagnetometerUpdates STUB_METHOD;
- (void)stopMagnetometerUpdates STUB_METHOD;
@property (readonly, nonatomic, getter=isMagnetometerActive) BOOL magnetometerActive STUB_PROPERTY;
@property (readonly, nonatomic, getter=isMagnetometerAvailable) BOOL magnetometerAvailable STUB_PROPERTY;
@property (readonly) CMMagnetometerData* magnetometerData STUB_PROPERTY;
@property (assign, nonatomic) BOOL showsDeviceMovementDisplay STUB_PROPERTY;
@property (assign, nonatomic) NSTimeInterval deviceMotionUpdateInterval STUB_PROPERTY;
- (void)startDeviceMotionUpdatesUsingReferenceFrame:(CMAttitudeReferenceFrame)referenceFrame
                                            toQueue:(NSOperationQueue*)queue
                                        withHandler:(CMDeviceMotionHandler)handler STUB_METHOD;
- (void)startDeviceMotionUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMDeviceMotionHandler)handler STUB_METHOD;
- (void)startDeviceMotionUpdatesUsingReferenceFrame:(CMAttitudeReferenceFrame)referenceFrame STUB_METHOD;
- (void)startDeviceMotionUpdates STUB_METHOD;
- (void)stopDeviceMotionUpdates STUB_METHOD;
@property (readonly, nonatomic) CMAttitudeReferenceFrame attitudeReferenceFrame STUB_PROPERTY;
+ (CMAttitudeReferenceFrame)availableAttitudeReferenceFrames STUB_METHOD;
@property (readonly, nonatomic, getter=isDeviceMotionActive) BOOL deviceMotionActive STUB_PROPERTY;
@property (readonly, nonatomic, getter=isDeviceMotionAvailable) BOOL deviceMotionAvailable STUB_PROPERTY;
@property (readonly) CMDeviceMotion* deviceMotion STUB_PROPERTY;
@end
