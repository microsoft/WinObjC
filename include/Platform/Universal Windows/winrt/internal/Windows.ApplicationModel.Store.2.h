// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Store.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_3e1fe603_f897_5263_b328_0806426b8a79
#define WINRT_GENERIC_3e1fe603_f897_5263_b328_0806426b8a79
template <> struct __declspec(uuid("3e1fe603-f897-5263-b328-0806426b8a79")) __declspec(novtable) IAsyncOperation<hstring> : impl_IAsyncOperation<hstring> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_161600f7_6d4f_500d_93a8_09ad6b5ac4ab
#define WINRT_GENERIC_161600f7_6d4f_500d_93a8_09ad6b5ac4ab
template <> struct __declspec(uuid("161600f7-6d4f-500d-93a8-09ad6b5ac4ab")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> : impl_IAsyncOperation<Windows::ApplicationModel::Store::ListingInformation> {};
#endif

#ifndef WINRT_GENERIC_5c8531ac_5d8d_5e07_b6ee_7cab96930e8a
#define WINRT_GENERIC_5c8531ac_5d8d_5e07_b6ee_7cab96930e8a
template <> struct __declspec(uuid("5c8531ac-5d8d-5e07-b6ee-7cab96930e8a")) __declspec(novtable) IAsyncOperation<winrt::Windows::ApplicationModel::Store::FulfillmentResult> : impl_IAsyncOperation<winrt::Windows::ApplicationModel::Store::FulfillmentResult> {};
#endif

#ifndef WINRT_GENERIC_241f6b10_6af6_5164_85eb_bae6bdae0be8
#define WINRT_GENERIC_241f6b10_6af6_5164_85eb_bae6bdae0be8
template <> struct __declspec(uuid("241f6b10-6af6-5164-85eb-bae6bdae0be8")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> : impl_IAsyncOperation<Windows::ApplicationModel::Store::PurchaseResults> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_f0ae5962_e039_5105_bcc5_9b552f13b102
#define WINRT_GENERIC_f0ae5962_e039_5105_bcc5_9b552f13b102
template <> struct __declspec(uuid("f0ae5962-e039-5105-bcc5-9b552f13b102")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable> : impl_IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable> {};
#endif

#ifndef WINRT_GENERIC_d6434f65_dd84_534c_b579_cc10d69ec30a
#define WINRT_GENERIC_d6434f65_dd84_534c_b579_cc10d69ec30a
template <> struct __declspec(uuid("d6434f65-dd84-534c-b579-cc10d69ec30a")) __declspec(novtable) IMapView<hstring, Windows::ApplicationModel::Store::ProductLicense> : impl_IMapView<hstring, Windows::ApplicationModel::Store::ProductLicense> {};
#endif

#ifndef WINRT_GENERIC_3206de83_efbe_5791_a487_2ac974206ec6
#define WINRT_GENERIC_3206de83_efbe_5791_a487_2ac974206ec6
template <> struct __declspec(uuid("3206de83-efbe-5791-a487-2ac974206ec6")) __declspec(novtable) IMapView<hstring, Windows::ApplicationModel::Store::ProductListing> : impl_IMapView<hstring, Windows::ApplicationModel::Store::ProductListing> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b79a741f_7fb5_50ae_9e99_911201ec3d41
#define WINRT_GENERIC_b79a741f_7fb5_50ae_9e99_911201ec3d41
template <> struct __declspec(uuid("b79a741f-7fb5-50ae-9e99-911201ec3d41")) __declspec(novtable) AsyncOperationCompletedHandler<hstring> : impl_AsyncOperationCompletedHandler<hstring> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_fdf83922_762e_57dc_b721_c72ee568fd96
#define WINRT_GENERIC_fdf83922_762e_57dc_b721_c72ee568fd96
template <> struct __declspec(uuid("fdf83922-762e-57dc-b721-c72ee568fd96")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Store::ListingInformation> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Store::ListingInformation> {};
#endif

#ifndef WINRT_GENERIC_8775acc9_b9ae_5cce_895c_971bf9270892
#define WINRT_GENERIC_8775acc9_b9ae_5cce_895c_971bf9270892
template <> struct __declspec(uuid("8775acc9-b9ae-5cce-895c-971bf9270892")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::Store::FulfillmentResult> : impl_AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::Store::FulfillmentResult> {};
#endif

#ifndef WINRT_GENERIC_24b6922a_fdb1_5003_ae89_c8bf16ca0143
#define WINRT_GENERIC_24b6922a_fdb1_5003_ae89_c8bf16ca0143
template <> struct __declspec(uuid("24b6922a-fdb1-5003-ae89-c8bf16ca0143")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Store::PurchaseResults> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Store::PurchaseResults> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_cb77cf2e_ef57_5256_9753_214baada2301
#define WINRT_GENERIC_cb77cf2e_ef57_5256_9753_214baada2301
template <> struct __declspec(uuid("cb77cf2e-ef57-5256-9753-214baada2301")) __declspec(novtable) IIterator<Windows::ApplicationModel::Store::UnfulfilledConsumable> : impl_IIterator<Windows::ApplicationModel::Store::UnfulfilledConsumable> {};
#endif

#ifndef WINRT_GENERIC_2f4d1483_dd86_5fdb_8c44_06c98844bf3d
#define WINRT_GENERIC_2f4d1483_dd86_5fdb_8c44_06c98844bf3d
template <> struct __declspec(uuid("2f4d1483-dd86-5fdb-8c44-06c98844bf3d")) __declspec(novtable) IIterable<Windows::ApplicationModel::Store::UnfulfilledConsumable> : impl_IIterable<Windows::ApplicationModel::Store::UnfulfilledConsumable> {};
#endif

#ifndef WINRT_GENERIC_ff71c38c_3e6e_5e60_994b_9201436deed1
#define WINRT_GENERIC_ff71c38c_3e6e_5e60_994b_9201436deed1
template <> struct __declspec(uuid("ff71c38c-3e6e-5e60-994b-9201436deed1")) __declspec(novtable) IKeyValuePair<hstring, Windows::ApplicationModel::Store::ProductLicense> : impl_IKeyValuePair<hstring, Windows::ApplicationModel::Store::ProductLicense> {};
#endif

#ifndef WINRT_GENERIC_61a02c5d_4007_573e_8a01_0259714927df
#define WINRT_GENERIC_61a02c5d_4007_573e_8a01_0259714927df
template <> struct __declspec(uuid("61a02c5d-4007-573e-8a01-0259714927df")) __declspec(novtable) IKeyValuePair<hstring, Windows::ApplicationModel::Store::ProductListing> : impl_IKeyValuePair<hstring, Windows::ApplicationModel::Store::ProductListing> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_f1cd679a_3a8f_5e1b_82f1_f2fd0916ca3f
#define WINRT_GENERIC_f1cd679a_3a8f_5e1b_82f1_f2fd0916ca3f
template <> struct __declspec(uuid("f1cd679a-3a8f-5e1b-82f1-f2fd0916ca3f")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>> {};
#endif

#ifndef WINRT_GENERIC_0451fe11_6b50_54c1_b765_d946b1d5c88b
#define WINRT_GENERIC_0451fe11_6b50_54c1_b765_d946b1d5c88b
template <> struct __declspec(uuid("0451fe11-6b50-54c1-b765-d946b1d5c88b")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::UnfulfilledConsumable>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_3f3c06e6_593f_557a_8e3c_45513ac01f7c
#define WINRT_GENERIC_3f3c06e6_593f_557a_8e3c_45513ac01f7c
template <> struct __declspec(uuid("3f3c06e6-593f-557a-8e3c-45513ac01f7c")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Store::ProductLicense>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Store::ProductLicense>> {};
#endif

#ifndef WINRT_GENERIC_ffe05002_6e65_5001_a752_9b27ed3e2839
#define WINRT_GENERIC_ffe05002_6e65_5001_a752_9b27ed3e2839
template <> struct __declspec(uuid("ffe05002-6e65-5001-a752-9b27ed3e2839")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Store::ProductLicense>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Store::ProductLicense>> {};
#endif

#ifndef WINRT_GENERIC_142a6937_1ae1_5aad_8ada_9a8ee034e4eb
#define WINRT_GENERIC_142a6937_1ae1_5aad_8ada_9a8ee034e4eb
template <> struct __declspec(uuid("142a6937-1ae1-5aad-8ada-9a8ee034e4eb")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Store::ProductListing>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Store::ProductListing>> {};
#endif

#ifndef WINRT_GENERIC_3a7d9a2f_2a82_59f8_bd7c_d691ca169863
#define WINRT_GENERIC_3a7d9a2f_2a82_59f8_bd7c_d691ca169863
template <> struct __declspec(uuid("3a7d9a2f-2a82-59f8-bd7c-d691ca169863")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Store::ProductListing>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Store::ProductListing>> {};
#endif


}

namespace Windows::ApplicationModel::Store {

struct LicenseChangedEventHandler : Windows::Foundation::IUnknown
{
    LicenseChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> LicenseChangedEventHandler(L lambda);
    template <typename F> LicenseChangedEventHandler (F * function);
    template <typename O, typename M> LicenseChangedEventHandler(O * object, M method);
    void operator()() const;
};

struct ICurrentApp :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrentApp>
{
    ICurrentApp(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrentApp2Statics :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrentApp2Statics>
{
    ICurrentApp2Statics(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrentAppSimulator :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrentAppSimulator>
{
    ICurrentAppSimulator(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrentAppSimulatorStaticsWithFiltering :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrentAppSimulatorStaticsWithFiltering>
{
    ICurrentAppSimulatorStaticsWithFiltering(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrentAppSimulatorWithCampaignId :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrentAppSimulatorWithCampaignId>
{
    ICurrentAppSimulatorWithCampaignId(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrentAppSimulatorWithConsumables :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrentAppSimulatorWithConsumables>
{
    ICurrentAppSimulatorWithConsumables(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrentAppStaticsWithFiltering :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrentAppStaticsWithFiltering>
{
    ICurrentAppStaticsWithFiltering(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrentAppWithCampaignId :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrentAppWithCampaignId>
{
    ICurrentAppWithCampaignId(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrentAppWithConsumables :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrentAppWithConsumables>
{
    ICurrentAppWithConsumables(std::nullptr_t = nullptr) noexcept {}
};

struct ILicenseInformation :
    Windows::Foundation::IInspectable,
    impl::consume<ILicenseInformation>
{
    ILicenseInformation(std::nullptr_t = nullptr) noexcept {}
};

struct IListingInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IListingInformation>
{
    IListingInformation(std::nullptr_t = nullptr) noexcept {}
};

struct IListingInformation2 :
    Windows::Foundation::IInspectable,
    impl::consume<IListingInformation2>
{
    IListingInformation2(std::nullptr_t = nullptr) noexcept {}
};

struct IProductLicense :
    Windows::Foundation::IInspectable,
    impl::consume<IProductLicense>
{
    IProductLicense(std::nullptr_t = nullptr) noexcept {}
};

struct IProductLicenseWithFulfillment :
    Windows::Foundation::IInspectable,
    impl::consume<IProductLicenseWithFulfillment>,
    impl::require<IProductLicenseWithFulfillment, Windows::ApplicationModel::Store::IProductLicense>
{
    IProductLicenseWithFulfillment(std::nullptr_t = nullptr) noexcept {}
};

struct IProductListing :
    Windows::Foundation::IInspectable,
    impl::consume<IProductListing>
{
    IProductListing(std::nullptr_t = nullptr) noexcept {}
};

struct IProductListing2 :
    Windows::Foundation::IInspectable,
    impl::consume<IProductListing2>
{
    IProductListing2(std::nullptr_t = nullptr) noexcept {}
};

struct IProductListingWithConsumables :
    Windows::Foundation::IInspectable,
    impl::consume<IProductListingWithConsumables>
{
    IProductListingWithConsumables(std::nullptr_t = nullptr) noexcept {}
};

struct IProductListingWithMetadata :
    Windows::Foundation::IInspectable,
    impl::consume<IProductListingWithMetadata>,
    impl::require<IProductListingWithMetadata, Windows::ApplicationModel::Store::IProductListing>
{
    IProductListingWithMetadata(std::nullptr_t = nullptr) noexcept {}
};

struct IProductPurchaseDisplayProperties :
    Windows::Foundation::IInspectable,
    impl::consume<IProductPurchaseDisplayProperties>
{
    IProductPurchaseDisplayProperties(std::nullptr_t = nullptr) noexcept {}
};

struct IProductPurchaseDisplayPropertiesFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IProductPurchaseDisplayPropertiesFactory>
{
    IProductPurchaseDisplayPropertiesFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IPurchaseResults :
    Windows::Foundation::IInspectable,
    impl::consume<IPurchaseResults>
{
    IPurchaseResults(std::nullptr_t = nullptr) noexcept {}
};

struct IUnfulfilledConsumable :
    Windows::Foundation::IInspectable,
    impl::consume<IUnfulfilledConsumable>
{
    IUnfulfilledConsumable(std::nullptr_t = nullptr) noexcept {}
};

}

}
