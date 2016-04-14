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

#import <CoreMotion/CMLogItem.h>
#import <CoreMotion/CMGyroData.h>
#import <CoreMotion/CMAccelerometerData.h>
#import <CoreMotion/CMMagnetometerData.h>
#import <CoreMotion/CoreMotionExport.h>

#import <Foundation/NSObject.h>

#import <objc\runtime.h>

@class CMAttitude;

COREMOTION_EXPORT_CLASS
@interface CMDeviceMotion : CMLogItem <NSCopying, NSSecureCoding>
@property (readonly, nonatomic) CMAttitude* attitude;
@property (readonly, nonatomic) CMRotationRate rotationRate STUB_PROPERTY;
@property (readonly, nonatomic) CMAcceleration gravity STUB_PROPERTY;
@property (readonly, nonatomic) CMAcceleration userAcceleration STUB_PROPERTY;
@property (readonly, nonatomic) CMCalibratedMagneticField magneticField STUB_PROPERTY;
@end
