// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.BulkAccess.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Storage::BulkAccess {

struct WINRT_EBO FileInformation :
    Windows::Storage::BulkAccess::IStorageItemInformation,
    impl::require<FileInformation, Windows::Storage::Streams::IRandomAccessStreamReference, Windows::Storage::IStorageItem, Windows::Storage::Streams::IInputStreamReference, Windows::Storage::IStorageFile, Windows::Storage::IStorageItem2, Windows::Storage::IStorageItemProperties, Windows::Storage::IStorageItemPropertiesWithProvider, Windows::Storage::IStorageFilePropertiesWithAvailability, Windows::Storage::IStorageFile2>
{
    FileInformation(std::nullptr_t) noexcept {}
    using impl_IStorageFile::OpenAsync;
    using impl_IStorageFile::OpenTransactedWriteAsync;
    using impl_IStorageFile2::OpenAsync;
    using impl_IStorageFile2::OpenTransactedWriteAsync;
};

struct WINRT_EBO FileInformationFactory :
    Windows::Storage::BulkAccess::IFileInformationFactory
{
    FileInformationFactory(std::nullptr_t) noexcept {}
    FileInformationFactory(const Windows::Storage::Search::IStorageQueryResultBase & queryResult, Windows::Storage::FileProperties::ThumbnailMode mode);
    FileInformationFactory(const Windows::Storage::Search::IStorageQueryResultBase & queryResult, Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedThumbnailSize);
    FileInformationFactory(const Windows::Storage::Search::IStorageQueryResultBase & queryResult, Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedThumbnailSize, Windows::Storage::FileProperties::ThumbnailOptions thumbnailOptions);
    FileInformationFactory(const Windows::Storage::Search::IStorageQueryResultBase & queryResult, Windows::Storage::FileProperties::ThumbnailMode mode, uint32_t requestedThumbnailSize, Windows::Storage::FileProperties::ThumbnailOptions thumbnailOptions, bool delayLoad);
};

struct WINRT_EBO FolderInformation :
    Windows::Storage::BulkAccess::IStorageItemInformation,
    impl::require<FolderInformation, Windows::Storage::IStorageItem, Windows::Storage::IStorageFolder, Windows::Storage::IStorageItem2, Windows::Storage::IStorageItemProperties, Windows::Storage::IStorageItemPropertiesWithProvider, Windows::Storage::Search::IStorageFolderQueryOperations, Windows::Storage::IStorageFolder2>
{
    FolderInformation(std::nullptr_t) noexcept {}
    using impl_IStorageFolder::GetFilesAsync;
    using impl_IStorageFolder::GetFoldersAsync;
    using impl_IStorageFolder::GetItemsAsync;
    using impl_IStorageFolderQueryOperations::GetFilesAsync;
    using impl_IStorageFolderQueryOperations::GetFoldersAsync;
    using impl_IStorageFolderQueryOperations::GetItemsAsync;
};

}

}
