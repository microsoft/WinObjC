// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.ApplicationModel.Store.Preview.3.h"
#include "Windows.ApplicationModel.Store.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics> : produce_base<D, Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics>
{
    HRESULT __stdcall abi_SetSystemConfiguration(impl::abi_arg_in<hstring> catalogHardwareManufacturerId, impl::abi_arg_in<hstring> catalogStoreContentModifierId, impl::abi_arg_in<Windows::Foundation::DateTime> systemConfigurationExpiration, impl::abi_arg_in<hstring> catalogHardwareDescriptor) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSystemConfiguration(*reinterpret_cast<const hstring *>(&catalogHardwareManufacturerId), *reinterpret_cast<const hstring *>(&catalogStoreContentModifierId), *reinterpret_cast<const Windows::Foundation::DateTime *>(&systemConfigurationExpiration), *reinterpret_cast<const hstring *>(&catalogHardwareDescriptor));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetMobileOperatorConfiguration(impl::abi_arg_in<hstring> mobileOperatorId, uint32_t appDownloadLimitInMegabytes, uint32_t updateDownloadLimitInMegabytes) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetMobileOperatorConfiguration(*reinterpret_cast<const hstring *>(&mobileOperatorId), appDownloadLimitInMegabytes, updateDownloadLimitInMegabytes);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStoreWebAccountId(impl::abi_arg_in<hstring> webAccountId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStoreWebAccountId(*reinterpret_cast<const hstring *>(&webAccountId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsStoreWebAccountId(impl::abi_arg_in<hstring> webAccountId, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStoreWebAccountId(*reinterpret_cast<const hstring *>(&webAccountId)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HardwareManufacturerInfo(impl::abi_arg_out<Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HardwareManufacturerInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FilterUnsupportedSystemFeaturesAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<winrt::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>> systemFeatures, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FilterUnsupportedSystemFeaturesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<winrt::Windows::ApplicationModel::Store::Preview::StoreSystemFeature> *>(&systemFeatures)));
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
struct produce<D, Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics2> : produce_base<D, Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics2>
{
    HRESULT __stdcall get_PurchasePromptingPolicy(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PurchasePromptingPolicy());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PurchasePromptingPolicy(impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PurchasePromptingPolicy(*reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics3> : produce_base<D, Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics3>
{
    HRESULT __stdcall abi_HasStoreWebAccount(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasStoreWebAccount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_HasStoreWebAccountForUser(impl::abi_arg_in<Windows::System::IUser> user, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasStoreWebAccountForUser(*reinterpret_cast<const Windows::System::User *>(&user)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStoreLogDataAsync(Windows::ApplicationModel::Store::Preview::StoreLogOptions options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetStoreLogDataAsync(options));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStoreWebAccountIdForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<hstring> webAccountId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStoreWebAccountIdForUser(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const hstring *>(&webAccountId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsStoreWebAccountIdForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<hstring> webAccountId, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStoreWebAccountIdForUser(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const hstring *>(&webAccountId)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPurchasePromptingPolicyForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetPurchasePromptingPolicyForUser(*reinterpret_cast<const Windows::System::User *>(&user)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPurchasePromptingPolicyForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPurchasePromptingPolicyForUser(*reinterpret_cast<const Windows::System::User *>(&user), *reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo> : produce_base<D, Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo>
{
    HRESULT __stdcall get_HardwareManufacturerId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HardwareManufacturerId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StoreContentModifierId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StoreContentModifierId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ModelName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ModelName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ManufacturerName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ManufacturerName());
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
struct produce<D, Windows::ApplicationModel::Store::Preview::IStorePreview> : produce_base<D, Windows::ApplicationModel::Store::Preview::IStorePreview>
{
    HRESULT __stdcall abi_RequestProductPurchaseByProductIdAndSkuIdAsync(impl::abi_arg_in<hstring> productId, impl::abi_arg_in<hstring> skuId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::StorePreviewPurchaseResults>> requestPurchaseBySkuIdOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestPurchaseBySkuIdOperation = detach_abi(this->shim().RequestProductPurchaseByProductIdAndSkuIdAsync(*reinterpret_cast<const hstring *>(&productId), *reinterpret_cast<const hstring *>(&skuId)));
            return S_OK;
        }
        catch (...)
        {
            *requestPurchaseBySkuIdOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadAddOnProductInfosAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo>>> loadAddOnProductInfosOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loadAddOnProductInfosOperation = detach_abi(this->shim().LoadAddOnProductInfosAsync());
            return S_OK;
        }
        catch (...)
        {
            *loadAddOnProductInfosOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo> : produce_base<D, Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo>
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

    HRESULT __stdcall get_ProductType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProductType());
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

    HRESULT __stdcall get_SkuInfoList(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::StorePreviewSkuInfo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SkuInfoList());
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
struct produce<D, Windows::ApplicationModel::Store::Preview::IStorePreviewPurchaseResults> : produce_base<D, Windows::ApplicationModel::Store::Preview::IStorePreviewPurchaseResults>
{
    HRESULT __stdcall get_ProductPurchaseStatus(Windows::ApplicationModel::Store::Preview::StorePreviewProductPurchaseStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProductPurchaseStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo> : produce_base<D, Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo>
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

    HRESULT __stdcall get_SkuId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SkuId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SkuType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SkuType());
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

    HRESULT __stdcall get_FormattedListPrice(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FormattedListPrice());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedData(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedData());
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

namespace Windows::ApplicationModel::Store::Preview {

template <typename D> hstring impl_IStorePreviewProductInfo<D>::ProductId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePreviewProductInfo)->get_ProductId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePreviewProductInfo<D>::ProductType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePreviewProductInfo)->get_ProductType(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePreviewProductInfo<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePreviewProductInfo)->get_Title(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePreviewProductInfo<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePreviewProductInfo)->get_Description(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::StorePreviewSkuInfo> impl_IStorePreviewProductInfo<D>::SkuInfoList() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::StorePreviewSkuInfo> value;
    check_hresult(WINRT_SHIM(IStorePreviewProductInfo)->get_SkuInfoList(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePreviewSkuInfo<D>::ProductId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePreviewSkuInfo)->get_ProductId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePreviewSkuInfo<D>::SkuId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePreviewSkuInfo)->get_SkuId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePreviewSkuInfo<D>::SkuType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePreviewSkuInfo)->get_SkuType(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePreviewSkuInfo<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePreviewSkuInfo)->get_Title(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePreviewSkuInfo<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePreviewSkuInfo)->get_Description(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePreviewSkuInfo<D>::CustomDeveloperData() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePreviewSkuInfo)->get_CustomDeveloperData(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePreviewSkuInfo<D>::CurrencyCode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePreviewSkuInfo)->get_CurrencyCode(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePreviewSkuInfo<D>::FormattedListPrice() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePreviewSkuInfo)->get_FormattedListPrice(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorePreviewSkuInfo<D>::ExtendedData() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStorePreviewSkuInfo)->get_ExtendedData(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Store::Preview::StorePreviewProductPurchaseStatus impl_IStorePreviewPurchaseResults<D>::ProductPurchaseStatus() const
{
    Windows::ApplicationModel::Store::Preview::StorePreviewProductPurchaseStatus value {};
    check_hresult(WINRT_SHIM(IStorePreviewPurchaseResults)->get_ProductPurchaseStatus(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::StorePreviewPurchaseResults> impl_IStorePreview<D>::RequestProductPurchaseByProductIdAndSkuIdAsync(hstring_view productId, hstring_view skuId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::StorePreviewPurchaseResults> requestPurchaseBySkuIdOperation;
    check_hresult(WINRT_SHIM(IStorePreview)->abi_RequestProductPurchaseByProductIdAndSkuIdAsync(get_abi(productId), get_abi(skuId), put_abi(requestPurchaseBySkuIdOperation)));
    return requestPurchaseBySkuIdOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo>> impl_IStorePreview<D>::LoadAddOnProductInfosAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo>> loadAddOnProductInfosOperation;
    check_hresult(WINRT_SHIM(IStorePreview)->abi_LoadAddOnProductInfosAsync(put_abi(loadAddOnProductInfosOperation)));
    return loadAddOnProductInfosOperation;
}

template <typename D> hstring impl_IStoreHardwareManufacturerInfo<D>::HardwareManufacturerId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreHardwareManufacturerInfo)->get_HardwareManufacturerId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreHardwareManufacturerInfo<D>::StoreContentModifierId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreHardwareManufacturerInfo)->get_StoreContentModifierId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreHardwareManufacturerInfo<D>::ModelName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreHardwareManufacturerInfo)->get_ModelName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStoreHardwareManufacturerInfo<D>::ManufacturerName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStoreHardwareManufacturerInfo)->get_ManufacturerName(put_abi(value)));
    return value;
}

template <typename D> void impl_IStoreConfigurationStatics<D>::SetSystemConfiguration(hstring_view catalogHardwareManufacturerId, hstring_view catalogStoreContentModifierId, const Windows::Foundation::DateTime & systemConfigurationExpiration, hstring_view catalogHardwareDescriptor) const
{
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics)->abi_SetSystemConfiguration(get_abi(catalogHardwareManufacturerId), get_abi(catalogStoreContentModifierId), get_abi(systemConfigurationExpiration), get_abi(catalogHardwareDescriptor)));
}

template <typename D> void impl_IStoreConfigurationStatics<D>::SetMobileOperatorConfiguration(hstring_view mobileOperatorId, uint32_t appDownloadLimitInMegabytes, uint32_t updateDownloadLimitInMegabytes) const
{
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics)->abi_SetMobileOperatorConfiguration(get_abi(mobileOperatorId), appDownloadLimitInMegabytes, updateDownloadLimitInMegabytes));
}

template <typename D> void impl_IStoreConfigurationStatics<D>::SetStoreWebAccountId(hstring_view webAccountId) const
{
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics)->abi_SetStoreWebAccountId(get_abi(webAccountId)));
}

template <typename D> bool impl_IStoreConfigurationStatics<D>::IsStoreWebAccountId(hstring_view webAccountId) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics)->abi_IsStoreWebAccountId(get_abi(webAccountId), &value));
    return value;
}

template <typename D> Windows::ApplicationModel::Store::Preview::StoreHardwareManufacturerInfo impl_IStoreConfigurationStatics<D>::HardwareManufacturerInfo() const
{
    Windows::ApplicationModel::Store::Preview::StoreHardwareManufacturerInfo value { nullptr };
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics)->get_HardwareManufacturerInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>> impl_IStoreConfigurationStatics<D>::FilterUnsupportedSystemFeaturesAsync(iterable<winrt::Windows::ApplicationModel::Store::Preview::StoreSystemFeature> systemFeatures) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>> operation;
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics)->abi_FilterUnsupportedSystemFeaturesAsync(get_abi(systemFeatures), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IStoreConfigurationStatics2<D>::PurchasePromptingPolicy() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics2)->get_PurchasePromptingPolicy(put_abi(value)));
    return value;
}

template <typename D> void impl_IStoreConfigurationStatics2<D>::PurchasePromptingPolicy(const optional<uint32_t> & value) const
{
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics2)->put_PurchasePromptingPolicy(get_abi(value)));
}

template <typename D> bool impl_IStoreConfigurationStatics3<D>::HasStoreWebAccount() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics3)->abi_HasStoreWebAccount(&value));
    return value;
}

