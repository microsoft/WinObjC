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

// WindowsUIXamlMedia.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Media.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlMedia.h"
#include "WindowsUIXamlMedia_priv.h"

@implementation WUXMVisualTreeHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IVisualTreeHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::IVisualTreeHelperStatics2> WUXMIVisualTreeHelperStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IVisualTreeHelperStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.VisualTreeHelper").Get(), &inst));
    return inst;
}

+ (NSArray* /* WUXCPPopup* */)getOpenPopups:(WXWindow*)window {
    ComPtr<IVectorView<ABI::Windows::UI::Xaml::Controls::Primitives::Popup*>> unmarshalledReturn;
    auto _comInst = WUXMIVisualTreeHelperStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetOpenPopups(_getRtInterface<ABI::Windows::UI::Xaml::IWindow>(window).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUXCPPopup_create(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Media::IVisualTreeHelperStatics> WUXMIVisualTreeHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IVisualTreeHelperStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.VisualTreeHelper").Get(), &inst));
    return inst;
}

+ (id<NSFastEnumeration> /* WXUIElement* */)findElementsInHostCoordinatesPoint:(WFPoint*)intersectingPoint subtree:(WXUIElement*)subtree {
    ComPtr<IIterable<ABI::Windows::UI::Xaml::UIElement*>> unmarshalledReturn;
    auto _comInst = WUXMIVisualTreeHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindElementsInHostCoordinatesPoint(*[intersectingPoint internalStruct],
                                                                    _getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(subtree).Get(),
                                                                    unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WXUIElement_create(unmarshalledReturn.Get());
}

+ (id<NSFastEnumeration> /* WXUIElement* */)findElementsInHostCoordinatesRect:(WFRect*)intersectingRect subtree:(WXUIElement*)subtree {
    ComPtr<IIterable<ABI::Windows::UI::Xaml::UIElement*>> unmarshalledReturn;
    auto _comInst = WUXMIVisualTreeHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindElementsInHostCoordinatesRect(*[intersectingRect internalStruct],
                                                                   _getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(subtree).Get(),
                                                                   unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WXUIElement_create(unmarshalledReturn.Get());
}

+ (id<NSFastEnumeration> /* WXUIElement* */)findAllElementsInHostCoordinatesPoint:(WFPoint*)intersectingPoint
                                                                          subtree:(WXUIElement*)subtree
                                                               includeAllElements:(BOOL)includeAllElements {
    ComPtr<IIterable<ABI::Windows::UI::Xaml::UIElement*>> unmarshalledReturn;
    auto _comInst = WUXMIVisualTreeHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllElementsInHostCoordinatesPoint(*[intersectingPoint internalStruct],
                                                                       _getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(subtree).Get(),
                                                                       (boolean)includeAllElements,
                                                                       unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WXUIElement_create(unmarshalledReturn.Get());
}

+ (id<NSFastEnumeration> /* WXUIElement* */)findAllElementsInHostCoordinatesRect:(WFRect*)intersectingRect
                                                                         subtree:(WXUIElement*)subtree
                                                              includeAllElements:(BOOL)includeAllElements {
    ComPtr<IIterable<ABI::Windows::UI::Xaml::UIElement*>> unmarshalledReturn;
    auto _comInst = WUXMIVisualTreeHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllElementsInHostCoordinatesRect(*[intersectingRect internalStruct],
                                                                      _getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(subtree).Get(),
                                                                      (boolean)includeAllElements,
                                                                      unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WXUIElement_create(unmarshalledReturn.Get());
}

+ (WXDependencyObject*)getChild:(WXDependencyObject*)reference childIndex:(int)childIndex {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = WUXMIVisualTreeHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetChild(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(reference).Get(),
                                          childIndex,
                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

+ (int)getChildrenCount:(WXDependencyObject*)reference {
    int unmarshalledReturn;
    auto _comInst = WUXMIVisualTreeHelperStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetChildrenCount(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(reference).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (WXDependencyObject*)getParent:(WXDependencyObject*)reference {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = WUXMIVisualTreeHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetParent(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(reference).Get(),
                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

+ (void)disconnectChildrenRecursive:(WXUIElement*)element {
    auto _comInst = WUXMIVisualTreeHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->DisconnectChildrenRecursive(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get()));
}

@end

@implementation WUXMPartialMediaFailureDetectedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.PartialMediaFailureDetectedEventArgs").Get(),
                                              &out));
    return [_createRtProxy<WUXMPartialMediaFailureDetectedEventArgs>(out.Get()) retain];
}

- (WMPFailedMediaStreamKind)streamKind {
    ABI::Windows::Media::Playback::FailedMediaStreamKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_StreamKind(&unmarshalledReturn));
    return (WMPFailedMediaStreamKind)unmarshalledReturn;
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WUXMMatrixHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IMatrixHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::IMatrixHelperStatics> WUXMIMatrixHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IMatrixHelperStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.MatrixHelper").Get(), &inst));
    return inst;
}

+ (WUXMMatrix*)identity {
    ABI::Windows::UI::Xaml::Media::Matrix unmarshalledReturn;
    auto _comInst = WUXMIMatrixHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Identity(&unmarshalledReturn));
    return WUXMMatrix_create(unmarshalledReturn);
}

+ (WUXMMatrix*)fromElements:(double)m11 m12:(double)m12 m21:(double)m21 m22:(double)m22 offsetX:(double)offsetX offsetY:(double)offsetY {
    ABI::Windows::UI::Xaml::Media::Matrix unmarshalledReturn;
    auto _comInst = WUXMIMatrixHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromElements(m11, m12, m21, m22, offsetX, offsetY, &unmarshalledReturn));
    return WUXMMatrix_create(unmarshalledReturn);
}

+ (BOOL)getIsIdentity:(WUXMMatrix*)target {
    boolean unmarshalledReturn;
    auto _comInst = WUXMIMatrixHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetIsIdentity(*[target internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (WFPoint*)transform:(WUXMMatrix*)target point:(WFPoint*)point {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = WUXMIMatrixHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Transform(*[target internalStruct], *[point internalStruct], &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

@end

@implementation WUXMBrushCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Media::IBrush*,
                      IVector<ABI::Windows::UI::Xaml::Media::Brush*>,
                      WUXMBrush,
                      ABI::Windows::UI::Xaml::Media::Brush*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, WUXMBrush, ABI::Windows::UI::Xaml::Media::IBrush*, ABI::Windows::UI::Xaml::Media::Brush*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Brush*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.BrushCollection").Get(), &out));
    return [_createRtProxy<WUXMBrushCollection>(out.Get()) retain];
}

@end

@implementation WUXMCompositionTarget

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::ICompositionTarget> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::ICompositionTargetStatics> WUXMICompositionTargetStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::ICompositionTargetStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.CompositionTarget").Get(), &inst));
    return inst;
}

+ (EventRegistrationToken)addRenderingEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WUXMICompositionTargetStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_Rendering(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeRenderingEvent:(EventRegistrationToken)token {
    auto _comInst = WUXMICompositionTargetStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_Rendering(token));
}

+ (EventRegistrationToken)addSurfaceContentsLostEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WUXMICompositionTargetStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_SurfaceContentsLost(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeSurfaceContentsLostEvent:(EventRegistrationToken)token {
    auto _comInst = WUXMICompositionTargetStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_SurfaceContentsLost(token));
}

@end

@implementation WUXMDoubleCollection {
    RTMutableArrayObj<double, IVector<double>, double, double, dummyObjCCreator, dummyWRLCreator> _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, double, double, double)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<double>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.DoubleCollection").Get(), &out));
    return [_createRtProxy<WUXMDoubleCollection>(out.Get()) retain];
}

@end

@implementation WUXMFontFamily

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IFontFamily> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXMFontFamily*)makeInstanceWithName:(NSString*)familyName {
    ComPtr<ABI::Windows::UI::Xaml::Media::IFontFamilyFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.FontFamily").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Media::IFontFamily> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    THROW_NS_IF_FAILED(factory->CreateInstanceWithName(nsStrToHstr(familyName).Get(), outer.Get(), &inner, &instance));
    WUXMFontFamily* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::Media::IFontFamilyStatics2> WUXMIFontFamilyStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IFontFamilyStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.FontFamily").Get(), &inst));
    return inst;
}

+ (WUXMFontFamily*)xamlAutoFontFamily {
    ComPtr<ABI::Windows::UI::Xaml::Media::IFontFamily> unmarshalledReturn;
    auto _comInst = WUXMIFontFamilyStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_XamlAutoFontFamily(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMFontFamily>(unmarshalledReturn.Get());
}

- (NSString*)source {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IFontFamily>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUXMMediaTransportControlsThumbnailRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IMediaTransportControlsThumbnailRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setThumbnailImage:(RTObject<WSSIInputStream>*)source {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IMediaTransportControlsThumbnailRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->SetThumbnailImage(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(source).Get()));
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IMediaTransportControlsThumbnailRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUXMPointCollection {
    RTMutableArrayObj<ABI::Windows::Foundation::Point,
                      IVector<ABI::Windows::Foundation::Point>,
                      WFPoint,
                      ABI::Windows::Foundation::Point,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, WFPoint, ABI::Windows::Foundation::Point, ABI::Windows::Foundation::Point)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::Foundation::Point>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.PointCollection").Get(), &out));
    return [_createRtProxy<WUXMPointCollection>(out.Get()) retain];
}

@end

@implementation WUXMRenderingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IRenderingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)renderingTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IRenderingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RenderingTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WUXMTimelineMarkerCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Media::ITimelineMarker*,
                      IVector<ABI::Windows::UI::Xaml::Media::TimelineMarker*>,
                      WUXMTimelineMarker,
                      ABI::Windows::UI::Xaml::Media::TimelineMarker*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WUXMTimelineMarker,
                         ABI::Windows::UI::Xaml::Media::ITimelineMarker*,
                         ABI::Windows::UI::Xaml::Media::TimelineMarker*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::TimelineMarker*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.TimelineMarkerCollection").Get(), &out));
    return [_createRtProxy<WUXMTimelineMarkerCollection>(out.Get()) retain];
}

@end

@implementation WUXMTransformCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Media::ITransform*,
                      IVector<ABI::Windows::UI::Xaml::Media::Transform*>,
                      WUXMTransform,
                      ABI::Windows::UI::Xaml::Media::Transform*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, WUXMTransform, ABI::Windows::UI::Xaml::Media::ITransform*, ABI::Windows::UI::Xaml::Media::Transform*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Transform*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.TransformCollection").Get(), &out));
    return [_createRtProxy<WUXMTransformCollection>(out.Get()) retain];
}

@end

@implementation WUXMBrush

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::IBrushStatics> WUXMIBrushStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrushStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Brush").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)opacityProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIBrushStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OpacityProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)transformProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIBrushStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TransformProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)relativeTransformProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIBrushStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RelativeTransformProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)opacity {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_Opacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOpacity:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_Opacity(value));
}

- (WUXMTransform*)transform {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITransform> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_Transform(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMTransform>(unmarshalledReturn.Get());
}

- (void)setTransform:(WUXMTransform*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_Transform(_getRtInterface<ABI::Windows::UI::Xaml::Media::ITransform>(value).Get()));
}

- (WUXMTransform*)relativeTransform {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITransform> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelativeTransform(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMTransform>(unmarshalledReturn.Get());
}

- (void)setRelativeTransform:(WUXMTransform*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_RelativeTransform(_getRtInterface<ABI::Windows::UI::Xaml::Media::ITransform>(value).Get()));
}

@end

@implementation WUXMCacheMode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::ICacheMode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXMGeneralTransform

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IGeneralTransform> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUXMGeneralTransform*)inverse {
    ComPtr<ABI::Windows::UI::Xaml::Media::IGeneralTransform> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGeneralTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_Inverse(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMGeneralTransform>(unmarshalledReturn.Get());
}

- (WFPoint*)transformPoint:(WFPoint*)point {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGeneralTransform>(self);
    THROW_NS_IF_FAILED(_comInst->TransformPoint(*[point internalStruct], &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (BOOL)tryTransform:(WFPoint*)inPoint outPoint:(WFPoint**)outPoint {
    ABI::Windows::Foundation::Point outPointOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGeneralTransform>(self);
    THROW_NS_IF_FAILED(_comInst->TryTransform(*[inPoint internalStruct], &outPointOutUnmarshaled, &unmarshalledReturn));
    *outPoint = WFPoint_create(outPointOutUnmarshaled);
    return (BOOL)unmarshalledReturn;
}

- (WFRect*)transformBounds:(WFRect*)rect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGeneralTransform>(self);
    THROW_NS_IF_FAILED(_comInst->TransformBounds(*[rect internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WUXMGeneralTransform*)inverseCore {
    ComPtr<ABI::Windows::UI::Xaml::Media::IGeneralTransform> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGeneralTransformOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->get_InverseCore(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMGeneralTransform>(unmarshalledReturn.Get());
}

- (BOOL)tryTransformCore:(WFPoint*)inPoint outPoint:(WFPoint**)outPoint {
    ABI::Windows::Foundation::Point outPointOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGeneralTransformOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->TryTransformCore(*[inPoint internalStruct], &outPointOutUnmarshaled, &unmarshalledReturn));
    *outPoint = WFPoint_create(outPointOutUnmarshaled);
    return (BOOL)unmarshalledReturn;
}

- (WFRect*)transformBoundsCore:(WFRect*)rect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGeneralTransformOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->TransformBoundsCore(*[rect internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

@end

@implementation WUXMGeometry

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IGeometry> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::IGeometryStatics> WUXMIGeometryStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IGeometryStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Geometry").Get(), &inst));
    return inst;
}

+ (WUXMGeometry*)empty {
    ComPtr<ABI::Windows::UI::Xaml::Media::IGeometry> unmarshalledReturn;
    auto _comInst = WUXMIGeometryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Empty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMGeometry>(unmarshalledReturn.Get());
}

+ (double)standardFlatteningTolerance {
    double unmarshalledReturn;
    auto _comInst = WUXMIGeometryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StandardFlatteningTolerance(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (WXDependencyProperty*)transformProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIGeometryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TransformProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMTransform*)transform {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITransform> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Transform(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMTransform>(unmarshalledReturn.Get());
}

- (void)setTransform:(WUXMTransform*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->put_Transform(_getRtInterface<ABI::Windows::UI::Xaml::Media::ITransform>(value).Get()));
}

- (WFRect*)bounds {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bounds(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

@end

@implementation WUXMImageSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IImageSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXMPathSegment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IPathSegment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXMProjection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IProjection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXMRateChangedRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IRateChangedRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.RateChangedRoutedEventArgs").Get(), &out));
    return [_createRtProxy<WUXMRateChangedRoutedEventArgs>(out.Get()) retain];
}

@end

@implementation WUXMTimelineMarker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITimelineMarker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.TimelineMarker").Get(), &out));
    return [_createRtProxy<WUXMTimelineMarker>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::ITimelineMarkerStatics> WUXMITimelineMarkerStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITimelineMarkerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.TimelineMarker").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)timeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMITimelineMarkerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TimeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)typeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMITimelineMarkerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TypeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)textProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMITimelineMarkerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TextProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)time {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITimelineMarker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Time(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setTime:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITimelineMarker>(self);
    THROW_NS_IF_FAILED(_comInst->put_Time(*[value internalStruct]));
}

- (NSString*)type {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITimelineMarker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setType:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITimelineMarker>(self);
    THROW_NS_IF_FAILED(_comInst->put_Type(nsStrToHstr(value).Get()));
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITimelineMarker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITimelineMarker>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

@end

@implementation WUXMTimelineMarkerRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITimelineMarkerRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.TimelineMarkerRoutedEventArgs").Get(), &out));
    return [_createRtProxy<WUXMTimelineMarkerRoutedEventArgs>(out.Get()) retain];
}

- (WUXMTimelineMarker*)marker {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITimelineMarker> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITimelineMarkerRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Marker(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMTimelineMarker>(unmarshalledReturn.Get());
}

- (void)setMarker:(WUXMTimelineMarker*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITimelineMarkerRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Marker(_getRtInterface<ABI::Windows::UI::Xaml::Media::ITimelineMarker>(value).Get()));
}

@end

@implementation WUXMBitmapCache

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBitmapCache> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.BitmapCache").Get(), &out));
    return [_createRtProxy<WUXMBitmapCache>(out.Get()) retain];
}

@end

@implementation WUXMMatrix3DProjection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IMatrix3DProjection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Matrix3DProjection").Get(), &out));
    return [_createRtProxy<WUXMMatrix3DProjection>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IMatrix3DProjectionStatics> WUXMIMatrix3DProjectionStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IMatrix3DProjectionStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Matrix3DProjection").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)projectionMatrixProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIMatrix3DProjectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ProjectionMatrixProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMMMatrix3D*)projectionMatrix {
    ABI::Windows::UI::Xaml::Media::Media3D::Matrix3D unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IMatrix3DProjection>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProjectionMatrix(&unmarshalledReturn));
    return WUXMMMatrix3D_create(unmarshalledReturn);
}

- (void)setProjectionMatrix:(WUXMMMatrix3D*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IMatrix3DProjection>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProjectionMatrix(*[value internalStruct]));
}

@end

@implementation WUXMPlaneProjection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IPlaneProjection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.PlaneProjection").Get(), &out));
    return [_createRtProxy<WUXMPlaneProjection>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IPlaneProjectionStatics> WUXMIPlaneProjectionStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IPlaneProjectionStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.PlaneProjection").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)localOffsetXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPlaneProjectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocalOffsetXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)localOffsetYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPlaneProjectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocalOffsetYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)localOffsetZProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPlaneProjectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocalOffsetZProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)rotationXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPlaneProjectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RotationXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)rotationYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPlaneProjectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RotationYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)rotationZProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPlaneProjectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RotationZProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)centerOfRotationXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPlaneProjectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterOfRotationXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)centerOfRotationYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPlaneProjectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterOfRotationYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)centerOfRotationZProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPlaneProjectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterOfRotationZProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)globalOffsetXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPlaneProjectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GlobalOffsetXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)globalOffsetYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPlaneProjectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GlobalOffsetYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)globalOffsetZProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPlaneProjectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GlobalOffsetZProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)projectionMatrixProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPlaneProjectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ProjectionMatrixProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)localOffsetX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalOffsetX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLocalOffsetX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->put_LocalOffsetX(value));
}

- (double)localOffsetY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalOffsetY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLocalOffsetY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->put_LocalOffsetY(value));
}

- (double)localOffsetZ {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalOffsetZ(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLocalOffsetZ:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->put_LocalOffsetZ(value));
}

- (double)rotationX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotationX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationX(value));
}

- (double)rotationY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotationY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationY(value));
}

- (double)rotationZ {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationZ(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotationZ:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationZ(value));
}

- (double)centerOfRotationX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterOfRotationX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCenterOfRotationX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterOfRotationX(value));
}

