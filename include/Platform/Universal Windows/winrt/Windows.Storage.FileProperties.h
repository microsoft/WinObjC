// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Geolocation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.FileProperties.3.h"
#include "Windows.Storage.h"
#include "Windows.Foundation.h"
#include "Windows.Storage.Streams.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Storage::FileProperties::IBasicProperties> : produce_base<D, Windows::Storage::FileProperties::IBasicProperties>
{
    HRESULT __stdcall get_Size(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Size());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DateModified(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DateModified());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ItemDate(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemDate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::FileProperties::IDocumentProperties> : produce_base<D, Windows::Storage::FileProperties::IDocumentProperties>
{
    HRESULT __stdcall get_Author(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Author());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Keywords(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Keywords());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Comment(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Comment());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Comment(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Comment(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::FileProperties::IGeotagHelperStatics> : produce_base<D, Windows::Storage::FileProperties::IGeotagHelperStatics>
{
    HRESULT __stdcall abi_GetGeotagAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geopoint>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetGeotagAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetGeotagFromGeolocatorAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<Windows::Devices::Geolocation::IGeolocator> geolocator, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SetGeotagFromGeolocatorAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const Windows::Devices::Geolocation::Geolocator *>(&geolocator)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetGeotagAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> geopoint, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SetGeotagAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&geopoint)));
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
struct produce<D, Windows::Storage::FileProperties::IImageProperties> : produce_base<D, Windows::Storage::FileProperties::IImageProperties>
{
    HRESULT __stdcall get_Rating(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rating());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Rating(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rating(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Keywords(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Keywords());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DateTaken(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DateTaken());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DateTaken(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DateTaken(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Width(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Width());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Height(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Height());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Latitude(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Latitude());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Longitude(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Longitude());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CameraManufacturer(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CameraManufacturer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CameraManufacturer(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraManufacturer(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CameraModel(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CameraModel());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CameraModel(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CameraModel(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Orientation(Windows::Storage::FileProperties::PhotoOrientation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Orientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PeopleNames(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PeopleNames());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::FileProperties::IMusicProperties> : produce_base<D, Windows::Storage::FileProperties::IMusicProperties>
{
    HRESULT __stdcall get_Album(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Album());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Album(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Album(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Artist(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Artist());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Artist(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Artist(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Genre(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Genre());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrackNumber(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrackNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TrackNumber(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrackNumber(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Rating(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rating());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Rating(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rating(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bitrate(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bitrate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlbumArtist(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlbumArtist());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AlbumArtist(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlbumArtist(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Composers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Composers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Conductors(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Conductors());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Subtitle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subtitle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Subtitle(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Subtitle(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Producers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Producers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Publisher(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Publisher());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Publisher(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Publisher(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Writers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Writers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Year(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Year());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Year(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Year(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::FileProperties::IStorageItemContentProperties> : produce_base<D, Windows::Storage::FileProperties::IStorageItemContentProperties>
{
    HRESULT __stdcall abi_GetMusicPropertiesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::MusicProperties>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetMusicPropertiesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetVideoPropertiesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::VideoProperties>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetVideoPropertiesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetImagePropertiesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::ImageProperties>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetImagePropertiesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDocumentPropertiesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::DocumentProperties>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetDocumentPropertiesAsync());
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
struct produce<D, Windows::Storage::FileProperties::IStorageItemExtraProperties> : produce_base<D, Windows::Storage::FileProperties::IStorageItemExtraProperties>
{
    HRESULT __stdcall abi_RetrievePropertiesAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> propertiesToRetrieve, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RetrievePropertiesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&propertiesToRetrieve)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SavePropertiesAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>>> propertiesToSave, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SavePropertiesAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> *>(&propertiesToSave)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SavePropertiesAsyncOverloadDefault(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SavePropertiesAsync());
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
struct produce<D, Windows::Storage::FileProperties::IThumbnailProperties> : produce_base<D, Windows::Storage::FileProperties::IThumbnailProperties>
{
    HRESULT __stdcall get_OriginalWidth(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OriginalWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OriginalHeight(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OriginalHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReturnedSmallerCachedSize(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReturnedSmallerCachedSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Type(Windows::Storage::FileProperties::ThumbnailType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::FileProperties::IVideoProperties> : produce_base<D, Windows::Storage::FileProperties::IVideoProperties>
{
    HRESULT __stdcall get_Rating(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rating());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Rating(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rating(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Keywords(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Keywords());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Width(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Width());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Height(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Height());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Latitude(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Latitude());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Longitude(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Longitude());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Subtitle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subtitle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Subtitle(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Subtitle(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Producers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Producers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Publisher(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Publisher());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Publisher(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Publisher(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Writers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Writers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Year(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Year());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Year(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Year(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bitrate(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bitrate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Directors(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Directors());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Orientation(Windows::Storage::FileProperties::VideoOrientation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Orientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Storage::FileProperties {

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geopoint> impl_IGeotagHelperStatics<D>::GetGeotagAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geopoint> operation;
    check_hresult(WINRT_SHIM(IGeotagHelperStatics)->abi_GetGeotagAsync(get_abi(file), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IGeotagHelperStatics<D>::SetGeotagFromGeolocatorAsync(const Windows::Storage::IStorageFile & file, const Windows::Devices::Geolocation::Geolocator & geolocator) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IGeotagHelperStatics)->abi_SetGeotagFromGeolocatorAsync(get_abi(file), get_abi(geolocator), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IGeotagHelperStatics<D>::SetGeotagAsync(const Windows::Storage::IStorageFile & file, const Windows::Devices::Geolocation::Geopoint & geopoint) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IGeotagHelperStatics)->abi_SetGeotagAsync(get_abi(file), get_abi(geopoint), put_abi(operation)));
    return operation;
}

template <typename D> uint32_t impl_IThumbnailProperties<D>::OriginalWidth() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IThumbnailProperties)->get_OriginalWidth(&value));
    return value;
}

template <typename D> uint32_t impl_IThumbnailProperties<D>::OriginalHeight() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IThumbnailProperties)->get_OriginalHeight(&value));
    return value;
}

template <typename D> bool impl_IThumbnailProperties<D>::ReturnedSmallerCachedSize() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IThumbnailProperties)->get_ReturnedSmallerCachedSize(&value));
    return value;
}

template <typename D> Windows::Storage::FileProperties::ThumbnailType impl_IThumbnailProperties<D>::Type() const
{
    Windows::Storage::FileProperties::ThumbnailType value {};
    check_hresult(WINRT_SHIM(IThumbnailProperties)->get_Type(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> impl_IStorageItemExtraProperties<D>::RetrievePropertiesAsync(iterable<hstring> propertiesToRetrieve) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> operation;
    check_hresult(WINRT_SHIM(IStorageItemExtraProperties)->abi_RetrievePropertiesAsync(get_abi(propertiesToRetrieve), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStorageItemExtraProperties<D>::SavePropertiesAsync(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> propertiesToSave) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IStorageItemExtraProperties)->abi_SavePropertiesAsync(get_abi(propertiesToSave), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStorageItemExtraProperties<D>::SavePropertiesAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IStorageItemExtraProperties)->abi_SavePropertiesAsyncOverloadDefault(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::MusicProperties> impl_IStorageItemContentProperties<D>::GetMusicPropertiesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::MusicProperties> operation;
    check_hresult(WINRT_SHIM(IStorageItemContentProperties)->abi_GetMusicPropertiesAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::VideoProperties> impl_IStorageItemContentProperties<D>::GetVideoPropertiesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::VideoProperties> operation;
    check_hresult(WINRT_SHIM(IStorageItemContentProperties)->abi_GetVideoPropertiesAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::ImageProperties> impl_IStorageItemContentProperties<D>::GetImagePropertiesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::ImageProperties> operation;
    check_hresult(WINRT_SHIM(IStorageItemContentProperties)->abi_GetImagePropertiesAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::DocumentProperties> impl_IStorageItemContentProperties<D>::GetDocumentPropertiesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::FileProperties::DocumentProperties> operation;
    check_hresult(WINRT_SHIM(IStorageItemContentProperties)->abi_GetDocumentPropertiesAsync(put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IMusicProperties<D>::Album() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMusicProperties)->get_Album(put_abi(value)));
    return value;
}

template <typename D> void impl_IMusicProperties<D>::Album(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMusicProperties)->put_Album(get_abi(value)));
}

template <typename D> hstring impl_IMusicProperties<D>::Artist() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMusicProperties)->get_Artist(put_abi(value)));
    return value;
}

template <typename D> void impl_IMusicProperties<D>::Artist(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMusicProperties)->put_Artist(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IMusicProperties<D>::Genre() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IMusicProperties)->get_Genre(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IMusicProperties<D>::TrackNumber() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMusicProperties)->get_TrackNumber(&value));
    return value;
}

template <typename D> void impl_IMusicProperties<D>::TrackNumber(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IMusicProperties)->put_TrackNumber(value));
}

template <typename D> hstring impl_IMusicProperties<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMusicProperties)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IMusicProperties<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMusicProperties)->put_Title(get_abi(value)));
}

template <typename D> uint32_t impl_IMusicProperties<D>::Rating() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMusicProperties)->get_Rating(&value));
    return value;
}

template <typename D> void impl_IMusicProperties<D>::Rating(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IMusicProperties)->put_Rating(value));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMusicProperties<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMusicProperties)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IMusicProperties<D>::Bitrate() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMusicProperties)->get_Bitrate(&value));
    return value;
}

template <typename D> hstring impl_IMusicProperties<D>::AlbumArtist() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMusicProperties)->get_AlbumArtist(put_abi(value)));
    return value;
}

template <typename D> void impl_IMusicProperties<D>::AlbumArtist(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMusicProperties)->put_AlbumArtist(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IMusicProperties<D>::Composers() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IMusicProperties)->get_Composers(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IMusicProperties<D>::Conductors() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IMusicProperties)->get_Conductors(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMusicProperties<D>::Subtitle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMusicProperties)->get_Subtitle(put_abi(value)));
    return value;
}

template <typename D> void impl_IMusicProperties<D>::Subtitle(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMusicProperties)->put_Subtitle(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IMusicProperties<D>::Producers() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IMusicProperties)->get_Producers(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMusicProperties<D>::Publisher() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMusicProperties)->get_Publisher(put_abi(value)));
    return value;
}

template <typename D> void impl_IMusicProperties<D>::Publisher(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMusicProperties)->put_Publisher(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IMusicProperties<D>::Writers() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IMusicProperties)->get_Writers(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IMusicProperties<D>::Year() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMusicProperties)->get_Year(&value));
    return value;
}

template <typename D> void impl_IMusicProperties<D>::Year(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IMusicProperties)->put_Year(value));
}

template <typename D> uint32_t impl_IImageProperties<D>::Rating() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IImageProperties)->get_Rating(&value));
    return value;
}

template <typename D> void impl_IImageProperties<D>::Rating(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IImageProperties)->put_Rating(value));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IImageProperties<D>::Keywords() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IImageProperties)->get_Keywords(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IImageProperties<D>::DateTaken() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IImageProperties)->get_DateTaken(put_abi(value)));
    return value;
}

template <typename D> void impl_IImageProperties<D>::DateTaken(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IImageProperties)->put_DateTaken(get_abi(value)));
}

template <typename D> uint32_t impl_IImageProperties<D>::Width() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IImageProperties)->get_Width(&value));
    return value;
}

template <typename D> uint32_t impl_IImageProperties<D>::Height() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IImageProperties)->get_Height(&value));
    return value;
}

