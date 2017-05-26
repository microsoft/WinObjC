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

// WindowsUIWebUICore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.WebUI.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIWebUICore.h"
#include "WindowsUIWebUICore_priv.h"

@implementation WUWCIWebUICommandBarElement

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarElement> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUWCIWebUICommandBarIcon

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIcon> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUWCWebUICommandBarItemInvokedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarItemInvokedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isPrimaryCommand {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarItemInvokedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPrimaryCommand(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUWCWebUICommandBarIconButton

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.WebUI.Core.WebUICommandBarIconButton").Get(), &out));
    return [_createRtProxy<WUWCWebUICommandBarIconButton>(out.Get()) retain];
}

- (BOOL)enabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton>(self);
    THROW_NS_IF_FAILED(_comInst->put_Enabled((boolean)value));
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (BOOL)isToggleButton {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsToggleButton(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsToggleButton:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsToggleButton((boolean)value));
}

- (BOOL)isChecked {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsChecked(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsChecked:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsChecked((boolean)value));
}

- (RTObject<WUWCIWebUICommandBarIcon>*)icon {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIcon> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton>(self);
    THROW_NS_IF_FAILED(_comInst->get_Icon(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWCIWebUICommandBarIcon>(unmarshalledReturn.Get());
}

- (void)setIcon:(RTObject<WUWCIWebUICommandBarIcon>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton>(self);
    THROW_NS_IF_FAILED(_comInst->put_Icon(_getRtInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIcon>(value).Get()));
}

- (EventRegistrationToken)addItemInvokedEvent:(void (^)(WUWCWebUICommandBarIconButton*, WUWCWebUICommandBarItemInvokedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton>(self);
    THROW_NS_IF_FAILED(_comInst->add_ItemInvoked(
        Make<ITypedEventHandler_Windows_UI_WebUI_Core_WebUICommandBarIconButton_Windows_UI_WebUI_Core_WebUICommandBarItemInvokedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeItemInvokedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ItemInvoked(token));
}

@end

@implementation WUWCWebUICommandBarConfirmationButton

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarConfirmationButton> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.WebUI.Core.WebUICommandBarConfirmationButton").Get(),
                                              &out));
    return [_createRtProxy<WUWCWebUICommandBarConfirmationButton>(out.Get()) retain];
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarConfirmationButton>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarConfirmationButton>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (EventRegistrationToken)addItemInvokedEvent:(void (^)(WUWCWebUICommandBarConfirmationButton*,
                                                        WUWCWebUICommandBarItemInvokedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarConfirmationButton>(self);
    THROW_NS_IF_FAILED(_comInst->add_ItemInvoked(
        Make<
            ITypedEventHandler_Windows_UI_WebUI_Core_WebUICommandBarConfirmationButton_Windows_UI_WebUI_Core_WebUICommandBarItemInvokedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeItemInvokedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarConfirmationButton>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ItemInvoked(token));
}

@end

@implementation WUWCWebUICommandBarBitmapIcon

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarBitmapIcon> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarBitmapIconFactory> WUWCIWebUICommandBarBitmapIconFactory_inst() {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarBitmapIconFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.WebUI.Core.WebUICommandBarBitmapIcon").Get(),
                                                       &inst));
    return inst;
}

+ (WUWCWebUICommandBarBitmapIcon*)make:(WFUri*)uri {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarBitmapIcon> unmarshalledReturn;
    auto _comInst = WUWCIWebUICommandBarBitmapIconFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUWCWebUICommandBarBitmapIcon>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.WebUI.Core.WebUICommandBarBitmapIcon").Get(), &out));
    return [_createRtProxy<WUWCWebUICommandBarBitmapIcon>(out.Get()) retain];
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarBitmapIcon>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarBitmapIcon>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

@end

@implementation WUWCWebUICommandBarSymbolIcon

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarSymbolIcon> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarSymbolIconFactory> WUWCIWebUICommandBarSymbolIconFactory_inst() {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarSymbolIconFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.WebUI.Core.WebUICommandBarSymbolIcon").Get(),
                                                       &inst));
    return inst;
}

+ (WUWCWebUICommandBarSymbolIcon*)make:(NSString*)symbol {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarSymbolIcon> unmarshalledReturn;
    auto _comInst = WUWCIWebUICommandBarSymbolIconFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(symbol).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUWCWebUICommandBarSymbolIcon>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.WebUI.Core.WebUICommandBarSymbolIcon").Get(), &out));
    return [_createRtProxy<WUWCWebUICommandBarSymbolIcon>(out.Get()) retain];
}

- (NSString*)symbol {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarSymbolIcon>(self);
    THROW_NS_IF_FAILED(_comInst->get_Symbol(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSymbol:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarSymbolIcon>(self);
    THROW_NS_IF_FAILED(_comInst->put_Symbol(nsStrToHstr(value).Get()));
}

@end

@implementation WUWCWebUICommandBarSizeChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarSizeChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFSize*)size {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBarSizeChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

@end

@implementation WUWCWebUICommandBar

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBar> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarStatics> WUWCIWebUICommandBarStatics_inst() {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.WebUI.Core.WebUICommandBar").Get(), &inst));
    return inst;
}

+ (WUWCWebUICommandBar*)getForCurrentView {
    ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBar> unmarshalledReturn;
    auto _comInst = WUWCIWebUICommandBarStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWCWebUICommandBar>(unmarshalledReturn.Get());
}

- (BOOL)visible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Visible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_Visible((boolean)value));
}

- (double)opacity {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Opacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOpacity:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_Opacity(value));
}

- (WUColor*)foregroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ForegroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setForegroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_ForegroundColor(*[value internalStruct]));
}

