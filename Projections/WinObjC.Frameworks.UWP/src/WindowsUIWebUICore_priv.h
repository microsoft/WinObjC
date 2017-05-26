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

// WindowsUIWebUICore_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsUI_priv.h"
static ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarBitmapIconFactory> WUWCIWebUICommandBarBitmapIconFactory_inst();
static ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarSymbolIconFactory> WUWCIWebUICommandBarSymbolIconFactory_inst();
ComPtr<ABI::Windows::UI::WebUI::Core::IWebUICommandBarStatics> WUWCIWebUICommandBarStatics_inst();

id RTProxiedObservableNSMutableArray_RTObject_WUWCIWebUICommandBarElement_create(IInspectable* val);

@class RTProxiedObservableNSMutableArray_RTObject_WUWCIWebUICommandBarElement;

#ifndef __ITypedEventHandler_Windows_UI_WebUI_Core_WebUICommandBarConfirmationButton_Windows_UI_WebUI_Core_WebUICommandBarItemInvokedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_WebUI_Core_WebUICommandBarConfirmationButton_Windows_UI_WebUI_Core_WebUICommandBarItemInvokedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_WebUI_Core_WebUICommandBarConfirmationButton_Windows_UI_WebUI_Core_WebUICommandBarItemInvokedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::WebUI::Core::WebUICommandBarConfirmationButton*,
                                                       ABI::Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs*>> {
    void (^_delegate)(WUWCWebUICommandBarConfirmationButton*, WUWCWebUICommandBarItemInvokedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_WebUI_Core_WebUICommandBarConfirmationButton_Windows_UI_WebUI_Core_WebUICommandBarItemInvokedEventArgs(
        void (^del)(WUWCWebUICommandBarConfirmationButton*, WUWCWebUICommandBarItemInvokedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_WebUI_Core_WebUICommandBarConfirmationButton_Windows_UI_WebUI_Core_WebUICommandBarItemInvokedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::WebUI::Core::IWebUICommandBarConfirmationButton* arg0,
                                             ABI::Windows::UI::WebUI::Core::IWebUICommandBarItemInvokedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUWCWebUICommandBarConfirmationButton>(arg0),
                      _createRtProxy<WUWCWebUICommandBarItemInvokedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_WebUI_Core_WebUICommandBarIconButton_Windows_UI_WebUI_Core_WebUICommandBarItemInvokedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_WebUI_Core_WebUICommandBarIconButton_Windows_UI_WebUI_Core_WebUICommandBarItemInvokedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_WebUI_Core_WebUICommandBarIconButton_Windows_UI_WebUI_Core_WebUICommandBarItemInvokedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::WebUI::Core::WebUICommandBarIconButton*,
                                                       ABI::Windows::UI::WebUI::Core::WebUICommandBarItemInvokedEventArgs*>> {
    void (^_delegate)(WUWCWebUICommandBarIconButton*, WUWCWebUICommandBarItemInvokedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_WebUI_Core_WebUICommandBarIconButton_Windows_UI_WebUI_Core_WebUICommandBarItemInvokedEventArgs(
        void (^del)(WUWCWebUICommandBarIconButton*, WUWCWebUICommandBarItemInvokedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_WebUI_Core_WebUICommandBarIconButton_Windows_UI_WebUI_Core_WebUICommandBarItemInvokedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::WebUI::Core::IWebUICommandBarIconButton* arg0,
                                             ABI::Windows::UI::WebUI::Core::IWebUICommandBarItemInvokedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUWCWebUICommandBarIconButton>(arg0), _createRtProxy<WUWCWebUICommandBarItemInvokedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUWCMenuClosedEventHandler_shim__DEFINED
#define __WUWCMenuClosedEventHandler_shim__DEFINED
class WUWCMenuClosedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::WebUI::Core::IMenuClosedEventHandler> {
    void (^_delegate)();

public:
    WUWCMenuClosedEventHandler_shim(void (^del)()) : _delegate([del copy]) {
    }
    ~WUWCMenuClosedEventHandler_shim() {
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

#ifndef __WUWCMenuOpenedEventHandler_shim__DEFINED
#define __WUWCMenuOpenedEventHandler_shim__DEFINED
class WUWCMenuOpenedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::WebUI::Core::IMenuOpenedEventHandler> {
    void (^_delegate)();

public:
    WUWCMenuOpenedEventHandler_shim(void (^del)()) : _delegate([del copy]) {
    }
    ~WUWCMenuOpenedEventHandler_shim() {
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

#ifndef __WUWCSizeChangedEventHandler_shim__DEFINED
#define __WUWCSizeChangedEventHandler_shim__DEFINED
class WUWCSizeChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::WebUI::Core::ISizeChangedEventHandler> {
    void (^_delegate)(WUWCWebUICommandBarSizeChangedEventArgs*);

public:
    WUWCSizeChangedEventHandler_shim(void (^del)(WUWCWebUICommandBarSizeChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUWCSizeChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::WebUI::Core::IWebUICommandBarSizeChangedEventArgs* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUWCWebUICommandBarSizeChangedEventArgs>(arg0));
            return 0;
        };
    }
};
#endif
