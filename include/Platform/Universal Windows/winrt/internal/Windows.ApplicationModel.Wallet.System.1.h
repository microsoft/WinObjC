// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Wallet.System.0.h"
#include "Windows.ApplicationModel.Wallet.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.ApplicationModel.Wallet.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Wallet::System {

struct __declspec(uuid("522e2bff-96a2-4a17-8d19-fe1d9f837561")) __declspec(novtable) IWalletItemSystemStore : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetItemsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> ** operation) = 0;
    virtual HRESULT __stdcall abi_DeleteAsync(Windows::ApplicationModel::Wallet::IWalletItem * item, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_ImportItemAsync(Windows::Storage::Streams::IRandomAccessStreamReference * stream, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetAppStatusForItem(Windows::ApplicationModel::Wallet::IWalletItem * item, winrt::Windows::ApplicationModel::Wallet::System::WalletItemAppAssociation * result) = 0;
    virtual HRESULT __stdcall abi_LaunchAppForItemAsync(Windows::ApplicationModel::Wallet::IWalletItem * item, Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
};

struct __declspec(uuid("f98d3a4e-be00-4fdd-9734-6c113c1ac1cb")) __declspec(novtable) IWalletItemSystemStore2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_ItemsChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore, Windows::Foundation::IInspectable> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_ItemsChanged(event_token cookie) = 0;
};

struct __declspec(uuid("bee8eb89-2634-4b9a-8b23-ee8903c91fe0")) __declspec(novtable) IWalletManagerSystemStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestStoreAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore> ** operation) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore> { using default_interface = Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore; };

}

namespace Windows::ApplicationModel::Wallet::System {

template <typename D>
struct WINRT_EBO impl_IWalletItemSystemStore
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> GetItemsAsync() const;
    Windows::Foundation::IAsyncAction DeleteAsync(const Windows::ApplicationModel::Wallet::WalletItem & item) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> ImportItemAsync(const Windows::Storage::Streams::IRandomAccessStreamReference & stream) const;
    Windows::ApplicationModel::Wallet::System::WalletItemAppAssociation GetAppStatusForItem(const Windows::ApplicationModel::Wallet::WalletItem & item) const;
    Windows::Foundation::IAsyncOperation<bool> LaunchAppForItemAsync(const Windows::ApplicationModel::Wallet::WalletItem & item) const;
};

template <typename D>
struct WINRT_EBO impl_IWalletItemSystemStore2
{
    event_token ItemsChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore, Windows::Foundation::IInspectable> & handler) const;
    using ItemsChanged_revoker = event_revoker<IWalletItemSystemStore2>;
    ItemsChanged_revoker ItemsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore, Windows::Foundation::IInspectable> & handler) const;
    void ItemsChanged(event_token cookie) const;
};

template <typename D>
struct WINRT_EBO impl_IWalletManagerSystemStatics
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore> RequestStoreAsync() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::System::impl_IWalletItemSystemStore<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore2>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore2;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::System::impl_IWalletItemSystemStore2<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::System::IWalletManagerSystemStatics>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::System::IWalletManagerSystemStatics;
    template <typename D> using consume = Windows::ApplicationModel::Wallet::System::impl_IWalletManagerSystemStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore>
{
    using abi = ABI::Windows::ApplicationModel::Wallet::System::WalletItemSystemStore;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Wallet.System.WalletItemSystemStore"; }
};

template <> struct traits<Windows::ApplicationModel::Wallet::System::WalletManagerSystem>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Wallet.System.WalletManagerSystem"; }
};

}

}
