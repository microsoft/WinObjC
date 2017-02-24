// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.ApplicationModel.Store.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Store {

template <typename L> LicenseChangedEventHandler::LicenseChangedEventHandler(L lambda) :
    LicenseChangedEventHandler(impl::make_delegate<impl_LicenseChangedEventHandler<L>, LicenseChangedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> LicenseChangedEventHandler::LicenseChangedEventHandler(F * function) :
    LicenseChangedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> LicenseChangedEventHandler::LicenseChangedEventHandler(O * object, M method) :
    LicenseChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void LicenseChangedEventHandler::operator()() const
{
    check_hresult((*(abi<LicenseChangedEventHandler> **)this)->abi_Invoke());
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::ICurrentApp> : produce_base<D, Windows::ApplicationModel::Store::ICurrentApp>
{
    HRESULT __stdcall get_LicenseInformation(impl::abi_arg_out<Windows::ApplicationModel::Store::ILicenseInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LicenseInformation());
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

    HRESULT __stdcall get_AppId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAppPurchaseAsync(bool includeReceipt, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> requestAppPurchaseOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestAppPurchaseOperation = detach_abi(this->shim().RequestAppPurchaseAsync(includeReceipt));
            return S_OK;
        }
        catch (...)
        {
            *requestAppPurchaseOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestProductPurchaseAsync(impl::abi_arg_in<hstring> productId, bool includeReceipt, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> requestProductPurchaseOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestProductPurchaseOperation = detach_abi(this->shim().RequestProductPurchaseAsync(*reinterpret_cast<const hstring *>(&productId), includeReceipt));
            return S_OK;
        }
        catch (...)
        {
            *requestProductPurchaseOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadListingInformationAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation>> loadListingOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loadListingOperation = detach_abi(this->shim().LoadListingInformationAsync());
            return S_OK;
        }
        catch (...)
        {
            *loadListingOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAppReceiptAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> appReceiptOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *appReceiptOperation = detach_abi(this->shim().GetAppReceiptAsync());
            return S_OK;
        }
        catch (...)
        {
            *appReceiptOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetProductReceiptAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> getProductReceiptOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *getProductReceiptOperation = detach_abi(this->shim().GetProductReceiptAsync(*reinterpret_cast<const hstring *>(&productId)));
            return S_OK;
        }
        catch (...)
        {
            *getProductReceiptOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::ICurrentApp2Statics> : produce_base<D, Windows::ApplicationModel::Store::ICurrentApp2Statics>
{
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::ICurrentAppSimulator> : produce_base<D, Windows::ApplicationModel::Store::ICurrentAppSimulator>
{
    HRESULT __stdcall get_LicenseInformation(impl::abi_arg_out<Windows::ApplicationModel::Store::ILicenseInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LicenseInformation());
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

    HRESULT __stdcall get_AppId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAppPurchaseAsync(bool includeReceipt, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> requestAppPurchaseOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestAppPurchaseOperation = detach_abi(this->shim().RequestAppPurchaseAsync(includeReceipt));
            return S_OK;
        }
        catch (...)
        {
            *requestAppPurchaseOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestProductPurchaseAsync(impl::abi_arg_in<hstring> productId, bool includeReceipt, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> requestProductPurchaseOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestProductPurchaseOperation = detach_abi(this->shim().RequestProductPurchaseAsync(*reinterpret_cast<const hstring *>(&productId), includeReceipt));
            return S_OK;
        }
        catch (...)
        {
            *requestProductPurchaseOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadListingInformationAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation>> loadListingOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loadListingOperation = detach_abi(this->shim().LoadListingInformationAsync());
            return S_OK;
        }
        catch (...)
        {
            *loadListingOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAppReceiptAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> appReceiptOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *appReceiptOperation = detach_abi(this->shim().GetAppReceiptAsync());
            return S_OK;
        }
        catch (...)
        {
            *appReceiptOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetProductReceiptAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> getProductReceiptOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *getProductReceiptOperation = detach_abi(this->shim().GetProductReceiptAsync(*reinterpret_cast<const hstring *>(&productId)));
            return S_OK;
        }
        catch (...)
        {
            *getProductReceiptOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReloadSimulatorAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> simulatorSettingsFile, impl::abi_arg_out<Windows::Foundation::IAsyncAction> reloadSimulatorOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *reloadSimulatorOperation = detach_abi(this->shim().ReloadSimulatorAsync(*reinterpret_cast<const Windows::Storage::StorageFile *>(&simulatorSettingsFile)));
            return S_OK;
        }
        catch (...)
        {
            *reloadSimulatorOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::ICurrentAppSimulatorStaticsWithFiltering> : produce_base<D, Windows::ApplicationModel::Store::ICurrentAppSimulatorStaticsWithFiltering>
{
    HRESULT __stdcall abi_LoadListingInformationByProductIdsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> productIds, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation>> loadListingOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loadListingOperation = detach_abi(this->shim().LoadListingInformationByProductIdsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&productIds)));
            return S_OK;
        }
        catch (...)
        {
            *loadListingOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadListingInformationByKeywordsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> keywords, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation>> loadListingOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loadListingOperation = detach_abi(this->shim().LoadListingInformationByKeywordsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&keywords)));
            return S_OK;
        }
        catch (...)
        {
            *loadListingOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::ICurrentAppSimulatorWithCampaignId> : produce_base<D, Windows::ApplicationModel::Store::ICurrentAppSimulatorWithCampaignId>
{
    HRESULT __stdcall abi_GetAppPurchaseCampaignIdAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetAppPurchaseCampaignIdAsync());
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
struct produce<D, Windows::ApplicationModel::Store::ICurrentAppSimulatorWithConsumables> : produce_base<D, Windows::ApplicationModel::Store::ICurrentAppSimulatorWithConsumables>
{
    HRESULT __stdcall abi_ReportConsumableFulfillmentAsync(impl::abi_arg_in<hstring> productId, GUID transactionId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Store::FulfillmentResult>> reportConsumableFulfillmentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *reportConsumableFulfillmentOperation = detach_abi(this->shim().ReportConsumableFulfillmentAsync(*reinterpret_cast<const hstring *>(&productId), transactionId));
            return S_OK;
        }
        catch (...)
        {
            *reportConsumableFulfillmentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestProductPurchaseWithResultsAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults>> requestProductPurchaseWithResultsOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestProductPurchaseWithResultsOperation = detach_abi(this->shim().RequestProductPurchaseAsync(*reinterpret_cast<const hstring *>(&productId)));
            return S_OK;
        }
        catch (...)
        {
            *requestProductPurchaseWithResultsOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestProductPurchaseWithDisplayPropertiesAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> offerId, impl::abi_arg_in<Windows::ApplicationModel::Store::IProductPurchaseDisplayProperties> displayProperties, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults>> requestProductPurchaseWithDisplayPropertiesOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestProductPurchaseWithDisplayPropertiesOperation = detach_abi(this->shim().RequestProductPurchaseAsync(*reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&offerId), *reinterpret_cast<const Windows::ApplicationModel::Store::ProductPurchaseDisplayProperties *>(&displayProperties)));
            return S_OK;
        }
        catch (...)
        {
            *requestProductPurchaseWithDisplayPropertiesOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetUnfulfilledConsumablesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>>> getUnfulfilledConsumablesOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *getUnfulfilledConsumablesOperation = detach_abi(this->shim().GetUnfulfilledConsumablesAsync());
            return S_OK;
        }
        catch (...)
        {
            *getUnfulfilledConsumablesOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::ICurrentAppStaticsWithFiltering> : produce_base<D, Windows::ApplicationModel::Store::ICurrentAppStaticsWithFiltering>
{
    HRESULT __stdcall abi_LoadListingInformationByProductIdsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> productIds, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation>> loadListingOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loadListingOperation = detach_abi(this->shim().LoadListingInformationByProductIdsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&productIds)));
            return S_OK;
        }
        catch (...)
        {
            *loadListingOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadListingInformationByKeywordsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> keywords, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation>> loadListingOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loadListingOperation = detach_abi(this->shim().LoadListingInformationByKeywordsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&keywords)));
            return S_OK;
        }
        catch (...)
        {
            *loadListingOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportProductFulfillment(impl::abi_arg_in<hstring> productId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportProductFulfillment(*reinterpret_cast<const hstring *>(&productId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::ICurrentAppWithCampaignId> : produce_base<D, Windows::ApplicationModel::Store::ICurrentAppWithCampaignId>
{
    HRESULT __stdcall abi_GetAppPurchaseCampaignIdAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetAppPurchaseCampaignIdAsync());
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
struct produce<D, Windows::ApplicationModel::Store::ICurrentAppWithConsumables> : produce_base<D, Windows::ApplicationModel::Store::ICurrentAppWithConsumables>
{
    HRESULT __stdcall abi_ReportConsumableFulfillmentAsync(impl::abi_arg_in<hstring> productId, GUID transactionId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Store::FulfillmentResult>> reportConsumableFulfillmentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *reportConsumableFulfillmentOperation = detach_abi(this->shim().ReportConsumableFulfillmentAsync(*reinterpret_cast<const hstring *>(&productId), transactionId));
            return S_OK;
        }
        catch (...)
        {
            *reportConsumableFulfillmentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestProductPurchaseWithResultsAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults>> requestProductPurchaseWithResultsOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestProductPurchaseWithResultsOperation = detach_abi(this->shim().RequestProductPurchaseAsync(*reinterpret_cast<const hstring *>(&productId)));
            return S_OK;
        }
        catch (...)
        {
            *requestProductPurchaseWithResultsOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestProductPurchaseWithDisplayPropertiesAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> offerId, impl::abi_arg_in<Windows::ApplicationModel::Store::IProductPurchaseDisplayProperties> displayProperties, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults>> requestProductPurchaseWithDisplayPropertiesOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestProductPurchaseWithDisplayPropertiesOperation = detach_abi(this->shim().RequestProductPurchaseAsync(*reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&offerId), *reinterpret_cast<const Windows::ApplicationModel::Store::ProductPurchaseDisplayProperties *>(&displayProperties)));
            return S_OK;
        }
        catch (...)
        {
            *requestProductPurchaseWithDisplayPropertiesOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetUnfulfilledConsumablesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>>> getUnfulfilledConsumablesOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *getUnfulfilledConsumablesOperation = detach_abi(this->shim().GetUnfulfilledConsumablesAsync());
            return S_OK;
        }
        catch (...)
        {
            *getUnfulfilledConsumablesOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::ILicenseInformation> : produce_base<D, Windows::ApplicationModel::Store::ILicenseInformation>
{
    HRESULT __stdcall get_ProductLicenses(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::ProductLicense>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProductLicenses());
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

    HRESULT __stdcall add_LicenseChanged(impl::abi_arg_in<Windows::ApplicationModel::Store::LicenseChangedEventHandler> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().LicenseChanged(*reinterpret_cast<const Windows::ApplicationModel::Store::LicenseChangedEventHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LicenseChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LicenseChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::IListingInformation> : produce_base<D, Windows::ApplicationModel::Store::IListingInformation>
{
    HRESULT __stdcall get_CurrentMarket(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentMarket());
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

    HRESULT __stdcall get_ProductListings(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::ProductListing>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProductListings());
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

    HRESULT __stdcall get_AgeRating(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AgeRating());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::IListingInformation2> : produce_base<D, Windows::ApplicationModel::Store::IListingInformation2>
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::IProductLicense> : produce_base<D, Windows::ApplicationModel::Store::IProductLicense>
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::IProductLicenseWithFulfillment> : produce_base<D, Windows::ApplicationModel::Store::IProductLicenseWithFulfillment>
{
    HRESULT __stdcall get_IsConsumable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsConsumable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::IProductListing> : produce_base<D, Windows::ApplicationModel::Store::IProductListing>
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::IProductListing2> : produce_base<D, Windows::ApplicationModel::Store::IProductListing2>
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::IProductListingWithConsumables> : produce_base<D, Windows::ApplicationModel::Store::IProductListingWithConsumables>
{
    HRESULT __stdcall get_ProductType(Windows::ApplicationModel::Store::ProductType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProductType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::IProductListingWithMetadata> : produce_base<D, Windows::ApplicationModel::Store::IProductListingWithMetadata>
{
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

    HRESULT __stdcall get_Keywords(impl::abi_arg_out<Windows::Foundation::Collections::IIterable<hstring>> value) noexcept override
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

    HRESULT __stdcall get_ProductType(Windows::ApplicationModel::Store::ProductType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProductType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tag(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Tag());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ImageUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImageUri());
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
struct produce<D, Windows::ApplicationModel::Store::IProductPurchaseDisplayProperties> : produce_base<D, Windows::ApplicationModel::Store::IProductPurchaseDisplayProperties>
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

    HRESULT __stdcall put_Description(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Image(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Image());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Image(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Image(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::IProductPurchaseDisplayPropertiesFactory> : produce_base<D, Windows::ApplicationModel::Store::IProductPurchaseDisplayPropertiesFactory>
{
    HRESULT __stdcall abi_CreateProductPurchaseDisplayProperties(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::ApplicationModel::Store::IProductPurchaseDisplayProperties> displayProperties) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *displayProperties = detach_abi(this->shim().CreateProductPurchaseDisplayProperties(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *displayProperties = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::IPurchaseResults> : produce_base<D, Windows::ApplicationModel::Store::IPurchaseResults>
{
    HRESULT __stdcall get_Status(Windows::ApplicationModel::Store::ProductPurchaseStatus * value) noexcept override
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

    HRESULT __stdcall get_TransactionId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransactionId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReceiptXml(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReceiptXml());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OfferId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OfferId());
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
struct produce<D, Windows::ApplicationModel::Store::IUnfulfilledConsumable> : produce_base<D, Windows::ApplicationModel::Store::IUnfulfilledConsumable>
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

    HRESULT __stdcall get_TransactionId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransactionId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OfferId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OfferId());
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

namespace Windows::ApplicationModel::Store {

template <typename D> Windows::ApplicationModel::Store::LicenseInformation impl_ICurrentApp<D>::LicenseInformation() const
{
    Windows::ApplicationModel::Store::LicenseInformation value { nullptr };
    check_hresult(WINRT_SHIM(ICurrentApp)->get_LicenseInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_ICurrentApp<D>::LinkUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ICurrentApp)->get_LinkUri(put_abi(value)));
    return value;
}

template <typename D> GUID impl_ICurrentApp<D>::AppId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(ICurrentApp)->get_AppId(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICurrentApp<D>::RequestAppPurchaseAsync(bool includeReceipt) const
{
    Windows::Foundation::IAsyncOperation<hstring> requestAppPurchaseOperation;
    check_hresult(WINRT_SHIM(ICurrentApp)->abi_RequestAppPurchaseAsync(includeReceipt, put_abi(requestAppPurchaseOperation)));
    return requestAppPurchaseOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICurrentApp<D>::RequestProductPurchaseAsync(hstring_view productId, bool includeReceipt) const
{
    Windows::Foundation::IAsyncOperation<hstring> requestProductPurchaseOperation;
    check_hresult(WINRT_SHIM(ICurrentApp)->abi_RequestProductPurchaseAsync(get_abi(productId), includeReceipt, put_abi(requestProductPurchaseOperation)));
    return requestProductPurchaseOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> impl_ICurrentApp<D>::LoadListingInformationAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> loadListingOperation;
    check_hresult(WINRT_SHIM(ICurrentApp)->abi_LoadListingInformationAsync(put_abi(loadListingOperation)));
    return loadListingOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICurrentApp<D>::GetAppReceiptAsync() const
{
    Windows::Foundation::IAsyncOperation<hstring> appReceiptOperation;
    check_hresult(WINRT_SHIM(ICurrentApp)->abi_GetAppReceiptAsync(put_abi(appReceiptOperation)));
    return appReceiptOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICurrentApp<D>::GetProductReceiptAsync(hstring_view productId) const
{
    Windows::Foundation::IAsyncOperation<hstring> getProductReceiptOperation;
    check_hresult(WINRT_SHIM(ICurrentApp)->abi_GetProductReceiptAsync(get_abi(productId), put_abi(getProductReceiptOperation)));
    return getProductReceiptOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Store::FulfillmentResult> impl_ICurrentAppWithConsumables<D>::ReportConsumableFulfillmentAsync(hstring_view productId, GUID transactionId) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Store::FulfillmentResult> reportConsumableFulfillmentOperation;
    check_hresult(WINRT_SHIM(ICurrentAppWithConsumables)->abi_ReportConsumableFulfillmentAsync(get_abi(productId), transactionId, put_abi(reportConsumableFulfillmentOperation)));
    return reportConsumableFulfillmentOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> impl_ICurrentAppWithConsumables<D>::RequestProductPurchaseAsync(hstring_view productId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> requestProductPurchaseWithResultsOperation;
    check_hresult(WINRT_SHIM(ICurrentAppWithConsumables)->abi_RequestProductPurchaseWithResultsAsync(get_abi(productId), put_abi(requestProductPurchaseWithResultsOperation)));
    return requestProductPurchaseWithResultsOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> impl_ICurrentAppWithConsumables<D>::RequestProductPurchaseAsync(hstring_view productId, hstring_view offerId, const Windows::ApplicationModel::Store::ProductPurchaseDisplayProperties & displayProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> requestProductPurchaseWithDisplayPropertiesOperation;
    check_hresult(WINRT_SHIM(ICurrentAppWithConsumables)->abi_RequestProductPurchaseWithDisplayPropertiesAsync(get_abi(productId), get_abi(offerId), get_abi(displayProperties), put_abi(requestProductPurchaseWithDisplayPropertiesOperation)));
    return requestProductPurchaseWithDisplayPropertiesOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>> impl_ICurrentAppWithConsumables<D>::GetUnfulfilledConsumablesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>> getUnfulfilledConsumablesOperation;
    check_hresult(WINRT_SHIM(ICurrentAppWithConsumables)->abi_GetUnfulfilledConsumablesAsync(put_abi(getUnfulfilledConsumablesOperation)));
    return getUnfulfilledConsumablesOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICurrentAppWithCampaignId<D>::GetAppPurchaseCampaignIdAsync() const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(ICurrentAppWithCampaignId)->abi_GetAppPurchaseCampaignIdAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICurrentApp2Statics<D>::GetCustomerPurchaseIdAsync(hstring_view serviceTicket, hstring_view publisherUserId) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(ICurrentApp2Statics)->abi_GetCustomerPurchaseIdAsync(get_abi(serviceTicket), get_abi(publisherUserId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICurrentApp2Statics<D>::GetCustomerCollectionsIdAsync(hstring_view serviceTicket, hstring_view publisherUserId) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(ICurrentApp2Statics)->abi_GetCustomerCollectionsIdAsync(get_abi(serviceTicket), get_abi(publisherUserId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::ApplicationModel::Store::LicenseInformation impl_ICurrentAppSimulator<D>::LicenseInformation() const
{
    Windows::ApplicationModel::Store::LicenseInformation value { nullptr };
    check_hresult(WINRT_SHIM(ICurrentAppSimulator)->get_LicenseInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_ICurrentAppSimulator<D>::LinkUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ICurrentAppSimulator)->get_LinkUri(put_abi(value)));
    return value;
}

template <typename D> GUID impl_ICurrentAppSimulator<D>::AppId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(ICurrentAppSimulator)->get_AppId(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICurrentAppSimulator<D>::RequestAppPurchaseAsync(bool includeReceipt) const
{
    Windows::Foundation::IAsyncOperation<hstring> requestAppPurchaseOperation;
    check_hresult(WINRT_SHIM(ICurrentAppSimulator)->abi_RequestAppPurchaseAsync(includeReceipt, put_abi(requestAppPurchaseOperation)));
    return requestAppPurchaseOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICurrentAppSimulator<D>::RequestProductPurchaseAsync(hstring_view productId, bool includeReceipt) const
{
    Windows::Foundation::IAsyncOperation<hstring> requestProductPurchaseOperation;
    check_hresult(WINRT_SHIM(ICurrentAppSimulator)->abi_RequestProductPurchaseAsync(get_abi(productId), includeReceipt, put_abi(requestProductPurchaseOperation)));
    return requestProductPurchaseOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> impl_ICurrentAppSimulator<D>::LoadListingInformationAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> loadListingOperation;
    check_hresult(WINRT_SHIM(ICurrentAppSimulator)->abi_LoadListingInformationAsync(put_abi(loadListingOperation)));
    return loadListingOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICurrentAppSimulator<D>::GetAppReceiptAsync() const
{
    Windows::Foundation::IAsyncOperation<hstring> appReceiptOperation;
    check_hresult(WINRT_SHIM(ICurrentAppSimulator)->abi_GetAppReceiptAsync(put_abi(appReceiptOperation)));
    return appReceiptOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICurrentAppSimulator<D>::GetProductReceiptAsync(hstring_view productId) const
{
    Windows::Foundation::IAsyncOperation<hstring> getProductReceiptOperation;
    check_hresult(WINRT_SHIM(ICurrentAppSimulator)->abi_GetProductReceiptAsync(get_abi(productId), put_abi(getProductReceiptOperation)));
    return getProductReceiptOperation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ICurrentAppSimulator<D>::ReloadSimulatorAsync(const Windows::Storage::StorageFile & simulatorSettingsFile) const
{
    Windows::Foundation::IAsyncAction reloadSimulatorOperation;
    check_hresult(WINRT_SHIM(ICurrentAppSimulator)->abi_ReloadSimulatorAsync(get_abi(simulatorSettingsFile), put_abi(reloadSimulatorOperation)));
    return reloadSimulatorOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICurrentAppSimulatorWithCampaignId<D>::GetAppPurchaseCampaignIdAsync() const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(ICurrentAppSimulatorWithCampaignId)->abi_GetAppPurchaseCampaignIdAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Store::FulfillmentResult> impl_ICurrentAppSimulatorWithConsumables<D>::ReportConsumableFulfillmentAsync(hstring_view productId, GUID transactionId) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Store::FulfillmentResult> reportConsumableFulfillmentOperation;
    check_hresult(WINRT_SHIM(ICurrentAppSimulatorWithConsumables)->abi_ReportConsumableFulfillmentAsync(get_abi(productId), transactionId, put_abi(reportConsumableFulfillmentOperation)));
    return reportConsumableFulfillmentOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> impl_ICurrentAppSimulatorWithConsumables<D>::RequestProductPurchaseAsync(hstring_view productId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> requestProductPurchaseWithResultsOperation;
    check_hresult(WINRT_SHIM(ICurrentAppSimulatorWithConsumables)->abi_RequestProductPurchaseWithResultsAsync(get_abi(productId), put_abi(requestProductPurchaseWithResultsOperation)));
    return requestProductPurchaseWithResultsOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> impl_ICurrentAppSimulatorWithConsumables<D>::RequestProductPurchaseAsync(hstring_view productId, hstring_view offerId, const Windows::ApplicationModel::Store::ProductPurchaseDisplayProperties & displayProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> requestProductPurchaseWithDisplayPropertiesOperation;
    check_hresult(WINRT_SHIM(ICurrentAppSimulatorWithConsumables)->abi_RequestProductPurchaseWithDisplayPropertiesAsync(get_abi(productId), get_abi(offerId), get_abi(displayProperties), put_abi(requestProductPurchaseWithDisplayPropertiesOperation)));
    return requestProductPurchaseWithDisplayPropertiesOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>> impl_ICurrentAppSimulatorWithConsumables<D>::GetUnfulfilledConsumablesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>> getUnfulfilledConsumablesOperation;
    check_hresult(WINRT_SHIM(ICurrentAppSimulatorWithConsumables)->abi_GetUnfulfilledConsumablesAsync(put_abi(getUnfulfilledConsumablesOperation)));
    return getUnfulfilledConsumablesOperation;
}

template <typename D> Windows::ApplicationModel::Store::ProductPurchaseStatus impl_IPurchaseResults<D>::Status() const
{
    Windows::ApplicationModel::Store::ProductPurchaseStatus value {};
    check_hresult(WINRT_SHIM(IPurchaseResults)->get_Status(&value));
    return value;
}

template <typename D> GUID impl_IPurchaseResults<D>::TransactionId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IPurchaseResults)->get_TransactionId(&value));
    return value;
}

template <typename D> hstring impl_IPurchaseResults<D>::ReceiptXml() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPurchaseResults)->get_ReceiptXml(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPurchaseResults<D>::OfferId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPurchaseResults)->get_OfferId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::ProductLicense> impl_ILicenseInformation<D>::ProductLicenses() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::ProductLicense> value;
    check_hresult(WINRT_SHIM(ILicenseInformation)->get_ProductLicenses(put_abi(value)));
    return value;
}

template <typename D> bool impl_ILicenseInformation<D>::IsActive() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILicenseInformation)->get_IsActive(&value));
    return value;
}

template <typename D> bool impl_ILicenseInformation<D>::IsTrial() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILicenseInformation)->get_IsTrial(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ILicenseInformation<D>::ExpirationDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ILicenseInformation)->get_ExpirationDate(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ILicenseInformation<D>::LicenseChanged(const Windows::ApplicationModel::Store::LicenseChangedEventHandler & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ILicenseInformation)->add_LicenseChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ILicenseInformation> impl_ILicenseInformation<D>::LicenseChanged(auto_revoke_t, const Windows::ApplicationModel::Store::LicenseChangedEventHandler & handler) const
{
    return impl::make_event_revoker<D, ILicenseInformation>(this, &ABI::Windows::ApplicationModel::Store::ILicenseInformation::remove_LicenseChanged, LicenseChanged(handler));
}

template <typename D> void impl_ILicenseInformation<D>::LicenseChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ILicenseInformation)->remove_LicenseChanged(cookie));
}

template <typename D> hstring impl_IProductLicense<D>::ProductId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProductLicense)->get_ProductId(put_abi(value)));
    return value;
}

template <typename D> bool impl_IProductLicense<D>::IsActive() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IProductLicense)->get_IsActive(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IProductLicense<D>::ExpirationDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IProductLicense)->get_ExpirationDate(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IListingInformation<D>::CurrentMarket() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IListingInformation)->get_CurrentMarket(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IListingInformation<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IListingInformation)->get_Description(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::ProductListing> impl_IListingInformation<D>::ProductListings() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::ProductListing> value;
    check_hresult(WINRT_SHIM(IListingInformation)->get_ProductListings(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IListingInformation<D>::FormattedPrice() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IListingInformation)->get_FormattedPrice(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IListingInformation<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IListingInformation)->get_Name(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IListingInformation<D>::AgeRating() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IListingInformation)->get_AgeRating(&value));
    return value;
}

template <typename D> hstring impl_IListingInformation2<D>::FormattedBasePrice() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IListingInformation2)->get_FormattedBasePrice(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IListingInformation2<D>::SaleEndDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IListingInformation2)->get_SaleEndDate(put_abi(value)));
    return value;
}

template <typename D> bool impl_IListingInformation2<D>::IsOnSale() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IListingInformation2)->get_IsOnSale(&value));
    return value;
}

template <typename D> hstring impl_IListingInformation2<D>::CurrencyCode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IListingInformation2)->get_CurrencyCode(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IProductListing<D>::ProductId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProductListing)->get_ProductId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IProductListing<D>::FormattedPrice() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProductListing)->get_FormattedPrice(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IProductListing<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProductListing)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Store::ProductType impl_IProductListingWithConsumables<D>::ProductType() const
{
    Windows::ApplicationModel::Store::ProductType value {};
    check_hresult(WINRT_SHIM(IProductListingWithConsumables)->get_ProductType(&value));
    return value;
}

template <typename D> hstring impl_IProductListing2<D>::FormattedBasePrice() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProductListing2)->get_FormattedBasePrice(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IProductListing2<D>::SaleEndDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IProductListing2)->get_SaleEndDate(put_abi(value)));
    return value;
}

template <typename D> bool impl_IProductListing2<D>::IsOnSale() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IProductListing2)->get_IsOnSale(&value));
    return value;
}

template <typename D> hstring impl_IProductListing2<D>::CurrencyCode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProductListing2)->get_CurrencyCode(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> impl_ICurrentAppStaticsWithFiltering<D>::LoadListingInformationByProductIdsAsync(iterable<hstring> productIds) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> loadListingOperation;
    check_hresult(WINRT_SHIM(ICurrentAppStaticsWithFiltering)->abi_LoadListingInformationByProductIdsAsync(get_abi(productIds), put_abi(loadListingOperation)));
    return loadListingOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> impl_ICurrentAppStaticsWithFiltering<D>::LoadListingInformationByKeywordsAsync(iterable<hstring> keywords) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> loadListingOperation;
    check_hresult(WINRT_SHIM(ICurrentAppStaticsWithFiltering)->abi_LoadListingInformationByKeywordsAsync(get_abi(keywords), put_abi(loadListingOperation)));
    return loadListingOperation;
}

template <typename D> void impl_ICurrentAppStaticsWithFiltering<D>::ReportProductFulfillment(hstring_view productId) const
{
    check_hresult(WINRT_SHIM(ICurrentAppStaticsWithFiltering)->abi_ReportProductFulfillment(get_abi(productId)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> impl_ICurrentAppSimulatorStaticsWithFiltering<D>::LoadListingInformationByProductIdsAsync(iterable<hstring> productIds) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> loadListingOperation;
    check_hresult(WINRT_SHIM(ICurrentAppSimulatorStaticsWithFiltering)->abi_LoadListingInformationByProductIdsAsync(get_abi(productIds), put_abi(loadListingOperation)));
    return loadListingOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> impl_ICurrentAppSimulatorStaticsWithFiltering<D>::LoadListingInformationByKeywordsAsync(iterable<hstring> keywords) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> loadListingOperation;
    check_hresult(WINRT_SHIM(ICurrentAppSimulatorStaticsWithFiltering)->abi_LoadListingInformationByKeywordsAsync(get_abi(keywords), put_abi(loadListingOperation)));
    return loadListingOperation;
}

template <typename D> bool impl_IProductLicenseWithFulfillment<D>::IsConsumable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IProductLicenseWithFulfillment)->get_IsConsumable(&value));
    return value;
}

template <typename D> hstring impl_IProductListingWithMetadata<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProductListingWithMetadata)->get_Description(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IIterable<hstring> impl_IProductListingWithMetadata<D>::Keywords() const
{
    Windows::Foundation::Collections::IIterable<hstring> value;
    check_hresult(WINRT_SHIM(IProductListingWithMetadata)->get_Keywords(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Store::ProductType impl_IProductListingWithMetadata<D>::ProductType() const
{
    Windows::ApplicationModel::Store::ProductType value {};
    check_hresult(WINRT_SHIM(IProductListingWithMetadata)->get_ProductType(&value));
    return value;
}

template <typename D> hstring impl_IProductListingWithMetadata<D>::Tag() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProductListingWithMetadata)->get_Tag(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IProductListingWithMetadata<D>::ImageUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IProductListingWithMetadata)->get_ImageUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUnfulfilledConsumable<D>::ProductId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUnfulfilledConsumable)->get_ProductId(put_abi(value)));
    return value;
}

template <typename D> GUID impl_IUnfulfilledConsumable<D>::TransactionId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IUnfulfilledConsumable)->get_TransactionId(&value));
    return value;
}

template <typename D> hstring impl_IUnfulfilledConsumable<D>::OfferId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUnfulfilledConsumable)->get_OfferId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IProductPurchaseDisplayProperties<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProductPurchaseDisplayProperties)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IProductPurchaseDisplayProperties<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IProductPurchaseDisplayProperties)->put_Name(get_abi(value)));
}