template <typename D> bool impl_IStoreConfigurationStatics3<D>::HasStoreWebAccountForUser(const Windows::System::User & user) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics3)->abi_HasStoreWebAccountForUser(get_abi(user), &value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference> impl_IStoreConfigurationStatics3<D>::GetStoreLogDataAsync(Windows::ApplicationModel::Store::Preview::StoreLogOptions options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference> operation;
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics3)->abi_GetStoreLogDataAsync(options, put_abi(operation)));
    return operation;
}

template <typename D> void impl_IStoreConfigurationStatics3<D>::SetStoreWebAccountIdForUser(const Windows::System::User & user, hstring_view webAccountId) const
{
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics3)->abi_SetStoreWebAccountIdForUser(get_abi(user), get_abi(webAccountId)));
}

template <typename D> bool impl_IStoreConfigurationStatics3<D>::IsStoreWebAccountIdForUser(const Windows::System::User & user, hstring_view webAccountId) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics3)->abi_IsStoreWebAccountIdForUser(get_abi(user), get_abi(webAccountId), &value));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IStoreConfigurationStatics3<D>::GetPurchasePromptingPolicyForUser(const Windows::System::User & user) const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics3)->abi_GetPurchasePromptingPolicyForUser(get_abi(user), put_abi(value)));
    return value;
}

