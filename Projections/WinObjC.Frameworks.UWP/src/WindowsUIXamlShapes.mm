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

// WindowsUIXamlShapes.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Shapes.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlShapes.h"
#include "WindowsUIXamlShapes_priv.h"

@implementation WUXSShape

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Shapes::IShape> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Shapes::IShapeStatics> WUXSIShapeStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Shapes::IShapeStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Shapes.Shape").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)fillProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIShapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FillProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)strokeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIShapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StrokeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)strokeMiterLimitProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIShapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StrokeMiterLimitProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)strokeThicknessProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIShapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StrokeThicknessProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)strokeStartLineCapProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIShapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StrokeStartLineCapProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)strokeEndLineCapProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIShapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StrokeEndLineCapProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)strokeLineJoinProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIShapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StrokeLineJoinProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)strokeDashOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIShapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StrokeDashOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)strokeDashCapProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIShapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StrokeDashCapProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)strokeDashArrayProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIShapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StrokeDashArrayProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)stretchProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIShapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StretchProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMBrush*)fill {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->get_Fill(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setFill:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->put_Fill(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)stroke {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->get_Stroke(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setStroke:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->put_Stroke(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (double)strokeMiterLimit {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeMiterLimit(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setStrokeMiterLimit:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeMiterLimit(value));
}

- (double)strokeThickness {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeThickness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setStrokeThickness:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeThickness(value));
}

- (WUXMPenLineCap)strokeStartLineCap {
    ABI::Windows::UI::Xaml::Media::PenLineCap unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeStartLineCap(&unmarshalledReturn));
    return (WUXMPenLineCap)unmarshalledReturn;
}

- (void)setStrokeStartLineCap:(WUXMPenLineCap)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeStartLineCap((ABI::Windows::UI::Xaml::Media::PenLineCap)value));
}

- (WUXMPenLineCap)strokeEndLineCap {
    ABI::Windows::UI::Xaml::Media::PenLineCap unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeEndLineCap(&unmarshalledReturn));
    return (WUXMPenLineCap)unmarshalledReturn;
}

- (void)setStrokeEndLineCap:(WUXMPenLineCap)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeEndLineCap((ABI::Windows::UI::Xaml::Media::PenLineCap)value));
}

- (WUXMPenLineJoin)strokeLineJoin {
    ABI::Windows::UI::Xaml::Media::PenLineJoin unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeLineJoin(&unmarshalledReturn));
    return (WUXMPenLineJoin)unmarshalledReturn;
}

- (void)setStrokeLineJoin:(WUXMPenLineJoin)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeLineJoin((ABI::Windows::UI::Xaml::Media::PenLineJoin)value));
}

- (double)strokeDashOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeDashOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setStrokeDashOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeDashOffset(value));
}

- (WUXMPenLineCap)strokeDashCap {
    ABI::Windows::UI::Xaml::Media::PenLineCap unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeDashCap(&unmarshalledReturn));
    return (WUXMPenLineCap)unmarshalledReturn;
}

- (void)setStrokeDashCap:(WUXMPenLineCap)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeDashCap((ABI::Windows::UI::Xaml::Media::PenLineCap)value));
}

- (WUXMDoubleCollection*)strokeDashArray {
    ComPtr<IVector<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->get_StrokeDashArray(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMDoubleCollection>(unmarshalledReturn.Get());
}

- (void)setStrokeDashArray:(WUXMDoubleCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->put_StrokeDashArray(_getRtInterface<IVector<double>>(value).Get()));
}

- (WUXMStretch)stretch {
    ABI::Windows::UI::Xaml::Media::Stretch unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->get_Stretch(&unmarshalledReturn));
    return (WUXMStretch)unmarshalledReturn;
}

- (void)setStretch:(WUXMStretch)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->put_Stretch((ABI::Windows::UI::Xaml::Media::Stretch)value));
}

