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

// WindowsUIXamlInput.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Input.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlInput.h"
#include "WindowsUIXamlInput_priv.h"

@implementation WUXIICommand

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::ICommand> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addCanExecuteChangedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::ICommand>(self);
    THROW_NS_IF_FAILED(_comInst->add_CanExecuteChanged(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCanExecuteChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::ICommand>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CanExecuteChanged(token));
}

- (BOOL)canExecute:(RTObject*)parameter {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::ICommand>(self);
    THROW_NS_IF_FAILED(_comInst->CanExecute([parameter comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)execute:(RTObject*)parameter {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::ICommand>(self);
    THROW_NS_IF_FAILED(_comInst->Execute([parameter comObj].Get()));
}

@end

@implementation WUXIPointer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IPointer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)pointerId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IPointer>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IPointer>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (BOOL)isInContact {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IPointer>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInContact(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isInRange {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IPointer>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInRange(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUXIAccessKeyDisplayRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IAccessKeyDisplayRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Input.AccessKeyDisplayRequestedEventArgs").Get(),
                                              &out));
    return [_createRtProxy<WUXIAccessKeyDisplayRequestedEventArgs>(out.Get()) retain];
}

- (NSString*)pressedKeys {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IAccessKeyDisplayRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PressedKeys(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUXIAccessKeyDisplayDismissedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IAccessKeyDisplayDismissedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Input.AccessKeyDisplayDismissedEventArgs").Get(),
                                              &out));
    return [_createRtProxy<WUXIAccessKeyDisplayDismissedEventArgs>(out.Get()) retain];
}

@end

@implementation WUXIAccessKeyInvokedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IAccessKeyInvokedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Input.AccessKeyInvokedEventArgs").Get(), &out));
    return [_createRtProxy<WUXIAccessKeyInvokedEventArgs>(out.Get()) retain];
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IAccessKeyInvokedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IAccessKeyInvokedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WUXIAccessKeyManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IAccessKeyManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Input::IAccessKeyManagerStatics> WUXIIAccessKeyManagerStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Input::IAccessKeyManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Input.AccessKeyManager").Get(), &inst));
    return inst;
}

+ (BOOL)isDisplayModeEnabled {
    boolean unmarshalledReturn;
    auto _comInst = WUXIIAccessKeyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsDisplayModeEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (EventRegistrationToken)addIsDisplayModeEnabledChangedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WUXIIAccessKeyManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_IsDisplayModeEnabledChanged(Make<ITypedEventHandler_System_Object_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeIsDisplayModeEnabledChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WUXIIAccessKeyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_IsDisplayModeEnabledChanged(token));
}

+ (void)exitDisplayMode {
    auto _comInst = WUXIIAccessKeyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ExitDisplayMode());
}

@end

@implementation WUXIFocusManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IFocusManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Input::IFocusManagerStatics> WUXIIFocusManagerStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Input::IFocusManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Input.FocusManager").Get(), &inst));
    return inst;
}

