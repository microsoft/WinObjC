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

// WindowsNetworkingNetworkOperators_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsNetworkingConnectivity_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsDevicesSms_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsNetworking_priv.h"
#include "WindowsDataXmlDom_priv.h"
ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountStatics> WNNIMobileBroadbandAccountStatics_inst();
ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics3>
WNNINetworkOperatorTetheringManagerStatics3_inst();
ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics2>
WNNINetworkOperatorTetheringManagerStatics2_inst();
ComPtr<ABI::Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics>
WNNINetworkOperatorTetheringManagerStatics_inst();
ComPtr<ABI::Windows::Networking::NetworkOperators::IMobileBroadbandModemStatics> WNNIMobileBroadbandModemStatics_inst();
ComPtr<ABI::Windows::Networking::NetworkOperators::IKnownCSimFilePathsStatics> WNNIKnownCSimFilePathsStatics_inst();
ComPtr<ABI::Windows::Networking::NetworkOperators::IKnownRuimFilePathsStatics> WNNIKnownRuimFilePathsStatics_inst();
ComPtr<ABI::Windows::Networking::NetworkOperators::IKnownSimFilePathsStatics> WNNIKnownSimFilePathsStatics_inst();
ComPtr<ABI::Windows::Networking::NetworkOperators::IKnownUSimFilePathsStatics> WNNIKnownUSimFilePathsStatics_inst();
ComPtr<ABI::Windows::Networking::NetworkOperators::IHotspotAuthenticationContextStatics> WNNIHotspotAuthenticationContextStatics_inst();
ComPtr<ABI::Windows::Networking::NetworkOperators::IProvisioningAgentStaticMethods> WNNIProvisioningAgentStaticMethods_inst();
static ComPtr<ABI::Windows::Networking::NetworkOperators::IUssdMessageFactory> WNNIUssdMessageFactory_inst();
ComPtr<ABI::Windows::Networking::NetworkOperators::IUssdSessionStatics> WNNIUssdSessionStatics_inst();
ComPtr<ABI::Windows::Networking::NetworkOperators::IFdnAccessManagerStatics> WNNIFdnAccessManagerStatics_inst();
@interface WNNProfileUsage (Internal)
+ (instancetype)createWith:(ABI::Windows::Networking::NetworkOperators::ProfileUsage)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Networking::NetworkOperators::ProfileUsage*)internalStruct;
@end
inline WNNProfileUsage* WNNProfileUsage_create(ABI::Windows::Networking::NetworkOperators::ProfileUsage val) {
    return [WNNProfileUsage createWith:val];
}

id RTProxiedIterableNSArray_UInt32_create(IInspectable* val);
id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_UInt32_create(IInspectable* val);
id RTProxiedNSArray_WNCConnectionProfile_create(IInspectable* val);
id RTProxiedNSArray_WNHostName_create(IInspectable* val);
id RTProxiedNSArray_WNNMobileBroadbandDeviceServiceInformation_create(IInspectable* val);
id RTProxiedNSArray_WNNMobileBroadbandNetworkRegistrationStateChange_create(IInspectable* val);
id RTProxiedNSArray_WNNMobileBroadbandPinLockStateChange_create(IInspectable* val);
id RTProxiedNSArray_WNNMobileBroadbandPinType_create(IInspectable* val);
id RTProxiedNSArray_WNNMobileBroadbandRadioStateChange_create(IInspectable* val);
id RTProxiedNSArray_WNNMobileBroadbandUiccApp_create(IInspectable* val);
id RTProxiedNSArray_WNNNetworkOperatorTetheringClient_create(IInspectable* val);

@class RTProxiedIterableNSArray_UInt32, RTProxiedNSArray_C_UInt8, RTProxiedNSArray_NSString, RTProxiedNSArray_UInt32,
    RTProxiedNSArray_WNCConnectionProfile;
@class RTProxiedNSArray_WNHostName, RTProxiedNSArray_WNNMobileBroadbandDeviceServiceInformation,
    RTProxiedNSArray_WNNMobileBroadbandNetworkRegistrationStateChange;
