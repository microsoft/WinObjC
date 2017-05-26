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

// WindowsDevicesAllJoyn_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsNetworkingSockets_priv.h"
#include "WindowsSecurityCryptographyCertificates_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsGlobalization_priv.h"
#include "WindowsDevicesEnumeration_priv.h"
#include "WindowsSecurityCredentials_priv.h"
ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynStatusStatics> WDAIAllJoynStatusStatics_inst();
static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachmentFactory> WDAIAllJoynBusAttachmentFactory_inst();
ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachmentStatics> WDAIAllJoynBusAttachmentStatics_inst();
static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoFactory> WDAIAllJoynServiceInfoFactory_inst();
ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoStatics> WDAIAllJoynServiceInfoStatics_inst();
ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataViewStatics> WDAIAllJoynAboutDataViewStatics_inst();
static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgsFactory>
WDAIAllJoynAcceptSessionJoinerEventArgsFactory_inst();
static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionJoinedEventArgsFactory> WDAIAllJoynSessionJoinedEventArgsFactory_inst();
ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionStatics> WDAIAllJoynSessionStatics_inst();
static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgsFactory>
WDAIAllJoynSessionMemberAddedEventArgsFactory_inst();
static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgsFactory>
WDAIAllJoynSessionMemberRemovedEventArgsFactory_inst();
static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynSessionLostEventArgsFactory> WDAIAllJoynSessionLostEventArgsFactory_inst();
static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusObjectFactory> WDAIAllJoynBusObjectFactory_inst();
static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgsFactory> WDAIAllJoynBusObjectStoppedEventArgsFactory_inst();
static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynProducerStoppedEventArgsFactory> WDAIAllJoynProducerStoppedEventArgsFactory_inst();
static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgsFactory> WDAIAllJoynWatcherStoppedEventArgsFactory_inst();
static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgsFactory>
WDAIAllJoynServiceInfoRemovedEventArgsFactory_inst();
static ComPtr<ABI::Windows::Devices::AllJoyn::IAllJoynMessageInfoFactory> WDAIAllJoynMessageInfoFactory_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WGLanguage_create(IInspectable* val);
id RTProxiedNSArray_WSCCCertificate_create(IInspectable* val);
id RTProxiedNSArray_WSCCChainValidationResult_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);
id RTProxiedNSMutableArray_WDAAllJoynAuthenticationMechanism_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val);

@class Nullable_WFDateTime, RTProxiedIterableNSArray_NSString, RTProxiedNSArray_WGLanguage, RTProxiedNSArray_WSCCCertificate,
    RTProxiedNSArray_WSCCChainValidationResult;
@class RTProxiedNSDictionary_NSString_RTObject, RTProxiedNSMutableArray_WDAAllJoynAuthenticationMechanism,
    RTProxiedNSMutableDictionary_NSString_NSString;

