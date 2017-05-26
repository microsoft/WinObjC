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

// WindowsApplicationModelAppExtensions_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundationCollections_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsApplicationModel_priv.h"
#include "WindowsStorage_priv.h"
ComPtr<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalogStatics> WAAIAppExtensionCatalogStatics_inst();

id RTProxiedNSArray_WAAAppExtension_create(IInspectable* val);

@class RTProxiedNSArray_WAAAppExtension;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageInstalledEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageInstalledEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageInstalledEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::AppExtensions::AppExtensionCatalog*,
                              ABI::Windows::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs*>> {
    void (^_delegate)(WAAAppExtensionCatalog*, WAAAppExtensionPackageInstalledEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageInstalledEventArgs(
        void (^del)(WAAAppExtensionCatalog*, WAAAppExtensionPackageInstalledEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageInstalledEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog* arg0,
           ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAAAppExtensionCatalog>(arg0), _createRtProxy<WAAAppExtensionPackageInstalledEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageStatusChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageStatusChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageStatusChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::AppExtensions::AppExtensionCatalog*,
                              ABI::Windows::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs*>> {
    void (^_delegate)(WAAAppExtensionCatalog*, WAAAppExtensionPackageStatusChangedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageStatusChangedEventArgs(
        void (^del)(WAAAppExtensionCatalog*, WAAAppExtensionPackageStatusChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageStatusChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog* arg0,
           ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAAAppExtensionCatalog>(arg0), _createRtProxy<WAAAppExtensionPackageStatusChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUninstallingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUninstallingEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUninstallingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::AppExtensions::AppExtensionCatalog*,
                              ABI::Windows::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs*>> {
    void (^_delegate)(WAAAppExtensionCatalog*, WAAAppExtensionPackageUninstallingEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUninstallingEventArgs(
        void (^del)(WAAAppExtensionCatalog*, WAAAppExtensionPackageUninstallingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUninstallingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog* arg0,
           ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAAAppExtensionCatalog>(arg0), _createRtProxy<WAAAppExtensionPackageUninstallingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUpdatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUpdatedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUpdatedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::AppExtensions::AppExtensionCatalog*,
                              ABI::Windows::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs*>> {
    void (^_delegate)(WAAAppExtensionCatalog*, WAAAppExtensionPackageUpdatedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUpdatedEventArgs(
        void (^del)(WAAAppExtensionCatalog*, WAAAppExtensionPackageUpdatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUpdatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog* arg0,
           ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAAAppExtensionCatalog>(arg0), _createRtProxy<WAAAppExtensionPackageUpdatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUpdatingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUpdatingEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUpdatingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::AppExtensions::AppExtensionCatalog*,
                              ABI::Windows::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs*>> {
    void (^_delegate)(WAAAppExtensionCatalog*, WAAAppExtensionPackageUpdatingEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUpdatingEventArgs(
        void (^del)(WAAAppExtensionCatalog*, WAAAppExtensionPackageUpdatingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUpdatingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog* arg0,
           ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAAAppExtensionCatalog>(arg0), _createRtProxy<WAAAppExtensionPackageUpdatingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
