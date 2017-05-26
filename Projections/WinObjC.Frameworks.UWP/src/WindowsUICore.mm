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

// WindowsUICore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUICore.h"
#include "WindowsUICore_priv.h"

@implementation WUCICoreWindowEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreWindowEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WUCICoreWindow

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreWindow> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)automationHostProvider {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutomationHostProvider(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WFRect*)bounds {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bounds(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)customProperties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

- (WUCCoreDispatcher*)dispatcher {
    ComPtr<ABI::Windows::UI::Core::ICoreDispatcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_Dispatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreDispatcher>(unmarshalledReturn.Get());
}

- (WUCCoreWindowFlowDirection)flowDirection {
    ABI::Windows::UI::Core::CoreWindowFlowDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_FlowDirection(&unmarshalledReturn));
    return (WUCCoreWindowFlowDirection)unmarshalledReturn;
}

- (void)setFlowDirection:(WUCCoreWindowFlowDirection)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->put_FlowDirection((ABI::Windows::UI::Core::CoreWindowFlowDirection)value));
}

- (BOOL)isInputEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInputEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsInputEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsInputEnabled((boolean)value));
}

- (WUCCoreCursor*)pointerCursor {
    ComPtr<ABI::Windows::UI::Core::ICoreCursor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerCursor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreCursor>(unmarshalledReturn.Get());
}

- (void)setPointerCursor:(WUCCoreCursor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->put_PointerCursor(_getRtInterface<ABI::Windows::UI::Core::ICoreCursor>(value).Get()));
}

- (WFPoint*)pointerPosition {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerPosition(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (BOOL)visible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_Visible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)activate {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->Activate());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WUCCoreVirtualKeyStates)getAsyncKeyState:(WSVirtualKey)virtualKey {
    ABI::Windows::UI::Core::CoreVirtualKeyStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->GetAsyncKeyState((ABI::Windows::System::VirtualKey)virtualKey, &unmarshalledReturn));
    return (WUCCoreVirtualKeyStates)unmarshalledReturn;
}

- (WUCCoreVirtualKeyStates)getKeyState:(WSVirtualKey)virtualKey {
    ABI::Windows::UI::Core::CoreVirtualKeyStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->GetKeyState((ABI::Windows::System::VirtualKey)virtualKey, &unmarshalledReturn));
    return (WUCCoreVirtualKeyStates)unmarshalledReturn;
}

- (void)releasePointerCapture {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->ReleasePointerCapture());
}

- (void)setPointerCapture {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->SetPointerCapture());
}

- (EventRegistrationToken)addActivatedEvent:(void (^)(WUCCoreWindow*, WUCWindowActivatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Activated(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_WindowActivatedEventArgs>(handler).Get(),
                                &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeActivatedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Activated(cookie));
}

- (EventRegistrationToken)addAutomationProviderRequestedEvent:(void (^)(WUCCoreWindow*, WUCAutomationProviderRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_AutomationProviderRequested(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_AutomationProviderRequestedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAutomationProviderRequestedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AutomationProviderRequested(cookie));
}

- (EventRegistrationToken)addCharacterReceivedEvent:(void (^)(WUCCoreWindow*, WUCCharacterReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_CharacterReceived(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CharacterReceivedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCharacterReceivedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CharacterReceived(cookie));
}

- (EventRegistrationToken)addClosedEvent:(void (^)(WUCCoreWindow*, WUCCoreWindowEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Closed(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CoreWindowEventArgs>(handler).Get(),
                             &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Closed(cookie));
}

- (EventRegistrationToken)addInputEnabledEvent:(void (^)(WUCCoreWindow*, WUCInputEnabledEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_InputEnabled(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_InputEnabledEventArgs>(handler).Get(),
                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeInputEnabledEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_InputEnabled(cookie));
}

- (EventRegistrationToken)addKeyDownEvent:(void (^)(WUCCoreWindow*, WUCKeyEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_KeyDown(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_KeyEventArgs>(handler).Get(),
                              &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeKeyDownEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_KeyDown(cookie));
}

- (EventRegistrationToken)addKeyUpEvent:(void (^)(WUCCoreWindow*, WUCKeyEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_KeyUp(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_KeyEventArgs>(handler).Get(),
                                           &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeKeyUpEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_KeyUp(cookie));
}

- (EventRegistrationToken)addPointerCaptureLostEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerCaptureLost(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerCaptureLostEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerCaptureLost(cookie));
}

- (EventRegistrationToken)addPointerEnteredEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerEntered(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                     &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerEnteredEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerEntered(cookie));
}

- (EventRegistrationToken)addPointerExitedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerExited(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerExitedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerExited(cookie));
}

- (EventRegistrationToken)addPointerMovedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerMoved(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerMovedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerMoved(cookie));
}

- (EventRegistrationToken)addPointerPressedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerPressed(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                     &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerPressed(cookie));
}

- (EventRegistrationToken)addPointerReleasedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerReleased(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                      &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerReleasedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerReleased(cookie));
}

- (EventRegistrationToken)addTouchHitTestingEvent:(void (^)(WUCCoreWindow*, WUCTouchHitTestingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_TouchHitTesting(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_TouchHitTestingEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTouchHitTestingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TouchHitTesting(cookie));
}

- (EventRegistrationToken)addPointerWheelChangedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerWheelChanged(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerWheelChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerWheelChanged(cookie));
}

- (EventRegistrationToken)addSizeChangedEvent:(void (^)(WUCCoreWindow*, WUCWindowSizeChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_SizeChanged(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_WindowSizeChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSizeChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SizeChanged(cookie));
}

- (EventRegistrationToken)addVisibilityChangedEvent:(void (^)(WUCCoreWindow*, WUCVisibilityChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_VisibilityChanged(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_VisibilityChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVisibilityChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VisibilityChanged(cookie));
}

@end

@implementation WUCICoreAcceleratorKeys

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreAcceleratorKeys> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addAcceleratorKeyActivatedEvent:(void (^)(WUCCoreDispatcher*, WUCAcceleratorKeyEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreAcceleratorKeys>(self);
    THROW_NS_IF_FAILED(_comInst->add_AcceleratorKeyActivated(
        Make<ITypedEventHandler_Windows_UI_Core_CoreDispatcher_Windows_UI_Core_AcceleratorKeyEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAcceleratorKeyActivatedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreAcceleratorKeys>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AcceleratorKeyActivated(cookie));
}

@end

@implementation WUCIInitializeWithCoreWindow

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::IInitializeWithCoreWindow> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)Initialize:(WUCCoreWindow*)window {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IInitializeWithCoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->Initialize(_getRtInterface<ABI::Windows::UI::Core::ICoreWindow>(window).Get()));
}

@end

@implementation WUCICoreInputSourceBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreInputSourceBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCoreDispatcher*)dispatcher {
    ComPtr<ABI::Windows::UI::Core::ICoreDispatcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Dispatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreDispatcher>(unmarshalledReturn.Get());
}

- (BOOL)isInputEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInputEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsInputEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsInputEnabled((boolean)value));
}

