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

// WindowsUIXaml.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXaml.h"
#include "WindowsUIXaml_priv.h"

@implementation WXIDataTemplateExtension

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDataTemplateExtension> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)resetTemplate {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDataTemplateExtension>(self);
    THROW_NS_IF_FAILED(_comInst->ResetTemplate());
}

- (BOOL)processBinding:(unsigned int)phase {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDataTemplateExtension>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessBinding(phase, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)processBindings:(WXCContainerContentChangingEventArgs*)arg {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDataTemplateExtension>(self);
    THROW_NS_IF_FAILED(
        _comInst->ProcessBindings(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IContainerContentChangingEventArgs>(arg).Get(),
                                  &unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WXDispatcherTimer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDispatcherTimer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::IDispatcherTimerFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.DispatcherTimer").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::IDispatcherTimer> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WXDispatcherTimer* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (WFTimeSpan*)interval {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDispatcherTimer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Interval(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setInterval:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDispatcherTimer>(self);
    THROW_NS_IF_FAILED(_comInst->put_Interval(*[value internalStruct]));
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDispatcherTimer>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addTickEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDispatcherTimer>(self);
    THROW_NS_IF_FAILED(_comInst->add_Tick(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTickEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDispatcherTimer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Tick(token));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDispatcherTimer>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDispatcherTimer>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

@end

@implementation WXCornerRadiusHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::ICornerRadiusHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::ICornerRadiusHelperStatics> WXICornerRadiusHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::ICornerRadiusHelperStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.CornerRadiusHelper").Get(), &inst));
    return inst;
}

+ (WXCornerRadius*)fromRadii:(double)topLeft topRight:(double)topRight bottomRight:(double)bottomRight bottomLeft:(double)bottomLeft {
    ABI::Windows::UI::Xaml::CornerRadius unmarshalledReturn;
    auto _comInst = WXICornerRadiusHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromRadii(topLeft, topRight, bottomRight, bottomLeft, &unmarshalledReturn));
    return WXCornerRadius_create(unmarshalledReturn);
}

+ (WXCornerRadius*)fromUniformRadius:(double)uniformRadius {
    ABI::Windows::UI::Xaml::CornerRadius unmarshalledReturn;
    auto _comInst = WXICornerRadiusHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromUniformRadius(uniformRadius, &unmarshalledReturn));
    return WXCornerRadius_create(unmarshalledReturn);
}

@end

@implementation WXDurationHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDurationHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::IDurationHelperStatics> WXIDurationHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IDurationHelperStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.DurationHelper").Get(), &inst));
    return inst;
}

+ (WXDuration*)automatic {
    ABI::Windows::UI::Xaml::Duration unmarshalledReturn;
    auto _comInst = WXIDurationHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Automatic(&unmarshalledReturn));
    return WXDuration_create(unmarshalledReturn);
}

+ (WXDuration*)forever {
    ABI::Windows::UI::Xaml::Duration unmarshalledReturn;
    auto _comInst = WXIDurationHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Forever(&unmarshalledReturn));
    return WXDuration_create(unmarshalledReturn);
}

+ (int)compare:(WXDuration*)duration1 duration2:(WXDuration*)duration2 {
    int unmarshalledReturn;
    auto _comInst = WXIDurationHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Compare(*[duration1 internalStruct], *[duration2 internalStruct], &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (WXDuration*)fromTimeSpan:(WFTimeSpan*)timeSpan {
    ABI::Windows::UI::Xaml::Duration unmarshalledReturn;
    auto _comInst = WXIDurationHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromTimeSpan(*[timeSpan internalStruct], &unmarshalledReturn));
    return WXDuration_create(unmarshalledReturn);
}

+ (BOOL)getHasTimeSpan:(WXDuration*)target {
    boolean unmarshalledReturn;
    auto _comInst = WXIDurationHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetHasTimeSpan(*[target internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (WXDuration*)add:(WXDuration*)target duration:(WXDuration*)duration {
    ABI::Windows::UI::Xaml::Duration unmarshalledReturn;
    auto _comInst = WXIDurationHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Add(*[target internalStruct], *[duration internalStruct], &unmarshalledReturn));
    return WXDuration_create(unmarshalledReturn);
}

+ (BOOL)equals:(WXDuration*)target value:(WXDuration*)value {
    boolean unmarshalledReturn;
    auto _comInst = WXIDurationHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Equals(*[target internalStruct], *[value internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (WXDuration*)subtract:(WXDuration*)target duration:(WXDuration*)duration {
    ABI::Windows::UI::Xaml::Duration unmarshalledReturn;
    auto _comInst = WXIDurationHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Subtract(*[target internalStruct], *[duration internalStruct], &unmarshalledReturn));
    return WXDuration_create(unmarshalledReturn);
}

@end

@implementation WXThicknessHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IThicknessHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::IThicknessHelperStatics> WXIThicknessHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IThicknessHelperStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.ThicknessHelper").Get(), &inst));
    return inst;
}

+ (WXThickness*)fromLengths:(double)left top:(double)top right:(double)right bottom:(double)bottom {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = WXIThicknessHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromLengths(left, top, right, bottom, &unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

+ (WXThickness*)fromUniformLength:(double)uniformLength {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = WXIThicknessHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromUniformLength(uniformLength, &unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

@end

@implementation WXApplicationInitializationCallbackParams

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IApplicationInitializationCallbackParams> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WXDependencyObject

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)getValue:(WXDependencyProperty*)dp {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDependencyObject>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetValue(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(dp).Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setValue:(WXDependencyProperty*)dp value:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDependencyObject>(self);
    THROW_NS_IF_FAILED(_comInst->SetValue(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(dp).Get(), [value comObj].Get()));
}

- (void)clearValue:(WXDependencyProperty*)dp {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDependencyObject>(self);
    THROW_NS_IF_FAILED(_comInst->ClearValue(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(dp).Get()));
}

- (RTObject*)readLocalValue:(WXDependencyProperty*)dp {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDependencyObject>(self);
    THROW_NS_IF_FAILED(_comInst->ReadLocalValue(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(dp).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)getAnimationBaseValue:(WXDependencyProperty*)dp {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDependencyObject>(self);
    THROW_NS_IF_FAILED(_comInst->GetAnimationBaseValue(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(dp).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WUCCoreDispatcher*)dispatcher {
    ComPtr<ABI::Windows::UI::Core::ICoreDispatcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDependencyObject>(self);
    THROW_NS_IF_FAILED(_comInst->get_Dispatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreDispatcher>(unmarshalledReturn.Get());
}

- (int64_t)registerPropertyChangedCallback:(WXDependencyProperty*)dp callback:(WXDependencyPropertyChangedCallback)callback {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDependencyObject2>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterPropertyChangedCallback(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(dp).Get(),
                                                                 Make<WXDependencyPropertyChangedCallback_shim>(callback).Get(),
                                                                 &unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)unregisterPropertyChangedCallback:(WXDependencyProperty*)dp token:(int64_t)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDependencyObject2>(self);
    THROW_NS_IF_FAILED(
        _comInst->UnregisterPropertyChangedCallback(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(dp).Get(), token));
}

@end

@implementation WXDependencyProperty

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::IDependencyPropertyStatics> WXIDependencyPropertyStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyPropertyStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.DependencyProperty").Get(), &inst));
    return inst;
}

+ (RTObject*)unsetValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WXIDependencyPropertyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UnsetValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)Register:(NSString*)name
                     propertyType:(WUXITypeName*)propertyType
                        ownerType:(WUXITypeName*)ownerType
                     typeMetadata:(WXPropertyMetadata*)typeMetadata {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIDependencyPropertyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Register(nsStrToHstr(name).Get(),
                                          *[propertyType internalStruct],
                                          *[ownerType internalStruct],
                                          _getRtInterface<ABI::Windows::UI::Xaml::IPropertyMetadata>(typeMetadata).Get(),
                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)registerAttached:(NSString*)name
                             propertyType:(WUXITypeName*)propertyType
                                ownerType:(WUXITypeName*)ownerType
                          defaultMetadata:(WXPropertyMetadata*)defaultMetadata {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIDependencyPropertyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RegisterAttached(nsStrToHstr(name).Get(),
                                                  *[propertyType internalStruct],
                                                  *[ownerType internalStruct],
                                                  _getRtInterface<ABI::Windows::UI::Xaml::IPropertyMetadata>(defaultMetadata).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WXPropertyMetadata*)getMetadata:(WUXITypeName*)forType {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyMetadata> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(self);
    THROW_NS_IF_FAILED(_comInst->GetMetadata(*[forType internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXPropertyMetadata>(unmarshalledReturn.Get());
}

@end

@implementation WXDependencyPropertyChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyPropertyChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WXDependencyProperty*)property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDependencyPropertyChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (RTObject*)oldValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDependencyPropertyChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)newValue __attribute__((ns_returns_not_retained)) {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDependencyPropertyChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WXRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEventArgsFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.RoutedEventArgs").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEventArgs> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WXRoutedEventArgs* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (RTObject*)originalSource {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OriginalSource(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WXUnhandledExceptionEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IUnhandledExceptionEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (HRESULT)exception {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUnhandledExceptionEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Exception(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (NSString*)message {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUnhandledExceptionEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUnhandledExceptionEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUnhandledExceptionEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WXVisualStateChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IVisualStateChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.VisualStateChangedEventArgs").Get(), &out));
    return [_createRtProxy<WXVisualStateChangedEventArgs>(out.Get()) retain];
}

- (WXVisualState*)oldState {
    ComPtr<ABI::Windows::UI::Xaml::IVisualState> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldState(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXVisualState>(unmarshalledReturn.Get());
}

- (void)setOldState:(WXVisualState*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_OldState(_getRtInterface<ABI::Windows::UI::Xaml::IVisualState>(value).Get()));
}

- (WXVisualState*)newState __attribute__((ns_returns_not_retained)) {
    ComPtr<ABI::Windows::UI::Xaml::IVisualState> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewState(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXVisualState>(unmarshalledReturn.Get());
}

- (void)setNewState:(WXVisualState*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_NewState(_getRtInterface<ABI::Windows::UI::Xaml::IVisualState>(value).Get()));
}

- (WXCControl*)control {
    ComPtr<ABI::Windows::UI::Xaml::Controls::IControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXCControl>(unmarshalledReturn.Get());
}

- (void)setControl:(WXCControl*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Control(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IControl>(value).Get()));
}

@end

@implementation WXDataContextChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDataContextChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)newValue __attribute__((ns_returns_not_retained)) {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDataContextChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDataContextChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDataContextChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WXDataTemplateKey

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDataTemplateKey> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::IDataTemplateKeyFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.DataTemplateKey").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::IDataTemplateKey> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WXDataTemplateKey* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (RTObject*)dataType {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDataTemplateKey>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataType(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setDataType:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDataTemplateKey>(self);
    THROW_NS_IF_FAILED(_comInst->put_DataType([value comObj].Get()));
}

@end

@implementation WXPropertyMetadata

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyMetadata> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WXPropertyMetadata*)makeInstanceWithDefaultValue:(RTObject*)defaultValue {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyMetadataFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.PropertyMetadata").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::IPropertyMetadata> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    THROW_NS_IF_FAILED(factory->CreateInstanceWithDefaultValue([defaultValue comObj].Get(), outer.Get(), &inner, &instance));
    WXPropertyMetadata* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

+ (WXPropertyMetadata*)makeInstanceWithDefaultValueAndCallback:(RTObject*)defaultValue
                                       propertyChangedCallback:(WXPropertyChangedCallback)propertyChangedCallback {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyMetadataFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.PropertyMetadata").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::IPropertyMetadata> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    THROW_NS_IF_FAILED(factory->CreateInstanceWithDefaultValueAndCallback(
        [defaultValue comObj].Get(), Make<WXPropertyChangedCallback_shim>(propertyChangedCallback).Get(), outer.Get(), &inner, &instance));
    WXPropertyMetadata* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::IPropertyMetadataStatics> WXIPropertyMetadataStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyMetadataStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.PropertyMetadata").Get(), &inst));
    return inst;
}

+ (WXPropertyMetadata*)createWithDefaultValue:(RTObject*)defaultValue {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyMetadata> unmarshalledReturn;
    auto _comInst = WXIPropertyMetadataStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithDefaultValue([defaultValue comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXPropertyMetadata>(unmarshalledReturn.Get());
}

+ (WXPropertyMetadata*)createWithDefaultValueAndCallback:(RTObject*)defaultValue
                                 propertyChangedCallback:(WXPropertyChangedCallback)propertyChangedCallback {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyMetadata> unmarshalledReturn;
    auto _comInst = WXIPropertyMetadataStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithDefaultValueAndCallback([defaultValue comObj].Get(),
                                                                   Make<WXPropertyChangedCallback_shim>(propertyChangedCallback).Get(),
                                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXPropertyMetadata>(unmarshalledReturn.Get());
}

+ (WXPropertyMetadata*)createWithFactory:(WXCreateDefaultValueCallback)createDefaultValueCallback {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyMetadata> unmarshalledReturn;
    auto _comInst = WXIPropertyMetadataStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithFactory(Make<WXCreateDefaultValueCallback_shim>(createDefaultValueCallback).Get(),
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXPropertyMetadata>(unmarshalledReturn.Get());
}

+ (WXPropertyMetadata*)createWithFactoryAndCallback:(WXCreateDefaultValueCallback)createDefaultValueCallback
                            propertyChangedCallback:(WXPropertyChangedCallback)propertyChangedCallback {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyMetadata> unmarshalledReturn;
    auto _comInst = WXIPropertyMetadataStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithFactoryAndCallback(Make<WXCreateDefaultValueCallback_shim>(createDefaultValueCallback).Get(),
                                                              Make<WXPropertyChangedCallback_shim>(propertyChangedCallback).Get(),
                                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXPropertyMetadata>(unmarshalledReturn.Get());
}

- (RTObject*)defaultValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IPropertyMetadata>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WXCreateDefaultValueCallback)createDefaultValueCallback {
    ComPtr<ABI::Windows::UI::Xaml::ICreateDefaultValueCallback> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IPropertyMetadata>(self);
    THROW_NS_IF_FAILED(_comInst->get_CreateDefaultValueCallback(unmarshalledReturn.GetAddressOf()));
    return nil;
}

@end

@implementation WXDragOperationDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDragOperationDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragOperationDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WXDragUI

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDragUI> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setContentFromBitmapImage:(WUXMIBitmapImage*)bitmapImage {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUI>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetContentFromBitmapImage(_getRtInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(bitmapImage).Get()));
}

- (void)setContentFromBitmapImageWithAnchorPoint:(WUXMIBitmapImage*)bitmapImage anchorPoint:(WFPoint*)anchorPoint {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUI>(self);
    THROW_NS_IF_FAILED(_comInst->SetContentFromBitmapImageWithAnchorPoint(
        _getRtInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(bitmapImage).Get(), *[anchorPoint internalStruct]));
}

- (void)setContentFromSoftwareBitmap:(WGISoftwareBitmap*)softwareBitmap {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUI>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetContentFromSoftwareBitmap(_getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(softwareBitmap).Get()));
}

- (void)setContentFromSoftwareBitmapWithAnchorPoint:(WGISoftwareBitmap*)softwareBitmap anchorPoint:(WFPoint*)anchorPoint {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUI>(self);
    THROW_NS_IF_FAILED(_comInst->SetContentFromSoftwareBitmapWithAnchorPoint(
        _getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(softwareBitmap).Get(), *[anchorPoint internalStruct]));
}

- (void)setContentFromDataPackage {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUI>(self);
    THROW_NS_IF_FAILED(_comInst->SetContentFromDataPackage());
}

@end

@implementation WXDragUIOverride

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDragUIOverride> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)caption {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->get_Caption(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCaption:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->put_Caption(nsStrToHstr(value).Get()));
}

- (BOOL)isContentVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsContentVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsContentVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsContentVisible((boolean)value));
}

- (BOOL)isCaptionVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCaptionVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsCaptionVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsCaptionVisible((boolean)value));
}

- (BOOL)isGlyphVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsGlyphVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsGlyphVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsGlyphVisible((boolean)value));
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

- (void)setContentFromBitmapImage:(WUXMIBitmapImage*)bitmapImage {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUIOverride>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetContentFromBitmapImage(_getRtInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(bitmapImage).Get()));
}

- (void)setContentFromBitmapImageWithAnchorPoint:(WUXMIBitmapImage*)bitmapImage anchorPoint:(WFPoint*)anchorPoint {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->SetContentFromBitmapImageWithAnchorPoint(
        _getRtInterface<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage>(bitmapImage).Get(), *[anchorPoint internalStruct]));
}

- (void)setContentFromSoftwareBitmap:(WGISoftwareBitmap*)softwareBitmap {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUIOverride>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetContentFromSoftwareBitmap(_getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(softwareBitmap).Get()));
}

