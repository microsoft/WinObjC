// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.Wallet.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.ApplicationModel.Wallet.System.3.h"
#include "Windows.ApplicationModel.Wallet.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore> : produce_base<D, Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore>
{
    HRESULT __stdcall abi_GetItemsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetItemsAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAsync(impl::abi_arg_in<Windows::ApplicationModel::Wallet::IWalletItem> item, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeleteAsync(*reinterpret_cast<const Windows::ApplicationModel::Wallet::WalletItem *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ImportItemAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> stream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ImportItemAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAppStatusForItem(impl::abi_arg_in<Windows::ApplicationModel::Wallet::IWalletItem> item, Windows::ApplicationModel::Wallet::System::WalletItemAppAssociation * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetAppStatusForItem(*reinterpret_cast<const Windows::ApplicationModel::Wallet::WalletItem *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchAppForItemAsync(impl::abi_arg_in<Windows::ApplicationModel::Wallet::IWalletItem> item, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchAppForItemAsync(*reinterpret_cast<const Windows::ApplicationModel::Wallet::WalletItem *>(&item)));
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
struct produce<D, Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore2> : produce_base<D, Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore2>
{
    HRESULT __stdcall add_ItemsChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore, Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().ItemsChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ItemsChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemsChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Wallet::System::IWalletManagerSystemStatics> : produce_base<D, Windows::ApplicationModel::Wallet::System::IWalletManagerSystemStatics>
{
    HRESULT __stdcall abi_RequestStoreAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestStoreAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Wallet::System {

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> impl_IWalletItemSystemStore<D>::GetItemsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Wallet::WalletItem>> operation;
    check_hresult(WINRT_SHIM(IWalletItemSystemStore)->abi_GetItemsAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWalletItemSystemStore<D>::DeleteAsync(const Windows::ApplicationModel::Wallet::WalletItem & item) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IWalletItemSystemStore)->abi_DeleteAsync(get_abi(item), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> impl_IWalletItemSystemStore<D>::ImportItemAsync(const Windows::Storage::Streams::IRandomAccessStreamReference & stream) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::WalletItem> operation;
    check_hresult(WINRT_SHIM(IWalletItemSystemStore)->abi_ImportItemAsync(get_abi(stream), put_abi(operation)));
    return operation;
}

template <typename D> Windows::ApplicationModel::Wallet::System::WalletItemAppAssociation impl_IWalletItemSystemStore<D>::GetAppStatusForItem(const Windows::ApplicationModel::Wallet::WalletItem & item) const
{
    Windows::ApplicationModel::Wallet::System::WalletItemAppAssociation result {};
    check_hresult(WINRT_SHIM(IWalletItemSystemStore)->abi_GetAppStatusForItem(get_abi(item), &result));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IWalletItemSystemStore<D>::LaunchAppForItemAsync(const Windows::ApplicationModel::Wallet::WalletItem & item) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IWalletItemSystemStore)->abi_LaunchAppForItemAsync(get_abi(item), put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IWalletItemSystemStore2<D>::ItemsChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore, Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IWalletItemSystemStore2)->add_ItemsChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IWalletItemSystemStore2> impl_IWalletItemSystemStore2<D>::ItemsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IWalletItemSystemStore2>(this, &ABI::Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore2::remove_ItemsChanged, ItemsChanged(handler));
}

template <typename D> void impl_IWalletItemSystemStore2<D>::ItemsChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IWalletItemSystemStore2)->remove_ItemsChanged(cookie));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore> impl_IWalletManagerSystemStatics<D>::RequestStoreAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore> operation;
    check_hresult(WINRT_SHIM(IWalletManagerSystemStatics)->abi_RequestStoreAsync(put_abi(operation)));
    return operation;
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Wallet::System::WalletItemSystemStore> WalletManagerSystem::RequestStoreAsync()
{
    return get_activation_factory<WalletManagerSystem, IWalletManagerSystemStatics>().RequestStoreAsync();
}

}

}
#pragma warning(pop)