- (EventRegistrationToken)addInputEnabledEvent:(void (^)(RTObject*, WUCInputEnabledEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_InputEnabled(Make<ITypedEventHandler_System_Object_Windows_UI_Core_InputEnabledEventArgs>(handler).Get(),
                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeInputEnabledEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_InputEnabled(cookie));
}

@end

@implementation WUCICorePointerInputSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICorePointerInputSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)releasePointerCapture {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->ReleasePointerCapture());
}

- (void)setPointerCapture {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->SetPointerCapture());
}

- (BOOL)hasCapture {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasCapture(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFPoint*)pointerPosition {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerPosition(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WUCCoreCursor*)pointerCursor {
    ComPtr<ABI::Windows::UI::Core::ICoreCursor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerCursor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreCursor>(unmarshalledReturn.Get());
}

- (void)setPointerCursor:(WUCCoreCursor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_PointerCursor(_getRtInterface<ABI::Windows::UI::Core::ICoreCursor>(value).Get()));
}

- (EventRegistrationToken)addPointerCaptureLostEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerCaptureLost(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                         &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerCaptureLostEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerCaptureLost(cookie));
}

- (EventRegistrationToken)addPointerEnteredEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerEntered(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerEnteredEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerEntered(cookie));
}

- (EventRegistrationToken)addPointerExitedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerExited(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerExitedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerExited(cookie));
}

- (EventRegistrationToken)addPointerMovedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerMoved(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                  &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerMovedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerMoved(cookie));
}

- (EventRegistrationToken)addPointerPressedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerPressed(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerPressed(cookie));
}

- (EventRegistrationToken)addPointerReleasedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerReleased(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                     &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerReleasedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerReleased(cookie));
}

- (EventRegistrationToken)addPointerWheelChangedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerWheelChanged(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                          &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerWheelChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerWheelChanged(cookie));
}

@end

