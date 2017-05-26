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

// WindowsNetworkingConnectivity_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsNetworking_priv.h"
static ComPtr<ABI::Windows::Networking::Connectivity::IRoutePolicyFactory> WNCIRoutePolicyFactory_inst();
ComPtr<ABI::Windows::Networking::Connectivity::INetworkInformationStatics2> WNCINetworkInformationStatics2_inst();
ComPtr<ABI::Windows::Networking::Connectivity::INetworkInformationStatics> WNCINetworkInformationStatics_inst();
ComPtr<ABI::Windows::Networking::Connectivity::IConnectivityManagerStatics> WNCIConnectivityManagerStatics_inst();
@interface WNCNetworkUsageStates (Internal)
+ (instancetype)createWith:(ABI::Windows::Networking::Connectivity::NetworkUsageStates)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Networking::Connectivity::NetworkUsageStates*)internalStruct;
@end
inline WNCNetworkUsageStates* WNCNetworkUsageStates_create(ABI::Windows::Networking::Connectivity::NetworkUsageStates val) {
    return [WNCNetworkUsageStates createWith:val];
}

id RTProxiedIterableNSArray_WNEndpointPair_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_UInt8_create(IInspectable* val);
id RTProxiedNSArray_WFUri_create(IInspectable* val);
id RTProxiedNSArray_WNCAttributedNetworkUsage_create(IInspectable* val);
id RTProxiedNSArray_WNCConnectionProfile_create(IInspectable* val);
id RTProxiedNSArray_WNCConnectivityInterval_create(IInspectable* val);
id RTProxiedNSArray_WNCLanIdentifier_create(IInspectable* val);
id RTProxiedNSArray_WNCNetworkUsage_create(IInspectable* val);
id RTProxiedNSArray_WNEndpointPair_create(IInspectable* val);
id RTProxiedNSArray_WNHostName_create(IInspectable* val);

@class Nullable_Boolean, Nullable_UInt32, Nullable_UInt64, Nullable_UInt8, Nullable_WFDateTime, Nullable_WFGUID,
    RTProxiedIterableNSArray_WNEndpointPair;
@class RTProxiedNSArray_NSString, RTProxiedNSArray_UInt8, RTProxiedNSArray_WFUri, RTProxiedNSArray_WNCAttributedNetworkUsage,
    RTProxiedNSArray_WNCConnectionProfile;
@class RTProxiedNSArray_WNCConnectivityInterval, RTProxiedNSArray_WNCLanIdentifier, RTProxiedNSArray_WNCNetworkUsage,
    RTProxiedNSArray_WNEndpointPair;
@class RTProxiedNSArray_WNHostName;

#ifndef __WNCNetworkStatusChangedEventHandler_shim__DEFINED
#define __WNCNetworkStatusChangedEventHandler_shim__DEFINED
class WNCNetworkStatusChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Networking::Connectivity::INetworkStatusChangedEventHandler> {
    void (^_delegate)(RTObject*);

public:
    WNCNetworkStatusChangedEventHandler_shim(void (^del)(RTObject*)) : _delegate([del copy]) {
    }
    ~WNCNetworkStatusChangedEventHandler_shim() {
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
