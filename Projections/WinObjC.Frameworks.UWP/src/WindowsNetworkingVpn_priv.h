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

// WindowsNetworkingVpn_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsSecurityCredentials_priv.h"
#include "WindowsSecurityCryptographyCertificates_priv.h"
#include "WindowsNetworking_priv.h"
#include "WindowsFoundation_priv.h"
static ComPtr<ABI::Windows::Networking::Vpn::IVpnRouteFactory> WNVIVpnRouteFactory_inst();
static ComPtr<ABI::Windows::Networking::Vpn::IVpnNamespaceInfoFactory> WNVIVpnNamespaceInfoFactory_inst();
static ComPtr<ABI::Windows::Networking::Vpn::IVpnInterfaceIdFactory> WNVIVpnInterfaceIdFactory_inst();
static ComPtr<ABI::Windows::Networking::Vpn::IVpnPacketBufferFactory> WNVIVpnPacketBufferFactory_inst();
ComPtr<ABI::Windows::Networking::Vpn::IVpnChannelStatics> WNVIVpnChannelStatics_inst();
static ComPtr<ABI::Windows::Networking::Vpn::IVpnAppIdFactory> WNVIVpnAppIdFactory_inst();
static ComPtr<ABI::Windows::Networking::Vpn::IVpnDomainNameInfoFactory> WNVIVpnDomainNameInfoFactory_inst();
static ComPtr<ABI::Windows::Networking::Vpn::IVpnTrafficFilterFactory> WNVIVpnTrafficFilterFactory_inst();

id RTProxiedIterableNSArray_WNHostName_create(IInspectable* val);
id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_RTObject_WNVIVpnCustomPrompt_create(IInspectable* val);
id RTProxiedNSArray_RTObject_WNVIVpnCustomPromptElement_create(IInspectable* val);
id RTProxiedNSArray_RTObject_WNVIVpnProfile_create(IInspectable* val);
id RTProxiedNSArray_WFUri_create(IInspectable* val);
id RTProxiedNSArray_WNHostName_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WFUri_create(IInspectable* val);
id RTProxiedNSMutableArray_WNHostName_create(IInspectable* val);
id RTProxiedNSMutableArray_WNVVpnAppId_create(IInspectable* val);
id RTProxiedNSMutableArray_WNVVpnDomainNameInfo_create(IInspectable* val);
id RTProxiedNSMutableArray_WNVVpnNamespaceInfo_create(IInspectable* val);
id RTProxiedNSMutableArray_WNVVpnRoute_create(IInspectable* val);
id RTProxiedNSMutableArray_WNVVpnTrafficFilter_create(IInspectable* val);

@class RTProxiedIterableNSArray_WNHostName, RTProxiedNSArray_C_UInt8, RTProxiedNSArray_NSString,
    RTProxiedNSArray_RTObject_WNVIVpnCustomPrompt;
@class RTProxiedNSArray_RTObject_WNVIVpnCustomPromptElement, RTProxiedNSArray_RTObject_WNVIVpnProfile, RTProxiedNSArray_WFUri,
    RTProxiedNSArray_WNHostName;
@class RTProxiedNSMutableArray_NSString, RTProxiedNSMutableArray_WFUri, RTProxiedNSMutableArray_WNHostName,
    RTProxiedNSMutableArray_WNVVpnAppId;
@class RTProxiedNSMutableArray_WNVVpnDomainNameInfo, RTProxiedNSMutableArray_WNVVpnNamespaceInfo, RTProxiedNSMutableArray_WNVVpnRoute;
@class RTProxiedNSMutableArray_WNVVpnTrafficFilter;

#ifndef __ITypedEventHandler_Windows_Networking_Vpn_VpnChannel_Windows_Networking_Vpn_VpnChannelActivityEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Networking_Vpn_VpnChannel_Windows_Networking_Vpn_VpnChannelActivityEventArgs__DEFINED
class ITypedEventHandler_Windows_Networking_Vpn_VpnChannel_Windows_Networking_Vpn_VpnChannelActivityEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Networking::Vpn::VpnChannel*,
                                                                       ABI::Windows::Networking::Vpn::VpnChannelActivityEventArgs*>> {
    void (^_delegate)(WNVVpnChannel*, WNVVpnChannelActivityEventArgs*);

public:
    ITypedEventHandler_Windows_Networking_Vpn_VpnChannel_Windows_Networking_Vpn_VpnChannelActivityEventArgs(
        void (^del)(WNVVpnChannel*, WNVVpnChannelActivityEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_Vpn_VpnChannel_Windows_Networking_Vpn_VpnChannelActivityEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Networking::Vpn::IVpnChannel* arg0,
                                             ABI::Windows::Networking::Vpn::IVpnChannelActivityEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNVVpnChannel>(arg0), _createRtProxy<WNVVpnChannelActivityEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Networking_Vpn_VpnChannel_Windows_Networking_Vpn_VpnChannelActivityStateChangedArgs__DEFINED
#define __ITypedEventHandler_Windows_Networking_Vpn_VpnChannel_Windows_Networking_Vpn_VpnChannelActivityStateChangedArgs__DEFINED
class ITypedEventHandler_Windows_Networking_Vpn_VpnChannel_Windows_Networking_Vpn_VpnChannelActivityStateChangedArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Networking::Vpn::VpnChannel*,
                                                       ABI::Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs*>> {
    void (^_delegate)(WNVVpnChannel*, WNVVpnChannelActivityStateChangedArgs*);

public:
    ITypedEventHandler_Windows_Networking_Vpn_VpnChannel_Windows_Networking_Vpn_VpnChannelActivityStateChangedArgs(
        void (^del)(WNVVpnChannel*, WNVVpnChannelActivityStateChangedArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_Vpn_VpnChannel_Windows_Networking_Vpn_VpnChannelActivityStateChangedArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Networking::Vpn::IVpnChannel* arg0,
                                             ABI::Windows::Networking::Vpn::IVpnChannelActivityStateChangedArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNVVpnChannel>(arg0), _createRtProxy<WNVVpnChannelActivityStateChangedArgs>(arg1));
            return 0;
        };
    }
};
#endif
