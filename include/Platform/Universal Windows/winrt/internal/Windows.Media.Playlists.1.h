// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.Playlists.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Storage.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Playlists {

struct __declspec(uuid("803736f5-cf44-4d97-83b3-7a089e9ab663")) __declspec(novtable) IPlaylist : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Files(Windows::Foundation::Collections::IVector<Windows::Storage::StorageFile> ** value) = 0;
    virtual HRESULT __stdcall abi_SaveAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_SaveAsAsync(Windows::Storage::IStorageFolder * saveLocation, hstring desiredName, winrt::Windows::Storage::NameCollisionOption option, Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> ** operation) = 0;
    virtual HRESULT __stdcall abi_SaveAsWithFormatAsync(Windows::Storage::IStorageFolder * saveLocation, hstring desiredName, winrt::Windows::Storage::NameCollisionOption option, winrt::Windows::Media::Playlists::PlaylistFormat playlistFormat, Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> ** operation) = 0;
};

struct __declspec(uuid("c5c331cd-81f9-4ff3-95b9-70b6ff046b68")) __declspec(novtable) IPlaylistStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_LoadAsync(Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncOperation<Windows::Media::Playlists::Playlist> ** operation) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::Playlists::Playlist> { using default_interface = Windows::Media::Playlists::IPlaylist; };

}

namespace Windows::Media::Playlists {

template <typename D>
struct WINRT_EBO impl_IPlaylist
{
    Windows::Foundation::Collections::IVector<Windows::Storage::StorageFile> Files() const;
    Windows::Foundation::IAsyncAction SaveAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> SaveAsAsync(const Windows::Storage::IStorageFolder & saveLocation, hstring_view desiredName, Windows::Storage::NameCollisionOption option) const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> SaveAsAsync(const Windows::Storage::IStorageFolder & saveLocation, hstring_view desiredName, Windows::Storage::NameCollisionOption option, Windows::Media::Playlists::PlaylistFormat playlistFormat) const;
};

template <typename D>
struct WINRT_EBO impl_IPlaylistStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Playlists::Playlist> LoadAsync(const Windows::Storage::IStorageFile & file) const;
};

}

namespace impl {

template <> struct traits<Windows::Media::Playlists::IPlaylist>
{
    using abi = ABI::Windows::Media::Playlists::IPlaylist;
    template <typename D> using consume = Windows::Media::Playlists::impl_IPlaylist<D>;
};

template <> struct traits<Windows::Media::Playlists::IPlaylistStatics>
{
    using abi = ABI::Windows::Media::Playlists::IPlaylistStatics;
    template <typename D> using consume = Windows::Media::Playlists::impl_IPlaylistStatics<D>;
};

template <> struct traits<Windows::Media::Playlists::Playlist>
{
    using abi = ABI::Windows::Media::Playlists::Playlist;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playlists.Playlist"; }
};

}

}
