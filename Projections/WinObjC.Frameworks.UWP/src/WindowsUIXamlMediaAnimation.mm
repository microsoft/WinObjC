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

// WindowsUIXamlMediaAnimation.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Media.Animation.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlMediaAnimation.h"
#include "WindowsUIXamlMediaAnimation_priv.h"

@implementation WUXMAKeyTimeHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IKeyTimeHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IKeyTimeHelperStatics> WUXMAIKeyTimeHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IKeyTimeHelperStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.KeyTimeHelper").Get(),
                                                       &inst));
    return inst;
}

+ (WUXMAKeyTime*)fromTimeSpan:(WFTimeSpan*)timeSpan {
    ABI::Windows::UI::Xaml::Media::Animation::KeyTime unmarshalledReturn;
    auto _comInst = WUXMAIKeyTimeHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromTimeSpan(*[timeSpan internalStruct], &unmarshalledReturn));
    return WUXMAKeyTime_create(unmarshalledReturn);
}

@end

@implementation WUXMARepeatBehaviorHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IRepeatBehaviorHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IRepeatBehaviorHelperStatics> WUXMAIRepeatBehaviorHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IRepeatBehaviorHelperStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.RepeatBehaviorHelper").Get(), &inst));
    return inst;
}

+ (WUXMARepeatBehavior*)forever {
    ABI::Windows::UI::Xaml::Media::Animation::RepeatBehavior unmarshalledReturn;
    auto _comInst = WUXMAIRepeatBehaviorHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Forever(&unmarshalledReturn));
    return WUXMARepeatBehavior_create(unmarshalledReturn);
}

+ (WUXMARepeatBehavior*)fromCount:(double)count {
    ABI::Windows::UI::Xaml::Media::Animation::RepeatBehavior unmarshalledReturn;
    auto _comInst = WUXMAIRepeatBehaviorHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromCount(count, &unmarshalledReturn));
    return WUXMARepeatBehavior_create(unmarshalledReturn);
}

+ (WUXMARepeatBehavior*)fromDuration:(WFTimeSpan*)duration {
    ABI::Windows::UI::Xaml::Media::Animation::RepeatBehavior unmarshalledReturn;
    auto _comInst = WUXMAIRepeatBehaviorHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromDuration(*[duration internalStruct], &unmarshalledReturn));
    return WUXMARepeatBehavior_create(unmarshalledReturn);
}

+ (BOOL)getHasCount:(WUXMARepeatBehavior*)target {
    boolean unmarshalledReturn;
    auto _comInst = WUXMAIRepeatBehaviorHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetHasCount(*[target internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)getHasDuration:(WUXMARepeatBehavior*)target {
    boolean unmarshalledReturn;
    auto _comInst = WUXMAIRepeatBehaviorHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetHasDuration(*[target internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)equals:(WUXMARepeatBehavior*)target value:(WUXMARepeatBehavior*)value {
    boolean unmarshalledReturn;
    auto _comInst = WUXMAIRepeatBehaviorHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Equals(*[target internalStruct], *[value internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUXMATransitionCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Media::Animation::ITransition*,
                      IVector<ABI::Windows::UI::Xaml::Media::Animation::Transition*>,
                      WUXMATransition,
                      ABI::Windows::UI::Xaml::Media::Animation::Transition*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WUXMATransition,
                         ABI::Windows::UI::Xaml::Media::Animation::ITransition*,
                         ABI::Windows::UI::Xaml::Media::Animation::Transition*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Animation::Transition*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.TransitionCollection").Get(), &out));
    return [_createRtProxy<WUXMATransitionCollection>(out.Get()) retain];
}

@end

@implementation WUXMAColorKeyFrameCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Media::Animation::IColorKeyFrame*,
                      IVector<ABI::Windows::UI::Xaml::Media::Animation::ColorKeyFrame*>,
                      WUXMAColorKeyFrame,
                      ABI::Windows::UI::Xaml::Media::Animation::ColorKeyFrame*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WUXMAColorKeyFrame,
                         ABI::Windows::UI::Xaml::Media::Animation::IColorKeyFrame*,
                         ABI::Windows::UI::Xaml::Media::Animation::ColorKeyFrame*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Animation::ColorKeyFrame*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ColorKeyFrameCollection").Get(),
                                              &out));
    return [_createRtProxy<WUXMAColorKeyFrameCollection>(out.Get()) retain];
}

@end

@implementation WUXMADoubleKeyFrameCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame*,
                      IVector<ABI::Windows::UI::Xaml::Media::Animation::DoubleKeyFrame*>,
                      WUXMADoubleKeyFrame,
                      ABI::Windows::UI::Xaml::Media::Animation::DoubleKeyFrame*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WUXMADoubleKeyFrame,
                         ABI::Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame*,
                         ABI::Windows::UI::Xaml::Media::Animation::DoubleKeyFrame*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Animation::DoubleKeyFrame*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DoubleKeyFrameCollection").Get(),
                                              &out));
    return [_createRtProxy<WUXMADoubleKeyFrameCollection>(out.Get()) retain];
}

@end

@implementation WUXMAObjectKeyFrameCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Media::Animation::IObjectKeyFrame*,
                      IVector<ABI::Windows::UI::Xaml::Media::Animation::ObjectKeyFrame*>,
                      WUXMAObjectKeyFrame,
                      ABI::Windows::UI::Xaml::Media::Animation::ObjectKeyFrame*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WUXMAObjectKeyFrame,
                         ABI::Windows::UI::Xaml::Media::Animation::IObjectKeyFrame*,
                         ABI::Windows::UI::Xaml::Media::Animation::ObjectKeyFrame*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Animation::ObjectKeyFrame*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ObjectKeyFrameCollection").Get(),
                                              &out));
    return [_createRtProxy<WUXMAObjectKeyFrameCollection>(out.Get()) retain];
}

@end

@implementation WUXMAPointKeyFrameCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Media::Animation::IPointKeyFrame*,
                      IVector<ABI::Windows::UI::Xaml::Media::Animation::PointKeyFrame*>,
                      WUXMAPointKeyFrame,
                      ABI::Windows::UI::Xaml::Media::Animation::PointKeyFrame*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WUXMAPointKeyFrame,
                         ABI::Windows::UI::Xaml::Media::Animation::IPointKeyFrame*,
                         ABI::Windows::UI::Xaml::Media::Animation::PointKeyFrame*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Animation::PointKeyFrame*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PointKeyFrameCollection").Get(),
                                              &out));
    return [_createRtProxy<WUXMAPointKeyFrameCollection>(out.Get()) retain];
}

@end

@implementation WUXMATimelineCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Media::Animation::ITimeline*,
                      IVector<ABI::Windows::UI::Xaml::Media::Animation::Timeline*>,
                      WUXMATimeline,
                      ABI::Windows::UI::Xaml::Media::Animation::Timeline*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj,
                         WUXMATimeline,
                         ABI::Windows::UI::Xaml::Media::Animation::ITimeline*,
                         ABI::Windows::UI::Xaml::Media::Animation::Timeline*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Animation::Timeline*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.TimelineCollection").Get(), &out));
    return [_createRtProxy<WUXMATimelineCollection>(out.Get()) retain];
}

@end

@implementation WUXMAColorKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IColorKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IColorKeyFrameStatics> WUXMAIColorKeyFrameStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IColorKeyFrameStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ColorKeyFrame").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)valueProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIColorKeyFrameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ValueProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)keyTimeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIColorKeyFrameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KeyTimeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUColor*)value {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setValue:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(*[value internalStruct]));
}

- (WUXMAKeyTime*)keyTime {
    ABI::Windows::UI::Xaml::Media::Animation::KeyTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyTime(&unmarshalledReturn));
    return WUXMAKeyTime_create(unmarshalledReturn);
}

- (void)setKeyTime:(WUXMAKeyTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyTime(*[value internalStruct]));
}

@end

