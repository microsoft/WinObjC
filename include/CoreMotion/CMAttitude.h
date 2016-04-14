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

#import <CoreMotion/CoreMotionExport.h>

#import <Foundation/NSObject.h>

typedef struct {
    double m11, m12, m13;
    double m21, m22, m23;
    double m31, m32, m33;
} CMRotationMatrix;

typedef struct { double x, y, z, w; } CMQuaternion;

typedef enum {
    CMAttitudeReferenceFrameXArbitraryZVertical = 1 << 0,
    CMAttitudeReferenceFrameXArbitraryCorrectedZVertical = 1 << 1,
    CMAttitudeReferenceFrameXMagneticNorthZVertical = 1 << 2,
    CMAttitudeReferenceFrameXTrueNorthZVertical = 1 << 3
} CMAttitudeReferenceFrame;

COREMOTION_EXPORT_CLASS
@interface CMAttitude : NSObject <NSCopying, NSSecureCoding>
@property (readonly, nonatomic) double roll;
@property (readonly, nonatomic) double pitch;
@property (readonly, nonatomic) double yaw;
@property (readonly, nonatomic) CMRotationMatrix rotationMatrix;
@property (readonly, nonatomic) CMQuaternion quaternion;
- (void)multiplyByInverseOfAttitude:(CMAttitude*)attitude STUB_METHOD;
@end
