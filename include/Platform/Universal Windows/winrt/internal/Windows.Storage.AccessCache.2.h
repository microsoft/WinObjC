// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.AccessCache.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_6be9e7d7_e83a_5cbc_802c_1768960b52c3
#define WINRT_GENERIC_6be9e7d7_e83a_5cbc_802c_1768960b52c3
template <> struct __declspec(uuid("6be9e7d7-e83a-5cbc-802c-1768960b52c3")) __declspec(novtable) IAsyncOperation<Windows::Storage::StorageFolder> : impl_IAsyncOperation<Windows::Storage::StorageFolder> {};
#endif

#ifndef WINRT_GENERIC_5e52f8ce_aced_5a42_95b4_f674dd84885e
#define WINRT_GENERIC_5e52f8ce_aced_5a42_95b4_f674dd84885e
template <> struct __declspec(uuid("5e52f8ce-aced-5a42-95b4-f674dd84885e")) __declspec(novtable) IAsyncOperation<Windows::Storage::StorageFile> : impl_IAsyncOperation<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_5fc9c137_ebb7_5e6c_9cba_686f2ec2b0bb
#define WINRT_GENERIC_5fc9c137_ebb7_5e6c_9cba_686f2ec2b0bb
template <> struct __declspec(uuid("5fc9c137-ebb7-5e6c-9cba-686f2ec2b0bb")) __declspec(novtable) IAsyncOperation<Windows::Storage::IStorageItem> : impl_IAsyncOperation<Windows::Storage::IStorageItem> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_42b49b8a_3014_5d27_8f2c_1ef5ee89ec00
#define WINRT_GENERIC_42b49b8a_3014_5d27_8f2c_1ef5ee89ec00
template <> struct __declspec(uuid("42b49b8a-3014-5d27-8f2c-1ef5ee89ec00")) __declspec(novtable) IVectorView<Windows::Storage::AccessCache::AccessListEntry> : impl_IVectorView<Windows::Storage::AccessCache::AccessListEntry> {};
#endif

#ifndef WINRT_GENERIC_4995c2b0_736b_588d_ae42_6f69b025b388
#define WINRT_GENERIC_4995c2b0_736b_588d_ae42_6f69b025b388
template <> struct __declspec(uuid("4995c2b0-736b-588d-ae42-6f69b025b388")) __declspec(novtable) IIterable<Windows::Storage::AccessCache::AccessListEntry> : impl_IIterable<Windows::Storage::AccessCache::AccessListEntry> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_029dace8_98d1_5bf7_b780_9717e95027ff
#define WINRT_GENERIC_029dace8_98d1_5bf7_b780_9717e95027ff
template <> struct __declspec(uuid("029dace8-98d1-5bf7-b780-9717e95027ff")) __declspec(novtable) TypedEventHandler<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::ItemRemovedEventArgs> : impl_TypedEventHandler<Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::ItemRemovedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_c211026e_9e63_5452_ba54_3a07d6a96874
#define WINRT_GENERIC_c211026e_9e63_5452_ba54_3a07d6a96874
template <> struct __declspec(uuid("c211026e-9e63-5452-ba54-3a07d6a96874")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::StorageFolder> : impl_AsyncOperationCompletedHandler<Windows::Storage::StorageFolder> {};
#endif

#ifndef WINRT_GENERIC_e521c894_2c26_5946_9e61_2b5e188d01ed
#define WINRT_GENERIC_e521c894_2c26_5946_9e61_2b5e188d01ed
template <> struct __declspec(uuid("e521c894-2c26-5946-9e61-2b5e188d01ed")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::StorageFile> : impl_AsyncOperationCompletedHandler<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_92c3102f_a327_5318_a6c1_76f6b2a0abfb
#define WINRT_GENERIC_92c3102f_a327_5318_a6c1_76f6b2a0abfb
template <> struct __declspec(uuid("92c3102f-a327-5318-a6c1-76f6b2a0abfb")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::IStorageItem> : impl_AsyncOperationCompletedHandler<Windows::Storage::IStorageItem> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_d1a0a6c4_889d_519b_8508_26241b329b7e
#define WINRT_GENERIC_d1a0a6c4_889d_519b_8508_26241b329b7e
template <> struct __declspec(uuid("d1a0a6c4-889d-519b-8508-26241b329b7e")) __declspec(novtable) IIterator<Windows::Storage::AccessCache::AccessListEntry> : impl_IIterator<Windows::Storage::AccessCache::AccessListEntry> {};
#endif


}

namespace Windows::Storage::AccessCache {

struct IItemRemovedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IItemRemovedEventArgs>
{
    IItemRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageApplicationPermissionsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageApplicationPermissionsStatics>
{
    IStorageApplicationPermissionsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageItemAccessList :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageItemAccessList>
{
    IStorageItemAccessList(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageItemMostRecentlyUsedList :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageItemMostRecentlyUsedList>,
    impl::require<IStorageItemMostRecentlyUsedList, Windows::Storage::AccessCache::IStorageItemAccessList>
{
    IStorageItemMostRecentlyUsedList(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageItemMostRecentlyUsedList2 :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageItemMostRecentlyUsedList2>,
    impl::require<IStorageItemMostRecentlyUsedList2, Windows::Storage::AccessCache::IStorageItemAccessList, Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList>
{
    IStorageItemMostRecentlyUsedList2(std::nullptr_t = nullptr) noexcept {}
    using impl_IStorageItemAccessList::Add;
    using impl_IStorageItemAccessList::AddOrReplace;
    using impl_IStorageItemMostRecentlyUsedList2::Add;
    using impl_IStorageItemMostRecentlyUsedList2::AddOrReplace;
};

}

}
