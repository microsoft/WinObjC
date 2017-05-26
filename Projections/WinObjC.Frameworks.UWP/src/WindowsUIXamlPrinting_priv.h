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

// WindowsUIXamlPrinting_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUIXaml_priv.h"
#include "WindowsGraphicsPrinting_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUICore_priv.h"
ComPtr<ABI::Windows::UI::Xaml::Printing::IPrintDocumentStatics> WUXPIPrintDocumentStatics_inst();

#ifndef __WUXPAddPagesEventHandler_shim__DEFINED
#define __WUXPAddPagesEventHandler_shim__DEFINED
class WUXPAddPagesEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Printing::IAddPagesEventHandler> {
    void (^_delegate)(RTObject*, WUXPAddPagesEventArgs*);

public:
    WUXPAddPagesEventHandler_shim(void (^del)(RTObject*, WUXPAddPagesEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXPAddPagesEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Printing::IAddPagesEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXPAddPagesEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXPGetPreviewPageEventHandler_shim__DEFINED
#define __WUXPGetPreviewPageEventHandler_shim__DEFINED
class WUXPGetPreviewPageEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Printing::IGetPreviewPageEventHandler> {
    void (^_delegate)(RTObject*, WUXPGetPreviewPageEventArgs*);

public:
    WUXPGetPreviewPageEventHandler_shim(void (^del)(RTObject*, WUXPGetPreviewPageEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXPGetPreviewPageEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Printing::IGetPreviewPageEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXPGetPreviewPageEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXPPaginateEventHandler_shim__DEFINED
#define __WUXPPaginateEventHandler_shim__DEFINED
class WUXPPaginateEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Printing::IPaginateEventHandler> {
    void (^_delegate)(RTObject*, WUXPPaginateEventArgs*);

public:
    WUXPPaginateEventHandler_shim(void (^del)(RTObject*, WUXPPaginateEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXPPaginateEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Printing::IPaginateEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXPPaginateEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXDependencyPropertyChangedCallback_shim__DEFINED
#define __WXDependencyPropertyChangedCallback_shim__DEFINED
class WXDependencyPropertyChangedCallback_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IDependencyPropertyChangedCallback> {
    void (^_delegate)(WXDependencyObject*, WXDependencyProperty*);

public:
    WXDependencyPropertyChangedCallback_shim(void (^del)(WXDependencyObject*, WXDependencyProperty*)) : _delegate([del copy]) {
    }
    ~WXDependencyPropertyChangedCallback_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IDependencyObject* arg0,
                                             ABI::Windows::UI::Xaml::IDependencyProperty* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXDependencyObject>(arg0), _createRtProxy<WXDependencyProperty>(arg1));
            return 0;
        };
    }
};
#endif
