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

// WindowsApplicationModel_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsSystem_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsApplicationModelCore_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsStorage_priv.h"
ComPtr<ABI::Windows::ApplicationModel::IFullTrustProcessLauncherStatics> WAIFullTrustProcessLauncherStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::IStartupTaskStatics> WAIStartupTaskStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::IPackageStatics> WAIPackageStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::IPackageCatalogStatics> WAIPackageCatalogStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::IDesignModeStatics> WAIDesignModeStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::ICameraApplicationManagerStatics> WAICameraApplicationManagerStatics_inst();
@interface WAPackageVersion (Internal)
+ (instancetype)createWith:(ABI::Windows::ApplicationModel::PackageVersion)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::ApplicationModel::PackageVersion*)internalStruct;
@end
inline WAPackageVersion* WAPackageVersion_create(ABI::Windows::ApplicationModel::PackageVersion val) {
    return [WAPackageVersion createWith:val];
}

id RTProxiedNSArray_WACAppListEntry_create(IInspectable* val);
id RTProxiedNSArray_WAPackage_create(IInspectable* val);
id RTProxiedNSArray_WAStartupTask_create(IInspectable* val);

@class RTProxiedNSArray_WACAppListEntry, RTProxiedNSArray_WAPackage, RTProxiedNSArray_WAStartupTask;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageInstallingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageInstallingEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageInstallingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::PackageCatalog*,
                                                                       ABI::Windows::ApplicationModel::PackageInstallingEventArgs*>> {
    void (^_delegate)(WAPackageCatalog*, WAPackageInstallingEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageInstallingEventArgs(
        void (^del)(WAPackageCatalog*, WAPackageInstallingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageInstallingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::IPackageCatalog* arg0,
                                             ABI::Windows::ApplicationModel::IPackageInstallingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAPackageCatalog>(arg0), _createRtProxy<WAPackageInstallingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageStagingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageStagingEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageStagingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::PackageCatalog*,
                                                                       ABI::Windows::ApplicationModel::PackageStagingEventArgs*>> {
    void (^_delegate)(WAPackageCatalog*, WAPackageStagingEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageStagingEventArgs(
        void (^del)(WAPackageCatalog*, WAPackageStagingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageStagingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::IPackageCatalog* arg0,
                                             ABI::Windows::ApplicationModel::IPackageStagingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAPackageCatalog>(arg0), _createRtProxy<WAPackageStagingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageStatusChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageStatusChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageStatusChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::PackageCatalog*,
                                                                       ABI::Windows::ApplicationModel::PackageStatusChangedEventArgs*>> {
    void (^_delegate)(WAPackageCatalog*, WAPackageStatusChangedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageStatusChangedEventArgs(
        void (^del)(WAPackageCatalog*, WAPackageStatusChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageStatusChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::IPackageCatalog* arg0,
                                             ABI::Windows::ApplicationModel::IPackageStatusChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAPackageCatalog>(arg0), _createRtProxy<WAPackageStatusChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageUninstallingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageUninstallingEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageUninstallingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::PackageCatalog*,
                                                                       ABI::Windows::ApplicationModel::PackageUninstallingEventArgs*>> {
    void (^_delegate)(WAPackageCatalog*, WAPackageUninstallingEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageUninstallingEventArgs(
        void (^del)(WAPackageCatalog*, WAPackageUninstallingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageUninstallingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::IPackageCatalog* arg0,
                                             ABI::Windows::ApplicationModel::IPackageUninstallingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAPackageCatalog>(arg0), _createRtProxy<WAPackageUninstallingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageUpdatingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageUpdatingEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageUpdatingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::PackageCatalog*,
                                                                       ABI::Windows::ApplicationModel::PackageUpdatingEventArgs*>> {
    void (^_delegate)(WAPackageCatalog*, WAPackageUpdatingEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageUpdatingEventArgs(
        void (^del)(WAPackageCatalog*, WAPackageUpdatingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageUpdatingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::IPackageCatalog* arg0,
                                             ABI::Windows::ApplicationModel::IPackageUpdatingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAPackageCatalog>(arg0), _createRtProxy<WAPackageUpdatingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
