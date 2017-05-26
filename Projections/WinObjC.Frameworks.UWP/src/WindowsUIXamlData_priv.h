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

// WindowsUIXamlData_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsUIXamlInterop_priv.h"
#include "WindowsUIXaml_priv.h"
#include "WindowsUICore_priv.h"
ComPtr<ABI::Windows::UI::Xaml::Data::IBindingOperationsStatics> WUXDIBindingOperationsStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Data::ICollectionViewSourceStatics> WUXDICollectionViewSourceStatics_inst();
@interface WUXDLoadMoreItemsResult (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult*)internalStruct;
@end
inline WUXDLoadMoreItemsResult* WUXDLoadMoreItemsResult_create(ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult val) {
    return [WUXDLoadMoreItemsResult createWith:val];
}

id RTProxiedNSArray_WUXDItemIndexRange_create(IInspectable* val);
id RTProxiedObservableNSMutableArray_RTObject_create(IInspectable* val);

@class RTProxiedNSArray_WUXDItemIndexRange, RTProxiedObservableNSMutableArray_RTObject;

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

#ifndef __WUXDCurrentChangingEventHandler_shim__DEFINED
#define __WUXDCurrentChangingEventHandler_shim__DEFINED
class WUXDCurrentChangingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Data::ICurrentChangingEventHandler> {
    void (^_delegate)(RTObject*, WUXDCurrentChangingEventArgs*);

public:
    WUXDCurrentChangingEventHandler_shim(void (^del)(RTObject*, WUXDCurrentChangingEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXDCurrentChangingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Data::ICurrentChangingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXDCurrentChangingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXDPropertyChangedEventHandler_shim__DEFINED
#define __WUXDPropertyChangedEventHandler_shim__DEFINED
class WUXDPropertyChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Data::IPropertyChangedEventHandler> {
    void (^_delegate)(RTObject*, WUXDPropertyChangedEventArgs*);

public:
    WUXDPropertyChangedEventHandler_shim(void (^del)(RTObject*, WUXDPropertyChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXDPropertyChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Data::IPropertyChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXDPropertyChangedEventArgs>(arg1));
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
