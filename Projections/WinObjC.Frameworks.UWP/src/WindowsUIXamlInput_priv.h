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

// WindowsUIXamlInput_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUIXaml_priv.h"
#include "WindowsDevicesInput_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUIInput_priv.h"
#include "WindowsSystem_priv.h"
#include "WindowsUICore_priv.h"
ComPtr<ABI::Windows::UI::Xaml::Input::IAccessKeyManagerStatics> WUXIIAccessKeyManagerStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Input::IFocusManagerStatics> WUXIIFocusManagerStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Input::IFocusManagerStatics2> WUXIIFocusManagerStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Input::IFocusManagerStatics3> WUXIIFocusManagerStatics3_inst();
static ComPtr<ABI::Windows::UI::Xaml::Input::IManipulationPivotFactory> WUXIIManipulationPivotFactory_inst();
static ComPtr<ABI::Windows::UI::Xaml::Input::IInputScopeNameFactory> WUXIIInputScopeNameFactory_inst();

id RTProxiedNSMutableArray_WUIPointerPoint_create(IInspectable* val);
id RTProxiedNSMutableArray_WUXIInputScopeName_create(IInspectable* val);

@class RTProxiedNSMutableArray_WUIPointerPoint, RTProxiedNSMutableArray_WUXIInputScopeName;

#ifndef __EventHandler_System_Object__DEFINED
#define __EventHandler_System_Object__DEFINED
class EventHandler_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Foundation::IEventHandler<IInspectable*>> {
    void (^_delegate)(RTObject*, RTObject*);

public:
    EventHandler_System_Object(void (^del)(RTObject*, RTObject*)) : _delegate([del copy]) {
    }
    ~EventHandler_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_System_Object_System_Object__DEFINED
#define __ITypedEventHandler_System_Object_System_Object__DEFINED
class ITypedEventHandler_System_Object_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<IInspectable*, IInspectable*>> {
    void (^_delegate)(RTObject*, RTObject*);

public:
    ITypedEventHandler_System_Object_System_Object(void (^del)(RTObject*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_System_Object_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createBareRTObj(arg1));
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
