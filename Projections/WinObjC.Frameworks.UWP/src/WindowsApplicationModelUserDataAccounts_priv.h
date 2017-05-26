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

// WindowsApplicationModelUserDataAccounts_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsApplicationModelContacts_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsApplicationModelEmail_priv.h"
#include "WindowsApplicationModelAppointments_priv.h"
#include "WindowsSystem_priv.h"
ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics2> WAUIUserDataAccountManagerStatics2_inst();
ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics> WAUIUserDataAccountManagerStatics_inst();

id RTProxiedNSArray_WAAAppointmentCalendar_create(IInspectable* val);
id RTProxiedNSArray_WACContactAnnotationList_create(IInspectable* val);
id RTProxiedNSArray_WACContactList_create(IInspectable* val);
id RTProxiedNSArray_WAEEmailMailbox_create(IInspectable* val);
id RTProxiedNSArray_WAUUserDataAccount_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);

@class RTProxiedNSArray_WAAAppointmentCalendar, RTProxiedNSArray_WACContactAnnotationList, RTProxiedNSArray_WACContactList,
    RTProxiedNSArray_WAEEmailMailbox;
@class RTProxiedNSArray_WAUUserDataAccount, RTProxiedNSMutableArray_NSString;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_UserDataAccounts_UserDataAccountStore_Windows_ApplicationModel_UserDataAccounts_UserDataAccountStoreChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_UserDataAccounts_UserDataAccountStore_Windows_ApplicationModel_UserDataAccounts_UserDataAccountStoreChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_UserDataAccounts_UserDataAccountStore_Windows_ApplicationModel_UserDataAccounts_UserDataAccountStoreChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::UserDataAccounts::UserDataAccountStore*,
                              ABI::Windows::ApplicationModel::UserDataAccounts::UserDataAccountStoreChangedEventArgs*>> {
    void (^_delegate)(WAUUserDataAccountStore*, WAUUserDataAccountStoreChangedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_UserDataAccounts_UserDataAccountStore_Windows_ApplicationModel_UserDataAccounts_UserDataAccountStoreChangedEventArgs(
        void (^del)(WAUUserDataAccountStore*, WAUUserDataAccountStoreChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_UserDataAccounts_UserDataAccountStore_Windows_ApplicationModel_UserDataAccounts_UserDataAccountStoreChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore* arg0,
           ABI::Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAUUserDataAccountStore>(arg0), _createRtProxy<WAUUserDataAccountStoreChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
