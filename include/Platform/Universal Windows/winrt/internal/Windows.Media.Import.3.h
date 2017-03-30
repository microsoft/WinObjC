// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Import.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Import {

struct WINRT_EBO PhotoImportDeleteImportedItemsFromSourceResult :
    Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult
{
    PhotoImportDeleteImportedItemsFromSourceResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhotoImportFindItemsResult :
    Windows::Media::Import::IPhotoImportFindItemsResult,
    impl::require<PhotoImportFindItemsResult, Windows::Media::Import::IPhotoImportFindItemsResult2>
{
    PhotoImportFindItemsResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhotoImportImportItemsResult :
    Windows::Media::Import::IPhotoImportImportItemsResult
{
    PhotoImportImportItemsResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhotoImportItem :
    Windows::Media::Import::IPhotoImportItem
{
    PhotoImportItem(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhotoImportItemImportedEventArgs :
    Windows::Media::Import::IPhotoImportItemImportedEventArgs
{
    PhotoImportItemImportedEventArgs(std::nullptr_t) noexcept {}
};

struct PhotoImportManager
{
    PhotoImportManager() = delete;
    static Windows::Foundation::IAsyncOperation<bool> IsSupportedAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportSource>> FindAllSourcesAsync();
    static Windows::Foundation::Collections::IVectorView<Windows::Media::Import::PhotoImportOperation> GetPendingOperations();
};

struct WINRT_EBO PhotoImportOperation :
    Windows::Media::Import::IPhotoImportOperation
{
    PhotoImportOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhotoImportSelectionChangedEventArgs :
    Windows::Media::Import::IPhotoImportSelectionChangedEventArgs
{
    PhotoImportSelectionChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhotoImportSession :
    Windows::Media::Import::IPhotoImportSession,
    impl::require<PhotoImportSession, Windows::Media::Import::IPhotoImportSession2>
{
    PhotoImportSession(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhotoImportSidecar :
    Windows::Media::Import::IPhotoImportSidecar
{
    PhotoImportSidecar(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhotoImportSource :
    Windows::Media::Import::IPhotoImportSource
{
    PhotoImportSource(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Media::Import::PhotoImportSource> FromIdAsync(hstring_view sourceId);
    static Windows::Foundation::IAsyncOperation<Windows::Media::Import::PhotoImportSource> FromFolderAsync(const Windows::Storage::IStorageFolder & sourceRootFolder);
};

struct WINRT_EBO PhotoImportStorageMedium :
    Windows::Media::Import::IPhotoImportStorageMedium
{
    PhotoImportStorageMedium(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PhotoImportVideoSegment :
    Windows::Media::Import::IPhotoImportVideoSegment
{
    PhotoImportVideoSegment(std::nullptr_t) noexcept {}
};

}

}