- (double)centerOfRotationY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterOfRotationY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCenterOfRotationY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterOfRotationY(value));
}

- (double)centerOfRotationZ {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterOfRotationZ(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCenterOfRotationZ:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterOfRotationZ(value));
}

- (double)globalOffsetX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->get_GlobalOffsetX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setGlobalOffsetX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->put_GlobalOffsetX(value));
}

- (double)globalOffsetY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->get_GlobalOffsetY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setGlobalOffsetY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->put_GlobalOffsetY(value));
}

- (double)globalOffsetZ {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->get_GlobalOffsetZ(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setGlobalOffsetZ:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->put_GlobalOffsetZ(value));
}

- (WUXMMMatrix3D*)projectionMatrix {
    ABI::Windows::UI::Xaml::Media::Media3D::Matrix3D unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPlaneProjection>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProjectionMatrix(&unmarshalledReturn));
    return WUXMMMatrix3D_create(unmarshalledReturn);
}

@end

@implementation WUXMRectangleGeometry

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IRectangleGeometry> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.RectangleGeometry").Get(), &out));
    return [_createRtProxy<WUXMRectangleGeometry>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IRectangleGeometryStatics> WUXMIRectangleGeometryStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IRectangleGeometryStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.RectangleGeometry").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)rectProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIRectangleGeometryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RectProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WFRect*)rect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IRectangleGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Rect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)setRect:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IRectangleGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->put_Rect(*[value internalStruct]));
}