- (void)setContentFromSoftwareBitmapWithAnchorPoint:(WGISoftwareBitmap*)softwareBitmap anchorPoint:(WFPoint*)anchorPoint {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->SetContentFromSoftwareBitmapWithAnchorPoint(
        _getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(softwareBitmap).Get(), *[anchorPoint internalStruct]));
}

@end

@implementation WXElementSoundPlayer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IElementSoundPlayer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::IElementSoundPlayerStatics> WXIElementSoundPlayerStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IElementSoundPlayerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.ElementSoundPlayer").Get(), &inst));
    return inst;
}

+ (double)volume {
    double unmarshalledReturn;
    auto _comInst = WXIElementSoundPlayerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Volume(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (void)setVolume:(double)value {
    auto _comInst = WXIElementSoundPlayerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_Volume(value));
}

+ (WXElementSoundPlayerState)state {
    ABI::Windows::UI::Xaml::ElementSoundPlayerState unmarshalledReturn;
    auto _comInst = WXIElementSoundPlayerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WXElementSoundPlayerState)unmarshalledReturn;
}

+ (void)setState:(WXElementSoundPlayerState)value {
    auto _comInst = WXIElementSoundPlayerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_State((ABI::Windows::UI::Xaml::ElementSoundPlayerState)value));
}

+ (void)play:(WXElementSoundKind)sound {
    auto _comInst = WXIElementSoundPlayerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Play((ABI::Windows::UI::Xaml::ElementSoundKind)sound));
}

@end

@implementation WXFrameworkView

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IFrameworkView> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.FrameworkView").Get(), &out));
    return [_createRtProxy<WXFrameworkView>(out.Get()) retain];
}

- (void)Initialize:(WACCoreApplicationView*)applicationView {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IFrameworkView>(self);
    THROW_NS_IF_FAILED(
        _comInst->Initialize(_getRtInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationView>(applicationView).Get()));
}

- (void)setWindow:(WUCCoreWindow*)window {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IFrameworkView>(self);
    THROW_NS_IF_FAILED(_comInst->SetWindow(_getRtInterface<ABI::Windows::UI::Core::ICoreWindow>(window).Get()));
}

- (void)Load:(NSString*)entryPoint {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IFrameworkView>(self);
    THROW_NS_IF_FAILED(_comInst->Load(nsStrToHstr(entryPoint).Get()));
}

- (void)run {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IFrameworkView>(self);
    THROW_NS_IF_FAILED(_comInst->Run());
}

- (void)uninitialize {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IFrameworkView>(self);
    THROW_NS_IF_FAILED(_comInst->Uninitialize());
}

@end

@implementation WXRoutedEvent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WXSetterBaseCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::ISetterBase*,
                      IVector<ABI::Windows::UI::Xaml::SetterBase*>,
                      WXSetterBase,
                      ABI::Windows::UI::Xaml::SetterBase*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, WXSetterBase, ABI::Windows::UI::Xaml::ISetterBase*, ABI::Windows::UI::Xaml::SetterBase*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::ISetterBaseCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.SetterBaseCollection").Get(), &out));
    return [_createRtProxy<WXSetterBaseCollection>(out.Get()) retain];
}

- (BOOL)isSealed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::ISetterBaseCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSealed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WXTargetPropertyPath

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::ITargetPropertyPath> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::ITargetPropertyPathFactory> WXITargetPropertyPathFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::ITargetPropertyPathFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.TargetPropertyPath").Get(), &inst));
    return inst;
}

+ (WXTargetPropertyPath*)makeInstance:(WXDependencyProperty*)targetProperty {
    ComPtr<ABI::Windows::UI::Xaml::ITargetPropertyPath> unmarshalledReturn;
    auto _comInst = WXITargetPropertyPathFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(targetProperty).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WXTargetPropertyPath>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.TargetPropertyPath").Get(), &out));
    return [_createRtProxy<WXTargetPropertyPath>(out.Get()) retain];
}

