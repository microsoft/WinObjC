// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.FileProperties.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Storage::FileProperties {

struct WINRT_EBO BasicProperties :
    Windows::Storage::FileProperties::IBasicProperties,
    impl::require<BasicProperties, Windows::Storage::FileProperties::IStorageItemExtraProperties>
{
    BasicProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DocumentProperties :
    Windows::Storage::FileProperties::IDocumentProperties
{
    DocumentProperties(std::nullptr_t) noexcept {}
};

struct GeotagHelper
{
    GeotagHelper() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geopoint> GetGeotagAsync(const Windows::Storage::IStorageFile & file);
    static Windows::Foundation::IAsyncAction SetGeotagFromGeolocatorAsync(const Windows::Storage::IStorageFile & file, const Windows::Devices::Geolocation::Geolocator & geolocator);
    static Windows::Foundation::IAsyncAction SetGeotagAsync(const Windows::Storage::IStorageFile & file, const Windows::Devices::Geolocation::Geopoint & geopoint);
};

struct WINRT_EBO ImageProperties :
    Windows::Storage::FileProperties::IImageProperties
{
    ImageProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MusicProperties :
    Windows::Storage::FileProperties::IMusicProperties
{
    MusicProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StorageItemContentProperties :
    Windows::Storage::FileProperties::IStorageItemContentProperties
{
    StorageItemContentProperties(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StorageItemThumbnail :
    Windows::Storage::Streams::IRandomAccessStreamWithContentType,
    impl::require<StorageItemThumbnail, Windows::Storage::FileProperties::IThumbnailProperties>
{
    StorageItemThumbnail(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VideoProperties :
    Windows::Storage::FileProperties::IVideoProperties
{
    VideoProperties(std::nullptr_t) noexcept {}
};

}

}
