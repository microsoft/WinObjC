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

// WindowsUIXamlInterop_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
@interface WUXITypeName (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Interop::TypeName)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Xaml::Interop::TypeName*)internalStruct;
@end
inline WUXITypeName* WUXITypeName_create(ABI::Windows::UI::Xaml::Interop::TypeName val) {
    return [WUXITypeName createWith:val];
}

#ifndef __WUXIBindableVectorChangedEventHandler_shim__DEFINED
#define __WUXIBindableVectorChangedEventHandler_shim__DEFINED
class WUXIBindableVectorChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Interop::IBindableVectorChangedEventHandler> {
    void (^_delegate)(RTObject<WUXIIBindableObservableVector>*, RTObject*);

public:
    WUXIBindableVectorChangedEventHandler_shim(void (^del)(RTObject<WUXIIBindableObservableVector>*, RTObject*)) : _delegate([del copy]) {
    }
    ~WUXIBindableVectorChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Interop::IBindableObservableVector* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXIIBindableObservableVector>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXINotifyCollectionChangedEventHandler_shim__DEFINED
#define __WUXINotifyCollectionChangedEventHandler_shim__DEFINED
class WUXINotifyCollectionChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Interop::INotifyCollectionChangedEventHandler> {
    void (^_delegate)(RTObject*, WUXINotifyCollectionChangedEventArgs*);

public:
    WUXINotifyCollectionChangedEventHandler_shim(void (^del)(RTObject*, WUXINotifyCollectionChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXINotifyCollectionChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXINotifyCollectionChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