@implementation WUCICorePointerRedirector

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICorePointerRedirector> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addPointerRoutedAwayEvent:(void (^)(RTObject<WUCICorePointerRedirector>*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerRedirector>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerRoutedAway(
        Make<ITypedEventHandler_Windows_UI_Core_ICorePointerRedirector_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerRoutedAwayEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerRedirector>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerRoutedAway(cookie));
}

- (EventRegistrationToken)addPointerRoutedToEvent:(void (^)(RTObject<WUCICorePointerRedirector>*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerRedirector>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerRoutedTo(
        Make<ITypedEventHandler_Windows_UI_Core_ICorePointerRedirector_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerRoutedToEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerRedirector>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerRoutedTo(cookie));
}

- (EventRegistrationToken)addPointerRoutedReleasedEvent:(void (^)(RTObject<WUCICorePointerRedirector>*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerRedirector>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerRoutedReleased(
        Make<ITypedEventHandler_Windows_UI_Core_ICorePointerRedirector_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerRoutedReleasedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerRedirector>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerRoutedReleased(cookie));
}

@end

@implementation WUCCoreDispatcher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreDispatcher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)hasThreadAccess {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreDispatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasThreadAccess(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)processEvents:(WUCCoreProcessEventsOption)options {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreDispatcher>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessEvents((ABI::Windows::UI::Core::CoreProcessEventsOption)options));
}

- (RTObject<WFIAsyncAction>*)runAsync:(WUCCoreDispatcherPriority)priority agileCallback:(WUCDispatchedHandler)agileCallback {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreDispatcher>(self);
    THROW_NS_IF_FAILED(_comInst->RunAsync((ABI::Windows::UI::Core::CoreDispatcherPriority)priority,
                                          Make<WUCDispatchedHandler_shim>(agileCallback).Get(),
                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)runIdleAsync:(WUCIdleDispatchedHandler)agileCallback {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreDispatcher>(self);
    THROW_NS_IF_FAILED(_comInst->RunIdleAsync(Make<WUCIdleDispatchedHandler_shim>(agileCallback).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addAcceleratorKeyActivatedEvent:(void (^)(WUCCoreDispatcher*, WUCAcceleratorKeyEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreAcceleratorKeys>(self);
    THROW_NS_IF_FAILED(_comInst->add_AcceleratorKeyActivated(
        Make<ITypedEventHandler_Windows_UI_Core_CoreDispatcher_Windows_UI_Core_AcceleratorKeyEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAcceleratorKeyActivatedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreAcceleratorKeys>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AcceleratorKeyActivated(cookie));
}

- (WUCCoreDispatcherPriority)currentPriority {
    ABI::Windows::UI::Core::CoreDispatcherPriority unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreDispatcherWithTaskPriority>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentPriority(&unmarshalledReturn));
    return (WUCCoreDispatcherPriority)unmarshalledReturn;
}

- (void)setCurrentPriority:(WUCCoreDispatcherPriority)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreDispatcherWithTaskPriority>(self);
    THROW_NS_IF_FAILED(_comInst->put_CurrentPriority((ABI::Windows::UI::Core::CoreDispatcherPriority)value));
}

- (BOOL)shouldYield {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreDispatcherWithTaskPriority>(self);
    THROW_NS_IF_FAILED(_comInst->ShouldYield(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)shouldYieldToPriority:(WUCCoreDispatcherPriority)priority {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreDispatcherWithTaskPriority>(self);
    THROW_NS_IF_FAILED(_comInst->ShouldYieldToPriority((ABI::Windows::UI::Core::CoreDispatcherPriority)priority, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)stopProcessEvents {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreDispatcherWithTaskPriority>(self);
    THROW_NS_IF_FAILED(_comInst->StopProcessEvents());
}

- (void)tryRunAsync:(WUCCoreDispatcherPriority)priority
      agileCallback:(WUCDispatchedHandler)agileCallback
            success:(void (^)(BOOL))success
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreDispatcher2>(self);
    THROW_NS_IF_FAILED(_comInst->TryRunAsync((ABI::Windows::UI::Core::CoreDispatcherPriority)priority,
                                             Make<WUCDispatchedHandler_shim>(agileCallback).Get(),
                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (void)tryRunIdleAsync:(WUCIdleDispatchedHandler)agileCallback success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreDispatcher2>(self);
    THROW_NS_IF_FAILED(_comInst->TryRunIdleAsync(Make<WUCIdleDispatchedHandler_shim>(agileCallback).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

@end

@implementation WUCCoreCursor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreCursor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Core::ICoreCursorFactory> WUCICoreCursorFactory_inst() {
    ComPtr<ABI::Windows::UI::Core::ICoreCursorFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Core.CoreCursor").Get(), &inst));
    return inst;
}

+ (WUCCoreCursor*)makeCursor:(WUCCoreCursorType)type id:(unsigned int)id {
    ComPtr<ABI::Windows::UI::Core::ICoreCursor> unmarshalledReturn;
    auto _comInst = WUCICoreCursorFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCursor((ABI::Windows::UI::Core::CoreCursorType)type, id, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUCCoreCursor>(unmarshalledReturn.Get()) retain];
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreCursor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUCCoreCursorType)type {
    ABI::Windows::UI::Core::CoreCursorType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreCursor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WUCCoreCursorType)unmarshalledReturn;
}

@end

@implementation WUCCoreWindow

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreWindow> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Core::ICoreWindowStatic> WUCICoreWindowStatic_inst() {
    ComPtr<ABI::Windows::UI::Core::ICoreWindowStatic> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Core.CoreWindow").Get(), &inst));
    return inst;
}

+ (WUCCoreWindow*)getForCurrentThread {
    ComPtr<ABI::Windows::UI::Core::ICoreWindow> unmarshalledReturn;
    auto _comInst = WUCICoreWindowStatic_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentThread(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreWindow>(unmarshalledReturn.Get());
}

- (RTObject*)automationHostProvider {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutomationHostProvider(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WFRect*)bounds {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bounds(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)customProperties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

- (WUCCoreDispatcher*)dispatcher {
    ComPtr<ABI::Windows::UI::Core::ICoreDispatcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_Dispatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreDispatcher>(unmarshalledReturn.Get());
}

- (WUCCoreWindowFlowDirection)flowDirection {
    ABI::Windows::UI::Core::CoreWindowFlowDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_FlowDirection(&unmarshalledReturn));
    return (WUCCoreWindowFlowDirection)unmarshalledReturn;
}

- (void)setFlowDirection:(WUCCoreWindowFlowDirection)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->put_FlowDirection((ABI::Windows::UI::Core::CoreWindowFlowDirection)value));
}

- (BOOL)isInputEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInputEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsInputEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsInputEnabled((boolean)value));
}

- (WUCCoreCursor*)pointerCursor {
    ComPtr<ABI::Windows::UI::Core::ICoreCursor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerCursor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreCursor>(unmarshalledReturn.Get());
}

- (void)setPointerCursor:(WUCCoreCursor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->put_PointerCursor(_getRtInterface<ABI::Windows::UI::Core::ICoreCursor>(value).Get()));
}

- (WFPoint*)pointerPosition {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerPosition(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (BOOL)visible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->get_Visible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)activate {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->Activate());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WUCCoreVirtualKeyStates)getAsyncKeyState:(WSVirtualKey)virtualKey {
    ABI::Windows::UI::Core::CoreVirtualKeyStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->GetAsyncKeyState((ABI::Windows::System::VirtualKey)virtualKey, &unmarshalledReturn));
    return (WUCCoreVirtualKeyStates)unmarshalledReturn;
}

- (WUCCoreVirtualKeyStates)getKeyState:(WSVirtualKey)virtualKey {
    ABI::Windows::UI::Core::CoreVirtualKeyStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->GetKeyState((ABI::Windows::System::VirtualKey)virtualKey, &unmarshalledReturn));
    return (WUCCoreVirtualKeyStates)unmarshalledReturn;
}

- (void)releasePointerCapture {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->ReleasePointerCapture());
}

- (void)setPointerCapture {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->SetPointerCapture());
}

- (EventRegistrationToken)addActivatedEvent:(void (^)(WUCCoreWindow*, WUCWindowActivatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Activated(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_WindowActivatedEventArgs>(handler).Get(),
                                &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeActivatedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Activated(cookie));
}

- (EventRegistrationToken)addAutomationProviderRequestedEvent:(void (^)(WUCCoreWindow*, WUCAutomationProviderRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_AutomationProviderRequested(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_AutomationProviderRequestedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAutomationProviderRequestedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AutomationProviderRequested(cookie));
}

- (EventRegistrationToken)addCharacterReceivedEvent:(void (^)(WUCCoreWindow*, WUCCharacterReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_CharacterReceived(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CharacterReceivedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCharacterReceivedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CharacterReceived(cookie));
}

- (EventRegistrationToken)addClosedEvent:(void (^)(WUCCoreWindow*, WUCCoreWindowEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Closed(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CoreWindowEventArgs>(handler).Get(),
                             &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Closed(cookie));
}

- (EventRegistrationToken)addInputEnabledEvent:(void (^)(WUCCoreWindow*, WUCInputEnabledEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_InputEnabled(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_InputEnabledEventArgs>(handler).Get(),
                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeInputEnabledEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_InputEnabled(cookie));
}

- (EventRegistrationToken)addKeyDownEvent:(void (^)(WUCCoreWindow*, WUCKeyEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_KeyDown(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_KeyEventArgs>(handler).Get(),
                              &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeKeyDownEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_KeyDown(cookie));
}

- (EventRegistrationToken)addKeyUpEvent:(void (^)(WUCCoreWindow*, WUCKeyEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_KeyUp(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_KeyEventArgs>(handler).Get(),
                                           &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeKeyUpEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_KeyUp(cookie));
}

- (EventRegistrationToken)addPointerCaptureLostEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerCaptureLost(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerCaptureLostEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerCaptureLost(cookie));
}

- (EventRegistrationToken)addPointerEnteredEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerEntered(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                     &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerEnteredEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerEntered(cookie));
}

- (EventRegistrationToken)addPointerExitedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerExited(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerExitedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerExited(cookie));
}

- (EventRegistrationToken)addPointerMovedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerMoved(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerMovedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerMoved(cookie));
}

- (EventRegistrationToken)addPointerPressedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerPressed(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                     &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerPressed(cookie));
}

- (EventRegistrationToken)addPointerReleasedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerReleased(Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                      &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerReleasedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerReleased(cookie));
}

- (EventRegistrationToken)addTouchHitTestingEvent:(void (^)(WUCCoreWindow*, WUCTouchHitTestingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_TouchHitTesting(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_TouchHitTestingEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTouchHitTestingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TouchHitTesting(cookie));
}

- (EventRegistrationToken)addPointerWheelChangedEvent:(void (^)(WUCCoreWindow*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerWheelChanged(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerWheelChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerWheelChanged(cookie));
}

- (EventRegistrationToken)addSizeChangedEvent:(void (^)(WUCCoreWindow*, WUCWindowSizeChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_SizeChanged(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_WindowSizeChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSizeChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SizeChanged(cookie));
}

- (EventRegistrationToken)addVisibilityChangedEvent:(void (^)(WUCCoreWindow*, WUCVisibilityChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->add_VisibilityChanged(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_VisibilityChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVisibilityChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VisibilityChanged(cookie));
}

- (void)setPointerPosition:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow2>(self);
    THROW_NS_IF_FAILED(_comInst->put_PointerPosition(*[value internalStruct]));
}

- (EventRegistrationToken)addPointerRoutedAwayEvent:(void (^)(RTObject<WUCICorePointerRedirector>*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerRedirector>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerRoutedAway(
        Make<ITypedEventHandler_Windows_UI_Core_ICorePointerRedirector_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerRoutedAwayEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerRedirector>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerRoutedAway(cookie));
}

- (EventRegistrationToken)addPointerRoutedToEvent:(void (^)(RTObject<WUCICorePointerRedirector>*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerRedirector>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerRoutedTo(
        Make<ITypedEventHandler_Windows_UI_Core_ICorePointerRedirector_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerRoutedToEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerRedirector>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerRoutedTo(cookie));
}

- (EventRegistrationToken)addPointerRoutedReleasedEvent:(void (^)(RTObject<WUCICorePointerRedirector>*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerRedirector>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerRoutedReleased(
        Make<ITypedEventHandler_Windows_UI_Core_ICorePointerRedirector_Windows_UI_Core_PointerEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerRoutedReleasedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerRedirector>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerRoutedReleased(cookie));
}

- (EventRegistrationToken)addClosestInteractiveBoundsRequestedEvent:(void (^)(WUCCoreWindow*,
                                                                              WUCClosestInteractiveBoundsRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow3>(self);
    THROW_NS_IF_FAILED(_comInst->add_ClosestInteractiveBoundsRequested(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_ClosestInteractiveBoundsRequestedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosestInteractiveBoundsRequestedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow3>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ClosestInteractiveBoundsRequested(cookie));
}

- (NSString*)getCurrentKeyEventDeviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindow3>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentKeyEventDeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUCWindowActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::IWindowActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCoreWindowActivationState)windowActivationState {
    ABI::Windows::UI::Core::CoreWindowActivationState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IWindowActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_WindowActivationState(&unmarshalledReturn));
    return (WUCCoreWindowActivationState)unmarshalledReturn;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WUCAutomationProviderRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::IAutomationProviderRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)automationProvider {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IAutomationProviderRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutomationProvider(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setAutomationProvider:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IAutomationProviderRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutomationProvider([value comObj].Get()));
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WUCCharacterReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICharacterReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)keyCode {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICharacterReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUCCorePhysicalKeyStatus*)keyStatus {
    ABI::Windows::UI::Core::CorePhysicalKeyStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICharacterReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyStatus(&unmarshalledReturn));
    return WUCCorePhysicalKeyStatus_create(unmarshalledReturn);
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WUCCoreWindowEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreWindowEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WUCInputEnabledEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::IInputEnabledEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)inputEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IInputEnabledEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WUCKeyEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::IKeyEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSVirtualKey)virtualKey {
    ABI::Windows::System::VirtualKey unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IKeyEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_VirtualKey(&unmarshalledReturn));
    return (WSVirtualKey)unmarshalledReturn;
}

- (WUCCorePhysicalKeyStatus*)keyStatus {
    ABI::Windows::UI::Core::CorePhysicalKeyStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IKeyEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyStatus(&unmarshalledReturn));
    return WUCCorePhysicalKeyStatus_create(unmarshalledReturn);
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IKeyEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUCPointerEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::IPointerEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUIPointerPoint*)currentPoint {
    ComPtr<ABI::Windows::UI::Input::IPointerPoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IPointerEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentPoint(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIPointerPoint>(unmarshalledReturn.Get());
}

- (WSVirtualKeyModifiers)keyModifiers {
    ABI::Windows::System::VirtualKeyModifiers unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IPointerEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyModifiers(&unmarshalledReturn));
    return (WSVirtualKeyModifiers)unmarshalledReturn;
}

- (NSMutableArray* /* WUIPointerPoint* */)getIntermediatePoints {
    ComPtr<IVector<ABI::Windows::UI::Input::PointerPoint*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IPointerEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetIntermediatePoints(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUIPointerPoint_create(unmarshalledReturn.Get());
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WUCTouchHitTestingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ITouchHitTestingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCoreProximityEvaluation*)proximityEvaluation {
    ABI::Windows::UI::Core::CoreProximityEvaluation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ITouchHitTestingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProximityEvaluation(&unmarshalledReturn));
    return WUCCoreProximityEvaluation_create(unmarshalledReturn);
}

- (void)setProximityEvaluation:(WUCCoreProximityEvaluation*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ITouchHitTestingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProximityEvaluation(*[value internalStruct]));
}

- (WFPoint*)point {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ITouchHitTestingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Point(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WFRect*)boundingBox {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ITouchHitTestingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_BoundingBox(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WUCCoreProximityEvaluation*)evaluateProximityToRect:(WFRect*)controlBoundingBox {
    ABI::Windows::UI::Core::CoreProximityEvaluation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ITouchHitTestingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->EvaluateProximityToRect(*[controlBoundingBox internalStruct], &unmarshalledReturn));
    return WUCCoreProximityEvaluation_create(unmarshalledReturn);
}

- (WUCCoreProximityEvaluation*)evaluateProximityToPolygon:(NSArray* /* WFPoint* */)controlVertices {
    ABI::Windows::UI::Core::CoreProximityEvaluation unmarshalledReturn;
    UINT32 __controlVertices_ArrayLen = 0;
    bool __controlVertices_IsTemp = false;
    ABI::Windows::Foundation::Point* __controlVertices_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Point>(controlVertices,
                                                          &__controlVertices_ArrayLen,
                                                          &__controlVertices_Array,
                                                          &__controlVertices_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ITouchHitTestingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->EvaluateProximityToPolygon(__controlVertices_ArrayLen, __controlVertices_Array, &unmarshalledReturn));
    if (__controlVertices_IsTemp)
        CoTaskMemFree(__controlVertices_Array);
    return WUCCoreProximityEvaluation_create(unmarshalledReturn);
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WUCWindowSizeChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::IWindowSizeChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFSize*)size {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IWindowSizeChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WUCVisibilityChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::IVisibilityChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)visible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IVisibilityChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Visible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WUCClosestInteractiveBoundsRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::IClosestInteractiveBoundsRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFPoint*)pointerPosition {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IClosestInteractiveBoundsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerPosition(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WFRect*)searchBounds {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IClosestInteractiveBoundsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SearchBounds(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)closestInteractiveBounds {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IClosestInteractiveBoundsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClosestInteractiveBounds(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)setClosestInteractiveBounds:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IClosestInteractiveBoundsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_ClosestInteractiveBounds(*[value internalStruct]));
}

@end

@implementation WUCIdleDispatchedHandlerArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::IIdleDispatchedHandlerArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isDispatcherIdle {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IIdleDispatchedHandlerArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDispatcherIdle(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUCAcceleratorKeyEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::IAcceleratorKeyEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCoreAcceleratorKeyEventType)eventType {
    ABI::Windows::UI::Core::CoreAcceleratorKeyEventType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IAcceleratorKeyEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_EventType(&unmarshalledReturn));
    return (WUCCoreAcceleratorKeyEventType)unmarshalledReturn;
}

- (WSVirtualKey)virtualKey {
    ABI::Windows::System::VirtualKey unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IAcceleratorKeyEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_VirtualKey(&unmarshalledReturn));
    return (WSVirtualKey)unmarshalledReturn;
}

- (WUCCorePhysicalKeyStatus*)keyStatus {
    ABI::Windows::UI::Core::CorePhysicalKeyStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IAcceleratorKeyEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyStatus(&unmarshalledReturn));
    return WUCCorePhysicalKeyStatus_create(unmarshalledReturn);
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IAcceleratorKeyEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUCCoreAcceleratorKeys

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreAcceleratorKeys> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addAcceleratorKeyActivatedEvent:(void (^)(WUCCoreDispatcher*, WUCAcceleratorKeyEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreAcceleratorKeys>(self);
    THROW_NS_IF_FAILED(_comInst->add_AcceleratorKeyActivated(
        Make<ITypedEventHandler_Windows_UI_Core_CoreDispatcher_Windows_UI_Core_AcceleratorKeyEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAcceleratorKeyActivatedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreAcceleratorKeys>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AcceleratorKeyActivated(cookie));
}

@end

@implementation WUCCoreWindowResizeManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreWindowResizeManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Core::ICoreWindowResizeManagerStatics> WUCICoreWindowResizeManagerStatics_inst() {
    ComPtr<ABI::Windows::UI::Core::ICoreWindowResizeManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Core.CoreWindowResizeManager").Get(), &inst));
    return inst;
}

+ (WUCCoreWindowResizeManager*)getForCurrentView {
    ComPtr<ABI::Windows::UI::Core::ICoreWindowResizeManager> unmarshalledReturn;
    auto _comInst = WUCICoreWindowResizeManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreWindowResizeManager>(unmarshalledReturn.Get());
}

- (void)notifyLayoutCompleted {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowResizeManager>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyLayoutCompleted());
}

- (void)setShouldWaitForLayoutCompletion:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowResizeManagerLayoutCapability>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShouldWaitForLayoutCompletion((boolean)value));
}

- (BOOL)shouldWaitForLayoutCompletion {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowResizeManagerLayoutCapability>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShouldWaitForLayoutCompletion(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUCCoreComponentInputSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreInputSourceBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCoreDispatcher*)dispatcher {
    ComPtr<ABI::Windows::UI::Core::ICoreDispatcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Dispatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreDispatcher>(unmarshalledReturn.Get());
}

- (BOOL)isInputEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInputEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsInputEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsInputEnabled((boolean)value));
}

- (EventRegistrationToken)addInputEnabledEvent:(void (^)(RTObject*, WUCInputEnabledEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_InputEnabled(Make<ITypedEventHandler_System_Object_Windows_UI_Core_InputEnabledEventArgs>(handler).Get(),
                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeInputEnabledEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_InputEnabled(cookie));
}

- (void)releasePointerCapture {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->ReleasePointerCapture());
}

- (void)setPointerCapture {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->SetPointerCapture());
}

- (BOOL)hasCapture {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasCapture(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFPoint*)pointerPosition {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerPosition(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WUCCoreCursor*)pointerCursor {
    ComPtr<ABI::Windows::UI::Core::ICoreCursor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerCursor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreCursor>(unmarshalledReturn.Get());
}

- (void)setPointerCursor:(WUCCoreCursor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_PointerCursor(_getRtInterface<ABI::Windows::UI::Core::ICoreCursor>(value).Get()));
}

- (EventRegistrationToken)addPointerCaptureLostEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerCaptureLost(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                         &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerCaptureLostEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerCaptureLost(cookie));
}

- (EventRegistrationToken)addPointerEnteredEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerEntered(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerEnteredEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerEntered(cookie));
}

- (EventRegistrationToken)addPointerExitedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerExited(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerExitedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerExited(cookie));
}

- (EventRegistrationToken)addPointerMovedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerMoved(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                  &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerMovedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerMoved(cookie));
}

- (EventRegistrationToken)addPointerPressedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerPressed(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerPressed(cookie));
}

- (EventRegistrationToken)addPointerReleasedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerReleased(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                     &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerReleasedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerReleased(cookie));
}

- (EventRegistrationToken)addPointerWheelChangedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerWheelChanged(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                          &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerWheelChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerWheelChanged(cookie));
}

