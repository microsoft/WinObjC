// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Storage {

struct ApplicationDataSetVersionHandler;
struct IApplicationData;
struct IApplicationData2;
struct IApplicationData3;
struct IApplicationDataContainer;
struct IApplicationDataStatics;
struct IApplicationDataStatics2;
struct ICachedFileManagerStatics;
struct IDownloadsFolderStatics;
struct IDownloadsFolderStatics2;
struct IFileIOStatics;
struct IKnownFoldersCameraRollStatics;
struct IKnownFoldersPlaylistsStatics;
struct IKnownFoldersSavedPicturesStatics;
struct IKnownFoldersStatics;
struct IKnownFoldersStatics2;
struct IKnownFoldersStatics3;
struct IPathIOStatics;
struct ISetVersionDeferral;
struct ISetVersionRequest;
struct IStorageFile;
struct IStorageFile2;
struct IStorageFilePropertiesWithAvailability;
struct IStorageFileStatics;
struct IStorageFolder;
struct IStorageFolder2;
struct IStorageFolderStatics;
struct IStorageItem;
struct IStorageItem2;
struct IStorageItemProperties;
struct IStorageItemProperties2;
struct IStorageItemPropertiesWithProvider;
struct IStorageLibrary;
struct IStorageLibrary2;
struct IStorageLibraryChange;
struct IStorageLibraryChangeReader;
struct IStorageLibraryChangeTracker;
struct IStorageLibraryStatics;
struct IStorageLibraryStatics2;
struct IStorageProvider;
struct IStorageStreamTransaction;
struct IStreamedFileDataRequest;
struct ISystemAudioProperties;
struct ISystemGPSProperties;
struct ISystemImageProperties;
struct ISystemMediaProperties;
struct ISystemMusicProperties;
struct ISystemPhotoProperties;
struct ISystemProperties;
struct ISystemVideoProperties;
struct StreamedFileDataRequestedHandler;
struct ApplicationData;
struct ApplicationDataCompositeValue;
struct ApplicationDataContainer;
struct ApplicationDataContainerSettings;
struct SetVersionDeferral;
struct SetVersionRequest;
struct StorageFile;
struct StorageFolder;
struct StorageLibrary;
struct StorageLibraryChange;
struct StorageLibraryChangeReader;
struct StorageLibraryChangeTracker;
struct StorageProvider;
struct StorageStreamTransaction;
struct StreamedFileDataRequest;
struct SystemAudioProperties;
struct SystemGPSProperties;
struct SystemImageProperties;
struct SystemMediaProperties;
struct SystemMusicProperties;
struct SystemPhotoProperties;
struct SystemVideoProperties;

}

namespace Windows::Storage {

struct ApplicationDataSetVersionHandler;
struct StreamedFileDataRequestedHandler;
struct IApplicationData;
struct IApplicationData2;
struct IApplicationData3;
struct IApplicationDataContainer;
struct IApplicationDataStatics;
struct IApplicationDataStatics2;
struct ICachedFileManagerStatics;
struct IDownloadsFolderStatics;
struct IDownloadsFolderStatics2;
struct IFileIOStatics;
struct IKnownFoldersCameraRollStatics;
struct IKnownFoldersPlaylistsStatics;
struct IKnownFoldersSavedPicturesStatics;
struct IKnownFoldersStatics;
struct IKnownFoldersStatics2;
struct IKnownFoldersStatics3;
struct IPathIOStatics;
struct ISetVersionDeferral;
struct ISetVersionRequest;
struct IStorageFile;
struct IStorageFile2;
struct IStorageFilePropertiesWithAvailability;
struct IStorageFileStatics;
struct IStorageFolder;
struct IStorageFolder2;
struct IStorageFolderStatics;
struct IStorageItem;
struct IStorageItem2;
struct IStorageItemProperties;
struct IStorageItemProperties2;
struct IStorageItemPropertiesWithProvider;
struct IStorageLibrary;
struct IStorageLibrary2;
struct IStorageLibraryChange;
struct IStorageLibraryChangeReader;
struct IStorageLibraryChangeTracker;
struct IStorageLibraryStatics;
struct IStorageLibraryStatics2;
struct IStorageProvider;
struct IStorageStreamTransaction;
struct IStreamedFileDataRequest;
struct ISystemAudioProperties;
struct ISystemGPSProperties;
struct ISystemImageProperties;
struct ISystemMediaProperties;
struct ISystemMusicProperties;
struct ISystemPhotoProperties;
struct ISystemProperties;
struct ISystemVideoProperties;
struct ApplicationData;
struct ApplicationDataCompositeValue;
struct ApplicationDataContainer;
struct ApplicationDataContainerSettings;
struct CachedFileManager;
struct DownloadsFolder;
struct FileIO;
struct KnownFolders;
struct PathIO;
struct SetVersionDeferral;
struct SetVersionRequest;
struct StorageFile;
struct StorageFolder;
struct StorageLibrary;
struct StorageLibraryChange;
struct StorageLibraryChangeReader;
struct StorageLibraryChangeTracker;
struct StorageProvider;
struct StorageStreamTransaction;
struct StreamedFileDataRequest;
struct SystemAudioProperties;
struct SystemGPSProperties;
struct SystemImageProperties;
struct SystemMediaProperties;
struct SystemMusicProperties;
struct SystemPhotoProperties;
struct SystemProperties;
struct SystemVideoProperties;

}