template <typename D> hstring impl_IProductPurchaseDisplayProperties<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProductPurchaseDisplayProperties)->get_Description(put_abi(value)));
    return value;
}

template <typename D> void impl_IProductPurchaseDisplayProperties<D>::Description(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IProductPurchaseDisplayProperties)->put_Description(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_IProductPurchaseDisplayProperties<D>::Image() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IProductPurchaseDisplayProperties)->get_Image(put_abi(value)));
    return value;
}

template <typename D> void impl_IProductPurchaseDisplayProperties<D>::Image(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IProductPurchaseDisplayProperties)->put_Image(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Store::ProductPurchaseDisplayProperties impl_IProductPurchaseDisplayPropertiesFactory<D>::CreateProductPurchaseDisplayProperties(hstring_view name) const
{
    Windows::ApplicationModel::Store::ProductPurchaseDisplayProperties displayProperties { nullptr };
    check_hresult(WINRT_SHIM(IProductPurchaseDisplayPropertiesFactory)->abi_CreateProductPurchaseDisplayProperties(get_abi(name), put_abi(displayProperties)));
    return displayProperties;
}

inline Windows::ApplicationModel::Store::LicenseInformation CurrentApp::LicenseInformation()
{
    return get_activation_factory<CurrentApp, ICurrentApp>().LicenseInformation();
}

inline Windows::Foundation::Uri CurrentApp::LinkUri()
{
    return get_activation_factory<CurrentApp, ICurrentApp>().LinkUri();
}

inline GUID CurrentApp::AppId()
{
    return get_activation_factory<CurrentApp, ICurrentApp>().AppId();
}

inline Windows::Foundation::IAsyncOperation<hstring> CurrentApp::RequestAppPurchaseAsync(bool includeReceipt)
{
    return get_activation_factory<CurrentApp, ICurrentApp>().RequestAppPurchaseAsync(includeReceipt);
}

inline Windows::Foundation::IAsyncOperation<hstring> CurrentApp::RequestProductPurchaseAsync(hstring_view productId, bool includeReceipt)
{
    return get_activation_factory<CurrentApp, ICurrentApp>().RequestProductPurchaseAsync(productId, includeReceipt);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> CurrentApp::LoadListingInformationAsync()
{
    return get_activation_factory<CurrentApp, ICurrentApp>().LoadListingInformationAsync();
}

inline Windows::Foundation::IAsyncOperation<hstring> CurrentApp::GetAppReceiptAsync()
{
    return get_activation_factory<CurrentApp, ICurrentApp>().GetAppReceiptAsync();
}

inline Windows::Foundation::IAsyncOperation<hstring> CurrentApp::GetProductReceiptAsync(hstring_view productId)
{
    return get_activation_factory<CurrentApp, ICurrentApp>().GetProductReceiptAsync(productId);
}

inline Windows::Foundation::IAsyncOperation<hstring> CurrentApp::GetCustomerPurchaseIdAsync(hstring_view serviceTicket, hstring_view publisherUserId)
{
    return get_activation_factory<CurrentApp, ICurrentApp2Statics>().GetCustomerPurchaseIdAsync(serviceTicket, publisherUserId);
}

inline Windows::Foundation::IAsyncOperation<hstring> CurrentApp::GetCustomerCollectionsIdAsync(hstring_view serviceTicket, hstring_view publisherUserId)
{
    return get_activation_factory<CurrentApp, ICurrentApp2Statics>().GetCustomerCollectionsIdAsync(serviceTicket, publisherUserId);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> CurrentApp::LoadListingInformationByProductIdsAsync(iterable<hstring> productIds)
{
    return get_activation_factory<CurrentApp, ICurrentAppStaticsWithFiltering>().LoadListingInformationByProductIdsAsync(productIds);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> CurrentApp::LoadListingInformationByKeywordsAsync(iterable<hstring> keywords)
{
    return get_activation_factory<CurrentApp, ICurrentAppStaticsWithFiltering>().LoadListingInformationByKeywordsAsync(keywords);
}

inline void CurrentApp::ReportProductFulfillment(hstring_view productId)
{
    get_activation_factory<CurrentApp, ICurrentAppStaticsWithFiltering>().ReportProductFulfillment(productId);
}

inline Windows::Foundation::IAsyncOperation<hstring> CurrentApp::GetAppPurchaseCampaignIdAsync()
{
    return get_activation_factory<CurrentApp, ICurrentAppWithCampaignId>().GetAppPurchaseCampaignIdAsync();
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Store::FulfillmentResult> CurrentApp::ReportConsumableFulfillmentAsync(hstring_view productId, GUID transactionId)
{
    return get_activation_factory<CurrentApp, ICurrentAppWithConsumables>().ReportConsumableFulfillmentAsync(productId, transactionId);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> CurrentApp::RequestProductPurchaseAsync(hstring_view productId)
{
    return get_activation_factory<CurrentApp, ICurrentAppWithConsumables>().RequestProductPurchaseAsync(productId);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> CurrentApp::RequestProductPurchaseAsync(hstring_view productId, hstring_view offerId, const Windows::ApplicationModel::Store::ProductPurchaseDisplayProperties & displayProperties)
{
    return get_activation_factory<CurrentApp, ICurrentAppWithConsumables>().RequestProductPurchaseAsync(productId, offerId, displayProperties);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>> CurrentApp::GetUnfulfilledConsumablesAsync()
{
    return get_activation_factory<CurrentApp, ICurrentAppWithConsumables>().GetUnfulfilledConsumablesAsync();
}

inline Windows::ApplicationModel::Store::LicenseInformation CurrentAppSimulator::LicenseInformation()
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulator>().LicenseInformation();
}

inline Windows::Foundation::Uri CurrentAppSimulator::LinkUri()
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulator>().LinkUri();
}

inline GUID CurrentAppSimulator::AppId()
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulator>().AppId();
}

inline Windows::Foundation::IAsyncOperation<hstring> CurrentAppSimulator::RequestAppPurchaseAsync(bool includeReceipt)
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulator>().RequestAppPurchaseAsync(includeReceipt);
}

inline Windows::Foundation::IAsyncOperation<hstring> CurrentAppSimulator::RequestProductPurchaseAsync(hstring_view productId, bool includeReceipt)
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulator>().RequestProductPurchaseAsync(productId, includeReceipt);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> CurrentAppSimulator::LoadListingInformationAsync()
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulator>().LoadListingInformationAsync();
}

inline Windows::Foundation::IAsyncOperation<hstring> CurrentAppSimulator::GetAppReceiptAsync()
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulator>().GetAppReceiptAsync();
}

inline Windows::Foundation::IAsyncOperation<hstring> CurrentAppSimulator::GetProductReceiptAsync(hstring_view productId)
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulator>().GetProductReceiptAsync(productId);
}

inline Windows::Foundation::IAsyncAction CurrentAppSimulator::ReloadSimulatorAsync(const Windows::Storage::StorageFile & simulatorSettingsFile)
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulator>().ReloadSimulatorAsync(simulatorSettingsFile);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> CurrentAppSimulator::LoadListingInformationByProductIdsAsync(iterable<hstring> productIds)
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulatorStaticsWithFiltering>().LoadListingInformationByProductIdsAsync(productIds);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> CurrentAppSimulator::LoadListingInformationByKeywordsAsync(iterable<hstring> keywords)
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulatorStaticsWithFiltering>().LoadListingInformationByKeywordsAsync(keywords);
}

