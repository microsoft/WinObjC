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

// WindowsApplicationModelContactsProvider_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsApplicationModelContacts_priv.h"
#include "WindowsFoundation_priv.h"

id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WACContactFieldType_create(IInspectable* val);

@class RTProxiedNSArray_NSString, RTProxiedNSMutableArray_WACContactFieldType;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Contacts_Provider_ContactPickerUI_Windows_ApplicationModel_Contacts_Provider_ContactRemovedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Contacts_Provider_ContactPickerUI_Windows_ApplicationModel_Contacts_Provider_ContactRemovedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Contacts_Provider_ContactPickerUI_Windows_ApplicationModel_Contacts_Provider_ContactRemovedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Contacts::Provider::ContactPickerUI*,
                                                       ABI::Windows::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs*>> {
    void (^_delegate)(WACPContactPickerUI*, WACPContactRemovedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Contacts_Provider_ContactPickerUI_Windows_ApplicationModel_Contacts_Provider_ContactRemovedEventArgs(
        void (^del)(WACPContactPickerUI*, WACPContactRemovedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Contacts_Provider_ContactPickerUI_Windows_ApplicationModel_Contacts_Provider_ContactRemovedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI* arg0,
                                             ABI::Windows::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACPContactPickerUI>(arg0), _createRtProxy<WACPContactRemovedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