template <typename D> hstring impl_IImageProperties<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IImageProperties)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IImageProperties<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IImageProperties)->put_Title(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<double> impl_IImageProperties<D>::Latitude() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IImageProperties)->get_Latitude(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_IImageProperties<D>::Longitude() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IImageProperties)->get_Longitude(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IImageProperties<D>::CameraManufacturer() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IImageProperties)->get_CameraManufacturer(put_abi(value)));
    return value;
}

template <typename D> void impl_IImageProperties<D>::CameraManufacturer(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IImageProperties)->put_CameraManufacturer(get_abi(value)));
}

template <typename D> hstring impl_IImageProperties<D>::CameraModel() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IImageProperties)->get_CameraModel(put_abi(value)));
    return value;
}

template <typename D> void impl_IImageProperties<D>::CameraModel(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IImageProperties)->put_CameraModel(get_abi(value)));
}

template <typename D> Windows::Storage::FileProperties::PhotoOrientation impl_IImageProperties<D>::Orientation() const
{
    Windows::Storage::FileProperties::PhotoOrientation value {};
    check_hresult(WINRT_SHIM(IImageProperties)->get_Orientation(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IImageProperties<D>::PeopleNames() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IImageProperties)->get_PeopleNames(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IVideoProperties<D>::Rating() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Rating(&value));
    return value;
}

template <typename D> void impl_IVideoProperties<D>::Rating(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IVideoProperties)->put_Rating(value));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IVideoProperties<D>::Keywords() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Keywords(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IVideoProperties<D>::Width() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Width(&value));
    return value;
}