template <typename D> void impl_IStoreConfigurationStatics3<D>::SetPurchasePromptingPolicyForUser(const Windows::System::User & user, const optional<uint32_t> & value) const
{
    check_hresult(WINRT_SHIM(IStoreConfigurationStatics3)->abi_SetPurchasePromptingPolicyForUser(get_abi(user), get_abi(value)));
}

inline void StoreConfiguration::SetSystemConfiguration(hstring_view catalogHardwareManufacturerId, hstring_view catalogStoreContentModifierId, const Windows::Foundation::DateTime & systemConfigurationExpiration, hstring_view catalogHardwareDescriptor)
{
    get_activation_factory<StoreConfiguration, IStoreConfigurationStatics>().SetSystemConfiguration(catalogHardwareManufacturerId, catalogStoreContentModifierId, systemConfigurationExpiration, catalogHardwareDescriptor);
}

inline void StoreConfiguration::SetMobileOperatorConfiguration(hstring_view mobileOperatorId, uint32_t appDownloadLimitInMegabytes, uint32_t updateDownloadLimitInMegabytes)
{
    get_activation_factory<StoreConfiguration, IStoreConfigurationStatics>().SetMobileOperatorConfiguration(mobileOperatorId, appDownloadLimitInMegabytes, updateDownloadLimitInMegabytes);
}

