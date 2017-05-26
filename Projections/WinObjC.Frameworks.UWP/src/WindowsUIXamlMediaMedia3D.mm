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

// WindowsUIXamlMediaMedia3D.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Media.Media3D.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlMediaMedia3D.h"
#include "WindowsUIXamlMediaMedia3D_priv.h"

@implementation WUXMMMatrix3DHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Media3D::IMatrix3DHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::Media3D::IMatrix3DHelperStatics> WUXMMIMatrix3DHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Media3D::IMatrix3DHelperStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Media3D.Matrix3DHelper").Get(),
                                                       &inst));
    return inst;
}

+ (WUXMMMatrix3D*)identity {
    ABI::Windows::UI::Xaml::Media::Media3D::Matrix3D unmarshalledReturn;
    auto _comInst = WUXMMIMatrix3DHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Identity(&unmarshalledReturn));
    return WUXMMMatrix3D_create(unmarshalledReturn);
}

+ (WUXMMMatrix3D*)multiply:(WUXMMMatrix3D*)matrix1 matrix2:(WUXMMMatrix3D*)matrix2 {
    ABI::Windows::UI::Xaml::Media::Media3D::Matrix3D unmarshalledReturn;
    auto _comInst = WUXMMIMatrix3DHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Multiply(*[matrix1 internalStruct], *[matrix2 internalStruct], &unmarshalledReturn));
    return WUXMMMatrix3D_create(unmarshalledReturn);
}

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
                           m44:(double)m44 {
    ABI::Windows::UI::Xaml::Media::Media3D::Matrix3D unmarshalledReturn;
    auto _comInst = WUXMMIMatrix3DHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromElements(
        m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, offsetX, offsetY, offsetZ, m44, &unmarshalledReturn));
    return WUXMMMatrix3D_create(unmarshalledReturn);
}

+ (BOOL)getHasInverse:(WUXMMMatrix3D*)target {
    boolean unmarshalledReturn;
    auto _comInst = WUXMMIMatrix3DHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetHasInverse(*[target internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)getIsIdentity:(WUXMMMatrix3D*)target {
    boolean unmarshalledReturn;
    auto _comInst = WUXMMIMatrix3DHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetIsIdentity(*[target internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (WUXMMMatrix3D*)invert:(WUXMMMatrix3D*)target {
    ABI::Windows::UI::Xaml::Media::Media3D::Matrix3D unmarshalledReturn;
    auto _comInst = WUXMMIMatrix3DHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Invert(*[target internalStruct], &unmarshalledReturn));
    return WUXMMMatrix3D_create(unmarshalledReturn);
}

@end

@implementation WUXMMTransform3D

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Media3D::ITransform3D> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXMMCompositeTransform3D

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Media3D.CompositeTransform3D").Get(), &out));
    return [_createRtProxy<WUXMMCompositeTransform3D>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3DStatics> WUXMMICompositeTransform3DStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3DStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Media3D.CompositeTransform3D").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)centerXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMICompositeTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)centerYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMICompositeTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)centerZProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMICompositeTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterZProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)rotationXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMICompositeTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RotationXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)rotationYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMICompositeTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RotationYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)rotationZProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMICompositeTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RotationZProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)scaleXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMICompositeTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ScaleXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)scaleYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMICompositeTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ScaleYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)scaleZProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMICompositeTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ScaleZProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)translateXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMICompositeTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TranslateXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)translateYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMICompositeTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TranslateYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)translateZProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMICompositeTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TranslateZProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)centerX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCenterX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterX(value));
}

- (double)centerY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCenterY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterY(value));
}

- (double)centerZ {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterZ(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCenterZ:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterZ(value));
}

- (double)rotationX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotationX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationX(value));
}

- (double)rotationY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotationY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationY(value));
}

- (double)rotationZ {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationZ(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotationZ:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationZ(value));
}

- (double)scaleX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaleX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setScaleX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScaleX(value));
}