#ifndef __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynAcceptSessionJoinerEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynAcceptSessionJoinerEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynAcceptSessionJoinerEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::AllJoyn::AllJoynBusAttachment*,
                                                       ABI::Windows::Devices::AllJoyn::AllJoynAcceptSessionJoinerEventArgs*>> {
    void (^_delegate)(WDAAllJoynBusAttachment*, WDAAllJoynAcceptSessionJoinerEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynAcceptSessionJoinerEventArgs(
        void (^del)(WDAAllJoynBusAttachment*, WDAAllJoynAcceptSessionJoinerEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynAcceptSessionJoinerEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment* arg0,
                                             ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDAAllJoynBusAttachment>(arg0), _createRtProxy<WDAAllJoynAcceptSessionJoinerEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynAuthenticationCompleteEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynAuthenticationCompleteEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynAuthenticationCompleteEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::AllJoyn::AllJoynBusAttachment*,
                                                       ABI::Windows::Devices::AllJoyn::AllJoynAuthenticationCompleteEventArgs*>> {
    void (^_delegate)(WDAAllJoynBusAttachment*, WDAAllJoynAuthenticationCompleteEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynAuthenticationCompleteEventArgs(
        void (^del)(WDAAllJoynBusAttachment*, WDAAllJoynAuthenticationCompleteEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynAuthenticationCompleteEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment* arg0,
                                             ABI::Windows::Devices::AllJoyn::IAllJoynAuthenticationCompleteEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDAAllJoynBusAttachment>(arg0), _createRtProxy<WDAAllJoynAuthenticationCompleteEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynBusAttachmentStateChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynBusAttachmentStateChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynBusAttachmentStateChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::AllJoyn::AllJoynBusAttachment*,
                                                       ABI::Windows::Devices::AllJoyn::AllJoynBusAttachmentStateChangedEventArgs*>> {
    void (^_delegate)(WDAAllJoynBusAttachment*, WDAAllJoynBusAttachmentStateChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynBusAttachmentStateChangedEventArgs(
        void (^del)(WDAAllJoynBusAttachment*, WDAAllJoynBusAttachmentStateChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynBusAttachmentStateChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment* arg0,
                                             ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachmentStateChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDAAllJoynBusAttachment>(arg0), _createRtProxy<WDAAllJoynBusAttachmentStateChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynCredentialsRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynCredentialsRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynCredentialsRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::AllJoyn::AllJoynBusAttachment*,
                                                       ABI::Windows::Devices::AllJoyn::AllJoynCredentialsRequestedEventArgs*>> {
    void (^_delegate)(WDAAllJoynBusAttachment*, WDAAllJoynCredentialsRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynCredentialsRequestedEventArgs(
        void (^del)(WDAAllJoynBusAttachment*, WDAAllJoynCredentialsRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynCredentialsRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment* arg0,
                                             ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDAAllJoynBusAttachment>(arg0), _createRtProxy<WDAAllJoynCredentialsRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynCredentialsVerificationRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynCredentialsVerificationRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynCredentialsVerificationRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::AllJoyn::AllJoynBusAttachment*,
                                                       ABI::Windows::Devices::AllJoyn::AllJoynCredentialsVerificationRequestedEventArgs*>> {
    void (^_delegate)(WDAAllJoynBusAttachment*, WDAAllJoynCredentialsVerificationRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynCredentialsVerificationRequestedEventArgs(
        void (^del)(WDAAllJoynBusAttachment*, WDAAllJoynCredentialsVerificationRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynCredentialsVerificationRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment* arg0,
           ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDAAllJoynBusAttachment>(arg0),
                      _createRtProxy<WDAAllJoynCredentialsVerificationRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynSessionJoinedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynSessionJoinedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynSessionJoinedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::AllJoyn::AllJoynBusAttachment*,
                                                                       ABI::Windows::Devices::AllJoyn::AllJoynSessionJoinedEventArgs*>> {
    void (^_delegate)(WDAAllJoynBusAttachment*, WDAAllJoynSessionJoinedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynSessionJoinedEventArgs(
        void (^del)(WDAAllJoynBusAttachment*, WDAAllJoynSessionJoinedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusAttachment_Windows_Devices_AllJoyn_AllJoynSessionJoinedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment* arg0,
                                             ABI::Windows::Devices::AllJoyn::IAllJoynSessionJoinedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDAAllJoynBusAttachment>(arg0), _createRtProxy<WDAAllJoynSessionJoinedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusObject_Windows_Devices_AllJoyn_AllJoynBusObjectStoppedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusObject_Windows_Devices_AllJoyn_AllJoynBusObjectStoppedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusObject_Windows_Devices_AllJoyn_AllJoynBusObjectStoppedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::AllJoyn::AllJoynBusObject*,
                                                                       ABI::Windows::Devices::AllJoyn::AllJoynBusObjectStoppedEventArgs*>> {
    void (^_delegate)(WDAAllJoynBusObject*, WDAAllJoynBusObjectStoppedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusObject_Windows_Devices_AllJoyn_AllJoynBusObjectStoppedEventArgs(
        void (^del)(WDAAllJoynBusObject*, WDAAllJoynBusObjectStoppedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynBusObject_Windows_Devices_AllJoyn_AllJoynBusObjectStoppedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::AllJoyn::IAllJoynBusObject* arg0,
                                             ABI::Windows::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDAAllJoynBusObject>(arg0), _createRtProxy<WDAAllJoynBusObjectStoppedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionLostEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionLostEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionLostEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::AllJoyn::AllJoynSession*,
                                                                       ABI::Windows::Devices::AllJoyn::AllJoynSessionLostEventArgs*>> {
    void (^_delegate)(WDAAllJoynSession*, WDAAllJoynSessionLostEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionLostEventArgs(
        void (^del)(WDAAllJoynSession*, WDAAllJoynSessionLostEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionLostEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::AllJoyn::IAllJoynSession* arg0,
                                             ABI::Windows::Devices::AllJoyn::IAllJoynSessionLostEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDAAllJoynSession>(arg0), _createRtProxy<WDAAllJoynSessionLostEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionMemberAddedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionMemberAddedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionMemberAddedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::AllJoyn::AllJoynSession*,
                                                       ABI::Windows::Devices::AllJoyn::AllJoynSessionMemberAddedEventArgs*>> {
    void (^_delegate)(WDAAllJoynSession*, WDAAllJoynSessionMemberAddedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionMemberAddedEventArgs(
        void (^del)(WDAAllJoynSession*, WDAAllJoynSessionMemberAddedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionMemberAddedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::AllJoyn::IAllJoynSession* arg0,
                                             ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDAAllJoynSession>(arg0), _createRtProxy<WDAAllJoynSessionMemberAddedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionMemberRemovedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionMemberRemovedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionMemberRemovedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::AllJoyn::AllJoynSession*,
                                                       ABI::Windows::Devices::AllJoyn::AllJoynSessionMemberRemovedEventArgs*>> {
    void (^_delegate)(WDAAllJoynSession*, WDAAllJoynSessionMemberRemovedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionMemberRemovedEventArgs(
        void (^del)(WDAAllJoynSession*, WDAAllJoynSessionMemberRemovedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_AllJoyn_AllJoynSession_Windows_Devices_AllJoyn_AllJoynSessionMemberRemovedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::AllJoyn::IAllJoynSession* arg0,
                                             ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDAAllJoynSession>(arg0), _createRtProxy<WDAAllJoynSessionMemberRemovedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