+ (RTObject*)getFocusedElement {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = WUXIIFocusManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetFocusedElement(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Input::IFocusManagerStatics2> WUXIIFocusManagerStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Input::IFocusManagerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Input.FocusManager").Get(), &inst));
    return inst;
}

+ (BOOL)tryMoveFocus:(WUXIFocusNavigationDirection)focusNavigationDirection {
    boolean unmarshalledReturn;
    auto _comInst = WUXIIFocusManagerStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryMoveFocus((ABI::Windows::UI::Xaml::Input::FocusNavigationDirection)focusNavigationDirection, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

ComPtr<ABI::Windows::UI::Xaml::Input::IFocusManagerStatics3> WUXIIFocusManagerStatics3_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Input::IFocusManagerStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Input.FocusManager").Get(), &inst));
    return inst;
}

+ (WXUIElement*)findNextFocusableElement:(WUXIFocusNavigationDirection)focusNavigationDirection {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = WUXIIFocusManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->FindNextFocusableElement((ABI::Windows::UI::Xaml::Input::FocusNavigationDirection)focusNavigationDirection,
                                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

+ (WXUIElement*)findNextFocusableElementWithHint:(WUXIFocusNavigationDirection)focusNavigationDirection hintRect:(WFRect*)hintRect {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = WUXIIFocusManagerStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->FindNextFocusableElementWithHint((ABI::Windows::UI::Xaml::Input::FocusNavigationDirection)focusNavigationDirection,
                                                   *[hintRect internalStruct],
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

@end

@implementation WUXIInertiaExpansionBehavior

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IInertiaExpansionBehavior> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)desiredDeceleration {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInertiaExpansionBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredDeceleration(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDesiredDeceleration:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInertiaExpansionBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredDeceleration(value));
}

- (double)desiredExpansion {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInertiaExpansionBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredExpansion(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDesiredExpansion:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInertiaExpansionBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredExpansion(value));
}

@end

@implementation WUXIInertiaRotationBehavior

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IInertiaRotationBehavior> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)desiredDeceleration {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInertiaRotationBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredDeceleration(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDesiredDeceleration:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInertiaRotationBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredDeceleration(value));
}

- (double)desiredRotation {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInertiaRotationBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredRotation(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDesiredRotation:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInertiaRotationBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredRotation(value));
}

@end

@implementation WUXIInertiaTranslationBehavior

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IInertiaTranslationBehavior> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)desiredDeceleration {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInertiaTranslationBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredDeceleration(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDesiredDeceleration:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInertiaTranslationBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredDeceleration(value));
}

- (double)desiredDisplacement {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInertiaTranslationBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredDisplacement(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDesiredDisplacement:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInertiaTranslationBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredDisplacement(value));
}

@end

@implementation WUXIManipulationPivot

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IManipulationPivot> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Input.ManipulationPivot").Get(), &out));
    return [_createRtProxy<WUXIManipulationPivot>(out.Get()) retain];
}

static ComPtr<ABI::Windows::UI::Xaml::Input::IManipulationPivotFactory> WUXIIManipulationPivotFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Input::IManipulationPivotFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Input.ManipulationPivot").Get(), &inst));
    return inst;
}

+ (WUXIManipulationPivot*)makeInstanceWithCenterAndRadius:(WFPoint*)center radius:(double)radius {
    ComPtr<ABI::Windows::UI::Xaml::Input::IManipulationPivot> unmarshalledReturn;
    auto _comInst = WUXIIManipulationPivotFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstanceWithCenterAndRadius(*[center internalStruct], radius, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXIManipulationPivot>(unmarshalledReturn.Get()) retain];
}

- (WFPoint*)center {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationPivot>(self);
    THROW_NS_IF_FAILED(_comInst->get_Center(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)setCenter:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationPivot>(self);
    THROW_NS_IF_FAILED(_comInst->put_Center(*[value internalStruct]));
}

- (double)radius {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationPivot>(self);
    THROW_NS_IF_FAILED(_comInst->get_Radius(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRadius:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationPivot>(self);
    THROW_NS_IF_FAILED(_comInst->put_Radius(value));
}

@end

@implementation WUXIContextRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IContextRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Input.ContextRequestedEventArgs").Get(), &out));
    return [_createRtProxy<WUXIContextRequestedEventArgs>(out.Get()) retain];
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IContextRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IContextRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (BOOL)tryGetPosition:(WXUIElement*)relativeTo point:(WFPoint**)point {
    ABI::Windows::Foundation::Point pointOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IContextRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetPosition(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(relativeTo).Get(),
                                                &pointOutUnmarshaled,
                                                &unmarshalledReturn));
    *point = WFPoint_create(pointOutUnmarshaled);
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUXIDoubleTappedRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Input.DoubleTappedRoutedEventArgs").Get(), &out));
    return [_createRtProxy<WUXIDoubleTappedRoutedEventArgs>(out.Get()) retain];
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WFPoint*)getPosition:(WXUIElement*)relativeTo {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetPosition(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(relativeTo).Get(), &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

@end

@implementation WUXIHoldingRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IHoldingRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Input.HoldingRoutedEventArgs").Get(), &out));
    return [_createRtProxy<WUXIHoldingRoutedEventArgs>(out.Get()) retain];
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IHoldingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (WUIHoldingState)holdingState {
    ABI::Windows::UI::Input::HoldingState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IHoldingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_HoldingState(&unmarshalledReturn));
    return (WUIHoldingState)unmarshalledReturn;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IHoldingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IHoldingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WFPoint*)getPosition:(WXUIElement*)relativeTo {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IHoldingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetPosition(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(relativeTo).Get(), &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

@end

@implementation WUXIInputScope

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IInputScope> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Input.InputScope").Get(), &out));
    return [_createRtProxy<WUXIInputScope>(out.Get()) retain];
}

- (NSMutableArray* /* WUXIInputScopeName* */)names {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Input::InputScopeName*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInputScope>(self);
    THROW_NS_IF_FAILED(_comInst->get_Names(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUXIInputScopeName_create(unmarshalledReturn.Get());
}

@end

@implementation WUXIInputScopeName

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IInputScopeName> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Input.InputScopeName").Get(), &out));
    return [_createRtProxy<WUXIInputScopeName>(out.Get()) retain];
}

static ComPtr<ABI::Windows::UI::Xaml::Input::IInputScopeNameFactory> WUXIIInputScopeNameFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Input::IInputScopeNameFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Input.InputScopeName").Get(), &inst));
    return inst;
}

+ (WUXIInputScopeName*)makeInstance:(WUXIInputScopeNameValue)nameValue {
    ComPtr<ABI::Windows::UI::Xaml::Input::IInputScopeName> unmarshalledReturn;
    auto _comInst = WUXIIInputScopeNameFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstance((ABI::Windows::UI::Xaml::Input::InputScopeNameValue)nameValue, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXIInputScopeName>(unmarshalledReturn.Get()) retain];
}

- (WUXIInputScopeNameValue)nameValue {
    ABI::Windows::UI::Xaml::Input::InputScopeNameValue unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInputScopeName>(self);
    THROW_NS_IF_FAILED(_comInst->get_NameValue(&unmarshalledReturn));
    return (WUXIInputScopeNameValue)unmarshalledReturn;
}

- (void)setNameValue:(WUXIInputScopeNameValue)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IInputScopeName>(self);
    THROW_NS_IF_FAILED(_comInst->put_NameValue((ABI::Windows::UI::Xaml::Input::InputScopeNameValue)value));
}

@end

@implementation WUXIKeyRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSVirtualKey)key {
    ABI::Windows::System::VirtualKey unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Key(&unmarshalledReturn));
    return (WSVirtualKey)unmarshalledReturn;
}

- (WUCCorePhysicalKeyStatus*)keyStatus {
    ABI::Windows::UI::Core::CorePhysicalKeyStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyStatus(&unmarshalledReturn));
    return WUCCorePhysicalKeyStatus_create(unmarshalledReturn);
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WSVirtualKey)originalKey {
    ABI::Windows::System::VirtualKey unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_OriginalKey(&unmarshalledReturn));
    return (WSVirtualKey)unmarshalledReturn;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs3>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUXIManipulationCompletedRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Input.ManipulationCompletedRoutedEventArgs").Get(),
                                              &out));
    return [_createRtProxy<WUXIManipulationCompletedRoutedEventArgs>(out.Get()) retain];
}