@end

@implementation WUXMSolidColorBrush

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::ISolidColorBrush> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.SolidColorBrush").Get(), &out));
    return [_createRtProxy<WUXMSolidColorBrush>(out.Get()) retain];
}

static ComPtr<ABI::Windows::UI::Xaml::Media::ISolidColorBrushFactory> WUXMISolidColorBrushFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::ISolidColorBrushFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.SolidColorBrush").Get(), &inst));
    return inst;
}

+ (WUXMSolidColorBrush*)makeInstanceWithColor:(WUColor*)color {
    ComPtr<ABI::Windows::UI::Xaml::Media::ISolidColorBrush> unmarshalledReturn;
    auto _comInst = WUXMISolidColorBrushFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceWithColor(*[color internalStruct], unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXMSolidColorBrush>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::ISolidColorBrushStatics> WUXMISolidColorBrushStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::ISolidColorBrushStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.SolidColorBrush").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)colorProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMISolidColorBrushStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ColorProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUColor*)color {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ISolidColorBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_Color(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ISolidColorBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_Color(*[value internalStruct]));
}

@end

@implementation WUXMTransform

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITransform> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXMCompositeTransform

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::ICompositeTransform> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.CompositeTransform").Get(), &out));
    return [_createRtProxy<WUXMCompositeTransform>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::ICompositeTransformStatics> WUXMICompositeTransformStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::ICompositeTransformStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.CompositeTransform").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)centerXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMICompositeTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)centerYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMICompositeTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)scaleXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMICompositeTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ScaleXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)scaleYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMICompositeTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ScaleYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)skewXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMICompositeTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SkewXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)skewYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMICompositeTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SkewYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)rotationProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMICompositeTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RotationProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)translateXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMICompositeTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TranslateXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)translateYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMICompositeTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TranslateYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)centerX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCenterX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterX(value));
}

- (double)centerY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCenterY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterY(value));
}