- (WUXMTransform*)geometryTransform {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITransform> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeometryTransform(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMTransform>(unmarshalledReturn.Get());
}

- (WUCCompositionBrush*)getAlphaMask {
    ComPtr<ABI::Windows::UI::Composition::ICompositionBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IShape2>(self);
    THROW_NS_IF_FAILED(_comInst->GetAlphaMask(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionBrush>(unmarshalledReturn.Get());
}

@end

@implementation WUXSEllipse

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Shapes::IEllipse> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Shapes.Ellipse").Get(), &out));
    return [_createRtProxy<WUXSEllipse>(out.Get()) retain];
}

@end

@implementation WUXSLine

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Shapes::ILine> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Shapes.Line").Get(), &out));
    return [_createRtProxy<WUXSLine>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Shapes::ILineStatics> WUXSILineStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Shapes::ILineStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Shapes.Line").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)x1Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSILineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_X1Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)y1Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSILineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Y1Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)x2Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSILineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_X2Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)y2Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSILineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Y2Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)x1 {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::ILine>(self);
    THROW_NS_IF_FAILED(_comInst->get_X1(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setX1:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::ILine>(self);
    THROW_NS_IF_FAILED(_comInst->put_X1(value));
}

- (double)y1 {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::ILine>(self);
    THROW_NS_IF_FAILED(_comInst->get_Y1(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setY1:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::ILine>(self);
    THROW_NS_IF_FAILED(_comInst->put_Y1(value));
}

- (double)x2 {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::ILine>(self);
    THROW_NS_IF_FAILED(_comInst->get_X2(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setX2:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::ILine>(self);
    THROW_NS_IF_FAILED(_comInst->put_X2(value));
}

- (double)y2 {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::ILine>(self);
    THROW_NS_IF_FAILED(_comInst->get_Y2(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setY2:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::ILine>(self);
    THROW_NS_IF_FAILED(_comInst->put_Y2(value));
}

@end

@implementation WUXSPath

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Shapes::IPath> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Shapes::IPathFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Shapes.Path").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Shapes::IPath> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WXIFrameworkElementOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WXIFrameworkElementOverrides)]) {
        typedOuter = Make<WXIFrameworkElementOverrides_RtProxy>();
        outer = typedOuter;
    }
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXSPath* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::Shapes::IPathStatics> WUXSIPathStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Shapes::IPathStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Shapes.Path").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)dataProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIPathStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DataProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMGeometry*)data {
    ComPtr<ABI::Windows::UI::Xaml::Media::IGeometry> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IPath>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMGeometry>(unmarshalledReturn.Get());
}

- (void)setData:(WUXMGeometry*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IPath>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(_getRtInterface<ABI::Windows::UI::Xaml::Media::IGeometry>(value).Get()));
}

@end

@implementation WUXSPolygon

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Shapes::IPolygon> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Shapes.Polygon").Get(), &out));
    return [_createRtProxy<WUXSPolygon>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Shapes::IPolygonStatics> WUXSIPolygonStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Shapes::IPolygonStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Shapes.Polygon").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)fillRuleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIPolygonStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FillRuleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)pointsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIPolygonStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMFillRule)fillRule {
    ABI::Windows::UI::Xaml::Media::FillRule unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IPolygon>(self);
    THROW_NS_IF_FAILED(_comInst->get_FillRule(&unmarshalledReturn));
    return (WUXMFillRule)unmarshalledReturn;
}

- (void)setFillRule:(WUXMFillRule)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IPolygon>(self);
    THROW_NS_IF_FAILED(_comInst->put_FillRule((ABI::Windows::UI::Xaml::Media::FillRule)value));
}

- (WUXMPointCollection*)points {
    ComPtr<IVector<ABI::Windows::Foundation::Point>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IPolygon>(self);
    THROW_NS_IF_FAILED(_comInst->get_Points(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMPointCollection>(unmarshalledReturn.Get());
}

- (void)setPoints:(WUXMPointCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IPolygon>(self);
    THROW_NS_IF_FAILED(_comInst->put_Points(_getRtInterface<IVector<ABI::Windows::Foundation::Point>>(value).Get()));
}

@end

@implementation WUXSPolyline

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Shapes::IPolyline> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Shapes.Polyline").Get(), &out));
    return [_createRtProxy<WUXSPolyline>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Shapes::IPolylineStatics> WUXSIPolylineStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Shapes::IPolylineStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Shapes.Polyline").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)fillRuleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIPolylineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FillRuleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)pointsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIPolylineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMFillRule)fillRule {
    ABI::Windows::UI::Xaml::Media::FillRule unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IPolyline>(self);
    THROW_NS_IF_FAILED(_comInst->get_FillRule(&unmarshalledReturn));
    return (WUXMFillRule)unmarshalledReturn;
}

- (void)setFillRule:(WUXMFillRule)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IPolyline>(self);
    THROW_NS_IF_FAILED(_comInst->put_FillRule((ABI::Windows::UI::Xaml::Media::FillRule)value));
}

- (WUXMPointCollection*)points {
    ComPtr<IVector<ABI::Windows::Foundation::Point>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IPolyline>(self);
    THROW_NS_IF_FAILED(_comInst->get_Points(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMPointCollection>(unmarshalledReturn.Get());
}

- (void)setPoints:(WUXMPointCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IPolyline>(self);
    THROW_NS_IF_FAILED(_comInst->put_Points(_getRtInterface<IVector<ABI::Windows::Foundation::Point>>(value).Get()));
}

@end

@implementation WUXSRectangle

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Shapes::IRectangle> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Shapes.Rectangle").Get(), &out));
    return [_createRtProxy<WUXSRectangle>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Shapes::IRectangleStatics> WUXSIRectangleStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Shapes::IRectangleStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Shapes.Rectangle").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)radiusXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIRectangleStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RadiusXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)radiusYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXSIRectangleStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RadiusYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)radiusX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IRectangle>(self);
    THROW_NS_IF_FAILED(_comInst->get_RadiusX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRadiusX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IRectangle>(self);
    THROW_NS_IF_FAILED(_comInst->put_RadiusX(value));
}

- (double)radiusY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IRectangle>(self);
    THROW_NS_IF_FAILED(_comInst->get_RadiusY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRadiusY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Shapes::IRectangle>(self);
    THROW_NS_IF_FAILED(_comInst->put_RadiusY(value));
}

@end

id RTProxiedIterableNSArray_RTProxiedIterableNSArray_WFPoint_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<IterableArrayAdapterObj<
        IIterable<IIterable<ABI::Windows::Foundation::Point>*>,
        RTIterableObj<IIterable<ABI::Windows::Foundation::Point>*,
                      IIterable<IIterable<ABI::Windows::Foundation::Point>*>,
                      RTProxiedIterableNSArray,
                      IIterable<ABI::Windows::Foundation::Point>*,
                      RTProxiedIterableNSArray_WFPoint_create,
                      ConvertToIterable<RTProxiedIterableNSArray,
                                        ABI::Windows::Foundation::Internal::AggregateType<IIterable<ABI::Windows::Foundation::Point>*,
                                                                                          IIterable<ABI::Windows::Foundation::Point>*>,
                                        RTProxiedIterableNSArray_WFPoint_create>>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WFPoint_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Foundation::Point>,
                                                 RTIterableObj<ABI::Windows::Foundation::Point,
                                                               IIterable<ABI::Windows::Foundation::Point>,
                                                               WFPoint,
                                                               ABI::Windows::Foundation::Point,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUXIPointer_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Xaml::Input::Pointer*>,
                                         RTArrayObj<ABI::Windows::UI::Xaml::Input::IPointer*,
                                                    IVectorView<ABI::Windows::UI::Xaml::Input::Pointer*>,
                                                    WUXIPointer,
                                                    ABI::Windows::UI::Xaml::Input::Pointer*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