- (WXUIElement*)container {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Container(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (BOOL)isInertial {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInertial(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUIManipulationDelta*)cumulative {
    ABI::Windows::UI::Input::ManipulationDelta unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cumulative(&unmarshalledReturn));
    return WUIManipulationDelta_create(unmarshalledReturn);
}

- (WUIManipulationVelocities*)velocities {
    ABI::Windows::UI::Input::ManipulationVelocities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Velocities(&unmarshalledReturn));
    return WUIManipulationVelocities_create(unmarshalledReturn);
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

@end

@implementation WUXIManipulationDeltaRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Input.ManipulationDeltaRoutedEventArgs").Get(),
                                              &out));
    return [_createRtProxy<WUXIManipulationDeltaRoutedEventArgs>(out.Get()) retain];
}

- (WXUIElement*)container {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Container(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (BOOL)isInertial {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInertial(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUIManipulationDelta*)delta {
    ABI::Windows::UI::Input::ManipulationDelta unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delta(&unmarshalledReturn));
    return WUIManipulationDelta_create(unmarshalledReturn);
}

- (WUIManipulationDelta*)cumulative {
    ABI::Windows::UI::Input::ManipulationDelta unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cumulative(&unmarshalledReturn));
    return WUIManipulationDelta_create(unmarshalledReturn);
}

- (WUIManipulationVelocities*)velocities {
    ABI::Windows::UI::Input::ManipulationVelocities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Velocities(&unmarshalledReturn));
    return WUIManipulationVelocities_create(unmarshalledReturn);
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WUXIManipulationInertiaStartingRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Input.ManipulationInertiaStartingRoutedEventArgs").Get(), &out));
    return [_createRtProxy<WUXIManipulationInertiaStartingRoutedEventArgs>(out.Get()) retain];
}

- (WXUIElement*)container {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Container(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

- (WUXIInertiaExpansionBehavior*)expansionBehavior {
    ComPtr<ABI::Windows::UI::Xaml::Input::IInertiaExpansionBehavior> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpansionBehavior(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXIInertiaExpansionBehavior>(unmarshalledReturn.Get());
}

- (void)setExpansionBehavior:(WUXIInertiaExpansionBehavior*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ExpansionBehavior(_getRtInterface<ABI::Windows::UI::Xaml::Input::IInertiaExpansionBehavior>(value).Get()));
}

- (WUXIInertiaRotationBehavior*)rotationBehavior {
    ComPtr<ABI::Windows::UI::Xaml::Input::IInertiaRotationBehavior> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationBehavior(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXIInertiaRotationBehavior>(unmarshalledReturn.Get());
}

- (void)setRotationBehavior:(WUXIInertiaRotationBehavior*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_RotationBehavior(_getRtInterface<ABI::Windows::UI::Xaml::Input::IInertiaRotationBehavior>(value).Get()));
}

- (WUXIInertiaTranslationBehavior*)translationBehavior {
    ComPtr<ABI::Windows::UI::Xaml::Input::IInertiaTranslationBehavior> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TranslationBehavior(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXIInertiaTranslationBehavior>(unmarshalledReturn.Get());
}

- (void)setTranslationBehavior:(WUXIInertiaTranslationBehavior*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_TranslationBehavior(_getRtInterface<ABI::Windows::UI::Xaml::Input::IInertiaTranslationBehavior>(value).Get()));
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (WUIManipulationDelta*)delta {
    ABI::Windows::UI::Input::ManipulationDelta unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delta(&unmarshalledReturn));
    return WUIManipulationDelta_create(unmarshalledReturn);
}

- (WUIManipulationDelta*)cumulative {
    ABI::Windows::UI::Input::ManipulationDelta unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cumulative(&unmarshalledReturn));
    return WUIManipulationDelta_create(unmarshalledReturn);
}

- (WUIManipulationVelocities*)velocities {
    ABI::Windows::UI::Input::ManipulationVelocities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Velocities(&unmarshalledReturn));
    return WUIManipulationVelocities_create(unmarshalledReturn);
}

