//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsFoundationNumerics.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WFNVector2, WFNVector3, WFNVector4, WFNMatrix3x2, WFNMatrix4x4, WFNPlane, WFNQuaternion;

#import <Foundation/Foundation.h>

// [struct] Windows.Foundation.Numerics.Vector2
WINRT_EXPORT
@interface WFNVector2 : NSObject
+ (instancetype) new;
@property float x;
@property float y;
@end

// [struct] Windows.Foundation.Numerics.Vector3
WINRT_EXPORT
@interface WFNVector3 : NSObject
+ (instancetype) new;
@property float x;
@property float y;
@property float z;
@end

// [struct] Windows.Foundation.Numerics.Vector4
WINRT_EXPORT
@interface WFNVector4 : NSObject
+ (instancetype) new;
@property float x;
@property float y;
@property float z;
@property float w;
@end

// [struct] Windows.Foundation.Numerics.Matrix3x2
WINRT_EXPORT
@interface WFNMatrix3x2 : NSObject
+ (instancetype) new;
@property float m11;
@property float m12;
@property float m21;
@property float m22;
@property float m31;
@property float m32;
@end

// [struct] Windows.Foundation.Numerics.Matrix4x4
WINRT_EXPORT
@interface WFNMatrix4x4 : NSObject
+ (instancetype) new;
@property float m11;
@property float m12;
@property float m13;
@property float m14;
@property float m21;
@property float m22;
@property float m23;
@property float m24;
@property float m31;
@property float m32;
@property float m33;
@property float m34;
@property float m41;
@property float m42;
@property float m43;
@property float m44;
@end

// [struct] Windows.Foundation.Numerics.Plane
WINRT_EXPORT
@interface WFNPlane : NSObject
+ (instancetype) new;
@property (copy) WFNVector3* normal;
@property float d;
@end

// [struct] Windows.Foundation.Numerics.Quaternion
WINRT_EXPORT
@interface WFNQuaternion : NSObject
+ (instancetype) new;
@property float x;
@property float y;
@property float z;
@property float w;
@end
