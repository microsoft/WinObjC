// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Store {

struct ICurrentApp;
struct ICurrentApp2Statics;
struct ICurrentAppSimulator;
struct ICurrentAppSimulatorStaticsWithFiltering;
struct ICurrentAppSimulatorWithCampaignId;
struct ICurrentAppSimulatorWithConsumables;
struct ICurrentAppStaticsWithFiltering;
struct ICurrentAppWithCampaignId;
struct ICurrentAppWithConsumables;
struct ILicenseInformation;
struct IListingInformation;
struct IListingInformation2;
struct IProductLicense;
struct IProductLicenseWithFulfillment;
struct IProductListing;
struct IProductListing2;
struct IProductListingWithConsumables;
struct IProductListingWithMetadata;
struct IProductPurchaseDisplayProperties;
struct IProductPurchaseDisplayPropertiesFactory;
struct IPurchaseResults;
struct IUnfulfilledConsumable;
struct LicenseChangedEventHandler;
struct LicenseInformation;
struct ListingInformation;
struct ProductLicense;
struct ProductListing;
struct ProductPurchaseDisplayProperties;
struct PurchaseResults;
struct UnfulfilledConsumable;

}

namespace Windows::ApplicationModel::Store {

struct LicenseChangedEventHandler;
struct ICurrentApp;
struct ICurrentApp2Statics;
struct ICurrentAppSimulator;
struct ICurrentAppSimulatorStaticsWithFiltering;
struct ICurrentAppSimulatorWithCampaignId;
struct ICurrentAppSimulatorWithConsumables;
struct ICurrentAppStaticsWithFiltering;
struct ICurrentAppWithCampaignId;
struct ICurrentAppWithConsumables;
struct ILicenseInformation;
struct IListingInformation;
struct IListingInformation2;
struct IProductLicense;
struct IProductLicenseWithFulfillment;
struct IProductListing;
struct IProductListing2;
struct IProductListingWithConsumables;
struct IProductListingWithMetadata;
struct IProductPurchaseDisplayProperties;
struct IProductPurchaseDisplayPropertiesFactory;
struct IPurchaseResults;
struct IUnfulfilledConsumable;
struct CurrentApp;
struct CurrentAppSimulator;
struct LicenseInformation;
struct ListingInformation;
struct ProductLicense;
struct ProductListing;
struct ProductPurchaseDisplayProperties;
struct PurchaseResults;
struct UnfulfilledConsumable;

}

namespace Windows::ApplicationModel::Store {

template <typename T> struct impl_ICurrentApp;
template <typename T> struct impl_ICurrentApp2Statics;
template <typename T> struct impl_ICurrentAppSimulator;
template <typename T> struct impl_ICurrentAppSimulatorStaticsWithFiltering;
template <typename T> struct impl_ICurrentAppSimulatorWithCampaignId;
template <typename T> struct impl_ICurrentAppSimulatorWithConsumables;
template <typename T> struct impl_ICurrentAppStaticsWithFiltering;
template <typename T> struct impl_ICurrentAppWithCampaignId;
template <typename T> struct impl_ICurrentAppWithConsumables;
template <typename T> struct impl_ILicenseInformation;
template <typename T> struct impl_IListingInformation;
template <typename T> struct impl_IListingInformation2;
template <typename T> struct impl_IProductLicense;
template <typename T> struct impl_IProductLicenseWithFulfillment;
template <typename T> struct impl_IProductListing;
template <typename T> struct impl_IProductListing2;
template <typename T> struct impl_IProductListingWithConsumables;
template <typename T> struct impl_IProductListingWithMetadata;
template <typename T> struct impl_IProductPurchaseDisplayProperties;
template <typename T> struct impl_IProductPurchaseDisplayPropertiesFactory;
template <typename T> struct impl_IPurchaseResults;
template <typename T> struct impl_IUnfulfilledConsumable;
template <typename T> struct impl_LicenseChangedEventHandler;

}

namespace Windows::ApplicationModel::Store {

enum class FulfillmentResult
{
    Succeeded = 0,
    NothingToFulfill = 1,
    PurchasePending = 2,
    PurchaseReverted = 3,
    ServerError = 4,
};

enum class ProductPurchaseStatus
{
    Succeeded = 0,
    AlreadyPurchased = 1,
    NotFulfilled = 2,
    NotPurchased = 3,
};

enum class ProductType
{
    Unknown = 0,
    Durable = 1,
    Consumable = 2,
};

}

}