- (WXPropertyPath*)path {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyPath> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::ITargetPropertyPath>(self);
    THROW_NS_IF_FAILED(_comInst->get_Path(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXPropertyPath>(unmarshalledReturn.Get());
}

- (void)setPath:(WXPropertyPath*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::ITargetPropertyPath>(self);
    THROW_NS_IF_FAILED(_comInst->put_Path(_getRtInterface<ABI::Windows::UI::Xaml::IPropertyPath>(value).Get()));
}

- (RTObject*)target {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::ITargetPropertyPath>(self);
    THROW_NS_IF_FAILED(_comInst->get_Target(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setTarget:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::ITargetPropertyPath>(self);
    THROW_NS_IF_FAILED(_comInst->put_Target([value comObj].Get()));
}

@end

@implementation WXTriggerActionCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::ITriggerAction*,
                      IVector<ABI::Windows::UI::Xaml::TriggerAction*>,
                      WXTriggerAction,
                      ABI::Windows::UI::Xaml::TriggerAction*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, WXTriggerAction, ABI::Windows::UI::Xaml::ITriggerAction*, ABI::Windows::UI::Xaml::TriggerAction*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::TriggerAction*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.TriggerActionCollection").Get(), &out));
    return [_createRtProxy<WXTriggerActionCollection>(out.Get()) retain];
}

@end

@implementation WXTriggerCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::ITriggerBase*,
                      IVector<ABI::Windows::UI::Xaml::TriggerBase*>,
                      WXTriggerBase,
                      ABI::Windows::UI::Xaml::TriggerBase*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, WXTriggerBase, ABI::Windows::UI::Xaml::ITriggerBase*, ABI::Windows::UI::Xaml::TriggerBase*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::TriggerBase*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WXWindow

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IWindow> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::IWindowStatics> WXIWindowStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IWindowStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Window").Get(), &inst));
    return inst;
}

+ (WXWindow*)current {
    ComPtr<ABI::Windows::UI::Xaml::IWindow> unmarshalledReturn;
    auto _comInst = WXIWindowStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Current(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXWindow>(unmarshalledReturn.Get());
}

- (WFRect*)bounds {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bounds(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (BOOL)visible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_Visible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WXUIElement*)content {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

- (void)setContent:(WXUIElement*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->put_Content(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(value).Get()));
}

- (WUCCoreWindow*)coreWindow {
    ComPtr<ABI::Windows::UI::Core::ICoreWindow> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_CoreWindow(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreWindow>(unmarshalledReturn.Get());
}

- (WUCCoreDispatcher*)dispatcher {
    ComPtr<ABI::Windows::UI::Core::ICoreDispatcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_Dispatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreDispatcher>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addActivatedEvent:(WXWindowActivatedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_Activated(Make<WXWindowActivatedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeActivatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Activated(token));
}

- (EventRegistrationToken)addClosedEvent:(WXWindowClosedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_Closed(Make<WXWindowClosedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Closed(token));
}

- (EventRegistrationToken)addSizeChangedEvent:(WXWindowSizeChangedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_SizeChanged(Make<WXWindowSizeChangedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSizeChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SizeChanged(token));
}

- (EventRegistrationToken)addVisibilityChangedEvent:(WXWindowVisibilityChangedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_VisibilityChanged(Make<WXWindowVisibilityChangedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVisibilityChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VisibilityChanged(token));
}

- (void)activate {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->Activate());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (void)setTitleBar:(WXUIElement*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindow2>(self);
    THROW_NS_IF_FAILED(_comInst->SetTitleBar(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(value).Get()));
}

@end

@implementation WXWindowCreatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IWindowCreatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WXWindow*)window {
    ComPtr<ABI::Windows::UI::Xaml::IWindow> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IWindowCreatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Window(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXWindow>(unmarshalledReturn.Get());
}

@end

@implementation WXDependencyObjectCollection {
    RTObservableArrayObjFull<ABI::Windows::UI::Xaml::IDependencyObject*,
                             IVector<ABI::Windows::UI::Xaml::DependencyObject*>,
                             WXDependencyObject,
                             ABI::Windows::UI::Xaml::DependencyObject*,
                             dummyObjCCreator,
                             dummyWRLCreator>
        _array;
}
INTEROP_IMPL_OBSVECTOR_FULL(self.comObj,
                            WXDependencyObject,
                            ABI::Windows::UI::Xaml::IDependencyObject*,
                            ABI::Windows::UI::Xaml::DependencyObject*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IObservableVector<ABI::Windows::UI::Xaml::DependencyObject*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObjectCollectionFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.DependencyObjectCollection").Get(),
                                                       &factory));
    ComPtr<IObservableVector<ABI::Windows::UI::Xaml::DependencyObject*>> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WXDependencyObjectCollection* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

@end

@implementation WXDragEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDragEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WADDataPackage*)data {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataPackage>(unmarshalledReturn.Get());
}

- (void)setData:(WADDataPackage*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(_getRtInterface<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage>(value).Get()));
}

- (WFPoint*)getPosition:(WXUIElement*)relativeTo {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetPosition(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(relativeTo).Get(), &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WADDataPackageView*)dataView {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataPackageView>(unmarshalledReturn.Get());
}

- (WXDragUIOverride*)dragUIOverride {
    ComPtr<ABI::Windows::UI::Xaml::IDragUIOverride> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DragUIOverride(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDragUIOverride>(unmarshalledReturn.Get());
}

- (WADDDragDropModifiers)modifiers {
    ABI::Windows::ApplicationModel::DataTransfer::DragDrop::DragDropModifiers unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Modifiers(&unmarshalledReturn));
    return (WADDDragDropModifiers)unmarshalledReturn;
}

- (WADDataPackageOperation)acceptedOperation {
    ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AcceptedOperation(&unmarshalledReturn));
    return (WADDataPackageOperation)unmarshalledReturn;
}

- (void)setAcceptedOperation:(WADDataPackageOperation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AcceptedOperation((ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation)value));
}

- (WXDragOperationDeferral*)getDeferral {
    ComPtr<ABI::Windows::UI::Xaml::IDragOperationDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDragOperationDeferral>(unmarshalledReturn.Get());
}

- (WADDataPackageOperation)allowedOperations {
    ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragEventArgs3>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowedOperations(&unmarshalledReturn));
    return (WADDataPackageOperation)unmarshalledReturn;
}

@end

@implementation WXDragStartingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDragStartingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)cancel {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragStartingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cancel(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCancel:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragStartingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Cancel((boolean)value));
}

- (WADDataPackage*)data {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragStartingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataPackage>(unmarshalledReturn.Get());
}

- (WXDragUI*)dragUI {
    ComPtr<ABI::Windows::UI::Xaml::IDragUI> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragStartingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_DragUI(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDragUI>(unmarshalledReturn.Get());
}

- (WXDragOperationDeferral*)getDeferral {
    ComPtr<ABI::Windows::UI::Xaml::IDragOperationDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragStartingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDragOperationDeferral>(unmarshalledReturn.Get());
}

- (WFPoint*)getPosition:(WXUIElement*)relativeTo {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragStartingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetPosition(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(relativeTo).Get(), &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WADDataPackageOperation)allowedOperations {
    ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragStartingEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowedOperations(&unmarshalledReturn));
    return (WADDataPackageOperation)unmarshalledReturn;
}

- (void)setAllowedOperations:(WADDataPackageOperation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDragStartingEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowedOperations((ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation)value));
}

@end

@implementation WXDropCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDropCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WADDataPackageOperation)dropResult {
    ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDropCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_DropResult(&unmarshalledReturn));
    return (WADDataPackageOperation)unmarshalledReturn;
}

@end

@implementation WXExceptionRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IExceptionRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)errorMessage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IExceptionRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorMessage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WXFrameworkTemplate

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IFrameworkTemplate> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WXDataTemplate

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDataTemplate> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::IDataTemplateFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.DataTemplate").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::IDataTemplate> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WXDataTemplate* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::IDataTemplateStatics2> WXIDataTemplateStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IDataTemplateStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.DataTemplate").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)extensionInstanceProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIDataTemplateStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExtensionInstanceProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (RTObject<WXIDataTemplateExtension>*)getExtensionInstance:(WXFrameworkElement*)element {
    ComPtr<ABI::Windows::UI::Xaml::IDataTemplateExtension> unmarshalledReturn;
    auto _comInst = WXIDataTemplateStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetExtensionInstance(_getRtInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(element).Get(),
                                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXIDataTemplateExtension>(unmarshalledReturn.Get());
}

+ (void)setExtensionInstance:(WXFrameworkElement*)element value:(RTObject<WXIDataTemplateExtension>*)value {
    auto _comInst = WXIDataTemplateStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->SetExtensionInstance(_getRtInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(element).Get(),
                                                      _getRtInterface<ABI::Windows::UI::Xaml::IDataTemplateExtension>(value).Get()));
}

- (WXDependencyObject*)loadContent {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDataTemplate>(self);
    THROW_NS_IF_FAILED(_comInst->LoadContent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

@end

@implementation WXPropertyPath

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyPath> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::IPropertyPathFactory> WXIPropertyPathFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyPathFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.PropertyPath").Get(), &inst));
    return inst;
}

+ (WXPropertyPath*)makeInstance:(NSString*)path {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyPath> unmarshalledReturn;
    auto _comInst = WXIPropertyPathFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance(nsStrToHstr(path).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WXPropertyPath>(unmarshalledReturn.Get()) retain];
}

- (NSString*)path {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IPropertyPath>(self);
    THROW_NS_IF_FAILED(_comInst->get_Path(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WXResourceDictionary {
    RTMapObj<IInspectable*,
             IInspectable*,
             IInspectable*,
             IInspectable*,
             RTObject,
             RTObject,
             IMap<IInspectable*, IInspectable*>,
             dummyObjCCreator,
             dummyObjCCreator,
             dummyWRLCreator,
             dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAP(self.comObj,
                 RTProxiedNSMutableDictionary_RTObject_RTObject,
                 IInspectable*,
                 IInspectable*,
                 IInspectable*,
                 IInspectable*,
                 RTObject,
                 RTObject)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IResourceDictionary> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::IResourceDictionaryFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.ResourceDictionary").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::IResourceDictionary> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WXResourceDictionary* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (WFUri*)source {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IResourceDictionary>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setSource:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IResourceDictionary>(self);
    THROW_NS_IF_FAILED(_comInst->put_Source(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSMutableArray* /* WXResourceDictionary* */)mergedDictionaries {
    ComPtr<IVector<ABI::Windows::UI::Xaml::ResourceDictionary*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IResourceDictionary>(self);
    THROW_NS_IF_FAILED(_comInst->get_MergedDictionaries(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WXResourceDictionary_create(unmarshalledReturn.Get());
}

- (NSMutableDictionary* /* RTObject*, RTObject* */)themeDictionaries {
    ComPtr<IMap<IInspectable*, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IResourceDictionary>(self);
    THROW_NS_IF_FAILED(_comInst->get_ThemeDictionaries(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_RTObject_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WXSetterBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::ISetterBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isSealed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::ISetterBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSealed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WXSizeChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::ISizeChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFSize*)previousSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::ISizeChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFSize*)newSize __attribute__((ns_returns_not_retained)) {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::ISizeChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

@end

@implementation WXStateTriggerBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IStateTriggerBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setActive:(BOOL)IsActive {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IStateTriggerBaseProtected>(self);
    THROW_NS_IF_FAILED(_comInst->SetActive((boolean)IsActive));
}

@end

@implementation WXStyle

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IStyle> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::IStyleFactory> WXIStyleFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IStyleFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Style").Get(), &inst));
    return inst;
}

+ (WXStyle*)makeInstance:(WUXITypeName*)targetType {
    ComPtr<ABI::Windows::UI::Xaml::IStyle> unmarshalledReturn;
    auto _comInst = WXIStyleFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance(*[targetType internalStruct], unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WXStyle>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Style").Get(), &out));
    return [_createRtProxy<WXStyle>(out.Get()) retain];
}

- (BOOL)isSealed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSealed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WXSetterBaseCollection*)setters {
    ComPtr<ABI::Windows::UI::Xaml::ISetterBaseCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_Setters(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXSetterBaseCollection>(unmarshalledReturn.Get());
}

- (WUXITypeName*)targetType {
    ABI::Windows::UI::Xaml::Interop::TypeName unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetType(&unmarshalledReturn));
    return WUXITypeName_create(unmarshalledReturn);
}

- (void)setTargetType:(WUXITypeName*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IStyle>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetType(*[value internalStruct]));
}

- (WXStyle*)basedOn {
    ComPtr<ABI::Windows::UI::Xaml::IStyle> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_BasedOn(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXStyle>(unmarshalledReturn.Get());
}

- (void)setBasedOn:(WXStyle*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IStyle>(self);
    THROW_NS_IF_FAILED(_comInst->put_BasedOn(_getRtInterface<ABI::Windows::UI::Xaml::IStyle>(value).Get()));
}

- (void)seal {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IStyle>(self);
    THROW_NS_IF_FAILED(_comInst->Seal());
}

@end

@implementation WXTriggerAction

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::ITriggerAction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WXTriggerBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::ITriggerBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WXUIElement

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::IUIElementStatics4> WXIUIElementStatics4_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IUIElementStatics4> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.UIElement").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)contextFlyoutProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContextFlyoutProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)exitDisplayModeOnAccessKeyInvokedProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExitDisplayModeOnAccessKeyInvokedProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isAccessKeyScopeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsAccessKeyScopeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)accessKeyScopeOwnerProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_AccessKeyScopeOwnerProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)accessKeyProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_AccessKeyProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::IUIElementStatics> WXIUIElementStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IUIElementStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.UIElement").Get(), &inst));
    return inst;
}

+ (WXRoutedEvent*)keyDownEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KeyDownEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)keyUpEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KeyUpEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)pointerEnteredEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointerEnteredEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)pointerPressedEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointerPressedEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)pointerMovedEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointerMovedEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)pointerReleasedEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointerReleasedEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)pointerExitedEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointerExitedEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)pointerCaptureLostEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointerCaptureLostEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)pointerCanceledEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointerCanceledEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)pointerWheelChangedEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointerWheelChangedEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)tappedEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TappedEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)doubleTappedEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DoubleTappedEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)holdingEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HoldingEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)rightTappedEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RightTappedEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)manipulationStartingEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ManipulationStartingEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)manipulationInertiaStartingEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ManipulationInertiaStartingEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)manipulationStartedEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ManipulationStartedEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)manipulationDeltaEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ManipulationDeltaEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)manipulationCompletedEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ManipulationCompletedEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)dragEnterEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DragEnterEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)dragLeaveEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DragLeaveEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)dragOverEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DragOverEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXRoutedEvent*)dropEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DropEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)allowDropProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllowDropProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)opacityProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OpacityProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)clipProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ClipProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)renderTransformProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RenderTransformProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)projectionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ProjectionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)renderTransformOriginProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RenderTransformOriginProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isHitTestVisibleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsHitTestVisibleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)visibilityProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VisibilityProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)useLayoutRoundingProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UseLayoutRoundingProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)transitionsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TransitionsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)cacheModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CacheModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isTapEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsTapEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isDoubleTapEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleTapEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isRightTapEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsRightTapEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isHoldingEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsHoldingEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)manipulationModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ManipulationModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)pointerCapturesProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointerCapturesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::IUIElementStatics2> WXIUIElementStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IUIElementStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.UIElement").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)compositeModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CompositeModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::IUIElementStatics3> WXIUIElementStatics3_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IUIElementStatics3> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.UIElement").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)transform3DProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_Transform3DProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)canDragProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIUIElementStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_CanDragProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)tryStartDirectManipulation:(WUXIPointer*)value {
    boolean unmarshalledReturn;
    auto _comInst = WXIUIElementStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryStartDirectManipulation(_getRtInterface<ABI::Windows::UI::Xaml::Input::IPointer>(value).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFSize*)desiredSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (BOOL)allowDrop {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowDrop(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowDrop:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowDrop((boolean)value));
}

- (double)opacity {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Opacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOpacity:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Opacity(value));
}