@implementation WUXMADoubleKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDoubleKeyFrameStatics> WUXMAIDoubleKeyFrameStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDoubleKeyFrameStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DoubleKeyFrame").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)valueProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDoubleKeyFrameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ValueProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)keyTimeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDoubleKeyFrameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KeyTimeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)value {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setValue:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(value));
}

- (WUXMAKeyTime*)keyTime {
    ABI::Windows::UI::Xaml::Media::Animation::KeyTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyTime(&unmarshalledReturn));
    return WUXMAKeyTime_create(unmarshalledReturn);
}

- (void)setKeyTime:(WUXMAKeyTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyTime(*[value internalStruct]));
}

@end

@implementation WUXMAEasingFunctionBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBaseStatics> WUXMAIEasingFunctionBaseStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBaseStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.EasingFunctionBase").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)easingModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIEasingFunctionBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EasingModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMAEasingMode)easingMode {
    ABI::Windows::UI::Xaml::Media::Animation::EasingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_EasingMode(&unmarshalledReturn));
    return (WUXMAEasingMode)unmarshalledReturn;
}

- (void)setEasingMode:(WUXMAEasingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_EasingMode((ABI::Windows::UI::Xaml::Media::Animation::EasingMode)value));
}

- (double)ease:(double)normalizedTime {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>(self);
    THROW_NS_IF_FAILED(_comInst->Ease(normalizedTime, &unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXMAKeySpline

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IKeySpline> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.KeySpline").Get(), &out));
    return [_createRtProxy<WUXMAKeySpline>(out.Get()) retain];
}

- (WFPoint*)controlPoint1 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IKeySpline>(self);
    THROW_NS_IF_FAILED(_comInst->get_ControlPoint1(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setControlPoint1:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IKeySpline>(self);
    THROW_NS_IF_FAILED(_comInst->put_ControlPoint1(*[value internalStruct]));
}

- (WFPoint*)controlPoint2 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IKeySpline>(self);
    THROW_NS_IF_FAILED(_comInst->get_ControlPoint2(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setControlPoint2:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IKeySpline>(self);
    THROW_NS_IF_FAILED(_comInst->put_ControlPoint2(*[value internalStruct]));
}

@end

@implementation WUXMANavigationTransitionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)getNavigationStateCore {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetNavigationStateCore(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNavigationStateCore:(NSString*)navigationState {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->SetNavigationStateCore(nsStrToHstr(navigationState).Get()));
}

@end

@implementation WUXMAObjectKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IObjectKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IObjectKeyFrameStatics> WUXMAIObjectKeyFrameStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IObjectKeyFrameStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ObjectKeyFrame").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)valueProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIObjectKeyFrameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ValueProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)keyTimeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIObjectKeyFrameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KeyTimeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IObjectKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IObjectKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value([value comObj].Get()));
}

- (WUXMAKeyTime*)keyTime {
    ABI::Windows::UI::Xaml::Media::Animation::KeyTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IObjectKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyTime(&unmarshalledReturn));
    return WUXMAKeyTime_create(unmarshalledReturn);
}

- (void)setKeyTime:(WUXMAKeyTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IObjectKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyTime(*[value internalStruct]));
}

@end

@implementation WUXMAPointKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointKeyFrameStatics> WUXMAIPointKeyFrameStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointKeyFrameStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PointKeyFrame").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)valueProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPointKeyFrameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ValueProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)keyTimeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPointKeyFrameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KeyTimeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WFPoint*)value {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setValue:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(*[value internalStruct]));
}

- (WUXMAKeyTime*)keyTime {
    ABI::Windows::UI::Xaml::Media::Animation::KeyTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyTime(&unmarshalledReturn));
    return WUXMAKeyTime_create(unmarshalledReturn);
}

- (void)setKeyTime:(WUXMAKeyTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyTime(*[value internalStruct]));
}

@end

@implementation WUXMATimeline

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ITimeline> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ITimelineStatics> WUXMAITimelineStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ITimelineStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.Timeline").Get(), &inst));
    return inst;
}

+ (BOOL)allowDependentAnimations {
    boolean unmarshalledReturn;
    auto _comInst = WUXMAITimelineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllowDependentAnimations(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setAllowDependentAnimations:(BOOL)value {
    auto _comInst = WUXMAITimelineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_AllowDependentAnimations((boolean)value));
}

+ (WXDependencyProperty*)autoReverseProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAITimelineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AutoReverseProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)beginTimeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAITimelineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BeginTimeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)durationProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAITimelineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DurationProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)speedRatioProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAITimelineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SpeedRatioProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fillBehaviorProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAITimelineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FillBehaviorProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)repeatBehaviorProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAITimelineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RepeatBehaviorProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (BOOL)autoReverse {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoReverse(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAutoReverse:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoReverse((boolean)value));
}

- (id /* WFTimeSpan* */)beginTime {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(self);
    THROW_NS_IF_FAILED(_comInst->get_BeginTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setBeginTime:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(self);
    THROW_NS_IF_FAILED(_comInst->put_BeginTime(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (WXDuration*)duration {
    ABI::Windows::UI::Xaml::Duration unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WXDuration_create(unmarshalledReturn);
}

- (void)setDuration:(WXDuration*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duration(*[value internalStruct]));
}

- (double)speedRatio {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpeedRatio(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSpeedRatio:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(self);
    THROW_NS_IF_FAILED(_comInst->put_SpeedRatio(value));
}

- (WUXMAFillBehavior)fillBehavior {
    ABI::Windows::UI::Xaml::Media::Animation::FillBehavior unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(self);
    THROW_NS_IF_FAILED(_comInst->get_FillBehavior(&unmarshalledReturn));
    return (WUXMAFillBehavior)unmarshalledReturn;
}

- (void)setFillBehavior:(WUXMAFillBehavior)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(self);
    THROW_NS_IF_FAILED(_comInst->put_FillBehavior((ABI::Windows::UI::Xaml::Media::Animation::FillBehavior)value));
}

- (WUXMARepeatBehavior*)repeatBehavior {
    ABI::Windows::UI::Xaml::Media::Animation::RepeatBehavior unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(self);
    THROW_NS_IF_FAILED(_comInst->get_RepeatBehavior(&unmarshalledReturn));
    return WUXMARepeatBehavior_create(unmarshalledReturn);
}

- (void)setRepeatBehavior:(WUXMARepeatBehavior*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(self);
    THROW_NS_IF_FAILED(_comInst->put_RepeatBehavior(*[value internalStruct]));
}

- (EventRegistrationToken)addCompletedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(self);
    THROW_NS_IF_FAILED(_comInst->add_Completed(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Completed(token));
}

@end

@implementation WUXMATransition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ITransition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXMAAddDeleteThemeTransition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IAddDeleteThemeTransition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.AddDeleteThemeTransition").Get(),
                                              &out));
    return [_createRtProxy<WUXMAAddDeleteThemeTransition>(out.Get()) retain];
}

@end

@implementation WUXMABackEase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IBackEase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.BackEase").Get(), &out));
    return [_createRtProxy<WUXMABackEase>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IBackEaseStatics> WUXMAIBackEaseStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IBackEaseStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.BackEase").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)amplitudeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIBackEaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AmplitudeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)amplitude {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IBackEase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Amplitude(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setAmplitude:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IBackEase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Amplitude(value));
}

@end