- (double)scaleX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaleX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setScaleX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScaleX(value));
}

- (double)scaleY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaleY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setScaleY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScaleY(value));
}

- (double)skewX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_SkewX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSkewX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_SkewX(value));
}

- (double)skewY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_SkewY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSkewY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_SkewY(value));
}

- (double)rotation {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_Rotation(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotation:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_Rotation(value));
}

- (double)translateX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_TranslateX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTranslateX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_TranslateX(value));
}

- (double)translateY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_TranslateY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTranslateY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ICompositeTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_TranslateY(value));
}

@end

@implementation WUXMMatrixTransform

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IMatrixTransform> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.MatrixTransform").Get(), &out));
    return [_createRtProxy<WUXMMatrixTransform>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IMatrixTransformStatics> WUXMIMatrixTransformStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IMatrixTransformStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.MatrixTransform").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)matrixProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIMatrixTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MatrixProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMMatrix*)matrix {
    ABI::Windows::UI::Xaml::Media::Matrix unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IMatrixTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_Matrix(&unmarshalledReturn));
    return WUXMMatrix_create(unmarshalledReturn);
}

- (void)setMatrix:(WUXMMatrix*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IMatrixTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_Matrix(*[value internalStruct]));
}

@end

@implementation WUXMRotateTransform

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IRotateTransform> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.RotateTransform").Get(), &out));
    return [_createRtProxy<WUXMRotateTransform>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IRotateTransformStatics> WUXMIRotateTransformStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IRotateTransformStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.RotateTransform").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)centerXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIRotateTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)centerYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIRotateTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)angleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIRotateTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AngleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)centerX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IRotateTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCenterX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IRotateTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterX(value));
}

- (double)centerY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IRotateTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCenterY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IRotateTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterY(value));
}

- (double)angle {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IRotateTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_Angle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setAngle:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IRotateTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_Angle(value));
}

@end

