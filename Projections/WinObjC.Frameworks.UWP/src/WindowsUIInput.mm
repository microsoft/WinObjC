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

// WindowsUIInput.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Input.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIInput.h"
#include "WindowsUIInput_priv.h"

@implementation WUIIPointerPointTransform

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IPointerPointTransform> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WUIIPointerPointTransform>*)inverse {
    ComPtr<ABI::Windows::UI::Input::IPointerPointTransform> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_Inverse(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIPointerPointTransform>(unmarshalledReturn.Get());
}

- (BOOL)tryTransform:(WFPoint*)inPoint outPoint:(WFPoint**)outPoint {
    ABI::Windows::Foundation::Point outPointOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointTransform>(self);
    THROW_NS_IF_FAILED(_comInst->TryTransform(*[inPoint internalStruct], &outPointOutUnmarshaled, &unmarshalledReturn));
    *outPoint = WFPoint_create(outPointOutUnmarshaled);
    return (BOOL)unmarshalledReturn;
}

- (WFRect*)transformBounds:(WFRect*)rect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointTransform>(self);
    THROW_NS_IF_FAILED(_comInst->TransformBounds(*[rect internalStruct], &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

@end

@implementation WUIEdgeGestureEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IEdgeGestureEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUIEdgeGestureKind)kind {
    ABI::Windows::UI::Input::EdgeGestureKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IEdgeGestureEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WUIEdgeGestureKind)unmarshalledReturn;
}

@end

@implementation WUIEdgeGesture

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IEdgeGesture> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Input::IEdgeGestureStatics> WUIIEdgeGestureStatics_inst() {
    ComPtr<ABI::Windows::UI::Input::IEdgeGestureStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Input.EdgeGesture").Get(), &inst));
    return inst;
}

+ (WUIEdgeGesture*)getForCurrentView {
    ComPtr<ABI::Windows::UI::Input::IEdgeGesture> unmarshalledReturn;
    auto _comInst = WUIIEdgeGestureStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIEdgeGesture>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addStartingEvent:(void (^)(WUIEdgeGesture*, WUIEdgeGestureEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IEdgeGesture>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Starting(Make<ITypedEventHandler_Windows_UI_Input_EdgeGesture_Windows_UI_Input_EdgeGestureEventArgs>(handler).Get(),
                               &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStartingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IEdgeGesture>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Starting(token));
}

- (EventRegistrationToken)addCompletedEvent:(void (^)(WUIEdgeGesture*, WUIEdgeGestureEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IEdgeGesture>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Completed(Make<ITypedEventHandler_Windows_UI_Input_EdgeGesture_Windows_UI_Input_EdgeGestureEventArgs>(handler).Get(),
                                &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IEdgeGesture>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Completed(token));
}

- (EventRegistrationToken)addCanceledEvent:(void (^)(WUIEdgeGesture*, WUIEdgeGestureEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IEdgeGesture>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Canceled(Make<ITypedEventHandler_Windows_UI_Input_EdgeGesture_Windows_UI_Input_EdgeGestureEventArgs>(handler).Get(),
                               &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCanceledEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IEdgeGesture>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Canceled(token));
}

@end

@implementation WUIKeyboardDeliveryInterceptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IKeyboardDeliveryInterceptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Input::IKeyboardDeliveryInterceptorStatics> WUIIKeyboardDeliveryInterceptorStatics_inst() {
    ComPtr<ABI::Windows::UI::Input::IKeyboardDeliveryInterceptorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Input.KeyboardDeliveryInterceptor").Get(),
                                                       &inst));
    return inst;
}

+ (WUIKeyboardDeliveryInterceptor*)getForCurrentView {
    ComPtr<ABI::Windows::UI::Input::IKeyboardDeliveryInterceptor> unmarshalledReturn;
    auto _comInst = WUIIKeyboardDeliveryInterceptorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIKeyboardDeliveryInterceptor>(unmarshalledReturn.Get());
}

- (BOOL)isInterceptionEnabledWhenInForeground {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IKeyboardDeliveryInterceptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInterceptionEnabledWhenInForeground(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsInterceptionEnabledWhenInForeground:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IKeyboardDeliveryInterceptor>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsInterceptionEnabledWhenInForeground((boolean)value));
}

- (EventRegistrationToken)addKeyDownEvent:(void (^)(WUIKeyboardDeliveryInterceptor*, WUCKeyEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IKeyboardDeliveryInterceptor>(self);
    THROW_NS_IF_FAILED(_comInst->add_KeyDown(
        Make<ITypedEventHandler_Windows_UI_Input_KeyboardDeliveryInterceptor_Windows_UI_Core_KeyEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeKeyDownEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IKeyboardDeliveryInterceptor>(self);
    THROW_NS_IF_FAILED(_comInst->remove_KeyDown(token));
}

- (EventRegistrationToken)addKeyUpEvent:(void (^)(WUIKeyboardDeliveryInterceptor*, WUCKeyEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IKeyboardDeliveryInterceptor>(self);
    THROW_NS_IF_FAILED(_comInst->add_KeyUp(
        Make<ITypedEventHandler_Windows_UI_Input_KeyboardDeliveryInterceptor_Windows_UI_Core_KeyEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeKeyUpEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IKeyboardDeliveryInterceptor>(self);
    THROW_NS_IF_FAILED(_comInst->remove_KeyUp(token));
}

@end

@implementation WUIMouseWheelParameters

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IMouseWheelParameters> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFPoint*)charTranslation {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IMouseWheelParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_CharTranslation(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setCharTranslation:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IMouseWheelParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_CharTranslation(*[value internalStruct]));
}

- (float)deltaScale {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IMouseWheelParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeltaScale(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDeltaScale:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IMouseWheelParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_DeltaScale(value));
}

- (float)deltaRotationAngle {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IMouseWheelParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeltaRotationAngle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDeltaRotationAngle:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IMouseWheelParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_DeltaRotationAngle(value));
}

- (WFPoint*)pageTranslation {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IMouseWheelParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_PageTranslation(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setPageTranslation:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IMouseWheelParameters>(self);
    THROW_NS_IF_FAILED(_comInst->put_PageTranslation(*[value internalStruct]));
}

@end

@implementation WUIGestureRecognizer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IGestureRecognizer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Input.GestureRecognizer").Get(), &out));
    return [_createRtProxy<WUIGestureRecognizer>(out.Get()) retain];
}

- (WUIGestureSettings)gestureSettings {
    ABI::Windows::UI::Input::GestureSettings unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_GestureSettings(&unmarshalledReturn));
    return (WUIGestureSettings)unmarshalledReturn;
}

- (void)setGestureSettings:(WUIGestureSettings)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_GestureSettings((ABI::Windows::UI::Input::GestureSettings)value));
}

- (BOOL)isInertial {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInertial(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isActive {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsActive(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)showGestureFeedback {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShowGestureFeedback(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setShowGestureFeedback:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShowGestureFeedback((boolean)value));
}

- (WFPoint*)pivotCenter {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_PivotCenter(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setPivotCenter:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_PivotCenter(*[value internalStruct]));
}

- (float)pivotRadius {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_PivotRadius(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPivotRadius:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_PivotRadius(value));
}

- (float)inertiaTranslationDeceleration {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InertiaTranslationDeceleration(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setInertiaTranslationDeceleration:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InertiaTranslationDeceleration(value));
}

- (float)inertiaRotationDeceleration {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InertiaRotationDeceleration(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setInertiaRotationDeceleration:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InertiaRotationDeceleration(value));
}

- (float)inertiaExpansionDeceleration {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InertiaExpansionDeceleration(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setInertiaExpansionDeceleration:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InertiaExpansionDeceleration(value));
}

- (float)inertiaTranslationDisplacement {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InertiaTranslationDisplacement(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setInertiaTranslationDisplacement:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InertiaTranslationDisplacement(value));
}

- (float)inertiaRotationAngle {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InertiaRotationAngle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setInertiaRotationAngle:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InertiaRotationAngle(value));
}

- (float)inertiaExpansion {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_InertiaExpansion(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setInertiaExpansion:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_InertiaExpansion(value));
}

- (BOOL)manipulationExact {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_ManipulationExact(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setManipulationExact:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_ManipulationExact((boolean)value));
}

- (WUICrossSlideThresholds*)crossSlideThresholds {
    ABI::Windows::UI::Input::CrossSlideThresholds unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_CrossSlideThresholds(&unmarshalledReturn));
    return WUICrossSlideThresholds_create(unmarshalledReturn);
}

- (void)setCrossSlideThresholds:(WUICrossSlideThresholds*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_CrossSlideThresholds(*[value internalStruct]));
}

- (BOOL)crossSlideHorizontally {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_CrossSlideHorizontally(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCrossSlideHorizontally:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_CrossSlideHorizontally((boolean)value));
}

- (BOOL)crossSlideExact {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_CrossSlideExact(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCrossSlideExact:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_CrossSlideExact((boolean)value));
}

- (BOOL)autoProcessInertia {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoProcessInertia(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAutoProcessInertia:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoProcessInertia((boolean)value));
}

- (WUIMouseWheelParameters*)mouseWheelParameters {
    ComPtr<ABI::Windows::UI::Input::IMouseWheelParameters> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_MouseWheelParameters(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIMouseWheelParameters>(unmarshalledReturn.Get());
}

- (BOOL)canBeDoubleTap:(WUIPointerPoint*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->CanBeDoubleTap(_getRtInterface<ABI::Windows::UI::Input::IPointerPoint>(value).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)processDownEvent:(WUIPointerPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessDownEvent(_getRtInterface<ABI::Windows::UI::Input::IPointerPoint>(value).Get()));
}

- (void)processMoveEvents:(NSMutableArray* /* WUIPointerPoint* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessMoveEvents(
        static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Input::PointerPoint*,
                                                              ABI::Windows::UI::Input::IPointerPoint*>>::type>*>(
            ConvertToVector<WUIPointerPoint,
                            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Input::PointerPoint*,
                                                                              ABI::Windows::UI::Input::IPointerPoint*>>(value)
                .Get())));
}

- (void)processUpEvent:(WUIPointerPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessUpEvent(_getRtInterface<ABI::Windows::UI::Input::IPointerPoint>(value).Get()));
}

- (void)processMouseWheelEvent:(WUIPointerPoint*)value isShiftKeyDown:(BOOL)isShiftKeyDown isControlKeyDown:(BOOL)isControlKeyDown {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessMouseWheelEvent(_getRtInterface<ABI::Windows::UI::Input::IPointerPoint>(value).Get(),
                                                        (boolean)isShiftKeyDown,
                                                        (boolean)isControlKeyDown));
}

- (void)processInertia {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessInertia());
}

- (void)completeGesture {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->CompleteGesture());
}

- (EventRegistrationToken)addTappedEvent:(void (^)(WUIGestureRecognizer*, WUITappedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Tapped(Make<ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_TappedEventArgs>(handler).Get(),
                             &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTappedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Tapped(cookie));
}

- (EventRegistrationToken)addRightTappedEvent:(void (^)(WUIGestureRecognizer*, WUIRightTappedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_RightTapped(
        Make<ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_RightTappedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRightTappedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RightTapped(cookie));
}

- (EventRegistrationToken)addHoldingEvent:(void (^)(WUIGestureRecognizer*, WUIHoldingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Holding(Make<ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_HoldingEventArgs>(handler).Get(),
                              &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHoldingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Holding(cookie));
}

- (EventRegistrationToken)addDraggingEvent:(void (^)(WUIGestureRecognizer*, WUIDraggingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_Dragging(
        Make<ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_DraggingEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDraggingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Dragging(cookie));
}

- (EventRegistrationToken)addManipulationStartedEvent:(void (^)(WUIGestureRecognizer*, WUIManipulationStartedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ManipulationStarted(
        Make<ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationStartedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeManipulationStartedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ManipulationStarted(cookie));
}

- (EventRegistrationToken)addManipulationUpdatedEvent:(void (^)(WUIGestureRecognizer*, WUIManipulationUpdatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ManipulationUpdated(
        Make<ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationUpdatedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeManipulationUpdatedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ManipulationUpdated(cookie));
}

- (EventRegistrationToken)addManipulationInertiaStartingEvent:(void (^)(WUIGestureRecognizer*,
                                                                        WUIManipulationInertiaStartingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ManipulationInertiaStarting(
        Make<ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationInertiaStartingEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeManipulationInertiaStartingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ManipulationInertiaStarting(cookie));
}

- (EventRegistrationToken)addManipulationCompletedEvent:(void (^)(WUIGestureRecognizer*, WUIManipulationCompletedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ManipulationCompleted(
        Make<ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationCompletedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeManipulationCompletedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ManipulationCompleted(cookie));
}

- (EventRegistrationToken)addCrossSlidingEvent:(void (^)(WUIGestureRecognizer*, WUICrossSlidingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_CrossSliding(
        Make<ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_CrossSlidingEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCrossSlidingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CrossSliding(cookie));
}

@end

@implementation WUITappedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::ITappedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::ITappedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::ITappedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (unsigned int)tapCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::ITappedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TapCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUIRightTappedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IRightTappedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRightTappedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRightTappedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

@end

@implementation WUIHoldingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IHoldingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IHoldingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IHoldingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WUIHoldingState)holdingState {
    ABI::Windows::UI::Input::HoldingState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IHoldingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_HoldingState(&unmarshalledReturn));
    return (WUIHoldingState)unmarshalledReturn;
}

@end

@implementation WUIDraggingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IDraggingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IDraggingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IDraggingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WUIDraggingState)draggingState {
    ABI::Windows::UI::Input::DraggingState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IDraggingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_DraggingState(&unmarshalledReturn));
    return (WUIDraggingState)unmarshalledReturn;
}

@end

@implementation WUIManipulationStartedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IManipulationStartedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WUIManipulationDelta*)cumulative {
    ABI::Windows::UI::Input::ManipulationDelta unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cumulative(&unmarshalledReturn));
    return WUIManipulationDelta_create(unmarshalledReturn);
}

@end

@implementation WUIManipulationUpdatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IManipulationUpdatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WUIManipulationDelta*)delta {
    ABI::Windows::UI::Input::ManipulationDelta unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delta(&unmarshalledReturn));
    return WUIManipulationDelta_create(unmarshalledReturn);
}

- (WUIManipulationDelta*)cumulative {
    ABI::Windows::UI::Input::ManipulationDelta unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cumulative(&unmarshalledReturn));
    return WUIManipulationDelta_create(unmarshalledReturn);
}

- (WUIManipulationVelocities*)velocities {
    ABI::Windows::UI::Input::ManipulationVelocities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Velocities(&unmarshalledReturn));
    return WUIManipulationVelocities_create(unmarshalledReturn);
}

@end

@implementation WUIManipulationInertiaStartingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IManipulationInertiaStartingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationInertiaStartingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationInertiaStartingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WUIManipulationDelta*)delta {
    ABI::Windows::UI::Input::ManipulationDelta unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationInertiaStartingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delta(&unmarshalledReturn));
    return WUIManipulationDelta_create(unmarshalledReturn);
}

- (WUIManipulationDelta*)cumulative {
    ABI::Windows::UI::Input::ManipulationDelta unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationInertiaStartingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cumulative(&unmarshalledReturn));
    return WUIManipulationDelta_create(unmarshalledReturn);
}

- (WUIManipulationVelocities*)velocities {
    ABI::Windows::UI::Input::ManipulationVelocities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationInertiaStartingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Velocities(&unmarshalledReturn));
    return WUIManipulationVelocities_create(unmarshalledReturn);
}

@end

@implementation WUIManipulationCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IManipulationCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WUIManipulationDelta*)cumulative {
    ABI::Windows::UI::Input::ManipulationDelta unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cumulative(&unmarshalledReturn));
    return WUIManipulationDelta_create(unmarshalledReturn);
}

- (WUIManipulationVelocities*)velocities {
    ABI::Windows::UI::Input::ManipulationVelocities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IManipulationCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Velocities(&unmarshalledReturn));
    return WUIManipulationVelocities_create(unmarshalledReturn);
}

@end

@implementation WUICrossSlidingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::ICrossSlidingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::ICrossSlidingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::ICrossSlidingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WUICrossSlidingState)crossSlidingState {
    ABI::Windows::UI::Input::CrossSlidingState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::ICrossSlidingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CrossSlidingState(&unmarshalledReturn));
    return (WUICrossSlidingState)unmarshalledReturn;
}

@end

@implementation WUIPointerPoint

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IPointerPoint> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Input::IPointerPointStatics> WUIIPointerPointStatics_inst() {
    ComPtr<ABI::Windows::UI::Input::IPointerPointStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Input.PointerPoint").Get(), &inst));
    return inst;
}

+ (WUIPointerPoint*)getCurrentPoint:(unsigned int)pointerId {
    ComPtr<ABI::Windows::UI::Input::IPointerPoint> unmarshalledReturn;
    auto _comInst = WUIIPointerPointStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetCurrentPoint(pointerId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIPointerPoint>(unmarshalledReturn.Get());
}

+ (NSMutableArray* /* WUIPointerPoint* */)getIntermediatePoints:(unsigned int)pointerId {
    ComPtr<IVector<ABI::Windows::UI::Input::PointerPoint*>> unmarshalledReturn;
    auto _comInst = WUIIPointerPointStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetIntermediatePoints(pointerId, unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUIPointerPoint_create(unmarshalledReturn.Get());
}

+ (WUIPointerPoint*)getCurrentPointTransformed:(unsigned int)pointerId transform:(RTObject<WUIIPointerPointTransform>*)transform {
    ComPtr<ABI::Windows::UI::Input::IPointerPoint> unmarshalledReturn;
    auto _comInst = WUIIPointerPointStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetCurrentPointTransformed(pointerId,
                                             _getRtInterface<ABI::Windows::UI::Input::IPointerPointTransform>(transform).Get(),
                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIPointerPoint>(unmarshalledReturn.Get());
}

+ (NSMutableArray* /* WUIPointerPoint* */)getIntermediatePointsTransformed:(unsigned int)pointerId
                                                                 transform:(RTObject<WUIIPointerPointTransform>*)transform {
    ComPtr<IVector<ABI::Windows::UI::Input::PointerPoint*>> unmarshalledReturn;
    auto _comInst = WUIIPointerPointStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetIntermediatePointsTransformed(pointerId,
                                                   _getRtInterface<ABI::Windows::UI::Input::IPointerPointTransform>(transform).Get(),
                                                   unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUIPointerPoint_create(unmarshalledReturn.Get());
}

- (WDIPointerDevice*)pointerDevice {
    ComPtr<ABI::Windows::Devices::Input::IPointerDevice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPoint>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDevice(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDIPointerDevice>(unmarshalledReturn.Get());
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPoint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WFPoint*)rawPosition {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPoint>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawPosition(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (unsigned int)pointerId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPoint>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)frameId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPoint>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)timestamp {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPoint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isInContact {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPoint>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInContact(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUIPointerPointProperties*)properties {
    ComPtr<ABI::Windows::UI::Input::IPointerPointProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPoint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIPointerPointProperties>(unmarshalledReturn.Get());
}

@end

@implementation WUIPointerPointProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IPointerPointProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (float)pressure {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pressure(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isInverted {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInverted(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isEraser {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEraser(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (float)orientation {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)xTilt {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_XTilt(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)yTilt {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_YTilt(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)twist {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Twist(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFRect*)contactRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)contactRectRaw {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactRectRaw(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (BOOL)touchConfidence {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_TouchConfidence(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isLeftButtonPressed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsLeftButtonPressed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isRightButtonPressed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRightButtonPressed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isMiddleButtonPressed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMiddleButtonPressed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)mouseWheelDelta {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_MouseWheelDelta(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isHorizontalMouseWheel {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHorizontalMouseWheel(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPrimary {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPrimary(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isInRange {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInRange(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCanceled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCanceled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isBarrelButtonPressed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBarrelButtonPressed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isXButton1Pressed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsXButton1Pressed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isXButton2Pressed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsXButton2Pressed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUIPointerUpdateKind)pointerUpdateKind {
    ABI::Windows::UI::Input::PointerUpdateKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerUpdateKind(&unmarshalledReturn));
    return (WUIPointerUpdateKind)unmarshalledReturn;
}

- (BOOL)hasUsage:(unsigned int)usagePage usageId:(unsigned int)usageId {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->HasUsage(usagePage, usageId, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)getUsageValue:(unsigned int)usagePage usageId:(unsigned int)usageId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties>(self);
    THROW_NS_IF_FAILED(_comInst->GetUsageValue(usagePage, usageId, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (id /* float */)zDistance {
    ComPtr<IReference<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerPointProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ZDistance(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<float, float>::convert(unmarshalledReturn.Get());
}

@end

@implementation WUIPointerVisualizationSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IPointerVisualizationSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Input::IPointerVisualizationSettingsStatics> WUIIPointerVisualizationSettingsStatics_inst() {
    ComPtr<ABI::Windows::UI::Input::IPointerVisualizationSettingsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Input.PointerVisualizationSettings").Get(),
                                                       &inst));
    return inst;
}

+ (WUIPointerVisualizationSettings*)getForCurrentView {
    ComPtr<ABI::Windows::UI::Input::IPointerVisualizationSettings> unmarshalledReturn;
    auto _comInst = WUIIPointerVisualizationSettingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIPointerVisualizationSettings>(unmarshalledReturn.Get());
}

- (void)setIsContactFeedbackEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerVisualizationSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsContactFeedbackEnabled((boolean)value));
}

- (BOOL)isContactFeedbackEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerVisualizationSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsContactFeedbackEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsBarrelButtonFeedbackEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerVisualizationSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsBarrelButtonFeedbackEnabled((boolean)value));
}

- (BOOL)isBarrelButtonFeedbackEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IPointerVisualizationSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBarrelButtonFeedbackEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUIRadialControllerScreenContact

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerScreenContact> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFRect*)bounds {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerScreenContact>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bounds(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerScreenContact>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

@end

@implementation WUIRadialControllerMenu

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerMenu> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSMutableArray* /* WUIRadialControllerMenuItem* */)items {
    ComPtr<IVector<ABI::Windows::UI::Input::RadialControllerMenuItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerMenu>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUIRadialControllerMenuItem_create(unmarshalledReturn.Get());
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerMenu>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerMenu>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsEnabled((boolean)value));
}

- (WUIRadialControllerMenuItem*)getSelectedMenuItem {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerMenuItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerMenu>(self);
    THROW_NS_IF_FAILED(_comInst->GetSelectedMenuItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIRadialControllerMenuItem>(unmarshalledReturn.Get());
}

- (void)selectMenuItem:(WUIRadialControllerMenuItem*)menuItem {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerMenu>(self);
    THROW_NS_IF_FAILED(_comInst->SelectMenuItem(_getRtInterface<ABI::Windows::UI::Input::IRadialControllerMenuItem>(menuItem).Get()));
}

- (BOOL)trySelectPreviouslySelectedMenuItem {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerMenu>(self);
    THROW_NS_IF_FAILED(_comInst->TrySelectPreviouslySelectedMenuItem(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUIRadialController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IRadialController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Input::IRadialControllerStatics> WUIIRadialControllerStatics_inst() {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Input.RadialController").Get(), &inst));
    return inst;
}

+ (BOOL)isSupported {
    boolean unmarshalledReturn;
    auto _comInst = WUIIRadialControllerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (WUIRadialController*)createForCurrentView {
    ComPtr<ABI::Windows::UI::Input::IRadialController> unmarshalledReturn;
    auto _comInst = WUIIRadialControllerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIRadialController>(unmarshalledReturn.Get());
}

- (WUIRadialControllerMenu*)menu {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerMenu> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Menu(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIRadialControllerMenu>(unmarshalledReturn.Get());
}

- (double)rotationResolutionInDegrees {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationResolutionInDegrees(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotationResolutionInDegrees:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationResolutionInDegrees(value));
}

- (BOOL)useAutomaticHapticFeedback {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->get_UseAutomaticHapticFeedback(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setUseAutomaticHapticFeedback:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->put_UseAutomaticHapticFeedback((boolean)value));
}

- (EventRegistrationToken)addScreenContactStartedEvent:(void (^)(WUIRadialController*,
                                                                 WUIRadialControllerScreenContactStartedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->add_ScreenContactStarted(
        Make<ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerScreenContactStartedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeScreenContactStartedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ScreenContactStarted(cookie));
}

- (EventRegistrationToken)addScreenContactEndedEvent:(void (^)(WUIRadialController*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ScreenContactEnded(Make<ITypedEventHandler_Windows_UI_Input_RadialController_System_Object>(handler).Get(),
                                         &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeScreenContactEndedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ScreenContactEnded(cookie));
}

- (EventRegistrationToken)addScreenContactContinuedEvent:(void (^)(WUIRadialController*,
                                                                   WUIRadialControllerScreenContactContinuedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->add_ScreenContactContinued(
        Make<ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerScreenContactContinuedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeScreenContactContinuedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ScreenContactContinued(cookie));
}

- (EventRegistrationToken)addControlLostEvent:(void (^)(WUIRadialController*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->add_ControlLost(Make<ITypedEventHandler_Windows_UI_Input_RadialController_System_Object>(handler).Get(),
                                                 &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeControlLostEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ControlLost(cookie));
}

- (EventRegistrationToken)addRotationChangedEvent:(void (^)(WUIRadialController*, WUIRadialControllerRotationChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->add_RotationChanged(
        Make<ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerRotationChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRotationChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RotationChanged(token));
}

- (EventRegistrationToken)addButtonClickedEvent:(void (^)(WUIRadialController*, WUIRadialControllerButtonClickedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->add_ButtonClicked(
        Make<ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerButtonClickedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeButtonClickedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ButtonClicked(token));
}

- (EventRegistrationToken)addControlAcquiredEvent:(void (^)(WUIRadialController*, WUIRadialControllerControlAcquiredEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->add_ControlAcquired(
        Make<ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerControlAcquiredEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeControlAcquiredEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ControlAcquired(cookie));
}

@end

@implementation WUIRadialControllerScreenContactStartedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerScreenContactStartedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUIRadialControllerScreenContact*)contact {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerScreenContact> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerScreenContactStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contact(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIRadialControllerScreenContact>(unmarshalledReturn.Get());
}

@end

@implementation WUIRadialControllerScreenContactContinuedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerScreenContactContinuedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUIRadialControllerScreenContact*)contact {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerScreenContact> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerScreenContactContinuedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contact(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIRadialControllerScreenContact>(unmarshalledReturn.Get());
}

@end

@implementation WUIRadialControllerRotationChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerRotationChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)rotationDeltaInDegrees {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerRotationChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationDeltaInDegrees(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUIRadialControllerScreenContact*)contact {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerScreenContact> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerRotationChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contact(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIRadialControllerScreenContact>(unmarshalledReturn.Get());
}

@end

@implementation WUIRadialControllerButtonClickedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerButtonClickedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUIRadialControllerScreenContact*)contact {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerScreenContact> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerButtonClickedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contact(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIRadialControllerScreenContact>(unmarshalledReturn.Get());
}

@end

@implementation WUIRadialControllerControlAcquiredEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerControlAcquiredEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUIRadialControllerScreenContact*)contact {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerScreenContact> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerControlAcquiredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contact(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIRadialControllerScreenContact>(unmarshalledReturn.Get());
}

@end

@implementation WUIRadialControllerMenuItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerMenuItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Input::IRadialControllerMenuItemStatics> WUIIRadialControllerMenuItemStatics_inst() {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerMenuItemStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Input.RadialControllerMenuItem").Get(), &inst));
    return inst;
}

+ (WUIRadialControllerMenuItem*)createFromIcon:(NSString*)displayText icon:(WSSRandomAccessStreamReference*)icon {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerMenuItem> unmarshalledReturn;
    auto _comInst = WUIIRadialControllerMenuItemStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromIcon(nsStrToHstr(displayText).Get(),
                                                _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(icon).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIRadialControllerMenuItem>(unmarshalledReturn.Get());
}

+ (WUIRadialControllerMenuItem*)createFromKnownIcon:(NSString*)displayText value:(WUIRadialControllerMenuKnownIcon)value {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerMenuItem> unmarshalledReturn;
    auto _comInst = WUIIRadialControllerMenuItemStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromKnownIcon(nsStrToHstr(displayText).Get(),
                                                     (ABI::Windows::UI::Input::RadialControllerMenuKnownIcon)value,
                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIRadialControllerMenuItem>(unmarshalledReturn.Get());
}

- (NSString*)displayText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerMenuItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject*)tag {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerMenuItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tag(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setTag:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerMenuItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Tag([value comObj].Get()));
}

- (EventRegistrationToken)addInvokedEvent:(void (^)(WUIRadialControllerMenuItem*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerMenuItem>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Invoked(Make<ITypedEventHandler_Windows_UI_Input_RadialControllerMenuItem_System_Object>(handler).Get(),
                              &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeInvokedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerMenuItem>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Invoked(token));
}

@end

@implementation WUIRadialControllerConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Input::IRadialControllerConfigurationStatics> WUIIRadialControllerConfigurationStatics_inst() {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerConfigurationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Input.RadialControllerConfiguration").Get(),
                                                       &inst));
    return inst;
}

+ (WUIRadialControllerConfiguration*)getForCurrentView {
    ComPtr<ABI::Windows::UI::Input::IRadialControllerConfiguration> unmarshalledReturn;
    auto _comInst = WUIIRadialControllerConfigurationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIRadialControllerConfiguration>(unmarshalledReturn.Get());
}

- (void)setDefaultMenuItems:(id<NSFastEnumeration> /* WUIRadialControllerSystemMenuItemKind */)buttons {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->SetDefaultMenuItems(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
                                                         ABI::Windows::UI::Input::RadialControllerSystemMenuItemKind>::type>*>(
        ConvertToIterable<WUIRadialControllerSystemMenuItemKind, ABI::Windows::UI::Input::RadialControllerSystemMenuItemKind>(buttons)
            .Get())));
}

- (void)resetToDefaultMenuItems {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->ResetToDefaultMenuItems());
}

- (BOOL)trySelectDefaultMenuItem:(WUIRadialControllerSystemMenuItemKind)type {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::IRadialControllerConfiguration>(self);
    THROW_NS_IF_FAILED(
        _comInst->TrySelectDefaultMenuItem((ABI::Windows::UI::Input::RadialControllerSystemMenuItemKind)type, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUIManipulationDelta {
    ABI::Windows::UI::Input::ManipulationDelta structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Input::ManipulationDelta)s {
    WUIManipulationDelta* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Input::ManipulationDelta*)internalStruct {
    return &structVal;
}
- (WFPoint*)translation {
    return WFPoint_create(structVal.Translation);
}
- (void)setTranslation:(WFPoint*)val {
    structVal.Translation = *[val internalStruct];
}
- (float)scale {
    return structVal.Scale;
}
- (void)setScale:(float)val {
    structVal.Scale = val;
}
- (float)rotation {
    return structVal.Rotation;
}
- (void)setRotation:(float)val {
    structVal.Rotation = val;
}
- (float)expansion {
    return structVal.Expansion;
}
- (void)setExpansion:(float)val {
    structVal.Expansion = val;
}
@end
@implementation WUIManipulationVelocities {
    ABI::Windows::UI::Input::ManipulationVelocities structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Input::ManipulationVelocities)s {
    WUIManipulationVelocities* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Input::ManipulationVelocities*)internalStruct {
    return &structVal;
}
- (WFPoint*)linear {
    return WFPoint_create(structVal.Linear);
}
- (void)setLinear:(WFPoint*)val {
    structVal.Linear = *[val internalStruct];
}
- (float)angular {
    return structVal.Angular;
}
- (void)setAngular:(float)val {
    structVal.Angular = val;
}
- (float)expansion {
    return structVal.Expansion;
}
- (void)setExpansion:(float)val {
    structVal.Expansion = val;
}
@end
@implementation WUICrossSlideThresholds {
    ABI::Windows::UI::Input::CrossSlideThresholds structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Input::CrossSlideThresholds)s {
    WUICrossSlideThresholds* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Input::CrossSlideThresholds*)internalStruct {
    return &structVal;
}
- (float)selectionStart {
    return structVal.SelectionStart;
}
- (void)setSelectionStart:(float)val {
    structVal.SelectionStart = val;
}
- (float)speedBumpStart {
    return structVal.SpeedBumpStart;
}
- (void)setSpeedBumpStart:(float)val {
    structVal.SpeedBumpStart = val;
}
- (float)speedBumpEnd {
    return structVal.SpeedBumpEnd;
}
- (void)setSpeedBumpEnd:(float)val {
    structVal.SpeedBumpEnd = val;
}
- (float)rearrangeStart {
    return structVal.RearrangeStart;
}
- (void)setRearrangeStart:(float)val {
    structVal.RearrangeStart = val;
}
@end
id RTProxiedIterableNSArray_WUIRadialControllerSystemMenuItemKind_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::UI::Input::RadialControllerSystemMenuItemKind>,
                                                 RTIterableObj<ABI::Windows::UI::Input::RadialControllerSystemMenuItemKind,
                                                               IIterable<ABI::Windows::UI::Input::RadialControllerSystemMenuItemKind>,
                                                               WUIRadialControllerSystemMenuItemKind,
                                                               ABI::Windows::UI::Input::RadialControllerSystemMenuItemKind,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WUIRadialControllerMenuItem_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Input::RadialControllerMenuItem*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Input::IRadialControllerMenuItem*,
                                                                  IVector<ABI::Windows::UI::Input::RadialControllerMenuItem*>,
                                                                  WUIRadialControllerMenuItem,
                                                                  ABI::Windows::UI::Input::RadialControllerMenuItem*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