@implementation WUXMABeginStoryboard

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IBeginStoryboard> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.BeginStoryboard").Get(), &out));
    return [_createRtProxy<WUXMABeginStoryboard>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IBeginStoryboardStatics> WUXMAIBeginStoryboardStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IBeginStoryboardStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.BeginStoryboard").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)storyboardProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIBeginStoryboardStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StoryboardProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMAStoryboard*)storyboard {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IBeginStoryboard>(self);
    THROW_NS_IF_FAILED(_comInst->get_Storyboard(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAStoryboard>(unmarshalledReturn.Get());
}

- (void)setStoryboard:(WUXMAStoryboard*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IBeginStoryboard>(self);
    THROW_NS_IF_FAILED(_comInst->put_Storyboard(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard>(value).Get()));
}

@end

@implementation WUXMABounceEase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IBounceEase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.BounceEase").Get(), &out));
    return [_createRtProxy<WUXMABounceEase>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IBounceEaseStatics> WUXMAIBounceEaseStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IBounceEaseStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.BounceEase").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)bouncesProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIBounceEaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BouncesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)bouncinessProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIBounceEaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BouncinessProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (int)bounces {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IBounceEase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bounces(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBounces:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IBounceEase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bounces(value));
}

- (double)bounciness {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IBounceEase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bounciness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBounciness:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IBounceEase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bounciness(value));
}

@end

@implementation WUXMACircleEase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ICircleEase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.CircleEase").Get(), &out));
    return [_createRtProxy<WUXMACircleEase>(out.Get()) retain];
}

@end

@implementation WUXMAColorAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ColorAnimation").Get(), &out));
    return [_createRtProxy<WUXMAColorAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimationStatics> WUXMAIColorAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ColorAnimation").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)fromProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIColorAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FromProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)toProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIColorAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ToProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)byProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIColorAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ByProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)easingFunctionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIColorAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EasingFunctionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)enableDependentAnimationProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIColorAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EnableDependentAnimationProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (id /* WUColor* */)from {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_From(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setFrom:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_From(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)to {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_To(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setTo:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_To(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)by {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_By(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setBy:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_By(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (WUXMAEasingFunctionBase*)easingFunction {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_EasingFunction(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAEasingFunctionBase>(unmarshalledReturn.Get());
}

- (void)setEasingFunction:(WUXMAEasingFunctionBase*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimation>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_EasingFunction(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>(value).Get()));
}

- (BOOL)enableDependentAnimation {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnableDependentAnimation(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnableDependentAnimation:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_EnableDependentAnimation((boolean)value));
}

@end

@implementation WUXMAColorAnimationUsingKeyFrames

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimationUsingKeyFrames> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ColorAnimationUsingKeyFrames").Get(),
                                              &out));
    return [_createRtProxy<WUXMAColorAnimationUsingKeyFrames>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimationUsingKeyFramesStatics> WUXMAIColorAnimationUsingKeyFramesStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimationUsingKeyFramesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ColorAnimationUsingKeyFrames").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)enableDependentAnimationProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIColorAnimationUsingKeyFramesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EnableDependentAnimationProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMAColorKeyFrameCollection*)keyFrames {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Animation::ColorKeyFrame*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimationUsingKeyFrames>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyFrames(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAColorKeyFrameCollection>(unmarshalledReturn.Get());
}

- (BOOL)enableDependentAnimation {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimationUsingKeyFrames>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnableDependentAnimation(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnableDependentAnimation:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IColorAnimationUsingKeyFrames>(self);
    THROW_NS_IF_FAILED(_comInst->put_EnableDependentAnimation((boolean)value));
}

@end

@implementation WUXMAContentThemeTransition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IContentThemeTransition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ContentThemeTransition").Get(),
                                              &out));
    return [_createRtProxy<WUXMAContentThemeTransition>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IContentThemeTransitionStatics> WUXMAIContentThemeTransitionStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IContentThemeTransitionStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ContentThemeTransition").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)horizontalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIContentThemeTransitionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HorizontalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)verticalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIContentThemeTransitionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VerticalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)horizontalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IContentThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHorizontalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IContentThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->put_HorizontalOffset(value));
}

- (double)verticalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IContentThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setVerticalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IContentThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->put_VerticalOffset(value));
}

@end

@implementation WUXMACubicEase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ICubicEase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.CubicEase").Get(), &out));
    return [_createRtProxy<WUXMACubicEase>(out.Get()) retain];
}

@end

@implementation WUXMADiscreteColorKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDiscreteColorKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DiscreteColorKeyFrame").Get(),
                                              &out));
    return [_createRtProxy<WUXMADiscreteColorKeyFrame>(out.Get()) retain];
}

@end

@implementation WUXMADiscreteDoubleKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDiscreteDoubleKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DiscreteDoubleKeyFrame").Get(),
                                              &out));
    return [_createRtProxy<WUXMADiscreteDoubleKeyFrame>(out.Get()) retain];
}

@end

@implementation WUXMADiscreteObjectKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDiscreteObjectKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DiscreteObjectKeyFrame").Get(),
                                              &out));
    return [_createRtProxy<WUXMADiscreteObjectKeyFrame>(out.Get()) retain];
}

@end

@implementation WUXMADiscretePointKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDiscretePointKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DiscretePointKeyFrame").Get(),
                                              &out));
    return [_createRtProxy<WUXMADiscretePointKeyFrame>(out.Get()) retain];
}

@end

@implementation WUXMADoubleAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DoubleAnimation").Get(), &out));
    return [_createRtProxy<WUXMADoubleAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimationStatics> WUXMAIDoubleAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DoubleAnimation").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)fromProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDoubleAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FromProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)toProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDoubleAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ToProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)byProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDoubleAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ByProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)easingFunctionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDoubleAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EasingFunctionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)enableDependentAnimationProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDoubleAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EnableDependentAnimationProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (id /* double */)from {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_From(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (void)setFrom:(id /* double */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_From(BuildNullable<double>(value)));
}

- (id /* double */)to {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_To(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (void)setTo:(id /* double */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_To(BuildNullable<double>(value)));
}

- (id /* double */)by {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_By(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (void)setBy:(id /* double */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_By(BuildNullable<double>(value)));
}

- (WUXMAEasingFunctionBase*)easingFunction {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_EasingFunction(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAEasingFunctionBase>(unmarshalledReturn.Get());
}

- (void)setEasingFunction:(WUXMAEasingFunctionBase*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimation>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_EasingFunction(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>(value).Get()));
}

- (BOOL)enableDependentAnimation {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnableDependentAnimation(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnableDependentAnimation:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_EnableDependentAnimation((boolean)value));
}

@end

@implementation WUXMADoubleAnimationUsingKeyFrames

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimationUsingKeyFrames> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DoubleAnimationUsingKeyFrames").Get(), &out));
    return [_createRtProxy<WUXMADoubleAnimationUsingKeyFrames>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimationUsingKeyFramesStatics> WUXMAIDoubleAnimationUsingKeyFramesStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimationUsingKeyFramesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DoubleAnimationUsingKeyFrames").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)enableDependentAnimationProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDoubleAnimationUsingKeyFramesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EnableDependentAnimationProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMADoubleKeyFrameCollection*)keyFrames {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Animation::DoubleKeyFrame*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimationUsingKeyFrames>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyFrames(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMADoubleKeyFrameCollection>(unmarshalledReturn.Get());
}

- (BOOL)enableDependentAnimation {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimationUsingKeyFrames>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnableDependentAnimation(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnableDependentAnimation:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDoubleAnimationUsingKeyFrames>(self);
    THROW_NS_IF_FAILED(_comInst->put_EnableDependentAnimation((boolean)value));
}

@end

@implementation WUXMADragItemThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDragItemThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DragItemThemeAnimation").Get(),
                                              &out));
    return [_createRtProxy<WUXMADragItemThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDragItemThemeAnimationStatics> WUXMAIDragItemThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDragItemThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DragItemThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)targetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDragItemThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)targetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDragItemThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDragItemThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetName(nsStrToHstr(value).Get()));
}

@end

@implementation WUXMADragOverThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DragOverThemeAnimation").Get(),
                                              &out));
    return [_createRtProxy<WUXMADragOverThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimationStatics> WUXMAIDragOverThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DragOverThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)targetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDragOverThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)toOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDragOverThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ToOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)directionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDragOverThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DirectionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)targetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetName(nsStrToHstr(value).Get()));
}

- (double)toOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setToOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToOffset(value));
}

- (WUXCPAnimationDirection)direction {
    ABI::Windows::UI::Xaml::Controls::Primitives::AnimationDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Direction(&unmarshalledReturn));
    return (WUXCPAnimationDirection)unmarshalledReturn;
}

