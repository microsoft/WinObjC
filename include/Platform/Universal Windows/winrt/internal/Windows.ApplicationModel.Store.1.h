// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Store.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Store {

struct __declspec(uuid("d52dc065-da3f-4685-995e-9b482eb5e603")) __declspec(novtable) ICurrentApp : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LicenseInformation(Windows::ApplicationModel::Store::ILicenseInformation ** value) = 0;
    virtual HRESULT __stdcall get_LinkUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_AppId(GUID * value) = 0;
    virtual HRESULT __stdcall abi_RequestAppPurchaseAsync(bool includeReceipt, Windows::Foundation::IAsyncOperation<hstring> ** requestAppPurchaseOperation) = 0;
    virtual HRESULT __stdcall abi_RequestProductPurchaseAsync(hstring productId, bool includeReceipt, Windows::Foundation::IAsyncOperation<hstring> ** requestProductPurchaseOperation) = 0;
    virtual HRESULT __stdcall abi_LoadListingInformationAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> ** loadListingOperation) = 0;
    virtual HRESULT __stdcall abi_GetAppReceiptAsync(Windows::Foundation::IAsyncOperation<hstring> ** appReceiptOperation) = 0;
    virtual HRESULT __stdcall abi_GetProductReceiptAsync(hstring productId, Windows::Foundation::IAsyncOperation<hstring> ** getProductReceiptOperation) = 0;
};

struct __declspec(uuid("df4e6e2d-3171-4ad3-8614-2c61244373cb")) __declspec(novtable) ICurrentApp2Statics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCustomerPurchaseIdAsync(hstring serviceTicket, hstring publisherUserId, Windows::Foundation::IAsyncOperation<hstring> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetCustomerCollectionsIdAsync(hstring serviceTicket, hstring publisherUserId, Windows::Foundation::IAsyncOperation<hstring> ** operation) = 0;
};

struct __declspec(uuid("f17f9db1-74cd-4787-9787-19866e9a5559")) __declspec(novtable) ICurrentAppSimulator : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LicenseInformation(Windows::ApplicationModel::Store::ILicenseInformation ** value) = 0;
    virtual HRESULT __stdcall get_LinkUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_AppId(GUID * value) = 0;
    virtual HRESULT __stdcall abi_RequestAppPurchaseAsync(bool includeReceipt, Windows::Foundation::IAsyncOperation<hstring> ** requestAppPurchaseOperation) = 0;
    virtual HRESULT __stdcall abi_RequestProductPurchaseAsync(hstring productId, bool includeReceipt, Windows::Foundation::IAsyncOperation<hstring> ** requestProductPurchaseOperation) = 0;
    virtual HRESULT __stdcall abi_LoadListingInformationAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> ** loadListingOperation) = 0;
    virtual HRESULT __stdcall abi_GetAppReceiptAsync(Windows::Foundation::IAsyncOperation<hstring> ** appReceiptOperation) = 0;
    virtual HRESULT __stdcall abi_GetProductReceiptAsync(hstring productId, Windows::Foundation::IAsyncOperation<hstring> ** getProductReceiptOperation) = 0;
    virtual HRESULT __stdcall abi_ReloadSimulatorAsync(Windows::Storage::IStorageFile * simulatorSettingsFile, Windows::Foundation::IAsyncAction ** reloadSimulatorOperation) = 0;
};

struct __declspec(uuid("617e70e2-f86f-4b54-9666-dde285092c68")) __declspec(novtable) ICurrentAppSimulatorStaticsWithFiltering : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_LoadListingInformationByProductIdsAsync(Windows::Foundation::Collections::IIterable<hstring> * productIds, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> ** loadListingOperation) = 0;
    virtual HRESULT __stdcall abi_LoadListingInformationByKeywordsAsync(Windows::Foundation::Collections::IIterable<hstring> * keywords, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> ** loadListingOperation) = 0;
};

struct __declspec(uuid("84678a43-df00-4672-a43f-b25b1441cfcf")) __declspec(novtable) ICurrentAppSimulatorWithCampaignId : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAppPurchaseCampaignIdAsync(Windows::Foundation::IAsyncOperation<hstring> ** operation) = 0;
};

