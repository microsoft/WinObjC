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

// WindowsUIApplicationSettings.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.ApplicationSettings.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIApplicationSettings.h"
#include "WindowsUIApplicationSettings_priv.h"

@implementation WUASettingsCommand

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Popups::IUICommand> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::ApplicationSettings::ISettingsCommandFactory> WUAISettingsCommandFactory_inst() {
    ComPtr<ABI::Windows::UI::ApplicationSettings::ISettingsCommandFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ApplicationSettings.SettingsCommand").Get(),
                                                       &inst));
    return inst;
}

+ (WUASettingsCommand*)makeSettingsCommand:(RTObject*)settingsCommandId label:(NSString*)label handler:(WUPUICommandInvokedHandler)handler {
    ComPtr<ABI::Windows::UI::Popups::IUICommand> unmarshalledReturn;
    auto _comInst = WUAISettingsCommandFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSettingsCommand([settingsCommandId comObj].Get(),
                                                       nsStrToHstr(label).Get(),
                                                       Make<WUPUICommandInvokedHandler_shim>(handler).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUASettingsCommand>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::UI::ApplicationSettings::ISettingsCommandStatics> WUAISettingsCommandStatics_inst() {
    ComPtr<ABI::Windows::UI::ApplicationSettings::ISettingsCommandStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ApplicationSettings.SettingsCommand").Get(),
                                                       &inst));
    return inst;
}

+ (WUASettingsCommand*)accountsCommand {
    ComPtr<ABI::Windows::UI::Popups::IUICommand> unmarshalledReturn;
    auto _comInst = WUAISettingsCommandStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AccountsCommand(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUASettingsCommand>(unmarshalledReturn.Get());
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (WUPUICommandInvokedHandler)invoked {
    ComPtr<ABI::Windows::UI::Popups::IUICommandInvokedHandler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Invoked(unmarshalledReturn.GetAddressOf()));
    return nil;
}

- (void)setInvoked:(WUPUICommandInvokedHandler)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->put_Invoked(Make<WUPUICommandInvokedHandler_shim>(value).Get()));
}

- (RTObject*)id {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setId:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Popups::IUICommand>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id([value comObj].Get()));
}

@end

@implementation WUAWebAccountProviderCommand

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IWebAccountProviderCommand> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::ApplicationSettings::IWebAccountProviderCommandFactory> WUAIWebAccountProviderCommandFactory_inst() {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IWebAccountProviderCommandFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.ApplicationSettings.WebAccountProviderCommand").Get(), &inst));
    return inst;
}

+ (WUAWebAccountProviderCommand*)makeWebAccountProviderCommand:(WSCWebAccountProvider*)webAccountProvider
                                                       invoked:(WUAWebAccountProviderCommandInvokedHandler)invoked {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IWebAccountProviderCommand> unmarshalledReturn;
    auto _comInst = WUAIWebAccountProviderCommandFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWebAccountProviderCommand(
        _getRtInterface<ABI::Windows::Security::Credentials::IWebAccountProvider>(webAccountProvider).Get(),
        Make<WUAWebAccountProviderCommandInvokedHandler_shim>(invoked).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUAWebAccountProviderCommand>(unmarshalledReturn.Get()) retain];
}

- (WSCWebAccountProvider*)webAccountProvider {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccountProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IWebAccountProviderCommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebAccountProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCWebAccountProvider>(unmarshalledReturn.Get());
}

- (WUAWebAccountProviderCommandInvokedHandler)invoked {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IWebAccountProviderCommandInvokedHandler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IWebAccountProviderCommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Invoked(unmarshalledReturn.GetAddressOf()));
    return nil;
}

@end

@implementation WUAWebAccountCommand

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IWebAccountCommand> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::ApplicationSettings::IWebAccountCommandFactory> WUAIWebAccountCommandFactory_inst() {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IWebAccountCommandFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ApplicationSettings.WebAccountCommand").Get(),
                                                       &inst));
    return inst;
}

+ (WUAWebAccountCommand*)makeWebAccountCommand:(WSCWebAccount*)webAccount
                                       invoked:(WUAWebAccountCommandInvokedHandler)invoked
                                       actions:(WUASupportedWebAccountActions)actions {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IWebAccountCommand> unmarshalledReturn;
    auto _comInst = WUAIWebAccountCommandFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWebAccountCommand(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(),
                                          Make<WUAWebAccountCommandInvokedHandler_shim>(invoked).Get(),
                                          (ABI::Windows::UI::ApplicationSettings::SupportedWebAccountActions)actions,
                                          unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUAWebAccountCommand>(unmarshalledReturn.Get()) retain];
}

