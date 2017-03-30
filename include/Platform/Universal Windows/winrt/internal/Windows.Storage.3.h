// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Storage {

template <typename H> struct impl_ApplicationDataSetVersionHandler : implements<impl_ApplicationDataSetVersionHandler<H>, abi<ApplicationDataSetVersionHandler>>, H
{
    impl_ApplicationDataSetVersionHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Storage::ISetVersionRequest> setVersionRequest) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Storage::SetVersionRequest *>(&setVersionRequest));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_StreamedFileDataRequestedHandler : implements<impl_StreamedFileDataRequestedHandler<H>, abi<StreamedFileDataRequestedHandler>>, H
{
    impl_StreamedFileDataRequestedHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> stream) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Storage::StreamedFileDataRequest *>(&stream));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Storage {

struct WINRT_EBO ApplicationData :
    Windows::Storage::IApplicationData,
    impl::require<ApplicationData, Windows::Storage::IApplicationData2, Windows::Storage::IApplicationData3>
{
    ApplicationData(std::nullptr_t) noexcept {}
    static Windows::Storage::ApplicationData Current();
    static Windows::Foundation::IAsyncOperation<Windows::Storage::ApplicationData> GetForUserAsync(const Windows::System::User & user);
};

struct WINRT_EBO ApplicationDataCompositeValue :
    Windows::Foundation::Collections::IPropertySet
{
    ApplicationDataCompositeValue(std::nullptr_t) noexcept {}
    ApplicationDataCompositeValue();
};

struct WINRT_EBO ApplicationDataContainer :
    Windows::Storage::IApplicationDataContainer
{
    ApplicationDataContainer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ApplicationDataContainerSettings :
    Windows::Foundation::Collections::IPropertySet
{
    ApplicationDataContainerSettings(std::nullptr_t) noexcept {}
};

struct CachedFileManager
{
    CachedFileManager() = delete;
    static void DeferUpdates(const Windows::Storage::IStorageFile & file);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::Storage::Provider::FileUpdateStatus> CompleteUpdatesAsync(const Windows::Storage::IStorageFile & file);
};

struct DownloadsFolder
{
    DownloadsFolder() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> CreateFileAsync(hstring_view desiredName);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> CreateFolderAsync(hstring_view desiredName);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> CreateFileAsync(hstring_view desiredName, Windows::Storage::CreationCollisionOption option);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> CreateFolderAsync(hstring_view desiredName, Windows::Storage::CreationCollisionOption option);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> CreateFileForUserAsync(const Windows::System::User & user, hstring_view desiredName);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> CreateFolderForUserAsync(const Windows::System::User & user, hstring_view desiredName);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> CreateFileForUserAsync(const Windows::System::User & user, hstring_view desiredName, Windows::Storage::CreationCollisionOption option);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> CreateFolderForUserAsync(const Windows::System::User & user, hstring_view desiredName, Windows::Storage::CreationCollisionOption option);
};

struct FileIO
{
    FileIO() = delete;
    static Windows::Foundation::IAsyncOperation<hstring> ReadTextAsync(const Windows::Storage::IStorageFile & file);
    static Windows::Foundation::IAsyncOperation<hstring> ReadTextAsync(const Windows::Storage::IStorageFile & file, Windows::Storage::Streams::UnicodeEncoding encoding);
    static Windows::Foundation::IAsyncAction WriteTextAsync(const Windows::Storage::IStorageFile & file, hstring_view contents);
    static Windows::Foundation::IAsyncAction WriteTextAsync(const Windows::Storage::IStorageFile & file, hstring_view contents, Windows::Storage::Streams::UnicodeEncoding encoding);
    static Windows::Foundation::IAsyncAction AppendTextAsync(const Windows::Storage::IStorageFile & file, hstring_view contents);
    static Windows::Foundation::IAsyncAction AppendTextAsync(const Windows::Storage::IStorageFile & file, hstring_view contents, Windows::Storage::Streams::UnicodeEncoding encoding);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> ReadLinesAsync(const Windows::Storage::IStorageFile & file);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> ReadLinesAsync(const Windows::Storage::IStorageFile & file, Windows::Storage::Streams::UnicodeEncoding encoding);
    static Windows::Foundation::IAsyncAction WriteLinesAsync(const Windows::Storage::IStorageFile & file, iterable<hstring> lines);
    static Windows::Foundation::IAsyncAction WriteLinesAsync(const Windows::Storage::IStorageFile & file, iterable<hstring> lines, Windows::Storage::Streams::UnicodeEncoding encoding);
    static Windows::Foundation::IAsyncAction AppendLinesAsync(const Windows::Storage::IStorageFile & file, iterable<hstring> lines);
    static Windows::Foundation::IAsyncAction AppendLinesAsync(const Windows::Storage::IStorageFile & file, iterable<hstring> lines, Windows::Storage::Streams::UnicodeEncoding encoding);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> ReadBufferAsync(const Windows::Storage::IStorageFile & file);
    static Windows::Foundation::IAsyncAction WriteBufferAsync(const Windows::Storage::IStorageFile & file, const Windows::Storage::Streams::IBuffer & buffer);
    static Windows::Foundation::IAsyncAction WriteBytesAsync(const Windows::Storage::IStorageFile & file, array_view<const uint8_t> buffer);
};

struct KnownFolders
{
    KnownFolders() = delete;
    static Windows::Storage::StorageFolder CameraRoll();
    static Windows::Storage::StorageFolder Playlists();
    static Windows::Storage::StorageFolder SavedPictures();
    static Windows::Storage::StorageFolder MusicLibrary();
    static Windows::Storage::StorageFolder PicturesLibrary();
    static Windows::Storage::StorageFolder VideosLibrary();
    static Windows::Storage::StorageFolder DocumentsLibrary();
    static Windows::Storage::StorageFolder HomeGroup();
    static Windows::Storage::StorageFolder RemovableDevices();
    static Windows::Storage::StorageFolder MediaServerDevices();
    static Windows::Storage::StorageFolder Objects3D();
    static Windows::Storage::StorageFolder AppCaptures();
    static Windows::Storage::StorageFolder RecordedCalls();
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> GetFolderForUserAsync(const Windows::System::User & user, Windows::Storage::KnownFolderId folderId);
};

struct PathIO
{
    PathIO() = delete;
    static Windows::Foundation::IAsyncOperation<hstring> ReadTextAsync(hstring_view absolutePath);
    static Windows::Foundation::IAsyncOperation<hstring> ReadTextAsync(hstring_view absolutePath, Windows::Storage::Streams::UnicodeEncoding encoding);
    static Windows::Foundation::IAsyncAction WriteTextAsync(hstring_view absolutePath, hstring_view contents);
    static Windows::Foundation::IAsyncAction WriteTextAsync(hstring_view absolutePath, hstring_view contents, Windows::Storage::Streams::UnicodeEncoding encoding);
    static Windows::Foundation::IAsyncAction AppendTextAsync(hstring_view absolutePath, hstring_view contents);
    static Windows::Foundation::IAsyncAction AppendTextAsync(hstring_view absolutePath, hstring_view contents, Windows::Storage::Streams::UnicodeEncoding encoding);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> ReadLinesAsync(hstring_view absolutePath);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<hstring>> ReadLinesAsync(hstring_view absolutePath, Windows::Storage::Streams::UnicodeEncoding encoding);
    static Windows::Foundation::IAsyncAction WriteLinesAsync(hstring_view absolutePath, iterable<hstring> lines);
    static Windows::Foundation::IAsyncAction WriteLinesAsync(hstring_view absolutePath, iterable<hstring> lines, Windows::Storage::Streams::UnicodeEncoding encoding);
    static Windows::Foundation::IAsyncAction AppendLinesAsync(hstring_view absolutePath, iterable<hstring> lines);
    static Windows::Foundation::IAsyncAction AppendLinesAsync(hstring_view absolutePath, iterable<hstring> lines, Windows::Storage::Streams::UnicodeEncoding encoding);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> ReadBufferAsync(hstring_view absolutePath);
    static Windows::Foundation::IAsyncAction WriteBufferAsync(hstring_view absolutePath, const Windows::Storage::Streams::IBuffer & buffer);
    static Windows::Foundation::IAsyncAction WriteBytesAsync(hstring_view absolutePath, array_view<const uint8_t> buffer);
};

struct WINRT_EBO SetVersionDeferral :
    Windows::Storage::ISetVersionDeferral
{
    SetVersionDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SetVersionRequest :
    Windows::Storage::ISetVersionRequest
{
    SetVersionRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StorageFile :
    Windows::Storage::IStorageFile,
    impl::require<StorageFile, Windows::Storage::IStorageItem2, Windows::Storage::IStorageItemProperties, Windows::Storage::IStorageItemProperties2, Windows::Storage::IStorageItemPropertiesWithProvider, Windows::Storage::IStorageFilePropertiesWithAvailability, Windows::Storage::IStorageFile2>
{
    StorageFile(std::nullptr_t) noexcept {}
    using impl_IStorageFile::OpenAsync;
    using impl_IStorageFile::OpenTransactedWriteAsync;
    using impl_IStorageFile2::OpenAsync;
    using impl_IStorageFile2::OpenTransactedWriteAsync;
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> GetFileFromPathAsync(hstring_view path);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> GetFileFromApplicationUriAsync(const Windows::Foundation::Uri & uri);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> CreateStreamedFileAsync(hstring_view displayNameWithExtension, const Windows::Storage::StreamedFileDataRequestedHandler & dataRequested, const Windows::Storage::Streams::IRandomAccessStreamReference & thumbnail);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> ReplaceWithStreamedFileAsync(const Windows::Storage::IStorageFile & fileToReplace, const Windows::Storage::StreamedFileDataRequestedHandler & dataRequested, const Windows::Storage::Streams::IRandomAccessStreamReference & thumbnail);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> CreateStreamedFileFromUriAsync(hstring_view displayNameWithExtension, const Windows::Foundation::Uri & uri, const Windows::Storage::Streams::IRandomAccessStreamReference & thumbnail);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFile> ReplaceWithStreamedFileFromUriAsync(const Windows::Storage::IStorageFile & fileToReplace, const Windows::Foundation::Uri & uri, const Windows::Storage::Streams::IRandomAccessStreamReference & thumbnail);
};

struct WINRT_EBO StorageFolder :
    Windows::Storage::IStorageFolder,
    impl::require<StorageFolder, Windows::Storage::IStorageItem2, Windows::Storage::IStorageItemProperties, Windows::Storage::IStorageItemProperties2, Windows::Storage::IStorageItemPropertiesWithProvider, Windows::Storage::Search::IStorageFolderQueryOperations, Windows::Storage::IStorageFolder2>
{
    StorageFolder(std::nullptr_t) noexcept {}
    using impl_IStorageFolder::GetFilesAsync;
    using impl_IStorageFolder::GetFoldersAsync;
    using impl_IStorageFolder::GetItemsAsync;
    using impl_IStorageFolderQueryOperations::GetFilesAsync;
    using impl_IStorageFolderQueryOperations::GetFoldersAsync;
    using impl_IStorageFolderQueryOperations::GetItemsAsync;
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageFolder> GetFolderFromPathAsync(hstring_view path);
};

struct WINRT_EBO StorageLibrary :
    Windows::Storage::IStorageLibrary,
    impl::require<StorageLibrary, Windows::Storage::IStorageLibrary2>
{
    StorageLibrary(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageLibrary> GetLibraryAsync(Windows::Storage::KnownLibraryId libraryId);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::StorageLibrary> GetLibraryForUserAsync(const Windows::System::User & user, Windows::Storage::KnownLibraryId libraryId);
};

struct WINRT_EBO StorageLibraryChange :
    Windows::Storage::IStorageLibraryChange
{
    StorageLibraryChange(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StorageLibraryChangeReader :
    Windows::Storage::IStorageLibraryChangeReader
{
    StorageLibraryChangeReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StorageLibraryChangeTracker :
    Windows::Storage::IStorageLibraryChangeTracker
{
    StorageLibraryChangeTracker(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StorageProvider :
    Windows::Storage::IStorageProvider
{
    StorageProvider(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StorageStreamTransaction :
    Windows::Storage::IStorageStreamTransaction
{
    StorageStreamTransaction(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StreamedFileDataRequest :
    Windows::Storage::Streams::IOutputStream,
    impl::require<StreamedFileDataRequest, Windows::Storage::IStreamedFileDataRequest>
{
    StreamedFileDataRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemAudioProperties :
    Windows::Storage::ISystemAudioProperties
{
    SystemAudioProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemGPSProperties :
    Windows::Storage::ISystemGPSProperties
{
    SystemGPSProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemImageProperties :
    Windows::Storage::ISystemImageProperties
{
    SystemImageProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemMediaProperties :
    Windows::Storage::ISystemMediaProperties
{
    SystemMediaProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemMusicProperties :
    Windows::Storage::ISystemMusicProperties
{
    SystemMusicProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemPhotoProperties :
    Windows::Storage::ISystemPhotoProperties
{
    SystemPhotoProperties(std::nullptr_t) noexcept {}
};

struct SystemProperties
{
    SystemProperties() = delete;
    static hstring Author();
    static hstring Comment();
    static hstring ItemNameDisplay();
    static hstring Keywords();
    static hstring Rating();
    static hstring Title();
    static Windows::Storage::SystemAudioProperties Audio();
    static Windows::Storage::SystemGPSProperties GPS();
    static Windows::Storage::SystemMediaProperties Media();
    static Windows::Storage::SystemMusicProperties Music();
    static Windows::Storage::SystemPhotoProperties Photo();
    static Windows::Storage::SystemVideoProperties Video();
    static Windows::Storage::SystemImageProperties Image();
};

struct WINRT_EBO SystemVideoProperties :
    Windows::Storage::ISystemVideoProperties
{
    SystemVideoProperties(std::nullptr_t) noexcept {}
};

}

}
