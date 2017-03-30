// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.AppExtensions.0.h"
#include "Windows.ApplicationModel.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Storage.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::AppExtensions {

struct __declspec(uuid("8450902c-15ed-4faf-93ea-2237bbf8cbd6")) __declspec(novtable) IAppExtension : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall get_Package(Windows::ApplicationModel::IPackage ** value) = 0;
    virtual HRESULT __stdcall get_AppInfo(Windows::ApplicationModel::IAppInfo ** value) = 0;
    virtual HRESULT __stdcall abi_GetExtensionPropertiesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IPropertySet> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetPublicFolderAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> ** operation) = 0;
};

struct __declspec(uuid("97872032-8426-4ad1-9084-92e88c2da200")) __declspec(novtable) IAppExtensionCatalog : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindAllAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppExtensions::AppExtension>> ** operation) = 0;
    virtual HRESULT __stdcall abi_RequestRemovePackageAsync(hstring packageFullName, Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall add_PackageInstalled(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PackageInstalled(event_token token) = 0;
    virtual HRESULT __stdcall add_PackageUpdating(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PackageUpdating(event_token token) = 0;
    virtual HRESULT __stdcall add_PackageUpdated(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PackageUpdated(event_token token) = 0;
    virtual HRESULT __stdcall add_PackageUninstalling(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PackageUninstalling(event_token token) = 0;
    virtual HRESULT __stdcall add_PackageStatusChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PackageStatusChanged(event_token token) = 0;
};

struct __declspec(uuid("3c36668a-5f18-4f0b-9ce5-cab61d196f11")) __declspec(novtable) IAppExtensionCatalogStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Open(hstring appExtensionName, Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog ** value) = 0;
};

struct __declspec(uuid("39e59234-3351-4a8d-9745-e7d3dd45bc48")) __declspec(novtable) IAppExtensionPackageInstalledEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppExtensionName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Package(Windows::ApplicationModel::IPackage ** value) = 0;
    virtual HRESULT __stdcall get_Extensions(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppExtensions::AppExtension> ** values) = 0;
};

struct __declspec(uuid("1ce17433-1153-44fd-87b1-8ae1050303df")) __declspec(novtable) IAppExtensionPackageStatusChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppExtensionName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Package(Windows::ApplicationModel::IPackage ** value) = 0;
};

struct __declspec(uuid("60f160c5-171e-40ff-ae98-ab2c20dd4d75")) __declspec(novtable) IAppExtensionPackageUninstallingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppExtensionName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Package(Windows::ApplicationModel::IPackage ** value) = 0;
};

struct __declspec(uuid("3a83c43f-797e-44b5-ba24-a4c8b5a543d7")) __declspec(novtable) IAppExtensionPackageUpdatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppExtensionName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Package(Windows::ApplicationModel::IPackage ** value) = 0;
    virtual HRESULT __stdcall get_Extensions(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppExtensions::AppExtension> ** values) = 0;
};