struct __declspec(uuid("4e51f0ab-20e7-4412-9b85-59bb78388667")) __declspec(novtable) ICurrentAppSimulatorWithConsumables : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ReportConsumableFulfillmentAsync(hstring productId, GUID transactionId, Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Store::FulfillmentResult> ** reportConsumableFulfillmentOperation) = 0;
    virtual HRESULT __stdcall abi_RequestProductPurchaseWithResultsAsync(hstring productId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> ** requestProductPurchaseWithResultsOperation) = 0;
    virtual HRESULT __stdcall abi_RequestProductPurchaseWithDisplayPropertiesAsync(hstring productId, hstring offerId, Windows::ApplicationModel::Store::IProductPurchaseDisplayProperties * displayProperties, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> ** requestProductPurchaseWithDisplayPropertiesOperation) = 0;
    virtual HRESULT __stdcall abi_GetUnfulfilledConsumablesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>> ** getUnfulfilledConsumablesOperation) = 0;
};

struct __declspec(uuid("d36d6542-9085-438e-97ba-a25c976be2fd")) __declspec(novtable) ICurrentAppStaticsWithFiltering : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_LoadListingInformationByProductIdsAsync(Windows::Foundation::Collections::IIterable<hstring> * productIds, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> ** loadListingOperation) = 0;
    virtual HRESULT __stdcall abi_LoadListingInformationByKeywordsAsync(Windows::Foundation::Collections::IIterable<hstring> * keywords, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> ** loadListingOperation) = 0;
    virtual HRESULT __stdcall abi_ReportProductFulfillment(hstring productId) = 0;
};

struct __declspec(uuid("312f4cd0-36c1-44a6-b32b-432d608e4dd6")) __declspec(novtable) ICurrentAppWithCampaignId : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAppPurchaseCampaignIdAsync(Windows::Foundation::IAsyncOperation<hstring> ** operation) = 0;
};

struct __declspec(uuid("844e0071-9e4f-4f79-995a-5f91172e6cef")) __declspec(novtable) ICurrentAppWithConsumables : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ReportConsumableFulfillmentAsync(hstring productId, GUID transactionId, Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Store::FulfillmentResult> ** reportConsumableFulfillmentOperation) = 0;
    virtual HRESULT __stdcall abi_RequestProductPurchaseWithResultsAsync(hstring productId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> ** requestProductPurchaseWithResultsOperation) = 0;
    virtual HRESULT __stdcall abi_RequestProductPurchaseWithDisplayPropertiesAsync(hstring productId, hstring offerId, Windows::ApplicationModel::Store::IProductPurchaseDisplayProperties * displayProperties, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> ** requestProductPurchaseWithDisplayPropertiesOperation) = 0;
    virtual HRESULT __stdcall abi_GetUnfulfilledConsumablesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>> ** getUnfulfilledConsumablesOperation) = 0;
};

struct __declspec(uuid("8eb7dc30-f170-4ed5-8e21-1516da3fd367")) __declspec(novtable) ILicenseInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProductLicenses(Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::ProductLicense> ** value) = 0;
    virtual HRESULT __stdcall get_IsActive(bool * value) = 0;
    virtual HRESULT __stdcall get_IsTrial(bool * value) = 0;
    virtual HRESULT __stdcall get_ExpirationDate(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall add_LicenseChanged(Windows::ApplicationModel::Store::LicenseChangedEventHandler * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_LicenseChanged(event_token cookie) = 0;
};

struct __declspec(uuid("588b4abf-bc74-4383-b78c-99606323dece")) __declspec(novtable) IListingInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CurrentMarket(hstring * value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall get_ProductListings(Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::ProductListing> ** value) = 0;
    virtual HRESULT __stdcall get_FormattedPrice(hstring * value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_AgeRating(uint32_t * value) = 0;
};

struct __declspec(uuid("c0fd2c1d-b30e-4384-84ea-72fefa82223e")) __declspec(novtable) IListingInformation2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FormattedBasePrice(hstring * value) = 0;
    virtual HRESULT __stdcall get_SaleEndDate(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_IsOnSale(bool * value) = 0;
    virtual HRESULT __stdcall get_CurrencyCode(hstring * value) = 0;
};

struct __declspec(uuid("363308c7-2bcf-4c0e-8f2f-e808aaa8f99d")) __declspec(novtable) IProductLicense : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProductId(hstring * value) = 0;
    virtual HRESULT __stdcall get_IsActive(bool * value) = 0;
    virtual HRESULT __stdcall get_ExpirationDate(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("fc535c8a-f667-40f3-ba3c-045a63abb3ac")) __declspec(novtable) IProductLicenseWithFulfillment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsConsumable(bool * value) = 0;
};

struct __declspec(uuid("45a7d6ad-c750-4d9c-947c-b00dcbf9e9c2")) __declspec(novtable) IProductListing : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProductId(hstring * value) = 0;
    virtual HRESULT __stdcall get_FormattedPrice(hstring * value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
};

struct __declspec(uuid("f89e290f-73fe-494d-a939-08a9b2495abe")) __declspec(novtable) IProductListing2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FormattedBasePrice(hstring * value) = 0;
    virtual HRESULT __stdcall get_SaleEndDate(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_IsOnSale(bool * value) = 0;
    virtual HRESULT __stdcall get_CurrencyCode(hstring * value) = 0;
};

struct __declspec(uuid("eb9e9790-8f6b-481f-93a7-5c3a63068149")) __declspec(novtable) IProductListingWithConsumables : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProductType(winrt::Windows::ApplicationModel::Store::ProductType * value) = 0;
};

