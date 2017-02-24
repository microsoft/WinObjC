// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Media.Playlists.3.h"
#include "Windows.Media.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::Playlists::IPlaylist> : produce_base<D, Windows::Media::Playlists::IPlaylist>
{
    HRESULT __stdcall get_Files(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Storage::StorageFile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Files());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SaveAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveAsAsync(impl::abi_arg_in<Windows::Storage::IStorageFolder> saveLocation, impl::abi_arg_in<hstring> desiredName, Windows::Storage::NameCollisionOption option, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SaveAsAsync(*reinterpret_cast<const Windows::Storage::IStorageFolder *>(&saveLocation), *reinterpret_cast<const hstring *>(&desiredName), option));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveAsWithFormatAsync(impl::abi_arg_in<Windows::Storage::IStorageFolder> saveLocation, impl::abi_arg_in<hstring> desiredName, Windows::Storage::NameCollisionOption option, Windows::Media::Playlists::PlaylistFormat playlistFormat, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SaveAsAsync(*reinterpret_cast<const Windows::Storage::IStorageFolder *>(&saveLocation), *reinterpret_cast<const hstring *>(&desiredName), option, playlistFormat));
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
struct produce<D, Windows::Media::Playlists::IPlaylistStatics> : produce_base<D, Windows::Media::Playlists::IPlaylistStatics>
{
    HRESULT __stdcall abi_LoadAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Playlists::Playlist>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LoadAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
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

namespace Windows::Media::Playlists {

template <typename D> Windows::Foundation::Collections::IVector<Windows::Storage::StorageFile> impl_IPlaylist<D>::Files() const
{
    Windows::Foundation::Collections::IVector<Windows::Storage::StorageFile> value;
    check_hresult(WINRT_SHIM(IPlaylist)->get_Files(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPlaylist<D>::SaveAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IPlaylist)->abi_SaveAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IPlaylist<D>::SaveAsAsync(const Windows::Storage::IStorageFolder & saveLocation, hstring_view desiredName, Windows::Storage::NameCollisionOption option) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IPlaylist)->abi_SaveAsAsync(get_abi(saveLocation), get_abi(desiredName), option, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> impl_IPlaylist<D>::SaveAsAsync(const Windows::Storage::IStorageFolder & saveLocation, hstring_view desiredName, Windows::Storage::NameCollisionOption option, Windows::Media::Playlists::PlaylistFormat playlistFormat) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> operation;
    check_hresult(WINRT_SHIM(IPlaylist)->abi_SaveAsWithFormatAsync(get_abi(saveLocation), get_abi(desiredName), option, playlistFormat, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Playlists::Playlist> impl_IPlaylistStatics<D>::LoadAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Playlists::Playlist> operation;
    check_hresult(WINRT_SHIM(IPlaylistStatics)->abi_LoadAsync(get_abi(file), put_abi(operation)));
    return operation;
}

inline Playlist::Playlist() :
    Playlist(activate_instance<Playlist>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::Media::Playlists::Playlist> Playlist::LoadAsync(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<Playlist, IPlaylistStatics>().LoadAsync(file);
}

}

}
#pragma warning(pop)
