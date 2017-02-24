// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.AccessCache.3.h"
#include "Windows.Storage.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Storage::AccessCache::IItemRemovedEventArgs> : produce_base<D, Windows::Storage::AccessCache::IItemRemovedEventArgs>
{
    HRESULT __stdcall get_RemovedEntry(impl::abi_arg_out<Windows::Storage::AccessCache::AccessListEntry> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemovedEntry());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics> : produce_base<D, Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics>
{
    HRESULT __stdcall get_FutureAccessList(impl::abi_arg_out<Windows::Storage::AccessCache::IStorageItemAccessList> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FutureAccessList());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MostRecentlyUsedList(impl::abi_arg_out<Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MostRecentlyUsedList());
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
struct produce<D, Windows::Storage::AccessCache::IStorageItemAccessList> : produce_base<D, Windows::Storage::AccessCache::IStorageItemAccessList>
{
    HRESULT __stdcall abi_AddOverloadDefaultMetadata(impl::abi_arg_in<Windows::Storage::IStorageItem> file, impl::abi_arg_out<hstring> token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Add(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *token = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Add(impl::abi_arg_in<Windows::Storage::IStorageItem> file, impl::abi_arg_in<hstring> metadata, impl::abi_arg_out<hstring> token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Add(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&file), *reinterpret_cast<const hstring *>(&metadata)));
            return S_OK;
        }
        catch (...)
        {
            *token = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddOrReplaceOverloadDefaultMetadata(impl::abi_arg_in<hstring> token, impl::abi_arg_in<Windows::Storage::IStorageItem> file) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddOrReplace(*reinterpret_cast<const hstring *>(&token), *reinterpret_cast<const Windows::Storage::IStorageItem *>(&file));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddOrReplace(impl::abi_arg_in<hstring> token, impl::abi_arg_in<Windows::Storage::IStorageItem> file, impl::abi_arg_in<hstring> metadata) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddOrReplace(*reinterpret_cast<const hstring *>(&token), *reinterpret_cast<const Windows::Storage::IStorageItem *>(&file), *reinterpret_cast<const hstring *>(&metadata));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemAsync(impl::abi_arg_in<hstring> token, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetItemAsync(*reinterpret_cast<const hstring *>(&token)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFileAsync(impl::abi_arg_in<hstring> token, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFileAsync(*reinterpret_cast<const hstring *>(&token)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFolderAsync(impl::abi_arg_in<hstring> token, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFolderAsync(*reinterpret_cast<const hstring *>(&token)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemWithOptionsAsync(impl::abi_arg_in<hstring> token, Windows::Storage::AccessCache::AccessCacheOptions options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetItemAsync(*reinterpret_cast<const hstring *>(&token), options));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFileWithOptionsAsync(impl::abi_arg_in<hstring> token, Windows::Storage::AccessCache::AccessCacheOptions options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFileAsync(*reinterpret_cast<const hstring *>(&token), options));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFolderWithOptionsAsync(impl::abi_arg_in<hstring> token, Windows::Storage::AccessCache::AccessCacheOptions options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetFolderAsync(*reinterpret_cast<const hstring *>(&token), options));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Remove(impl::abi_arg_in<hstring> token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<const hstring *>(&token));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ContainsItem(impl::abi_arg_in<hstring> token, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContainsItem(*reinterpret_cast<const hstring *>(&token)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CheckAccess(impl::abi_arg_in<Windows::Storage::IStorageItem> file, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CheckAccess(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Entries(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Storage::AccessCache::AccessListEntry>> entries) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *entries = detach_abi(this->shim().Entries());
            return S_OK;
        }
        catch (...)
        {
            *entries = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaximumItemsAllowed(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaximumItemsAllowed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList> : produce_base<D, Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList>
{
    HRESULT __stdcall add_ItemRemoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::ItemRemovedEventArgs>> handler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().ItemRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::ItemRemovedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ItemRemoved(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemRemoved(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList2> : produce_base<D, Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList2>
{
    HRESULT __stdcall abi_AddWithMetadataAndVisibility(impl::abi_arg_in<Windows::Storage::IStorageItem> file, impl::abi_arg_in<hstring> metadata, Windows::Storage::AccessCache::RecentStorageItemVisibility visibility, impl::abi_arg_out<hstring> token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Add(*reinterpret_cast<const Windows::Storage::IStorageItem *>(&file), *reinterpret_cast<const hstring *>(&metadata), visibility));
            return S_OK;
        }
        catch (...)
        {
            *token = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddOrReplaceWithMetadataAndVisibility(impl::abi_arg_in<hstring> token, impl::abi_arg_in<Windows::Storage::IStorageItem> file, impl::abi_arg_in<hstring> metadata, Windows::Storage::AccessCache::RecentStorageItemVisibility visibility) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddOrReplace(*reinterpret_cast<const hstring *>(&token), *reinterpret_cast<const Windows::Storage::IStorageItem *>(&file), *reinterpret_cast<const hstring *>(&metadata), visibility);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Storage::AccessCache {

template <typename D> Windows::Storage::AccessCache::AccessListEntry impl_IItemRemovedEventArgs<D>::RemovedEntry() const
{
    Windows::Storage::AccessCache::AccessListEntry value {};
    check_hresult(WINRT_SHIM(IItemRemovedEventArgs)->get_RemovedEntry(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStorageItemAccessList<D>::Add(const Windows::Storage::IStorageItem & file) const
{
    hstring token;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_AddOverloadDefaultMetadata(get_abi(file), put_abi(token)));
    return token;
}

template <typename D> hstring impl_IStorageItemAccessList<D>::Add(const Windows::Storage::IStorageItem & file, hstring_view metadata) const
{
    hstring token;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_Add(get_abi(file), get_abi(metadata), put_abi(token)));
    return token;
}

template <typename D> void impl_IStorageItemAccessList<D>::AddOrReplace(hstring_view token, const Windows::Storage::IStorageItem & file) const
{
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_AddOrReplaceOverloadDefaultMetadata(get_abi(token), get_abi(file)));
}

template <typename D> void impl_IStorageItemAccessList<D>::AddOrReplace(hstring_view token, const Windows::Storage::IStorageItem & file, hstring_view metadata) const
{
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_AddOrReplace(get_abi(token), get_abi(file), get_abi(metadata)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem> impl_IStorageItemAccessList<D>::GetItemAsync(hstring_view token) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem> operation;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_GetItemAsync(get_abi(token), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageItemAccessList<D>::GetFileAsync(hstring_view token) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_GetFileAsync(get_abi(token), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IStorageItemAccessList<D>::GetFolderAsync(hstring_view token) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_GetFolderAsync(get_abi(token), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem> impl_IStorageItemAccessList<D>::GetItemAsync(hstring_view token, Windows::Storage::AccessCache::AccessCacheOptions options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::IStorageItem> operation;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_GetItemWithOptionsAsync(get_abi(token), options, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IStorageItemAccessList<D>::GetFileAsync(hstring_view token, Windows::Storage::AccessCache::AccessCacheOptions options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_GetFileWithOptionsAsync(get_abi(token), options, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> impl_IStorageItemAccessList<D>::GetFolderAsync(hstring_view token, Windows::Storage::AccessCache::AccessCacheOptions options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> operation;
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_GetFolderWithOptionsAsync(get_abi(token), options, put_abi(operation)));
    return operation;
}

template <typename D> void impl_IStorageItemAccessList<D>::Remove(hstring_view token) const
{
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_Remove(get_abi(token)));
}

template <typename D> bool impl_IStorageItemAccessList<D>::ContainsItem(hstring_view token) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_ContainsItem(get_abi(token), &value));
    return value;
}

template <typename D> void impl_IStorageItemAccessList<D>::Clear() const
{
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_Clear());
}

template <typename D> bool impl_IStorageItemAccessList<D>::CheckAccess(const Windows::Storage::IStorageItem & file) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->abi_CheckAccess(get_abi(file), &value));
    return value;
}

template <typename D> Windows::Storage::AccessCache::AccessListEntryView impl_IStorageItemAccessList<D>::Entries() const
{
    Windows::Storage::AccessCache::AccessListEntryView entries { nullptr };
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->get_Entries(put_abi(entries)));
    return entries;
}

template <typename D> uint32_t impl_IStorageItemAccessList<D>::MaximumItemsAllowed() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IStorageItemAccessList)->get_MaximumItemsAllowed(&value));
    return value;
}

template <typename D> event_token impl_IStorageItemMostRecentlyUsedList<D>::ItemRemoved(const Windows::Foundation::TypedEventHandler<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::ItemRemovedEventArgs> & handler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IStorageItemMostRecentlyUsedList)->add_ItemRemoved(get_abi(handler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IStorageItemMostRecentlyUsedList> impl_IStorageItemMostRecentlyUsedList<D>::ItemRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::ItemRemovedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IStorageItemMostRecentlyUsedList>(this, &ABI::Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList::remove_ItemRemoved, ItemRemoved(handler));
}

template <typename D> void impl_IStorageItemMostRecentlyUsedList<D>::ItemRemoved(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IStorageItemMostRecentlyUsedList)->remove_ItemRemoved(eventCookie));
}

template <typename D> hstring impl_IStorageItemMostRecentlyUsedList2<D>::Add(const Windows::Storage::IStorageItem & file, hstring_view metadata, Windows::Storage::AccessCache::RecentStorageItemVisibility visibility) const
{
    hstring token;
    check_hresult(WINRT_SHIM(IStorageItemMostRecentlyUsedList2)->abi_AddWithMetadataAndVisibility(get_abi(file), get_abi(metadata), visibility, put_abi(token)));
    return token;
}

template <typename D> void impl_IStorageItemMostRecentlyUsedList2<D>::AddOrReplace(hstring_view token, const Windows::Storage::IStorageItem & file, hstring_view metadata, Windows::Storage::AccessCache::RecentStorageItemVisibility visibility) const
{
    check_hresult(WINRT_SHIM(IStorageItemMostRecentlyUsedList2)->abi_AddOrReplaceWithMetadataAndVisibility(get_abi(token), get_abi(file), get_abi(metadata), visibility));
}

template <typename D> Windows::Storage::AccessCache::StorageItemAccessList impl_IStorageApplicationPermissionsStatics<D>::FutureAccessList() const
{
    Windows::Storage::AccessCache::StorageItemAccessList value { nullptr };
    check_hresult(WINRT_SHIM(IStorageApplicationPermissionsStatics)->get_FutureAccessList(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList impl_IStorageApplicationPermissionsStatics<D>::MostRecentlyUsedList() const
{
    Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList value { nullptr };
    check_hresult(WINRT_SHIM(IStorageApplicationPermissionsStatics)->get_MostRecentlyUsedList(put_abi(value)));
    return value;
}

inline Windows::Storage::AccessCache::StorageItemAccessList StorageApplicationPermissions::FutureAccessList()
{
    return get_activation_factory<StorageApplicationPermissions, IStorageApplicationPermissionsStatics>().FutureAccessList();
}

inline Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList StorageApplicationPermissions::MostRecentlyUsedList()
{
    return get_activation_factory<StorageApplicationPermissions, IStorageApplicationPermissionsStatics>().MostRecentlyUsedList();
}

}

}
#pragma warning(pop)
