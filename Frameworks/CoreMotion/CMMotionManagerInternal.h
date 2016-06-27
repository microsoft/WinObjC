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

#import "UWP/WindowsFoundation.h"
#import "UWP/WindowsDevicesSensors.h"

@interface CMAccelerometerData ()
- (instancetype)initWithValues:(double)x y:(double)y z:(double)z time:(double)time;
@end

@interface CMGyroData ()
- (instancetype)initWithValues:(double)x y:(double)y z:(double)z time:(double)time;
@end

@interface CMMagnetometerData ()
- (instancetype)initWithValues:(double)x y:(double)y z:(double)z time:(double)time;
@end

@interface CMAttitude ()
- (instancetype)initWithValues:(double)roll
                         pitch:(double)pitch
                           yaw:(double)yaw
                rotationMatrix:(CMRotationMatrix)rotationMatrix
                    quaternion:(CMQuaternion)quaternion;
@end

@interface CMDeviceMotion()
- (instancetype)initWithValues:(CMAttitude*)attitude time:(double)time;
@end

@interface CMMotionManager ()
+ (CMAttitude*)toAttitude:(WDSSensorRotationMatrix*)rm quaternion:(WDSSensorQuaternion*)q;
@end