- (void)setDirection:(WUXCPAnimationDirection)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_Direction((ABI::Windows::UI::Xaml::Controls::Primitives::AnimationDirection)value));
}

@end

@implementation WUXMADrillInThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DrillInThemeAnimation").Get(),
                                              &out));
    return [_createRtProxy<WUXMADrillInThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimationStatics> WUXMAIDrillInThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DrillInThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)entranceTargetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDrillInThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EntranceTargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)entranceTargetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDrillInThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EntranceTargetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)exitTargetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDrillInThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExitTargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)exitTargetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDrillInThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExitTargetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)entranceTargetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_EntranceTargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setEntranceTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_EntranceTargetName(nsStrToHstr(value).Get()));
}

- (WXDependencyObject*)entranceTarget {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_EntranceTarget(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setEntranceTarget:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_EntranceTarget(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

- (NSString*)exitTargetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExitTargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setExitTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExitTargetName(nsStrToHstr(value).Get()));
}

- (WXDependencyObject*)exitTarget {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExitTarget(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setExitTarget:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExitTarget(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

@end

@implementation WUXMADrillOutThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DrillOutThemeAnimation").Get(),
                                              &out));
    return [_createRtProxy<WUXMADrillOutThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimationStatics> WUXMAIDrillOutThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DrillOutThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)entranceTargetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDrillOutThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EntranceTargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)entranceTargetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDrillOutThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EntranceTargetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)exitTargetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDrillOutThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExitTargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)exitTargetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDrillOutThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExitTargetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)entranceTargetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_EntranceTargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setEntranceTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_EntranceTargetName(nsStrToHstr(value).Get()));
}

- (WXDependencyObject*)entranceTarget {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_EntranceTarget(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setEntranceTarget:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_EntranceTarget(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

- (NSString*)exitTargetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExitTargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setExitTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExitTargetName(nsStrToHstr(value).Get()));
}

- (WXDependencyObject*)exitTarget {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExitTarget(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setExitTarget:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExitTarget(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

@end

@implementation WUXMADropTargetItemThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDropTargetItemThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DropTargetItemThemeAnimation").Get(),
                                              &out));
    return [_createRtProxy<WUXMADropTargetItemThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDropTargetItemThemeAnimationStatics> WUXMAIDropTargetItemThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDropTargetItemThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DropTargetItemThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)targetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIDropTargetItemThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)targetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDropTargetItemThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IDropTargetItemThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetName(nsStrToHstr(value).Get()));
}

@end

@implementation WUXMAEasingColorKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingColorKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.EasingColorKeyFrame").Get(), &out));
    return [_createRtProxy<WUXMAEasingColorKeyFrame>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingColorKeyFrameStatics> WUXMAIEasingColorKeyFrameStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingColorKeyFrameStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.EasingColorKeyFrame").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)easingFunctionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIEasingColorKeyFrameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EasingFunctionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMAEasingFunctionBase*)easingFunction {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingColorKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_EasingFunction(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAEasingFunctionBase>(unmarshalledReturn.Get());
}

- (void)setEasingFunction:(WUXMAEasingFunctionBase*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingColorKeyFrame>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_EasingFunction(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>(value).Get()));
}

@end

@implementation WUXMAEasingDoubleKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingDoubleKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.EasingDoubleKeyFrame").Get(), &out));
    return [_createRtProxy<WUXMAEasingDoubleKeyFrame>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingDoubleKeyFrameStatics> WUXMAIEasingDoubleKeyFrameStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingDoubleKeyFrameStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.EasingDoubleKeyFrame").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)easingFunctionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIEasingDoubleKeyFrameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EasingFunctionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMAEasingFunctionBase*)easingFunction {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingDoubleKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_EasingFunction(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAEasingFunctionBase>(unmarshalledReturn.Get());
}

- (void)setEasingFunction:(WUXMAEasingFunctionBase*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingDoubleKeyFrame>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_EasingFunction(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>(value).Get()));
}

@end

@implementation WUXMAEasingPointKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingPointKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.EasingPointKeyFrame").Get(), &out));
    return [_createRtProxy<WUXMAEasingPointKeyFrame>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingPointKeyFrameStatics> WUXMAIEasingPointKeyFrameStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingPointKeyFrameStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.EasingPointKeyFrame").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)easingFunctionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIEasingPointKeyFrameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EasingFunctionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMAEasingFunctionBase*)easingFunction {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingPointKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_EasingFunction(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAEasingFunctionBase>(unmarshalledReturn.Get());
}

- (void)setEasingFunction:(WUXMAEasingFunctionBase*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingPointKeyFrame>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_EasingFunction(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>(value).Get()));
}

@end

@implementation WUXMAEdgeUIThemeTransition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEdgeUIThemeTransition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.EdgeUIThemeTransition").Get(),
                                              &out));
    return [_createRtProxy<WUXMAEdgeUIThemeTransition>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEdgeUIThemeTransitionStatics> WUXMAIEdgeUIThemeTransitionStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEdgeUIThemeTransitionStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.EdgeUIThemeTransition").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)edgeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIEdgeUIThemeTransitionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EdgeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXCPEdgeTransitionLocation)edge {
    ABI::Windows::UI::Xaml::Controls::Primitives::EdgeTransitionLocation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEdgeUIThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Edge(&unmarshalledReturn));
    return (WUXCPEdgeTransitionLocation)unmarshalledReturn;
}

- (void)setEdge:(WUXCPEdgeTransitionLocation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEdgeUIThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->put_Edge((ABI::Windows::UI::Xaml::Controls::Primitives::EdgeTransitionLocation)value));
}

@end

@implementation WUXMAElasticEase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IElasticEase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ElasticEase").Get(), &out));
    return [_createRtProxy<WUXMAElasticEase>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IElasticEaseStatics> WUXMAIElasticEaseStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IElasticEaseStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ElasticEase").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)oscillationsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIElasticEaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OscillationsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)springinessProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIElasticEaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SpringinessProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (int)oscillations {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IElasticEase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Oscillations(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOscillations:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IElasticEase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Oscillations(value));
}

- (double)springiness {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IElasticEase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Springiness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSpringiness:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IElasticEase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Springiness(value));
}

@end

@implementation WUXMAEntranceThemeTransition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEntranceThemeTransition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.EntranceThemeTransition").Get(),
                                              &out));
    return [_createRtProxy<WUXMAEntranceThemeTransition>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEntranceThemeTransitionStatics> WUXMAIEntranceThemeTransitionStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEntranceThemeTransitionStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.EntranceThemeTransition").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)fromHorizontalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIEntranceThemeTransitionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FromHorizontalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fromVerticalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIEntranceThemeTransitionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FromVerticalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isStaggeringEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIEntranceThemeTransitionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsStaggeringEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)fromHorizontalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEntranceThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_FromHorizontalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFromHorizontalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEntranceThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->put_FromHorizontalOffset(value));
}

- (double)fromVerticalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEntranceThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_FromVerticalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFromVerticalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEntranceThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->put_FromVerticalOffset(value));
}

- (BOOL)isStaggeringEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEntranceThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStaggeringEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsStaggeringEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IEntranceThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsStaggeringEnabled((boolean)value));
}

@end

@implementation WUXMAExponentialEase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IExponentialEase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ExponentialEase").Get(), &out));
    return [_createRtProxy<WUXMAExponentialEase>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IExponentialEaseStatics> WUXMAIExponentialEaseStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IExponentialEaseStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ExponentialEase").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)exponentProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIExponentialEaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExponentProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)exponent {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IExponentialEase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Exponent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setExponent:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IExponentialEase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Exponent(value));
}

@end

