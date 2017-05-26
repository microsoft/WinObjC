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

// WindowsUIInputInkingCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Input.Inking.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIInputInkingCore.h"
#include "WindowsUIInputInkingCore_priv.h"

@implementation WUIICCoreInkIndependentInputSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSourceStatics> WUIICICoreInkIndependentInputSourceStatics_inst() {
    ComPtr<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSourceStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Input.Inking.Core.CoreInkIndependentInputSource").Get(), &inst));
    return inst;
}

+ (WUIICCoreInkIndependentInputSource*)create:(WUIIInkPresenter*)inkPresenter {
    ComPtr<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource> unmarshalledReturn;
    auto _comInst = WUIICICoreInkIndependentInputSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Create(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(inkPresenter).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIICCoreInkIndependentInputSource>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addPointerEnteringEvent:(void (^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerEntering(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreInkIndependentInputSource_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerEnteringEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerEntering(cookie));
}

- (EventRegistrationToken)addPointerHoveringEvent:(void (^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerHovering(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreInkIndependentInputSource_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerHoveringEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerHovering(cookie));
}

- (EventRegistrationToken)addPointerExitingEvent:(void (^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerExiting(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreInkIndependentInputSource_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerExitingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerExiting(cookie));
}

- (EventRegistrationToken)addPointerPressingEvent:(void (^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerPressing(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreInkIndependentInputSource_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerPressingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerPressing(cookie));
}

- (EventRegistrationToken)addPointerMovingEvent:(void (^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerMoving(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreInkIndependentInputSource_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerMovingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerMoving(cookie));
}

- (EventRegistrationToken)addPointerReleasingEvent:(void (^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerReleasing(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreInkIndependentInputSource_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerReleasingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerReleasing(cookie));
}

- (EventRegistrationToken)addPointerLostEvent:(void (^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerLost(
        Make<ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreInkIndependentInputSource_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerLostEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerLost(cookie));
}

- (WUIIInkPresenter*)inkPresenter {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPresenter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_InkPresenter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkPresenter>(unmarshalledReturn.Get());
}

@end

@implementation WUIICCoreWetStrokeUpdateEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSMutableArray* /* WUIIInkPoint* */)newInkPoints __attribute__((ns_returns_not_retained)) {
    ComPtr<IVector<ABI::Windows::UI::Input::Inking::InkPoint*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewInkPoints(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUIIInkPoint_create(unmarshalledReturn.Get());
}

- (unsigned int)pointerId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUIICCoreWetStrokeDisposition)disposition {
    ABI::Windows::UI::Input::Inking::Core::CoreWetStrokeDisposition unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Disposition(&unmarshalledReturn));
    return (WUIICCoreWetStrokeDisposition)unmarshalledReturn;
}

- (void)setDisposition:(WUIICCoreWetStrokeDisposition)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Disposition((ABI::Windows::UI::Input::Inking::Core::CoreWetStrokeDisposition)value));
}

@end

@implementation WUIICCoreWetStrokeUpdateSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSourceStatics> WUIICICoreWetStrokeUpdateSourceStatics_inst() {
    ComPtr<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSourceStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Input.Inking.Core.CoreWetStrokeUpdateSource").Get(), &inst));
    return inst;
}

+ (WUIICCoreWetStrokeUpdateSource*)create:(WUIIInkPresenter*)inkPresenter {
    ComPtr<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource> unmarshalledReturn;
    auto _comInst = WUIICICoreWetStrokeUpdateSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Create(_getRtInterface<ABI::Windows::UI::Input::Inking::IInkPresenter>(inkPresenter).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIICCoreWetStrokeUpdateSource>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addWetStrokeStartingEvent:(void (^)(WUIICCoreWetStrokeUpdateSource*, WUIICCoreWetStrokeUpdateEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_WetStrokeStarting(
        Make<
            ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateSource_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeWetStrokeStartingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_WetStrokeStarting(cookie));
}

- (EventRegistrationToken)addWetStrokeContinuingEvent:(void (^)(WUIICCoreWetStrokeUpdateSource*,
                                                                WUIICCoreWetStrokeUpdateEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_WetStrokeContinuing(
        Make<
            ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateSource_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeWetStrokeContinuingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_WetStrokeContinuing(cookie));
}

- (EventRegistrationToken)addWetStrokeStoppingEvent:(void (^)(WUIICCoreWetStrokeUpdateSource*, WUIICCoreWetStrokeUpdateEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_WetStrokeStopping(
        Make<
            ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateSource_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeWetStrokeStoppingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_WetStrokeStopping(cookie));
}

- (EventRegistrationToken)addWetStrokeCompletedEvent:(void (^)(WUIICCoreWetStrokeUpdateSource*,
                                                               WUIICCoreWetStrokeUpdateEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_WetStrokeCompleted(
        Make<
            ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateSource_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeWetStrokeCompletedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_WetStrokeCompleted(cookie));
}

- (EventRegistrationToken)addWetStrokeCanceledEvent:(void (^)(WUIICCoreWetStrokeUpdateSource*, WUIICCoreWetStrokeUpdateEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_WetStrokeCanceled(
        Make<
            ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateSource_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeWetStrokeCanceledEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_WetStrokeCanceled(cookie));
}

- (WUIIInkPresenter*)inkPresenter {
    ComPtr<ABI::Windows::UI::Input::Inking::IInkPresenter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_InkPresenter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIIInkPresenter>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSMutableArray_WUIIInkPoint_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Input::Inking::InkPoint*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Input::Inking::IInkPoint*,
                                                                  IVector<ABI::Windows::UI::Input::Inking::InkPoint*>,
                                                                  WUIIInkPoint,
                                                                  ABI::Windows::UI::Input::Inking::InkPoint*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
