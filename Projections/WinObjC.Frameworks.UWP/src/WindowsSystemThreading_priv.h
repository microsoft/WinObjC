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

// WindowsSystemThreading_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::System::Threading::IThreadPoolTimerStatics> WSTIThreadPoolTimerStatics_inst();
ComPtr<ABI::Windows::System::Threading::IThreadPoolStatics> WSTIThreadPoolStatics_inst();

#ifndef __WSTTimerDestroyedHandler_shim__DEFINED
#define __WSTTimerDestroyedHandler_shim__DEFINED
class WSTTimerDestroyedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::System::Threading::ITimerDestroyedHandler> {
    void (^_delegate)(WSTThreadPoolTimer*);

public:
    WSTTimerDestroyedHandler_shim(void (^del)(WSTThreadPoolTimer*)) : _delegate([del copy]) {
    }
    ~WSTTimerDestroyedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::System::Threading::IThreadPoolTimer* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSTThreadPoolTimer>(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WSTTimerElapsedHandler_shim__DEFINED
#define __WSTTimerElapsedHandler_shim__DEFINED
class WSTTimerElapsedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::System::Threading::ITimerElapsedHandler> {
    void (^_delegate)(WSTThreadPoolTimer*);

public:
    WSTTimerElapsedHandler_shim(void (^del)(WSTThreadPoolTimer*)) : _delegate([del copy]) {
    }
    ~WSTTimerElapsedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::System::Threading::IThreadPoolTimer* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSTThreadPoolTimer>(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WSTWorkItemHandler_shim__DEFINED
#define __WSTWorkItemHandler_shim__DEFINED
class WSTWorkItemHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::System::Threading::IWorkItemHandler> {
    void (^_delegate)(RTObject<WFIAsyncAction>*);

public:
    WSTWorkItemHandler_shim(void (^del)(RTObject<WFIAsyncAction>*)) : _delegate([del copy]) {
    }
    ~WSTWorkItemHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Foundation::IAsyncAction* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WFIAsyncAction>(arg0));
            return 0;
        };
    }
};
#endif
