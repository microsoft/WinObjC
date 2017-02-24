// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.System.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Management.Deployment.3.h"
#include "internal/Windows.ApplicationModel.Store.Preview.InstallControl.3.h"
#include "Windows.ApplicationModel.Store.Preview.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem> : produce_base<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem>
{
    HRESULT __stdcall get_ProductId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProductId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InstallType(Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InstallType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsUserInitiated(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsUserInitiated());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentStatus(impl::abi_arg_out<Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetCurrentStatus());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Cancel() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Cancel();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Pause() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Pause();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Restart() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Restart();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Completed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Completed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Completed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().StatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StatusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem2> : produce_base<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem2>
{
    HRESULT __stdcall abi_CancelWithTelemetry(impl::abi_arg_in<hstring> correlationVector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Cancel(*reinterpret_cast<const hstring *>(&correlationVector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PauseWithTelemetry(impl::abi_arg_in<hstring> correlationVector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Pause(*reinterpret_cast<const hstring *>(&correlationVector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RestartWithTelemetry(impl::abi_arg_in<hstring> correlationVector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Restart(*reinterpret_cast<const hstring *>(&correlationVector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager> : produce_base<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>
{
    HRESULT __stdcall get_AppInstallItems(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppInstallItems());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Cancel(impl::abi_arg_in<hstring> productId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Cancel(*reinterpret_cast<const hstring *>(&productId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Pause(impl::abi_arg_in<hstring> productId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Pause(*reinterpret_cast<const hstring *>(&productId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Restart(impl::abi_arg_in<hstring> productId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Restart(*reinterpret_cast<const hstring *>(&productId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ItemCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManager, Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManagerItemEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ItemCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManager, Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManagerItemEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ItemCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ItemStatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManager, Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManagerItemEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ItemStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManager, Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManagerItemEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ItemStatusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoUpdateSetting(Windows::ApplicationModel::Store::Preview::InstallControl::AutoUpdateSetting * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoUpdateSetting());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoUpdateSetting(Windows::ApplicationModel::Store::Preview::InstallControl::AutoUpdateSetting value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoUpdateSetting(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AcquisitionIdentity(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AcquisitionIdentity());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AcquisitionIdentity(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcquisitionIdentity(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsApplicableAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> skuId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetIsApplicableAsync(*reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&skuId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartAppInstallAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> skuId, bool repair, bool forceUseOfNonRemovableStorage, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StartAppInstallAsync(*reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&skuId), repair, forceUseOfNonRemovableStorage));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateAppByPackageFamilyNameAsync(impl::abi_arg_in<hstring> packageFamilyName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().UpdateAppByPackageFamilyNameAsync(*reinterpret_cast<const hstring *>(&packageFamilyName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SearchForUpdatesAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> skuId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SearchForUpdatesAsync(*reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&skuId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SearchForAllUpdatesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SearchForAllUpdatesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsStoreBlockedByPolicyAsync(impl::abi_arg_in<hstring> storeClientName, impl::abi_arg_in<hstring> storeClientPublisher, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().IsStoreBlockedByPolicyAsync(*reinterpret_cast<const hstring *>(&storeClientName), *reinterpret_cast<const hstring *>(&storeClientPublisher)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsAppAllowedToInstallAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetIsAppAllowedToInstallAsync(*reinterpret_cast<const hstring *>(&productId)));
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
struct produce<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2> : produce_base<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>
{
    HRESULT __stdcall abi_StartAppInstallWithTelemetryAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> skuId, bool repair, bool forceUseOfNonRemovableStorage, impl::abi_arg_in<hstring> catalogId, impl::abi_arg_in<hstring> bundleId, impl::abi_arg_in<hstring> correlationVector, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StartAppInstallAsync(*reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&skuId), repair, forceUseOfNonRemovableStorage, *reinterpret_cast<const hstring *>(&catalogId), *reinterpret_cast<const hstring *>(&bundleId), *reinterpret_cast<const hstring *>(&correlationVector)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateAppByPackageFamilyNameWithTelemetryAsync(impl::abi_arg_in<hstring> packageFamilyName, impl::abi_arg_in<hstring> correlationVector, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().UpdateAppByPackageFamilyNameAsync(*reinterpret_cast<const hstring *>(&packageFamilyName), *reinterpret_cast<const hstring *>(&correlationVector)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SearchForUpdatesWithTelemetryAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> skuId, impl::abi_arg_in<hstring> catalogId, impl::abi_arg_in<hstring> correlationVector, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SearchForUpdatesAsync(*reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&skuId), *reinterpret_cast<const hstring *>(&catalogId), *reinterpret_cast<const hstring *>(&correlationVector)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SearchForAllUpdatesWithTelemetryAsync(impl::abi_arg_in<hstring> correlationVector, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SearchForAllUpdatesAsync(*reinterpret_cast<const hstring *>(&correlationVector)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsAppAllowedToInstallWithTelemetryAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> skuId, impl::abi_arg_in<hstring> catalogId, impl::abi_arg_in<hstring> correlationVector, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetIsAppAllowedToInstallAsync(*reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&skuId), *reinterpret_cast<const hstring *>(&catalogId), *reinterpret_cast<const hstring *>(&correlationVector)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CancelWithTelemetry(impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> correlationVector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Cancel(*reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&correlationVector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PauseWithTelemetry(impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> correlationVector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Pause(*reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&correlationVector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RestartWithTelemetry(impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> correlationVector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Restart(*reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&correlationVector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3> : produce_base<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3>
{
    HRESULT __stdcall abi_StartProductInstallAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> catalogId, impl::abi_arg_in<hstring> flightId, impl::abi_arg_in<hstring> clientId, bool repair, bool forceUseOfNonRemovableStorage, impl::abi_arg_in<hstring> correlationVector, impl::abi_arg_in<Windows::Management::Deployment::IPackageVolume> targetVolume, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StartProductInstallAsync(*reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&catalogId), *reinterpret_cast<const hstring *>(&flightId), *reinterpret_cast<const hstring *>(&clientId), repair, forceUseOfNonRemovableStorage, *reinterpret_cast<const hstring *>(&correlationVector), *reinterpret_cast<const Windows::Management::Deployment::PackageVolume *>(&targetVolume)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartProductInstallForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> catalogId, impl::abi_arg_in<hstring> flightId, impl::abi_arg_in<hstring> clientId, bool repair, bool forceUseOfNonRemovableStorage, impl::abi_arg_in<hstring> correlationVector, impl::abi_arg_in<Windows::Management::Deployment::IPackageVolume> targetVolume, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StartProductInstallForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&catalogId), *reinterpret_cast<const hstring *>(&flightId), *reinterpret_cast<const hstring *>(&clientId), repair, forceUseOfNonRemovableStorage, *reinterpret_cast<const hstring *>(&correlationVector), *reinterpret_cast<const Windows::Management::Deployment::PackageVolume *>(&targetVolume)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateAppByPackageFamilyNameForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<hstring> packageFamilyName, impl::abi_arg_in<hstring> correlationVector, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().UpdateAppByPackageFamilyNameForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const hstring *>(&packageFamilyName), *reinterpret_cast<const hstring *>(&correlationVector)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SearchForUpdatesForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> skuId, impl::abi_arg_in<hstring> catalogId, impl::abi_arg_in<hstring> correlationVector, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SearchForUpdatesForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&skuId), *reinterpret_cast<const hstring *>(&catalogId), *reinterpret_cast<const hstring *>(&correlationVector)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SearchForAllUpdatesForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<hstring> correlationVector, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SearchForAllUpdatesForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const hstring *>(&correlationVector)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsAppAllowedToInstallForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> skuId, impl::abi_arg_in<hstring> catalogId, impl::abi_arg_in<hstring> correlationVector, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetIsAppAllowedToInstallForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&skuId), *reinterpret_cast<const hstring *>(&catalogId), *reinterpret_cast<const hstring *>(&correlationVector)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsApplicableForUserAsync(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> skuId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetIsApplicableForUserAsync(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&skuId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveToFrontOfDownloadQueue(impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> correlationVector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MoveToFrontOfDownloadQueue(*reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&correlationVector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManagerItemEventArgs> : produce_base<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManagerItemEventArgs>
{
    HRESULT __stdcall get_Item(impl::abi_arg_out<Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Item());
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
struct produce<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus> : produce_base<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus>
{
    HRESULT __stdcall get_InstallState(Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InstallState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DownloadSizeInBytes(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DownloadSizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BytesDownloaded(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BytesDownloaded());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PercentComplete(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PercentComplete());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ErrorCode(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus2> : produce_base<D, Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus2>
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

    HRESULT __stdcall get_ReadyForLaunch(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadyForLaunch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Store::Preview::InstallControl {

template <typename D> Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallState impl_IAppInstallStatus<D>::InstallState() const
{
    Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallState value {};
    check_hresult(WINRT_SHIM(IAppInstallStatus)->get_InstallState(&value));
    return value;
}

template <typename D> uint64_t impl_IAppInstallStatus<D>::DownloadSizeInBytes() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IAppInstallStatus)->get_DownloadSizeInBytes(&value));
    return value;
}

template <typename D> uint64_t impl_IAppInstallStatus<D>::BytesDownloaded() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IAppInstallStatus)->get_BytesDownloaded(&value));
    return value;
}

template <typename D> double impl_IAppInstallStatus<D>::PercentComplete() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAppInstallStatus)->get_PercentComplete(&value));
    return value;
}

template <typename D> HRESULT impl_IAppInstallStatus<D>::ErrorCode() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IAppInstallStatus)->get_ErrorCode(&value));
    return value;
}

template <typename D> Windows::System::User impl_IAppInstallStatus2<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IAppInstallStatus2)->get_User(put_abi(value)));
    return value;
}

template <typename D> bool impl_IAppInstallStatus2<D>::ReadyForLaunch() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppInstallStatus2)->get_ReadyForLaunch(&value));
    return value;
}

template <typename D> hstring impl_IAppInstallItem<D>::ProductId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppInstallItem)->get_ProductId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppInstallItem<D>::PackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppInstallItem)->get_PackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallType impl_IAppInstallItem<D>::InstallType() const
{
    Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallType value {};
    check_hresult(WINRT_SHIM(IAppInstallItem)->get_InstallType(&value));
    return value;
}

template <typename D> bool impl_IAppInstallItem<D>::IsUserInitiated() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppInstallItem)->get_IsUserInitiated(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallStatus impl_IAppInstallItem<D>::GetCurrentStatus() const
{
    Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallStatus result { nullptr };
    check_hresult(WINRT_SHIM(IAppInstallItem)->abi_GetCurrentStatus(put_abi(result)));
    return result;
}

template <typename D> void impl_IAppInstallItem<D>::Cancel() const
{
    check_hresult(WINRT_SHIM(IAppInstallItem)->abi_Cancel());
}

template <typename D> void impl_IAppInstallItem<D>::Pause() const
{
    check_hresult(WINRT_SHIM(IAppInstallItem)->abi_Pause());
}

template <typename D> void impl_IAppInstallItem<D>::Restart() const
{
    check_hresult(WINRT_SHIM(IAppInstallItem)->abi_Restart());
}

template <typename D> event_token impl_IAppInstallItem<D>::Completed(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAppInstallItem)->add_Completed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAppInstallItem> impl_IAppInstallItem<D>::Completed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IAppInstallItem>(this, &ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem::remove_Completed, Completed(handler));
}

template <typename D> void impl_IAppInstallItem<D>::Completed(event_token token) const
{
    check_hresult(WINRT_SHIM(IAppInstallItem)->remove_Completed(token));
}

template <typename D> event_token impl_IAppInstallItem<D>::StatusChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAppInstallItem)->add_StatusChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAppInstallItem> impl_IAppInstallItem<D>::StatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IAppInstallItem>(this, &ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem::remove_StatusChanged, StatusChanged(handler));
}

template <typename D> void impl_IAppInstallItem<D>::StatusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IAppInstallItem)->remove_StatusChanged(token));
}

template <typename D> void impl_IAppInstallItem2<D>::Cancel(hstring_view correlationVector) const
{
    check_hresult(WINRT_SHIM(IAppInstallItem2)->abi_CancelWithTelemetry(get_abi(correlationVector)));
}

template <typename D> void impl_IAppInstallItem2<D>::Pause(hstring_view correlationVector) const
{
    check_hresult(WINRT_SHIM(IAppInstallItem2)->abi_PauseWithTelemetry(get_abi(correlationVector)));
}

template <typename D> void impl_IAppInstallItem2<D>::Restart(hstring_view correlationVector) const
{
    check_hresult(WINRT_SHIM(IAppInstallItem2)->abi_RestartWithTelemetry(get_abi(correlationVector)));
}

template <typename D> Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem impl_IAppInstallManagerItemEventArgs<D>::Item() const
{
    Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem value { nullptr };
    check_hresult(WINRT_SHIM(IAppInstallManagerItemEventArgs)->get_Item(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> impl_IAppInstallManager<D>::AppInstallItems() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> value;
    check_hresult(WINRT_SHIM(IAppInstallManager)->get_AppInstallItems(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppInstallManager<D>::Cancel(hstring_view productId) const
{
    check_hresult(WINRT_SHIM(IAppInstallManager)->abi_Cancel(get_abi(productId)));
}

template <typename D> void impl_IAppInstallManager<D>::Pause(hstring_view productId) const
{
    check_hresult(WINRT_SHIM(IAppInstallManager)->abi_Pause(get_abi(productId)));
}

template <typename D> void impl_IAppInstallManager<D>::Restart(hstring_view productId) const
{
    check_hresult(WINRT_SHIM(IAppInstallManager)->abi_Restart(get_abi(productId)));
}

template <typename D> event_token impl_IAppInstallManager<D>::ItemCompleted(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManager, Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManagerItemEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAppInstallManager)->add_ItemCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAppInstallManager> impl_IAppInstallManager<D>::ItemCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManager, Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManagerItemEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAppInstallManager>(this, &ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager::remove_ItemCompleted, ItemCompleted(handler));
}

template <typename D> void impl_IAppInstallManager<D>::ItemCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IAppInstallManager)->remove_ItemCompleted(token));
}

template <typename D> event_token impl_IAppInstallManager<D>::ItemStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManager, Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManagerItemEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAppInstallManager)->add_ItemStatusChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAppInstallManager> impl_IAppInstallManager<D>::ItemStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManager, Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManagerItemEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAppInstallManager>(this, &ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager::remove_ItemStatusChanged, ItemStatusChanged(handler));
}

template <typename D> void impl_IAppInstallManager<D>::ItemStatusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IAppInstallManager)->remove_ItemStatusChanged(token));
}

template <typename D> Windows::ApplicationModel::Store::Preview::InstallControl::AutoUpdateSetting impl_IAppInstallManager<D>::AutoUpdateSetting() const
{
    Windows::ApplicationModel::Store::Preview::InstallControl::AutoUpdateSetting value {};
    check_hresult(WINRT_SHIM(IAppInstallManager)->get_AutoUpdateSetting(&value));
    return value;
}

template <typename D> void impl_IAppInstallManager<D>::AutoUpdateSetting(Windows::ApplicationModel::Store::Preview::InstallControl::AutoUpdateSetting value) const
{
    check_hresult(WINRT_SHIM(IAppInstallManager)->put_AutoUpdateSetting(value));
}

template <typename D> hstring impl_IAppInstallManager<D>::AcquisitionIdentity() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppInstallManager)->get_AcquisitionIdentity(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppInstallManager<D>::AcquisitionIdentity(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAppInstallManager)->put_AcquisitionIdentity(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppInstallManager<D>::GetIsApplicableAsync(hstring_view productId, hstring_view skuId) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager)->abi_GetIsApplicableAsync(get_abi(productId), get_abi(skuId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> impl_IAppInstallManager<D>::StartAppInstallAsync(hstring_view productId, hstring_view skuId, bool repair, bool forceUseOfNonRemovableStorage) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager)->abi_StartAppInstallAsync(get_abi(productId), get_abi(skuId), repair, forceUseOfNonRemovableStorage, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> impl_IAppInstallManager<D>::UpdateAppByPackageFamilyNameAsync(hstring_view packageFamilyName) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager)->abi_UpdateAppByPackageFamilyNameAsync(get_abi(packageFamilyName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> impl_IAppInstallManager<D>::SearchForUpdatesAsync(hstring_view productId, hstring_view skuId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager)->abi_SearchForUpdatesAsync(get_abi(productId), get_abi(skuId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> impl_IAppInstallManager<D>::SearchForAllUpdatesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager)->abi_SearchForAllUpdatesAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppInstallManager<D>::IsStoreBlockedByPolicyAsync(hstring_view storeClientName, hstring_view storeClientPublisher) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager)->abi_IsStoreBlockedByPolicyAsync(get_abi(storeClientName), get_abi(storeClientPublisher), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppInstallManager<D>::GetIsAppAllowedToInstallAsync(hstring_view productId) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager)->abi_GetIsAppAllowedToInstallAsync(get_abi(productId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> impl_IAppInstallManager2<D>::StartAppInstallAsync(hstring_view productId, hstring_view skuId, bool repair, bool forceUseOfNonRemovableStorage, hstring_view catalogId, hstring_view bundleId, hstring_view correlationVector) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager2)->abi_StartAppInstallWithTelemetryAsync(get_abi(productId), get_abi(skuId), repair, forceUseOfNonRemovableStorage, get_abi(catalogId), get_abi(bundleId), get_abi(correlationVector), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> impl_IAppInstallManager2<D>::UpdateAppByPackageFamilyNameAsync(hstring_view packageFamilyName, hstring_view correlationVector) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager2)->abi_UpdateAppByPackageFamilyNameWithTelemetryAsync(get_abi(packageFamilyName), get_abi(correlationVector), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> impl_IAppInstallManager2<D>::SearchForUpdatesAsync(hstring_view productId, hstring_view skuId, hstring_view catalogId, hstring_view correlationVector) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager2)->abi_SearchForUpdatesWithTelemetryAsync(get_abi(productId), get_abi(skuId), get_abi(catalogId), get_abi(correlationVector), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> impl_IAppInstallManager2<D>::SearchForAllUpdatesAsync(hstring_view correlationVector) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager2)->abi_SearchForAllUpdatesWithTelemetryAsync(get_abi(correlationVector), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppInstallManager2<D>::GetIsAppAllowedToInstallAsync(hstring_view productId, hstring_view skuId, hstring_view catalogId, hstring_view correlationVector) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager2)->abi_GetIsAppAllowedToInstallWithTelemetryAsync(get_abi(productId), get_abi(skuId), get_abi(catalogId), get_abi(correlationVector), put_abi(operation)));
    return operation;
}

template <typename D> void impl_IAppInstallManager2<D>::Cancel(hstring_view productId, hstring_view correlationVector) const
{
    check_hresult(WINRT_SHIM(IAppInstallManager2)->abi_CancelWithTelemetry(get_abi(productId), get_abi(correlationVector)));
}

template <typename D> void impl_IAppInstallManager2<D>::Pause(hstring_view productId, hstring_view correlationVector) const
{
    check_hresult(WINRT_SHIM(IAppInstallManager2)->abi_PauseWithTelemetry(get_abi(productId), get_abi(correlationVector)));
}

template <typename D> void impl_IAppInstallManager2<D>::Restart(hstring_view productId, hstring_view correlationVector) const
{
    check_hresult(WINRT_SHIM(IAppInstallManager2)->abi_RestartWithTelemetry(get_abi(productId), get_abi(correlationVector)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> impl_IAppInstallManager3<D>::StartProductInstallAsync(hstring_view productId, hstring_view catalogId, hstring_view flightId, hstring_view clientId, bool repair, bool forceUseOfNonRemovableStorage, hstring_view correlationVector, const Windows::Management::Deployment::PackageVolume & targetVolume) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager3)->abi_StartProductInstallAsync(get_abi(productId), get_abi(catalogId), get_abi(flightId), get_abi(clientId), repair, forceUseOfNonRemovableStorage, get_abi(correlationVector), get_abi(targetVolume), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> impl_IAppInstallManager3<D>::StartProductInstallForUserAsync(const Windows::System::User & user, hstring_view productId, hstring_view catalogId, hstring_view flightId, hstring_view clientId, bool repair, bool forceUseOfNonRemovableStorage, hstring_view correlationVector, const Windows::Management::Deployment::PackageVolume & targetVolume) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager3)->abi_StartProductInstallForUserAsync(get_abi(user), get_abi(productId), get_abi(catalogId), get_abi(flightId), get_abi(clientId), repair, forceUseOfNonRemovableStorage, get_abi(correlationVector), get_abi(targetVolume), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> impl_IAppInstallManager3<D>::UpdateAppByPackageFamilyNameForUserAsync(const Windows::System::User & user, hstring_view packageFamilyName, hstring_view correlationVector) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager3)->abi_UpdateAppByPackageFamilyNameForUserAsync(get_abi(user), get_abi(packageFamilyName), get_abi(correlationVector), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> impl_IAppInstallManager3<D>::SearchForUpdatesForUserAsync(const Windows::System::User & user, hstring_view productId, hstring_view skuId, hstring_view catalogId, hstring_view correlationVector) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager3)->abi_SearchForUpdatesForUserAsync(get_abi(user), get_abi(productId), get_abi(skuId), get_abi(catalogId), get_abi(correlationVector), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> impl_IAppInstallManager3<D>::SearchForAllUpdatesForUserAsync(const Windows::System::User & user, hstring_view correlationVector) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager3)->abi_SearchForAllUpdatesForUserAsync(get_abi(user), get_abi(correlationVector), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppInstallManager3<D>::GetIsAppAllowedToInstallForUserAsync(const Windows::System::User & user, hstring_view productId, hstring_view skuId, hstring_view catalogId, hstring_view correlationVector) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager3)->abi_GetIsAppAllowedToInstallForUserAsync(get_abi(user), get_abi(productId), get_abi(skuId), get_abi(catalogId), get_abi(correlationVector), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppInstallManager3<D>::GetIsApplicableForUserAsync(const Windows::System::User & user, hstring_view productId, hstring_view skuId) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IAppInstallManager3)->abi_GetIsApplicableForUserAsync(get_abi(user), get_abi(productId), get_abi(skuId), put_abi(operation)));
    return operation;
}

template <typename D> void impl_IAppInstallManager3<D>::MoveToFrontOfDownloadQueue(hstring_view productId, hstring_view correlationVector) const
{
    check_hresult(WINRT_SHIM(IAppInstallManager3)->abi_MoveToFrontOfDownloadQueue(get_abi(productId), get_abi(correlationVector)));
}

inline AppInstallManager::AppInstallManager() :
    AppInstallManager(activate_instance<AppInstallManager>())
{}

}

}
#pragma warning(pop)
