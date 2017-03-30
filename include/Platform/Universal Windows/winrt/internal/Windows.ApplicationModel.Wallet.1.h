// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Wallet.0.h"
#include "Windows.Devices.Geolocation.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.UI.0.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Wallet {

struct __declspec(uuid("4f857b29-de80-4ea4-a1cd-81cd084dac27")) __declspec(novtable) IWalletBarcode : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Symbology(winrt::Windows::ApplicationModel::Wallet::WalletBarcodeSymbology * value) = 0;
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetImageAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference> ** operation) = 0;
};

struct __declspec(uuid("30117161-ed9c-469e-bbfd-306c95ea7108")) __declspec(novtable) IWalletBarcodeFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWalletBarcode(winrt::Windows::ApplicationModel::Wallet::WalletBarcodeSymbology symbology, hstring value, Windows::ApplicationModel::Wallet::IWalletBarcode ** barcode) = 0;
    virtual HRESULT __stdcall abi_CreateCustomWalletBarcode(Windows::Storage::Streams::IRandomAccessStreamReference * streamToBarcodeImage, Windows::ApplicationModel::Wallet::IWalletBarcode ** barcode) = 0;
};

struct __declspec(uuid("20b54be8-118d-4ec4-996c-b963e7bd3e74")) __declspec(novtable) IWalletItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_IsAcknowledged(bool * value) = 0;
    virtual HRESULT __stdcall put_IsAcknowledged(bool value) = 0;
    virtual HRESULT __stdcall get_IssuerDisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_IssuerDisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_LastUpdated(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_LastUpdated(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_Kind(winrt::Windows::ApplicationModel::Wallet::WalletItemKind * value) = 0;
    virtual HRESULT __stdcall get_Barcode(Windows::ApplicationModel::Wallet::IWalletBarcode ** value) = 0;
    virtual HRESULT __stdcall put_Barcode(Windows::ApplicationModel::Wallet::IWalletBarcode * value) = 0;
    virtual HRESULT __stdcall get_ExpirationDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_ExpirationDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_Logo159x159(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_Logo159x159(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_Logo336x336(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_Logo336x336(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_Logo99x99(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_Logo99x99(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_DisplayMessage(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayMessage(hstring value) = 0;
    virtual HRESULT __stdcall get_IsDisplayMessageLaunchable(bool * value) = 0;
    virtual HRESULT __stdcall put_IsDisplayMessageLaunchable(bool value) = 0;
    virtual HRESULT __stdcall get_LogoText(hstring * value) = 0;
    virtual HRESULT __stdcall put_LogoText(hstring value) = 0;
    virtual HRESULT __stdcall get_HeaderColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_HeaderColor(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall get_BodyColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_BodyColor(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall get_HeaderFontColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_HeaderFontColor(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall get_BodyFontColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_BodyFontColor(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall get_HeaderBackgroundImage(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_HeaderBackgroundImage(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_BodyBackgroundImage(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_BodyBackgroundImage(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_LogoImage(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_LogoImage(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_PromotionalImage(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_PromotionalImage(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_RelevantDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_RelevantDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_RelevantDateDisplayMessage(hstring * value) = 0;
    virtual HRESULT __stdcall put_RelevantDateDisplayMessage(hstring value) = 0;
    virtual HRESULT __stdcall get_TransactionHistory(Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletTransaction> ** value) = 0;
    virtual HRESULT __stdcall get_RelevantLocations(Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletRelevantLocation> ** value) = 0;
    virtual HRESULT __stdcall get_IsMoreTransactionHistoryLaunchable(bool * value) = 0;
    virtual HRESULT __stdcall put_IsMoreTransactionHistoryLaunchable(bool value) = 0;
    virtual HRESULT __stdcall get_DisplayProperties(Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletItemCustomProperty> ** value) = 0;
    virtual HRESULT __stdcall get_Verbs(Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletVerb> ** value) = 0;
};

struct __declspec(uuid("b94b40f3-fa00-40fd-98dc-9de46697f1e7")) __declspec(novtable) IWalletItemCustomProperty : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall put_Name(hstring value) = 0;
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
    virtual HRESULT __stdcall put_Value(hstring value) = 0;
    virtual HRESULT __stdcall get_AutoDetectLinks(bool * value) = 0;
    virtual HRESULT __stdcall put_AutoDetectLinks(bool value) = 0;
    virtual HRESULT __stdcall get_DetailViewPosition(winrt::Windows::ApplicationModel::Wallet::WalletDetailViewPosition * value) = 0;
    virtual HRESULT __stdcall put_DetailViewPosition(winrt::Windows::ApplicationModel::Wallet::WalletDetailViewPosition value) = 0;
    virtual HRESULT __stdcall get_SummaryViewPosition(winrt::Windows::ApplicationModel::Wallet::WalletSummaryViewPosition * value) = 0;
    virtual HRESULT __stdcall put_SummaryViewPosition(winrt::Windows::ApplicationModel::Wallet::WalletSummaryViewPosition value) = 0;
};

struct __declspec(uuid("d0046a44-61a1-41aa-b259-a5610ab5d575")) __declspec(novtable) IWalletItemCustomPropertyFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWalletItemCustomProperty(hstring name, hstring value, Windows::ApplicationModel::Wallet::IWalletItemCustomProperty ** walletItemCustomProperty) = 0;
};

struct __declspec(uuid("53e27470-4f0b-4a3e-99e5-0bbb1eab38d4")) __declspec(novtable) IWalletItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWalletItem(winrt::Windows::ApplicationModel::Wallet::WalletItemKind kind, hstring displayName, Windows::ApplicationModel::Wallet::IWalletItem ** walletItem) = 0;
};

struct __declspec(uuid("7160484b-6d49-48f8-91a9-40a1d0f13ef4")) __declspec(novtable) IWalletItemStore : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddAsync(hstring id, Windows::ApplicationModel::Wallet::IWalletItem * item, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_ClearAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_GetWalletItemAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetItemsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetItemsWithKindAsync(winrt::Windows::ApplicationModel::Wallet::WalletItemKind kind, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> ** operation) = 0;
    virtual HRESULT __stdcall abi_ImportItemAsync(Windows::Storage::Streams::IRandomAccessStreamReference * stream, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> ** operation) = 0;
    virtual HRESULT __stdcall abi_DeleteAsync(hstring id, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_ShowAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_ShowItemAsync(hstring id, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_UpdateAsync(Windows::ApplicationModel::Wallet::IWalletItem * item, Windows::Foundation::IAsyncAction ** operation) = 0;
};

struct __declspec(uuid("65e682f0-7009-4a15-bd54-4fff379bffe2")) __declspec(novtable) IWalletItemStore2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_ItemsChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::WalletItemStore, Windows::Foundation::IInspectable> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_ItemsChanged(event_token cookie) = 0;
};

struct __declspec(uuid("5111d6b8-c9a4-4c64-b4dd-e1e548001c0d")) __declspec(novtable) IWalletManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestStoreAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItemStore> ** operation) = 0;
};

struct __declspec(uuid("9fd8782a-e3f9-4de1-bab3-bb192e46b3f3")) __declspec(novtable) IWalletRelevantLocation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Devices::Geolocation::BasicGeoposition * value) = 0;
    virtual HRESULT __stdcall put_Position(Windows::Devices::Geolocation::BasicGeoposition value) = 0;
    virtual HRESULT __stdcall get_DisplayMessage(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayMessage(hstring value) = 0;
};

struct __declspec(uuid("40e1e940-2606-4519-81cb-bff1c60d1f79")) __declspec(novtable) IWalletTransaction : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall put_Description(hstring value) = 0;
    virtual HRESULT __stdcall get_DisplayAmount(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayAmount(hstring value) = 0;
    virtual HRESULT __stdcall get_IgnoreTimeOfDay(bool * value) = 0;
    virtual HRESULT __stdcall put_IgnoreTimeOfDay(bool value) = 0;
    virtual HRESULT __stdcall get_DisplayLocation(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayLocation(hstring value) = 0;
    virtual HRESULT __stdcall get_TransactionDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_TransactionDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_IsLaunchable(bool * value) = 0;
    virtual HRESULT __stdcall put_IsLaunchable(bool value) = 0;
};

struct __declspec(uuid("17b826d6-e3c1-4c74-8a94-217aadbc4884")) __declspec(novtable) IWalletVerb : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall put_Name(hstring value) = 0;
};

struct __declspec(uuid("76012771-be58-4d5e-83ed-58b1669c7ad9")) __declspec(novtable) IWalletVerbFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWalletVerb(hstring name, Windows::ApplicationModel::Wallet::IWalletVerb ** WalletVerb) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Wallet::WalletBarcode> { using default_interface = Windows::ApplicationModel::Wallet::IWalletBarcode; };
template <> struct traits<Windows::ApplicationModel::Wallet::WalletItem> { using default_interface = Windows::ApplicationModel::Wallet::IWalletItem; };
template <> struct traits<Windows::ApplicationModel::Wallet::WalletItemCustomProperty> { using default_interface = Windows::ApplicationModel::Wallet::IWalletItemCustomProperty; };
template <> struct traits<Windows::ApplicationModel::Wallet::WalletItemStore> { using default_interface = Windows::ApplicationModel::Wallet::IWalletItemStore; };
template <> struct traits<Windows::ApplicationModel::Wallet::WalletRelevantLocation> { using default_interface = Windows::ApplicationModel::Wallet::IWalletRelevantLocation; };
template <> struct traits<Windows::ApplicationModel::Wallet::WalletTransaction> { using default_interface = Windows::ApplicationModel::Wallet::IWalletTransaction; };
template <> struct traits<Windows::ApplicationModel::Wallet::WalletVerb> { using default_interface = Windows::ApplicationModel::Wallet::IWalletVerb; };

}

namespace Windows::ApplicationModel::Wallet {

template <typename D>
struct WINRT_EBO impl_IWalletBarcode
{
    Windows::ApplicationModel::Wallet::WalletBarcodeSymbology Symbology() const;
    hstring Value() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamReference> GetImageAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IWalletBarcodeFactory
{
    Windows::ApplicationModel::Wallet::WalletBarcode CreateWalletBarcode(Windows::ApplicationModel::Wallet::WalletBarcodeSymbology symbology, hstring_view value) const;
    Windows::ApplicationModel::Wallet::WalletBarcode CreateCustomWalletBarcode(const Windows::Storage::Streams::IRandomAccessStreamReference & streamToBarcodeImage) const;
};

template <typename D>
struct WINRT_EBO impl_IWalletItem
{
    hstring DisplayName() const;
    void DisplayName(hstring_view value) const;
    hstring Id() const;
    bool IsAcknowledged() const;
    void IsAcknowledged(bool value) const;
    hstring IssuerDisplayName() const;
    void IssuerDisplayName(hstring_view value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> LastUpdated() const;
    void LastUpdated(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::ApplicationModel::Wallet::WalletItemKind Kind() const;
    Windows::ApplicationModel::Wallet::WalletBarcode Barcode() const;
    void Barcode(const Windows::ApplicationModel::Wallet::WalletBarcode & value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> ExpirationDate() const;
    void ExpirationDate(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference Logo159x159() const;
    void Logo159x159(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference Logo336x336() const;
    void Logo336x336(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference Logo99x99() const;
    void Logo99x99(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    hstring DisplayMessage() const;
    void DisplayMessage(hstring_view value) const;
    bool IsDisplayMessageLaunchable() const;
    void IsDisplayMessageLaunchable(bool value) const;
    hstring LogoText() const;
    void LogoText(hstring_view value) const;
    Windows::UI::Color HeaderColor() const;
    void HeaderColor(const Windows::UI::Color & value) const;
    Windows::UI::Color BodyColor() const;
    void BodyColor(const Windows::UI::Color & value) const;
    Windows::UI::Color HeaderFontColor() const;
    void HeaderFontColor(const Windows::UI::Color & value) const;
    Windows::UI::Color BodyFontColor() const;
    void BodyFontColor(const Windows::UI::Color & value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference HeaderBackgroundImage() const;
    void HeaderBackgroundImage(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference BodyBackgroundImage() const;
    void BodyBackgroundImage(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference LogoImage() const;
    void LogoImage(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference PromotionalImage() const;
    void PromotionalImage(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> RelevantDate() const;
    void RelevantDate(const optional<Windows::Foundation::DateTime> & value) const;
    hstring RelevantDateDisplayMessage() const;
    void RelevantDateDisplayMessage(hstring_view value) const;
    Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletTransaction> TransactionHistory() const;
    Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletRelevantLocation> RelevantLocations() const;
    bool IsMoreTransactionHistoryLaunchable() const;
    void IsMoreTransactionHistoryLaunchable(bool value) const;
    Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletItemCustomProperty> DisplayProperties() const;
    Windows::Foundation::Collections::IMap<hstring, Windows::ApplicationModel::Wallet::WalletVerb> Verbs() const;
};

template <typename D>
struct WINRT_EBO impl_IWalletItemCustomProperty
{
    hstring Name() const;
    void Name(hstring_view value) const;
    hstring Value() const;
    void Value(hstring_view value) const;
    bool AutoDetectLinks() const;
    void AutoDetectLinks(bool value) const;
    Windows::ApplicationModel::Wallet::WalletDetailViewPosition DetailViewPosition() const;
    void DetailViewPosition(Windows::ApplicationModel::Wallet::WalletDetailViewPosition value) const;
    Windows::ApplicationModel::Wallet::WalletSummaryViewPosition SummaryViewPosition() const;
    void SummaryViewPosition(Windows::ApplicationModel::Wallet::WalletSummaryViewPosition value) const;
};

template <typename D>
struct WINRT_EBO impl_IWalletItemCustomPropertyFactory
{
    Windows::ApplicationModel::Wallet::WalletItemCustomProperty CreateWalletItemCustomProperty(hstring_view name, hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IWalletItemFactory
{
    Windows::ApplicationModel::Wallet::WalletItem CreateWalletItem(Windows::ApplicationModel::Wallet::WalletItemKind kind, hstring_view displayName) const;
};

template <typename D>
struct WINRT_EBO impl_IWalletItemStore
{
    Windows::Foundation::IAsyncAction AddAsync(hstring_view id, const Windows::ApplicationModel::Wallet::WalletItem & item) const;
    Windows::Foundation::IAsyncAction ClearAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> GetWalletItemAsync(hstring_view id) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> GetItemsAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> GetItemsAsync(Windows::ApplicationModel::Wallet::WalletItemKind kind) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> ImportItemAsync(const Windows::Storage::Streams::IRandomAccessStreamReference & stream) const;
    Windows::Foundation::IAsyncAction DeleteAsync(hstring_view id) const;
    Windows::Foundation::IAsyncAction ShowAsync() const;
    Windows::Foundation::IAsyncAction ShowAsync(hstring_view id) const;
    Windows::Foundation::IAsyncAction UpdateAsync(const Windows::ApplicationModel::Wallet::WalletItem & item) const;
};

template <typename D>
struct WINRT_EBO impl_IWalletItemStore2
{
    event_token ItemsChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::WalletItemStore, Windows::Foundation::IInspectable> & handler) const;
    using ItemsChanged_revoker = event_revoker<IWalletItemStore2>;
    ItemsChanged_revoker ItemsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::WalletItemStore, Windows::Foundation::IInspectable> & handler) const;
    void ItemsChanged(event_token cookie) const;
};

template <typename D>
struct WINRT_EBO impl_IWalletManagerStatics
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItemStore> RequestStoreAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IWalletRelevantLocation
{
    Windows::Devices::Geolocation::BasicGeoposition Position() const;
    void Position(const Windows::Devices::Geolocation::BasicGeoposition & value) const;
    hstring DisplayMessage() const;
    void DisplayMessage(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IWalletTransaction
{
    hstring Description() const;
    void Description(hstring_view value) const;
    hstring DisplayAmount() const;
    void DisplayAmount(hstring_view value) const;
    bool IgnoreTimeOfDay() const;
    void IgnoreTimeOfDay(bool value) const;
    hstring DisplayLocation() const;
    void DisplayLocation(hstring_view value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> TransactionDate() const;
    void TransactionDate(const optional<Windows::Foundation::DateTime> & value) const;
    bool IsLaunchable() const;
    void IsLaunchable(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IWalletVerb
{
    hstring Name() const;
    void Name(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IWalletVerbFactory
{
    Windows::ApplicationModel::Wallet::WalletVerb CreateWalletVerb(hstring_view name) const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Wallet::IWalletBarcode>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::IWalletBarcode;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::impl_IWalletBarcode<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::IWalletBarcodeFactory>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::IWalletBarcodeFactory;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::impl_IWalletBarcodeFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::IWalletItem>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::IWalletItem;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::impl_IWalletItem<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::IWalletItemCustomProperty>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomProperty;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::impl_IWalletItemCustomProperty<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::IWalletItemCustomPropertyFactory>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomPropertyFactory;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::impl_IWalletItemCustomPropertyFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::IWalletItemFactory>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::IWalletItemFactory;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::impl_IWalletItemFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::IWalletItemStore>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::IWalletItemStore;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::impl_IWalletItemStore<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::IWalletItemStore2>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::IWalletItemStore2;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::impl_IWalletItemStore2<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::IWalletManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::IWalletManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::impl_IWalletManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::IWalletRelevantLocation>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::IWalletRelevantLocation;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::impl_IWalletRelevantLocation<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::IWalletTransaction>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::IWalletTransaction;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::impl_IWalletTransaction<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::IWalletVerb>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::IWalletVerb;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::impl_IWalletVerb<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::IWalletVerbFactory>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::IWalletVerbFactory;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::impl_IWalletVerbFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::WalletBarcode>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::WalletBarcode;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Wallet.WalletBarcode"; }
};

template <> struct traits<Windows::ApplicationModel::Wallet::WalletItem>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::WalletItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Wallet.WalletItem"; }
};

template <> struct traits<Windows::ApplicationModel::Wallet::WalletItemCustomProperty>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::WalletItemCustomProperty;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Wallet.WalletItemCustomProperty"; }
};

template <> struct traits<Windows::ApplicationModel::Wallet::WalletItemStore>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::WalletItemStore;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Wallet.WalletItemStore"; }
};

template <> struct traits<Windows::ApplicationModel::Wallet::WalletManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Wallet.WalletManager"; }
};

template <> struct traits<Windows::ApplicationModel::Wallet::WalletRelevantLocation>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::WalletRelevantLocation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Wallet.WalletRelevantLocation"; }
};

template <> struct traits<Windows::ApplicationModel::Wallet::WalletTransaction>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::WalletTransaction;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Wallet.WalletTransaction"; }
};

template <> struct traits<Windows::ApplicationModel::Wallet::WalletVerb>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::WalletVerb;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Wallet.WalletVerb"; }
};

}

}