@implementation WUXMScaleTransform

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IScaleTransform> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.ScaleTransform").Get(), &out));
    return [_createRtProxy<WUXMScaleTransform>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IScaleTransformStatics> WUXMIScaleTransformStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IScaleTransformStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.ScaleTransform").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)centerXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIScaleTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)centerYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIScaleTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)scaleXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIScaleTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ScaleXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)scaleYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIScaleTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ScaleYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)centerX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IScaleTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCenterX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IScaleTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterX(value));
}

- (double)centerY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IScaleTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCenterY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IScaleTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterY(value));
}

- (double)scaleX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IScaleTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaleX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setScaleX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IScaleTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScaleX(value));
}

- (double)scaleY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IScaleTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaleY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setScaleY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IScaleTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScaleY(value));
}

@end

@implementation WUXMSkewTransform

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::ISkewTransform> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.SkewTransform").Get(), &out));
    return [_createRtProxy<WUXMSkewTransform>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::ISkewTransformStatics> WUXMISkewTransformStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::ISkewTransformStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.SkewTransform").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)centerXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMISkewTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)centerYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMISkewTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)angleXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMISkewTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AngleXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)angleYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMISkewTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AngleYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)centerX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ISkewTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCenterX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ISkewTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterX(value));
}

- (double)centerY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ISkewTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCenterY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ISkewTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterY(value));
}

- (double)angleX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ISkewTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_AngleX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setAngleX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ISkewTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_AngleX(value));
}

- (double)angleY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ISkewTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_AngleY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setAngleY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ISkewTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_AngleY(value));
}

@end

@implementation WUXMTransformGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITransformGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.TransformGroup").Get(), &out));
    return [_createRtProxy<WUXMTransformGroup>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::ITransformGroupStatics> WUXMITransformGroupStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITransformGroupStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.TransformGroup").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)childrenProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMITransformGroupStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ChildrenProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMTransformCollection*)children {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Transform*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITransformGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Children(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMTransformCollection>(unmarshalledReturn.Get());
}

- (void)setChildren:(WUXMTransformCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITransformGroup>(self);
    THROW_NS_IF_FAILED(_comInst->put_Children(_getRtInterface<IVector<ABI::Windows::UI::Xaml::Media::Transform*>>(value).Get()));
}

- (WUXMMatrix*)value {
    ABI::Windows::UI::Xaml::Media::Matrix unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITransformGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return WUXMMatrix_create(unmarshalledReturn);
}

@end

@implementation WUXMTranslateTransform

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITranslateTransform> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.TranslateTransform").Get(), &out));
    return [_createRtProxy<WUXMTranslateTransform>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::ITranslateTransformStatics> WUXMITranslateTransformStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITranslateTransformStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.TranslateTransform").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)xProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMITranslateTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_XProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)yProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMITranslateTransformStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_YProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)x {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITranslateTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_X(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITranslateTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_X(value));
}

- (double)y {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITranslateTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_Y(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITranslateTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_Y(value));
}

@end

@implementation WUXMGeometryCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Media::IGeometry*,
                      IVector<ABI::Windows::UI::Xaml::Media::Geometry*>,
                      WUXMGeometry,
                      ABI::Windows::UI::Xaml::Media::Geometry*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, WUXMGeometry, ABI::Windows::UI::Xaml::Media::IGeometry*, ABI::Windows::UI::Xaml::Media::Geometry*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Geometry*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.GeometryCollection").Get(), &out));
    return [_createRtProxy<WUXMGeometryCollection>(out.Get()) retain];
}

@end

@implementation WUXMGradientStopCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Media::IGradientStop*,
                      IVector<ABI::Windows::UI::Xaml::Media::GradientStop*>,
                      WUXMGradientStop,
                      ABI::Windows::UI::Xaml::Media::GradientStop*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WUXMGradientStop,
                         ABI::Windows::UI::Xaml::Media::IGradientStop*,
                         ABI::Windows::UI::Xaml::Media::GradientStop*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::GradientStop*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.GradientStopCollection").Get(), &out));
    return [_createRtProxy<WUXMGradientStopCollection>(out.Get()) retain];
}

@end

@implementation WUXMPathFigureCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Media::IPathFigure*,
                      IVector<ABI::Windows::UI::Xaml::Media::PathFigure*>,
                      WUXMPathFigure,
                      ABI::Windows::UI::Xaml::Media::PathFigure*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WUXMPathFigure,
                         ABI::Windows::UI::Xaml::Media::IPathFigure*,
                         ABI::Windows::UI::Xaml::Media::PathFigure*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::PathFigure*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.PathFigureCollection").Get(), &out));
    return [_createRtProxy<WUXMPathFigureCollection>(out.Get()) retain];
}

@end

@implementation WUXMPathSegmentCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Media::IPathSegment*,
                      IVector<ABI::Windows::UI::Xaml::Media::PathSegment*>,
                      WUXMPathSegment,
                      ABI::Windows::UI::Xaml::Media::PathSegment*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WUXMPathSegment,
                         ABI::Windows::UI::Xaml::Media::IPathSegment*,
                         ABI::Windows::UI::Xaml::Media::PathSegment*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::PathSegment*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.PathSegmentCollection").Get(), &out));
    return [_createRtProxy<WUXMPathSegmentCollection>(out.Get()) retain];
}

@end

