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

// WindowsApplicationModelContacts_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundationCollections_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsUIViewManagement_priv.h"
#include "WindowsDataText_priv.h"
#include "WindowsUIPopups_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsSystem_priv.h"
static ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptionsFactory> WACIContactQueryOptionsFactory_inst();
ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics3> WACIContactManagerStatics3_inst();
ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics4> WACIContactManagerStatics4_inst();
ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics> WACIContactManagerStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics2> WACIContactManagerStatics2_inst();
ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLaunchActionVerbsStatics> WACIContactLaunchActionVerbsStatics_inst();
static ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactFieldFactory> WACIContactFieldFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLocationFieldFactory> WACIContactLocationFieldFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory> WACIContactInstantMessageFieldFactory_inst();
ComPtr<ABI::Windows::ApplicationModel::Contacts::IKnownContactFieldStatics> WACIKnownContactFieldStatics_inst();

id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WACContact_create(IInspectable* val);
id RTProxiedNSArray_WACContactAnnotation_create(IInspectable* val);
id RTProxiedNSArray_WACContactAnnotationList_create(IInspectable* val);
id RTProxiedNSArray_WACContactChange_create(IInspectable* val);
id RTProxiedNSArray_WACContactField_create(IInspectable* val);
id RTProxiedNSArray_WACContactInformation_create(IInspectable* val);
id RTProxiedNSArray_WACContactInstantMessageField_create(IInspectable* val);
id RTProxiedNSArray_WACContactList_create(IInspectable* val);
id RTProxiedNSArray_WACContactLocationField_create(IInspectable* val);
id RTProxiedNSArray_WACContactMatchReason_create(IInspectable* val);
id RTProxiedNSArray_WDTTextSegment_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_RTObject_WACIContactField_create(IInspectable* val);
id RTProxiedNSMutableArray_WACContact_create(IInspectable* val);
id RTProxiedNSMutableArray_WACContactAddress_create(IInspectable* val);
id RTProxiedNSMutableArray_WACContactConnectedServiceAccount_create(IInspectable* val);
id RTProxiedNSMutableArray_WACContactDate_create(IInspectable* val);
id RTProxiedNSMutableArray_WACContactEmail_create(IInspectable* val);
id RTProxiedNSMutableArray_WACContactFieldType_create(IInspectable* val);
id RTProxiedNSMutableArray_WACContactJobInfo_create(IInspectable* val);
id RTProxiedNSMutableArray_WACContactPhone_create(IInspectable* val);
id RTProxiedNSMutableArray_WACContactSignificantOther_create(IInspectable* val);
id RTProxiedNSMutableArray_WACContactWebsite_create(IInspectable* val);

@class Nullable_Int32, Nullable_UInt32, RTProxiedNSArray_NSString, RTProxiedNSArray_WACContact, RTProxiedNSArray_WACContactAnnotation,
    RTProxiedNSArray_WACContactAnnotationList;
@class RTProxiedNSArray_WACContactChange, RTProxiedNSArray_WACContactField, RTProxiedNSArray_WACContactInformation,
    RTProxiedNSArray_WACContactInstantMessageField;
@class RTProxiedNSArray_WACContactList, RTProxiedNSArray_WACContactLocationField, RTProxiedNSArray_WACContactMatchReason,
    RTProxiedNSArray_WDTTextSegment;
@class RTProxiedNSMutableArray_NSString, RTProxiedNSMutableArray_RTObject_WACIContactField, RTProxiedNSMutableArray_WACContact,
    RTProxiedNSMutableArray_WACContactAddress;
@class RTProxiedNSMutableArray_WACContactConnectedServiceAccount, RTProxiedNSMutableArray_WACContactDate,
    RTProxiedNSMutableArray_WACContactEmail;
@class RTProxiedNSMutableArray_WACContactFieldType, RTProxiedNSMutableArray_WACContactJobInfo, RTProxiedNSMutableArray_WACContactPhone;
@class RTProxiedNSMutableArray_WACContactSignificantOther, RTProxiedNSMutableArray_WACContactWebsite;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactListSyncManager_System_Object__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactListSyncManager_System_Object__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactListSyncManager_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Contacts::ContactListSyncManager*, IInspectable*>> {
    void (^_delegate)(WACContactListSyncManager*, RTObject*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactListSyncManager_System_Object(void (^del)(WACContactListSyncManager*,
                                                                                                          RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactListSyncManager_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACContactListSyncManager>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactList_Windows_ApplicationModel_Contacts_ContactChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactList_Windows_ApplicationModel_Contacts_ContactChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactList_Windows_ApplicationModel_Contacts_ContactChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Contacts::ContactList*,
                                                       ABI::Windows::ApplicationModel::Contacts::ContactChangedEventArgs*>> {
    void (^_delegate)(WACContactList*, WACContactChangedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactList_Windows_ApplicationModel_Contacts_ContactChangedEventArgs(
        void (^del)(WACContactList*, WACContactChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactList_Windows_ApplicationModel_Contacts_ContactChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Contacts::IContactList* arg0,
                                             ABI::Windows::ApplicationModel::Contacts::IContactChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACContactList>(arg0), _createRtProxy<WACContactChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactStore_Windows_ApplicationModel_Contacts_ContactChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactStore_Windows_ApplicationModel_Contacts_ContactChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactStore_Windows_ApplicationModel_Contacts_ContactChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Contacts::ContactStore*,
                                                       ABI::Windows::ApplicationModel::Contacts::ContactChangedEventArgs*>> {
    void (^_delegate)(WACContactStore*, WACContactChangedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactStore_Windows_ApplicationModel_Contacts_ContactChangedEventArgs(
        void (^del)(WACContactStore*, WACContactChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactStore_Windows_ApplicationModel_Contacts_ContactChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Contacts::IContactStore* arg0,
                                             ABI::Windows::ApplicationModel::Contacts::IContactChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACContactStore>(arg0), _createRtProxy<WACContactChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
