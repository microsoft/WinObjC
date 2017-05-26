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

// WindowsDevicesWiFiDirect_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsSecurityCredentials_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsDevicesEnumeration_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsNetworking_priv.h"
ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectDeviceStatics2> WDWIWiFiDirectDeviceStatics2_inst();
ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectDeviceStatics> WDWIWiFiDirectDeviceStatics_inst();
ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionParametersStatics> WDWIWiFiDirectConnectionParametersStatics_inst();
ComPtr<ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElementStatics> WDWIWiFiDirectInformationElementStatics_inst();

id RTProxiedNSArray_WNEndpointPair_create(IInspectable* val);
id RTProxiedNSMutableArray_WDWWiFiDirectConfigurationMethod_create(IInspectable* val);
id RTProxiedNSMutableArray_WDWWiFiDirectInformationElement_create(IInspectable* val);

@class RTProxiedNSArray_WNEndpointPair, RTProxiedNSMutableArray_WDWWiFiDirectConfigurationMethod,
    RTProxiedNSMutableArray_WDWWiFiDirectInformationElement;

#ifndef __ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectAdvertisementPublisher_Windows_Devices_WiFiDirect_WiFiDirectAdvertisementPublisherStatusChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectAdvertisementPublisher_Windows_Devices_WiFiDirect_WiFiDirectAdvertisementPublisherStatusChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectAdvertisementPublisher_Windows_Devices_WiFiDirect_WiFiDirectAdvertisementPublisherStatusChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisher*,
                              ABI::Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatusChangedEventArgs*>> {
    void (^_delegate)(WDWWiFiDirectAdvertisementPublisher*, WDWWiFiDirectAdvertisementPublisherStatusChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectAdvertisementPublisher_Windows_Devices_WiFiDirect_WiFiDirectAdvertisementPublisherStatusChangedEventArgs(
        void (^del)(WDWWiFiDirectAdvertisementPublisher*, WDWWiFiDirectAdvertisementPublisherStatusChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectAdvertisementPublisher_Windows_Devices_WiFiDirect_WiFiDirectAdvertisementPublisherStatusChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher* arg0,
           ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDWWiFiDirectAdvertisementPublisher>(arg0),
                      _createRtProxy<WDWWiFiDirectAdvertisementPublisherStatusChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectConnectionListener_Windows_Devices_WiFiDirect_WiFiDirectConnectionRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectConnectionListener_Windows_Devices_WiFiDirect_WiFiDirectConnectionRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectConnectionListener_Windows_Devices_WiFiDirect_WiFiDirectConnectionRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::WiFiDirect::WiFiDirectConnectionListener*,
                                                       ABI::Windows::Devices::WiFiDirect::WiFiDirectConnectionRequestedEventArgs*>> {
    void (^_delegate)(WDWWiFiDirectConnectionListener*, WDWWiFiDirectConnectionRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectConnectionListener_Windows_Devices_WiFiDirect_WiFiDirectConnectionRequestedEventArgs(
        void (^del)(WDWWiFiDirectConnectionListener*, WDWWiFiDirectConnectionRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectConnectionListener_Windows_Devices_WiFiDirect_WiFiDirectConnectionRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionListener* arg0,
                                             ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDWWiFiDirectConnectionListener>(arg0),
                      _createRtProxy<WDWWiFiDirectConnectionRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectDevice_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectDevice_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectDevice_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::WiFiDirect::WiFiDirectDevice*, IInspectable*>> {
    void (^_delegate)(WDWWiFiDirectDevice*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectDevice_System_Object(void (^del)(WDWWiFiDirectDevice*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_WiFiDirect_WiFiDirectDevice_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::WiFiDirect::IWiFiDirectDevice* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDWWiFiDirectDevice>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
