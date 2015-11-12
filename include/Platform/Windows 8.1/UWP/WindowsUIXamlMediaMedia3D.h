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

// WindowsUIXamlMediaMedia3D.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUXMMMatrix3DHelper;
@class WUXMMMatrix3D;
@protocol WUXMMIMatrix3DHelper
, WUXMMIMatrix3DHelperStatics;

// [struct] Windows.UI.Xaml.Media.Media3D.Matrix3D
WINRT_EXPORT
@interface WUXMMMatrix3D : NSObject
+ (instancetype) new;
@property double m11;
@property double m12;
@property double m13;
@property double m14;
@property double m21;
@property double m22;
@property double m23;
@property double m24;
@property double m31;
@property double m32;
@property double m33;
@property double m34;
@property double offsetX;
@property double offsetY;
@property double offsetZ;
@property double m44;
@end

// Windows.UI.Xaml.Media.Media3D.Matrix3DHelper
#ifndef __WUXMMMatrix3DHelper_DEFINED__
#define __WUXMMMatrix3DHelper_DEFINED__

WINRT_EXPORT
@interface WUXMMMatrix3DHelper : RTObject
+ (WUXMMMatrix3D*)multiply:(WUXMMMatrix3D*)matrix1 matrix2:(WUXMMMatrix3D*)matrix2;
+ (WUXMMMatrix3D*)fromElements:(double)m11
                           m12:(double)m12
                           m13:(double)m13
                           m14:(double)m14
                           m21:(double)m21
                           m22:(double)m22
                           m23:(double)m23
                           m24:(double)m24
                           m31:(double)m31
                           m32:(double)m32
                           m33:(double)m33
                           m34:(double)m34
                       offsetX:(double)offsetX
                       offsetY:(double)offsetY
                       offsetZ:(double)offsetZ
                           m44:(double)m44;
+ (BOOL)getHasInverse:(WUXMMMatrix3D*)target;
+ (BOOL)getIsIdentity:(WUXMMMatrix3D*)target;
+ (WUXMMMatrix3D*)invert:(WUXMMMatrix3D*)target;
+ (WUXMMMatrix3D*)identity;
@end

#endif // __WUXMMMatrix3DHelper_DEFINED__