@implementation WUXMAFadeInThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IFadeInThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.FadeInThemeAnimation").Get(), &out));
    return [_createRtProxy<WUXMAFadeInThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IFadeInThemeAnimationStatics> WUXMAIFadeInThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IFadeInThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.FadeInThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)targetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIFadeInThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)targetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IFadeInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IFadeInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetName(nsStrToHstr(value).Get()));
}

@end

@implementation WUXMAFadeOutThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IFadeOutThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.FadeOutThemeAnimation").Get(),
                                              &out));
    return [_createRtProxy<WUXMAFadeOutThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IFadeOutThemeAnimationStatics> WUXMAIFadeOutThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IFadeOutThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.FadeOutThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)targetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIFadeOutThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)targetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IFadeOutThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IFadeOutThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetName(nsStrToHstr(value).Get()));
}

@end

@implementation WUXMALinearColorKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ILinearColorKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.LinearColorKeyFrame").Get(), &out));
    return [_createRtProxy<WUXMALinearColorKeyFrame>(out.Get()) retain];
}

@end

@implementation WUXMALinearDoubleKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ILinearDoubleKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.LinearDoubleKeyFrame").Get(), &out));
    return [_createRtProxy<WUXMALinearDoubleKeyFrame>(out.Get()) retain];
}

@end

@implementation WUXMALinearPointKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ILinearPointKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.LinearPointKeyFrame").Get(), &out));
    return [_createRtProxy<WUXMALinearPointKeyFrame>(out.Get()) retain];
}

@end

@implementation WUXMAObjectAnimationUsingKeyFrames

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IObjectAnimationUsingKeyFrames> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ObjectAnimationUsingKeyFrames").Get(), &out));
    return [_createRtProxy<WUXMAObjectAnimationUsingKeyFrames>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IObjectAnimationUsingKeyFramesStatics> WUXMAIObjectAnimationUsingKeyFramesStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IObjectAnimationUsingKeyFramesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ObjectAnimationUsingKeyFrames").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)enableDependentAnimationProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIObjectAnimationUsingKeyFramesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EnableDependentAnimationProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMAObjectKeyFrameCollection*)keyFrames {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Animation::ObjectKeyFrame*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IObjectAnimationUsingKeyFrames>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyFrames(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAObjectKeyFrameCollection>(unmarshalledReturn.Get());
}

- (BOOL)enableDependentAnimation {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IObjectAnimationUsingKeyFrames>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnableDependentAnimation(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnableDependentAnimation:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IObjectAnimationUsingKeyFrames>(self);
    THROW_NS_IF_FAILED(_comInst->put_EnableDependentAnimation((boolean)value));
}

@end

@implementation WUXMAPaneThemeTransition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPaneThemeTransition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PaneThemeTransition").Get(), &out));
    return [_createRtProxy<WUXMAPaneThemeTransition>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPaneThemeTransitionStatics> WUXMAIPaneThemeTransitionStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPaneThemeTransitionStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PaneThemeTransition").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)edgeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPaneThemeTransitionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EdgeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXCPEdgeTransitionLocation)edge {
    ABI::Windows::UI::Xaml::Controls::Primitives::EdgeTransitionLocation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPaneThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Edge(&unmarshalledReturn));
    return (WUXCPEdgeTransitionLocation)unmarshalledReturn;
}

- (void)setEdge:(WUXCPEdgeTransitionLocation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPaneThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->put_Edge((ABI::Windows::UI::Xaml::Controls::Primitives::EdgeTransitionLocation)value));
}

@end