struct __declspec(uuid("124da567-23f8-423e-9532-189943c40ace")) __declspec(novtable) IProductListingWithMetadata : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall get_Keywords(Windows::Foundation::Collections::IIterable<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_ProductType(winrt::Windows::ApplicationModel::Store::ProductType * value) = 0;
    virtual HRESULT __stdcall get_Tag(hstring * value) = 0;
    virtual HRESULT __stdcall get_ImageUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
};

struct __declspec(uuid("d70b7420-bc92-401b-a809-c9b2e5dbbdaf")) __declspec(novtable) IProductPurchaseDisplayProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall put_Name(hstring value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall put_Description(hstring value) = 0;
    virtual HRESULT __stdcall get_Image(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_Image(Windows::Foundation::IUriRuntimeClass * value) = 0;
};

struct __declspec(uuid("6f491df4-32d6-4b40-b474-b83038a4d9cf")) __declspec(novtable) IProductPurchaseDisplayPropertiesFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateProductPurchaseDisplayProperties(hstring name, Windows::ApplicationModel::Store::IProductPurchaseDisplayProperties ** displayProperties) = 0;
};

struct __declspec(uuid("ed50b37e-8656-4f65-b8c8-ac7e0cb1a1c2")) __declspec(novtable) IPurchaseResults : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::ApplicationModel::Store::ProductPurchaseStatus * value) = 0;
    virtual HRESULT __stdcall get_TransactionId(GUID * value) = 0;
    virtual HRESULT __stdcall get_ReceiptXml(hstring * value) = 0;
    virtual HRESULT __stdcall get_OfferId(hstring * value) = 0;
};

struct __declspec(uuid("2df7fbbb-1cdd-4cb8-a014-7b9cf8986927")) __declspec(novtable) IUnfulfilledConsumable : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProductId(hstring * value) = 0;
    virtual HRESULT __stdcall get_TransactionId(GUID * value) = 0;
    virtual HRESULT __stdcall get_OfferId(hstring * value) = 0;
};

struct __declspec(uuid("d4a50255-1369-4c36-832f-6f2d88e3659b")) __declspec(novtable) LicenseChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke() = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Store::LicenseInformation> { using default_interface = Windows::ApplicationModel::Store::ILicenseInformation; };
template <> struct traits<Windows::ApplicationModel::Store::ListingInformation> { using default_interface = Windows::ApplicationModel::Store::IListingInformation; };
template <> struct traits<Windows::ApplicationModel::Store::ProductLicense> { using default_interface = Windows::ApplicationModel::Store::IProductLicense; };
template <> struct traits<Windows::ApplicationModel::Store::ProductListing> { using default_interface = Windows::ApplicationModel::Store::IProductListing; };
template <> struct traits<Windows::ApplicationModel::Store::ProductPurchaseDisplayProperties> { using default_interface = Windows::ApplicationModel::Store::IProductPurchaseDisplayProperties; };
template <> struct traits<Windows::ApplicationModel::Store::PurchaseResults> { using default_interface = Windows::ApplicationModel::Store::IPurchaseResults; };
template <> struct traits<Windows::ApplicationModel::Store::UnfulfilledConsumable> { using default_interface = Windows::ApplicationModel::Store::IUnfulfilledConsumable; };

}

