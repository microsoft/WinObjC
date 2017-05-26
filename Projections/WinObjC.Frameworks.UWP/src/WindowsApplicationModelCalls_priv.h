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

// WindowsApplicationModelCalls_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsApplicationModelContacts_priv.h"
#include "WindowsUI_priv.h"
#include "WindowsSystem_priv.h"
ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneLineStatics> WACIPhoneLineStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallManagerStatics2> WACIPhoneCallManagerStatics2_inst();
ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallManagerStatics> WACIPhoneCallManagerStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics>
WACIPhoneCallVideoCapabilitiesManagerStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallBlockingStatics> WACIPhoneCallBlockingStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinatorStatics> WACIVoipCallCoordinatorStatics_inst();
static ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory> WACIPhoneCallHistoryEntryAddressFactory_inst();
ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics> WACIPhoneCallHistoryManagerStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2> WACIPhoneCallHistoryManagerStatics2_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_WACPhoneCallHistoryEntry_create(IInspectable* val);
id RTProxiedNSArray_WACPhoneCallHistoryEntry_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);

@class Nullable_WFTimeSpan, RTProxiedIterableNSArray_NSString, RTProxiedIterableNSArray_WACPhoneCallHistoryEntry,
    RTProxiedNSArray_WACPhoneCallHistoryEntry;
@class RTProxiedNSDictionary_NSString_RTObject, RTProxiedNSMutableArray_NSString;

#ifndef __EventHandler_System_Object__DEFINED
#define __EventHandler_System_Object__DEFINED
class EventHandler_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Foundation::IEventHandler<IInspectable*>> {
    void (^_delegate)(RTObject*, RTObject*);

public:
    EventHandler_System_Object(void (^del)(RTObject*, RTObject*)) : _delegate([del copy]) {
    }
    ~EventHandler_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Calls_LockScreenCallUI_System_Object__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Calls_LockScreenCallUI_System_Object__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Calls_LockScreenCallUI_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Calls::LockScreenCallUI*, IInspectable*>> {
    void (^_delegate)(WACLockScreenCallUI*, RTObject*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Calls_LockScreenCallUI_System_Object(void (^del)(WACLockScreenCallUI*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Calls_LockScreenCallUI_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Calls::ILockScreenCallUI* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACLockScreenCallUI>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Calls_LockScreenCallUI_Windows_ApplicationModel_Calls_LockScreenCallEndRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Calls_LockScreenCallUI_Windows_ApplicationModel_Calls_LockScreenCallEndRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Calls_LockScreenCallUI_Windows_ApplicationModel_Calls_LockScreenCallEndRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Calls::LockScreenCallUI*,
                                                       ABI::Windows::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs*>> {
    void (^_delegate)(WACLockScreenCallUI*, WACLockScreenCallEndRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Calls_LockScreenCallUI_Windows_ApplicationModel_Calls_LockScreenCallEndRequestedEventArgs(
        void (^del)(WACLockScreenCallUI*, WACLockScreenCallEndRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Calls_LockScreenCallUI_Windows_ApplicationModel_Calls_LockScreenCallEndRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Calls::ILockScreenCallUI* arg0,
                                             ABI::Windows::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACLockScreenCallUI>(arg0), _createRtProxy<WACLockScreenCallEndRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_System_Object__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_System_Object__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Calls::PhoneLineWatcher*, IInspectable*>> {
    void (^_delegate)(WACPhoneLineWatcher*, RTObject*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_System_Object(void (^del)(WACPhoneLineWatcher*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACPhoneLineWatcher>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_Windows_ApplicationModel_Calls_PhoneLineWatcherEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_Windows_ApplicationModel_Calls_PhoneLineWatcherEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_Windows_ApplicationModel_Calls_PhoneLineWatcherEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Calls::PhoneLineWatcher*,
                                                                       ABI::Windows::ApplicationModel::Calls::PhoneLineWatcherEventArgs*>> {
    void (^_delegate)(WACPhoneLineWatcher*, WACPhoneLineWatcherEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_Windows_ApplicationModel_Calls_PhoneLineWatcherEventArgs(
        void (^del)(WACPhoneLineWatcher*, WACPhoneLineWatcherEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLineWatcher_Windows_ApplicationModel_Calls_PhoneLineWatcherEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcher* arg0,
                                             ABI::Windows::ApplicationModel::Calls::IPhoneLineWatcherEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACPhoneLineWatcher>(arg0), _createRtProxy<WACPhoneLineWatcherEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLine_System_Object__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLine_System_Object__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLine_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Calls::PhoneLine*, IInspectable*>> {
    void (^_delegate)(WACPhoneLine*, RTObject*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLine_System_Object(void (^del)(WACPhoneLine*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Calls_PhoneLine_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Calls::IPhoneLine* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACPhoneLine>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Calls_VoipCallCoordinator_Windows_ApplicationModel_Calls_MuteChangeEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Calls_VoipCallCoordinator_Windows_ApplicationModel_Calls_MuteChangeEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Calls_VoipCallCoordinator_Windows_ApplicationModel_Calls_MuteChangeEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Calls::VoipCallCoordinator*,
                                                                       ABI::Windows::ApplicationModel::Calls::MuteChangeEventArgs*>> {
    void (^_delegate)(WACVoipCallCoordinator*, WACMuteChangeEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Calls_VoipCallCoordinator_Windows_ApplicationModel_Calls_MuteChangeEventArgs(
        void (^del)(WACVoipCallCoordinator*, WACMuteChangeEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Calls_VoipCallCoordinator_Windows_ApplicationModel_Calls_MuteChangeEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Calls::IVoipCallCoordinator* arg0,
                                             ABI::Windows::ApplicationModel::Calls::IMuteChangeEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACVoipCallCoordinator>(arg0), _createRtProxy<WACMuteChangeEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallAnswerEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallAnswerEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallAnswerEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Calls::VoipPhoneCall*,
                                                                       ABI::Windows::ApplicationModel::Calls::CallAnswerEventArgs*>> {
    void (^_delegate)(WACVoipPhoneCall*, WACCallAnswerEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallAnswerEventArgs(
        void (^del)(WACVoipPhoneCall*, WACCallAnswerEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallAnswerEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall* arg0,
                                             ABI::Windows::ApplicationModel::Calls::ICallAnswerEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACVoipPhoneCall>(arg0), _createRtProxy<WACCallAnswerEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallRejectEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallRejectEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallRejectEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Calls::VoipPhoneCall*,
                                                                       ABI::Windows::ApplicationModel::Calls::CallRejectEventArgs*>> {
    void (^_delegate)(WACVoipPhoneCall*, WACCallRejectEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallRejectEventArgs(
        void (^del)(WACVoipPhoneCall*, WACCallRejectEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallRejectEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall* arg0,
                                             ABI::Windows::ApplicationModel::Calls::ICallRejectEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACVoipPhoneCall>(arg0), _createRtProxy<WACCallRejectEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallStateChangeEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallStateChangeEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallStateChangeEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Calls::VoipPhoneCall*,
                                                                       ABI::Windows::ApplicationModel::Calls::CallStateChangeEventArgs*>> {
    void (^_delegate)(WACVoipPhoneCall*, WACCallStateChangeEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallStateChangeEventArgs(
        void (^del)(WACVoipPhoneCall*, WACCallStateChangeEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Calls_VoipPhoneCall_Windows_ApplicationModel_Calls_CallStateChangeEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Calls::IVoipPhoneCall* arg0,
                                             ABI::Windows::ApplicationModel::Calls::ICallStateChangeEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACVoipPhoneCall>(arg0), _createRtProxy<WACCallStateChangeEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
