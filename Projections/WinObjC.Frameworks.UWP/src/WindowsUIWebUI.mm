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

// WindowsUIWebUI.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.WebUI.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIWebUI.h"
#include "WindowsUIWebUI_priv.h"

@implementation WUWIActivatedEventArgsDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWIWebUINavigatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::IWebUINavigatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUWWebUINavigatedOperation*)navigatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IWebUINavigatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IWebUINavigatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NavigatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWWebUINavigatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWIWebUIBackgroundTaskInstance

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::IWebUIBackgroundTaskInstance> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)succeeded {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IWebUIBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Succeeded(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSucceeded:(BOOL)succeeded {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IWebUIBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->put_Succeeded((boolean)succeeded));
}

@end

@implementation WUWWebUIPrintTaskSettingsActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPEPrintTaskConfiguration*)configuration {
    ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfiguration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Configuration(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPEPrintTaskConfiguration>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIPrint3DWorkflowActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPEPrint3DWorkflow*)workflow {
    ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Workflow(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPEPrint3DWorkflow>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUILockScreenCallActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACLockScreenCallUI*)callUI {
    ComPtr<ABI::Windows::ApplicationModel::Calls::ILockScreenCallUI> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallUI(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACLockScreenCallUI>(unmarshalledReturn.Get());
}

- (NSString*)arguments {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Arguments(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)tileId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TileId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (int)currentlyShownApplicationViewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentlyShownApplicationViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUICameraSettingsActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)videoDeviceController {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoDeviceController(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)videoDeviceExtension {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoDeviceExtension(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIContactPickerActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IContactPickerActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACPContactPickerUI*)contactPickerUI {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactPickerActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactPickerUI(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACPContactPickerUI>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIContactCallActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IContactCallActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)serviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactCallActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)serviceUserId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactCallActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceUserId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WACContact*)contact {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactCallActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contact(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContact>(unmarshalledReturn.Get());
}

- (NSString*)verb {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Verb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIContactMessageActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IContactMessageActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)serviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactMessageActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)serviceUserId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactMessageActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceUserId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WACContact*)contact {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactMessageActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contact(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContact>(unmarshalledReturn.Get());
}

- (NSString*)verb {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Verb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIContactMapActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IContactMapActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACContactAddress*)address {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactAddress> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactMapActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Address(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactAddress>(unmarshalledReturn.Get());
}

- (WACContact*)contact {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactMapActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contact(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContact>(unmarshalledReturn.Get());
}

- (NSString*)verb {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Verb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIContactPostActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IContactPostActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)serviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactPostActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)serviceUserId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactPostActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceUserId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WACContact*)contact {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactPostActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contact(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContact>(unmarshalledReturn.Get());
}

- (NSString*)verb {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Verb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIContactVideoCallActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)serviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)serviceUserId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceUserId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WACContact*)contact {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contact(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContact>(unmarshalledReturn.Get());
}

- (NSString*)verb {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Verb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUISearchActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)queryText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WASSearchPaneQueryLinguisticDetails*)linguisticDetails {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinguisticDetails(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchPaneQueryLinguisticDetails>(unmarshalledReturn.Get());
}

- (int)currentlyShownApplicationViewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentlyShownApplicationViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIWalletActionActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IWalletActionActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)itemId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IWalletActionActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAWWalletActionKind)actionKind {
    ABI::Windows::ApplicationModel::Wallet::WalletActionKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IWalletActionActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActionKind(&unmarshalledReturn));
    return (WAWWalletActionKind)unmarshalledReturn;
}

- (NSString*)actionId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IWalletActionActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIAppointmentsProviderAddAppointmentActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAAAAddAppointmentOperation*)addAppointmentOperation {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AddAppointmentOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAAddAppointmentOperation>(unmarshalledReturn.Get());
}

- (NSString*)verb {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Verb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAAAReplaceAppointmentOperation*)replaceAppointmentOperation {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReplaceAppointmentOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAReplaceAppointmentOperation>(unmarshalledReturn.Get());
}

- (NSString*)verb {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Verb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAAARemoveAppointmentOperation*)removeAppointmentOperation {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoveAppointmentOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAARemoveAppointmentOperation>(unmarshalledReturn.Get());
}