namespace Windows::ApplicationModel::Store {

template <typename D>
struct WINRT_EBO impl_ICurrentApp
{
    Windows::ApplicationModel::Store::LicenseInformation LicenseInformation() const;
    Windows::Foundation::Uri LinkUri() const;
    GUID AppId() const;
    Windows::Foundation::IAsyncOperation<hstring> RequestAppPurchaseAsync(bool includeReceipt) const;
    [[deprecated("RequestProductPurchaseAsync(productId, includeReceipt) may be altered or unavailable for releases after Windows 8.1. Instead, use RequestProductPurchaseAsync(productId).")]] Windows::Foundation::IAsyncOperation<hstring> RequestProductPurchaseAsync(hstring_view productId, bool includeReceipt) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> LoadListingInformationAsync() const;
    Windows::Foundation::IAsyncOperation<hstring> GetAppReceiptAsync() const;
    Windows::Foundation::IAsyncOperation<hstring> GetProductReceiptAsync(hstring_view productId) const;
};

template <typename D>
struct WINRT_EBO impl_ICurrentApp2Statics
{
    Windows::Foundation::IAsyncOperation<hstring> GetCustomerPurchaseIdAsync(hstring_view serviceTicket, hstring_view publisherUserId) const;
    Windows::Foundation::IAsyncOperation<hstring> GetCustomerCollectionsIdAsync(hstring_view serviceTicket, hstring_view publisherUserId) const;
};

template <typename D>
struct WINRT_EBO impl_ICurrentAppSimulator
{
    Windows::ApplicationModel::Store::LicenseInformation LicenseInformation() const;
    Windows::Foundation::Uri LinkUri() const;
    GUID AppId() const;
    Windows::Foundation::IAsyncOperation<hstring> RequestAppPurchaseAsync(bool includeReceipt) const;
    [[deprecated("RequestProductPurchaseAsync(productId, includeReceipt) may be altered or unavailable for releases after Windows 8.1. Instead, use RequestProductPurchaseAsync(productId).")]] Windows::Foundation::IAsyncOperation<hstring> RequestProductPurchaseAsync(hstring_view productId, bool includeReceipt) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> LoadListingInformationAsync() const;
    Windows::Foundation::IAsyncOperation<hstring> GetAppReceiptAsync() const;
    Windows::Foundation::IAsyncOperation<hstring> GetProductReceiptAsync(hstring_view productId) const;
    Windows::Foundation::IAsyncAction ReloadSimulatorAsync(const Windows::Storage::StorageFile & simulatorSettingsFile) const;
};

template <typename D>
struct WINRT_EBO impl_ICurrentAppSimulatorStaticsWithFiltering
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> LoadListingInformationByProductIdsAsync(iterable<hstring> productIds) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> LoadListingInformationByKeywordsAsync(iterable<hstring> keywords) const;
};

template <typename D>
struct WINRT_EBO impl_ICurrentAppSimulatorWithCampaignId
{
    Windows::Foundation::IAsyncOperation<hstring> GetAppPurchaseCampaignIdAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ICurrentAppSimulatorWithConsumables
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Store::FulfillmentResult> ReportConsumableFulfillmentAsync(hstring_view productId, GUID transactionId) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> RequestProductPurchaseAsync(hstring_view productId) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> RequestProductPurchaseAsync(hstring_view productId, hstring_view offerId, const Windows::ApplicationModel::Store::ProductPurchaseDisplayProperties & displayProperties) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>> GetUnfulfilledConsumablesAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ICurrentAppStaticsWithFiltering
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> LoadListingInformationByProductIdsAsync(iterable<hstring> productIds) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> LoadListingInformationByKeywordsAsync(iterable<hstring> keywords) const;
    void ReportProductFulfillment(hstring_view productId) const;
};

template <typename D>
struct WINRT_EBO impl_ICurrentAppWithCampaignId
{
    Windows::Foundation::IAsyncOperation<hstring> GetAppPurchaseCampaignIdAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ICurrentAppWithConsumables
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Store::FulfillmentResult> ReportConsumableFulfillmentAsync(hstring_view productId, GUID transactionId) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> RequestProductPurchaseAsync(hstring_view productId) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> RequestProductPurchaseAsync(hstring_view productId, hstring_view offerId, const Windows::ApplicationModel::Store::ProductPurchaseDisplayProperties & displayProperties) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>> GetUnfulfilledConsumablesAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ILicenseInformation
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::ProductLicense> ProductLicenses() const;
    bool IsActive() const;
    bool IsTrial() const;
    Windows::Foundation::DateTime ExpirationDate() const;
    event_token LicenseChanged(const Windows::ApplicationModel::Store::LicenseChangedEventHandler & handler) const;
    using LicenseChanged_revoker = event_revoker<ILicenseInformation>;
    LicenseChanged_revoker LicenseChanged(auto_revoke_t, const Windows::ApplicationModel::Store::LicenseChangedEventHandler & handler) const;
    void LicenseChanged(event_token cookie) const;
};

