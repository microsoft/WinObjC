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

// WindowsFoundationNumerics_priv.h
// Forward decls for private object generation
#pragma once

@interface WFNVector2 (Internal)
+ (instancetype)createWith:(ABI::Windows::Foundation::Numerics::Vector2)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Foundation::Numerics::Vector2*)internalStruct;
@end
inline WFNVector2* WFNVector2_create(ABI::Windows::Foundation::Numerics::Vector2 val) {
    return [WFNVector2 createWith:val];
}
@interface WFNVector3 (Internal)
+ (instancetype)createWith:(ABI::Windows::Foundation::Numerics::Vector3)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Foundation::Numerics::Vector3*)internalStruct;
@end
inline WFNVector3* WFNVector3_create(ABI::Windows::Foundation::Numerics::Vector3 val) {
    return [WFNVector3 createWith:val];
}
@interface WFNVector4 (Internal)
+ (instancetype)createWith:(ABI::Windows::Foundation::Numerics::Vector4)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Foundation::Numerics::Vector4*)internalStruct;
@end
inline WFNVector4* WFNVector4_create(ABI::Windows::Foundation::Numerics::Vector4 val) {
    return [WFNVector4 createWith:val];
}
@interface WFNMatrix3x2 (Internal)
+ (instancetype)createWith:(ABI::Windows::Foundation::Numerics::Matrix3x2)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Foundation::Numerics::Matrix3x2*)internalStruct;
@end
inline WFNMatrix3x2* WFNMatrix3x2_create(ABI::Windows::Foundation::Numerics::Matrix3x2 val) {
    return [WFNMatrix3x2 createWith:val];
}
@interface WFNMatrix4x4 (Internal)
+ (instancetype)createWith:(ABI::Windows::Foundation::Numerics::Matrix4x4)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Foundation::Numerics::Matrix4x4*)internalStruct;
@end
inline WFNMatrix4x4* WFNMatrix4x4_create(ABI::Windows::Foundation::Numerics::Matrix4x4 val) {
    return [WFNMatrix4x4 createWith:val];
}
@interface WFNPlane (Internal)
+ (instancetype)createWith:(ABI::Windows::Foundation::Numerics::Plane)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Foundation::Numerics::Plane*)internalStruct;
@end
inline WFNPlane* WFNPlane_create(ABI::Windows::Foundation::Numerics::Plane val) {
    return [WFNPlane createWith:val];
}
@interface WFNQuaternion (Internal)
+ (instancetype)createWith:(ABI::Windows::Foundation::Numerics::Quaternion)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Foundation::Numerics::Quaternion*)internalStruct;
@end
inline WFNQuaternion* WFNQuaternion_create(ABI::Windows::Foundation::Numerics::Quaternion val) {
    return [WFNQuaternion createWith:val];
}