- (NSString*)verb {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Verb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* WFDateTime* */)instanceStartDate {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstanceStartDate(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (NSString*)localId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)roamingId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoamingId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)verb {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Verb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIAppointmentsProviderShowTimeFrameActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timeToShow {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeToShow(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSString*)verb {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Verb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIUserDataAccountProviderActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WAUPIUserDataAccountProviderOperation>*)operation {
    ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Operation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAUPIUserDataAccountProviderOperation>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIDevicePairingActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IDevicePairingActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDEDeviceInformation*)deviceInformation {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IDevicePairingActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIVoiceCommandActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMSSpeechRecognitionResult*)result {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Result(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSSpeechRecognitionResult>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWActivatedDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WUWActivatedOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUWActivatedDeferral*)getDeferral {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedOperation>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUILaunchActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)arguments {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Arguments(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)tileId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TileId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (BOOL)prelaunchActivated {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IPrelaunchActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrelaunchActivated(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)currentlyShownApplicationViewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentlyShownApplicationViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIShareTargetActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WADSShareOperation*)shareOperation {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShareOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADSShareOperation>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIFileActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* RTObject<WSIStorageItem>* */)files {
    ComPtr<IVectorView<ABI::Windows::Storage::IStorageItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Files(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WSIStorageItem_create(unmarshalledReturn.Get());
}

- (NSString*)verb {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Verb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (int)currentlyShownApplicationViewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentlyShownApplicationViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSSStorageFileQueryResult*)neighboringFilesQuery {
    ComPtr<ABI::Windows::Storage::Search::IStorageFileQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles>(self);
    THROW_NS_IF_FAILED(_comInst->get_NeighboringFilesQuery(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorageFileQueryResult>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIProtocolActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IProtocolActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IProtocolActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (NSString*)callerPackageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallerPackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFCValueSet*)data {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

- (int)currentlyShownApplicationViewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentlyShownApplicationViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIProtocolForResultsActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSProtocolForResultsOperation*)protocolForResultsOperation {
    ComPtr<ABI::Windows::System::IProtocolForResultsOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtocolForResultsOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSProtocolForResultsOperation>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IProtocolActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSString*)callerPackageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallerPackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFCValueSet*)data {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

- (int)currentlyShownApplicationViewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentlyShownApplicationViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIFileOpenPickerActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSPPFileOpenPickerUI*)fileOpenPickerUI {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileOpenPickerUI(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPPFileOpenPickerUI>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (NSString*)callerPackageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallerPackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIFileSavePickerActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSPPFileSavePickerUI*)fileSavePickerUI {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileSavePickerUI(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPPFileSavePickerUI>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (NSString*)callerPackageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallerPackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)enterpriseId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnterpriseId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUICachedFileUpdaterActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSPCachedFileUpdaterUI*)cachedFileUpdaterUI {
    ComPtr<ABI::Windows::Storage::Provider::ICachedFileUpdaterUI> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CachedFileUpdaterUI(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPCachedFileUpdaterUI>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIDeviceActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IDeviceActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceInformationId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IDeviceActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceInformationId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)verb {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IDeviceActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Verb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (int)currentlyShownApplicationViewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentlyShownApplicationViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUILockScreenActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ILockScreenActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)info {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ILockScreenActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Info(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (int)currentlyShownApplicationViewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentlyShownApplicationViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIRestrictedLaunchActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)sharedContext {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SharedContext(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIFileOpenPickerContinuationEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WSStorageFile* */)files {
    ComPtr<IVectorView<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Files(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSStorageFile_create(unmarshalledReturn.Get());
}

- (WFCValueSet*)continuationData {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContinuationActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContinuationData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIFileSavePickerContinuationEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSStorageFile*)file {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_File(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFile>(unmarshalledReturn.Get());
}

- (WFCValueSet*)continuationData {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContinuationActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContinuationData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIFolderPickerContinuationEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IFolderPickerContinuationEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSStorageFolder*)folder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFolderPickerContinuationEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Folder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (WFCValueSet*)continuationData {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContinuationActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContinuationData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIWebAuthenticationBrokerContinuationEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSAWWebAuthenticationResult*)webAuthenticationResult {
    ComPtr<ABI::Windows::Security::Authentication::Web::IWebAuthenticationResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebAuthenticationResult(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAWWebAuthenticationResult>(unmarshalledReturn.Get());
}

- (WFCValueSet*)continuationData {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContinuationActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContinuationData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIWebAccountProviderActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSAWPIWebAccountProviderOperation>*)operation {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Operation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAWPIWebAccountProviderOperation>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIDialReceiverActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IDialReceiverActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IDialReceiverActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)arguments {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Arguments(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)tileId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TileId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (int)currentlyShownApplicationViewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentlyShownApplicationViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIToastNotificationActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IToastNotificationActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)argument {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IToastNotificationActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Argument(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFCValueSet*)userInput {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IToastNotificationActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserInput(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

- (WAAActivationKind)kind {
    ABI::Windows::ApplicationModel::Activation::ActivationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAAActivationKind)unmarshalledReturn;
}

- (WAAApplicationExecutionState)previousExecutionState {
    ABI::Windows::ApplicationModel::Activation::ApplicationExecutionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousExecutionState(&unmarshalledReturn));
    return (WAAApplicationExecutionState)unmarshalledReturn;
}

- (WAASplashScreen*)splashScreen {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SplashScreen(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAASplashScreen>(unmarshalledReturn.Get());
}

- (WUWActivatedOperation*)activatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IActivatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IActivatedEventArgsDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWActivatedOperation>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUINavigatedOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::IWebUINavigatedOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUWWebUINavigatedDeferral*)getDeferral {
    ComPtr<ABI::Windows::UI::WebUI::IWebUINavigatedDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IWebUINavigatedOperation>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWWebUINavigatedDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUWSuspendingDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ISuspendingDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WUWSuspendingOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WASuspendingDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ISuspendingOperation>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASuspendingDeferral>(unmarshalledReturn.Get());
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ISuspendingOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WUWSuspendingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WASuspendingOperation*)suspendingOperation {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ISuspendingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuspendingOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASuspendingOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWLeavingBackgroundEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ILeavingBackgroundEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ILeavingBackgroundEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUWEnteredBackgroundEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IEnteredBackgroundEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IEnteredBackgroundEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIBackgroundTaskInstanceRuntimeClass

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::IWebUIBackgroundTaskInstance> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)succeeded {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IWebUIBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Succeeded(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSucceeded:(BOOL)succeeded {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IWebUIBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->put_Succeeded((boolean)succeeded));
}

- (WFGUID*)instanceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstanceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WABBackgroundTaskRegistration*)task {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Task(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABBackgroundTaskRegistration>(unmarshalledReturn.Get());
}

- (unsigned int)progress {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Progress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setProgress:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->put_Progress(value));
}

- (RTObject*)triggerDetails {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriggerDetails(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addCanceledEvent:(WABBackgroundTaskCanceledEventHandler)cancelHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->add_Canceled(Make<WABBackgroundTaskCanceledEventHandler_shim>(cancelHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCanceledEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Canceled(cookie));
}

- (unsigned int)suspendedCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuspendedCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WABBackgroundTaskDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABBackgroundTaskDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIBackgroundTaskInstance

ComPtr<ABI::Windows::UI::WebUI::IWebUIBackgroundTaskInstanceStatics> WUWIWebUIBackgroundTaskInstanceStatics_inst() {
    ComPtr<ABI::Windows::UI::WebUI::IWebUIBackgroundTaskInstanceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.WebUI.WebUIBackgroundTaskInstance").Get(),
                                                       &inst));
    return inst;
}

+ (RTObject<WUWIWebUIBackgroundTaskInstance>*)current {
    ComPtr<ABI::Windows::UI::WebUI::IWebUIBackgroundTaskInstance> unmarshalledReturn;
    auto _comInst = WUWIWebUIBackgroundTaskInstanceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Current(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWIWebUIBackgroundTaskInstance>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUINavigatedDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::IWebUINavigatedDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IWebUINavigatedDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WUWWebUINavigatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::IWebUINavigatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUWWebUINavigatedOperation*)navigatedOperation {
    ComPtr<ABI::Windows::UI::WebUI::IWebUINavigatedOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IWebUINavigatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NavigatedOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUWWebUINavigatedOperation>(unmarshalledReturn.Get());
}

@end

@implementation WUWWebUIApplication

ComPtr<ABI::Windows::UI::WebUI::IWebUIActivationStatics> WUWIWebUIActivationStatics_inst() {
    ComPtr<ABI::Windows::UI::WebUI::IWebUIActivationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.WebUI.WebUIApplication").Get(), &inst));
    return inst;
}

+ (EventRegistrationToken)addActivatedEvent:(WUWActivatedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WUWIWebUIActivationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_Activated(Make<WUWActivatedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeActivatedEvent:(EventRegistrationToken)token {
    auto _comInst = WUWIWebUIActivationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_Activated(token));
}

+ (EventRegistrationToken)addSuspendingEvent:(WUWSuspendingEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WUWIWebUIActivationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_Suspending(Make<WUWSuspendingEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeSuspendingEvent:(EventRegistrationToken)token {
    auto _comInst = WUWIWebUIActivationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_Suspending(token));
}

+ (EventRegistrationToken)addResumingEvent:(WUWResumingEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WUWIWebUIActivationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_Resuming(Make<WUWResumingEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeResumingEvent:(EventRegistrationToken)token {
    auto _comInst = WUWIWebUIActivationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_Resuming(token));
}

+ (EventRegistrationToken)addNavigatedEvent:(WUWNavigatedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WUWIWebUIActivationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_Navigated(Make<WUWNavigatedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeNavigatedEvent:(EventRegistrationToken)token {
    auto _comInst = WUWIWebUIActivationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_Navigated(token));
}

ComPtr<ABI::Windows::UI::WebUI::IWebUIActivationStatics2> WUWIWebUIActivationStatics2_inst() {
    ComPtr<ABI::Windows::UI::WebUI::IWebUIActivationStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.WebUI.WebUIApplication").Get(), &inst));
    return inst;
}

+ (EventRegistrationToken)addLeavingBackgroundEvent:(WUWLeavingBackgroundEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WUWIWebUIActivationStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->add_LeavingBackground(Make<WUWLeavingBackgroundEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeLeavingBackgroundEvent:(EventRegistrationToken)token {
    auto _comInst = WUWIWebUIActivationStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->remove_LeavingBackground(token));
}

+ (EventRegistrationToken)addEnteredBackgroundEvent:(WUWEnteredBackgroundEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WUWIWebUIActivationStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->add_EnteredBackground(Make<WUWEnteredBackgroundEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeEnteredBackgroundEvent:(EventRegistrationToken)token {
    auto _comInst = WUWIWebUIActivationStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->remove_EnteredBackground(token));
}

+ (void)enablePrelaunch:(BOOL)value {
    auto _comInst = WUWIWebUIActivationStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->EnablePrelaunch((boolean)value));
}

@end

@implementation WUWHtmlPrintDocumentSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUWPrintContent)content {
    ABI::Windows::UI::WebUI::PrintContent unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(&unmarshalledReturn));
    return (WUWPrintContent)unmarshalledReturn;
}

- (void)setContent:(WUWPrintContent)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_Content((ABI::Windows::UI::WebUI::PrintContent)value));
}

- (float)leftMargin {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_LeftMargin(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLeftMargin:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_LeftMargin(value));
}

- (float)topMargin {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_TopMargin(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTopMargin:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_TopMargin(value));
}

- (float)rightMargin {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_RightMargin(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRightMargin:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_RightMargin(value));
}

- (float)bottomMargin {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_BottomMargin(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBottomMargin:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_BottomMargin(value));
}

- (BOOL)enableHeaderFooter {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnableHeaderFooter(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnableHeaderFooter:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_EnableHeaderFooter((boolean)value));
}

- (BOOL)shrinkToFit {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShrinkToFit(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setShrinkToFit:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShrinkToFit((boolean)value));
}

- (float)percentScale {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PercentScale(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPercentScale:(float)scalePercent {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_PercentScale(scalePercent));
}

- (NSString*)pageRange {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PageRange(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)trySetPageRange:(NSString*)strPageRange {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::WebUI::IHtmlPrintDocumentSource>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetPageRange(nsStrToHstr(strPageRange).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

id RTProxiedNSArray_RTObject_WSIStorageItem_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Storage::IStorageItem*>,
                                                                             RTArrayObj<ABI::Windows::Storage::IStorageItem*,
                                                                                        IVectorView<ABI::Windows::Storage::IStorageItem*>,
                                                                                        RTObject<WSIStorageItem>,
                                                                                        ABI::Windows::Storage::IStorageItem*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSStorageFile_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Storage::StorageFile*>,
                                                                             RTArrayObj<ABI::Windows::Storage::IStorageFile*,
                                                                                        IVectorView<ABI::Windows::Storage::StorageFile*>,
                                                                                        WSStorageFile,
                                                                                        ABI::Windows::Storage::StorageFile*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
