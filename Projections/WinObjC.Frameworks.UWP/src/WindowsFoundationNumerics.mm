//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsFoundationNumerics.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Foundation.Numerics.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsFoundationNumerics.h"
#include "WindowsFoundationNumerics_priv.h"

@implementation WFNVector2 {
    ABI::Windows::Foundation::Numerics::Vector2 structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Foundation::Numerics::Vector2)s {
    WFNVector2* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Foundation::Numerics::Vector2*)internalStruct {
    return &structVal;
}
- (float)x {
    return structVal.X;
}
- (void)setX:(float)val {
    structVal.X = val;
}
- (float)y {
    return structVal.Y;
}
- (void)setY:(float)val {
    structVal.Y = val;
}
@end
@implementation WFNVector3 {
    ABI::Windows::Foundation::Numerics::Vector3 structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Foundation::Numerics::Vector3)s {
    WFNVector3* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Foundation::Numerics::Vector3*)internalStruct {
    return &structVal;
}
- (float)x {
    return structVal.X;
}
- (void)setX:(float)val {
    structVal.X = val;
}
- (float)y {
    return structVal.Y;
}
- (void)setY:(float)val {
    structVal.Y = val;
}
- (float)z {
    return structVal.Z;
}
- (void)setZ:(float)val {
    structVal.Z = val;
}
@end
@implementation WFNVector4 {
    ABI::Windows::Foundation::Numerics::Vector4 structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Foundation::Numerics::Vector4)s {
    WFNVector4* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Foundation::Numerics::Vector4*)internalStruct {
    return &structVal;
}
- (float)x {
    return structVal.X;
}
- (void)setX:(float)val {
    structVal.X = val;
}
- (float)y {
    return structVal.Y;
}
- (void)setY:(float)val {
    structVal.Y = val;
}
- (float)z {
    return structVal.Z;
}
- (void)setZ:(float)val {
    structVal.Z = val;
}
- (float)w {
    return structVal.W;
}
- (void)setW:(float)val {
    structVal.W = val;
}
@end
@implementation WFNMatrix3x2 {
    ABI::Windows::Foundation::Numerics::Matrix3x2 structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Foundation::Numerics::Matrix3x2)s {
    WFNMatrix3x2* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Foundation::Numerics::Matrix3x2*)internalStruct {
    return &structVal;
}
- (float)m11 {
    return structVal.M11;
}
- (void)setM11:(float)val {
    structVal.M11 = val;
}
- (float)m12 {
    return structVal.M12;
}
- (void)setM12:(float)val {
    structVal.M12 = val;
}
- (float)m21 {
    return structVal.M21;
}
- (void)setM21:(float)val {
    structVal.M21 = val;
}
- (float)m22 {
    return structVal.M22;
}
- (void)setM22:(float)val {
    structVal.M22 = val;
}
- (float)m31 {
    return structVal.M31;
}
- (void)setM31:(float)val {
    structVal.M31 = val;
}
- (float)m32 {
    return structVal.M32;
}
- (void)setM32:(float)val {
    structVal.M32 = val;
}
@end
@implementation WFNMatrix4x4 {
    ABI::Windows::Foundation::Numerics::Matrix4x4 structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Foundation::Numerics::Matrix4x4)s {
    WFNMatrix4x4* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Foundation::Numerics::Matrix4x4*)internalStruct {
    return &structVal;
}
- (float)m11 {
    return structVal.M11;
}
- (void)setM11:(float)val {
    structVal.M11 = val;
}
- (float)m12 {
    return structVal.M12;
}
- (void)setM12:(float)val {
    structVal.M12 = val;
}
- (float)m13 {
    return structVal.M13;
}
- (void)setM13:(float)val {
    structVal.M13 = val;
}
- (float)m14 {
    return structVal.M14;
}
- (void)setM14:(float)val {
    structVal.M14 = val;
}
- (float)m21 {
    return structVal.M21;
}
- (void)setM21:(float)val {
    structVal.M21 = val;
}
- (float)m22 {
    return structVal.M22;
}
- (void)setM22:(float)val {
    structVal.M22 = val;
}
- (float)m23 {
    return structVal.M23;
}
- (void)setM23:(float)val {
    structVal.M23 = val;
}
- (float)m24 {
    return structVal.M24;
}
- (void)setM24:(float)val {
    structVal.M24 = val;
}
- (float)m31 {
    return structVal.M31;
}
- (void)setM31:(float)val {
    structVal.M31 = val;
}
- (float)m32 {
    return structVal.M32;
}
- (void)setM32:(float)val {
    structVal.M32 = val;
}
- (float)m33 {
    return structVal.M33;
}
- (void)setM33:(float)val {
    structVal.M33 = val;
}
- (float)m34 {
    return structVal.M34;
}
- (void)setM34:(float)val {
    structVal.M34 = val;
}
- (float)m41 {
    return structVal.M41;
}
- (void)setM41:(float)val {
    structVal.M41 = val;
}
- (float)m42 {
    return structVal.M42;
}
- (void)setM42:(float)val {
    structVal.M42 = val;
}
- (float)m43 {
    return structVal.M43;
}
- (void)setM43:(float)val {
    structVal.M43 = val;
}
- (float)m44 {
    return structVal.M44;
}
- (void)setM44:(float)val {
    structVal.M44 = val;
}
@end
@implementation WFNPlane {
    ABI::Windows::Foundation::Numerics::Plane structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Foundation::Numerics::Plane)s {
    WFNPlane* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Foundation::Numerics::Plane*)internalStruct {
    return &structVal;
}
- (WFNVector3*)normal {
    return WFNVector3_create(structVal.Normal);
}
- (void)setNormal:(WFNVector3*)val {
    structVal.Normal = *[val internalStruct];
}
- (float)d {
    return structVal.D;
}
- (void)setD:(float)val {
    structVal.D = val;
}
@end
@implementation WFNQuaternion {
    ABI::Windows::Foundation::Numerics::Quaternion structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Foundation::Numerics::Quaternion)s {
    WFNQuaternion* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Foundation::Numerics::Quaternion*)internalStruct {
    return &structVal;
}
- (float)x {
    return structVal.X;
}
- (void)setX:(float)val {
    structVal.X = val;
}
- (float)y {
    return structVal.Y;
}
- (void)setY:(float)val {
    structVal.Y = val;
}
- (float)z {
    return structVal.Z;
}
- (void)setZ:(float)val {
    structVal.Z = val;
}
- (float)w {
    return structVal.W;
}
- (void)setW:(float)val {
    structVal.W = val;
}
@end