struct __declspec(uuid("7ed59329-1a65-4800-a700-b321009e306a")) __declspec(novtable) IAppExtensionPackageUpdatingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppExtensionName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Package(Windows::ApplicationModel::IPackage ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::AppExtensions::AppExtension> { using default_interface = Windows::ApplicationModel::AppExtensions::IAppExtension; };
template <> struct traits<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog> { using default_interface = Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog; };
template <> struct traits<Windows::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs> { using default_interface = Windows::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs; };
template <> struct traits<Windows::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs> { using default_interface = Windows::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs; };
template <> struct traits<Windows::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs> { using default_interface = Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs; };
template <> struct traits<Windows::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs> { using default_interface = Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs> { using default_interface = Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs; };

}

namespace Windows::ApplicationModel::AppExtensions {

template <typename D>
struct WINRT_EBO impl_IAppExtension
{
    hstring Id() const;
    hstring DisplayName() const;
    hstring Description() const;
    Windows::ApplicationModel::Package Package() const;
    Windows::ApplicationModel::AppInfo AppInfo() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IPropertySet> GetExtensionPropertiesAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> GetPublicFolderAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IAppExtensionCatalog
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppExtensions::AppExtension>> FindAllAsync() const;
    Windows::Foundation::IAsyncOperation<bool> RequestRemovePackageAsync(hstring_view packageFullName) const;
    event_token PackageInstalled(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs> & handler) const;
    using PackageInstalled_revoker = event_revoker<IAppExtensionCatalog>;
    PackageInstalled_revoker PackageInstalled(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs> & handler) const;
    void PackageInstalled(event_token token) const;
    event_token PackageUpdating(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs> & handler) const;
    using PackageUpdating_revoker = event_revoker<IAppExtensionCatalog>;
    PackageUpdating_revoker PackageUpdating(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs> & handler) const;
    void PackageUpdating(event_token token) const;
    event_token PackageUpdated(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs> & handler) const;
    using PackageUpdated_revoker = event_revoker<IAppExtensionCatalog>;
    PackageUpdated_revoker PackageUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs> & handler) const;
    void PackageUpdated(event_token token) const;
    event_token PackageUninstalling(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs> & handler) const;
    using PackageUninstalling_revoker = event_revoker<IAppExtensionCatalog>;
    PackageUninstalling_revoker PackageUninstalling(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs> & handler) const;
    void PackageUninstalling(event_token token) const;
    event_token PackageStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs> & handler) const;
    using PackageStatusChanged_revoker = event_revoker<IAppExtensionCatalog>;
    PackageStatusChanged_revoker PackageStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog, Windows::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs> & handler) const;
    void PackageStatusChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAppExtensionCatalogStatics
{
    Windows::ApplicationModel::AppExtensions::AppExtensionCatalog Open(hstring_view appExtensionName) const;
};

template <typename D>
struct WINRT_EBO impl_IAppExtensionPackageInstalledEventArgs
{
    hstring AppExtensionName() const;
    Windows::ApplicationModel::Package Package() const;
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppExtensions::AppExtension> Extensions() const;
};

template <typename D>
struct WINRT_EBO impl_IAppExtensionPackageStatusChangedEventArgs
{
    hstring AppExtensionName() const;
    Windows::ApplicationModel::Package Package() const;
};

template <typename D>
struct WINRT_EBO impl_IAppExtensionPackageUninstallingEventArgs
{
    hstring AppExtensionName() const;
    Windows::ApplicationModel::Package Package() const;
};

template <typename D>
struct WINRT_EBO impl_IAppExtensionPackageUpdatedEventArgs
{
    hstring AppExtensionName() const;
    Windows::ApplicationModel::Package Package() const;
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppExtensions::AppExtension> Extensions() const;
};

template <typename D>
struct WINRT_EBO impl_IAppExtensionPackageUpdatingEventArgs
{
    hstring AppExtensionName() const;
    Windows::ApplicationModel::Package Package() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::AppExtensions::IAppExtension>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::IAppExtension;
    template <typename D> using consume = Windows::ApplicationModel::AppExtensions::impl_IAppExtension<D>;
};

template <> struct traits<Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog;
    template <typename D> using consume = Windows::ApplicationModel::AppExtensions::impl_IAppExtensionCatalog<D>;
};

template <> struct traits<Windows::ApplicationModel::AppExtensions::IAppExtensionCatalogStatics>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalogStatics;
    template <typename D> using consume = Windows::ApplicationModel::AppExtensions::impl_IAppExtensionCatalogStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::AppExtensions::impl_IAppExtensionPackageInstalledEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::AppExtensions::impl_IAppExtensionPackageStatusChangedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::AppExtensions::impl_IAppExtensionPackageUninstallingEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::AppExtensions::impl_IAppExtensionPackageUpdatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::AppExtensions::impl_IAppExtensionPackageUpdatingEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::AppExtensions::AppExtension>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::AppExtension;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.AppExtensions.AppExtension"; }
};

template <> struct traits<Windows::ApplicationModel::AppExtensions::AppExtensionCatalog>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::AppExtensionCatalog;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.AppExtensions.AppExtensionCatalog"; }
};

template <> struct traits<Windows::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.AppExtensions.AppExtensionPackageInstalledEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.AppExtensions.AppExtensionPackageStatusChangedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.AppExtensions.AppExtensionPackageUninstallingEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.AppExtensions.AppExtensionPackageUpdatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.AppExtensions.AppExtensionPackageUpdatingEventArgs"; }
};

}

}
