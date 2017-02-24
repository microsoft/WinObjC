// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.ApplicationModel.3.h"
#include "internal/Windows.Services.Store.3.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Services::Store::IStoreAcquireLicenseResult> : produce_base<D, Windows::Services::Store::IStoreAcquireLicenseResult>
{
    HRESULT __stdcall get_StorePackageLicense(impl::abi_arg_out<Windows::Services::Store::IStorePackageLicense> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StorePackageLicense());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedError(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Store::IStoreAppLicense> : produce_base<D, Windows::Services::Store::IStoreAppLicense>
{
    HRESULT __stdcall get_SkuStoreId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SkuStoreId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsActive(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsActive());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTrial(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTrial());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpirationDate(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpirationDate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedJsonData(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedJsonData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AddOnLicenses(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Services::Store::StoreLicense>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AddOnLicenses());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrialTimeRemaining(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrialTimeRemaining());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTrialOwnedByThisUser(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTrialOwnedByThisUser());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrialUniqueId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrialUniqueId());
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
struct produce<D, Windows::Services::Store::IStoreAvailability> : produce_base<D, Windows::Services::Store::IStoreAvailability>
{
    HRESULT __stdcall get_StoreId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StoreId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndDate(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndDate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Price(impl::abi_arg_out<Windows::Services::Store::IStorePrice> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Price());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedJsonData(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedJsonData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestPurchaseAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestPurchaseAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestPurchaseWithPurchasePropertiesAsync(impl::abi_arg_in<Windows::Services::Store::IStorePurchaseProperties> storePurchaseProperties, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestPurchaseAsync(*reinterpret_cast<const Windows::Services::Store::StorePurchaseProperties *>(&storePurchaseProperties)));
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
struct produce<D, Windows::Services::Store::IStoreCollectionData> : produce_base<D, Windows::Services::Store::IStoreCollectionData>
{
    HRESULT __stdcall get_IsTrial(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTrial());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CampaignId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CampaignId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeveloperOfferId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeveloperOfferId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AcquiredDate(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AcquiredDate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StartDate(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartDate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndDate(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndDate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrialTimeRemaining(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrialTimeRemaining());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedJsonData(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedJsonData());
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
struct produce<D, Windows::Services::Store::IStoreConsumableResult> : produce_base<D, Windows::Services::Store::IStoreConsumableResult>
{
    HRESULT __stdcall get_Status(Windows::Services::Store::StoreConsumableStatus * value) noexcept override
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

    HRESULT __stdcall get_TrackingId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrackingId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BalanceRemaining(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BalanceRemaining());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedError(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Store::IStoreContext> : produce_base<D, Windows::Services::Store::IStoreContext>
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

    HRESULT __stdcall add_OfflineLicensesChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Services::Store::StoreContext, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().OfflineLicensesChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Services::Store::StoreContext, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_OfflineLicensesChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OfflineLicensesChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCustomerPurchaseIdAsync(impl::abi_arg_in<hstring> serviceTicket, impl::abi_arg_in<hstring> publisherUserId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetCustomerPurchaseIdAsync(*reinterpret_cast<const hstring *>(&serviceTicket), *reinterpret_cast<const hstring *>(&publisherUserId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCustomerCollectionsIdAsync(impl::abi_arg_in<hstring> serviceTicket, impl::abi_arg_in<hstring> publisherUserId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetCustomerCollectionsIdAsync(*reinterpret_cast<const hstring *>(&serviceTicket), *reinterpret_cast<const hstring *>(&publisherUserId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAppLicenseAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreAppLicense>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetAppLicenseAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStoreProductForCurrentAppAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetStoreProductForCurrentAppAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStoreProductsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> productKinds, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> storeIds, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductQueryResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetStoreProductsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&productKinds), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&storeIds)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAssociatedStoreProductsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> productKinds, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductQueryResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetAssociatedStoreProductsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&productKinds)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAssociatedStoreProductsWithPagingAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> productKinds, uint32_t maxItemsToRetrievePerPage, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductPagedQueryResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetAssociatedStoreProductsWithPagingAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&productKinds), maxItemsToRetrievePerPage));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetUserCollectionAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> productKinds, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductQueryResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetUserCollectionAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&productKinds)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetUserCollectionWithPagingAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> productKinds, uint32_t maxItemsToRetrievePerPage, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductPagedQueryResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetUserCollectionWithPagingAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&productKinds), maxItemsToRetrievePerPage));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportConsumableFulfillmentAsync(impl::abi_arg_in<hstring> productStoreId, uint32_t quantity, GUID trackingId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreConsumableResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ReportConsumableFulfillmentAsync(*reinterpret_cast<const hstring *>(&productStoreId), quantity, trackingId));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConsumableBalanceRemainingAsync(impl::abi_arg_in<hstring> productStoreId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreConsumableResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetConsumableBalanceRemainingAsync(*reinterpret_cast<const hstring *>(&productStoreId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AcquireStoreLicenseForOptionalPackageAsync(impl::abi_arg_in<Windows::ApplicationModel::IPackage> optionalPackage, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreAcquireLicenseResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().AcquireStoreLicenseForOptionalPackageAsync(*reinterpret_cast<const Windows::ApplicationModel::Package *>(&optionalPackage)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestPurchaseAsync(impl::abi_arg_in<hstring> storeId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestPurchaseAsync(*reinterpret_cast<const hstring *>(&storeId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestPurchaseWithPurchasePropertiesAsync(impl::abi_arg_in<hstring> storeId, impl::abi_arg_in<Windows::Services::Store::IStorePurchaseProperties> storePurchaseProperties, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestPurchaseAsync(*reinterpret_cast<const hstring *>(&storeId), *reinterpret_cast<const Windows::Services::Store::StorePurchaseProperties *>(&storePurchaseProperties)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAppAndOptionalStorePackageUpdatesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StorePackageUpdate>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetAppAndOptionalStorePackageUpdatesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestDownloadStorePackageUpdatesAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Services::Store::StorePackageUpdate>> storePackageUpdates, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Services::Store::StorePackageUpdateResult, Windows::Services::Store::StorePackageUpdateStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestDownloadStorePackageUpdatesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Services::Store::StorePackageUpdate> *>(&storePackageUpdates)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestDownloadAndInstallStorePackageUpdatesAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Services::Store::StorePackageUpdate>> storePackageUpdates, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Services::Store::StorePackageUpdateResult, Windows::Services::Store::StorePackageUpdateStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestDownloadAndInstallStorePackageUpdatesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Services::Store::StorePackageUpdate> *>(&storePackageUpdates)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestDownloadAndInstallStorePackagesAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> storeIds, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Services::Store::StorePackageUpdateResult, Windows::Services::Store::StorePackageUpdateStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestDownloadAndInstallStorePackagesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&storeIds)));
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
struct produce<D, Windows::Services::Store::IStoreContextStatics> : produce_base<D, Windows::Services::Store::IStoreContextStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Services::Store::IStoreContext> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDefault());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::Services::Store::IStoreContext> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetForUser(*reinterpret_cast<const Windows::System::User *>(&user)));
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
struct produce<D, Windows::Services::Store::IStoreImage> : produce_base<D, Windows::Services::Store::IStoreImage>
{
    HRESULT __stdcall get_Uri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ImagePurposeTag(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImagePurposeTag());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Width(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Width());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Height(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Height());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Caption(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Caption());
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
struct produce<D, Windows::Services::Store::IStoreLicense> : produce_base<D, Windows::Services::Store::IStoreLicense>
{
    HRESULT __stdcall get_SkuStoreId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SkuStoreId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsActive(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsActive());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpirationDate(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpirationDate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedJsonData(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedJsonData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InAppOfferToken(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InAppOfferToken());
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
struct produce<D, Windows::Services::Store::IStorePackageLicense> : produce_base<D, Windows::Services::Store::IStorePackageLicense>
{
    HRESULT __stdcall add_LicenseLost(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Services::Store::StorePackageLicense, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().LicenseLost(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Services::Store::StorePackageLicense, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LicenseLost(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LicenseLost(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Package(impl::abi_arg_out<Windows::ApplicationModel::IPackage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Package());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsValid(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsValid());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReleaseLicense() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleaseLicense();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Store::IStorePackageUpdate> : produce_base<D, Windows::Services::Store::IStorePackageUpdate>
{
    HRESULT __stdcall get_Package(impl::abi_arg_out<Windows::ApplicationModel::IPackage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Package());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mandatory(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mandatory());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Store::IStorePackageUpdateResult> : produce_base<D, Windows::Services::Store::IStorePackageUpdateResult>
{
    HRESULT __stdcall get_OverallState(Windows::Services::Store::StorePackageUpdateState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OverallState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StorePackageUpdateStatuses(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StorePackageUpdateStatus>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StorePackageUpdateStatuses());
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
struct produce<D, Windows::Services::Store::IStorePrice> : produce_base<D, Windows::Services::Store::IStorePrice>
{
    HRESULT __stdcall get_FormattedBasePrice(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FormattedBasePrice());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FormattedPrice(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FormattedPrice());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsOnSale(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOnSale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SaleEndDate(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SaleEndDate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrencyCode(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrencyCode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FormattedRecurrencePrice(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FormattedRecurrencePrice());
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
struct produce<D, Windows::Services::Store::IStoreProduct> : produce_base<D, Windows::Services::Store::IStoreProduct>
{
    HRESULT __stdcall get_StoreId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StoreId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Description(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Description());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProductKind(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProductKind());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasDigitalDownload(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasDigitalDownload());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Keywords(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Keywords());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Images(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreImage>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Images());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Videos(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreVideo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Videos());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Skus(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreSku>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Skus());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsInUserCollection(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsInUserCollection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Price(impl::abi_arg_out<Windows::Services::Store::IStorePrice> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Price());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedJsonData(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedJsonData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LinkUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LinkUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsAnySkuInstalledAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetIsAnySkuInstalledAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestPurchaseAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestPurchaseAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestPurchaseWithPurchasePropertiesAsync(impl::abi_arg_in<Windows::Services::Store::IStorePurchaseProperties> storePurchaseProperties, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestPurchaseAsync(*reinterpret_cast<const Windows::Services::Store::StorePurchaseProperties *>(&storePurchaseProperties)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InAppOfferToken(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InAppOfferToken());
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
struct produce<D, Windows::Services::Store::IStoreProductPagedQueryResult> : produce_base<D, Windows::Services::Store::IStoreProductPagedQueryResult>
{
    HRESULT __stdcall get_Products(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Services::Store::StoreProduct>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Products());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasMoreResults(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasMoreResults());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedError(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNextAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductPagedQueryResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetNextAsync());
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
struct produce<D, Windows::Services::Store::IStoreProductQueryResult> : produce_base<D, Windows::Services::Store::IStoreProductQueryResult>
{
    HRESULT __stdcall get_Products(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Services::Store::StoreProduct>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Products());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedError(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Store::IStoreProductResult> : produce_base<D, Windows::Services::Store::IStoreProductResult>
{
    HRESULT __stdcall get_Product(impl::abi_arg_out<Windows::Services::Store::IStoreProduct> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Product());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedError(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Store::IStorePurchaseProperties> : produce_base<D, Windows::Services::Store::IStorePurchaseProperties>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedJsonData(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedJsonData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExtendedJsonData(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExtendedJsonData(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Store::IStorePurchasePropertiesFactory> : produce_base<D, Windows::Services::Store::IStorePurchasePropertiesFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Services::Store::IStorePurchaseProperties> storePurchaseProperties) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *storePurchaseProperties = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *storePurchaseProperties = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Store::IStorePurchaseResult> : produce_base<D, Windows::Services::Store::IStorePurchaseResult>
{
    HRESULT __stdcall get_Status(Windows::Services::Store::StorePurchaseStatus * value) noexcept override
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

    HRESULT __stdcall get_ExtendedError(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Store::IStoreRequestHelperStatics> : produce_base<D, Windows::Services::Store::IStoreRequestHelperStatics>
{
    HRESULT __stdcall abi_SendRequestAsync(impl::abi_arg_in<Windows::Services::Store::IStoreContext> context, uint32_t requestKind, impl::abi_arg_in<hstring> parametersAsJson, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreSendRequestResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SendRequestAsync(*reinterpret_cast<const Windows::Services::Store::StoreContext *>(&context), requestKind, *reinterpret_cast<const hstring *>(&parametersAsJson)));
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
struct produce<D, Windows::Services::Store::IStoreSendRequestResult> : produce_base<D, Windows::Services::Store::IStoreSendRequestResult>
{
    HRESULT __stdcall get_Response(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Response());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedError(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Store::IStoreSku> : produce_base<D, Windows::Services::Store::IStoreSku>
{
    HRESULT __stdcall get_StoreId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StoreId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Description(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Description());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTrial(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTrial());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomDeveloperData(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomDeveloperData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Images(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreImage>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Images());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Videos(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreVideo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Videos());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Availabilities(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreAvailability>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Availabilities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Price(impl::abi_arg_out<Windows::Services::Store::IStorePrice> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Price());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedJsonData(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedJsonData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsInUserCollection(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsInUserCollection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BundledSkus(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BundledSkus());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CollectionData(impl::abi_arg_out<Windows::Services::Store::IStoreCollectionData> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CollectionData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsInstalledAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetIsInstalledAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestPurchaseAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestPurchaseAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestPurchaseWithPurchasePropertiesAsync(impl::abi_arg_in<Windows::Services::Store::IStorePurchaseProperties> storePurchaseProperties, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestPurchaseAsync(*reinterpret_cast<const Windows::Services::Store::StorePurchaseProperties *>(&storePurchaseProperties)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSubscription(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSubscription());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubscriptionInfo(impl::abi_arg_out<Windows::Services::Store::IStoreSubscriptionInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubscriptionInfo());
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
struct produce<D, Windows::Services::Store::IStoreSubscriptionInfo> : produce_base<D, Windows::Services::Store::IStoreSubscriptionInfo>
{
    HRESULT __stdcall get_BillingPeriod(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BillingPeriod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BillingPeriodUnit(Windows::Services::Store::StoreDurationUnit * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BillingPeriodUnit());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasTrialPeriod(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasTrialPeriod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrialPeriod(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrialPeriod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrialPeriodUnit(Windows::Services::Store::StoreDurationUnit * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrialPeriodUnit());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Store::IStoreVideo> : produce_base<D, Windows::Services::Store::IStoreVideo>
{
    HRESULT __stdcall get_Uri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoPurposeTag(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoPurposeTag());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Width(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Width());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Height(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Height());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Caption(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Caption());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreviewImage(impl::abi_arg_out<Windows::Services::Store::IStoreImage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreviewImage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Services::Store {

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Services::Store::StoreProduct> impl_IStoreProductPagedQueryResult<D>::Products() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Services::Store::StoreProduct> value;
    check_hresult(WINRT_SHIM(IStoreProductPagedQueryResult)->get_Products(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStoreProductPagedQueryResult<D>::HasMoreResults() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreProductPagedQueryResult)->get_HasMoreResults(&value));
    return value;
}

template <typename D> HRESULT impl_IStoreProductPagedQueryResult<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IStoreProductPagedQueryResult)->get_ExtendedError(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductPagedQueryResult> impl_IStoreProductPagedQueryResult<D>::GetNextAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductPagedQueryResult> operation;
    check_hresult(WINRT_SHIM(IStoreProductPagedQueryResult)->abi_GetNextAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Services::Store::StoreProduct> impl_IStoreProductQueryResult<D>::Products() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Services::Store::StoreProduct> value;
    check_hresult(WINRT_SHIM(IStoreProductQueryResult)->get_Products(put_abi(value)));
    return value;
}

template <typename D> HRESULT impl_IStoreProductQueryResult<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IStoreProductQueryResult)->get_ExtendedError(&value));
    return value;
}

template <typename D> Windows::Services::Store::StoreProduct impl_IStoreProductResult<D>::Product() const
{
    Windows::Services::Store::StoreProduct value { nullptr };
    check_hresult(WINRT_SHIM(IStoreProductResult)->get_Product(put_abi(value)));
    return value;
}

template <typename D> HRESULT impl_IStoreProductResult<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IStoreProductResult)->get_ExtendedError(&value));
    return value;
}

template <typename D> hstring impl_IStorePurchaseProperties<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePurchaseProperties)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IStorePurchaseProperties<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IStorePurchaseProperties)->put_Name(get_abi(value)));
}

template <typename D> hstring impl_IStorePurchaseProperties<D>::ExtendedJsonData() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePurchaseProperties)->get_ExtendedJsonData(put_abi(value)));
    return value;
}

template <typename D> void impl_IStorePurchaseProperties<D>::ExtendedJsonData(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IStorePurchaseProperties)->put_ExtendedJsonData(get_abi(value)));
}

template <typename D> Windows::Services::Store::StorePurchaseProperties impl_IStorePurchasePropertiesFactory<D>::Create(hstring_view name) const
{
    Windows::Services::Store::StorePurchaseProperties storePurchaseProperties { nullptr };
    check_hresult(WINRT_SHIM(IStorePurchasePropertiesFactory)->abi_Create(get_abi(name), put_abi(storePurchaseProperties)));
    return storePurchaseProperties;
}

template <typename D> bool impl_IStoreCollectionData<D>::IsTrial() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreCollectionData)->get_IsTrial(&value));
    return value;
}

template <typename D> hstring impl_IStoreCollectionData<D>::CampaignId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreCollectionData)->get_CampaignId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreCollectionData<D>::DeveloperOfferId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreCollectionData)->get_DeveloperOfferId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IStoreCollectionData<D>::AcquiredDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IStoreCollectionData)->get_AcquiredDate(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IStoreCollectionData<D>::StartDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IStoreCollectionData)->get_StartDate(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IStoreCollectionData<D>::EndDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IStoreCollectionData)->get_EndDate(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IStoreCollectionData<D>::TrialTimeRemaining() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IStoreCollectionData)->get_TrialTimeRemaining(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreCollectionData<D>::ExtendedJsonData() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreCollectionData)->get_ExtendedJsonData(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreLicense<D>::SkuStoreId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreLicense)->get_SkuStoreId(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStoreLicense<D>::IsActive() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreLicense)->get_IsActive(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IStoreLicense<D>::ExpirationDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IStoreLicense)->get_ExpirationDate(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreLicense<D>::ExtendedJsonData() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreLicense)->get_ExtendedJsonData(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreLicense<D>::InAppOfferToken() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreLicense)->get_InAppOfferToken(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreAppLicense<D>::SkuStoreId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreAppLicense)->get_SkuStoreId(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStoreAppLicense<D>::IsActive() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreAppLicense)->get_IsActive(&value));
    return value;
}

template <typename D> bool impl_IStoreAppLicense<D>::IsTrial() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreAppLicense)->get_IsTrial(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IStoreAppLicense<D>::ExpirationDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IStoreAppLicense)->get_ExpirationDate(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreAppLicense<D>::ExtendedJsonData() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreAppLicense)->get_ExtendedJsonData(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Services::Store::StoreLicense> impl_IStoreAppLicense<D>::AddOnLicenses() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Services::Store::StoreLicense> value;
    check_hresult(WINRT_SHIM(IStoreAppLicense)->get_AddOnLicenses(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IStoreAppLicense<D>::TrialTimeRemaining() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IStoreAppLicense)->get_TrialTimeRemaining(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStoreAppLicense<D>::IsTrialOwnedByThisUser() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreAppLicense)->get_IsTrialOwnedByThisUser(&value));
    return value;
}

template <typename D> hstring impl_IStoreAppLicense<D>::TrialUniqueId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreAppLicense)->get_TrialUniqueId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreSendRequestResult<D>::Response() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreSendRequestResult)->get_Response(put_abi(value)));
    return value;
}

template <typename D> HRESULT impl_IStoreSendRequestResult<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IStoreSendRequestResult)->get_ExtendedError(&value));
    return value;
}

template <typename D> hstring impl_IStoreProduct<D>::StoreId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreProduct)->get_StoreId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreProduct<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreProduct)->get_Language(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreProduct<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreProduct)->get_Title(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreProduct<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreProduct)->get_Description(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreProduct<D>::ProductKind() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreProduct)->get_ProductKind(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStoreProduct<D>::HasDigitalDownload() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreProduct)->get_HasDigitalDownload(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IStoreProduct<D>::Keywords() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IStoreProduct)->get_Keywords(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreImage> impl_IStoreProduct<D>::Images() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreImage> value;
    check_hresult(WINRT_SHIM(IStoreProduct)->get_Images(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreVideo> impl_IStoreProduct<D>::Videos() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreVideo> value;
    check_hresult(WINRT_SHIM(IStoreProduct)->get_Videos(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreSku> impl_IStoreProduct<D>::Skus() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreSku> value;
    check_hresult(WINRT_SHIM(IStoreProduct)->get_Skus(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStoreProduct<D>::IsInUserCollection() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreProduct)->get_IsInUserCollection(&value));
    return value;
}

template <typename D> Windows::Services::Store::StorePrice impl_IStoreProduct<D>::Price() const
{
    Windows::Services::Store::StorePrice value { nullptr };
    check_hresult(WINRT_SHIM(IStoreProduct)->get_Price(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreProduct<D>::ExtendedJsonData() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreProduct)->get_ExtendedJsonData(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IStoreProduct<D>::LinkUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IStoreProduct)->get_LinkUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IStoreProduct<D>::GetIsAnySkuInstalledAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IStoreProduct)->abi_GetIsAnySkuInstalledAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> impl_IStoreProduct<D>::RequestPurchaseAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> operation;
    check_hresult(WINRT_SHIM(IStoreProduct)->abi_RequestPurchaseAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> impl_IStoreProduct<D>::RequestPurchaseAsync(const Windows::Services::Store::StorePurchaseProperties & storePurchaseProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> operation;
    check_hresult(WINRT_SHIM(IStoreProduct)->abi_RequestPurchaseWithPurchasePropertiesAsync(get_abi(storePurchaseProperties), put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IStoreProduct<D>::InAppOfferToken() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreProduct)->get_InAppOfferToken(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IStoreImage<D>::Uri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IStoreImage)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreImage<D>::ImagePurposeTag() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreImage)->get_ImagePurposeTag(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IStoreImage<D>::Width() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IStoreImage)->get_Width(&value));
    return value;
}

template <typename D> uint32_t impl_IStoreImage<D>::Height() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IStoreImage)->get_Height(&value));
    return value;
}

template <typename D> hstring impl_IStoreImage<D>::Caption() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreImage)->get_Caption(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IStoreVideo<D>::Uri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IStoreVideo)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreVideo<D>::VideoPurposeTag() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreVideo)->get_VideoPurposeTag(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IStoreVideo<D>::Width() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IStoreVideo)->get_Width(&value));
    return value;
}

template <typename D> uint32_t impl_IStoreVideo<D>::Height() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IStoreVideo)->get_Height(&value));
    return value;
}

template <typename D> hstring impl_IStoreVideo<D>::Caption() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreVideo)->get_Caption(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Store::StoreImage impl_IStoreVideo<D>::PreviewImage() const
{
    Windows::Services::Store::StoreImage value { nullptr };
    check_hresult(WINRT_SHIM(IStoreVideo)->get_PreviewImage(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreSku<D>::StoreId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreSku)->get_StoreId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreSku<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreSku)->get_Language(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreSku<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreSku)->get_Title(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreSku<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreSku)->get_Description(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStoreSku<D>::IsTrial() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreSku)->get_IsTrial(&value));
    return value;
}

template <typename D> hstring impl_IStoreSku<D>::CustomDeveloperData() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreSku)->get_CustomDeveloperData(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreImage> impl_IStoreSku<D>::Images() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreImage> value;
    check_hresult(WINRT_SHIM(IStoreSku)->get_Images(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreVideo> impl_IStoreSku<D>::Videos() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreVideo> value;
    check_hresult(WINRT_SHIM(IStoreSku)->get_Videos(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreAvailability> impl_IStoreSku<D>::Availabilities() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StoreAvailability> value;
    check_hresult(WINRT_SHIM(IStoreSku)->get_Availabilities(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Store::StorePrice impl_IStoreSku<D>::Price() const
{
    Windows::Services::Store::StorePrice value { nullptr };
    check_hresult(WINRT_SHIM(IStoreSku)->get_Price(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreSku<D>::ExtendedJsonData() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreSku)->get_ExtendedJsonData(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStoreSku<D>::IsInUserCollection() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreSku)->get_IsInUserCollection(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IStoreSku<D>::BundledSkus() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IStoreSku)->get_BundledSkus(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Store::StoreCollectionData impl_IStoreSku<D>::CollectionData() const
{
    Windows::Services::Store::StoreCollectionData value { nullptr };
    check_hresult(WINRT_SHIM(IStoreSku)->get_CollectionData(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IStoreSku<D>::GetIsInstalledAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IStoreSku)->abi_GetIsInstalledAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> impl_IStoreSku<D>::RequestPurchaseAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> operation;
    check_hresult(WINRT_SHIM(IStoreSku)->abi_RequestPurchaseAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> impl_IStoreSku<D>::RequestPurchaseAsync(const Windows::Services::Store::StorePurchaseProperties & storePurchaseProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> operation;
    check_hresult(WINRT_SHIM(IStoreSku)->abi_RequestPurchaseWithPurchasePropertiesAsync(get_abi(storePurchaseProperties), put_abi(operation)));
    return operation;
}

template <typename D> bool impl_IStoreSku<D>::IsSubscription() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreSku)->get_IsSubscription(&value));
    return value;
}

template <typename D> Windows::Services::Store::StoreSubscriptionInfo impl_IStoreSku<D>::SubscriptionInfo() const
{
    Windows::Services::Store::StoreSubscriptionInfo value { nullptr };
    check_hresult(WINRT_SHIM(IStoreSku)->get_SubscriptionInfo(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreAvailability<D>::StoreId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreAvailability)->get_StoreId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IStoreAvailability<D>::EndDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IStoreAvailability)->get_EndDate(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Store::StorePrice impl_IStoreAvailability<D>::Price() const
{
    Windows::Services::Store::StorePrice value { nullptr };
    check_hresult(WINRT_SHIM(IStoreAvailability)->get_Price(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreAvailability<D>::ExtendedJsonData() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreAvailability)->get_ExtendedJsonData(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> impl_IStoreAvailability<D>::RequestPurchaseAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> operation;
    check_hresult(WINRT_SHIM(IStoreAvailability)->abi_RequestPurchaseAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> impl_IStoreAvailability<D>::RequestPurchaseAsync(const Windows::Services::Store::StorePurchaseProperties & storePurchaseProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> operation;
    check_hresult(WINRT_SHIM(IStoreAvailability)->abi_RequestPurchaseWithPurchasePropertiesAsync(get_abi(storePurchaseProperties), put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IStorePrice<D>::FormattedBasePrice() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePrice)->get_FormattedBasePrice(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePrice<D>::FormattedPrice() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePrice)->get_FormattedPrice(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStorePrice<D>::IsOnSale() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStorePrice)->get_IsOnSale(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IStorePrice<D>::SaleEndDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IStorePrice)->get_SaleEndDate(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePrice<D>::CurrencyCode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePrice)->get_CurrencyCode(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePrice<D>::FormattedRecurrencePrice() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePrice)->get_FormattedRecurrencePrice(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IStoreSubscriptionInfo<D>::BillingPeriod() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IStoreSubscriptionInfo)->get_BillingPeriod(&value));
    return value;
}

template <typename D> Windows::Services::Store::StoreDurationUnit impl_IStoreSubscriptionInfo<D>::BillingPeriodUnit() const
{
    Windows::Services::Store::StoreDurationUnit value {};
    check_hresult(WINRT_SHIM(IStoreSubscriptionInfo)->get_BillingPeriodUnit(&value));
    return value;
}

template <typename D> bool impl_IStoreSubscriptionInfo<D>::HasTrialPeriod() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreSubscriptionInfo)->get_HasTrialPeriod(&value));
    return value;
}

template <typename D> uint32_t impl_IStoreSubscriptionInfo<D>::TrialPeriod() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IStoreSubscriptionInfo)->get_TrialPeriod(&value));
    return value;
}

template <typename D> Windows::Services::Store::StoreDurationUnit impl_IStoreSubscriptionInfo<D>::TrialPeriodUnit() const
{
    Windows::Services::Store::StoreDurationUnit value {};
    check_hresult(WINRT_SHIM(IStoreSubscriptionInfo)->get_TrialPeriodUnit(&value));
    return value;
}

template <typename D> Windows::Services::Store::StoreConsumableStatus impl_IStoreConsumableResult<D>::Status() const
{
    Windows::Services::Store::StoreConsumableStatus value {};
    check_hresult(WINRT_SHIM(IStoreConsumableResult)->get_Status(&value));
    return value;
}

template <typename D> GUID impl_IStoreConsumableResult<D>::TrackingId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IStoreConsumableResult)->get_TrackingId(&value));
    return value;
}

template <typename D> uint32_t impl_IStoreConsumableResult<D>::BalanceRemaining() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IStoreConsumableResult)->get_BalanceRemaining(&value));
    return value;
}

template <typename D> HRESULT impl_IStoreConsumableResult<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IStoreConsumableResult)->get_ExtendedError(&value));
    return value;
}

template <typename D> Windows::Services::Store::StorePurchaseStatus impl_IStorePurchaseResult<D>::Status() const
{
    Windows::Services::Store::StorePurchaseStatus value {};
    check_hresult(WINRT_SHIM(IStorePurchaseResult)->get_Status(&value));
    return value;
}

template <typename D> HRESULT impl_IStorePurchaseResult<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IStorePurchaseResult)->get_ExtendedError(&value));
    return value;
}

template <typename D> Windows::Services::Store::StoreContext impl_IStoreContextStatics<D>::GetDefault() const
{
    Windows::Services::Store::StoreContext value { nullptr };
    check_hresult(WINRT_SHIM(IStoreContextStatics)->abi_GetDefault(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Store::StoreContext impl_IStoreContextStatics<D>::GetForUser(const Windows::System::User & user) const
{
    Windows::Services::Store::StoreContext value { nullptr };
    check_hresult(WINRT_SHIM(IStoreContextStatics)->abi_GetForUser(get_abi(user), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreSendRequestResult> impl_IStoreRequestHelperStatics<D>::SendRequestAsync(const Windows::Services::Store::StoreContext & context, uint32_t requestKind, hstring_view parametersAsJson) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreSendRequestResult> operation;
    check_hresult(WINRT_SHIM(IStoreRequestHelperStatics)->abi_SendRequestAsync(get_abi(context), requestKind, get_abi(parametersAsJson), put_abi(operation)));
    return operation;
}

template <typename D> Windows::System::User impl_IStoreContext<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IStoreContext)->get_User(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IStoreContext<D>::OfflineLicensesChanged(const Windows::Foundation::TypedEventHandler<Windows::Services::Store::StoreContext, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IStoreContext)->add_OfflineLicensesChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IStoreContext> impl_IStoreContext<D>::OfflineLicensesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Store::StoreContext, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IStoreContext>(this, &ABI::Windows::Services::Store::IStoreContext::remove_OfflineLicensesChanged, OfflineLicensesChanged(handler));
}

template <typename D> void impl_IStoreContext<D>::OfflineLicensesChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IStoreContext)->remove_OfflineLicensesChanged(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IStoreContext<D>::GetCustomerPurchaseIdAsync(hstring_view serviceTicket, hstring_view publisherUserId) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_GetCustomerPurchaseIdAsync(get_abi(serviceTicket), get_abi(publisherUserId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IStoreContext<D>::GetCustomerCollectionsIdAsync(hstring_view serviceTicket, hstring_view publisherUserId) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_GetCustomerCollectionsIdAsync(get_abi(serviceTicket), get_abi(publisherUserId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreAppLicense> impl_IStoreContext<D>::GetAppLicenseAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreAppLicense> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_GetAppLicenseAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductResult> impl_IStoreContext<D>::GetStoreProductForCurrentAppAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductResult> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_GetStoreProductForCurrentAppAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductQueryResult> impl_IStoreContext<D>::GetStoreProductsAsync(iterable<hstring> productKinds, iterable<hstring> storeIds) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductQueryResult> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_GetStoreProductsAsync(get_abi(productKinds), get_abi(storeIds), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductQueryResult> impl_IStoreContext<D>::GetAssociatedStoreProductsAsync(iterable<hstring> productKinds) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductQueryResult> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_GetAssociatedStoreProductsAsync(get_abi(productKinds), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductPagedQueryResult> impl_IStoreContext<D>::GetAssociatedStoreProductsWithPagingAsync(iterable<hstring> productKinds, uint32_t maxItemsToRetrievePerPage) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductPagedQueryResult> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_GetAssociatedStoreProductsWithPagingAsync(get_abi(productKinds), maxItemsToRetrievePerPage, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductQueryResult> impl_IStoreContext<D>::GetUserCollectionAsync(iterable<hstring> productKinds) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductQueryResult> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_GetUserCollectionAsync(get_abi(productKinds), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductPagedQueryResult> impl_IStoreContext<D>::GetUserCollectionWithPagingAsync(iterable<hstring> productKinds, uint32_t maxItemsToRetrievePerPage) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreProductPagedQueryResult> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_GetUserCollectionWithPagingAsync(get_abi(productKinds), maxItemsToRetrievePerPage, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreConsumableResult> impl_IStoreContext<D>::ReportConsumableFulfillmentAsync(hstring_view productStoreId, uint32_t quantity, GUID trackingId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreConsumableResult> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_ReportConsumableFulfillmentAsync(get_abi(productStoreId), quantity, trackingId, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreConsumableResult> impl_IStoreContext<D>::GetConsumableBalanceRemainingAsync(hstring_view productStoreId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreConsumableResult> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_GetConsumableBalanceRemainingAsync(get_abi(productStoreId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreAcquireLicenseResult> impl_IStoreContext<D>::AcquireStoreLicenseForOptionalPackageAsync(const Windows::ApplicationModel::Package & optionalPackage) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreAcquireLicenseResult> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_AcquireStoreLicenseForOptionalPackageAsync(get_abi(optionalPackage), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> impl_IStoreContext<D>::RequestPurchaseAsync(hstring_view storeId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_RequestPurchaseAsync(get_abi(storeId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> impl_IStoreContext<D>::RequestPurchaseAsync(hstring_view storeId, const Windows::Services::Store::StorePurchaseProperties & storePurchaseProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Store::StorePurchaseResult> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_RequestPurchaseWithPurchasePropertiesAsync(get_abi(storeId), get_abi(storePurchaseProperties), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StorePackageUpdate>> impl_IStoreContext<D>::GetAppAndOptionalStorePackageUpdatesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StorePackageUpdate>> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_GetAppAndOptionalStorePackageUpdatesAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Services::Store::StorePackageUpdateResult, Windows::Services::Store::StorePackageUpdateStatus> impl_IStoreContext<D>::RequestDownloadStorePackageUpdatesAsync(iterable<Windows::Services::Store::StorePackageUpdate> storePackageUpdates) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Services::Store::StorePackageUpdateResult, Windows::Services::Store::StorePackageUpdateStatus> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_RequestDownloadStorePackageUpdatesAsync(get_abi(storePackageUpdates), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Services::Store::StorePackageUpdateResult, Windows::Services::Store::StorePackageUpdateStatus> impl_IStoreContext<D>::RequestDownloadAndInstallStorePackageUpdatesAsync(iterable<Windows::Services::Store::StorePackageUpdate> storePackageUpdates) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Services::Store::StorePackageUpdateResult, Windows::Services::Store::StorePackageUpdateStatus> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_RequestDownloadAndInstallStorePackageUpdatesAsync(get_abi(storePackageUpdates), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Services::Store::StorePackageUpdateResult, Windows::Services::Store::StorePackageUpdateStatus> impl_IStoreContext<D>::RequestDownloadAndInstallStorePackagesAsync(iterable<hstring> storeIds) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Services::Store::StorePackageUpdateResult, Windows::Services::Store::StorePackageUpdateStatus> operation;
    check_hresult(WINRT_SHIM(IStoreContext)->abi_RequestDownloadAndInstallStorePackagesAsync(get_abi(storeIds), put_abi(operation)));
    return operation;
}

template <typename D> Windows::ApplicationModel::Package impl_IStorePackageUpdate<D>::Package() const
{
    Windows::ApplicationModel::Package value { nullptr };
    check_hresult(WINRT_SHIM(IStorePackageUpdate)->get_Package(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStorePackageUpdate<D>::Mandatory() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStorePackageUpdate)->get_Mandatory(&value));
    return value;
}

template <typename D> Windows::Services::Store::StorePackageUpdateState impl_IStorePackageUpdateResult<D>::OverallState() const
{
    Windows::Services::Store::StorePackageUpdateState value {};
    check_hresult(WINRT_SHIM(IStorePackageUpdateResult)->get_OverallState(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StorePackageUpdateStatus> impl_IStorePackageUpdateResult<D>::StorePackageUpdateStatuses() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Store::StorePackageUpdateStatus> value;
    check_hresult(WINRT_SHIM(IStorePackageUpdateResult)->get_StorePackageUpdateStatuses(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Store::StorePackageLicense impl_IStoreAcquireLicenseResult<D>::StorePackageLicense() const
{
    Windows::Services::Store::StorePackageLicense value { nullptr };
    check_hresult(WINRT_SHIM(IStoreAcquireLicenseResult)->get_StorePackageLicense(put_abi(value)));
    return value;
}

template <typename D> HRESULT impl_IStoreAcquireLicenseResult<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IStoreAcquireLicenseResult)->get_ExtendedError(&value));
    return value;
}

template <typename D> event_token impl_IStorePackageLicense<D>::LicenseLost(const Windows::Foundation::TypedEventHandler<Windows::Services::Store::StorePackageLicense, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IStorePackageLicense)->add_LicenseLost(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IStorePackageLicense> impl_IStorePackageLicense<D>::LicenseLost(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Services::Store::StorePackageLicense, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IStorePackageLicense>(this, &ABI::Windows::Services::Store::IStorePackageLicense::remove_LicenseLost, LicenseLost(handler));
}

template <typename D> void impl_IStorePackageLicense<D>::LicenseLost(event_token token) const
{
    check_hresult(WINRT_SHIM(IStorePackageLicense)->remove_LicenseLost(token));
}

template <typename D> Windows::ApplicationModel::Package impl_IStorePackageLicense<D>::Package() const
{
    Windows::ApplicationModel::Package value { nullptr };
    check_hresult(WINRT_SHIM(IStorePackageLicense)->get_Package(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStorePackageLicense<D>::IsValid() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStorePackageLicense)->get_IsValid(&value));
    return value;
}

template <typename D> void impl_IStorePackageLicense<D>::ReleaseLicense() const
{
    check_hresult(WINRT_SHIM(IStorePackageLicense)->abi_ReleaseLicense());
}

inline Windows::Services::Store::StoreContext StoreContext::GetDefault()
{
    return get_activation_factory<StoreContext, IStoreContextStatics>().GetDefault();
}

inline Windows::Services::Store::StoreContext StoreContext::GetForUser(const Windows::System::User & user)
{
    return get_activation_factory<StoreContext, IStoreContextStatics>().GetForUser(user);
}

inline StorePurchaseProperties::StorePurchaseProperties() :
    StorePurchaseProperties(activate_instance<StorePurchaseProperties>())
{}

inline StorePurchaseProperties::StorePurchaseProperties(hstring_view name) :
    StorePurchaseProperties(get_activation_factory<StorePurchaseProperties, IStorePurchasePropertiesFactory>().Create(name))
{}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Store::StoreSendRequestResult> StoreRequestHelper::SendRequestAsync(const Windows::Services::Store::StoreContext & context, uint32_t requestKind, hstring_view parametersAsJson)
{
    return get_activation_factory<StoreRequestHelper, IStoreRequestHelperStatics>().SendRequestAsync(context, requestKind, parametersAsJson);
}

}

}
#pragma warning(pop)
