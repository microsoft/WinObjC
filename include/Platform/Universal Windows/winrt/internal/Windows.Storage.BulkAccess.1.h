// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Storage.BulkAccess.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Storage.FileProperties.0.h"
#include "Windows.Storage.Search.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Storage::BulkAccess {

struct __declspec(uuid("401d88be-960f-4d6d-a7d0-1a3861e76c83")) __declspec(novtable) IFileInformationFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetItemsAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::IStorageItemInformation>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetItemsAsyncDefaultStartAndCount(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::IStorageItemInformation>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetFilesAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FileInformation>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetFilesAsyncDefaultStartAndCount(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FileInformation>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetFoldersAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FolderInformation>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetFoldersAsyncDefaultStartAndCount(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FolderInformation>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetVirtualizedItemsVector(Windows::Foundation::IInspectable ** vector) = 0;
    virtual HRESULT __stdcall abi_GetVirtualizedFilesVector(Windows::Foundation::IInspectable ** vector) = 0;
    virtual HRESULT __stdcall abi_GetVirtualizedFoldersVector(Windows::Foundation::IInspectable ** vector) = 0;
};

struct __declspec(uuid("84ea0e7d-e4a2-4f00-8afa-af5e0f826bd5")) __declspec(novtable) IFileInformationFactoryFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWithMode(Windows::Storage::Search::IStorageQueryResultBase * queryResult, winrt::Windows::Storage::FileProperties::ThumbnailMode mode, Windows::Storage::BulkAccess::IFileInformationFactory ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithModeAndSize(Windows::Storage::Search::IStorageQueryResultBase * queryResult, winrt::Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedThumbnailSize, Windows::Storage::BulkAccess::IFileInformationFactory ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithModeAndSizeAndOptions(Windows::Storage::Search::IStorageQueryResultBase * queryResult, winrt::Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedThumbnailSize, winrt::Windows::Storage::FileProperties::ThumbnailOptions thumbnailOptions, Windows::Storage::BulkAccess::IFileInformationFactory ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithModeAndSizeAndOptionsAndFlags(Windows::Storage::Search::IStorageQueryResultBase * queryResult, winrt::Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedThumbnailSize, winrt::Windows::Storage::FileProperties::ThumbnailOptions thumbnailOptions, bool delayLoad, Windows::Storage::BulkAccess::IFileInformationFactory ** value) = 0;
};

struct __declspec(uuid("87a5cb8b-8972-4f40-8de0-d86fb179d8fa")) __declspec(novtable) IStorageItemInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MusicProperties(Windows::Storage::FileProperties::IMusicProperties ** value) = 0;
    virtual HRESULT __stdcall get_VideoProperties(Windows::Storage::FileProperties::IVideoProperties ** value) = 0;
    virtual HRESULT __stdcall get_ImageProperties(Windows::Storage::FileProperties::IImageProperties ** value) = 0;
    virtual HRESULT __stdcall get_DocumentProperties(Windows::Storage::FileProperties::IDocumentProperties ** value) = 0;
    virtual HRESULT __stdcall get_BasicProperties(Windows::Storage::FileProperties::IBasicProperties ** value) = 0;
    virtual HRESULT __stdcall get_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamWithContentType ** value) = 0;
    virtual HRESULT __stdcall add_ThumbnailUpdated(Windows::Foundation::TypedEventHandler<Windows::Storage::BulkAccess::IStorageItemInformation, Windows::Foundation::IInspectable> * changedHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_ThumbnailUpdated(event_token eventCookie) = 0;
    virtual HRESULT __stdcall add_PropertiesUpdated(Windows::Foundation::TypedEventHandler<Windows::Storage::BulkAccess::IStorageItemInformation, Windows::Foundation::IInspectable> * changedHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_PropertiesUpdated(event_token eventCookie) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Storage::BulkAccess::FileInformation> { using default_interface = Windows::Storage::BulkAccess::IStorageItemInformation; };
template <> struct traits<Windows::Storage::BulkAccess::FileInformationFactory> { using default_interface = Windows::Storage::BulkAccess::IFileInformationFactory; };
template <> struct traits<Windows::Storage::BulkAccess::FolderInformation> { using default_interface = Windows::Storage::BulkAccess::IStorageItemInformation; };

}

namespace Windows::Storage::BulkAccess {

template <typename D>
struct WINRT_EBO impl_IFileInformationFactory
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::IStorageItemInformation>> GetItemsAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::IStorageItemInformation>> GetItemsAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FileInformation>> GetFilesAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FileInformation>> GetFilesAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FolderInformation>> GetFoldersAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FolderInformation>> GetFoldersAsync() const;
    Windows::Foundation::IInspectable GetVirtualizedItemsVector() const;
    Windows::Foundation::IInspectable GetVirtualizedFilesVector() const;
    Windows::Foundation::IInspectable GetVirtualizedFoldersVector() const;
};

template <typename D>
struct WINRT_EBO impl_IFileInformationFactoryFactory
{
    Windows::Storage::BulkAccess::FileInformationFactory CreateWithMode(const Windows::Storage::Search::IStorageQueryResultBase & queryResult, Windows::Storage::FileProperties::ThumbnailMode mode) const;
    Windows::Storage::BulkAccess::FileInformationFactory CreateWithModeAndSize(const Windows::Storage::Search::IStorageQueryResultBase & queryResult, Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedThumbnailSize) const;
    Windows::Storage::BulkAccess::FileInformationFactory CreateWithModeAndSizeAndOptions(const Windows::Storage::Search::IStorageQueryResultBase & queryResult, Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedThumbnailSize, Windows::Storage::FileProperties::ThumbnailOptions thumbnailOptions) const;
    Windows::Storage::BulkAccess::FileInformationFactory CreateWithModeAndSizeAndOptionsAndFlags(const Windows::Storage::Search::IStorageQueryResultBase & queryResult, Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedThumbnailSize, Windows::Storage::FileProperties::ThumbnailOptions thumbnailOptions, bool delayLoad) const;
};

template <typename D>
struct WINRT_EBO impl_IStorageItemInformation
{
    Windows::Storage::FileProperties::MusicProperties MusicProperties() const;
    Windows::Storage::FileProperties::VideoProperties VideoProperties() const;
    Windows::Storage::FileProperties::ImageProperties ImageProperties() const;
    Windows::Storage::FileProperties::DocumentProperties DocumentProperties() const;
    Windows::Storage::FileProperties::BasicProperties BasicProperties() const;
    Windows::Storage::FileProperties::StorageItemThumbnail Thumbnail() const;
    event_token ThumbnailUpdated(const Windows::Foundation::TypedEventHandler<Windows::Storage::BulkAccess::IStorageItemInformation, Windows::Foundation::IInspectable> & changedHandler) const;
    using ThumbnailUpdated_revoker = event_revoker<IStorageItemInformation>;
    ThumbnailUpdated_revoker ThumbnailUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::BulkAccess::IStorageItemInformation, Windows::Foundation::IInspectable> & changedHandler) const;
    void ThumbnailUpdated(event_token eventCookie) const;
    event_token PropertiesUpdated(const Windows::Foundation::TypedEventHandler<Windows::Storage::BulkAccess::IStorageItemInformation, Windows::Foundation::IInspectable> & changedHandler) const;
    using PropertiesUpdated_revoker = event_revoker<IStorageItemInformation>;
    PropertiesUpdated_revoker PropertiesUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Storage::BulkAccess::IStorageItemInformation, Windows::Foundation::IInspectable> & changedHandler) const;
    void PropertiesUpdated(event_token eventCookie) const;
};

}

namespace impl {

template <> struct traits<Windows::Storage::BulkAccess::IFileInformationFactory>
{
    using abi = ABI::Windows::Storage::BulkAccess::IFileInformationFactory;
    template <typename D> using consume = Windows::Storage::BulkAccess::impl_IFileInformationFactory<D>;
};

template <> struct traits<Windows::Storage::BulkAccess::IFileInformationFactoryFactory>
{
    using abi = ABI::Windows::Storage::BulkAccess::IFileInformationFactoryFactory;
    template <typename D> using consume = Windows::Storage::BulkAccess::impl_IFileInformationFactoryFactory<D>;
};

template <> struct traits<Windows::Storage::BulkAccess::IStorageItemInformation>
{
    using abi = ABI::Windows::Storage::BulkAccess::IStorageItemInformation;
    template <typename D> using consume = Windows::Storage::BulkAccess::impl_IStorageItemInformation<D>;
};

template <> struct traits<Windows::Storage::BulkAccess::FileInformation>
{
    using abi = ABI::Windows::Storage::BulkAccess::FileInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.BulkAccess.FileInformation"; }
};

template <> struct traits<Windows::Storage::BulkAccess::FileInformationFactory>
{
    using abi = ABI::Windows::Storage::BulkAccess::FileInformationFactory;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.BulkAccess.FileInformationFactory"; }
};

template <> struct traits<Windows::Storage::BulkAccess::FolderInformation>
{
    using abi = ABI::Windows::Storage::BulkAccess::FolderInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.BulkAccess.FolderInformation"; }
};

}

}
