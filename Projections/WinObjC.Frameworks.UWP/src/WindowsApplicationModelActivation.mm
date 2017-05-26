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

// WindowsApplicationModelActivation.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Activation.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelActivation.h"
#include "WindowsApplicationModelActivation_priv.h"

@implementation WAAIActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@end

@implementation WAAIPrintTaskSettingsActivatedEventArgs

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

@end

@implementation WAAIPrint3DWorkflowActivatedEventArgs

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

@end

@implementation WAAICameraSettingsActivatedEventArgs

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

@end

@implementation WAAIContactPickerActivatedEventArgs

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

@end

@implementation WAAIContactActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IContactActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@end

@implementation WAAIContactCallActivatedEventArgs

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

@end

@implementation WAAIContactMessageActivatedEventArgs

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

@end

@implementation WAAIContactMapActivatedEventArgs

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

@end

@implementation WAAIContactPostActivatedEventArgs

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

@end

@implementation WAAIContactVideoCallActivatedEventArgs

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

@end

@implementation WAAIContactsProviderActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IContactsProviderActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)verb {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IContactsProviderActivatedEventArgs>(self);
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

@end

@implementation WAAIWalletActionActivatedEventArgs

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

@end

@implementation WAAIAppointmentsProviderActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@end

@implementation WAAIAppointmentsProviderAddAppointmentActivatedEventArgs

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

@end

@implementation WAAIAppointmentsProviderReplaceAppointmentActivatedEventArgs

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

@end

@implementation WAAIAppointmentsProviderRemoveAppointmentActivatedEventArgs

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

@end

@implementation WAAIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs

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

@end

@implementation WAAIAppointmentsProviderShowTimeFrameActivatedEventArgs

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

@end

@implementation WAAIUserDataAccountProviderActivatedEventArgs

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

@end

@implementation WAAIActivatedEventArgsWithUser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
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

@end

@implementation WAAIApplicationViewActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)currentlyShownApplicationViewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentlyShownApplicationViewId(&unmarshalledReturn));
    return unmarshalledReturn;
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

@end

@implementation WAAIViewSwitcherProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IViewSwitcherProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUVActivationViewSwitcher*)viewSwitcher {
    ComPtr<ABI::Windows::UI::ViewManagement::IActivationViewSwitcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IViewSwitcherProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewSwitcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVActivationViewSwitcher>(unmarshalledReturn.Get());
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

@end

@implementation WAAIPrelaunchActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IPrelaunchActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)prelaunchActivated {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IPrelaunchActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrelaunchActivated(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
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

@end

@implementation WAAILaunchActivatedEventArgs

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

@end

@implementation WAAILockScreenCallActivatedEventArgs

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

@end

@implementation WAAILaunchActivatedEventArgs2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAATileActivatedInfo*)tileActivatedInfo {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ITileActivatedInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TileActivatedInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAATileActivatedInfo>(unmarshalledReturn.Get());
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

@end

@implementation WAAISearchActivatedEventArgs

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

@end

@implementation WAAISearchActivatedEventArgsWithLinguisticDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WASSearchPaneQueryLinguisticDetails*)linguisticDetails {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinguisticDetails(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchPaneQueryLinguisticDetails>(unmarshalledReturn.Get());
}

@end

@implementation WAAIShareTargetActivatedEventArgs

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

@end

@implementation WAAIFileActivatedEventArgs

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

@end

@implementation WAAIFileActivatedEventArgsWithNeighboringFiles

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSSStorageFileQueryResult*)neighboringFilesQuery {
    ComPtr<ABI::Windows::Storage::Search::IStorageFileQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles>(self);
    THROW_NS_IF_FAILED(_comInst->get_NeighboringFilesQuery(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorageFileQueryResult>(unmarshalledReturn.Get());
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

@end

@implementation WAAIFileActivatedEventArgsWithCallerPackageFamilyName

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithCallerPackageFamilyName> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)callerPackageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithCallerPackageFamilyName>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallerPackageFamilyName(&unmarshalledReturn));
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

@end

@implementation WAAIProtocolActivatedEventArgs

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

@end

@implementation WAAIProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@end

@implementation WAAIProtocolForResultsActivatedEventArgs

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

@end

@implementation WAAIFileOpenPickerActivatedEventArgs

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

@end

@implementation WAAIFileOpenPickerActivatedEventArgs2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)callerPackageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallerPackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WAAIFileSavePickerActivatedEventArgs

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

@end

@implementation WAAIFileSavePickerActivatedEventArgs2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@end

@implementation WAAICachedFileUpdaterActivatedEventArgs

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

@end

@implementation WAAIDeviceActivatedEventArgs

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

@end

@implementation WAAIPickerReturnedActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)pickerOperationId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PickerOperationId(&unmarshalledReturn));
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

