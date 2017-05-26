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

// WindowsUIXamlAutomationProvider_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUIXamlAutomationPeers_priv.h"
#include "WindowsUI_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUIXamlAutomation_priv.h"
#include "WindowsUIXamlAutomationText_priv.h"
#include "WindowsUIXaml_priv.h"
#include "WindowsUICore_priv.h"

id RTProxiedNSArray_C_Double_create(UINT32 size, double* val);
id RTProxiedNSArray_C_Int32_create(UINT32 size, int* val);
id RTProxiedNSArray_C_NSString_create(UINT32 size, HSTRING* val);
id RTProxiedNSArray_C_RTObject_WUXAPITextRangeProvider_create(UINT32 size,
                                                              ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider** val);
id RTProxiedNSArray_C_WUXAAnnotationType_create(UINT32 size, ABI::Windows::UI::Xaml::Automation::AnnotationType* val);
id RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(UINT32 size,
                                                            ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** val);

@class RTProxiedNSArray_C_Double, RTProxiedNSArray_C_Int32, RTProxiedNSArray_C_NSString,
    RTProxiedNSArray_C_RTObject_WUXAPITextRangeProvider;
@class RTProxiedNSArray_C_WUXAAnnotationType, RTProxiedNSArray_C_WUXAPIRawElementProviderSimple;

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
