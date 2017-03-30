// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Storage.FileProperties.0.h"
#include "Windows.Devices.Geolocation.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Devices.Geolocation.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Storage::FileProperties {

struct __declspec(uuid("d05d55db-785e-4a66-be02-9beec58aea81")) __declspec(novtable) IBasicProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Size(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_DateModified(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_ItemDate(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("7eab19bc-1821-4923-b4a9-0aea404d0070")) __declspec(novtable) IDocumentProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Author(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_Keywords(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Comment(hstring * value) = 0;
    virtual HRESULT __stdcall put_Comment(hstring value) = 0;
};

struct __declspec(uuid("41493244-2524-4655-86a6-ed16f5fc716b")) __declspec(novtable) IGeotagHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetGeotagAsync(Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geopoint> ** operation) = 0;
    virtual HRESULT __stdcall abi_SetGeotagFromGeolocatorAsync(Windows::Storage::IStorageFile * file, Windows::Devices::Geolocation::IGeolocator * geolocator, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_SetGeotagAsync(Windows::Storage::IStorageFile * file, Windows::Devices::Geolocation::IGeopoint * geopoint, Windows::Foundation::IAsyncAction ** operation) = 0;
};

struct __declspec(uuid("523c9424-fcff-4275-afee-ecdb9ab47973")) __declspec(novtable) IImageProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Rating(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Rating(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Keywords(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_DateTaken(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_DateTaken(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_Width(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Height(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_Latitude(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall get_Longitude(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall get_CameraManufacturer(hstring * value) = 0;
    virtual HRESULT __stdcall put_CameraManufacturer(hstring value) = 0;
    virtual HRESULT __stdcall get_CameraModel(hstring * value) = 0;
    virtual HRESULT __stdcall put_CameraModel(hstring value) = 0;
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::Storage::FileProperties::PhotoOrientation * value) = 0;
    virtual HRESULT __stdcall get_PeopleNames(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
};

struct __declspec(uuid("bc8aab62-66ec-419a-bc5d-ca65a4cb46da")) __declspec(novtable) IMusicProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Album(hstring * value) = 0;
    virtual HRESULT __stdcall put_Album(hstring value) = 0;
    virtual HRESULT __stdcall get_Artist(hstring * value) = 0;
    virtual HRESULT __stdcall put_Artist(hstring value) = 0;
    virtual HRESULT __stdcall get_Genre(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_TrackNumber(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_TrackNumber(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_Rating(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Rating(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Duration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Bitrate(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_AlbumArtist(hstring * value) = 0;
    virtual HRESULT __stdcall put_AlbumArtist(hstring value) = 0;
    virtual HRESULT __stdcall get_Composers(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Conductors(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Subtitle(hstring * value) = 0;
    virtual HRESULT __stdcall put_Subtitle(hstring value) = 0;
    virtual HRESULT __stdcall get_Producers(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Publisher(hstring * value) = 0;
    virtual HRESULT __stdcall put_Publisher(hstring value) = 0;
    virtual HRESULT __stdcall get_Writers(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Year(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Year(uint32_t value) = 0;
};

struct __declspec(uuid("05294bad-bc38-48bf-85d7-770e0e2ae0ba")) __declspec(novtable) IStorageItemContentProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetMusicPropertiesAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::MusicProperties> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetVideoPropertiesAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::VideoProperties> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetImagePropertiesAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::ImageProperties> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetDocumentPropertiesAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::DocumentProperties> ** operation) = 0;
};

struct __declspec(uuid("c54361b2-54cd-432b-bdbc-4b19c4b470d7")) __declspec(novtable) IStorageItemExtraProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RetrievePropertiesAsync(Windows::Foundation::Collections::IIterable<hstring> * propertiesToRetrieve, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> ** operation) = 0;
    virtual HRESULT __stdcall abi_SavePropertiesAsync(Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> * propertiesToSave, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_SavePropertiesAsyncOverloadDefault(Windows::Foundation::IAsyncAction ** operation) = 0;
};

struct __declspec(uuid("693dd42f-dbe7-49b5-b3b3-2893ac5d3423")) __declspec(novtable) IThumbnailProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OriginalWidth(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_OriginalHeight(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ReturnedSmallerCachedSize(bool * value) = 0;
    virtual HRESULT __stdcall get_Type(winrt::Windows::Storage::FileProperties::ThumbnailType * value) = 0;
};

struct __declspec(uuid("719ae507-68de-4db8-97de-49998c059f2f")) __declspec(novtable) IVideoProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Rating(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Rating(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Keywords(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Width(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Height(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Duration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Latitude(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall get_Longitude(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_Subtitle(hstring * value) = 0;
    virtual HRESULT __stdcall put_Subtitle(hstring value) = 0;
    virtual HRESULT __stdcall get_Producers(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Publisher(hstring * value) = 0;
    virtual HRESULT __stdcall put_Publisher(hstring value) = 0;
    virtual HRESULT __stdcall get_Writers(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Year(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Year(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Bitrate(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Directors(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::Storage::FileProperties::VideoOrientation * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Storage::FileProperties::BasicProperties> { using default_interface = Windows::Storage::FileProperties::IBasicProperties; };
template <> struct traits<Windows::Storage::FileProperties::DocumentProperties> { using default_interface = Windows::Storage::FileProperties::IDocumentProperties; };
template <> struct traits<Windows::Storage::FileProperties::ImageProperties> { using default_interface = Windows::Storage::FileProperties::IImageProperties; };
template <> struct traits<Windows::Storage::FileProperties::MusicProperties> { using default_interface = Windows::Storage::FileProperties::IMusicProperties; };
template <> struct traits<Windows::Storage::FileProperties::StorageItemContentProperties> { using default_interface = Windows::Storage::FileProperties::IStorageItemContentProperties; };
template <> struct traits<Windows::Storage::FileProperties::StorageItemThumbnail> { using default_interface = Windows::Storage::Streams::IRandomAccessStreamWithContentType; };
template <> struct traits<Windows::Storage::FileProperties::VideoProperties> { using default_interface = Windows::Storage::FileProperties::IVideoProperties; };

}

namespace Windows::Storage::FileProperties {

template <typename D>
struct WINRT_EBO impl_IBasicProperties
{
    uint64_t Size() const;
    Windows::Foundation::DateTime DateModified() const;
    Windows::Foundation::DateTime ItemDate() const;
};

template <typename D>
struct WINRT_EBO impl_IDocumentProperties
{
    Windows::Foundation::Collections::IVector<hstring> Author() const;
    hstring Title() const;
    void Title(hstring_view value) const;
    Windows::Foundation::Collections::IVector<hstring> Keywords() const;
    hstring Comment() const;
    void Comment(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IGeotagHelperStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geopoint> GetGeotagAsync(const Windows::Storage::IStorageFile & file) const;
    Windows::Foundation::IAsyncAction SetGeotagFromGeolocatorAsync(const Windows::Storage::IStorageFile & file, const Windows::Devices::Geolocation::Geolocator & geolocator) const;
    Windows::Foundation::IAsyncAction SetGeotagAsync(const Windows::Storage::IStorageFile & file, const Windows::Devices::Geolocation::Geopoint & geopoint) const;
};

template <typename D>
struct WINRT_EBO impl_IImageProperties
{
    uint32_t Rating() const;
    void Rating(uint32_t value) const;
    Windows::Foundation::Collections::IVector<hstring> Keywords() const;
    Windows::Foundation::DateTime DateTaken() const;
    void DateTaken(const Windows::Foundation::DateTime & value) const;
    uint32_t Width() const;
    uint32_t Height() const;
    hstring Title() const;
    void Title(hstring_view value) const;
    Windows::Foundation::IReference<double> Latitude() const;
    Windows::Foundation::IReference<double> Longitude() const;
    hstring CameraManufacturer() const;
    void CameraManufacturer(hstring_view value) const;
    hstring CameraModel() const;
    void CameraModel(hstring_view value) const;
    Windows::Storage::FileProperties::PhotoOrientation Orientation() const;
    Windows::Foundation::Collections::IVectorView<hstring> PeopleNames() const;
};

template <typename D>
struct WINRT_EBO impl_IMusicProperties
{
    hstring Album() const;
    void Album(hstring_view value) const;
    hstring Artist() const;
    void Artist(hstring_view value) const;
    Windows::Foundation::Collections::IVector<hstring> Genre() const;
    uint32_t TrackNumber() const;
    void TrackNumber(uint32_t value) const;
    hstring Title() const;
    void Title(hstring_view value) const;
    uint32_t Rating() const;
    void Rating(uint32_t value) const;
    Windows::Foundation::TimeSpan Duration() const;
    uint32_t Bitrate() const;
    hstring AlbumArtist() const;
    void AlbumArtist(hstring_view value) const;
    Windows::Foundation::Collections::IVector<hstring> Composers() const;
    Windows::Foundation::Collections::IVector<hstring> Conductors() const;
    hstring Subtitle() const;
    void Subtitle(hstring_view value) const;
    Windows::Foundation::Collections::IVector<hstring> Producers() const;
    hstring Publisher() const;
    void Publisher(hstring_view value) const;
    Windows::Foundation::Collections::IVector<hstring> Writers() const;
    uint32_t Year() const;
    void Year(uint32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IStorageItemContentProperties
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::MusicProperties> GetMusicPropertiesAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::VideoProperties> GetVideoPropertiesAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::ImageProperties> GetImagePropertiesAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::DocumentProperties> GetDocumentPropertiesAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IStorageItemExtraProperties
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> RetrievePropertiesAsync(iterable<hstring> propertiesToRetrieve) const;
    Windows::Foundation::IAsyncAction SavePropertiesAsync(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> propertiesToSave) const;
    Windows::Foundation::IAsyncAction SavePropertiesAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IThumbnailProperties
{
    uint32_t OriginalWidth() const;
    uint32_t OriginalHeight() const;
    bool ReturnedSmallerCachedSize() const;
    Windows::Storage::FileProperties::ThumbnailType Type() const;
};

template <typename D>
struct WINRT_EBO impl_IVideoProperties
{
    uint32_t Rating() const;
    void Rating(uint32_t value) const;
    Windows::Foundation::Collections::IVector<hstring> Keywords() const;
    uint32_t Width() const;
    uint32_t Height() const;
    Windows::Foundation::TimeSpan Duration() const;
    Windows::Foundation::IReference<double> Latitude() const;
    Windows::Foundation::IReference<double> Longitude() const;
    hstring Title() const;
    void Title(hstring_view value) const;
    hstring Subtitle() const;
    void Subtitle(hstring_view value) const;
    Windows::Foundation::Collections::IVector<hstring> Producers() const;
    hstring Publisher() const;
    void Publisher(hstring_view value) const;
    Windows::Foundation::Collections::IVector<hstring> Writers() const;
    uint32_t Year() const;
    void Year(uint32_t value) const;
    uint32_t Bitrate() const;
    Windows::Foundation::Collections::IVector<hstring> Directors() const;
    Windows::Storage::FileProperties::VideoOrientation Orientation() const;
};

}

namespace impl {

template <> struct traits<Windows::Storage::FileProperties::IBasicProperties>
{
    using abi = ABI::Windows::Storage::FileProperties::IBasicProperties;
    template <typename D> using consume = Windows::Storage::FileProperties::impl_IBasicProperties<D>;
};

template <> struct traits<Windows::Storage::FileProperties::IDocumentProperties>
{
    using abi = ABI::Windows::Storage::FileProperties::IDocumentProperties;
    template <typename D> using consume = Windows::Storage::FileProperties::impl_IDocumentProperties<D>;
};

template <> struct traits<Windows::Storage::FileProperties::IGeotagHelperStatics>
{
    using abi = ABI::Windows::Storage::FileProperties::IGeotagHelperStatics;
    template <typename D> using consume = Windows::Storage::FileProperties::impl_IGeotagHelperStatics<D>;
};

template <> struct traits<Windows::Storage::FileProperties::IImageProperties>
{
    using abi = ABI::Windows::Storage::FileProperties::IImageProperties;
    template <typename D> using consume = Windows::Storage::FileProperties::impl_IImageProperties<D>;
};

template <> struct traits<Windows::Storage::FileProperties::IMusicProperties>
{
    using abi = ABI::Windows::Storage::FileProperties::IMusicProperties;
    template <typename D> using consume = Windows::Storage::FileProperties::impl_IMusicProperties<D>;
};

template <> struct traits<Windows::Storage::FileProperties::IStorageItemContentProperties>
{
    using abi = ABI::Windows::Storage::FileProperties::IStorageItemContentProperties;
    template <typename D> using consume = Windows::Storage::FileProperties::impl_IStorageItemContentProperties<D>;
};

template <> struct traits<Windows::Storage::FileProperties::IStorageItemExtraProperties>
{
    using abi = ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties;
    template <typename D> using consume = Windows::Storage::FileProperties::impl_IStorageItemExtraProperties<D>;
};

template <> struct traits<Windows::Storage::FileProperties::IThumbnailProperties>
{
    using abi = ABI::Windows::Storage::FileProperties::IThumbnailProperties;
    template <typename D> using consume = Windows::Storage::FileProperties::impl_IThumbnailProperties<D>;
};

template <> struct traits<Windows::Storage::FileProperties::IVideoProperties>
{
    using abi = ABI::Windows::Storage::FileProperties::IVideoProperties;
    template <typename D> using consume = Windows::Storage::FileProperties::impl_IVideoProperties<D>;
};

template <> struct traits<Windows::Storage::FileProperties::BasicProperties>
{
    using abi = ABI::Windows::Storage::FileProperties::BasicProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.FileProperties.BasicProperties"; }
};

template <> struct traits<Windows::Storage::FileProperties::DocumentProperties>
{
    using abi = ABI::Windows::Storage::FileProperties::DocumentProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.FileProperties.DocumentProperties"; }
};

template <> struct traits<Windows::Storage::FileProperties::GeotagHelper>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.FileProperties.GeotagHelper"; }
};

template <> struct traits<Windows::Storage::FileProperties::ImageProperties>
{
    using abi = ABI::Windows::Storage::FileProperties::ImageProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.FileProperties.ImageProperties"; }
};

template <> struct traits<Windows::Storage::FileProperties::MusicProperties>
{
    using abi = ABI::Windows::Storage::FileProperties::MusicProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.FileProperties.MusicProperties"; }
};

template <> struct traits<Windows::Storage::FileProperties::StorageItemContentProperties>
{
    using abi = ABI::Windows::Storage::FileProperties::StorageItemContentProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.FileProperties.StorageItemContentProperties"; }
};

template <> struct traits<Windows::Storage::FileProperties::StorageItemThumbnail>
{
    using abi = ABI::Windows::Storage::FileProperties::StorageItemThumbnail;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.FileProperties.StorageItemThumbnail"; }
};

template <> struct traits<Windows::Storage::FileProperties::VideoProperties>
{
    using abi = ABI::Windows::Storage::FileProperties::VideoProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.FileProperties.VideoProperties"; }
};

}

}