- (WUXMRectangleGeometry*)clip {
    ComPtr<ABI::Windows::UI::Xaml::Media::IRectangleGeometry> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Clip(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMRectangleGeometry>(unmarshalledReturn.Get());
}

- (void)setClip:(WUXMRectangleGeometry*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Clip(_getRtInterface<ABI::Windows::UI::Xaml::Media::IRectangleGeometry>(value).Get()));
}

- (WUXMTransform*)renderTransform {
    ComPtr<ABI::Windows::UI::Xaml::Media::ITransform> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_RenderTransform(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMTransform>(unmarshalledReturn.Get());
}

- (void)setRenderTransform:(WUXMTransform*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_RenderTransform(_getRtInterface<ABI::Windows::UI::Xaml::Media::ITransform>(value).Get()));
}

- (WUXMProjection*)projection {
    ComPtr<ABI::Windows::UI::Xaml::Media::IProjection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Projection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMProjection>(unmarshalledReturn.Get());
}

- (void)setProjection:(WUXMProjection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Projection(_getRtInterface<ABI::Windows::UI::Xaml::Media::IProjection>(value).Get()));
}

- (WFPoint*)renderTransformOrigin {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_RenderTransformOrigin(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setRenderTransformOrigin:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_RenderTransformOrigin(*[value internalStruct]));
}

- (BOOL)isHitTestVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHitTestVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsHitTestVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsHitTestVisible((boolean)value));
}

- (WXVisibility)visibility {
    ABI::Windows::UI::Xaml::Visibility unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Visibility(&unmarshalledReturn));
    return (WXVisibility)unmarshalledReturn;
}

- (void)setVisibility:(WXVisibility)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Visibility((ABI::Windows::UI::Xaml::Visibility)value));
}

- (WFSize*)renderSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_RenderSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (BOOL)useLayoutRounding {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_UseLayoutRounding(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setUseLayoutRounding:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_UseLayoutRounding((boolean)value));
}

- (WUXMATransitionCollection*)transitions {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Animation::Transition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Transitions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMATransitionCollection>(unmarshalledReturn.Get());
}

- (void)setTransitions:(WUXMATransitionCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Transitions(_getRtInterface<IVector<ABI::Windows::UI::Xaml::Media::Animation::Transition*>>(value).Get()));
}

- (WUXMCacheMode*)cacheMode {
    ComPtr<ABI::Windows::UI::Xaml::Media::ICacheMode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_CacheMode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMCacheMode>(unmarshalledReturn.Get());
}

- (void)setCacheMode:(WUXMCacheMode*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_CacheMode(_getRtInterface<ABI::Windows::UI::Xaml::Media::ICacheMode>(value).Get()));
}

- (BOOL)isTapEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTapEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsTapEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsTapEnabled((boolean)value));
}

- (BOOL)isDoubleTapEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleTapEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsDoubleTapEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDoubleTapEnabled((boolean)value));
}

- (BOOL)isRightTapEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRightTapEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsRightTapEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsRightTapEnabled((boolean)value));
}

- (BOOL)isHoldingEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHoldingEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsHoldingEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsHoldingEnabled((boolean)value));
}

- (WUXIManipulationModes)manipulationMode {
    ABI::Windows::UI::Xaml::Input::ManipulationModes unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_ManipulationMode(&unmarshalledReturn));
    return (WUXIManipulationModes)unmarshalledReturn;
}

- (void)setManipulationMode:(WUXIManipulationModes)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_ManipulationMode((ABI::Windows::UI::Xaml::Input::ManipulationModes)value));
}

- (NSArray* /* WUXIPointer* */)pointerCaptures {
    ComPtr<IVectorView<ABI::Windows::UI::Xaml::Input::Pointer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerCaptures(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUXIPointer_create(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addKeyUpEvent:(WUXIKeyEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_KeyUp(Make<WUXIKeyEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeKeyUpEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_KeyUp(token));
}

- (EventRegistrationToken)addKeyDownEvent:(WUXIKeyEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_KeyDown(Make<WUXIKeyEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeKeyDownEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_KeyDown(token));
}

- (EventRegistrationToken)addGotFocusEvent:(WXRoutedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_GotFocus(Make<WXRoutedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeGotFocusEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_GotFocus(token));
}

- (EventRegistrationToken)addLostFocusEvent:(WXRoutedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_LostFocus(Make<WXRoutedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLostFocusEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LostFocus(token));
}

- (EventRegistrationToken)addDragEnterEvent:(WXDragEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_DragEnter(Make<WXDragEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDragEnterEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DragEnter(token));
}

- (EventRegistrationToken)addDragLeaveEvent:(WXDragEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_DragLeave(Make<WXDragEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDragLeaveEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DragLeave(token));
}

- (EventRegistrationToken)addDragOverEvent:(WXDragEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_DragOver(Make<WXDragEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDragOverEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DragOver(token));
}

- (EventRegistrationToken)addDropEvent:(WXDragEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_Drop(Make<WXDragEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDropEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Drop(token));
}

- (EventRegistrationToken)addPointerPressedEvent:(WUXIPointerEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerPressed(Make<WUXIPointerEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerPressedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerPressed(token));
}

- (EventRegistrationToken)addPointerMovedEvent:(WUXIPointerEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerMoved(Make<WUXIPointerEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerMovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerMoved(token));
}

- (EventRegistrationToken)addPointerReleasedEvent:(WUXIPointerEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerReleased(Make<WUXIPointerEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerReleasedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerReleased(token));
}

- (EventRegistrationToken)addPointerEnteredEvent:(WUXIPointerEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerEntered(Make<WUXIPointerEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerEnteredEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerEntered(token));
}

- (EventRegistrationToken)addPointerExitedEvent:(WUXIPointerEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerExited(Make<WUXIPointerEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerExitedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerExited(token));
}

- (EventRegistrationToken)addPointerCaptureLostEvent:(WUXIPointerEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerCaptureLost(Make<WUXIPointerEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerCaptureLostEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerCaptureLost(token));
}

- (EventRegistrationToken)addPointerCanceledEvent:(WUXIPointerEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerCanceled(Make<WUXIPointerEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerCanceledEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerCanceled(token));
}

- (EventRegistrationToken)addPointerWheelChangedEvent:(WUXIPointerEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerWheelChanged(Make<WUXIPointerEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerWheelChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerWheelChanged(token));
}

- (EventRegistrationToken)addTappedEvent:(WUXITappedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_Tapped(Make<WUXITappedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTappedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Tapped(token));
}

- (EventRegistrationToken)addDoubleTappedEvent:(WUXIDoubleTappedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_DoubleTapped(Make<WUXIDoubleTappedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDoubleTappedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DoubleTapped(token));
}

- (EventRegistrationToken)addHoldingEvent:(WUXIHoldingEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_Holding(Make<WUXIHoldingEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHoldingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Holding(token));
}

- (EventRegistrationToken)addRightTappedEvent:(WUXIRightTappedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_RightTapped(Make<WUXIRightTappedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRightTappedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RightTapped(token));
}

- (EventRegistrationToken)addManipulationStartingEvent:(WUXIManipulationStartingEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ManipulationStarting(Make<WUXIManipulationStartingEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeManipulationStartingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ManipulationStarting(token));
}

- (EventRegistrationToken)addManipulationInertiaStartingEvent:(WUXIManipulationInertiaStartingEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_ManipulationInertiaStarting(Make<WUXIManipulationInertiaStartingEventHandler_shim>(value).Get(),
                                                                 &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeManipulationInertiaStartingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ManipulationInertiaStarting(token));
}

- (EventRegistrationToken)addManipulationStartedEvent:(WUXIManipulationStartedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_ManipulationStarted(Make<WUXIManipulationStartedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeManipulationStartedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ManipulationStarted(token));
}

- (EventRegistrationToken)addManipulationDeltaEvent:(WUXIManipulationDeltaEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_ManipulationDelta(Make<WUXIManipulationDeltaEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeManipulationDeltaEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ManipulationDelta(token));
}

- (EventRegistrationToken)addManipulationCompletedEvent:(WUXIManipulationCompletedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ManipulationCompleted(Make<WUXIManipulationCompletedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeManipulationCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ManipulationCompleted(token));
}

- (void)measure:(WFSize*)availableSize {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->Measure(*[availableSize internalStruct]));
}

- (void)arrange:(WFRect*)finalRect {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->Arrange(*[finalRect internalStruct]));
}

- (BOOL)capturePointer:(WUXIPointer*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(
        _comInst->CapturePointer(_getRtInterface<ABI::Windows::UI::Xaml::Input::IPointer>(value).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)releasePointerCapture:(WUXIPointer*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->ReleasePointerCapture(_getRtInterface<ABI::Windows::UI::Xaml::Input::IPointer>(value).Get()));
}

- (void)releasePointerCaptures {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->ReleasePointerCaptures());
}

- (void)addHandler:(WXRoutedEvent*)routedEvent handler:(RTObject*)handler handledEventsToo:(BOOL)handledEventsToo {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->AddHandler(_getRtInterface<ABI::Windows::UI::Xaml::IRoutedEvent>(routedEvent).Get(),
                                            [handler comObj].Get(),
                                            (boolean)handledEventsToo));
}