- (double)scaleY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaleY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setScaleY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScaleY(value));
}

- (double)scaleZ {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaleZ(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setScaleZ:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScaleZ(value));
}

- (double)translateX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_TranslateX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTranslateX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_TranslateX(value));
}

- (double)translateY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_TranslateY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTranslateY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_TranslateY(value));
}

- (double)translateZ {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_TranslateZ(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTranslateZ:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_TranslateZ(value));
}

@end

@implementation WUXMMPerspectiveTransform3D

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Media3D::IPerspectiveTransform3D> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Media3D.PerspectiveTransform3D").Get(), &out));
    return [_createRtProxy<WUXMMPerspectiveTransform3D>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Media3D::IPerspectiveTransform3DStatics> WUXMMIPerspectiveTransform3DStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Media3D::IPerspectiveTransform3DStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Media3D.PerspectiveTransform3D").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)depthProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMIPerspectiveTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DepthProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)offsetXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMIPerspectiveTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OffsetXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)offsetYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMMIPerspectiveTransform3DStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OffsetYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)depth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::IPerspectiveTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_Depth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDepth:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::IPerspectiveTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_Depth(value));
}

- (double)offsetX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::IPerspectiveTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_OffsetX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOffsetX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::IPerspectiveTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_OffsetX(value));
}

- (double)offsetY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::IPerspectiveTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->get_OffsetY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOffsetY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Media3D::IPerspectiveTransform3D>(self);
    THROW_NS_IF_FAILED(_comInst->put_OffsetY(value));
}

@end

@implementation WUXMMMatrix3D {
    ABI::Windows::UI::Xaml::Media::Media3D::Matrix3D structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Media::Media3D::Matrix3D)s {
    WUXMMMatrix3D* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::Media::Media3D::Matrix3D*)internalStruct {
    return &structVal;
}
- (double)m11 {
    return structVal.M11;
}
- (void)setM11:(double)val {
    structVal.M11 = val;
}
- (double)m12 {
    return structVal.M12;
}
- (void)setM12:(double)val {
    structVal.M12 = val;
}
- (double)m13 {
    return structVal.M13;
}
- (void)setM13:(double)val {
    structVal.M13 = val;
}
- (double)m14 {
    return structVal.M14;
}
- (void)setM14:(double)val {
    structVal.M14 = val;
}
- (double)m21 {
    return structVal.M21;
}
- (void)setM21:(double)val {
    structVal.M21 = val;
}
- (double)m22 {
    return structVal.M22;
}
- (void)setM22:(double)val {
    structVal.M22 = val;
}
- (double)m23 {
    return structVal.M23;
}
- (void)setM23:(double)val {
    structVal.M23 = val;
}
- (double)m24 {
    return structVal.M24;
}
- (void)setM24:(double)val {
    structVal.M24 = val;
}
- (double)m31 {
    return structVal.M31;
}
- (void)setM31:(double)val {
    structVal.M31 = val;
}
- (double)m32 {
    return structVal.M32;
}
- (void)setM32:(double)val {
    structVal.M32 = val;
}
- (double)m33 {
    return structVal.M33;
}
- (void)setM33:(double)val {
    structVal.M33 = val;
}
- (double)m34 {
    return structVal.M34;
}
- (void)setM34:(double)val {
    structVal.M34 = val;
}
- (double)offsetX {
    return structVal.OffsetX;
}
- (void)setOffsetX:(double)val {
    structVal.OffsetX = val;
}
- (double)offsetY {
    return structVal.OffsetY;
}
- (void)setOffsetY:(double)val {
    structVal.OffsetY = val;
}
- (double)offsetZ {
    return structVal.OffsetZ;
}
- (void)setOffsetZ:(double)val {
    structVal.OffsetZ = val;
}
- (double)m44 {
    return structVal.M44;
}
- (void)setM44:(double)val {
    structVal.M44 = val;
}
@end