inline void StoreConfiguration::SetStoreWebAccountId(hstring_view webAccountId)
{
    get_activation_factory<StoreConfiguration, IStoreConfigurationStatics>().SetStoreWebAccountId(webAccountId);
}

inline bool StoreConfiguration::IsStoreWebAccountId(hstring_view webAccountId)
{
    return get_activation_factory<StoreConfiguration, IStoreConfigurationStatics>().IsStoreWebAccountId(webAccountId);
}

inline Windows::ApplicationModel::Store::Preview::StoreHardwareManufacturerInfo StoreConfiguration::HardwareManufacturerInfo()
{
    return get_activation_factory<StoreConfiguration, IStoreConfigurationStatics>().HardwareManufacturerInfo();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>> StoreConfiguration::FilterUnsupportedSystemFeaturesAsync(iterable<winrt::Windows::ApplicationModel::Store::Preview::StoreSystemFeature> systemFeatures)
{
    return get_activation_factory<StoreConfiguration, IStoreConfigurationStatics>().FilterUnsupportedSystemFeaturesAsync(systemFeatures);
}

inline Windows::Foundation::IReference<uint32_t> StoreConfiguration::PurchasePromptingPolicy()
{
    return get_activation_factory<StoreConfiguration, IStoreConfigurationStatics2>().PurchasePromptingPolicy();
}

inline void StoreConfiguration::PurchasePromptingPolicy(const optional<uint32_t> & value)
{
    get_activation_factory<StoreConfiguration, IStoreConfigurationStatics2>().PurchasePromptingPolicy(value);
}

inline bool StoreConfiguration::HasStoreWebAccount()
{
    return get_activation_factory<StoreConfiguration, IStoreConfigurationStatics3>().HasStoreWebAccount();
}

inline bool StoreConfiguration::HasStoreWebAccountForUser(const Windows::System::User & user)
{
    return get_activation_factory<StoreConfiguration, IStoreConfigurationStatics3>().HasStoreWebAccountForUser(user);
}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference> StoreConfiguration::GetStoreLogDataAsync(Windows::ApplicationModel::Store::Preview::StoreLogOptions options)
{
    return get_activation_factory<StoreConfiguration, IStoreConfigurationStatics3>().GetStoreLogDataAsync(options);
}

inline void StoreConfiguration::SetStoreWebAccountIdForUser(const Windows::System::User & user, hstring_view webAccountId)
{
    get_activation_factory<StoreConfiguration, IStoreConfigurationStatics3>().SetStoreWebAccountIdForUser(user, webAccountId);
}

inline bool StoreConfiguration::IsStoreWebAccountIdForUser(const Windows::System::User & user, hstring_view webAccountId)
{
    return get_activation_factory<StoreConfiguration, IStoreConfigurationStatics3>().IsStoreWebAccountIdForUser(user, webAccountId);
}

inline Windows::Foundation::IReference<uint32_t> StoreConfiguration::GetPurchasePromptingPolicyForUser(const Windows::System::User & user)
{
    return get_activation_factory<StoreConfiguration, IStoreConfigurationStatics3>().GetPurchasePromptingPolicyForUser(user);
}

inline void StoreConfiguration::SetPurchasePromptingPolicyForUser(const Windows::System::User & user, const optional<uint32_t> & value)
{
    get_activation_factory<StoreConfiguration, IStoreConfigurationStatics3>().SetPurchasePromptingPolicyForUser(user, value);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::Preview::StorePreviewPurchaseResults> StorePreview::RequestProductPurchaseByProductIdAndSkuIdAsync(hstring_view productId, hstring_view skuId)
{
    return get_activation_factory<StorePreview, IStorePreview>().RequestProductPurchaseByProductIdAndSkuIdAsync(productId, skuId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo>> StorePreview::LoadAddOnProductInfosAsync()
{
    return get_activation_factory<StorePreview, IStorePreview>().LoadAddOnProductInfosAsync();
}

}

}
#pragma warning(pop)