- (WUColor*)backgroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setBackgroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_BackgroundColor(*[value internalStruct]));
}

- (WUWCWebUICommandBarClosedDisplayMode)closedDisplayMode {
    ABI::Windows::UI::WebUI::Core::WebUICommandBarClosedDisplayMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClosedDisplayMode(&unmarshalledReturn));
    return (WUWCWebUICommandBarClosedDisplayMode)unmarshalledReturn;
}

- (void)setClosedDisplayMode:(WUWCWebUICommandBarClosedDisplayMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_ClosedDisplayMode((ABI::Windows::UI::WebUI::Core::WebUICommandBarClosedDisplayMode)value));
}

- (BOOL)isOpen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOpen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsOpen:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsOpen((boolean)value));
}

- (WFSize*)size {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (NSMutableArray<RTObservableCollection>* /* RTObject<WUWCIWebUICommandBarElement>* */)primaryCommands {
    ComPtr<IObservableVector<ABI::Windows::UI::WebUI::Core::IWebUICommandBarElement*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrimaryCommands(unmarshalledReturn.GetAddressOf()));
    return RTProxiedObservableNSMutableArray_RTObject_WUWCIWebUICommandBarElement_create(unmarshalledReturn.Get());
}

- (NSMutableArray<RTObservableCollection>* /* RTObject<WUWCIWebUICommandBarElement>* */)secondaryCommands {
    ComPtr<IObservableVector<ABI::Windows::UI::WebUI::Core::IWebUICommandBarElement*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_SecondaryCommands(unmarshalledReturn.GetAddressOf()));
    return RTProxiedObservableNSMutableArray_RTObject_WUWCIWebUICommandBarElement_create(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addMenuOpenedEvent:(WUWCMenuOpenedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->add_MenuOpened(Make<WUWCMenuOpenedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMenuOpenedEvent:(EventRegistrationToken)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MenuOpened(value));
}

- (EventRegistrationToken)addMenuClosedEvent:(WUWCMenuClosedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->add_MenuClosed(Make<WUWCMenuClosedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMenuClosedEvent:(EventRegistrationToken)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MenuClosed(value));
}

- (EventRegistrationToken)addSizeChangedEvent:(WUWCSizeChangedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->add_SizeChanged(Make<WUWCSizeChangedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSizeChangedEvent:(EventRegistrationToken)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::Core::IWebUICommandBar>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SizeChanged(value));
}

@end

id RTProxiedObservableNSMutableArray_RTObject_WUWCIWebUICommandBarElement_create(IInspectable* val) {
    std::unique_ptr<ObservableArrayAdapter> adapter =
        std::make_unique<ObservableArrayAdapterObj<IObservableVector<ABI::Windows::UI::WebUI::Core::IWebUICommandBarElement*>,
                                                   RTObservableArrayObj<ABI::Windows::UI::WebUI::Core::IWebUICommandBarElement*,
                                                                        IVector<ABI::Windows::UI::WebUI::Core::IWebUICommandBarElement*>,
                                                                        RTObject<WUWCIWebUICommandBarElement>,
                                                                        ABI::Windows::UI::WebUI::Core::IWebUICommandBarElement*,
                                                                        dummyObjCCreator,
                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedObservableNSMutableArray alloc] initWithAdapter:std::move(adapter)] autorelease];
}