- (WUCCoreVirtualKeyStates)getCurrentKeyState:(WSVirtualKey)virtualKey {
    ABI::Windows::UI::Core::CoreVirtualKeyStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreKeyboardInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentKeyState((ABI::Windows::System::VirtualKey)virtualKey, &unmarshalledReturn));
    return (WUCCoreVirtualKeyStates)unmarshalledReturn;
}

- (EventRegistrationToken)addCharacterReceivedEvent:(void (^)(RTObject*, WUCCharacterReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreKeyboardInputSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_CharacterReceived(Make<ITypedEventHandler_System_Object_Windows_UI_Core_CharacterReceivedEventArgs>(handler).Get(),
                                        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCharacterReceivedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreKeyboardInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CharacterReceived(cookie));
}

- (EventRegistrationToken)addKeyDownEvent:(void (^)(RTObject*, WUCKeyEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreKeyboardInputSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_KeyDown(Make<ITypedEventHandler_System_Object_Windows_UI_Core_KeyEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeKeyDownEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreKeyboardInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_KeyDown(cookie));
}

- (EventRegistrationToken)addKeyUpEvent:(void (^)(RTObject*, WUCKeyEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreKeyboardInputSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_KeyUp(Make<ITypedEventHandler_System_Object_Windows_UI_Core_KeyEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeKeyUpEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreKeyboardInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_KeyUp(cookie));
}

- (BOOL)hasFocus {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreComponentFocusable>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasFocus(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addGotFocusEvent:(void (^)(RTObject*, WUCCoreWindowEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreComponentFocusable>(self);
    THROW_NS_IF_FAILED(_comInst->add_GotFocus(Make<ITypedEventHandler_System_Object_Windows_UI_Core_CoreWindowEventArgs>(handler).Get(),
                                              &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeGotFocusEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreComponentFocusable>(self);
    THROW_NS_IF_FAILED(_comInst->remove_GotFocus(cookie));
}

- (EventRegistrationToken)addLostFocusEvent:(void (^)(RTObject*, WUCCoreWindowEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreComponentFocusable>(self);
    THROW_NS_IF_FAILED(_comInst->add_LostFocus(Make<ITypedEventHandler_System_Object_Windows_UI_Core_CoreWindowEventArgs>(handler).Get(),
                                               &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLostFocusEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreComponentFocusable>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LostFocus(cookie));
}

- (EventRegistrationToken)addTouchHitTestingEvent:(void (^)(RTObject*, WUCTouchHitTestingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreTouchHitTesting>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_TouchHitTesting(Make<ITypedEventHandler_System_Object_Windows_UI_Core_TouchHitTestingEventArgs>(handler).Get(),
                                      &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTouchHitTestingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreTouchHitTesting>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TouchHitTesting(cookie));
}

- (EventRegistrationToken)addClosestInteractiveBoundsRequestedEvent:(void (^)(WUCCoreComponentInputSource*,
                                                                              WUCClosestInteractiveBoundsRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreClosestInteractiveBoundsRequested>(self);
    THROW_NS_IF_FAILED(_comInst->add_ClosestInteractiveBoundsRequested(
        Make<ITypedEventHandler_Windows_UI_Core_CoreComponentInputSource_Windows_UI_Core_ClosestInteractiveBoundsRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosestInteractiveBoundsRequestedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreClosestInteractiveBoundsRequested>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ClosestInteractiveBoundsRequested(cookie));
}

- (NSString*)getCurrentKeyEventDeviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreKeyboardInputSource2>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentKeyEventDeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUCCoreIndependentInputSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreInputSourceBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCoreDispatcher*)dispatcher {
    ComPtr<ABI::Windows::UI::Core::ICoreDispatcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Dispatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreDispatcher>(unmarshalledReturn.Get());
}

- (BOOL)isInputEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInputEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsInputEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsInputEnabled((boolean)value));
}

- (EventRegistrationToken)addInputEnabledEvent:(void (^)(RTObject*, WUCInputEnabledEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_InputEnabled(Make<ITypedEventHandler_System_Object_Windows_UI_Core_InputEnabledEventArgs>(handler).Get(),
                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeInputEnabledEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreInputSourceBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_InputEnabled(cookie));
}

- (void)releasePointerCapture {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->ReleasePointerCapture());
}

- (void)setPointerCapture {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->SetPointerCapture());
}

- (BOOL)hasCapture {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasCapture(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFPoint*)pointerPosition {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerPosition(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WUCCoreCursor*)pointerCursor {
    ComPtr<ABI::Windows::UI::Core::ICoreCursor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerCursor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreCursor>(unmarshalledReturn.Get());
}

- (void)setPointerCursor:(WUCCoreCursor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_PointerCursor(_getRtInterface<ABI::Windows::UI::Core::ICoreCursor>(value).Get()));
}

- (EventRegistrationToken)addPointerCaptureLostEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerCaptureLost(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                         &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerCaptureLostEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerCaptureLost(cookie));
}

- (EventRegistrationToken)addPointerEnteredEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerEntered(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerEnteredEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerEntered(cookie));
}

- (EventRegistrationToken)addPointerExitedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerExited(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerExitedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerExited(cookie));
}

- (EventRegistrationToken)addPointerMovedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerMoved(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                  &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerMovedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerMoved(cookie));
}

- (EventRegistrationToken)addPointerPressedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerPressed(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerPressed(cookie));
}

- (EventRegistrationToken)addPointerReleasedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_PointerReleased(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                                     &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerReleasedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerReleased(cookie));
}

- (EventRegistrationToken)addPointerWheelChangedEvent:(void (^)(RTObject*, WUCPointerEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PointerWheelChanged(Make<ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs>(handler).Get(),
                                          &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePointerWheelChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICorePointerInputSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PointerWheelChanged(cookie));
}

@end

@implementation WUCBackRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::IBackRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IBackRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::IBackRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WUCSystemNavigationManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ISystemNavigationManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Core::ISystemNavigationManagerStatics> WUCISystemNavigationManagerStatics_inst() {
    ComPtr<ABI::Windows::UI::Core::ISystemNavigationManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Core.SystemNavigationManager").Get(), &inst));
    return inst;
}

+ (WUCSystemNavigationManager*)getForCurrentView {
    ComPtr<ABI::Windows::UI::Core::ISystemNavigationManager> unmarshalledReturn;
    auto _comInst = WUCISystemNavigationManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCSystemNavigationManager>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addBackRequestedEvent:(void (^)(RTObject*, WUCBackRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ISystemNavigationManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_BackRequested(Make<EventHandler_Windows_UI_Core_BackRequestedEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBackRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ISystemNavigationManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BackRequested(token));
}

- (WUCAppViewBackButtonVisibility)appViewBackButtonVisibility {
    ABI::Windows::UI::Core::AppViewBackButtonVisibility unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ISystemNavigationManager2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppViewBackButtonVisibility(&unmarshalledReturn));
    return (WUCAppViewBackButtonVisibility)unmarshalledReturn;
}

- (void)setAppViewBackButtonVisibility:(WUCAppViewBackButtonVisibility)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ISystemNavigationManager2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AppViewBackButtonVisibility((ABI::Windows::UI::Core::AppViewBackButtonVisibility)value));
}

@end

@implementation WUCCoreWindowPopupShowingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreWindowPopupShowingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setDesiredSize:(WFSize*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowPopupShowingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->SetDesiredSize(*[value internalStruct]));
}

@end

@implementation WUCCoreWindowDialog

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreWindowDialog> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Core.CoreWindowDialog").Get(), &out));
    return [_createRtProxy<WUCCoreWindowDialog>(out.Get()) retain];
}

static ComPtr<ABI::Windows::UI::Core::ICoreWindowDialogFactory> WUCICoreWindowDialogFactory_inst() {
    ComPtr<ABI::Windows::UI::Core::ICoreWindowDialogFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Core.CoreWindowDialog").Get(), &inst));
    return inst;
}

+ (WUCCoreWindowDialog*)makeWithTitle:(NSString*)title {
    ComPtr<ABI::Windows::UI::Core::ICoreWindowDialog> unmarshalledReturn;
    auto _comInst = WUCICoreWindowDialogFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithTitle(nsStrToHstr(title).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUCCoreWindowDialog>(unmarshalledReturn.Get()) retain];
}

- (EventRegistrationToken)addShowingEvent:(void (^)(WUCCoreWindow*, WUCCoreWindowPopupShowingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->add_Showing(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CoreWindowPopupShowingEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeShowingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Showing(cookie));
}

- (WFSize*)maxSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFSize*)minSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (int)isInteractionDelayed {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInteractionDelayed(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIsInteractionDelayed:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsInteractionDelayed(value));
}

- (NSMutableArray* /* RTObject<WUPIUICommand>* */)commands {
    ComPtr<IVector<ABI::Windows::UI::Popups::IUICommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->get_Commands(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WUPIUICommand_create(unmarshalledReturn.Get());
}

- (unsigned int)defaultCommandIndex {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultCommandIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDefaultCommandIndex:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->put_DefaultCommandIndex(value));
}

- (unsigned int)cancelCommandIndex {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->get_CancelCommandIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCancelCommandIndex:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->put_CancelCommandIndex(value));
}

- (WUPUICommandInvokedHandler)backButtonCommand {
    ComPtr<ABI::Windows::UI::Popups::IUICommandInvokedHandler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackButtonCommand(unmarshalledReturn.GetAddressOf()));
    return nil;
}