template <typename D>
struct WINRT_EBO impl_IListingInformation
{
    hstring CurrentMarket() const;
    hstring Description() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::ProductListing> ProductListings() const;
    hstring FormattedPrice() const;
    hstring Name() const;
    uint32_t AgeRating() const;
};

template <typename D>
struct WINRT_EBO impl_IListingInformation2
{
    hstring FormattedBasePrice() const;
    Windows::Foundation::DateTime SaleEndDate() const;
    bool IsOnSale() const;
    hstring CurrencyCode() const;
};

template <typename D>
struct WINRT_EBO impl_IProductLicense
{
    hstring ProductId() const;
    bool IsActive() const;
    Windows::Foundation::DateTime ExpirationDate() const;
};

template <typename D>
struct WINRT_EBO impl_IProductLicenseWithFulfillment
{
    bool IsConsumable() const;
};

template <typename D>
struct WINRT_EBO impl_IProductListing
{
    hstring ProductId() const;
    hstring FormattedPrice() const;
    hstring Name() const;
};

template <typename D>
struct WINRT_EBO impl_IProductListing2
{
    hstring FormattedBasePrice() const;
    Windows::Foundation::DateTime SaleEndDate() const;
    bool IsOnSale() const;
    hstring CurrencyCode() const;
};

template <typename D>
struct WINRT_EBO impl_IProductListingWithConsumables
{
    Windows::ApplicationModel::Store::ProductType ProductType() const;
};

template <typename D>
struct WINRT_EBO impl_IProductListingWithMetadata
{
    hstring Description() const;
    Windows::Foundation::Collections::IIterable<hstring> Keywords() const;
    Windows::ApplicationModel::Store::ProductType ProductType() const;
    hstring Tag() const;
    Windows::Foundation::Uri ImageUri() const;
};

template <typename D>
struct WINRT_EBO impl_IProductPurchaseDisplayProperties
{
    hstring Name() const;
    void Name(hstring_view value) const;
    hstring Description() const;
    void Description(hstring_view value) const;
    Windows::Foundation::Uri Image() const;
    void Image(const Windows::Foundation::Uri & value) const;
};

template <typename D>
struct WINRT_EBO impl_IProductPurchaseDisplayPropertiesFactory
{
    Windows::ApplicationModel::Store::ProductPurchaseDisplayProperties CreateProductPurchaseDisplayProperties(hstring_view name) const;
};

template <typename D>
struct WINRT_EBO impl_IPurchaseResults
{
    Windows::ApplicationModel::Store::ProductPurchaseStatus Status() const;
    GUID TransactionId() const;
    hstring ReceiptXml() const;
    hstring OfferId() const;
};

