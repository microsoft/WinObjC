// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.AccessCache.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Storage::AccessCache {

struct WINRT_EBO AccessListEntryView :
    Windows::Foundation::Collections::IVectorView<Windows::Storage::AccessCache::AccessListEntry>
{
    AccessListEntryView(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ItemRemovedEventArgs :
    Windows::Storage::AccessCache::IItemRemovedEventArgs
{
    ItemRemovedEventArgs(std::nullptr_t) noexcept {}
};

struct StorageApplicationPermissions
{
    StorageApplicationPermissions() = delete;
    static Windows::Storage::AccessCache::StorageItemAccessList FutureAccessList();
    static Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList MostRecentlyUsedList();
};

struct WINRT_EBO StorageItemAccessList :
    Windows::Storage::AccessCache::IStorageItemAccessList
{
    StorageItemAccessList(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StorageItemMostRecentlyUsedList :
    Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList,
    impl::require<StorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList2>
{
    StorageItemMostRecentlyUsedList(std::nullptr_t) noexcept {}
    using impl_IStorageItemAccessList::Add;
    using impl_IStorageItemAccessList::AddOrReplace;
    using impl_IStorageItemMostRecentlyUsedList2::Add;
    using impl_IStorageItemMostRecentlyUsedList2::AddOrReplace;
};

}

}
