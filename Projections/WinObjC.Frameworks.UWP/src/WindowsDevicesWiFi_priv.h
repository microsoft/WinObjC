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

// WindowsDevicesWiFi_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsNetworkingConnectivity_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsSecurityCredentials_priv.h"
ComPtr<ABI::Windows::Devices::WiFi::IWiFiAdapterStatics> WDWIWiFiAdapterStatics_inst();

id RTProxiedNSArray_WDWWiFiAdapter_create(IInspectable* val);
id RTProxiedNSArray_WDWWiFiAvailableNetwork_create(IInspectable* val);

@class RTProxiedNSArray_WDWWiFiAdapter, RTProxiedNSArray_WDWWiFiAvailableNetwork;

#ifndef __ITypedEventHandler_Windows_Devices_WiFi_WiFiAdapter_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_WiFi_WiFiAdapter_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_WiFi_WiFiAdapter_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::WiFi::WiFiAdapter*, IInspectable*>> {
    void (^_delegate)(WDWWiFiAdapter*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_WiFi_WiFiAdapter_System_Object(void (^del)(WDWWiFiAdapter*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_WiFi_WiFiAdapter_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::WiFi::IWiFiAdapter* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDWWiFiAdapter>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
