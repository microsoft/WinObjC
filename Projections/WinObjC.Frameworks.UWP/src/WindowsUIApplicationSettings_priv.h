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

// WindowsUIApplicationSettings_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsUIPopups_priv.h"
#include "WindowsSecurityCredentials_priv.h"
static ComPtr<ABI::Windows::UI::ApplicationSettings::ISettingsCommandFactory> WUAISettingsCommandFactory_inst();
ComPtr<ABI::Windows::UI::ApplicationSettings::ISettingsCommandStatics> WUAISettingsCommandStatics_inst();
static ComPtr<ABI::Windows::UI::ApplicationSettings::IWebAccountProviderCommandFactory> WUAIWebAccountProviderCommandFactory_inst();
static ComPtr<ABI::Windows::UI::ApplicationSettings::IWebAccountCommandFactory> WUAIWebAccountCommandFactory_inst();
static ComPtr<ABI::Windows::UI::ApplicationSettings::ICredentialCommandFactory> WUAICredentialCommandFactory_inst();
ComPtr<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneStatics2> WUAIAccountsSettingsPaneStatics2_inst();
ComPtr<ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneStatics> WUAIAccountsSettingsPaneStatics_inst();
ComPtr<ABI::Windows::UI::ApplicationSettings::ISettingsPaneStatics> WUAISettingsPaneStatics_inst();

id RTProxiedNSMutableArray_WUACredentialCommand_create(IInspectable* val);
id RTProxiedNSMutableArray_WUASettingsCommand_create(IInspectable* val);
id RTProxiedNSMutableArray_WUAWebAccountCommand_create(IInspectable* val);
id RTProxiedNSMutableArray_WUAWebAccountProviderCommand_create(IInspectable* val);

@class RTProxiedNSMutableArray_WUACredentialCommand, RTProxiedNSMutableArray_WUASettingsCommand,
    RTProxiedNSMutableArray_WUAWebAccountCommand;
@class RTProxiedNSMutableArray_WUAWebAccountProviderCommand;

#ifndef __ITypedEventHandler_Windows_UI_ApplicationSettings_AccountsSettingsPane_Windows_UI_ApplicationSettings_AccountsSettingsPaneCommandsRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_ApplicationSettings_AccountsSettingsPane_Windows_UI_ApplicationSettings_AccountsSettingsPaneCommandsRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_UI_ApplicationSettings_AccountsSettingsPane_Windows_UI_ApplicationSettings_AccountsSettingsPaneCommandsRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::UI::ApplicationSettings::AccountsSettingsPane*,
                              ABI::Windows::UI::ApplicationSettings::AccountsSettingsPaneCommandsRequestedEventArgs*>> {
    void (^_delegate)(WUAAccountsSettingsPane*, WUAAccountsSettingsPaneCommandsRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_ApplicationSettings_AccountsSettingsPane_Windows_UI_ApplicationSettings_AccountsSettingsPaneCommandsRequestedEventArgs(
        void (^del)(WUAAccountsSettingsPane*, WUAAccountsSettingsPaneCommandsRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_ApplicationSettings_AccountsSettingsPane_Windows_UI_ApplicationSettings_AccountsSettingsPaneCommandsRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPane* arg0,
           ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUAAccountsSettingsPane>(arg0),
                      _createRtProxy<WUAAccountsSettingsPaneCommandsRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_ApplicationSettings_SettingsPane_Windows_UI_ApplicationSettings_SettingsPaneCommandsRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_ApplicationSettings_SettingsPane_Windows_UI_ApplicationSettings_SettingsPaneCommandsRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_ApplicationSettings_SettingsPane_Windows_UI_ApplicationSettings_SettingsPaneCommandsRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::ApplicationSettings::SettingsPane*,
                                                       ABI::Windows::UI::ApplicationSettings::SettingsPaneCommandsRequestedEventArgs*>> {
    void (^_delegate)(WUASettingsPane*, WUASettingsPaneCommandsRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_ApplicationSettings_SettingsPane_Windows_UI_ApplicationSettings_SettingsPaneCommandsRequestedEventArgs(
        void (^del)(WUASettingsPane*, WUASettingsPaneCommandsRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_ApplicationSettings_SettingsPane_Windows_UI_ApplicationSettings_SettingsPaneCommandsRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::UI::ApplicationSettings::ISettingsPane* arg0,
           ABI::Windows::UI::ApplicationSettings::ISettingsPaneCommandsRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUASettingsPane>(arg0), _createRtProxy<WUASettingsPaneCommandsRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUACredentialCommandCredentialDeletedHandler_shim__DEFINED
#define __WUACredentialCommandCredentialDeletedHandler_shim__DEFINED
class WUACredentialCommandCredentialDeletedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::UI::ApplicationSettings::ICredentialCommandCredentialDeletedHandler> {
    void (^_delegate)(WUACredentialCommand*);

public:
    WUACredentialCommandCredentialDeletedHandler_shim(void (^del)(WUACredentialCommand*)) : _delegate([del copy]) {
    }
    ~WUACredentialCommandCredentialDeletedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::ApplicationSettings::ICredentialCommand* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUACredentialCommand>(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WUAWebAccountCommandInvokedHandler_shim__DEFINED
#define __WUAWebAccountCommandInvokedHandler_shim__DEFINED
class WUAWebAccountCommandInvokedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::ApplicationSettings::IWebAccountCommandInvokedHandler> {
    void (^_delegate)(WUAWebAccountCommand*, WUAWebAccountInvokedArgs*);

public:
    WUAWebAccountCommandInvokedHandler_shim(void (^del)(WUAWebAccountCommand*, WUAWebAccountInvokedArgs*)) : _delegate([del copy]) {
    }
    ~WUAWebAccountCommandInvokedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::ApplicationSettings::IWebAccountCommand* arg0,
                                             ABI::Windows::UI::ApplicationSettings::IWebAccountInvokedArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUAWebAccountCommand>(arg0), _createRtProxy<WUAWebAccountInvokedArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUAWebAccountProviderCommandInvokedHandler_shim__DEFINED
#define __WUAWebAccountProviderCommandInvokedHandler_shim__DEFINED
class WUAWebAccountProviderCommandInvokedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::UI::ApplicationSettings::IWebAccountProviderCommandInvokedHandler> {
    void (^_delegate)(WUAWebAccountProviderCommand*);

public:
    WUAWebAccountProviderCommandInvokedHandler_shim(void (^del)(WUAWebAccountProviderCommand*)) : _delegate([del copy]) {
    }
    ~WUAWebAccountProviderCommandInvokedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::ApplicationSettings::IWebAccountProviderCommand* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUAWebAccountProviderCommand>(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WUPUICommandInvokedHandler_shim__DEFINED
#define __WUPUICommandInvokedHandler_shim__DEFINED
class WUPUICommandInvokedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Popups::IUICommandInvokedHandler> {
    void (^_delegate)(RTObject<WUPIUICommand>*);

public:
    WUPUICommandInvokedHandler_shim(void (^del)(RTObject<WUPIUICommand>*)) : _delegate([del copy]) {
    }
    ~WUPUICommandInvokedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Popups::IUICommand* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUPIUICommand>(arg0));
            return 0;
        };
    }
};
#endif