@implementation WUXMGradientStop

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IGradientStop> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.GradientStop").Get(), &out));
    return [_createRtProxy<WUXMGradientStop>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IGradientStopStatics> WUXMIGradientStopStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IGradientStopStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.GradientStop").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)colorProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIGradientStopStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ColorProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)offsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIGradientStopStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUColor*)color {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGradientStop>(self);
    THROW_NS_IF_FAILED(_comInst->get_Color(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGradientStop>(self);
    THROW_NS_IF_FAILED(_comInst->put_Color(*[value internalStruct]));
}

- (double)offset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGradientStop>(self);
    THROW_NS_IF_FAILED(_comInst->get_Offset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGradientStop>(self);
    THROW_NS_IF_FAILED(_comInst->put_Offset(value));
}

@end

@implementation WUXMPathFigure

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IPathFigure> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.PathFigure").Get(), &out));
    return [_createRtProxy<WUXMPathFigure>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IPathFigureStatics> WUXMIPathFigureStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IPathFigureStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.PathFigure").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)segmentsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPathFigureStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SegmentsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)startPointProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPathFigureStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StartPointProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isClosedProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPathFigureStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsClosedProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isFilledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPathFigureStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsFilledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMPathSegmentCollection*)segments {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::PathSegment*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPathFigure>(self);
    THROW_NS_IF_FAILED(_comInst->get_Segments(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMPathSegmentCollection>(unmarshalledReturn.Get());
}

- (void)setSegments:(WUXMPathSegmentCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPathFigure>(self);
    THROW_NS_IF_FAILED(_comInst->put_Segments(_getRtInterface<IVector<ABI::Windows::UI::Xaml::Media::PathSegment*>>(value).Get()));
}

- (WFPoint*)startPoint {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPathFigure>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartPoint(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setStartPoint:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPathFigure>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartPoint(*[value internalStruct]));
}

- (BOOL)isClosed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPathFigure>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsClosed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsClosed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPathFigure>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsClosed((boolean)value));
}

- (BOOL)isFilled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPathFigure>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsFilled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsFilled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPathFigure>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsFilled((boolean)value));
}

@end

@implementation WUXMArcSegment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IArcSegment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.ArcSegment").Get(), &out));
    return [_createRtProxy<WUXMArcSegment>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IArcSegmentStatics> WUXMIArcSegmentStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IArcSegmentStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.ArcSegment").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)pointProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIArcSegmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)sizeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIArcSegmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SizeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)rotationAngleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIArcSegmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RotationAngleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isLargeArcProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIArcSegmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsLargeArcProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)sweepDirectionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIArcSegmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SweepDirectionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WFPoint*)point {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IArcSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Point(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setPoint:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IArcSegment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Point(*[value internalStruct]));
}

- (WFSize*)size {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IArcSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (void)setSize:(WFSize*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IArcSegment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Size(*[value internalStruct]));
}

- (double)rotationAngle {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IArcSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationAngle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotationAngle:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IArcSegment>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationAngle(value));
}

- (BOOL)isLargeArc {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IArcSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsLargeArc(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsLargeArc:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IArcSegment>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsLargeArc((boolean)value));
}

- (WUXMSweepDirection)sweepDirection {
    ABI::Windows::UI::Xaml::Media::SweepDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IArcSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_SweepDirection(&unmarshalledReturn));
    return (WUXMSweepDirection)unmarshalledReturn;
}

- (void)setSweepDirection:(WUXMSweepDirection)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IArcSegment>(self);
    THROW_NS_IF_FAILED(_comInst->put_SweepDirection((ABI::Windows::UI::Xaml::Media::SweepDirection)value));
}

@end

@implementation WUXMBezierSegment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBezierSegment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.BezierSegment").Get(), &out));
    return [_createRtProxy<WUXMBezierSegment>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IBezierSegmentStatics> WUXMIBezierSegmentStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBezierSegmentStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.BezierSegment").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)point1Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIBezierSegmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Point1Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)point2Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIBezierSegmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Point2Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)point3Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIBezierSegmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Point3Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WFPoint*)point1 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IBezierSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Point1(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setPoint1:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IBezierSegment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Point1(*[value internalStruct]));
}

- (WFPoint*)point2 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IBezierSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Point2(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setPoint2:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IBezierSegment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Point2(*[value internalStruct]));
}

- (WFPoint*)point3 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IBezierSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Point3(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setPoint3:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IBezierSegment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Point3(*[value internalStruct]));
}

@end

@implementation WUXMEllipseGeometry

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IEllipseGeometry> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.EllipseGeometry").Get(), &out));
    return [_createRtProxy<WUXMEllipseGeometry>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IEllipseGeometryStatics> WUXMIEllipseGeometryStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IEllipseGeometryStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.EllipseGeometry").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)centerProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIEllipseGeometryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CenterProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)radiusXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIEllipseGeometryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RadiusXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)radiusYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIEllipseGeometryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RadiusYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WFPoint*)center {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IEllipseGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Center(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setCenter:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IEllipseGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->put_Center(*[value internalStruct]));
}

- (double)radiusX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IEllipseGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->get_RadiusX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRadiusX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IEllipseGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->put_RadiusX(value));
}

- (double)radiusY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IEllipseGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->get_RadiusY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRadiusY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IEllipseGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->put_RadiusY(value));
}

@end

@implementation WUXMGeometryGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IGeometryGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.GeometryGroup").Get(), &out));
    return [_createRtProxy<WUXMGeometryGroup>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IGeometryGroupStatics> WUXMIGeometryGroupStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IGeometryGroupStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.GeometryGroup").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)fillRuleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIGeometryGroupStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FillRuleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)childrenProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIGeometryGroupStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ChildrenProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMFillRule)fillRule {
    ABI::Windows::UI::Xaml::Media::FillRule unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGeometryGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_FillRule(&unmarshalledReturn));
    return (WUXMFillRule)unmarshalledReturn;
}

- (void)setFillRule:(WUXMFillRule)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGeometryGroup>(self);
    THROW_NS_IF_FAILED(_comInst->put_FillRule((ABI::Windows::UI::Xaml::Media::FillRule)value));
}

- (WUXMGeometryCollection*)children {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Geometry*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGeometryGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Children(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMGeometryCollection>(unmarshalledReturn.Get());
}

- (void)setChildren:(WUXMGeometryCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGeometryGroup>(self);
    THROW_NS_IF_FAILED(_comInst->put_Children(_getRtInterface<IVector<ABI::Windows::UI::Xaml::Media::Geometry*>>(value).Get()));
}

@end

@implementation WUXMGradientBrush

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IGradientBrush> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::IGradientBrushStatics> WUXMIGradientBrushStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IGradientBrushStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.GradientBrush").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)spreadMethodProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIGradientBrushStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SpreadMethodProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)mappingModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIGradientBrushStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MappingModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)colorInterpolationModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIGradientBrushStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ColorInterpolationModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)gradientStopsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIGradientBrushStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GradientStopsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMGradientSpreadMethod)spreadMethod {
    ABI::Windows::UI::Xaml::Media::GradientSpreadMethod unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGradientBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpreadMethod(&unmarshalledReturn));
    return (WUXMGradientSpreadMethod)unmarshalledReturn;
}

