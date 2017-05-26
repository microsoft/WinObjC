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

// WindowsUIXamlMediaMedia3D_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUIXaml_priv.h"
#include "WindowsUICore_priv.h"
ComPtr<ABI::Windows::UI::Xaml::Media::Media3D::IMatrix3DHelperStatics> WUXMMIMatrix3DHelperStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Media3D::ICompositeTransform3DStatics> WUXMMICompositeTransform3DStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Media3D::IPerspectiveTransform3DStatics> WUXMMIPerspectiveTransform3DStatics_inst();
@interface WUXMMMatrix3D (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Media::Media3D::Matrix3D)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Xaml::Media::Media3D::Matrix3D*)internalStruct;
@end
inline WUXMMMatrix3D* WUXMMMatrix3D_create(ABI::Windows::UI::Xaml::Media::Media3D::Matrix3D val) {
    return [WUXMMMatrix3D createWith:val];
}

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