@end

@implementation WUXIManipulationStartedRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgsFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Input.ManipulationStartedRoutedEventArgs").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXIManipulationStartedRoutedEventArgs* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (WXUIElement*)container {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Container(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (WUIManipulationDelta*)cumulative {
    ABI::Windows::UI::Input::ManipulationDelta unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cumulative(&unmarshalledReturn));
    return WUIManipulationDelta_create(unmarshalledReturn);
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WUXIManipulationStartingRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Input.ManipulationStartingRoutedEventArgs").Get(),
                                              &out));
    return [_createRtProxy<WUXIManipulationStartingRoutedEventArgs>(out.Get()) retain];
}

- (WUXIManipulationModes)mode {
    ABI::Windows::UI::Xaml::Input::ManipulationModes unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WUXIManipulationModes)unmarshalledReturn;
}

- (void)setMode:(WUXIManipulationModes)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::UI::Xaml::Input::ManipulationModes)value));
}

- (WXUIElement*)container {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Container(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

- (void)setContainer:(WXUIElement*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Container(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(value).Get()));
}

- (WUXIManipulationPivot*)pivot {
    ComPtr<ABI::Windows::UI::Xaml::Input::IManipulationPivot> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pivot(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXIManipulationPivot>(unmarshalledReturn.Get());
}

- (void)setPivot:(WUXIManipulationPivot*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Pivot(_getRtInterface<ABI::Windows::UI::Xaml::Input::IManipulationPivot>(value).Get()));
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WUXIPointerRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUXIPointer*)pointer {
    ComPtr<ABI::Windows::UI::Xaml::Input::IPointer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pointer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXIPointer>(unmarshalledReturn.Get());
}

- (WSVirtualKeyModifiers)keyModifiers {
    ABI::Windows::System::VirtualKeyModifiers unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyModifiers(&unmarshalledReturn));
    return (WSVirtualKeyModifiers)unmarshalledReturn;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WUIPointerPoint*)getCurrentPoint:(WXUIElement*)relativeTo {
    ComPtr<ABI::Windows::UI::Input::IPointerPoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentPoint(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(relativeTo).Get(),
                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUIPointerPoint>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WUIPointerPoint* */)getIntermediatePoints:(WXUIElement*)relativeTo {
    ComPtr<IVector<ABI::Windows::UI::Input::PointerPoint*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetIntermediatePoints(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(relativeTo).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUIPointerPoint_create(unmarshalledReturn.Get());
}

@end

@implementation WUXIRightTappedRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Input.RightTappedRoutedEventArgs").Get(), &out));
    return [_createRtProxy<WUXIRightTappedRoutedEventArgs>(out.Get()) retain];
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WFPoint*)getPosition:(WXUIElement*)relativeTo {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetPosition(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(relativeTo).Get(), &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

@end

@implementation WUXITappedRoutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Input::ITappedRoutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Input.TappedRoutedEventArgs").Get(), &out));
    return [_createRtProxy<WUXITappedRoutedEventArgs>(out.Get()) retain];
}

- (WDIPointerDeviceType)pointerDeviceType {
    ABI::Windows::Devices::Input::PointerDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::ITappedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerDeviceType(&unmarshalledReturn));
    return (WDIPointerDeviceType)unmarshalledReturn;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::ITappedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::ITappedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WFPoint*)getPosition:(WXUIElement*)relativeTo {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Input::ITappedRoutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetPosition(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(relativeTo).Get(), &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

@end

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

id RTProxiedNSMutableArray_WUXIInputScopeName_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::Input::InputScopeName*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Xaml::Input::IInputScopeName*,
                                                                  IVector<ABI::Windows::UI::Xaml::Input::InputScopeName*>,
                                                                  WUXIInputScopeName,
                                                                  ABI::Windows::UI::Xaml::Input::InputScopeName*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