- (void)removeHandler:(WXRoutedEvent*)routedEvent handler:(RTObject*)handler {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveHandler(_getRtInterface<ABI::Windows::UI::Xaml::IRoutedEvent>(routedEvent).Get(), [handler comObj].Get()));
}

- (WUXMGeneralTransform*)transformToVisual:(WXUIElement*)visual {
    ComPtr<ABI::Windows::UI::Xaml::Media::IGeneralTransform> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(
        _comInst->TransformToVisual(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(visual).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMGeneralTransform>(unmarshalledReturn.Get());
}

- (void)invalidateMeasure {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->InvalidateMeasure());
}

- (void)invalidateArrange {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->InvalidateArrange());
}

- (void)updateLayout {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateLayout());
}

- (WUXAPAutomationPeer*)onCreateAutomationPeer {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElementOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnCreateAutomationPeer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPAutomationPeer>(unmarshalledReturn.Get());
}

- (void)onDisconnectVisualChildren {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElementOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnDisconnectVisualChildren());
}

- (id<NSFastEnumeration> /* id<NSFastEnumeration> < WFPoint* > */)findSubElementsForTouchTargeting:(WFPoint*)point
                                                                                      boundingRect:(WFRect*)boundingRect {
    ComPtr<IIterable<IIterable<ABI::Windows::Foundation::Point>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElementOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->FindSubElementsForTouchTargeting(*[point internalStruct],
                                                                  *[boundingRect internalStruct],
                                                                  unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_RTProxiedIterableNSArray_WFPoint_create(unmarshalledReturn.Get());
}

- (WUXMElementCompositeMode)compositeMode {
    ABI::Windows::UI::Xaml::Media::ElementCompositeMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompositeMode(&unmarshalledReturn));
    return (WUXMElementCompositeMode)unmarshalledReturn;
}

- (void)setCompositeMode:(WUXMElementCompositeMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CompositeMode((ABI::Windows::UI::Xaml::Media::ElementCompositeMode)value));
}

- (BOOL)cancelDirectManipulations {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement2>(self);
    THROW_NS_IF_FAILED(_comInst->CancelDirectManipulations(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUXMMTransform3D*)transform3D {
    ComPtr<ABI::Windows::UI::Xaml::Media::Media3D::ITransform3D> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement3>(self);
    THROW_NS_IF_FAILED(_comInst->get_Transform3D(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMMTransform3D>(unmarshalledReturn.Get());
}

- (void)setTransform3D:(WUXMMTransform3D*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement3>(self);
    THROW_NS_IF_FAILED(_comInst->put_Transform3D(_getRtInterface<ABI::Windows::UI::Xaml::Media::Media3D::ITransform3D>(value).Get()));
}

- (BOOL)canDrag {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement3>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanDrag(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanDrag:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanDrag((boolean)value));
}

- (EventRegistrationToken)addDragStartingEvent:(void (^)(WXUIElement*, WXDragStartingEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement3>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_DragStarting(Make<ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs>(value).Get(),
                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDragStartingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement3>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DragStarting(token));
}

- (EventRegistrationToken)addDropCompletedEvent:(void (^)(WXUIElement*, WXDropCompletedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement3>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_DropCompleted(Make<ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs>(value).Get(),
                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDropCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement3>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DropCompleted(token));
}

- (void)startDragAsync:(WUIPointerPoint*)pointerPoint
               success:(void (^)(WADDataPackageOperation))success
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement3>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartDragAsync(_getRtInterface<ABI::Windows::UI::Input::IPointerPoint>(pointerPoint).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WADDataPackageOperation)result);
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (WUXCPFlyoutBase*)contextFlyout {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContextFlyout(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCPFlyoutBase>(unmarshalledReturn.Get());
}

- (void)setContextFlyout:(WUXCPFlyoutBase*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ContextFlyout(_getRtInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase>(value).Get()));
}

- (BOOL)exitDisplayModeOnAccessKeyInvoked {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExitDisplayModeOnAccessKeyInvoked(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setExitDisplayModeOnAccessKeyInvoked:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExitDisplayModeOnAccessKeyInvoked((boolean)value));
}

- (BOOL)isAccessKeyScope {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAccessKeyScope(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsAccessKeyScope:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsAccessKeyScope((boolean)value));
}

- (WXDependencyObject*)accessKeyScopeOwner {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessKeyScopeOwner(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setAccessKeyScopeOwner:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->put_AccessKeyScopeOwner(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

- (NSString*)accessKey {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessKey(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAccessKey:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->put_AccessKey(nsStrToHstr(value).Get()));
}

- (EventRegistrationToken)addContextRequestedEvent:(void (^)(WXUIElement*, WUXIContextRequestedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->add_ContextRequested(
        Make<ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeContextRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ContextRequested(token));
}

- (EventRegistrationToken)addContextCanceledEvent:(void (^)(WXUIElement*, WXRoutedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ContextCanceled(Make<ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs>(value).Get(),
                                      &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeContextCanceledEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ContextCanceled(token));
}

- (EventRegistrationToken)addAccessKeyDisplayRequestedEvent:(void (^)(WXUIElement*, WUXIAccessKeyDisplayRequestedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->add_AccessKeyDisplayRequested(
        Make<ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAccessKeyDisplayRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AccessKeyDisplayRequested(token));
}

- (EventRegistrationToken)addAccessKeyDisplayDismissedEvent:(void (^)(WXUIElement*, WUXIAccessKeyDisplayDismissedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->add_AccessKeyDisplayDismissed(
        Make<ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAccessKeyDisplayDismissedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AccessKeyDisplayDismissed(token));
}

- (EventRegistrationToken)addAccessKeyInvokedEvent:(void (^)(WXUIElement*, WUXIAccessKeyInvokedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->add_AccessKeyInvoked(
        Make<ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAccessKeyInvokedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IUIElement4>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AccessKeyInvoked(token));
}

@end

@implementation WXVisualState

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IVisualState> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.VisualState").Get(), &out));
    return [_createRtProxy<WXVisualState>(out.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualState>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUXMAStoryboard*)storyboard {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualState>(self);
    THROW_NS_IF_FAILED(_comInst->get_Storyboard(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAStoryboard>(unmarshalledReturn.Get());
}

- (void)setStoryboard:(WUXMAStoryboard*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualState>(self);
    THROW_NS_IF_FAILED(_comInst->put_Storyboard(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard>(value).Get()));
}

- (WXSetterBaseCollection*)setters {
    ComPtr<ABI::Windows::UI::Xaml::ISetterBaseCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualState2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Setters(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXSetterBaseCollection>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WXStateTriggerBase* */)stateTriggers {
    ComPtr<IVector<ABI::Windows::UI::Xaml::StateTriggerBase*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualState2>(self);
    THROW_NS_IF_FAILED(_comInst->get_StateTriggers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WXStateTriggerBase_create(unmarshalledReturn.Get());
}

@end

@implementation WXVisualStateGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IVisualStateGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.VisualStateGroup").Get(), &out));
    return [_createRtProxy<WXVisualStateGroup>(out.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSMutableArray* /* WXVisualTransition* */)transitions {
    ComPtr<IVector<ABI::Windows::UI::Xaml::VisualTransition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Transitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WXVisualTransition_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WXVisualState* */)states {
    ComPtr<IVector<ABI::Windows::UI::Xaml::VisualState*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_States(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WXVisualState_create(unmarshalledReturn.Get());
}

- (WXVisualState*)currentState {
    ComPtr<ABI::Windows::UI::Xaml::IVisualState> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentState(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXVisualState>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addCurrentStateChangedEvent:(WXVisualStateChangedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateGroup>(self);
    THROW_NS_IF_FAILED(_comInst->add_CurrentStateChanged(Make<WXVisualStateChangedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCurrentStateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateGroup>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CurrentStateChanged(token));
}

- (EventRegistrationToken)addCurrentStateChangingEvent:(WXVisualStateChangedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateGroup>(self);
    THROW_NS_IF_FAILED(_comInst->add_CurrentStateChanging(Make<WXVisualStateChangedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCurrentStateChangingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateGroup>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CurrentStateChanging(token));
}

@end

@implementation WXVisualStateManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IVisualStateManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::IVisualStateManagerFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.VisualStateManager").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::IVisualStateManager> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WXIVisualStateManagerOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WXIVisualStateManagerOverrides)]) {
        typedOuter = Make<WXIVisualStateManagerOverrides_RtProxy>();
        outer = typedOuter;
    }
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WXVisualStateManager* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::IVisualStateManagerStatics> WXIVisualStateManagerStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IVisualStateManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.VisualStateManager").Get(), &inst));
    return inst;
}

+ (NSMutableArray* /* WXVisualStateGroup* */)getVisualStateGroups:(WXFrameworkElement*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::VisualStateGroup*>> unmarshalledReturn;
    auto _comInst = WXIVisualStateManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetVisualStateGroups(_getRtInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(obj).Get(),
                                                      unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WXVisualStateGroup_create(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)customVisualStateManagerProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIVisualStateManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CustomVisualStateManagerProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXVisualStateManager*)getCustomVisualStateManager:(WXFrameworkElement*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IVisualStateManager> unmarshalledReturn;
    auto _comInst = WXIVisualStateManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetCustomVisualStateManager(_getRtInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(obj).Get(),
                                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXVisualStateManager>(unmarshalledReturn.Get());
}

+ (void)setCustomVisualStateManager:(WXFrameworkElement*)obj value:(WXVisualStateManager*)value {
    auto _comInst = WXIVisualStateManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetCustomVisualStateManager(_getRtInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(obj).Get(),
                                                             _getRtInterface<ABI::Windows::UI::Xaml::IVisualStateManager>(value).Get()));
}

+ (BOOL)goToState:(WXCControl*)control stateName:(NSString*)stateName useTransitions:(BOOL)useTransitions {
    boolean unmarshalledReturn;
    auto _comInst = WXIVisualStateManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GoToState(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IControl>(control).Get(),
                                           nsStrToHstr(stateName).Get(),
                                           (boolean)useTransitions,
                                           &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)goToStateCore:(WXCControl*)control
         templateRoot:(WXFrameworkElement*)templateRoot
            stateName:(NSString*)stateName
                group:(WXVisualStateGroup*)group
                state:(WXVisualState*)state
       useTransitions:(BOOL)useTransitions {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateManagerOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GoToStateCore(_getRtInterface<ABI::Windows::UI::Xaml::Controls::IControl>(control).Get(),
                                               _getRtInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(templateRoot).Get(),
                                               nsStrToHstr(stateName).Get(),
                                               _getRtInterface<ABI::Windows::UI::Xaml::IVisualStateGroup>(group).Get(),
                                               _getRtInterface<ABI::Windows::UI::Xaml::IVisualState>(state).Get(),
                                               (boolean)useTransitions,
                                               &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)raiseCurrentStateChanging:(WXVisualStateGroup*)stateGroup
                         oldState:(WXVisualState*)oldState
                         newState:(WXVisualState*)newState
                          control:(WXCControl*)control {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateManagerProtected>(self);
    THROW_NS_IF_FAILED(_comInst->RaiseCurrentStateChanging(_getRtInterface<ABI::Windows::UI::Xaml::IVisualStateGroup>(stateGroup).Get(),
                                                           _getRtInterface<ABI::Windows::UI::Xaml::IVisualState>(oldState).Get(),
                                                           _getRtInterface<ABI::Windows::UI::Xaml::IVisualState>(newState).Get(),
                                                           _getRtInterface<ABI::Windows::UI::Xaml::Controls::IControl>(control).Get()));
}

- (void)raiseCurrentStateChanged:(WXVisualStateGroup*)stateGroup
                        oldState:(WXVisualState*)oldState
                        newState:(WXVisualState*)newState
                         control:(WXCControl*)control {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualStateManagerProtected>(self);
    THROW_NS_IF_FAILED(_comInst->RaiseCurrentStateChanged(_getRtInterface<ABI::Windows::UI::Xaml::IVisualStateGroup>(stateGroup).Get(),
                                                          _getRtInterface<ABI::Windows::UI::Xaml::IVisualState>(oldState).Get(),
                                                          _getRtInterface<ABI::Windows::UI::Xaml::IVisualState>(newState).Get(),
                                                          _getRtInterface<ABI::Windows::UI::Xaml::Controls::IControl>(control).Get()));
}

@end

@implementation WXVisualTransition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IVisualTransition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::IVisualTransitionFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.VisualTransition").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::IVisualTransition> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WXVisualTransition* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (WXDuration*)generatedDuration {
    ABI::Windows::UI::Xaml::Duration unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeneratedDuration(&unmarshalledReturn));
    return WXDuration_create(unmarshalledReturn);
}

- (void)setGeneratedDuration:(WXDuration*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualTransition>(self);
    THROW_NS_IF_FAILED(_comInst->put_GeneratedDuration(*[value internalStruct]));
}

- (WUXMAEasingFunctionBase*)generatedEasingFunction {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeneratedEasingFunction(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAEasingFunctionBase>(unmarshalledReturn.Get());
}

- (void)setGeneratedEasingFunction:(WUXMAEasingFunctionBase*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualTransition>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_GeneratedEasingFunction(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>(value).Get()));
}

- (NSString*)to {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_To(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTo:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualTransition>(self);
    THROW_NS_IF_FAILED(_comInst->put_To(nsStrToHstr(value).Get()));
}

- (NSString*)from {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_From(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFrom:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualTransition>(self);
    THROW_NS_IF_FAILED(_comInst->put_From(nsStrToHstr(value).Get()));
}

- (WUXMAStoryboard*)storyboard {
    ComPtr<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualTransition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Storyboard(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMAStoryboard>(unmarshalledReturn.Get());
}

- (void)setStoryboard:(WUXMAStoryboard*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IVisualTransition>(self);
    THROW_NS_IF_FAILED(_comInst->put_Storyboard(_getRtInterface<ABI::Windows::UI::Xaml::Media::Animation::IStoryboard>(value).Get()));
}

@end

@implementation WXAdaptiveTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IAdaptiveTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::IAdaptiveTriggerFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.AdaptiveTrigger").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::IAdaptiveTrigger> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WXAdaptiveTrigger* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::IAdaptiveTriggerStatics> WXIAdaptiveTriggerStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IAdaptiveTriggerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.AdaptiveTrigger").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)minWindowWidthProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIAdaptiveTriggerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MinWindowWidthProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)minWindowHeightProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIAdaptiveTriggerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MinWindowHeightProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)minWindowWidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IAdaptiveTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinWindowWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMinWindowWidth:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IAdaptiveTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->put_MinWindowWidth(value));
}

- (double)minWindowHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IAdaptiveTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinWindowHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMinWindowHeight:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IAdaptiveTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->put_MinWindowHeight(value));
}

@end

@implementation WXEventTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IEventTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.EventTrigger").Get(), &out));
    return [_createRtProxy<WXEventTrigger>(out.Get()) retain];
}

- (WXRoutedEvent*)routedEvent {
    ComPtr<ABI::Windows::UI::Xaml::IRoutedEvent> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IEventTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoutedEvent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXRoutedEvent>(unmarshalledReturn.Get());
}

- (void)setRoutedEvent:(WXRoutedEvent*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IEventTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->put_RoutedEvent(_getRtInterface<ABI::Windows::UI::Xaml::IRoutedEvent>(value).Get()));
}

- (WXTriggerActionCollection*)actions {
    ComPtr<IVector<ABI::Windows::UI::Xaml::TriggerAction*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IEventTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_Actions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXTriggerActionCollection>(unmarshalledReturn.Get());
}

@end

@implementation WXFrameworkElement

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IFrameworkElement> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::IFrameworkElementStatics> WXIFrameworkElementStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IFrameworkElementStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.FrameworkElement").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)tagProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TagProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)languageProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LanguageProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)actualWidthProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ActualWidthProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)actualHeightProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ActualHeightProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)widthProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_WidthProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)heightProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HeightProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)minWidthProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MinWidthProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)maxWidthProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MaxWidthProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)minHeightProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MinHeightProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)maxHeightProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MaxHeightProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)horizontalAlignmentProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HorizontalAlignmentProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)verticalAlignmentProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VerticalAlignmentProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)marginProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MarginProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)nameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)dataContextProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DataContextProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)styleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StyleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)flowDirectionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FlowDirectionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::IFrameworkElementStatics4> WXIFrameworkElementStatics4_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IFrameworkElementStatics4> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.FrameworkElement").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)allowFocusOnInteractionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllowFocusOnInteractionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)focusVisualMarginProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_FocusVisualMarginProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)focusVisualSecondaryThicknessProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_FocusVisualSecondaryThicknessProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)focusVisualPrimaryThicknessProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_FocusVisualPrimaryThicknessProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)focusVisualSecondaryBrushProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_FocusVisualSecondaryBrushProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)focusVisualPrimaryBrushProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_FocusVisualPrimaryBrushProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)allowFocusWhenDisabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllowFocusWhenDisabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::IFrameworkElementStatics2> WXIFrameworkElementStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IFrameworkElementStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.FrameworkElement").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)requestedThemeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIFrameworkElementStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_RequestedThemeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WXTriggerCollection*)triggers {
    ComPtr<IVector<ABI::Windows::UI::Xaml::TriggerBase*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Triggers(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXTriggerCollection>(unmarshalledReturn.Get());
}

- (WXResourceDictionary*)resources {
    ComPtr<ABI::Windows::UI::Xaml::IResourceDictionary> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Resources(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXResourceDictionary>(unmarshalledReturn.Get());
}

- (void)setResources:(WXResourceDictionary*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Resources(_getRtInterface<ABI::Windows::UI::Xaml::IResourceDictionary>(value).Get()));
}

- (RTObject*)tag {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tag(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setTag:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Tag([value comObj].Get()));
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Language(nsStrToHstr(value).Get()));
}

- (double)actualWidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActualWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)actualHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActualHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)width {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setWidth:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Width(value));
}

- (double)height {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHeight:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Height(value));
}

- (double)minWidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMinWidth:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_MinWidth(value));
}

- (double)maxWidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxWidth:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxWidth(value));
}