inline Windows::Foundation::IAsyncOperation<hstring> CurrentAppSimulator::GetAppPurchaseCampaignIdAsync()
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulatorWithCampaignId>().GetAppPurchaseCampaignIdAsync();
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Store::FulfillmentResult> CurrentAppSimulator::ReportConsumableFulfillmentAsync(hstring_view productId, GUID transactionId)
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulatorWithConsumables>().ReportConsumableFulfillmentAsync(productId, transactionId);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> CurrentAppSimulator::RequestProductPurchaseAsync(hstring_view productId)
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulatorWithConsumables>().RequestProductPurchaseAsync(productId);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> CurrentAppSimulator::RequestProductPurchaseAsync(hstring_view productId, hstring_view offerId, const Windows::ApplicationModel::Store::ProductPurchaseDisplayProperties & displayProperties)
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulatorWithConsumables>().RequestProductPurchaseAsync(productId, offerId, displayProperties);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>> CurrentAppSimulator::GetUnfulfilledConsumablesAsync()
{
    return get_activation_factory<CurrentAppSimulator, ICurrentAppSimulatorWithConsumables>().GetUnfulfilledConsumablesAsync();
}

inline ProductPurchaseDisplayProperties::ProductPurchaseDisplayProperties() :
    ProductPurchaseDisplayProperties(activate_instance<ProductPurchaseDisplayProperties>())
{}

inline ProductPurchaseDisplayProperties::ProductPurchaseDisplayProperties(hstring_view name) :
    ProductPurchaseDisplayProperties(get_activation_factory<ProductPurchaseDisplayProperties, IProductPurchaseDisplayPropertiesFactory>().CreateProductPurchaseDisplayProperties(name))
{}

}

}
#pragma warning(pop)
