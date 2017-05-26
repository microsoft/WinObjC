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

// WindowsNetworkingProximity_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsNetworking_priv.h"
#include "WindowsNetworkingSockets_priv.h"
ComPtr<ABI::Windows::Networking::Proximity::IProximityDeviceStatics> WNPIProximityDeviceStatics_inst();
ComPtr<ABI::Windows::Networking::Proximity::IPeerFinderStatics2> WNPIPeerFinderStatics2_inst();
ComPtr<ABI::Windows::Networking::Proximity::IPeerFinderStatics> WNPIPeerFinderStatics_inst();

id RTProxiedNSArray_WNPPeerInformation_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val);

@class RTProxiedNSArray_WNPPeerInformation, RTProxiedNSMutableDictionary_NSString_NSString;

#ifndef __ITypedEventHandler_System_Object_Windows_Networking_Proximity_ConnectionRequestedEventArgs__DEFINED
#define __ITypedEventHandler_System_Object_Windows_Networking_Proximity_ConnectionRequestedEventArgs__DEFINED
class ITypedEventHandler_System_Object_Windows_Networking_Proximity_ConnectionRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<IInspectable*, ABI::Windows::Networking::Proximity::ConnectionRequestedEventArgs*>> {
    void (^_delegate)(RTObject*, WNPConnectionRequestedEventArgs*);

public:
    ITypedEventHandler_System_Object_Windows_Networking_Proximity_ConnectionRequestedEventArgs(
        void (^del)(RTObject*, WNPConnectionRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_System_Object_Windows_Networking_Proximity_ConnectionRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::Networking::Proximity::IConnectionRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WNPConnectionRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_System_Object_Windows_Networking_Proximity_TriggeredConnectionStateChangedEventArgs__DEFINED
#define __ITypedEventHandler_System_Object_Windows_Networking_Proximity_TriggeredConnectionStateChangedEventArgs__DEFINED
class ITypedEventHandler_System_Object_Windows_Networking_Proximity_TriggeredConnectionStateChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<IInspectable*,
                                                       ABI::Windows::Networking::Proximity::TriggeredConnectionStateChangedEventArgs*>> {
    void (^_delegate)(RTObject*, WNPTriggeredConnectionStateChangedEventArgs*);

public:
    ITypedEventHandler_System_Object_Windows_Networking_Proximity_TriggeredConnectionStateChangedEventArgs(
        void (^del)(RTObject*, WNPTriggeredConnectionStateChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_System_Object_Windows_Networking_Proximity_TriggeredConnectionStateChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(IInspectable* arg0, ABI::Windows::Networking::Proximity::ITriggeredConnectionStateChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WNPTriggeredConnectionStateChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_System_Object__DEFINED
class ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Networking::Proximity::PeerWatcher*, IInspectable*>> {
    void (^_delegate)(WNPPeerWatcher*, RTObject*);

public:
    ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_System_Object(void (^del)(WNPPeerWatcher*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Networking::Proximity::IPeerWatcher* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNPPeerWatcher>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_Windows_Networking_Proximity_PeerInformation__DEFINED
#define __ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_Windows_Networking_Proximity_PeerInformation__DEFINED
class ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_Windows_Networking_Proximity_PeerInformation
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Networking::Proximity::PeerWatcher*,
                                                                       ABI::Windows::Networking::Proximity::PeerInformation*>> {
    void (^_delegate)(WNPPeerWatcher*, WNPPeerInformation*);

public:
    ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_Windows_Networking_Proximity_PeerInformation(
        void (^del)(WNPPeerWatcher*, WNPPeerInformation*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_Proximity_PeerWatcher_Windows_Networking_Proximity_PeerInformation() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Networking::Proximity::IPeerWatcher* arg0,
                                             ABI::Windows::Networking::Proximity::IPeerInformation* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNPPeerWatcher>(arg0), _createRtProxy<WNPPeerInformation>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WNPDeviceArrivedEventHandler_shim__DEFINED
#define __WNPDeviceArrivedEventHandler_shim__DEFINED
class WNPDeviceArrivedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Networking::Proximity::IDeviceArrivedEventHandler> {
    void (^_delegate)(WNPProximityDevice*);

public:
    WNPDeviceArrivedEventHandler_shim(void (^del)(WNPProximityDevice*)) : _delegate([del copy]) {
    }
    ~WNPDeviceArrivedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Networking::Proximity::IProximityDevice* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNPProximityDevice>(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WNPDeviceDepartedEventHandler_shim__DEFINED
#define __WNPDeviceDepartedEventHandler_shim__DEFINED
class WNPDeviceDepartedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Networking::Proximity::IDeviceDepartedEventHandler> {
    void (^_delegate)(WNPProximityDevice*);

public:
    WNPDeviceDepartedEventHandler_shim(void (^del)(WNPProximityDevice*)) : _delegate([del copy]) {
    }
    ~WNPDeviceDepartedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Networking::Proximity::IProximityDevice* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNPProximityDevice>(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WNPMessageReceivedHandler_shim__DEFINED
#define __WNPMessageReceivedHandler_shim__DEFINED
class WNPMessageReceivedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Networking::Proximity::IMessageReceivedHandler> {
    void (^_delegate)(WNPProximityDevice*, WNPProximityMessage*);

public:
    WNPMessageReceivedHandler_shim(void (^del)(WNPProximityDevice*, WNPProximityMessage*)) : _delegate([del copy]) {
    }
    ~WNPMessageReceivedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Networking::Proximity::IProximityDevice* arg0,
                                             ABI::Windows::Networking::Proximity::IProximityMessage* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNPProximityDevice>(arg0), _createRtProxy<WNPProximityMessage>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WNPMessageTransmittedHandler_shim__DEFINED
#define __WNPMessageTransmittedHandler_shim__DEFINED
class WNPMessageTransmittedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Networking::Proximity::IMessageTransmittedHandler> {
    void (^_delegate)(WNPProximityDevice*, int64_t);

public:
    WNPMessageTransmittedHandler_shim(void (^del)(WNPProximityDevice*, int64_t)) : _delegate([del copy]) {
    }
    ~WNPMessageTransmittedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Networking::Proximity::IProximityDevice* arg0, int64_t arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNPProximityDevice>(arg0), arg1);
            return 0;
        };
    }
};
#endif