- (void)setSpreadMethod:(WUXMGradientSpreadMethod)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGradientBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_SpreadMethod((ABI::Windows::UI::Xaml::Media::GradientSpreadMethod)value));
}

- (WUXMBrushMappingMode)mappingMode {
    ABI::Windows::UI::Xaml::Media::BrushMappingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGradientBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_MappingMode(&unmarshalledReturn));
    return (WUXMBrushMappingMode)unmarshalledReturn;
}

- (void)setMappingMode:(WUXMBrushMappingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGradientBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_MappingMode((ABI::Windows::UI::Xaml::Media::BrushMappingMode)value));
}

- (WUXMColorInterpolationMode)colorInterpolationMode {
    ABI::Windows::UI::Xaml::Media::ColorInterpolationMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGradientBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorInterpolationMode(&unmarshalledReturn));
    return (WUXMColorInterpolationMode)unmarshalledReturn;
}

- (void)setColorInterpolationMode:(WUXMColorInterpolationMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGradientBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_ColorInterpolationMode((ABI::Windows::UI::Xaml::Media::ColorInterpolationMode)value));
}

- (WUXMGradientStopCollection*)gradientStops {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::GradientStop*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGradientBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_GradientStops(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMGradientStopCollection>(unmarshalledReturn.Get());
}

- (void)setGradientStops:(WUXMGradientStopCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IGradientBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_GradientStops(_getRtInterface<IVector<ABI::Windows::UI::Xaml::Media::GradientStop*>>(value).Get()));
}

@end

@implementation WUXMLineGeometry

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::ILineGeometry> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.LineGeometry").Get(), &out));
    return [_createRtProxy<WUXMLineGeometry>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::ILineGeometryStatics> WUXMILineGeometryStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::ILineGeometryStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.LineGeometry").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)startPointProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMILineGeometryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StartPointProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)endPointProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMILineGeometryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EndPointProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WFPoint*)startPoint {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ILineGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartPoint(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setStartPoint:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ILineGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartPoint(*[value internalStruct]));
}

- (WFPoint*)endPoint {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ILineGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndPoint(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setEndPoint:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ILineGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->put_EndPoint(*[value internalStruct]));
}

@end

@implementation WUXMLineSegment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::ILineSegment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.LineSegment").Get(), &out));
    return [_createRtProxy<WUXMLineSegment>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::ILineSegmentStatics> WUXMILineSegmentStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::ILineSegmentStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.LineSegment").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)pointProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMILineSegmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WFPoint*)point {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ILineSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Point(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setPoint:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ILineSegment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Point(*[value internalStruct]));
}

@end

@implementation WUXMPathGeometry

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IPathGeometry> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.PathGeometry").Get(), &out));
    return [_createRtProxy<WUXMPathGeometry>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IPathGeometryStatics> WUXMIPathGeometryStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IPathGeometryStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.PathGeometry").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)fillRuleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPathGeometryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FillRuleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)figuresProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPathGeometryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FiguresProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMFillRule)fillRule {
    ABI::Windows::UI::Xaml::Media::FillRule unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPathGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->get_FillRule(&unmarshalledReturn));
    return (WUXMFillRule)unmarshalledReturn;
}

- (void)setFillRule:(WUXMFillRule)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPathGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->put_FillRule((ABI::Windows::UI::Xaml::Media::FillRule)value));
}

- (WUXMPathFigureCollection*)figures {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::PathFigure*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPathGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->get_Figures(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMPathFigureCollection>(unmarshalledReturn.Get());
}

- (void)setFigures:(WUXMPathFigureCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPathGeometry>(self);
    THROW_NS_IF_FAILED(_comInst->put_Figures(_getRtInterface<IVector<ABI::Windows::UI::Xaml::Media::PathFigure*>>(value).Get()));
}

@end

@implementation WUXMPolyBezierSegment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IPolyBezierSegment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.PolyBezierSegment").Get(), &out));
    return [_createRtProxy<WUXMPolyBezierSegment>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IPolyBezierSegmentStatics> WUXMIPolyBezierSegmentStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IPolyBezierSegmentStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.PolyBezierSegment").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)pointsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPolyBezierSegmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMPointCollection*)points {
    ComPtr<IVector<ABI::Windows::Foundation::Point>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPolyBezierSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Points(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMPointCollection>(unmarshalledReturn.Get());
}

- (void)setPoints:(WUXMPointCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPolyBezierSegment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Points(_getRtInterface<IVector<ABI::Windows::Foundation::Point>>(value).Get()));
}

@end

@implementation WUXMPolyLineSegment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IPolyLineSegment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.PolyLineSegment").Get(), &out));
    return [_createRtProxy<WUXMPolyLineSegment>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IPolyLineSegmentStatics> WUXMIPolyLineSegmentStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IPolyLineSegmentStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.PolyLineSegment").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)pointsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPolyLineSegmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMPointCollection*)points {
    ComPtr<IVector<ABI::Windows::Foundation::Point>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPolyLineSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Points(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMPointCollection>(unmarshalledReturn.Get());
}

- (void)setPoints:(WUXMPointCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPolyLineSegment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Points(_getRtInterface<IVector<ABI::Windows::Foundation::Point>>(value).Get()));
}

@end

@implementation WUXMPolyQuadraticBezierSegment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IPolyQuadraticBezierSegment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.PolyQuadraticBezierSegment").Get(), &out));
    return [_createRtProxy<WUXMPolyQuadraticBezierSegment>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IPolyQuadraticBezierSegmentStatics> WUXMIPolyQuadraticBezierSegmentStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IPolyQuadraticBezierSegmentStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.PolyQuadraticBezierSegment").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)pointsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIPolyQuadraticBezierSegmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMPointCollection*)points {
    ComPtr<IVector<ABI::Windows::Foundation::Point>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPolyQuadraticBezierSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Points(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMPointCollection>(unmarshalledReturn.Get());
}

- (void)setPoints:(WUXMPointCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IPolyQuadraticBezierSegment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Points(_getRtInterface<IVector<ABI::Windows::Foundation::Point>>(value).Get()));
}

@end

@implementation WUXMQuadraticBezierSegment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IQuadraticBezierSegment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.QuadraticBezierSegment").Get(), &out));
    return [_createRtProxy<WUXMQuadraticBezierSegment>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IQuadraticBezierSegmentStatics> WUXMIQuadraticBezierSegmentStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IQuadraticBezierSegmentStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.QuadraticBezierSegment").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)point1Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIQuadraticBezierSegmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Point1Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)point2Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIQuadraticBezierSegmentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Point2Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WFPoint*)point1 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IQuadraticBezierSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Point1(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setPoint1:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IQuadraticBezierSegment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Point1(*[value internalStruct]));
}

- (WFPoint*)point2 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IQuadraticBezierSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Point2(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setPoint2:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IQuadraticBezierSegment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Point2(*[value internalStruct]));
}

