// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Playlists.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5e52f8ce_aced_5a42_95b4_f674dd84885e
#define WINRT_GENERIC_5e52f8ce_aced_5a42_95b4_f674dd84885e
template <> struct __declspec(uuid("5e52f8ce-aced-5a42-95b4-f674dd84885e")) __declspec(novtable) IAsyncOperation<Windows::Storage::StorageFile> : impl_IAsyncOperation<Windows::Storage::StorageFile> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_80646519_5e2a_595d_a8cd_2a24b4067f1b
#define WINRT_GENERIC_80646519_5e2a_595d_a8cd_2a24b4067f1b
template <> struct __declspec(uuid("80646519-5e2a-595d-a8cd-2a24b4067f1b")) __declspec(novtable) IVectorView<Windows::Storage::StorageFile> : impl_IVectorView<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_9ac00304_83ea_5688_87b6_ae38aab65d0b
#define WINRT_GENERIC_9ac00304_83ea_5688_87b6_ae38aab65d0b
template <> struct __declspec(uuid("9ac00304-83ea-5688-87b6-ae38aab65d0b")) __declspec(novtable) IIterable<Windows::Storage::StorageFile> : impl_IIterable<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_fcbc8b8b_6103_5b4e_ba00_4bc2cedb6a35
#define WINRT_GENERIC_fcbc8b8b_6103_5b4e_ba00_4bc2cedb6a35
template <> struct __declspec(uuid("fcbc8b8b-6103-5b4e-ba00-4bc2cedb6a35")) __declspec(novtable) IVector<Windows::Storage::StorageFile> : impl_IVector<Windows::Storage::StorageFile> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_8ffb74ab_912f_5bc1_87fa_2865f673cbfc
#define WINRT_GENERIC_8ffb74ab_912f_5bc1_87fa_2865f673cbfc
template <> struct __declspec(uuid("8ffb74ab-912f-5bc1-87fa-2865f673cbfc")) __declspec(novtable) IAsyncOperation<Windows::Media::Playlists::Playlist> : impl_IAsyncOperation<Windows::Media::Playlists::Playlist> {};
#endif

#ifndef WINRT_GENERIC_e521c894_2c26_5946_9e61_2b5e188d01ed
#define WINRT_GENERIC_e521c894_2c26_5946_9e61_2b5e188d01ed
template <> struct __declspec(uuid("e521c894-2c26-5946-9e61-2b5e188d01ed")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::StorageFile> : impl_AsyncOperationCompletedHandler<Windows::Storage::StorageFile> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_43e29f53_0298_55aa_a6c8_4edd323d9598
#define WINRT_GENERIC_43e29f53_0298_55aa_a6c8_4edd323d9598
template <> struct __declspec(uuid("43e29f53-0298-55aa-a6c8-4edd323d9598")) __declspec(novtable) IIterator<Windows::Storage::StorageFile> : impl_IIterator<Windows::Storage::StorageFile> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_427deafd_b226_5ef0_9320_c9f325e37474
#define WINRT_GENERIC_427deafd_b226_5ef0_9320_c9f325e37474
template <> struct __declspec(uuid("427deafd-b226-5ef0-9320-c9f325e37474")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::Playlists::Playlist> : impl_AsyncOperationCompletedHandler<Windows::Media::Playlists::Playlist> {};
#endif


}

namespace Windows::Media::Playlists {

struct IPlaylist :
    Windows::Foundation::IInspectable,
    impl::consume<IPlaylist>
{
    IPlaylist(std::nullptr_t = nullptr) noexcept {}
};

struct IPlaylistStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPlaylistStatics>
{
    IPlaylistStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