template <typename D> uint32_t impl_IVideoProperties<D>::Height() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Height(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IVideoProperties<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_IVideoProperties<D>::Latitude() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Latitude(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_IVideoProperties<D>::Longitude() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Longitude(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVideoProperties<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IVideoProperties<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVideoProperties)->put_Title(get_abi(value)));
}

template <typename D> hstring impl_IVideoProperties<D>::Subtitle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Subtitle(put_abi(value)));
    return value;
}

template <typename D> void impl_IVideoProperties<D>::Subtitle(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVideoProperties)->put_Subtitle(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IVideoProperties<D>::Producers() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Producers(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVideoProperties<D>::Publisher() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Publisher(put_abi(value)));
    return value;
}

template <typename D> void impl_IVideoProperties<D>::Publisher(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVideoProperties)->put_Publisher(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IVideoProperties<D>::Writers() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Writers(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IVideoProperties<D>::Year() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Year(&value));
    return value;
}

template <typename D> void impl_IVideoProperties<D>::Year(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IVideoProperties)->put_Year(value));
}

template <typename D> uint32_t impl_IVideoProperties<D>::Bitrate() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Bitrate(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IVideoProperties<D>::Directors() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Directors(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::FileProperties::VideoOrientation impl_IVideoProperties<D>::Orientation() const
{
    Windows::Storage::FileProperties::VideoOrientation value {};
    check_hresult(WINRT_SHIM(IVideoProperties)->get_Orientation(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IDocumentProperties<D>::Author() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IDocumentProperties)->get_Author(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDocumentProperties<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDocumentProperties)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IDocumentProperties<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDocumentProperties)->put_Title(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IDocumentProperties<D>::Keywords() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IDocumentProperties)->get_Keywords(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDocumentProperties<D>::Comment() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDocumentProperties)->get_Comment(put_abi(value)));
    return value;
}

template <typename D> void impl_IDocumentProperties<D>::Comment(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDocumentProperties)->put_Comment(get_abi(value)));
}

template <typename D> uint64_t impl_IBasicProperties<D>::Size() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IBasicProperties)->get_Size(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IBasicProperties<D>::DateModified() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IBasicProperties)->get_DateModified(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IBasicProperties<D>::ItemDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IBasicProperties)->get_ItemDate(put_abi(value)));
    return value;
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geopoint> GeotagHelper::GetGeotagAsync(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<GeotagHelper, IGeotagHelperStatics>().GetGeotagAsync(file);
}

inline Windows::Foundation::IAsyncAction GeotagHelper::SetGeotagFromGeolocatorAsync(const Windows::Storage::IStorageFile & file, const Windows::Devices::Geolocation::Geolocator & geolocator)
{
    return get_activation_factory<GeotagHelper, IGeotagHelperStatics>().SetGeotagFromGeolocatorAsync(file, geolocator);
}

inline Windows::Foundation::IAsyncAction GeotagHelper::SetGeotagAsync(const Windows::Storage::IStorageFile & file, const Windows::Devices::Geolocation::Geopoint & geopoint)
{
    return get_activation_factory<GeotagHelper, IGeotagHelperStatics>().SetGeotagAsync(file, geopoint);
}

}

}
#pragma warning(pop)