@implementation WUXMAPointAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PointAnimation").Get(), &out));
    return [_createRtProxy<WUXMAPointAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimationStatics> WUXMAIPointAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PointAnimation").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)fromProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPointAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FromProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)toProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPointAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ToProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)byProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPointAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ByProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)easingFunctionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPointAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EasingFunctionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)enableDependentAnimationProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPointAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EnableDependentAnimationProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (id /* WFPoint* */)from {
    ComPtr<IReference<ABI::Windows::Foundation::Point>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_From(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFPoint, ABI::Windows::Foundation::Point>::convert(unmarshalledReturn.Get());
}

- (void)setFrom:(id /* WFPoint* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_From(BuildNullable<ABI::Windows::Foundation::Point>(value)));
}

- (id /* WFPoint* */)to {
    ComPtr<IReference<ABI::Windows::Foundation::Point>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_To(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFPoint, ABI::Windows::Foundation::Point>::convert(unmarshalledReturn.Get());
}

- (void)setTo:(id /* WFPoint* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_To(BuildNullable<ABI::Windows::Foundation::Point>(value)));
}

- (id /* WFPoint* */)by {
    ComPtr<IReference<ABI::Windows::Foundation::Point>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_By(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFPoint, ABI::Windows::Foundation::Point>::convert(unmarshalledReturn.Get());
}

- (void)setBy:(id /* WFPoint* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_By(BuildNullable<ABI::Windows::Foundation::Point>(value)));
}

- (WUXMAEasingFunctionBase*)easingFunction {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_EasingFunction(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAEasingFunctionBase>(unmarshalledReturn.Get());
}

- (void)setEasingFunction:(WUXMAEasingFunctionBase*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimation>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_EasingFunction(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>(value).Get()));
}

- (BOOL)enableDependentAnimation {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnableDependentAnimation(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnableDependentAnimation:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_EnableDependentAnimation((boolean)value));
}

@end

@implementation WUXMAPointAnimationUsingKeyFrames

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimationUsingKeyFrames> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PointAnimationUsingKeyFrames").Get(),
                                              &out));
    return [_createRtProxy<WUXMAPointAnimationUsingKeyFrames>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimationUsingKeyFramesStatics> WUXMAIPointAnimationUsingKeyFramesStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimationUsingKeyFramesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PointAnimationUsingKeyFrames").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)enableDependentAnimationProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPointAnimationUsingKeyFramesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EnableDependentAnimationProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMAPointKeyFrameCollection*)keyFrames {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Animation::PointKeyFrame*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimationUsingKeyFrames>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyFrames(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAPointKeyFrameCollection>(unmarshalledReturn.Get());
}

- (BOOL)enableDependentAnimation {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimationUsingKeyFrames>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnableDependentAnimation(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnableDependentAnimation:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointAnimationUsingKeyFrames>(self);
    THROW_NS_IF_FAILED(_comInst->put_EnableDependentAnimation((boolean)value));
}

@end

@implementation WUXMAPointerDownThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointerDownThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PointerDownThemeAnimation").Get(),
                                              &out));
    return [_createRtProxy<WUXMAPointerDownThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointerDownThemeAnimationStatics> WUXMAIPointerDownThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointerDownThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PointerDownThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)targetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPointerDownThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)targetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointerDownThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointerDownThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetName(nsStrToHstr(value).Get()));
}

@end

@implementation WUXMAPointerUpThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointerUpThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PointerUpThemeAnimation").Get(),
                                              &out));
    return [_createRtProxy<WUXMAPointerUpThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointerUpThemeAnimationStatics> WUXMAIPointerUpThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPointerUpThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PointerUpThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)targetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPointerUpThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)targetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointerUpThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPointerUpThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetName(nsStrToHstr(value).Get()));
}

@end

@implementation WUXMAPopInThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPopInThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PopInThemeAnimation").Get(), &out));
    return [_createRtProxy<WUXMAPopInThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPopInThemeAnimationStatics> WUXMAIPopInThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPopInThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PopInThemeAnimation").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)targetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPopInThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fromHorizontalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPopInThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FromHorizontalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fromVerticalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPopInThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FromVerticalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)targetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPopInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPopInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetName(nsStrToHstr(value).Get()));
}

- (double)fromHorizontalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPopInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FromHorizontalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFromHorizontalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPopInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_FromHorizontalOffset(value));
}

- (double)fromVerticalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPopInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FromVerticalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFromVerticalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPopInThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_FromVerticalOffset(value));
}

@end

@implementation WUXMAPopOutThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPopOutThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PopOutThemeAnimation").Get(), &out));
    return [_createRtProxy<WUXMAPopOutThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPopOutThemeAnimationStatics> WUXMAIPopOutThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPopOutThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PopOutThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)targetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPopOutThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)targetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPopOutThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPopOutThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetName(nsStrToHstr(value).Get()));
}

@end

@implementation WUXMAPopupThemeTransition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPopupThemeTransition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PopupThemeTransition").Get(), &out));
    return [_createRtProxy<WUXMAPopupThemeTransition>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPopupThemeTransitionStatics> WUXMAIPopupThemeTransitionStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPopupThemeTransitionStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PopupThemeTransition").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)fromHorizontalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPopupThemeTransitionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FromHorizontalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fromVerticalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPopupThemeTransitionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FromVerticalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)fromHorizontalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPopupThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_FromHorizontalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFromHorizontalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPopupThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->put_FromHorizontalOffset(value));
}

- (double)fromVerticalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPopupThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_FromVerticalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFromVerticalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPopupThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->put_FromVerticalOffset(value));
}

@end

@implementation WUXMAPowerEase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPowerEase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PowerEase").Get(), &out));
    return [_createRtProxy<WUXMAPowerEase>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPowerEaseStatics> WUXMAIPowerEaseStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IPowerEaseStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.PowerEase").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)powerProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIPowerEaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PowerProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)power {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPowerEase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Power(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPower:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IPowerEase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Power(value));
}

@end

@implementation WUXMAQuadraticEase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IQuadraticEase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.QuadraticEase").Get(), &out));
    return [_createRtProxy<WUXMAQuadraticEase>(out.Get()) retain];
}

@end

@implementation WUXMAQuarticEase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IQuarticEase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.QuarticEase").Get(), &out));
    return [_createRtProxy<WUXMAQuarticEase>(out.Get()) retain];
}

@end

@implementation WUXMAQuinticEase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IQuinticEase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.QuinticEase").Get(), &out));
    return [_createRtProxy<WUXMAQuinticEase>(out.Get()) retain];
}

@end

@implementation WUXMAReorderThemeTransition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IReorderThemeTransition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ReorderThemeTransition").Get(),
                                              &out));
    return [_createRtProxy<WUXMAReorderThemeTransition>(out.Get()) retain];
}

@end

@implementation WUXMARepositionThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.RepositionThemeAnimation").Get(),
                                              &out));
    return [_createRtProxy<WUXMARepositionThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimationStatics> WUXMAIRepositionThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.RepositionThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)targetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIRepositionThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fromHorizontalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIRepositionThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FromHorizontalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fromVerticalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIRepositionThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FromVerticalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)targetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetName(nsStrToHstr(value).Get()));
}

- (double)fromHorizontalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FromHorizontalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFromHorizontalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_FromHorizontalOffset(value));
}

- (double)fromVerticalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FromVerticalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFromVerticalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_FromVerticalOffset(value));
}

@end

@implementation WUXMARepositionThemeTransition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeTransition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.RepositionThemeTransition").Get(),
                                              &out));
    return [_createRtProxy<WUXMARepositionThemeTransition>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeTransitionStatics2> WUXMAIRepositionThemeTransitionStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeTransitionStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.RepositionThemeTransition").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)isStaggeringEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIRepositionThemeTransitionStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsStaggeringEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (BOOL)isStaggeringEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeTransition2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStaggeringEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsStaggeringEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IRepositionThemeTransition2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsStaggeringEnabled((boolean)value));
}

@end

@implementation WUXMASineEase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISineEase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SineEase").Get(), &out));
    return [_createRtProxy<WUXMASineEase>(out.Get()) retain];
}

@end

@implementation WUXMASplineColorKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplineColorKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SplineColorKeyFrame").Get(), &out));
    return [_createRtProxy<WUXMASplineColorKeyFrame>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplineColorKeyFrameStatics> WUXMAISplineColorKeyFrameStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplineColorKeyFrameStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SplineColorKeyFrame").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)keySplineProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplineColorKeyFrameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KeySplineProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMAKeySpline*)keySpline {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IKeySpline> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplineColorKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeySpline(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAKeySpline>(unmarshalledReturn.Get());
}

- (void)setKeySpline:(WUXMAKeySpline*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplineColorKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeySpline(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::IKeySpline>(value).Get()));
}

@end

@implementation WUXMASplineDoubleKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplineDoubleKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SplineDoubleKeyFrame").Get(), &out));
    return [_createRtProxy<WUXMASplineDoubleKeyFrame>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplineDoubleKeyFrameStatics> WUXMAISplineDoubleKeyFrameStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplineDoubleKeyFrameStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SplineDoubleKeyFrame").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)keySplineProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplineDoubleKeyFrameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KeySplineProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMAKeySpline*)keySpline {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IKeySpline> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplineDoubleKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeySpline(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAKeySpline>(unmarshalledReturn.Get());
}

- (void)setKeySpline:(WUXMAKeySpline*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplineDoubleKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeySpline(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::IKeySpline>(value).Get()));
}

@end

@implementation WUXMASplinePointKeyFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplinePointKeyFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SplinePointKeyFrame").Get(), &out));
    return [_createRtProxy<WUXMASplinePointKeyFrame>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplinePointKeyFrameStatics> WUXMAISplinePointKeyFrameStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplinePointKeyFrameStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SplinePointKeyFrame").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)keySplineProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplinePointKeyFrameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KeySplineProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMAKeySpline*)keySpline {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IKeySpline> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplinePointKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeySpline(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAKeySpline>(unmarshalledReturn.Get());
}

- (void)setKeySpline:(WUXMAKeySpline*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplinePointKeyFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeySpline(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::IKeySpline>(value).Get()));
}

@end

@implementation WUXMASplitCloseThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SplitCloseThemeAnimation").Get(),
                                              &out));
    return [_createRtProxy<WUXMASplitCloseThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimationStatics> WUXMAISplitCloseThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SplitCloseThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)openedTargetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitCloseThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OpenedTargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)openedTargetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitCloseThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OpenedTargetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)closedTargetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitCloseThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ClosedTargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)closedTargetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitCloseThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ClosedTargetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)contentTargetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitCloseThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContentTargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)contentTargetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitCloseThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContentTargetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)openedLengthProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitCloseThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OpenedLengthProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)closedLengthProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitCloseThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ClosedLengthProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)offsetFromCenterProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitCloseThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OffsetFromCenterProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)contentTranslationDirectionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitCloseThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContentTranslationDirectionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)contentTranslationOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitCloseThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContentTranslationOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)openedTargetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_OpenedTargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setOpenedTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_OpenedTargetName(nsStrToHstr(value).Get()));
}

- (WXDependencyObject*)openedTarget {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_OpenedTarget(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setOpenedTarget:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_OpenedTarget(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

- (NSString*)closedTargetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClosedTargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setClosedTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ClosedTargetName(nsStrToHstr(value).Get()));
}

- (WXDependencyObject*)closedTarget {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClosedTarget(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setClosedTarget:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ClosedTarget(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

- (NSString*)contentTargetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentTargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setContentTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentTargetName(nsStrToHstr(value).Get()));
}

- (WXDependencyObject*)contentTarget {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentTarget(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setContentTarget:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentTarget(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

- (double)openedLength {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_OpenedLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOpenedLength:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_OpenedLength(value));
}

- (double)closedLength {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClosedLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setClosedLength:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ClosedLength(value));
}

- (double)offsetFromCenter {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_OffsetFromCenter(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOffsetFromCenter:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_OffsetFromCenter(value));
}

- (WUXCPAnimationDirection)contentTranslationDirection {
    ABI::Windows::UI::Xaml::Controls::Primitives::AnimationDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentTranslationDirection(&unmarshalledReturn));
    return (WUXCPAnimationDirection)unmarshalledReturn;
}

- (void)setContentTranslationDirection:(WUXCPAnimationDirection)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentTranslationDirection((ABI::Windows::UI::Xaml::Controls::Primitives::AnimationDirection)value));
}

- (double)contentTranslationOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentTranslationOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setContentTranslationOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentTranslationOffset(value));
}

@end

@implementation WUXMASplitOpenThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SplitOpenThemeAnimation").Get(),
                                              &out));
    return [_createRtProxy<WUXMASplitOpenThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimationStatics> WUXMAISplitOpenThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SplitOpenThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)openedTargetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitOpenThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OpenedTargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)openedTargetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitOpenThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OpenedTargetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)closedTargetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitOpenThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ClosedTargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)closedTargetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitOpenThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ClosedTargetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)contentTargetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitOpenThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContentTargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)contentTargetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitOpenThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContentTargetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)openedLengthProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitOpenThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OpenedLengthProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)closedLengthProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitOpenThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ClosedLengthProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)offsetFromCenterProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitOpenThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OffsetFromCenterProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)contentTranslationDirectionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitOpenThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContentTranslationDirectionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)contentTranslationOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISplitOpenThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContentTranslationOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)openedTargetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_OpenedTargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setOpenedTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_OpenedTargetName(nsStrToHstr(value).Get()));
}

- (WXDependencyObject*)openedTarget {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_OpenedTarget(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setOpenedTarget:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_OpenedTarget(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

- (NSString*)closedTargetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClosedTargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setClosedTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ClosedTargetName(nsStrToHstr(value).Get()));
}

- (WXDependencyObject*)closedTarget {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClosedTarget(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setClosedTarget:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ClosedTarget(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

- (NSString*)contentTargetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentTargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setContentTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentTargetName(nsStrToHstr(value).Get()));
}

- (WXDependencyObject*)contentTarget {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentTarget(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setContentTarget:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentTarget(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

- (double)openedLength {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_OpenedLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOpenedLength:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_OpenedLength(value));
}

- (double)closedLength {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClosedLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setClosedLength:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ClosedLength(value));
}

- (double)offsetFromCenter {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_OffsetFromCenter(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOffsetFromCenter:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_OffsetFromCenter(value));
}

- (WUXCPAnimationDirection)contentTranslationDirection {
    ABI::Windows::UI::Xaml::Controls::Primitives::AnimationDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentTranslationDirection(&unmarshalledReturn));
    return (WUXCPAnimationDirection)unmarshalledReturn;
}

- (void)setContentTranslationDirection:(WUXCPAnimationDirection)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentTranslationDirection((ABI::Windows::UI::Xaml::Controls::Primitives::AnimationDirection)value));
}

- (double)contentTranslationOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentTranslationOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setContentTranslationOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentTranslationOffset(value));
}

@end

@implementation WUXMAStoryboard

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.Storyboard").Get(), &out));
    return [_createRtProxy<WUXMAStoryboard>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IStoryboardStatics> WUXMAIStoryboardStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IStoryboardStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.Storyboard").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)targetPropertyProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIStoryboardStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetPropertyProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSString*)getTargetProperty:(WUXMATimeline*)element {
    HSTRING unmarshalledReturn;
    auto _comInst = WUXMAIStoryboardStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetTargetProperty(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(element).Get(),
                                                   &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setTargetProperty:(WUXMATimeline*)element path:(NSString*)path {
    auto _comInst = WUXMAIStoryboardStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetTargetProperty(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(element).Get(),
                                                   nsStrToHstr(path).Get()));
}

+ (WXDependencyProperty*)targetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIStoryboardStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSString*)getTargetName:(WUXMATimeline*)element {
    HSTRING unmarshalledReturn;
    auto _comInst = WUXMAIStoryboardStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetTargetName(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(element).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setTargetName:(WUXMATimeline*)element name:(NSString*)name {
    auto _comInst = WUXMAIStoryboardStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetTargetName(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(element).Get(),
                                               nsStrToHstr(name).Get()));
}

+ (void)setTarget:(WUXMATimeline*)timeline target:(WXDependencyObject*)target {
    auto _comInst = WUXMAIStoryboardStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetTarget(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::ITimeline>(timeline).Get(),
                                           _getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(target).Get()));
}

- (WUXMATimelineCollection*)children {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Animation::Timeline*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard>(self);
    THROW_NS_IF_FAILED(_comInst->get_Children(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMATimelineCollection>(unmarshalledReturn.Get());
}

- (void)seek:(WFTimeSpan*)offset {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard>(self);
    THROW_NS_IF_FAILED(_comInst->Seek(*[offset internalStruct]));
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)begin {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard>(self);
    THROW_NS_IF_FAILED(_comInst->Begin());
}

- (void)pause {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard>(self);
    THROW_NS_IF_FAILED(_comInst->Pause());
}

- (void)resume {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard>(self);
    THROW_NS_IF_FAILED(_comInst->Resume());
}

- (WUXMAClockState)getCurrentState {
    ABI::Windows::UI::Xaml::Media::Animation::ClockState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentState(&unmarshalledReturn));
    return (WUXMAClockState)unmarshalledReturn;
}

- (WFTimeSpan*)getCurrentTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)seekAlignedToLastTick:(WFTimeSpan*)offset {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard>(self);
    THROW_NS_IF_FAILED(_comInst->SeekAlignedToLastTick(*[offset internalStruct]));
}

- (void)skipToFill {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard>(self);
    THROW_NS_IF_FAILED(_comInst->SkipToFill());
}

@end

@implementation WUXMASwipeBackThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SwipeBackThemeAnimation").Get(),
                                              &out));
    return [_createRtProxy<WUXMASwipeBackThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimationStatics> WUXMAISwipeBackThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SwipeBackThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)targetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISwipeBackThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fromHorizontalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISwipeBackThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FromHorizontalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fromVerticalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISwipeBackThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FromVerticalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)targetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetName(nsStrToHstr(value).Get()));
}

- (double)fromHorizontalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FromHorizontalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFromHorizontalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_FromHorizontalOffset(value));
}

- (double)fromVerticalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FromVerticalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFromVerticalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_FromVerticalOffset(value));
}

@end

@implementation WUXMASwipeHintThemeAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SwipeHintThemeAnimation").Get(),
                                              &out));
    return [_createRtProxy<WUXMASwipeHintThemeAnimation>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimationStatics> WUXMAISwipeHintThemeAnimationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SwipeHintThemeAnimation").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)targetNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISwipeHintThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)toHorizontalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISwipeHintThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ToHorizontalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)toVerticalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAISwipeHintThemeAnimationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ToVerticalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)targetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTargetName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetName(nsStrToHstr(value).Get()));
}

- (double)toHorizontalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToHorizontalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setToHorizontalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToHorizontalOffset(value));
}

- (double)toVerticalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToVerticalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setToVerticalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ToVerticalOffset(value));
}

@end

@implementation WUXMAConnectedAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addCompletedEvent:(void (^)(WUXMAConnectedAnimation*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimation>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Completed(Make<ITypedEventHandler_Windows_UI_Xaml_Media_Animation_ConnectedAnimation_System_Object>(value).Get(),
                                &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Completed(token));
}

- (BOOL)tryStart:(WXUIElement*)destination {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->TryStart(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(destination).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

@end

@implementation WUXMAConnectedAnimationService

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimationService> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimationServiceStatics> WUXMAIConnectedAnimationServiceStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimationServiceStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ConnectedAnimationService").Get(), &inst));
    return inst;
}

+ (WUXMAConnectedAnimationService*)getForCurrentView {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimationService> unmarshalledReturn;
    auto _comInst = WUXMAIConnectedAnimationServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAConnectedAnimationService>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)defaultDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimationService>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setDefaultDuration:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimationService>(self);
    THROW_NS_IF_FAILED(_comInst->put_DefaultDuration(*[value internalStruct]));
}

- (WUCCompositionEasingFunction*)defaultEasingFunction {
    ComPtr<ABI::Windows::UI::Composition::ICompositionEasingFunction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimationService>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultEasingFunction(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionEasingFunction>(unmarshalledReturn.Get());
}

- (void)setDefaultEasingFunction:(WUCCompositionEasingFunction*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimationService>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_DefaultEasingFunction(_getRtInterface<ABI::Windows::UI::Composition::ICompositionEasingFunction>(value).Get()));
}

- (WUXMAConnectedAnimation*)prepareToAnimate:(NSString*)key source:(WXUIElement*)source {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimationService>(self);
    THROW_NS_IF_FAILED(_comInst->PrepareToAnimate(nsStrToHstr(key).Get(),
                                                  _getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(source).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAConnectedAnimation>(unmarshalledReturn.Get());
}

- (WUXMAConnectedAnimation*)getAnimation:(NSString*)key {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IConnectedAnimationService>(self);
    THROW_NS_IF_FAILED(_comInst->GetAnimation(nsStrToHstr(key).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAConnectedAnimation>(unmarshalledReturn.Get());
}

@end

@implementation WUXMACommonNavigationTransitionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ICommonNavigationTransitionInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.CommonNavigationTransitionInfo").Get(), &out));
    return [_createRtProxy<WUXMACommonNavigationTransitionInfo>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ICommonNavigationTransitionInfoStatics>
WUXMAICommonNavigationTransitionInfoStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ICommonNavigationTransitionInfoStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.CommonNavigationTransitionInfo").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)isStaggeringEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAICommonNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsStaggeringEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isStaggerElementProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAICommonNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsStaggerElementProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getIsStaggerElement:(WXUIElement*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXMAICommonNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetIsStaggerElement(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setIsStaggerElement:(WXUIElement*)element value:(BOOL)value {
    auto _comInst = WUXMAICommonNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetIsStaggerElement(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(), (boolean)value));
}

- (BOOL)isStaggeringEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ICommonNavigationTransitionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStaggeringEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsStaggeringEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::ICommonNavigationTransitionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsStaggeringEnabled((boolean)value));
}

@end

@implementation WUXMAContinuumNavigationTransitionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IContinuumNavigationTransitionInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ContinuumNavigationTransitionInfo").Get(), &out));
    return [_createRtProxy<WUXMAContinuumNavigationTransitionInfo>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IContinuumNavigationTransitionInfoStatics>
WUXMAIContinuumNavigationTransitionInfoStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IContinuumNavigationTransitionInfoStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.ContinuumNavigationTransitionInfo").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)exitElementProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIContinuumNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExitElementProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isEntranceElementProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIContinuumNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsEntranceElementProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getIsEntranceElement:(WXUIElement*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXMAIContinuumNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetIsEntranceElement(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setIsEntranceElement:(WXUIElement*)element value:(BOOL)value {
    auto _comInst = WUXMAIContinuumNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetIsEntranceElement(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)isExitElementProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIContinuumNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsExitElementProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getIsExitElement:(WXUIElement*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXMAIContinuumNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetIsExitElement(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setIsExitElement:(WXUIElement*)element value:(BOOL)value {
    auto _comInst = WUXMAIContinuumNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetIsExitElement(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)exitElementContainerProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIContinuumNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExitElementContainerProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getExitElementContainer:(WXCListViewBase*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXMAIContinuumNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetExitElementContainer(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IListViewBase>(element).Get(),
                                                         &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setExitElementContainer:(WXCListViewBase*)element value:(BOOL)value {
    auto _comInst = WUXMAIContinuumNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetExitElementContainer(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IListViewBase>(element).Get(), (boolean)value));
}

- (WXUIElement*)exitElement {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IContinuumNavigationTransitionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExitElement(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

- (void)setExitElement:(WXUIElement*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::IContinuumNavigationTransitionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExitElement(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(value).Get()));
}

@end

@implementation WUXMADrillInNavigationTransitionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IDrillInNavigationTransitionInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.DrillInNavigationTransitionInfo").Get(), &out));
    return [_createRtProxy<WUXMADrillInNavigationTransitionInfo>(out.Get()) retain];
}

@end

@implementation WUXMAEntranceNavigationTransitionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEntranceNavigationTransitionInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.EntranceNavigationTransitionInfo").Get(), &out));
    return [_createRtProxy<WUXMAEntranceNavigationTransitionInfo>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEntranceNavigationTransitionInfoStatics>
WUXMAIEntranceNavigationTransitionInfoStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEntranceNavigationTransitionInfoStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.EntranceNavigationTransitionInfo").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)isTargetElementProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAIEntranceNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsTargetElementProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getIsTargetElement:(WXUIElement*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXMAIEntranceNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetIsTargetElement(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setIsTargetElement:(WXUIElement*)element value:(BOOL)value {
    auto _comInst = WUXMAIEntranceNavigationTransitionInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetIsTargetElement(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(), (boolean)value));
}

@end

@implementation WUXMANavigationThemeTransition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::INavigationThemeTransition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.NavigationThemeTransition").Get(),
                                              &out));
    return [_createRtProxy<WUXMANavigationThemeTransition>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Media::Animation::INavigationThemeTransitionStatics> WUXMAINavigationThemeTransitionStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::INavigationThemeTransitionStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.NavigationThemeTransition").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)defaultNavigationTransitionInfoProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXMAINavigationThemeTransitionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DefaultNavigationTransitionInfoProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMANavigationTransitionInfo*)defaultNavigationTransitionInfo {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::INavigationThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultNavigationTransitionInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMANavigationTransitionInfo>(unmarshalledReturn.Get());
}

- (void)setDefaultNavigationTransitionInfo:(WUXMANavigationTransitionInfo*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Media::Animation::INavigationThemeTransition>(self);
    THROW_NS_IF_FAILED(_comInst->put_DefaultNavigationTransitionInfo(
        _getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo>(value).Get()));
}

@end

@implementation WUXMASlideNavigationTransitionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISlideNavigationTransitionInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SlideNavigationTransitionInfo").Get(), &out));
    return [_createRtProxy<WUXMASlideNavigationTransitionInfo>(out.Get()) retain];
}

@end

@implementation WUXMASuppressNavigationTransitionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::ISuppressNavigationTransitionInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Media.Animation.SuppressNavigationTransitionInfo").Get(), &out));
    return [_createRtProxy<WUXMASuppressNavigationTransitionInfo>(out.Get()) retain];
}

@end

@implementation WUXMAKeyTime {
    ABI::Windows::UI::Xaml::Media::Animation::KeyTime structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Media::Animation::KeyTime)s {
    WUXMAKeyTime* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::Media::Animation::KeyTime*)internalStruct {
    return &structVal;
}
- (WFTimeSpan*)timeSpan {
    return WFTimeSpan_create(structVal.TimeSpan);
}
- (void)setTimeSpan:(WFTimeSpan*)val {
    structVal.TimeSpan = *[val internalStruct];
}
@end
@implementation WUXMARepeatBehavior {
    ABI::Windows::UI::Xaml::Media::Animation::RepeatBehavior structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Media::Animation::RepeatBehavior)s {
    WUXMARepeatBehavior* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::Media::Animation::RepeatBehavior*)internalStruct {
    return &structVal;
}
- (double)count {
    return structVal.Count;
}
- (void)setCount:(double)val {
    structVal.Count = val;
}
- (WFTimeSpan*)duration {
    return WFTimeSpan_create(structVal.Duration);
}
- (void)setDuration:(WFTimeSpan*)val {
    structVal.Duration = *[val internalStruct];
}
- (WUXMARepeatBehaviorType)type {
    return (WUXMARepeatBehaviorType)structVal.Type;
}
- (void)setType:(WUXMARepeatBehaviorType)val {
    structVal.Type = (ABI::Windows::UI::Xaml::Media::Animation::RepeatBehaviorType)val;
}
@end
