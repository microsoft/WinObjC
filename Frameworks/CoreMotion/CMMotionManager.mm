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

#import <CoreMotion/CMMotionManager.h>
#import <StubReturn.h>

NSString* const CMErrorDomain = @"CMErrorDomain";

@implementation CMMotionManager
/**
 @Status Stub
 @Notes
*/
- (void)startAccelerometerUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMAccelerometerHandler)handler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)startAccelerometerUpdates {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)stopAccelerometerUpdates {
    UNIMPLEMENTED();
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
