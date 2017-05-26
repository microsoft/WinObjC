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

// WindowsUIWebUI_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsGraphicsPrinting_priv.h"
#include "WindowsApplicationModelCalls_priv.h"
#include "WindowsApplicationModelContactsProvider_priv.h"
#include "WindowsApplicationModelActivation_priv.h"
#include "WindowsDevicesPrintersExtensions_priv.h"
#include "WindowsApplicationModelContacts_priv.h"
#include "WindowsMediaSpeechRecognition_priv.h"
#include "WindowsApplicationModelSearch_priv.h"
#include "WindowsApplicationModelWallet_priv.h"
#include "WindowsApplicationModelAppointmentsAppointmentsProvider_priv.h"
#include "WindowsStoragePickersProvider_priv.h"
#include "WindowsSystem_priv.h"
#include "WindowsApplicationModelUserDataAccountsProvider_priv.h"
#include "WindowsDevicesEnumeration_priv.h"
#include "WindowsApplicationModelDataTransferShareTarget_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsStorageSearch_priv.h"
#include "WindowsFoundationCollections_priv.h"
#include "WindowsStorageProvider_priv.h"
#include "WindowsSecurityAuthenticationWeb_priv.h"
#include "WindowsSecurityAuthenticationWebProvider_priv.h"
#include "WindowsApplicationModel_priv.h"
#include "WindowsApplicationModelBackground_priv.h"
ComPtr<ABI::Windows::UI::WebUI::IWebUIBackgroundTaskInstanceStatics> WUWIWebUIBackgroundTaskInstanceStatics_inst();
ComPtr<ABI::Windows::UI::WebUI::IWebUIActivationStatics> WUWIWebUIActivationStatics_inst();
ComPtr<ABI::Windows::UI::WebUI::IWebUIActivationStatics2> WUWIWebUIActivationStatics2_inst();

id RTProxiedNSArray_RTObject_WSIStorageItem_create(IInspectable* val);
id RTProxiedNSArray_WSStorageFile_create(IInspectable* val);

@class Nullable_WFDateTime, RTProxiedNSArray_RTObject_WSIStorageItem, RTProxiedNSArray_WSStorageFile;

#ifndef __WABBackgroundTaskCanceledEventHandler_shim__DEFINED
#define __WABBackgroundTaskCanceledEventHandler_shim__DEFINED
class WABBackgroundTaskCanceledEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::ApplicationModel::Background::IBackgroundTaskCanceledEventHandler> {
    void (^_delegate)(RTObject<WABIBackgroundTaskInstance>*, WABBackgroundTaskCancellationReason);

public:
    WABBackgroundTaskCanceledEventHandler_shim(void (^del)(RTObject<WABIBackgroundTaskInstance>*, WABBackgroundTaskCancellationReason))
        : _delegate([del copy]) {
    }
    ~WABBackgroundTaskCanceledEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance* arg0,
                                             ABI::Windows::ApplicationModel::Background::BackgroundTaskCancellationReason arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WABIBackgroundTaskInstance>(arg0), (WABBackgroundTaskCancellationReason)arg1);
            return 0;
        };
    }
};
#endif

#ifndef __WUWActivatedEventHandler_shim__DEFINED
#define __WUWActivatedEventHandler_shim__DEFINED
class WUWActivatedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::WebUI::IActivatedEventHandler> {
    void (^_delegate)(RTObject*, RTObject<WAAIActivatedEventArgs>*);

public:
    WUWActivatedEventHandler_shim(void (^del)(RTObject*, RTObject<WAAIActivatedEventArgs>*)) : _delegate([del copy]) {
    }
    ~WUWActivatedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WAAIActivatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUWEnteredBackgroundEventHandler_shim__DEFINED
#define __WUWEnteredBackgroundEventHandler_shim__DEFINED
class WUWEnteredBackgroundEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::WebUI::IEnteredBackgroundEventHandler> {
    void (^_delegate)(RTObject*, RTObject<WAIEnteredBackgroundEventArgs>*);

public:
    WUWEnteredBackgroundEventHandler_shim(void (^del)(RTObject*, RTObject<WAIEnteredBackgroundEventArgs>*)) : _delegate([del copy]) {
    }
    ~WUWEnteredBackgroundEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::ApplicationModel::IEnteredBackgroundEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WAIEnteredBackgroundEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUWLeavingBackgroundEventHandler_shim__DEFINED
#define __WUWLeavingBackgroundEventHandler_shim__DEFINED
class WUWLeavingBackgroundEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::WebUI::ILeavingBackgroundEventHandler> {
    void (^_delegate)(RTObject*, RTObject<WAILeavingBackgroundEventArgs>*);

public:
    WUWLeavingBackgroundEventHandler_shim(void (^del)(RTObject*, RTObject<WAILeavingBackgroundEventArgs>*)) : _delegate([del copy]) {
    }
    ~WUWLeavingBackgroundEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::ApplicationModel::ILeavingBackgroundEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WAILeavingBackgroundEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUWNavigatedEventHandler_shim__DEFINED
#define __WUWNavigatedEventHandler_shim__DEFINED
class WUWNavigatedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::WebUI::INavigatedEventHandler> {
    void (^_delegate)(RTObject*, RTObject<WUWIWebUINavigatedEventArgs>*);

public:
    WUWNavigatedEventHandler_shim(void (^del)(RTObject*, RTObject<WUWIWebUINavigatedEventArgs>*)) : _delegate([del copy]) {
    }
    ~WUWNavigatedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::WebUI::IWebUINavigatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUWIWebUINavigatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUWResumingEventHandler_shim__DEFINED
#define __WUWResumingEventHandler_shim__DEFINED
class WUWResumingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::WebUI::IResumingEventHandler> {
    void (^_delegate)(RTObject*);

public:
    WUWResumingEventHandler_shim(void (^del)(RTObject*)) : _delegate([del copy]) {
    }
    ~WUWResumingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WUWSuspendingEventHandler_shim__DEFINED
#define __WUWSuspendingEventHandler_shim__DEFINED
class WUWSuspendingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::WebUI::ISuspendingEventHandler> {
    void (^_delegate)(RTObject*, RTObject<WAISuspendingEventArgs>*);

public:
    WUWSuspendingEventHandler_shim(void (^del)(RTObject*, RTObject<WAISuspendingEventArgs>*)) : _delegate([del copy]) {
    }
    ~WUWSuspendingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::ApplicationModel::ISuspendingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WAISuspendingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
