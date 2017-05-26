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

// WindowsGamingPreviewGamesEnumeration_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsApplicationModel_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics> WGPGIGameListStatics_inst();

id RTProxiedNSArray_WGPGGameListEntry_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);

@class RTProxiedNSArray_WGPGGameListEntry, RTProxiedNSDictionary_NSString_RTObject;

#ifndef __WGPGGameListChangedEventHandler_shim__DEFINED
#define __WGPGGameListChangedEventHandler_shim__DEFINED
class WGPGGameListChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListChangedEventHandler> {
    void (^_delegate)(WGPGGameListEntry*);

public:
    WGPGGameListChangedEventHandler_shim(void (^del)(WGPGGameListEntry*)) : _delegate([del copy]) {
    }
    ~WGPGGameListChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGPGGameListEntry>(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WGPGGameListRemovedEventHandler_shim__DEFINED
#define __WGPGGameListRemovedEventHandler_shim__DEFINED
class WGPGGameListRemovedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Gaming::Preview::GamesEnumeration::IGameListRemovedEventHandler> {
    void (^_delegate)(NSString*);

public:
    WGPGGameListRemovedEventHandler_shim(void (^del)(NSString*)) : _delegate([del copy]) {
    }
    ~WGPGGameListRemovedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(HSTRING arg0) override {
        @autoreleasepool {
            _delegate(hstrToNSStr(arg0));
            return 0;
        };
    }
};
#endif
