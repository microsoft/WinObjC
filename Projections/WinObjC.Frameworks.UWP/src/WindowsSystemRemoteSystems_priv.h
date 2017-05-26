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

// WindowsSystemRemoteSystems_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsNetworking_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemStatics> WSRIRemoteSystemStatics_inst();
static ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemConnectionRequestFactory> WSRIRemoteSystemConnectionRequestFactory_inst();
ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemKindStatics> WSRIRemoteSystemKindStatics_inst();
static ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemKindFilterFactory> WSRIRemoteSystemKindFilterFactory_inst();
static ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilterFactory>
WSRIRemoteSystemDiscoveryTypeFilterFactory_inst();
static ComPtr<ABI::Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilterFactory> WSRIRemoteSystemStatusTypeFilterFactory_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_RTObject_WSRIRemoteSystemFilter_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedIterableNSArray_RTObject_WSRIRemoteSystemFilter, RTProxiedNSArray_NSString;

#ifndef __ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemAddedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemAddedEventArgs__DEFINED
class ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemAddedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::System::RemoteSystems::RemoteSystemWatcher*,
                                                                       ABI::Windows::System::RemoteSystems::RemoteSystemAddedEventArgs*>> {
    void (^_delegate)(WSRRemoteSystemWatcher*, WSRRemoteSystemAddedEventArgs*);

public:
    ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemAddedEventArgs(
        void (^del)(WSRRemoteSystemWatcher*, WSRRemoteSystemAddedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemAddedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher* arg0,
                                             ABI::Windows::System::RemoteSystems::IRemoteSystemAddedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSRRemoteSystemWatcher>(arg0), _createRtProxy<WSRRemoteSystemAddedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemRemovedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemRemovedEventArgs__DEFINED
class ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemRemovedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::System::RemoteSystems::RemoteSystemWatcher*,
                                                       ABI::Windows::System::RemoteSystems::RemoteSystemRemovedEventArgs*>> {
    void (^_delegate)(WSRRemoteSystemWatcher*, WSRRemoteSystemRemovedEventArgs*);

public:
    ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemRemovedEventArgs(
        void (^del)(WSRRemoteSystemWatcher*, WSRRemoteSystemRemovedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemRemovedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher* arg0,
                                             ABI::Windows::System::RemoteSystems::IRemoteSystemRemovedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSRRemoteSystemWatcher>(arg0), _createRtProxy<WSRRemoteSystemRemovedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemUpdatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemUpdatedEventArgs__DEFINED
class ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemUpdatedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::System::RemoteSystems::RemoteSystemWatcher*,
                                                       ABI::Windows::System::RemoteSystems::RemoteSystemUpdatedEventArgs*>> {
    void (^_delegate)(WSRRemoteSystemWatcher*, WSRRemoteSystemUpdatedEventArgs*);

public:
    ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemUpdatedEventArgs(
        void (^del)(WSRRemoteSystemWatcher*, WSRRemoteSystemUpdatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_System_RemoteSystems_RemoteSystemWatcher_Windows_System_RemoteSystems_RemoteSystemUpdatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher* arg0,
                                             ABI::Windows::System::RemoteSystems::IRemoteSystemUpdatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSRRemoteSystemWatcher>(arg0), _createRtProxy<WSRRemoteSystemUpdatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
