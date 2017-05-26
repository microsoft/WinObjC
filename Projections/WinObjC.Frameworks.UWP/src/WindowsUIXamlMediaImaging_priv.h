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

// WindowsUIXamlMediaImaging_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUIXamlMedia_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUIXaml_priv.h"
#include "WindowsApplicationModelBackground_priv.h"
#include "WindowsUICore_priv.h"
#include "WindowsGraphicsImaging_priv.h"
ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapSourceStatics> WUXMIIBitmapSourceStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmapStatics> WUXMIIRenderTargetBitmapStatics_inst();
static ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageFactory> WUXMIIBitmapImageFactory_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics> WUXMIIBitmapImageStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics3> WUXMIIBitmapImageStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics2> WUXMIIBitmapImageStatics2_inst();
static ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSourceFactory> WUXMIIVirtualSurfaceImageSourceFactory_inst();
static ComPtr<ABI::Windows::UI::Xaml::Media::Imaging::IWriteableBitmapFactory> WUXMIIWriteableBitmapFactory_inst();

#ifndef __WUXMIDownloadProgressEventHandler_shim__DEFINED
#define __WUXMIDownloadProgressEventHandler_shim__DEFINED
class WUXMIDownloadProgressEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Media::Imaging::IDownloadProgressEventHandler> {
    void (^_delegate)(RTObject*, WUXMIDownloadProgressEventArgs*);

public:
    WUXMIDownloadProgressEventHandler_shim(void (^del)(RTObject*, WUXMIDownloadProgressEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXMIDownloadProgressEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Media::Imaging::IDownloadProgressEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXMIDownloadProgressEventArgs>(arg1));
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

#ifndef __WXExceptionRoutedEventHandler_shim__DEFINED
#define __WXExceptionRoutedEventHandler_shim__DEFINED
class WXExceptionRoutedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IExceptionRoutedEventHandler> {
    void (^_delegate)(RTObject*, WXExceptionRoutedEventArgs*);

public:
    WXExceptionRoutedEventHandler_shim(void (^del)(RTObject*, WXExceptionRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXExceptionRoutedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::IExceptionRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXExceptionRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXRoutedEventHandler_shim__DEFINED
#define __WXRoutedEventHandler_shim__DEFINED
class WXRoutedEventHandler_shim : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IRoutedEventHandler> {
    void (^_delegate)(RTObject*, WXRoutedEventArgs*);

public:
    WXRoutedEventHandler_shim(void (^del)(RTObject*, WXRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXRoutedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::IRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

class WUXMIIXamlRenderingBackgroundTaskOverrides_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides, ComposableBase<>> {
    InspectableClass(L"WUXMIIXamlRenderingBackgroundTaskOverrides_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WUXMIIXamlRenderingBackgroundTaskOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE OnRun(ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance* taskInstance_in) override {
        [_inner onRun:_createRtProxy<WABIBackgroundTaskInstance>(taskInstance_in)];
        return 0;
    }
};
