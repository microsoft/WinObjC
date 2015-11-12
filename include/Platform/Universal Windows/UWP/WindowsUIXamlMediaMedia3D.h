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
@class WUXMMMatrix3DHelper, WUXMMTransform3D, WUXMMCompositeTransform3D, WUXMMPerspectiveTransform3D;
@class WUXMMMatrix3D;
@protocol WUXMMIMatrix3DHelper
, WUXMMIMatrix3DHelperStatics, WUXMMITransform3D, WUXMMITransform3DFactory, WUXMMICompositeTransform3D, WUXMMICompositeTransform3DStatics,
    WUXMMIPerspectiveTransform3D, WUXMMIPerspectiveTransform3DStatics;

#include "WindowsUIXaml.h"
#include "WindowsUICore.h"
// Windows.UI.Xaml.DependencyPropertyChangedCallback
#ifndef __WXDependencyPropertyChangedCallback__DEFINED
#define __WXDependencyPropertyChangedCallback__DEFINED
typedef void (^WXDependencyPropertyChangedCallback)(WXDependencyObject* sender, WXDependencyProperty* dp);
#endif // __WXDependencyPropertyChangedCallback__DEFINED

#import <Foundation/Foundation.h>

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

// Windows.UI.Xaml.DependencyObject
#ifndef __WXDependencyObject_DEFINED__
#define __WXDependencyObject_DEFINED__

WINRT_EXPORT
@interface WXDependencyObject : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WUCCoreDispatcher* dispatcher;
- (RTObject*)getValue:(WXDependencyProperty*)dp;
- (void)setValue:(WXDependencyProperty*)dp value:(RTObject*)value;
- (void)clearValue:(WXDependencyProperty*)dp;
- (RTObject*)readLocalValue:(WXDependencyProperty*)dp;
- (RTObject*)getAnimationBaseValue:(WXDependencyProperty*)dp;
- (int64_t)registerPropertyChangedCallback:(WXDependencyProperty*)dp callback:(WXDependencyPropertyChangedCallback)callback;
- (void)unregisterPropertyChangedCallback:(WXDependencyProperty*)dp token:(int64_t)token;
@end

#endif // __WXDependencyObject_DEFINED__

// Windows.UI.Xaml.Media.Media3D.Transform3D
#ifndef __WUXMMTransform3D_DEFINED__
#define __WUXMMTransform3D_DEFINED__

WINRT_EXPORT
@interface WUXMMTransform3D : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXMMTransform3D_DEFINED__

// Windows.UI.Xaml.Media.Media3D.CompositeTransform3D
#ifndef __WUXMMCompositeTransform3D_DEFINED__
#define __WUXMMCompositeTransform3D_DEFINED__

WINRT_EXPORT
@interface WUXMMCompositeTransform3D : WUXMMTransform3D
+ (instancetype)create ACTIVATOR;
@property double rotationZ;
@property double rotationY;
@property double rotationX;
@property double centerZ;
@property double centerY;
@property double scaleX;
@property double centerX;
@property double translateZ;
@property double translateY;
@property double translateX;
@property double scaleZ;
@property double scaleY;
+ (WXDependencyProperty*)centerXProperty;
+ (WXDependencyProperty*)centerYProperty;
+ (WXDependencyProperty*)centerZProperty;
+ (WXDependencyProperty*)rotationXProperty;
+ (WXDependencyProperty*)rotationYProperty;
+ (WXDependencyProperty*)rotationZProperty;
+ (WXDependencyProperty*)scaleXProperty;
+ (WXDependencyProperty*)scaleYProperty;
+ (WXDependencyProperty*)scaleZProperty;
+ (WXDependencyProperty*)translateXProperty;
+ (WXDependencyProperty*)translateYProperty;
+ (WXDependencyProperty*)translateZProperty;
@end

#endif // __WUXMMCompositeTransform3D_DEFINED__

// Windows.UI.Xaml.Media.Media3D.PerspectiveTransform3D
#ifndef __WUXMMPerspectiveTransform3D_DEFINED__
#define __WUXMMPerspectiveTransform3D_DEFINED__

WINRT_EXPORT
@interface WUXMMPerspectiveTransform3D : WUXMMTransform3D
+ (instancetype)create ACTIVATOR;
@property double offsetY;
@property double offsetX;
@property double depth;
+ (WXDependencyProperty*)depthProperty;
+ (WXDependencyProperty*)offsetXProperty;
+ (WXDependencyProperty*)offsetYProperty;
@end

#endif // __WUXMMPerspectiveTransform3D_DEFINED__
