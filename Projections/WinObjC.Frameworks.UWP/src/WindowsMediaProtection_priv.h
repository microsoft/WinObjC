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

// WindowsMediaProtection_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsFoundationCollections_priv.h"
#include "WindowsMediaPlayback_priv.h"
static ComPtr<ABI::Windows::Media::Protection::IMediaProtectionPMPServerFactory> WMPIMediaProtectionPMPServerFactory_inst();
ComPtr<ABI::Windows::Media::Protection::IComponentRenewalStatics> WMPIComponentRenewalStatics_inst();

id RTProxiedNSMutableArray_WMPRevocationAndRenewalItem_create(IInspectable* val);

@class Nullable_WMPHdcpProtection, RTProxiedNSMutableArray_WMPRevocationAndRenewalItem;

#ifndef __ITypedEventHandler_Windows_Media_Protection_HdcpSession_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Protection_HdcpSession_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Protection_HdcpSession_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Protection::HdcpSession*, IInspectable*>> {
    void (^_delegate)(WMPHdcpSession*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Protection_HdcpSession_System_Object(void (^del)(WMPHdcpSession*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Protection_HdcpSession_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Protection::IHdcpSession* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPHdcpSession>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WMPComponentLoadFailedEventHandler_shim__DEFINED
#define __WMPComponentLoadFailedEventHandler_shim__DEFINED
class WMPComponentLoadFailedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Media::Protection::IComponentLoadFailedEventHandler> {
    void (^_delegate)(WMPMediaProtectionManager*, WMPComponentLoadFailedEventArgs*);

public:
    WMPComponentLoadFailedEventHandler_shim(void (^del)(WMPMediaProtectionManager*, WMPComponentLoadFailedEventArgs*))
        : _delegate([del copy]) {
    }
    ~WMPComponentLoadFailedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Protection::IMediaProtectionManager* arg0,
                                             ABI::Windows::Media::Protection::IComponentLoadFailedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaProtectionManager>(arg0), _createRtProxy<WMPComponentLoadFailedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WMPRebootNeededEventHandler_shim__DEFINED
#define __WMPRebootNeededEventHandler_shim__DEFINED
class WMPRebootNeededEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Media::Protection::IRebootNeededEventHandler> {
    void (^_delegate)(WMPMediaProtectionManager*);

public:
    WMPRebootNeededEventHandler_shim(void (^del)(WMPMediaProtectionManager*)) : _delegate([del copy]) {
    }
    ~WMPRebootNeededEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Protection::IMediaProtectionManager* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaProtectionManager>(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WMPServiceRequestedEventHandler_shim__DEFINED
#define __WMPServiceRequestedEventHandler_shim__DEFINED
class WMPServiceRequestedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Media::Protection::IServiceRequestedEventHandler> {
    void (^_delegate)(WMPMediaProtectionManager*, WMPServiceRequestedEventArgs*);

public:
    WMPServiceRequestedEventHandler_shim(void (^del)(WMPMediaProtectionManager*, WMPServiceRequestedEventArgs*)) : _delegate([del copy]) {
    }
    ~WMPServiceRequestedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Protection::IMediaProtectionManager* arg0,
                                             ABI::Windows::Media::Protection::IServiceRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaProtectionManager>(arg0), _createRtProxy<WMPServiceRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