- (WSCWebAccount*)webAccount {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccount> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IWebAccountCommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebAccount(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCWebAccount>(unmarshalledReturn.Get());
}

- (WUAWebAccountCommandInvokedHandler)invoked {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IWebAccountCommandInvokedHandler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IWebAccountCommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Invoked(unmarshalledReturn.GetAddressOf()));
    return nil;
}

- (WUASupportedWebAccountActions)actions {
    ABI::Windows::UI::ApplicationSettings::SupportedWebAccountActions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IWebAccountCommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Actions(&unmarshalledReturn));
    return (WUASupportedWebAccountActions)unmarshalledReturn;
}

@end

@implementation WUAWebAccountInvokedArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IWebAccountInvokedArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUAWebAccountAction)action {
    ABI::Windows::UI::ApplicationSettings::WebAccountAction unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IWebAccountInvokedArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Action(&unmarshalledReturn));
    return (WUAWebAccountAction)unmarshalledReturn;
}

@end

@implementation WUACredentialCommand

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ApplicationSettings::ICredentialCommand> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::ApplicationSettings::ICredentialCommandFactory> WUAICredentialCommandFactory_inst() {
    ComPtr<ABI::Windows::UI::ApplicationSettings::ICredentialCommandFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ApplicationSettings.CredentialCommand").Get(),
                                                       &inst));
    return inst;
}

+ (WUACredentialCommand*)makeCredentialCommand:(WSCPasswordCredential*)passwordCredential {
    ComPtr<ABI::Windows::UI::ApplicationSettings::ICredentialCommand> unmarshalledReturn;
    auto _comInst = WUAICredentialCommandFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCredentialCommand(
        _getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(passwordCredential).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUACredentialCommand>(unmarshalledReturn.Get()) retain];
}

+ (WUACredentialCommand*)makeCredentialCommandWithHandler:(WSCPasswordCredential*)passwordCredential
                                                  deleted:(WUACredentialCommandCredentialDeletedHandler)deleted {
    ComPtr<ABI::Windows::UI::ApplicationSettings::ICredentialCommand> unmarshalledReturn;
    auto _comInst = WUAICredentialCommandFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCredentialCommandWithHandler(
        _getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(passwordCredential).Get(),
        Make<WUACredentialCommandCredentialDeletedHandler_shim>(deleted).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUACredentialCommand>(unmarshalledReturn.Get()) retain];
}

- (WSCPasswordCredential*)passwordCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::ICredentialCommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_PasswordCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (WUACredentialCommandCredentialDeletedHandler)credentialDeleted {
    ComPtr<ABI::Windows::UI::ApplicationSettings::ICredentialCommandCredentialDeletedHandler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::ICredentialCommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_CredentialDeleted(unmarshalledReturn.GetAddressOf()));
    return nil;
}

@end

@implementation WUAAccountsSettingsPaneEventDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WUAAccountsSettingsPaneCommandsRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSMutableArray* /* WUAWebAccountProviderCommand* */)webAccountProviderCommands {
    ComPtr<IVector<ABI::Windows::UI::ApplicationSettings::WebAccountProviderCommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebAccountProviderCommands(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUAWebAccountProviderCommand_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WUAWebAccountCommand* */)webAccountCommands {
    ComPtr<IVector<ABI::Windows::UI::ApplicationSettings::WebAccountCommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebAccountCommands(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUAWebAccountCommand_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WUACredentialCommand* */)credentialCommands {
    ComPtr<IVector<ABI::Windows::UI::ApplicationSettings::CredentialCommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CredentialCommands(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUACredentialCommand_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WUASettingsCommand* */)commands {
    ComPtr<IVector<ABI::Windows::UI::ApplicationSettings::SettingsCommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Commands(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUASettingsCommand_create(unmarshalledReturn.Get());
}

- (NSString*)headerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_HeaderText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setHeaderText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_HeaderText(nsStrToHstr(value).Get()));
}

- (WUAAccountsSettingsPaneEventDeferral*)getDeferral {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUAAccountsSettingsPaneEventDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUAAccountsSettingsPane

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPane> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneStatics2> WUAIAccountsSettingsPaneStatics2_inst() {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ApplicationSettings.AccountsSettingsPane").Get(),
                                                       &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)showManageAccountsAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WUAIAccountsSettingsPaneStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->ShowManageAccountsAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)showAddAccountAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WUAIAccountsSettingsPaneStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->ShowAddAccountAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneStatics> WUAIAccountsSettingsPaneStatics_inst() {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ApplicationSettings.AccountsSettingsPane").Get(),
                                                       &inst));
    return inst;
}

