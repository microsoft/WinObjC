// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Storage::AccessCache {

struct AccessListEntry;

}

namespace Windows::Storage::AccessCache {

struct AccessListEntry;

}

namespace ABI::Windows::Storage::AccessCache {

struct IItemRemovedEventArgs;
struct IStorageApplicationPermissionsStatics;
struct IStorageItemAccessList;
struct IStorageItemMostRecentlyUsedList;
struct IStorageItemMostRecentlyUsedList2;
struct AccessListEntryView;
struct ItemRemovedEventArgs;
struct StorageItemAccessList;
struct StorageItemMostRecentlyUsedList;

}

namespace Windows::Storage::AccessCache {

struct IItemRemovedEventArgs;
struct IStorageApplicationPermissionsStatics;
struct IStorageItemAccessList;
struct IStorageItemMostRecentlyUsedList;
struct IStorageItemMostRecentlyUsedList2;
struct AccessListEntryView;
struct ItemRemovedEventArgs;
struct StorageApplicationPermissions;
struct StorageItemAccessList;
struct StorageItemMostRecentlyUsedList;

}

namespace Windows::Storage::AccessCache {

template <typename T> struct impl_IItemRemovedEventArgs;
template <typename T> struct impl_IStorageApplicationPermissionsStatics;
template <typename T> struct impl_IStorageItemAccessList;
template <typename T> struct impl_IStorageItemMostRecentlyUsedList;
template <typename T> struct impl_IStorageItemMostRecentlyUsedList2;

}

namespace Windows::Storage::AccessCache {

enum class AccessCacheOptions : unsigned
{
    None = 0x0,
    DisallowUserInput = 0x1,
    FastLocationsOnly = 0x2,
    UseReadOnlyCachedCopy = 0x4,
    SuppressAccessTimeUpdate = 0x8,
};

DEFINE_ENUM_FLAG_OPERATORS(AccessCacheOptions)

enum class RecentStorageItemVisibility
{
    AppOnly = 0,
    AppAndSystem = 1,
};

}

}