@end

@implementation WAAIRestrictedLaunchActivatedEventArgs

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

@end

@implementation WAAILockScreenActivatedEventArgs

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

@end

@implementation WAAIContinuationActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IContinuationActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@end

@implementation WAAIFileOpenPickerContinuationEventArgs

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

@end

@implementation WAAIFileSavePickerContinuationEventArgs

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

@end

@implementation WAAIFolderPickerContinuationEventArgs

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

@end

@implementation WAAIWebAuthenticationBrokerContinuationEventArgs

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

@end

@implementation WAAIWebAccountProviderActivatedEventArgs

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

@end

@implementation WAAIToastNotificationActivatedEventArgs

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

@end

@implementation WAAIDialReceiverActivatedEventArgs

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

@end

@implementation WAAIBackgroundActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WABIBackgroundTaskInstance>*)taskInstance {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TaskInstance(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABIBackgroundTaskInstance>(unmarshalledReturn.Get());
}

@end

@implementation WAAIDevicePairingActivatedEventArgs

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

@end

@implementation WAAIVoiceCommandActivatedEventArgs

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

@end

@implementation WAAPrintTaskSettingsActivatedEventArgs

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

@end

@implementation WAAPrint3DWorkflowActivatedEventArgs

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

@end

@implementation WAALockScreenCallActivatedEventArgs

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

- (WUVActivationViewSwitcher*)viewSwitcher {
    ComPtr<ABI::Windows::UI::ViewManagement::IActivationViewSwitcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IViewSwitcherProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewSwitcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVActivationViewSwitcher>(unmarshalledReturn.Get());
}

@end

@implementation WAACameraSettingsActivatedEventArgs

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

@end

@implementation WAAContactPickerActivatedEventArgs

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

@end

@implementation WAAContactCallActivatedEventArgs

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

@end

@implementation WAAContactMessageActivatedEventArgs

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

@end

@implementation WAAContactMapActivatedEventArgs

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

@end

@implementation WAAContactPostActivatedEventArgs

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

@end

@implementation WAAContactVideoCallActivatedEventArgs

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

@end

@implementation WAAWalletActionActivatedEventArgs

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

@end

@implementation WAAAppointmentsProviderAddAppointmentActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAAppointmentsProviderReplaceAppointmentActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAAppointmentsProviderRemoveAppointmentActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAAppointmentsProviderShowAppointmentDetailsActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAAppointmentsProviderShowTimeFrameActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAUserDataAccountProviderActivatedEventArgs

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

@end

@implementation WAASplashScreen

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ISplashScreen> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFRect*)imageLocation {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ISplashScreen>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImageLocation(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (EventRegistrationToken)addDismissedEvent:(void (^)(WAASplashScreen*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ISplashScreen>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Dismissed(Make<ITypedEventHandler_Windows_ApplicationModel_Activation_SplashScreen_System_Object>(handler).Get(),
                                &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDismissedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ISplashScreen>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Dismissed(cookie));
}

@end

@implementation WAATileActivatedInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ITileActivatedInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WUNShownTileNotification* */)recentlyShownNotifications {
    ComPtr<IVectorView<ABI::Windows::UI::Notifications::ShownTileNotification*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ITileActivatedInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_RecentlyShownNotifications(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUNShownTileNotification_create(unmarshalledReturn.Get());
}

@end

@implementation WAALaunchActivatedEventArgs

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

- (int)currentlyShownApplicationViewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentlyShownApplicationViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)prelaunchActivated {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IPrelaunchActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrelaunchActivated(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUVActivationViewSwitcher*)viewSwitcher {
    ComPtr<ABI::Windows::UI::ViewManagement::IActivationViewSwitcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IViewSwitcherProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewSwitcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVActivationViewSwitcher>(unmarshalledReturn.Get());
}

- (WAATileActivatedInfo*)tileActivatedInfo {
    ComPtr<ABI::Windows::ApplicationModel::Activation::ITileActivatedInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TileActivatedInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAATileActivatedInfo>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAASearchActivatedEventArgs

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

- (int)currentlyShownApplicationViewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentlyShownApplicationViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WASSearchPaneQueryLinguisticDetails*)linguisticDetails {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinguisticDetails(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchPaneQueryLinguisticDetails>(unmarshalledReturn.Get());
}

- (WUVActivationViewSwitcher*)viewSwitcher {
    ComPtr<ABI::Windows::UI::ViewManagement::IActivationViewSwitcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IViewSwitcherProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewSwitcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVActivationViewSwitcher>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAShareTargetActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAFileActivatedEventArgs

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

- (WSSStorageFileQueryResult*)neighboringFilesQuery {
    ComPtr<ABI::Windows::Storage::Search::IStorageFileQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles>(self);
    THROW_NS_IF_FAILED(_comInst->get_NeighboringFilesQuery(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorageFileQueryResult>(unmarshalledReturn.Get());
}

- (NSString*)callerPackageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithCallerPackageFamilyName>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallerPackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)currentlyShownApplicationViewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentlyShownApplicationViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUVActivationViewSwitcher*)viewSwitcher {
    ComPtr<ABI::Windows::UI::ViewManagement::IActivationViewSwitcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IViewSwitcherProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewSwitcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVActivationViewSwitcher>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAProtocolActivatedEventArgs

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

- (WUVActivationViewSwitcher*)viewSwitcher {
    ComPtr<ABI::Windows::UI::ViewManagement::IActivationViewSwitcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IViewSwitcherProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewSwitcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVActivationViewSwitcher>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAProtocolForResultsActivatedEventArgs

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

- (WUVActivationViewSwitcher*)viewSwitcher {
    ComPtr<ABI::Windows::UI::ViewManagement::IActivationViewSwitcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IViewSwitcherProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewSwitcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVActivationViewSwitcher>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAFileOpenPickerActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAFileSavePickerActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAACachedFileUpdaterActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAADeviceActivatedEventArgs

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

- (WUVActivationViewSwitcher*)viewSwitcher {
    ComPtr<ABI::Windows::UI::ViewManagement::IActivationViewSwitcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IViewSwitcherProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewSwitcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVActivationViewSwitcher>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAPickerReturnedActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)pickerOperationId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PickerOperationId(&unmarshalledReturn));
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

@end

@implementation WAARestrictedLaunchActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAALockScreenActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAFileOpenPickerContinuationEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAFileSavePickerContinuationEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAFolderPickerContinuationEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAWebAuthenticationBrokerContinuationEventArgs

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

@end

@implementation WAAWebAccountProviderActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAToastNotificationActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAADialReceiverActivatedEventArgs

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

- (WUVActivationViewSwitcher*)viewSwitcher {
    ComPtr<ABI::Windows::UI::ViewManagement::IActivationViewSwitcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IViewSwitcherProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewSwitcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVActivationViewSwitcher>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAABackgroundActivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WABIBackgroundTaskInstance>*)taskInstance {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TaskInstance(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABIBackgroundTaskInstance>(unmarshalledReturn.Get());
}

@end

@implementation WAADevicePairingActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAVoiceCommandActivatedEventArgs

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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
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

id RTProxiedNSArray_WUNShownTileNotification_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Notifications::ShownTileNotification*>,
                                         RTArrayObj<ABI::Windows::UI::Notifications::IShownTileNotification*,
                                                    IVectorView<ABI::Windows::UI::Notifications::ShownTileNotification*>,
                                                    WUNShownTileNotification,
                                                    ABI::Windows::UI::Notifications::ShownTileNotification*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