template <typename D>
struct WINRT_EBO impl_IUnfulfilledConsumable
{
    hstring ProductId() const;
    GUID TransactionId() const;
    hstring OfferId() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Store::ICurrentApp>
{
    using abi = ABI::Windows::ApplicationModel::Store::ICurrentApp;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_ICurrentApp<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::ICurrentApp2Statics>
{
    using abi = ABI::Windows::ApplicationModel::Store::ICurrentApp2Statics;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_ICurrentApp2Statics<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::ICurrentAppSimulator>
{
    using abi = ABI::Windows::ApplicationModel::Store::ICurrentAppSimulator;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_ICurrentAppSimulator<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::ICurrentAppSimulatorStaticsWithFiltering>
{
    using abi = ABI::Windows::ApplicationModel::Store::ICurrentAppSimulatorStaticsWithFiltering;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_ICurrentAppSimulatorStaticsWithFiltering<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::ICurrentAppSimulatorWithCampaignId>
{
    using abi = ABI::Windows::ApplicationModel::Store::ICurrentAppSimulatorWithCampaignId;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_ICurrentAppSimulatorWithCampaignId<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::ICurrentAppSimulatorWithConsumables>
{
    using abi = ABI::Windows::ApplicationModel::Store::ICurrentAppSimulatorWithConsumables;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_ICurrentAppSimulatorWithConsumables<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::ICurrentAppStaticsWithFiltering>
{
    using abi = ABI::Windows::ApplicationModel::Store::ICurrentAppStaticsWithFiltering;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_ICurrentAppStaticsWithFiltering<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::ICurrentAppWithCampaignId>
{
    using abi = ABI::Windows::ApplicationModel::Store::ICurrentAppWithCampaignId;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_ICurrentAppWithCampaignId<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::ICurrentAppWithConsumables>
{
    using abi = ABI::Windows::ApplicationModel::Store::ICurrentAppWithConsumables;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_ICurrentAppWithConsumables<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::ILicenseInformation>
{
    using abi = ABI::Windows::ApplicationModel::Store::ILicenseInformation;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_ILicenseInformation<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::IListingInformation>
{
    using abi = ABI::Windows::ApplicationModel::Store::IListingInformation;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_IListingInformation<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::IListingInformation2>
{
    using abi = ABI::Windows::ApplicationModel::Store::IListingInformation2;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_IListingInformation2<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::IProductLicense>
{
    using abi = ABI::Windows::ApplicationModel::Store::IProductLicense;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_IProductLicense<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::IProductLicenseWithFulfillment>
{
    using abi = ABI::Windows::ApplicationModel::Store::IProductLicenseWithFulfillment;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_IProductLicenseWithFulfillment<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::IProductListing>
{
    using abi = ABI::Windows::ApplicationModel::Store::IProductListing;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_IProductListing<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::IProductListing2>
{
    using abi = ABI::Windows::ApplicationModel::Store::IProductListing2;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_IProductListing2<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::IProductListingWithConsumables>
{
    using abi = ABI::Windows::ApplicationModel::Store::IProductListingWithConsumables;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_IProductListingWithConsumables<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::IProductListingWithMetadata>
{
    using abi = ABI::Windows::ApplicationModel::Store::IProductListingWithMetadata;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_IProductListingWithMetadata<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::IProductPurchaseDisplayProperties>
{
    using abi = ABI::Windows::ApplicationModel::Store::IProductPurchaseDisplayProperties;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_IProductPurchaseDisplayProperties<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::IProductPurchaseDisplayPropertiesFactory>
{
    using abi = ABI::Windows::ApplicationModel::Store::IProductPurchaseDisplayPropertiesFactory;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_IProductPurchaseDisplayPropertiesFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::IPurchaseResults>
{
    using abi = ABI::Windows::ApplicationModel::Store::IPurchaseResults;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_IPurchaseResults<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::IUnfulfilledConsumable>
{
    using abi = ABI::Windows::ApplicationModel::Store::IUnfulfilledConsumable;
    template <typename D> using consume = Windows::ApplicationModel::Store::impl_IUnfulfilledConsumable<D>;
};

template <> struct traits<Windows::ApplicationModel::Store::LicenseChangedEventHandler>
{
    using abi = ABI::Windows::ApplicationModel::Store::LicenseChangedEventHandler;
};

template <> struct traits<Windows::ApplicationModel::Store::CurrentApp>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Store.CurrentApp"; }
};

template <> struct traits<Windows::ApplicationModel::Store::CurrentAppSimulator>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Store.CurrentAppSimulator"; }
};

template <> struct traits<Windows::ApplicationModel::Store::LicenseInformation>
{
    using abi = ABI::Windows::ApplicationModel::Store::LicenseInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Store.LicenseInformation"; }
};

template <> struct traits<Windows::ApplicationModel::Store::ListingInformation>
{
    using abi = ABI::Windows::ApplicationModel::Store::ListingInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Store.ListingInformation"; }
};

template <> struct traits<Windows::ApplicationModel::Store::ProductLicense>
{
    using abi = ABI::Windows::ApplicationModel::Store::ProductLicense;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Store.ProductLicense"; }
};

template <> struct traits<Windows::ApplicationModel::Store::ProductListing>
{
    using abi = ABI::Windows::ApplicationModel::Store::ProductListing;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Store.ProductListing"; }
};

template <> struct traits<Windows::ApplicationModel::Store::ProductPurchaseDisplayProperties>
{
    using abi = ABI::Windows::ApplicationModel::Store::ProductPurchaseDisplayProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Store.ProductPurchaseDisplayProperties"; }
};

template <> struct traits<Windows::ApplicationModel::Store::PurchaseResults>
{
    using abi = ABI::Windows::ApplicationModel::Store::PurchaseResults;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Store.PurchaseResults"; }
};

template <> struct traits<Windows::ApplicationModel::Store::UnfulfilledConsumable>
{
    using abi = ABI::Windows::ApplicationModel::Store::UnfulfilledConsumable;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Store.UnfulfilledConsumable"; }
};

}

}
