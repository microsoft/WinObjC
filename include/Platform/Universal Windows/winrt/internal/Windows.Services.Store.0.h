// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Services::Store {

struct StorePackageUpdateStatus;

}

namespace Windows::Services::Store {

struct StorePackageUpdateStatus;

}

namespace ABI::Windows::Services::Store {

struct IStoreAcquireLicenseResult;
struct IStoreAppLicense;
struct IStoreAvailability;
struct IStoreCollectionData;
struct IStoreConsumableResult;
struct IStoreContext;
struct IStoreContextStatics;
struct IStoreImage;
struct IStoreLicense;
struct IStorePackageLicense;
struct IStorePackageUpdate;
struct IStorePackageUpdateResult;
struct IStorePrice;
struct IStoreProduct;
struct IStoreProductPagedQueryResult;
struct IStoreProductQueryResult;
struct IStoreProductResult;
struct IStorePurchaseProperties;
struct IStorePurchasePropertiesFactory;
struct IStorePurchaseResult;
struct IStoreRequestHelperStatics;
struct IStoreSendRequestResult;
struct IStoreSku;
struct IStoreSubscriptionInfo;
struct IStoreVideo;
struct StoreAcquireLicenseResult;
struct StoreAppLicense;
struct StoreAvailability;
struct StoreCollectionData;
struct StoreConsumableResult;
struct StoreContext;
struct StoreImage;
struct StoreLicense;
struct StorePackageLicense;
struct StorePackageUpdate;
struct StorePackageUpdateResult;
struct StorePrice;
struct StoreProduct;
struct StoreProductPagedQueryResult;
struct StoreProductQueryResult;
struct StoreProductResult;
struct StorePurchaseProperties;
struct StorePurchaseResult;
struct StoreSendRequestResult;
struct StoreSku;
struct StoreSubscriptionInfo;
struct StoreVideo;

}

namespace Windows::Services::Store {

struct IStoreAcquireLicenseResult;
struct IStoreAppLicense;
struct IStoreAvailability;
struct IStoreCollectionData;
struct IStoreConsumableResult;
struct IStoreContext;
struct IStoreContextStatics;
struct IStoreImage;
struct IStoreLicense;
struct IStorePackageLicense;
struct IStorePackageUpdate;
struct IStorePackageUpdateResult;
struct IStorePrice;
struct IStoreProduct;
struct IStoreProductPagedQueryResult;
struct IStoreProductQueryResult;
struct IStoreProductResult;
struct IStorePurchaseProperties;
struct IStorePurchasePropertiesFactory;
struct IStorePurchaseResult;
struct IStoreRequestHelperStatics;
struct IStoreSendRequestResult;
struct IStoreSku;
struct IStoreSubscriptionInfo;
struct IStoreVideo;
struct StoreAcquireLicenseResult;
struct StoreAppLicense;
struct StoreAvailability;
struct StoreCollectionData;
struct StoreConsumableResult;
struct StoreContext;
struct StoreImage;
struct StoreLicense;
struct StorePackageLicense;
struct StorePackageUpdate;
struct StorePackageUpdateResult;
struct StorePrice;
struct StoreProduct;
struct StoreProductPagedQueryResult;
struct StoreProductQueryResult;
struct StoreProductResult;
struct StorePurchaseProperties;
struct StorePurchaseResult;
struct StoreRequestHelper;
struct StoreSendRequestResult;
struct StoreSku;
struct StoreSubscriptionInfo;
struct StoreVideo;

}

namespace Windows::Services::Store {

template <typename T> struct impl_IStoreAcquireLicenseResult;
template <typename T> struct impl_IStoreAppLicense;
template <typename T> struct impl_IStoreAvailability;
template <typename T> struct impl_IStoreCollectionData;
template <typename T> struct impl_IStoreConsumableResult;
template <typename T> struct impl_IStoreContext;
template <typename T> struct impl_IStoreContextStatics;
template <typename T> struct impl_IStoreImage;
template <typename T> struct impl_IStoreLicense;
template <typename T> struct impl_IStorePackageLicense;
template <typename T> struct impl_IStorePackageUpdate;
template <typename T> struct impl_IStorePackageUpdateResult;
template <typename T> struct impl_IStorePrice;
template <typename T> struct impl_IStoreProduct;
template <typename T> struct impl_IStoreProductPagedQueryResult;
template <typename T> struct impl_IStoreProductQueryResult;
template <typename T> struct impl_IStoreProductResult;
template <typename T> struct impl_IStorePurchaseProperties;
template <typename T> struct impl_IStorePurchasePropertiesFactory;
template <typename T> struct impl_IStorePurchaseResult;
template <typename T> struct impl_IStoreRequestHelperStatics;
template <typename T> struct impl_IStoreSendRequestResult;
template <typename T> struct impl_IStoreSku;
template <typename T> struct impl_IStoreSubscriptionInfo;
template <typename T> struct impl_IStoreVideo;

}

namespace Windows::Services::Store {

enum class StoreConsumableStatus
{
    Succeeded = 0,
    InsufficentQuantity = 1,
    NetworkError = 2,
    ServerError = 3,
};

enum class StoreDurationUnit
{
    Minute = 0,
    Hour = 1,
    Day = 2,
    Week = 3,
    Month = 4,
    Year = 5,
};

enum class StorePackageUpdateState
{
    Pending = 0,
    Downloading = 1,
    Deploying = 2,
    Completed = 3,
    Canceled = 4,
    OtherError = 5,
    ErrorLowBattery = 6,
    ErrorWiFiRecommended = 7,
    ErrorWiFiRequired = 8,
};

enum class StorePurchaseStatus
{
    Succeeded = 0,
    AlreadyPurchased = 1,
    NotPurchased = 2,
    NetworkError = 3,
    ServerError = 4,
};

}

}
