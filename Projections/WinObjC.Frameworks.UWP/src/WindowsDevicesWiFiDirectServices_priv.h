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

// WindowsDevicesWiFiDirectServices_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsNetworkingSockets_priv.h"
#include "WindowsNetworking_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsDevicesEnumeration_priv.h"
static ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiserFactory>
WDWSIWiFiDirectServiceAdvertiserFactory_inst();
ComPtr<ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceStatics> WDWSIWiFiDirectServiceStatics_inst();

id RTProxiedNSArray_WDWSWiFiDirectServiceConfigurationMethod_create(IInspectable* val);
id RTProxiedNSArray_WNEndpointPair_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WDWSWiFiDirectServiceConfigurationMethod_create(IInspectable* val);

@class RTProxiedNSArray_WDWSWiFiDirectServiceConfigurationMethod, RTProxiedNSArray_WNEndpointPair, RTProxiedNSMutableArray_NSString;
@class RTProxiedNSMutableArray_WDWSWiFiDirectServiceConfigurationMethod;

#ifndef __ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser*,
                                                       IInspectable*>> {
    void (^_delegate)(WDWSWiFiDirectServiceAdvertiser*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_System_Object(
        void (^del)(WDWSWiFiDirectServiceAdvertiser*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDWSWiFiDirectServiceAdvertiser>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAutoAcceptSessionConnectedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAutoAcceptSessionConnectedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAutoAcceptSessionConnectedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser*,
                              ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAutoAcceptSessionConnectedEventArgs*>> {
    void (^_delegate)(WDWSWiFiDirectServiceAdvertiser*, WDWSWiFiDirectServiceAutoAcceptSessionConnectedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAutoAcceptSessionConnectedEventArgs(
        void (^del)(WDWSWiFiDirectServiceAdvertiser*, WDWSWiFiDirectServiceAutoAcceptSessionConnectedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAutoAcceptSessionConnectedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser* arg0,
           ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDWSWiFiDirectServiceAdvertiser>(arg0),
                      _createRtProxy<WDWSWiFiDirectServiceAutoAcceptSessionConnectedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSessionRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSessionRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSessionRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser*,
                              ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequestedEventArgs*>> {
    void (^_delegate)(WDWSWiFiDirectServiceAdvertiser*, WDWSWiFiDirectServiceSessionRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSessionRequestedEventArgs(
        void (^del)(WDWSWiFiDirectServiceAdvertiser*, WDWSWiFiDirectServiceSessionRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceAdvertiser_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSessionRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser* arg0,
           ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDWSWiFiDirectServiceAdvertiser>(arg0),
                      _createRtProxy<WDWSWiFiDirectServiceSessionRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSession_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSession_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSession_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::
                              ITypedEventHandler<ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession*, IInspectable*>> {
    void (^_delegate)(WDWSWiFiDirectServiceSession*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSession_System_Object(void (^del)(WDWSWiFiDirectServiceSession*,
                                                                                                              RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSession_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDWSWiFiDirectServiceSession>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSession_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceRemotePortAddedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSession_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceRemotePortAddedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSession_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceRemotePortAddedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession*,
                              ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceRemotePortAddedEventArgs*>> {
    void (^_delegate)(WDWSWiFiDirectServiceSession*, WDWSWiFiDirectServiceRemotePortAddedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSession_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceRemotePortAddedEventArgs(
        void (^del)(WDWSWiFiDirectServiceSession*, WDWSWiFiDirectServiceRemotePortAddedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSession_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceRemotePortAddedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession* arg0,
           ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceRemotePortAddedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDWSWiFiDirectServiceSession>(arg0),
                      _createRtProxy<WDWSWiFiDirectServiceRemotePortAddedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectService_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSessionDeferredEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectService_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSessionDeferredEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectService_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSessionDeferredEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectService*,
                              ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionDeferredEventArgs*>> {
    void (^_delegate)(WDWSWiFiDirectService*, WDWSWiFiDirectServiceSessionDeferredEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectService_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSessionDeferredEventArgs(
        void (^del)(WDWSWiFiDirectService*, WDWSWiFiDirectServiceSessionDeferredEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_WiFiDirect_Services_WiFiDirectService_Windows_Devices_WiFiDirect_Services_WiFiDirectServiceSessionDeferredEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService* arg0,
           ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionDeferredEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDWSWiFiDirectService>(arg0), _createRtProxy<WDWSWiFiDirectServiceSessionDeferredEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