- (double)minHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMinHeight:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_MinHeight(value));
}

- (double)maxHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxHeight:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxHeight(value));
}

- (WXHorizontalAlignment)horizontalAlignment {
    ABI::Windows::UI::Xaml::HorizontalAlignment unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalAlignment(&unmarshalledReturn));
    return (WXHorizontalAlignment)unmarshalledReturn;
}

- (void)setHorizontalAlignment:(WXHorizontalAlignment)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_HorizontalAlignment((ABI::Windows::UI::Xaml::HorizontalAlignment)value));
}

- (WXVerticalAlignment)verticalAlignment {
    ABI::Windows::UI::Xaml::VerticalAlignment unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalAlignment(&unmarshalledReturn));
    return (WXVerticalAlignment)unmarshalledReturn;
}

- (void)setVerticalAlignment:(WXVerticalAlignment)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_VerticalAlignment((ABI::Windows::UI::Xaml::VerticalAlignment)value));
}

- (WXThickness*)margin {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Margin(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (void)setMargin:(WXThickness*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Margin(*[value internalStruct]));
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (WFUri*)baseUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_BaseUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (RTObject*)dataContext {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataContext(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setDataContext:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_DataContext([value comObj].Get()));
}

- (WXStyle*)style {
    ComPtr<ABI::Windows::UI::Xaml::IStyle> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Style(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXStyle>(unmarshalledReturn.Get());
}

- (void)setStyle:(WXStyle*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Style(_getRtInterface<ABI::Windows::UI::Xaml::IStyle>(value).Get()));
}

- (WXDependencyObject*)parent {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (WXFlowDirection)flowDirection {
    ABI::Windows::UI::Xaml::FlowDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_FlowDirection(&unmarshalledReturn));
    return (WXFlowDirection)unmarshalledReturn;
}

- (void)setFlowDirection:(WXFlowDirection)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_FlowDirection((ABI::Windows::UI::Xaml::FlowDirection)value));
}

- (EventRegistrationToken)addLoadedEvent:(WXRoutedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_Loaded(Make<WXRoutedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLoadedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Loaded(token));
}

- (EventRegistrationToken)addUnloadedEvent:(WXRoutedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_Unloaded(Make<WXRoutedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUnloadedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Unloaded(token));
}

- (EventRegistrationToken)addSizeChangedEvent:(WXSizeChangedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_SizeChanged(Make<WXSizeChangedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSizeChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SizeChanged(token));
}

- (EventRegistrationToken)addLayoutUpdatedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->add_LayoutUpdated(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLayoutUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LayoutUpdated(token));
}

- (RTObject*)findName:(NSString*)name {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->FindName(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setBinding:(WXDependencyProperty*)dp binding:(WUXDBindingBase*)binding {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(self);
    THROW_NS_IF_FAILED(_comInst->SetBinding(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(dp).Get(),
                                            _getRtInterface<ABI::Windows::UI::Xaml::Data::IBindingBase>(binding).Get()));
}

- (WFSize*)measureOverride:(WFSize*)availableSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElementOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->MeasureOverride(*[availableSize internalStruct], &unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFSize*)arrangeOverride:(WFSize*)finalSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElementOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->ArrangeOverride(*[finalSize internalStruct], &unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (void)onApplyTemplate {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElementOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnApplyTemplate());
}

- (WXElementTheme)requestedTheme {
    ABI::Windows::UI::Xaml::ElementTheme unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedTheme(&unmarshalledReturn));
    return (WXElementTheme)unmarshalledReturn;
}

- (void)setRequestedTheme:(WXElementTheme)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RequestedTheme((ABI::Windows::UI::Xaml::ElementTheme)value));
}

