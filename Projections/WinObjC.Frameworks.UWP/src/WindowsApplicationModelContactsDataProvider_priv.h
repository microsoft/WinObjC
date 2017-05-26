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

// WindowsApplicationModelContactsDataProvider_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsApplicationModelContacts_priv.h"

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Contacts_DataProvider_ContactDataProviderConnection_Windows_ApplicationModel_Contacts_DataProvider_ContactListServerSearchReadBatchRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Contacts_DataProvider_ContactDataProviderConnection_Windows_ApplicationModel_Contacts_DataProvider_ContactListServerSearchReadBatchRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Contacts_DataProvider_ContactDataProviderConnection_Windows_ApplicationModel_Contacts_DataProvider_ContactListServerSearchReadBatchRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequestEventArgs*>> {
    void (^_delegate)(WACDContactDataProviderConnection*, WACDContactListServerSearchReadBatchRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Contacts_DataProvider_ContactDataProviderConnection_Windows_ApplicationModel_Contacts_DataProvider_ContactListServerSearchReadBatchRequestEventArgs(
        void (^del)(WACDContactDataProviderConnection*, WACDContactListServerSearchReadBatchRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Contacts_DataProvider_ContactDataProviderConnection_Windows_ApplicationModel_Contacts_DataProvider_ContactListServerSearchReadBatchRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACDContactDataProviderConnection>(arg0),
                      _createRtProxy<WACDContactListServerSearchReadBatchRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Contacts_DataProvider_ContactDataProviderConnection_Windows_ApplicationModel_Contacts_DataProvider_ContactListSyncManagerSyncRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Contacts_DataProvider_ContactDataProviderConnection_Windows_ApplicationModel_Contacts_DataProvider_ContactListSyncManagerSyncRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Contacts_DataProvider_ContactDataProviderConnection_Windows_ApplicationModel_Contacts_DataProvider_ContactListSyncManagerSyncRequestEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection*,
                              ABI::Windows::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequestEventArgs*>> {
    void (^_delegate)(WACDContactDataProviderConnection*, WACDContactListSyncManagerSyncRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Contacts_DataProvider_ContactDataProviderConnection_Windows_ApplicationModel_Contacts_DataProvider_ContactListSyncManagerSyncRequestEventArgs(
        void (^del)(WACDContactDataProviderConnection*, WACDContactListSyncManagerSyncRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Contacts_DataProvider_ContactDataProviderConnection_Windows_ApplicationModel_Contacts_DataProvider_ContactListSyncManagerSyncRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACDContactDataProviderConnection>(arg0),
                      _createRtProxy<WACDContactListSyncManagerSyncRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
