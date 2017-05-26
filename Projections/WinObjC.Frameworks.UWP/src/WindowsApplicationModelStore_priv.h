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

// WindowsApplicationModelStore_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsStorage_priv.h"
static ComPtr<ABI::Windows::ApplicationModel::Store::IProductPurchaseDisplayPropertiesFactory>
WSIProductPurchaseDisplayPropertiesFactory_inst();
ComPtr<ABI::Windows::ApplicationModel::Store::ICurrentAppWithCampaignId> WSICurrentAppWithCampaignId_inst();
ComPtr<ABI::Windows::ApplicationModel::Store::ICurrentApp2Statics> WSICurrentApp2Statics_inst();
ComPtr<ABI::Windows::ApplicationModel::Store::ICurrentAppStaticsWithFiltering> WSICurrentAppStaticsWithFiltering_inst();
ComPtr<ABI::Windows::ApplicationModel::Store::ICurrentApp> WSICurrentApp_inst();
ComPtr<ABI::Windows::ApplicationModel::Store::ICurrentAppWithConsumables> WSICurrentAppWithConsumables_inst();
ComPtr<ABI::Windows::ApplicationModel::Store::ICurrentAppSimulatorWithConsumables> WSICurrentAppSimulatorWithConsumables_inst();
ComPtr<ABI::Windows::ApplicationModel::Store::ICurrentAppSimulatorWithCampaignId> WSICurrentAppSimulatorWithCampaignId_inst();
ComPtr<ABI::Windows::ApplicationModel::Store::ICurrentAppSimulator> WSICurrentAppSimulator_inst();
ComPtr<ABI::Windows::ApplicationModel::Store::ICurrentAppSimulatorStaticsWithFiltering> WSICurrentAppSimulatorStaticsWithFiltering_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WSUnfulfilledConsumable_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_WSProductLicense_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_WSProductListing_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedNSArray_WSUnfulfilledConsumable, RTProxiedNSDictionary_NSString_WSProductLicense;
@class RTProxiedNSDictionary_NSString_WSProductListing;

#ifndef __WSLicenseChangedEventHandler_shim__DEFINED
#define __WSLicenseChangedEventHandler_shim__DEFINED
class WSLicenseChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::ApplicationModel::Store::ILicenseChangedEventHandler> {
    void (^_delegate)();

public:
    WSLicenseChangedEventHandler_shim(void (^del)()) : _delegate([del copy]) {
    }
    ~WSLicenseChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke() override {
        @autoreleasepool {
            _delegate();
            return 0;
        };
    }
};
#endif