namespace Windows::Storage {

template <typename T> struct impl_IApplicationData;
template <typename T> struct impl_IApplicationData2;
template <typename T> struct impl_IApplicationData3;
template <typename T> struct impl_IApplicationDataContainer;
template <typename T> struct impl_IApplicationDataStatics;
template <typename T> struct impl_IApplicationDataStatics2;
template <typename T> struct impl_ICachedFileManagerStatics;
template <typename T> struct impl_IDownloadsFolderStatics;
template <typename T> struct impl_IDownloadsFolderStatics2;
template <typename T> struct impl_IFileIOStatics;
template <typename T> struct impl_IKnownFoldersCameraRollStatics;
template <typename T> struct impl_IKnownFoldersPlaylistsStatics;
template <typename T> struct impl_IKnownFoldersSavedPicturesStatics;
template <typename T> struct impl_IKnownFoldersStatics;
template <typename T> struct impl_IKnownFoldersStatics2;
template <typename T> struct impl_IKnownFoldersStatics3;
template <typename T> struct impl_IPathIOStatics;
template <typename T> struct impl_ISetVersionDeferral;
template <typename T> struct impl_ISetVersionRequest;
template <typename T> struct impl_IStorageFile;
template <typename T> struct impl_IStorageFile2;
template <typename T> struct impl_IStorageFilePropertiesWithAvailability;
template <typename T> struct impl_IStorageFileStatics;
template <typename T> struct impl_IStorageFolder;
template <typename T> struct impl_IStorageFolder2;
template <typename T> struct impl_IStorageFolderStatics;
template <typename T> struct impl_IStorageItem;
template <typename T> struct impl_IStorageItem2;
template <typename T> struct impl_IStorageItemProperties;
template <typename T> struct impl_IStorageItemProperties2;
template <typename T> struct impl_IStorageItemPropertiesWithProvider;
template <typename T> struct impl_IStorageLibrary;
template <typename T> struct impl_IStorageLibrary2;
template <typename T> struct impl_IStorageLibraryChange;
template <typename T> struct impl_IStorageLibraryChangeReader;
template <typename T> struct impl_IStorageLibraryChangeTracker;
template <typename T> struct impl_IStorageLibraryStatics;
template <typename T> struct impl_IStorageLibraryStatics2;
template <typename T> struct impl_IStorageProvider;
template <typename T> struct impl_IStorageStreamTransaction;
template <typename T> struct impl_IStreamedFileDataRequest;
template <typename T> struct impl_ISystemAudioProperties;
template <typename T> struct impl_ISystemGPSProperties;
template <typename T> struct impl_ISystemImageProperties;
template <typename T> struct impl_ISystemMediaProperties;
template <typename T> struct impl_ISystemMusicProperties;
template <typename T> struct impl_ISystemPhotoProperties;
template <typename T> struct impl_ISystemProperties;
template <typename T> struct impl_ISystemVideoProperties;
template <typename T> struct impl_ApplicationDataSetVersionHandler;
template <typename T> struct impl_StreamedFileDataRequestedHandler;

}

namespace Windows::Storage {

enum class ApplicationDataCreateDisposition
{
    Always = 0,
    Existing = 1,
};

enum class ApplicationDataLocality
{
    Local = 0,
    Roaming = 1,
    Temporary = 2,
    LocalCache = 3,
};

enum class CreationCollisionOption
{
    GenerateUniqueName = 0,
    ReplaceExisting = 1,
    FailIfExists = 2,
    OpenIfExists = 3,
};

enum class FileAccessMode
{
    Read = 0,
    ReadWrite = 1,
};

enum class FileAttributes : unsigned
{
    Normal = 0x0,
    ReadOnly = 0x1,
    Directory = 0x10,
    Archive = 0x20,
    Temporary = 0x100,
    LocallyIncomplete = 0x200,
};

DEFINE_ENUM_FLAG_OPERATORS(FileAttributes)

enum class KnownFolderId
{
    AppCaptures = 0,
    CameraRoll = 1,
    DocumentsLibrary = 2,
    HomeGroup = 3,
    MediaServerDevices = 4,
    MusicLibrary = 5,
    Objects3D = 6,
    PicturesLibrary = 7,
    Playlists = 8,
    RecordedCalls = 9,
    RemovableDevices = 10,
    SavedPictures = 11,
    Screenshots = 12,
    VideosLibrary = 13,
};

enum class KnownLibraryId
{
    Music = 0,
    Pictures = 1,
    Videos = 2,
    Documents = 3,
};

enum class NameCollisionOption
{
    GenerateUniqueName = 0,
    ReplaceExisting = 1,
    FailIfExists = 2,
};

enum class StorageDeleteOption
{
    Default = 0,
    PermanentDelete = 1,
};

enum class StorageItemTypes : unsigned
{
    None = 0x0,
    File = 0x1,
    Folder = 0x2,
};

DEFINE_ENUM_FLAG_OPERATORS(StorageItemTypes)

enum class StorageLibraryChangeType
{
    Created = 0,
    Deleted = 1,
    MovedOrRenamed = 2,
    ContentsChanged = 3,
    MovedOutOfLibrary = 4,
    MovedIntoLibrary = 5,
    ContentsReplaced = 6,
    IndexingStatusChanged = 7,
    EncryptionChanged = 8,
    ChangeTrackingLost = 9,
};

enum class StorageOpenOptions : unsigned
{
    None = 0x0,
    AllowOnlyReaders = 0x1,
};

DEFINE_ENUM_FLAG_OPERATORS(StorageOpenOptions)

enum class StreamedFileFailureMode
{
    Failed = 0,
    CurrentlyUnavailable = 1,
    Incomplete = 2,
};

}

}
