// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.Popups.3.h"
#include "internal/Windows.Storage.Search.3.h"
#include "internal/Windows.UI.ViewManagement.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.System.RemoteSystems.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.System.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::System::IAppMemoryReport> : produce_base<D, Windows::System::IAppMemoryReport>
{
    HRESULT __stdcall get_PrivateCommitUsage(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrivateCommitUsage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PeakPrivateCommitUsage(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PeakPrivateCommitUsage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TotalCommitUsage(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TotalCommitUsage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TotalCommitLimit(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TotalCommitLimit());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IAppMemoryUsageLimitChangingEventArgs> : produce_base<D, Windows::System::IAppMemoryUsageLimitChangingEventArgs>
{
    HRESULT __stdcall get_OldLimit(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OldLimit());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewLimit(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewLimit());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IFolderLauncherOptions> : produce_base<D, Windows::System::IFolderLauncherOptions>
{
    HRESULT __stdcall get_ItemsToSelect(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Storage::IStorageItem>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemsToSelect());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IKnownUserPropertiesStatics> : produce_base<D, Windows::System::IKnownUserPropertiesStatics>
{
    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProviderName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProviderName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccountName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccountName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GuestHost(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GuestHost());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrincipalName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrincipalName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DomainName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DomainName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SessionInitiationProtocolUri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SessionInitiationProtocolUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::ILaunchUriResult> : produce_base<D, Windows::System::ILaunchUriResult>
{
    HRESULT __stdcall get_Status(Windows::System::LaunchUriStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Result(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Result());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::ILauncherOptions> : produce_base<D, Windows::System::ILauncherOptions>
{
    HRESULT __stdcall get_TreatAsUntrusted(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TreatAsUntrusted());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TreatAsUntrusted(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TreatAsUntrusted(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayApplicationPicker(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayApplicationPicker());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayApplicationPicker(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayApplicationPicker(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UI(impl::abi_arg_out<Windows::System::ILauncherUIOptions> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UI());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreferredApplicationPackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreferredApplicationPackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PreferredApplicationPackageFamilyName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferredApplicationPackageFamilyName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreferredApplicationDisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreferredApplicationDisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PreferredApplicationDisplayName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferredApplicationDisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FallbackUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FallbackUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FallbackUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FallbackUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentType(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentType(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::ILauncherOptions2> : produce_base<D, Windows::System::ILauncherOptions2>
{
    HRESULT __stdcall get_TargetApplicationPackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetApplicationPackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetApplicationPackageFamilyName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetApplicationPackageFamilyName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NeighboringFilesQuery(impl::abi_arg_out<Windows::Storage::Search::IStorageFileQueryResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NeighboringFilesQuery());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NeighboringFilesQuery(impl::abi_arg_in<Windows::Storage::Search::IStorageFileQueryResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NeighboringFilesQuery(*reinterpret_cast<const Windows::Storage::Search::StorageFileQueryResult *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::ILauncherOptions3> : produce_base<D, Windows::System::ILauncherOptions3>
{
    HRESULT __stdcall get_IgnoreAppUriHandlers(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IgnoreAppUriHandlers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IgnoreAppUriHandlers(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IgnoreAppUriHandlers(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::ILauncherStatics> : produce_base<D, Windows::System::ILauncherStatics>
{
    HRESULT __stdcall abi_LaunchFileAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchFileWithOptionsAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<Windows::System::ILauncherOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const Windows::System::LauncherOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchUriAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchUriAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchUriWithOptionsAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::System::ILauncherOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchUriAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::System::LauncherOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::ILauncherStatics2> : produce_base<D, Windows::System::ILauncherStatics2>
{
    HRESULT __stdcall abi_LaunchUriForResultsAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::System::ILauncherOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchUriForResultsAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::System::LauncherOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchUriForResultsWithDataAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::System::ILauncherOptions> options, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> inputData, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchUriForResultsAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::System::LauncherOptions *>(&options), *reinterpret_cast<const Windows::Foundation::Collections::ValueSet *>(&inputData)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchUriWithDataAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::System::ILauncherOptions> options, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> inputData, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchUriAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::System::LauncherOptions *>(&options), *reinterpret_cast<const Windows::Foundation::Collections::ValueSet *>(&inputData)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_QueryUriSupportAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, Windows::System::LaunchQuerySupportType launchQuerySupportType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().QueryUriSupportAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), launchQuerySupportType));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_QueryUriSupportWithPackageFamilyNameAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, Windows::System::LaunchQuerySupportType launchQuerySupportType, impl::abi_arg_in<hstring> packageFamilyName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().QueryUriSupportAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), launchQuerySupportType, *reinterpret_cast<const hstring *>(&packageFamilyName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_QueryFileSupportAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().QueryFileSupportAsync(*reinterpret_cast<const Windows::Storage::StorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_QueryFileSupportWithPackageFamilyNameAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<hstring> packageFamilyName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().QueryFileSupportAsync(*reinterpret_cast<const Windows::Storage::StorageFile *>(&file), *reinterpret_cast<const hstring *>(&packageFamilyName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindUriSchemeHandlersAsync(impl::abi_arg_in<hstring> scheme, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindUriSchemeHandlersAsync(*reinterpret_cast<const hstring *>(&scheme)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindUriSchemeHandlersWithLaunchUriTypeAsync(impl::abi_arg_in<hstring> scheme, Windows::System::LaunchQuerySupportType launchQuerySupportType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindUriSchemeHandlersAsync(*reinterpret_cast<const hstring *>(&scheme), launchQuerySupportType));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindFileHandlersAsync(impl::abi_arg_in<hstring> extension, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindFileHandlersAsync(*reinterpret_cast<const hstring *>(&extension)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::ILauncherStatics3> : produce_base<D, Windows::System::ILauncherStatics3>
{
    HRESULT __stdcall abi_LaunchFolderAsync(impl::abi_arg_in<Windows::Storage::IStorageFolder> folder, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchFolderAsync(*reinterpret_cast<const Windows::Storage::IStorageFolder *>(&folder)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchFolderWithOptionsAsync(impl::abi_arg_in<Windows::Storage::IStorageFolder> folder, impl::abi_arg_in<Windows::System::IFolderLauncherOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchFolderAsync(*reinterpret_cast<const Windows::Storage::IStorageFolder *>(&folder), *reinterpret_cast<const Windows::System::FolderLauncherOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::ILauncherStatics4> : produce_base<D, Windows::System::ILauncherStatics4>
{
    HRESULT __stdcall abi_QueryAppUriSupportAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().QueryAppUriSupportAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_QueryAppUriSupportWithPackageFamilyNameAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<hstring> packageFamilyName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().QueryAppUriSupportAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const hstring *>(&packageFamilyName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAppUriHandlersAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindAppUriHandlersAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchUriForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchUriForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchUriWithOptionsForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::System::ILauncherOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchUriForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::System::LauncherOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchUriWithDataForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::System::ILauncherOptions> options, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> inputData, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchUriForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::System::LauncherOptions *>(&options), *reinterpret_cast<const Windows::Foundation::Collections::ValueSet *>(&inputData)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchUriForResultsForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::System::ILauncherOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchUriForResultsForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::System::LauncherOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchUriForResultsWithDataForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::System::ILauncherOptions> options, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> inputData, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchUriForResultsForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::System::LauncherOptions *>(&options), *reinterpret_cast<const Windows::Foundation::Collections::ValueSet *>(&inputData)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::ILauncherUIOptions> : produce_base<D, Windows::System::ILauncherUIOptions>
{
    HRESULT __stdcall get_InvocationPoint(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::Point>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InvocationPoint());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InvocationPoint(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::Point>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InvocationPoint(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::Point> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectionRect(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::Rect>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectionRect());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SelectionRect(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::Rect>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectionRect(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::Rect> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreferredPlacement(Windows::UI::Popups::Placement * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreferredPlacement());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PreferredPlacement(Windows::UI::Popups::Placement value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferredPlacement(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::ILauncherViewOptions> : produce_base<D, Windows::System::ILauncherViewOptions>
{
    HRESULT __stdcall get_DesiredRemainingView(Windows::UI::ViewManagement::ViewSizePreference * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredRemainingView());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredRemainingView(Windows::UI::ViewManagement::ViewSizePreference value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredRemainingView(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IMemoryManagerStatics> : produce_base<D, Windows::System::IMemoryManagerStatics>
{
    HRESULT __stdcall get_AppMemoryUsage(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppMemoryUsage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppMemoryUsageLimit(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppMemoryUsageLimit());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppMemoryUsageLevel(Windows::System::AppMemoryUsageLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppMemoryUsageLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AppMemoryUsageIncreased(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AppMemoryUsageIncreased(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AppMemoryUsageIncreased(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppMemoryUsageIncreased(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AppMemoryUsageDecreased(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AppMemoryUsageDecreased(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AppMemoryUsageDecreased(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppMemoryUsageDecreased(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AppMemoryUsageLimitChanging(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::System::AppMemoryUsageLimitChangingEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AppMemoryUsageLimitChanging(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::System::AppMemoryUsageLimitChangingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AppMemoryUsageLimitChanging(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppMemoryUsageLimitChanging(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IMemoryManagerStatics2> : produce_base<D, Windows::System::IMemoryManagerStatics2>
{
    HRESULT __stdcall abi_GetAppMemoryReport(impl::abi_arg_out<Windows::System::IAppMemoryReport> memoryReport) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *memoryReport = detach_abi(this->shim().GetAppMemoryReport());
            return S_OK;
        }
        catch (...)
        {
            *memoryReport = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetProcessMemoryReport(impl::abi_arg_out<Windows::System::IProcessMemoryReport> memoryReport) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *memoryReport = detach_abi(this->shim().GetProcessMemoryReport());
            return S_OK;
        }
        catch (...)
        {
            *memoryReport = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IMemoryManagerStatics3> : produce_base<D, Windows::System::IMemoryManagerStatics3>
{
    HRESULT __stdcall abi_TrySetAppMemoryUsageLimit(uint64_t value, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TrySetAppMemoryUsageLimit(value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IProcessLauncherOptions> : produce_base<D, Windows::System::IProcessLauncherOptions>
{
    HRESULT __stdcall get_StandardInput(impl::abi_arg_out<Windows::Storage::Streams::IInputStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StandardInput());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StandardInput(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StandardInput(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StandardOutput(impl::abi_arg_out<Windows::Storage::Streams::IOutputStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StandardOutput());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StandardOutput(impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StandardOutput(*reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StandardError(impl::abi_arg_out<Windows::Storage::Streams::IOutputStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StandardError());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StandardError(impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StandardError(*reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WorkingDirectory(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WorkingDirectory());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_WorkingDirectory(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WorkingDirectory(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IProcessLauncherResult> : produce_base<D, Windows::System::IProcessLauncherResult>
{
    HRESULT __stdcall get_ExitCode(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IProcessLauncherStatics> : produce_base<D, Windows::System::IProcessLauncherStatics>
{
    HRESULT __stdcall abi_RunToCompletionAsync(impl::abi_arg_in<hstring> fileName, impl::abi_arg_in<hstring> args, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::System::ProcessLauncherResult>> asyncOperationResult) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperationResult = detach_abi(this->shim().RunToCompletionAsync(*reinterpret_cast<const hstring *>(&fileName), *reinterpret_cast<const hstring *>(&args)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperationResult = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RunToCompletionAsyncWithOptions(impl::abi_arg_in<hstring> fileName, impl::abi_arg_in<hstring> args, impl::abi_arg_in<Windows::System::IProcessLauncherOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::System::ProcessLauncherResult>> asyncOperationResult) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperationResult = detach_abi(this->shim().RunToCompletionAsync(*reinterpret_cast<const hstring *>(&fileName), *reinterpret_cast<const hstring *>(&args), *reinterpret_cast<const Windows::System::ProcessLauncherOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperationResult = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IProcessMemoryReport> : produce_base<D, Windows::System::IProcessMemoryReport>
{
    HRESULT __stdcall get_PrivateWorkingSetUsage(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrivateWorkingSetUsage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TotalWorkingSetUsage(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TotalWorkingSetUsage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IProtocolForResultsOperation> : produce_base<D, Windows::System::IProtocolForResultsOperation>
{
    HRESULT __stdcall abi_ReportCompleted(impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> data) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted(*reinterpret_cast<const Windows::Foundation::Collections::ValueSet *>(&data));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IRemoteLauncherOptions> : produce_base<D, Windows::System::IRemoteLauncherOptions>
{
    HRESULT __stdcall get_FallbackUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FallbackUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FallbackUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FallbackUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreferredAppIds(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreferredAppIds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IRemoteLauncherStatics> : produce_base<D, Windows::System::IRemoteLauncherStatics>
{
    HRESULT __stdcall abi_LaunchUriAsync(impl::abi_arg_in<Windows::System::RemoteSystems::IRemoteSystemConnectionRequest> remoteSystemConnectionRequest, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchUriAsync(*reinterpret_cast<const Windows::System::RemoteSystems::RemoteSystemConnectionRequest *>(&remoteSystemConnectionRequest), *reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchUriWithOptionsAsync(impl::abi_arg_in<Windows::System::RemoteSystems::IRemoteSystemConnectionRequest> remoteSystemConnectionRequest, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::System::IRemoteLauncherOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchUriAsync(*reinterpret_cast<const Windows::System::RemoteSystems::RemoteSystemConnectionRequest *>(&remoteSystemConnectionRequest), *reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::System::RemoteLauncherOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchUriWithDataAsync(impl::abi_arg_in<Windows::System::RemoteSystems::IRemoteSystemConnectionRequest> remoteSystemConnectionRequest, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::System::IRemoteLauncherOptions> options, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> inputData, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchUriAsync(*reinterpret_cast<const Windows::System::RemoteSystems::RemoteSystemConnectionRequest *>(&remoteSystemConnectionRequest), *reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::System::RemoteLauncherOptions *>(&options), *reinterpret_cast<const Windows::Foundation::Collections::ValueSet *>(&inputData)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IShutdownManagerStatics> : produce_base<D, Windows::System::IShutdownManagerStatics>
{
    HRESULT __stdcall abi_BeginShutdown(Windows::System::ShutdownKind shutdownKind, impl::abi_arg_in<Windows::Foundation::TimeSpan> timeout) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BeginShutdown(shutdownKind, *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&timeout));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CancelShutdown() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CancelShutdown();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::ITimeZoneSettingsStatics> : produce_base<D, Windows::System::ITimeZoneSettingsStatics>
{
    HRESULT __stdcall get_CurrentTimeZoneDisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentTimeZoneDisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedTimeZoneDisplayNames(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedTimeZoneDisplayNames());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanChangeTimeZone(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanChangeTimeZone());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ChangeTimeZoneByDisplayName(impl::abi_arg_in<hstring> timeZoneDisplayName) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChangeTimeZoneByDisplayName(*reinterpret_cast<const hstring *>(&timeZoneDisplayName));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IUser> : produce_base<D, Windows::System::IUser>
{
    HRESULT __stdcall get_NonRoamableId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NonRoamableId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AuthenticationStatus(Windows::System::UserAuthenticationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AuthenticationStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Type(Windows::System::UserType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPropertyAsync(impl::abi_arg_in<hstring> value, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetPropertyAsync(*reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPropertiesAsync(impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<hstring>> values, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IPropertySet>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetPropertiesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IVectorView<hstring> *>(&values)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPictureAsync(Windows::System::UserPictureSize desiredSize, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetPictureAsync(desiredSize));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IUserAuthenticationStatusChangeDeferral> : produce_base<D, Windows::System::IUserAuthenticationStatusChangeDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IUserAuthenticationStatusChangingEventArgs> : produce_base<D, Windows::System::IUserAuthenticationStatusChangingEventArgs>
{
    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::System::IUserAuthenticationStatusChangeDeferral> deferral) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deferral = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *deferral = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_User(impl::abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().User());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewStatus(Windows::System::UserAuthenticationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentStatus(Windows::System::UserAuthenticationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IUserChangedEventArgs> : produce_base<D, Windows::System::IUserChangedEventArgs>
{
    HRESULT __stdcall get_User(impl::abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().User());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IUserDeviceAssociationChangedEventArgs> : produce_base<D, Windows::System::IUserDeviceAssociationChangedEventArgs>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewUser(impl::abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewUser());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OldUser(impl::abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OldUser());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IUserDeviceAssociationStatics> : produce_base<D, Windows::System::IUserDeviceAssociationStatics>
{
    HRESULT __stdcall abi_FindUserFromDeviceId(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::System::IUser> user) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *user = detach_abi(this->shim().FindUserFromDeviceId(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *user = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_UserDeviceAssociationChanged(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::System::UserDeviceAssociationChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UserDeviceAssociationChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::System::UserDeviceAssociationChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UserDeviceAssociationChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserDeviceAssociationChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IUserPicker> : produce_base<D, Windows::System::IUserPicker>
{
    HRESULT __stdcall get_AllowGuestAccounts(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowGuestAccounts());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowGuestAccounts(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowGuestAccounts(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuggestedSelectedUser(impl::abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuggestedSelectedUser());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuggestedSelectedUser(impl::abi_arg_in<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuggestedSelectedUser(*reinterpret_cast<const Windows::System::User *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickSingleUserAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::System::User>> pickSingleUserOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pickSingleUserOperation = detach_abi(this->shim().PickSingleUserAsync());
            return S_OK;
        }
        catch (...)
        {
            *pickSingleUserOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IUserPickerStatics> : produce_base<D, Windows::System::IUserPickerStatics>
{
    HRESULT __stdcall abi_IsSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IUserStatics> : produce_base<D, Windows::System::IUserStatics>
{
    HRESULT __stdcall abi_CreateWatcher(impl::abi_arg_out<Windows::System::IUserWatcher> watcher) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *watcher = detach_abi(this->shim().CreateWatcher());
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindAllAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsyncByType(Windows::System::UserType type, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindAllAsync(type));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsyncByTypeAndStatus(Windows::System::UserType type, Windows::System::UserAuthenticationStatus status, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindAllAsync(type, status));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFromId(impl::abi_arg_in<hstring> nonRoamableId, impl::abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetFromId(*reinterpret_cast<const hstring *>(&nonRoamableId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::IUserWatcher> : produce_base<D, Windows::System::IUserWatcher>
{
    HRESULT __stdcall get_Status(Windows::System::UserWatcherStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Added(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Added(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Added(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Added(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Removed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Removed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Removed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Removed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Updated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Updated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Updated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Updated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AuthenticationStatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AuthenticationStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AuthenticationStatusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticationStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AuthenticationStatusChanging(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserAuthenticationStatusChangingEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AuthenticationStatusChanging(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserAuthenticationStatusChangingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AuthenticationStatusChanging(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticationStatusChanging(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EnumerationCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EnumerationCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EnumerationCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Stopped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Stopped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Stopped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::System {

template <typename D> uint64_t impl_IAppMemoryReport<D>::PrivateCommitUsage() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IAppMemoryReport)->get_PrivateCommitUsage(&value));
    return value;
}

template <typename D> uint64_t impl_IAppMemoryReport<D>::PeakPrivateCommitUsage() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IAppMemoryReport)->get_PeakPrivateCommitUsage(&value));
    return value;
}

template <typename D> uint64_t impl_IAppMemoryReport<D>::TotalCommitUsage() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IAppMemoryReport)->get_TotalCommitUsage(&value));
    return value;
}

template <typename D> uint64_t impl_IAppMemoryReport<D>::TotalCommitLimit() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IAppMemoryReport)->get_TotalCommitLimit(&value));
    return value;
}

template <typename D> uint64_t impl_IProcessMemoryReport<D>::PrivateWorkingSetUsage() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IProcessMemoryReport)->get_PrivateWorkingSetUsage(&value));
    return value;
}

template <typename D> uint64_t impl_IProcessMemoryReport<D>::TotalWorkingSetUsage() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IProcessMemoryReport)->get_TotalWorkingSetUsage(&value));
    return value;
}

template <typename D> uint64_t impl_IAppMemoryUsageLimitChangingEventArgs<D>::OldLimit() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IAppMemoryUsageLimitChangingEventArgs)->get_OldLimit(&value));
    return value;
}

template <typename D> uint64_t impl_IAppMemoryUsageLimitChangingEventArgs<D>::NewLimit() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IAppMemoryUsageLimitChangingEventArgs)->get_NewLimit(&value));
    return value;
}

template <typename D> uint64_t impl_IMemoryManagerStatics<D>::AppMemoryUsage() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IMemoryManagerStatics)->get_AppMemoryUsage(&value));
    return value;
}

template <typename D> uint64_t impl_IMemoryManagerStatics<D>::AppMemoryUsageLimit() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IMemoryManagerStatics)->get_AppMemoryUsageLimit(&value));
    return value;
}

template <typename D> Windows::System::AppMemoryUsageLevel impl_IMemoryManagerStatics<D>::AppMemoryUsageLevel() const
{
    Windows::System::AppMemoryUsageLevel value {};
    check_hresult(WINRT_SHIM(IMemoryManagerStatics)->get_AppMemoryUsageLevel(&value));
    return value;
}

template <typename D> event_token impl_IMemoryManagerStatics<D>::AppMemoryUsageIncreased(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMemoryManagerStatics)->add_AppMemoryUsageIncreased(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMemoryManagerStatics> impl_IMemoryManagerStatics<D>::AppMemoryUsageIncreased(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMemoryManagerStatics>(this, &ABI::Windows::System::IMemoryManagerStatics::remove_AppMemoryUsageIncreased, AppMemoryUsageIncreased(handler));
}

template <typename D> void impl_IMemoryManagerStatics<D>::AppMemoryUsageIncreased(event_token token) const
{
    check_hresult(WINRT_SHIM(IMemoryManagerStatics)->remove_AppMemoryUsageIncreased(token));
}

template <typename D> event_token impl_IMemoryManagerStatics<D>::AppMemoryUsageDecreased(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMemoryManagerStatics)->add_AppMemoryUsageDecreased(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMemoryManagerStatics> impl_IMemoryManagerStatics<D>::AppMemoryUsageDecreased(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMemoryManagerStatics>(this, &ABI::Windows::System::IMemoryManagerStatics::remove_AppMemoryUsageDecreased, AppMemoryUsageDecreased(handler));
}

template <typename D> void impl_IMemoryManagerStatics<D>::AppMemoryUsageDecreased(event_token token) const
{
    check_hresult(WINRT_SHIM(IMemoryManagerStatics)->remove_AppMemoryUsageDecreased(token));
}

template <typename D> event_token impl_IMemoryManagerStatics<D>::AppMemoryUsageLimitChanging(const Windows::Foundation::EventHandler<Windows::System::AppMemoryUsageLimitChangingEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMemoryManagerStatics)->add_AppMemoryUsageLimitChanging(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMemoryManagerStatics> impl_IMemoryManagerStatics<D>::AppMemoryUsageLimitChanging(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::System::AppMemoryUsageLimitChangingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMemoryManagerStatics>(this, &ABI::Windows::System::IMemoryManagerStatics::remove_AppMemoryUsageLimitChanging, AppMemoryUsageLimitChanging(handler));
}

template <typename D> void impl_IMemoryManagerStatics<D>::AppMemoryUsageLimitChanging(event_token token) const
{
    check_hresult(WINRT_SHIM(IMemoryManagerStatics)->remove_AppMemoryUsageLimitChanging(token));
}

template <typename D> Windows::System::AppMemoryReport impl_IMemoryManagerStatics2<D>::GetAppMemoryReport() const
{
    Windows::System::AppMemoryReport memoryReport { nullptr };
    check_hresult(WINRT_SHIM(IMemoryManagerStatics2)->abi_GetAppMemoryReport(put_abi(memoryReport)));
    return memoryReport;
}

template <typename D> Windows::System::ProcessMemoryReport impl_IMemoryManagerStatics2<D>::GetProcessMemoryReport() const
{
    Windows::System::ProcessMemoryReport memoryReport { nullptr };
    check_hresult(WINRT_SHIM(IMemoryManagerStatics2)->abi_GetProcessMemoryReport(put_abi(memoryReport)));
    return memoryReport;
}

template <typename D> bool impl_IMemoryManagerStatics3<D>::TrySetAppMemoryUsageLimit(uint64_t value) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IMemoryManagerStatics3)->abi_TrySetAppMemoryUsageLimit(value, &result));
    return result;
}

template <typename D> void impl_IProtocolForResultsOperation<D>::ReportCompleted(const Windows::Foundation::Collections::ValueSet & data) const
{
    check_hresult(WINRT_SHIM(IProtocolForResultsOperation)->abi_ReportCompleted(get_abi(data)));
}

template <typename D> hstring impl_IUser<D>::NonRoamableId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUser)->get_NonRoamableId(put_abi(value)));
    return value;
}

template <typename D> Windows::System::UserAuthenticationStatus impl_IUser<D>::AuthenticationStatus() const
{
    Windows::System::UserAuthenticationStatus value {};
    check_hresult(WINRT_SHIM(IUser)->get_AuthenticationStatus(&value));
    return value;
}

template <typename D> Windows::System::UserType impl_IUser<D>::Type() const
{
    Windows::System::UserType value {};
    check_hresult(WINRT_SHIM(IUser)->get_Type(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable> impl_IUser<D>::GetPropertyAsync(hstring_view value) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable> operation;
    check_hresult(WINRT_SHIM(IUser)->abi_GetPropertyAsync(get_abi(value), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IPropertySet> impl_IUser<D>::GetPropertiesAsync(vector_view<hstring> values) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IPropertySet> operation;
    check_hresult(WINRT_SHIM(IUser)->abi_GetPropertiesAsync(get_abi(values), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference> impl_IUser<D>::GetPictureAsync(Windows::System::UserPictureSize desiredSize) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference> operation;
    check_hresult(WINRT_SHIM(IUser)->abi_GetPictureAsync(desiredSize, put_abi(operation)));
    return operation;
}

template <typename D> Windows::System::UserWatcher impl_IUserStatics<D>::CreateWatcher() const
{
    Windows::System::UserWatcher watcher { nullptr };
    check_hresult(WINRT_SHIM(IUserStatics)->abi_CreateWatcher(put_abi(watcher)));
    return watcher;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>> impl_IUserStatics<D>::FindAllAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>> operation;
    check_hresult(WINRT_SHIM(IUserStatics)->abi_FindAllAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>> impl_IUserStatics<D>::FindAllAsync(Windows::System::UserType type) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>> operation;
    check_hresult(WINRT_SHIM(IUserStatics)->abi_FindAllAsyncByType(type, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>> impl_IUserStatics<D>::FindAllAsync(Windows::System::UserType type, Windows::System::UserAuthenticationStatus status) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>> operation;
    check_hresult(WINRT_SHIM(IUserStatics)->abi_FindAllAsyncByTypeAndStatus(type, status, put_abi(operation)));
    return operation;
}

template <typename D> Windows::System::User impl_IUserStatics<D>::GetFromId(hstring_view nonRoamableId) const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IUserStatics)->abi_GetFromId(get_abi(nonRoamableId), put_abi(value)));
    return value;
}

template <typename D> Windows::System::UserWatcherStatus impl_IUserWatcher<D>::Status() const
{
    Windows::System::UserWatcherStatus value {};
    check_hresult(WINRT_SHIM(IUserWatcher)->get_Status(&value));
    return value;
}

template <typename D> void impl_IUserWatcher<D>::Start() const
{
    check_hresult(WINRT_SHIM(IUserWatcher)->abi_Start());
}

template <typename D> void impl_IUserWatcher<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IUserWatcher)->abi_Stop());
}

template <typename D> event_token impl_IUserWatcher<D>::Added(const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUserWatcher)->add_Added(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IUserWatcher> impl_IUserWatcher<D>::Added(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IUserWatcher>(this, &ABI::Windows::System::IUserWatcher::remove_Added, Added(handler));
}

template <typename D> void impl_IUserWatcher<D>::Added(event_token token) const
{
    check_hresult(WINRT_SHIM(IUserWatcher)->remove_Added(token));
}

template <typename D> event_token impl_IUserWatcher<D>::Removed(const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUserWatcher)->add_Removed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IUserWatcher> impl_IUserWatcher<D>::Removed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IUserWatcher>(this, &ABI::Windows::System::IUserWatcher::remove_Removed, Removed(handler));
}

template <typename D> void impl_IUserWatcher<D>::Removed(event_token token) const
{
    check_hresult(WINRT_SHIM(IUserWatcher)->remove_Removed(token));
}

template <typename D> event_token impl_IUserWatcher<D>::Updated(const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUserWatcher)->add_Updated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IUserWatcher> impl_IUserWatcher<D>::Updated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IUserWatcher>(this, &ABI::Windows::System::IUserWatcher::remove_Updated, Updated(handler));
}

template <typename D> void impl_IUserWatcher<D>::Updated(event_token token) const
{
    check_hresult(WINRT_SHIM(IUserWatcher)->remove_Updated(token));
}

template <typename D> event_token impl_IUserWatcher<D>::AuthenticationStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUserWatcher)->add_AuthenticationStatusChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IUserWatcher> impl_IUserWatcher<D>::AuthenticationStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IUserWatcher>(this, &ABI::Windows::System::IUserWatcher::remove_AuthenticationStatusChanged, AuthenticationStatusChanged(handler));
}

template <typename D> void impl_IUserWatcher<D>::AuthenticationStatusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IUserWatcher)->remove_AuthenticationStatusChanged(token));
}

template <typename D> event_token impl_IUserWatcher<D>::AuthenticationStatusChanging(const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserAuthenticationStatusChangingEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUserWatcher)->add_AuthenticationStatusChanging(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IUserWatcher> impl_IUserWatcher<D>::AuthenticationStatusChanging(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::System::UserAuthenticationStatusChangingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IUserWatcher>(this, &ABI::Windows::System::IUserWatcher::remove_AuthenticationStatusChanging, AuthenticationStatusChanging(handler));
}

template <typename D> void impl_IUserWatcher<D>::AuthenticationStatusChanging(event_token token) const
{
    check_hresult(WINRT_SHIM(IUserWatcher)->remove_AuthenticationStatusChanging(token));
}

template <typename D> event_token impl_IUserWatcher<D>::EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUserWatcher)->add_EnumerationCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IUserWatcher> impl_IUserWatcher<D>::EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IUserWatcher>(this, &ABI::Windows::System::IUserWatcher::remove_EnumerationCompleted, EnumerationCompleted(handler));
}

template <typename D> void impl_IUserWatcher<D>::EnumerationCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IUserWatcher)->remove_EnumerationCompleted(token));
}

template <typename D> event_token impl_IUserWatcher<D>::Stopped(const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUserWatcher)->add_Stopped(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IUserWatcher> impl_IUserWatcher<D>::Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::System::UserWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IUserWatcher>(this, &ABI::Windows::System::IUserWatcher::remove_Stopped, Stopped(handler));
}

template <typename D> void impl_IUserWatcher<D>::Stopped(event_token token) const
{
    check_hresult(WINRT_SHIM(IUserWatcher)->remove_Stopped(token));
}

template <typename D> Windows::System::User impl_IUserChangedEventArgs<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IUserChangedEventArgs)->get_User(put_abi(value)));
    return value;
}

template <typename D> void impl_IUserAuthenticationStatusChangeDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IUserAuthenticationStatusChangeDeferral)->abi_Complete());
}

template <typename D> Windows::System::UserAuthenticationStatusChangeDeferral impl_IUserAuthenticationStatusChangingEventArgs<D>::GetDeferral() const
{
    Windows::System::UserAuthenticationStatusChangeDeferral deferral { nullptr };
    check_hresult(WINRT_SHIM(IUserAuthenticationStatusChangingEventArgs)->abi_GetDeferral(put_abi(deferral)));
    return deferral;
}

template <typename D> Windows::System::User impl_IUserAuthenticationStatusChangingEventArgs<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IUserAuthenticationStatusChangingEventArgs)->get_User(put_abi(value)));
    return value;
}

template <typename D> Windows::System::UserAuthenticationStatus impl_IUserAuthenticationStatusChangingEventArgs<D>::NewStatus() const
{
    Windows::System::UserAuthenticationStatus value {};
    check_hresult(WINRT_SHIM(IUserAuthenticationStatusChangingEventArgs)->get_NewStatus(&value));
    return value;
}

template <typename D> Windows::System::UserAuthenticationStatus impl_IUserAuthenticationStatusChangingEventArgs<D>::CurrentStatus() const
{
    Windows::System::UserAuthenticationStatus value {};
    check_hresult(WINRT_SHIM(IUserAuthenticationStatusChangingEventArgs)->get_CurrentStatus(&value));
    return value;
}

template <typename D> hstring impl_IKnownUserPropertiesStatics<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownUserPropertiesStatics)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownUserPropertiesStatics<D>::FirstName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownUserPropertiesStatics)->get_FirstName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownUserPropertiesStatics<D>::LastName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownUserPropertiesStatics)->get_LastName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownUserPropertiesStatics<D>::ProviderName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownUserPropertiesStatics)->get_ProviderName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownUserPropertiesStatics<D>::AccountName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownUserPropertiesStatics)->get_AccountName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownUserPropertiesStatics<D>::GuestHost() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownUserPropertiesStatics)->get_GuestHost(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownUserPropertiesStatics<D>::PrincipalName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownUserPropertiesStatics)->get_PrincipalName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownUserPropertiesStatics<D>::DomainName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownUserPropertiesStatics)->get_DomainName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKnownUserPropertiesStatics<D>::SessionInitiationProtocolUri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKnownUserPropertiesStatics)->get_SessionInitiationProtocolUri(put_abi(value)));
    return value;
}

template <typename D> bool impl_IUserPickerStatics<D>::IsSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUserPickerStatics)->abi_IsSupported(&value));
    return value;
}

template <typename D> bool impl_IUserPicker<D>::AllowGuestAccounts() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUserPicker)->get_AllowGuestAccounts(&value));
    return value;
}

template <typename D> void impl_IUserPicker<D>::AllowGuestAccounts(bool value) const
{
    check_hresult(WINRT_SHIM(IUserPicker)->put_AllowGuestAccounts(value));
}

template <typename D> Windows::System::User impl_IUserPicker<D>::SuggestedSelectedUser() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IUserPicker)->get_SuggestedSelectedUser(put_abi(value)));
    return value;
}

template <typename D> void impl_IUserPicker<D>::SuggestedSelectedUser(const Windows::System::User & value) const
{
    check_hresult(WINRT_SHIM(IUserPicker)->put_SuggestedSelectedUser(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::System::User> impl_IUserPicker<D>::PickSingleUserAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::System::User> pickSingleUserOperation;
    check_hresult(WINRT_SHIM(IUserPicker)->abi_PickSingleUserAsync(put_abi(pickSingleUserOperation)));
    return pickSingleUserOperation;
}

template <typename D> hstring impl_IUserDeviceAssociationChangedEventArgs<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUserDeviceAssociationChangedEventArgs)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::System::User impl_IUserDeviceAssociationChangedEventArgs<D>::NewUser() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IUserDeviceAssociationChangedEventArgs)->get_NewUser(put_abi(value)));
    return value;
}

template <typename D> Windows::System::User impl_IUserDeviceAssociationChangedEventArgs<D>::OldUser() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IUserDeviceAssociationChangedEventArgs)->get_OldUser(put_abi(value)));
    return value;
}

template <typename D> Windows::System::User impl_IUserDeviceAssociationStatics<D>::FindUserFromDeviceId(hstring_view deviceId) const
{
    Windows::System::User user { nullptr };
    check_hresult(WINRT_SHIM(IUserDeviceAssociationStatics)->abi_FindUserFromDeviceId(get_abi(deviceId), put_abi(user)));
    return user;
}

template <typename D> event_token impl_IUserDeviceAssociationStatics<D>::UserDeviceAssociationChanged(const Windows::Foundation::EventHandler<Windows::System::UserDeviceAssociationChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUserDeviceAssociationStatics)->add_UserDeviceAssociationChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IUserDeviceAssociationStatics> impl_IUserDeviceAssociationStatics<D>::UserDeviceAssociationChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::System::UserDeviceAssociationChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IUserDeviceAssociationStatics>(this, &ABI::Windows::System::IUserDeviceAssociationStatics::remove_UserDeviceAssociationChanged, UserDeviceAssociationChanged(handler));
}

template <typename D> void impl_IUserDeviceAssociationStatics<D>::UserDeviceAssociationChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IUserDeviceAssociationStatics)->remove_UserDeviceAssociationChanged(token));
}

template <typename D> Windows::System::LaunchUriStatus impl_ILaunchUriResult<D>::Status() const
{
    Windows::System::LaunchUriStatus value {};
    check_hresult(WINRT_SHIM(ILaunchUriResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_ILaunchUriResult<D>::Result() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(ILaunchUriResult)->get_Result(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::Point> impl_ILauncherUIOptions<D>::InvocationPoint() const
{
    Windows::Foundation::IReference<Windows::Foundation::Point> value;
    check_hresult(WINRT_SHIM(ILauncherUIOptions)->get_InvocationPoint(put_abi(value)));
    return value;
}

template <typename D> void impl_ILauncherUIOptions<D>::InvocationPoint(const optional<Windows::Foundation::Point> & value) const
{
    check_hresult(WINRT_SHIM(ILauncherUIOptions)->put_InvocationPoint(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::Rect> impl_ILauncherUIOptions<D>::SelectionRect() const
{
    Windows::Foundation::IReference<Windows::Foundation::Rect> value;
    check_hresult(WINRT_SHIM(ILauncherUIOptions)->get_SelectionRect(put_abi(value)));
    return value;
}

template <typename D> void impl_ILauncherUIOptions<D>::SelectionRect(const optional<Windows::Foundation::Rect> & value) const
{
    check_hresult(WINRT_SHIM(ILauncherUIOptions)->put_SelectionRect(get_abi(value)));
}

template <typename D> Windows::UI::Popups::Placement impl_ILauncherUIOptions<D>::PreferredPlacement() const
{
    Windows::UI::Popups::Placement value {};
    check_hresult(WINRT_SHIM(ILauncherUIOptions)->get_PreferredPlacement(&value));
    return value;
}

template <typename D> void impl_ILauncherUIOptions<D>::PreferredPlacement(Windows::UI::Popups::Placement value) const
{
    check_hresult(WINRT_SHIM(ILauncherUIOptions)->put_PreferredPlacement(value));
}

template <typename D> bool impl_ILauncherOptions<D>::TreatAsUntrusted() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILauncherOptions)->get_TreatAsUntrusted(&value));
    return value;
}

template <typename D> void impl_ILauncherOptions<D>::TreatAsUntrusted(bool value) const
{
    check_hresult(WINRT_SHIM(ILauncherOptions)->put_TreatAsUntrusted(value));
}

template <typename D> bool impl_ILauncherOptions<D>::DisplayApplicationPicker() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILauncherOptions)->get_DisplayApplicationPicker(&value));
    return value;
}

template <typename D> void impl_ILauncherOptions<D>::DisplayApplicationPicker(bool value) const
{
    check_hresult(WINRT_SHIM(ILauncherOptions)->put_DisplayApplicationPicker(value));
}

template <typename D> Windows::System::LauncherUIOptions impl_ILauncherOptions<D>::UI() const
{
    Windows::System::LauncherUIOptions value { nullptr };
    check_hresult(WINRT_SHIM(ILauncherOptions)->get_UI(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILauncherOptions<D>::PreferredApplicationPackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILauncherOptions)->get_PreferredApplicationPackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> void impl_ILauncherOptions<D>::PreferredApplicationPackageFamilyName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ILauncherOptions)->put_PreferredApplicationPackageFamilyName(get_abi(value)));
}

template <typename D> hstring impl_ILauncherOptions<D>::PreferredApplicationDisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILauncherOptions)->get_PreferredApplicationDisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_ILauncherOptions<D>::PreferredApplicationDisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ILauncherOptions)->put_PreferredApplicationDisplayName(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ILauncherOptions<D>::FallbackUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ILauncherOptions)->get_FallbackUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ILauncherOptions<D>::FallbackUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ILauncherOptions)->put_FallbackUri(get_abi(value)));
}

template <typename D> hstring impl_ILauncherOptions<D>::ContentType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILauncherOptions)->get_ContentType(put_abi(value)));
    return value;
}

template <typename D> void impl_ILauncherOptions<D>::ContentType(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ILauncherOptions)->put_ContentType(get_abi(value)));
}

template <typename D> hstring impl_ILauncherOptions2<D>::TargetApplicationPackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILauncherOptions2)->get_TargetApplicationPackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> void impl_ILauncherOptions2<D>::TargetApplicationPackageFamilyName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ILauncherOptions2)->put_TargetApplicationPackageFamilyName(get_abi(value)));
}

template <typename D> Windows::Storage::Search::StorageFileQueryResult impl_ILauncherOptions2<D>::NeighboringFilesQuery() const
{
    Windows::Storage::Search::StorageFileQueryResult value { nullptr };
    check_hresult(WINRT_SHIM(ILauncherOptions2)->get_NeighboringFilesQuery(put_abi(value)));
    return value;
}

template <typename D> void impl_ILauncherOptions2<D>::NeighboringFilesQuery(const Windows::Storage::Search::StorageFileQueryResult & value) const
{
    check_hresult(WINRT_SHIM(ILauncherOptions2)->put_NeighboringFilesQuery(get_abi(value)));
}

template <typename D> bool impl_ILauncherOptions3<D>::IgnoreAppUriHandlers() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILauncherOptions3)->get_IgnoreAppUriHandlers(&value));
    return value;
}

template <typename D> void impl_ILauncherOptions3<D>::IgnoreAppUriHandlers(bool value) const
{
    check_hresult(WINRT_SHIM(ILauncherOptions3)->put_IgnoreAppUriHandlers(value));
}

template <typename D> Windows::UI::ViewManagement::ViewSizePreference impl_ILauncherViewOptions<D>::DesiredRemainingView() const
{
    Windows::UI::ViewManagement::ViewSizePreference value {};
    check_hresult(WINRT_SHIM(ILauncherViewOptions)->get_DesiredRemainingView(&value));
    return value;
}

template <typename D> void impl_ILauncherViewOptions<D>::DesiredRemainingView(Windows::UI::ViewManagement::ViewSizePreference value) const
{
    check_hresult(WINRT_SHIM(ILauncherViewOptions)->put_DesiredRemainingView(value));
}

template <typename D> Windows::Foundation::Uri impl_IRemoteLauncherOptions<D>::FallbackUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IRemoteLauncherOptions)->get_FallbackUri(put_abi(value)));
    return value;
}

template <typename D> void impl_IRemoteLauncherOptions<D>::FallbackUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IRemoteLauncherOptions)->put_FallbackUri(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IRemoteLauncherOptions<D>::PreferredAppIds() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IRemoteLauncherOptions)->get_PreferredAppIds(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Storage::IStorageItem> impl_IFolderLauncherOptions<D>::ItemsToSelect() const
{
    Windows::Foundation::Collections::IVector<Windows::Storage::IStorageItem> value;
    check_hresult(WINRT_SHIM(IFolderLauncherOptions)->get_ItemsToSelect(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ILauncherStatics<D>::LaunchFileAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics)->abi_LaunchFileAsync(get_abi(file), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ILauncherStatics<D>::LaunchFileAsync(const Windows::Storage::IStorageFile & file, const Windows::System::LauncherOptions & options) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics)->abi_LaunchFileWithOptionsAsync(get_abi(file), get_abi(options), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ILauncherStatics<D>::LaunchUriAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics)->abi_LaunchUriAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ILauncherStatics<D>::LaunchUriAsync(const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics)->abi_LaunchUriWithOptionsAsync(get_abi(uri), get_abi(options), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> impl_ILauncherStatics2<D>::LaunchUriForResultsAsync(const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options) const
{
    Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics2)->abi_LaunchUriForResultsAsync(get_abi(uri), get_abi(options), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> impl_ILauncherStatics2<D>::LaunchUriForResultsAsync(const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData) const
{
    Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics2)->abi_LaunchUriForResultsWithDataAsync(get_abi(uri), get_abi(options), get_abi(inputData), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ILauncherStatics2<D>::LaunchUriAsync(const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics2)->abi_LaunchUriWithDataAsync(get_abi(uri), get_abi(options), get_abi(inputData), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> impl_ILauncherStatics2<D>::QueryUriSupportAsync(const Windows::Foundation::Uri & uri, Windows::System::LaunchQuerySupportType launchQuerySupportType) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics2)->abi_QueryUriSupportAsync(get_abi(uri), launchQuerySupportType, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> impl_ILauncherStatics2<D>::QueryUriSupportAsync(const Windows::Foundation::Uri & uri, Windows::System::LaunchQuerySupportType launchQuerySupportType, hstring_view packageFamilyName) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics2)->abi_QueryUriSupportWithPackageFamilyNameAsync(get_abi(uri), launchQuerySupportType, get_abi(packageFamilyName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> impl_ILauncherStatics2<D>::QueryFileSupportAsync(const Windows::Storage::StorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics2)->abi_QueryFileSupportAsync(get_abi(file), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> impl_ILauncherStatics2<D>::QueryFileSupportAsync(const Windows::Storage::StorageFile & file, hstring_view packageFamilyName) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics2)->abi_QueryFileSupportWithPackageFamilyNameAsync(get_abi(file), get_abi(packageFamilyName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> impl_ILauncherStatics2<D>::FindUriSchemeHandlersAsync(hstring_view scheme) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics2)->abi_FindUriSchemeHandlersAsync(get_abi(scheme), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> impl_ILauncherStatics2<D>::FindUriSchemeHandlersAsync(hstring_view scheme, Windows::System::LaunchQuerySupportType launchQuerySupportType) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics2)->abi_FindUriSchemeHandlersWithLaunchUriTypeAsync(get_abi(scheme), launchQuerySupportType, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> impl_ILauncherStatics2<D>::FindFileHandlersAsync(hstring_view extension) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics2)->abi_FindFileHandlersAsync(get_abi(extension), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ILauncherStatics3<D>::LaunchFolderAsync(const Windows::Storage::IStorageFolder & folder) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics3)->abi_LaunchFolderAsync(get_abi(folder), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ILauncherStatics3<D>::LaunchFolderAsync(const Windows::Storage::IStorageFolder & folder, const Windows::System::FolderLauncherOptions & options) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics3)->abi_LaunchFolderWithOptionsAsync(get_abi(folder), get_abi(options), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> impl_ILauncherStatics4<D>::QueryAppUriSupportAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics4)->abi_QueryAppUriSupportAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> impl_ILauncherStatics4<D>::QueryAppUriSupportAsync(const Windows::Foundation::Uri & uri, hstring_view packageFamilyName) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics4)->abi_QueryAppUriSupportWithPackageFamilyNameAsync(get_abi(uri), get_abi(packageFamilyName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> impl_ILauncherStatics4<D>::FindAppUriHandlersAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics4)->abi_FindAppUriHandlersAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus> impl_ILauncherStatics4<D>::LaunchUriForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics4)->abi_LaunchUriForUserAsync(get_abi(user), get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus> impl_ILauncherStatics4<D>::LaunchUriForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics4)->abi_LaunchUriWithOptionsForUserAsync(get_abi(user), get_abi(uri), get_abi(options), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus> impl_ILauncherStatics4<D>::LaunchUriForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics4)->abi_LaunchUriWithDataForUserAsync(get_abi(user), get_abi(uri), get_abi(options), get_abi(inputData), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> impl_ILauncherStatics4<D>::LaunchUriForResultsForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options) const
{
    Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics4)->abi_LaunchUriForResultsForUserAsync(get_abi(user), get_abi(uri), get_abi(options), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> impl_ILauncherStatics4<D>::LaunchUriForResultsForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData) const
{
    Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> operation;
    check_hresult(WINRT_SHIM(ILauncherStatics4)->abi_LaunchUriForResultsWithDataForUserAsync(get_abi(user), get_abi(uri), get_abi(options), get_abi(inputData), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus> impl_IRemoteLauncherStatics<D>::LaunchUriAsync(const Windows::System::RemoteSystems::RemoteSystemConnectionRequest & remoteSystemConnectionRequest, const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus> operation;
    check_hresult(WINRT_SHIM(IRemoteLauncherStatics)->abi_LaunchUriAsync(get_abi(remoteSystemConnectionRequest), get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus> impl_IRemoteLauncherStatics<D>::LaunchUriAsync(const Windows::System::RemoteSystems::RemoteSystemConnectionRequest & remoteSystemConnectionRequest, const Windows::Foundation::Uri & uri, const Windows::System::RemoteLauncherOptions & options) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus> operation;
    check_hresult(WINRT_SHIM(IRemoteLauncherStatics)->abi_LaunchUriWithOptionsAsync(get_abi(remoteSystemConnectionRequest), get_abi(uri), get_abi(options), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus> impl_IRemoteLauncherStatics<D>::LaunchUriAsync(const Windows::System::RemoteSystems::RemoteSystemConnectionRequest & remoteSystemConnectionRequest, const Windows::Foundation::Uri & uri, const Windows::System::RemoteLauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus> operation;
    check_hresult(WINRT_SHIM(IRemoteLauncherStatics)->abi_LaunchUriWithDataAsync(get_abi(remoteSystemConnectionRequest), get_abi(uri), get_abi(options), get_abi(inputData), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::Streams::IInputStream impl_IProcessLauncherOptions<D>::StandardInput() const
{
    Windows::Storage::Streams::IInputStream value;
    check_hresult(WINRT_SHIM(IProcessLauncherOptions)->get_StandardInput(put_abi(value)));
    return value;
}

template <typename D> void impl_IProcessLauncherOptions<D>::StandardInput(const Windows::Storage::Streams::IInputStream & value) const
{
    check_hresult(WINRT_SHIM(IProcessLauncherOptions)->put_StandardInput(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IOutputStream impl_IProcessLauncherOptions<D>::StandardOutput() const
{
    Windows::Storage::Streams::IOutputStream value;
    check_hresult(WINRT_SHIM(IProcessLauncherOptions)->get_StandardOutput(put_abi(value)));
    return value;
}

template <typename D> void impl_IProcessLauncherOptions<D>::StandardOutput(const Windows::Storage::Streams::IOutputStream & value) const
{
    check_hresult(WINRT_SHIM(IProcessLauncherOptions)->put_StandardOutput(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IOutputStream impl_IProcessLauncherOptions<D>::StandardError() const
{
    Windows::Storage::Streams::IOutputStream value;
    check_hresult(WINRT_SHIM(IProcessLauncherOptions)->get_StandardError(put_abi(value)));
    return value;
}

template <typename D> void impl_IProcessLauncherOptions<D>::StandardError(const Windows::Storage::Streams::IOutputStream & value) const
{
    check_hresult(WINRT_SHIM(IProcessLauncherOptions)->put_StandardError(get_abi(value)));
}

template <typename D> hstring impl_IProcessLauncherOptions<D>::WorkingDirectory() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProcessLauncherOptions)->get_WorkingDirectory(put_abi(value)));
    return value;
}

template <typename D> void impl_IProcessLauncherOptions<D>::WorkingDirectory(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IProcessLauncherOptions)->put_WorkingDirectory(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::System::ProcessLauncherResult> impl_IProcessLauncherStatics<D>::RunToCompletionAsync(hstring_view fileName, hstring_view args) const
{
    Windows::Foundation::IAsyncOperation<Windows::System::ProcessLauncherResult> asyncOperationResult;
    check_hresult(WINRT_SHIM(IProcessLauncherStatics)->abi_RunToCompletionAsync(get_abi(fileName), get_abi(args), put_abi(asyncOperationResult)));
    return asyncOperationResult;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::System::ProcessLauncherResult> impl_IProcessLauncherStatics<D>::RunToCompletionAsync(hstring_view fileName, hstring_view args, const Windows::System::ProcessLauncherOptions & options) const
{
    Windows::Foundation::IAsyncOperation<Windows::System::ProcessLauncherResult> asyncOperationResult;
    check_hresult(WINRT_SHIM(IProcessLauncherStatics)->abi_RunToCompletionAsyncWithOptions(get_abi(fileName), get_abi(args), get_abi(options), put_abi(asyncOperationResult)));
    return asyncOperationResult;
}

template <typename D> uint32_t impl_IProcessLauncherResult<D>::ExitCode() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IProcessLauncherResult)->get_ExitCode(&value));
    return value;
}

template <typename D> void impl_IShutdownManagerStatics<D>::BeginShutdown(Windows::System::ShutdownKind shutdownKind, const Windows::Foundation::TimeSpan & timeout) const
{
    check_hresult(WINRT_SHIM(IShutdownManagerStatics)->abi_BeginShutdown(shutdownKind, get_abi(timeout)));
}

template <typename D> void impl_IShutdownManagerStatics<D>::CancelShutdown() const
{
    check_hresult(WINRT_SHIM(IShutdownManagerStatics)->abi_CancelShutdown());
}

template <typename D> hstring impl_ITimeZoneSettingsStatics<D>::CurrentTimeZoneDisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITimeZoneSettingsStatics)->get_CurrentTimeZoneDisplayName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ITimeZoneSettingsStatics<D>::SupportedTimeZoneDisplayNames() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(ITimeZoneSettingsStatics)->get_SupportedTimeZoneDisplayNames(put_abi(value)));
    return value;
}

template <typename D> bool impl_ITimeZoneSettingsStatics<D>::CanChangeTimeZone() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITimeZoneSettingsStatics)->get_CanChangeTimeZone(&value));
    return value;
}

template <typename D> void impl_ITimeZoneSettingsStatics<D>::ChangeTimeZoneByDisplayName(hstring_view timeZoneDisplayName) const
{
    check_hresult(WINRT_SHIM(ITimeZoneSettingsStatics)->abi_ChangeTimeZoneByDisplayName(get_abi(timeZoneDisplayName)));
}

inline FolderLauncherOptions::FolderLauncherOptions() :
    FolderLauncherOptions(activate_instance<FolderLauncherOptions>())
{}

inline hstring KnownUserProperties::DisplayName()
{
    return get_activation_factory<KnownUserProperties, IKnownUserPropertiesStatics>().DisplayName();
}

inline hstring KnownUserProperties::FirstName()
{
    return get_activation_factory<KnownUserProperties, IKnownUserPropertiesStatics>().FirstName();
}

inline hstring KnownUserProperties::LastName()
{
    return get_activation_factory<KnownUserProperties, IKnownUserPropertiesStatics>().LastName();
}

inline hstring KnownUserProperties::ProviderName()
{
    return get_activation_factory<KnownUserProperties, IKnownUserPropertiesStatics>().ProviderName();
}

inline hstring KnownUserProperties::AccountName()
{
    return get_activation_factory<KnownUserProperties, IKnownUserPropertiesStatics>().AccountName();
}

inline hstring KnownUserProperties::GuestHost()
{
    return get_activation_factory<KnownUserProperties, IKnownUserPropertiesStatics>().GuestHost();
}

inline hstring KnownUserProperties::PrincipalName()
{
    return get_activation_factory<KnownUserProperties, IKnownUserPropertiesStatics>().PrincipalName();
}

inline hstring KnownUserProperties::DomainName()
{
    return get_activation_factory<KnownUserProperties, IKnownUserPropertiesStatics>().DomainName();
}

inline hstring KnownUserProperties::SessionInitiationProtocolUri()
{
    return get_activation_factory<KnownUserProperties, IKnownUserPropertiesStatics>().SessionInitiationProtocolUri();
}

inline Windows::Foundation::IAsyncOperation<bool> Launcher::LaunchFileAsync(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<Launcher, ILauncherStatics>().LaunchFileAsync(file);
}

inline Windows::Foundation::IAsyncOperation<bool> Launcher::LaunchFileAsync(const Windows::Storage::IStorageFile & file, const Windows::System::LauncherOptions & options)
{
    return get_activation_factory<Launcher, ILauncherStatics>().LaunchFileAsync(file, options);
}

inline Windows::Foundation::IAsyncOperation<bool> Launcher::LaunchUriAsync(const Windows::Foundation::Uri & uri)
{
    return get_activation_factory<Launcher, ILauncherStatics>().LaunchUriAsync(uri);
}

inline Windows::Foundation::IAsyncOperation<bool> Launcher::LaunchUriAsync(const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options)
{
    return get_activation_factory<Launcher, ILauncherStatics>().LaunchUriAsync(uri, options);
}

inline Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> Launcher::LaunchUriForResultsAsync(const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options)
{
    return get_activation_factory<Launcher, ILauncherStatics2>().LaunchUriForResultsAsync(uri, options);
}

inline Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> Launcher::LaunchUriForResultsAsync(const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData)
{
    return get_activation_factory<Launcher, ILauncherStatics2>().LaunchUriForResultsAsync(uri, options, inputData);
}

inline Windows::Foundation::IAsyncOperation<bool> Launcher::LaunchUriAsync(const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData)
{
    return get_activation_factory<Launcher, ILauncherStatics2>().LaunchUriAsync(uri, options, inputData);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> Launcher::QueryUriSupportAsync(const Windows::Foundation::Uri & uri, Windows::System::LaunchQuerySupportType launchQuerySupportType)
{
    return get_activation_factory<Launcher, ILauncherStatics2>().QueryUriSupportAsync(uri, launchQuerySupportType);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> Launcher::QueryUriSupportAsync(const Windows::Foundation::Uri & uri, Windows::System::LaunchQuerySupportType launchQuerySupportType, hstring_view packageFamilyName)
{
    return get_activation_factory<Launcher, ILauncherStatics2>().QueryUriSupportAsync(uri, launchQuerySupportType, packageFamilyName);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> Launcher::QueryFileSupportAsync(const Windows::Storage::StorageFile & file)
{
    return get_activation_factory<Launcher, ILauncherStatics2>().QueryFileSupportAsync(file);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> Launcher::QueryFileSupportAsync(const Windows::Storage::StorageFile & file, hstring_view packageFamilyName)
{
    return get_activation_factory<Launcher, ILauncherStatics2>().QueryFileSupportAsync(file, packageFamilyName);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> Launcher::FindUriSchemeHandlersAsync(hstring_view scheme)
{
    return get_activation_factory<Launcher, ILauncherStatics2>().FindUriSchemeHandlersAsync(scheme);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> Launcher::FindUriSchemeHandlersAsync(hstring_view scheme, Windows::System::LaunchQuerySupportType launchQuerySupportType)
{
    return get_activation_factory<Launcher, ILauncherStatics2>().FindUriSchemeHandlersAsync(scheme, launchQuerySupportType);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> Launcher::FindFileHandlersAsync(hstring_view extension)
{
    return get_activation_factory<Launcher, ILauncherStatics2>().FindFileHandlersAsync(extension);
}

inline Windows::Foundation::IAsyncOperation<bool> Launcher::LaunchFolderAsync(const Windows::Storage::IStorageFolder & folder)
{
    return get_activation_factory<Launcher, ILauncherStatics3>().LaunchFolderAsync(folder);
}

inline Windows::Foundation::IAsyncOperation<bool> Launcher::LaunchFolderAsync(const Windows::Storage::IStorageFolder & folder, const Windows::System::FolderLauncherOptions & options)
{
    return get_activation_factory<Launcher, ILauncherStatics3>().LaunchFolderAsync(folder, options);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> Launcher::QueryAppUriSupportAsync(const Windows::Foundation::Uri & uri)
{
    return get_activation_factory<Launcher, ILauncherStatics4>().QueryAppUriSupportAsync(uri);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> Launcher::QueryAppUriSupportAsync(const Windows::Foundation::Uri & uri, hstring_view packageFamilyName)
{
    return get_activation_factory<Launcher, ILauncherStatics4>().QueryAppUriSupportAsync(uri, packageFamilyName);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> Launcher::FindAppUriHandlersAsync(const Windows::Foundation::Uri & uri)
{
    return get_activation_factory<Launcher, ILauncherStatics4>().FindAppUriHandlersAsync(uri);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus> Launcher::LaunchUriForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri)
{
    return get_activation_factory<Launcher, ILauncherStatics4>().LaunchUriForUserAsync(user, uri);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus> Launcher::LaunchUriForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options)
{
    return get_activation_factory<Launcher, ILauncherStatics4>().LaunchUriForUserAsync(user, uri, options);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus> Launcher::LaunchUriForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData)
{
    return get_activation_factory<Launcher, ILauncherStatics4>().LaunchUriForUserAsync(user, uri, options, inputData);
}

inline Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> Launcher::LaunchUriForResultsForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options)
{
    return get_activation_factory<Launcher, ILauncherStatics4>().LaunchUriForResultsForUserAsync(user, uri, options);
}

inline Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> Launcher::LaunchUriForResultsForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData)
{
    return get_activation_factory<Launcher, ILauncherStatics4>().LaunchUriForResultsForUserAsync(user, uri, options, inputData);
}

inline LauncherOptions::LauncherOptions() :
    LauncherOptions(activate_instance<LauncherOptions>())
{}

inline uint64_t MemoryManager::AppMemoryUsage()
{
    return get_activation_factory<MemoryManager, IMemoryManagerStatics>().AppMemoryUsage();
}

inline uint64_t MemoryManager::AppMemoryUsageLimit()
{
    return get_activation_factory<MemoryManager, IMemoryManagerStatics>().AppMemoryUsageLimit();
}

inline Windows::System::AppMemoryUsageLevel MemoryManager::AppMemoryUsageLevel()
{
    return get_activation_factory<MemoryManager, IMemoryManagerStatics>().AppMemoryUsageLevel();
}

inline event_token MemoryManager::AppMemoryUsageIncreased(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<MemoryManager, IMemoryManagerStatics>().AppMemoryUsageIncreased(handler);
}

inline factory_event_revoker<IMemoryManagerStatics> MemoryManager::AppMemoryUsageIncreased(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<MemoryManager, IMemoryManagerStatics>();
    return { factory, &ABI::Windows::System::IMemoryManagerStatics::remove_AppMemoryUsageIncreased, factory.AppMemoryUsageIncreased(handler) };
}

inline void MemoryManager::AppMemoryUsageIncreased(event_token token)
{
    get_activation_factory<MemoryManager, IMemoryManagerStatics>().AppMemoryUsageIncreased(token);
}

inline event_token MemoryManager::AppMemoryUsageDecreased(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<MemoryManager, IMemoryManagerStatics>().AppMemoryUsageDecreased(handler);
}

inline factory_event_revoker<IMemoryManagerStatics> MemoryManager::AppMemoryUsageDecreased(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<MemoryManager, IMemoryManagerStatics>();
    return { factory, &ABI::Windows::System::IMemoryManagerStatics::remove_AppMemoryUsageDecreased, factory.AppMemoryUsageDecreased(handler) };
}

inline void MemoryManager::AppMemoryUsageDecreased(event_token token)
{
    get_activation_factory<MemoryManager, IMemoryManagerStatics>().AppMemoryUsageDecreased(token);
}

inline event_token MemoryManager::AppMemoryUsageLimitChanging(const Windows::Foundation::EventHandler<Windows::System::AppMemoryUsageLimitChangingEventArgs> & handler)
{
    return get_activation_factory<MemoryManager, IMemoryManagerStatics>().AppMemoryUsageLimitChanging(handler);
}

inline factory_event_revoker<IMemoryManagerStatics> MemoryManager::AppMemoryUsageLimitChanging(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::System::AppMemoryUsageLimitChangingEventArgs> & handler)
{
    auto factory = get_activation_factory<MemoryManager, IMemoryManagerStatics>();
    return { factory, &ABI::Windows::System::IMemoryManagerStatics::remove_AppMemoryUsageLimitChanging, factory.AppMemoryUsageLimitChanging(handler) };
}

inline void MemoryManager::AppMemoryUsageLimitChanging(event_token token)
{
    get_activation_factory<MemoryManager, IMemoryManagerStatics>().AppMemoryUsageLimitChanging(token);
}

inline Windows::System::AppMemoryReport MemoryManager::GetAppMemoryReport()
{
    return get_activation_factory<MemoryManager, IMemoryManagerStatics2>().GetAppMemoryReport();
}

inline Windows::System::ProcessMemoryReport MemoryManager::GetProcessMemoryReport()
{
    return get_activation_factory<MemoryManager, IMemoryManagerStatics2>().GetProcessMemoryReport();
}

inline bool MemoryManager::TrySetAppMemoryUsageLimit(uint64_t value)
{
    return get_activation_factory<MemoryManager, IMemoryManagerStatics3>().TrySetAppMemoryUsageLimit(value);
}

inline Windows::Foundation::IAsyncOperation<Windows::System::ProcessLauncherResult> ProcessLauncher::RunToCompletionAsync(hstring_view fileName, hstring_view args)
{
    return get_activation_factory<ProcessLauncher, IProcessLauncherStatics>().RunToCompletionAsync(fileName, args);
}

inline Windows::Foundation::IAsyncOperation<Windows::System::ProcessLauncherResult> ProcessLauncher::RunToCompletionAsync(hstring_view fileName, hstring_view args, const Windows::System::ProcessLauncherOptions & options)
{
    return get_activation_factory<ProcessLauncher, IProcessLauncherStatics>().RunToCompletionAsync(fileName, args, options);
}

inline ProcessLauncherOptions::ProcessLauncherOptions() :
    ProcessLauncherOptions(activate_instance<ProcessLauncherOptions>())
{}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus> RemoteLauncher::LaunchUriAsync(const Windows::System::RemoteSystems::RemoteSystemConnectionRequest & remoteSystemConnectionRequest, const Windows::Foundation::Uri & uri)
{
    return get_activation_factory<RemoteLauncher, IRemoteLauncherStatics>().LaunchUriAsync(remoteSystemConnectionRequest, uri);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus> RemoteLauncher::LaunchUriAsync(const Windows::System::RemoteSystems::RemoteSystemConnectionRequest & remoteSystemConnectionRequest, const Windows::Foundation::Uri & uri, const Windows::System::RemoteLauncherOptions & options)
{
    return get_activation_factory<RemoteLauncher, IRemoteLauncherStatics>().LaunchUriAsync(remoteSystemConnectionRequest, uri, options);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus> RemoteLauncher::LaunchUriAsync(const Windows::System::RemoteSystems::RemoteSystemConnectionRequest & remoteSystemConnectionRequest, const Windows::Foundation::Uri & uri, const Windows::System::RemoteLauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData)
{
    return get_activation_factory<RemoteLauncher, IRemoteLauncherStatics>().LaunchUriAsync(remoteSystemConnectionRequest, uri, options, inputData);
}

inline RemoteLauncherOptions::RemoteLauncherOptions() :
    RemoteLauncherOptions(activate_instance<RemoteLauncherOptions>())
{}

inline void ShutdownManager::BeginShutdown(Windows::System::ShutdownKind shutdownKind, const Windows::Foundation::TimeSpan & timeout)
{
    get_activation_factory<ShutdownManager, IShutdownManagerStatics>().BeginShutdown(shutdownKind, timeout);
}

inline void ShutdownManager::CancelShutdown()
{
    get_activation_factory<ShutdownManager, IShutdownManagerStatics>().CancelShutdown();
}

inline hstring TimeZoneSettings::CurrentTimeZoneDisplayName()
{
    return get_activation_factory<TimeZoneSettings, ITimeZoneSettingsStatics>().CurrentTimeZoneDisplayName();
}

inline Windows::Foundation::Collections::IVectorView<hstring> TimeZoneSettings::SupportedTimeZoneDisplayNames()
{
    return get_activation_factory<TimeZoneSettings, ITimeZoneSettingsStatics>().SupportedTimeZoneDisplayNames();
}

inline bool TimeZoneSettings::CanChangeTimeZone()
{
    return get_activation_factory<TimeZoneSettings, ITimeZoneSettingsStatics>().CanChangeTimeZone();
}

inline void TimeZoneSettings::ChangeTimeZoneByDisplayName(hstring_view timeZoneDisplayName)
{
    get_activation_factory<TimeZoneSettings, ITimeZoneSettingsStatics>().ChangeTimeZoneByDisplayName(timeZoneDisplayName);
}

inline Windows::System::UserWatcher User::CreateWatcher()
{
    return get_activation_factory<User, IUserStatics>().CreateWatcher();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>> User::FindAllAsync()
{
    return get_activation_factory<User, IUserStatics>().FindAllAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>> User::FindAllAsync(Windows::System::UserType type)
{
    return get_activation_factory<User, IUserStatics>().FindAllAsync(type);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>> User::FindAllAsync(Windows::System::UserType type, Windows::System::UserAuthenticationStatus status)
{
    return get_activation_factory<User, IUserStatics>().FindAllAsync(type, status);
}

inline Windows::System::User User::GetFromId(hstring_view nonRoamableId)
{
    return get_activation_factory<User, IUserStatics>().GetFromId(nonRoamableId);
}

inline Windows::System::User UserDeviceAssociation::FindUserFromDeviceId(hstring_view deviceId)
{
    return get_activation_factory<UserDeviceAssociation, IUserDeviceAssociationStatics>().FindUserFromDeviceId(deviceId);
}

inline event_token UserDeviceAssociation::UserDeviceAssociationChanged(const Windows::Foundation::EventHandler<Windows::System::UserDeviceAssociationChangedEventArgs> & handler)
{
    return get_activation_factory<UserDeviceAssociation, IUserDeviceAssociationStatics>().UserDeviceAssociationChanged(handler);
}

inline factory_event_revoker<IUserDeviceAssociationStatics> UserDeviceAssociation::UserDeviceAssociationChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::System::UserDeviceAssociationChangedEventArgs> & handler)
{
    auto factory = get_activation_factory<UserDeviceAssociation, IUserDeviceAssociationStatics>();
    return { factory, &ABI::Windows::System::IUserDeviceAssociationStatics::remove_UserDeviceAssociationChanged, factory.UserDeviceAssociationChanged(handler) };
}

inline void UserDeviceAssociation::UserDeviceAssociationChanged(event_token token)
{
    get_activation_factory<UserDeviceAssociation, IUserDeviceAssociationStatics>().UserDeviceAssociationChanged(token);
}

inline UserPicker::UserPicker() :
    UserPicker(activate_instance<UserPicker>())
{}

inline bool UserPicker::IsSupported()
{
    return get_activation_factory<UserPicker, IUserPickerStatics>().IsSupported();
}

}

}
#pragma warning(pop)