@end

@implementation WUXMTileBrush

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITileBrush> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::ITileBrushStatics> WUXMITileBrushStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITileBrushStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.TileBrush").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)alignmentXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMITileBrushStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AlignmentXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)alignmentYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMITileBrushStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AlignmentYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)stretchProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMITileBrushStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StretchProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMAlignmentX)alignmentX {
    ABI::Windows::UI::Xaml::Media::AlignmentX unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITileBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlignmentX(&unmarshalledReturn));
    return (WUXMAlignmentX)unmarshalledReturn;
}

- (void)setAlignmentX:(WUXMAlignmentX)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITileBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_AlignmentX((ABI::Windows::UI::Xaml::Media::AlignmentX)value));
}

- (WUXMAlignmentY)alignmentY {
    ABI::Windows::UI::Xaml::Media::AlignmentY unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITileBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlignmentY(&unmarshalledReturn));
    return (WUXMAlignmentY)unmarshalledReturn;
}

- (void)setAlignmentY:(WUXMAlignmentY)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITileBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_AlignmentY((ABI::Windows::UI::Xaml::Media::AlignmentY)value));
}

- (WUXMStretch)stretch {
    ABI::Windows::UI::Xaml::Media::Stretch unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITileBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_Stretch(&unmarshalledReturn));
    return (WUXMStretch)unmarshalledReturn;
}

- (void)setStretch:(WUXMStretch)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ITileBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_Stretch((ABI::Windows::UI::Xaml::Media::Stretch)value));
}

@end

@implementation WUXMImageBrush

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::IImageBrush> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.ImageBrush").Get(), &out));
    return [_createRtProxy<WUXMImageBrush>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::IImageBrushStatics> WUXMIImageBrushStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::IImageBrushStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.ImageBrush").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)imageSourceProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMIImageBrushStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ImageSourceProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMImageSource*)imageSource {
    ComPtr<ABI::Windows::UI::Xaml::Media::IImageSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IImageBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImageSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMImageSource>(unmarshalledReturn.Get());
}

- (void)setImageSource:(WUXMImageSource*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IImageBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_ImageSource(_getRtInterface<ABI::Windows::UI::Xaml::Media::IImageSource>(value).Get()));
}

- (EventRegistrationToken)addImageFailedEvent:(WXExceptionRoutedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IImageBrush>(self);
    THROW_NS_IF_FAILED(_comInst->add_ImageFailed(Make<WXExceptionRoutedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeImageFailedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IImageBrush>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ImageFailed(token));
}

- (EventRegistrationToken)addImageOpenedEvent:(WXRoutedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IImageBrush>(self);
    THROW_NS_IF_FAILED(_comInst->add_ImageOpened(Make<WXRoutedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeImageOpenedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::IImageBrush>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ImageOpened(token));
}

@end

@implementation WUXMLinearGradientBrush

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::ILinearGradientBrush> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.LinearGradientBrush").Get(), &out));
    return [_createRtProxy<WUXMLinearGradientBrush>(out.Get()) retain];
}

static ComPtr<ABI::Windows::UI::Xaml::Media::ILinearGradientBrushFactory> WUXMILinearGradientBrushFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::ILinearGradientBrushFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.LinearGradientBrush").Get(), &inst));
    return inst;
}

+ (WUXMLinearGradientBrush*)makeInstanceWithGradientStopCollectionAndAngle:(WUXMGradientStopCollection*)gradientStopCollection
                                                                     angle:(double)angle {
    ComPtr<ABI::Windows::UI::Xaml::Media::ILinearGradientBrush> unmarshalledReturn;
    auto _comInst = WUXMILinearGradientBrushFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceWithGradientStopCollectionAndAngle(
        _getRtInterface<IVector<ABI::Windows::UI::Xaml::Media::GradientStop*>>(gradientStopCollection).Get(),
        angle,
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXMLinearGradientBrush>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::ILinearGradientBrushStatics> WUXMILinearGradientBrushStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::ILinearGradientBrushStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.LinearGradientBrush").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)startPointProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMILinearGradientBrushStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StartPointProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)endPointProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMILinearGradientBrushStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EndPointProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WFPoint*)startPoint {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ILinearGradientBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartPoint(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setStartPoint:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ILinearGradientBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartPoint(*[value internalStruct]));
}

- (WFPoint*)endPoint {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ILinearGradientBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndPoint(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setEndPoint:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::ILinearGradientBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_EndPoint(*[value internalStruct]));
}

@end

@implementation WUXMMatrix {
    ABI::Windows::UI::Xaml::Media::Matrix structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Media::Matrix)s {
    WUXMMatrix* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::Media::Matrix*)internalStruct {
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
@end
id RTProxiedIterableNSArray_WXUIElement_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::UI::Xaml::UIElement*>,
                                                 RTIterableObj<ABI::Windows::UI::Xaml::IUIElement*,
                                                               IIterable<ABI::Windows::UI::Xaml::UIElement*>,
                                                               WXUIElement,
                                                               ABI::Windows::UI::Xaml::UIElement*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WUXCPPopup_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Xaml::Controls::Primitives::Popup*>,
                                         RTArrayObj<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup*,
                                                    IVectorView<ABI::Windows::UI::Xaml::Controls::Primitives::Popup*>,
                                                    WUXCPPopup,
                                                    ABI::Windows::UI::Xaml::Controls::Primitives::Popup*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
