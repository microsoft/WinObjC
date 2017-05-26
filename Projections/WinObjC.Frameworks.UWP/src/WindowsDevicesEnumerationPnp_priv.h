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

// WindowsDevicesEnumerationPnp_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsDevicesEnumeration_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectStatics> WDEPIPnpObjectStatics_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedNSDictionary_NSString_RTObject;

#ifndef __ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Enumeration::Pnp::PnpObjectWatcher*, IInspectable*>> {
    void (^_delegate)(WDEPPnpObjectWatcher*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_System_Object(void (^del)(WDEPPnpObjectWatcher*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDEPPnpObjectWatcher>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_Windows_Devices_Enumeration_Pnp_PnpObject__DEFINED
#define __ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_Windows_Devices_Enumeration_Pnp_PnpObject__DEFINED
class ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_Windows_Devices_Enumeration_Pnp_PnpObject
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Enumeration::Pnp::PnpObjectWatcher*,
                                                                       ABI::Windows::Devices::Enumeration::Pnp::PnpObject*>> {
    void (^_delegate)(WDEPPnpObjectWatcher*, WDEPPnpObject*);

public:
    ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_Windows_Devices_Enumeration_Pnp_PnpObject(
        void (^del)(WDEPPnpObjectWatcher*, WDEPPnpObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_Windows_Devices_Enumeration_Pnp_PnpObject() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher* arg0,
                                             ABI::Windows::Devices::Enumeration::Pnp::IPnpObject* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDEPPnpObjectWatcher>(arg0), _createRtProxy<WDEPPnpObject>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_Windows_Devices_Enumeration_Pnp_PnpObjectUpdate__DEFINED
#define __ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_Windows_Devices_Enumeration_Pnp_PnpObjectUpdate__DEFINED
class ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_Windows_Devices_Enumeration_Pnp_PnpObjectUpdate
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Enumeration::Pnp::PnpObjectWatcher*,
                                                                       ABI::Windows::Devices::Enumeration::Pnp::PnpObjectUpdate*>> {
    void (^_delegate)(WDEPPnpObjectWatcher*, WDEPPnpObjectUpdate*);

public:
    ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_Windows_Devices_Enumeration_Pnp_PnpObjectUpdate(
        void (^del)(WDEPPnpObjectWatcher*, WDEPPnpObjectUpdate*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Enumeration_Pnp_PnpObjectWatcher_Windows_Devices_Enumeration_Pnp_PnpObjectUpdate() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher* arg0,
                                             ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectUpdate* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDEPPnpObjectWatcher>(arg0), _createRtProxy<WDEPPnpObjectUpdate>(arg1));
            return 0;
        };
    }
};
#endif