+ (WUAAccountsSettingsPane*)getForCurrentView {
    ComPtr<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPane> unmarshalledReturn;
    auto _comInst = WUAIAccountsSettingsPaneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUAAccountsSettingsPane>(unmarshalledReturn.Get());
}

+ (void)show {
    auto _comInst = WUAIAccountsSettingsPaneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Show());
}

- (EventRegistrationToken)addAccountCommandsRequestedEvent:(void (^)(WUAAccountsSettingsPane*,
                                                                     WUAAccountsSettingsPaneCommandsRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPane>(self);
    THROW_NS_IF_FAILED(_comInst->add_AccountCommandsRequested(
        Make<
            ITypedEventHandler_Windows_UI_ApplicationSettings_AccountsSettingsPane_Windows_UI_ApplicationSettings_AccountsSettingsPaneCommandsRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAccountCommandsRequestedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPane>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AccountCommandsRequested(cookie));
}

@end

@implementation WUASettingsPaneCommandsRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSMutableArray* /* WUASettingsCommand* */)applicationCommands {
    ComPtr<IVector<ABI::Windows::UI::ApplicationSettings::SettingsCommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationCommands(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUASettingsCommand_create(unmarshalledReturn.Get());
}

@end

@implementation WUASettingsPaneCommandsRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUASettingsPaneCommandsRequest*)request {
    ComPtr<ABI::Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUASettingsPaneCommandsRequest>(unmarshalledReturn.Get());
}

@end

@implementation WUASettingsPane

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ApplicationSettings::ISettingsPane> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::ApplicationSettings::ISettingsPaneStatics> WUAISettingsPaneStatics_inst() {
    ComPtr<ABI::Windows::UI::ApplicationSettings::ISettingsPaneStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ApplicationSettings.SettingsPane").Get(),
                                                       &inst));
    return inst;
}

+ (WUASettingsPane*)getForCurrentView {
    ComPtr<ABI::Windows::UI::ApplicationSettings::ISettingsPane> unmarshalledReturn;
    auto _comInst = WUAISettingsPaneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUASettingsPane>(unmarshalledReturn.Get());
}

+ (void)show {
    auto _comInst = WUAISettingsPaneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Show());
}

+ (WUASettingsEdgeLocation)edge {
    ABI::Windows::UI::ApplicationSettings::SettingsEdgeLocation unmarshalledReturn;
    auto _comInst = WUAISettingsPaneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Edge(&unmarshalledReturn));
    return (WUASettingsEdgeLocation)unmarshalledReturn;
}

- (EventRegistrationToken)addCommandsRequestedEvent:(void (^)(WUASettingsPane*, WUASettingsPaneCommandsRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::ISettingsPane>(self);
    THROW_NS_IF_FAILED(_comInst->add_CommandsRequested(
        Make<
            ITypedEventHandler_Windows_UI_ApplicationSettings_SettingsPane_Windows_UI_ApplicationSettings_SettingsPaneCommandsRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCommandsRequestedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ApplicationSettings::ISettingsPane>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CommandsRequested(cookie));
}

@end

id RTProxiedNSMutableArray_WUACredentialCommand_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::ApplicationSettings::CredentialCommand*>,
                                                RTMutableArrayObj<ABI::Windows::UI::ApplicationSettings::ICredentialCommand*,
                                                                  IVector<ABI::Windows::UI::ApplicationSettings::CredentialCommand*>,
                                                                  WUACredentialCommand,
                                                                  ABI::Windows::UI::ApplicationSettings::CredentialCommand*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WUASettingsCommand_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::ApplicationSettings::SettingsCommand*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Popups::IUICommand*,
                                                                  IVector<ABI::Windows::UI::ApplicationSettings::SettingsCommand*>,
                                                                  WUASettingsCommand,
                                                                  ABI::Windows::UI::ApplicationSettings::SettingsCommand*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WUAWebAccountCommand_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::ApplicationSettings::WebAccountCommand*>,
                                                RTMutableArrayObj<ABI::Windows::UI::ApplicationSettings::IWebAccountCommand*,
                                                                  IVector<ABI::Windows::UI::ApplicationSettings::WebAccountCommand*>,
                                                                  WUAWebAccountCommand,
                                                                  ABI::Windows::UI::ApplicationSettings::WebAccountCommand*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WUAWebAccountProviderCommand_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::UI::ApplicationSettings::WebAccountProviderCommand*>,
                               RTMutableArrayObj<ABI::Windows::UI::ApplicationSettings::IWebAccountProviderCommand*,
                                                 IVector<ABI::Windows::UI::ApplicationSettings::WebAccountProviderCommand*>,
                                                 WUAWebAccountProviderCommand,
                                                 ABI::Windows::UI::ApplicationSettings::WebAccountProviderCommand*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