@class RTProxiedNSArray_WNNMobileBroadbandPinLockStateChange, RTProxiedNSArray_WNNMobileBroadbandPinType,
    RTProxiedNSArray_WNNMobileBroadbandRadioStateChange;
@class RTProxiedNSArray_WNNMobileBroadbandUiccApp, RTProxiedNSArray_WNNNetworkOperatorTetheringClient;

#ifndef __ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_System_Object__DEFINED
class ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher*,
                                                       IInspectable*>> {
    void (^_delegate)(WNNMobileBroadbandAccountWatcher*, RTObject*);

public:
    ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_System_Object(
        void (^del)(WNNMobileBroadbandAccountWatcher*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNNMobileBroadbandAccountWatcher>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_Windows_Networking_NetworkOperators_MobileBroadbandAccountEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_Windows_Networking_NetworkOperators_MobileBroadbandAccountEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_Windows_Networking_NetworkOperators_MobileBroadbandAccountEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher*,
                                                       ABI::Windows::Networking::NetworkOperators::MobileBroadbandAccountEventArgs*>> {
    void (^_delegate)(WNNMobileBroadbandAccountWatcher*, WNNMobileBroadbandAccountEventArgs*);

public:
    ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_Windows_Networking_NetworkOperators_MobileBroadbandAccountEventArgs(
        void (^del)(WNNMobileBroadbandAccountWatcher*, WNNMobileBroadbandAccountEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_Windows_Networking_NetworkOperators_MobileBroadbandAccountEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher* arg0,
                                             ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNNMobileBroadbandAccountWatcher>(arg0), _createRtProxy<WNNMobileBroadbandAccountEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_Windows_Networking_NetworkOperators_MobileBroadbandAccountUpdatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_Windows_Networking_NetworkOperators_MobileBroadbandAccountUpdatedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_Windows_Networking_NetworkOperators_MobileBroadbandAccountUpdatedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher*,
                              ABI::Windows::Networking::NetworkOperators::MobileBroadbandAccountUpdatedEventArgs*>> {
    void (^_delegate)(WNNMobileBroadbandAccountWatcher*, WNNMobileBroadbandAccountUpdatedEventArgs*);

public:
    ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_Windows_Networking_NetworkOperators_MobileBroadbandAccountUpdatedEventArgs(
        void (^del)(WNNMobileBroadbandAccountWatcher*, WNNMobileBroadbandAccountUpdatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandAccountWatcher_Windows_Networking_NetworkOperators_MobileBroadbandAccountUpdatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher* arg0,
           ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNNMobileBroadbandAccountWatcher>(arg0),
                      _createRtProxy<WNNMobileBroadbandAccountUpdatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandDeviceServiceDataSession_Windows_Networking_NetworkOperators_MobileBroadbandDeviceServiceDataReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandDeviceServiceDataSession_Windows_Networking_NetworkOperators_MobileBroadbandDeviceServiceDataReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandDeviceServiceDataSession_Windows_Networking_NetworkOperators_MobileBroadbandDeviceServiceDataReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataSession*,
                              ABI::Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataReceivedEventArgs*>> {
    void (^_delegate)(WNNMobileBroadbandDeviceServiceDataSession*, WNNMobileBroadbandDeviceServiceDataReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandDeviceServiceDataSession_Windows_Networking_NetworkOperators_MobileBroadbandDeviceServiceDataReceivedEventArgs(
        void (^del)(WNNMobileBroadbandDeviceServiceDataSession*, WNNMobileBroadbandDeviceServiceDataReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_NetworkOperators_MobileBroadbandDeviceServiceDataSession_Windows_Networking_NetworkOperators_MobileBroadbandDeviceServiceDataReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession* arg0,
           ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNNMobileBroadbandDeviceServiceDataSession>(arg0),
                      _createRtProxy<WNNMobileBroadbandDeviceServiceDataReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