- (EventRegistrationToken)addDataContextChangedEvent:(void (^)(WXFrameworkElement*, WXDataContextChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement2>(self);
    THROW_NS_IF_FAILED(_comInst->add_DataContextChanged(
        Make<ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDataContextChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DataContextChanged(token));
}

- (WUXDBindingExpression*)getBindingExpression:(WXDependencyProperty*)dp {
    ComPtr<ABI::Windows::UI::Xaml::Data::IBindingExpression> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement2>(self);
    THROW_NS_IF_FAILED(_comInst->GetBindingExpression(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(dp).Get(),
                                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDBindingExpression>(unmarshalledReturn.Get());
}

- (BOOL)goToElementStateCore:(NSString*)stateName useTransitions:(BOOL)useTransitions {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElementOverrides2>(self);
    THROW_NS_IF_FAILED(_comInst->GoToElementStateCore(nsStrToHstr(stateName).Get(), (boolean)useTransitions, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addLoadingEvent:(void (^)(WXFrameworkElement*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement3>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Loading(Make<ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLoadingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement3>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Loading(token));
}

- (BOOL)allowFocusOnInteraction {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement4>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowFocusOnInteraction(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowFocusOnInteraction:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement4>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowFocusOnInteraction((boolean)value));
}

- (WXThickness*)focusVisualMargin {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement4>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusVisualMargin(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (void)setFocusVisualMargin:(WXThickness*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement4>(self);
    THROW_NS_IF_FAILED(_comInst->put_FocusVisualMargin(*[value internalStruct]));
}

- (WXThickness*)focusVisualSecondaryThickness {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement4>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusVisualSecondaryThickness(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (void)setFocusVisualSecondaryThickness:(WXThickness*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement4>(self);
    THROW_NS_IF_FAILED(_comInst->put_FocusVisualSecondaryThickness(*[value internalStruct]));
}

- (WXThickness*)focusVisualPrimaryThickness {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement4>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusVisualPrimaryThickness(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (void)setFocusVisualPrimaryThickness:(WXThickness*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement4>(self);
    THROW_NS_IF_FAILED(_comInst->put_FocusVisualPrimaryThickness(*[value internalStruct]));
}

- (WUXMBrush*)focusVisualSecondaryBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement4>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusVisualSecondaryBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setFocusVisualSecondaryBrush:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement4>(self);
    THROW_NS_IF_FAILED(_comInst->put_FocusVisualSecondaryBrush(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)focusVisualPrimaryBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement4>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusVisualPrimaryBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setFocusVisualPrimaryBrush:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement4>(self);
    THROW_NS_IF_FAILED(_comInst->put_FocusVisualPrimaryBrush(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (BOOL)allowFocusWhenDisabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement4>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowFocusWhenDisabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowFocusWhenDisabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IFrameworkElement4>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowFocusWhenDisabled((boolean)value));
}

@end

@implementation WXMediaFailedRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IMediaFailedRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)errorTrace {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IMediaFailedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorTrace(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WXSetter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::ISetter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Xaml::ISetterFactory> WXISetterFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::ISetterFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Setter").Get(), &inst));
    return inst;
}

+ (WXSetter*)makeInstance:(WXDependencyProperty*)targetProperty value:(RTObject*)value {
    ComPtr<ABI::Windows::UI::Xaml::ISetter> unmarshalledReturn;
    auto _comInst = WXISetterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(targetProperty).Get(),
                                                [value comObj].Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WXSetter>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Setter").Get(), &out));
    return [_createRtProxy<WXSetter>(out.Get()) retain];
}

- (WXDependencyProperty*)property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::ISetter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (void)setProperty:(WXDependencyProperty*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::ISetter>(self);
    THROW_NS_IF_FAILED(_comInst->put_Property(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(value).Get()));
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::ISetter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::ISetter>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value([value comObj].Get()));
}

- (WXTargetPropertyPath*)target {
    ComPtr<ABI::Windows::UI::Xaml::ITargetPropertyPath> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::ISetter2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Target(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXTargetPropertyPath>(unmarshalledReturn.Get());
}

- (void)setTarget:(WXTargetPropertyPath*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::ISetter2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Target(_getRtInterface<ABI::Windows::UI::Xaml::ITargetPropertyPath>(value).Get()));
}

@end

@implementation WXStateTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IStateTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.StateTrigger").Get(), &out));
    return [_createRtProxy<WXStateTrigger>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::IStateTriggerStatics> WXIStateTriggerStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IStateTriggerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.StateTrigger").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)isActiveProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WXIStateTriggerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsActiveProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (BOOL)isActive {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IStateTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsActive(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsActive:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IStateTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsActive((boolean)value));
}

@end

@implementation WXGridLengthHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IGridLengthHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::IGridLengthHelperStatics> WXIGridLengthHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IGridLengthHelperStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.GridLengthHelper").Get(), &inst));
    return inst;
}

+ (WXGridLength*)Auto {
    ABI::Windows::UI::Xaml::GridLength unmarshalledReturn;
    auto _comInst = WXIGridLengthHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Auto(&unmarshalledReturn));
    return WXGridLength_create(unmarshalledReturn);
}

+ (WXGridLength*)fromPixels:(double)pixels {
    ABI::Windows::UI::Xaml::GridLength unmarshalledReturn;
    auto _comInst = WXIGridLengthHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromPixels(pixels, &unmarshalledReturn));
    return WXGridLength_create(unmarshalledReturn);
}

+ (WXGridLength*)fromValueAndType:(double)value type:(WXGridUnitType)type {
    ABI::Windows::UI::Xaml::GridLength unmarshalledReturn;
    auto _comInst = WXIGridLengthHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromValueAndType(value, (ABI::Windows::UI::Xaml::GridUnitType)type, &unmarshalledReturn));
    return WXGridLength_create(unmarshalledReturn);
}

+ (BOOL)getIsAbsolute:(WXGridLength*)target {
    boolean unmarshalledReturn;
    auto _comInst = WXIGridLengthHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetIsAbsolute(*[target internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)getIsAuto:(WXGridLength*)target {
    boolean unmarshalledReturn;
    auto _comInst = WXIGridLengthHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetIsAuto(*[target internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)getIsStar:(WXGridLength*)target {
    boolean unmarshalledReturn;
    auto _comInst = WXIGridLengthHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetIsStar(*[target internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)equals:(WXGridLength*)target value:(WXGridLength*)value {
    boolean unmarshalledReturn;
    auto _comInst = WXIGridLengthHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Equals(*[target internalStruct], *[value internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WXBindingFailedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IBindingFailedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)message {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IBindingFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WXDebugSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IDebugSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)enableFrameRateCounter {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDebugSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnableFrameRateCounter(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnableFrameRateCounter:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDebugSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_EnableFrameRateCounter((boolean)value));
}

- (BOOL)isBindingTracingEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDebugSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBindingTracingEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsBindingTracingEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDebugSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsBindingTracingEnabled((boolean)value));
}

- (BOOL)isOverdrawHeatMapEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDebugSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOverdrawHeatMapEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsOverdrawHeatMapEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDebugSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsOverdrawHeatMapEnabled((boolean)value));
}

- (EventRegistrationToken)addBindingFailedEvent:(WXBindingFailedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDebugSettings>(self);
    THROW_NS_IF_FAILED(_comInst->add_BindingFailed(Make<WXBindingFailedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBindingFailedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDebugSettings>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BindingFailed(token));
}

- (BOOL)enableRedrawRegions {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDebugSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnableRedrawRegions(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnableRedrawRegions:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDebugSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->put_EnableRedrawRegions((boolean)value));
}

- (BOOL)isTextPerformanceVisualizationEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDebugSettings3>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTextPerformanceVisualizationEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsTextPerformanceVisualizationEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IDebugSettings3>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsTextPerformanceVisualizationEnabled((boolean)value));
}

@end

@implementation WXApplication

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IApplication> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::IApplicationFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Application").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::IApplication> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WXIApplicationOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WXIApplicationOverrides)]) {
        typedOuter = Make<WXIApplicationOverrides_RtProxy>();
        outer = typedOuter;
    }
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WXApplication* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::IApplicationStatics> WXIApplicationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IApplicationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Application").Get(), &inst));
    return inst;
}

+ (WXApplication*)current {
    ComPtr<ABI::Windows::UI::Xaml::IApplication> unmarshalledReturn;
    auto _comInst = WXIApplicationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Current(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXApplication>(unmarshalledReturn.Get());
}

+ (void)start:(WXApplicationInitializationCallback)callback {
    auto _comInst = WXIApplicationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Start(Make<WXApplicationInitializationCallback_shim>(callback).Get()));
}

+ (void)loadComponent:(RTObject*)component resourceLocator:(WFUri*)resourceLocator {
    auto _comInst = WXIApplicationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LoadComponent([component comObj].Get(),
                                               _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(resourceLocator).Get()));
}

+ (void)loadComponentWithResourceLocation:(RTObject*)component
                          resourceLocator:(WFUri*)resourceLocator
                componentResourceLocation:(WUXCPComponentResourceLocation)componentResourceLocation {
    auto _comInst = WXIApplicationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->LoadComponentWithResourceLocation([component comObj].Get(),
                                                    _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(resourceLocator).Get(),
                                                    (ABI::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation)
                                                        componentResourceLocation));
}

- (WXResourceDictionary*)resources {
    ComPtr<ABI::Windows::UI::Xaml::IResourceDictionary> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication>(self);
    THROW_NS_IF_FAILED(_comInst->get_Resources(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXResourceDictionary>(unmarshalledReturn.Get());
}

- (void)setResources:(WXResourceDictionary*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication>(self);
    THROW_NS_IF_FAILED(_comInst->put_Resources(_getRtInterface<ABI::Windows::UI::Xaml::IResourceDictionary>(value).Get()));
}

- (WXDebugSettings*)debugSettings {
    ComPtr<ABI::Windows::UI::Xaml::IDebugSettings> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication>(self);
    THROW_NS_IF_FAILED(_comInst->get_DebugSettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDebugSettings>(unmarshalledReturn.Get());
}

- (WXApplicationTheme)requestedTheme {
    ABI::Windows::UI::Xaml::ApplicationTheme unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedTheme(&unmarshalledReturn));
    return (WXApplicationTheme)unmarshalledReturn;
}

- (void)setRequestedTheme:(WXApplicationTheme)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication>(self);
    THROW_NS_IF_FAILED(_comInst->put_RequestedTheme((ABI::Windows::UI::Xaml::ApplicationTheme)value));
}

- (EventRegistrationToken)addUnhandledExceptionEvent:(WXUnhandledExceptionEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication>(self);
    THROW_NS_IF_FAILED(_comInst->add_UnhandledException(Make<WXUnhandledExceptionEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUnhandledExceptionEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UnhandledException(token));
}

- (EventRegistrationToken)addSuspendingEvent:(WXSuspendingEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication>(self);
    THROW_NS_IF_FAILED(_comInst->add_Suspending(Make<WXSuspendingEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSuspendingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Suspending(token));
}

- (EventRegistrationToken)addResumingEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication>(self);
    THROW_NS_IF_FAILED(_comInst->add_Resuming(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeResumingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Resuming(token));
}

- (void)exit {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication>(self);
    THROW_NS_IF_FAILED(_comInst->Exit());
}

- (void)onActivated:(RTObject<WAAIActivatedEventArgs>*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplicationOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnActivated(_getRtInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(args).Get()));
}

- (void)onLaunched:(WAALaunchActivatedEventArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplicationOverrides>(self);
    THROW_NS_IF_FAILED(
        _comInst->OnLaunched(_getRtInterface<ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs>(args).Get()));
}

- (void)onFileActivated:(WAAFileActivatedEventArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplicationOverrides>(self);
    THROW_NS_IF_FAILED(
        _comInst->OnFileActivated(_getRtInterface<ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgs>(args).Get()));
}

- (void)onSearchActivated:(WAASearchActivatedEventArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplicationOverrides>(self);
    THROW_NS_IF_FAILED(
        _comInst->OnSearchActivated(_getRtInterface<ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgs>(args).Get()));
}

- (void)onShareTargetActivated:(WAAShareTargetActivatedEventArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplicationOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnShareTargetActivated(
        _getRtInterface<ABI::Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs>(args).Get()));
}

- (void)onFileOpenPickerActivated:(WAAFileOpenPickerActivatedEventArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplicationOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnFileOpenPickerActivated(
        _getRtInterface<ABI::Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs>(args).Get()));
}

- (void)onFileSavePickerActivated:(WAAFileSavePickerActivatedEventArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplicationOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnFileSavePickerActivated(
        _getRtInterface<ABI::Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs>(args).Get()));
}

- (void)onCachedFileUpdaterActivated:(WAACachedFileUpdaterActivatedEventArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplicationOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnCachedFileUpdaterActivated(
        _getRtInterface<ABI::Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs>(args).Get()));
}

- (void)onWindowCreated:(WXWindowCreatedEventArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplicationOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnWindowCreated(_getRtInterface<ABI::Windows::UI::Xaml::IWindowCreatedEventArgs>(args).Get()));
}

- (WXFocusVisualKind)focusVisualKind {
    ABI::Windows::UI::Xaml::FocusVisualKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusVisualKind(&unmarshalledReturn));
    return (WXFocusVisualKind)unmarshalledReturn;
}

- (void)setFocusVisualKind:(WXFocusVisualKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication2>(self);
    THROW_NS_IF_FAILED(_comInst->put_FocusVisualKind((ABI::Windows::UI::Xaml::FocusVisualKind)value));
}

- (WXApplicationRequiresPointerMode)requiresPointerMode {
    ABI::Windows::UI::Xaml::ApplicationRequiresPointerMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequiresPointerMode(&unmarshalledReturn));
    return (WXApplicationRequiresPointerMode)unmarshalledReturn;
}

- (void)setRequiresPointerMode:(WXApplicationRequiresPointerMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RequiresPointerMode((ABI::Windows::UI::Xaml::ApplicationRequiresPointerMode)value));
}

- (EventRegistrationToken)addLeavingBackgroundEvent:(WXLeavingBackgroundEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication2>(self);
    THROW_NS_IF_FAILED(_comInst->add_LeavingBackground(Make<WXLeavingBackgroundEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLeavingBackgroundEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LeavingBackground(token));
}

- (EventRegistrationToken)addEnteredBackgroundEvent:(WXEnteredBackgroundEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication2>(self);
    THROW_NS_IF_FAILED(_comInst->add_EnteredBackground(Make<WXEnteredBackgroundEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEnteredBackgroundEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplication2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EnteredBackground(token));
}

- (void)onBackgroundActivated:(WAABackgroundActivatedEventArgs*)args {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::IApplicationOverrides2>(self);
    THROW_NS_IF_FAILED(_comInst->OnBackgroundActivated(
        _getRtInterface<ABI::Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs>(args).Get()));
}

@end

@implementation WXFrameworkViewSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IFrameworkViewSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.FrameworkViewSource").Get(), &out));
    return [_createRtProxy<WXFrameworkViewSource>(out.Get()) retain];
}

- (RTObject<WACIFrameworkView>*)createView {
    ComPtr<ABI::Windows::ApplicationModel::Core::IFrameworkView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IFrameworkViewSource>(self);
    THROW_NS_IF_FAILED(_comInst->CreateView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACIFrameworkView>(unmarshalledReturn.Get());
}

@end

@implementation WXPointHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IPointHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::IPointHelperStatics> WXIPointHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IPointHelperStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.PointHelper").Get(), &inst));
    return inst;
}

+ (WFPoint*)fromCoordinates:(float)x y:(float)y {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = WXIPointHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromCoordinates(x, y, &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

@end

@implementation WXRectHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::IRectHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::IRectHelperStatics> WXIRectHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::IRectHelperStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.RectHelper").Get(), &inst));
    return inst;
}

+ (WFRect*)empty {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = WXIRectHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Empty(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

+ (WFRect*)fromCoordinatesAndDimensions:(float)x y:(float)y width:(float)width height:(float)height {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = WXIRectHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromCoordinatesAndDimensions(x, y, width, height, &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

+ (WFRect*)fromPoints:(WFPoint*)point1 point2:(WFPoint*)point2 {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = WXIRectHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromPoints(*[point1 internalStruct], *[point2 internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

+ (WFRect*)fromLocationAndSize:(WFPoint*)location size:(WFSize*)size {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = WXIRectHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromLocationAndSize(*[location internalStruct], *[size internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

+ (BOOL)getIsEmpty:(WFRect*)target {
    boolean unmarshalledReturn;
    auto _comInst = WXIRectHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetIsEmpty(*[target internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (float)getBottom:(WFRect*)target {
    float unmarshalledReturn;
    auto _comInst = WXIRectHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetBottom(*[target internalStruct], &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (float)getLeft:(WFRect*)target {
    float unmarshalledReturn;
    auto _comInst = WXIRectHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetLeft(*[target internalStruct], &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (float)getRight:(WFRect*)target {
    float unmarshalledReturn;
    auto _comInst = WXIRectHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetRight(*[target internalStruct], &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (float)getTop:(WFRect*)target {
    float unmarshalledReturn;
    auto _comInst = WXIRectHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetTop(*[target internalStruct], &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (BOOL)contains:(WFRect*)target point:(WFPoint*)point {
    boolean unmarshalledReturn;
    auto _comInst = WXIRectHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Contains(*[target internalStruct], *[point internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)equals:(WFRect*)target value:(WFRect*)value {
    boolean unmarshalledReturn;
    auto _comInst = WXIRectHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Equals(*[target internalStruct], *[value internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (WFRect*)intersect:(WFRect*)target rect:(WFRect*)rect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = WXIRectHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Intersect(*[target internalStruct], *[rect internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

+ (WFRect*)unionWithPoint:(WFRect*)target point:(WFPoint*)point {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = WXIRectHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->UnionWithPoint(*[target internalStruct], *[point internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

+ (WFRect*)unionWithRect:(WFRect*)target rect:(WFRect*)rect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = WXIRectHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->UnionWithRect(*[target internalStruct], *[rect internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

@end

@implementation WXSizeHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::ISizeHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::ISizeHelperStatics> WXISizeHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::ISizeHelperStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.SizeHelper").Get(), &inst));
    return inst;
}

+ (WFSize*)empty {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = WXISizeHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Empty(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

+ (WFSize*)fromDimensions:(float)width height:(float)height {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = WXISizeHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromDimensions(width, height, &unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

+ (BOOL)getIsEmpty:(WFSize*)target {
    boolean unmarshalledReturn;
    auto _comInst = WXISizeHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetIsEmpty(*[target internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)equals:(WFSize*)target value:(WFSize*)value {
    boolean unmarshalledReturn;
    auto _comInst = WXISizeHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Equals(*[target internalStruct], *[value internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WXCornerRadius {
    ABI::Windows::UI::Xaml::CornerRadius structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::CornerRadius)s {
    WXCornerRadius* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::CornerRadius*)internalStruct {
    return &structVal;
}
- (double)topLeft {
    return structVal.TopLeft;
}
- (void)setTopLeft:(double)val {
    structVal.TopLeft = val;
}
- (double)topRight {
    return structVal.TopRight;
}
- (void)setTopRight:(double)val {
    structVal.TopRight = val;
}
- (double)bottomRight {
    return structVal.BottomRight;
}
- (void)setBottomRight:(double)val {
    structVal.BottomRight = val;
}
- (double)bottomLeft {
    return structVal.BottomLeft;
}
- (void)setBottomLeft:(double)val {
    structVal.BottomLeft = val;
}
@end
@implementation WXDuration {
    ABI::Windows::UI::Xaml::Duration structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Duration)s {
    WXDuration* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::Duration*)internalStruct {
    return &structVal;
}
- (WFTimeSpan*)timeSpan {
    return WFTimeSpan_create(structVal.TimeSpan);
}
- (void)setTimeSpan:(WFTimeSpan*)val {
    structVal.TimeSpan = *[val internalStruct];
}
- (WXDurationType)type {
    return (WXDurationType)structVal.Type;
}
- (void)setType:(WXDurationType)val {
    structVal.Type = (ABI::Windows::UI::Xaml::DurationType)val;
}
@end
@implementation WXThickness {
    ABI::Windows::UI::Xaml::Thickness structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Thickness)s {
    WXThickness* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::Thickness*)internalStruct {
    return &structVal;
}
- (double)left {
    return structVal.Left;
}
- (void)setLeft:(double)val {
    structVal.Left = val;
}
- (double)top {
    return structVal.Top;
}
- (void)setTop:(double)val {
    structVal.Top = val;
}
- (double)right {
    return structVal.Right;
}
- (void)setRight:(double)val {
    structVal.Right = val;
}
- (double)bottom {
    return structVal.Bottom;
}
- (void)setBottom:(double)val {
    structVal.Bottom = val;
}
@end
@implementation WXGridLength {
    ABI::Windows::UI::Xaml::GridLength structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::GridLength)s {
    WXGridLength* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::GridLength*)internalStruct {
    return &structVal;
}
- (double)value {
    return structVal.Value;
}
- (void)setValue:(double)val {
    structVal.Value = val;
}
- (WXGridUnitType)gridUnitType {
    return (WXGridUnitType)structVal.GridUnitType;
}
- (void)setGridUnitType:(WXGridUnitType)val {
    structVal.GridUnitType = (ABI::Windows::UI::Xaml::GridUnitType)val;
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

id RTProxiedNSMutableArray_WXResourceDictionary_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::ResourceDictionary*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Xaml::IResourceDictionary*,
                                                                  IVector<ABI::Windows::UI::Xaml::ResourceDictionary*>,
                                                                  WXResourceDictionary,
                                                                  ABI::Windows::UI::Xaml::ResourceDictionary*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WXStateTriggerBase_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::StateTriggerBase*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Xaml::IStateTriggerBase*,
                                                                  IVector<ABI::Windows::UI::Xaml::StateTriggerBase*>,
                                                                  WXStateTriggerBase,
                                                                  ABI::Windows::UI::Xaml::StateTriggerBase*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WXVisualState_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::VisualState*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Xaml::IVisualState*,
                                                                  IVector<ABI::Windows::UI::Xaml::VisualState*>,
                                                                  WXVisualState,
                                                                  ABI::Windows::UI::Xaml::VisualState*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WXVisualStateGroup_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::VisualStateGroup*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Xaml::IVisualStateGroup*,
                                                                  IVector<ABI::Windows::UI::Xaml::VisualStateGroup*>,
                                                                  WXVisualStateGroup,
                                                                  ABI::Windows::UI::Xaml::VisualStateGroup*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WXVisualTransition_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::VisualTransition*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Xaml::IVisualTransition*,
                                                                  IVector<ABI::Windows::UI::Xaml::VisualTransition*>,
                                                                  WXVisualTransition,
                                                                  ABI::Windows::UI::Xaml::VisualTransition*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_RTObject_RTObject_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<MutableDictionaryAdapterObj<
        IMap<IInspectable*, IInspectable*>,
        DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<IInspectable*, IInspectable*, RTObject, IInspectable*>>,
        RTMapObj<IInspectable*,
                 IInspectable*,
                 IInspectable*,
                 IInspectable*,
                 RTObject,
                 RTObject,
                 IMap<IInspectable*, IInspectable*>,
                 dummyObjCCreator,
                 dummyObjCCreator,
                 dummyWRLCreator,
                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