- (void)setBackButtonCommand:(WUPUICommandInvokedHandler)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->put_BackButtonCommand(Make<WUPUICommandInvokedHandler_shim>(value).Get()));
}

- (void)showAsyncWithSuccess:(void (^)(RTObject<WUPIUICommand>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Popups::IUICommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowDialog>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::UI::Popups::IUICommand*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Popups::IUICommand*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::UI::Popups::IUICommand> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WUPIUICommand>(result.Get()));
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

@end

@implementation WUCCoreWindowFlyout

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::ICoreWindowFlyout> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Core::ICoreWindowFlyoutFactory> WUCICoreWindowFlyoutFactory_inst() {
    ComPtr<ABI::Windows::UI::Core::ICoreWindowFlyoutFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Core.CoreWindowFlyout").Get(), &inst));
    return inst;
}

+ (WUCCoreWindowFlyout*)make:(WFPoint*)position {
    ComPtr<ABI::Windows::UI::Core::ICoreWindowFlyout> unmarshalledReturn;
    auto _comInst = WUCICoreWindowFlyoutFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(*[position internalStruct], unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUCCoreWindowFlyout>(unmarshalledReturn.Get()) retain];
}

+ (WUCCoreWindowFlyout*)makeWithTitle:(WFPoint*)position title:(NSString*)title {
    ComPtr<ABI::Windows::UI::Core::ICoreWindowFlyout> unmarshalledReturn;
    auto _comInst = WUCICoreWindowFlyoutFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithTitle(*[position internalStruct], nsStrToHstr(title).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUCCoreWindowFlyout>(unmarshalledReturn.Get()) retain];
}

- (EventRegistrationToken)addShowingEvent:(void (^)(WUCCoreWindow*, WUCCoreWindowPopupShowingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowFlyout>(self);
    THROW_NS_IF_FAILED(_comInst->add_Showing(
        Make<ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CoreWindowPopupShowingEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeShowingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowFlyout>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Showing(cookie));
}

- (WFSize*)maxSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowFlyout>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFSize*)minSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowFlyout>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowFlyout>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowFlyout>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (int)isInteractionDelayed {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowFlyout>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInteractionDelayed(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIsInteractionDelayed:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowFlyout>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsInteractionDelayed(value));
}

- (NSMutableArray* /* RTObject<WUPIUICommand>* */)commands {
    ComPtr<IVector<ABI::Windows::UI::Popups::IUICommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowFlyout>(self);
    THROW_NS_IF_FAILED(_comInst->get_Commands(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WUPIUICommand_create(unmarshalledReturn.Get());
}

- (unsigned int)defaultCommandIndex {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowFlyout>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultCommandIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDefaultCommandIndex:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowFlyout>(self);
    THROW_NS_IF_FAILED(_comInst->put_DefaultCommandIndex(value));
}

- (WUPUICommandInvokedHandler)backButtonCommand {
    ComPtr<ABI::Windows::UI::Popups::IUICommandInvokedHandler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowFlyout>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackButtonCommand(unmarshalledReturn.GetAddressOf()));
    return nil;
}

- (void)setBackButtonCommand:(WUPUICommandInvokedHandler)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowFlyout>(self);
    THROW_NS_IF_FAILED(_comInst->put_BackButtonCommand(Make<WUPUICommandInvokedHandler_shim>(value).Get()));
}

- (void)showAsyncWithSuccess:(void (^)(RTObject<WUPIUICommand>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Popups::IUICommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::ICoreWindowFlyout>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::UI::Popups::IUICommand*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Popups::IUICommand*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::UI::Popups::IUICommand> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WUPIUICommand>(result.Get()));
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

@end

@implementation WUCCorePhysicalKeyStatus {
    ABI::Windows::UI::Core::CorePhysicalKeyStatus structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Core::CorePhysicalKeyStatus)s {
    WUCCorePhysicalKeyStatus* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Core::CorePhysicalKeyStatus*)internalStruct {
    return &structVal;
}
- (unsigned int)repeatCount {
    return structVal.RepeatCount;
}
- (void)setRepeatCount:(unsigned int)val {
    structVal.RepeatCount = val;
}
- (unsigned int)scanCode {
    return structVal.ScanCode;
}
- (void)setScanCode:(unsigned int)val {
    structVal.ScanCode = val;
}
- (BOOL)isExtendedKey {
    return (BOOL)structVal.IsExtendedKey;
}
- (void)setIsExtendedKey:(BOOL)val {
    structVal.IsExtendedKey = (boolean)val;
}
- (BOOL)isMenuKeyDown {
    return (BOOL)structVal.IsMenuKeyDown;
}
- (void)setIsMenuKeyDown:(BOOL)val {
    structVal.IsMenuKeyDown = (boolean)val;
}
- (BOOL)wasKeyDown {
    return (BOOL)structVal.WasKeyDown;
}
- (void)setWasKeyDown:(BOOL)val {
    structVal.WasKeyDown = (boolean)val;
}
- (BOOL)isKeyReleased {
    return (BOOL)structVal.IsKeyReleased;
}
- (void)setIsKeyReleased:(BOOL)val {
    structVal.IsKeyReleased = (boolean)val;
}
@end
@implementation WUCCoreProximityEvaluation {
    ABI::Windows::UI::Core::CoreProximityEvaluation structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Core::CoreProximityEvaluation)s {
    WUCCoreProximityEvaluation* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Core::CoreProximityEvaluation*)internalStruct {
    return &structVal;
}
- (int)score {
    return structVal.Score;
}
- (void)setScore:(int)val {
    structVal.Score = val;
}
- (WFPoint*)adjustedPoint {
    return WFPoint_create(structVal.AdjustedPoint);
}
- (void)setAdjustedPoint:(WFPoint*)val {
    structVal.AdjustedPoint = *[val internalStruct];
}
@end
id RTProxiedNSArray_C_WFPoint_create(UINT32 size, ABI::Windows::Foundation::Point* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<
        CArrayAdapterObj<ABI::Windows::Foundation::Point, RTCArrayObj<ABI::Windows::Foundation::Point, WFPoint, dummyObjCCreator>>>(size,
                                                                                                                                    val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_RTObject_WUPIUICommand_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Popups::IUICommand*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Popups::IUICommand*,
                                                                  IVector<ABI::Windows::UI::Popups::IUICommand*>,
                                                                  RTObject<WUPIUICommand>,
                                                                  ABI::Windows::UI::Popups::IUICommand*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WUIPointerPoint_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Input::PointerPoint*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Input::IPointerPoint*,
                                                                  IVector<ABI::Windows::UI::Input::PointerPoint*>,
                                                                  WUIPointerPoint,
                                                                  ABI::Windows::UI::Input::PointerPoint*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
